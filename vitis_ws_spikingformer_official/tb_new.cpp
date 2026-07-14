#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ap_int.h>
#include <dirent.h>

void control(ap_int<32> v0[91189248], ap_int<32> v1[91189248], ap_int<32> v2[91189248]);

int main() {
    const size_t N = 91189248;
    ap_int<32>* buf0 = (ap_int<32>*)calloc(N, sizeof(ap_int<32>));
    ap_int<32>* buf1 = (ap_int<32>*)calloc(N, sizeof(ap_int<32>));
    ap_int<32>* buf2 = (ap_int<32>*)calloc(N, sizeof(ap_int<32>));
    if (!buf0 || !buf1 || !buf2) { printf("calloc failed\n"); return 1; }

    // Auto-generate weight loading from bin files
    const char* bindir = "TBEOF"

echo "BINS_DIR" >> /home/hwx/HCA/FPGA-SNN/vitis_ws/vitis_ws_spikingformer_official/tb_new.cpp
# Too complex to inline. Use Python to generate the full tb
python3 << 'PYEOF'
import os, struct, re
bins_dir = '/home/hwx/HCA/FPGA-SNN/spikingjelly2onnx/examples/spikformer/result/gen/bins'

# Read mem_init_ext to get offset mapping
txt = open('/home/hwx/HCA/FPGA-SNN/spikingjelly2onnx/examples/spikformer/result/gen/host/mem_init_ext.cpp').read()
entries = []
for m in re.finditer(r'memcpy\(\(void\*\)\(HCA_DDR_BASE \+ (\d+)\),\s*\(void\*\)\((const_\d+)\),\s*(\d+)\);', txt):
    entries.append((int(m.group(1)), m.group(2), int(m.group(3))))

# Generate testbench
tb = '''#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ap_int.h>

void control(ap_int<32> v0[91189248], ap_int<32> v1[91189248], ap_int<32> v2[91189248]);

int main() {
    printf("=== Spikingformer v1.2 Real Weights Test ===\\n");
    const size_t N = 91189248;
    ap_int<32>* buf0 = (ap_int<32>*)calloc(N, sizeof(ap_int<32>));
    ap_int<32>* buf1 = (ap_int<32>*)calloc(N, sizeof(ap_int<32>));
    ap_int<32>* buf2 = (ap_int<32>*)calloc(N, sizeof(ap_int<32>));
    if (!buf0 || !buf1 || !buf2) { printf("malloc fail\\n"); return 1; }

    // Weight table from mem_init_ext
    const char* bindir = "{BINS_DIR}";
    struct { const char* fn; size_t off; size_t sz; } wts[] = {{
'''

for offset, name, size in sorted(entries):
    tb += f'        {{"{name}.bin", {offset}, {size}}},\n'

tb += '''        {nullptr, 0, 0}
    };

    // Load weights into buf2
    printf("Loading %d weights...\\n", (int)(sizeof(wts)/sizeof(wts[0])-1));
    char path[1024];
    for (int i = 0; wts[i].fn; i++) {
        snprintf(path, sizeof(path), "%s/%s", bindir, wts[i].fn);
        FILE* fp = fopen(path, "rb");
        if (!fp) { printf("Missing: %s\\n", wts[i].fn); continue; }
        fread((char*)buf2 + wts[i].off, 1, wts[i].sz, fp);
        fclose(fp);
    }
    printf("Weights loaded.\\n");

    // Load real CIFAR-10 image
    float* img = (float*)buf0;
    FILE* fi = fopen("/tmp/cifar10_real_img.bin", "rb");
    if (!fi) { printf("No image\\n"); return 1; }
    fread(img, sizeof(float), 3*32*32, fi);
    fclose(fi);
    printf("Image loaded: [0]=%.3f\\n", img[0]);

    // T=4 simulation
    for (int t = 0; t < 4; t++) {
        control(buf0, buf1, buf2);
        float* out = (float*)(buf0 + 6906624);
        printf("T=%d: class= ", t+1);
        int pred = 0;
        for (int i = 0; i < 10; i++) { if (out[i] > out[pred]) pred = i; printf("%.4f ", out[i]); }
        printf("-> %d\\n", pred);
    }

    free(buf0); free(buf1); free(buf2);
    printf("=== DONE ===\\n");
    return 0;
}
'''
tb = tb.replace('{BINS_DIR}', bins_dir)
with open('/home/hwx/HCA/FPGA-SNN/vitis_ws/vitis_ws_spikingformer_official/tb_new.cpp', 'w') as f:
    f.write(tb)
print(f"Generated tb_new.cpp with {len(entries)} weight entries")
PYEOF

cat > /home/hwx/HCA/FPGA-SNN/vitis_ws/vitis_ws_spikingformer_official/run_new.tcl << 'TCL'
open_project -reset sf_new_real
set_top control
add_files hls_new_ddr.cpp
add_files -tb tb_new.cpp
open_solution solution1
set_part {xczu7ev-ffvc1156-2-e}
create_clock -period 10 -name default
csim_design
exit
TCL

source /data/YellowSmile/AMD/2025.2/Vitis/settings64.sh
cd /home/hwx/HCA/FPGA-SNN/vitis_ws/vitis_ws_spikingformer_official
vitis-run --mode hls --tcl run_new.tcl 2>&1 | grep -E "T=|Image|weights|error|Error|class|Class"
