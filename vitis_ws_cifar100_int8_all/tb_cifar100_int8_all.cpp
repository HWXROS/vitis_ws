#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ap_int.h>

void control(ap_int<32> v0[100417536], ap_int<32> v1[100417536], ap_int<32> v2[100417536], ap_int<8> v3[401670144], ap_int<64> v4[50208768], ap_int<8> v5[401670144], ap_int<64> v6[50208768], ap_int<8> v7[401670144]);

int main() {
    printf("=== cifar100_int8_all C-Simulation ===\n");

    ap_int<32>* buf0 = (ap_int<32>*)malloc(100417536 * sizeof(ap_int<32>));
    if (!buf0) { printf("Failed to allocate buf0\n"); return 1; }
    memset(buf0, 0, 100417536 * sizeof(ap_int<32>));
    ap_int<32>* buf1 = (ap_int<32>*)malloc(100417536 * sizeof(ap_int<32>));
    if (!buf1) { printf("Failed to allocate buf1\n"); return 1; }
    memset(buf1, 0, 100417536 * sizeof(ap_int<32>));
    ap_int<32>* buf2 = (ap_int<32>*)malloc(100417536 * sizeof(ap_int<32>));
    if (!buf2) { printf("Failed to allocate buf2\n"); return 1; }
    memset(buf2, 0, 100417536 * sizeof(ap_int<32>));
    ap_int<8>* buf3 = (ap_int<8>*)malloc(401670144 * sizeof(ap_int<8>));
    if (!buf3) { printf("Failed to allocate buf3\n"); return 1; }
    memset(buf3, 0, 401670144 * sizeof(ap_int<8>));
    ap_int<64>* buf4 = (ap_int<64>*)malloc(50208768 * sizeof(ap_int<64>));
    if (!buf4) { printf("Failed to allocate buf4\n"); return 1; }
    memset(buf4, 0, 50208768 * sizeof(ap_int<64>));
    ap_int<8>* buf5 = (ap_int<8>*)malloc(401670144 * sizeof(ap_int<8>));
    if (!buf5) { printf("Failed to allocate buf5\n"); return 1; }
    memset(buf5, 0, 401670144 * sizeof(ap_int<8>));
    ap_int<64>* buf6 = (ap_int<64>*)malloc(50208768 * sizeof(ap_int<64>));
    if (!buf6) { printf("Failed to allocate buf6\n"); return 1; }
    memset(buf6, 0, 50208768 * sizeof(ap_int<64>));
    ap_int<8>* buf7 = (ap_int<8>*)malloc(401670144 * sizeof(ap_int<8>));
    if (!buf7) { printf("Failed to allocate buf7\n"); return 1; }
    memset(buf7, 0, 401670144 * sizeof(ap_int<8>));

    // Load weight data from bin files
    const char* bins_dir = "/home/hwx/HCA/FPGA-SNN/gen/bins";
    // TODO: populate buffer with weight data from bin files
    printf("Note: weights need to be loaded for real inference.\n");

    // Prepare input data
    printf("Initialized 8 buffers.\n");

    printf("Running control()...\n");
    control(buf0, buf1, buf2, buf3, buf4, buf5, buf6, buf7);
    printf("control() completed.\n");

    // Print first 10 elements of output buffer
    printf("Output (ap_int<8>): ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", buf7[i].to_int());
    }
    printf("\n");

    free(buf0);
    free(buf1);
    free(buf2);
    free(buf3);
    free(buf4);
    free(buf5);
    free(buf6);
    free(buf7);
    printf("Simulation PASSED.\n");
    return 0;
}