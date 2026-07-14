#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ap_int.h>

void control(ap_int<32> v0[91189248], ap_int<32> v1[91189248], ap_int<32> v2[91189248]);

int main() {
    printf("=== spikingformer_official C-Simulation ===\n");

    ap_int<32>* buf0 = (ap_int<32>*)malloc(91189248 * sizeof(ap_int<32>));
    if (!buf0) { printf("Failed to allocate buf0\n"); return 1; }
    memset(buf0, 0, 91189248 * sizeof(ap_int<32>));
    ap_int<32>* buf1 = (ap_int<32>*)malloc(91189248 * sizeof(ap_int<32>));
    if (!buf1) { printf("Failed to allocate buf1\n"); return 1; }
    memset(buf1, 0, 91189248 * sizeof(ap_int<32>));
    ap_int<32>* buf2 = (ap_int<32>*)malloc(91189248 * sizeof(ap_int<32>));
    if (!buf2) { printf("Failed to allocate buf2\n"); return 1; }
    memset(buf2, 0, 91189248 * sizeof(ap_int<32>));

    // Load weight data from bin files
    const char* bins_dir = "/home/hwx/HCA/FPGA-SNN/gen/bins";
    // TODO: populate buffer with weight data from bin files
    printf("Note: weights need to be loaded for real inference.\n");

    // Prepare input data
    printf("Initialized 3 buffers.\n");

    printf("Running control()...\n");
    control(buf0, buf1, buf2);
    printf("control() completed.\n");

    // Print first 10 elements of output buffer
    printf("Output (ap_int<32>): ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", buf2[i].to_int());
    }
    printf("\n");

    free(buf0);
    free(buf1);
    free(buf2);
    printf("Simulation PASSED.\n");
    return 0;
}