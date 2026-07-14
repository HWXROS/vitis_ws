
//===-----------------------------------------------------===//
//                     FHCA HLS AutoGen                      //
//===-----------------------------------------------------===//
    
#include <algorithm>
#include <ap_axi_sdata.h>
#include <ap_fixed.h>
#include <ap_int.h>
#include <hls_math.h>
#include <hls_stream.h>
#include <math.h>
#include <stdint.h>
#include <string.h>
    
using namespace std;
    
void kernel0(
  float v0[100],
  float v1[1][100]
) {	// L2
  for (int v2 = 0; v2 < 100; v2 += 1) {	// L3
    #pragma HLS pipeline II=1
    #pragma HLS dependence false variable=v1
    #pragma HLS dependence false variable=v0
    float v3 = v1[0][v2];	// L4
    float v4 = v0[v2];	// L5
    float v5 = v3 + v4;	// L6
    v1[0][v2] = v5;	// L7
  }
}

void kernel1(
  float v6[100],
  float v7[100]
) {	// L11
  for (int v8 = 0; v8 < 100; v8 += 1) {	// L12
    #pragma HLS pipeline II=1
    #pragma HLS dependence false variable=v7
    #pragma HLS dependence false variable=v6
    float v9 = v7[v8];	// L13
    float v10 = v6[v8];	// L14
    float v11 = v9 * v10;	// L15
    v7[v8] = v11;	// L16
  }
}

void kernel2(
  ap_int<32> v12[100],
  float v13[100]
) {	// L20
  for (int v14 = 0; v14 < 100; v14 += 1) {	// L21
    #pragma HLS pipeline II=1
    #pragma HLS dependence false variable=v12
    #pragma HLS dependence false variable=v13
    ap_int<32> v15 = v12[v14];	// L22
    float v16 = v15;	// L23
    v13[v14] = v16;	// L24
  }
}

void kernel3(
  float v17[1][100],
  float v18[1][100]
) {	// L28
  for (int v19 = 0; v19 < 100; v19 += 1) {	// L29
    #pragma HLS pipeline II=1
    #pragma HLS dependence false variable=v18
    #pragma HLS dependence false variable=v17
    float v20 = v18[0][v19];	// L30
    float v21 = v17[0][v19];	// L31
    float v22 = v20 * v21;	// L32
    v18[0][v19] = v22;	// L33
  }
}

void kernel4(
  ap_int<32> v23[1][100],
  float v24[1][100]
) {	// L37
  for (int v25 = 0; v25 < 100; v25 += 1) {	// L38
    #pragma HLS pipeline II=1
    #pragma HLS dependence false variable=v23
    #pragma HLS dependence false variable=v24
    ap_int<32> v26 = v23[0][v25];	// L39
    float v27 = v26;	// L40
    v24[0][v25] = v27;	// L41
  }
}

void kernel5(
  ap_int<64> v28[1][100],
  ap_int<32> v29[1][100]
) {	// L45
  for (int v30 = 0; v30 < 100; v30 += 1) {	// L46
    #pragma HLS pipeline II=1
    #pragma HLS dependence false variable=v28
    #pragma HLS dependence false variable=v29
    ap_int<64> v31 = v28[0][v30];	// L47
    ap_int<32> v32 = v31;	// L48
    v29[0][v30] = v32;	// L49
  }
}

void kernel6(
  ap_int<32> v33[1][384],
  ap_int<32> v34[384][100],
  ap_int<64> v35[1][100]
) {	// L53
  ap_int<32> v36[1][384];	// L54
  #pragma HLS resource variable=v36 core=ram_t2p_bram

  memcpy(v36, v33, 384 * sizeof(ap_int<32>));	// L55

  for (int v37 = 0; v37 < 384; v37 += 1) {	// L56
    for (int v38 = 0; v38 < 100; v38 += 1) {	// L57
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v36
      #pragma HLS dependence false variable=v34
      #pragma HLS dependence false variable=v35
      ap_int<32> v39 = v36[0][v37];	// L58
      ap_int<32> v40 = v34[v37][v38];	// L59
      ap_int<64> v41 = v35[0][v38];	// L60
      ap_int<64> v42 = v39;	// L61
      ap_int<64> v43 = v40;	// L62
      ap_int<64> v44 = v42 * v43;	// L63
      ap_int<64> v45 = v41 + v44;	// L64
      v35[0][v38] = v45;	// L65
    }
  }
}

void kernel7(
  ap_int<64> v46[1][100],
  ap_int<64> v47
) {	// L70
  for (int v48 = 0; v48 < 100; v48 += 1) {	// L71
    #pragma HLS pipeline II=1
    #pragma HLS dependence false variable=v46
    v46[0][v48] = v47;	// L72
  }
}

void kernel8(
  ap_int<32> v49[100][384],
  ap_int<32> v50[384][100]
) {	// L76
  for (int v51 = 0; v51 < 384; v51 += 1) {	// L77
    for (int v52 = 0; v52 < 100; v52 += 1) {	// L78
      ap_int<32> v53 = v49[v52][v51];	// L79
      v50[v51][v52] = v53;	// L80
    }
  }
}

void kernel9(
  ap_int<8> v54[100][384],
  ap_int<32> v55[100][384]
) {	// L85
  for (int v56 = 0; v56 < 100; v56 += 1) {	// L86
    for (int v57 = 0; v57 < 384; v57 += 1) {	// L87
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v54
      #pragma HLS dependence false variable=v55
      ap_int<8> v58 = v54[v56][v57];	// L88
      ap_int<32> v59 = v58;	// L89
      v55[v56][v57] = v59;	// L90
    }
  }
}

void kernel10(
  ap_int<8> v60[1][384],
  ap_int<32> v61[1][384]
) {	// L95
  for (int v62 = 0; v62 < 384; v62 += 1) {	// L96
    #pragma HLS pipeline II=1
    #pragma HLS dependence false variable=v60
    #pragma HLS dependence false variable=v61
    ap_int<8> v63 = v60[0][v62];	// L97
    ap_int<32> v64 = v63;	// L98
    v61[0][v62] = v64;	// L99
  }
}

void kernel11(
  float v65[1][384],
  ap_int<8> v66[1][384]
) {	// L103
  for (int v67 = 0; v67 < 384; v67 += 1) {	// L104
    #pragma HLS pipeline II=1
    #pragma HLS dependence false variable=v65
    #pragma HLS dependence false variable=v66
    float v68 = v65[0][v67];	// L105
    ap_int<8> v69 = v68;	// L106
    v66[0][v67] = v69;	// L107
  }
}

void kernel12(
  float v70[1][384],
  float v71,
  float v72
) {	// L111
  for (int v73 = 0; v73 < 384; v73 += 1) {	// L112
    #pragma HLS pipeline II=1
    #pragma HLS dependence false variable=v70
    float v74 = v70[0][v73];	// L113
    bool v75 = v74 < v72;	// L114
    float v76 = v75 ? v72 : v74;	// L115
    bool v77 = v76 > v71;	// L116
    float v78 = v77 ? v71 : v76;	// L117
    v70[0][v73] = v78;	// L118
  }
}

void kernel13(
  float v79[1][384]
) {	// L122
  for (int v80 = 0; v80 < 384; v80 += 1) {	// L123
    #pragma HLS pipeline II=1
    #pragma HLS dependence false variable=v79
    float v81 = v79[0][v80];	// L124
    float v82 = round(v81);	// L125
    v79[0][v80] = v82;	// L126
  }
}

void kernel14(
  float v83[1][384],
  float v84
) {	// L130
  for (int v85 = 0; v85 < 384; v85 += 1) {	// L131
    #pragma HLS pipeline II=1
    #pragma HLS dependence false variable=v83
    float v86 = v83[0][v85];	// L132
    float v87 = v86 / v84;	// L133
    v83[0][v85] = v87;	// L134
  }
}

void kernel16(
  float v88[1][384][64],
  float v89[1][384]
) {	// L138
  for (int v90 = 0; v90 < 64; v90 += 1) {	// L139
    for (int v91 = 0; v91 < 384; v91 += 1) {	// L140
      float v92 = v88[0][v91][v90];	// L141
      float v93 = v89[0][v91];	// L142
      float v94 = v92 + v93;	// L143
      v89[0][v91] = v94;	// L144
    }
  }
}

void kernel17(
  float v95[1][384],
  float v96
) {	// L149
  for (int v97 = 0; v97 < 384; v97 += 1) {	// L150
    #pragma HLS pipeline II=1
    #pragma HLS dependence false variable=v95
    v95[0][v97] = v96;	// L151
  }
}

void kernel18(
  ap_int<8> v98[1][384][8][8],
  float v99[1][384][64]
) {	// L155
  for (int v100 = 0; v100 < 384; v100 += 1) {	// L156
    for (int v101 = 0; v101 < 64; v101 += 1) {	// L157
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v98
      #pragma HLS dependence false variable=v99
      ap_int<8> v102 = v98[0][v100][(v101 / 8)][(v101 % 8)];	// L158
      float v103 = v102;	// L159
      v99[0][v100][v101] = v103;	// L160
    }
  }
}

void kernel19(
  ap_int<8> v104[1][384][8][8],
  ap_int<8> v105[1][384][8][8]
) {	// L165
  for (int v106 = 0; v106 < 384; v106 += 1) {	// L166
    for (int v107 = 0; v107 < 8; v107 += 1) {	// L167
      for (int v108 = 0; v108 < 8; v108 += 1) {	// L168
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v104
        #pragma HLS dependence false variable=v105
        ap_int<8> v109 = v104[0][v106][v107][v108];	// L169
        ap_int<8> v110 = v105[0][v106][v107][v108];	// L170
        ap_int<8> v111 = v109 + v110;	// L171
        v105[0][v106][v107][v108] = v111;	// L172
      }
    }
  }
}

void kernel20(
  float v112[1][384][8][8],
  float v113[1][384][8][8]
) {	// L178
  for (int v114 = 0; v114 < 384; v114 += 1) {	// L179
    for (int v115 = 0; v115 < 8; v115 += 1) {	// L180
      for (int v116 = 0; v116 < 8; v116 += 1) {	// L181
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v112
        #pragma HLS dependence false variable=v113
        float v117 = v112[0][v114][v115][v116];	// L182
        v113[0][v114][v115][v116] = v117;	// L183
      }
    }
  }
}

void kernel21(
  float v118[1][384][8][8],
  float v119[1][384][8][8]
) {	// L189
  for (int v120 = 0; v120 < 384; v120 += 1) {	// L190
    for (int v121 = 0; v121 < 8; v121 += 1) {	// L191
      for (int v122 = 0; v122 < 8; v122 += 1) {	// L192
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v118
        #pragma HLS dependence false variable=v119
        float v123 = v118[0][v120][v121][v122];	// L193
        float v124 = v119[0][v120][v121][v122];	// L194
        float v125 = v123 + v124;	// L195
        v119[0][v120][v121][v122] = v125;	// L196
      }
    }
  }
}

void kernel22(
  float v126[1][384][8][8],
  float v127[1][384][8][8],
  float v128[1][384][8][8]
) {	// L202
  for (int v129 = 0; v129 < 384; v129 += 1) {	// L203
    for (int v130 = 0; v130 < 8; v130 += 1) {	// L204
      for (int v131 = 0; v131 < 8; v131 += 1) {	// L205
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v127
        #pragma HLS dependence false variable=v128
        #pragma HLS dependence false variable=v126
        float v132 = v127[0][v129][v130][v131];	// L206
        float v133 = v126[0][v129][v130][v131];	// L207
        float v134 = v132 - v133;	// L208
        v128[0][v129][v130][v131] = v134;	// L209
      }
    }
  }
}

void kernel23(
  float v135[1][384][8][8],
  float v136[1][384][8][8],
  float v137
) {	// L215
  for (int v138 = 0; v138 < 384; v138 += 1) {	// L216
    for (int v139 = 0; v139 < 8; v139 += 1) {	// L217
      for (int v140 = 0; v140 < 8; v140 += 1) {	// L218
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v136
        #pragma HLS dependence false variable=v135
        float v141 = v136[0][v138][v139][v140];	// L219
        float v142 = v135[0][v138][v139][v140];	// L220
        bool v143 = v141 >= v137;	// L221
        float v144 = v143 ? v142 : v137;	// L222
        v136[0][v138][v139][v140] = v144;	// L223
      }
    }
  }
}

void kernel24(
  float v145[1][384][8][8],
  ap_int<8> v146[1][384][8][8],
  float v147
) {	// L229
  for (int v148 = 0; v148 < 384; v148 += 1) {	// L230
    for (int v149 = 0; v149 < 8; v149 += 1) {	// L231
      for (int v150 = 0; v150 < 8; v150 += 1) {	// L232
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v145
        #pragma HLS dependence false variable=v146
        float v151 = v145[0][v148][v149][v150];	// L233
        bool v152 = v151 >= v147;	// L234
        ap_int<8> v153 = v152;	// L235
        v146[0][v148][v149][v150] = v153;	// L236
      }
    }
  }
}

void kernel25(
  float v154[1][384][8][8],
  float v155
) {	// L242
  for (int v156 = 0; v156 < 384; v156 += 1) {	// L243
    for (int v157 = 0; v157 < 8; v157 += 1) {	// L244
      for (int v158 = 0; v158 < 8; v158 += 1) {	// L245
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v154
        float v159 = v154[0][v156][v157][v158];	// L246
        float v160 = v159 - v155;	// L247
        v154[0][v156][v157][v158] = v160;	// L248
      }
    }
  }
}

void kernel27(
  float v161[1][384][8][8],
  float v162[1][384][8][8],
  float v163[1][384][8][8]
) {	// L254
  for (int v164 = 0; v164 < 384; v164 += 1) {	// L255
    for (int v165 = 0; v165 < 8; v165 += 1) {	// L256
      for (int v166 = 0; v166 < 8; v166 += 1) {	// L257
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v162
        #pragma HLS dependence false variable=v163
        #pragma HLS dependence false variable=v161
        float v167 = v162[0][v164][v165][v166];	// L258
        float v168 = v161[0][v164][v165][v166];	// L259
        float v169 = v167 + v168;	// L260
        v163[0][v164][v165][v166] = v169;	// L261
      }
    }
  }
}

void kernel28(
  float v170[1][384][8][8],
  float v171
) {	// L267
  for (int v172 = 0; v172 < 384; v172 += 1) {	// L268
    for (int v173 = 0; v173 < 8; v173 += 1) {	// L269
      for (int v174 = 0; v174 < 8; v174 += 1) {	// L270
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v170
        float v175 = v170[0][v172][v173][v174];	// L271
        float v176 = v175 / v171;	// L272
        v170[0][v172][v173][v174] = v176;	// L273
      }
    }
  }
}

void kernel33(
  float v177[384],
  float v178[1][384][8][8],
  float v179[1][384][8][8]
) {	// L279
  float v180[384];	// L280
  #pragma HLS resource variable=v180 core=ram_t2p_bram

  memcpy(v180, v177, 384 * sizeof(float));	// L281

  for (int v181 = 0; v181 < 384; v181 += 1) {	// L282
    for (int v182 = 0; v182 < 8; v182 += 1) {	// L283
      for (int v183 = 0; v183 < 8; v183 += 1) {	// L284
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v178
        #pragma HLS dependence false variable=v179
        #pragma HLS dependence false variable=v180
        float v184 = v178[0][v181][v182][v183];	// L285
        float v185 = v180[v181];	// L286
        float v186 = v184 + v185;	// L287
        v179[0][v181][v182][v183] = v186;	// L288
      }
    }
  }
}

void kernel34(
  float v187[384],
  float v188[384],
  float v189[384]
) {	// L294
  for (int v190 = 0; v190 < 384; v190 += 1) {	// L295
    #pragma HLS pipeline II=1
    #pragma HLS dependence false variable=v188
    #pragma HLS dependence false variable=v189
    #pragma HLS dependence false variable=v187
    float v191 = v188[v190];	// L296
    float v192 = v187[v190];	// L297
    float v193 = v191 * v192;	// L298
    v189[v190] = v193;	// L299
  }
}

void kernel35(
  float v194[1][384][1][1],
  float v195[1][384][8][8]
) {	// L303
  float v196[1][384][1][1];	// L304
  #pragma HLS resource variable=v196 core=ram_t2p_bram

  memcpy(v196, v194, 384 * sizeof(float));	// L305

  for (int v197 = 0; v197 < 384; v197 += 1) {	// L306
    for (int v198 = 0; v198 < 8; v198 += 1) {	// L307
      for (int v199 = 0; v199 < 8; v199 += 1) {	// L308
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v195
        #pragma HLS dependence false variable=v196
        float v200 = v195[0][v197][v198][v199];	// L309
        float v201 = v196[0][v197][0][0];	// L310
        float v202 = v200 * v201;	// L311
        v195[0][v197][v198][v199] = v202;	// L312
      }
    }
  }
}

void kernel36(
  ap_int<32> v203[1][384][8][8],
  float v204[1][384][8][8]
) {	// L318
  for (int v205 = 0; v205 < 384; v205 += 1) {	// L319
    for (int v206 = 0; v206 < 8; v206 += 1) {	// L320
      for (int v207 = 0; v207 < 8; v207 += 1) {	// L321
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v203
        #pragma HLS dependence false variable=v204
        ap_int<32> v208 = v203[0][v205][v206][v207];	// L322
        float v209 = v208;	// L323
        v204[0][v205][v206][v207] = v209;	// L324
      }
    }
  }
}

void kernel37(
  ap_int<64> v210[1][384][8][8],
  ap_int<32> v211[1][384][8][8]
) {	// L330
  for (int v212 = 0; v212 < 384; v212 += 1) {	// L331
    for (int v213 = 0; v213 < 8; v213 += 1) {	// L332
      for (int v214 = 0; v214 < 8; v214 += 1) {	// L333
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v210
        #pragma HLS dependence false variable=v211
        ap_int<64> v215 = v210[0][v212][v213][v214];	// L334
        ap_int<32> v216 = v215;	// L335
        v211[0][v212][v213][v214] = v216;	// L336
      }
    }
  }
}

void kernel38(
  ap_int<32> v217[1][1536][8][8],
  ap_int<32> v218[384][1536][1][1],
  ap_int<64> v219[1][384][8][8]
) {	// L342
  ap_int<32> v220[384][1536][1][1];	// L343
  #pragma HLS resource variable=v220 core=ram_t2p_bram

  memcpy(v220, v218, 589824 * sizeof(ap_int<32>));	// L344

  for (int v221 = 0; v221 < 1536; v221 += 1) {	// L345
    for (int v222 = 0; v222 < 384; v222 += 1) {	// L346
      for (int v223 = 0; v223 < 8; v223 += 1) {	// L347
        for (int v224 = 0; v224 < 8; v224 += 1) {	// L348
          #pragma HLS pipeline II=1
          #pragma HLS dependence false variable=v217
          #pragma HLS dependence false variable=v219
          #pragma HLS dependence false variable=v220
          ap_int<32> v225 = v217[0][v221][v223][v224];	// L349
          ap_int<32> v226 = v220[v222][v221][0][0];	// L350
          ap_int<64> v227 = v219[0][v222][v223][v224];	// L351
          ap_int<64> v228 = v225;	// L352
          ap_int<64> v229 = v226;	// L353
          ap_int<64> v230 = v228 * v229;	// L354
          ap_int<64> v231 = v227 + v230;	// L355
          v219[0][v222][v223][v224] = v231;	// L356
        }
      }
    }
  }
}

void kernel39(
  ap_int<8> v232[384][1536][1][1],
  ap_int<32> v233[384][1536][1][1]
) {	// L363
  for (int v234 = 0; v234 < 384; v234 += 1) {	// L364
    for (int v235 = 0; v235 < 1536; v235 += 1) {	// L365
      ap_int<8> v236 = v232[v234][v235][0][0];	// L366
      ap_int<32> v237 = v236;	// L367
      v233[v234][v235][0][0] = v237;	// L368
    }
  }
}

void kernel40(
  ap_int<8> v238[1][1536][8][8],
  ap_int<32> v239[1][1536][8][8]
) {	// L373
  for (int v240 = 0; v240 < 1536; v240 += 1) {	// L374
    for (int v241 = 0; v241 < 8; v241 += 1) {	// L375
      for (int v242 = 0; v242 < 8; v242 += 1) {	// L376
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v238
        #pragma HLS dependence false variable=v239
        ap_int<8> v243 = v238[0][v240][v241][v242];	// L377
        ap_int<32> v244 = v243;	// L378
        v239[0][v240][v241][v242] = v244;	// L379
      }
    }
  }
}

void kernel41(
  float v245[1][1536][8][8],
  float v246[1][1536][8][8]
) {	// L385
  for (int v247 = 0; v247 < 1536; v247 += 1) {	// L386
    for (int v248 = 0; v248 < 8; v248 += 1) {	// L387
      for (int v249 = 0; v249 < 8; v249 += 1) {	// L388
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v245
        #pragma HLS dependence false variable=v246
        float v250 = v245[0][v247][v248][v249];	// L389
        v246[0][v247][v248][v249] = v250;	// L390
      }
    }
  }
}

void kernel42(
  float v251[1][1536][8][8],
  float v252[1][1536][8][8]
) {	// L396
  for (int v253 = 0; v253 < 1536; v253 += 1) {	// L397
    for (int v254 = 0; v254 < 8; v254 += 1) {	// L398
      for (int v255 = 0; v255 < 8; v255 += 1) {	// L399
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v251
        #pragma HLS dependence false variable=v252
        float v256 = v251[0][v253][v254][v255];	// L400
        float v257 = v252[0][v253][v254][v255];	// L401
        float v258 = v256 + v257;	// L402
        v252[0][v253][v254][v255] = v258;	// L403
      }
    }
  }
}

void kernel43(
  float v259[1][1536][8][8],
  float v260[1][1536][8][8],
  float v261[1][1536][8][8]
) {	// L409
  for (int v262 = 0; v262 < 1536; v262 += 1) {	// L410
    for (int v263 = 0; v263 < 8; v263 += 1) {	// L411
      for (int v264 = 0; v264 < 8; v264 += 1) {	// L412
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v260
        #pragma HLS dependence false variable=v261
        #pragma HLS dependence false variable=v259
        float v265 = v260[0][v262][v263][v264];	// L413
        float v266 = v259[0][v262][v263][v264];	// L414
        float v267 = v265 - v266;	// L415
        v261[0][v262][v263][v264] = v267;	// L416
      }
    }
  }
}

void kernel44(
  float v268[1][1536][8][8],
  float v269[1][1536][8][8],
  float v270
) {	// L422
  for (int v271 = 0; v271 < 1536; v271 += 1) {	// L423
    for (int v272 = 0; v272 < 8; v272 += 1) {	// L424
      for (int v273 = 0; v273 < 8; v273 += 1) {	// L425
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v269
        #pragma HLS dependence false variable=v268
        float v274 = v269[0][v271][v272][v273];	// L426
        float v275 = v268[0][v271][v272][v273];	// L427
        bool v276 = v274 >= v270;	// L428
        float v277 = v276 ? v275 : v270;	// L429
        v269[0][v271][v272][v273] = v277;	// L430
      }
    }
  }
}

void kernel45(
  float v278[1][1536][8][8],
  ap_int<8> v279[1][1536][8][8],
  float v280
) {	// L436
  for (int v281 = 0; v281 < 1536; v281 += 1) {	// L437
    for (int v282 = 0; v282 < 8; v282 += 1) {	// L438
      for (int v283 = 0; v283 < 8; v283 += 1) {	// L439
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v278
        #pragma HLS dependence false variable=v279
        float v284 = v278[0][v281][v282][v283];	// L440
        bool v285 = v284 >= v280;	// L441
        ap_int<8> v286 = v285;	// L442
        v279[0][v281][v282][v283] = v286;	// L443
      }
    }
  }
}

void kernel46(
  float v287[1][1536][8][8],
  float v288
) {	// L449
  for (int v289 = 0; v289 < 1536; v289 += 1) {	// L450
    for (int v290 = 0; v290 < 8; v290 += 1) {	// L451
      for (int v291 = 0; v291 < 8; v291 += 1) {	// L452
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v287
        float v292 = v287[0][v289][v290][v291];	// L453
        float v293 = v292 - v288;	// L454
        v287[0][v289][v290][v291] = v293;	// L455
      }
    }
  }
}

void kernel48(
  float v294[1][1536][8][8],
  float v295[1][1536][8][8],
  float v296[1][1536][8][8]
) {	// L461
  for (int v297 = 0; v297 < 1536; v297 += 1) {	// L462
    for (int v298 = 0; v298 < 8; v298 += 1) {	// L463
      for (int v299 = 0; v299 < 8; v299 += 1) {	// L464
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v295
        #pragma HLS dependence false variable=v296
        #pragma HLS dependence false variable=v294
        float v300 = v295[0][v297][v298][v299];	// L465
        float v301 = v294[0][v297][v298][v299];	// L466
        float v302 = v300 + v301;	// L467
        v296[0][v297][v298][v299] = v302;	// L468
      }
    }
  }
}

void kernel49(
  float v303[1][1536][8][8],
  float v304
) {	// L474
  for (int v305 = 0; v305 < 1536; v305 += 1) {	// L475
    for (int v306 = 0; v306 < 8; v306 += 1) {	// L476
      for (int v307 = 0; v307 < 8; v307 += 1) {	// L477
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v303
        float v308 = v303[0][v305][v306][v307];	// L478
        float v309 = v308 / v304;	// L479
        v303[0][v305][v306][v307] = v309;	// L480
      }
    }
  }
}

void kernel54(
  float v310[1536],
  float v311[1][1536][8][8],
  float v312[1][1536][8][8]
) {	// L486
  float v313[1536];	// L487
  #pragma HLS resource variable=v313 core=ram_t2p_bram

  memcpy(v313, v310, 1536 * sizeof(float));	// L488

  for (int v314 = 0; v314 < 1536; v314 += 1) {	// L489
    for (int v315 = 0; v315 < 8; v315 += 1) {	// L490
      for (int v316 = 0; v316 < 8; v316 += 1) {	// L491
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v311
        #pragma HLS dependence false variable=v312
        #pragma HLS dependence false variable=v313
        float v317 = v311[0][v314][v315][v316];	// L492
        float v318 = v313[v314];	// L493
        float v319 = v317 + v318;	// L494
        v312[0][v314][v315][v316] = v319;	// L495
      }
    }
  }
}

void kernel55(
  float v320[1536],
  float v321[1536],
  float v322[1536]
) {	// L501
  for (int v323 = 0; v323 < 1536; v323 += 1) {	// L502
    #pragma HLS pipeline II=1
    #pragma HLS dependence false variable=v321
    #pragma HLS dependence false variable=v322
    #pragma HLS dependence false variable=v320
    float v324 = v321[v323];	// L503
    float v325 = v320[v323];	// L504
    float v326 = v324 * v325;	// L505
    v322[v323] = v326;	// L506
  }
}

void kernel56(
  float v327[1][1536][1][1],
  float v328[1][1536][8][8]
) {	// L510
  float v329[1][1536][1][1];	// L511
  #pragma HLS resource variable=v329 core=ram_t2p_bram

  memcpy(v329, v327, 1536 * sizeof(float));	// L512

  for (int v330 = 0; v330 < 1536; v330 += 1) {	// L513
    for (int v331 = 0; v331 < 8; v331 += 1) {	// L514
      for (int v332 = 0; v332 < 8; v332 += 1) {	// L515
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v328
        #pragma HLS dependence false variable=v329
        float v333 = v328[0][v330][v331][v332];	// L516
        float v334 = v329[0][v330][0][0];	// L517
        float v335 = v333 * v334;	// L518
        v328[0][v330][v331][v332] = v335;	// L519
      }
    }
  }
}

void kernel57(
  ap_int<32> v336[1][1536][8][8],
  float v337[1][1536][8][8]
) {	// L525
  for (int v338 = 0; v338 < 1536; v338 += 1) {	// L526
    for (int v339 = 0; v339 < 8; v339 += 1) {	// L527
      for (int v340 = 0; v340 < 8; v340 += 1) {	// L528
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v336
        #pragma HLS dependence false variable=v337
        ap_int<32> v341 = v336[0][v338][v339][v340];	// L529
        float v342 = v341;	// L530
        v337[0][v338][v339][v340] = v342;	// L531
      }
    }
  }
}

void kernel58(
  ap_int<64> v343[1][1536][8][8],
  ap_int<32> v344[1][1536][8][8]
) {	// L537
  for (int v345 = 0; v345 < 1536; v345 += 1) {	// L538
    for (int v346 = 0; v346 < 8; v346 += 1) {	// L539
      for (int v347 = 0; v347 < 8; v347 += 1) {	// L540
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v343
        #pragma HLS dependence false variable=v344
        ap_int<64> v348 = v343[0][v345][v346][v347];	// L541
        ap_int<32> v349 = v348;	// L542
        v344[0][v345][v346][v347] = v349;	// L543
      }
    }
  }
}

void kernel59(
  ap_int<32> v350[1][384][8][8],
  ap_int<32> v351[1536][384][1][1],
  ap_int<64> v352[1][1536][8][8]
) {	// L549
  ap_int<32> v353[1536][384][1][1];	// L550
  #pragma HLS resource variable=v353 core=ram_t2p_bram

  memcpy(v353, v351, 589824 * sizeof(ap_int<32>));	// L551

  for (int v354 = 0; v354 < 384; v354 += 1) {	// L552
    for (int v355 = 0; v355 < 1536; v355 += 1) {	// L553
      for (int v356 = 0; v356 < 8; v356 += 1) {	// L554
        for (int v357 = 0; v357 < 8; v357 += 1) {	// L555
          #pragma HLS pipeline II=1
          #pragma HLS dependence false variable=v350
          #pragma HLS dependence false variable=v352
          #pragma HLS dependence false variable=v353
          ap_int<32> v358 = v350[0][v354][v356][v357];	// L556
          ap_int<32> v359 = v353[v355][v354][0][0];	// L557
          ap_int<64> v360 = v352[0][v355][v356][v357];	// L558
          ap_int<64> v361 = v358;	// L559
          ap_int<64> v362 = v359;	// L560
          ap_int<64> v363 = v361 * v362;	// L561
          ap_int<64> v364 = v360 + v363;	// L562
          v352[0][v355][v356][v357] = v364;	// L563
        }
      }
    }
  }
}

void kernel60(
  ap_int<8> v365[1536][384][1][1],
  ap_int<32> v366[1536][384][1][1]
) {	// L570
  for (int v367 = 0; v367 < 1536; v367 += 1) {	// L571
    for (int v368 = 0; v368 < 384; v368 += 1) {	// L572
      ap_int<8> v369 = v365[v367][v368][0][0];	// L573
      ap_int<32> v370 = v369;	// L574
      v366[v367][v368][0][0] = v370;	// L575
    }
  }
}

void kernel61(
  ap_int<8> v371[1][384][8][8],
  ap_int<32> v372[1][384][8][8]
) {	// L580
  for (int v373 = 0; v373 < 384; v373 += 1) {	// L581
    for (int v374 = 0; v374 < 8; v374 += 1) {	// L582
      for (int v375 = 0; v375 < 8; v375 += 1) {	// L583
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v371
        #pragma HLS dependence false variable=v372
        ap_int<8> v376 = v371[0][v373][v374][v375];	// L584
        ap_int<32> v377 = v376;	// L585
        v372[0][v373][v374][v375] = v377;	// L586
      }
    }
  }
}

void kernel62(
  ap_int<8> v378[1][384][64],
  ap_int<8> v379[1][384][8][8],
  ap_int<8> v380[1][384][8][8]
) {	// L592
  for (int v381 = 0; v381 < 384; v381 += 1) {	// L593
    for (int v382 = 0; v382 < 8; v382 += 1) {	// L594
      for (int v383 = 0; v383 < 8; v383 += 1) {	// L595
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v379
        #pragma HLS dependence false variable=v380
        #pragma HLS dependence false variable=v378
        ap_int<8> v384 = v379[0][v381][v382][v383];	// L596
        ap_int<8> v385 = v378[0][v381][((v382 * 8) + v383)];	// L597
        ap_int<8> v386 = v384 + v385;	// L598
        v380[0][v381][v382][v383] = v386;	// L599
      }
    }
  }
}

void kernel63(
  float v387[1][384][64],
  float v388[1][384][64]
) {	// L605
  for (int v389 = 0; v389 < 384; v389 += 1) {	// L606
    for (int v390 = 0; v390 < 64; v390 += 1) {	// L607
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v387
      #pragma HLS dependence false variable=v388
      float v391 = v387[0][v389][v390];	// L608
      v388[0][v389][v390] = v391;	// L609
    }
  }
}

void kernel64(
  float v392[1][384][64],
  float v393[1][384][64]
) {	// L614
  for (int v394 = 0; v394 < 384; v394 += 1) {	// L615
    for (int v395 = 0; v395 < 64; v395 += 1) {	// L616
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v392
      #pragma HLS dependence false variable=v393
      float v396 = v392[0][v394][v395];	// L617
      float v397 = v393[0][v394][v395];	// L618
      float v398 = v396 + v397;	// L619
      v393[0][v394][v395] = v398;	// L620
    }
  }
}

void kernel65(
  float v399[1][384][64],
  float v400[1][384][64],
  float v401[1][384][64]
) {	// L625
  for (int v402 = 0; v402 < 384; v402 += 1) {	// L626
    for (int v403 = 0; v403 < 64; v403 += 1) {	// L627
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v400
      #pragma HLS dependence false variable=v401
      #pragma HLS dependence false variable=v399
      float v404 = v400[0][v402][v403];	// L628
      float v405 = v399[0][v402][v403];	// L629
      float v406 = v404 - v405;	// L630
      v401[0][v402][v403] = v406;	// L631
    }
  }
}

void kernel66(
  float v407[1][384][64],
  float v408[1][384][64],
  float v409
) {	// L636
  for (int v410 = 0; v410 < 384; v410 += 1) {	// L637
    for (int v411 = 0; v411 < 64; v411 += 1) {	// L638
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v408
      #pragma HLS dependence false variable=v407
      float v412 = v408[0][v410][v411];	// L639
      float v413 = v407[0][v410][v411];	// L640
      bool v414 = v412 >= v409;	// L641
      float v415 = v414 ? v413 : v409;	// L642
      v408[0][v410][v411] = v415;	// L643
    }
  }
}

void kernel67(
  float v416[1][384][64],
  ap_int<8> v417[1][384][64],
  float v418
) {	// L648
  for (int v419 = 0; v419 < 384; v419 += 1) {	// L649
    for (int v420 = 0; v420 < 64; v420 += 1) {	// L650
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v416
      #pragma HLS dependence false variable=v417
      float v421 = v416[0][v419][v420];	// L651
      bool v422 = v421 >= v418;	// L652
      ap_int<8> v423 = v422;	// L653
      v417[0][v419][v420] = v423;	// L654
    }
  }
}

void kernel68(
  float v424[1][384][64],
  float v425
) {	// L659
  for (int v426 = 0; v426 < 384; v426 += 1) {	// L660
    for (int v427 = 0; v427 < 64; v427 += 1) {	// L661
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v424
      float v428 = v424[0][v426][v427];	// L662
      float v429 = v428 - v425;	// L663
      v424[0][v426][v427] = v429;	// L664
    }
  }
}

void kernel70(
  float v430[1][384][64],
  float v431[1][384][64],
  float v432[1][384][64]
) {	// L669
  for (int v433 = 0; v433 < 384; v433 += 1) {	// L670
    for (int v434 = 0; v434 < 64; v434 += 1) {	// L671
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v431
      #pragma HLS dependence false variable=v432
      #pragma HLS dependence false variable=v430
      float v435 = v431[0][v433][v434];	// L672
      float v436 = v430[0][v433][v434];	// L673
      float v437 = v435 + v436;	// L674
      v432[0][v433][v434] = v437;	// L675
    }
  }
}

void kernel71(
  float v438[1][384][64],
  float v439
) {	// L680
  for (int v440 = 0; v440 < 384; v440 += 1) {	// L681
    for (int v441 = 0; v441 < 64; v441 += 1) {	// L682
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v438
      float v442 = v438[0][v440][v441];	// L683
      float v443 = v442 / v439;	// L684
      v438[0][v440][v441] = v443;	// L685
    }
  }
}

void kernel76(
  float v444[384],
  float v445[1][384][64],
  float v446[1][384][64]
) {	// L690
  float v447[384];	// L691
  #pragma HLS resource variable=v447 core=ram_t2p_bram

  memcpy(v447, v444, 384 * sizeof(float));	// L692

  for (int v448 = 0; v448 < 384; v448 += 1) {	// L693
    for (int v449 = 0; v449 < 64; v449 += 1) {	// L694
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v445
      #pragma HLS dependence false variable=v446
      #pragma HLS dependence false variable=v447
      float v450 = v445[0][v448][v449];	// L695
      float v451 = v447[v448];	// L696
      float v452 = v450 + v451;	// L697
      v446[0][v448][v449] = v452;	// L698
    }
  }
}

void kernel78(
  float v453[1][384][1],
  float v454[1][384][64]
) {	// L703
  float v455[1][384][1];	// L704
  #pragma HLS resource variable=v455 core=ram_t2p_bram

  memcpy(v455, v453, 384 * sizeof(float));	// L705

  for (int v456 = 0; v456 < 384; v456 += 1) {	// L706
    for (int v457 = 0; v457 < 64; v457 += 1) {	// L707
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v454
      #pragma HLS dependence false variable=v455
      float v458 = v454[0][v456][v457];	// L708
      float v459 = v455[0][v456][0];	// L709
      float v460 = v458 * v459;	// L710
      v454[0][v456][v457] = v460;	// L711
    }
  }
}

void kernel79(
  ap_int<32> v461[1][384][64],
  float v462[1][384][64]
) {	// L716
  for (int v463 = 0; v463 < 384; v463 += 1) {	// L717
    for (int v464 = 0; v464 < 64; v464 += 1) {	// L718
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v461
      #pragma HLS dependence false variable=v462
      ap_int<32> v465 = v461[0][v463][v464];	// L719
      float v466 = v465;	// L720
      v462[0][v463][v464] = v466;	// L721
    }
  }
}

void kernel80(
  ap_int<64> v467[1][384][64],
  ap_int<32> v468[1][384][64]
) {	// L726
  for (int v469 = 0; v469 < 384; v469 += 1) {	// L727
    for (int v470 = 0; v470 < 64; v470 += 1) {	// L728
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v467
      #pragma HLS dependence false variable=v468
      ap_int<64> v471 = v467[0][v469][v470];	// L729
      ap_int<32> v472 = v471;	// L730
      v468[0][v469][v470] = v472;	// L731
    }
  }
}

void kernel81(
  ap_int<32> v473[1][384][64],
  ap_int<32> v474[384][384][1],
  ap_int<64> v475[1][384][64]
) {	// L736
  ap_int<32> v476[384][384][1];	// L737
  #pragma HLS resource variable=v476 core=ram_t2p_bram

  memcpy(v476, v474, 147456 * sizeof(ap_int<32>));	// L738

  for (int v477 = 0; v477 < 384; v477 += 1) {	// L739
    for (int v478 = 0; v478 < 384; v478 += 1) {	// L740
      for (int v479 = 0; v479 < 64; v479 += 1) {	// L741
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v473
        #pragma HLS dependence false variable=v475
        #pragma HLS dependence false variable=v476
        ap_int<32> v480 = v473[0][v477][v479];	// L742
        ap_int<32> v481 = v476[v478][v477][0];	// L743
        ap_int<64> v482 = v475[0][v478][v479];	// L744
        ap_int<64> v483 = v480;	// L745
        ap_int<64> v484 = v481;	// L746
        ap_int<64> v485 = v483 * v484;	// L747
        ap_int<64> v486 = v482 + v485;	// L748
        v475[0][v478][v479] = v486;	// L749
      }
    }
  }
}

void kernel82(
  ap_int<8> v487[384][384][1],
  ap_int<32> v488[384][384][1]
) {	// L755
  for (int v489 = 0; v489 < 384; v489 += 1) {	// L756
    for (int v490 = 0; v490 < 384; v490 += 1) {	// L757
      ap_int<8> v491 = v487[v489][v490][0];	// L758
      ap_int<32> v492 = v491;	// L759
      v488[v489][v490][0] = v492;	// L760
    }
  }
}

void kernel83(
  ap_int<8> v493[1][384][64],
  ap_int<32> v494[1][384][64]
) {	// L765
  for (int v495 = 0; v495 < 384; v495 += 1) {	// L766
    for (int v496 = 0; v496 < 64; v496 += 1) {	// L767
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v493
      #pragma HLS dependence false variable=v494
      ap_int<8> v497 = v493[0][v495][v496];	// L768
      ap_int<32> v498 = v497;	// L769
      v494[0][v495][v496] = v498;	// L770
    }
  }
}

void kernel93(
  float v499[1][8][48][64],
  float v500[1][384][64]
) {	// L775
  for (int v501 = 0; v501 < 384; v501 += 1) {	// L776
    for (int v502 = 0; v502 < 64; v502 += 1) {	// L777
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v499
      #pragma HLS dependence false variable=v500
      float v503 = v499[0][(v501 / 48)][(v501 % 48)][v502];	// L778
      v500[0][v501][v502] = v503;	// L779
    }
  }
}

void kernel97(
  float v504[1][8][64][48],
  float v505[1][8][48][64]
) {	// L784
  for (int v506 = 0; v506 < 8; v506 += 1) {	// L785
    for (int v507 = 0; v507 < 48; v507 += 1) {	// L786
      for (int v508 = 0; v508 < 64; v508 += 1) {	// L787
        float v509 = v504[0][v506][v508][v507];	// L788
        v505[0][v506][v507][v508] = v509;	// L789
      }
    }
  }
}

void kernel98(
  ap_int<8> v510[8][64][48],
  float v511[1][8][64][48],
  float v512
) {	// L795
  for (int v513 = 0; v513 < 8; v513 += 1) {	// L796
    for (int v514 = 0; v514 < 64; v514 += 1) {	// L797
      for (int v515 = 0; v515 < 48; v515 += 1) {	// L798
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v510
        #pragma HLS dependence false variable=v511
        ap_int<8> v516 = v510[v513][v514][v515];	// L799
        float v517 = v516;	// L800
        float v518 = v517 * v512;	// L801
        v511[0][v513][v514][v515] = v518;	// L802
      }
    }
  }
}

void kernel99(
  float v519[8][64][48],
  ap_int<8> v520[8][64][48]
) {	// L808
  for (int v521 = 0; v521 < 8; v521 += 1) {	// L809
    for (int v522 = 0; v522 < 64; v522 += 1) {	// L810
      for (int v523 = 0; v523 < 48; v523 += 1) {	// L811
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v519
        #pragma HLS dependence false variable=v520
        float v524 = v519[v521][v522][v523];	// L812
        ap_int<8> v525 = v524;	// L813
        v520[v521][v522][v523] = v525;	// L814
      }
    }
  }
}

void kernel100(
  float v526[8][64][48],
  float v527[8][48][48],
  float v528[8][64][48]
) {	// L820
  float v529[8][64][48];	// L821
  #pragma HLS resource variable=v529 core=ram_t2p_bram

  memcpy(v529, v526, 24576 * sizeof(float));	// L822

  for (int v530 = 0; v530 < 48; v530 += 1) {	// L823
    for (int v531 = 0; v531 < 8; v531 += 1) {	// L824
      for (int v532 = 0; v532 < 64; v532 += 1) {	// L825
        for (int v533 = 0; v533 < 48; v533 += 1) {	// L826
          #pragma HLS pipeline II=1
          #pragma HLS dependence false variable=v529
          #pragma HLS dependence false variable=v527
          #pragma HLS dependence false variable=v528
          float v534 = v529[v531][v532][v530];	// L827
          float v535 = v527[v531][v530][v533];	// L828
          float v536 = v528[v531][v532][v533];	// L829
          float v537 = v534 * v535;	// L830
          float v538 = v536 + v537;	// L831
          v528[v531][v532][v533] = v538;	// L832
        }
      }
    }
  }
}

void kernel101(
  ap_int<8> v539[8][48][48],
  float v540[8][48][48]
) {	// L839
  for (int v541 = 0; v541 < 8; v541 += 1) {	// L840
    for (int v542 = 0; v542 < 48; v542 += 1) {	// L841
      for (int v543 = 0; v543 < 48; v543 += 1) {	// L842
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v539
        #pragma HLS dependence false variable=v540
        ap_int<8> v544 = v539[v541][v542][v543];	// L843
        float v545 = v544;	// L844
        v540[v541][v542][v543] = v545;	// L845
      }
    }
  }
}

void kernel102(
  ap_int<8> v546[1][8][64][48],
  float v547[8][64][48]
) {	// L851
  for (int v548 = 0; v548 < 8; v548 += 1) {	// L852
    for (int v549 = 0; v549 < 64; v549 += 1) {	// L853
      for (int v550 = 0; v550 < 48; v550 += 1) {	// L854
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v546
        #pragma HLS dependence false variable=v547
        ap_int<8> v551 = v546[0][v548][v549][v550];	// L855
        float v552 = v551;	// L856
        v547[v548][v549][v550] = v552;	// L857
      }
    }
  }
}

void kernel103(
  float v553[8][48][48],
  ap_int<8> v554[8][48][48]
) {	// L863
  for (int v555 = 0; v555 < 8; v555 += 1) {	// L864
    for (int v556 = 0; v556 < 48; v556 += 1) {	// L865
      for (int v557 = 0; v557 < 48; v557 += 1) {	// L866
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v553
        #pragma HLS dependence false variable=v554
        float v558 = v553[v555][v556][v557];	// L867
        ap_int<8> v559 = v558;	// L868
        v554[v555][v556][v557] = v559;	// L869
      }
    }
  }
}

void kernel104(
  float v560[8][48][64],
  float v561[8][64][48],
  float v562[8][48][48]
) {	// L875
  float v563[8][48][64];	// L876
  #pragma HLS resource variable=v563 core=ram_t2p_bram

  memcpy(v563, v560, 24576 * sizeof(float));	// L877

  for (int v564 = 0; v564 < 64; v564 += 1) {	// L878
    for (int v565 = 0; v565 < 8; v565 += 1) {	// L879
      for (int v566 = 0; v566 < 48; v566 += 1) {	// L880
        for (int v567 = 0; v567 < 48; v567 += 1) {	// L881
          #pragma HLS pipeline II=1
          #pragma HLS dependence false variable=v563
          #pragma HLS dependence false variable=v561
          #pragma HLS dependence false variable=v562
          float v568 = v563[v565][v566][v564];	// L882
          float v569 = v561[v565][v564][v567];	// L883
          float v570 = v562[v565][v566][v567];	// L884
          float v571 = v568 * v569;	// L885
          float v572 = v570 + v571;	// L886
          v562[v565][v566][v567] = v572;	// L887
        }
      }
    }
  }
}

void kernel106(
  ap_int<8> v573[1][8][48][64],
  float v574[8][48][64]
) {	// L894
  for (int v575 = 0; v575 < 8; v575 += 1) {	// L895
    for (int v576 = 0; v576 < 48; v576 += 1) {	// L896
      for (int v577 = 0; v577 < 64; v577 += 1) {	// L897
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v573
        #pragma HLS dependence false variable=v574
        ap_int<8> v578 = v573[0][v575][v576][v577];	// L898
        float v579 = v578;	// L899
        v574[v575][v576][v577] = v579;	// L900
      }
    }
  }
}

void kernel107(
  ap_int<8> v580[1][64][384],
  ap_int<8> v581[1][8][48][64]
) {	// L906
  for (int v582 = 0; v582 < 8; v582 += 1) {	// L907
    for (int v583 = 0; v583 < 48; v583 += 1) {	// L908
      for (int v584 = 0; v584 < 64; v584 += 1) {	// L909
        ap_int<8> v585 = v580[0][v584][((v582 * 48) + v583)];	// L910
        v581[0][v582][v583][v584] = v585;	// L911
      }
    }
  }
}

void kernel108(
  ap_int<8> v586[1][64][384],
  ap_int<8> v587[1][8][64][48]
) {	// L917
  for (int v588 = 0; v588 < 8; v588 += 1) {	// L918
    for (int v589 = 0; v589 < 64; v589 += 1) {	// L919
      for (int v590 = 0; v590 < 48; v590 += 1) {	// L920
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v586
        #pragma HLS dependence false variable=v587
        ap_int<8> v591 = v586[0][v589][((v588 * 48) + v590)];	// L921
        v587[0][v588][v589][v590] = v591;	// L922
      }
    }
  }
}

void kernel109(
  ap_int<8> v592[1][384][64],
  ap_int<8> v593[1][64][384]
) {	// L928
  for (int v594 = 0; v594 < 64; v594 += 1) {	// L929
    for (int v595 = 0; v595 < 384; v595 += 1) {	// L930
      ap_int<8> v596 = v592[0][v595][v594];	// L931
      v593[0][v594][v595] = v596;	// L932
    }
  }
}

void kernel129(
  ap_int<64> v597[1][384][64],
  ap_int<64> v598[1][384][64]
) {	// L937
  for (int v599 = 0; v599 < 384; v599 += 1) {	// L938
    for (int v600 = 0; v600 < 64; v600 += 1) {	// L939
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v597
      #pragma HLS dependence false variable=v598
      ap_int<64> v601 = v597[0][v599][v600];	// L940
      v598[0][v599][v600] = v601;	// L941
    }
  }
}

void kernel176(
  ap_int<8> v602[1][384][8][8],
  ap_int<32> v603[1][384][64]
) {	// L946
  for (int v604 = 0; v604 < 384; v604 += 1) {	// L947
    for (int v605 = 0; v605 < 64; v605 += 1) {	// L948
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v602
      #pragma HLS dependence false variable=v603
      ap_int<8> v606 = v602[0][v604][(v605 / 8)][(v605 % 8)];	// L949
      ap_int<32> v607 = v606;	// L950
      v603[0][v604][v605] = v607;	// L951
    }
  }
}

void kernel197(
  ap_int<64> v608[1][384][8][8],
  ap_int<64> v609[1][384][8][8]
) {	// L956
  for (int v610 = 0; v610 < 384; v610 += 1) {	// L957
    for (int v611 = 0; v611 < 8; v611 += 1) {	// L958
      for (int v612 = 0; v612 < 8; v612 += 1) {	// L959
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v608
        #pragma HLS dependence false variable=v609
        ap_int<64> v613 = v608[0][v610][v611][v612];	// L960
        v609[0][v610][v611][v612] = v613;	// L961
      }
    }
  }
}

void kernel219(
  ap_int<64> v614[1][1536][8][8],
  ap_int<64> v615[1][1536][8][8]
) {	// L967
  for (int v616 = 0; v616 < 1536; v616 += 1) {	// L968
    for (int v617 = 0; v617 < 8; v617 += 1) {	// L969
      for (int v618 = 0; v618 < 8; v618 += 1) {	// L970
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v614
        #pragma HLS dependence false variable=v615
        ap_int<64> v619 = v614[0][v616][v617][v618];	// L971
        v615[0][v616][v617][v618] = v619;	// L972
      }
    }
  }
}

void kernel220(
  ap_int<64> v620[1][1536][8][8],
  ap_int<64> v621
) {	// L978
  for (int v622 = 0; v622 < 1536; v622 += 1) {	// L979
    for (int v623 = 0; v623 < 8; v623 += 1) {	// L980
      for (int v624 = 0; v624 < 8; v624 += 1) {	// L981
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v620
        v620[0][v622][v623][v624] = v621;	// L982
      }
    }
  }
}

void kernel263(
  float v625[8][64][48],
  float v626[8][64][48]
) {	// L988
  for (int v627 = 0; v627 < 8; v627 += 1) {	// L989
    for (int v628 = 0; v628 < 64; v628 += 1) {	// L990
      for (int v629 = 0; v629 < 48; v629 += 1) {	// L991
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v625
        #pragma HLS dependence false variable=v626
        float v630 = v625[v627][v628][v629];	// L992
        v626[v627][v628][v629] = v630;	// L993
      }
    }
  }
}

void kernel264(
  float v631[8][64][48],
  float v632
) {	// L999
  for (int v633 = 0; v633 < 8; v633 += 1) {	// L1000
    for (int v634 = 0; v634 < 64; v634 += 1) {	// L1001
      for (int v635 = 0; v635 < 48; v635 += 1) {	// L1002
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v631
        v631[v633][v634][v635] = v632;	// L1003
      }
    }
  }
}

void kernel269(
  float v636[8][48][48],
  float v637[8][48][48]
) {	// L1009
  for (int v638 = 0; v638 < 8; v638 += 1) {	// L1010
    for (int v639 = 0; v639 < 48; v639 += 1) {	// L1011
      for (int v640 = 0; v640 < 48; v640 += 1) {	// L1012
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v636
        #pragma HLS dependence false variable=v637
        float v641 = v636[v638][v639][v640];	// L1013
        v637[v638][v639][v640] = v641;	// L1014
      }
    }
  }
}

void kernel270(
  float v642[8][48][48],
  float v643
) {	// L1020
  for (int v644 = 0; v644 < 8; v644 += 1) {	// L1021
    for (int v645 = 0; v645 < 48; v645 += 1) {	// L1022
      for (int v646 = 0; v646 < 48; v646 += 1) {	// L1023
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v642
        v642[v644][v645][v646] = v643;	// L1024
      }
    }
  }
}

void kernel341(
  ap_int<64> v647[1][384][64],
  ap_int<64> v648
) {	// L1030
  for (int v649 = 0; v649 < 384; v649 += 1) {	// L1031
    for (int v650 = 0; v650 < 64; v650 += 1) {	// L1032
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v647
      v647[0][v649][v650] = v648;	// L1033
    }
  }
}

void kernel363(
  ap_int<32> v651[1][192][16][16],
  ap_int<32> v652[384][192][1][1],
  ap_int<64> v653[1][384][8][8]
) {	// L1038
  ap_int<32> v654[384][192][1][1];	// L1039
  #pragma HLS resource variable=v654 core=ram_t2p_bram

  memcpy(v654, v652, 73728 * sizeof(ap_int<32>));	// L1040

  for (int v655 = 0; v655 < 192; v655 += 1) {	// L1041
    for (int v656 = 0; v656 < 384; v656 += 1) {	// L1042
      for (int v657 = 0; v657 < 8; v657 += 1) {	// L1043
        for (int v658 = 0; v658 < 8; v658 += 1) {	// L1044
          #pragma HLS pipeline II=1
          #pragma HLS dependence false variable=v651
          #pragma HLS dependence false variable=v653
          #pragma HLS dependence false variable=v654
          ap_int<32> v659 = v651[0][v655][(v657 * 2)][(v658 * 2)];	// L1045
          ap_int<32> v660 = v654[v656][v655][0][0];	// L1046
          ap_int<64> v661 = v653[0][v656][v657][v658];	// L1047
          ap_int<64> v662 = v659;	// L1048
          ap_int<64> v663 = v660;	// L1049
          ap_int<64> v664 = v662 * v663;	// L1050
          ap_int<64> v665 = v661 + v664;	// L1051
          v653[0][v656][v657][v658] = v665;	// L1052
        }
      }
    }
  }
}

void kernel365(
  ap_int<64> v666[1][384][8][8],
  ap_int<64> v667
) {	// L1059
  for (int v668 = 0; v668 < 384; v668 += 1) {	// L1060
    for (int v669 = 0; v669 < 8; v669 += 1) {	// L1061
      for (int v670 = 0; v670 < 8; v670 += 1) {	// L1062
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v666
        v666[0][v668][v669][v670] = v667;	// L1063
      }
    }
  }
}

void kernel366(
  ap_int<8> v671[384][192][1][1],
  ap_int<32> v672[384][192][1][1]
) {	// L1069
  for (int v673 = 0; v673 < 384; v673 += 1) {	// L1070
    for (int v674 = 0; v674 < 192; v674 += 1) {	// L1071
      ap_int<8> v675 = v671[v673][v674][0][0];	// L1072
      ap_int<32> v676 = v675;	// L1073
      v672[v673][v674][0][0] = v676;	// L1074
    }
  }
}

void kernel380(
  float v677[1][384][18][18],
  float v678[3][3],
  float v679[1][384][8][8]
) {	// L1079
  for (int v680 = 0; v680 < 3; v680 += 1) {	// L1080
    for (int v681 = 0; v681 < 3; v681 += 1) {	// L1081
      for (int v682 = 0; v682 < 384; v682 += 1) {	// L1082
        for (int v683 = 0; v683 < 8; v683 += 1) {	// L1083
          for (int v684 = 0; v684 < 8; v684 += 1) {	// L1084
            #pragma HLS pipeline II=1
            #pragma HLS dependence false variable=v677
            #pragma HLS dependence false variable=v679
            float v685 = v677[0][v682][((v683 * 2) + v680)][((v684 * 2) + v681)];	// L1085
            float v686 = v679[0][v682][v683][v684];	// L1086
            float v687 = max(v686, v685);	// L1087
            v679[0][v682][v683][v684] = v687;	// L1088
          }
        }
      }
    }
  }
}

void kernel381(
  float v688[1][384][8][8],
  float v689
) {	// L1096
  for (int v690 = 0; v690 < 384; v690 += 1) {	// L1097
    for (int v691 = 0; v691 < 8; v691 += 1) {	// L1098
      for (int v692 = 0; v692 < 8; v692 += 1) {	// L1099
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v688
        v688[0][v690][v691][v692] = v689;	// L1100
      }
    }
  }
}

void kernel382(
  float v693[1][384][16][16],
  float v694[1][384][18][18]
) {	// L1106
  for (int v695 = 0; v695 < 384; v695 += 1) {	// L1107
    for (int v696 = 0; v696 < 16; v696 += 1) {	// L1108
      for (int v697 = 0; v697 < 16; v697 += 1) {	// L1109
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v693
        #pragma HLS dependence false variable=v694
        float v698 = v693[0][v695][v696][v697];	// L1110
        v694[0][v695][(v696 + 1)][(v697 + 1)] = v698;	// L1111
      }
    }
  }
}

void kernel383(
  float v699[1][384][18][18],
  float v700
) {	// L1117
  for (int v701 = 0; v701 < 384; v701 += 1) {	// L1118
    for (int v702 = 0; v702 < 18; v702 += 1) {	// L1119
      for (int v703 = 0; v703 < 18; v703 += 1) {	// L1120
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v699
        v699[0][v701][v702][v703] = v700;	// L1121
      }
    }
  }
}

void kernel384(
  float v704[384],
  float v705[1][384][16][16]
) {	// L1127
  float v706[384];	// L1128
  #pragma HLS resource variable=v706 core=ram_t2p_bram

  memcpy(v706, v704, 384 * sizeof(float));	// L1129

  for (int v707 = 0; v707 < 384; v707 += 1) {	// L1130
    for (int v708 = 0; v708 < 16; v708 += 1) {	// L1131
      for (int v709 = 0; v709 < 16; v709 += 1) {	// L1132
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v705
        #pragma HLS dependence false variable=v706
        float v710 = v705[0][v707][v708][v709];	// L1133
        float v711 = v706[v707];	// L1134
        float v712 = v710 + v711;	// L1135
        v705[0][v707][v708][v709] = v712;	// L1136
      }
    }
  }
}

void kernel386(
  float v713[1][384][1][1],
  float v714[1][384][16][16]
) {	// L1142
  float v715[1][384][1][1];	// L1143
  #pragma HLS resource variable=v715 core=ram_t2p_bram

  memcpy(v715, v713, 384 * sizeof(float));	// L1144

  for (int v716 = 0; v716 < 384; v716 += 1) {	// L1145
    for (int v717 = 0; v717 < 16; v717 += 1) {	// L1146
      for (int v718 = 0; v718 < 16; v718 += 1) {	// L1147
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v714
        #pragma HLS dependence false variable=v715
        float v719 = v714[0][v716][v717][v718];	// L1148
        float v720 = v715[0][v716][0][0];	// L1149
        float v721 = v719 * v720;	// L1150
        v714[0][v716][v717][v718] = v721;	// L1151
      }
    }
  }
}

void kernel387(
  ap_int<32> v722[1][384][16][16],
  float v723[1][384][16][16]
) {	// L1157
  for (int v724 = 0; v724 < 384; v724 += 1) {	// L1158
    for (int v725 = 0; v725 < 16; v725 += 1) {	// L1159
      for (int v726 = 0; v726 < 16; v726 += 1) {	// L1160
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v722
        #pragma HLS dependence false variable=v723
        ap_int<32> v727 = v722[0][v724][v725][v726];	// L1161
        float v728 = v727;	// L1162
        v723[0][v724][v725][v726] = v728;	// L1163
      }
    }
  }
}

void kernel388(
  ap_int<64> v729[1][384][16][16],
  ap_int<32> v730[1][384][16][16]
) {	// L1169
  for (int v731 = 0; v731 < 384; v731 += 1) {	// L1170
    for (int v732 = 0; v732 < 16; v732 += 1) {	// L1171
      for (int v733 = 0; v733 < 16; v733 += 1) {	// L1172
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v729
        #pragma HLS dependence false variable=v730
        ap_int<64> v734 = v729[0][v731][v732][v733];	// L1173
        ap_int<32> v735 = v734;	// L1174
        v730[0][v731][v732][v733] = v735;	// L1175
      }
    }
  }
}

void kernel389(
  ap_int<32> v736[1][384][18][18],
  ap_int<32> v737[384][384][3][3],
  ap_int<64> v738[1][384][16][16]
) {	// L1181
  ap_int<32> v739[384][384][3][3];	// L1182
  #pragma HLS resource variable=v739 core=ram_t2p_bram

  memcpy(v739, v737, 1327104 * sizeof(ap_int<32>));	// L1183

  for (int v740 = 0; v740 < 384; v740 += 1) {	// L1184
    for (int v741 = 0; v741 < 3; v741 += 1) {	// L1185
      for (int v742 = 0; v742 < 3; v742 += 1) {	// L1186
        for (int v743 = 0; v743 < 384; v743 += 1) {	// L1187
          for (int v744 = 0; v744 < 16; v744 += 1) {	// L1188
            for (int v745 = 0; v745 < 16; v745 += 1) {	// L1189
              #pragma HLS pipeline II=1
              #pragma HLS dependence false variable=v736
              #pragma HLS dependence false variable=v738
              #pragma HLS dependence false variable=v739
              ap_int<32> v746 = v736[0][v740][(v744 + v741)][(v745 + v742)];	// L1190
              ap_int<32> v747 = v739[v743][v740][v741][v742];	// L1191
              ap_int<64> v748 = v738[0][v743][v744][v745];	// L1192
              ap_int<64> v749 = v746;	// L1193
              ap_int<64> v750 = v747;	// L1194
              ap_int<64> v751 = v749 * v750;	// L1195
              ap_int<64> v752 = v748 + v751;	// L1196
              v738[0][v743][v744][v745] = v752;	// L1197
            }
          }
        }
      }
    }
  }
}

void kernel390(
  ap_int<32> v753[1][384][16][16],
  ap_int<32> v754[1][384][18][18]
) {	// L1206
  for (int v755 = 0; v755 < 384; v755 += 1) {	// L1207
    for (int v756 = 0; v756 < 16; v756 += 1) {	// L1208
      for (int v757 = 0; v757 < 16; v757 += 1) {	// L1209
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v753
        #pragma HLS dependence false variable=v754
        ap_int<32> v758 = v753[0][v755][v756][v757];	// L1210
        v754[0][v755][(v756 + 1)][(v757 + 1)] = v758;	// L1211
      }
    }
  }
}

void kernel391(
  ap_int<32> v759[1][384][18][18],
  ap_int<32> v760
) {	// L1217
  for (int v761 = 0; v761 < 384; v761 += 1) {	// L1218
    for (int v762 = 0; v762 < 18; v762 += 1) {	// L1219
      for (int v763 = 0; v763 < 18; v763 += 1) {	// L1220
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v759
        v759[0][v761][v762][v763] = v760;	// L1221
      }
    }
  }
}

void kernel392(
  ap_int<8> v764[384][384][3][3],
  ap_int<32> v765[384][384][3][3]
) {	// L1227
  for (int v766 = 0; v766 < 384; v766 += 1) {	// L1228
    for (int v767 = 0; v767 < 384; v767 += 1) {	// L1229
      for (int v768 = 0; v768 < 3; v768 += 1) {	// L1230
        for (int v769 = 0; v769 < 3; v769 += 1) {	// L1231
          #pragma HLS pipeline II=1
          #pragma HLS dependence false variable=v764
          #pragma HLS dependence false variable=v765
          ap_int<8> v770 = v764[v766][v767][v768][v769];	// L1232
          ap_int<32> v771 = v770;	// L1233
          v765[v766][v767][v768][v769] = v771;	// L1234
        }
      }
    }
  }
}

void kernel393(
  ap_int<8> v772[1][384][16][16],
  ap_int<32> v773[1][384][16][16]
) {	// L1241
  for (int v774 = 0; v774 < 384; v774 += 1) {	// L1242
    for (int v775 = 0; v775 < 16; v775 += 1) {	// L1243
      for (int v776 = 0; v776 < 16; v776 += 1) {	// L1244
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v772
        #pragma HLS dependence false variable=v773
        ap_int<8> v777 = v772[0][v774][v775][v776];	// L1245
        ap_int<32> v778 = v777;	// L1246
        v773[0][v774][v775][v776] = v778;	// L1247
      }
    }
  }
}

void kernel394(
  float v779[1][384][16][16],
  float v780[1][384][16][16]
) {	// L1253
  for (int v781 = 0; v781 < 384; v781 += 1) {	// L1254
    for (int v782 = 0; v782 < 16; v782 += 1) {	// L1255
      for (int v783 = 0; v783 < 16; v783 += 1) {	// L1256
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v779
        #pragma HLS dependence false variable=v780
        float v784 = v779[0][v781][v782][v783];	// L1257
        v780[0][v781][v782][v783] = v784;	// L1258
      }
    }
  }
}

void kernel395(
  float v785[1][384][16][16],
  float v786[1][384][16][16]
) {	// L1264
  for (int v787 = 0; v787 < 384; v787 += 1) {	// L1265
    for (int v788 = 0; v788 < 16; v788 += 1) {	// L1266
      for (int v789 = 0; v789 < 16; v789 += 1) {	// L1267
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v785
        #pragma HLS dependence false variable=v786
        float v790 = v785[0][v787][v788][v789];	// L1268
        float v791 = v786[0][v787][v788][v789];	// L1269
        float v792 = v790 + v791;	// L1270
        v786[0][v787][v788][v789] = v792;	// L1271
      }
    }
  }
}

void kernel396(
  float v793[1][384][16][16],
  float v794[1][384][16][16],
  float v795[1][384][16][16]
) {	// L1277
  for (int v796 = 0; v796 < 384; v796 += 1) {	// L1278
    for (int v797 = 0; v797 < 16; v797 += 1) {	// L1279
      for (int v798 = 0; v798 < 16; v798 += 1) {	// L1280
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v794
        #pragma HLS dependence false variable=v795
        #pragma HLS dependence false variable=v793
        float v799 = v794[0][v796][v797][v798];	// L1281
        float v800 = v793[0][v796][v797][v798];	// L1282
        float v801 = v799 - v800;	// L1283
        v795[0][v796][v797][v798] = v801;	// L1284
      }
    }
  }
}

void kernel397(
  float v802[1][384][16][16],
  float v803[1][384][16][16],
  float v804
) {	// L1290
  for (int v805 = 0; v805 < 384; v805 += 1) {	// L1291
    for (int v806 = 0; v806 < 16; v806 += 1) {	// L1292
      for (int v807 = 0; v807 < 16; v807 += 1) {	// L1293
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v803
        #pragma HLS dependence false variable=v802
        float v808 = v803[0][v805][v806][v807];	// L1294
        float v809 = v802[0][v805][v806][v807];	// L1295
        bool v810 = v808 >= v804;	// L1296
        float v811 = v810 ? v809 : v804;	// L1297
        v803[0][v805][v806][v807] = v811;	// L1298
      }
    }
  }
}

void kernel398(
  float v812[1][384][16][16],
  ap_int<8> v813[1][384][16][16],
  float v814
) {	// L1304
  for (int v815 = 0; v815 < 384; v815 += 1) {	// L1305
    for (int v816 = 0; v816 < 16; v816 += 1) {	// L1306
      for (int v817 = 0; v817 < 16; v817 += 1) {	// L1307
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v812
        #pragma HLS dependence false variable=v813
        float v818 = v812[0][v815][v816][v817];	// L1308
        bool v819 = v818 >= v814;	// L1309
        ap_int<8> v820 = v819;	// L1310
        v813[0][v815][v816][v817] = v820;	// L1311
      }
    }
  }
}

void kernel399(
  float v821[1][384][16][16],
  float v822
) {	// L1317
  for (int v823 = 0; v823 < 384; v823 += 1) {	// L1318
    for (int v824 = 0; v824 < 16; v824 += 1) {	// L1319
      for (int v825 = 0; v825 < 16; v825 += 1) {	// L1320
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v821
        float v826 = v821[0][v823][v824][v825];	// L1321
        float v827 = v826 - v822;	// L1322
        v821[0][v823][v824][v825] = v827;	// L1323
      }
    }
  }
}

void kernel401(
  float v828[1][384][16][16],
  float v829[1][384][16][16],
  float v830[1][384][16][16]
) {	// L1329
  for (int v831 = 0; v831 < 384; v831 += 1) {	// L1330
    for (int v832 = 0; v832 < 16; v832 += 1) {	// L1331
      for (int v833 = 0; v833 < 16; v833 += 1) {	// L1332
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v829
        #pragma HLS dependence false variable=v830
        #pragma HLS dependence false variable=v828
        float v834 = v829[0][v831][v832][v833];	// L1333
        float v835 = v828[0][v831][v832][v833];	// L1334
        float v836 = v834 + v835;	// L1335
        v830[0][v831][v832][v833] = v836;	// L1336
      }
    }
  }
}

void kernel402(
  float v837[1][384][16][16],
  float v838
) {	// L1342
  for (int v839 = 0; v839 < 384; v839 += 1) {	// L1343
    for (int v840 = 0; v840 < 16; v840 += 1) {	// L1344
      for (int v841 = 0; v841 < 16; v841 += 1) {	// L1345
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v837
        float v842 = v837[0][v839][v840][v841];	// L1346
        float v843 = v842 / v838;	// L1347
        v837[0][v839][v840][v841] = v843;	// L1348
      }
    }
  }
}

void kernel407(
  float v844[384],
  float v845[1][384][16][16],
  float v846[1][384][16][16]
) {	// L1354
  float v847[384];	// L1355
  #pragma HLS resource variable=v847 core=ram_t2p_bram

  memcpy(v847, v844, 384 * sizeof(float));	// L1356

  for (int v848 = 0; v848 < 384; v848 += 1) {	// L1357
    for (int v849 = 0; v849 < 16; v849 += 1) {	// L1358
      for (int v850 = 0; v850 < 16; v850 += 1) {	// L1359
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v845
        #pragma HLS dependence false variable=v846
        #pragma HLS dependence false variable=v847
        float v851 = v845[0][v848][v849][v850];	// L1360
        float v852 = v847[v848];	// L1361
        float v853 = v851 + v852;	// L1362
        v846[0][v848][v849][v850] = v853;	// L1363
      }
    }
  }
}

void kernel412(
  ap_int<32> v854[1][192][18][18],
  ap_int<32> v855[384][192][3][3],
  ap_int<64> v856[1][384][16][16]
) {	// L1369
  ap_int<32> v857[384][192][3][3];	// L1370
  #pragma HLS resource variable=v857 core=ram_t2p_bram

  memcpy(v857, v855, 663552 * sizeof(ap_int<32>));	// L1371

  for (int v858 = 0; v858 < 192; v858 += 1) {	// L1372
    for (int v859 = 0; v859 < 3; v859 += 1) {	// L1373
      for (int v860 = 0; v860 < 3; v860 += 1) {	// L1374
        for (int v861 = 0; v861 < 384; v861 += 1) {	// L1375
          for (int v862 = 0; v862 < 16; v862 += 1) {	// L1376
            for (int v863 = 0; v863 < 16; v863 += 1) {	// L1377
              #pragma HLS pipeline II=1
              #pragma HLS dependence false variable=v854
              #pragma HLS dependence false variable=v856
              #pragma HLS dependence false variable=v857
              ap_int<32> v864 = v854[0][v858][(v862 + v859)][(v863 + v860)];	// L1378
              ap_int<32> v865 = v857[v861][v858][v859][v860];	// L1379
              ap_int<64> v866 = v856[0][v861][v862][v863];	// L1380
              ap_int<64> v867 = v864;	// L1381
              ap_int<64> v868 = v865;	// L1382
              ap_int<64> v869 = v867 * v868;	// L1383
              ap_int<64> v870 = v866 + v869;	// L1384
              v856[0][v861][v862][v863] = v870;	// L1385
            }
          }
        }
      }
    }
  }
}

void kernel413(
  ap_int<64> v871[1][384][16][16],
  ap_int<64> v872[1][384][16][16]
) {	// L1394
  for (int v873 = 0; v873 < 384; v873 += 1) {	// L1395
    for (int v874 = 0; v874 < 16; v874 += 1) {	// L1396
      for (int v875 = 0; v875 < 16; v875 += 1) {	// L1397
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v871
        #pragma HLS dependence false variable=v872
        ap_int<64> v876 = v871[0][v873][v874][v875];	// L1398
        v872[0][v873][v874][v875] = v876;	// L1399
      }
    }
  }
}

void kernel414(
  ap_int<64> v877[1][384][16][16],
  ap_int<64> v878
) {	// L1405
  for (int v879 = 0; v879 < 384; v879 += 1) {	// L1406
    for (int v880 = 0; v880 < 16; v880 += 1) {	// L1407
      for (int v881 = 0; v881 < 16; v881 += 1) {	// L1408
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v877
        v877[0][v879][v880][v881] = v878;	// L1409
      }
    }
  }
}

void kernel415(
  ap_int<32> v882[1][192][16][16],
  ap_int<32> v883[1][192][18][18]
) {	// L1415
  for (int v884 = 0; v884 < 192; v884 += 1) {	// L1416
    for (int v885 = 0; v885 < 16; v885 += 1) {	// L1417
      for (int v886 = 0; v886 < 16; v886 += 1) {	// L1418
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v882
        #pragma HLS dependence false variable=v883
        ap_int<32> v887 = v882[0][v884][v885][v886];	// L1419
        v883[0][v884][(v885 + 1)][(v886 + 1)] = v887;	// L1420
      }
    }
  }
}

void kernel416(
  ap_int<32> v888[1][192][18][18],
  ap_int<32> v889
) {	// L1426
  for (int v890 = 0; v890 < 192; v890 += 1) {	// L1427
    for (int v891 = 0; v891 < 18; v891 += 1) {	// L1428
      for (int v892 = 0; v892 < 18; v892 += 1) {	// L1429
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v888
        v888[0][v890][v891][v892] = v889;	// L1430
      }
    }
  }
}

void kernel417(
  ap_int<8> v893[384][192][3][3],
  ap_int<32> v894[384][192][3][3]
) {	// L1436
  for (int v895 = 0; v895 < 384; v895 += 1) {	// L1437
    for (int v896 = 0; v896 < 192; v896 += 1) {	// L1438
      for (int v897 = 0; v897 < 3; v897 += 1) {	// L1439
        for (int v898 = 0; v898 < 3; v898 += 1) {	// L1440
          #pragma HLS pipeline II=1
          #pragma HLS dependence false variable=v893
          #pragma HLS dependence false variable=v894
          ap_int<8> v899 = v893[v895][v896][v897][v898];	// L1441
          ap_int<32> v900 = v899;	// L1442
          v894[v895][v896][v897][v898] = v900;	// L1443
        }
      }
    }
  }
}

void kernel418(
  ap_int<8> v901[1][192][16][16],
  ap_int<32> v902[1][192][16][16]
) {	// L1450
  for (int v903 = 0; v903 < 192; v903 += 1) {	// L1451
    for (int v904 = 0; v904 < 16; v904 += 1) {	// L1452
      for (int v905 = 0; v905 < 16; v905 += 1) {	// L1453
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v901
        #pragma HLS dependence false variable=v902
        ap_int<8> v906 = v901[0][v903][v904][v905];	// L1454
        ap_int<32> v907 = v906;	// L1455
        v902[0][v903][v904][v905] = v907;	// L1456
      }
    }
  }
}

void kernel419(
  ap_int<8> v908[1][192][16][16],
  ap_int<8> v909[1][192][16][16]
) {	// L1462
  for (int v910 = 0; v910 < 192; v910 += 1) {	// L1463
    for (int v911 = 0; v911 < 16; v911 += 1) {	// L1464
      for (int v912 = 0; v912 < 16; v912 += 1) {	// L1465
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v908
        #pragma HLS dependence false variable=v909
        ap_int<8> v913 = v908[0][v910][v911][v912];	// L1466
        ap_int<8> v914 = v909[0][v910][v911][v912];	// L1467
        ap_int<8> v915 = v913 + v914;	// L1468
        v909[0][v910][v911][v912] = v915;	// L1469
      }
    }
  }
}

void kernel420(
  float v916[1][192][16][16],
  float v917[1][192][16][16]
) {	// L1475
  for (int v918 = 0; v918 < 192; v918 += 1) {	// L1476
    for (int v919 = 0; v919 < 16; v919 += 1) {	// L1477
      for (int v920 = 0; v920 < 16; v920 += 1) {	// L1478
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v916
        #pragma HLS dependence false variable=v917
        float v921 = v916[0][v918][v919][v920];	// L1479
        v917[0][v918][v919][v920] = v921;	// L1480
      }
    }
  }
}

void kernel421(
  float v922[1][192][16][16],
  float v923[1][192][16][16]
) {	// L1486
  for (int v924 = 0; v924 < 192; v924 += 1) {	// L1487
    for (int v925 = 0; v925 < 16; v925 += 1) {	// L1488
      for (int v926 = 0; v926 < 16; v926 += 1) {	// L1489
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v922
        #pragma HLS dependence false variable=v923
        float v927 = v922[0][v924][v925][v926];	// L1490
        float v928 = v923[0][v924][v925][v926];	// L1491
        float v929 = v927 + v928;	// L1492
        v923[0][v924][v925][v926] = v929;	// L1493
      }
    }
  }
}

void kernel422(
  float v930[1][192][16][16],
  float v931[1][192][16][16],
  float v932[1][192][16][16]
) {	// L1499
  for (int v933 = 0; v933 < 192; v933 += 1) {	// L1500
    for (int v934 = 0; v934 < 16; v934 += 1) {	// L1501
      for (int v935 = 0; v935 < 16; v935 += 1) {	// L1502
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v931
        #pragma HLS dependence false variable=v932
        #pragma HLS dependence false variable=v930
        float v936 = v931[0][v933][v934][v935];	// L1503
        float v937 = v930[0][v933][v934][v935];	// L1504
        float v938 = v936 - v937;	// L1505
        v932[0][v933][v934][v935] = v938;	// L1506
      }
    }
  }
}

void kernel423(
  float v939[1][192][16][16],
  float v940[1][192][16][16],
  float v941
) {	// L1512
  for (int v942 = 0; v942 < 192; v942 += 1) {	// L1513
    for (int v943 = 0; v943 < 16; v943 += 1) {	// L1514
      for (int v944 = 0; v944 < 16; v944 += 1) {	// L1515
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v940
        #pragma HLS dependence false variable=v939
        float v945 = v940[0][v942][v943][v944];	// L1516
        float v946 = v939[0][v942][v943][v944];	// L1517
        bool v947 = v945 >= v941;	// L1518
        float v948 = v947 ? v946 : v941;	// L1519
        v940[0][v942][v943][v944] = v948;	// L1520
      }
    }
  }
}

void kernel424(
  float v949[1][192][16][16],
  ap_int<8> v950[1][192][16][16],
  float v951
) {	// L1526
  for (int v952 = 0; v952 < 192; v952 += 1) {	// L1527
    for (int v953 = 0; v953 < 16; v953 += 1) {	// L1528
      for (int v954 = 0; v954 < 16; v954 += 1) {	// L1529
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v949
        #pragma HLS dependence false variable=v950
        float v955 = v949[0][v952][v953][v954];	// L1530
        bool v956 = v955 >= v951;	// L1531
        ap_int<8> v957 = v956;	// L1532
        v950[0][v952][v953][v954] = v957;	// L1533
      }
    }
  }
}

void kernel425(
  float v958[1][192][16][16],
  float v959
) {	// L1539
  for (int v960 = 0; v960 < 192; v960 += 1) {	// L1540
    for (int v961 = 0; v961 < 16; v961 += 1) {	// L1541
      for (int v962 = 0; v962 < 16; v962 += 1) {	// L1542
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v958
        float v963 = v958[0][v960][v961][v962];	// L1543
        float v964 = v963 - v959;	// L1544
        v958[0][v960][v961][v962] = v964;	// L1545
      }
    }
  }
}

void kernel427(
  float v965[1][192][16][16],
  float v966[1][192][16][16],
  float v967[1][192][16][16]
) {	// L1551
  for (int v968 = 0; v968 < 192; v968 += 1) {	// L1552
    for (int v969 = 0; v969 < 16; v969 += 1) {	// L1553
      for (int v970 = 0; v970 < 16; v970 += 1) {	// L1554
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v966
        #pragma HLS dependence false variable=v967
        #pragma HLS dependence false variable=v965
        float v971 = v966[0][v968][v969][v970];	// L1555
        float v972 = v965[0][v968][v969][v970];	// L1556
        float v973 = v971 + v972;	// L1557
        v967[0][v968][v969][v970] = v973;	// L1558
      }
    }
  }
}

void kernel428(
  float v974[1][192][16][16],
  float v975
) {	// L1564
  for (int v976 = 0; v976 < 192; v976 += 1) {	// L1565
    for (int v977 = 0; v977 < 16; v977 += 1) {	// L1566
      for (int v978 = 0; v978 < 16; v978 += 1) {	// L1567
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v974
        float v979 = v974[0][v976][v977][v978];	// L1568
        float v980 = v979 / v975;	// L1569
        v974[0][v976][v977][v978] = v980;	// L1570
      }
    }
  }
}

void kernel433(
  float v981[192],
  float v982[1][192][16][16],
  float v983[1][192][16][16]
) {	// L1576
  float v984[192];	// L1577
  #pragma HLS resource variable=v984 core=ram_t2p_bram

  memcpy(v984, v981, 192 * sizeof(float));	// L1578

  for (int v985 = 0; v985 < 192; v985 += 1) {	// L1579
    for (int v986 = 0; v986 < 16; v986 += 1) {	// L1580
      for (int v987 = 0; v987 < 16; v987 += 1) {	// L1581
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v982
        #pragma HLS dependence false variable=v983
        #pragma HLS dependence false variable=v984
        float v988 = v982[0][v985][v986][v987];	// L1582
        float v989 = v984[v985];	// L1583
        float v990 = v988 + v989;	// L1584
        v983[0][v985][v986][v987] = v990;	// L1585
      }
    }
  }
}

void kernel434(
  float v991[192],
  float v992[192],
  float v993[192]
) {	// L1591
  for (int v994 = 0; v994 < 192; v994 += 1) {	// L1592
    #pragma HLS pipeline II=1
    #pragma HLS dependence false variable=v992
    #pragma HLS dependence false variable=v993
    #pragma HLS dependence false variable=v991
    float v995 = v992[v994];	// L1593
    float v996 = v991[v994];	// L1594
    float v997 = v995 * v996;	// L1595
    v993[v994] = v997;	// L1596
  }
}

void kernel435(
  float v998[1][192][1][1],
  float v999[1][192][16][16]
) {	// L1600
  float v1000[1][192][1][1];	// L1601
  #pragma HLS resource variable=v1000 core=ram_t2p_bram

  memcpy(v1000, v998, 192 * sizeof(float));	// L1602

  for (int v1001 = 0; v1001 < 192; v1001 += 1) {	// L1603
    for (int v1002 = 0; v1002 < 16; v1002 += 1) {	// L1604
      for (int v1003 = 0; v1003 < 16; v1003 += 1) {	// L1605
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v999
        #pragma HLS dependence false variable=v1000
        float v1004 = v999[0][v1001][v1002][v1003];	// L1606
        float v1005 = v1000[0][v1001][0][0];	// L1607
        float v1006 = v1004 * v1005;	// L1608
        v999[0][v1001][v1002][v1003] = v1006;	// L1609
      }
    }
  }
}

void kernel436(
  ap_int<32> v1007[1][192][16][16],
  float v1008[1][192][16][16]
) {	// L1615
  for (int v1009 = 0; v1009 < 192; v1009 += 1) {	// L1616
    for (int v1010 = 0; v1010 < 16; v1010 += 1) {	// L1617
      for (int v1011 = 0; v1011 < 16; v1011 += 1) {	// L1618
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1007
        #pragma HLS dependence false variable=v1008
        ap_int<32> v1012 = v1007[0][v1009][v1010][v1011];	// L1619
        float v1013 = v1012;	// L1620
        v1008[0][v1009][v1010][v1011] = v1013;	// L1621
      }
    }
  }
}

void kernel437(
  ap_int<64> v1014[1][192][16][16],
  ap_int<32> v1015[1][192][16][16]
) {	// L1627
  for (int v1016 = 0; v1016 < 192; v1016 += 1) {	// L1628
    for (int v1017 = 0; v1017 < 16; v1017 += 1) {	// L1629
      for (int v1018 = 0; v1018 < 16; v1018 += 1) {	// L1630
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1014
        #pragma HLS dependence false variable=v1015
        ap_int<64> v1019 = v1014[0][v1016][v1017][v1018];	// L1631
        ap_int<32> v1020 = v1019;	// L1632
        v1015[0][v1016][v1017][v1018] = v1020;	// L1633
      }
    }
  }
}

void kernel438(
  ap_int<32> v1021[1][768][16][16],
  ap_int<32> v1022[192][768][1][1],
  ap_int<64> v1023[1][192][16][16]
) {	// L1639
  ap_int<32> v1024[192][768][1][1];	// L1640
  #pragma HLS resource variable=v1024 core=ram_t2p_bram

  memcpy(v1024, v1022, 147456 * sizeof(ap_int<32>));	// L1641

  for (int v1025 = 0; v1025 < 768; v1025 += 1) {	// L1642
    for (int v1026 = 0; v1026 < 192; v1026 += 1) {	// L1643
      for (int v1027 = 0; v1027 < 16; v1027 += 1) {	// L1644
        for (int v1028 = 0; v1028 < 16; v1028 += 1) {	// L1645
          #pragma HLS pipeline II=1
          #pragma HLS dependence false variable=v1021
          #pragma HLS dependence false variable=v1023
          #pragma HLS dependence false variable=v1024
          ap_int<32> v1029 = v1021[0][v1025][v1027][v1028];	// L1646
          ap_int<32> v1030 = v1024[v1026][v1025][0][0];	// L1647
          ap_int<64> v1031 = v1023[0][v1026][v1027][v1028];	// L1648
          ap_int<64> v1032 = v1029;	// L1649
          ap_int<64> v1033 = v1030;	// L1650
          ap_int<64> v1034 = v1032 * v1033;	// L1651
          ap_int<64> v1035 = v1031 + v1034;	// L1652
          v1023[0][v1026][v1027][v1028] = v1035;	// L1653
        }
      }
    }
  }
}

void kernel439(
  ap_int<8> v1036[192][768][1][1],
  ap_int<32> v1037[192][768][1][1]
) {	// L1660
  for (int v1038 = 0; v1038 < 192; v1038 += 1) {	// L1661
    for (int v1039 = 0; v1039 < 768; v1039 += 1) {	// L1662
      ap_int<8> v1040 = v1036[v1038][v1039][0][0];	// L1663
      ap_int<32> v1041 = v1040;	// L1664
      v1037[v1038][v1039][0][0] = v1041;	// L1665
    }
  }
}

void kernel440(
  ap_int<8> v1042[1][768][16][16],
  ap_int<32> v1043[1][768][16][16]
) {	// L1670
  for (int v1044 = 0; v1044 < 768; v1044 += 1) {	// L1671
    for (int v1045 = 0; v1045 < 16; v1045 += 1) {	// L1672
      for (int v1046 = 0; v1046 < 16; v1046 += 1) {	// L1673
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1042
        #pragma HLS dependence false variable=v1043
        ap_int<8> v1047 = v1042[0][v1044][v1045][v1046];	// L1674
        ap_int<32> v1048 = v1047;	// L1675
        v1043[0][v1044][v1045][v1046] = v1048;	// L1676
      }
    }
  }
}

void kernel441(
  float v1049[1][768][16][16],
  float v1050[1][768][16][16]
) {	// L1682
  for (int v1051 = 0; v1051 < 768; v1051 += 1) {	// L1683
    for (int v1052 = 0; v1052 < 16; v1052 += 1) {	// L1684
      for (int v1053 = 0; v1053 < 16; v1053 += 1) {	// L1685
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1049
        #pragma HLS dependence false variable=v1050
        float v1054 = v1049[0][v1051][v1052][v1053];	// L1686
        v1050[0][v1051][v1052][v1053] = v1054;	// L1687
      }
    }
  }
}

void kernel442(
  float v1055[1][768][16][16],
  float v1056[1][768][16][16]
) {	// L1693
  for (int v1057 = 0; v1057 < 768; v1057 += 1) {	// L1694
    for (int v1058 = 0; v1058 < 16; v1058 += 1) {	// L1695
      for (int v1059 = 0; v1059 < 16; v1059 += 1) {	// L1696
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1055
        #pragma HLS dependence false variable=v1056
        float v1060 = v1055[0][v1057][v1058][v1059];	// L1697
        float v1061 = v1056[0][v1057][v1058][v1059];	// L1698
        float v1062 = v1060 + v1061;	// L1699
        v1056[0][v1057][v1058][v1059] = v1062;	// L1700
      }
    }
  }
}

void kernel443(
  float v1063[1][768][16][16],
  float v1064[1][768][16][16],
  float v1065[1][768][16][16]
) {	// L1706
  for (int v1066 = 0; v1066 < 768; v1066 += 1) {	// L1707
    for (int v1067 = 0; v1067 < 16; v1067 += 1) {	// L1708
      for (int v1068 = 0; v1068 < 16; v1068 += 1) {	// L1709
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1064
        #pragma HLS dependence false variable=v1065
        #pragma HLS dependence false variable=v1063
        float v1069 = v1064[0][v1066][v1067][v1068];	// L1710
        float v1070 = v1063[0][v1066][v1067][v1068];	// L1711
        float v1071 = v1069 - v1070;	// L1712
        v1065[0][v1066][v1067][v1068] = v1071;	// L1713
      }
    }
  }
}

void kernel444(
  float v1072[1][768][16][16],
  float v1073[1][768][16][16],
  float v1074
) {	// L1719
  for (int v1075 = 0; v1075 < 768; v1075 += 1) {	// L1720
    for (int v1076 = 0; v1076 < 16; v1076 += 1) {	// L1721
      for (int v1077 = 0; v1077 < 16; v1077 += 1) {	// L1722
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1073
        #pragma HLS dependence false variable=v1072
        float v1078 = v1073[0][v1075][v1076][v1077];	// L1723
        float v1079 = v1072[0][v1075][v1076][v1077];	// L1724
        bool v1080 = v1078 >= v1074;	// L1725
        float v1081 = v1080 ? v1079 : v1074;	// L1726
        v1073[0][v1075][v1076][v1077] = v1081;	// L1727
      }
    }
  }
}

void kernel445(
  float v1082[1][768][16][16],
  ap_int<8> v1083[1][768][16][16],
  float v1084
) {	// L1733
  for (int v1085 = 0; v1085 < 768; v1085 += 1) {	// L1734
    for (int v1086 = 0; v1086 < 16; v1086 += 1) {	// L1735
      for (int v1087 = 0; v1087 < 16; v1087 += 1) {	// L1736
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1082
        #pragma HLS dependence false variable=v1083
        float v1088 = v1082[0][v1085][v1086][v1087];	// L1737
        bool v1089 = v1088 >= v1084;	// L1738
        ap_int<8> v1090 = v1089;	// L1739
        v1083[0][v1085][v1086][v1087] = v1090;	// L1740
      }
    }
  }
}

void kernel446(
  float v1091[1][768][16][16],
  float v1092
) {	// L1746
  for (int v1093 = 0; v1093 < 768; v1093 += 1) {	// L1747
    for (int v1094 = 0; v1094 < 16; v1094 += 1) {	// L1748
      for (int v1095 = 0; v1095 < 16; v1095 += 1) {	// L1749
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1091
        float v1096 = v1091[0][v1093][v1094][v1095];	// L1750
        float v1097 = v1096 - v1092;	// L1751
        v1091[0][v1093][v1094][v1095] = v1097;	// L1752
      }
    }
  }
}

void kernel448(
  float v1098[1][768][16][16],
  float v1099[1][768][16][16],
  float v1100[1][768][16][16]
) {	// L1758
  for (int v1101 = 0; v1101 < 768; v1101 += 1) {	// L1759
    for (int v1102 = 0; v1102 < 16; v1102 += 1) {	// L1760
      for (int v1103 = 0; v1103 < 16; v1103 += 1) {	// L1761
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1099
        #pragma HLS dependence false variable=v1100
        #pragma HLS dependence false variable=v1098
        float v1104 = v1099[0][v1101][v1102][v1103];	// L1762
        float v1105 = v1098[0][v1101][v1102][v1103];	// L1763
        float v1106 = v1104 + v1105;	// L1764
        v1100[0][v1101][v1102][v1103] = v1106;	// L1765
      }
    }
  }
}

void kernel449(
  float v1107[1][768][16][16],
  float v1108
) {	// L1771
  for (int v1109 = 0; v1109 < 768; v1109 += 1) {	// L1772
    for (int v1110 = 0; v1110 < 16; v1110 += 1) {	// L1773
      for (int v1111 = 0; v1111 < 16; v1111 += 1) {	// L1774
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1107
        float v1112 = v1107[0][v1109][v1110][v1111];	// L1775
        float v1113 = v1112 / v1108;	// L1776
        v1107[0][v1109][v1110][v1111] = v1113;	// L1777
      }
    }
  }
}

void kernel454(
  float v1114[768],
  float v1115[1][768][16][16],
  float v1116[1][768][16][16]
) {	// L1783
  float v1117[768];	// L1784
  #pragma HLS resource variable=v1117 core=ram_t2p_bram

  memcpy(v1117, v1114, 768 * sizeof(float));	// L1785

  for (int v1118 = 0; v1118 < 768; v1118 += 1) {	// L1786
    for (int v1119 = 0; v1119 < 16; v1119 += 1) {	// L1787
      for (int v1120 = 0; v1120 < 16; v1120 += 1) {	// L1788
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1115
        #pragma HLS dependence false variable=v1116
        #pragma HLS dependence false variable=v1117
        float v1121 = v1115[0][v1118][v1119][v1120];	// L1789
        float v1122 = v1117[v1118];	// L1790
        float v1123 = v1121 + v1122;	// L1791
        v1116[0][v1118][v1119][v1120] = v1123;	// L1792
      }
    }
  }
}

void kernel455(
  float v1124[768],
  float v1125[768],
  float v1126[768]
) {	// L1798
  for (int v1127 = 0; v1127 < 768; v1127 += 1) {	// L1799
    #pragma HLS pipeline II=1
    #pragma HLS dependence false variable=v1125
    #pragma HLS dependence false variable=v1126
    #pragma HLS dependence false variable=v1124
    float v1128 = v1125[v1127];	// L1800
    float v1129 = v1124[v1127];	// L1801
    float v1130 = v1128 * v1129;	// L1802
    v1126[v1127] = v1130;	// L1803
  }
}

void kernel456(
  float v1131[1][768][1][1],
  float v1132[1][768][16][16]
) {	// L1807
  float v1133[1][768][1][1];	// L1808
  #pragma HLS resource variable=v1133 core=ram_t2p_bram

  memcpy(v1133, v1131, 768 * sizeof(float));	// L1809

  for (int v1134 = 0; v1134 < 768; v1134 += 1) {	// L1810
    for (int v1135 = 0; v1135 < 16; v1135 += 1) {	// L1811
      for (int v1136 = 0; v1136 < 16; v1136 += 1) {	// L1812
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1132
        #pragma HLS dependence false variable=v1133
        float v1137 = v1132[0][v1134][v1135][v1136];	// L1813
        float v1138 = v1133[0][v1134][0][0];	// L1814
        float v1139 = v1137 * v1138;	// L1815
        v1132[0][v1134][v1135][v1136] = v1139;	// L1816
      }
    }
  }
}

void kernel457(
  ap_int<32> v1140[1][768][16][16],
  float v1141[1][768][16][16]
) {	// L1822
  for (int v1142 = 0; v1142 < 768; v1142 += 1) {	// L1823
    for (int v1143 = 0; v1143 < 16; v1143 += 1) {	// L1824
      for (int v1144 = 0; v1144 < 16; v1144 += 1) {	// L1825
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1140
        #pragma HLS dependence false variable=v1141
        ap_int<32> v1145 = v1140[0][v1142][v1143][v1144];	// L1826
        float v1146 = v1145;	// L1827
        v1141[0][v1142][v1143][v1144] = v1146;	// L1828
      }
    }
  }
}

void kernel458(
  ap_int<64> v1147[1][768][16][16],
  ap_int<32> v1148[1][768][16][16]
) {	// L1834
  for (int v1149 = 0; v1149 < 768; v1149 += 1) {	// L1835
    for (int v1150 = 0; v1150 < 16; v1150 += 1) {	// L1836
      for (int v1151 = 0; v1151 < 16; v1151 += 1) {	// L1837
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1147
        #pragma HLS dependence false variable=v1148
        ap_int<64> v1152 = v1147[0][v1149][v1150][v1151];	// L1838
        ap_int<32> v1153 = v1152;	// L1839
        v1148[0][v1149][v1150][v1151] = v1153;	// L1840
      }
    }
  }
}

void kernel459(
  ap_int<32> v1154[1][192][16][16],
  ap_int<32> v1155[768][192][1][1],
  ap_int<64> v1156[1][768][16][16]
) {	// L1846
  ap_int<32> v1157[768][192][1][1];	// L1847
  #pragma HLS resource variable=v1157 core=ram_t2p_bram

  memcpy(v1157, v1155, 147456 * sizeof(ap_int<32>));	// L1848

  for (int v1158 = 0; v1158 < 192; v1158 += 1) {	// L1849
    for (int v1159 = 0; v1159 < 768; v1159 += 1) {	// L1850
      for (int v1160 = 0; v1160 < 16; v1160 += 1) {	// L1851
        for (int v1161 = 0; v1161 < 16; v1161 += 1) {	// L1852
          #pragma HLS pipeline II=1
          #pragma HLS dependence false variable=v1154
          #pragma HLS dependence false variable=v1156
          #pragma HLS dependence false variable=v1157
          ap_int<32> v1162 = v1154[0][v1158][v1160][v1161];	// L1853
          ap_int<32> v1163 = v1157[v1159][v1158][0][0];	// L1854
          ap_int<64> v1164 = v1156[0][v1159][v1160][v1161];	// L1855
          ap_int<64> v1165 = v1162;	// L1856
          ap_int<64> v1166 = v1163;	// L1857
          ap_int<64> v1167 = v1165 * v1166;	// L1858
          ap_int<64> v1168 = v1164 + v1167;	// L1859
          v1156[0][v1159][v1160][v1161] = v1168;	// L1860
        }
      }
    }
  }
}

void kernel460(
  ap_int<64> v1169[1][768][16][16],
  ap_int<64> v1170
) {	// L1867
  for (int v1171 = 0; v1171 < 768; v1171 += 1) {	// L1868
    for (int v1172 = 0; v1172 < 16; v1172 += 1) {	// L1869
      for (int v1173 = 0; v1173 < 16; v1173 += 1) {	// L1870
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1169
        v1169[0][v1171][v1172][v1173] = v1170;	// L1871
      }
    }
  }
}

void kernel461(
  ap_int<8> v1174[768][192][1][1],
  ap_int<32> v1175[768][192][1][1]
) {	// L1877
  for (int v1176 = 0; v1176 < 768; v1176 += 1) {	// L1878
    for (int v1177 = 0; v1177 < 192; v1177 += 1) {	// L1879
      ap_int<8> v1178 = v1174[v1176][v1177][0][0];	// L1880
      ap_int<32> v1179 = v1178;	// L1881
      v1175[v1176][v1177][0][0] = v1179;	// L1882
    }
  }
}

void kernel463(
  ap_int<8> v1180[1][192][256],
  ap_int<8> v1181[1][192][16][16],
  ap_int<8> v1182[1][192][16][16]
) {	// L1887
  for (int v1183 = 0; v1183 < 192; v1183 += 1) {	// L1888
    for (int v1184 = 0; v1184 < 16; v1184 += 1) {	// L1889
      for (int v1185 = 0; v1185 < 16; v1185 += 1) {	// L1890
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1181
        #pragma HLS dependence false variable=v1182
        #pragma HLS dependence false variable=v1180
        ap_int<8> v1186 = v1181[0][v1183][v1184][v1185];	// L1891
        ap_int<8> v1187 = v1180[0][v1183][((v1184 * 16) + v1185)];	// L1892
        ap_int<8> v1188 = v1186 + v1187;	// L1893
        v1182[0][v1183][v1184][v1185] = v1188;	// L1894
      }
    }
  }
}

void kernel464(
  float v1189[1][192][256],
  float v1190[1][192][256]
) {	// L1900
  for (int v1191 = 0; v1191 < 192; v1191 += 1) {	// L1901
    for (int v1192 = 0; v1192 < 256; v1192 += 1) {	// L1902
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v1189
      #pragma HLS dependence false variable=v1190
      float v1193 = v1189[0][v1191][v1192];	// L1903
      v1190[0][v1191][v1192] = v1193;	// L1904
    }
  }
}

void kernel465(
  float v1194[1][192][256],
  float v1195[1][192][256]
) {	// L1909
  for (int v1196 = 0; v1196 < 192; v1196 += 1) {	// L1910
    for (int v1197 = 0; v1197 < 256; v1197 += 1) {	// L1911
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v1194
      #pragma HLS dependence false variable=v1195
      float v1198 = v1194[0][v1196][v1197];	// L1912
      float v1199 = v1195[0][v1196][v1197];	// L1913
      float v1200 = v1198 + v1199;	// L1914
      v1195[0][v1196][v1197] = v1200;	// L1915
    }
  }
}

void kernel466(
  float v1201[1][192][256],
  float v1202[1][192][256],
  float v1203[1][192][256]
) {	// L1920
  for (int v1204 = 0; v1204 < 192; v1204 += 1) {	// L1921
    for (int v1205 = 0; v1205 < 256; v1205 += 1) {	// L1922
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v1202
      #pragma HLS dependence false variable=v1203
      #pragma HLS dependence false variable=v1201
      float v1206 = v1202[0][v1204][v1205];	// L1923
      float v1207 = v1201[0][v1204][v1205];	// L1924
      float v1208 = v1206 - v1207;	// L1925
      v1203[0][v1204][v1205] = v1208;	// L1926
    }
  }
}

void kernel467(
  float v1209[1][192][256],
  float v1210[1][192][256],
  float v1211
) {	// L1931
  for (int v1212 = 0; v1212 < 192; v1212 += 1) {	// L1932
    for (int v1213 = 0; v1213 < 256; v1213 += 1) {	// L1933
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v1210
      #pragma HLS dependence false variable=v1209
      float v1214 = v1210[0][v1212][v1213];	// L1934
      float v1215 = v1209[0][v1212][v1213];	// L1935
      bool v1216 = v1214 >= v1211;	// L1936
      float v1217 = v1216 ? v1215 : v1211;	// L1937
      v1210[0][v1212][v1213] = v1217;	// L1938
    }
  }
}

void kernel468(
  float v1218[1][192][256],
  ap_int<8> v1219[1][192][256],
  float v1220
) {	// L1943
  for (int v1221 = 0; v1221 < 192; v1221 += 1) {	// L1944
    for (int v1222 = 0; v1222 < 256; v1222 += 1) {	// L1945
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v1218
      #pragma HLS dependence false variable=v1219
      float v1223 = v1218[0][v1221][v1222];	// L1946
      bool v1224 = v1223 >= v1220;	// L1947
      ap_int<8> v1225 = v1224;	// L1948
      v1219[0][v1221][v1222] = v1225;	// L1949
    }
  }
}

void kernel469(
  float v1226[1][192][256],
  float v1227
) {	// L1954
  for (int v1228 = 0; v1228 < 192; v1228 += 1) {	// L1955
    for (int v1229 = 0; v1229 < 256; v1229 += 1) {	// L1956
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v1226
      float v1230 = v1226[0][v1228][v1229];	// L1957
      float v1231 = v1230 - v1227;	// L1958
      v1226[0][v1228][v1229] = v1231;	// L1959
    }
  }
}

void kernel471(
  float v1232[1][192][256],
  float v1233[1][192][256],
  float v1234[1][192][256]
) {	// L1964
  for (int v1235 = 0; v1235 < 192; v1235 += 1) {	// L1965
    for (int v1236 = 0; v1236 < 256; v1236 += 1) {	// L1966
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v1233
      #pragma HLS dependence false variable=v1234
      #pragma HLS dependence false variable=v1232
      float v1237 = v1233[0][v1235][v1236];	// L1967
      float v1238 = v1232[0][v1235][v1236];	// L1968
      float v1239 = v1237 + v1238;	// L1969
      v1234[0][v1235][v1236] = v1239;	// L1970
    }
  }
}

void kernel472(
  float v1240[1][192][256],
  float v1241
) {	// L1975
  for (int v1242 = 0; v1242 < 192; v1242 += 1) {	// L1976
    for (int v1243 = 0; v1243 < 256; v1243 += 1) {	// L1977
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v1240
      float v1244 = v1240[0][v1242][v1243];	// L1978
      float v1245 = v1244 / v1241;	// L1979
      v1240[0][v1242][v1243] = v1245;	// L1980
    }
  }
}

void kernel477(
  float v1246[192],
  float v1247[1][192][256],
  float v1248[1][192][256]
) {	// L1985
  float v1249[192];	// L1986
  #pragma HLS resource variable=v1249 core=ram_t2p_bram

  memcpy(v1249, v1246, 192 * sizeof(float));	// L1987

  for (int v1250 = 0; v1250 < 192; v1250 += 1) {	// L1988
    for (int v1251 = 0; v1251 < 256; v1251 += 1) {	// L1989
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v1247
      #pragma HLS dependence false variable=v1248
      #pragma HLS dependence false variable=v1249
      float v1252 = v1247[0][v1250][v1251];	// L1990
      float v1253 = v1249[v1250];	// L1991
      float v1254 = v1252 + v1253;	// L1992
      v1248[0][v1250][v1251] = v1254;	// L1993
    }
  }
}

void kernel479(
  float v1255[1][192][1],
  float v1256[1][192][256]
) {	// L1998
  float v1257[1][192][1];	// L1999
  #pragma HLS resource variable=v1257 core=ram_t2p_bram

  memcpy(v1257, v1255, 192 * sizeof(float));	// L2000

  for (int v1258 = 0; v1258 < 192; v1258 += 1) {	// L2001
    for (int v1259 = 0; v1259 < 256; v1259 += 1) {	// L2002
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v1256
      #pragma HLS dependence false variable=v1257
      float v1260 = v1256[0][v1258][v1259];	// L2003
      float v1261 = v1257[0][v1258][0];	// L2004
      float v1262 = v1260 * v1261;	// L2005
      v1256[0][v1258][v1259] = v1262;	// L2006
    }
  }
}

void kernel480(
  ap_int<32> v1263[1][192][256],
  float v1264[1][192][256]
) {	// L2011
  for (int v1265 = 0; v1265 < 192; v1265 += 1) {	// L2012
    for (int v1266 = 0; v1266 < 256; v1266 += 1) {	// L2013
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v1263
      #pragma HLS dependence false variable=v1264
      ap_int<32> v1267 = v1263[0][v1265][v1266];	// L2014
      float v1268 = v1267;	// L2015
      v1264[0][v1265][v1266] = v1268;	// L2016
    }
  }
}

void kernel481(
  ap_int<64> v1269[1][192][256],
  ap_int<32> v1270[1][192][256]
) {	// L2021
  for (int v1271 = 0; v1271 < 192; v1271 += 1) {	// L2022
    for (int v1272 = 0; v1272 < 256; v1272 += 1) {	// L2023
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v1269
      #pragma HLS dependence false variable=v1270
      ap_int<64> v1273 = v1269[0][v1271][v1272];	// L2024
      ap_int<32> v1274 = v1273;	// L2025
      v1270[0][v1271][v1272] = v1274;	// L2026
    }
  }
}

void kernel482(
  ap_int<32> v1275[1][192][256],
  ap_int<32> v1276[192][192][1],
  ap_int<64> v1277[1][192][256]
) {	// L2031
  ap_int<32> v1278[192][192][1];	// L2032
  #pragma HLS resource variable=v1278 core=ram_t2p_bram

  memcpy(v1278, v1276, 36864 * sizeof(ap_int<32>));	// L2033

  for (int v1279 = 0; v1279 < 192; v1279 += 1) {	// L2034
    for (int v1280 = 0; v1280 < 192; v1280 += 1) {	// L2035
      for (int v1281 = 0; v1281 < 256; v1281 += 1) {	// L2036
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1275
        #pragma HLS dependence false variable=v1277
        #pragma HLS dependence false variable=v1278
        ap_int<32> v1282 = v1275[0][v1279][v1281];	// L2037
        ap_int<32> v1283 = v1278[v1280][v1279][0];	// L2038
        ap_int<64> v1284 = v1277[0][v1280][v1281];	// L2039
        ap_int<64> v1285 = v1282;	// L2040
        ap_int<64> v1286 = v1283;	// L2041
        ap_int<64> v1287 = v1285 * v1286;	// L2042
        ap_int<64> v1288 = v1284 + v1287;	// L2043
        v1277[0][v1280][v1281] = v1288;	// L2044
      }
    }
  }
}

void kernel483(
  ap_int<8> v1289[192][192][1],
  ap_int<32> v1290[192][192][1]
) {	// L2050
  for (int v1291 = 0; v1291 < 192; v1291 += 1) {	// L2051
    for (int v1292 = 0; v1292 < 192; v1292 += 1) {	// L2052
      ap_int<8> v1293 = v1289[v1291][v1292][0];	// L2053
      ap_int<32> v1294 = v1293;	// L2054
      v1290[v1291][v1292][0] = v1294;	// L2055
    }
  }
}

void kernel484(
  ap_int<8> v1295[1][8][24][256],
  ap_int<32> v1296[1][192][256]
) {	// L2060
  for (int v1297 = 0; v1297 < 192; v1297 += 1) {	// L2061
    for (int v1298 = 0; v1298 < 256; v1298 += 1) {	// L2062
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v1295
      #pragma HLS dependence false variable=v1296
      ap_int<8> v1299 = v1295[0][(v1297 / 24)][(v1297 % 24)][v1298];	// L2063
      ap_int<32> v1300 = v1299;	// L2064
      v1296[0][v1297][v1298] = v1300;	// L2065
    }
  }
}

void kernel485(
  ap_int<8> v1301[1][192][256],
  ap_int<8> v1302[1][8][24][256]
) {	// L2070
  for (int v1303 = 0; v1303 < 8; v1303 += 1) {	// L2071
    for (int v1304 = 0; v1304 < 24; v1304 += 1) {	// L2072
      for (int v1305 = 0; v1305 < 256; v1305 += 1) {	// L2073
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1302
        #pragma HLS dependence false variable=v1301
        ap_int<8> v1306 = v1302[0][v1303][v1304][v1305];	// L2074
        ap_int<8> v1307 = v1301[0][((v1303 * 24) + v1304)][v1305];	// L2075
        ap_int<8> v1308 = v1306 * v1307;	// L2076
        v1302[0][v1303][v1304][v1305] = v1308;	// L2077
      }
    }
  }
}

void kernel486(
  float v1309[1][8][24][256],
  float v1310[1][8][24][256]
) {	// L2083
  for (int v1311 = 0; v1311 < 8; v1311 += 1) {	// L2084
    for (int v1312 = 0; v1312 < 24; v1312 += 1) {	// L2085
      for (int v1313 = 0; v1313 < 256; v1313 += 1) {	// L2086
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1309
        #pragma HLS dependence false variable=v1310
        float v1314 = v1309[0][v1311][v1312][v1313];	// L2087
        v1310[0][v1311][v1312][v1313] = v1314;	// L2088
      }
    }
  }
}

void kernel487(
  float v1315[1][8][24][256],
  float v1316[1][8][24][256]
) {	// L2094
  for (int v1317 = 0; v1317 < 8; v1317 += 1) {	// L2095
    for (int v1318 = 0; v1318 < 24; v1318 += 1) {	// L2096
      for (int v1319 = 0; v1319 < 256; v1319 += 1) {	// L2097
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1315
        #pragma HLS dependence false variable=v1316
        float v1320 = v1315[0][v1317][v1318][v1319];	// L2098
        float v1321 = v1316[0][v1317][v1318][v1319];	// L2099
        float v1322 = v1320 + v1321;	// L2100
        v1316[0][v1317][v1318][v1319] = v1322;	// L2101
      }
    }
  }
}

void kernel488(
  float v1323[1][8][24][256],
  float v1324[1][8][24][256],
  float v1325[1][8][24][256]
) {	// L2107
  for (int v1326 = 0; v1326 < 8; v1326 += 1) {	// L2108
    for (int v1327 = 0; v1327 < 24; v1327 += 1) {	// L2109
      for (int v1328 = 0; v1328 < 256; v1328 += 1) {	// L2110
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1324
        #pragma HLS dependence false variable=v1325
        #pragma HLS dependence false variable=v1323
        float v1329 = v1324[0][v1326][v1327][v1328];	// L2111
        float v1330 = v1323[0][v1326][v1327][v1328];	// L2112
        float v1331 = v1329 - v1330;	// L2113
        v1325[0][v1326][v1327][v1328] = v1331;	// L2114
      }
    }
  }
}

void kernel489(
  float v1332[1][8][24][256],
  float v1333[1][8][24][256],
  float v1334
) {	// L2120
  for (int v1335 = 0; v1335 < 8; v1335 += 1) {	// L2121
    for (int v1336 = 0; v1336 < 24; v1336 += 1) {	// L2122
      for (int v1337 = 0; v1337 < 256; v1337 += 1) {	// L2123
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1333
        #pragma HLS dependence false variable=v1332
        float v1338 = v1333[0][v1335][v1336][v1337];	// L2124
        float v1339 = v1332[0][v1335][v1336][v1337];	// L2125
        bool v1340 = v1338 >= v1334;	// L2126
        float v1341 = v1340 ? v1339 : v1334;	// L2127
        v1333[0][v1335][v1336][v1337] = v1341;	// L2128
      }
    }
  }
}

void kernel490(
  float v1342[1][8][24][256],
  ap_int<8> v1343[1][8][24][256],
  float v1344
) {	// L2134
  for (int v1345 = 0; v1345 < 8; v1345 += 1) {	// L2135
    for (int v1346 = 0; v1346 < 24; v1346 += 1) {	// L2136
      for (int v1347 = 0; v1347 < 256; v1347 += 1) {	// L2137
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1342
        #pragma HLS dependence false variable=v1343
        float v1348 = v1342[0][v1345][v1346][v1347];	// L2138
        bool v1349 = v1348 >= v1344;	// L2139
        ap_int<8> v1350 = v1349;	// L2140
        v1343[0][v1345][v1346][v1347] = v1350;	// L2141
      }
    }
  }
}

void kernel491(
  float v1351[1][8][24][256],
  float v1352
) {	// L2147
  for (int v1353 = 0; v1353 < 8; v1353 += 1) {	// L2148
    for (int v1354 = 0; v1354 < 24; v1354 += 1) {	// L2149
      for (int v1355 = 0; v1355 < 256; v1355 += 1) {	// L2150
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1351
        float v1356 = v1351[0][v1353][v1354][v1355];	// L2151
        float v1357 = v1356 - v1352;	// L2152
        v1351[0][v1353][v1354][v1355] = v1357;	// L2153
      }
    }
  }
}

void kernel493(
  float v1358[1][8][24][256],
  float v1359[1][8][24][256],
  float v1360[1][8][24][256]
) {	// L2159
  for (int v1361 = 0; v1361 < 8; v1361 += 1) {	// L2160
    for (int v1362 = 0; v1362 < 24; v1362 += 1) {	// L2161
      for (int v1363 = 0; v1363 < 256; v1363 += 1) {	// L2162
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1359
        #pragma HLS dependence false variable=v1360
        #pragma HLS dependence false variable=v1358
        float v1364 = v1359[0][v1361][v1362][v1363];	// L2163
        float v1365 = v1358[0][v1361][v1362][v1363];	// L2164
        float v1366 = v1364 + v1365;	// L2165
        v1360[0][v1361][v1362][v1363] = v1366;	// L2166
      }
    }
  }
}

void kernel494(
  float v1367[1][8][24][256],
  float v1368
) {	// L2172
  for (int v1369 = 0; v1369 < 8; v1369 += 1) {	// L2173
    for (int v1370 = 0; v1370 < 24; v1370 += 1) {	// L2174
      for (int v1371 = 0; v1371 < 256; v1371 += 1) {	// L2175
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1367
        float v1372 = v1367[0][v1369][v1370][v1371];	// L2176
        float v1373 = v1372 / v1368;	// L2177
        v1367[0][v1369][v1370][v1371] = v1373;	// L2178
      }
    }
  }
}

void kernel499(
  ap_int<8> v1374[1][8][24][256],
  float v1375[1][8][24][256]
) {	// L2184
  for (int v1376 = 0; v1376 < 8; v1376 += 1) {	// L2185
    for (int v1377 = 0; v1377 < 24; v1377 += 1) {	// L2186
      for (int v1378 = 0; v1378 < 256; v1378 += 1) {	// L2187
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1374
        #pragma HLS dependence false variable=v1375
        ap_int<8> v1379 = v1374[0][v1376][v1377][v1378];	// L2188
        float v1380 = v1379;	// L2189
        v1375[0][v1376][v1377][v1378] = v1380;	// L2190
      }
    }
  }
}

void kernel500(
  ap_int<8> v1381[1][192][256],
  ap_int<8> v1382[1][8][1][256],
  ap_int<8> v1383[1][8][24][256]
) {	// L2196
  for (int v1384 = 0; v1384 < 8; v1384 += 1) {	// L2197
    for (int v1385 = 0; v1385 < 24; v1385 += 1) {	// L2198
      for (int v1386 = 0; v1386 < 256; v1386 += 1) {	// L2199
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1382
        #pragma HLS dependence false variable=v1383
        #pragma HLS dependence false variable=v1381
        ap_int<8> v1387 = v1382[0][v1384][0][v1386];	// L2200
        ap_int<8> v1388 = v1381[0][((v1384 * 24) + v1385)][v1386];	// L2201
        ap_int<8> v1389 = v1387 * v1388;	// L2202
        v1383[0][v1384][v1385][v1386] = v1389;	// L2203
      }
    }
  }
}

void kernel501(
  ap_int<8> v1390[1][192][256],
  ap_int<8> v1391[1][8][1][256]
) {	// L2209
  for (int v1392 = 0; v1392 < 24; v1392 += 1) {	// L2210
    for (int v1393 = 0; v1393 < 8; v1393 += 1) {	// L2211
      for (int v1394 = 0; v1394 < 256; v1394 += 1) {	// L2212
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1390
        #pragma HLS dependence false variable=v1391
        ap_int<8> v1395 = v1390[0][((v1393 * 24) + v1392)][v1394];	// L2213
        ap_int<8> v1396 = v1391[0][v1393][0][v1394];	// L2214
        ap_int<8> v1397 = v1395 + v1396;	// L2215
        v1391[0][v1393][0][v1394] = v1397;	// L2216
      }
    }
  }
}

void kernel502(
  ap_int<8> v1398[1][8][1][256],
  ap_int<8> v1399
) {	// L2222
  for (int v1400 = 0; v1400 < 8; v1400 += 1) {	// L2223
    for (int v1401 = 0; v1401 < 256; v1401 += 1) {	// L2224
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v1398
      v1398[0][v1400][0][v1401] = v1399;	// L2225
    }
  }
}

void kernel522(
  ap_int<64> v1402[1][192][256],
  ap_int<64> v1403[1][192][256]
) {	// L2230
  for (int v1404 = 0; v1404 < 192; v1404 += 1) {	// L2231
    for (int v1405 = 0; v1405 < 256; v1405 += 1) {	// L2232
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v1402
      #pragma HLS dependence false variable=v1403
      ap_int<64> v1406 = v1402[0][v1404][v1405];	// L2233
      v1403[0][v1404][v1405] = v1406;	// L2234
    }
  }
}

void kernel544(
  ap_int<64> v1407[1][192][256],
  ap_int<64> v1408
) {	// L2239
  for (int v1409 = 0; v1409 < 192; v1409 += 1) {	// L2240
    for (int v1410 = 0; v1410 < 256; v1410 += 1) {	// L2241
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v1407
      v1407[0][v1409][v1410] = v1408;	// L2242
    }
  }
}

void kernel546(
  ap_int<8> v1411[1][192][16][16],
  ap_int<32> v1412[1][192][256]
) {	// L2247
  for (int v1413 = 0; v1413 < 192; v1413 += 1) {	// L2248
    for (int v1414 = 0; v1414 < 256; v1414 += 1) {	// L2249
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v1411
      #pragma HLS dependence false variable=v1412
      ap_int<8> v1415 = v1411[0][v1413][(v1414 / 16)][(v1414 % 16)];	// L2250
      ap_int<32> v1416 = v1415;	// L2251
      v1412[0][v1413][v1414] = v1416;	// L2252
    }
  }
}

void kernel566(
  ap_int<32> v1417[1][96][32][32],
  ap_int<32> v1418[192][96][1][1],
  ap_int<64> v1419[1][192][16][16]
) {	// L2257
  ap_int<32> v1420[192][96][1][1];	// L2258
  #pragma HLS resource variable=v1420 core=ram_t2p_bram

  memcpy(v1420, v1418, 18432 * sizeof(ap_int<32>));	// L2259

  for (int v1421 = 0; v1421 < 96; v1421 += 1) {	// L2260
    for (int v1422 = 0; v1422 < 192; v1422 += 1) {	// L2261
      for (int v1423 = 0; v1423 < 16; v1423 += 1) {	// L2262
        for (int v1424 = 0; v1424 < 16; v1424 += 1) {	// L2263
          #pragma HLS pipeline II=1
          #pragma HLS dependence false variable=v1417
          #pragma HLS dependence false variable=v1419
          #pragma HLS dependence false variable=v1420
          ap_int<32> v1425 = v1417[0][v1421][(v1423 * 2)][(v1424 * 2)];	// L2264
          ap_int<32> v1426 = v1420[v1422][v1421][0][0];	// L2265
          ap_int<64> v1427 = v1419[0][v1422][v1423][v1424];	// L2266
          ap_int<64> v1428 = v1425;	// L2267
          ap_int<64> v1429 = v1426;	// L2268
          ap_int<64> v1430 = v1428 * v1429;	// L2269
          ap_int<64> v1431 = v1427 + v1430;	// L2270
          v1419[0][v1422][v1423][v1424] = v1431;	// L2271
        }
      }
    }
  }
}

void kernel567(
  ap_int<64> v1432[1][192][16][16],
  ap_int<64> v1433[1][192][16][16]
) {	// L2278
  for (int v1434 = 0; v1434 < 192; v1434 += 1) {	// L2279
    for (int v1435 = 0; v1435 < 16; v1435 += 1) {	// L2280
      for (int v1436 = 0; v1436 < 16; v1436 += 1) {	// L2281
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1432
        #pragma HLS dependence false variable=v1433
        ap_int<64> v1437 = v1432[0][v1434][v1435][v1436];	// L2282
        v1433[0][v1434][v1435][v1436] = v1437;	// L2283
      }
    }
  }
}

void kernel568(
  ap_int<64> v1438[1][192][16][16],
  ap_int<64> v1439
) {	// L2289
  for (int v1440 = 0; v1440 < 192; v1440 += 1) {	// L2290
    for (int v1441 = 0; v1441 < 16; v1441 += 1) {	// L2291
      for (int v1442 = 0; v1442 < 16; v1442 += 1) {	// L2292
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1438
        v1438[0][v1440][v1441][v1442] = v1439;	// L2293
      }
    }
  }
}

void kernel569(
  ap_int<8> v1443[192][96][1][1],
  ap_int<32> v1444[192][96][1][1]
) {	// L2299
  for (int v1445 = 0; v1445 < 192; v1445 += 1) {	// L2300
    for (int v1446 = 0; v1446 < 96; v1446 += 1) {	// L2301
      ap_int<8> v1447 = v1443[v1445][v1446][0][0];	// L2302
      ap_int<32> v1448 = v1447;	// L2303
      v1444[v1445][v1446][0][0] = v1448;	// L2304
    }
  }
}

void kernel583(
  float v1449[1][192][34][34],
  float v1450[3][3],
  float v1451[1][192][16][16]
) {	// L2309
  for (int v1452 = 0; v1452 < 3; v1452 += 1) {	// L2310
    for (int v1453 = 0; v1453 < 3; v1453 += 1) {	// L2311
      for (int v1454 = 0; v1454 < 192; v1454 += 1) {	// L2312
        for (int v1455 = 0; v1455 < 16; v1455 += 1) {	// L2313
          for (int v1456 = 0; v1456 < 16; v1456 += 1) {	// L2314
            #pragma HLS pipeline II=1
            #pragma HLS dependence false variable=v1449
            #pragma HLS dependence false variable=v1451
            float v1457 = v1449[0][v1454][((v1455 * 2) + v1452)][((v1456 * 2) + v1453)];	// L2315
            float v1458 = v1451[0][v1454][v1455][v1456];	// L2316
            float v1459 = max(v1458, v1457);	// L2317
            v1451[0][v1454][v1455][v1456] = v1459;	// L2318
          }
        }
      }
    }
  }
}

void kernel584(
  float v1460[1][192][16][16],
  float v1461
) {	// L2326
  for (int v1462 = 0; v1462 < 192; v1462 += 1) {	// L2327
    for (int v1463 = 0; v1463 < 16; v1463 += 1) {	// L2328
      for (int v1464 = 0; v1464 < 16; v1464 += 1) {	// L2329
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1460
        v1460[0][v1462][v1463][v1464] = v1461;	// L2330
      }
    }
  }
}

void kernel585(
  float v1465[1][192][32][32],
  float v1466[1][192][34][34]
) {	// L2336
  for (int v1467 = 0; v1467 < 192; v1467 += 1) {	// L2337
    for (int v1468 = 0; v1468 < 32; v1468 += 1) {	// L2338
      for (int v1469 = 0; v1469 < 32; v1469 += 1) {	// L2339
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1465
        #pragma HLS dependence false variable=v1466
        float v1470 = v1465[0][v1467][v1468][v1469];	// L2340
        v1466[0][v1467][(v1468 + 1)][(v1469 + 1)] = v1470;	// L2341
      }
    }
  }
}

void kernel586(
  float v1471[1][192][34][34],
  float v1472
) {	// L2347
  for (int v1473 = 0; v1473 < 192; v1473 += 1) {	// L2348
    for (int v1474 = 0; v1474 < 34; v1474 += 1) {	// L2349
      for (int v1475 = 0; v1475 < 34; v1475 += 1) {	// L2350
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1471
        v1471[0][v1473][v1474][v1475] = v1472;	// L2351
      }
    }
  }
}

void kernel587(
  float v1476[192],
  float v1477[1][192][32][32]
) {	// L2357
  float v1478[192];	// L2358
  #pragma HLS resource variable=v1478 core=ram_t2p_bram

  memcpy(v1478, v1476, 192 * sizeof(float));	// L2359

  for (int v1479 = 0; v1479 < 192; v1479 += 1) {	// L2360
    for (int v1480 = 0; v1480 < 32; v1480 += 1) {	// L2361
      for (int v1481 = 0; v1481 < 32; v1481 += 1) {	// L2362
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1477
        #pragma HLS dependence false variable=v1478
        float v1482 = v1477[0][v1479][v1480][v1481];	// L2363
        float v1483 = v1478[v1479];	// L2364
        float v1484 = v1482 + v1483;	// L2365
        v1477[0][v1479][v1480][v1481] = v1484;	// L2366
      }
    }
  }
}

void kernel589(
  float v1485[1][192][1][1],
  float v1486[1][192][32][32]
) {	// L2372
  float v1487[1][192][1][1];	// L2373
  #pragma HLS resource variable=v1487 core=ram_t2p_bram

  memcpy(v1487, v1485, 192 * sizeof(float));	// L2374

  for (int v1488 = 0; v1488 < 192; v1488 += 1) {	// L2375
    for (int v1489 = 0; v1489 < 32; v1489 += 1) {	// L2376
      for (int v1490 = 0; v1490 < 32; v1490 += 1) {	// L2377
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1486
        #pragma HLS dependence false variable=v1487
        float v1491 = v1486[0][v1488][v1489][v1490];	// L2378
        float v1492 = v1487[0][v1488][0][0];	// L2379
        float v1493 = v1491 * v1492;	// L2380
        v1486[0][v1488][v1489][v1490] = v1493;	// L2381
      }
    }
  }
}

void kernel590(
  ap_int<32> v1494[1][192][32][32],
  float v1495[1][192][32][32]
) {	// L2387
  for (int v1496 = 0; v1496 < 192; v1496 += 1) {	// L2388
    for (int v1497 = 0; v1497 < 32; v1497 += 1) {	// L2389
      for (int v1498 = 0; v1498 < 32; v1498 += 1) {	// L2390
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1494
        #pragma HLS dependence false variable=v1495
        ap_int<32> v1499 = v1494[0][v1496][v1497][v1498];	// L2391
        float v1500 = v1499;	// L2392
        v1495[0][v1496][v1497][v1498] = v1500;	// L2393
      }
    }
  }
}

void kernel591(
  ap_int<64> v1501[1][192][32][32],
  ap_int<32> v1502[1][192][32][32]
) {	// L2399
  for (int v1503 = 0; v1503 < 192; v1503 += 1) {	// L2400
    for (int v1504 = 0; v1504 < 32; v1504 += 1) {	// L2401
      for (int v1505 = 0; v1505 < 32; v1505 += 1) {	// L2402
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1501
        #pragma HLS dependence false variable=v1502
        ap_int<64> v1506 = v1501[0][v1503][v1504][v1505];	// L2403
        ap_int<32> v1507 = v1506;	// L2404
        v1502[0][v1503][v1504][v1505] = v1507;	// L2405
      }
    }
  }
}

void kernel592(
  ap_int<32> v1508[1][192][34][34],
  ap_int<32> v1509[192][192][3][3],
  ap_int<64> v1510[1][192][32][32]
) {	// L2411
  ap_int<32> v1511[192][192][3][3];	// L2412
  #pragma HLS resource variable=v1511 core=ram_t2p_bram

  memcpy(v1511, v1509, 331776 * sizeof(ap_int<32>));	// L2413

  for (int v1512 = 0; v1512 < 192; v1512 += 1) {	// L2414
    for (int v1513 = 0; v1513 < 3; v1513 += 1) {	// L2415
      for (int v1514 = 0; v1514 < 3; v1514 += 1) {	// L2416
        for (int v1515 = 0; v1515 < 192; v1515 += 1) {	// L2417
          for (int v1516 = 0; v1516 < 32; v1516 += 1) {	// L2418
            for (int v1517 = 0; v1517 < 32; v1517 += 1) {	// L2419
              #pragma HLS pipeline II=1
              #pragma HLS dependence false variable=v1508
              #pragma HLS dependence false variable=v1510
              #pragma HLS dependence false variable=v1511
              ap_int<32> v1518 = v1508[0][v1512][(v1516 + v1513)][(v1517 + v1514)];	// L2420
              ap_int<32> v1519 = v1511[v1515][v1512][v1513][v1514];	// L2421
              ap_int<64> v1520 = v1510[0][v1515][v1516][v1517];	// L2422
              ap_int<64> v1521 = v1518;	// L2423
              ap_int<64> v1522 = v1519;	// L2424
              ap_int<64> v1523 = v1521 * v1522;	// L2425
              ap_int<64> v1524 = v1520 + v1523;	// L2426
              v1510[0][v1515][v1516][v1517] = v1524;	// L2427
            }
          }
        }
      }
    }
  }
}

void kernel593(
  ap_int<32> v1525[1][192][32][32],
  ap_int<32> v1526[1][192][34][34]
) {	// L2436
  for (int v1527 = 0; v1527 < 192; v1527 += 1) {	// L2437
    for (int v1528 = 0; v1528 < 32; v1528 += 1) {	// L2438
      for (int v1529 = 0; v1529 < 32; v1529 += 1) {	// L2439
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1525
        #pragma HLS dependence false variable=v1526
        ap_int<32> v1530 = v1525[0][v1527][v1528][v1529];	// L2440
        v1526[0][v1527][(v1528 + 1)][(v1529 + 1)] = v1530;	// L2441
      }
    }
  }
}

void kernel594(
  ap_int<32> v1531[1][192][34][34],
  ap_int<32> v1532
) {	// L2447
  for (int v1533 = 0; v1533 < 192; v1533 += 1) {	// L2448
    for (int v1534 = 0; v1534 < 34; v1534 += 1) {	// L2449
      for (int v1535 = 0; v1535 < 34; v1535 += 1) {	// L2450
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1531
        v1531[0][v1533][v1534][v1535] = v1532;	// L2451
      }
    }
  }
}

void kernel595(
  ap_int<8> v1536[192][192][3][3],
  ap_int<32> v1537[192][192][3][3]
) {	// L2457
  for (int v1538 = 0; v1538 < 192; v1538 += 1) {	// L2458
    for (int v1539 = 0; v1539 < 192; v1539 += 1) {	// L2459
      for (int v1540 = 0; v1540 < 3; v1540 += 1) {	// L2460
        for (int v1541 = 0; v1541 < 3; v1541 += 1) {	// L2461
          #pragma HLS pipeline II=1
          #pragma HLS dependence false variable=v1536
          #pragma HLS dependence false variable=v1537
          ap_int<8> v1542 = v1536[v1538][v1539][v1540][v1541];	// L2462
          ap_int<32> v1543 = v1542;	// L2463
          v1537[v1538][v1539][v1540][v1541] = v1543;	// L2464
        }
      }
    }
  }
}

void kernel596(
  ap_int<8> v1544[1][192][32][32],
  ap_int<32> v1545[1][192][32][32]
) {	// L2471
  for (int v1546 = 0; v1546 < 192; v1546 += 1) {	// L2472
    for (int v1547 = 0; v1547 < 32; v1547 += 1) {	// L2473
      for (int v1548 = 0; v1548 < 32; v1548 += 1) {	// L2474
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1544
        #pragma HLS dependence false variable=v1545
        ap_int<8> v1549 = v1544[0][v1546][v1547][v1548];	// L2475
        ap_int<32> v1550 = v1549;	// L2476
        v1545[0][v1546][v1547][v1548] = v1550;	// L2477
      }
    }
  }
}

void kernel597(
  float v1551[1][192][32][32],
  float v1552[1][192][32][32]
) {	// L2483
  for (int v1553 = 0; v1553 < 192; v1553 += 1) {	// L2484
    for (int v1554 = 0; v1554 < 32; v1554 += 1) {	// L2485
      for (int v1555 = 0; v1555 < 32; v1555 += 1) {	// L2486
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1551
        #pragma HLS dependence false variable=v1552
        float v1556 = v1551[0][v1553][v1554][v1555];	// L2487
        v1552[0][v1553][v1554][v1555] = v1556;	// L2488
      }
    }
  }
}

void kernel598(
  float v1557[1][192][32][32],
  float v1558[1][192][32][32]
) {	// L2494
  for (int v1559 = 0; v1559 < 192; v1559 += 1) {	// L2495
    for (int v1560 = 0; v1560 < 32; v1560 += 1) {	// L2496
      for (int v1561 = 0; v1561 < 32; v1561 += 1) {	// L2497
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1557
        #pragma HLS dependence false variable=v1558
        float v1562 = v1557[0][v1559][v1560][v1561];	// L2498
        float v1563 = v1558[0][v1559][v1560][v1561];	// L2499
        float v1564 = v1562 + v1563;	// L2500
        v1558[0][v1559][v1560][v1561] = v1564;	// L2501
      }
    }
  }
}

void kernel599(
  float v1565[1][192][32][32],
  float v1566[1][192][32][32],
  float v1567[1][192][32][32]
) {	// L2507
  for (int v1568 = 0; v1568 < 192; v1568 += 1) {	// L2508
    for (int v1569 = 0; v1569 < 32; v1569 += 1) {	// L2509
      for (int v1570 = 0; v1570 < 32; v1570 += 1) {	// L2510
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1566
        #pragma HLS dependence false variable=v1567
        #pragma HLS dependence false variable=v1565
        float v1571 = v1566[0][v1568][v1569][v1570];	// L2511
        float v1572 = v1565[0][v1568][v1569][v1570];	// L2512
        float v1573 = v1571 - v1572;	// L2513
        v1567[0][v1568][v1569][v1570] = v1573;	// L2514
      }
    }
  }
}

void kernel600(
  float v1574[1][192][32][32],
  float v1575[1][192][32][32],
  float v1576
) {	// L2520
  for (int v1577 = 0; v1577 < 192; v1577 += 1) {	// L2521
    for (int v1578 = 0; v1578 < 32; v1578 += 1) {	// L2522
      for (int v1579 = 0; v1579 < 32; v1579 += 1) {	// L2523
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1575
        #pragma HLS dependence false variable=v1574
        float v1580 = v1575[0][v1577][v1578][v1579];	// L2524
        float v1581 = v1574[0][v1577][v1578][v1579];	// L2525
        bool v1582 = v1580 >= v1576;	// L2526
        float v1583 = v1582 ? v1581 : v1576;	// L2527
        v1575[0][v1577][v1578][v1579] = v1583;	// L2528
      }
    }
  }
}

void kernel601(
  float v1584[1][192][32][32],
  ap_int<8> v1585[1][192][32][32],
  float v1586
) {	// L2534
  for (int v1587 = 0; v1587 < 192; v1587 += 1) {	// L2535
    for (int v1588 = 0; v1588 < 32; v1588 += 1) {	// L2536
      for (int v1589 = 0; v1589 < 32; v1589 += 1) {	// L2537
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1584
        #pragma HLS dependence false variable=v1585
        float v1590 = v1584[0][v1587][v1588][v1589];	// L2538
        bool v1591 = v1590 >= v1586;	// L2539
        ap_int<8> v1592 = v1591;	// L2540
        v1585[0][v1587][v1588][v1589] = v1592;	// L2541
      }
    }
  }
}

void kernel602(
  float v1593[1][192][32][32],
  float v1594
) {	// L2547
  for (int v1595 = 0; v1595 < 192; v1595 += 1) {	// L2548
    for (int v1596 = 0; v1596 < 32; v1596 += 1) {	// L2549
      for (int v1597 = 0; v1597 < 32; v1597 += 1) {	// L2550
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1593
        float v1598 = v1593[0][v1595][v1596][v1597];	// L2551
        float v1599 = v1598 - v1594;	// L2552
        v1593[0][v1595][v1596][v1597] = v1599;	// L2553
      }
    }
  }
}

void kernel604(
  float v1600[1][192][32][32],
  float v1601[1][192][32][32],
  float v1602[1][192][32][32]
) {	// L2559
  for (int v1603 = 0; v1603 < 192; v1603 += 1) {	// L2560
    for (int v1604 = 0; v1604 < 32; v1604 += 1) {	// L2561
      for (int v1605 = 0; v1605 < 32; v1605 += 1) {	// L2562
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1601
        #pragma HLS dependence false variable=v1602
        #pragma HLS dependence false variable=v1600
        float v1606 = v1601[0][v1603][v1604][v1605];	// L2563
        float v1607 = v1600[0][v1603][v1604][v1605];	// L2564
        float v1608 = v1606 + v1607;	// L2565
        v1602[0][v1603][v1604][v1605] = v1608;	// L2566
      }
    }
  }
}

void kernel605(
  float v1609[1][192][32][32],
  float v1610
) {	// L2572
  for (int v1611 = 0; v1611 < 192; v1611 += 1) {	// L2573
    for (int v1612 = 0; v1612 < 32; v1612 += 1) {	// L2574
      for (int v1613 = 0; v1613 < 32; v1613 += 1) {	// L2575
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1609
        float v1614 = v1609[0][v1611][v1612][v1613];	// L2576
        float v1615 = v1614 / v1610;	// L2577
        v1609[0][v1611][v1612][v1613] = v1615;	// L2578
      }
    }
  }
}

void kernel610(
  float v1616[192],
  float v1617[1][192][32][32],
  float v1618[1][192][32][32]
) {	// L2584
  float v1619[192];	// L2585
  #pragma HLS resource variable=v1619 core=ram_t2p_bram

  memcpy(v1619, v1616, 192 * sizeof(float));	// L2586

  for (int v1620 = 0; v1620 < 192; v1620 += 1) {	// L2587
    for (int v1621 = 0; v1621 < 32; v1621 += 1) {	// L2588
      for (int v1622 = 0; v1622 < 32; v1622 += 1) {	// L2589
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1617
        #pragma HLS dependence false variable=v1618
        #pragma HLS dependence false variable=v1619
        float v1623 = v1617[0][v1620][v1621][v1622];	// L2590
        float v1624 = v1619[v1620];	// L2591
        float v1625 = v1623 + v1624;	// L2592
        v1618[0][v1620][v1621][v1622] = v1625;	// L2593
      }
    }
  }
}

void kernel615(
  ap_int<32> v1626[1][96][34][34],
  ap_int<32> v1627[192][96][3][3],
  ap_int<64> v1628[1][192][32][32]
) {	// L2599
  ap_int<32> v1629[192][96][3][3];	// L2600
  #pragma HLS resource variable=v1629 core=ram_t2p_bram

  memcpy(v1629, v1627, 165888 * sizeof(ap_int<32>));	// L2601

  for (int v1630 = 0; v1630 < 96; v1630 += 1) {	// L2602
    for (int v1631 = 0; v1631 < 3; v1631 += 1) {	// L2603
      for (int v1632 = 0; v1632 < 3; v1632 += 1) {	// L2604
        for (int v1633 = 0; v1633 < 192; v1633 += 1) {	// L2605
          for (int v1634 = 0; v1634 < 32; v1634 += 1) {	// L2606
            for (int v1635 = 0; v1635 < 32; v1635 += 1) {	// L2607
              #pragma HLS pipeline II=1
              #pragma HLS dependence false variable=v1626
              #pragma HLS dependence false variable=v1628
              #pragma HLS dependence false variable=v1629
              ap_int<32> v1636 = v1626[0][v1630][(v1634 + v1631)][(v1635 + v1632)];	// L2608
              ap_int<32> v1637 = v1629[v1633][v1630][v1631][v1632];	// L2609
              ap_int<64> v1638 = v1628[0][v1633][v1634][v1635];	// L2610
              ap_int<64> v1639 = v1636;	// L2611
              ap_int<64> v1640 = v1637;	// L2612
              ap_int<64> v1641 = v1639 * v1640;	// L2613
              ap_int<64> v1642 = v1638 + v1641;	// L2614
              v1628[0][v1633][v1634][v1635] = v1642;	// L2615
            }
          }
        }
      }
    }
  }
}

void kernel616(
  ap_int<64> v1643[1][192][32][32],
  ap_int<64> v1644[1][192][32][32]
) {	// L2624
  for (int v1645 = 0; v1645 < 192; v1645 += 1) {	// L2625
    for (int v1646 = 0; v1646 < 32; v1646 += 1) {	// L2626
      for (int v1647 = 0; v1647 < 32; v1647 += 1) {	// L2627
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1643
        #pragma HLS dependence false variable=v1644
        ap_int<64> v1648 = v1643[0][v1645][v1646][v1647];	// L2628
        v1644[0][v1645][v1646][v1647] = v1648;	// L2629
      }
    }
  }
}

void kernel617(
  ap_int<64> v1649[1][192][32][32],
  ap_int<64> v1650
) {	// L2635
  for (int v1651 = 0; v1651 < 192; v1651 += 1) {	// L2636
    for (int v1652 = 0; v1652 < 32; v1652 += 1) {	// L2637
      for (int v1653 = 0; v1653 < 32; v1653 += 1) {	// L2638
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1649
        v1649[0][v1651][v1652][v1653] = v1650;	// L2639
      }
    }
  }
}

void kernel618(
  ap_int<32> v1654[1][96][32][32],
  ap_int<32> v1655[1][96][34][34]
) {	// L2645
  for (int v1656 = 0; v1656 < 96; v1656 += 1) {	// L2646
    for (int v1657 = 0; v1657 < 32; v1657 += 1) {	// L2647
      for (int v1658 = 0; v1658 < 32; v1658 += 1) {	// L2648
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1654
        #pragma HLS dependence false variable=v1655
        ap_int<32> v1659 = v1654[0][v1656][v1657][v1658];	// L2649
        v1655[0][v1656][(v1657 + 1)][(v1658 + 1)] = v1659;	// L2650
      }
    }
  }
}

void kernel619(
  ap_int<32> v1660[1][96][34][34],
  ap_int<32> v1661
) {	// L2656
  for (int v1662 = 0; v1662 < 96; v1662 += 1) {	// L2657
    for (int v1663 = 0; v1663 < 34; v1663 += 1) {	// L2658
      for (int v1664 = 0; v1664 < 34; v1664 += 1) {	// L2659
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1660
        v1660[0][v1662][v1663][v1664] = v1661;	// L2660
      }
    }
  }
}

void kernel620(
  ap_int<8> v1665[192][96][3][3],
  ap_int<32> v1666[192][96][3][3]
) {	// L2666
  for (int v1667 = 0; v1667 < 192; v1667 += 1) {	// L2667
    for (int v1668 = 0; v1668 < 96; v1668 += 1) {	// L2668
      for (int v1669 = 0; v1669 < 3; v1669 += 1) {	// L2669
        for (int v1670 = 0; v1670 < 3; v1670 += 1) {	// L2670
          #pragma HLS pipeline II=1
          #pragma HLS dependence false variable=v1665
          #pragma HLS dependence false variable=v1666
          ap_int<8> v1671 = v1665[v1667][v1668][v1669][v1670];	// L2671
          ap_int<32> v1672 = v1671;	// L2672
          v1666[v1667][v1668][v1669][v1670] = v1672;	// L2673
        }
      }
    }
  }
}

void kernel621(
  ap_int<8> v1673[1][96][32][32],
  ap_int<32> v1674[1][96][32][32]
) {	// L2680
  for (int v1675 = 0; v1675 < 96; v1675 += 1) {	// L2681
    for (int v1676 = 0; v1676 < 32; v1676 += 1) {	// L2682
      for (int v1677 = 0; v1677 < 32; v1677 += 1) {	// L2683
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1673
        #pragma HLS dependence false variable=v1674
        ap_int<8> v1678 = v1673[0][v1675][v1676][v1677];	// L2684
        ap_int<32> v1679 = v1678;	// L2685
        v1674[0][v1675][v1676][v1677] = v1679;	// L2686
      }
    }
  }
}

void kernel622(
  ap_int<8> v1680[1][96][32][32],
  ap_int<8> v1681[1][96][32][32]
) {	// L2692
  for (int v1682 = 0; v1682 < 96; v1682 += 1) {	// L2693
    for (int v1683 = 0; v1683 < 32; v1683 += 1) {	// L2694
      for (int v1684 = 0; v1684 < 32; v1684 += 1) {	// L2695
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1680
        #pragma HLS dependence false variable=v1681
        ap_int<8> v1685 = v1680[0][v1682][v1683][v1684];	// L2696
        ap_int<8> v1686 = v1681[0][v1682][v1683][v1684];	// L2697
        ap_int<8> v1687 = v1685 + v1686;	// L2698
        v1681[0][v1682][v1683][v1684] = v1687;	// L2699
      }
    }
  }
}

void kernel623(
  float v1688[1][96][32][32],
  float v1689[1][96][32][32]
) {	// L2705
  for (int v1690 = 0; v1690 < 96; v1690 += 1) {	// L2706
    for (int v1691 = 0; v1691 < 32; v1691 += 1) {	// L2707
      for (int v1692 = 0; v1692 < 32; v1692 += 1) {	// L2708
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1688
        #pragma HLS dependence false variable=v1689
        float v1693 = v1688[0][v1690][v1691][v1692];	// L2709
        v1689[0][v1690][v1691][v1692] = v1693;	// L2710
      }
    }
  }
}

void kernel624(
  float v1694[1][96][32][32],
  float v1695[1][96][32][32]
) {	// L2716
  for (int v1696 = 0; v1696 < 96; v1696 += 1) {	// L2717
    for (int v1697 = 0; v1697 < 32; v1697 += 1) {	// L2718
      for (int v1698 = 0; v1698 < 32; v1698 += 1) {	// L2719
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1694
        #pragma HLS dependence false variable=v1695
        float v1699 = v1694[0][v1696][v1697][v1698];	// L2720
        float v1700 = v1695[0][v1696][v1697][v1698];	// L2721
        float v1701 = v1699 + v1700;	// L2722
        v1695[0][v1696][v1697][v1698] = v1701;	// L2723
      }
    }
  }
}

void kernel625(
  float v1702[1][96][32][32],
  float v1703[1][96][32][32],
  float v1704[1][96][32][32]
) {	// L2729
  for (int v1705 = 0; v1705 < 96; v1705 += 1) {	// L2730
    for (int v1706 = 0; v1706 < 32; v1706 += 1) {	// L2731
      for (int v1707 = 0; v1707 < 32; v1707 += 1) {	// L2732
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1703
        #pragma HLS dependence false variable=v1704
        #pragma HLS dependence false variable=v1702
        float v1708 = v1703[0][v1705][v1706][v1707];	// L2733
        float v1709 = v1702[0][v1705][v1706][v1707];	// L2734
        float v1710 = v1708 - v1709;	// L2735
        v1704[0][v1705][v1706][v1707] = v1710;	// L2736
      }
    }
  }
}

void kernel626(
  float v1711[1][96][32][32],
  float v1712[1][96][32][32],
  float v1713
) {	// L2742
  for (int v1714 = 0; v1714 < 96; v1714 += 1) {	// L2743
    for (int v1715 = 0; v1715 < 32; v1715 += 1) {	// L2744
      for (int v1716 = 0; v1716 < 32; v1716 += 1) {	// L2745
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1712
        #pragma HLS dependence false variable=v1711
        float v1717 = v1712[0][v1714][v1715][v1716];	// L2746
        float v1718 = v1711[0][v1714][v1715][v1716];	// L2747
        bool v1719 = v1717 >= v1713;	// L2748
        float v1720 = v1719 ? v1718 : v1713;	// L2749
        v1712[0][v1714][v1715][v1716] = v1720;	// L2750
      }
    }
  }
}

void kernel627(
  float v1721[1][96][32][32],
  ap_int<8> v1722[1][96][32][32],
  float v1723
) {	// L2756
  for (int v1724 = 0; v1724 < 96; v1724 += 1) {	// L2757
    for (int v1725 = 0; v1725 < 32; v1725 += 1) {	// L2758
      for (int v1726 = 0; v1726 < 32; v1726 += 1) {	// L2759
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1721
        #pragma HLS dependence false variable=v1722
        float v1727 = v1721[0][v1724][v1725][v1726];	// L2760
        bool v1728 = v1727 >= v1723;	// L2761
        ap_int<8> v1729 = v1728;	// L2762
        v1722[0][v1724][v1725][v1726] = v1729;	// L2763
      }
    }
  }
}

void kernel628(
  float v1730[1][96][32][32],
  float v1731
) {	// L2769
  for (int v1732 = 0; v1732 < 96; v1732 += 1) {	// L2770
    for (int v1733 = 0; v1733 < 32; v1733 += 1) {	// L2771
      for (int v1734 = 0; v1734 < 32; v1734 += 1) {	// L2772
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1730
        float v1735 = v1730[0][v1732][v1733][v1734];	// L2773
        float v1736 = v1735 - v1731;	// L2774
        v1730[0][v1732][v1733][v1734] = v1736;	// L2775
      }
    }
  }
}

void kernel630(
  float v1737[1][96][32][32],
  float v1738[1][96][32][32],
  float v1739[1][96][32][32]
) {	// L2781
  for (int v1740 = 0; v1740 < 96; v1740 += 1) {	// L2782
    for (int v1741 = 0; v1741 < 32; v1741 += 1) {	// L2783
      for (int v1742 = 0; v1742 < 32; v1742 += 1) {	// L2784
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1738
        #pragma HLS dependence false variable=v1739
        #pragma HLS dependence false variable=v1737
        float v1743 = v1738[0][v1740][v1741][v1742];	// L2785
        float v1744 = v1737[0][v1740][v1741][v1742];	// L2786
        float v1745 = v1743 + v1744;	// L2787
        v1739[0][v1740][v1741][v1742] = v1745;	// L2788
      }
    }
  }
}

void kernel631(
  float v1746[1][96][32][32],
  float v1747
) {	// L2794
  for (int v1748 = 0; v1748 < 96; v1748 += 1) {	// L2795
    for (int v1749 = 0; v1749 < 32; v1749 += 1) {	// L2796
      for (int v1750 = 0; v1750 < 32; v1750 += 1) {	// L2797
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1746
        float v1751 = v1746[0][v1748][v1749][v1750];	// L2798
        float v1752 = v1751 / v1747;	// L2799
        v1746[0][v1748][v1749][v1750] = v1752;	// L2800
      }
    }
  }
}

void kernel636(
  float v1753[96],
  float v1754[1][96][32][32],
  float v1755[1][96][32][32]
) {	// L2806
  float v1756[96];	// L2807
  #pragma HLS resource variable=v1756 core=ram_t2p_bram

  memcpy(v1756, v1753, 96 * sizeof(float));	// L2808

  for (int v1757 = 0; v1757 < 96; v1757 += 1) {	// L2809
    for (int v1758 = 0; v1758 < 32; v1758 += 1) {	// L2810
      for (int v1759 = 0; v1759 < 32; v1759 += 1) {	// L2811
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1754
        #pragma HLS dependence false variable=v1755
        #pragma HLS dependence false variable=v1756
        float v1760 = v1754[0][v1757][v1758][v1759];	// L2812
        float v1761 = v1756[v1757];	// L2813
        float v1762 = v1760 + v1761;	// L2814
        v1755[0][v1757][v1758][v1759] = v1762;	// L2815
      }
    }
  }
}

void kernel637(
  float v1763[96],
  float v1764[96],
  float v1765[96]
) {	// L2821
  for (int v1766 = 0; v1766 < 96; v1766 += 1) {	// L2822
    #pragma HLS pipeline II=1
    #pragma HLS dependence false variable=v1764
    #pragma HLS dependence false variable=v1765
    #pragma HLS dependence false variable=v1763
    float v1767 = v1764[v1766];	// L2823
    float v1768 = v1763[v1766];	// L2824
    float v1769 = v1767 * v1768;	// L2825
    v1765[v1766] = v1769;	// L2826
  }
}

void kernel638(
  float v1770[1][96][1][1],
  float v1771[1][96][32][32]
) {	// L2830
  float v1772[1][96][1][1];	// L2831
  #pragma HLS resource variable=v1772 core=ram_t2p_bram

  memcpy(v1772, v1770, 96 * sizeof(float));	// L2832

  for (int v1773 = 0; v1773 < 96; v1773 += 1) {	// L2833
    for (int v1774 = 0; v1774 < 32; v1774 += 1) {	// L2834
      for (int v1775 = 0; v1775 < 32; v1775 += 1) {	// L2835
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1771
        #pragma HLS dependence false variable=v1772
        float v1776 = v1771[0][v1773][v1774][v1775];	// L2836
        float v1777 = v1772[0][v1773][0][0];	// L2837
        float v1778 = v1776 * v1777;	// L2838
        v1771[0][v1773][v1774][v1775] = v1778;	// L2839
      }
    }
  }
}

void kernel639(
  ap_int<32> v1779[1][96][32][32],
  float v1780[1][96][32][32]
) {	// L2845
  for (int v1781 = 0; v1781 < 96; v1781 += 1) {	// L2846
    for (int v1782 = 0; v1782 < 32; v1782 += 1) {	// L2847
      for (int v1783 = 0; v1783 < 32; v1783 += 1) {	// L2848
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1779
        #pragma HLS dependence false variable=v1780
        ap_int<32> v1784 = v1779[0][v1781][v1782][v1783];	// L2849
        float v1785 = v1784;	// L2850
        v1780[0][v1781][v1782][v1783] = v1785;	// L2851
      }
    }
  }
}

void kernel640(
  ap_int<64> v1786[1][96][32][32],
  ap_int<32> v1787[1][96][32][32]
) {	// L2857
  for (int v1788 = 0; v1788 < 96; v1788 += 1) {	// L2858
    for (int v1789 = 0; v1789 < 32; v1789 += 1) {	// L2859
      for (int v1790 = 0; v1790 < 32; v1790 += 1) {	// L2860
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1786
        #pragma HLS dependence false variable=v1787
        ap_int<64> v1791 = v1786[0][v1788][v1789][v1790];	// L2861
        ap_int<32> v1792 = v1791;	// L2862
        v1787[0][v1788][v1789][v1790] = v1792;	// L2863
      }
    }
  }
}

void kernel641(
  ap_int<32> v1793[1][384][32][32],
  ap_int<32> v1794[96][384][1][1],
  ap_int<64> v1795[1][96][32][32]
) {	// L2869
  ap_int<32> v1796[96][384][1][1];	// L2870
  #pragma HLS resource variable=v1796 core=ram_t2p_bram

  memcpy(v1796, v1794, 36864 * sizeof(ap_int<32>));	// L2871

  for (int v1797 = 0; v1797 < 384; v1797 += 1) {	// L2872
    for (int v1798 = 0; v1798 < 96; v1798 += 1) {	// L2873
      for (int v1799 = 0; v1799 < 32; v1799 += 1) {	// L2874
        for (int v1800 = 0; v1800 < 32; v1800 += 1) {	// L2875
          #pragma HLS pipeline II=1
          #pragma HLS dependence false variable=v1793
          #pragma HLS dependence false variable=v1795
          #pragma HLS dependence false variable=v1796
          ap_int<32> v1801 = v1793[0][v1797][v1799][v1800];	// L2876
          ap_int<32> v1802 = v1796[v1798][v1797][0][0];	// L2877
          ap_int<64> v1803 = v1795[0][v1798][v1799][v1800];	// L2878
          ap_int<64> v1804 = v1801;	// L2879
          ap_int<64> v1805 = v1802;	// L2880
          ap_int<64> v1806 = v1804 * v1805;	// L2881
          ap_int<64> v1807 = v1803 + v1806;	// L2882
          v1795[0][v1798][v1799][v1800] = v1807;	// L2883
        }
      }
    }
  }
}

void kernel642(
  ap_int<8> v1808[96][384][1][1],
  ap_int<32> v1809[96][384][1][1]
) {	// L2890
  for (int v1810 = 0; v1810 < 96; v1810 += 1) {	// L2891
    for (int v1811 = 0; v1811 < 384; v1811 += 1) {	// L2892
      ap_int<8> v1812 = v1808[v1810][v1811][0][0];	// L2893
      ap_int<32> v1813 = v1812;	// L2894
      v1809[v1810][v1811][0][0] = v1813;	// L2895
    }
  }
}

void kernel643(
  ap_int<8> v1814[1][384][32][32],
  ap_int<32> v1815[1][384][32][32]
) {	// L2900
  for (int v1816 = 0; v1816 < 384; v1816 += 1) {	// L2901
    for (int v1817 = 0; v1817 < 32; v1817 += 1) {	// L2902
      for (int v1818 = 0; v1818 < 32; v1818 += 1) {	// L2903
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1814
        #pragma HLS dependence false variable=v1815
        ap_int<8> v1819 = v1814[0][v1816][v1817][v1818];	// L2904
        ap_int<32> v1820 = v1819;	// L2905
        v1815[0][v1816][v1817][v1818] = v1820;	// L2906
      }
    }
  }
}

void kernel644(
  float v1821[1][384][32][32],
  float v1822[1][384][32][32]
) {	// L2912
  for (int v1823 = 0; v1823 < 384; v1823 += 1) {	// L2913
    for (int v1824 = 0; v1824 < 32; v1824 += 1) {	// L2914
      for (int v1825 = 0; v1825 < 32; v1825 += 1) {	// L2915
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1821
        #pragma HLS dependence false variable=v1822
        float v1826 = v1821[0][v1823][v1824][v1825];	// L2916
        v1822[0][v1823][v1824][v1825] = v1826;	// L2917
      }
    }
  }
}

void kernel645(
  float v1827[1][384][32][32],
  float v1828[1][384][32][32]
) {	// L2923
  for (int v1829 = 0; v1829 < 384; v1829 += 1) {	// L2924
    for (int v1830 = 0; v1830 < 32; v1830 += 1) {	// L2925
      for (int v1831 = 0; v1831 < 32; v1831 += 1) {	// L2926
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1827
        #pragma HLS dependence false variable=v1828
        float v1832 = v1827[0][v1829][v1830][v1831];	// L2927
        float v1833 = v1828[0][v1829][v1830][v1831];	// L2928
        float v1834 = v1832 + v1833;	// L2929
        v1828[0][v1829][v1830][v1831] = v1834;	// L2930
      }
    }
  }
}

void kernel646(
  float v1835[1][384][32][32],
  float v1836[1][384][32][32],
  float v1837[1][384][32][32]
) {	// L2936
  for (int v1838 = 0; v1838 < 384; v1838 += 1) {	// L2937
    for (int v1839 = 0; v1839 < 32; v1839 += 1) {	// L2938
      for (int v1840 = 0; v1840 < 32; v1840 += 1) {	// L2939
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1836
        #pragma HLS dependence false variable=v1837
        #pragma HLS dependence false variable=v1835
        float v1841 = v1836[0][v1838][v1839][v1840];	// L2940
        float v1842 = v1835[0][v1838][v1839][v1840];	// L2941
        float v1843 = v1841 - v1842;	// L2942
        v1837[0][v1838][v1839][v1840] = v1843;	// L2943
      }
    }
  }
}

void kernel647(
  float v1844[1][384][32][32],
  float v1845[1][384][32][32],
  float v1846
) {	// L2949
  for (int v1847 = 0; v1847 < 384; v1847 += 1) {	// L2950
    for (int v1848 = 0; v1848 < 32; v1848 += 1) {	// L2951
      for (int v1849 = 0; v1849 < 32; v1849 += 1) {	// L2952
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1845
        #pragma HLS dependence false variable=v1844
        float v1850 = v1845[0][v1847][v1848][v1849];	// L2953
        float v1851 = v1844[0][v1847][v1848][v1849];	// L2954
        bool v1852 = v1850 >= v1846;	// L2955
        float v1853 = v1852 ? v1851 : v1846;	// L2956
        v1845[0][v1847][v1848][v1849] = v1853;	// L2957
      }
    }
  }
}

void kernel648(
  float v1854[1][384][32][32],
  ap_int<8> v1855[1][384][32][32],
  float v1856
) {	// L2963
  for (int v1857 = 0; v1857 < 384; v1857 += 1) {	// L2964
    for (int v1858 = 0; v1858 < 32; v1858 += 1) {	// L2965
      for (int v1859 = 0; v1859 < 32; v1859 += 1) {	// L2966
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1854
        #pragma HLS dependence false variable=v1855
        float v1860 = v1854[0][v1857][v1858][v1859];	// L2967
        bool v1861 = v1860 >= v1856;	// L2968
        ap_int<8> v1862 = v1861;	// L2969
        v1855[0][v1857][v1858][v1859] = v1862;	// L2970
      }
    }
  }
}

void kernel649(
  float v1863[1][384][32][32],
  float v1864
) {	// L2976
  for (int v1865 = 0; v1865 < 384; v1865 += 1) {	// L2977
    for (int v1866 = 0; v1866 < 32; v1866 += 1) {	// L2978
      for (int v1867 = 0; v1867 < 32; v1867 += 1) {	// L2979
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1863
        float v1868 = v1863[0][v1865][v1866][v1867];	// L2980
        float v1869 = v1868 - v1864;	// L2981
        v1863[0][v1865][v1866][v1867] = v1869;	// L2982
      }
    }
  }
}

void kernel651(
  float v1870[1][384][32][32],
  float v1871[1][384][32][32],
  float v1872[1][384][32][32]
) {	// L2988
  for (int v1873 = 0; v1873 < 384; v1873 += 1) {	// L2989
    for (int v1874 = 0; v1874 < 32; v1874 += 1) {	// L2990
      for (int v1875 = 0; v1875 < 32; v1875 += 1) {	// L2991
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1871
        #pragma HLS dependence false variable=v1872
        #pragma HLS dependence false variable=v1870
        float v1876 = v1871[0][v1873][v1874][v1875];	// L2992
        float v1877 = v1870[0][v1873][v1874][v1875];	// L2993
        float v1878 = v1876 + v1877;	// L2994
        v1872[0][v1873][v1874][v1875] = v1878;	// L2995
      }
    }
  }
}

void kernel652(
  float v1879[1][384][32][32],
  float v1880
) {	// L3001
  for (int v1881 = 0; v1881 < 384; v1881 += 1) {	// L3002
    for (int v1882 = 0; v1882 < 32; v1882 += 1) {	// L3003
      for (int v1883 = 0; v1883 < 32; v1883 += 1) {	// L3004
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1879
        float v1884 = v1879[0][v1881][v1882][v1883];	// L3005
        float v1885 = v1884 / v1880;	// L3006
        v1879[0][v1881][v1882][v1883] = v1885;	// L3007
      }
    }
  }
}

void kernel657(
  float v1886[384],
  float v1887[1][384][32][32],
  float v1888[1][384][32][32]
) {	// L3013
  float v1889[384];	// L3014
  #pragma HLS resource variable=v1889 core=ram_t2p_bram

  memcpy(v1889, v1886, 384 * sizeof(float));	// L3015

  for (int v1890 = 0; v1890 < 384; v1890 += 1) {	// L3016
    for (int v1891 = 0; v1891 < 32; v1891 += 1) {	// L3017
      for (int v1892 = 0; v1892 < 32; v1892 += 1) {	// L3018
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1887
        #pragma HLS dependence false variable=v1888
        #pragma HLS dependence false variable=v1889
        float v1893 = v1887[0][v1890][v1891][v1892];	// L3019
        float v1894 = v1889[v1890];	// L3020
        float v1895 = v1893 + v1894;	// L3021
        v1888[0][v1890][v1891][v1892] = v1895;	// L3022
      }
    }
  }
}

void kernel659(
  float v1896[1][384][1][1],
  float v1897[1][384][32][32]
) {	// L3028
  float v1898[1][384][1][1];	// L3029
  #pragma HLS resource variable=v1898 core=ram_t2p_bram

  memcpy(v1898, v1896, 384 * sizeof(float));	// L3030

  for (int v1899 = 0; v1899 < 384; v1899 += 1) {	// L3031
    for (int v1900 = 0; v1900 < 32; v1900 += 1) {	// L3032
      for (int v1901 = 0; v1901 < 32; v1901 += 1) {	// L3033
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1897
        #pragma HLS dependence false variable=v1898
        float v1902 = v1897[0][v1899][v1900][v1901];	// L3034
        float v1903 = v1898[0][v1899][0][0];	// L3035
        float v1904 = v1902 * v1903;	// L3036
        v1897[0][v1899][v1900][v1901] = v1904;	// L3037
      }
    }
  }
}

void kernel660(
  ap_int<32> v1905[1][384][32][32],
  float v1906[1][384][32][32]
) {	// L3043
  for (int v1907 = 0; v1907 < 384; v1907 += 1) {	// L3044
    for (int v1908 = 0; v1908 < 32; v1908 += 1) {	// L3045
      for (int v1909 = 0; v1909 < 32; v1909 += 1) {	// L3046
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1905
        #pragma HLS dependence false variable=v1906
        ap_int<32> v1910 = v1905[0][v1907][v1908][v1909];	// L3047
        float v1911 = v1910;	// L3048
        v1906[0][v1907][v1908][v1909] = v1911;	// L3049
      }
    }
  }
}

void kernel661(
  ap_int<64> v1912[1][384][32][32],
  ap_int<32> v1913[1][384][32][32]
) {	// L3055
  for (int v1914 = 0; v1914 < 384; v1914 += 1) {	// L3056
    for (int v1915 = 0; v1915 < 32; v1915 += 1) {	// L3057
      for (int v1916 = 0; v1916 < 32; v1916 += 1) {	// L3058
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1912
        #pragma HLS dependence false variable=v1913
        ap_int<64> v1917 = v1912[0][v1914][v1915][v1916];	// L3059
        ap_int<32> v1918 = v1917;	// L3060
        v1913[0][v1914][v1915][v1916] = v1918;	// L3061
      }
    }
  }
}

void kernel662(
  ap_int<32> v1919[1][96][32][32],
  ap_int<32> v1920[384][96][1][1],
  ap_int<64> v1921[1][384][32][32]
) {	// L3067
  ap_int<32> v1922[384][96][1][1];	// L3068
  #pragma HLS resource variable=v1922 core=ram_t2p_bram

  memcpy(v1922, v1920, 36864 * sizeof(ap_int<32>));	// L3069

  for (int v1923 = 0; v1923 < 96; v1923 += 1) {	// L3070
    for (int v1924 = 0; v1924 < 384; v1924 += 1) {	// L3071
      for (int v1925 = 0; v1925 < 32; v1925 += 1) {	// L3072
        for (int v1926 = 0; v1926 < 32; v1926 += 1) {	// L3073
          #pragma HLS pipeline II=1
          #pragma HLS dependence false variable=v1919
          #pragma HLS dependence false variable=v1921
          #pragma HLS dependence false variable=v1922
          ap_int<32> v1927 = v1919[0][v1923][v1925][v1926];	// L3074
          ap_int<32> v1928 = v1922[v1924][v1923][0][0];	// L3075
          ap_int<64> v1929 = v1921[0][v1924][v1925][v1926];	// L3076
          ap_int<64> v1930 = v1927;	// L3077
          ap_int<64> v1931 = v1928;	// L3078
          ap_int<64> v1932 = v1930 * v1931;	// L3079
          ap_int<64> v1933 = v1929 + v1932;	// L3080
          v1921[0][v1924][v1925][v1926] = v1933;	// L3081
        }
      }
    }
  }
}

void kernel663(
  ap_int<64> v1934[1][384][32][32],
  ap_int<64> v1935
) {	// L3088
  for (int v1936 = 0; v1936 < 384; v1936 += 1) {	// L3089
    for (int v1937 = 0; v1937 < 32; v1937 += 1) {	// L3090
      for (int v1938 = 0; v1938 < 32; v1938 += 1) {	// L3091
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1934
        v1934[0][v1936][v1937][v1938] = v1935;	// L3092
      }
    }
  }
}

void kernel664(
  ap_int<8> v1939[384][96][1][1],
  ap_int<32> v1940[384][96][1][1]
) {	// L3098
  for (int v1941 = 0; v1941 < 384; v1941 += 1) {	// L3099
    for (int v1942 = 0; v1942 < 96; v1942 += 1) {	// L3100
      ap_int<8> v1943 = v1939[v1941][v1942][0][0];	// L3101
      ap_int<32> v1944 = v1943;	// L3102
      v1940[v1941][v1942][0][0] = v1944;	// L3103
    }
  }
}

void kernel666(
  ap_int<8> v1945[1][96][1024],
  ap_int<8> v1946[1][96][32][32],
  ap_int<8> v1947[1][96][32][32]
) {	// L3108
  for (int v1948 = 0; v1948 < 96; v1948 += 1) {	// L3109
    for (int v1949 = 0; v1949 < 32; v1949 += 1) {	// L3110
      for (int v1950 = 0; v1950 < 32; v1950 += 1) {	// L3111
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1946
        #pragma HLS dependence false variable=v1947
        #pragma HLS dependence false variable=v1945
        ap_int<8> v1951 = v1946[0][v1948][v1949][v1950];	// L3112
        ap_int<8> v1952 = v1945[0][v1948][((v1949 * 32) + v1950)];	// L3113
        ap_int<8> v1953 = v1951 + v1952;	// L3114
        v1947[0][v1948][v1949][v1950] = v1953;	// L3115
      }
    }
  }
}

void kernel667(
  float v1954[1][96][1024],
  float v1955[1][96][1024]
) {	// L3121
  for (int v1956 = 0; v1956 < 96; v1956 += 1) {	// L3122
    for (int v1957 = 0; v1957 < 1024; v1957 += 1) {	// L3123
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v1954
      #pragma HLS dependence false variable=v1955
      float v1958 = v1954[0][v1956][v1957];	// L3124
      v1955[0][v1956][v1957] = v1958;	// L3125
    }
  }
}

void kernel668(
  float v1959[1][96][1024],
  float v1960[1][96][1024]
) {	// L3130
  for (int v1961 = 0; v1961 < 96; v1961 += 1) {	// L3131
    for (int v1962 = 0; v1962 < 1024; v1962 += 1) {	// L3132
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v1959
      #pragma HLS dependence false variable=v1960
      float v1963 = v1959[0][v1961][v1962];	// L3133
      float v1964 = v1960[0][v1961][v1962];	// L3134
      float v1965 = v1963 + v1964;	// L3135
      v1960[0][v1961][v1962] = v1965;	// L3136
    }
  }
}

void kernel669(
  float v1966[1][96][1024],
  float v1967[1][96][1024],
  float v1968[1][96][1024]
) {	// L3141
  for (int v1969 = 0; v1969 < 96; v1969 += 1) {	// L3142
    for (int v1970 = 0; v1970 < 1024; v1970 += 1) {	// L3143
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v1967
      #pragma HLS dependence false variable=v1968
      #pragma HLS dependence false variable=v1966
      float v1971 = v1967[0][v1969][v1970];	// L3144
      float v1972 = v1966[0][v1969][v1970];	// L3145
      float v1973 = v1971 - v1972;	// L3146
      v1968[0][v1969][v1970] = v1973;	// L3147
    }
  }
}

void kernel670(
  float v1974[1][96][1024],
  float v1975[1][96][1024],
  float v1976
) {	// L3152
  for (int v1977 = 0; v1977 < 96; v1977 += 1) {	// L3153
    for (int v1978 = 0; v1978 < 1024; v1978 += 1) {	// L3154
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v1975
      #pragma HLS dependence false variable=v1974
      float v1979 = v1975[0][v1977][v1978];	// L3155
      float v1980 = v1974[0][v1977][v1978];	// L3156
      bool v1981 = v1979 >= v1976;	// L3157
      float v1982 = v1981 ? v1980 : v1976;	// L3158
      v1975[0][v1977][v1978] = v1982;	// L3159
    }
  }
}

void kernel671(
  float v1983[1][96][1024],
  ap_int<8> v1984[1][96][1024],
  float v1985
) {	// L3164
  for (int v1986 = 0; v1986 < 96; v1986 += 1) {	// L3165
    for (int v1987 = 0; v1987 < 1024; v1987 += 1) {	// L3166
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v1983
      #pragma HLS dependence false variable=v1984
      float v1988 = v1983[0][v1986][v1987];	// L3167
      bool v1989 = v1988 >= v1985;	// L3168
      ap_int<8> v1990 = v1989;	// L3169
      v1984[0][v1986][v1987] = v1990;	// L3170
    }
  }
}

void kernel672(
  float v1991[1][96][1024],
  float v1992
) {	// L3175
  for (int v1993 = 0; v1993 < 96; v1993 += 1) {	// L3176
    for (int v1994 = 0; v1994 < 1024; v1994 += 1) {	// L3177
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v1991
      float v1995 = v1991[0][v1993][v1994];	// L3178
      float v1996 = v1995 - v1992;	// L3179
      v1991[0][v1993][v1994] = v1996;	// L3180
    }
  }
}

void kernel674(
  float v1997[1][96][1024],
  float v1998[1][96][1024],
  float v1999[1][96][1024]
) {	// L3185
  for (int v2000 = 0; v2000 < 96; v2000 += 1) {	// L3186
    for (int v2001 = 0; v2001 < 1024; v2001 += 1) {	// L3187
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v1998
      #pragma HLS dependence false variable=v1999
      #pragma HLS dependence false variable=v1997
      float v2002 = v1998[0][v2000][v2001];	// L3188
      float v2003 = v1997[0][v2000][v2001];	// L3189
      float v2004 = v2002 + v2003;	// L3190
      v1999[0][v2000][v2001] = v2004;	// L3191
    }
  }
}

void kernel675(
  float v2005[1][96][1024],
  float v2006
) {	// L3196
  for (int v2007 = 0; v2007 < 96; v2007 += 1) {	// L3197
    for (int v2008 = 0; v2008 < 1024; v2008 += 1) {	// L3198
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v2005
      float v2009 = v2005[0][v2007][v2008];	// L3199
      float v2010 = v2009 / v2006;	// L3200
      v2005[0][v2007][v2008] = v2010;	// L3201
    }
  }
}

void kernel680(
  float v2011[96],
  float v2012[1][96][1024],
  float v2013[1][96][1024]
) {	// L3206
  float v2014[96];	// L3207
  #pragma HLS resource variable=v2014 core=ram_t2p_bram

  memcpy(v2014, v2011, 96 * sizeof(float));	// L3208

  for (int v2015 = 0; v2015 < 96; v2015 += 1) {	// L3209
    for (int v2016 = 0; v2016 < 1024; v2016 += 1) {	// L3210
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v2012
      #pragma HLS dependence false variable=v2013
      #pragma HLS dependence false variable=v2014
      float v2017 = v2012[0][v2015][v2016];	// L3211
      float v2018 = v2014[v2015];	// L3212
      float v2019 = v2017 + v2018;	// L3213
      v2013[0][v2015][v2016] = v2019;	// L3214
    }
  }
}

void kernel682(
  float v2020[1][96][1],
  float v2021[1][96][1024]
) {	// L3219
  float v2022[1][96][1];	// L3220
  #pragma HLS resource variable=v2022 core=ram_t2p_bram

  memcpy(v2022, v2020, 96 * sizeof(float));	// L3221

  for (int v2023 = 0; v2023 < 96; v2023 += 1) {	// L3222
    for (int v2024 = 0; v2024 < 1024; v2024 += 1) {	// L3223
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v2021
      #pragma HLS dependence false variable=v2022
      float v2025 = v2021[0][v2023][v2024];	// L3224
      float v2026 = v2022[0][v2023][0];	// L3225
      float v2027 = v2025 * v2026;	// L3226
      v2021[0][v2023][v2024] = v2027;	// L3227
    }
  }
}

void kernel683(
  ap_int<32> v2028[1][96][1024],
  float v2029[1][96][1024]
) {	// L3232
  for (int v2030 = 0; v2030 < 96; v2030 += 1) {	// L3233
    for (int v2031 = 0; v2031 < 1024; v2031 += 1) {	// L3234
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v2028
      #pragma HLS dependence false variable=v2029
      ap_int<32> v2032 = v2028[0][v2030][v2031];	// L3235
      float v2033 = v2032;	// L3236
      v2029[0][v2030][v2031] = v2033;	// L3237
    }
  }
}

void kernel684(
  ap_int<64> v2034[1][96][1024],
  ap_int<32> v2035[1][96][1024]
) {	// L3242
  for (int v2036 = 0; v2036 < 96; v2036 += 1) {	// L3243
    for (int v2037 = 0; v2037 < 1024; v2037 += 1) {	// L3244
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v2034
      #pragma HLS dependence false variable=v2035
      ap_int<64> v2038 = v2034[0][v2036][v2037];	// L3245
      ap_int<32> v2039 = v2038;	// L3246
      v2035[0][v2036][v2037] = v2039;	// L3247
    }
  }
}

void kernel685(
  ap_int<32> v2040[1][96][1024],
  ap_int<32> v2041[96][96][1],
  ap_int<64> v2042[1][96][1024]
) {	// L3252
  ap_int<32> v2043[96][96][1];	// L3253
  #pragma HLS resource variable=v2043 core=ram_t2p_bram

  memcpy(v2043, v2041, 9216 * sizeof(ap_int<32>));	// L3254

  for (int v2044 = 0; v2044 < 96; v2044 += 1) {	// L3255
    for (int v2045 = 0; v2045 < 96; v2045 += 1) {	// L3256
      for (int v2046 = 0; v2046 < 1024; v2046 += 1) {	// L3257
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v2040
        #pragma HLS dependence false variable=v2042
        #pragma HLS dependence false variable=v2043
        ap_int<32> v2047 = v2040[0][v2044][v2046];	// L3258
        ap_int<32> v2048 = v2043[v2045][v2044][0];	// L3259
        ap_int<64> v2049 = v2042[0][v2045][v2046];	// L3260
        ap_int<64> v2050 = v2047;	// L3261
        ap_int<64> v2051 = v2048;	// L3262
        ap_int<64> v2052 = v2050 * v2051;	// L3263
        ap_int<64> v2053 = v2049 + v2052;	// L3264
        v2042[0][v2045][v2046] = v2053;	// L3265
      }
    }
  }
}

void kernel686(
  ap_int<8> v2054[96][96][1],
  ap_int<32> v2055[96][96][1]
) {	// L3271
  for (int v2056 = 0; v2056 < 96; v2056 += 1) {	// L3272
    for (int v2057 = 0; v2057 < 96; v2057 += 1) {	// L3273
      ap_int<8> v2058 = v2054[v2056][v2057][0];	// L3274
      ap_int<32> v2059 = v2058;	// L3275
      v2055[v2056][v2057][0] = v2059;	// L3276
    }
  }
}

void kernel687(
  ap_int<8> v2060[1][8][12][1024],
  ap_int<32> v2061[1][96][1024]
) {	// L3281
  for (int v2062 = 0; v2062 < 96; v2062 += 1) {	// L3282
    for (int v2063 = 0; v2063 < 1024; v2063 += 1) {	// L3283
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v2060
      #pragma HLS dependence false variable=v2061
      ap_int<8> v2064 = v2060[0][(v2062 / 12)][(v2062 % 12)][v2063];	// L3284
      ap_int<32> v2065 = v2064;	// L3285
      v2061[0][v2062][v2063] = v2065;	// L3286
    }
  }
}

void kernel688(
  ap_int<8> v2066[1][96][1024],
  ap_int<8> v2067[1][8][12][1024]
) {	// L3291
  for (int v2068 = 0; v2068 < 8; v2068 += 1) {	// L3292
    for (int v2069 = 0; v2069 < 12; v2069 += 1) {	// L3293
      for (int v2070 = 0; v2070 < 1024; v2070 += 1) {	// L3294
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v2067
        #pragma HLS dependence false variable=v2066
        ap_int<8> v2071 = v2067[0][v2068][v2069][v2070];	// L3295
        ap_int<8> v2072 = v2066[0][((v2068 * 12) + v2069)][v2070];	// L3296
        ap_int<8> v2073 = v2071 * v2072;	// L3297
        v2067[0][v2068][v2069][v2070] = v2073;	// L3298
      }
    }
  }
}

void kernel689(
  float v2074[1][8][12][1024],
  float v2075[1][8][12][1024]
) {	// L3304
  for (int v2076 = 0; v2076 < 8; v2076 += 1) {	// L3305
    for (int v2077 = 0; v2077 < 12; v2077 += 1) {	// L3306
      for (int v2078 = 0; v2078 < 1024; v2078 += 1) {	// L3307
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v2074
        #pragma HLS dependence false variable=v2075
        float v2079 = v2074[0][v2076][v2077][v2078];	// L3308
        v2075[0][v2076][v2077][v2078] = v2079;	// L3309
      }
    }
  }
}

void kernel690(
  float v2080[1][8][12][1024],
  float v2081[1][8][12][1024]
) {	// L3315
  for (int v2082 = 0; v2082 < 8; v2082 += 1) {	// L3316
    for (int v2083 = 0; v2083 < 12; v2083 += 1) {	// L3317
      for (int v2084 = 0; v2084 < 1024; v2084 += 1) {	// L3318
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v2080
        #pragma HLS dependence false variable=v2081
        float v2085 = v2080[0][v2082][v2083][v2084];	// L3319
        float v2086 = v2081[0][v2082][v2083][v2084];	// L3320
        float v2087 = v2085 + v2086;	// L3321
        v2081[0][v2082][v2083][v2084] = v2087;	// L3322
      }
    }
  }
}

void kernel691(
  float v2088[1][8][12][1024],
  float v2089[1][8][12][1024],
  float v2090[1][8][12][1024]
) {	// L3328
  for (int v2091 = 0; v2091 < 8; v2091 += 1) {	// L3329
    for (int v2092 = 0; v2092 < 12; v2092 += 1) {	// L3330
      for (int v2093 = 0; v2093 < 1024; v2093 += 1) {	// L3331
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v2089
        #pragma HLS dependence false variable=v2090
        #pragma HLS dependence false variable=v2088
        float v2094 = v2089[0][v2091][v2092][v2093];	// L3332
        float v2095 = v2088[0][v2091][v2092][v2093];	// L3333
        float v2096 = v2094 - v2095;	// L3334
        v2090[0][v2091][v2092][v2093] = v2096;	// L3335
      }
    }
  }
}

void kernel692(
  float v2097[1][8][12][1024],
  float v2098[1][8][12][1024],
  float v2099
) {	// L3341
  for (int v2100 = 0; v2100 < 8; v2100 += 1) {	// L3342
    for (int v2101 = 0; v2101 < 12; v2101 += 1) {	// L3343
      for (int v2102 = 0; v2102 < 1024; v2102 += 1) {	// L3344
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v2098
        #pragma HLS dependence false variable=v2097
        float v2103 = v2098[0][v2100][v2101][v2102];	// L3345
        float v2104 = v2097[0][v2100][v2101][v2102];	// L3346
        bool v2105 = v2103 >= v2099;	// L3347
        float v2106 = v2105 ? v2104 : v2099;	// L3348
        v2098[0][v2100][v2101][v2102] = v2106;	// L3349
      }
    }
  }
}

void kernel693(
  float v2107[1][8][12][1024],
  ap_int<8> v2108[1][8][12][1024],
  float v2109
) {	// L3355
  for (int v2110 = 0; v2110 < 8; v2110 += 1) {	// L3356
    for (int v2111 = 0; v2111 < 12; v2111 += 1) {	// L3357
      for (int v2112 = 0; v2112 < 1024; v2112 += 1) {	// L3358
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v2107
        #pragma HLS dependence false variable=v2108
        float v2113 = v2107[0][v2110][v2111][v2112];	// L3359
        bool v2114 = v2113 >= v2109;	// L3360
        ap_int<8> v2115 = v2114;	// L3361
        v2108[0][v2110][v2111][v2112] = v2115;	// L3362
      }
    }
  }
}

void kernel694(
  float v2116[1][8][12][1024],
  float v2117
) {	// L3368
  for (int v2118 = 0; v2118 < 8; v2118 += 1) {	// L3369
    for (int v2119 = 0; v2119 < 12; v2119 += 1) {	// L3370
      for (int v2120 = 0; v2120 < 1024; v2120 += 1) {	// L3371
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v2116
        float v2121 = v2116[0][v2118][v2119][v2120];	// L3372
        float v2122 = v2121 - v2117;	// L3373
        v2116[0][v2118][v2119][v2120] = v2122;	// L3374
      }
    }
  }
}

void kernel696(
  float v2123[1][8][12][1024],
  float v2124[1][8][12][1024],
  float v2125[1][8][12][1024]
) {	// L3380
  for (int v2126 = 0; v2126 < 8; v2126 += 1) {	// L3381
    for (int v2127 = 0; v2127 < 12; v2127 += 1) {	// L3382
      for (int v2128 = 0; v2128 < 1024; v2128 += 1) {	// L3383
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v2124
        #pragma HLS dependence false variable=v2125
        #pragma HLS dependence false variable=v2123
        float v2129 = v2124[0][v2126][v2127][v2128];	// L3384
        float v2130 = v2123[0][v2126][v2127][v2128];	// L3385
        float v2131 = v2129 + v2130;	// L3386
        v2125[0][v2126][v2127][v2128] = v2131;	// L3387
      }
    }
  }
}

void kernel697(
  float v2132[1][8][12][1024],
  float v2133
) {	// L3393
  for (int v2134 = 0; v2134 < 8; v2134 += 1) {	// L3394
    for (int v2135 = 0; v2135 < 12; v2135 += 1) {	// L3395
      for (int v2136 = 0; v2136 < 1024; v2136 += 1) {	// L3396
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v2132
        float v2137 = v2132[0][v2134][v2135][v2136];	// L3397
        float v2138 = v2137 / v2133;	// L3398
        v2132[0][v2134][v2135][v2136] = v2138;	// L3399
      }
    }
  }
}

void kernel702(
  ap_int<8> v2139[1][8][12][1024],
  float v2140[1][8][12][1024]
) {	// L3405
  for (int v2141 = 0; v2141 < 8; v2141 += 1) {	// L3406
    for (int v2142 = 0; v2142 < 12; v2142 += 1) {	// L3407
      for (int v2143 = 0; v2143 < 1024; v2143 += 1) {	// L3408
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v2139
        #pragma HLS dependence false variable=v2140
        ap_int<8> v2144 = v2139[0][v2141][v2142][v2143];	// L3409
        float v2145 = v2144;	// L3410
        v2140[0][v2141][v2142][v2143] = v2145;	// L3411
      }
    }
  }
}

void kernel703(
  ap_int<8> v2146[1][96][1024],
  ap_int<8> v2147[1][8][1][1024],
  ap_int<8> v2148[1][8][12][1024]
) {	// L3417
  for (int v2149 = 0; v2149 < 8; v2149 += 1) {	// L3418
    for (int v2150 = 0; v2150 < 12; v2150 += 1) {	// L3419
      for (int v2151 = 0; v2151 < 1024; v2151 += 1) {	// L3420
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v2147
        #pragma HLS dependence false variable=v2148
        #pragma HLS dependence false variable=v2146
        ap_int<8> v2152 = v2147[0][v2149][0][v2151];	// L3421
        ap_int<8> v2153 = v2146[0][((v2149 * 12) + v2150)][v2151];	// L3422
        ap_int<8> v2154 = v2152 * v2153;	// L3423
        v2148[0][v2149][v2150][v2151] = v2154;	// L3424
      }
    }
  }
}

void kernel704(
  ap_int<8> v2155[1][96][1024],
  ap_int<8> v2156[1][8][1][1024]
) {	// L3430
  for (int v2157 = 0; v2157 < 12; v2157 += 1) {	// L3431
    for (int v2158 = 0; v2158 < 8; v2158 += 1) {	// L3432
      for (int v2159 = 0; v2159 < 1024; v2159 += 1) {	// L3433
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v2155
        #pragma HLS dependence false variable=v2156
        ap_int<8> v2160 = v2155[0][((v2158 * 12) + v2157)][v2159];	// L3434
        ap_int<8> v2161 = v2156[0][v2158][0][v2159];	// L3435
        ap_int<8> v2162 = v2160 + v2161;	// L3436
        v2156[0][v2158][0][v2159] = v2162;	// L3437
      }
    }
  }
}

void kernel705(
  ap_int<8> v2163[1][8][1][1024],
  ap_int<8> v2164
) {	// L3443
  for (int v2165 = 0; v2165 < 8; v2165 += 1) {	// L3444
    for (int v2166 = 0; v2166 < 1024; v2166 += 1) {	// L3445
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v2163
      v2163[0][v2165][0][v2166] = v2164;	// L3446
    }
  }
}

void kernel725(
  ap_int<64> v2167[1][96][1024],
  ap_int<64> v2168[1][96][1024]
) {	// L3451
  for (int v2169 = 0; v2169 < 96; v2169 += 1) {	// L3452
    for (int v2170 = 0; v2170 < 1024; v2170 += 1) {	// L3453
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v2167
      #pragma HLS dependence false variable=v2168
      ap_int<64> v2171 = v2167[0][v2169][v2170];	// L3454
      v2168[0][v2169][v2170] = v2171;	// L3455
    }
  }
}

void kernel747(
  ap_int<64> v2172[1][96][1024],
  ap_int<64> v2173
) {	// L3460
  for (int v2174 = 0; v2174 < 96; v2174 += 1) {	// L3461
    for (int v2175 = 0; v2175 < 1024; v2175 += 1) {	// L3462
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v2172
      v2172[0][v2174][v2175] = v2173;	// L3463
    }
  }
}

void kernel749(
  ap_int<8> v2176[1][96][32][32],
  ap_int<32> v2177[1][96][1024]
) {	// L3468
  for (int v2178 = 0; v2178 < 96; v2178 += 1) {	// L3469
    for (int v2179 = 0; v2179 < 1024; v2179 += 1) {	// L3470
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v2176
      #pragma HLS dependence false variable=v2177
      ap_int<8> v2180 = v2176[0][v2178][(v2179 / 32)][(v2179 % 32)];	// L3471
      ap_int<32> v2181 = v2180;	// L3472
      v2177[0][v2178][v2179] = v2181;	// L3473
    }
  }
}

void kernel769(
  ap_int<32> v2182[1][48][32][32],
  ap_int<32> v2183[96][48][1][1],
  ap_int<64> v2184[1][96][32][32]
) {	// L3478
  ap_int<32> v2185[96][48][1][1];	// L3479
  #pragma HLS resource variable=v2185 core=ram_t2p_bram

  memcpy(v2185, v2183, 4608 * sizeof(ap_int<32>));	// L3480

  for (int v2186 = 0; v2186 < 48; v2186 += 1) {	// L3481
    for (int v2187 = 0; v2187 < 96; v2187 += 1) {	// L3482
      for (int v2188 = 0; v2188 < 32; v2188 += 1) {	// L3483
        for (int v2189 = 0; v2189 < 32; v2189 += 1) {	// L3484
          #pragma HLS pipeline II=1
          #pragma HLS dependence false variable=v2182
          #pragma HLS dependence false variable=v2184
          #pragma HLS dependence false variable=v2185
          ap_int<32> v2190 = v2182[0][v2186][v2188][v2189];	// L3485
          ap_int<32> v2191 = v2185[v2187][v2186][0][0];	// L3486
          ap_int<64> v2192 = v2184[0][v2187][v2188][v2189];	// L3487
          ap_int<64> v2193 = v2190;	// L3488
          ap_int<64> v2194 = v2191;	// L3489
          ap_int<64> v2195 = v2193 * v2194;	// L3490
          ap_int<64> v2196 = v2192 + v2195;	// L3491
          v2184[0][v2187][v2188][v2189] = v2196;	// L3492
        }
      }
    }
  }
}

void kernel770(
  ap_int<64> v2197[1][96][32][32],
  ap_int<64> v2198[1][96][32][32]
) {	// L3499
  for (int v2199 = 0; v2199 < 96; v2199 += 1) {	// L3500
    for (int v2200 = 0; v2200 < 32; v2200 += 1) {	// L3501
      for (int v2201 = 0; v2201 < 32; v2201 += 1) {	// L3502
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v2197
        #pragma HLS dependence false variable=v2198
        ap_int<64> v2202 = v2197[0][v2199][v2200][v2201];	// L3503
        v2198[0][v2199][v2200][v2201] = v2202;	// L3504
      }
    }
  }
}

void kernel771(
  ap_int<8> v2203[96][48][1][1],
  ap_int<32> v2204[96][48][1][1]
) {	// L3510
  for (int v2205 = 0; v2205 < 96; v2205 += 1) {	// L3511
    for (int v2206 = 0; v2206 < 48; v2206 += 1) {	// L3512
      ap_int<8> v2207 = v2203[v2205][v2206][0][0];	// L3513
      ap_int<32> v2208 = v2207;	// L3514
      v2204[v2205][v2206][0][0] = v2208;	// L3515
    }
  }
}

void kernel790(
  ap_int<32> v2209[1][48][34][34],
  ap_int<32> v2210[96][48][3][3],
  ap_int<64> v2211[1][96][32][32]
) {	// L3520
  ap_int<32> v2212[96][48][3][3];	// L3521
  #pragma HLS resource variable=v2212 core=ram_t2p_bram

  memcpy(v2212, v2210, 41472 * sizeof(ap_int<32>));	// L3522

  for (int v2213 = 0; v2213 < 48; v2213 += 1) {	// L3523
    for (int v2214 = 0; v2214 < 3; v2214 += 1) {	// L3524
      for (int v2215 = 0; v2215 < 3; v2215 += 1) {	// L3525
        for (int v2216 = 0; v2216 < 96; v2216 += 1) {	// L3526
          for (int v2217 = 0; v2217 < 32; v2217 += 1) {	// L3527
            for (int v2218 = 0; v2218 < 32; v2218 += 1) {	// L3528
              #pragma HLS pipeline II=1
              #pragma HLS dependence false variable=v2209
              #pragma HLS dependence false variable=v2211
              #pragma HLS dependence false variable=v2212
              ap_int<32> v2219 = v2209[0][v2213][(v2217 + v2214)][(v2218 + v2215)];	// L3529
              ap_int<32> v2220 = v2212[v2216][v2213][v2214][v2215];	// L3530
              ap_int<64> v2221 = v2211[0][v2216][v2217][v2218];	// L3531
              ap_int<64> v2222 = v2219;	// L3532
              ap_int<64> v2223 = v2220;	// L3533
              ap_int<64> v2224 = v2222 * v2223;	// L3534
              ap_int<64> v2225 = v2221 + v2224;	// L3535
              v2211[0][v2216][v2217][v2218] = v2225;	// L3536
            }
          }
        }
      }
    }
  }
}

void kernel792(
  ap_int<64> v2226[1][96][32][32],
  ap_int<64> v2227
) {	// L3545
  for (int v2228 = 0; v2228 < 96; v2228 += 1) {	// L3546
    for (int v2229 = 0; v2229 < 32; v2229 += 1) {	// L3547
      for (int v2230 = 0; v2230 < 32; v2230 += 1) {	// L3548
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v2226
        v2226[0][v2228][v2229][v2230] = v2227;	// L3549
      }
    }
  }
}

void kernel793(
  ap_int<32> v2231[1][48][32][32],
  ap_int<32> v2232[1][48][34][34]
) {	// L3555
  for (int v2233 = 0; v2233 < 48; v2233 += 1) {	// L3556
    for (int v2234 = 0; v2234 < 32; v2234 += 1) {	// L3557
      for (int v2235 = 0; v2235 < 32; v2235 += 1) {	// L3558
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v2231
        #pragma HLS dependence false variable=v2232
        ap_int<32> v2236 = v2231[0][v2233][v2234][v2235];	// L3559
        v2232[0][v2233][(v2234 + 1)][(v2235 + 1)] = v2236;	// L3560
      }
    }
  }
}

void kernel794(
  ap_int<32> v2237[1][48][34][34],
  ap_int<32> v2238
) {	// L3566
  for (int v2239 = 0; v2239 < 48; v2239 += 1) {	// L3567
    for (int v2240 = 0; v2240 < 34; v2240 += 1) {	// L3568
      for (int v2241 = 0; v2241 < 34; v2241 += 1) {	// L3569
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v2237
        v2237[0][v2239][v2240][v2241] = v2238;	// L3570
      }
    }
  }
}

void kernel795(
  ap_int<8> v2242[96][48][3][3],
  ap_int<32> v2243[96][48][3][3]
) {	// L3576
  for (int v2244 = 0; v2244 < 96; v2244 += 1) {	// L3577
    for (int v2245 = 0; v2245 < 48; v2245 += 1) {	// L3578
      for (int v2246 = 0; v2246 < 3; v2246 += 1) {	// L3579
        for (int v2247 = 0; v2247 < 3; v2247 += 1) {	// L3580
          #pragma HLS pipeline II=1
          #pragma HLS dependence false variable=v2242
          #pragma HLS dependence false variable=v2243
          ap_int<8> v2248 = v2242[v2244][v2245][v2246][v2247];	// L3581
          ap_int<32> v2249 = v2248;	// L3582
          v2243[v2244][v2245][v2246][v2247] = v2249;	// L3583
        }
      }
    }
  }
}

void kernel796(
  ap_int<8> v2250[1][48][32][32],
  ap_int<32> v2251[1][48][32][32]
) {	// L3590
  for (int v2252 = 0; v2252 < 48; v2252 += 1) {	// L3591
    for (int v2253 = 0; v2253 < 32; v2253 += 1) {	// L3592
      for (int v2254 = 0; v2254 < 32; v2254 += 1) {	// L3593
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v2250
        #pragma HLS dependence false variable=v2251
        ap_int<8> v2255 = v2250[0][v2252][v2253][v2254];	// L3594
        ap_int<32> v2256 = v2255;	// L3595
        v2251[0][v2252][v2253][v2254] = v2256;	// L3596
      }
    }
  }
}

void kernel797(
  float v2257[1][48][32][32],
  float v2258[1][48][32][32]
) {	// L3602
  for (int v2259 = 0; v2259 < 48; v2259 += 1) {	// L3603
    for (int v2260 = 0; v2260 < 32; v2260 += 1) {	// L3604
      for (int v2261 = 0; v2261 < 32; v2261 += 1) {	// L3605
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v2257
        #pragma HLS dependence false variable=v2258
        float v2262 = v2257[0][v2259][v2260][v2261];	// L3606
        v2258[0][v2259][v2260][v2261] = v2262;	// L3607
      }
    }
  }
}

void kernel798(
  float v2263[1][48][32][32],
  float v2264[1][48][32][32]
) {	// L3613
  for (int v2265 = 0; v2265 < 48; v2265 += 1) {	// L3614
    for (int v2266 = 0; v2266 < 32; v2266 += 1) {	// L3615
      for (int v2267 = 0; v2267 < 32; v2267 += 1) {	// L3616
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v2263
        #pragma HLS dependence false variable=v2264
        float v2268 = v2263[0][v2265][v2266][v2267];	// L3617
        float v2269 = v2264[0][v2265][v2266][v2267];	// L3618
        float v2270 = v2268 + v2269;	// L3619
        v2264[0][v2265][v2266][v2267] = v2270;	// L3620
      }
    }
  }
}

void kernel799(
  float v2271[1][48][32][32],
  float v2272[1][48][32][32],
  float v2273[1][48][32][32]
) {	// L3626
  for (int v2274 = 0; v2274 < 48; v2274 += 1) {	// L3627
    for (int v2275 = 0; v2275 < 32; v2275 += 1) {	// L3628
      for (int v2276 = 0; v2276 < 32; v2276 += 1) {	// L3629
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v2272
        #pragma HLS dependence false variable=v2273
        #pragma HLS dependence false variable=v2271
        float v2277 = v2272[0][v2274][v2275][v2276];	// L3630
        float v2278 = v2271[0][v2274][v2275][v2276];	// L3631
        float v2279 = v2277 - v2278;	// L3632
        v2273[0][v2274][v2275][v2276] = v2279;	// L3633
      }
    }
  }
}

void kernel800(
  float v2280[1][48][32][32],
  float v2281[1][48][32][32],
  float v2282
) {	// L3639
  for (int v2283 = 0; v2283 < 48; v2283 += 1) {	// L3640
    for (int v2284 = 0; v2284 < 32; v2284 += 1) {	// L3641
      for (int v2285 = 0; v2285 < 32; v2285 += 1) {	// L3642
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v2281
        #pragma HLS dependence false variable=v2280
        float v2286 = v2281[0][v2283][v2284][v2285];	// L3643
        float v2287 = v2280[0][v2283][v2284][v2285];	// L3644
        bool v2288 = v2286 >= v2282;	// L3645
        float v2289 = v2288 ? v2287 : v2282;	// L3646
        v2281[0][v2283][v2284][v2285] = v2289;	// L3647
      }
    }
  }
}

void kernel801(
  float v2290[1][48][32][32],
  ap_int<8> v2291[1][48][32][32],
  float v2292
) {	// L3653
  for (int v2293 = 0; v2293 < 48; v2293 += 1) {	// L3654
    for (int v2294 = 0; v2294 < 32; v2294 += 1) {	// L3655
      for (int v2295 = 0; v2295 < 32; v2295 += 1) {	// L3656
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v2290
        #pragma HLS dependence false variable=v2291
        float v2296 = v2290[0][v2293][v2294][v2295];	// L3657
        bool v2297 = v2296 >= v2292;	// L3658
        ap_int<8> v2298 = v2297;	// L3659
        v2291[0][v2293][v2294][v2295] = v2298;	// L3660
      }
    }
  }
}

void kernel802(
  float v2299[1][48][32][32],
  float v2300
) {	// L3666
  for (int v2301 = 0; v2301 < 48; v2301 += 1) {	// L3667
    for (int v2302 = 0; v2302 < 32; v2302 += 1) {	// L3668
      for (int v2303 = 0; v2303 < 32; v2303 += 1) {	// L3669
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v2299
        float v2304 = v2299[0][v2301][v2302][v2303];	// L3670
        float v2305 = v2304 - v2300;	// L3671
        v2299[0][v2301][v2302][v2303] = v2305;	// L3672
      }
    }
  }
}

void kernel804(
  float v2306[1][48][32][32],
  float v2307[1][48][32][32],
  float v2308[1][48][32][32]
) {	// L3678
  for (int v2309 = 0; v2309 < 48; v2309 += 1) {	// L3679
    for (int v2310 = 0; v2310 < 32; v2310 += 1) {	// L3680
      for (int v2311 = 0; v2311 < 32; v2311 += 1) {	// L3681
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v2307
        #pragma HLS dependence false variable=v2308
        #pragma HLS dependence false variable=v2306
        float v2312 = v2307[0][v2309][v2310][v2311];	// L3682
        float v2313 = v2306[0][v2309][v2310][v2311];	// L3683
        float v2314 = v2312 + v2313;	// L3684
        v2308[0][v2309][v2310][v2311] = v2314;	// L3685
      }
    }
  }
}

void kernel805(
  float v2315[1][48][32][32],
  float v2316
) {	// L3691
  for (int v2317 = 0; v2317 < 48; v2317 += 1) {	// L3692
    for (int v2318 = 0; v2318 < 32; v2318 += 1) {	// L3693
      for (int v2319 = 0; v2319 < 32; v2319 += 1) {	// L3694
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v2315
        float v2320 = v2315[0][v2317][v2318][v2319];	// L3695
        float v2321 = v2320 / v2316;	// L3696
        v2315[0][v2317][v2318][v2319] = v2321;	// L3697
      }
    }
  }
}

void kernel810(
  float v2322[48],
  float v2323[1][48][32][32],
  float v2324[1][48][32][32]
) {	// L3703
  float v2325[48];	// L3704
  #pragma HLS resource variable=v2325 core=ram_t2p_bram

  memcpy(v2325, v2322, 48 * sizeof(float));	// L3705

  for (int v2326 = 0; v2326 < 48; v2326 += 1) {	// L3706
    for (int v2327 = 0; v2327 < 32; v2327 += 1) {	// L3707
      for (int v2328 = 0; v2328 < 32; v2328 += 1) {	// L3708
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v2323
        #pragma HLS dependence false variable=v2324
        #pragma HLS dependence false variable=v2325
        float v2329 = v2323[0][v2326][v2327][v2328];	// L3709
        float v2330 = v2325[v2326];	// L3710
        float v2331 = v2329 + v2330;	// L3711
        v2324[0][v2326][v2327][v2328] = v2331;	// L3712
      }
    }
  }
}

void kernel811(
  float v2332[48],
  float v2333[48],
  float v2334[48]
) {	// L3718
  for (int v2335 = 0; v2335 < 48; v2335 += 1) {	// L3719
    #pragma HLS pipeline II=1
    #pragma HLS dependence false variable=v2333
    #pragma HLS dependence false variable=v2334
    #pragma HLS dependence false variable=v2332
    float v2336 = v2333[v2335];	// L3720
    float v2337 = v2332[v2335];	// L3721
    float v2338 = v2336 * v2337;	// L3722
    v2334[v2335] = v2338;	// L3723
  }
}

void kernel812(
  float v2339[1][48][1][1],
  float v2340[1][48][32][32]
) {	// L3727
  float v2341[1][48][1][1];	// L3728
  #pragma HLS resource variable=v2341 core=ram_t2p_bram

  memcpy(v2341, v2339, 48 * sizeof(float));	// L3729

  for (int v2342 = 0; v2342 < 48; v2342 += 1) {	// L3730
    for (int v2343 = 0; v2343 < 32; v2343 += 1) {	// L3731
      for (int v2344 = 0; v2344 < 32; v2344 += 1) {	// L3732
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v2340
        #pragma HLS dependence false variable=v2341
        float v2345 = v2340[0][v2342][v2343][v2344];	// L3733
        float v2346 = v2341[0][v2342][0][0];	// L3734
        float v2347 = v2345 * v2346;	// L3735
        v2340[0][v2342][v2343][v2344] = v2347;	// L3736
      }
    }
  }
}

void kernel813(
  ap_int<32> v2348[1][48][32][32],
  float v2349[1][48][32][32]
) {	// L3742
  for (int v2350 = 0; v2350 < 48; v2350 += 1) {	// L3743
    for (int v2351 = 0; v2351 < 32; v2351 += 1) {	// L3744
      for (int v2352 = 0; v2352 < 32; v2352 += 1) {	// L3745
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v2348
        #pragma HLS dependence false variable=v2349
        ap_int<32> v2353 = v2348[0][v2350][v2351][v2352];	// L3746
        float v2354 = v2353;	// L3747
        v2349[0][v2350][v2351][v2352] = v2354;	// L3748
      }
    }
  }
}

void kernel814(
  ap_int<64> v2355[1][48][32][32],
  ap_int<32> v2356[1][48][32][32]
) {	// L3754
  for (int v2357 = 0; v2357 < 48; v2357 += 1) {	// L3755
    for (int v2358 = 0; v2358 < 32; v2358 += 1) {	// L3756
      for (int v2359 = 0; v2359 < 32; v2359 += 1) {	// L3757
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v2355
        #pragma HLS dependence false variable=v2356
        ap_int<64> v2360 = v2355[0][v2357][v2358][v2359];	// L3758
        ap_int<32> v2361 = v2360;	// L3759
        v2356[0][v2357][v2358][v2359] = v2361;	// L3760
      }
    }
  }
}

void kernel815(
  ap_int<32> v2362[1][3][34][34],
  ap_int<32> v2363[48][3][3][3],
  ap_int<64> v2364[1][48][32][32]
) {	// L3766
  ap_int<32> v2365[48][3][3][3];	// L3767
  #pragma HLS resource variable=v2365 core=ram_t2p_bram

  memcpy(v2365, v2363, 1296 * sizeof(ap_int<32>));	// L3768

  for (int v2366 = 0; v2366 < 3; v2366 += 1) {	// L3769
    for (int v2367 = 0; v2367 < 3; v2367 += 1) {	// L3770
      for (int v2368 = 0; v2368 < 3; v2368 += 1) {	// L3771
        for (int v2369 = 0; v2369 < 48; v2369 += 1) {	// L3772
          for (int v2370 = 0; v2370 < 32; v2370 += 1) {	// L3773
            for (int v2371 = 0; v2371 < 32; v2371 += 1) {	// L3774
              #pragma HLS pipeline II=1
              #pragma HLS dependence false variable=v2362
              #pragma HLS dependence false variable=v2364
              #pragma HLS dependence false variable=v2365
              ap_int<32> v2372 = v2362[0][v2366][(v2370 + v2367)][(v2371 + v2368)];	// L3775
              ap_int<32> v2373 = v2365[v2369][v2366][v2367][v2368];	// L3776
              ap_int<64> v2374 = v2364[0][v2369][v2370][v2371];	// L3777
              ap_int<64> v2375 = v2372;	// L3778
              ap_int<64> v2376 = v2373;	// L3779
              ap_int<64> v2377 = v2375 * v2376;	// L3780
              ap_int<64> v2378 = v2374 + v2377;	// L3781
              v2364[0][v2369][v2370][v2371] = v2378;	// L3782
            }
          }
        }
      }
    }
  }
}

void kernel816(
  ap_int<64> v2379[1][48][32][32],
  ap_int<64> v2380
) {	// L3791
  for (int v2381 = 0; v2381 < 48; v2381 += 1) {	// L3792
    for (int v2382 = 0; v2382 < 32; v2382 += 1) {	// L3793
      for (int v2383 = 0; v2383 < 32; v2383 += 1) {	// L3794
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v2379
        v2379[0][v2381][v2382][v2383] = v2380;	// L3795
      }
    }
  }
}

void kernel817(
  ap_int<32> v2384[1][3][32][32],
  ap_int<32> v2385[1][3][34][34]
) {	// L3801
  for (int v2386 = 0; v2386 < 3; v2386 += 1) {	// L3802
    for (int v2387 = 0; v2387 < 32; v2387 += 1) {	// L3803
      for (int v2388 = 0; v2388 < 32; v2388 += 1) {	// L3804
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v2384
        #pragma HLS dependence false variable=v2385
        ap_int<32> v2389 = v2384[0][v2386][v2387][v2388];	// L3805
        v2385[0][v2386][(v2387 + 1)][(v2388 + 1)] = v2389;	// L3806
      }
    }
  }
}

void kernel818(
  ap_int<32> v2390[1][3][34][34],
  ap_int<32> v2391
) {	// L3812
  for (int v2392 = 0; v2392 < 3; v2392 += 1) {	// L3813
    for (int v2393 = 0; v2393 < 34; v2393 += 1) {	// L3814
      for (int v2394 = 0; v2394 < 34; v2394 += 1) {	// L3815
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v2390
        v2390[0][v2392][v2393][v2394] = v2391;	// L3816
      }
    }
  }
}

void kernel819(
  ap_int<8> v2395[48][3][3][3],
  ap_int<32> v2396[48][3][3][3]
) {	// L3822
  for (int v2397 = 0; v2397 < 48; v2397 += 1) {	// L3823
    for (int v2398 = 0; v2398 < 3; v2398 += 1) {	// L3824
      for (int v2399 = 0; v2399 < 3; v2399 += 1) {	// L3825
        for (int v2400 = 0; v2400 < 3; v2400 += 1) {	// L3826
          #pragma HLS pipeline II=1
          #pragma HLS dependence false variable=v2395
          #pragma HLS dependence false variable=v2396
          ap_int<8> v2401 = v2395[v2397][v2398][v2399][v2400];	// L3827
          ap_int<32> v2402 = v2401;	// L3828
          v2396[v2397][v2398][v2399][v2400] = v2402;	// L3829
        }
      }
    }
  }
}

void kernel820(
  ap_int<8> v2403[1][3][32][32],
  ap_int<32> v2404[1][3][32][32]
) {	// L3836
  for (int v2405 = 0; v2405 < 3; v2405 += 1) {	// L3837
    for (int v2406 = 0; v2406 < 32; v2406 += 1) {	// L3838
      for (int v2407 = 0; v2407 < 32; v2407 += 1) {	// L3839
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v2403
        #pragma HLS dependence false variable=v2404
        ap_int<8> v2408 = v2403[0][v2405][v2406][v2407];	// L3840
        ap_int<32> v2409 = v2408;	// L3841
        v2404[0][v2405][v2406][v2407] = v2409;	// L3842
      }
    }
  }
}

void kernel821(
  float v2410[1][3][32][32],
  ap_int<8> v2411[1][3][32][32]
) {	// L3848
  for (int v2412 = 0; v2412 < 3; v2412 += 1) {	// L3849
    for (int v2413 = 0; v2413 < 32; v2413 += 1) {	// L3850
      for (int v2414 = 0; v2414 < 32; v2414 += 1) {	// L3851
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v2410
        #pragma HLS dependence false variable=v2411
        float v2415 = v2410[0][v2412][v2413][v2414];	// L3852
        ap_int<8> v2416 = v2415;	// L3853
        v2411[0][v2412][v2413][v2414] = v2416;	// L3854
      }
    }
  }
}

void kernel822(
  float v2417[1][3][32][32],
  float v2418,
  float v2419
) {	// L3860
  for (int v2420 = 0; v2420 < 3; v2420 += 1) {	// L3861
    for (int v2421 = 0; v2421 < 32; v2421 += 1) {	// L3862
      for (int v2422 = 0; v2422 < 32; v2422 += 1) {	// L3863
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v2417
        float v2423 = v2417[0][v2420][v2421][v2422];	// L3864
        bool v2424 = v2423 < v2419;	// L3865
        float v2425 = v2424 ? v2419 : v2423;	// L3866
        bool v2426 = v2425 > v2418;	// L3867
        float v2427 = v2426 ? v2418 : v2425;	// L3868
        v2417[0][v2420][v2421][v2422] = v2427;	// L3869
      }
    }
  }
}

void kernel823(
  float v2428[1][3][32][32]
) {	// L3875
  for (int v2429 = 0; v2429 < 3; v2429 += 1) {	// L3876
    for (int v2430 = 0; v2430 < 32; v2430 += 1) {	// L3877
      for (int v2431 = 0; v2431 < 32; v2431 += 1) {	// L3878
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v2428
        float v2432 = v2428[0][v2429][v2430][v2431];	// L3879
        float v2433 = round(v2432);	// L3880
        v2428[0][v2429][v2430][v2431] = v2433;	// L3881
      }
    }
  }
}

void kernel824(
  float v2434[1][3][32][32],
  float v2435
) {	// L3887
  for (int v2436 = 0; v2436 < 3; v2436 += 1) {	// L3888
    for (int v2437 = 0; v2437 < 32; v2437 += 1) {	// L3889
      for (int v2438 = 0; v2438 < 32; v2438 += 1) {	// L3890
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v2434
        float v2439 = v2434[0][v2436][v2437][v2438];	// L3891
        float v2440 = v2439 / v2435;	// L3892
        v2434[0][v2436][v2437][v2438] = v2440;	// L3893
      }
    }
  }
}

/// The top function
void control(
  ap_int<32> v2441[100417536],
  ap_int<32> v2442[100417536],
  ap_int<32> v2443[100417536],
  ap_int<8> v2444[401670144],
  ap_int<64> v2445[50208768],
  ap_int<8> v2446[401670144],
  ap_int<64> v2447[50208768],
  ap_int<8> v2448[401670144]
) {	// L3899
  #pragma HLS interface s_axilite port=return bundle=ctrl
  #pragma hls interface m_axi offset=direct bundle=g0 port=v2441
  #pragma hls stable variable=v2441
  #pragma hls interface m_axi offset=direct bundle=g0 port=v2442
  #pragma hls stable variable=v2442
  #pragma hls interface m_axi offset=direct bundle=g0 port=v2443
  #pragma hls stable variable=v2443
  #pragma hls interface m_axi offset=direct bundle=g0 port=v2444
  #pragma hls stable variable=v2444
  #pragma hls interface m_axi offset=direct bundle=g0 port=v2445
  #pragma hls stable variable=v2445
  #pragma hls interface m_axi offset=direct bundle=g0 port=v2446
  #pragma hls stable variable=v2446
  #pragma hls interface m_axi offset=direct bundle=g0 port=v2447
  #pragma hls stable variable=v2447
  #pragma hls interface m_axi offset=direct bundle=g0 port=v2448
  #pragma hls stable variable=v2448

  auto v2449 = reinterpret_cast<float(*)[3][32][32]>(v2441 + 14155776);
  kernel824(v2449, (float)0.016744);	// L3915
  kernel823(v2449);	// L3916
  kernel822(v2449, (float)127.000000, (float)-127.000000);	// L3917
  auto v2450 = reinterpret_cast<ap_int<8>(*)[3][32][32]>(v2444 + 61931520);
  kernel821(v2449, v2450);	// L3919
  auto v2451 = reinterpret_cast<ap_int<32>(*)[3][32][32]>(v2441 + 14155776);
  kernel820(v2450, v2451);	// L3921
  auto v2452 = reinterpret_cast<ap_int<32>(*)[3][3][3]>(v2441 + 15482880);
  auto v2453 = reinterpret_cast<ap_int<8>(*)[3][3][3]>(v2448 + 231800832);
  kernel819(v2453, v2452);	// L3924
  auto v2454 = reinterpret_cast<ap_int<32>(*)[3][34][34]>(v2442 + 16809984);
  kernel818(v2454, (ap_int<32>)0);	// L3926
  kernel817(v2451, v2454);	// L3927
  auto v2455 = reinterpret_cast<ap_int<64>(*)[48][32][32]>(v2445 + 7077888);
  kernel816(v2455, (ap_int<64>)0);	// L3929
  kernel815(v2454, v2452, v2455);	// L3930
  auto v2456 = reinterpret_cast<ap_int<32>(*)[48][32][32]>(v2441 + 15482880);
  kernel814(v2455, v2456);	// L3932
  auto v2457 = reinterpret_cast<float(*)[48][32][32]>(v2442 + 14155776);
  kernel813(v2456, v2457);	// L3934
  auto v2458 = reinterpret_cast<float(*)[48][1][1]>(v2443 + 58281984);
  kernel812(v2458, v2457);	// L3936
  auto v2459 = reinterpret_cast<float(*)>(v2441 + 16809984);
  auto v2460 = reinterpret_cast<float(*)>(v2443 + 58613760);
  auto v2461 = reinterpret_cast<float(*)>(v2442 + 58945536);
  kernel811(v2461, v2460, v2459);	// L3940
  auto v2462 = reinterpret_cast<float(*)[48][32][32]>(v2443 + 18137088);
  kernel810(v2459, v2457, v2462);	// L3942
  auto v2463 = reinterpret_cast<float(*)[48][32][32]>(v2441);
  kernel797(v2463, v2457);	// L3944
  kernel805(v2457, (float)2.000000);	// L3945
  auto v2464 = reinterpret_cast<float(*)[48][32][32]>(v2443 + 16809984);
  kernel799(v2457, v2463, v2464);	// L3947
  kernel797(v2462, v2457);	// L3948
  kernel805(v2457, (float)2.000000);	// L3949
  auto v2465 = reinterpret_cast<float(*)[48][32][32]>(v2441 + 18137088);
  kernel804(v2457, v2464, v2465);	// L3951
  kernel797(v2465, v2457);	// L3952
  kernel802(v2457, (float)1.000000);	// L3953
  auto v2466 = reinterpret_cast<ap_int<8>(*)[48][32][32]>(v2444 + 67239936);
  kernel801(v2457, v2466, (float)0.000000);	// L3955
  kernel800(v2465, v2457, (float)0.000000);	// L3956
  auto v2467 = reinterpret_cast<float(*)[48][32][32]>(v2441 + 19464192);
  kernel799(v2457, v2465, v2467);	// L3958
  kernel798(v2467, v2457);	// L3959
  kernel797(v2457, v2463);	// L3960
  kernel796(v2466, v2456);	// L3961
  auto v2468 = reinterpret_cast<ap_int<32>(*)[48][3][3]>(v2441 + 14155776);
  auto v2469 = reinterpret_cast<ap_int<8>(*)[48][3][3]>(v2448 + 237109248);
  kernel795(v2469, v2468);	// L3964
  auto v2470 = reinterpret_cast<ap_int<32>(*)[48][34][34]>(v2441 + 16809984);
  kernel794(v2470, (ap_int<32>)0);	// L3966
  kernel793(v2456, v2470);	// L3967
  auto v2471 = reinterpret_cast<ap_int<64>(*)[96][32][32]>(v2445 + 9068544);
  kernel792(v2471, (ap_int<64>)0);	// L3969
  auto v2472 = reinterpret_cast<ap_int<64>(*)[96][32][32]>(v2445 + 9732096);
  kernel770(v2471, v2472);	// L3971
  kernel790(v2470, v2468, v2472);	// L3972
  auto v2473 = reinterpret_cast<ap_int<32>(*)[96][32][32]>(v2441 + 14155776);
  kernel640(v2472, v2473);	// L3974
  auto v2474 = reinterpret_cast<float(*)[96][32][32]>(v2441 + 16809984);
  kernel639(v2473, v2474);	// L3976
  auto v2475 = reinterpret_cast<float(*)[96][1][1]>(v2443 + 59609088);
  kernel638(v2475, v2474);	// L3978
  auto v2476 = reinterpret_cast<float(*)>(v2443 + 19464192);
  auto v2477 = reinterpret_cast<float(*)>(v2442 + 59940864);
  auto v2478 = reinterpret_cast<float(*)>(v2441 + 60272640);
  kernel637(v2478, v2477, v2476);	// L3982
  auto v2479 = reinterpret_cast<float(*)[96][32][32]>(v2442 + 20791296);
  kernel636(v2476, v2474, v2479);	// L3984
  auto v2480 = reinterpret_cast<float(*)[96][32][32]>(v2441 + 393216);
  kernel623(v2480, v2474);	// L3986
  kernel631(v2474, (float)2.000000);	// L3987
  auto v2481 = reinterpret_cast<float(*)[96][32][32]>(v2443 + 22118400);
  kernel625(v2474, v2480, v2481);	// L3989
  kernel623(v2479, v2474);	// L3990
  kernel631(v2474, (float)2.000000);	// L3991
  kernel630(v2474, v2481, v2479);	// L3992
  kernel623(v2479, v2474);	// L3993
  kernel628(v2474, (float)1.000000);	// L3994
  auto v2482 = reinterpret_cast<ap_int<8>(*)[96][32][32]>(v2444 + 88473600);
  kernel627(v2474, v2482, (float)0.000000);	// L3996
  kernel626(v2479, v2474, (float)0.000000);	// L3997
  auto v2483 = reinterpret_cast<float(*)[96][32][32]>(v2443 + 23445504);
  kernel625(v2474, v2479, v2483);	// L3999
  kernel624(v2483, v2474);	// L4000
  kernel623(v2474, v2480);	// L4001
  auto v2484 = reinterpret_cast<ap_int<32>(*)[48][1][1]>(v2441 + 20791296);
  auto v2485 = reinterpret_cast<ap_int<8>(*)[48][1][1]>(v2448 + 242417664);
  kernel771(v2485, v2484);	// L4004
  auto v2486 = reinterpret_cast<ap_int<64>(*)[96][32][32]>(v2447 + 11722752);
  kernel770(v2471, v2486);	// L4006
  kernel769(v2456, v2484, v2486);	// L4007
  kernel640(v2486, v2473);	// L4008
  kernel639(v2473, v2474);	// L4009
  auto v2487 = reinterpret_cast<float(*)[96][1][1]>(v2443 + 60936192);
  kernel638(v2487, v2474);	// L4011
  auto v2488 = reinterpret_cast<float(*)>(v2442 + 61267968);
  auto v2489 = reinterpret_cast<float(*)>(v2441 + 61599744);
  kernel637(v2489, v2488, v2476);	// L4014
  auto v2490 = reinterpret_cast<float(*)[96][32][32]>(v2442 + 15482880);
  kernel636(v2476, v2474, v2490);	// L4016
  auto v2491 = reinterpret_cast<float(*)[96][32][32]>(v2441 + 786432);
  kernel623(v2491, v2474);	// L4018
  kernel631(v2474, (float)2.000000);	// L4019
  kernel625(v2474, v2491, v2479);	// L4020
  kernel623(v2490, v2474);	// L4021
  kernel631(v2474, (float)2.000000);	// L4022
  kernel630(v2474, v2479, v2490);	// L4023
  kernel623(v2490, v2474);	// L4024
  kernel628(v2474, (float)1.000000);	// L4025
  auto v2492 = reinterpret_cast<ap_int<8>(*)[96][32][32]>(v2444 + 83165184);
  kernel627(v2474, v2492, (float)0.000000);	// L4027
  kernel626(v2490, v2474, (float)0.000000);	// L4028
  kernel625(v2474, v2490, v2483);	// L4029
  kernel624(v2483, v2474);	// L4030
  kernel623(v2474, v2491);	// L4031
  kernel622(v2482, v2492);	// L4032
  auto v2493 = reinterpret_cast<ap_int<32>(*)[96][1024]>(v2442 + 15482880);
  kernel749(v2492, v2493);	// L4034
  auto v2494 = reinterpret_cast<ap_int<32>(*)[96][1]>(v2441 + 22118400);
  auto v2495 = reinterpret_cast<ap_int<8>(*)[96][1]>(v2448 + 247726080);
  kernel686(v2495, v2494);	// L4037
  auto v2496 = reinterpret_cast<ap_int<64>(*)[96][1024]>(v2445 + 11722752);
  kernel747(v2496, (ap_int<64>)0);	// L4039
  auto v2497 = reinterpret_cast<ap_int<64>(*)[96][1024]>(v2445 + 12386304);
  kernel725(v2496, v2497);	// L4041
  kernel685(v2493, v2494, v2497);	// L4042
  auto v2498 = reinterpret_cast<ap_int<32>(*)[96][1024]>(v2441 + 26099712);
  kernel684(v2497, v2498);	// L4044
  auto v2499 = reinterpret_cast<float(*)[96][1024]>(v2441 + 24772608);
  kernel683(v2498, v2499);	// L4046
  auto v2500 = reinterpret_cast<float(*)[96][1]>(v2443 + 62263296);
  kernel682(v2500, v2499);	// L4048
  auto v2501 = reinterpret_cast<float(*)>(v2442 + 62595072);
  auto v2502 = reinterpret_cast<float(*)>(v2441 + 62926848);
  kernel637(v2502, v2501, v2476);	// L4051
  auto v2503 = reinterpret_cast<float(*)[96][1024]>(v2442 + 27426816);
  kernel680(v2476, v2499, v2503);	// L4053
  auto v2504 = reinterpret_cast<float(*)[96][1024]>(v2441 + 1179648);
  kernel667(v2504, v2499);	// L4055
  kernel675(v2499, (float)2.000000);	// L4056
  auto v2505 = reinterpret_cast<float(*)[96][1024]>(v2443 + 28753920);
  kernel669(v2499, v2504, v2505);	// L4058
  kernel667(v2503, v2499);	// L4059
  kernel675(v2499, (float)2.000000);	// L4060
  kernel674(v2499, v2505, v2503);	// L4061
  kernel667(v2503, v2499);	// L4062
  kernel672(v2499, (float)1.000000);	// L4063
  auto v2506 = reinterpret_cast<ap_int<8>(*)[96][1024]>(v2444 + 115015680);
  kernel671(v2499, v2506, (float)0.000000);	// L4065
  kernel670(v2503, v2499, (float)0.000000);	// L4066
  auto v2507 = reinterpret_cast<float(*)[96][1024]>(v2442 + 30081024);
  kernel669(v2499, v2503, v2507);	// L4068
  kernel668(v2507, v2499);	// L4069
  kernel667(v2499, v2504);	// L4070
  auto v2508 = reinterpret_cast<ap_int<8>(*)[96][1]>(v2448 + 253034496);
  kernel686(v2508, v2494);	// L4072
  auto v2509 = reinterpret_cast<ap_int<64>(*)[96][1024]>(v2447 + 13713408);
  kernel725(v2496, v2509);	// L4074
  kernel685(v2493, v2494, v2509);	// L4075
  kernel684(v2509, v2498);	// L4076
  kernel683(v2498, v2499);	// L4077
  auto v2510 = reinterpret_cast<float(*)[96][1]>(v2443 + 63590400);
  kernel682(v2510, v2499);	// L4079
  auto v2511 = reinterpret_cast<float(*)>(v2442 + 63922176);
  auto v2512 = reinterpret_cast<float(*)>(v2441 + 64253952);
  kernel637(v2512, v2511, v2476);	// L4082
  auto v2513 = reinterpret_cast<float(*)[96][1024]>(v2442 + 15482880);
  kernel680(v2476, v2499, v2513);	// L4084
  auto v2514 = reinterpret_cast<float(*)[96][1024]>(v2441 + 1572864);
  kernel667(v2514, v2499);	// L4086
  kernel675(v2499, (float)2.000000);	// L4087
  kernel669(v2499, v2514, v2503);	// L4088
  kernel667(v2513, v2499);	// L4089
  kernel675(v2499, (float)2.000000);	// L4090
  auto v2515 = reinterpret_cast<float(*)[96][1024]>(v2443 + 15482880);
  kernel674(v2499, v2503, v2515);	// L4092
  kernel667(v2515, v2499);	// L4093
  kernel672(v2499, (float)1.000000);	// L4094
  auto v2516 = reinterpret_cast<ap_int<8>(*)[96][1024]>(v2446 + 109707264);
  kernel671(v2499, v2516, (float)0.000000);	// L4096
  kernel670(v2515, v2499, (float)0.000000);	// L4097
  kernel669(v2499, v2515, v2507);	// L4098
  kernel668(v2507, v2499);	// L4099
  kernel667(v2499, v2514);	// L4100
  auto v2517 = reinterpret_cast<ap_int<8>(*)[8][1][1024]>(v2446 + 61931520);
  kernel705(v2517, (ap_int<8>)0);	// L4102
  kernel704(v2506, v2517);	// L4103
  auto v2518 = reinterpret_cast<ap_int<8>(*)[8][12][1024]>(v2444 + 115015680);
  kernel703(v2516, v2517, v2518);	// L4105
  auto v2519 = reinterpret_cast<float(*)[8][12][1024]>(v2441 + 15482880);
  kernel702(v2518, v2519);	// L4107
  auto v2520 = reinterpret_cast<float(*)[8][12][1024]>(v2441 + 1966080);
  auto v2521 = reinterpret_cast<float(*)[8][12][1024]>(v2442 + 30081024);
  kernel689(v2520, v2521);	// L4110
  kernel697(v2521, (float)2.000000);	// L4111
  auto v2522 = reinterpret_cast<float(*)[8][12][1024]>(v2441 + 31408128);
  kernel691(v2521, v2520, v2522);	// L4113
  kernel689(v2519, v2521);	// L4114
  kernel697(v2521, (float)2.000000);	// L4115
  auto v2523 = reinterpret_cast<float(*)[8][12][1024]>(v2443 + 15482880);
  kernel696(v2521, v2522, v2523);	// L4117
  kernel689(v2523, v2521);	// L4118
  kernel694(v2521, (float)0.500000);	// L4119
  kernel693(v2521, v2518, (float)0.000000);	// L4120
  kernel692(v2523, v2521, (float)0.000000);	// L4121
  kernel691(v2521, v2523, v2522);	// L4122
  kernel690(v2522, v2521);	// L4123
  kernel689(v2521, v2520);	// L4124
  kernel688(v2516, v2518);	// L4125
  kernel687(v2518, v2498);	// L4126
  auto v2524 = reinterpret_cast<ap_int<8>(*)[96][1]>(v2448 + 258342912);
  kernel686(v2524, v2494);	// L4128
  kernel685(v2498, v2494, v2496);	// L4129
  kernel684(v2496, v2498);	// L4130
  kernel683(v2498, v2499);	// L4131
  auto v2525 = reinterpret_cast<float(*)[96][1]>(v2443 + 64917504);
  kernel682(v2525, v2499);	// L4133
  auto v2526 = reinterpret_cast<float(*)>(v2442 + 65249280);
  auto v2527 = reinterpret_cast<float(*)>(v2441 + 65581056);
  kernel637(v2527, v2526, v2476);	// L4136
  kernel680(v2476, v2499, v2513);	// L4137
  auto v2528 = reinterpret_cast<float(*)[96][1024]>(v2441 + 2359296);
  kernel667(v2528, v2499);	// L4139
  kernel675(v2499, (float)2.000000);	// L4140
  auto v2529 = reinterpret_cast<float(*)[96][1024]>(v2442 + 22118400);
  kernel669(v2499, v2528, v2529);	// L4142
  kernel667(v2513, v2499);	// L4143
  kernel675(v2499, (float)2.000000);	// L4144
  kernel674(v2499, v2529, v2513);	// L4145
  kernel667(v2513, v2499);	// L4146
  kernel672(v2499, (float)1.000000);	// L4147
  kernel671(v2499, v2516, (float)0.000000);	// L4148
  kernel670(v2513, v2499, (float)0.000000);	// L4149
  kernel669(v2499, v2513, v2529);	// L4150
  kernel668(v2529, v2499);	// L4151
  kernel667(v2499, v2528);	// L4152
  auto v2530 = reinterpret_cast<ap_int<8>(*)[96][32][32]>(v2448 + 61931520);
  kernel666(v2516, v2492, v2530);	// L4154
  kernel621(v2530, v2473);	// L4155
  auto v2531 = reinterpret_cast<ap_int<32>(*)[96][1][1]>(v2441 + 22118400);
  auto v2532 = reinterpret_cast<ap_int<8>(*)[96][1][1]>(v2448 + 263651328);
  kernel664(v2532, v2531);	// L4158
  auto v2533 = reinterpret_cast<ap_int<64>(*)[384][32][32]>(v2445 + 11722752);
  kernel663(v2533, (ap_int<64>)0);	// L4160
  kernel662(v2473, v2531, v2533);	// L4161
  auto v2534 = reinterpret_cast<ap_int<32>(*)[384][32][32]>(v2441 + 22118400);
  kernel661(v2533, v2534);	// L4163
  auto v2535 = reinterpret_cast<float(*)[384][32][32]>(v2442 + 23445504);
  kernel660(v2534, v2535);	// L4165
  auto v2536 = reinterpret_cast<float(*)[384][1][1]>(v2443 + 66244608);
  kernel659(v2536, v2535);	// L4167
  auto v2537 = reinterpret_cast<float(*)>(v2443 + 24772608);
  auto v2538 = reinterpret_cast<float(*)>(v2442 + 66576384);
  auto v2539 = reinterpret_cast<float(*)>(v2441 + 66908160);
  kernel34(v2539, v2538, v2537);	// L4171
  auto v2540 = reinterpret_cast<float(*)[384][32][32]>(v2441 + 26099712);
  kernel657(v2537, v2535, v2540);	// L4173
  auto v2541 = reinterpret_cast<float(*)[384][32][32]>(v2441 + 2752512);
  kernel644(v2541, v2535);	// L4175
  kernel652(v2535, (float)2.000000);	// L4176
  auto v2542 = reinterpret_cast<float(*)[384][32][32]>(v2443 + 27426816);
  kernel646(v2535, v2541, v2542);	// L4178
  kernel644(v2540, v2535);	// L4179
  kernel652(v2535, (float)2.000000);	// L4180
  kernel651(v2535, v2542, v2540);	// L4181
  kernel644(v2540, v2535);	// L4182
  kernel649(v2535, (float)1.000000);	// L4183
  auto v2543 = reinterpret_cast<ap_int<8>(*)[384][32][32]>(v2444 + 109707264);
  kernel648(v2535, v2543, (float)0.000000);	// L4185
  kernel647(v2540, v2535, (float)0.000000);	// L4186
  auto v2544 = reinterpret_cast<float(*)[384][32][32]>(v2441 + 28753920);
  kernel646(v2535, v2540, v2544);	// L4188
  kernel645(v2544, v2535);	// L4189
  kernel644(v2535, v2541);	// L4190
  kernel643(v2543, v2534);	// L4191
  auto v2545 = reinterpret_cast<ap_int<32>(*)[384][1][1]>(v2442 + 23445504);
  auto v2546 = reinterpret_cast<ap_int<8>(*)[384][1][1]>(v2448 + 268959744);
  kernel642(v2546, v2545);	// L4194
  kernel641(v2534, v2545, v2471);	// L4195
  kernel640(v2471, v2473);	// L4196
  kernel639(v2473, v2474);	// L4197
  auto v2547 = reinterpret_cast<float(*)[96][1][1]>(v2443 + 67571712);
  kernel638(v2547, v2474);	// L4199
  auto v2548 = reinterpret_cast<float(*)>(v2442 + 67903488);
  auto v2549 = reinterpret_cast<float(*)>(v2441 + 68235264);
  kernel637(v2549, v2548, v2476);	// L4202
  auto v2550 = reinterpret_cast<float(*)[96][32][32]>(v2442 + 18137088);
  kernel636(v2476, v2474, v2550);	// L4204
  auto v2551 = reinterpret_cast<float(*)[96][32][32]>(v2441 + 3145728);
  kernel623(v2551, v2474);	// L4206
  kernel631(v2474, (float)2.000000);	// L4207
  auto v2552 = reinterpret_cast<float(*)[96][32][32]>(v2442 + 19464192);
  kernel625(v2474, v2551, v2552);	// L4209
  kernel623(v2550, v2474);	// L4210
  kernel631(v2474, (float)2.000000);	// L4211
  auto v2553 = reinterpret_cast<float(*)[96][32][32]>(v2443 + 18137088);
  kernel630(v2474, v2552, v2553);	// L4213
  kernel623(v2553, v2474);	// L4214
  kernel628(v2474, (float)1.000000);	// L4215
  kernel627(v2474, v2492, (float)0.000000);	// L4216
  kernel626(v2553, v2474, (float)0.000000);	// L4217
  kernel625(v2474, v2553, v2552);	// L4218
  kernel624(v2552, v2474);	// L4219
  kernel623(v2474, v2551);	// L4220
  kernel622(v2530, v2492);	// L4221
  kernel621(v2492, v2473);	// L4222
  auto v2554 = reinterpret_cast<ap_int<32>(*)[96][3][3]>(v2441 + 15482880);
  auto v2555 = reinterpret_cast<ap_int<8>(*)[96][3][3]>(v2448 + 274268160);
  kernel620(v2555, v2554);	// L4225
  auto v2556 = reinterpret_cast<ap_int<32>(*)[96][34][34]>(v2441 + 16809984);
  kernel619(v2556, (ap_int<32>)0);	// L4227
  kernel618(v2473, v2556);	// L4228
  auto v2557 = reinterpret_cast<ap_int<64>(*)[192][32][32]>(v2445 + 9068544);
  kernel617(v2557, (ap_int<64>)0);	// L4230
  auto v2558 = reinterpret_cast<ap_int<64>(*)[192][32][32]>(v2445 + 9732096);
  kernel616(v2557, v2558);	// L4232
  kernel615(v2556, v2554, v2558);	// L4233
  auto v2559 = reinterpret_cast<ap_int<32>(*)[192][32][32]>(v2442 + 15482880);
  kernel591(v2558, v2559);	// L4235
  auto v2560 = reinterpret_cast<float(*)[192][32][32]>(v2441 + 16809984);
  kernel590(v2559, v2560);	// L4237
  auto v2561 = reinterpret_cast<float(*)[192][1][1]>(v2443 + 68898816);
  kernel589(v2561, v2560);	// L4239
  auto v2562 = reinterpret_cast<float(*)>(v2441 + 19464192);
  auto v2563 = reinterpret_cast<float(*)>(v2443 + 69230592);
  auto v2564 = reinterpret_cast<float(*)>(v2442 + 69562368);
  kernel434(v2564, v2563, v2562);	// L4243
  auto v2565 = reinterpret_cast<float(*)[192][32][32]>(v2442 + 20791296);
  kernel610(v2562, v2560, v2565);	// L4245
  auto v2566 = reinterpret_cast<float(*)[192][32][32]>(v2441 + 3538944);
  kernel597(v2566, v2560);	// L4247
  kernel605(v2560, (float)2.000000);	// L4248
  auto v2567 = reinterpret_cast<float(*)[192][32][32]>(v2442 + 22118400);
  kernel599(v2560, v2566, v2567);	// L4250
  kernel597(v2565, v2560);	// L4251
  kernel605(v2560, (float)2.000000);	// L4252
  auto v2568 = reinterpret_cast<float(*)[192][32][32]>(v2443 + 20791296);
  kernel604(v2560, v2567, v2568);	// L4254
  kernel597(v2568, v2560);	// L4255
  kernel602(v2560, (float)1.000000);	// L4256
  auto v2569 = reinterpret_cast<ap_int<8>(*)[192][32][32]>(v2444 + 88473600);
  kernel601(v2560, v2569, (float)0.000000);	// L4258
  kernel600(v2568, v2560, (float)0.000000);	// L4259
  auto v2570 = reinterpret_cast<float(*)[192][32][32]>(v2442 + 23445504);
  kernel599(v2560, v2568, v2570);	// L4261
  kernel598(v2570, v2560);	// L4262
  kernel597(v2560, v2566);	// L4263
  kernel596(v2569, v2559);	// L4264
  auto v2571 = reinterpret_cast<ap_int<32>(*)[192][3][3]>(v2442 + 20791296);
  auto v2572 = reinterpret_cast<ap_int<8>(*)[192][3][3]>(v2448 + 279576576);
  kernel595(v2572, v2571);	// L4267
  auto v2573 = reinterpret_cast<ap_int<32>(*)[192][34][34]>(v2441 + 22118400);
  kernel594(v2573, (ap_int<32>)0);	// L4269
  kernel593(v2559, v2573);	// L4270
  kernel592(v2573, v2571, v2557);	// L4271
  kernel591(v2557, v2559);	// L4272
  kernel590(v2559, v2560);	// L4273
  auto v2574 = reinterpret_cast<float(*)[192][1][1]>(v2443 + 70225920);
  kernel589(v2574, v2560);	// L4275
  auto v2575 = reinterpret_cast<float(*)>(v2443 + 70557696);
  auto v2576 = reinterpret_cast<float(*)>(v2442 + 70889472);
  kernel434(v2576, v2575, v2562);	// L4278
  kernel587(v2562, v2560);	// L4279
  auto v2577 = reinterpret_cast<float(*)[192][34][34]>(v2441 + 15482880);
  kernel586(v2577, (float)-INFINITY);	// L4281
  kernel585(v2560, v2577);	// L4282
  auto v2578 = reinterpret_cast<float(*)[192][16][16]>(v2442 + 16809984);
  kernel584(v2578, (float)-INFINITY);	// L4284
  auto v2579 = reinterpret_cast<float(*)[3]>(v2441 + 18137088);
  kernel583(v2577, v2579, v2578);	// L4286
  auto v2580 = reinterpret_cast<float(*)[192][16][16]>(v2441 + 3932160);
  auto v2581 = reinterpret_cast<float(*)[192][16][16]>(v2441 + 15482880);
  kernel420(v2580, v2581);	// L4289
  kernel428(v2581, (float)2.000000);	// L4290
  auto v2582 = reinterpret_cast<float(*)[192][16][16]>(v2442 + 20791296);
  kernel422(v2581, v2580, v2582);	// L4292
  kernel420(v2578, v2581);	// L4293
  kernel428(v2581, (float)2.000000);	// L4294
  kernel427(v2581, v2582, v2578);	// L4295
  kernel420(v2578, v2581);	// L4296
  kernel425(v2581, (float)1.000000);	// L4297
  auto v2583 = reinterpret_cast<ap_int<8>(*)[192][16][16]>(v2446 + 83165184);
  kernel424(v2581, v2583, (float)0.000000);	// L4299
  kernel423(v2578, v2581, (float)0.000000);	// L4300
  auto v2584 = reinterpret_cast<float(*)[192][16][16]>(v2442 + 22118400);
  kernel422(v2581, v2578, v2584);	// L4302
  kernel421(v2584, v2581);	// L4303
  kernel420(v2581, v2580);	// L4304
  auto v2585 = reinterpret_cast<ap_int<32>(*)[96][1][1]>(v2442 + 16809984);
  auto v2586 = reinterpret_cast<ap_int<8>(*)[96][1][1]>(v2448 + 284884992);
  kernel569(v2586, v2585);	// L4307
  auto v2587 = reinterpret_cast<ap_int<64>(*)[192][16][16]>(v2447 + 11059200);
  kernel568(v2587, (ap_int<64>)0);	// L4309
  auto v2588 = reinterpret_cast<ap_int<64>(*)[192][16][16]>(v2445 + 11722752);
  kernel567(v2587, v2588);	// L4311
  kernel566(v2473, v2585, v2588);	// L4312
  auto v2589 = reinterpret_cast<ap_int<32>(*)[192][16][16]>(v2441 + 14155776);
  kernel437(v2588, v2589);	// L4314
  kernel436(v2589, v2581);	// L4315
  auto v2590 = reinterpret_cast<float(*)[192][1][1]>(v2443 + 71553024);
  kernel435(v2590, v2581);	// L4317
  auto v2591 = reinterpret_cast<float(*)>(v2443 + 71884800);
  auto v2592 = reinterpret_cast<float(*)>(v2442 + 72216576);
  kernel434(v2592, v2591, v2562);	// L4320
  kernel433(v2562, v2581, v2578);	// L4321
  auto v2593 = reinterpret_cast<float(*)[192][16][16]>(v2441 + 4325376);
  kernel420(v2593, v2581);	// L4323
  kernel428(v2581, (float)2.000000);	// L4324
  auto v2594 = reinterpret_cast<float(*)[192][16][16]>(v2442 + 23445504);
  kernel422(v2581, v2593, v2594);	// L4326
  kernel420(v2578, v2581);	// L4327
  kernel428(v2581, (float)2.000000);	// L4328
  auto v2595 = reinterpret_cast<float(*)[192][16][16]>(v2443 + 16809984);
  kernel427(v2581, v2594, v2595);	// L4330
  kernel420(v2595, v2581);	// L4331
  kernel425(v2581, (float)1.000000);	// L4332
  auto v2596 = reinterpret_cast<ap_int<8>(*)[192][16][16]>(v2444 + 93782016);
  kernel424(v2581, v2596, (float)0.000000);	// L4334
  kernel423(v2595, v2581, (float)0.000000);	// L4335
  auto v2597 = reinterpret_cast<float(*)[192][16][16]>(v2442 + 26099712);
  kernel422(v2581, v2595, v2597);	// L4337
  kernel421(v2597, v2581);	// L4338
  kernel420(v2581, v2593);	// L4339
  kernel419(v2583, v2596);	// L4340
  auto v2598 = reinterpret_cast<ap_int<32>(*)[192][256]>(v2442 + 16809984);
  kernel546(v2596, v2598);	// L4342
  auto v2599 = reinterpret_cast<ap_int<32>(*)[192][1]>(v2441 + 20791296);
  auto v2600 = reinterpret_cast<ap_int<8>(*)[192][1]>(v2448 + 290193408);
  kernel483(v2600, v2599);	// L4345
  auto v2601 = reinterpret_cast<ap_int<64>(*)[192][256]>(v2445 + 13049856);
  kernel544(v2601, (ap_int<64>)0);	// L4347
  auto v2602 = reinterpret_cast<ap_int<64>(*)[192][256]>(v2445 + 13713408);
  kernel522(v2601, v2602);	// L4349
  kernel482(v2598, v2599, v2602);	// L4350
  auto v2603 = reinterpret_cast<ap_int<32>(*)[192][256]>(v2441 + 28753920);
  kernel481(v2602, v2603);	// L4352
  auto v2604 = reinterpret_cast<float(*)[192][256]>(v2442 + 27426816);
  kernel480(v2603, v2604);	// L4354
  auto v2605 = reinterpret_cast<float(*)[192][1]>(v2443 + 72880128);
  kernel479(v2605, v2604);	// L4356
  auto v2606 = reinterpret_cast<float(*)>(v2443 + 73211904);
  auto v2607 = reinterpret_cast<float(*)>(v2442 + 73543680);
  kernel434(v2607, v2606, v2562);	// L4359
  auto v2608 = reinterpret_cast<float(*)[192][256]>(v2441 + 30081024);
  kernel477(v2562, v2604, v2608);	// L4361
  auto v2609 = reinterpret_cast<float(*)[192][256]>(v2441 + 4718592);
  kernel464(v2609, v2604);	// L4363
  kernel472(v2604, (float)2.000000);	// L4364
  auto v2610 = reinterpret_cast<float(*)[192][256]>(v2443 + 31408128);
  kernel466(v2604, v2609, v2610);	// L4366
  kernel464(v2608, v2604);	// L4367
  kernel472(v2604, (float)2.000000);	// L4368
  kernel471(v2604, v2610, v2608);	// L4369
  kernel464(v2608, v2604);	// L4370
  kernel469(v2604, (float)1.000000);	// L4371
  auto v2611 = reinterpret_cast<ap_int<8>(*)[192][256]>(v2444 + 125632512);
  kernel468(v2604, v2611, (float)0.000000);	// L4373
  kernel467(v2608, v2604, (float)0.000000);	// L4374
  auto v2612 = reinterpret_cast<float(*)[192][256]>(v2441 + 32735232);
  kernel466(v2604, v2608, v2612);	// L4376
  kernel465(v2612, v2604);	// L4377
  kernel464(v2604, v2609);	// L4378
  auto v2613 = reinterpret_cast<ap_int<8>(*)[192][1]>(v2448 + 295501824);
  kernel483(v2613, v2599);	// L4380
  auto v2614 = reinterpret_cast<ap_int<64>(*)[192][256]>(v2445 + 15040512);
  kernel522(v2601, v2614);	// L4382
  kernel482(v2598, v2599, v2614);	// L4383
  kernel481(v2614, v2603);	// L4384
  kernel480(v2603, v2604);	// L4385
  auto v2615 = reinterpret_cast<float(*)[192][1]>(v2443 + 74207232);
  kernel479(v2615, v2604);	// L4387
  auto v2616 = reinterpret_cast<float(*)>(v2443 + 74539008);
  auto v2617 = reinterpret_cast<float(*)>(v2442 + 74870784);
  kernel434(v2617, v2616, v2562);	// L4390
  auto v2618 = reinterpret_cast<float(*)[192][256]>(v2443 + 16809984);
  kernel477(v2562, v2604, v2618);	// L4392
  auto v2619 = reinterpret_cast<float(*)[192][256]>(v2441 + 5111808);
  kernel464(v2619, v2604);	// L4394
  kernel472(v2604, (float)2.000000);	// L4395
  auto v2620 = reinterpret_cast<float(*)[192][256]>(v2443 + 30081024);
  kernel466(v2604, v2619, v2620);	// L4397
  kernel464(v2618, v2604);	// L4398
  kernel472(v2604, (float)2.000000);	// L4399
  auto v2621 = reinterpret_cast<float(*)[192][256]>(v2441 + 16809984);
  kernel471(v2604, v2620, v2621);	// L4401
  kernel464(v2621, v2604);	// L4402
  kernel469(v2604, (float)1.000000);	// L4403
  auto v2622 = reinterpret_cast<ap_int<8>(*)[192][256]>(v2444 + 120324096);
  kernel468(v2604, v2622, (float)0.000000);	// L4405
  kernel467(v2621, v2604, (float)0.000000);	// L4406
  auto v2623 = reinterpret_cast<float(*)[192][256]>(v2443 + 32735232);
  kernel466(v2604, v2621, v2623);	// L4408
  kernel465(v2623, v2604);	// L4409
  kernel464(v2604, v2619);	// L4410
  auto v2624 = reinterpret_cast<ap_int<8>(*)[8][1][256]>(v2446 + 67239936);
  kernel502(v2624, (ap_int<8>)0);	// L4412
  kernel501(v2611, v2624);	// L4413
  auto v2625 = reinterpret_cast<ap_int<8>(*)[8][24][256]>(v2448 + 125632512);
  kernel500(v2622, v2624, v2625);	// L4415
  auto v2626 = reinterpret_cast<float(*)[8][24][256]>(v2441 + 16809984);
  kernel499(v2625, v2626);	// L4417
  auto v2627 = reinterpret_cast<float(*)[8][24][256]>(v2441 + 5505024);
  auto v2628 = reinterpret_cast<float(*)[8][24][256]>(v2441 + 32735232);
  kernel486(v2627, v2628);	// L4420
  kernel494(v2628, (float)2.000000);	// L4421
  auto v2629 = reinterpret_cast<float(*)[8][24][256]>(v2442 + 34062336);
  kernel488(v2628, v2627, v2629);	// L4423
  kernel486(v2626, v2628);	// L4424
  kernel494(v2628, (float)2.000000);	// L4425
  auto v2630 = reinterpret_cast<float(*)[8][24][256]>(v2442 + 16809984);
  kernel493(v2628, v2629, v2630);	// L4427
  kernel486(v2630, v2628);	// L4428
  kernel491(v2628, (float)0.500000);	// L4429
  kernel490(v2628, v2625, (float)0.000000);	// L4430
  kernel489(v2630, v2628, (float)0.000000);	// L4431
  kernel488(v2628, v2630, v2629);	// L4432
  kernel487(v2629, v2628);	// L4433
  kernel486(v2628, v2627);	// L4434
  kernel485(v2622, v2625);	// L4435
  kernel484(v2625, v2603);	// L4436
  auto v2631 = reinterpret_cast<ap_int<8>(*)[192][1]>(v2448 + 300810240);
  kernel483(v2631, v2599);	// L4438
  kernel482(v2603, v2599, v2601);	// L4439
  kernel481(v2601, v2603);	// L4440
  kernel480(v2603, v2604);	// L4441
  auto v2632 = reinterpret_cast<float(*)[192][1]>(v2443 + 75534336);
  kernel479(v2632, v2604);	// L4443
  auto v2633 = reinterpret_cast<float(*)>(v2443 + 75866112);
  auto v2634 = reinterpret_cast<float(*)>(v2442 + 76197888);
  kernel434(v2634, v2633, v2562);	// L4446
  kernel477(v2562, v2604, v2618);	// L4447
  auto v2635 = reinterpret_cast<float(*)[192][256]>(v2441 + 5898240);
  kernel464(v2635, v2604);	// L4449
  kernel472(v2604, (float)2.000000);	// L4450
  auto v2636 = reinterpret_cast<float(*)[192][256]>(v2441 + 20791296);
  kernel466(v2604, v2635, v2636);	// L4452
  kernel464(v2618, v2604);	// L4453
  kernel472(v2604, (float)2.000000);	// L4454
  kernel471(v2604, v2636, v2618);	// L4455
  kernel464(v2618, v2604);	// L4456
  kernel469(v2604, (float)1.000000);	// L4457
  kernel468(v2604, v2622, (float)0.000000);	// L4458
  kernel467(v2618, v2604, (float)0.000000);	// L4459
  kernel466(v2604, v2618, v2636);	// L4460
  kernel465(v2636, v2604);	// L4461
  kernel464(v2604, v2635);	// L4462
  auto v2637 = reinterpret_cast<ap_int<8>(*)[192][16][16]>(v2446 + 67239936);
  kernel463(v2622, v2596, v2637);	// L4464
  kernel418(v2637, v2589);	// L4465
  auto v2638 = reinterpret_cast<ap_int<32>(*)[192][1][1]>(v2442 + 20791296);
  auto v2639 = reinterpret_cast<ap_int<8>(*)[192][1][1]>(v2448 + 306118656);
  kernel461(v2639, v2638);	// L4468
  auto v2640 = reinterpret_cast<ap_int<64>(*)[768][16][16]>(v2445 + 13049856);
  kernel460(v2640, (ap_int<64>)0);	// L4470
  kernel459(v2589, v2638, v2640);	// L4471
  auto v2641 = reinterpret_cast<ap_int<32>(*)[768][16][16]>(v2441 + 20791296);
  kernel458(v2640, v2641);	// L4473
  auto v2642 = reinterpret_cast<float(*)[768][16][16]>(v2442 + 26099712);
  kernel457(v2641, v2642);	// L4475
  auto v2643 = reinterpret_cast<float(*)[768][1][1]>(v2443 + 76861440);
  kernel456(v2643, v2642);	// L4477
  auto v2644 = reinterpret_cast<float(*)>(v2443 + 27426816);
  auto v2645 = reinterpret_cast<float(*)>(v2442 + 77193216);
  auto v2646 = reinterpret_cast<float(*)>(v2441 + 77524992);
  kernel455(v2646, v2645, v2644);	// L4481
  auto v2647 = reinterpret_cast<float(*)[768][16][16]>(v2441 + 28753920);
  kernel454(v2644, v2642, v2647);	// L4483
  auto v2648 = reinterpret_cast<float(*)[768][16][16]>(v2441 + 6291456);
  kernel441(v2648, v2642);	// L4485
  kernel449(v2642, (float)2.000000);	// L4486
  auto v2649 = reinterpret_cast<float(*)[768][16][16]>(v2443 + 27426816);
  kernel443(v2642, v2648, v2649);	// L4488
  kernel441(v2647, v2642);	// L4489
  kernel449(v2642, (float)2.000000);	// L4490
  kernel448(v2642, v2649, v2647);	// L4491
  kernel441(v2647, v2642);	// L4492
  kernel446(v2642, (float)1.000000);	// L4493
  auto v2650 = reinterpret_cast<ap_int<8>(*)[768][16][16]>(v2444 + 109707264);
  kernel445(v2642, v2650, (float)0.000000);	// L4495
  kernel444(v2647, v2642, (float)0.000000);	// L4496
  auto v2651 = reinterpret_cast<float(*)[768][16][16]>(v2443 + 30081024);
  kernel443(v2642, v2647, v2651);	// L4498
  kernel442(v2651, v2642);	// L4499
  kernel441(v2642, v2648);	// L4500
  kernel440(v2650, v2641);	// L4501
  auto v2652 = reinterpret_cast<ap_int<32>(*)[768][1][1]>(v2441 + 26099712);
  auto v2653 = reinterpret_cast<ap_int<8>(*)[768][1][1]>(v2448 + 311427072);
  kernel439(v2653, v2652);	// L4504
  kernel438(v2641, v2652, v2587);	// L4505
  kernel437(v2587, v2589);	// L4506
  kernel436(v2589, v2581);	// L4507
  auto v2654 = reinterpret_cast<float(*)[192][1][1]>(v2443 + 78188544);
  kernel435(v2654, v2581);	// L4509
  auto v2655 = reinterpret_cast<float(*)>(v2443 + 78520320);
  auto v2656 = reinterpret_cast<float(*)>(v2442 + 78852096);
  kernel434(v2656, v2655, v2562);	// L4512
  kernel433(v2562, v2581, v2582);	// L4513
  auto v2657 = reinterpret_cast<float(*)[192][16][16]>(v2441 + 6684672);
  kernel420(v2657, v2581);	// L4515
  kernel428(v2581, (float)2.000000);	// L4516
  auto v2658 = reinterpret_cast<float(*)[192][16][16]>(v2443 + 19464192);
  kernel422(v2581, v2657, v2658);	// L4518
  kernel420(v2582, v2581);	// L4519
  kernel428(v2581, (float)2.000000);	// L4520
  kernel427(v2581, v2658, v2582);	// L4521
  kernel420(v2582, v2581);	// L4522
  kernel425(v2581, (float)1.000000);	// L4523
  kernel424(v2581, v2596, (float)0.000000);	// L4524
  kernel423(v2582, v2581, (float)0.000000);	// L4525
  kernel422(v2581, v2582, v2658);	// L4526
  kernel421(v2658, v2581);	// L4527
  kernel420(v2581, v2657);	// L4528
  kernel419(v2637, v2596);	// L4529
  kernel418(v2596, v2589);	// L4530
  auto v2659 = reinterpret_cast<ap_int<32>(*)[192][3][3]>(v2441 + 15482880);
  auto v2660 = reinterpret_cast<ap_int<8>(*)[192][3][3]>(v2448 + 316735488);
  kernel417(v2660, v2659);	// L4533
  auto v2661 = reinterpret_cast<ap_int<32>(*)[192][18][18]>(v2442 + 16809984);
  kernel416(v2661, (ap_int<32>)0);	// L4535
  kernel415(v2589, v2661);	// L4536
  auto v2662 = reinterpret_cast<ap_int<64>(*)[384][16][16]>(v2447 + 9732096);
  kernel414(v2662, (ap_int<64>)0);	// L4538
  auto v2663 = reinterpret_cast<ap_int<64>(*)[384][16][16]>(v2445 + 10395648);
  kernel413(v2662, v2663);	// L4540
  kernel412(v2661, v2659, v2663);	// L4541
  auto v2664 = reinterpret_cast<ap_int<32>(*)[384][16][16]>(v2441 + 15482880);
  kernel388(v2663, v2664);	// L4543
  auto v2665 = reinterpret_cast<float(*)[384][16][16]>(v2442 + 16809984);
  kernel387(v2664, v2665);	// L4545
  auto v2666 = reinterpret_cast<float(*)[384][1][1]>(v2443 + 79515648);
  kernel386(v2666, v2665);	// L4547
  auto v2667 = reinterpret_cast<float(*)>(v2442 + 79847424);
  auto v2668 = reinterpret_cast<float(*)>(v2441 + 80179200);
  kernel34(v2668, v2667, v2537);	// L4550
  auto v2669 = reinterpret_cast<float(*)[384][16][16]>(v2441 + 20791296);
  kernel407(v2537, v2665, v2669);	// L4552
  auto v2670 = reinterpret_cast<float(*)[384][16][16]>(v2441 + 7077888);
  kernel394(v2670, v2665);	// L4554
  kernel402(v2665, (float)2.000000);	// L4555
  auto v2671 = reinterpret_cast<float(*)[384][16][16]>(v2441 + 22118400);
  kernel396(v2665, v2670, v2671);	// L4557
  kernel394(v2669, v2665);	// L4558
  kernel402(v2665, (float)2.000000);	// L4559
  auto v2672 = reinterpret_cast<float(*)[384][16][16]>(v2443 + 20791296);
  kernel401(v2665, v2671, v2672);	// L4561
  kernel394(v2672, v2665);	// L4562
  kernel399(v2665, (float)1.000000);	// L4563
  auto v2673 = reinterpret_cast<ap_int<8>(*)[384][16][16]>(v2444 + 88473600);
  kernel398(v2665, v2673, (float)0.000000);	// L4565
  kernel397(v2672, v2665, (float)0.000000);	// L4566
  auto v2674 = reinterpret_cast<float(*)[384][16][16]>(v2441 + 23445504);
  kernel396(v2665, v2672, v2674);	// L4568
  kernel395(v2674, v2665);	// L4569
  kernel394(v2665, v2670);	// L4570
  kernel393(v2673, v2664);	// L4571
  auto v2675 = reinterpret_cast<ap_int<32>(*)[384][3][3]>(v2441 + 20791296);
  auto v2676 = reinterpret_cast<ap_int<8>(*)[384][3][3]>(v2448 + 322043904);
  kernel392(v2676, v2675);	// L4574
  auto v2677 = reinterpret_cast<ap_int<32>(*)[384][18][18]>(v2441 + 22118400);
  kernel391(v2677, (ap_int<32>)0);	// L4576
  kernel390(v2664, v2677);	// L4577
  kernel389(v2677, v2675, v2662);	// L4578
  kernel388(v2662, v2664);	// L4579
  kernel387(v2664, v2665);	// L4580
  auto v2678 = reinterpret_cast<float(*)[384][1][1]>(v2443 + 80842752);
  kernel386(v2678, v2665);	// L4582
  auto v2679 = reinterpret_cast<float(*)>(v2442 + 81174528);
  auto v2680 = reinterpret_cast<float(*)>(v2441 + 81506304);
  kernel34(v2680, v2679, v2537);	// L4585
  kernel384(v2537, v2665);	// L4586
  auto v2681 = reinterpret_cast<float(*)[384][18][18]>(v2442 + 15482880);
  kernel383(v2681, (float)-INFINITY);	// L4588
  kernel382(v2665, v2681);	// L4589
  auto v2682 = reinterpret_cast<float(*)[384][8][8]>(v2443 + 16809984);
  kernel381(v2682, (float)-INFINITY);	// L4591
  kernel380(v2681, v2579, v2682);	// L4592
  auto v2683 = reinterpret_cast<float(*)[384][8][8]>(v2441 + 7471104);
  auto v2684 = reinterpret_cast<float(*)[384][8][8]>(v2441 + 15482880);
  kernel20(v2683, v2684);	// L4595
  kernel28(v2684, (float)2.000000);	// L4596
  auto v2685 = reinterpret_cast<float(*)[384][8][8]>(v2442 + 18137088);
  kernel22(v2684, v2683, v2685);	// L4598
  kernel20(v2682, v2684);	// L4599
  kernel28(v2684, (float)2.000000);	// L4600
  auto v2686 = reinterpret_cast<float(*)[384][8][8]>(v2442 + 16809984);
  kernel27(v2684, v2685, v2686);	// L4602
  kernel20(v2686, v2684);	// L4603
  kernel25(v2684, (float)1.000000);	// L4604
  auto v2687 = reinterpret_cast<ap_int<8>(*)[384][8][8]>(v2446 + 72548352);
  kernel24(v2684, v2687, (float)0.000000);	// L4606
  kernel23(v2686, v2684, (float)0.000000);	// L4607
  auto v2688 = reinterpret_cast<float(*)[384][8][8]>(v2443 + 19464192);
  kernel22(v2684, v2686, v2688);	// L4609
  kernel21(v2688, v2684);	// L4610
  kernel20(v2684, v2683);	// L4611
  auto v2689 = reinterpret_cast<ap_int<32>(*)[192][1][1]>(v2441 + 16809984);
  auto v2690 = reinterpret_cast<ap_int<8>(*)[192][1][1]>(v2448 + 327352320);
  kernel366(v2690, v2689);	// L4614
  auto v2691 = reinterpret_cast<ap_int<64>(*)[384][8][8]>(v2447 + 9732096);
  kernel365(v2691, (ap_int<64>)0);	// L4616
  auto v2692 = reinterpret_cast<ap_int<64>(*)[384][8][8]>(v2445 + 10395648);
  kernel197(v2691, v2692);	// L4618
  kernel363(v2589, v2689, v2692);	// L4619
  auto v2693 = reinterpret_cast<ap_int<32>(*)[384][8][8]>(v2442 + 14155776);
  kernel37(v2692, v2693);	// L4621
  kernel36(v2693, v2684);	// L4622
  auto v2694 = reinterpret_cast<float(*)[384][1][1]>(v2443 + 82169856);
  kernel35(v2694, v2684);	// L4624
  auto v2695 = reinterpret_cast<float(*)>(v2442 + 82501632);
  auto v2696 = reinterpret_cast<float(*)>(v2441 + 82833408);
  kernel34(v2696, v2695, v2537);	// L4627
  kernel33(v2537, v2684, v2686);	// L4628
  auto v2697 = reinterpret_cast<float(*)[384][8][8]>(v2441 + 7864320);
  kernel20(v2697, v2684);	// L4630
  kernel28(v2684, (float)2.000000);	// L4631
  auto v2698 = reinterpret_cast<float(*)[384][8][8]>(v2443 + 20791296);
  kernel22(v2684, v2697, v2698);	// L4633
  kernel20(v2686, v2684);	// L4634
  kernel28(v2684, (float)2.000000);	// L4635
  kernel27(v2684, v2698, v2686);	// L4636
  kernel20(v2686, v2684);	// L4637
  kernel25(v2684, (float)1.000000);	// L4638
  auto v2699 = reinterpret_cast<ap_int<8>(*)[384][8][8]>(v2444 + 83165184);
  kernel24(v2684, v2699, (float)0.000000);	// L4640
  kernel23(v2686, v2684, (float)0.000000);	// L4641
  auto v2700 = reinterpret_cast<float(*)[384][8][8]>(v2442 + 22118400);
  kernel22(v2684, v2686, v2700);	// L4643
  kernel21(v2700, v2684);	// L4644
  kernel20(v2684, v2697);	// L4645
  kernel19(v2687, v2699);	// L4646
  auto v2701 = reinterpret_cast<ap_int<32>(*)[384][64]>(v2441 + 16809984);
  kernel176(v2699, v2701);	// L4648
  auto v2702 = reinterpret_cast<ap_int<32>(*)[384][1]>(v2441 + 18137088);
  auto v2703 = reinterpret_cast<ap_int<8>(*)[384][1]>(v2448 + 332660736);
  kernel82(v2703, v2702);	// L4651
  auto v2704 = reinterpret_cast<ap_int<64>(*)[384][64]>(v2445 + 11059200);
  kernel341(v2704, (ap_int<64>)0);	// L4653
  auto v2705 = reinterpret_cast<ap_int<64>(*)[384][64]>(v2445 + 11722752);
  kernel129(v2704, v2705);	// L4655
  kernel81(v2701, v2702, v2705);	// L4656
  auto v2706 = reinterpret_cast<ap_int<32>(*)[384][64]>(v2442 + 26099712);
  kernel80(v2705, v2706);	// L4658
  auto v2707 = reinterpret_cast<float(*)[384][64]>(v2441 + 23445504);
  kernel79(v2706, v2707);	// L4660
  auto v2708 = reinterpret_cast<float(*)[384][1]>(v2443 + 83496960);
  kernel78(v2708, v2707);	// L4662
  auto v2709 = reinterpret_cast<float(*)>(v2442 + 83828736);
  auto v2710 = reinterpret_cast<float(*)>(v2441 + 84160512);
  kernel34(v2710, v2709, v2537);	// L4665
  auto v2711 = reinterpret_cast<float(*)[384][64]>(v2442 + 27426816);
  kernel76(v2537, v2707, v2711);	// L4667
  auto v2712 = reinterpret_cast<float(*)[384][64]>(v2441 + 8257536);
  kernel63(v2712, v2707);	// L4669
  kernel71(v2707, (float)2.000000);	// L4670
  auto v2713 = reinterpret_cast<float(*)[384][64]>(v2442 + 28753920);
  kernel65(v2707, v2712, v2713);	// L4672
  kernel63(v2711, v2707);	// L4673
  kernel71(v2707, (float)2.000000);	// L4674
  auto v2714 = reinterpret_cast<float(*)[384][64]>(v2443 + 27426816);
  kernel70(v2707, v2713, v2714);	// L4676
  kernel63(v2714, v2707);	// L4677
  kernel68(v2707, (float)1.000000);	// L4678
  auto v2715 = reinterpret_cast<ap_int<8>(*)[384][64]>(v2444 + 115015680);
  kernel67(v2707, v2715, (float)0.000000);	// L4680
  kernel66(v2714, v2707, (float)0.000000);	// L4681
  auto v2716 = reinterpret_cast<float(*)[384][64]>(v2442 + 30081024);
  kernel65(v2707, v2714, v2716);	// L4683
  kernel64(v2716, v2707);	// L4684
  kernel63(v2707, v2712);	// L4685
  auto v2717 = reinterpret_cast<ap_int<8>(*)[64][384]>(v2446 + 109707264);
  kernel109(v2715, v2717);	// L4687
  auto v2718 = reinterpret_cast<ap_int<8>(*)[8][64][48]>(v2444 + 120324096);
  kernel108(v2717, v2718);	// L4689
  auto v2719 = reinterpret_cast<ap_int<8>(*)[384][1]>(v2448 + 337969152);
  kernel82(v2719, v2702);	// L4691
  auto v2720 = reinterpret_cast<ap_int<64>(*)[384][64]>(v2447 + 15704064);
  kernel129(v2704, v2720);	// L4693
  kernel81(v2701, v2702, v2720);	// L4694
  kernel80(v2720, v2706);	// L4695
  kernel79(v2706, v2707);	// L4696
  auto v2721 = reinterpret_cast<float(*)[384][1]>(v2443 + 84824064);
  kernel78(v2721, v2707);	// L4698
  auto v2722 = reinterpret_cast<float(*)>(v2442 + 85155840);
  auto v2723 = reinterpret_cast<float(*)>(v2441 + 85487616);
  kernel34(v2723, v2722, v2537);	// L4701
  auto v2724 = reinterpret_cast<float(*)[384][64]>(v2442 + 31408128);
  kernel76(v2537, v2707, v2724);	// L4703
  auto v2725 = reinterpret_cast<float(*)[384][64]>(v2441 + 8650752);
  kernel63(v2725, v2707);	// L4705
  kernel71(v2707, (float)2.000000);	// L4706
  auto v2726 = reinterpret_cast<float(*)[384][64]>(v2442 + 32735232);
  kernel65(v2707, v2725, v2726);	// L4708
  kernel63(v2724, v2707);	// L4709
  kernel71(v2707, (float)2.000000);	// L4710
  auto v2727 = reinterpret_cast<float(*)[384][64]>(v2443 + 31408128);
  kernel70(v2707, v2726, v2727);	// L4712
  kernel63(v2727, v2707);	// L4713
  kernel68(v2707, (float)1.000000);	// L4714
  kernel67(v2707, v2715, (float)0.000000);	// L4715
  kernel66(v2727, v2707, (float)0.000000);	// L4716
  kernel65(v2707, v2727, v2726);	// L4717
  kernel64(v2726, v2707);	// L4718
  kernel63(v2707, v2725);	// L4719
  auto v2728 = reinterpret_cast<ap_int<8>(*)[64][384]>(v2446 + 125632512);
  kernel109(v2715, v2728);	// L4721
  auto v2729 = reinterpret_cast<ap_int<8>(*)[384][1]>(v2448 + 343277568);
  kernel82(v2729, v2702);	// L4723
  auto v2730 = reinterpret_cast<ap_int<64>(*)[384][64]>(v2445 + 16367616);
  kernel129(v2704, v2730);	// L4725
  kernel81(v2701, v2702, v2730);	// L4726
  kernel80(v2730, v2706);	// L4727
  kernel79(v2706, v2707);	// L4728
  auto v2731 = reinterpret_cast<float(*)[384][1]>(v2443 + 86151168);
  kernel78(v2731, v2707);	// L4730
  auto v2732 = reinterpret_cast<float(*)>(v2442 + 86482944);
  auto v2733 = reinterpret_cast<float(*)>(v2441 + 86814720);
  kernel34(v2733, v2732, v2537);	// L4733
  auto v2734 = reinterpret_cast<float(*)[384][64]>(v2442 + 16809984);
  kernel76(v2537, v2707, v2734);	// L4735
  auto v2735 = reinterpret_cast<float(*)[384][64]>(v2441 + 9043968);
  kernel63(v2735, v2707);	// L4737
  kernel71(v2707, (float)2.000000);	// L4738
  auto v2736 = reinterpret_cast<float(*)[384][64]>(v2443 + 32735232);
  kernel65(v2707, v2735, v2736);	// L4740
  kernel63(v2734, v2707);	// L4741
  kernel71(v2707, (float)2.000000);	// L4742
  kernel70(v2707, v2736, v2734);	// L4743
  kernel63(v2734, v2707);	// L4744
  kernel68(v2707, (float)1.000000);	// L4745
  kernel67(v2707, v2715, (float)0.000000);	// L4746
  kernel66(v2734, v2707, (float)0.000000);	// L4747
  kernel65(v2707, v2734, v2726);	// L4748
  kernel64(v2726, v2707);	// L4749
  kernel63(v2707, v2735);	// L4750
  kernel109(v2715, v2717);	// L4751
  auto v2737 = reinterpret_cast<ap_int<8>(*)[8][64][48]>(v2444 + 67239936);
  kernel108(v2717, v2737);	// L4753
  auto v2738 = reinterpret_cast<ap_int<8>(*)[8][48][64]>(v2444 + 130940928);
  kernel107(v2728, v2738);	// L4755
  auto v2739 = reinterpret_cast<float(*)[48][64]>(v2442 + 31408128);
  kernel106(v2738, v2739);	// L4757
  auto v2740 = reinterpret_cast<float(*)[64][48]>(v2441 + 34062336);
  kernel102(v2737, v2740);	// L4759
  auto v2741 = reinterpret_cast<float(*)[48][48]>(v2441 + 35389440);
  kernel270(v2741, (float)0.000000);	// L4761
  auto v2742 = reinterpret_cast<float(*)[48][48]>(v2441 + 36716544);
  kernel269(v2741, v2742);	// L4763
  kernel104(v2739, v2740, v2742);	// L4764
  auto v2743 = reinterpret_cast<ap_int<8>(*)[48][48]>(v2444 + 152174592);
  kernel103(v2742, v2743);	// L4766
  kernel102(v2718, v2740);	// L4767
  auto v2744 = reinterpret_cast<float(*)[48][48]>(v2441 + 30081024);
  kernel101(v2743, v2744);	// L4769
  auto v2745 = reinterpret_cast<float(*)[64][48]>(v2441 + 36716544);
  kernel264(v2745, (float)0.000000);	// L4771
  auto v2746 = reinterpret_cast<float(*)[64][48]>(v2442 + 39370752);
  kernel263(v2745, v2746);	// L4773
  kernel100(v2740, v2744, v2746);	// L4774
  auto v2747 = reinterpret_cast<ap_int<8>(*)[64][48]>(v2444 + 162791424);
  kernel99(v2746, v2747);	// L4776
  auto v2748 = reinterpret_cast<float(*)[8][64][48]>(v2441 + 39370752);
  kernel98(v2747, v2748, (float)0.125000);	// L4778
  auto v2749 = reinterpret_cast<float(*)[8][48][64]>(v2442 + 42024960);
  kernel97(v2748, v2749);	// L4780
  auto v2750 = reinterpret_cast<float(*)[384][64]>(v2441 + 9437184);
  kernel63(v2750, v2707);	// L4782
  kernel71(v2707, (float)2.000000);	// L4783
  auto v2751 = reinterpret_cast<float(*)[384][64]>(v2443 + 43352064);
  kernel65(v2707, v2750, v2751);	// L4785
  kernel93(v2749, v2707);	// L4786
  kernel71(v2707, (float)2.000000);	// L4787
  auto v2752 = reinterpret_cast<float(*)[384][64]>(v2442 + 44679168);
  kernel70(v2707, v2751, v2752);	// L4789
  kernel63(v2752, v2707);	// L4790
  kernel68(v2707, (float)0.500000);	// L4791
  kernel67(v2707, v2715, (float)0.000000);	// L4792
  kernel66(v2752, v2707, (float)0.000000);	// L4793
  kernel65(v2707, v2752, v2751);	// L4794
  kernel64(v2751, v2707);	// L4795
  kernel63(v2707, v2750);	// L4796
  kernel83(v2715, v2706);	// L4797
  auto v2753 = reinterpret_cast<ap_int<8>(*)[384][1]>(v2448 + 348585984);
  kernel82(v2753, v2702);	// L4799
  auto v2754 = reinterpret_cast<ap_int<64>(*)[384][64]>(v2445 + 21676032);
  kernel129(v2704, v2754);	// L4801
  kernel81(v2706, v2702, v2754);	// L4802
  kernel80(v2754, v2706);	// L4803
  kernel79(v2706, v2707);	// L4804
  auto v2755 = reinterpret_cast<float(*)[384][1]>(v2443 + 87478272);
  kernel78(v2755, v2707);	// L4806
  auto v2756 = reinterpret_cast<float(*)>(v2442 + 87810048);
  auto v2757 = reinterpret_cast<float(*)>(v2441 + 88141824);
  kernel34(v2757, v2756, v2537);	// L4809
  auto v2758 = reinterpret_cast<float(*)[384][64]>(v2442 + 43352064);
  kernel76(v2537, v2707, v2758);	// L4811
  auto v2759 = reinterpret_cast<float(*)[384][64]>(v2441 + 9830400);
  kernel63(v2759, v2707);	// L4813
  kernel71(v2707, (float)2.000000);	// L4814
  auto v2760 = reinterpret_cast<float(*)[384][64]>(v2443 + 44679168);
  kernel65(v2707, v2759, v2760);	// L4816
  kernel63(v2758, v2707);	// L4817
  kernel71(v2707, (float)2.000000);	// L4818
  kernel70(v2707, v2760, v2758);	// L4819
  kernel63(v2758, v2707);	// L4820
  kernel68(v2707, (float)1.000000);	// L4821
  kernel67(v2707, v2715, (float)0.000000);	// L4822
  kernel66(v2758, v2707, (float)0.000000);	// L4823
  kernel65(v2707, v2758, v2752);	// L4824
  kernel64(v2752, v2707);	// L4825
  kernel63(v2707, v2759);	// L4826
  auto v2761 = reinterpret_cast<ap_int<8>(*)[384][8][8]>(v2446 + 173408256);
  kernel62(v2715, v2699, v2761);	// L4828
  kernel61(v2761, v2693);	// L4829
  auto v2762 = reinterpret_cast<ap_int<32>(*)[384][1][1]>(v2441 + 44679168);
  auto v2763 = reinterpret_cast<ap_int<8>(*)[384][1][1]>(v2448 + 353894400);
  kernel60(v2763, v2762);	// L4832
  auto v2764 = reinterpret_cast<ap_int<64>(*)[1536][8][8]>(v2445 + 23003136);
  kernel220(v2764, (ap_int<64>)0);	// L4834
  auto v2765 = reinterpret_cast<ap_int<64>(*)[1536][8][8]>(v2447 + 23666688);
  kernel219(v2764, v2765);	// L4836
  kernel59(v2693, v2762, v2765);	// L4837
  auto v2766 = reinterpret_cast<ap_int<32>(*)[1536][8][8]>(v2441 + 48660480);
  kernel58(v2765, v2766);	// L4839
  auto v2767 = reinterpret_cast<float(*)[1536][8][8]>(v2441 + 47333376);
  kernel57(v2766, v2767);	// L4841
  auto v2768 = reinterpret_cast<float(*)[1536][1][1]>(v2443 + 88805376);
  kernel56(v2768, v2767);	// L4843
  auto v2769 = reinterpret_cast<float(*)>(v2443 + 49987584);
  auto v2770 = reinterpret_cast<float(*)>(v2442 + 89137152);
  auto v2771 = reinterpret_cast<float(*)>(v2441 + 89468928);
  kernel55(v2771, v2770, v2769);	// L4847
  auto v2772 = reinterpret_cast<float(*)[1536][8][8]>(v2442 + 51314688);
  kernel54(v2769, v2767, v2772);	// L4849
  auto v2773 = reinterpret_cast<float(*)[1536][8][8]>(v2441 + 10223616);
  kernel41(v2773, v2767);	// L4851
  kernel49(v2767, (float)2.000000);	// L4852
  auto v2774 = reinterpret_cast<float(*)[1536][8][8]>(v2442 + 52641792);
  kernel43(v2767, v2773, v2774);	// L4854
  kernel41(v2772, v2767);	// L4855
  kernel49(v2767, (float)2.000000);	// L4856
  kernel48(v2767, v2774, v2772);	// L4857
  kernel41(v2772, v2767);	// L4858
  kernel46(v2767, (float)1.000000);	// L4859
  auto v2775 = reinterpret_cast<ap_int<8>(*)[1536][8][8]>(v2444 + 210567168);
  kernel45(v2767, v2775, (float)0.000000);	// L4861
  kernel44(v2772, v2767, (float)0.000000);	// L4862
  auto v2776 = reinterpret_cast<float(*)[1536][8][8]>(v2443 + 53968896);
  kernel43(v2767, v2772, v2776);	// L4864
  kernel42(v2776, v2767);	// L4865
  kernel41(v2767, v2773);	// L4866
  kernel40(v2775, v2766);	// L4867
  auto v2777 = reinterpret_cast<ap_int<32>(*)[1536][1][1]>(v2442 + 51314688);
  auto v2778 = reinterpret_cast<ap_int<8>(*)[1536][1][1]>(v2448 + 359202816);
  kernel39(v2778, v2777);	// L4870
  auto v2779 = reinterpret_cast<ap_int<64>(*)[384][8][8]>(v2445 + 26984448);
  kernel197(v2691, v2779);	// L4872
  kernel38(v2766, v2777, v2779);	// L4873
  kernel37(v2779, v2693);	// L4874
  kernel36(v2693, v2684);	// L4875
  auto v2780 = reinterpret_cast<float(*)[384][1][1]>(v2443 + 90132480);
  kernel35(v2780, v2684);	// L4877
  auto v2781 = reinterpret_cast<float(*)>(v2442 + 90464256);
  auto v2782 = reinterpret_cast<float(*)>(v2441 + 90796032);
  kernel34(v2782, v2781, v2537);	// L4880
  auto v2783 = reinterpret_cast<float(*)[384][8][8]>(v2442 + 53968896);
  kernel33(v2537, v2684, v2783);	// L4882
  auto v2784 = reinterpret_cast<float(*)[384][8][8]>(v2441 + 10616832);
  kernel20(v2784, v2684);	// L4884
  kernel28(v2684, (float)2.000000);	// L4885
  auto v2785 = reinterpret_cast<float(*)[384][8][8]>(v2442 + 55296000);
  kernel22(v2684, v2784, v2785);	// L4887
  kernel20(v2783, v2684);	// L4888
  kernel28(v2684, (float)2.000000);	// L4889
  kernel27(v2684, v2785, v2783);	// L4890
  kernel20(v2783, v2684);	// L4891
  kernel25(v2684, (float)1.000000);	// L4892
  kernel24(v2684, v2699, (float)0.000000);	// L4893
  kernel23(v2783, v2684, (float)0.000000);	// L4894
  auto v2786 = reinterpret_cast<float(*)[384][8][8]>(v2443 + 55296000);
  kernel22(v2684, v2783, v2786);	// L4896
  kernel21(v2786, v2684);	// L4897
  kernel20(v2684, v2784);	// L4898
  kernel19(v2761, v2699);	// L4899
  auto v2787 = reinterpret_cast<ap_int<32>(*)[384][64]>(v2442 + 43352064);
  kernel176(v2699, v2787);	// L4901
  auto v2788 = reinterpret_cast<ap_int<8>(*)[384][1]>(v2448 + 364511232);
  kernel82(v2788, v2702);	// L4903
  auto v2789 = reinterpret_cast<ap_int<64>(*)[384][64]>(v2445 + 26984448);
  kernel129(v2704, v2789);	// L4905
  kernel81(v2787, v2702, v2789);	// L4906
  kernel80(v2789, v2706);	// L4907
  kernel79(v2706, v2707);	// L4908
  auto v2790 = reinterpret_cast<float(*)[384][1]>(v2443 + 91459584);
  kernel78(v2790, v2707);	// L4910
  auto v2791 = reinterpret_cast<float(*)>(v2442 + 91791360);
  auto v2792 = reinterpret_cast<float(*)>(v2441 + 92123136);
  kernel34(v2792, v2791, v2537);	// L4913
  auto v2793 = reinterpret_cast<float(*)[384][64]>(v2442 + 53968896);
  kernel76(v2537, v2707, v2793);	// L4915
  auto v2794 = reinterpret_cast<float(*)[384][64]>(v2441 + 11010048);
  kernel63(v2794, v2707);	// L4917
  kernel71(v2707, (float)2.000000);	// L4918
  auto v2795 = reinterpret_cast<float(*)[384][64]>(v2442 + 55296000);
  kernel65(v2707, v2794, v2795);	// L4920
  kernel63(v2793, v2707);	// L4921
  kernel71(v2707, (float)2.000000);	// L4922
  kernel70(v2707, v2795, v2793);	// L4923
  kernel63(v2793, v2707);	// L4924
  kernel68(v2707, (float)1.000000);	// L4925
  kernel67(v2707, v2715, (float)0.000000);	// L4926
  kernel66(v2793, v2707, (float)0.000000);	// L4927
  auto v2796 = reinterpret_cast<float(*)[384][64]>(v2443 + 55296000);
  kernel65(v2707, v2793, v2796);	// L4929
  kernel64(v2796, v2707);	// L4930
  kernel63(v2707, v2794);	// L4931
  kernel109(v2715, v2717);	// L4932
  auto v2797 = reinterpret_cast<ap_int<8>(*)[8][64][48]>(v2444 + 215875584);
  kernel108(v2717, v2797);	// L4934
  auto v2798 = reinterpret_cast<ap_int<8>(*)[384][1]>(v2448 + 369819648);
  kernel82(v2798, v2702);	// L4936
  auto v2799 = reinterpret_cast<ap_int<64>(*)[384][64]>(v2445 + 27648000);
  kernel129(v2704, v2799);	// L4938
  kernel81(v2787, v2702, v2799);	// L4939
  kernel80(v2799, v2706);	// L4940
  kernel79(v2706, v2707);	// L4941
  auto v2800 = reinterpret_cast<float(*)[384][1]>(v2443 + 92786688);
  kernel78(v2800, v2707);	// L4943
  auto v2801 = reinterpret_cast<float(*)>(v2442 + 93118464);
  auto v2802 = reinterpret_cast<float(*)>(v2441 + 93450240);
  kernel34(v2802, v2801, v2537);	// L4946
  kernel76(v2537, v2707, v2795);	// L4947
  auto v2803 = reinterpret_cast<float(*)[384][64]>(v2441 + 11403264);
  kernel63(v2803, v2707);	// L4949
  kernel71(v2707, (float)2.000000);	// L4950
  auto v2804 = reinterpret_cast<float(*)[384][64]>(v2442 + 56623104);
  kernel65(v2707, v2803, v2804);	// L4952
  kernel63(v2795, v2707);	// L4953
  kernel71(v2707, (float)2.000000);	// L4954
  kernel70(v2707, v2804, v2796);	// L4955
  kernel63(v2796, v2707);	// L4956
  kernel68(v2707, (float)1.000000);	// L4957
  kernel67(v2707, v2715, (float)0.000000);	// L4958
  kernel66(v2796, v2707, (float)0.000000);	// L4959
  kernel65(v2707, v2796, v2804);	// L4960
  kernel64(v2804, v2707);	// L4961
  kernel63(v2707, v2803);	// L4962
  auto v2805 = reinterpret_cast<ap_int<8>(*)[64][384]>(v2446 + 221184000);
  kernel109(v2715, v2805);	// L4964
  auto v2806 = reinterpret_cast<ap_int<8>(*)[384][1]>(v2448 + 375128064);
  kernel82(v2806, v2702);	// L4966
  auto v2807 = reinterpret_cast<ap_int<64>(*)[384][64]>(v2445 + 28311552);
  kernel129(v2704, v2807);	// L4968
  kernel81(v2787, v2702, v2807);	// L4969
  kernel80(v2807, v2706);	// L4970
  kernel79(v2706, v2707);	// L4971
  auto v2808 = reinterpret_cast<float(*)[384][1]>(v2443 + 94113792);
  kernel78(v2808, v2707);	// L4973
  auto v2809 = reinterpret_cast<float(*)>(v2442 + 94445568);
  auto v2810 = reinterpret_cast<float(*)>(v2441 + 94777344);
  kernel34(v2810, v2809, v2537);	// L4976
  kernel76(v2537, v2707, v2758);	// L4977
  auto v2811 = reinterpret_cast<float(*)[384][64]>(v2441 + 11796480);
  kernel63(v2811, v2707);	// L4979
  kernel71(v2707, (float)2.000000);	// L4980
  auto v2812 = reinterpret_cast<float(*)[384][64]>(v2443 + 56623104);
  kernel65(v2707, v2811, v2812);	// L4982
  kernel63(v2758, v2707);	// L4983
  kernel71(v2707, (float)2.000000);	// L4984
  kernel70(v2707, v2812, v2758);	// L4985
  kernel63(v2758, v2707);	// L4986
  kernel68(v2707, (float)1.000000);	// L4987
  kernel67(v2707, v2715, (float)0.000000);	// L4988
  kernel66(v2758, v2707, (float)0.000000);	// L4989
  kernel65(v2707, v2758, v2812);	// L4990
  kernel64(v2812, v2707);	// L4991
  kernel63(v2707, v2811);	// L4992
  kernel109(v2715, v2717);	// L4993
  kernel108(v2717, v2737);	// L4994
  kernel107(v2805, v2738);	// L4995
  kernel106(v2738, v2739);	// L4996
  kernel102(v2737, v2740);	// L4997
  kernel104(v2739, v2740, v2741);	// L4998
  kernel103(v2741, v2743);	// L4999
  kernel102(v2797, v2740);	// L5000
  kernel101(v2743, v2744);	// L5001
  kernel100(v2740, v2744, v2745);	// L5002
  kernel99(v2745, v2747);	// L5003
  kernel98(v2747, v2748, (float)0.125000);	// L5004
  kernel97(v2748, v2749);	// L5005
  auto v2813 = reinterpret_cast<float(*)[384][64]>(v2441 + 12189696);
  kernel63(v2813, v2707);	// L5007
  kernel71(v2707, (float)2.000000);	// L5008
  kernel65(v2707, v2813, v2734);	// L5009
  kernel93(v2749, v2707);	// L5010
  kernel71(v2707, (float)2.000000);	// L5011
  kernel70(v2707, v2734, v2714);	// L5012
  kernel63(v2714, v2707);	// L5013
  kernel68(v2707, (float)0.500000);	// L5014
  kernel67(v2707, v2715, (float)0.000000);	// L5015
  kernel66(v2714, v2707, (float)0.000000);	// L5016
  kernel65(v2707, v2714, v2734);	// L5017
  kernel64(v2734, v2707);	// L5018
  kernel63(v2707, v2813);	// L5019
  kernel83(v2715, v2706);	// L5020
  auto v2814 = reinterpret_cast<ap_int<8>(*)[384][1]>(v2448 + 380436480);
  kernel82(v2814, v2702);	// L5022
  kernel81(v2706, v2702, v2704);	// L5023
  kernel80(v2704, v2706);	// L5024
  kernel79(v2706, v2707);	// L5025
  auto v2815 = reinterpret_cast<float(*)[384][1]>(v2443 + 95440896);
  kernel78(v2815, v2707);	// L5027
  auto v2816 = reinterpret_cast<float(*)>(v2442 + 95772672);
  auto v2817 = reinterpret_cast<float(*)>(v2441 + 96104448);
  kernel34(v2817, v2816, v2537);	// L5030
  kernel76(v2537, v2707, v2734);	// L5031
  auto v2818 = reinterpret_cast<float(*)[384][64]>(v2441 + 12582912);
  kernel63(v2818, v2707);	// L5033
  kernel71(v2707, (float)2.000000);	// L5034
  auto v2819 = reinterpret_cast<float(*)[384][64]>(v2443 + 18137088);
  kernel65(v2707, v2818, v2819);	// L5036
  kernel63(v2734, v2707);	// L5037
  kernel71(v2707, (float)2.000000);	// L5038
  kernel70(v2707, v2819, v2734);	// L5039
  kernel63(v2734, v2707);	// L5040
  kernel68(v2707, (float)1.000000);	// L5041
  kernel67(v2707, v2715, (float)0.000000);	// L5042
  kernel66(v2734, v2707, (float)0.000000);	// L5043
  kernel65(v2707, v2734, v2819);	// L5044
  kernel64(v2819, v2707);	// L5045
  kernel63(v2707, v2818);	// L5046
  auto v2820 = reinterpret_cast<ap_int<8>(*)[384][8][8]>(v2446 + 67239936);
  kernel62(v2715, v2699, v2820);	// L5048
  kernel61(v2820, v2693);	// L5049
  auto v2821 = reinterpret_cast<ap_int<8>(*)[384][1][1]>(v2448 + 385744896);
  kernel60(v2821, v2762);	// L5051
  kernel59(v2693, v2762, v2764);	// L5052
  kernel58(v2764, v2766);	// L5053
  kernel57(v2766, v2767);	// L5054
  auto v2822 = reinterpret_cast<float(*)[1536][1][1]>(v2443 + 96768000);
  kernel56(v2822, v2767);	// L5056
  auto v2823 = reinterpret_cast<float(*)>(v2442 + 97099776);
  auto v2824 = reinterpret_cast<float(*)>(v2441 + 97431552);
  kernel55(v2824, v2823, v2769);	// L5059
  auto v2825 = reinterpret_cast<float(*)[1536][8][8]>(v2442 + 18137088);
  kernel54(v2769, v2767, v2825);	// L5061
  auto v2826 = reinterpret_cast<float(*)[1536][8][8]>(v2441 + 12976128);
  kernel41(v2826, v2767);	// L5063
  kernel49(v2767, (float)2.000000);	// L5064
  auto v2827 = reinterpret_cast<float(*)[1536][8][8]>(v2442 + 22118400);
  kernel43(v2767, v2826, v2827);	// L5066
  kernel41(v2825, v2767);	// L5067
  kernel49(v2767, (float)2.000000);	// L5068
  auto v2828 = reinterpret_cast<float(*)[1536][8][8]>(v2443 + 18137088);
  kernel48(v2767, v2827, v2828);	// L5070
  kernel41(v2828, v2767);	// L5071
  kernel46(v2767, (float)1.000000);	// L5072
  kernel45(v2767, v2775, (float)0.000000);	// L5073
  kernel44(v2828, v2767, (float)0.000000);	// L5074
  kernel43(v2767, v2828, v2827);	// L5075
  kernel42(v2827, v2767);	// L5076
  kernel41(v2767, v2826);	// L5077
  kernel40(v2775, v2766);	// L5078
  auto v2829 = reinterpret_cast<ap_int<8>(*)[1536][1][1]>(v2448 + 391053312);
  kernel39(v2829, v2777);	// L5080
  kernel38(v2766, v2777, v2691);	// L5081
  kernel37(v2691, v2693);	// L5082
  kernel36(v2693, v2684);	// L5083
  auto v2830 = reinterpret_cast<float(*)[384][1][1]>(v2443 + 98095104);
  kernel35(v2830, v2684);	// L5085
  auto v2831 = reinterpret_cast<float(*)>(v2442 + 98426880);
  auto v2832 = reinterpret_cast<float(*)>(v2441 + 98758656);
  kernel34(v2832, v2831, v2537);	// L5088
  auto v2833 = reinterpret_cast<float(*)[384][8][8]>(v2442 + 14155776);
  kernel33(v2537, v2684, v2833);	// L5090
  auto v2834 = reinterpret_cast<float(*)[384][8][8]>(v2441 + 13369344);
  kernel20(v2834, v2684);	// L5092
  kernel28(v2684, (float)2.000000);	// L5093
  auto v2835 = reinterpret_cast<float(*)[384][8][8]>(v2443 + 18137088);
  kernel22(v2684, v2834, v2835);	// L5095
  kernel20(v2833, v2684);	// L5096
  kernel28(v2684, (float)2.000000);	// L5097
  kernel27(v2684, v2835, v2833);	// L5098
  kernel20(v2833, v2684);	// L5099
  kernel25(v2684, (float)1.000000);	// L5100
  kernel24(v2684, v2699, (float)0.000000);	// L5101
  kernel23(v2833, v2684, (float)0.000000);	// L5102
  kernel22(v2684, v2833, v2835);	// L5103
  kernel21(v2835, v2684);	// L5104
  kernel20(v2684, v2834);	// L5105
  kernel19(v2820, v2699);	// L5106
  kernel18(v2699, v2707);	// L5107
  auto v2836 = reinterpret_cast<float(*)[384]>(v2441 + 14155776);
  kernel17(v2836, (float)0.000000);	// L5109
  kernel16(v2707, v2836);	// L5110
  kernel14(v2836, (float)64.000000);	// L5111
  kernel14(v2836, (float)0.027436);	// L5112
  kernel13(v2836);	// L5113
  kernel12(v2836, (float)127.000000, (float)-127.000000);	// L5114
  auto v2837 = reinterpret_cast<ap_int<8>(*)[384]>(v2444 + 61931520);
  kernel11(v2836, v2837);	// L5116
  auto v2838 = reinterpret_cast<ap_int<32>(*)[384]>(v2441 + 14155776);
  kernel10(v2837, v2838);	// L5118
  auto v2839 = reinterpret_cast<ap_int<32>(*)[384]>(v2441 + 15482880);
  auto v2840 = reinterpret_cast<ap_int<8>(*)[384]>(v2448 + 396361728);
  kernel9(v2840, v2839);	// L5121
  auto v2841 = reinterpret_cast<ap_int<32>(*)[100]>(v2442 + 16809984);
  kernel8(v2839, v2841);	// L5123
  auto v2842 = reinterpret_cast<ap_int<64>(*)[100]>(v2445 + 7741440);
  kernel7(v2842, (ap_int<64>)0);	// L5125
  kernel6(v2838, v2841, v2842);	// L5126
  auto v2843 = reinterpret_cast<ap_int<32>(*)[100]>(v2442 + 14155776);
  kernel5(v2842, v2843);	// L5128
  auto v2844 = reinterpret_cast<float(*)[100]>(v2441 + 13762560);
  kernel4(v2843, v2844);	// L5130
  auto v2845 = reinterpret_cast<float(*)[100]>(v2443 + 99422208);
  kernel3(v2845, v2844);	// L5132
  auto v2846 = reinterpret_cast<float(*)>(v2441 + 14155776);
  auto v2847 = reinterpret_cast<ap_int<32>(*)>(v2443 + 99753984);
  kernel2(v2847, v2846);	// L5135
  auto v2848 = reinterpret_cast<float(*)>(v2443 + 100085760);
  kernel1(v2848, v2846);	// L5137
  kernel0(v2846, v2844);	// L5138
}

