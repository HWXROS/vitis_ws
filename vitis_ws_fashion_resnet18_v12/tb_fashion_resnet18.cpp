#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ap_int.h>

void control(ap_int<32> v0[102852096], ap_int<32> v1[102852096], ap_int<32> v2[102852096]);

int load_buf(const char* path, ap_int<32>* buf, int n) {
    FILE* f = fopen(path, "rb");
    if (!f) { printf("Failed to open %s\n", path); return 1; }
    size_t r = fread(buf, sizeof(ap_int<32>), n, f);
    fclose(f);
    if ((int)r != n) { printf("Short read %s: %zu/%d\n", path, r, n); return 1; }
    return 0;
}

int main() {
    printf("=== Fashion-ResNet18 v1.2 T=4 C-Simulation ===\n");

    ap_int<32>* buf0 = (ap_int<32>*)malloc(102852096 * sizeof(ap_int<32>));
    ap_int<32>* buf1 = (ap_int<32>*)malloc(102852096 * sizeof(ap_int<32>));
    ap_int<32>* buf2 = (ap_int<32>*)malloc(102852096 * sizeof(ap_int<32>));
    if (!buf0 || !buf1 || !buf2) { printf("OOM\n"); return 1; }

    memset(buf0, 0, 102852096 * sizeof(ap_int<32>));
    memset(buf1, 0, 102852096 * sizeof(ap_int<32>));

    if (load_buf("v697_weights.bin", buf2, 102852096)) return 1;
    if (load_buf("test_image.bin", buf0, 9216)) return 1;

    // T=4: call control() 4 times, IF states persist in DDR
    float accum[10] = {0};
    for (int t = 0; t < 4; t++) {
        control(buf0, buf1, buf2);
        float* out = reinterpret_cast<float*>(buf0 + 2654208);
        printf("T=%d: ", t + 1);
        for (int i = 0; i < 10; i++) {
            printf("%.4f%c", out[i], i < 9 ? ' ' : '\n');
            accum[i] += out[i];
        }
    }

    // Average
    printf("\nT=4 averaged logits: ");
    for (int i = 0; i < 10; i++) {
        accum[i] /= 4.0f;
        printf("%.4f%c", accum[i], i < 9 ? ' ' : '\n');
    }

    int pred = 0;
    for (int i = 1; i < 10; i++)
        if (accum[i] > accum[pred]) pred = i;
    printf("Predicted class: %d\n", pred);

    // Compare with PyTorch T=4 reference
    float pytorch[10];
    FILE* pf = fopen("pytorch_outputs_t4.bin", "rb");
    if (pf) {
        fread(pytorch, sizeof(float), 10, pf);
        fclose(pf);
        printf("PyTorch T=4 ref: ");
        for (int i = 0; i < 10; i++) printf("%.4f%c", pytorch[i], i < 9 ? ' ' : '\n');

        float max_err = 0;
        for (int i = 0; i < 10; i++) {
            float err = fabs(accum[i] - pytorch[i]);
            if (err > max_err) max_err = err;
        }
        printf("Max abs error: %.6f\n", max_err);

        int pt_pred = 0;
        for (int i = 1; i < 10; i++)
            if (pytorch[i] > pytorch[pt_pred]) pt_pred = i;
        printf("PyTorch pred: %d, C-Sim pred: %d %s\n",
               pt_pred, pred, pred == pt_pred ? "MATCH!" : "MISMATCH!");
        if (pred != pt_pred) { free(buf0); free(buf1); free(buf2); return 1; }
    } else {
        printf("(No pytorch_outputs_t4.bin found)\n");
    }

    free(buf0); free(buf1); free(buf2);
    printf("\nC-Simulation PASSED.\n");
    return 0;
}
