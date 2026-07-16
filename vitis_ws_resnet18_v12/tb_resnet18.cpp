#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ap_int.h>

void control(ap_int<32> v0[118502656], ap_int<32> v1[118502656], ap_int<32> v2[118502656]);

int load_buf(const char* path, ap_int<32>* buf, int n) {
    FILE* f = fopen(path, "rb");
    if (!f) { printf("Failed to open %s\n", path); return 1; }
    size_t r = fread(buf, sizeof(ap_int<32>), n, f);
    fclose(f);
    if ((int)r != n) { printf("Short read %s: %zu/%d\n", path, r, n); return 1; }
    return 0;
}

int main() {
    printf("=== ResNet18 v1.2 T=4 C-Simulation (ImageNet, 1000 classes) ===\n");

    ap_int<32>* buf0 = (ap_int<32>*)malloc(118502656 * sizeof(ap_int<32>));
    ap_int<32>* buf1 = (ap_int<32>*)malloc(118502656 * sizeof(ap_int<32>));
    ap_int<32>* buf2 = (ap_int<32>*)malloc(118502656 * sizeof(ap_int<32>));
    if (!buf0 || !buf1 || !buf2) { printf("OOM\n"); return 1; }

    memset(buf0, 0, 118502656 * sizeof(ap_int<32>));
    memset(buf1, 0, 118502656 * sizeof(ap_int<32>));

    // Load weights into buf2 (v700 equivalent)
    if (load_buf("v700_weights.bin", buf2, 118502656)) return 1;

    // Load test image into buf0 (v698, input at offset 0: [3][224][224] = 150528 floats)
    if (load_buf("test_image.bin", buf0, 150528)) return 1;

    // T=4: call control() 4 times, IF states persist in DDR (buf1)
    float accum[1000] = {0};
    for (int t = 0; t < 4; t++) {
        control(buf0, buf1, buf2);
        // Output logits at v698 + 14450688 (v815), float[1000]
        float* out = reinterpret_cast<float*>(buf0 + 14450688);
        printf("T=%d top5: ", t + 1);
        // Find top-5
        int top5[5] = {0};
        for (int i = 0; i < 5; i++) {
            int best = -1;
            for (int j = 0; j < 1000; j++) {
                // Skip already listed
                int already = 0;
                for (int k = 0; k < i; k++)
                    if (top5[k] == j) { already = 1; break; }
                if (already) continue;
                if (best < 0 || out[j] > out[best]) best = j;
            }
            top5[i] = best;
            printf("%s%d(%.2f)", i > 0 ? " " : "", best, out[best]);
        }
        printf("\n");

        // Accumulate
        for (int i = 0; i < 1000; i++)
            accum[i] += out[i];
    }

    // Average
    printf("\nT=4 averaged top5: ");
    for (int i = 0; i < 1000; i++) accum[i] /= 4.0f;
    int top5_avg[5] = {0};
    for (int i = 0; i < 5; i++) {
        int best = -1;
        for (int j = 0; j < 1000; j++) {
            int already = 0;
            for (int k = 0; k < i; k++)
                if (top5_avg[k] == j) { already = 1; break; }
            if (already) continue;
            if (best < 0 || accum[j] > accum[best]) best = j;
        }
        top5_avg[i] = best;
        printf("%s%d(%.2f)", i > 0 ? " " : "", best, accum[best]);
    }
    printf("\n");

    // Compare with PyTorch T=4 reference
    float pytorch[1000];
    FILE* pf = fopen("pytorch_outputs_t4.bin", "rb");
    if (pf) {
        fread(pytorch, sizeof(float), 1000, pf);
        fclose(pf);

        // Find PyTorch top5
        int pt_top5[5] = {0};
        for (int i = 0; i < 5; i++) {
            int best = -1;
            for (int j = 0; j < 1000; j++) {
                int already = 0;
                for (int k = 0; k < i; k++)
                    if (pt_top5[k] == j) { already = 1; break; }
                if (already) continue;
                if (best < 0 || pytorch[j] > pytorch[best]) best = j;
            }
            pt_top5[i] = best;
        }

        printf("\nPyTorch T=4 top5: ");
        for (int i = 0; i < 5; i++)
            printf("%s%d(%.2f)", i > 0 ? " " : "", pt_top5[i], pytorch[pt_top5[i]]);
        printf("\n");

        // Compute max error
        float max_err = 0;
        int max_err_idx = -1;
        for (int i = 0; i < 1000; i++) {
            float err = fabs(accum[i] - pytorch[i]);
            if (err > max_err) { max_err = err; max_err_idx = i; }
        }
        printf("Max abs error: %.6f (idx %d, csim=%.4f, pt=%.4f)\n",
               max_err, max_err_idx, accum[max_err_idx], pytorch[max_err_idx]);

        // Count close matches
        int close = 0, very_close = 0;
        for (int i = 0; i < 1000; i++) {
            float err = fabs(accum[i] - pytorch[i]);
            if (err < 1e-3) very_close++;
            if (err < 1e-2) close++;
        }
        printf("Close (<1e-2): %d/1000, Very close (<1e-3): %d/1000\n",
               close, very_close);

        // Argmax comparison
        int csim_pred = 0, pt_pred = 0;
        for (int i = 1; i < 1000; i++) {
            if (accum[i] > accum[csim_pred]) csim_pred = i;
            if (pytorch[i] > pytorch[pt_pred]) pt_pred = i;
        }
        printf("PyTorch pred: %d, C-Sim pred: %d %s\n",
               pt_pred, csim_pred,
               csim_pred == pt_pred ? "MATCH!" : "MISMATCH!");
    } else {
        printf("(No pytorch_outputs_t4.bin found)\n");
    }

    free(buf0);
    free(buf1);
    free(buf2);
    printf("\nC-Simulation completed.\n");
    return 0;
}
