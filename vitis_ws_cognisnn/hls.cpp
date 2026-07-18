
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
  float v0[11],
  float v1[1][11]
) {	// L2
  for (int v2 = 0; v2 < 11; v2 += 1) {	// L3
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
  float v6[1][32][1][1],
  float v7[32][11],
  float v8[1][11]
) {	// L11
  float v9[1][32][1][1];	// L12
  #pragma HLS resource variable=v9 core=ram_t2p_bram

  memcpy(v9, v6, 32 * sizeof(float));	// L13

  for (int v10 = 0; v10 < 32; v10 += 1) {	// L14
    for (int v11 = 0; v11 < 11; v11 += 1) {	// L15
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v9
      #pragma HLS dependence false variable=v7
      #pragma HLS dependence false variable=v8
      float v12 = v9[0][v10][0][0];	// L16
      float v13 = v7[v10][v11];	// L17
      float v14 = v8[0][v11];	// L18
      float v15 = v12 * v13;	// L19
      float v16 = v14 + v15;	// L20
      v8[0][v11] = v16;	// L21
    }
  }
}

void kernel2(
  float v17[1][11],
  float v18
) {	// L26
  for (int v19 = 0; v19 < 11; v19 += 1) {	// L27
    #pragma HLS pipeline II=1
    #pragma HLS dependence false variable=v17
    v17[0][v19] = v18;	// L28
  }
}

void kernel3(
  float v20[1][32][1][1],
  float v21
) {	// L32
  for (int v22 = 0; v22 < 32; v22 += 1) {	// L33
    float v23 = v20[0][v22][0][0];	// L34
    float v24 = v23 / v21;	// L35
    v20[0][v22][0][0] = v24;	// L36
  }
}

void kernel4(
  float v25[1][32][2][2],
  float v26[2][2],
  float v27[1][32][1][1]
) {	// L40
  for (int v28 = 0; v28 < 2; v28 += 1) {	// L41
    for (int v29 = 0; v29 < 2; v29 += 1) {	// L42
      for (int v30 = 0; v30 < 32; v30 += 1) {	// L43
        float v31 = v25[0][v30][v28][v29];	// L44
        float v32 = v27[0][v30][0][0];	// L45
        float v33 = v32 + v31;	// L46
        v27[0][v30][0][0] = v33;	// L47
      }
    }
  }
}

void kernel5(
  float v34[1][32][1][1],
  float v35
) {	// L53
  for (int v36 = 0; v36 < 32; v36 += 1) {	// L54
    v34[0][v36][0][0] = v35;	// L55
  }
}

void kernel6(
  float v37[1][32][2][2],
  float v38[1][32][2][2],
  float v39[1][32][2][2],
  float v40
) {	// L59
  for (int v41 = 0; v41 < 32; v41 += 1) {	// L60
    for (int v42 = 0; v42 < 2; v42 += 1) {	// L61
      for (int v43 = 0; v43 < 2; v43 += 1) {	// L62
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v37
        #pragma HLS dependence false variable=v39
        #pragma HLS dependence false variable=v38
        float v44 = v37[0][v41][v42][v43];	// L63
        float v45 = v38[0][v41][v42][v43];	// L64
        float v46 = v40 - v45;	// L65
        float v47 = v40 - v44;	// L66
        float v48 = v47 * v46;	// L67
        float v49 = v40 - v48;	// L68
        v39[0][v41][v42][v43] = v49;	// L69
      }
    }
  }
}

void kernel7(
  float v50[1][32][2][2],
  float v51[1][32][2][2]
) {	// L75
  for (int v52 = 0; v52 < 32; v52 += 1) {	// L76
    for (int v53 = 0; v53 < 2; v53 += 1) {	// L77
      for (int v54 = 0; v54 < 2; v54 += 1) {	// L78
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v50
        #pragma HLS dependence false variable=v51
        float v55 = v50[0][v52][v53][v54];	// L79
        v51[0][v52][v53][v54] = v55;	// L80
      }
    }
  }
}

void kernel8(
  float v56[1][32][2][2],
  float v57[1][32][2][2],
  float v58
) {	// L86
  for (int v59 = 0; v59 < 32; v59 += 1) {	// L87
    for (int v60 = 0; v60 < 2; v60 += 1) {	// L88
      for (int v61 = 0; v61 < 2; v61 += 1) {	// L89
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v57
        #pragma HLS dependence false variable=v56
        float v62 = v57[0][v59][v60][v61];	// L90
        float v63 = v56[0][v59][v60][v61];	// L91
        float v64 = v63 * v58;	// L92
        float v65 = v62 - v63;	// L93
        float v66 = v65 + v64;	// L94
        v57[0][v59][v60][v61] = v66;	// L95
      }
    }
  }
}

void kernel9(
  float v67[1][32][2][2],
  float v68,
  float v69
) {	// L101
  for (int v70 = 0; v70 < 32; v70 += 1) {	// L102
    for (int v71 = 0; v71 < 2; v71 += 1) {	// L103
      for (int v72 = 0; v72 < 2; v72 += 1) {	// L104
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v67
        float v73 = v67[0][v70][v71][v72];	// L105
        float v74 = v73 - v69;	// L106
        bool v75 = v74 >= v68;	// L107
        float v76 = v75 ? v69 : v68;	// L108
        v67[0][v70][v71][v72] = v76;	// L109
      }
    }
  }
}

void kernel11(
  float v77[1][32][2][2],
  float v78[1][32][2][2],
  float v79[1][32][2][2],
  float v80
) {	// L115
  for (int v81 = 0; v81 < 32; v81 += 1) {	// L116
    for (int v82 = 0; v82 < 2; v82 += 1) {	// L117
      for (int v83 = 0; v83 < 2; v83 += 1) {	// L118
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v77
        #pragma HLS dependence false variable=v79
        #pragma HLS dependence false variable=v78
        float v84 = v77[0][v81][v82][v83];	// L119
        float v85 = v78[0][v81][v82][v83];	// L120
        float v86 = v85 / v80;	// L121
        float v87 = v84 / v80;	// L122
        float v88 = v84 - v87;	// L123
        float v89 = v88 + v86;	// L124
        v79[0][v81][v82][v83] = v89;	// L125
      }
    }
  }
}

void kernel12(
  float v90[1][32][4][4],
  float v91[32][32][3][3],
  float v92[1][32][2][2]
) {	// L131
  float v93[32][32][3][3];	// L132
  #pragma HLS resource variable=v93 core=ram_t2p_bram

  memcpy(v93, v91, 9216 * sizeof(float));	// L133

  for (int v94 = 0; v94 < 32; v94 += 1) {	// L134
    for (int v95 = 0; v95 < 3; v95 += 1) {	// L135
      for (int v96 = 0; v96 < 3; v96 += 1) {	// L136
        for (int v97 = 0; v97 < 32; v97 += 1) {	// L137
          for (int v98 = 0; v98 < 2; v98 += 1) {	// L138
            for (int v99 = 0; v99 < 2; v99 += 1) {	// L139
              #pragma HLS pipeline II=1
              #pragma HLS dependence false variable=v90
              #pragma HLS dependence false variable=v92
              #pragma HLS dependence false variable=v93
              float v100 = v90[0][v94][(v98 + v95)][(v99 + v96)];	// L140
              float v101 = v93[v97][v94][v95][v96];	// L141
              float v102 = v92[0][v97][v98][v99];	// L142
              float v103 = v100 * v101;	// L143
              float v104 = v102 + v103;	// L144
              v92[0][v97][v98][v99] = v104;	// L145
            }
          }
        }
      }
    }
  }
}

void kernel13(
  float v105[1][32][2][2],
  float v106[1][32][4][4]
) {	// L154
  for (int v107 = 0; v107 < 32; v107 += 1) {	// L155
    for (int v108 = 0; v108 < 2; v108 += 1) {	// L156
      for (int v109 = 0; v109 < 2; v109 += 1) {	// L157
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v105
        #pragma HLS dependence false variable=v106
        float v110 = v105[0][v107][v108][v109];	// L158
        v106[0][v107][(v108 + 1)][(v109 + 1)] = v110;	// L159
      }
    }
  }
}

void kernel14(
  float v111[1][32][4][4],
  float v112
) {	// L165
  for (int v113 = 0; v113 < 32; v113 += 1) {	// L166
    for (int v114 = 0; v114 < 4; v114 += 1) {	// L167
      for (int v115 = 0; v115 < 4; v115 += 1) {	// L168
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v111
        v111[0][v113][v114][v115] = v112;	// L169
      }
    }
  }
}

void kernel22(
  float v116[32],
  float v117[1][32][2][2]
) {	// L175
  float v118[32];	// L176
  #pragma HLS resource variable=v118 core=ram_t2p_bram

  memcpy(v118, v116, 32 * sizeof(float));	// L177

  for (int v119 = 0; v119 < 32; v119 += 1) {	// L178
    for (int v120 = 0; v120 < 2; v120 += 1) {	// L179
      for (int v121 = 0; v121 < 2; v121 += 1) {	// L180
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v118
        #pragma HLS dependence false variable=v117
        float v122 = v118[v119];	// L181
        v117[0][v119][v120][v121] = v122;	// L182
      }
    }
  }
}

void kernel24(
  float v123[1][32][4][4],
  float v124
) {	// L188
  for (int v125 = 0; v125 < 32; v125 += 1) {	// L189
    for (int v126 = 0; v126 < 4; v126 += 1) {	// L190
      for (int v127 = 0; v127 < 4; v127 += 1) {	// L191
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v123
        v123[0][v125][v126][v127] = v124;	// L192
      }
    }
  }
}

void kernel25(
  float v128[1][32][2][2],
  float v129
) {	// L198
  for (int v130 = 0; v130 < 32; v130 += 1) {	// L199
    for (int v131 = 0; v131 < 2; v131 += 1) {	// L200
      for (int v132 = 0; v132 < 2; v132 += 1) {	// L201
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v128
        float v133 = v128[0][v130][v131][v132];	// L202
        float v134 = v133 / v129;	// L203
        v128[0][v130][v131][v132] = v134;	// L204
      }
    }
  }
}

void kernel26(
  float v135[1][32][4][4],
  float v136[2][2],
  float v137[1][32][2][2]
) {	// L210
  for (int v138 = 0; v138 < 2; v138 += 1) {	// L211
    for (int v139 = 0; v139 < 2; v139 += 1) {	// L212
      for (int v140 = 0; v140 < 32; v140 += 1) {	// L213
        for (int v141 = 0; v141 < 2; v141 += 1) {	// L214
          for (int v142 = 0; v142 < 2; v142 += 1) {	// L215
            #pragma HLS pipeline II=1
            #pragma HLS dependence false variable=v135
            #pragma HLS dependence false variable=v137
            float v143 = v135[0][v140][((v141 * 2) + v138)][((v142 * 2) + v139)];	// L216
            float v144 = v137[0][v140][v141][v142];	// L217
            float v145 = v144 + v143;	// L218
            v137[0][v140][v141][v142] = v145;	// L219
          }
        }
      }
    }
  }
}

void kernel27(
  float v146[1][32][2][2],
  float v147
) {	// L227
  for (int v148 = 0; v148 < 32; v148 += 1) {	// L228
    for (int v149 = 0; v149 < 2; v149 += 1) {	// L229
      for (int v150 = 0; v150 < 2; v150 += 1) {	// L230
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v146
        v146[0][v148][v149][v150] = v147;	// L231
      }
    }
  }
}

void kernel28(
  float v151[1][32][4][4],
  float v152[1][32][4][4],
  float v153[1][32][4][4],
  float v154
) {	// L237
  for (int v155 = 0; v155 < 32; v155 += 1) {	// L238
    for (int v156 = 0; v156 < 4; v156 += 1) {	// L239
      for (int v157 = 0; v157 < 4; v157 += 1) {	// L240
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v151
        #pragma HLS dependence false variable=v153
        #pragma HLS dependence false variable=v152
        float v158 = v151[0][v155][v156][v157];	// L241
        float v159 = v152[0][v155][v156][v157];	// L242
        float v160 = v154 - v159;	// L243
        float v161 = v154 - v158;	// L244
        float v162 = v161 * v160;	// L245
        float v163 = v154 - v162;	// L246
        v153[0][v155][v156][v157] = v163;	// L247
      }
    }
  }
}

void kernel29(
  float v164[1][32][4][4],
  float v165[1][32][4][4]
) {	// L253
  for (int v166 = 0; v166 < 32; v166 += 1) {	// L254
    for (int v167 = 0; v167 < 4; v167 += 1) {	// L255
      for (int v168 = 0; v168 < 4; v168 += 1) {	// L256
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v164
        #pragma HLS dependence false variable=v165
        float v169 = v164[0][v166][v167][v168];	// L257
        v165[0][v166][v167][v168] = v169;	// L258
      }
    }
  }
}

void kernel30(
  float v170[1][32][4][4],
  float v171[1][32][4][4],
  float v172
) {	// L264
  for (int v173 = 0; v173 < 32; v173 += 1) {	// L265
    for (int v174 = 0; v174 < 4; v174 += 1) {	// L266
      for (int v175 = 0; v175 < 4; v175 += 1) {	// L267
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v171
        #pragma HLS dependence false variable=v170
        float v176 = v171[0][v173][v174][v175];	// L268
        float v177 = v170[0][v173][v174][v175];	// L269
        float v178 = v177 * v172;	// L270
        float v179 = v176 - v177;	// L271
        float v180 = v179 + v178;	// L272
        v171[0][v173][v174][v175] = v180;	// L273
      }
    }
  }
}

void kernel31(
  float v181[1][32][4][4],
  float v182,
  float v183
) {	// L279
  for (int v184 = 0; v184 < 32; v184 += 1) {	// L280
    for (int v185 = 0; v185 < 4; v185 += 1) {	// L281
      for (int v186 = 0; v186 < 4; v186 += 1) {	// L282
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v181
        float v187 = v181[0][v184][v185][v186];	// L283
        float v188 = v187 - v183;	// L284
        bool v189 = v188 >= v182;	// L285
        float v190 = v189 ? v183 : v182;	// L286
        v181[0][v184][v185][v186] = v190;	// L287
      }
    }
  }
}

void kernel33(
  float v191[1][32][4][4],
  float v192[1][32][4][4],
  float v193[1][32][4][4],
  float v194
) {	// L293
  for (int v195 = 0; v195 < 32; v195 += 1) {	// L294
    for (int v196 = 0; v196 < 4; v196 += 1) {	// L295
      for (int v197 = 0; v197 < 4; v197 += 1) {	// L296
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v191
        #pragma HLS dependence false variable=v193
        #pragma HLS dependence false variable=v192
        float v198 = v191[0][v195][v196][v197];	// L297
        float v199 = v192[0][v195][v196][v197];	// L298
        float v200 = v199 / v194;	// L299
        float v201 = v198 / v194;	// L300
        float v202 = v198 - v201;	// L301
        float v203 = v202 + v200;	// L302
        v193[0][v195][v196][v197] = v203;	// L303
      }
    }
  }
}

void kernel34(
  float v204[1][32][6][6],
  float v205[32][32][3][3],
  float v206[1][32][4][4]
) {	// L309
  float v207[32][32][3][3];	// L310
  #pragma HLS resource variable=v207 core=ram_t2p_bram

  memcpy(v207, v205, 9216 * sizeof(float));	// L311

  for (int v208 = 0; v208 < 32; v208 += 1) {	// L312
    for (int v209 = 0; v209 < 3; v209 += 1) {	// L313
      for (int v210 = 0; v210 < 3; v210 += 1) {	// L314
        for (int v211 = 0; v211 < 32; v211 += 1) {	// L315
          for (int v212 = 0; v212 < 4; v212 += 1) {	// L316
            for (int v213 = 0; v213 < 4; v213 += 1) {	// L317
              #pragma HLS pipeline II=1
              #pragma HLS dependence false variable=v204
              #pragma HLS dependence false variable=v206
              #pragma HLS dependence false variable=v207
              float v214 = v204[0][v208][(v212 + v209)][(v213 + v210)];	// L318
              float v215 = v207[v211][v208][v209][v210];	// L319
              float v216 = v206[0][v211][v212][v213];	// L320
              float v217 = v214 * v215;	// L321
              float v218 = v216 + v217;	// L322
              v206[0][v211][v212][v213] = v218;	// L323
            }
          }
        }
      }
    }
  }
}

void kernel35(
  float v219[1][32][4][4],
  float v220[1][32][6][6]
) {	// L332
  for (int v221 = 0; v221 < 32; v221 += 1) {	// L333
    for (int v222 = 0; v222 < 4; v222 += 1) {	// L334
      for (int v223 = 0; v223 < 4; v223 += 1) {	// L335
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v219
        #pragma HLS dependence false variable=v220
        float v224 = v219[0][v221][v222][v223];	// L336
        v220[0][v221][(v222 + 1)][(v223 + 1)] = v224;	// L337
      }
    }
  }
}

void kernel36(
  float v225[1][32][6][6],
  float v226
) {	// L343
  for (int v227 = 0; v227 < 32; v227 += 1) {	// L344
    for (int v228 = 0; v228 < 6; v228 += 1) {	// L345
      for (int v229 = 0; v229 < 6; v229 += 1) {	// L346
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v225
        v225[0][v227][v228][v229] = v226;	// L347
      }
    }
  }
}

void kernel44(
  float v230[32],
  float v231[1][32][4][4]
) {	// L353
  float v232[32];	// L354
  #pragma HLS resource variable=v232 core=ram_t2p_bram

  memcpy(v232, v230, 32 * sizeof(float));	// L355

  for (int v233 = 0; v233 < 32; v233 += 1) {	// L356
    for (int v234 = 0; v234 < 4; v234 += 1) {	// L357
      for (int v235 = 0; v235 < 4; v235 += 1) {	// L358
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v232
        #pragma HLS dependence false variable=v231
        float v236 = v232[v233];	// L359
        v231[0][v233][v234][v235] = v236;	// L360
      }
    }
  }
}

void kernel46(
  float v237[1][32][6][6],
  float v238
) {	// L366
  for (int v239 = 0; v239 < 32; v239 += 1) {	// L367
    for (int v240 = 0; v240 < 6; v240 += 1) {	// L368
      for (int v241 = 0; v241 < 6; v241 += 1) {	// L369
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v237
        v237[0][v239][v240][v241] = v238;	// L370
      }
    }
  }
}

void kernel47(
  float v242[1][32][4][4],
  float v243[1][32][4][4],
  float v244[1][32][4][4],
  float v245,
  float v246,
  float v247,
  float v248,
  float v249
) {	// L376
  for (int v250 = 0; v250 < 32; v250 += 1) {	// L377
    for (int v251 = 0; v251 < 4; v251 += 1) {	// L378
      for (int v252 = 0; v252 < 4; v252 += 1) {	// L379
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v243
        #pragma HLS dependence false variable=v242
        #pragma HLS dependence false variable=v244
        float v253 = v242[0][v250][v251][v252];	// L380
        float v254 = v244[0][v250][v251][v252];	// L381
        float v255 = v243[0][v250][v251][v252];	// L382
        float v256 = v255 / v249;	// L383
        float v257 = v256 * v247;	// L384
        float v258 = v254 / v249;	// L385
        float v259 = v258 * v246;	// L386
        float v260 = v253 / v248;	// L387
        float v261 = v260 * v245;	// L388
        float v262 = v261 + v259;	// L389
        float v263 = v262 + v257;	// L390
        v244[0][v250][v251][v252] = v263;	// L391
      }
    }
  }
}

void kernel48(
  float v264[1][32][8][8],
  float v265[2][2],
  float v266[1][32][4][4]
) {	// L397
  for (int v267 = 0; v267 < 2; v267 += 1) {	// L398
    for (int v268 = 0; v268 < 2; v268 += 1) {	// L399
      for (int v269 = 0; v269 < 32; v269 += 1) {	// L400
        for (int v270 = 0; v270 < 4; v270 += 1) {	// L401
          for (int v271 = 0; v271 < 4; v271 += 1) {	// L402
            #pragma HLS pipeline II=1
            #pragma HLS dependence false variable=v264
            #pragma HLS dependence false variable=v266
            float v272 = v264[0][v269][((v270 * 2) + v267)][((v271 * 2) + v268)];	// L403
            float v273 = v266[0][v269][v270][v271];	// L404
            float v274 = v273 + v272;	// L405
            v266[0][v269][v270][v271] = v274;	// L406
          }
        }
      }
    }
  }
}

void kernel49(
  float v275[1][32][16][16],
  float v276[4][4],
  float v277[1][32][4][4]
) {	// L414
  for (int v278 = 0; v278 < 4; v278 += 1) {	// L415
    for (int v279 = 0; v279 < 4; v279 += 1) {	// L416
      for (int v280 = 0; v280 < 32; v280 += 1) {	// L417
        for (int v281 = 0; v281 < 4; v281 += 1) {	// L418
          for (int v282 = 0; v282 < 4; v282 += 1) {	// L419
            #pragma HLS pipeline II=1
            #pragma HLS dependence false variable=v275
            #pragma HLS dependence false variable=v277
            float v283 = v275[0][v280][((v281 * 4) + v278)][((v282 * 4) + v279)];	// L420
            float v284 = v277[0][v280][v281][v282];	// L421
            float v285 = v284 + v283;	// L422
            v277[0][v280][v281][v282] = v285;	// L423
          }
        }
      }
    }
  }
}

void kernel53(
  float v286[1][32][4][4],
  float v287
) {	// L431
  for (int v288 = 0; v288 < 32; v288 += 1) {	// L432
    for (int v289 = 0; v289 < 4; v289 += 1) {	// L433
      for (int v290 = 0; v290 < 4; v290 += 1) {	// L434
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v286
        v286[0][v288][v289][v290] = v287;	// L435
      }
    }
  }
}

void kernel54(
  float v291[1][32][8][8],
  float v292[1][32][8][8],
  float v293[1][32][8][8],
  float v294
) {	// L441
  for (int v295 = 0; v295 < 32; v295 += 1) {	// L442
    for (int v296 = 0; v296 < 8; v296 += 1) {	// L443
      for (int v297 = 0; v297 < 8; v297 += 1) {	// L444
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v291
        #pragma HLS dependence false variable=v293
        #pragma HLS dependence false variable=v292
        float v298 = v291[0][v295][v296][v297];	// L445
        float v299 = v292[0][v295][v296][v297];	// L446
        float v300 = v294 - v299;	// L447
        float v301 = v294 - v298;	// L448
        float v302 = v301 * v300;	// L449
        float v303 = v294 - v302;	// L450
        v293[0][v295][v296][v297] = v303;	// L451
      }
    }
  }
}

void kernel55(
  float v304[1][32][8][8],
  float v305[1][32][8][8]
) {	// L457
  for (int v306 = 0; v306 < 32; v306 += 1) {	// L458
    for (int v307 = 0; v307 < 8; v307 += 1) {	// L459
      for (int v308 = 0; v308 < 8; v308 += 1) {	// L460
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v304
        #pragma HLS dependence false variable=v305
        float v309 = v304[0][v306][v307][v308];	// L461
        v305[0][v306][v307][v308] = v309;	// L462
      }
    }
  }
}

void kernel56(
  float v310[1][32][8][8],
  float v311[1][32][8][8],
  float v312
) {	// L468
  for (int v313 = 0; v313 < 32; v313 += 1) {	// L469
    for (int v314 = 0; v314 < 8; v314 += 1) {	// L470
      for (int v315 = 0; v315 < 8; v315 += 1) {	// L471
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v311
        #pragma HLS dependence false variable=v310
        float v316 = v311[0][v313][v314][v315];	// L472
        float v317 = v310[0][v313][v314][v315];	// L473
        float v318 = v317 * v312;	// L474
        float v319 = v316 - v317;	// L475
        float v320 = v319 + v318;	// L476
        v311[0][v313][v314][v315] = v320;	// L477
      }
    }
  }
}

void kernel57(
  float v321[1][32][8][8],
  float v322,
  float v323
) {	// L483
  for (int v324 = 0; v324 < 32; v324 += 1) {	// L484
    for (int v325 = 0; v325 < 8; v325 += 1) {	// L485
      for (int v326 = 0; v326 < 8; v326 += 1) {	// L486
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v321
        float v327 = v321[0][v324][v325][v326];	// L487
        float v328 = v327 - v323;	// L488
        bool v329 = v328 >= v322;	// L489
        float v330 = v329 ? v323 : v322;	// L490
        v321[0][v324][v325][v326] = v330;	// L491
      }
    }
  }
}

void kernel59(
  float v331[1][32][8][8],
  float v332[1][32][8][8],
  float v333[1][32][8][8],
  float v334
) {	// L497
  for (int v335 = 0; v335 < 32; v335 += 1) {	// L498
    for (int v336 = 0; v336 < 8; v336 += 1) {	// L499
      for (int v337 = 0; v337 < 8; v337 += 1) {	// L500
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v331
        #pragma HLS dependence false variable=v333
        #pragma HLS dependence false variable=v332
        float v338 = v331[0][v335][v336][v337];	// L501
        float v339 = v332[0][v335][v336][v337];	// L502
        float v340 = v339 / v334;	// L503
        float v341 = v338 / v334;	// L504
        float v342 = v338 - v341;	// L505
        float v343 = v342 + v340;	// L506
        v333[0][v335][v336][v337] = v343;	// L507
      }
    }
  }
}

void kernel60(
  float v344[1][32][10][10],
  float v345[32][32][3][3],
  float v346[1][32][8][8]
) {	// L513
  float v347[32][32][3][3];	// L514
  #pragma HLS resource variable=v347 core=ram_t2p_bram

  memcpy(v347, v345, 9216 * sizeof(float));	// L515

  for (int v348 = 0; v348 < 32; v348 += 1) {	// L516
    for (int v349 = 0; v349 < 3; v349 += 1) {	// L517
      for (int v350 = 0; v350 < 3; v350 += 1) {	// L518
        for (int v351 = 0; v351 < 32; v351 += 1) {	// L519
          for (int v352 = 0; v352 < 8; v352 += 1) {	// L520
            for (int v353 = 0; v353 < 8; v353 += 1) {	// L521
              #pragma HLS pipeline II=1
              #pragma HLS dependence false variable=v344
              #pragma HLS dependence false variable=v346
              #pragma HLS dependence false variable=v347
              float v354 = v344[0][v348][(v352 + v349)][(v353 + v350)];	// L522
              float v355 = v347[v351][v348][v349][v350];	// L523
              float v356 = v346[0][v351][v352][v353];	// L524
              float v357 = v354 * v355;	// L525
              float v358 = v356 + v357;	// L526
              v346[0][v351][v352][v353] = v358;	// L527
            }
          }
        }
      }
    }
  }
}

void kernel61(
  float v359[1][32][8][8],
  float v360[1][32][10][10]
) {	// L536
  for (int v361 = 0; v361 < 32; v361 += 1) {	// L537
    for (int v362 = 0; v362 < 8; v362 += 1) {	// L538
      for (int v363 = 0; v363 < 8; v363 += 1) {	// L539
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v359
        #pragma HLS dependence false variable=v360
        float v364 = v359[0][v361][v362][v363];	// L540
        v360[0][v361][(v362 + 1)][(v363 + 1)] = v364;	// L541
      }
    }
  }
}

void kernel62(
  float v365[1][32][10][10],
  float v366
) {	// L547
  for (int v367 = 0; v367 < 32; v367 += 1) {	// L548
    for (int v368 = 0; v368 < 10; v368 += 1) {	// L549
      for (int v369 = 0; v369 < 10; v369 += 1) {	// L550
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v365
        v365[0][v367][v368][v369] = v366;	// L551
      }
    }
  }
}

void kernel70(
  float v370[32],
  float v371[1][32][8][8]
) {	// L557
  float v372[32];	// L558
  #pragma HLS resource variable=v372 core=ram_t2p_bram

  memcpy(v372, v370, 32 * sizeof(float));	// L559

  for (int v373 = 0; v373 < 32; v373 += 1) {	// L560
    for (int v374 = 0; v374 < 8; v374 += 1) {	// L561
      for (int v375 = 0; v375 < 8; v375 += 1) {	// L562
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v372
        #pragma HLS dependence false variable=v371
        float v376 = v372[v373];	// L563
        v371[0][v373][v374][v375] = v376;	// L564
      }
    }
  }
}

void kernel72(
  float v377[1][32][10][10],
  float v378
) {	// L570
  for (int v379 = 0; v379 < 32; v379 += 1) {	// L571
    for (int v380 = 0; v380 < 10; v380 += 1) {	// L572
      for (int v381 = 0; v381 < 10; v381 += 1) {	// L573
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v377
        v377[0][v379][v380][v381] = v378;	// L574
      }
    }
  }
}

void kernel73(
  float v382[1][32][8][8],
  float v383
) {	// L580
  for (int v384 = 0; v384 < 32; v384 += 1) {	// L581
    for (int v385 = 0; v385 < 8; v385 += 1) {	// L582
      for (int v386 = 0; v386 < 8; v386 += 1) {	// L583
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v382
        float v387 = v382[0][v384][v385][v386];	// L584
        float v388 = v387 / v383;	// L585
        v382[0][v384][v385][v386] = v388;	// L586
      }
    }
  }
}

void kernel75(
  float v389[1][32][16][16],
  float v390[2][2],
  float v391[1][32][8][8]
) {	// L592
  for (int v392 = 0; v392 < 2; v392 += 1) {	// L593
    for (int v393 = 0; v393 < 2; v393 += 1) {	// L594
      for (int v394 = 0; v394 < 32; v394 += 1) {	// L595
        for (int v395 = 0; v395 < 8; v395 += 1) {	// L596
          for (int v396 = 0; v396 < 8; v396 += 1) {	// L597
            #pragma HLS pipeline II=1
            #pragma HLS dependence false variable=v389
            #pragma HLS dependence false variable=v391
            float v397 = v389[0][v394][((v395 * 2) + v392)][((v396 * 2) + v393)];	// L598
            float v398 = v391[0][v394][v395][v396];	// L599
            float v399 = v398 + v397;	// L600
            v391[0][v394][v395][v396] = v399;	// L601
          }
        }
      }
    }
  }
}

void kernel76(
  float v400[1][32][8][8],
  float v401
) {	// L609
  for (int v402 = 0; v402 < 32; v402 += 1) {	// L610
    for (int v403 = 0; v403 < 8; v403 += 1) {	// L611
      for (int v404 = 0; v404 < 8; v404 += 1) {	// L612
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v400
        v400[0][v402][v403][v404] = v401;	// L613
      }
    }
  }
}

void kernel77(
  float v405[1][32][16][16],
  float v406[1][32][16][16],
  float v407[1][32][16][16],
  float v408
) {	// L619
  for (int v409 = 0; v409 < 32; v409 += 1) {	// L620
    for (int v410 = 0; v410 < 16; v410 += 1) {	// L621
      for (int v411 = 0; v411 < 16; v411 += 1) {	// L622
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v405
        #pragma HLS dependence false variable=v407
        #pragma HLS dependence false variable=v406
        float v412 = v405[0][v409][v410][v411];	// L623
        float v413 = v406[0][v409][v410][v411];	// L624
        float v414 = v408 - v413;	// L625
        float v415 = v408 - v412;	// L626
        float v416 = v415 * v414;	// L627
        float v417 = v408 - v416;	// L628
        v407[0][v409][v410][v411] = v417;	// L629
      }
    }
  }
}

void kernel78(
  float v418[1][32][16][16],
  float v419[1][32][16][16]
) {	// L635
  for (int v420 = 0; v420 < 32; v420 += 1) {	// L636
    for (int v421 = 0; v421 < 16; v421 += 1) {	// L637
      for (int v422 = 0; v422 < 16; v422 += 1) {	// L638
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v418
        #pragma HLS dependence false variable=v419
        float v423 = v418[0][v420][v421][v422];	// L639
        v419[0][v420][v421][v422] = v423;	// L640
      }
    }
  }
}

void kernel79(
  float v424[1][32][16][16],
  float v425[1][32][16][16],
  float v426
) {	// L646
  for (int v427 = 0; v427 < 32; v427 += 1) {	// L647
    for (int v428 = 0; v428 < 16; v428 += 1) {	// L648
      for (int v429 = 0; v429 < 16; v429 += 1) {	// L649
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v425
        #pragma HLS dependence false variable=v424
        float v430 = v425[0][v427][v428][v429];	// L650
        float v431 = v424[0][v427][v428][v429];	// L651
        float v432 = v431 * v426;	// L652
        float v433 = v430 - v431;	// L653
        float v434 = v433 + v432;	// L654
        v425[0][v427][v428][v429] = v434;	// L655
      }
    }
  }
}

void kernel80(
  float v435[1][32][16][16],
  float v436,
  float v437
) {	// L661
  for (int v438 = 0; v438 < 32; v438 += 1) {	// L662
    for (int v439 = 0; v439 < 16; v439 += 1) {	// L663
      for (int v440 = 0; v440 < 16; v440 += 1) {	// L664
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v435
        float v441 = v435[0][v438][v439][v440];	// L665
        float v442 = v441 - v437;	// L666
        bool v443 = v442 >= v436;	// L667
        float v444 = v443 ? v437 : v436;	// L668
        v435[0][v438][v439][v440] = v444;	// L669
      }
    }
  }
}

void kernel82(
  float v445[1][32][16][16],
  float v446[1][32][16][16],
  float v447[1][32][16][16],
  float v448
) {	// L675
  for (int v449 = 0; v449 < 32; v449 += 1) {	// L676
    for (int v450 = 0; v450 < 16; v450 += 1) {	// L677
      for (int v451 = 0; v451 < 16; v451 += 1) {	// L678
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v445
        #pragma HLS dependence false variable=v447
        #pragma HLS dependence false variable=v446
        float v452 = v445[0][v449][v450][v451];	// L679
        float v453 = v446[0][v449][v450][v451];	// L680
        float v454 = v453 / v448;	// L681
        float v455 = v452 / v448;	// L682
        float v456 = v452 - v455;	// L683
        float v457 = v456 + v454;	// L684
        v447[0][v449][v450][v451] = v457;	// L685
      }
    }
  }
}

void kernel83(
  float v458[1][32][18][18],
  float v459[32][32][3][3],
  float v460[1][32][16][16]
) {	// L691
  float v461[32][32][3][3];	// L692
  #pragma HLS resource variable=v461 core=ram_t2p_bram

  memcpy(v461, v459, 9216 * sizeof(float));	// L693

  for (int v462 = 0; v462 < 32; v462 += 1) {	// L694
    for (int v463 = 0; v463 < 3; v463 += 1) {	// L695
      for (int v464 = 0; v464 < 3; v464 += 1) {	// L696
        for (int v465 = 0; v465 < 32; v465 += 1) {	// L697
          for (int v466 = 0; v466 < 16; v466 += 1) {	// L698
            for (int v467 = 0; v467 < 16; v467 += 1) {	// L699
              #pragma HLS pipeline II=1
              #pragma HLS dependence false variable=v458
              #pragma HLS dependence false variable=v460
              #pragma HLS dependence false variable=v461
              float v468 = v458[0][v462][(v466 + v463)][(v467 + v464)];	// L700
              float v469 = v461[v465][v462][v463][v464];	// L701
              float v470 = v460[0][v465][v466][v467];	// L702
              float v471 = v468 * v469;	// L703
              float v472 = v470 + v471;	// L704
              v460[0][v465][v466][v467] = v472;	// L705
            }
          }
        }
      }
    }
  }
}

void kernel84(
  float v473[1][32][16][16],
  float v474[1][32][18][18]
) {	// L714
  for (int v475 = 0; v475 < 32; v475 += 1) {	// L715
    for (int v476 = 0; v476 < 16; v476 += 1) {	// L716
      for (int v477 = 0; v477 < 16; v477 += 1) {	// L717
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v473
        #pragma HLS dependence false variable=v474
        float v478 = v473[0][v475][v476][v477];	// L718
        v474[0][v475][(v476 + 1)][(v477 + 1)] = v478;	// L719
      }
    }
  }
}

void kernel85(
  float v479[1][32][18][18],
  float v480
) {	// L725
  for (int v481 = 0; v481 < 32; v481 += 1) {	// L726
    for (int v482 = 0; v482 < 18; v482 += 1) {	// L727
      for (int v483 = 0; v483 < 18; v483 += 1) {	// L728
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v479
        v479[0][v481][v482][v483] = v480;	// L729
      }
    }
  }
}

void kernel93(
  float v484[32],
  float v485[1][32][16][16]
) {	// L735
  float v486[32];	// L736
  #pragma HLS resource variable=v486 core=ram_t2p_bram

  memcpy(v486, v484, 32 * sizeof(float));	// L737

  for (int v487 = 0; v487 < 32; v487 += 1) {	// L738
    for (int v488 = 0; v488 < 16; v488 += 1) {	// L739
      for (int v489 = 0; v489 < 16; v489 += 1) {	// L740
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v486
        #pragma HLS dependence false variable=v485
        float v490 = v486[v487];	// L741
        v485[0][v487][v488][v489] = v490;	// L742
      }
    }
  }
}

void kernel95(
  float v491[1][32][18][18],
  float v492
) {	// L748
  for (int v493 = 0; v493 < 32; v493 += 1) {	// L749
    for (int v494 = 0; v494 < 18; v494 += 1) {	// L750
      for (int v495 = 0; v495 < 18; v495 += 1) {	// L751
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v491
        v491[0][v493][v494][v495] = v492;	// L752
      }
    }
  }
}

void kernel96(
  float v496[1][32][16][16],
  float v497[1][32][16][16],
  float v498,
  float v499,
  float v500
) {	// L758
  for (int v501 = 0; v501 < 32; v501 += 1) {	// L759
    for (int v502 = 0; v502 < 16; v502 += 1) {	// L760
      for (int v503 = 0; v503 < 16; v503 += 1) {	// L761
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v497
        #pragma HLS dependence false variable=v496
        float v504 = v497[0][v501][v502][v503];	// L762
        float v505 = v496[0][v501][v502][v503];	// L763
        float v506 = v505 * v499;	// L764
        float v507 = v504 / v500;	// L765
        float v508 = v507 * v498;	// L766
        float v509 = v508 + v506;	// L767
        v497[0][v501][v502][v503] = v509;	// L768
      }
    }
  }
}

void kernel97(
  float v510[1][32][32][32],
  float v511[2][2],
  float v512[1][32][16][16]
) {	// L774
  for (int v513 = 0; v513 < 2; v513 += 1) {	// L775
    for (int v514 = 0; v514 < 2; v514 += 1) {	// L776
      for (int v515 = 0; v515 < 32; v515 += 1) {	// L777
        for (int v516 = 0; v516 < 16; v516 += 1) {	// L778
          for (int v517 = 0; v517 < 16; v517 += 1) {	// L779
            #pragma HLS pipeline II=1
            #pragma HLS dependence false variable=v510
            #pragma HLS dependence false variable=v512
            float v518 = v510[0][v515][((v516 * 2) + v513)][((v517 * 2) + v514)];	// L780
            float v519 = v512[0][v515][v516][v517];	// L781
            float v520 = v519 + v518;	// L782
            v512[0][v515][v516][v517] = v520;	// L783
          }
        }
      }
    }
  }
}

void kernel98(
  float v521[1][32][16][16],
  float v522
) {	// L791
  for (int v523 = 0; v523 < 32; v523 += 1) {	// L792
    for (int v524 = 0; v524 < 16; v524 += 1) {	// L793
      for (int v525 = 0; v525 < 16; v525 += 1) {	// L794
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v521
        float v526 = v521[0][v523][v524][v525];	// L795
        float v527 = v526 / v522;	// L796
        v521[0][v523][v524][v525] = v527;	// L797
      }
    }
  }
}

void kernel101(
  float v528[1][32][16][16],
  float v529
) {	// L803
  for (int v530 = 0; v530 < 32; v530 += 1) {	// L804
    for (int v531 = 0; v531 < 16; v531 += 1) {	// L805
      for (int v532 = 0; v532 < 16; v532 += 1) {	// L806
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v528
        v528[0][v530][v531][v532] = v529;	// L807
      }
    }
  }
}

void kernel102(
  float v533[1][32][32][32],
  float v534[1][32][32][32],
  float v535[1][32][32][32],
  float v536
) {	// L813
  for (int v537 = 0; v537 < 32; v537 += 1) {	// L814
    for (int v538 = 0; v538 < 32; v538 += 1) {	// L815
      for (int v539 = 0; v539 < 32; v539 += 1) {	// L816
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v533
        #pragma HLS dependence false variable=v535
        #pragma HLS dependence false variable=v534
        float v540 = v533[0][v537][v538][v539];	// L817
        float v541 = v534[0][v537][v538][v539];	// L818
        float v542 = v536 - v541;	// L819
        float v543 = v536 - v540;	// L820
        float v544 = v543 * v542;	// L821
        float v545 = v536 - v544;	// L822
        v535[0][v537][v538][v539] = v545;	// L823
      }
    }
  }
}

void kernel103(
  float v546[1][32][32][32],
  float v547[1][32][32][32]
) {	// L829
  for (int v548 = 0; v548 < 32; v548 += 1) {	// L830
    for (int v549 = 0; v549 < 32; v549 += 1) {	// L831
      for (int v550 = 0; v550 < 32; v550 += 1) {	// L832
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v546
        #pragma HLS dependence false variable=v547
        float v551 = v546[0][v548][v549][v550];	// L833
        v547[0][v548][v549][v550] = v551;	// L834
      }
    }
  }
}

void kernel104(
  float v552[1][32][32][32],
  float v553[1][32][32][32],
  float v554
) {	// L840
  for (int v555 = 0; v555 < 32; v555 += 1) {	// L841
    for (int v556 = 0; v556 < 32; v556 += 1) {	// L842
      for (int v557 = 0; v557 < 32; v557 += 1) {	// L843
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v553
        #pragma HLS dependence false variable=v552
        float v558 = v553[0][v555][v556][v557];	// L844
        float v559 = v552[0][v555][v556][v557];	// L845
        float v560 = v559 * v554;	// L846
        float v561 = v558 - v559;	// L847
        float v562 = v561 + v560;	// L848
        v553[0][v555][v556][v557] = v562;	// L849
      }
    }
  }
}

void kernel105(
  float v563[1][32][32][32],
  float v564,
  float v565
) {	// L855
  for (int v566 = 0; v566 < 32; v566 += 1) {	// L856
    for (int v567 = 0; v567 < 32; v567 += 1) {	// L857
      for (int v568 = 0; v568 < 32; v568 += 1) {	// L858
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v563
        float v569 = v563[0][v566][v567][v568];	// L859
        float v570 = v569 - v565;	// L860
        bool v571 = v570 >= v564;	// L861
        float v572 = v571 ? v565 : v564;	// L862
        v563[0][v566][v567][v568] = v572;	// L863
      }
    }
  }
}

void kernel107(
  float v573[1][32][32][32],
  float v574[1][32][32][32],
  float v575[1][32][32][32],
  float v576
) {	// L869
  for (int v577 = 0; v577 < 32; v577 += 1) {	// L870
    for (int v578 = 0; v578 < 32; v578 += 1) {	// L871
      for (int v579 = 0; v579 < 32; v579 += 1) {	// L872
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v573
        #pragma HLS dependence false variable=v575
        #pragma HLS dependence false variable=v574
        float v580 = v573[0][v577][v578][v579];	// L873
        float v581 = v574[0][v577][v578][v579];	// L874
        float v582 = v581 / v576;	// L875
        float v583 = v580 / v576;	// L876
        float v584 = v580 - v583;	// L877
        float v585 = v584 + v582;	// L878
        v575[0][v577][v578][v579] = v585;	// L879
      }
    }
  }
}

void kernel108(
  float v586[1][32][34][34],
  float v587[32][32][3][3],
  float v588[1][32][32][32]
) {	// L885
  float v589[32][32][3][3];	// L886
  #pragma HLS resource variable=v589 core=ram_t2p_bram

  memcpy(v589, v587, 9216 * sizeof(float));	// L887

  for (int v590 = 0; v590 < 32; v590 += 1) {	// L888
    for (int v591 = 0; v591 < 3; v591 += 1) {	// L889
      for (int v592 = 0; v592 < 3; v592 += 1) {	// L890
        for (int v593 = 0; v593 < 32; v593 += 1) {	// L891
          for (int v594 = 0; v594 < 32; v594 += 1) {	// L892
            for (int v595 = 0; v595 < 32; v595 += 1) {	// L893
              #pragma HLS pipeline II=1
              #pragma HLS dependence false variable=v586
              #pragma HLS dependence false variable=v588
              #pragma HLS dependence false variable=v589
              float v596 = v586[0][v590][(v594 + v591)][(v595 + v592)];	// L894
              float v597 = v589[v593][v590][v591][v592];	// L895
              float v598 = v588[0][v593][v594][v595];	// L896
              float v599 = v596 * v597;	// L897
              float v600 = v598 + v599;	// L898
              v588[0][v593][v594][v595] = v600;	// L899
            }
          }
        }
      }
    }
  }
}

void kernel109(
  float v601[1][32][32][32],
  float v602[1][32][34][34]
) {	// L908
  for (int v603 = 0; v603 < 32; v603 += 1) {	// L909
    for (int v604 = 0; v604 < 32; v604 += 1) {	// L910
      for (int v605 = 0; v605 < 32; v605 += 1) {	// L911
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v601
        #pragma HLS dependence false variable=v602
        float v606 = v601[0][v603][v604][v605];	// L912
        v602[0][v603][(v604 + 1)][(v605 + 1)] = v606;	// L913
      }
    }
  }
}

void kernel110(
  float v607[1][32][34][34],
  float v608
) {	// L919
  for (int v609 = 0; v609 < 32; v609 += 1) {	// L920
    for (int v610 = 0; v610 < 34; v610 += 1) {	// L921
      for (int v611 = 0; v611 < 34; v611 += 1) {	// L922
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v607
        v607[0][v609][v610][v611] = v608;	// L923
      }
    }
  }
}

void kernel118(
  float v612[32],
  float v613[1][32][32][32]
) {	// L929
  float v614[32];	// L930
  #pragma HLS resource variable=v614 core=ram_t2p_bram

  memcpy(v614, v612, 32 * sizeof(float));	// L931

  for (int v615 = 0; v615 < 32; v615 += 1) {	// L932
    for (int v616 = 0; v616 < 32; v616 += 1) {	// L933
      for (int v617 = 0; v617 < 32; v617 += 1) {	// L934
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v614
        #pragma HLS dependence false variable=v613
        float v618 = v614[v615];	// L935
        v613[0][v615][v616][v617] = v618;	// L936
      }
    }
  }
}

void kernel120(
  float v619[1][32][34][34],
  float v620
) {	// L942
  for (int v621 = 0; v621 < 32; v621 += 1) {	// L943
    for (int v622 = 0; v622 < 34; v622 += 1) {	// L944
      for (int v623 = 0; v623 < 34; v623 += 1) {	// L945
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v619
        v619[0][v621][v622][v623] = v620;	// L946
      }
    }
  }
}

void kernel121(
  float v624[1][32][32][32],
  float v625
) {	// L952
  for (int v626 = 0; v626 < 32; v626 += 1) {	// L953
    for (int v627 = 0; v627 < 32; v627 += 1) {	// L954
      for (int v628 = 0; v628 < 32; v628 += 1) {	// L955
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v624
        float v629 = v624[0][v626][v627][v628];	// L956
        float v630 = v629 / v625;	// L957
        v624[0][v626][v627][v628] = v630;	// L958
      }
    }
  }
}

void kernel123(
  float v631[1][32][64][64],
  float v632[2][2],
  float v633[1][32][32][32]
) {	// L964
  for (int v634 = 0; v634 < 2; v634 += 1) {	// L965
    for (int v635 = 0; v635 < 2; v635 += 1) {	// L966
      for (int v636 = 0; v636 < 32; v636 += 1) {	// L967
        for (int v637 = 0; v637 < 32; v637 += 1) {	// L968
          for (int v638 = 0; v638 < 32; v638 += 1) {	// L969
            #pragma HLS pipeline II=1
            #pragma HLS dependence false variable=v631
            #pragma HLS dependence false variable=v633
            float v639 = v631[0][v636][((v637 * 2) + v634)][((v638 * 2) + v635)];	// L970
            float v640 = v633[0][v636][v637][v638];	// L971
            float v641 = v640 + v639;	// L972
            v633[0][v636][v637][v638] = v641;	// L973
          }
        }
      }
    }
  }
}

void kernel124(
  float v642[1][32][32][32],
  float v643
) {	// L981
  for (int v644 = 0; v644 < 32; v644 += 1) {	// L982
    for (int v645 = 0; v645 < 32; v645 += 1) {	// L983
      for (int v646 = 0; v646 < 32; v646 += 1) {	// L984
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v642
        v642[0][v644][v645][v646] = v643;	// L985
      }
    }
  }
}

void kernel125(
  float v647[1][32][64][64],
  float v648[1][32][64][64],
  float v649[1][32][64][64],
  float v650
) {	// L991
  for (int v651 = 0; v651 < 32; v651 += 1) {	// L992
    for (int v652 = 0; v652 < 64; v652 += 1) {	// L993
      for (int v653 = 0; v653 < 64; v653 += 1) {	// L994
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v647
        #pragma HLS dependence false variable=v649
        #pragma HLS dependence false variable=v648
        float v654 = v647[0][v651][v652][v653];	// L995
        float v655 = v648[0][v651][v652][v653];	// L996
        float v656 = v650 - v655;	// L997
        float v657 = v650 - v654;	// L998
        float v658 = v657 * v656;	// L999
        float v659 = v650 - v658;	// L1000
        v649[0][v651][v652][v653] = v659;	// L1001
      }
    }
  }
}

void kernel126(
  float v660[1][32][64][64],
  float v661[1][32][64][64]
) {	// L1007
  for (int v662 = 0; v662 < 32; v662 += 1) {	// L1008
    for (int v663 = 0; v663 < 64; v663 += 1) {	// L1009
      for (int v664 = 0; v664 < 64; v664 += 1) {	// L1010
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v660
        #pragma HLS dependence false variable=v661
        float v665 = v660[0][v662][v663][v664];	// L1011
        v661[0][v662][v663][v664] = v665;	// L1012
      }
    }
  }
}

void kernel127(
  float v666[1][32][64][64],
  float v667[1][32][64][64],
  float v668
) {	// L1018
  for (int v669 = 0; v669 < 32; v669 += 1) {	// L1019
    for (int v670 = 0; v670 < 64; v670 += 1) {	// L1020
      for (int v671 = 0; v671 < 64; v671 += 1) {	// L1021
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v667
        #pragma HLS dependence false variable=v666
        float v672 = v667[0][v669][v670][v671];	// L1022
        float v673 = v666[0][v669][v670][v671];	// L1023
        float v674 = v673 * v668;	// L1024
        float v675 = v672 - v673;	// L1025
        float v676 = v675 + v674;	// L1026
        v667[0][v669][v670][v671] = v676;	// L1027
      }
    }
  }
}

void kernel128(
  float v677[1][32][64][64],
  float v678,
  float v679
) {	// L1033
  for (int v680 = 0; v680 < 32; v680 += 1) {	// L1034
    for (int v681 = 0; v681 < 64; v681 += 1) {	// L1035
      for (int v682 = 0; v682 < 64; v682 += 1) {	// L1036
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v677
        float v683 = v677[0][v680][v681][v682];	// L1037
        float v684 = v683 - v679;	// L1038
        bool v685 = v684 >= v678;	// L1039
        float v686 = v685 ? v679 : v678;	// L1040
        v677[0][v680][v681][v682] = v686;	// L1041
      }
    }
  }
}

void kernel130(
  float v687[1][32][64][64],
  float v688[1][32][64][64],
  float v689[1][32][64][64],
  float v690
) {	// L1047
  for (int v691 = 0; v691 < 32; v691 += 1) {	// L1048
    for (int v692 = 0; v692 < 64; v692 += 1) {	// L1049
      for (int v693 = 0; v693 < 64; v693 += 1) {	// L1050
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v687
        #pragma HLS dependence false variable=v689
        #pragma HLS dependence false variable=v688
        float v694 = v687[0][v691][v692][v693];	// L1051
        float v695 = v688[0][v691][v692][v693];	// L1052
        float v696 = v695 / v690;	// L1053
        float v697 = v694 / v690;	// L1054
        float v698 = v694 - v697;	// L1055
        float v699 = v698 + v696;	// L1056
        v689[0][v691][v692][v693] = v699;	// L1057
      }
    }
  }
}

void kernel131(
  float v700[1][32][66][66],
  float v701[32][32][3][3],
  float v702[1][32][64][64]
) {	// L1063
  float v703[32][32][3][3];	// L1064
  #pragma HLS resource variable=v703 core=ram_t2p_bram

  memcpy(v703, v701, 9216 * sizeof(float));	// L1065

  for (int v704 = 0; v704 < 32; v704 += 1) {	// L1066
    for (int v705 = 0; v705 < 3; v705 += 1) {	// L1067
      for (int v706 = 0; v706 < 3; v706 += 1) {	// L1068
        for (int v707 = 0; v707 < 32; v707 += 1) {	// L1069
          for (int v708 = 0; v708 < 64; v708 += 1) {	// L1070
            for (int v709 = 0; v709 < 64; v709 += 1) {	// L1071
              #pragma HLS pipeline II=1
              #pragma HLS dependence false variable=v700
              #pragma HLS dependence false variable=v702
              #pragma HLS dependence false variable=v703
              float v710 = v700[0][v704][(v708 + v705)][(v709 + v706)];	// L1072
              float v711 = v703[v707][v704][v705][v706];	// L1073
              float v712 = v702[0][v707][v708][v709];	// L1074
              float v713 = v710 * v711;	// L1075
              float v714 = v712 + v713;	// L1076
              v702[0][v707][v708][v709] = v714;	// L1077
            }
          }
        }
      }
    }
  }
}

void kernel132(
  float v715[1][32][64][64],
  float v716[1][32][66][66]
) {	// L1086
  for (int v717 = 0; v717 < 32; v717 += 1) {	// L1087
    for (int v718 = 0; v718 < 64; v718 += 1) {	// L1088
      for (int v719 = 0; v719 < 64; v719 += 1) {	// L1089
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v715
        #pragma HLS dependence false variable=v716
        float v720 = v715[0][v717][v718][v719];	// L1090
        v716[0][v717][(v718 + 1)][(v719 + 1)] = v720;	// L1091
      }
    }
  }
}

void kernel133(
  float v721[1][32][66][66],
  float v722
) {	// L1097
  for (int v723 = 0; v723 < 32; v723 += 1) {	// L1098
    for (int v724 = 0; v724 < 66; v724 += 1) {	// L1099
      for (int v725 = 0; v725 < 66; v725 += 1) {	// L1100
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v721
        v721[0][v723][v724][v725] = v722;	// L1101
      }
    }
  }
}

void kernel141(
  float v726[32],
  float v727[1][32][64][64]
) {	// L1107
  float v728[32];	// L1108
  #pragma HLS resource variable=v728 core=ram_t2p_bram

  memcpy(v728, v726, 32 * sizeof(float));	// L1109

  for (int v729 = 0; v729 < 32; v729 += 1) {	// L1110
    for (int v730 = 0; v730 < 64; v730 += 1) {	// L1111
      for (int v731 = 0; v731 < 64; v731 += 1) {	// L1112
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v728
        #pragma HLS dependence false variable=v727
        float v732 = v728[v729];	// L1113
        v727[0][v729][v730][v731] = v732;	// L1114
      }
    }
  }
}

void kernel143(
  float v733[1][32][66][66],
  float v734
) {	// L1120
  for (int v735 = 0; v735 < 32; v735 += 1) {	// L1121
    for (int v736 = 0; v736 < 66; v736 += 1) {	// L1122
      for (int v737 = 0; v737 < 66; v737 += 1) {	// L1123
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v733
        v733[0][v735][v736][v737] = v734;	// L1124
      }
    }
  }
}

void kernel144(
  float v738[1][32][64][64],
  float v739
) {	// L1130
  for (int v740 = 0; v740 < 32; v740 += 1) {	// L1131
    for (int v741 = 0; v741 < 64; v741 += 1) {	// L1132
      for (int v742 = 0; v742 < 64; v742 += 1) {	// L1133
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v738
        float v743 = v738[0][v740][v741][v742];	// L1134
        float v744 = v743 / v739;	// L1135
        v738[0][v740][v741][v742] = v744;	// L1136
      }
    }
  }
}

void kernel145(
  float v745[1][32][128][128],
  float v746[2][2],
  float v747[1][32][64][64]
) {	// L1142
  for (int v748 = 0; v748 < 2; v748 += 1) {	// L1143
    for (int v749 = 0; v749 < 2; v749 += 1) {	// L1144
      for (int v750 = 0; v750 < 32; v750 += 1) {	// L1145
        for (int v751 = 0; v751 < 64; v751 += 1) {	// L1146
          for (int v752 = 0; v752 < 64; v752 += 1) {	// L1147
            #pragma HLS pipeline II=1
            #pragma HLS dependence false variable=v745
            #pragma HLS dependence false variable=v747
            float v753 = v745[0][v750][((v751 * 2) + v748)][((v752 * 2) + v749)];	// L1148
            float v754 = v747[0][v750][v751][v752];	// L1149
            float v755 = v754 + v753;	// L1150
            v747[0][v750][v751][v752] = v755;	// L1151
          }
        }
      }
    }
  }
}

void kernel146(
  float v756[1][32][64][64],
  float v757
) {	// L1159
  for (int v758 = 0; v758 < 32; v758 += 1) {	// L1160
    for (int v759 = 0; v759 < 64; v759 += 1) {	// L1161
      for (int v760 = 0; v760 < 64; v760 += 1) {	// L1162
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v756
        v756[0][v758][v759][v760] = v757;	// L1163
      }
    }
  }
}

void kernel147(
  float v761[1][32][128][128],
  float v762[1][32][128][128],
  float v763[1][32][128][128],
  float v764
) {	// L1169
  for (int v765 = 0; v765 < 32; v765 += 1) {	// L1170
    for (int v766 = 0; v766 < 128; v766 += 1) {	// L1171
      for (int v767 = 0; v767 < 128; v767 += 1) {	// L1172
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v761
        #pragma HLS dependence false variable=v763
        #pragma HLS dependence false variable=v762
        float v768 = v761[0][v765][v766][v767];	// L1173
        float v769 = v762[0][v765][v766][v767];	// L1174
        float v770 = v764 - v769;	// L1175
        float v771 = v764 - v768;	// L1176
        float v772 = v771 * v770;	// L1177
        float v773 = v764 - v772;	// L1178
        v763[0][v765][v766][v767] = v773;	// L1179
      }
    }
  }
}

void kernel148(
  float v774[1][32][128][128],
  float v775[1][32][128][128]
) {	// L1185
  for (int v776 = 0; v776 < 32; v776 += 1) {	// L1186
    for (int v777 = 0; v777 < 128; v777 += 1) {	// L1187
      for (int v778 = 0; v778 < 128; v778 += 1) {	// L1188
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v774
        #pragma HLS dependence false variable=v775
        float v779 = v774[0][v776][v777][v778];	// L1189
        v775[0][v776][v777][v778] = v779;	// L1190
      }
    }
  }
}

void kernel149(
  float v780[1][32][128][128],
  float v781[1][32][128][128],
  float v782
) {	// L1196
  for (int v783 = 0; v783 < 32; v783 += 1) {	// L1197
    for (int v784 = 0; v784 < 128; v784 += 1) {	// L1198
      for (int v785 = 0; v785 < 128; v785 += 1) {	// L1199
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v781
        #pragma HLS dependence false variable=v780
        float v786 = v781[0][v783][v784][v785];	// L1200
        float v787 = v780[0][v783][v784][v785];	// L1201
        float v788 = v787 * v782;	// L1202
        float v789 = v786 - v787;	// L1203
        float v790 = v789 + v788;	// L1204
        v781[0][v783][v784][v785] = v790;	// L1205
      }
    }
  }
}

void kernel150(
  float v791[1][32][128][128],
  float v792,
  float v793
) {	// L1211
  for (int v794 = 0; v794 < 32; v794 += 1) {	// L1212
    for (int v795 = 0; v795 < 128; v795 += 1) {	// L1213
      for (int v796 = 0; v796 < 128; v796 += 1) {	// L1214
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v791
        float v797 = v791[0][v794][v795][v796];	// L1215
        float v798 = v797 - v793;	// L1216
        bool v799 = v798 >= v792;	// L1217
        float v800 = v799 ? v793 : v792;	// L1218
        v791[0][v794][v795][v796] = v800;	// L1219
      }
    }
  }
}

void kernel152(
  float v801[1][32][128][128],
  float v802[1][32][128][128],
  float v803[1][32][128][128],
  float v804
) {	// L1225
  for (int v805 = 0; v805 < 32; v805 += 1) {	// L1226
    for (int v806 = 0; v806 < 128; v806 += 1) {	// L1227
      for (int v807 = 0; v807 < 128; v807 += 1) {	// L1228
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v801
        #pragma HLS dependence false variable=v803
        #pragma HLS dependence false variable=v802
        float v808 = v801[0][v805][v806][v807];	// L1229
        float v809 = v802[0][v805][v806][v807];	// L1230
        float v810 = v809 / v804;	// L1231
        float v811 = v808 / v804;	// L1232
        float v812 = v808 - v811;	// L1233
        float v813 = v812 + v810;	// L1234
        v803[0][v805][v806][v807] = v813;	// L1235
      }
    }
  }
}

void kernel153(
  float v814[1][32][130][130],
  float v815[32][32][3][3],
  float v816[1][32][128][128]
) {	// L1241
  float v817[32][32][3][3];	// L1242
  #pragma HLS resource variable=v817 core=ram_t2p_bram

  memcpy(v817, v815, 9216 * sizeof(float));	// L1243

  for (int v818 = 0; v818 < 32; v818 += 1) {	// L1244
    for (int v819 = 0; v819 < 3; v819 += 1) {	// L1245
      for (int v820 = 0; v820 < 3; v820 += 1) {	// L1246
        for (int v821 = 0; v821 < 32; v821 += 1) {	// L1247
          for (int v822 = 0; v822 < 128; v822 += 1) {	// L1248
            for (int v823 = 0; v823 < 128; v823 += 1) {	// L1249
              #pragma HLS pipeline II=1
              #pragma HLS dependence false variable=v814
              #pragma HLS dependence false variable=v816
              #pragma HLS dependence false variable=v817
              float v824 = v814[0][v818][(v822 + v819)][(v823 + v820)];	// L1250
              float v825 = v817[v821][v818][v819][v820];	// L1251
              float v826 = v816[0][v821][v822][v823];	// L1252
              float v827 = v824 * v825;	// L1253
              float v828 = v826 + v827;	// L1254
              v816[0][v821][v822][v823] = v828;	// L1255
            }
          }
        }
      }
    }
  }
}

void kernel154(
  float v829[1][32][128][128],
  float v830[1][32][130][130]
) {	// L1264
  for (int v831 = 0; v831 < 32; v831 += 1) {	// L1265
    for (int v832 = 0; v832 < 128; v832 += 1) {	// L1266
      for (int v833 = 0; v833 < 128; v833 += 1) {	// L1267
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v829
        #pragma HLS dependence false variable=v830
        float v834 = v829[0][v831][v832][v833];	// L1268
        v830[0][v831][(v832 + 1)][(v833 + 1)] = v834;	// L1269
      }
    }
  }
}

void kernel155(
  float v835[1][32][130][130],
  float v836
) {	// L1275
  for (int v837 = 0; v837 < 32; v837 += 1) {	// L1276
    for (int v838 = 0; v838 < 130; v838 += 1) {	// L1277
      for (int v839 = 0; v839 < 130; v839 += 1) {	// L1278
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v835
        v835[0][v837][v838][v839] = v836;	// L1279
      }
    }
  }
}

void kernel164(
  float v840[1][32][130][130],
  float v841
) {	// L1285
  for (int v842 = 0; v842 < 32; v842 += 1) {	// L1286
    for (int v843 = 0; v843 < 130; v843 += 1) {	// L1287
      for (int v844 = 0; v844 < 130; v844 += 1) {	// L1288
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v840
        v840[0][v842][v843][v844] = v841;	// L1289
      }
    }
  }
}

void kernel170(
  float v845[1][2][130][130],
  float v846[32][2][3][3],
  float v847[1][32][128][128]
) {	// L1295
  float v848[32][2][3][3];	// L1296
  #pragma HLS resource variable=v848 core=ram_t2p_bram

  memcpy(v848, v846, 576 * sizeof(float));	// L1297

  for (int v849 = 0; v849 < 2; v849 += 1) {	// L1298
    for (int v850 = 0; v850 < 3; v850 += 1) {	// L1299
      for (int v851 = 0; v851 < 3; v851 += 1) {	// L1300
        for (int v852 = 0; v852 < 32; v852 += 1) {	// L1301
          for (int v853 = 0; v853 < 128; v853 += 1) {	// L1302
            for (int v854 = 0; v854 < 128; v854 += 1) {	// L1303
              #pragma HLS pipeline II=1
              #pragma HLS dependence false variable=v845
              #pragma HLS dependence false variable=v847
              #pragma HLS dependence false variable=v848
              float v855 = v845[0][v849][(v853 + v850)][(v854 + v851)];	// L1304
              float v856 = v848[v852][v849][v850][v851];	// L1305
              float v857 = v847[0][v852][v853][v854];	// L1306
              float v858 = v855 * v856;	// L1307
              float v859 = v857 + v858;	// L1308
              v847[0][v852][v853][v854] = v859;	// L1309
            }
          }
        }
      }
    }
  }
}

void kernel172(
  float v860[32],
  float v861[1][32][128][128]
) {	// L1318
  float v862[32];	// L1319
  #pragma HLS resource variable=v862 core=ram_t2p_bram

  memcpy(v862, v860, 32 * sizeof(float));	// L1320

  for (int v863 = 0; v863 < 32; v863 += 1) {	// L1321
    for (int v864 = 0; v864 < 128; v864 += 1) {	// L1322
      for (int v865 = 0; v865 < 128; v865 += 1) {	// L1323
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v862
        #pragma HLS dependence false variable=v861
        float v866 = v862[v863];	// L1324
        v861[0][v863][v864][v865] = v866;	// L1325
      }
    }
  }
}

void kernel173(
  float v867[1][2][128][128],
  float v868[1][2][130][130]
) {	// L1331
  for (int v869 = 0; v869 < 2; v869 += 1) {	// L1332
    for (int v870 = 0; v870 < 128; v870 += 1) {	// L1333
      for (int v871 = 0; v871 < 128; v871 += 1) {	// L1334
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v867
        #pragma HLS dependence false variable=v868
        float v872 = v867[0][v869][v870][v871];	// L1335
        v868[0][v869][(v870 + 1)][(v871 + 1)] = v872;	// L1336
      }
    }
  }
}

void kernel174(
  float v873[1][2][130][130],
  float v874
) {	// L1342
  for (int v875 = 0; v875 < 2; v875 += 1) {	// L1343
    for (int v876 = 0; v876 < 130; v876 += 1) {	// L1344
      for (int v877 = 0; v877 < 130; v877 += 1) {	// L1345
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v873
        v873[0][v875][v876][v877] = v874;	// L1346
      }
    }
  }
}

/// The top function
void control(
  ap_int<32> v878[12864384],
  ap_int<32> v879[12864384],
  ap_int<32> v880[12864384]
) {	// L1352
  #pragma HLS interface s_axilite port=return bundle=ctrl
  #pragma hls interface m_axi offset=direct bundle=g0 port=v878
  #pragma hls stable variable=v878
  #pragma hls interface m_axi offset=direct bundle=g0 port=v879
  #pragma hls stable variable=v879
  #pragma hls interface m_axi offset=direct bundle=g0 port=v880
  #pragma hls stable variable=v880

  auto v881 = reinterpret_cast<float(*)[2][130][130]>(v878 + 8912896);
  kernel174(v881, (float)0.000000);	// L1364
  auto v882 = reinterpret_cast<float(*)[2][128][128]>(v878);
  kernel173(v882, v881);	// L1366
  auto v883 = reinterpret_cast<float(*)[32][128][128]>(v878 + 9453696);
  auto v884 = reinterpret_cast<float(*)>(v880 + 12845952);
  kernel172(v884, v883);	// L1369
  auto v885 = reinterpret_cast<float(*)[32][128][128]>(v880 + 9994496);
  kernel148(v883, v885);	// L1371
  auto v886 = reinterpret_cast<float(*)[2][3][3]>(v879 + 12855168);
  kernel170(v881, v886, v885);	// L1373
  auto v887 = reinterpret_cast<float(*)[32][128][128]>(v878 + 524288);
  auto v888 = reinterpret_cast<float(*)[32][128][128]>(v879 + 8912896);
  kernel152(v887, v885, v888, (float)-0.000000);	// L1376
  auto v889 = reinterpret_cast<float(*)[32][128][128]>(v878 + 9994496);
  kernel148(v888, v889);	// L1378
  kernel150(v889, (float)0.000000, (float)1.000000);	// L1379
  kernel149(v889, v888, (float)0.000000);	// L1380
  kernel148(v888, v887);	// L1381
  auto v890 = reinterpret_cast<float(*)[32][130][130]>(v879 + 10535296);
  kernel164(v890, (float)0.000000);	// L1383
  kernel154(v889, v890);	// L1384
  kernel148(v883, v885);	// L1385
  auto v891 = reinterpret_cast<float(*)[32][3][3]>(v878 + 12836736);
  kernel153(v890, v891, v885);	// L1387
  auto v892 = reinterpret_cast<float(*)[32][128][128]>(v878 + 1048576);
  kernel152(v892, v885, v888, (float)-0.000000);	// L1389
  kernel148(v888, v889);	// L1390
  kernel150(v889, (float)0.000000, (float)1.000000);	// L1391
  kernel149(v889, v888, (float)0.000000);	// L1392
  kernel148(v888, v892);	// L1393
  kernel155(v890, (float)0.000000);	// L1394
  kernel154(v889, v890);	// L1395
  auto v893 = reinterpret_cast<float(*)[32][3][3]>(v880 + 12827520);
  kernel153(v890, v893, v883);	// L1397
  auto v894 = reinterpret_cast<float(*)[32][128][128]>(v878 + 1572864);
  kernel152(v894, v883, v888, (float)-0.000000);	// L1399
  kernel148(v888, v883);	// L1400
  kernel150(v883, (float)0.000000, (float)1.000000);	// L1401
  kernel149(v883, v888, (float)0.000000);	// L1402
  kernel148(v888, v894);	// L1403
  kernel147(v889, v883, v888, (float)1.000000);	// L1404
  auto v895 = reinterpret_cast<float(*)[32][64][64]>(v878 + 9453696);
  kernel146(v895, (float)0.000000);	// L1406
  auto v896 = reinterpret_cast<float(*)[2]>(v878 + 9994496);
  kernel145(v888, v896, v895);	// L1408
  kernel144(v895, (float)4.000000);	// L1409
  auto v897 = reinterpret_cast<float(*)[32][66][66]>(v878 + 8912896);
  kernel143(v897, (float)0.000000);	// L1411
  kernel132(v895, v897);	// L1412
  auto v898 = reinterpret_cast<float(*)[32][64][64]>(v879 + 10535296);
  kernel141(v884, v898);	// L1414
  auto v899 = reinterpret_cast<float(*)[32][64][64]>(v879 + 11076096);
  kernel126(v898, v899);	// L1416
  auto v900 = reinterpret_cast<float(*)[32][3][3]>(v880 + 12818304);
  kernel131(v897, v900, v899);	// L1418
  auto v901 = reinterpret_cast<float(*)[32][64][64]>(v878 + 2097152);
  kernel130(v901, v899, v895, (float)-0.000000);	// L1420
  auto v902 = reinterpret_cast<float(*)[32][64][64]>(v879 + 8912896);
  kernel126(v895, v902);	// L1422
  kernel128(v902, (float)0.000000, (float)1.000000);	// L1423
  kernel127(v902, v895, (float)0.000000);	// L1424
  kernel126(v895, v901);	// L1425
  auto v903 = reinterpret_cast<float(*)[32][66][66]>(v878 + 11076096);
  kernel133(v903, (float)0.000000);	// L1427
  kernel132(v902, v903);	// L1428
  auto v904 = reinterpret_cast<float(*)[32][3][3]>(v880 + 12809088);
  kernel131(v903, v904, v898);	// L1430
  auto v905 = reinterpret_cast<float(*)[32][64][64]>(v878 + 2621440);
  kernel130(v905, v898, v895, (float)-0.000000);	// L1432
  kernel126(v895, v898);	// L1433
  kernel128(v898, (float)0.000000, (float)1.000000);	// L1434
  kernel127(v898, v895, (float)0.000000);	// L1435
  kernel126(v895, v905);	// L1436
  kernel125(v902, v898, v895, (float)1.000000);	// L1437
  auto v906 = reinterpret_cast<float(*)[32][32][32]>(v879 + 8912896);
  kernel124(v906, (float)0.000000);	// L1439
  kernel123(v895, v896, v906);	// L1440
  auto v907 = reinterpret_cast<float(*)[32][32][32]>(v878 + 9453696);
  kernel103(v906, v907);	// L1442
  kernel121(v907, (float)4.000000);	// L1443
  auto v908 = reinterpret_cast<float(*)[32][34][34]>(v878 + 10535296);
  kernel120(v908, (float)0.000000);	// L1445
  kernel109(v907, v908);	// L1446
  auto v909 = reinterpret_cast<float(*)[32][32][32]>(v880 + 11076096);
  kernel118(v884, v909);	// L1448
  auto v910 = reinterpret_cast<float(*)[32][32][32]>(v879 + 11616896);
  kernel103(v909, v910);	// L1450
  auto v911 = reinterpret_cast<float(*)[32][3][3]>(v880 + 12799872);
  kernel108(v908, v911, v910);	// L1452
  auto v912 = reinterpret_cast<float(*)[32][32][32]>(v878 + 3145728);
  kernel107(v912, v910, v906, (float)-0.000000);	// L1454
  auto v913 = reinterpret_cast<float(*)[32][32][32]>(v878 + 10535296);
  kernel103(v906, v913);	// L1456
  kernel105(v913, (float)0.000000, (float)1.000000);	// L1457
  kernel104(v913, v906, (float)0.000000);	// L1458
  kernel103(v906, v912);	// L1459
  auto v914 = reinterpret_cast<float(*)[32][34][34]>(v878 + 11616896);
  kernel110(v914, (float)0.000000);	// L1461
  kernel109(v913, v914);	// L1462
  auto v915 = reinterpret_cast<float(*)[32][3][3]>(v879 + 12790656);
  kernel108(v914, v915, v909);	// L1464
  auto v916 = reinterpret_cast<float(*)[32][32][32]>(v878 + 3670016);
  kernel107(v916, v909, v906, (float)-0.000000);	// L1466
  kernel103(v906, v909);	// L1467
  kernel105(v909, (float)0.000000, (float)1.000000);	// L1468
  kernel104(v909, v906, (float)0.000000);	// L1469
  kernel103(v906, v916);	// L1470
  kernel102(v913, v909, v906, (float)1.000000);	// L1471
  auto v917 = reinterpret_cast<float(*)[32][16][16]>(v879 + 10535296);
  kernel101(v917, (float)0.000000);	// L1473
  auto v918 = reinterpret_cast<float(*)[32][16][16]>(v878 + 11076096);
  kernel78(v917, v918);	// L1475
  kernel97(v906, v896, v918);	// L1476
  kernel98(v918, (float)4.000000);	// L1477
  kernel97(v907, v896, v917);	// L1478
  kernel96(v918, v917, (float)0.731261, (float)0.730867, (float)4.000000);	// L1479
  auto v919 = reinterpret_cast<float(*)[32][18][18]>(v878 + 8912896);
  kernel95(v919, (float)0.000000);	// L1481
  kernel84(v917, v919);	// L1482
  auto v920 = reinterpret_cast<float(*)[32][16][16]>(v878 + 9453696);
  kernel93(v884, v920);	// L1484
  auto v921 = reinterpret_cast<float(*)[32][16][16]>(v879 + 11616896);
  kernel78(v920, v921);	// L1486
  auto v922 = reinterpret_cast<float(*)[32][3][3]>(v880 + 12781440);
  kernel83(v919, v922, v921);	// L1488
  auto v923 = reinterpret_cast<float(*)[32][16][16]>(v878 + 4194304);
  kernel82(v923, v921, v917, (float)-0.000000);	// L1490
  auto v924 = reinterpret_cast<float(*)[32][16][16]>(v878 + 8912896);
  kernel78(v917, v924);	// L1492
  kernel80(v924, (float)0.000000, (float)1.000000);	// L1493
  kernel79(v924, v917, (float)0.000000);	// L1494
  kernel78(v917, v923);	// L1495
  auto v925 = reinterpret_cast<float(*)[32][18][18]>(v879 + 11616896);
  kernel85(v925, (float)0.000000);	// L1497
  kernel84(v924, v925);	// L1498
  auto v926 = reinterpret_cast<float(*)[32][3][3]>(v880 + 12772224);
  kernel83(v925, v926, v920);	// L1500
  auto v927 = reinterpret_cast<float(*)[32][16][16]>(v878 + 4718592);
  kernel82(v927, v920, v917, (float)-0.000000);	// L1502
  kernel78(v917, v920);	// L1503
  kernel80(v920, (float)0.000000, (float)1.000000);	// L1504
  kernel79(v920, v917, (float)0.000000);	// L1505
  kernel78(v917, v927);	// L1506
  kernel77(v924, v920, v917, (float)1.000000);	// L1507
  auto v928 = reinterpret_cast<float(*)[32][8][8]>(v879 + 8912896);
  kernel76(v928, (float)0.000000);	// L1509
  kernel75(v917, v896, v928);	// L1510
  auto v929 = reinterpret_cast<float(*)[32][8][8]>(v878 + 9453696);
  kernel55(v928, v929);	// L1512
  kernel73(v929, (float)4.000000);	// L1513
  auto v930 = reinterpret_cast<float(*)[32][10][10]>(v879 + 10535296);
  kernel72(v930, (float)0.000000);	// L1515
  kernel61(v929, v930);	// L1516
  auto v931 = reinterpret_cast<float(*)[32][8][8]>(v880 + 11616896);
  kernel70(v884, v931);	// L1518
  auto v932 = reinterpret_cast<float(*)[32][8][8]>(v878 + 12157696);
  kernel55(v931, v932);	// L1520
  auto v933 = reinterpret_cast<float(*)[32][3][3]>(v880 + 12763008);
  kernel60(v930, v933, v932);	// L1522
  auto v934 = reinterpret_cast<float(*)[32][8][8]>(v878 + 5242880);
  kernel59(v934, v932, v928, (float)-0.000000);	// L1524
  auto v935 = reinterpret_cast<float(*)[32][8][8]>(v879 + 10535296);
  kernel55(v928, v935);	// L1526
  kernel57(v935, (float)0.000000, (float)1.000000);	// L1527
  kernel56(v935, v928, (float)0.000000);	// L1528
  kernel55(v928, v934);	// L1529
  auto v936 = reinterpret_cast<float(*)[32][10][10]>(v878 + 12157696);
  kernel62(v936, (float)0.000000);	// L1531
  kernel61(v935, v936);	// L1532
  auto v937 = reinterpret_cast<float(*)[32][3][3]>(v879 + 12753792);
  kernel60(v936, v937, v931);	// L1534
  auto v938 = reinterpret_cast<float(*)[32][8][8]>(v878 + 5767168);
  kernel59(v938, v931, v928, (float)-0.000000);	// L1536
  auto v939 = reinterpret_cast<float(*)[32][8][8]>(v878 + 11616896);
  kernel55(v928, v939);	// L1538
  kernel57(v939, (float)0.000000, (float)1.000000);	// L1539
  kernel56(v939, v928, (float)0.000000);	// L1540
  kernel55(v928, v938);	// L1541
  kernel54(v935, v939, v928, (float)1.000000);	// L1542
  auto v940 = reinterpret_cast<float(*)[32][4][4]>(v878 + 10535296);
  kernel53(v940, (float)0.000000);	// L1544
  auto v941 = reinterpret_cast<float(*)[32][4][4]>(v880 + 11616896);
  kernel29(v940, v941);	// L1546
  kernel48(v928, v896, v941);	// L1547
  auto v942 = reinterpret_cast<float(*)[32][4][4]>(v879 + 8912896);
  kernel29(v940, v942);	// L1549
  auto v943 = reinterpret_cast<float(*)[4]>(v880 + 12157696);
  kernel49(v918, v943, v942);	// L1551
  kernel48(v929, v896, v940);	// L1552
  kernel47(v942, v941, v940, (float)0.730819, (float)0.729963, (float)0.732428, (float)16.000000, (float)4.000000);	// L1553
  auto v944 = reinterpret_cast<float(*)[32][6][6]>(v878 + 8912896);
  kernel46(v944, (float)0.000000);	// L1555
  kernel35(v940, v944);	// L1556
  auto v945 = reinterpret_cast<float(*)[32][4][4]>(v878 + 9453696);
  kernel44(v884, v945);	// L1558
  auto v946 = reinterpret_cast<float(*)[32][4][4]>(v879 + 11076096);
  kernel29(v945, v946);	// L1560
  auto v947 = reinterpret_cast<float(*)[32][3][3]>(v880 + 12744576);
  kernel34(v944, v947, v946);	// L1562
  auto v948 = reinterpret_cast<float(*)[32][4][4]>(v878 + 6291456);
  kernel33(v948, v946, v940, (float)-0.000000);	// L1564
  kernel29(v940, v942);	// L1565
  kernel31(v942, (float)0.000000, (float)1.000000);	// L1566
  kernel30(v942, v940, (float)0.000000);	// L1567
  kernel29(v940, v948);	// L1568
  auto v949 = reinterpret_cast<float(*)[32][6][6]>(v878 + 11076096);
  kernel36(v949, (float)0.000000);	// L1570
  kernel35(v942, v949);	// L1571
  auto v950 = reinterpret_cast<float(*)[32][3][3]>(v880 + 12735360);
  kernel34(v949, v950, v945);	// L1573
  auto v951 = reinterpret_cast<float(*)[32][4][4]>(v878 + 6815744);
  kernel33(v951, v945, v940, (float)-0.000000);	// L1575
  auto v952 = reinterpret_cast<float(*)[32][4][4]>(v880 + 9453696);
  kernel29(v940, v952);	// L1577
  kernel31(v952, (float)0.000000, (float)1.000000);	// L1578
  kernel30(v952, v940, (float)0.000000);	// L1579
  kernel29(v940, v951);	// L1580
  kernel28(v942, v952, v940, (float)1.000000);	// L1581
  auto v953 = reinterpret_cast<float(*)[32][2][2]>(v879 + 8912896);
  kernel27(v953, (float)0.000000);	// L1583
  kernel26(v940, v896, v953);	// L1584
  kernel25(v953, (float)4.000000);	// L1585
  kernel24(v945, (float)0.000000);	// L1586
  kernel13(v953, v945);	// L1587
  auto v954 = reinterpret_cast<float(*)[32][2][2]>(v880 + 10535296);
  kernel22(v884, v954);	// L1589
  auto v955 = reinterpret_cast<float(*)[32][2][2]>(v879 + 11076096);
  kernel7(v954, v955);	// L1591
  auto v956 = reinterpret_cast<float(*)[32][3][3]>(v880 + 12726144);
  kernel12(v945, v956, v955);	// L1593
  auto v957 = reinterpret_cast<float(*)[32][2][2]>(v878 + 7340032);
  kernel11(v957, v955, v953, (float)-0.000000);	// L1595
  auto v958 = reinterpret_cast<float(*)[32][2][2]>(v878 + 9453696);
  kernel7(v953, v958);	// L1597
  kernel9(v958, (float)0.000000, (float)1.000000);	// L1598
  kernel8(v958, v953, (float)0.000000);	// L1599
  kernel7(v953, v957);	// L1600
  auto v959 = reinterpret_cast<float(*)[32][4][4]>(v878 + 11076096);
  kernel14(v959, (float)0.000000);	// L1602
  kernel13(v958, v959);	// L1603
  auto v960 = reinterpret_cast<float(*)[32][3][3]>(v879 + 12716928);
  kernel12(v959, v960, v954);	// L1605
  auto v961 = reinterpret_cast<float(*)[32][2][2]>(v878 + 7864320);
  kernel11(v961, v954, v953, (float)-0.000000);	// L1607
  auto v962 = reinterpret_cast<float(*)[32][2][2]>(v878 + 10535296);
  kernel7(v953, v962);	// L1609
  kernel9(v962, (float)0.000000, (float)1.000000);	// L1610
  kernel8(v962, v953, (float)0.000000);	// L1611
  kernel7(v953, v961);	// L1612
  kernel6(v958, v962, v953, (float)1.000000);	// L1613
  auto v963 = reinterpret_cast<float(*)[32][1][1]>(v878 + 9453696);
  kernel5(v963, (float)0.000000);	// L1615
  kernel4(v953, v896, v963);	// L1616
  kernel3(v963, (float)4.000000);	// L1617
  auto v964 = reinterpret_cast<float(*)[11]>(v878 + 8388608);
  kernel2(v964, (float)0.000000);	// L1619
  auto v965 = reinterpret_cast<float(*)[11]>(v880 + 12698496);
  kernel1(v963, v965, v964);	// L1621
  auto v966 = reinterpret_cast<float(*)>(v880 + 12707712);
  kernel0(v966, v964);	// L1623
}

/// The T-step wrapper (FHCA v1.4: on-chip time-step loop)
/// Drives the single-step control T times; membrane states persist in DDR top_level buffers.
/// input_frames: DDR staging of T input frames (per-step-input);
///   frame t is memcpy'd to the input slot (arg0+0) before step t.
///   frame_elems=0: static input (host pre-writes frame, no copy).
/// out_frames: per-step outputs staged to DDR (out region assumed on
///   arg0 at out_elem_offset); out_elems=0: skip staging.
void control_t(
  ap_int<32> t_v0[12864384],
  ap_int<32> t_v1[12864384],
  ap_int<32> t_v2[12864384],
  const ap_int<32> *input_frames,
  float *out_frames,
  long out_elem_offset,
  int out_elems,
  int t_steps,
  long frame_elems
) {
  #pragma HLS interface s_axilite port=return bundle=ctrl
  #pragma hls interface m_axi offset=direct bundle=g0 port=t_v0
  #pragma hls stable variable=t_v0
  #pragma hls interface m_axi offset=direct bundle=g0 port=t_v1
  #pragma hls stable variable=t_v1
  #pragma hls interface m_axi offset=direct bundle=g0 port=t_v2
  #pragma hls stable variable=t_v2
  #pragma hls interface m_axi offset=direct bundle=g1 port=input_frames
  #pragma hls interface m_axi offset=direct bundle=g1 port=out_frames
  for (int t = 0; t < t_steps; t++) {
    if (frame_elems > 0)
      memcpy((void*)t_v0, (const void*)(input_frames + (long)t * frame_elems), frame_elems * sizeof(ap_int<32>));
    control(t_v0, t_v1, t_v2);
    if (out_elems > 0)
      memcpy((void*)(out_frames + (long)t * out_elems),
             (const void*)((const char*)t_v0 + out_elem_offset * sizeof(ap_int<32>)),
             out_elems * sizeof(float));
  }
}

