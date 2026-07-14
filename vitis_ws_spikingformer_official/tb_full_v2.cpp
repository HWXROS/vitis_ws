#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ap_int.h>

void control(
  ap_int<32> v944[91189248],
  ap_int<32> v945[91189248],
  ap_int<32> v946[91189248]
);

int main() {
    printf("=== Spikingformer Official C-Simulation ===\n");

    // Use static allocation via malloc (too large for stack)
    ap_int<32>* buf0 = (ap_int<32>*)calloc(91189248, sizeof(ap_int<32>));
    ap_int<32>* buf1 = (ap_int<32>*)calloc(91189248, sizeof(ap_int<32>));
    ap_int<32>* buf2 = (ap_int<32>*)calloc(91189248, sizeof(ap_int<32>));
    if (!buf0 || !buf1 || !buf2) { 
        printf("calloc failed!\n"); 
        free(buf0); free(buf1); free(buf2);
        return 1; 
    }

    // Load weights
    const char* bins = "/home/hwx/HCA/FPGA-SNN/FastHCA/gen-mlir2hls/spikingformer_official/output/gen/bins";
    struct { const char* fn; ap_int<32>* buf; size_t off; size_t sz; } wts[] = {
        {"const_61.bin", buf2, 0, 192},  {"const_62.bin", buf2, 4243456, 5184},
        {"const_63.bin", buf2, 8486912, 384}, {"const_64.bin", buf2, 12730368, 165888},
        {"const_65.bin", buf2, 16973824, 768}, {"const_66.bin", buf2, 21217280, 663552},
        {"const_67.bin", buf2, 25460736, 1536}, {"const_68.bin", buf2, 29704192, 2654208},
        {"const_69.bin", buf2, 33947648, 1536}, {"const_70.bin", buf2, 38191104, 2654208},
        {"const_71.bin", buf2, 42434560, 1536}, {"const_72.bin", buf2, 46678016, 589824},
        {"const_73.bin", buf2, 50921472, 1536}, {"const_74.bin", buf2, 55164928, 589824},
        {"const_75.bin", buf2, 59408384, 1536}, {"const_76.bin", buf2, 63651840, 589824},
        {"const_77.bin", buf2, 67895296, 4},   {"const_78.bin", buf2, 72138752, 1536},
        {"const_79.bin", buf2, 76382208, 589824}, {"const_80.bin", buf2, 80625664, 6144},
        {"const_81.bin", buf2, 84869120, 2359296}, {"const_82.bin", buf2, 89112576, 1536},
        {"const_83.bin", buf2, 93356032, 2359296}, {"const_84.bin", buf2, 97599488, 1536},
        {"const_85.bin", buf2, 101842944, 589824}, {"const_86.bin", buf2, 106127360, 1536},
        {"const_87.bin", buf2, 110411776, 589824}, {"const_88.bin", buf2, 114696192, 1536},
        {"const_89.bin", buf2, 118980608, 589824}, {"const_90.bin", buf2, 123265024, 1536},
        {"const_91.bin", buf2, 127549440, 589824}, {"const_92.bin", buf2, 133169152, 6144},
        {"const_93.bin", buf2, 138788864, 2359296}, {"const_94.bin", buf2, 144408576, 1536},
        {"const_95.bin", buf2, 150028288, 2359296}, {"const_96.bin", buf2, 155648000, 1536},
        {"const_97.bin", buf2, 161267712, 589824}, {"const_98.bin", buf2, 166887424, 1536},
        {"const_99.bin", buf2, 172507136, 589824}, {"const_100.bin", buf2, 178126848, 1536},
        {"const_101.bin", buf2, 183746560, 589824}, {"const_102.bin", buf2, 189366272, 1536},
        {"const_103.bin", buf2, 194985984, 589824}, {"const_104.bin", buf2, 200605696, 6144},
        {"const_105.bin", buf2, 206225408, 2359296}, {"const_106.bin", buf2, 211845120, 1536},
        {"const_107.bin", buf2, 217464832, 2359296}, {"const_108.bin", buf2, 223084544, 1536},
        {"const_109.bin", buf2, 228704256, 589824}, {"const_110.bin", buf2, 234323968, 1536},
        {"const_111.bin", buf2, 239943680, 589824}, {"const_112.bin", buf2, 245563392, 1536},
        {"const_113.bin", buf2, 251183104, 589824}, {"const_114.bin", buf2, 256802816, 1536},
        {"const_115.bin", buf2, 262422528, 589824}, {"const_116.bin", buf2, 268042240, 6144},
        {"const_117.bin", buf2, 273661952, 2359296}, {"const_118.bin", buf2, 279281664, 1536},
        {"const_119.bin", buf2, 284901376, 2359296}, {"const_120.bin", buf2, 290521088, 15360},
        {"const_121.bin", buf2, 294960128, 40}, {nullptr, nullptr, 0, 0}
    };

    printf("Loading weights...\n");
    char path[1024];
    for (int i = 0; wts[i].fn; i++) {
        snprintf(path, sizeof(path), "%s/%s", bins, wts[i].fn);
        FILE* fp = fopen(path, "rb");
        if (!fp) { printf("Missing: %s\n", wts[i].fn); continue; }
        fread((char*)wts[i].buf + wts[i].off, 1, wts[i].sz, fp);
        fclose(fp);
    }
    printf("Weights loaded.\n");

    // Input: test pattern at buf0[0] (reinterpret_cast float(*)[3][32][32])
    float* input = (float*)buf0;
    for (int i = 0; i < 3*32*32; i++) input[i] = 0.01f * (i % 100);

    printf("Running control()...\n");
    control(buf0, buf1, buf2);
    printf("Done.\n");

    // Output: reinterpret_cast float(*)[10] at buf0 + 6906624
    float* out = (float*)(buf0 + 6906624);
    printf("Output: ");
    int pred = 0;
    for (int i = 0; i < 10; i++) {
        printf("%.4f ", out[i]);
        if (out[i] > out[pred]) pred = i;
    }
    printf("\nPredicted class: %d\n", pred);

    float norm = 0; for (int i=0;i<10;i++) norm += out[i]*out[i];
    printf("Output norm: %.6f\n", norm);

    free(buf0); free(buf1); free(buf2);
    printf("=== PASS ===\n");
    return 0;
}
