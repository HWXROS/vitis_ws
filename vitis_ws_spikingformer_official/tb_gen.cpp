#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ap_int.h>

void control(ap_int<32>* buf0, ap_int<32>* buf1, ap_int<32>* buf2);

const size_t N = 91189248;

struct WeightInfo { const char* fn; size_t off; size_t sz; };

int main() {
    ap_int<32>* buf0 = (ap_int<32>*)calloc(N, sizeof(ap_int<32>));
    ap_int<32>* buf1 = (ap_int<32>*)calloc(N, sizeof(ap_int<32>));
    ap_int<32>* buf2 = (ap_int<32>*)calloc(N, sizeof(ap_int<32>));

    char bindir[] = "/home/hwx/HCA/FPGA-SNN/FastHCA/gen-mlir2hls/spikingformer_official/output/gen/bins";
    WeightInfo w[62] = {
        {"const_121.bin", 40943616, 40},
        {"const_120.bin", 46252032, 15360},
        {"const_118.bin", 51560448, 1536},
        {"const_119.bin", 56868864, 2359296},
        {"const_116.bin", 62177280, 6144},
        {"const_117.bin", 67485696, 2359296},
        {"const_114.bin", 72794112, 1536},
        {"const_115.bin", 78102528, 589824},
        {"const_112.bin", 83410944, 1536},
        {"const_113.bin", 88719360, 589824},
        {"const_110.bin", 94027776, 1536},
        {"const_111.bin", 99336192, 589824},
        {"const_108.bin", 104644608, 1536},
        {"const_109.bin", 109953024, 589824},
        {"const_106.bin", 115261440, 1536},
        {"const_107.bin", 120569856, 2359296},
        {"const_104.bin", 125878272, 6144},
        {"const_105.bin", 131186688, 2359296},
        {"const_102.bin", 136495104, 1536},
        {"const_103.bin", 141803520, 589824},
        {"const_100.bin", 147111936, 1536},
        {"const_101.bin", 152420352, 589824},
        {"const_98.bin", 157728768, 1536},
        {"const_99.bin", 163037184, 589824},
        {"const_96.bin", 168345600, 1536},
        {"const_97.bin", 173654016, 589824},
        {"const_94.bin", 178962432, 1536},
        {"const_95.bin", 184270848, 2359296},
        {"const_92.bin", 189579264, 6144},
        {"const_93.bin", 194887680, 2359296},
        {"const_90.bin", 200196096, 1536},
        {"const_91.bin", 205504512, 589824},
        {"const_88.bin", 210812928, 1536},
        {"const_89.bin", 216121344, 589824},
        {"const_86.bin", 221429760, 1536},
        {"const_87.bin", 226738176, 589824},
        {"const_84.bin", 232046592, 1536},
        {"const_85.bin", 237355008, 589824},
        {"const_82.bin", 242663424, 1536},
        {"const_83.bin", 247971840, 2359296},
        {"const_80.bin", 253280256, 6144},
        {"const_81.bin", 258588672, 2359296},
        {"const_78.bin", 263897088, 1536},
        {"const_79.bin", 269205504, 589824},
        {"const_75.bin", 274513920, 1536},
        {"const_76.bin", 279822336, 589824},
        {"const_73.bin", 285130752, 1536},
        {"const_74.bin", 290439168, 589824},
        {"const_71.bin", 295747584, 1536},
        {"const_72.bin", 301056000, 589824},
        {"const_69.bin", 306364416, 1536},
        {"const_70.bin", 311672832, 5308416},
        {"const_67.bin", 316981248, 1536},
        {"const_68.bin", 322289664, 2654208},
        {"const_65.bin", 327598080, 768},
        {"const_66.bin", 332906496, 663552},
        {"const_63.bin", 338214912, 384},
        {"const_64.bin", 343523328, 165888},
        {"const_61.bin", 348831744, 192},
        {"const_62.bin", 354140160, 5184},
        {"const_77.bin", 359448576, 4},
        {nullptr, 0, 0}
    };

    printf("Loading %d weights...\n", (int)(sizeof(w)/sizeof(w[0])-1));
    char path[1024];
    for (int i = 0; w[i].fn; i++) {
        snprintf(path, sizeof(path), "%s/%s", bindir, w[i].fn);
        FILE* fp = fopen(path, "rb");
        if (!fp) { printf("Missing: %s\n", w[i].fn); continue; }
        fread((char*)buf2 + w[i].off, 1, w[i].sz, fp);
        fclose(fp);
    }
    FILE* fimg;  printf("Loaded.\n");
    
    // Test input pattern
    float* img = (float*)buf0; printf("Input at buf0+0: img[0]=%.4f img[100]=%.4f\n", img[0], img[100]);
    FILE* fi = fopen("/tmp/cifar10_real_img.bin", "rb"); fread(img, sizeof(float), 3*32*32, fi); fclose(fi);
    printf("Real image loaded: img[0]=%.3f img[100]=%.3f img[500]=%.3f\n", img[0], img[100], img[500]);
    
    printf("Running T=4...\n");
    for (int t = 0; t < 4; t++) {
        control(buf0, buf1, buf2);
        float* dbg = (float*)(buf0 + 6906624);
        printf("T=%d: out[0]=%.4f out[5]=%.4f\n", t+1, dbg[0], dbg[5]);
    }
    
    float* out = (float*)(buf0 + 6906624);
    printf("Output: ");
    int pred = 0;
    for (int i = 0; i < 10; i++) {
        printf("%.4f ", out[i]);
        if (out[i] > out[pred]) pred = i;
    }
    printf("\nClass: %d\n", pred);
    
    free(buf0); free(buf1); free(buf2);
    return 0;
}

