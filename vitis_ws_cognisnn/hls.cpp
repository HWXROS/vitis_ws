
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
  float v20[11][32],
  float v21[32][11]
) {	// L32
  for (int v22 = 0; v22 < 32; v22 += 1) {	// L33
    for (int v23 = 0; v23 < 11; v23 += 1) {	// L34
      float v24 = v20[v23][v22];	// L35
      v21[v22][v23] = v24;	// L36
    }
  }
}

void kernel4(
  float v25[1][32][1][1],
  float v26
) {	// L41
  for (int v27 = 0; v27 < 32; v27 += 1) {	// L42
    float v28 = v25[0][v27][0][0];	// L43
    float v29 = v28 / v26;	// L44
    v25[0][v27][0][0] = v29;	// L45
  }
}

void kernel5(
  float v30[1][32][2][2],
  float v31[2][2],
  float v32[1][32][1][1]
) {	// L49
  for (int v33 = 0; v33 < 2; v33 += 1) {	// L50
    for (int v34 = 0; v34 < 2; v34 += 1) {	// L51
      for (int v35 = 0; v35 < 32; v35 += 1) {	// L52
        float v36 = v30[0][v35][v33][v34];	// L53
        float v37 = v32[0][v35][0][0];	// L54
        float v38 = v37 + v36;	// L55
        v32[0][v35][0][0] = v38;	// L56
      }
    }
  }
}

void kernel6(
  float v39[1][32][1][1],
  float v40
) {	// L62
  for (int v41 = 0; v41 < 32; v41 += 1) {	// L63
    v39[0][v41][0][0] = v40;	// L64
  }
}

void kernel7(
  float v42[1],
  float v43[1][32][2][2]
) {	// L68
  float v44[1];	// L69
  memcpy(v44, v42, 1 * sizeof(float));	// L70

  for (int v45 = 0; v45 < 32; v45 += 1) {	// L71
    for (int v46 = 0; v46 < 2; v46 += 1) {	// L72
      for (int v47 = 0; v47 < 2; v47 += 1) {	// L73
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v44
        #pragma HLS dependence false variable=v43
        float v48 = v44[0];	// L74
        float v49 = v43[0][v45][v46][v47];	// L75
        float v50 = v48 - v49;	// L76
        v43[0][v45][v46][v47] = v50;	// L77
      }
    }
  }
}

void kernel8(
  float v51[1][32][2][2],
  float v52[1][32][2][2]
) {	// L83
  for (int v53 = 0; v53 < 32; v53 += 1) {	// L84
    for (int v54 = 0; v54 < 2; v54 += 1) {	// L85
      for (int v55 = 0; v55 < 2; v55 += 1) {	// L86
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v51
        #pragma HLS dependence false variable=v52
        float v56 = v51[0][v53][v54][v55];	// L87
        float v57 = v52[0][v53][v54][v55];	// L88
        float v58 = v56 * v57;	// L89
        v52[0][v53][v54][v55] = v58;	// L90
      }
    }
  }
}

void kernel9(
  float v59[1][32][2][2],
  float v60[1],
  float v61[1][32][2][2]
) {	// L96
  float v62[1];	// L97
  memcpy(v62, v60, 1 * sizeof(float));	// L98

  for (int v63 = 0; v63 < 32; v63 += 1) {	// L99
    for (int v64 = 0; v64 < 2; v64 += 1) {	// L100
      for (int v65 = 0; v65 < 2; v65 += 1) {	// L101
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v62
        #pragma HLS dependence false variable=v59
        #pragma HLS dependence false variable=v61
        float v66 = v62[0];	// L102
        float v67 = v59[0][v63][v64][v65];	// L103
        float v68 = v66 - v67;	// L104
        v61[0][v63][v64][v65] = v68;	// L105
      }
    }
  }
}

void kernel11(
  float v69[1][32][2][2],
  float v70[1][32][2][2]
) {	// L111
  for (int v71 = 0; v71 < 32; v71 += 1) {	// L112
    for (int v72 = 0; v72 < 2; v72 += 1) {	// L113
      for (int v73 = 0; v73 < 2; v73 += 1) {	// L114
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v69
        #pragma HLS dependence false variable=v70
        float v74 = v69[0][v71][v72][v73];	// L115
        v70[0][v71][v72][v73] = v74;	// L116
      }
    }
  }
}

void kernel12(
  float v75[1][32][2][2],
  float v76[1][32][2][2]
) {	// L122
  for (int v77 = 0; v77 < 32; v77 += 1) {	// L123
    for (int v78 = 0; v78 < 2; v78 += 1) {	// L124
      for (int v79 = 0; v79 < 2; v79 += 1) {	// L125
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v75
        #pragma HLS dependence false variable=v76
        float v80 = v75[0][v77][v78][v79];	// L126
        float v81 = v76[0][v77][v78][v79];	// L127
        float v82 = v80 + v81;	// L128
        v76[0][v77][v78][v79] = v82;	// L129
      }
    }
  }
}

void kernel13(
  float v83[1][32][2][2],
  float v84
) {	// L135
  for (int v85 = 0; v85 < 32; v85 += 1) {	// L136
    for (int v86 = 0; v86 < 2; v86 += 1) {	// L137
      for (int v87 = 0; v87 < 2; v87 += 1) {	// L138
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v83
        float v88 = v83[0][v85][v86][v87];	// L139
        float v89 = v88 * v84;	// L140
        v83[0][v85][v86][v87] = v89;	// L141
      }
    }
  }
}

void kernel15(
  float v90[1][32][2][2],
  float v91[1][32][2][2],
  float v92[1][32][2][2]
) {	// L147
  for (int v93 = 0; v93 < 32; v93 += 1) {	// L148
    for (int v94 = 0; v94 < 2; v94 += 1) {	// L149
      for (int v95 = 0; v95 < 2; v95 += 1) {	// L150
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v91
        #pragma HLS dependence false variable=v92
        #pragma HLS dependence false variable=v90
        float v96 = v91[0][v93][v94][v95];	// L151
        float v97 = v90[0][v93][v94][v95];	// L152
        float v98 = v96 - v97;	// L153
        v92[0][v93][v94][v95] = v98;	// L154
      }
    }
  }
}

void kernel16(
  float v99[1][32][2][2],
  float v100,
  float v101
) {	// L160
  for (int v102 = 0; v102 < 32; v102 += 1) {	// L161
    for (int v103 = 0; v103 < 2; v103 += 1) {	// L162
      for (int v104 = 0; v104 < 2; v104 += 1) {	// L163
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v99
        float v105 = v99[0][v102][v103][v104];	// L164
        bool v106 = v105 >= v101;	// L165
        float v107 = v106 ? v100 : v101;	// L166
        v99[0][v102][v103][v104] = v107;	// L167
      }
    }
  }
}

void kernel18(
  float v108[1][32][2][2],
  float v109
) {	// L173
  for (int v110 = 0; v110 < 32; v110 += 1) {	// L174
    for (int v111 = 0; v111 < 2; v111 += 1) {	// L175
      for (int v112 = 0; v112 < 2; v112 += 1) {	// L176
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v108
        float v113 = v108[0][v110][v111][v112];	// L177
        float v114 = v113 - v109;	// L178
        v108[0][v110][v111][v112] = v114;	// L179
      }
    }
  }
}

void kernel20(
  float v115[1][32][2][2],
  float v116[1][32][2][2],
  float v117[1][32][2][2]
) {	// L185
  for (int v118 = 0; v118 < 32; v118 += 1) {	// L186
    for (int v119 = 0; v119 < 2; v119 += 1) {	// L187
      for (int v120 = 0; v120 < 2; v120 += 1) {	// L188
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v116
        #pragma HLS dependence false variable=v117
        #pragma HLS dependence false variable=v115
        float v121 = v116[0][v118][v119][v120];	// L189
        float v122 = v115[0][v118][v119][v120];	// L190
        float v123 = v121 + v122;	// L191
        v117[0][v118][v119][v120] = v123;	// L192
      }
    }
  }
}

void kernel21(
  float v124[1][32][2][2],
  float v125
) {	// L198
  for (int v126 = 0; v126 < 32; v126 += 1) {	// L199
    for (int v127 = 0; v127 < 2; v127 += 1) {	// L200
      for (int v128 = 0; v128 < 2; v128 += 1) {	// L201
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v124
        float v129 = v124[0][v126][v127][v128];	// L202
        float v130 = v129 / v125;	// L203
        v124[0][v126][v127][v128] = v130;	// L204
      }
    }
  }
}

void kernel26(
  float v131[1][32][4][4],
  float v132[32][32][3][3],
  float v133[1][32][2][2]
) {	// L210
  float v134[32][32][3][3];	// L211
  #pragma HLS resource variable=v134 core=ram_t2p_bram

  memcpy(v134, v132, 9216 * sizeof(float));	// L212

  for (int v135 = 0; v135 < 32; v135 += 1) {	// L213
    for (int v136 = 0; v136 < 3; v136 += 1) {	// L214
      for (int v137 = 0; v137 < 3; v137 += 1) {	// L215
        for (int v138 = 0; v138 < 32; v138 += 1) {	// L216
          for (int v139 = 0; v139 < 2; v139 += 1) {	// L217
            for (int v140 = 0; v140 < 2; v140 += 1) {	// L218
              #pragma HLS pipeline II=1
              #pragma HLS dependence false variable=v131
              #pragma HLS dependence false variable=v133
              #pragma HLS dependence false variable=v134
              float v141 = v131[0][v135][(v139 + v136)][(v140 + v137)];	// L219
              float v142 = v134[v138][v135][v136][v137];	// L220
              float v143 = v133[0][v138][v139][v140];	// L221
              float v144 = v141 * v142;	// L222
              float v145 = v143 + v144;	// L223
              v133[0][v138][v139][v140] = v145;	// L224
            }
          }
        }
      }
    }
  }
}

void kernel27(
  float v146[1][32][2][2],
  float v147[1][32][4][4]
) {	// L233
  for (int v148 = 0; v148 < 32; v148 += 1) {	// L234
    for (int v149 = 0; v149 < 2; v149 += 1) {	// L235
      for (int v150 = 0; v150 < 2; v150 += 1) {	// L236
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v146
        #pragma HLS dependence false variable=v147
        float v151 = v146[0][v148][v149][v150];	// L237
        v147[0][v148][(v149 + 1)][(v150 + 1)] = v151;	// L238
      }
    }
  }
}

void kernel28(
  float v152[1][32][4][4],
  float v153
) {	// L244
  for (int v154 = 0; v154 < 32; v154 += 1) {	// L245
    for (int v155 = 0; v155 < 4; v155 += 1) {	// L246
      for (int v156 = 0; v156 < 4; v156 += 1) {	// L247
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v152
        v152[0][v154][v155][v156] = v153;	// L248
      }
    }
  }
}

void kernel46(
  float v157[32],
  float v158[1][32][2][2]
) {	// L254
  float v159[32];	// L255
  #pragma HLS resource variable=v159 core=ram_t2p_bram

  memcpy(v159, v157, 32 * sizeof(float));	// L256

  for (int v160 = 0; v160 < 32; v160 += 1) {	// L257
    for (int v161 = 0; v161 < 2; v161 += 1) {	// L258
      for (int v162 = 0; v162 < 2; v162 += 1) {	// L259
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v159
        #pragma HLS dependence false variable=v158
        float v163 = v159[v160];	// L260
        v158[0][v160][v161][v162] = v163;	// L261
      }
    }
  }
}

void kernel48(
  float v164[1][32][4][4],
  float v165
) {	// L267
  for (int v166 = 0; v166 < 32; v166 += 1) {	// L268
    for (int v167 = 0; v167 < 4; v167 += 1) {	// L269
      for (int v168 = 0; v168 < 4; v168 += 1) {	// L270
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v164
        v164[0][v166][v167][v168] = v165;	// L271
      }
    }
  }
}

void kernel50(
  float v169[1][32][4][4],
  float v170[2][2],
  float v171[1][32][2][2]
) {	// L277
  for (int v172 = 0; v172 < 2; v172 += 1) {	// L278
    for (int v173 = 0; v173 < 2; v173 += 1) {	// L279
      for (int v174 = 0; v174 < 32; v174 += 1) {	// L280
        for (int v175 = 0; v175 < 2; v175 += 1) {	// L281
          for (int v176 = 0; v176 < 2; v176 += 1) {	// L282
            #pragma HLS pipeline II=1
            #pragma HLS dependence false variable=v169
            #pragma HLS dependence false variable=v171
            float v177 = v169[0][v174][((v175 * 2) + v172)][((v176 * 2) + v173)];	// L283
            float v178 = v171[0][v174][v175][v176];	// L284
            float v179 = v178 + v177;	// L285
            v171[0][v174][v175][v176] = v179;	// L286
          }
        }
      }
    }
  }
}

void kernel51(
  float v180[1][32][2][2],
  float v181
) {	// L294
  for (int v182 = 0; v182 < 32; v182 += 1) {	// L295
    for (int v183 = 0; v183 < 2; v183 += 1) {	// L296
      for (int v184 = 0; v184 < 2; v184 += 1) {	// L297
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v180
        v180[0][v182][v183][v184] = v181;	// L298
      }
    }
  }
}

void kernel52(
  float v185[1],
  float v186[1][32][4][4]
) {	// L304
  float v187[1];	// L305
  memcpy(v187, v185, 1 * sizeof(float));	// L306

  for (int v188 = 0; v188 < 32; v188 += 1) {	// L307
    for (int v189 = 0; v189 < 4; v189 += 1) {	// L308
      for (int v190 = 0; v190 < 4; v190 += 1) {	// L309
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v187
        #pragma HLS dependence false variable=v186
        float v191 = v187[0];	// L310
        float v192 = v186[0][v188][v189][v190];	// L311
        float v193 = v191 - v192;	// L312
        v186[0][v188][v189][v190] = v193;	// L313
      }
    }
  }
}

void kernel53(
  float v194[1][32][4][4],
  float v195[1][32][4][4]
) {	// L319
  for (int v196 = 0; v196 < 32; v196 += 1) {	// L320
    for (int v197 = 0; v197 < 4; v197 += 1) {	// L321
      for (int v198 = 0; v198 < 4; v198 += 1) {	// L322
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v194
        #pragma HLS dependence false variable=v195
        float v199 = v194[0][v196][v197][v198];	// L323
        float v200 = v195[0][v196][v197][v198];	// L324
        float v201 = v199 * v200;	// L325
        v195[0][v196][v197][v198] = v201;	// L326
      }
    }
  }
}

void kernel54(
  float v202[1][32][4][4],
  float v203[1],
  float v204[1][32][4][4]
) {	// L332
  float v205[1];	// L333
  memcpy(v205, v203, 1 * sizeof(float));	// L334

  for (int v206 = 0; v206 < 32; v206 += 1) {	// L335
    for (int v207 = 0; v207 < 4; v207 += 1) {	// L336
      for (int v208 = 0; v208 < 4; v208 += 1) {	// L337
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v205
        #pragma HLS dependence false variable=v202
        #pragma HLS dependence false variable=v204
        float v209 = v205[0];	// L338
        float v210 = v202[0][v206][v207][v208];	// L339
        float v211 = v209 - v210;	// L340
        v204[0][v206][v207][v208] = v211;	// L341
      }
    }
  }
}

void kernel56(
  float v212[1][32][4][4],
  float v213[1][32][4][4]
) {	// L347
  for (int v214 = 0; v214 < 32; v214 += 1) {	// L348
    for (int v215 = 0; v215 < 4; v215 += 1) {	// L349
      for (int v216 = 0; v216 < 4; v216 += 1) {	// L350
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v212
        #pragma HLS dependence false variable=v213
        float v217 = v212[0][v214][v215][v216];	// L351
        v213[0][v214][v215][v216] = v217;	// L352
      }
    }
  }
}

void kernel57(
  float v218[1][32][4][4],
  float v219[1][32][4][4]
) {	// L358
  for (int v220 = 0; v220 < 32; v220 += 1) {	// L359
    for (int v221 = 0; v221 < 4; v221 += 1) {	// L360
      for (int v222 = 0; v222 < 4; v222 += 1) {	// L361
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v218
        #pragma HLS dependence false variable=v219
        float v223 = v218[0][v220][v221][v222];	// L362
        float v224 = v219[0][v220][v221][v222];	// L363
        float v225 = v223 + v224;	// L364
        v219[0][v220][v221][v222] = v225;	// L365
      }
    }
  }
}

void kernel58(
  float v226[1][32][4][4],
  float v227
) {	// L371
  for (int v228 = 0; v228 < 32; v228 += 1) {	// L372
    for (int v229 = 0; v229 < 4; v229 += 1) {	// L373
      for (int v230 = 0; v230 < 4; v230 += 1) {	// L374
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v226
        float v231 = v226[0][v228][v229][v230];	// L375
        float v232 = v231 * v227;	// L376
        v226[0][v228][v229][v230] = v232;	// L377
      }
    }
  }
}

void kernel60(
  float v233[1][32][4][4],
  float v234[1][32][4][4],
  float v235[1][32][4][4]
) {	// L383
  for (int v236 = 0; v236 < 32; v236 += 1) {	// L384
    for (int v237 = 0; v237 < 4; v237 += 1) {	// L385
      for (int v238 = 0; v238 < 4; v238 += 1) {	// L386
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v234
        #pragma HLS dependence false variable=v235
        #pragma HLS dependence false variable=v233
        float v239 = v234[0][v236][v237][v238];	// L387
        float v240 = v233[0][v236][v237][v238];	// L388
        float v241 = v239 - v240;	// L389
        v235[0][v236][v237][v238] = v241;	// L390
      }
    }
  }
}

void kernel61(
  float v242[1][32][4][4],
  float v243,
  float v244
) {	// L396
  for (int v245 = 0; v245 < 32; v245 += 1) {	// L397
    for (int v246 = 0; v246 < 4; v246 += 1) {	// L398
      for (int v247 = 0; v247 < 4; v247 += 1) {	// L399
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v242
        float v248 = v242[0][v245][v246][v247];	// L400
        bool v249 = v248 >= v244;	// L401
        float v250 = v249 ? v243 : v244;	// L402
        v242[0][v245][v246][v247] = v250;	// L403
      }
    }
  }
}

void kernel63(
  float v251[1][32][4][4],
  float v252
) {	// L409
  for (int v253 = 0; v253 < 32; v253 += 1) {	// L410
    for (int v254 = 0; v254 < 4; v254 += 1) {	// L411
      for (int v255 = 0; v255 < 4; v255 += 1) {	// L412
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v251
        float v256 = v251[0][v253][v254][v255];	// L413
        float v257 = v256 - v252;	// L414
        v251[0][v253][v254][v255] = v257;	// L415
      }
    }
  }
}

void kernel65(
  float v258[1][32][4][4],
  float v259[1][32][4][4],
  float v260[1][32][4][4]
) {	// L421
  for (int v261 = 0; v261 < 32; v261 += 1) {	// L422
    for (int v262 = 0; v262 < 4; v262 += 1) {	// L423
      for (int v263 = 0; v263 < 4; v263 += 1) {	// L424
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v259
        #pragma HLS dependence false variable=v260
        #pragma HLS dependence false variable=v258
        float v264 = v259[0][v261][v262][v263];	// L425
        float v265 = v258[0][v261][v262][v263];	// L426
        float v266 = v264 + v265;	// L427
        v260[0][v261][v262][v263] = v266;	// L428
      }
    }
  }
}

void kernel66(
  float v267[1][32][4][4],
  float v268
) {	// L434
  for (int v269 = 0; v269 < 32; v269 += 1) {	// L435
    for (int v270 = 0; v270 < 4; v270 += 1) {	// L436
      for (int v271 = 0; v271 < 4; v271 += 1) {	// L437
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v267
        float v272 = v267[0][v269][v270][v271];	// L438
        float v273 = v272 / v268;	// L439
        v267[0][v269][v270][v271] = v273;	// L440
      }
    }
  }
}

void kernel71(
  float v274[1][32][6][6],
  float v275[32][32][3][3],
  float v276[1][32][4][4]
) {	// L446
  float v277[32][32][3][3];	// L447
  #pragma HLS resource variable=v277 core=ram_t2p_bram

  memcpy(v277, v275, 9216 * sizeof(float));	// L448

  for (int v278 = 0; v278 < 32; v278 += 1) {	// L449
    for (int v279 = 0; v279 < 3; v279 += 1) {	// L450
      for (int v280 = 0; v280 < 3; v280 += 1) {	// L451
        for (int v281 = 0; v281 < 32; v281 += 1) {	// L452
          for (int v282 = 0; v282 < 4; v282 += 1) {	// L453
            for (int v283 = 0; v283 < 4; v283 += 1) {	// L454
              #pragma HLS pipeline II=1
              #pragma HLS dependence false variable=v274
              #pragma HLS dependence false variable=v276
              #pragma HLS dependence false variable=v277
              float v284 = v274[0][v278][(v282 + v279)][(v283 + v280)];	// L455
              float v285 = v277[v281][v278][v279][v280];	// L456
              float v286 = v276[0][v281][v282][v283];	// L457
              float v287 = v284 * v285;	// L458
              float v288 = v286 + v287;	// L459
              v276[0][v281][v282][v283] = v288;	// L460
            }
          }
        }
      }
    }
  }
}

void kernel72(
  float v289[1][32][4][4],
  float v290[1][32][6][6]
) {	// L469
  for (int v291 = 0; v291 < 32; v291 += 1) {	// L470
    for (int v292 = 0; v292 < 4; v292 += 1) {	// L471
      for (int v293 = 0; v293 < 4; v293 += 1) {	// L472
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v289
        #pragma HLS dependence false variable=v290
        float v294 = v289[0][v291][v292][v293];	// L473
        v290[0][v291][(v292 + 1)][(v293 + 1)] = v294;	// L474
      }
    }
  }
}

void kernel73(
  float v295[1][32][6][6],
  float v296
) {	// L480
  for (int v297 = 0; v297 < 32; v297 += 1) {	// L481
    for (int v298 = 0; v298 < 6; v298 += 1) {	// L482
      for (int v299 = 0; v299 < 6; v299 += 1) {	// L483
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v295
        v295[0][v297][v298][v299] = v296;	// L484
      }
    }
  }
}

void kernel91(
  float v300[32],
  float v301[1][32][4][4]
) {	// L490
  float v302[32];	// L491
  #pragma HLS resource variable=v302 core=ram_t2p_bram

  memcpy(v302, v300, 32 * sizeof(float));	// L492

  for (int v303 = 0; v303 < 32; v303 += 1) {	// L493
    for (int v304 = 0; v304 < 4; v304 += 1) {	// L494
      for (int v305 = 0; v305 < 4; v305 += 1) {	// L495
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v302
        #pragma HLS dependence false variable=v301
        float v306 = v302[v303];	// L496
        v301[0][v303][v304][v305] = v306;	// L497
      }
    }
  }
}

void kernel93(
  float v307[1][32][6][6],
  float v308
) {	// L503
  for (int v309 = 0; v309 < 32; v309 += 1) {	// L504
    for (int v310 = 0; v310 < 6; v310 += 1) {	// L505
      for (int v311 = 0; v311 < 6; v311 += 1) {	// L506
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v307
        v307[0][v309][v310][v311] = v308;	// L507
      }
    }
  }
}

void kernel95(
  float v312[1],
  float v313[1][32][4][4],
  float v314[1][32][4][4]
) {	// L513
  float v315[1];	// L514
  memcpy(v315, v312, 1 * sizeof(float));	// L515

  for (int v316 = 0; v316 < 32; v316 += 1) {	// L516
    for (int v317 = 0; v317 < 4; v317 += 1) {	// L517
      for (int v318 = 0; v318 < 4; v318 += 1) {	// L518
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v313
        #pragma HLS dependence false variable=v314
        #pragma HLS dependence false variable=v315
        float v319 = v313[0][v316][v317][v318];	// L519
        float v320 = v315[0];	// L520
        float v321 = v319 * v320;	// L521
        v314[0][v316][v317][v318] = v321;	// L522
      }
    }
  }
}

void kernel96(
  float v322[1],
  float v323[1],
  float v324
) {	// L528
  float v325 = v322[0];	// L529
  float v326 = -(v325);	// L530
  float v327 = exp(v326);	// L531
  float v328 = v327 + v324;	// L532
  float v329 = v324 / v328;	// L533
  v323[0] = v329;	// L534
}

void kernel98(
  float v330[1],
  float v331[1][32][4][4]
) {	// L537
  float v332[1];	// L538
  memcpy(v332, v330, 1 * sizeof(float));	// L539

  for (int v333 = 0; v333 < 32; v333 += 1) {	// L540
    for (int v334 = 0; v334 < 4; v334 += 1) {	// L541
      for (int v335 = 0; v335 < 4; v335 += 1) {	// L542
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v331
        #pragma HLS dependence false variable=v332
        float v336 = v331[0][v333][v334][v335];	// L543
        float v337 = v332[0];	// L544
        float v338 = v336 * v337;	// L545
        v331[0][v333][v334][v335] = v338;	// L546
      }
    }
  }
}

void kernel103(
  float v339[1][32][8][8],
  float v340[2][2],
  float v341[1][32][4][4]
) {	// L552
  for (int v342 = 0; v342 < 2; v342 += 1) {	// L553
    for (int v343 = 0; v343 < 2; v343 += 1) {	// L554
      for (int v344 = 0; v344 < 32; v344 += 1) {	// L555
        for (int v345 = 0; v345 < 4; v345 += 1) {	// L556
          for (int v346 = 0; v346 < 4; v346 += 1) {	// L557
            #pragma HLS pipeline II=1
            #pragma HLS dependence false variable=v339
            #pragma HLS dependence false variable=v341
            float v347 = v339[0][v344][((v345 * 2) + v342)][((v346 * 2) + v343)];	// L558
            float v348 = v341[0][v344][v345][v346];	// L559
            float v349 = v348 + v347;	// L560
            v341[0][v344][v345][v346] = v349;	// L561
          }
        }
      }
    }
  }
}

void kernel105(
  float v350[1][32][16][16],
  float v351[4][4],
  float v352[1][32][4][4]
) {	// L569
  for (int v353 = 0; v353 < 4; v353 += 1) {	// L570
    for (int v354 = 0; v354 < 4; v354 += 1) {	// L571
      for (int v355 = 0; v355 < 32; v355 += 1) {	// L572
        for (int v356 = 0; v356 < 4; v356 += 1) {	// L573
          for (int v357 = 0; v357 < 4; v357 += 1) {	// L574
            #pragma HLS pipeline II=1
            #pragma HLS dependence false variable=v350
            #pragma HLS dependence false variable=v352
            float v358 = v350[0][v355][((v356 * 4) + v353)][((v357 * 4) + v354)];	// L575
            float v359 = v352[0][v355][v356][v357];	// L576
            float v360 = v359 + v358;	// L577
            v352[0][v355][v356][v357] = v360;	// L578
          }
        }
      }
    }
  }
}

void kernel110(
  float v361[1][32][4][4],
  float v362
) {	// L586
  for (int v363 = 0; v363 < 32; v363 += 1) {	// L587
    for (int v364 = 0; v364 < 4; v364 += 1) {	// L588
      for (int v365 = 0; v365 < 4; v365 += 1) {	// L589
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v361
        v361[0][v363][v364][v365] = v362;	// L590
      }
    }
  }
}

void kernel111(
  float v366[1],
  float v367[1][32][8][8]
) {	// L596
  float v368[1];	// L597
  memcpy(v368, v366, 1 * sizeof(float));	// L598

  for (int v369 = 0; v369 < 32; v369 += 1) {	// L599
    for (int v370 = 0; v370 < 8; v370 += 1) {	// L600
      for (int v371 = 0; v371 < 8; v371 += 1) {	// L601
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v368
        #pragma HLS dependence false variable=v367
        float v372 = v368[0];	// L602
        float v373 = v367[0][v369][v370][v371];	// L603
        float v374 = v372 - v373;	// L604
        v367[0][v369][v370][v371] = v374;	// L605
      }
    }
  }
}

void kernel112(
  float v375[1][32][8][8],
  float v376[1][32][8][8]
) {	// L611
  for (int v377 = 0; v377 < 32; v377 += 1) {	// L612
    for (int v378 = 0; v378 < 8; v378 += 1) {	// L613
      for (int v379 = 0; v379 < 8; v379 += 1) {	// L614
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v375
        #pragma HLS dependence false variable=v376
        float v380 = v375[0][v377][v378][v379];	// L615
        float v381 = v376[0][v377][v378][v379];	// L616
        float v382 = v380 * v381;	// L617
        v376[0][v377][v378][v379] = v382;	// L618
      }
    }
  }
}

void kernel113(
  float v383[1][32][8][8],
  float v384[1],
  float v385[1][32][8][8]
) {	// L624
  float v386[1];	// L625
  memcpy(v386, v384, 1 * sizeof(float));	// L626

  for (int v387 = 0; v387 < 32; v387 += 1) {	// L627
    for (int v388 = 0; v388 < 8; v388 += 1) {	// L628
      for (int v389 = 0; v389 < 8; v389 += 1) {	// L629
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v386
        #pragma HLS dependence false variable=v383
        #pragma HLS dependence false variable=v385
        float v390 = v386[0];	// L630
        float v391 = v383[0][v387][v388][v389];	// L631
        float v392 = v390 - v391;	// L632
        v385[0][v387][v388][v389] = v392;	// L633
      }
    }
  }
}

void kernel115(
  float v393[1][32][8][8],
  float v394[1][32][8][8]
) {	// L639
  for (int v395 = 0; v395 < 32; v395 += 1) {	// L640
    for (int v396 = 0; v396 < 8; v396 += 1) {	// L641
      for (int v397 = 0; v397 < 8; v397 += 1) {	// L642
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v393
        #pragma HLS dependence false variable=v394
        float v398 = v393[0][v395][v396][v397];	// L643
        v394[0][v395][v396][v397] = v398;	// L644
      }
    }
  }
}

void kernel116(
  float v399[1][32][8][8],
  float v400[1][32][8][8]
) {	// L650
  for (int v401 = 0; v401 < 32; v401 += 1) {	// L651
    for (int v402 = 0; v402 < 8; v402 += 1) {	// L652
      for (int v403 = 0; v403 < 8; v403 += 1) {	// L653
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v399
        #pragma HLS dependence false variable=v400
        float v404 = v399[0][v401][v402][v403];	// L654
        float v405 = v400[0][v401][v402][v403];	// L655
        float v406 = v404 + v405;	// L656
        v400[0][v401][v402][v403] = v406;	// L657
      }
    }
  }
}

void kernel117(
  float v407[1][32][8][8],
  float v408
) {	// L663
  for (int v409 = 0; v409 < 32; v409 += 1) {	// L664
    for (int v410 = 0; v410 < 8; v410 += 1) {	// L665
      for (int v411 = 0; v411 < 8; v411 += 1) {	// L666
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v407
        float v412 = v407[0][v409][v410][v411];	// L667
        float v413 = v412 * v408;	// L668
        v407[0][v409][v410][v411] = v413;	// L669
      }
    }
  }
}

void kernel119(
  float v414[1][32][8][8],
  float v415[1][32][8][8],
  float v416[1][32][8][8]
) {	// L675
  for (int v417 = 0; v417 < 32; v417 += 1) {	// L676
    for (int v418 = 0; v418 < 8; v418 += 1) {	// L677
      for (int v419 = 0; v419 < 8; v419 += 1) {	// L678
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v415
        #pragma HLS dependence false variable=v416
        #pragma HLS dependence false variable=v414
        float v420 = v415[0][v417][v418][v419];	// L679
        float v421 = v414[0][v417][v418][v419];	// L680
        float v422 = v420 - v421;	// L681
        v416[0][v417][v418][v419] = v422;	// L682
      }
    }
  }
}

void kernel120(
  float v423[1][32][8][8],
  float v424,
  float v425
) {	// L688
  for (int v426 = 0; v426 < 32; v426 += 1) {	// L689
    for (int v427 = 0; v427 < 8; v427 += 1) {	// L690
      for (int v428 = 0; v428 < 8; v428 += 1) {	// L691
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v423
        float v429 = v423[0][v426][v427][v428];	// L692
        bool v430 = v429 >= v425;	// L693
        float v431 = v430 ? v424 : v425;	// L694
        v423[0][v426][v427][v428] = v431;	// L695
      }
    }
  }
}

void kernel122(
  float v432[1][32][8][8],
  float v433
) {	// L701
  for (int v434 = 0; v434 < 32; v434 += 1) {	// L702
    for (int v435 = 0; v435 < 8; v435 += 1) {	// L703
      for (int v436 = 0; v436 < 8; v436 += 1) {	// L704
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v432
        float v437 = v432[0][v434][v435][v436];	// L705
        float v438 = v437 - v433;	// L706
        v432[0][v434][v435][v436] = v438;	// L707
      }
    }
  }
}

void kernel124(
  float v439[1][32][8][8],
  float v440[1][32][8][8],
  float v441[1][32][8][8]
) {	// L713
  for (int v442 = 0; v442 < 32; v442 += 1) {	// L714
    for (int v443 = 0; v443 < 8; v443 += 1) {	// L715
      for (int v444 = 0; v444 < 8; v444 += 1) {	// L716
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v440
        #pragma HLS dependence false variable=v441
        #pragma HLS dependence false variable=v439
        float v445 = v440[0][v442][v443][v444];	// L717
        float v446 = v439[0][v442][v443][v444];	// L718
        float v447 = v445 + v446;	// L719
        v441[0][v442][v443][v444] = v447;	// L720
      }
    }
  }
}

void kernel125(
  float v448[1][32][8][8],
  float v449
) {	// L726
  for (int v450 = 0; v450 < 32; v450 += 1) {	// L727
    for (int v451 = 0; v451 < 8; v451 += 1) {	// L728
      for (int v452 = 0; v452 < 8; v452 += 1) {	// L729
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v448
        float v453 = v448[0][v450][v451][v452];	// L730
        float v454 = v453 / v449;	// L731
        v448[0][v450][v451][v452] = v454;	// L732
      }
    }
  }
}

void kernel130(
  float v455[1][32][10][10],
  float v456[32][32][3][3],
  float v457[1][32][8][8]
) {	// L738
  float v458[32][32][3][3];	// L739
  #pragma HLS resource variable=v458 core=ram_t2p_bram

  memcpy(v458, v456, 9216 * sizeof(float));	// L740

  for (int v459 = 0; v459 < 32; v459 += 1) {	// L741
    for (int v460 = 0; v460 < 3; v460 += 1) {	// L742
      for (int v461 = 0; v461 < 3; v461 += 1) {	// L743
        for (int v462 = 0; v462 < 32; v462 += 1) {	// L744
          for (int v463 = 0; v463 < 8; v463 += 1) {	// L745
            for (int v464 = 0; v464 < 8; v464 += 1) {	// L746
              #pragma HLS pipeline II=1
              #pragma HLS dependence false variable=v455
              #pragma HLS dependence false variable=v457
              #pragma HLS dependence false variable=v458
              float v465 = v455[0][v459][(v463 + v460)][(v464 + v461)];	// L747
              float v466 = v458[v462][v459][v460][v461];	// L748
              float v467 = v457[0][v462][v463][v464];	// L749
              float v468 = v465 * v466;	// L750
              float v469 = v467 + v468;	// L751
              v457[0][v462][v463][v464] = v469;	// L752
            }
          }
        }
      }
    }
  }
}

void kernel131(
  float v470[1][32][8][8],
  float v471[1][32][10][10]
) {	// L761
  for (int v472 = 0; v472 < 32; v472 += 1) {	// L762
    for (int v473 = 0; v473 < 8; v473 += 1) {	// L763
      for (int v474 = 0; v474 < 8; v474 += 1) {	// L764
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v470
        #pragma HLS dependence false variable=v471
        float v475 = v470[0][v472][v473][v474];	// L765
        v471[0][v472][(v473 + 1)][(v474 + 1)] = v475;	// L766
      }
    }
  }
}

void kernel132(
  float v476[1][32][10][10],
  float v477
) {	// L772
  for (int v478 = 0; v478 < 32; v478 += 1) {	// L773
    for (int v479 = 0; v479 < 10; v479 += 1) {	// L774
      for (int v480 = 0; v480 < 10; v480 += 1) {	// L775
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v476
        v476[0][v478][v479][v480] = v477;	// L776
      }
    }
  }
}

void kernel150(
  float v481[32],
  float v482[1][32][8][8]
) {	// L782
  float v483[32];	// L783
  #pragma HLS resource variable=v483 core=ram_t2p_bram

  memcpy(v483, v481, 32 * sizeof(float));	// L784

  for (int v484 = 0; v484 < 32; v484 += 1) {	// L785
    for (int v485 = 0; v485 < 8; v485 += 1) {	// L786
      for (int v486 = 0; v486 < 8; v486 += 1) {	// L787
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v483
        #pragma HLS dependence false variable=v482
        float v487 = v483[v484];	// L788
        v482[0][v484][v485][v486] = v487;	// L789
      }
    }
  }
}

void kernel152(
  float v488[1][32][10][10],
  float v489
) {	// L795
  for (int v490 = 0; v490 < 32; v490 += 1) {	// L796
    for (int v491 = 0; v491 < 10; v491 += 1) {	// L797
      for (int v492 = 0; v492 < 10; v492 += 1) {	// L798
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v488
        v488[0][v490][v491][v492] = v489;	// L799
      }
    }
  }
}

void kernel155(
  float v493[1][32][16][16],
  float v494[2][2],
  float v495[1][32][8][8]
) {	// L805
  for (int v496 = 0; v496 < 2; v496 += 1) {	// L806
    for (int v497 = 0; v497 < 2; v497 += 1) {	// L807
      for (int v498 = 0; v498 < 32; v498 += 1) {	// L808
        for (int v499 = 0; v499 < 8; v499 += 1) {	// L809
          for (int v500 = 0; v500 < 8; v500 += 1) {	// L810
            #pragma HLS pipeline II=1
            #pragma HLS dependence false variable=v493
            #pragma HLS dependence false variable=v495
            float v501 = v493[0][v498][((v499 * 2) + v496)][((v500 * 2) + v497)];	// L811
            float v502 = v495[0][v498][v499][v500];	// L812
            float v503 = v502 + v501;	// L813
            v495[0][v498][v499][v500] = v503;	// L814
          }
        }
      }
    }
  }
}

void kernel156(
  float v504[1][32][8][8],
  float v505
) {	// L822
  for (int v506 = 0; v506 < 32; v506 += 1) {	// L823
    for (int v507 = 0; v507 < 8; v507 += 1) {	// L824
      for (int v508 = 0; v508 < 8; v508 += 1) {	// L825
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v504
        v504[0][v506][v507][v508] = v505;	// L826
      }
    }
  }
}

void kernel157(
  float v509[1],
  float v510[1][32][16][16]
) {	// L832
  float v511[1];	// L833
  memcpy(v511, v509, 1 * sizeof(float));	// L834

  for (int v512 = 0; v512 < 32; v512 += 1) {	// L835
    for (int v513 = 0; v513 < 16; v513 += 1) {	// L836
      for (int v514 = 0; v514 < 16; v514 += 1) {	// L837
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v511
        #pragma HLS dependence false variable=v510
        float v515 = v511[0];	// L838
        float v516 = v510[0][v512][v513][v514];	// L839
        float v517 = v515 - v516;	// L840
        v510[0][v512][v513][v514] = v517;	// L841
      }
    }
  }
}

void kernel158(
  float v518[1][32][16][16],
  float v519[1][32][16][16]
) {	// L847
  for (int v520 = 0; v520 < 32; v520 += 1) {	// L848
    for (int v521 = 0; v521 < 16; v521 += 1) {	// L849
      for (int v522 = 0; v522 < 16; v522 += 1) {	// L850
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v518
        #pragma HLS dependence false variable=v519
        float v523 = v518[0][v520][v521][v522];	// L851
        float v524 = v519[0][v520][v521][v522];	// L852
        float v525 = v523 * v524;	// L853
        v519[0][v520][v521][v522] = v525;	// L854
      }
    }
  }
}

void kernel159(
  float v526[1][32][16][16],
  float v527[1],
  float v528[1][32][16][16]
) {	// L860
  float v529[1];	// L861
  memcpy(v529, v527, 1 * sizeof(float));	// L862

  for (int v530 = 0; v530 < 32; v530 += 1) {	// L863
    for (int v531 = 0; v531 < 16; v531 += 1) {	// L864
      for (int v532 = 0; v532 < 16; v532 += 1) {	// L865
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v529
        #pragma HLS dependence false variable=v526
        #pragma HLS dependence false variable=v528
        float v533 = v529[0];	// L866
        float v534 = v526[0][v530][v531][v532];	// L867
        float v535 = v533 - v534;	// L868
        v528[0][v530][v531][v532] = v535;	// L869
      }
    }
  }
}

void kernel161(
  float v536[1][32][16][16],
  float v537[1][32][16][16]
) {	// L875
  for (int v538 = 0; v538 < 32; v538 += 1) {	// L876
    for (int v539 = 0; v539 < 16; v539 += 1) {	// L877
      for (int v540 = 0; v540 < 16; v540 += 1) {	// L878
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v536
        #pragma HLS dependence false variable=v537
        float v541 = v536[0][v538][v539][v540];	// L879
        v537[0][v538][v539][v540] = v541;	// L880
      }
    }
  }
}

void kernel162(
  float v542[1][32][16][16],
  float v543[1][32][16][16]
) {	// L886
  for (int v544 = 0; v544 < 32; v544 += 1) {	// L887
    for (int v545 = 0; v545 < 16; v545 += 1) {	// L888
      for (int v546 = 0; v546 < 16; v546 += 1) {	// L889
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v542
        #pragma HLS dependence false variable=v543
        float v547 = v542[0][v544][v545][v546];	// L890
        float v548 = v543[0][v544][v545][v546];	// L891
        float v549 = v547 + v548;	// L892
        v543[0][v544][v545][v546] = v549;	// L893
      }
    }
  }
}

void kernel163(
  float v550[1][32][16][16],
  float v551
) {	// L899
  for (int v552 = 0; v552 < 32; v552 += 1) {	// L900
    for (int v553 = 0; v553 < 16; v553 += 1) {	// L901
      for (int v554 = 0; v554 < 16; v554 += 1) {	// L902
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v550
        float v555 = v550[0][v552][v553][v554];	// L903
        float v556 = v555 * v551;	// L904
        v550[0][v552][v553][v554] = v556;	// L905
      }
    }
  }
}

void kernel165(
  float v557[1][32][16][16],
  float v558[1][32][16][16],
  float v559[1][32][16][16]
) {	// L911
  for (int v560 = 0; v560 < 32; v560 += 1) {	// L912
    for (int v561 = 0; v561 < 16; v561 += 1) {	// L913
      for (int v562 = 0; v562 < 16; v562 += 1) {	// L914
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v558
        #pragma HLS dependence false variable=v559
        #pragma HLS dependence false variable=v557
        float v563 = v558[0][v560][v561][v562];	// L915
        float v564 = v557[0][v560][v561][v562];	// L916
        float v565 = v563 - v564;	// L917
        v559[0][v560][v561][v562] = v565;	// L918
      }
    }
  }
}

void kernel166(
  float v566[1][32][16][16],
  float v567,
  float v568
) {	// L924
  for (int v569 = 0; v569 < 32; v569 += 1) {	// L925
    for (int v570 = 0; v570 < 16; v570 += 1) {	// L926
      for (int v571 = 0; v571 < 16; v571 += 1) {	// L927
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v566
        float v572 = v566[0][v569][v570][v571];	// L928
        bool v573 = v572 >= v568;	// L929
        float v574 = v573 ? v567 : v568;	// L930
        v566[0][v569][v570][v571] = v574;	// L931
      }
    }
  }
}

void kernel168(
  float v575[1][32][16][16],
  float v576
) {	// L937
  for (int v577 = 0; v577 < 32; v577 += 1) {	// L938
    for (int v578 = 0; v578 < 16; v578 += 1) {	// L939
      for (int v579 = 0; v579 < 16; v579 += 1) {	// L940
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v575
        float v580 = v575[0][v577][v578][v579];	// L941
        float v581 = v580 - v576;	// L942
        v575[0][v577][v578][v579] = v581;	// L943
      }
    }
  }
}

void kernel170(
  float v582[1][32][16][16],
  float v583[1][32][16][16],
  float v584[1][32][16][16]
) {	// L949
  for (int v585 = 0; v585 < 32; v585 += 1) {	// L950
    for (int v586 = 0; v586 < 16; v586 += 1) {	// L951
      for (int v587 = 0; v587 < 16; v587 += 1) {	// L952
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v583
        #pragma HLS dependence false variable=v584
        #pragma HLS dependence false variable=v582
        float v588 = v583[0][v585][v586][v587];	// L953
        float v589 = v582[0][v585][v586][v587];	// L954
        float v590 = v588 + v589;	// L955
        v584[0][v585][v586][v587] = v590;	// L956
      }
    }
  }
}

void kernel171(
  float v591[1][32][16][16],
  float v592
) {	// L962
  for (int v593 = 0; v593 < 32; v593 += 1) {	// L963
    for (int v594 = 0; v594 < 16; v594 += 1) {	// L964
      for (int v595 = 0; v595 < 16; v595 += 1) {	// L965
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v591
        float v596 = v591[0][v593][v594][v595];	// L966
        float v597 = v596 / v592;	// L967
        v591[0][v593][v594][v595] = v597;	// L968
      }
    }
  }
}

void kernel176(
  float v598[1][32][18][18],
  float v599[32][32][3][3],
  float v600[1][32][16][16]
) {	// L974
  float v601[32][32][3][3];	// L975
  #pragma HLS resource variable=v601 core=ram_t2p_bram

  memcpy(v601, v599, 9216 * sizeof(float));	// L976

  for (int v602 = 0; v602 < 32; v602 += 1) {	// L977
    for (int v603 = 0; v603 < 3; v603 += 1) {	// L978
      for (int v604 = 0; v604 < 3; v604 += 1) {	// L979
        for (int v605 = 0; v605 < 32; v605 += 1) {	// L980
          for (int v606 = 0; v606 < 16; v606 += 1) {	// L981
            for (int v607 = 0; v607 < 16; v607 += 1) {	// L982
              #pragma HLS pipeline II=1
              #pragma HLS dependence false variable=v598
              #pragma HLS dependence false variable=v600
              #pragma HLS dependence false variable=v601
              float v608 = v598[0][v602][(v606 + v603)][(v607 + v604)];	// L983
              float v609 = v601[v605][v602][v603][v604];	// L984
              float v610 = v600[0][v605][v606][v607];	// L985
              float v611 = v608 * v609;	// L986
              float v612 = v610 + v611;	// L987
              v600[0][v605][v606][v607] = v612;	// L988
            }
          }
        }
      }
    }
  }
}

void kernel177(
  float v613[1][32][16][16],
  float v614[1][32][18][18]
) {	// L997
  for (int v615 = 0; v615 < 32; v615 += 1) {	// L998
    for (int v616 = 0; v616 < 16; v616 += 1) {	// L999
      for (int v617 = 0; v617 < 16; v617 += 1) {	// L1000
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v613
        #pragma HLS dependence false variable=v614
        float v618 = v613[0][v615][v616][v617];	// L1001
        v614[0][v615][(v616 + 1)][(v617 + 1)] = v618;	// L1002
      }
    }
  }
}

void kernel178(
  float v619[1][32][18][18],
  float v620
) {	// L1008
  for (int v621 = 0; v621 < 32; v621 += 1) {	// L1009
    for (int v622 = 0; v622 < 18; v622 += 1) {	// L1010
      for (int v623 = 0; v623 < 18; v623 += 1) {	// L1011
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v619
        v619[0][v621][v622][v623] = v620;	// L1012
      }
    }
  }
}

void kernel196(
  float v624[32],
  float v625[1][32][16][16]
) {	// L1018
  float v626[32];	// L1019
  #pragma HLS resource variable=v626 core=ram_t2p_bram

  memcpy(v626, v624, 32 * sizeof(float));	// L1020

  for (int v627 = 0; v627 < 32; v627 += 1) {	// L1021
    for (int v628 = 0; v628 < 16; v628 += 1) {	// L1022
      for (int v629 = 0; v629 < 16; v629 += 1) {	// L1023
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v626
        #pragma HLS dependence false variable=v625
        float v630 = v626[v627];	// L1024
        v625[0][v627][v628][v629] = v630;	// L1025
      }
    }
  }
}

void kernel198(
  float v631[1][32][18][18],
  float v632
) {	// L1031
  for (int v633 = 0; v633 < 32; v633 += 1) {	// L1032
    for (int v634 = 0; v634 < 18; v634 += 1) {	// L1033
      for (int v635 = 0; v635 < 18; v635 += 1) {	// L1034
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v631
        v631[0][v633][v634][v635] = v632;	// L1035
      }
    }
  }
}

void kernel200(
  float v636[1],
  float v637[1][32][16][16],
  float v638[1][32][16][16]
) {	// L1041
  float v639[1];	// L1042
  memcpy(v639, v636, 1 * sizeof(float));	// L1043

  for (int v640 = 0; v640 < 32; v640 += 1) {	// L1044
    for (int v641 = 0; v641 < 16; v641 += 1) {	// L1045
      for (int v642 = 0; v642 < 16; v642 += 1) {	// L1046
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v637
        #pragma HLS dependence false variable=v638
        #pragma HLS dependence false variable=v639
        float v643 = v637[0][v640][v641][v642];	// L1047
        float v644 = v639[0];	// L1048
        float v645 = v643 * v644;	// L1049
        v638[0][v640][v641][v642] = v645;	// L1050
      }
    }
  }
}

void kernel205(
  float v646[1][32][32][32],
  float v647[2][2],
  float v648[1][32][16][16]
) {	// L1056
  for (int v649 = 0; v649 < 2; v649 += 1) {	// L1057
    for (int v650 = 0; v650 < 2; v650 += 1) {	// L1058
      for (int v651 = 0; v651 < 32; v651 += 1) {	// L1059
        for (int v652 = 0; v652 < 16; v652 += 1) {	// L1060
          for (int v653 = 0; v653 < 16; v653 += 1) {	// L1061
            #pragma HLS pipeline II=1
            #pragma HLS dependence false variable=v646
            #pragma HLS dependence false variable=v648
            float v654 = v646[0][v651][((v652 * 2) + v649)][((v653 * 2) + v650)];	// L1062
            float v655 = v648[0][v651][v652][v653];	// L1063
            float v656 = v655 + v654;	// L1064
            v648[0][v651][v652][v653] = v656;	// L1065
          }
        }
      }
    }
  }
}

void kernel209(
  float v657[1][32][16][16],
  float v658
) {	// L1073
  for (int v659 = 0; v659 < 32; v659 += 1) {	// L1074
    for (int v660 = 0; v660 < 16; v660 += 1) {	// L1075
      for (int v661 = 0; v661 < 16; v661 += 1) {	// L1076
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v657
        v657[0][v659][v660][v661] = v658;	// L1077
      }
    }
  }
}

void kernel210(
  float v662[1],
  float v663[1][32][32][32]
) {	// L1083
  float v664[1];	// L1084
  memcpy(v664, v662, 1 * sizeof(float));	// L1085

  for (int v665 = 0; v665 < 32; v665 += 1) {	// L1086
    for (int v666 = 0; v666 < 32; v666 += 1) {	// L1087
      for (int v667 = 0; v667 < 32; v667 += 1) {	// L1088
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v664
        #pragma HLS dependence false variable=v663
        float v668 = v664[0];	// L1089
        float v669 = v663[0][v665][v666][v667];	// L1090
        float v670 = v668 - v669;	// L1091
        v663[0][v665][v666][v667] = v670;	// L1092
      }
    }
  }
}

void kernel211(
  float v671[1][32][32][32],
  float v672[1][32][32][32]
) {	// L1098
  for (int v673 = 0; v673 < 32; v673 += 1) {	// L1099
    for (int v674 = 0; v674 < 32; v674 += 1) {	// L1100
      for (int v675 = 0; v675 < 32; v675 += 1) {	// L1101
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v671
        #pragma HLS dependence false variable=v672
        float v676 = v671[0][v673][v674][v675];	// L1102
        float v677 = v672[0][v673][v674][v675];	// L1103
        float v678 = v676 * v677;	// L1104
        v672[0][v673][v674][v675] = v678;	// L1105
      }
    }
  }
}

void kernel212(
  float v679[1][32][32][32],
  float v680[1],
  float v681[1][32][32][32]
) {	// L1111
  float v682[1];	// L1112
  memcpy(v682, v680, 1 * sizeof(float));	// L1113

  for (int v683 = 0; v683 < 32; v683 += 1) {	// L1114
    for (int v684 = 0; v684 < 32; v684 += 1) {	// L1115
      for (int v685 = 0; v685 < 32; v685 += 1) {	// L1116
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v682
        #pragma HLS dependence false variable=v679
        #pragma HLS dependence false variable=v681
        float v686 = v682[0];	// L1117
        float v687 = v679[0][v683][v684][v685];	// L1118
        float v688 = v686 - v687;	// L1119
        v681[0][v683][v684][v685] = v688;	// L1120
      }
    }
  }
}

void kernel214(
  float v689[1][32][32][32],
  float v690[1][32][32][32]
) {	// L1126
  for (int v691 = 0; v691 < 32; v691 += 1) {	// L1127
    for (int v692 = 0; v692 < 32; v692 += 1) {	// L1128
      for (int v693 = 0; v693 < 32; v693 += 1) {	// L1129
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v689
        #pragma HLS dependence false variable=v690
        float v694 = v689[0][v691][v692][v693];	// L1130
        v690[0][v691][v692][v693] = v694;	// L1131
      }
    }
  }
}

void kernel215(
  float v695[1][32][32][32],
  float v696[1][32][32][32]
) {	// L1137
  for (int v697 = 0; v697 < 32; v697 += 1) {	// L1138
    for (int v698 = 0; v698 < 32; v698 += 1) {	// L1139
      for (int v699 = 0; v699 < 32; v699 += 1) {	// L1140
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v695
        #pragma HLS dependence false variable=v696
        float v700 = v695[0][v697][v698][v699];	// L1141
        float v701 = v696[0][v697][v698][v699];	// L1142
        float v702 = v700 + v701;	// L1143
        v696[0][v697][v698][v699] = v702;	// L1144
      }
    }
  }
}

void kernel216(
  float v703[1][32][32][32],
  float v704
) {	// L1150
  for (int v705 = 0; v705 < 32; v705 += 1) {	// L1151
    for (int v706 = 0; v706 < 32; v706 += 1) {	// L1152
      for (int v707 = 0; v707 < 32; v707 += 1) {	// L1153
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v703
        float v708 = v703[0][v705][v706][v707];	// L1154
        float v709 = v708 * v704;	// L1155
        v703[0][v705][v706][v707] = v709;	// L1156
      }
    }
  }
}

void kernel218(
  float v710[1][32][32][32],
  float v711[1][32][32][32],
  float v712[1][32][32][32]
) {	// L1162
  for (int v713 = 0; v713 < 32; v713 += 1) {	// L1163
    for (int v714 = 0; v714 < 32; v714 += 1) {	// L1164
      for (int v715 = 0; v715 < 32; v715 += 1) {	// L1165
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v711
        #pragma HLS dependence false variable=v712
        #pragma HLS dependence false variable=v710
        float v716 = v711[0][v713][v714][v715];	// L1166
        float v717 = v710[0][v713][v714][v715];	// L1167
        float v718 = v716 - v717;	// L1168
        v712[0][v713][v714][v715] = v718;	// L1169
      }
    }
  }
}

void kernel219(
  float v719[1][32][32][32],
  float v720,
  float v721
) {	// L1175
  for (int v722 = 0; v722 < 32; v722 += 1) {	// L1176
    for (int v723 = 0; v723 < 32; v723 += 1) {	// L1177
      for (int v724 = 0; v724 < 32; v724 += 1) {	// L1178
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v719
        float v725 = v719[0][v722][v723][v724];	// L1179
        bool v726 = v725 >= v721;	// L1180
        float v727 = v726 ? v720 : v721;	// L1181
        v719[0][v722][v723][v724] = v727;	// L1182
      }
    }
  }
}

void kernel221(
  float v728[1][32][32][32],
  float v729
) {	// L1188
  for (int v730 = 0; v730 < 32; v730 += 1) {	// L1189
    for (int v731 = 0; v731 < 32; v731 += 1) {	// L1190
      for (int v732 = 0; v732 < 32; v732 += 1) {	// L1191
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v728
        float v733 = v728[0][v730][v731][v732];	// L1192
        float v734 = v733 - v729;	// L1193
        v728[0][v730][v731][v732] = v734;	// L1194
      }
    }
  }
}

void kernel223(
  float v735[1][32][32][32],
  float v736[1][32][32][32],
  float v737[1][32][32][32]
) {	// L1200
  for (int v738 = 0; v738 < 32; v738 += 1) {	// L1201
    for (int v739 = 0; v739 < 32; v739 += 1) {	// L1202
      for (int v740 = 0; v740 < 32; v740 += 1) {	// L1203
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v736
        #pragma HLS dependence false variable=v737
        #pragma HLS dependence false variable=v735
        float v741 = v736[0][v738][v739][v740];	// L1204
        float v742 = v735[0][v738][v739][v740];	// L1205
        float v743 = v741 + v742;	// L1206
        v737[0][v738][v739][v740] = v743;	// L1207
      }
    }
  }
}

void kernel224(
  float v744[1][32][32][32],
  float v745
) {	// L1213
  for (int v746 = 0; v746 < 32; v746 += 1) {	// L1214
    for (int v747 = 0; v747 < 32; v747 += 1) {	// L1215
      for (int v748 = 0; v748 < 32; v748 += 1) {	// L1216
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v744
        float v749 = v744[0][v746][v747][v748];	// L1217
        float v750 = v749 / v745;	// L1218
        v744[0][v746][v747][v748] = v750;	// L1219
      }
    }
  }
}

void kernel229(
  float v751[1][32][34][34],
  float v752[32][32][3][3],
  float v753[1][32][32][32]
) {	// L1225
  float v754[32][32][3][3];	// L1226
  #pragma HLS resource variable=v754 core=ram_t2p_bram

  memcpy(v754, v752, 9216 * sizeof(float));	// L1227

  for (int v755 = 0; v755 < 32; v755 += 1) {	// L1228
    for (int v756 = 0; v756 < 3; v756 += 1) {	// L1229
      for (int v757 = 0; v757 < 3; v757 += 1) {	// L1230
        for (int v758 = 0; v758 < 32; v758 += 1) {	// L1231
          for (int v759 = 0; v759 < 32; v759 += 1) {	// L1232
            for (int v760 = 0; v760 < 32; v760 += 1) {	// L1233
              #pragma HLS pipeline II=1
              #pragma HLS dependence false variable=v751
              #pragma HLS dependence false variable=v753
              #pragma HLS dependence false variable=v754
              float v761 = v751[0][v755][(v759 + v756)][(v760 + v757)];	// L1234
              float v762 = v754[v758][v755][v756][v757];	// L1235
              float v763 = v753[0][v758][v759][v760];	// L1236
              float v764 = v761 * v762;	// L1237
              float v765 = v763 + v764;	// L1238
              v753[0][v758][v759][v760] = v765;	// L1239
            }
          }
        }
      }
    }
  }
}

void kernel230(
  float v766[1][32][32][32],
  float v767[1][32][34][34]
) {	// L1248
  for (int v768 = 0; v768 < 32; v768 += 1) {	// L1249
    for (int v769 = 0; v769 < 32; v769 += 1) {	// L1250
      for (int v770 = 0; v770 < 32; v770 += 1) {	// L1251
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v766
        #pragma HLS dependence false variable=v767
        float v771 = v766[0][v768][v769][v770];	// L1252
        v767[0][v768][(v769 + 1)][(v770 + 1)] = v771;	// L1253
      }
    }
  }
}

void kernel231(
  float v772[1][32][34][34],
  float v773
) {	// L1259
  for (int v774 = 0; v774 < 32; v774 += 1) {	// L1260
    for (int v775 = 0; v775 < 34; v775 += 1) {	// L1261
      for (int v776 = 0; v776 < 34; v776 += 1) {	// L1262
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v772
        v772[0][v774][v775][v776] = v773;	// L1263
      }
    }
  }
}

void kernel249(
  float v777[32],
  float v778[1][32][32][32]
) {	// L1269
  float v779[32];	// L1270
  #pragma HLS resource variable=v779 core=ram_t2p_bram

  memcpy(v779, v777, 32 * sizeof(float));	// L1271

  for (int v780 = 0; v780 < 32; v780 += 1) {	// L1272
    for (int v781 = 0; v781 < 32; v781 += 1) {	// L1273
      for (int v782 = 0; v782 < 32; v782 += 1) {	// L1274
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v779
        #pragma HLS dependence false variable=v778
        float v783 = v779[v780];	// L1275
        v778[0][v780][v781][v782] = v783;	// L1276
      }
    }
  }
}

void kernel251(
  float v784[1][32][34][34],
  float v785
) {	// L1282
  for (int v786 = 0; v786 < 32; v786 += 1) {	// L1283
    for (int v787 = 0; v787 < 34; v787 += 1) {	// L1284
      for (int v788 = 0; v788 < 34; v788 += 1) {	// L1285
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v784
        v784[0][v786][v787][v788] = v785;	// L1286
      }
    }
  }
}

void kernel254(
  float v789[1][32][64][64],
  float v790[2][2],
  float v791[1][32][32][32]
) {	// L1292
  for (int v792 = 0; v792 < 2; v792 += 1) {	// L1293
    for (int v793 = 0; v793 < 2; v793 += 1) {	// L1294
      for (int v794 = 0; v794 < 32; v794 += 1) {	// L1295
        for (int v795 = 0; v795 < 32; v795 += 1) {	// L1296
          for (int v796 = 0; v796 < 32; v796 += 1) {	// L1297
            #pragma HLS pipeline II=1
            #pragma HLS dependence false variable=v789
            #pragma HLS dependence false variable=v791
            float v797 = v789[0][v794][((v795 * 2) + v792)][((v796 * 2) + v793)];	// L1298
            float v798 = v791[0][v794][v795][v796];	// L1299
            float v799 = v798 + v797;	// L1300
            v791[0][v794][v795][v796] = v799;	// L1301
          }
        }
      }
    }
  }
}

void kernel255(
  float v800[1][32][32][32],
  float v801
) {	// L1309
  for (int v802 = 0; v802 < 32; v802 += 1) {	// L1310
    for (int v803 = 0; v803 < 32; v803 += 1) {	// L1311
      for (int v804 = 0; v804 < 32; v804 += 1) {	// L1312
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v800
        v800[0][v802][v803][v804] = v801;	// L1313
      }
    }
  }
}

void kernel256(
  float v805[1],
  float v806[1][32][64][64]
) {	// L1319
  float v807[1];	// L1320
  memcpy(v807, v805, 1 * sizeof(float));	// L1321

  for (int v808 = 0; v808 < 32; v808 += 1) {	// L1322
    for (int v809 = 0; v809 < 64; v809 += 1) {	// L1323
      for (int v810 = 0; v810 < 64; v810 += 1) {	// L1324
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v807
        #pragma HLS dependence false variable=v806
        float v811 = v807[0];	// L1325
        float v812 = v806[0][v808][v809][v810];	// L1326
        float v813 = v811 - v812;	// L1327
        v806[0][v808][v809][v810] = v813;	// L1328
      }
    }
  }
}

void kernel257(
  float v814[1][32][64][64],
  float v815[1][32][64][64]
) {	// L1334
  for (int v816 = 0; v816 < 32; v816 += 1) {	// L1335
    for (int v817 = 0; v817 < 64; v817 += 1) {	// L1336
      for (int v818 = 0; v818 < 64; v818 += 1) {	// L1337
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v814
        #pragma HLS dependence false variable=v815
        float v819 = v814[0][v816][v817][v818];	// L1338
        float v820 = v815[0][v816][v817][v818];	// L1339
        float v821 = v819 * v820;	// L1340
        v815[0][v816][v817][v818] = v821;	// L1341
      }
    }
  }
}

void kernel258(
  float v822[1][32][64][64],
  float v823[1],
  float v824[1][32][64][64]
) {	// L1347
  float v825[1];	// L1348
  memcpy(v825, v823, 1 * sizeof(float));	// L1349

  for (int v826 = 0; v826 < 32; v826 += 1) {	// L1350
    for (int v827 = 0; v827 < 64; v827 += 1) {	// L1351
      for (int v828 = 0; v828 < 64; v828 += 1) {	// L1352
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v825
        #pragma HLS dependence false variable=v822
        #pragma HLS dependence false variable=v824
        float v829 = v825[0];	// L1353
        float v830 = v822[0][v826][v827][v828];	// L1354
        float v831 = v829 - v830;	// L1355
        v824[0][v826][v827][v828] = v831;	// L1356
      }
    }
  }
}

void kernel260(
  float v832[1][32][64][64],
  float v833[1][32][64][64]
) {	// L1362
  for (int v834 = 0; v834 < 32; v834 += 1) {	// L1363
    for (int v835 = 0; v835 < 64; v835 += 1) {	// L1364
      for (int v836 = 0; v836 < 64; v836 += 1) {	// L1365
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v832
        #pragma HLS dependence false variable=v833
        float v837 = v832[0][v834][v835][v836];	// L1366
        v833[0][v834][v835][v836] = v837;	// L1367
      }
    }
  }
}

void kernel261(
  float v838[1][32][64][64],
  float v839[1][32][64][64]
) {	// L1373
  for (int v840 = 0; v840 < 32; v840 += 1) {	// L1374
    for (int v841 = 0; v841 < 64; v841 += 1) {	// L1375
      for (int v842 = 0; v842 < 64; v842 += 1) {	// L1376
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v838
        #pragma HLS dependence false variable=v839
        float v843 = v838[0][v840][v841][v842];	// L1377
        float v844 = v839[0][v840][v841][v842];	// L1378
        float v845 = v843 + v844;	// L1379
        v839[0][v840][v841][v842] = v845;	// L1380
      }
    }
  }
}

void kernel262(
  float v846[1][32][64][64],
  float v847
) {	// L1386
  for (int v848 = 0; v848 < 32; v848 += 1) {	// L1387
    for (int v849 = 0; v849 < 64; v849 += 1) {	// L1388
      for (int v850 = 0; v850 < 64; v850 += 1) {	// L1389
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v846
        float v851 = v846[0][v848][v849][v850];	// L1390
        float v852 = v851 * v847;	// L1391
        v846[0][v848][v849][v850] = v852;	// L1392
      }
    }
  }
}

void kernel264(
  float v853[1][32][64][64],
  float v854[1][32][64][64],
  float v855[1][32][64][64]
) {	// L1398
  for (int v856 = 0; v856 < 32; v856 += 1) {	// L1399
    for (int v857 = 0; v857 < 64; v857 += 1) {	// L1400
      for (int v858 = 0; v858 < 64; v858 += 1) {	// L1401
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v854
        #pragma HLS dependence false variable=v855
        #pragma HLS dependence false variable=v853
        float v859 = v854[0][v856][v857][v858];	// L1402
        float v860 = v853[0][v856][v857][v858];	// L1403
        float v861 = v859 - v860;	// L1404
        v855[0][v856][v857][v858] = v861;	// L1405
      }
    }
  }
}

void kernel265(
  float v862[1][32][64][64],
  float v863,
  float v864
) {	// L1411
  for (int v865 = 0; v865 < 32; v865 += 1) {	// L1412
    for (int v866 = 0; v866 < 64; v866 += 1) {	// L1413
      for (int v867 = 0; v867 < 64; v867 += 1) {	// L1414
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v862
        float v868 = v862[0][v865][v866][v867];	// L1415
        bool v869 = v868 >= v864;	// L1416
        float v870 = v869 ? v863 : v864;	// L1417
        v862[0][v865][v866][v867] = v870;	// L1418
      }
    }
  }
}

void kernel267(
  float v871[1][32][64][64],
  float v872
) {	// L1424
  for (int v873 = 0; v873 < 32; v873 += 1) {	// L1425
    for (int v874 = 0; v874 < 64; v874 += 1) {	// L1426
      for (int v875 = 0; v875 < 64; v875 += 1) {	// L1427
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v871
        float v876 = v871[0][v873][v874][v875];	// L1428
        float v877 = v876 - v872;	// L1429
        v871[0][v873][v874][v875] = v877;	// L1430
      }
    }
  }
}

void kernel269(
  float v878[1][32][64][64],
  float v879[1][32][64][64],
  float v880[1][32][64][64]
) {	// L1436
  for (int v881 = 0; v881 < 32; v881 += 1) {	// L1437
    for (int v882 = 0; v882 < 64; v882 += 1) {	// L1438
      for (int v883 = 0; v883 < 64; v883 += 1) {	// L1439
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v879
        #pragma HLS dependence false variable=v880
        #pragma HLS dependence false variable=v878
        float v884 = v879[0][v881][v882][v883];	// L1440
        float v885 = v878[0][v881][v882][v883];	// L1441
        float v886 = v884 + v885;	// L1442
        v880[0][v881][v882][v883] = v886;	// L1443
      }
    }
  }
}

void kernel270(
  float v887[1][32][64][64],
  float v888
) {	// L1449
  for (int v889 = 0; v889 < 32; v889 += 1) {	// L1450
    for (int v890 = 0; v890 < 64; v890 += 1) {	// L1451
      for (int v891 = 0; v891 < 64; v891 += 1) {	// L1452
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v887
        float v892 = v887[0][v889][v890][v891];	// L1453
        float v893 = v892 / v888;	// L1454
        v887[0][v889][v890][v891] = v893;	// L1455
      }
    }
  }
}

void kernel275(
  float v894[1][32][66][66],
  float v895[32][32][3][3],
  float v896[1][32][64][64]
) {	// L1461
  float v897[32][32][3][3];	// L1462
  #pragma HLS resource variable=v897 core=ram_t2p_bram

  memcpy(v897, v895, 9216 * sizeof(float));	// L1463

  for (int v898 = 0; v898 < 32; v898 += 1) {	// L1464
    for (int v899 = 0; v899 < 3; v899 += 1) {	// L1465
      for (int v900 = 0; v900 < 3; v900 += 1) {	// L1466
        for (int v901 = 0; v901 < 32; v901 += 1) {	// L1467
          for (int v902 = 0; v902 < 64; v902 += 1) {	// L1468
            for (int v903 = 0; v903 < 64; v903 += 1) {	// L1469
              #pragma HLS pipeline II=1
              #pragma HLS dependence false variable=v894
              #pragma HLS dependence false variable=v896
              #pragma HLS dependence false variable=v897
              float v904 = v894[0][v898][(v902 + v899)][(v903 + v900)];	// L1470
              float v905 = v897[v901][v898][v899][v900];	// L1471
              float v906 = v896[0][v901][v902][v903];	// L1472
              float v907 = v904 * v905;	// L1473
              float v908 = v906 + v907;	// L1474
              v896[0][v901][v902][v903] = v908;	// L1475
            }
          }
        }
      }
    }
  }
}

void kernel276(
  float v909[1][32][64][64],
  float v910[1][32][66][66]
) {	// L1484
  for (int v911 = 0; v911 < 32; v911 += 1) {	// L1485
    for (int v912 = 0; v912 < 64; v912 += 1) {	// L1486
      for (int v913 = 0; v913 < 64; v913 += 1) {	// L1487
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v909
        #pragma HLS dependence false variable=v910
        float v914 = v909[0][v911][v912][v913];	// L1488
        v910[0][v911][(v912 + 1)][(v913 + 1)] = v914;	// L1489
      }
    }
  }
}

void kernel277(
  float v915[1][32][66][66],
  float v916
) {	// L1495
  for (int v917 = 0; v917 < 32; v917 += 1) {	// L1496
    for (int v918 = 0; v918 < 66; v918 += 1) {	// L1497
      for (int v919 = 0; v919 < 66; v919 += 1) {	// L1498
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v915
        v915[0][v917][v918][v919] = v916;	// L1499
      }
    }
  }
}

void kernel295(
  float v920[32],
  float v921[1][32][64][64]
) {	// L1505
  float v922[32];	// L1506
  #pragma HLS resource variable=v922 core=ram_t2p_bram

  memcpy(v922, v920, 32 * sizeof(float));	// L1507

  for (int v923 = 0; v923 < 32; v923 += 1) {	// L1508
    for (int v924 = 0; v924 < 64; v924 += 1) {	// L1509
      for (int v925 = 0; v925 < 64; v925 += 1) {	// L1510
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v922
        #pragma HLS dependence false variable=v921
        float v926 = v922[v923];	// L1511
        v921[0][v923][v924][v925] = v926;	// L1512
      }
    }
  }
}

void kernel297(
  float v927[1][32][66][66],
  float v928
) {	// L1518
  for (int v929 = 0; v929 < 32; v929 += 1) {	// L1519
    for (int v930 = 0; v930 < 66; v930 += 1) {	// L1520
      for (int v931 = 0; v931 < 66; v931 += 1) {	// L1521
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v927
        v927[0][v929][v930][v931] = v928;	// L1522
      }
    }
  }
}

void kernel299(
  float v932[1][32][128][128],
  float v933[2][2],
  float v934[1][32][64][64]
) {	// L1528
  for (int v935 = 0; v935 < 2; v935 += 1) {	// L1529
    for (int v936 = 0; v936 < 2; v936 += 1) {	// L1530
      for (int v937 = 0; v937 < 32; v937 += 1) {	// L1531
        for (int v938 = 0; v938 < 64; v938 += 1) {	// L1532
          for (int v939 = 0; v939 < 64; v939 += 1) {	// L1533
            #pragma HLS pipeline II=1
            #pragma HLS dependence false variable=v932
            #pragma HLS dependence false variable=v934
            float v940 = v932[0][v937][((v938 * 2) + v935)][((v939 * 2) + v936)];	// L1534
            float v941 = v934[0][v937][v938][v939];	// L1535
            float v942 = v941 + v940;	// L1536
            v934[0][v937][v938][v939] = v942;	// L1537
          }
        }
      }
    }
  }
}

void kernel300(
  float v943[1][32][64][64],
  float v944
) {	// L1545
  for (int v945 = 0; v945 < 32; v945 += 1) {	// L1546
    for (int v946 = 0; v946 < 64; v946 += 1) {	// L1547
      for (int v947 = 0; v947 < 64; v947 += 1) {	// L1548
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v943
        v943[0][v945][v946][v947] = v944;	// L1549
      }
    }
  }
}

void kernel301(
  float v948[1],
  float v949[1][32][128][128]
) {	// L1555
  float v950[1];	// L1556
  memcpy(v950, v948, 1 * sizeof(float));	// L1557

  for (int v951 = 0; v951 < 32; v951 += 1) {	// L1558
    for (int v952 = 0; v952 < 128; v952 += 1) {	// L1559
      for (int v953 = 0; v953 < 128; v953 += 1) {	// L1560
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v950
        #pragma HLS dependence false variable=v949
        float v954 = v950[0];	// L1561
        float v955 = v949[0][v951][v952][v953];	// L1562
        float v956 = v954 - v955;	// L1563
        v949[0][v951][v952][v953] = v956;	// L1564
      }
    }
  }
}

void kernel302(
  float v957[1][32][128][128],
  float v958[1][32][128][128]
) {	// L1570
  for (int v959 = 0; v959 < 32; v959 += 1) {	// L1571
    for (int v960 = 0; v960 < 128; v960 += 1) {	// L1572
      for (int v961 = 0; v961 < 128; v961 += 1) {	// L1573
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v957
        #pragma HLS dependence false variable=v958
        float v962 = v957[0][v959][v960][v961];	// L1574
        float v963 = v958[0][v959][v960][v961];	// L1575
        float v964 = v962 * v963;	// L1576
        v958[0][v959][v960][v961] = v964;	// L1577
      }
    }
  }
}

void kernel303(
  float v965[1][32][128][128],
  float v966[1],
  float v967[1][32][128][128]
) {	// L1583
  float v968[1];	// L1584
  memcpy(v968, v966, 1 * sizeof(float));	// L1585

  for (int v969 = 0; v969 < 32; v969 += 1) {	// L1586
    for (int v970 = 0; v970 < 128; v970 += 1) {	// L1587
      for (int v971 = 0; v971 < 128; v971 += 1) {	// L1588
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v968
        #pragma HLS dependence false variable=v965
        #pragma HLS dependence false variable=v967
        float v972 = v968[0];	// L1589
        float v973 = v965[0][v969][v970][v971];	// L1590
        float v974 = v972 - v973;	// L1591
        v967[0][v969][v970][v971] = v974;	// L1592
      }
    }
  }
}

void kernel305(
  float v975[1][32][128][128],
  float v976[1][32][128][128]
) {	// L1598
  for (int v977 = 0; v977 < 32; v977 += 1) {	// L1599
    for (int v978 = 0; v978 < 128; v978 += 1) {	// L1600
      for (int v979 = 0; v979 < 128; v979 += 1) {	// L1601
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v975
        #pragma HLS dependence false variable=v976
        float v980 = v975[0][v977][v978][v979];	// L1602
        v976[0][v977][v978][v979] = v980;	// L1603
      }
    }
  }
}

void kernel306(
  float v981[1][32][128][128],
  float v982[1][32][128][128]
) {	// L1609
  for (int v983 = 0; v983 < 32; v983 += 1) {	// L1610
    for (int v984 = 0; v984 < 128; v984 += 1) {	// L1611
      for (int v985 = 0; v985 < 128; v985 += 1) {	// L1612
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v981
        #pragma HLS dependence false variable=v982
        float v986 = v981[0][v983][v984][v985];	// L1613
        float v987 = v982[0][v983][v984][v985];	// L1614
        float v988 = v986 + v987;	// L1615
        v982[0][v983][v984][v985] = v988;	// L1616
      }
    }
  }
}

void kernel307(
  float v989[1][32][128][128],
  float v990
) {	// L1622
  for (int v991 = 0; v991 < 32; v991 += 1) {	// L1623
    for (int v992 = 0; v992 < 128; v992 += 1) {	// L1624
      for (int v993 = 0; v993 < 128; v993 += 1) {	// L1625
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v989
        float v994 = v989[0][v991][v992][v993];	// L1626
        float v995 = v994 * v990;	// L1627
        v989[0][v991][v992][v993] = v995;	// L1628
      }
    }
  }
}

void kernel309(
  float v996[1][32][128][128],
  float v997[1][32][128][128],
  float v998[1][32][128][128]
) {	// L1634
  for (int v999 = 0; v999 < 32; v999 += 1) {	// L1635
    for (int v1000 = 0; v1000 < 128; v1000 += 1) {	// L1636
      for (int v1001 = 0; v1001 < 128; v1001 += 1) {	// L1637
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v997
        #pragma HLS dependence false variable=v998
        #pragma HLS dependence false variable=v996
        float v1002 = v997[0][v999][v1000][v1001];	// L1638
        float v1003 = v996[0][v999][v1000][v1001];	// L1639
        float v1004 = v1002 - v1003;	// L1640
        v998[0][v999][v1000][v1001] = v1004;	// L1641
      }
    }
  }
}

void kernel310(
  float v1005[1][32][128][128],
  float v1006,
  float v1007
) {	// L1647
  for (int v1008 = 0; v1008 < 32; v1008 += 1) {	// L1648
    for (int v1009 = 0; v1009 < 128; v1009 += 1) {	// L1649
      for (int v1010 = 0; v1010 < 128; v1010 += 1) {	// L1650
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1005
        float v1011 = v1005[0][v1008][v1009][v1010];	// L1651
        bool v1012 = v1011 >= v1007;	// L1652
        float v1013 = v1012 ? v1006 : v1007;	// L1653
        v1005[0][v1008][v1009][v1010] = v1013;	// L1654
      }
    }
  }
}

void kernel312(
  float v1014[1][32][128][128],
  float v1015
) {	// L1660
  for (int v1016 = 0; v1016 < 32; v1016 += 1) {	// L1661
    for (int v1017 = 0; v1017 < 128; v1017 += 1) {	// L1662
      for (int v1018 = 0; v1018 < 128; v1018 += 1) {	// L1663
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1014
        float v1019 = v1014[0][v1016][v1017][v1018];	// L1664
        float v1020 = v1019 - v1015;	// L1665
        v1014[0][v1016][v1017][v1018] = v1020;	// L1666
      }
    }
  }
}

void kernel314(
  float v1021[1][32][128][128],
  float v1022[1][32][128][128],
  float v1023[1][32][128][128]
) {	// L1672
  for (int v1024 = 0; v1024 < 32; v1024 += 1) {	// L1673
    for (int v1025 = 0; v1025 < 128; v1025 += 1) {	// L1674
      for (int v1026 = 0; v1026 < 128; v1026 += 1) {	// L1675
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1022
        #pragma HLS dependence false variable=v1023
        #pragma HLS dependence false variable=v1021
        float v1027 = v1022[0][v1024][v1025][v1026];	// L1676
        float v1028 = v1021[0][v1024][v1025][v1026];	// L1677
        float v1029 = v1027 + v1028;	// L1678
        v1023[0][v1024][v1025][v1026] = v1029;	// L1679
      }
    }
  }
}

void kernel315(
  float v1030[1][32][128][128],
  float v1031
) {	// L1685
  for (int v1032 = 0; v1032 < 32; v1032 += 1) {	// L1686
    for (int v1033 = 0; v1033 < 128; v1033 += 1) {	// L1687
      for (int v1034 = 0; v1034 < 128; v1034 += 1) {	// L1688
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1030
        float v1035 = v1030[0][v1032][v1033][v1034];	// L1689
        float v1036 = v1035 / v1031;	// L1690
        v1030[0][v1032][v1033][v1034] = v1036;	// L1691
      }
    }
  }
}

void kernel320(
  float v1037[1][32][130][130],
  float v1038[32][32][3][3],
  float v1039[1][32][128][128]
) {	// L1697
  float v1040[32][32][3][3];	// L1698
  #pragma HLS resource variable=v1040 core=ram_t2p_bram

  memcpy(v1040, v1038, 9216 * sizeof(float));	// L1699

  for (int v1041 = 0; v1041 < 32; v1041 += 1) {	// L1700
    for (int v1042 = 0; v1042 < 3; v1042 += 1) {	// L1701
      for (int v1043 = 0; v1043 < 3; v1043 += 1) {	// L1702
        for (int v1044 = 0; v1044 < 32; v1044 += 1) {	// L1703
          for (int v1045 = 0; v1045 < 128; v1045 += 1) {	// L1704
            for (int v1046 = 0; v1046 < 128; v1046 += 1) {	// L1705
              #pragma HLS pipeline II=1
              #pragma HLS dependence false variable=v1037
              #pragma HLS dependence false variable=v1039
              #pragma HLS dependence false variable=v1040
              float v1047 = v1037[0][v1041][(v1045 + v1042)][(v1046 + v1043)];	// L1706
              float v1048 = v1040[v1044][v1041][v1042][v1043];	// L1707
              float v1049 = v1039[0][v1044][v1045][v1046];	// L1708
              float v1050 = v1047 * v1048;	// L1709
              float v1051 = v1049 + v1050;	// L1710
              v1039[0][v1044][v1045][v1046] = v1051;	// L1711
            }
          }
        }
      }
    }
  }
}

void kernel321(
  float v1052[1][32][128][128],
  float v1053[1][32][130][130]
) {	// L1720
  for (int v1054 = 0; v1054 < 32; v1054 += 1) {	// L1721
    for (int v1055 = 0; v1055 < 128; v1055 += 1) {	// L1722
      for (int v1056 = 0; v1056 < 128; v1056 += 1) {	// L1723
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1052
        #pragma HLS dependence false variable=v1053
        float v1057 = v1052[0][v1054][v1055][v1056];	// L1724
        v1053[0][v1054][(v1055 + 1)][(v1056 + 1)] = v1057;	// L1725
      }
    }
  }
}

void kernel322(
  float v1058[1][32][130][130],
  float v1059
) {	// L1731
  for (int v1060 = 0; v1060 < 32; v1060 += 1) {	// L1732
    for (int v1061 = 0; v1061 < 130; v1061 += 1) {	// L1733
      for (int v1062 = 0; v1062 < 130; v1062 += 1) {	// L1734
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1058
        v1058[0][v1060][v1061][v1062] = v1059;	// L1735
      }
    }
  }
}

void kernel341(
  float v1063[1][32][130][130],
  float v1064
) {	// L1741
  for (int v1065 = 0; v1065 < 32; v1065 += 1) {	// L1742
    for (int v1066 = 0; v1066 < 130; v1066 += 1) {	// L1743
      for (int v1067 = 0; v1067 < 130; v1067 += 1) {	// L1744
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1063
        v1063[0][v1065][v1066][v1067] = v1064;	// L1745
      }
    }
  }
}

void kernel357(
  float v1068[1][2][130][130],
  float v1069[32][2][3][3],
  float v1070[1][32][128][128]
) {	// L1751
  float v1071[32][2][3][3];	// L1752
  #pragma HLS resource variable=v1071 core=ram_t2p_bram

  memcpy(v1071, v1069, 576 * sizeof(float));	// L1753

  for (int v1072 = 0; v1072 < 2; v1072 += 1) {	// L1754
    for (int v1073 = 0; v1073 < 3; v1073 += 1) {	// L1755
      for (int v1074 = 0; v1074 < 3; v1074 += 1) {	// L1756
        for (int v1075 = 0; v1075 < 32; v1075 += 1) {	// L1757
          for (int v1076 = 0; v1076 < 128; v1076 += 1) {	// L1758
            for (int v1077 = 0; v1077 < 128; v1077 += 1) {	// L1759
              #pragma HLS pipeline II=1
              #pragma HLS dependence false variable=v1068
              #pragma HLS dependence false variable=v1070
              #pragma HLS dependence false variable=v1071
              float v1078 = v1068[0][v1072][(v1076 + v1073)][(v1077 + v1074)];	// L1760
              float v1079 = v1071[v1075][v1072][v1073][v1074];	// L1761
              float v1080 = v1070[0][v1075][v1076][v1077];	// L1762
              float v1081 = v1078 * v1079;	// L1763
              float v1082 = v1080 + v1081;	// L1764
              v1070[0][v1075][v1076][v1077] = v1082;	// L1765
            }
          }
        }
      }
    }
  }
}

void kernel359(
  float v1083[32],
  float v1084[1][32][128][128]
) {	// L1774
  float v1085[32];	// L1775
  #pragma HLS resource variable=v1085 core=ram_t2p_bram

  memcpy(v1085, v1083, 32 * sizeof(float));	// L1776

  for (int v1086 = 0; v1086 < 32; v1086 += 1) {	// L1777
    for (int v1087 = 0; v1087 < 128; v1087 += 1) {	// L1778
      for (int v1088 = 0; v1088 < 128; v1088 += 1) {	// L1779
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1085
        #pragma HLS dependence false variable=v1084
        float v1089 = v1085[v1086];	// L1780
        v1084[0][v1086][v1087][v1088] = v1089;	// L1781
      }
    }
  }
}

void kernel360(
  float v1090[1][2][128][128],
  float v1091[1][2][130][130]
) {	// L1787
  for (int v1092 = 0; v1092 < 2; v1092 += 1) {	// L1788
    for (int v1093 = 0; v1093 < 128; v1093 += 1) {	// L1789
      for (int v1094 = 0; v1094 < 128; v1094 += 1) {	// L1790
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1090
        #pragma HLS dependence false variable=v1091
        float v1095 = v1090[0][v1092][v1093][v1094];	// L1791
        v1091[0][v1092][(v1093 + 1)][(v1094 + 1)] = v1095;	// L1792
      }
    }
  }
}

void kernel361(
  float v1096[1][2][130][130],
  float v1097
) {	// L1798
  for (int v1098 = 0; v1098 < 2; v1098 += 1) {	// L1799
    for (int v1099 = 0; v1099 < 130; v1099 += 1) {	// L1800
      for (int v1100 = 0; v1100 < 130; v1100 += 1) {	// L1801
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1096
        v1096[0][v1098][v1099][v1100] = v1097;	// L1802
      }
    }
  }
}

/// The top function
void control(
  ap_int<32> v1101[14001280],
  ap_int<32> v1102[14001280],
  ap_int<32> v1103[14001280]
) {	// L1808
  #pragma HLS interface s_axilite port=return bundle=ctrl
  #pragma hls interface m_axi offset=direct bundle=g0 port=v1101
  #pragma hls stable variable=v1101
  #pragma hls interface m_axi offset=direct bundle=g0 port=v1102
  #pragma hls stable variable=v1102
  #pragma hls interface m_axi offset=direct bundle=g0 port=v1103
  #pragma hls stable variable=v1103

  auto v1104 = reinterpret_cast<float(*)[2][130][130]>(v1101 + 8912896);
  kernel361(v1104, (float)0.000000);	// L1815
  auto v1105 = reinterpret_cast<float(*)[2][128][128]>(v1101);
  kernel360(v1105, v1104);	// L1817
  auto v1106 = reinterpret_cast<float(*)[32][128][128]>(v1101 + 9453696);
  auto v1107 = reinterpret_cast<float(*)>(v1103 + 13973632);
  kernel359(v1107, v1106);	// L1820
  auto v1108 = reinterpret_cast<float(*)[32][128][128]>(v1102 + 9994496);
  kernel305(v1106, v1108);	// L1822
  auto v1109 = reinterpret_cast<float(*)[2][3][3]>(v1103 + 13982848);
  kernel357(v1104, v1109, v1108);	// L1824
  auto v1110 = reinterpret_cast<float(*)[32][128][128]>(v1101 + 524288);
  auto v1111 = reinterpret_cast<float(*)[32][128][128]>(v1101 + 8912896);
  kernel305(v1110, v1111);	// L1827
  kernel315(v1111, (float)-0.000000);	// L1828
  auto v1112 = reinterpret_cast<float(*)[32][128][128]>(v1102 + 10535296);
  kernel309(v1111, v1110, v1112);	// L1830
  kernel305(v1108, v1111);	// L1831
  kernel315(v1111, (float)-0.000000);	// L1832
  kernel314(v1111, v1112, v1108);	// L1833
  kernel305(v1108, v1111);	// L1834
  kernel312(v1111, (float)1.000000);	// L1835
  kernel305(v1111, v1112);	// L1836
  kernel310(v1112, (float)1.000000, (float)0.000000);	// L1837
  auto v1113 = reinterpret_cast<float(*)[32][128][128]>(v1101 + 11076096);
  kernel309(v1112, v1108, v1113);	// L1839
  kernel305(v1112, v1111);	// L1840
  kernel307(v1111, (float)0.000000);	// L1841
  kernel306(v1113, v1111);	// L1842
  kernel305(v1111, v1110);	// L1843
  auto v1114 = reinterpret_cast<float(*)[32][130][130]>(v1101 + 9994496);
  kernel341(v1114, (float)0.000000);	// L1845
  kernel321(v1112, v1114);	// L1846
  kernel305(v1106, v1112);	// L1847
  auto v1115 = reinterpret_cast<float(*)[32][3][3]>(v1103 + 13964416);
  kernel320(v1114, v1115, v1112);	// L1849
  auto v1116 = reinterpret_cast<float(*)[32][128][128]>(v1101 + 1048576);
  kernel305(v1116, v1111);	// L1851
  kernel315(v1111, (float)-0.000000);	// L1852
  kernel309(v1111, v1116, v1108);	// L1853
  kernel305(v1112, v1111);	// L1854
  kernel315(v1111, (float)-0.000000);	// L1855
  auto v1117 = reinterpret_cast<float(*)[32][128][128]>(v1103 + 10535296);
  kernel314(v1111, v1108, v1117);	// L1857
  kernel305(v1117, v1111);	// L1858
  kernel312(v1111, (float)1.000000);	// L1859
  auto v1118 = reinterpret_cast<float(*)[32][128][128]>(v1101 + 9994496);
  kernel305(v1111, v1118);	// L1861
  kernel310(v1118, (float)1.000000, (float)0.000000);	// L1862
  auto v1119 = reinterpret_cast<float(*)[32][128][128]>(v1102 + 11076096);
  kernel309(v1118, v1117, v1119);	// L1864
  kernel305(v1118, v1111);	// L1865
  kernel307(v1111, (float)0.000000);	// L1866
  kernel306(v1119, v1111);	// L1867
  kernel305(v1111, v1116);	// L1868
  auto v1120 = reinterpret_cast<float(*)[32][130][130]>(v1102 + 10535296);
  kernel322(v1120, (float)0.000000);	// L1870
  kernel321(v1118, v1120);	// L1871
  auto v1121 = reinterpret_cast<float(*)[32][3][3]>(v1103 + 13955200);
  kernel320(v1120, v1121, v1106);	// L1873
  auto v1122 = reinterpret_cast<float(*)[32][128][128]>(v1101 + 1572864);
  kernel305(v1122, v1111);	// L1875
  kernel315(v1111, (float)-0.000000);	// L1876
  kernel309(v1111, v1122, v1112);	// L1877
  kernel305(v1106, v1111);	// L1878
  kernel315(v1111, (float)-0.000000);	// L1879
  auto v1123 = reinterpret_cast<float(*)[32][128][128]>(v1102 + 9453696);
  kernel314(v1111, v1112, v1123);	// L1881
  kernel305(v1123, v1111);	// L1882
  kernel312(v1111, (float)1.000000);	// L1883
  kernel305(v1111, v1112);	// L1884
  kernel310(v1112, (float)1.000000, (float)0.000000);	// L1885
  kernel309(v1112, v1123, v1119);	// L1886
  kernel305(v1112, v1111);	// L1887
  kernel307(v1111, (float)0.000000);	// L1888
  kernel306(v1119, v1111);	// L1889
  kernel305(v1111, v1122);	// L1890
  auto v1124 = reinterpret_cast<float(*)>(v1103 + 13992064);
  kernel303(v1118, v1124, v1123);	// L1892
  kernel303(v1112, v1124, v1111);	// L1893
  kernel302(v1123, v1111);	// L1894
  kernel301(v1124, v1111);	// L1895
  auto v1125 = reinterpret_cast<float(*)[32][64][64]>(v1101 + 9453696);
  kernel300(v1125, (float)0.000000);	// L1897
  auto v1126 = reinterpret_cast<float(*)[2]>(v1101 + 9994496);
  kernel299(v1111, v1126, v1125);	// L1899
  kernel270(v1125, (float)4.000000);	// L1900
  auto v1127 = reinterpret_cast<float(*)[32][66][66]>(v1101 + 8912896);
  kernel297(v1127, (float)0.000000);	// L1902
  kernel276(v1125, v1127);	// L1903
  auto v1128 = reinterpret_cast<float(*)[32][64][64]>(v1102 + 10535296);
  kernel295(v1107, v1128);	// L1905
  auto v1129 = reinterpret_cast<float(*)[32][64][64]>(v1102 + 11076096);
  kernel260(v1128, v1129);	// L1907
  auto v1130 = reinterpret_cast<float(*)[32][3][3]>(v1103 + 13945984);
  kernel275(v1127, v1130, v1129);	// L1909
  auto v1131 = reinterpret_cast<float(*)[32][64][64]>(v1101 + 2097152);
  kernel260(v1131, v1125);	// L1911
  kernel270(v1125, (float)-0.000000);	// L1912
  auto v1132 = reinterpret_cast<float(*)[32][64][64]>(v1102 + 8912896);
  kernel264(v1125, v1131, v1132);	// L1914
  kernel260(v1129, v1125);	// L1915
  kernel270(v1125, (float)-0.000000);	// L1916
  auto v1133 = reinterpret_cast<float(*)[32][64][64]>(v1103 + 11076096);
  kernel269(v1125, v1132, v1133);	// L1918
  kernel260(v1133, v1125);	// L1919
  kernel267(v1125, (float)1.000000);	// L1920
  kernel260(v1125, v1132);	// L1921
  kernel265(v1132, (float)1.000000, (float)0.000000);	// L1922
  auto v1134 = reinterpret_cast<float(*)[32][64][64]>(v1102 + 11616896);
  kernel264(v1132, v1133, v1134);	// L1924
  kernel260(v1132, v1125);	// L1925
  kernel262(v1125, (float)0.000000);	// L1926
  kernel261(v1134, v1125);	// L1927
  kernel260(v1125, v1131);	// L1928
  auto v1135 = reinterpret_cast<float(*)[32][66][66]>(v1101 + 11076096);
  kernel277(v1135, (float)0.000000);	// L1930
  kernel276(v1132, v1135);	// L1931
  auto v1136 = reinterpret_cast<float(*)[32][3][3]>(v1103 + 13936768);
  kernel275(v1135, v1136, v1128);	// L1933
  auto v1137 = reinterpret_cast<float(*)[32][64][64]>(v1101 + 2621440);
  kernel260(v1137, v1125);	// L1935
  kernel270(v1125, (float)-0.000000);	// L1936
  kernel264(v1125, v1137, v1129);	// L1937
  kernel260(v1128, v1125);	// L1938
  kernel270(v1125, (float)-0.000000);	// L1939
  auto v1138 = reinterpret_cast<float(*)[32][64][64]>(v1103 + 10535296);
  kernel269(v1125, v1129, v1138);	// L1941
  kernel260(v1138, v1125);	// L1942
  kernel267(v1125, (float)1.000000);	// L1943
  kernel260(v1125, v1129);	// L1944
  kernel265(v1129, (float)1.000000, (float)0.000000);	// L1945
  auto v1139 = reinterpret_cast<float(*)[32][64][64]>(v1101 + 11616896);
  kernel264(v1129, v1138, v1139);	// L1947
  kernel260(v1129, v1125);	// L1948
  kernel262(v1125, (float)0.000000);	// L1949
  kernel261(v1139, v1125);	// L1950
  kernel260(v1125, v1137);	// L1951
  kernel258(v1132, v1124, v1128);	// L1952
  kernel258(v1129, v1124, v1125);	// L1953
  kernel257(v1128, v1125);	// L1954
  kernel256(v1124, v1125);	// L1955
  auto v1140 = reinterpret_cast<float(*)[32][32][32]>(v1101 + 8912896);
  kernel255(v1140, (float)0.000000);	// L1957
  kernel254(v1125, v1126, v1140);	// L1958
  auto v1141 = reinterpret_cast<float(*)[32][32][32]>(v1102 + 9453696);
  kernel214(v1140, v1141);	// L1960
  kernel224(v1141, (float)4.000000);	// L1961
  auto v1142 = reinterpret_cast<float(*)[32][34][34]>(v1101 + 10535296);
  kernel251(v1142, (float)0.000000);	// L1963
  kernel230(v1141, v1142);	// L1964
  auto v1143 = reinterpret_cast<float(*)[32][32][32]>(v1102 + 11076096);
  kernel249(v1107, v1143);	// L1966
  auto v1144 = reinterpret_cast<float(*)[32][32][32]>(v1102 + 11616896);
  kernel214(v1143, v1144);	// L1968
  auto v1145 = reinterpret_cast<float(*)[32][3][3]>(v1103 + 13927552);
  kernel229(v1142, v1145, v1144);	// L1970
  auto v1146 = reinterpret_cast<float(*)[32][32][32]>(v1101 + 3145728);
  kernel214(v1146, v1140);	// L1972
  kernel224(v1140, (float)-0.000000);	// L1973
  auto v1147 = reinterpret_cast<float(*)[32][32][32]>(v1102 + 10535296);
  kernel218(v1140, v1146, v1147);	// L1975
  kernel214(v1144, v1140);	// L1976
  kernel224(v1140, (float)-0.000000);	// L1977
  auto v1148 = reinterpret_cast<float(*)[32][32][32]>(v1103 + 11616896);
  kernel223(v1140, v1147, v1148);	// L1979
  kernel214(v1148, v1140);	// L1980
  kernel221(v1140, (float)1.000000);	// L1981
  auto v1149 = reinterpret_cast<float(*)[32][32][32]>(v1101 + 10535296);
  kernel214(v1140, v1149);	// L1983
  kernel219(v1149, (float)1.000000, (float)0.000000);	// L1984
  auto v1150 = reinterpret_cast<float(*)[32][32][32]>(v1102 + 12157696);
  kernel218(v1149, v1148, v1150);	// L1986
  kernel214(v1149, v1140);	// L1987
  kernel216(v1140, (float)0.000000);	// L1988
  kernel215(v1150, v1140);	// L1989
  kernel214(v1140, v1146);	// L1990
  auto v1151 = reinterpret_cast<float(*)[32][34][34]>(v1102 + 11616896);
  kernel231(v1151, (float)0.000000);	// L1992
  kernel230(v1149, v1151);	// L1993
  auto v1152 = reinterpret_cast<float(*)[32][3][3]>(v1103 + 13918336);
  kernel229(v1151, v1152, v1143);	// L1995
  auto v1153 = reinterpret_cast<float(*)[32][32][32]>(v1101 + 3670016);
  kernel214(v1153, v1140);	// L1997
  kernel224(v1140, (float)-0.000000);	// L1998
  kernel218(v1140, v1153, v1144);	// L1999
  kernel214(v1143, v1140);	// L2000
  kernel224(v1140, (float)-0.000000);	// L2001
  auto v1154 = reinterpret_cast<float(*)[32][32][32]>(v1103 + 11076096);
  kernel223(v1140, v1144, v1154);	// L2003
  kernel214(v1154, v1140);	// L2004
  kernel221(v1140, (float)1.000000);	// L2005
  kernel214(v1140, v1144);	// L2006
  kernel219(v1144, (float)1.000000, (float)0.000000);	// L2007
  kernel218(v1144, v1154, v1150);	// L2008
  kernel214(v1144, v1140);	// L2009
  kernel216(v1140, (float)0.000000);	// L2010
  kernel215(v1150, v1140);	// L2011
  kernel214(v1140, v1153);	// L2012
  kernel212(v1149, v1124, v1143);	// L2013
  kernel212(v1144, v1124, v1140);	// L2014
  kernel211(v1143, v1140);	// L2015
  kernel210(v1124, v1140);	// L2016
  auto v1155 = reinterpret_cast<float(*)[32][16][16]>(v1102 + 10535296);
  kernel209(v1155, (float)0.000000);	// L2018
  auto v1156 = reinterpret_cast<float(*)[32][16][16]>(v1102 + 11076096);
  kernel161(v1155, v1156);	// L2020
  kernel205(v1140, v1126, v1156);	// L2021
  kernel171(v1156, (float)4.000000);	// L2022
  kernel205(v1141, v1126, v1155);	// L2023
  kernel171(v1155, (float)4.000000);	// L2024
  auto v1157 = reinterpret_cast<float(*)>(v1101 + 8912896);
  auto v1158 = reinterpret_cast<float(*)>(v1103 + 13816960);
  kernel96(v1158, v1157, (float)1.000000);	// L2027
  auto v1159 = reinterpret_cast<float(*)[32][16][16]>(v1101 + 9453696);
  kernel200(v1157, v1155, v1159);	// L2029
  auto v1160 = reinterpret_cast<float(*)>(v1103 + 13807744);
  kernel96(v1160, v1157, (float)1.000000);	// L2031
  kernel200(v1157, v1156, v1155);	// L2032
  kernel162(v1159, v1155);	// L2033
  auto v1161 = reinterpret_cast<float(*)[32][18][18]>(v1101 + 9453696);
  kernel198(v1161, (float)0.000000);	// L2035
  kernel177(v1155, v1161);	// L2036
  auto v1162 = reinterpret_cast<float(*)[32][16][16]>(v1101 + 11616896);
  kernel196(v1107, v1162);	// L2038
  auto v1163 = reinterpret_cast<float(*)[32][16][16]>(v1101 + 12157696);
  kernel161(v1162, v1163);	// L2040
  auto v1164 = reinterpret_cast<float(*)[32][3][3]>(v1103 + 13909120);
  kernel176(v1161, v1164, v1163);	// L2042
  auto v1165 = reinterpret_cast<float(*)[32][16][16]>(v1101 + 4194304);
  kernel161(v1165, v1155);	// L2044
  kernel171(v1155, (float)-0.000000);	// L2045
  auto v1166 = reinterpret_cast<float(*)[32][16][16]>(v1103 + 9453696);
  kernel165(v1155, v1165, v1166);	// L2047
  kernel161(v1163, v1155);	// L2048
  kernel171(v1155, (float)-0.000000);	// L2049
  kernel170(v1155, v1166, v1163);	// L2050
  kernel161(v1163, v1155);	// L2051
  kernel168(v1155, (float)1.000000);	// L2052
  kernel161(v1155, v1159);	// L2053
  kernel166(v1159, (float)1.000000, (float)0.000000);	// L2054
  auto v1167 = reinterpret_cast<float(*)[32][16][16]>(v1101 + 12698496);
  kernel165(v1159, v1163, v1167);	// L2056
  kernel161(v1159, v1155);	// L2057
  kernel163(v1155, (float)0.000000);	// L2058
  kernel162(v1167, v1155);	// L2059
  kernel161(v1155, v1165);	// L2060
  auto v1168 = reinterpret_cast<float(*)[32][18][18]>(v1102 + 12157696);
  kernel178(v1168, (float)0.000000);	// L2062
  kernel177(v1159, v1168);	// L2063
  auto v1169 = reinterpret_cast<float(*)[32][3][3]>(v1103 + 13899904);
  kernel176(v1168, v1169, v1162);	// L2065
  auto v1170 = reinterpret_cast<float(*)[32][16][16]>(v1101 + 4718592);
  kernel161(v1170, v1155);	// L2067
  kernel171(v1155, (float)-0.000000);	// L2068
  kernel165(v1155, v1170, v1163);	// L2069
  kernel161(v1162, v1155);	// L2070
  kernel171(v1155, (float)-0.000000);	// L2071
  auto v1171 = reinterpret_cast<float(*)[32][16][16]>(v1103 + 11616896);
  kernel170(v1155, v1163, v1171);	// L2073
  kernel161(v1171, v1155);	// L2074
  kernel168(v1155, (float)1.000000);	// L2075
  kernel161(v1155, v1163);	// L2076
  kernel166(v1163, (float)1.000000, (float)0.000000);	// L2077
  auto v1172 = reinterpret_cast<float(*)[32][16][16]>(v1102 + 12698496);
  kernel165(v1163, v1171, v1172);	// L2079
  kernel161(v1163, v1155);	// L2080
  kernel163(v1155, (float)0.000000);	// L2081
  kernel162(v1172, v1155);	// L2082
  kernel161(v1155, v1170);	// L2083
  kernel159(v1159, v1124, v1162);	// L2084
  kernel159(v1163, v1124, v1155);	// L2085
  kernel158(v1162, v1155);	// L2086
  kernel157(v1124, v1155);	// L2087
  auto v1173 = reinterpret_cast<float(*)[32][8][8]>(v1101 + 9453696);
  kernel156(v1173, (float)0.000000);	// L2089
  kernel155(v1155, v1126, v1173);	// L2090
  auto v1174 = reinterpret_cast<float(*)[32][8][8]>(v1102 + 10535296);
  kernel115(v1173, v1174);	// L2092
  kernel125(v1174, (float)4.000000);	// L2093
  auto v1175 = reinterpret_cast<float(*)[32][10][10]>(v1101 + 11616896);
  kernel152(v1175, (float)0.000000);	// L2095
  kernel131(v1174, v1175);	// L2096
  auto v1176 = reinterpret_cast<float(*)[32][8][8]>(v1102 + 12157696);
  kernel150(v1107, v1176);	// L2098
  auto v1177 = reinterpret_cast<float(*)[32][8][8]>(v1102 + 12698496);
  kernel115(v1176, v1177);	// L2100
  auto v1178 = reinterpret_cast<float(*)[32][3][3]>(v1103 + 13890688);
  kernel130(v1175, v1178, v1177);	// L2102
  auto v1179 = reinterpret_cast<float(*)[32][8][8]>(v1101 + 5242880);
  kernel115(v1179, v1173);	// L2104
  kernel125(v1173, (float)-0.000000);	// L2105
  auto v1180 = reinterpret_cast<float(*)[32][8][8]>(v1102 + 11616896);
  kernel119(v1173, v1179, v1180);	// L2107
  kernel115(v1177, v1173);	// L2108
  kernel125(v1173, (float)-0.000000);	// L2109
  kernel124(v1173, v1180, v1177);	// L2110
  kernel115(v1177, v1173);	// L2111
  kernel122(v1173, (float)1.000000);	// L2112
  kernel115(v1173, v1180);	// L2113
  kernel120(v1180, (float)1.000000, (float)0.000000);	// L2114
  auto v1181 = reinterpret_cast<float(*)[32][8][8]>(v1101 + 13239296);
  kernel119(v1180, v1177, v1181);	// L2116
  kernel115(v1180, v1173);	// L2117
  kernel117(v1173, (float)0.000000);	// L2118
  kernel116(v1181, v1173);	// L2119
  kernel115(v1173, v1179);	// L2120
  auto v1182 = reinterpret_cast<float(*)[32][10][10]>(v1101 + 12698496);
  kernel132(v1182, (float)0.000000);	// L2122
  kernel131(v1180, v1182);	// L2123
  auto v1183 = reinterpret_cast<float(*)[32][3][3]>(v1103 + 13881472);
  kernel130(v1182, v1183, v1176);	// L2125
  auto v1184 = reinterpret_cast<float(*)[32][8][8]>(v1101 + 5767168);
  kernel115(v1184, v1173);	// L2127
  kernel125(v1173, (float)-0.000000);	// L2128
  kernel119(v1173, v1184, v1177);	// L2129
  kernel115(v1176, v1173);	// L2130
  kernel125(v1173, (float)-0.000000);	// L2131
  auto v1185 = reinterpret_cast<float(*)[32][8][8]>(v1103 + 12157696);
  kernel124(v1173, v1177, v1185);	// L2133
  kernel115(v1185, v1173);	// L2134
  kernel122(v1173, (float)1.000000);	// L2135
  kernel115(v1173, v1177);	// L2136
  kernel120(v1177, (float)1.000000, (float)0.000000);	// L2137
  kernel119(v1177, v1185, v1181);	// L2138
  kernel115(v1177, v1173);	// L2139
  kernel117(v1173, (float)0.000000);	// L2140
  kernel116(v1181, v1173);	// L2141
  kernel115(v1173, v1184);	// L2142
  auto v1186 = reinterpret_cast<float(*)[32][8][8]>(v1101 + 12157696);
  kernel113(v1180, v1124, v1186);	// L2144
  kernel113(v1177, v1124, v1173);	// L2145
  kernel112(v1186, v1173);	// L2146
  kernel111(v1124, v1173);	// L2147
  auto v1187 = reinterpret_cast<float(*)[32][4][4]>(v1103 + 11616896);
  kernel110(v1187, (float)0.000000);	// L2149
  auto v1188 = reinterpret_cast<float(*)[32][4][4]>(v1102 + 12157696);
  kernel56(v1187, v1188);	// L2151
  kernel103(v1173, v1126, v1188);	// L2152
  kernel66(v1188, (float)4.000000);	// L2153
  auto v1189 = reinterpret_cast<float(*)[32][4][4]>(v1101 + 9453696);
  kernel56(v1187, v1189);	// L2155
  auto v1190 = reinterpret_cast<float(*)[4]>(v1103 + 12698496);
  kernel105(v1156, v1190, v1189);	// L2157
  kernel66(v1189, (float)16.000000);	// L2158
  kernel103(v1174, v1126, v1187);	// L2159
  kernel66(v1187, (float)4.000000);	// L2160
  auto v1191 = reinterpret_cast<float(*)>(v1103 + 13798528);
  kernel96(v1191, v1157, (float)1.000000);	// L2162
  auto v1192 = reinterpret_cast<float(*)[32][4][4]>(v1102 + 10535296);
  kernel95(v1157, v1189, v1192);	// L2164
  auto v1193 = reinterpret_cast<float(*)>(v1103 + 13789312);
  kernel96(v1193, v1157, (float)1.000000);	// L2166
  kernel98(v1157, v1187);	// L2167
  kernel65(v1187, v1192, v1189);	// L2168
  auto v1194 = reinterpret_cast<float(*)>(v1103 + 13780096);
  kernel96(v1194, v1157, (float)1.000000);	// L2170
  kernel95(v1157, v1188, v1187);	// L2171
  kernel57(v1189, v1187);	// L2172
  auto v1195 = reinterpret_cast<float(*)[32][6][6]>(v1101 + 8912896);
  kernel93(v1195, (float)0.000000);	// L2174
  kernel72(v1187, v1195);	// L2175
  kernel91(v1107, v1189);	// L2176
  kernel56(v1189, v1192);	// L2177
  auto v1196 = reinterpret_cast<float(*)[32][3][3]>(v1103 + 13872256);
  kernel71(v1195, v1196, v1192);	// L2179
  auto v1197 = reinterpret_cast<float(*)[32][4][4]>(v1101 + 6291456);
  kernel56(v1197, v1187);	// L2181
  kernel66(v1187, (float)-0.000000);	// L2182
  auto v1198 = reinterpret_cast<float(*)[32][4][4]>(v1101 + 8912896);
  kernel60(v1187, v1197, v1198);	// L2184
  kernel56(v1192, v1187);	// L2185
  kernel66(v1187, (float)-0.000000);	// L2186
  kernel65(v1187, v1198, v1192);	// L2187
  kernel56(v1192, v1187);	// L2188
  kernel63(v1187, (float)1.000000);	// L2189
  kernel56(v1187, v1198);	// L2190
  kernel61(v1198, (float)1.000000, (float)0.000000);	// L2191
  auto v1199 = reinterpret_cast<float(*)[32][4][4]>(v1101 + 11076096);
  kernel60(v1198, v1192, v1199);	// L2193
  kernel56(v1198, v1187);	// L2194
  kernel58(v1187, (float)0.000000);	// L2195
  kernel57(v1199, v1187);	// L2196
  kernel56(v1187, v1197);	// L2197
  auto v1200 = reinterpret_cast<float(*)[32][6][6]>(v1102 + 10535296);
  kernel73(v1200, (float)0.000000);	// L2199
  kernel72(v1198, v1200);	// L2200
  auto v1201 = reinterpret_cast<float(*)[32][3][3]>(v1103 + 13863040);
  kernel71(v1200, v1201, v1189);	// L2202
  auto v1202 = reinterpret_cast<float(*)[32][4][4]>(v1101 + 6815744);
  kernel56(v1202, v1187);	// L2204
  kernel66(v1187, (float)-0.000000);	// L2205
  kernel60(v1187, v1202, v1192);	// L2206
  kernel56(v1189, v1187);	// L2207
  kernel66(v1187, (float)-0.000000);	// L2208
  auto v1203 = reinterpret_cast<float(*)[32][4][4]>(v1102 + 9453696);
  kernel65(v1187, v1192, v1203);	// L2210
  kernel56(v1203, v1187);	// L2211
  kernel63(v1187, (float)1.000000);	// L2212
  auto v1204 = reinterpret_cast<float(*)[32][4][4]>(v1101 + 10535296);
  kernel56(v1187, v1204);	// L2214
  kernel61(v1204, (float)1.000000, (float)0.000000);	// L2215
  kernel60(v1204, v1203, v1199);	// L2216
  kernel56(v1204, v1187);	// L2217
  kernel58(v1187, (float)0.000000);	// L2218
  kernel57(v1199, v1187);	// L2219
  kernel56(v1187, v1202);	// L2220
  kernel54(v1198, v1124, v1189);	// L2221
  kernel54(v1204, v1124, v1187);	// L2222
  kernel53(v1189, v1187);	// L2223
  kernel52(v1124, v1187);	// L2224
  auto v1205 = reinterpret_cast<float(*)[32][2][2]>(v1101 + 8912896);
  kernel51(v1205, (float)0.000000);	// L2226
  kernel50(v1187, v1126, v1205);	// L2227
  kernel21(v1205, (float)4.000000);	// L2228
  kernel48(v1189, (float)0.000000);	// L2229
  kernel27(v1205, v1189);	// L2230
  auto v1206 = reinterpret_cast<float(*)[32][2][2]>(v1101 + 10535296);
  kernel46(v1107, v1206);	// L2232
  auto v1207 = reinterpret_cast<float(*)[32][2][2]>(v1102 + 11076096);
  kernel11(v1206, v1207);	// L2234
  auto v1208 = reinterpret_cast<float(*)[32][3][3]>(v1103 + 13853824);
  kernel26(v1189, v1208, v1207);	// L2236
  auto v1209 = reinterpret_cast<float(*)[32][2][2]>(v1101 + 7340032);
  kernel11(v1209, v1205);	// L2238
  kernel21(v1205, (float)-0.000000);	// L2239
  auto v1210 = reinterpret_cast<float(*)[32][2][2]>(v1103 + 9453696);
  kernel15(v1205, v1209, v1210);	// L2241
  kernel11(v1207, v1205);	// L2242
  kernel21(v1205, (float)-0.000000);	// L2243
  kernel20(v1205, v1210, v1207);	// L2244
  kernel11(v1207, v1205);	// L2245
  kernel18(v1205, (float)1.000000);	// L2246
  auto v1211 = reinterpret_cast<float(*)[32][2][2]>(v1101 + 9453696);
  kernel11(v1205, v1211);	// L2248
  kernel16(v1211, (float)1.000000, (float)0.000000);	// L2249
  auto v1212 = reinterpret_cast<float(*)[32][2][2]>(v1103 + 11616896);
  kernel15(v1211, v1207, v1212);	// L2251
  kernel11(v1211, v1205);	// L2252
  kernel13(v1205, (float)0.000000);	// L2253
  kernel12(v1212, v1205);	// L2254
  kernel11(v1205, v1209);	// L2255
  auto v1213 = reinterpret_cast<float(*)[32][4][4]>(v1102 + 11076096);
  kernel28(v1213, (float)0.000000);	// L2257
  kernel27(v1211, v1213);	// L2258
  auto v1214 = reinterpret_cast<float(*)[32][3][3]>(v1103 + 13844608);
  kernel26(v1213, v1214, v1206);	// L2260
  auto v1215 = reinterpret_cast<float(*)[32][2][2]>(v1101 + 7864320);
  kernel11(v1215, v1205);	// L2262
  kernel21(v1205, (float)-0.000000);	// L2263
  kernel15(v1205, v1215, v1207);	// L2264
  kernel11(v1206, v1205);	// L2265
  kernel21(v1205, (float)-0.000000);	// L2266
  auto v1216 = reinterpret_cast<float(*)[32][2][2]>(v1102 + 10535296);
  kernel20(v1205, v1207, v1216);	// L2268
  kernel11(v1216, v1205);	// L2269
  kernel18(v1205, (float)1.000000);	// L2270
  kernel11(v1205, v1207);	// L2271
  kernel16(v1207, (float)1.000000, (float)0.000000);	// L2272
  auto v1217 = reinterpret_cast<float(*)[32][2][2]>(v1102 + 11616896);
  kernel15(v1207, v1216, v1217);	// L2274
  kernel11(v1207, v1205);	// L2275
  kernel13(v1205, (float)0.000000);	// L2276
  kernel12(v1217, v1205);	// L2277
  kernel11(v1205, v1215);	// L2278
  kernel9(v1211, v1124, v1216);	// L2279
  kernel9(v1207, v1124, v1205);	// L2280
  kernel8(v1216, v1205);	// L2281
  kernel7(v1124, v1205);	// L2282
  auto v1218 = reinterpret_cast<float(*)[32][1][1]>(v1102 + 9453696);
  kernel6(v1218, (float)0.000000);	// L2284
  kernel5(v1205, v1126, v1218);	// L2285
  kernel4(v1218, (float)4.000000);	// L2286
  auto v1219 = reinterpret_cast<float(*)[11]>(v1103 + 8912896);
  auto v1220 = reinterpret_cast<float(*)[32]>(v1102 + 13835392);
  kernel3(v1220, v1219);	// L2289
  auto v1221 = reinterpret_cast<float(*)[11]>(v1101 + 8388608);
  kernel2(v1221, (float)0.000000);	// L2291
  kernel1(v1218, v1219, v1221);	// L2292
  auto v1222 = reinterpret_cast<float(*)>(v1103 + 13826176);
  kernel0(v1222, v1221);	// L2294
}

