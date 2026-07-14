
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
  float v0[10],
  float v1[1][10]
) {	// L2
  for (int v2 = 0; v2 < 10; v2 += 1) {	// L3
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
  float v6[1][384],
  float v7[384][10],
  float v8[1][10]
) {	// L11
  float v9[1][384];	// L12

  memcpy(v9, v6, 384 * sizeof(float));	// L13

  for (int v10 = 0; v10 < 384; v10 += 1) {	// L14
    for (int v11 = 0; v11 < 10; v11 += 1) {	// L15
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v9
      #pragma HLS dependence false variable=v7
      #pragma HLS dependence false variable=v8
      float v12 = v9[0][v10];	// L16
      float v13 = v7[v10][v11];	// L17
      float v14 = v8[0][v11];	// L18
      float v15 = v12 * v13;	// L19
      float v16 = v14 + v15;	// L20
      v8[0][v11] = v16;	// L21
    }
  }
}

void kernel2(
  float v17[1][10],
  float v18
) {	// L26
  for (int v19 = 0; v19 < 10; v19 += 1) {	// L27
    #pragma HLS pipeline II=1
    #pragma HLS dependence false variable=v17
    v17[0][v19] = v18;	// L28
  }
}

void kernel3(
  float v20[10][384],
  float v21[384][10]
) {	// L32
  for (int v22 = 0; v22 < 384; v22 += 1) {	// L33
    for (int v23 = 0; v23 < 10; v23 += 1) {	// L34
      float v24 = v20[v23][v22];	// L35
      v21[v22][v23] = v24;	// L36
    }
  }
}

void kernel4(
  float v25[1][384],
  float v26
) {	// L41
  for (int v27 = 0; v27 < 384; v27 += 1) {	// L42
    #pragma HLS pipeline II=1
    #pragma HLS dependence false variable=v25
    float v28 = v25[0][v27];	// L43
    float v29 = v28 / v26;	// L44
    v25[0][v27] = v29;	// L45
  }
}

void kernel5(
  float v30[1][384][8][8],
  float v31[1][384]
) {	// L49
  for (int v32 = 0; v32 < 64; v32 += 1) {	// L50
    for (int v33 = 0; v33 < 384; v33 += 1) {	// L51
      float v34 = v30[0][v33][(v32 / 8)][(v32 % 8)];	// L52
      float v35 = v31[0][v33];	// L53
      float v36 = v34 + v35;	// L54
      v31[0][v33] = v36;	// L55
    }
  }
}

void kernel6(
  float v37[1][384],
  float v38
) {	// L60
  for (int v39 = 0; v39 < 384; v39 += 1) {	// L61
    #pragma HLS pipeline II=1
    #pragma HLS dependence false variable=v37
    v37[0][v39] = v38;	// L62
  }
}

void kernel7(
  float v40[1][384][8][8],
  float v41[1][384][8][8]
) {	// L66
  for (int v42 = 0; v42 < 384; v42 += 1) {	// L67
    for (int v43 = 0; v43 < 8; v43 += 1) {	// L68
      for (int v44 = 0; v44 < 8; v44 += 1) {	// L69
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v40
        #pragma HLS dependence false variable=v41
        float v45 = v40[0][v42][v43][v44];	// L70
        float v46 = v41[0][v42][v43][v44];	// L71
        float v47 = v45 + v46;	// L72
        v41[0][v42][v43][v44] = v47;	// L73
      }
    }
  }
}

void kernel8(
  float v48[1][1536][8][8],
  float v49[384][1536][1][1],
  float v50[1][384][8][8]
) {	// L79


  for (int v52 = 0; v52 < 1536; v52 += 1) {	// L82
    for (int v53 = 0; v53 < 384; v53 += 1) {	// L83
      for (int v54 = 0; v54 < 8; v54 += 1) {	// L84
        for (int v55 = 0; v55 < 8; v55 += 1) {	// L85
          #pragma HLS pipeline II=1
          #pragma HLS dependence false variable=v48
          #pragma HLS dependence false variable=v50
          #pragma HLS dependence false variable=v49
          float v56 = v48[0][v52][v54][v55];	// L86
          float v57 = v49[v53][v52][0][0];	// L87
          float v58 = v50[0][v53][v54][v55];	// L88
          float v59 = v56 * v57;	// L89
          float v60 = v58 + v59;	// L90
          v50[0][v53][v54][v55] = v60;	// L91
        }
      }
    }
  }
}

void kernel9(
  float v61[384],
  float v62[1][384][8][8]
) {	// L98
  float v63[384];	// L99

  memcpy(v63, v61, 384 * sizeof(float));	// L100

  for (int v64 = 0; v64 < 384; v64 += 1) {	// L101
    for (int v65 = 0; v65 < 8; v65 += 1) {	// L102
      for (int v66 = 0; v66 < 8; v66 += 1) {	// L103
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v63
        #pragma HLS dependence false variable=v62
        float v67 = v63[v64];	// L104
        v62[0][v64][v65][v66] = v67;	// L105
      }
    }
  }
}

void kernel10(
  float v68[1][1536][8][8],
  float v69[1][1536][8][8]
) {	// L111
  for (int v70 = 0; v70 < 1536; v70 += 1) {	// L112
    for (int v71 = 0; v71 < 8; v71 += 1) {	// L113
      for (int v72 = 0; v72 < 8; v72 += 1) {	// L114
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v68
        #pragma HLS dependence false variable=v69
        float v73 = v68[0][v70][v71][v72];	// L115
        v69[0][v70][v71][v72] = v73;	// L116
      }
    }
  }
}

void kernel11(
  float v74[1][1536][8][8],
  float v75[1][1536][8][8]
) {	// L122
  for (int v76 = 0; v76 < 1536; v76 += 1) {	// L123
    for (int v77 = 0; v77 < 8; v77 += 1) {	// L124
      for (int v78 = 0; v78 < 8; v78 += 1) {	// L125
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v74
        #pragma HLS dependence false variable=v75
        float v79 = v74[0][v76][v77][v78];	// L126
        float v80 = v75[0][v76][v77][v78];	// L127
        float v81 = v79 + v80;	// L128
        v75[0][v76][v77][v78] = v81;	// L129
      }
    }
  }
}

void kernel12(
  float v82[1][1536][8][8],
  float v83[1][1536][8][8],
  float v84[1][1536][8][8]
) {	// L135
  for (int v85 = 0; v85 < 1536; v85 += 1) {	// L136
    for (int v86 = 0; v86 < 8; v86 += 1) {	// L137
      for (int v87 = 0; v87 < 8; v87 += 1) {	// L138
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v83
        #pragma HLS dependence false variable=v84
        #pragma HLS dependence false variable=v82
        float v88 = v83[0][v85][v86][v87];	// L139
        float v89 = v82[0][v85][v86][v87];	// L140
        float v90 = v88 - v89;	// L141
        v84[0][v85][v86][v87] = v90;	// L142
      }
    }
  }
}

void kernel13(
  float v91[1][1536][8][8],
  float v92[1][1536][8][8],
  float v93
) {	// L148
  for (int v94 = 0; v94 < 1536; v94 += 1) {	// L149
    for (int v95 = 0; v95 < 8; v95 += 1) {	// L150
      for (int v96 = 0; v96 < 8; v96 += 1) {	// L151
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v92
        #pragma HLS dependence false variable=v91
        float v97 = v92[0][v94][v95][v96];	// L152
        float v98 = v91[0][v94][v95][v96];	// L153
        bool v99 = v97 >= v93;	// L154
        float v100 = v99 ? v98 : v93;	// L155
        v92[0][v94][v95][v96] = v100;	// L156
      }
    }
  }
}

void kernel14(
  float v101[1][1536][8][8],
  float v102,
  float v103
) {	// L162
  for (int v104 = 0; v104 < 1536; v104 += 1) {	// L163
    for (int v105 = 0; v105 < 8; v105 += 1) {	// L164
      for (int v106 = 0; v106 < 8; v106 += 1) {	// L165
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v101
        float v107 = v101[0][v104][v105][v106];	// L166
        bool v108 = v107 >= v103;	// L167
        float v109 = v108 ? v102 : v103;	// L168
        v101[0][v104][v105][v106] = v109;	// L169
      }
    }
  }
}

void kernel16(
  float v110[1][1536][8][8],
  float v111
) {	// L175
  for (int v112 = 0; v112 < 1536; v112 += 1) {	// L176
    for (int v113 = 0; v113 < 8; v113 += 1) {	// L177
      for (int v114 = 0; v114 < 8; v114 += 1) {	// L178
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v110
        float v115 = v110[0][v112][v113][v114];	// L179
        float v116 = v115 - v111;	// L180
        v110[0][v112][v113][v114] = v116;	// L181
      }
    }
  }
}

void kernel18(
  float v117[1][1536][8][8],
  float v118[1][1536][8][8],
  float v119[1][1536][8][8]
) {	// L187
  for (int v120 = 0; v120 < 1536; v120 += 1) {	// L188
    for (int v121 = 0; v121 < 8; v121 += 1) {	// L189
      for (int v122 = 0; v122 < 8; v122 += 1) {	// L190
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v118
        #pragma HLS dependence false variable=v119
        #pragma HLS dependence false variable=v117
        float v123 = v118[0][v120][v121][v122];	// L191
        float v124 = v117[0][v120][v121][v122];	// L192
        float v125 = v123 + v124;	// L193
        v119[0][v120][v121][v122] = v125;	// L194
      }
    }
  }
}

void kernel19(
  float v126[1][1536][8][8],
  float v127
) {	// L200
  for (int v128 = 0; v128 < 1536; v128 += 1) {	// L201
    for (int v129 = 0; v129 < 8; v129 += 1) {	// L202
      for (int v130 = 0; v130 < 8; v130 += 1) {	// L203
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v126
        float v131 = v126[0][v128][v129][v130];	// L204
        float v132 = v131 / v127;	// L205
        v126[0][v128][v129][v130] = v132;	// L206
      }
    }
  }
}

void kernel24(
  float v133[1][384][8][8],
  float v134[1536][384][1][1],
  float v135[1][1536][8][8]
) {	// L212


  for (int v137 = 0; v137 < 384; v137 += 1) {	// L215
    for (int v138 = 0; v138 < 1536; v138 += 1) {	// L216
      for (int v139 = 0; v139 < 8; v139 += 1) {	// L217
        for (int v140 = 0; v140 < 8; v140 += 1) {	// L218
          #pragma HLS pipeline II=1
          #pragma HLS dependence false variable=v133
          #pragma HLS dependence false variable=v135
          #pragma HLS dependence false variable=v134
          float v141 = v133[0][v137][v139][v140];	// L219
          float v142 = v134[v138][v137][0][0];	// L220
          float v143 = v135[0][v138][v139][v140];	// L221
          float v144 = v141 * v142;	// L222
          float v145 = v143 + v144;	// L223
          v135[0][v138][v139][v140] = v145;	// L224
        }
      }
    }
  }
}

void kernel25(
  float v146[1536],
  float v147[1][1536][8][8]
) {	// L231
  float v148[1536];	// L232

  memcpy(v148, v146, 1536 * sizeof(float));	// L233

  for (int v149 = 0; v149 < 1536; v149 += 1) {	// L234
    for (int v150 = 0; v150 < 8; v150 += 1) {	// L235
      for (int v151 = 0; v151 < 8; v151 += 1) {	// L236
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v148
        #pragma HLS dependence false variable=v147
        float v152 = v148[v149];	// L237
        v147[0][v149][v150][v151] = v152;	// L238
      }
    }
  }
}

void kernel26(
  float v153[1][384][8][8],
  float v154[1][384][8][8]
) {	// L244
  for (int v155 = 0; v155 < 384; v155 += 1) {	// L245
    for (int v156 = 0; v156 < 8; v156 += 1) {	// L246
      for (int v157 = 0; v157 < 8; v157 += 1) {	// L247
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v153
        #pragma HLS dependence false variable=v154
        float v158 = v153[0][v155][v156][v157];	// L248
        v154[0][v155][v156][v157] = v158;	// L249
      }
    }
  }
}

void kernel28(
  float v159[1][384][8][8],
  float v160[1][384][8][8],
  float v161[1][384][8][8]
) {	// L255
  for (int v162 = 0; v162 < 384; v162 += 1) {	// L256
    for (int v163 = 0; v163 < 8; v163 += 1) {	// L257
      for (int v164 = 0; v164 < 8; v164 += 1) {	// L258
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v160
        #pragma HLS dependence false variable=v161
        #pragma HLS dependence false variable=v159
        float v165 = v160[0][v162][v163][v164];	// L259
        float v166 = v159[0][v162][v163][v164];	// L260
        float v167 = v165 - v166;	// L261
        v161[0][v162][v163][v164] = v167;	// L262
      }
    }
  }
}

void kernel29(
  float v168[1][384][8][8],
  float v169[1][384][8][8],
  float v170
) {	// L268
  for (int v171 = 0; v171 < 384; v171 += 1) {	// L269
    for (int v172 = 0; v172 < 8; v172 += 1) {	// L270
      for (int v173 = 0; v173 < 8; v173 += 1) {	// L271
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v169
        #pragma HLS dependence false variable=v168
        float v174 = v169[0][v171][v172][v173];	// L272
        float v175 = v168[0][v171][v172][v173];	// L273
        bool v176 = v174 >= v170;	// L274
        float v177 = v176 ? v175 : v170;	// L275
        v169[0][v171][v172][v173] = v177;	// L276
      }
    }
  }
}

void kernel30(
  float v178[1][384][8][8],
  float v179,
  float v180
) {	// L282
  for (int v181 = 0; v181 < 384; v181 += 1) {	// L283
    for (int v182 = 0; v182 < 8; v182 += 1) {	// L284
      for (int v183 = 0; v183 < 8; v183 += 1) {	// L285
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v178
        float v184 = v178[0][v181][v182][v183];	// L286
        bool v185 = v184 >= v180;	// L287
        float v186 = v185 ? v179 : v180;	// L288
        v178[0][v181][v182][v183] = v186;	// L289
      }
    }
  }
}

void kernel32(
  float v187[1][384][8][8],
  float v188
) {	// L295
  for (int v189 = 0; v189 < 384; v189 += 1) {	// L296
    for (int v190 = 0; v190 < 8; v190 += 1) {	// L297
      for (int v191 = 0; v191 < 8; v191 += 1) {	// L298
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v187
        float v192 = v187[0][v189][v190][v191];	// L299
        float v193 = v192 - v188;	// L300
        v187[0][v189][v190][v191] = v193;	// L301
      }
    }
  }
}

void kernel34(
  float v194[1][384][8][8],
  float v195[1][384][8][8],
  float v196[1][384][8][8]
) {	// L307
  for (int v197 = 0; v197 < 384; v197 += 1) {	// L308
    for (int v198 = 0; v198 < 8; v198 += 1) {	// L309
      for (int v199 = 0; v199 < 8; v199 += 1) {	// L310
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v195
        #pragma HLS dependence false variable=v196
        #pragma HLS dependence false variable=v194
        float v200 = v195[0][v197][v198][v199];	// L311
        float v201 = v194[0][v197][v198][v199];	// L312
        float v202 = v200 + v201;	// L313
        v196[0][v197][v198][v199] = v202;	// L314
      }
    }
  }
}

void kernel35(
  float v203[1][384][8][8],
  float v204
) {	// L320
  for (int v205 = 0; v205 < 384; v205 += 1) {	// L321
    for (int v206 = 0; v206 < 8; v206 += 1) {	// L322
      for (int v207 = 0; v207 < 8; v207 += 1) {	// L323
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v203
        float v208 = v203[0][v205][v206][v207];	// L324
        float v209 = v208 / v204;	// L325
        v203[0][v205][v206][v207] = v209;	// L326
      }
    }
  }
}

void kernel40(
  float v210[1][384][64],
  float v211[1][384][8][8],
  float v212[1][384][8][8]
) {	// L332
  for (int v213 = 0; v213 < 384; v213 += 1) {	// L333
    for (int v214 = 0; v214 < 8; v214 += 1) {	// L334
      for (int v215 = 0; v215 < 8; v215 += 1) {	// L335
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v211
        #pragma HLS dependence false variable=v212
        #pragma HLS dependence false variable=v210
        float v216 = v211[0][v213][v214][v215];	// L336
        float v217 = v210[0][v213][((v214 * 8) + v215)];	// L337
        float v218 = v216 + v217;	// L338
        v212[0][v213][v214][v215] = v218;	// L339
      }
    }
  }
}

void kernel41(
  float v219[1][384][64],
  float v220[384][384][1],
  float v221[1][384][64]
) {	// L345


  for (int v223 = 0; v223 < 384; v223 += 1) {	// L348
    for (int v224 = 0; v224 < 384; v224 += 1) {	// L349
      for (int v225 = 0; v225 < 64; v225 += 1) {	// L350
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v219
        #pragma HLS dependence false variable=v221
        #pragma HLS dependence false variable=v220
        float v226 = v219[0][v223][v225];	// L351
        float v227 = v220[v224][v223][0];	// L352
        float v228 = v221[0][v224][v225];	// L353
        float v229 = v226 * v227;	// L354
        float v230 = v228 + v229;	// L355
        v221[0][v224][v225] = v230;	// L356
      }
    }
  }
}

void kernel42(
  float v231[384],
  float v232[1][384][64]
) {	// L362
  float v233[384];	// L363

  memcpy(v233, v231, 384 * sizeof(float));	// L364

  for (int v234 = 0; v234 < 384; v234 += 1) {	// L365
    for (int v235 = 0; v235 < 64; v235 += 1) {	// L366
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v233
      #pragma HLS dependence false variable=v232
      float v236 = v233[v234];	// L367
      v232[0][v234][v235] = v236;	// L368
    }
  }
}

void kernel43(
  float v237[1][64][384],
  float v238[1][384][64]
) {	// L373
  for (int v239 = 0; v239 < 384; v239 += 1) {	// L374
    for (int v240 = 0; v240 < 64; v240 += 1) {	// L375
      float v241 = v237[0][v240][v239];	// L376
      v238[0][v239][v240] = v241;	// L377
    }
  }
}

void kernel44(
  float v242[1][64][384],
  float v243[1][64][384]
) {	// L382
  for (int v244 = 0; v244 < 64; v244 += 1) {	// L383
    for (int v245 = 0; v245 < 384; v245 += 1) {	// L384
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v242
      #pragma HLS dependence false variable=v243
      float v246 = v242[0][v244][v245];	// L385
      v243[0][v244][v245] = v246;	// L386
    }
  }
}

void kernel45(
  float v247[1][64][384],
  float v248[1][64][384]
) {	// L391
  for (int v249 = 0; v249 < 64; v249 += 1) {	// L392
    for (int v250 = 0; v250 < 384; v250 += 1) {	// L393
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v247
      #pragma HLS dependence false variable=v248
      float v251 = v247[0][v249][v250];	// L394
      float v252 = v248[0][v249][v250];	// L395
      float v253 = v251 + v252;	// L396
      v248[0][v249][v250] = v253;	// L397
    }
  }
}

void kernel46(
  float v254[1][64][384],
  float v255[1][64][384],
  float v256[1][64][384]
) {	// L402
  for (int v257 = 0; v257 < 64; v257 += 1) {	// L403
    for (int v258 = 0; v258 < 384; v258 += 1) {	// L404
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v255
      #pragma HLS dependence false variable=v256
      #pragma HLS dependence false variable=v254
      float v259 = v255[0][v257][v258];	// L405
      float v260 = v254[0][v257][v258];	// L406
      float v261 = v259 - v260;	// L407
      v256[0][v257][v258] = v261;	// L408
    }
  }
}

void kernel47(
  float v262[1][64][384],
  float v263[1][64][384],
  float v264
) {	// L413
  for (int v265 = 0; v265 < 64; v265 += 1) {	// L414
    for (int v266 = 0; v266 < 384; v266 += 1) {	// L415
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v263
      #pragma HLS dependence false variable=v262
      float v267 = v263[0][v265][v266];	// L416
      float v268 = v262[0][v265][v266];	// L417
      bool v269 = v267 >= v264;	// L418
      float v270 = v269 ? v268 : v264;	// L419
      v263[0][v265][v266] = v270;	// L420
    }
  }
}

void kernel48(
  float v271[1][64][384],
  float v272,
  float v273
) {	// L425
  for (int v274 = 0; v274 < 64; v274 += 1) {	// L426
    for (int v275 = 0; v275 < 384; v275 += 1) {	// L427
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v271
      float v276 = v271[0][v274][v275];	// L428
      bool v277 = v276 >= v273;	// L429
      float v278 = v277 ? v272 : v273;	// L430
      v271[0][v274][v275] = v278;	// L431
    }
  }
}

void kernel50(
  float v279[1][64][384],
  float v280
) {	// L436
  for (int v281 = 0; v281 < 64; v281 += 1) {	// L437
    for (int v282 = 0; v282 < 384; v282 += 1) {	// L438
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v279
      float v283 = v279[0][v281][v282];	// L439
      float v284 = v283 - v280;	// L440
      v279[0][v281][v282] = v284;	// L441
    }
  }
}

void kernel52(
  float v285[1][64][384],
  float v286[1][64][384],
  float v287[1][64][384]
) {	// L446
  for (int v288 = 0; v288 < 64; v288 += 1) {	// L447
    for (int v289 = 0; v289 < 384; v289 += 1) {	// L448
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v286
      #pragma HLS dependence false variable=v287
      #pragma HLS dependence false variable=v285
      float v290 = v286[0][v288][v289];	// L449
      float v291 = v285[0][v288][v289];	// L450
      float v292 = v290 + v291;	// L451
      v287[0][v288][v289] = v292;	// L452
    }
  }
}

void kernel53(
  float v293[1][64][384],
  float v294
) {	// L457
  for (int v295 = 0; v295 < 64; v295 += 1) {	// L458
    for (int v296 = 0; v296 < 384; v296 += 1) {	// L459
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v293
      float v297 = v293[0][v295][v296];	// L460
      float v298 = v297 / v294;	// L461
      v293[0][v295][v296] = v298;	// L462
    }
  }
}

void kernel54(
  float v299[1][64][12][32],
  float v300[1][64][384]
) {	// L467
  for (int v301 = 0; v301 < 64; v301 += 1) {	// L468
    for (int v302 = 0; v302 < 384; v302 += 1) {	// L469
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v299
      #pragma HLS dependence false variable=v300
      float v303 = v299[0][v301][(v302 / 32)][(v302 % 32)];	// L470
      v300[0][v301][v302] = v303;	// L471
    }
  }
}

void kernel58(
  float v304[1][12][64][32],
  float v305[1][64][12][32]
) {	// L476
  for (int v306 = 0; v306 < 64; v306 += 1) {	// L477
    for (int v307 = 0; v307 < 12; v307 += 1) {	// L478
      for (int v308 = 0; v308 < 32; v308 += 1) {	// L479
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v304
        #pragma HLS dependence false variable=v305
        float v309 = v304[0][v307][v306][v308];	// L480
        v305[0][v306][v307][v308] = v309;	// L481
      }
    }
  }
}

void kernel59(
  float v310[12][64][32],
  float v311[1],
  float v312[1][12][64][32]
) {	// L487
  float v313[1];	// L488
  memcpy(v313, v311, 1 * sizeof(float));	// L489

  for (int v314 = 0; v314 < 12; v314 += 1) {	// L490
    for (int v315 = 0; v315 < 64; v315 += 1) {	// L491
      for (int v316 = 0; v316 < 32; v316 += 1) {	// L492
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v310
        #pragma HLS dependence false variable=v312
        #pragma HLS dependence false variable=v313
        float v317 = v310[v314][v315][v316];	// L493
        float v318 = v313[0];	// L494
        float v319 = v317 * v318;	// L495
        v312[0][v314][v315][v316] = v319;	// L496
      }
    }
  }
}

void kernel60(
  float v320[1][12][64][64],
  float v321[1][12][64][32],
  float v322[12][64][32]
) {	// L502


  for (int v324 = 0; v324 < 64; v324 += 1) {	// L505
    for (int v325 = 0; v325 < 12; v325 += 1) {	// L506
      for (int v326 = 0; v326 < 64; v326 += 1) {	// L507
        for (int v327 = 0; v327 < 32; v327 += 1) {	// L508
          #pragma HLS pipeline II=1
          #pragma HLS dependence false variable=v320
          #pragma HLS dependence false variable=v321
          #pragma HLS dependence false variable=v322
          float v328 = v320[0][v325][v326][v324];	// L509
          float v329 = v321[0][v325][v324][v327];	// L510
          float v330 = v322[v325][v326][v327];	// L511
          float v331 = v328 * v329;	// L512
          float v332 = v330 + v331;	// L513
          v322[v325][v326][v327] = v332;	// L514
        }
      }
    }
  }
}

void kernel61(
  float v333[1][12][64][32],
  float v334[1][12][64][32]
) {	// L521
  for (int v335 = 0; v335 < 12; v335 += 1) {	// L522
    for (int v336 = 0; v336 < 64; v336 += 1) {	// L523
      for (int v337 = 0; v337 < 32; v337 += 1) {	// L524
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v333
        #pragma HLS dependence false variable=v334
        float v338 = v333[0][v335][v336][v337];	// L525
        v334[0][v335][v336][v337] = v338;	// L526
      }
    }
  }
}

void kernel62(
  float v339[12][64][64],
  float v340[1][12][64][64]
) {	// L532
  for (int v341 = 0; v341 < 12; v341 += 1) {	// L533
    for (int v342 = 0; v342 < 64; v342 += 1) {	// L534
      for (int v343 = 0; v343 < 64; v343 += 1) {	// L535
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v339
        #pragma HLS dependence false variable=v340
        float v344 = v339[v341][v342][v343];	// L536
        v340[0][v341][v342][v343] = v344;	// L537
      }
    }
  }
}

void kernel63(
  float v345[1][12][64][32],
  float v346[1][12][32][64],
  float v347[12][64][64]
) {	// L543


  for (int v349 = 0; v349 < 32; v349 += 1) {	// L546
    for (int v350 = 0; v350 < 12; v350 += 1) {	// L547
      for (int v351 = 0; v351 < 64; v351 += 1) {	// L548
        for (int v352 = 0; v352 < 64; v352 += 1) {	// L549
          #pragma HLS pipeline II=1
          #pragma HLS dependence false variable=v345
          #pragma HLS dependence false variable=v346
          #pragma HLS dependence false variable=v347
          float v353 = v345[0][v350][v351][v349];	// L550
          float v354 = v346[0][v350][v349][v352];	// L551
          float v355 = v347[v350][v351][v352];	// L552
          float v356 = v353 * v354;	// L553
          float v357 = v355 + v356;	// L554
          v347[v350][v351][v352] = v357;	// L555
        }
      }
    }
  }
}

void kernel64(
  float v358[1][12][32][64],
  float v359[1][12][32][64]
) {	// L562
  for (int v360 = 0; v360 < 12; v360 += 1) {	// L563
    for (int v361 = 0; v361 < 32; v361 += 1) {	// L564
      for (int v362 = 0; v362 < 64; v362 += 1) {	// L565
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v358
        #pragma HLS dependence false variable=v359
        float v363 = v358[0][v360][v361][v362];	// L566
        v359[0][v360][v361][v362] = v363;	// L567
      }
    }
  }
}

void kernel66(
  float v364[1][64][384],
  float v365[1][12][32][64]
) {	// L573
  for (int v366 = 0; v366 < 12; v366 += 1) {	// L574
    for (int v367 = 0; v367 < 32; v367 += 1) {	// L575
      for (int v368 = 0; v368 < 64; v368 += 1) {	// L576
        float v369 = v364[0][v368][((v366 * 32) + v367)];	// L577
        v365[0][v366][v367][v368] = v369;	// L578
      }
    }
  }
}

void kernel67(
  float v370[1][64][384],
  float v371[1][12][64][32]
) {	// L584
  for (int v372 = 0; v372 < 12; v372 += 1) {	// L585
    for (int v373 = 0; v373 < 64; v373 += 1) {	// L586
      for (int v374 = 0; v374 < 32; v374 += 1) {	// L587
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v370
        #pragma HLS dependence false variable=v371
        float v375 = v370[0][v373][((v372 * 32) + v374)];	// L588
        v371[0][v372][v373][v374] = v375;	// L589
      }
    }
  }
}

void kernel68(
  float v376[1][384][64],
  float v377[1][64][384]
) {	// L595
  for (int v378 = 0; v378 < 64; v378 += 1) {	// L596
    for (int v379 = 0; v379 < 384; v379 += 1) {	// L597
      float v380 = v376[0][v379][v378];	// L598
      v377[0][v378][v379] = v380;	// L599
    }
  }
}

void kernel69(
  float v381[1][384][64],
  float v382[1][384][64]
) {	// L604
  for (int v383 = 0; v383 < 384; v383 += 1) {	// L605
    for (int v384 = 0; v384 < 64; v384 += 1) {	// L606
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v381
      #pragma HLS dependence false variable=v382
      float v385 = v381[0][v383][v384];	// L607
      v382[0][v383][v384] = v385;	// L608
    }
  }
}

void kernel70(
  float v386[1][384][64],
  float v387[1][384][64]
) {	// L613
  for (int v388 = 0; v388 < 384; v388 += 1) {	// L614
    for (int v389 = 0; v389 < 64; v389 += 1) {	// L615
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v386
      #pragma HLS dependence false variable=v387
      float v390 = v386[0][v388][v389];	// L616
      float v391 = v387[0][v388][v389];	// L617
      float v392 = v390 + v391;	// L618
      v387[0][v388][v389] = v392;	// L619
    }
  }
}

void kernel71(
  float v393[1][384][64],
  float v394[1][384][64],
  float v395[1][384][64]
) {	// L624
  for (int v396 = 0; v396 < 384; v396 += 1) {	// L625
    for (int v397 = 0; v397 < 64; v397 += 1) {	// L626
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v394
      #pragma HLS dependence false variable=v395
      #pragma HLS dependence false variable=v393
      float v398 = v394[0][v396][v397];	// L627
      float v399 = v393[0][v396][v397];	// L628
      float v400 = v398 - v399;	// L629
      v395[0][v396][v397] = v400;	// L630
    }
  }
}

void kernel72(
  float v401[1][384][64],
  float v402[1][384][64],
  float v403
) {	// L635
  for (int v404 = 0; v404 < 384; v404 += 1) {	// L636
    for (int v405 = 0; v405 < 64; v405 += 1) {	// L637
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v402
      #pragma HLS dependence false variable=v401
      float v406 = v402[0][v404][v405];	// L638
      float v407 = v401[0][v404][v405];	// L639
      bool v408 = v406 >= v403;	// L640
      float v409 = v408 ? v407 : v403;	// L641
      v402[0][v404][v405] = v409;	// L642
    }
  }
}

void kernel73(
  float v410[1][384][64],
  float v411,
  float v412
) {	// L647
  for (int v413 = 0; v413 < 384; v413 += 1) {	// L648
    for (int v414 = 0; v414 < 64; v414 += 1) {	// L649
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v410
      float v415 = v410[0][v413][v414];	// L650
      bool v416 = v415 >= v412;	// L651
      float v417 = v416 ? v411 : v412;	// L652
      v410[0][v413][v414] = v417;	// L653
    }
  }
}

void kernel75(
  float v418[1][384][64],
  float v419
) {	// L658
  for (int v420 = 0; v420 < 384; v420 += 1) {	// L659
    for (int v421 = 0; v421 < 64; v421 += 1) {	// L660
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v418
      float v422 = v418[0][v420][v421];	// L661
      float v423 = v422 - v419;	// L662
      v418[0][v420][v421] = v423;	// L663
    }
  }
}

void kernel77(
  float v424[1][384][64],
  float v425[1][384][64],
  float v426[1][384][64]
) {	// L668
  for (int v427 = 0; v427 < 384; v427 += 1) {	// L669
    for (int v428 = 0; v428 < 64; v428 += 1) {	// L670
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v425
      #pragma HLS dependence false variable=v426
      #pragma HLS dependence false variable=v424
      float v429 = v425[0][v427][v428];	// L671
      float v430 = v424[0][v427][v428];	// L672
      float v431 = v429 + v430;	// L673
      v426[0][v427][v428] = v431;	// L674
    }
  }
}

void kernel78(
  float v432[1][384][64],
  float v433
) {	// L679
  for (int v434 = 0; v434 < 384; v434 += 1) {	// L680
    for (int v435 = 0; v435 < 64; v435 += 1) {	// L681
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v432
      float v436 = v432[0][v434][v435];	// L682
      float v437 = v436 / v433;	// L683
      v432[0][v434][v435] = v437;	// L684
    }
  }
}

void kernel83(
  float v438[1][384][8][8],
  float v439[384][384][1],
  float v440[1][384][64]
) {	// L689


  for (int v442 = 0; v442 < 384; v442 += 1) {	// L692
    for (int v443 = 0; v443 < 384; v443 += 1) {	// L693
      for (int v444 = 0; v444 < 64; v444 += 1) {	// L694
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v438
        #pragma HLS dependence false variable=v440
        #pragma HLS dependence false variable=v439
        float v445 = v438[0][v442][(v444 / 8)][(v444 % 8)];	// L695
        float v446 = v439[v443][v442][0];	// L696
        float v447 = v440[0][v443][v444];	// L697
        float v448 = v445 * v446;	// L698
        float v449 = v447 + v448;	// L699
        v440[0][v443][v444] = v449;	// L700
      }
    }
  }
}

void kernel188(
  float v450[12][64][32],
  float v451[12][64][32]
) {	// L706
  for (int v452 = 0; v452 < 12; v452 += 1) {	// L707
    for (int v453 = 0; v453 < 64; v453 += 1) {	// L708
      for (int v454 = 0; v454 < 32; v454 += 1) {	// L709
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v450
        #pragma HLS dependence false variable=v451
        float v455 = v450[v452][v453][v454];	// L710
        v451[v452][v453][v454] = v455;	// L711
      }
    }
  }
}

void kernel192(
  float v456[12][64][64],
  float v457[12][64][64]
) {	// L717
  for (int v458 = 0; v458 < 12; v458 += 1) {	// L718
    for (int v459 = 0; v459 < 64; v459 += 1) {	// L719
      for (int v460 = 0; v460 < 64; v460 += 1) {	// L720
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v456
        #pragma HLS dependence false variable=v457
        float v461 = v456[v458][v459][v460];	// L721
        v457[v458][v459][v460] = v461;	// L722
      }
    }
  }
}

void kernel447(
  float v462[12][64][32],
  float v463
) {	// L728
  for (int v464 = 0; v464 < 12; v464 += 1) {	// L729
    for (int v465 = 0; v465 < 64; v465 += 1) {	// L730
      for (int v466 = 0; v466 < 32; v466 += 1) {	// L731
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v462
        v462[v464][v465][v466] = v463;	// L732
      }
    }
  }
}

void kernel452(
  float v467[12][64][64],
  float v468
) {	// L738
  for (int v469 = 0; v469 < 12; v469 += 1) {	// L739
    for (int v470 = 0; v470 < 64; v470 += 1) {	// L740
      for (int v471 = 0; v471 < 64; v471 += 1) {	// L741
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v467
        v467[v469][v470][v471] = v468;	// L742
      }
    }
  }
}

void kernel523(
  float v472[1][384][10][10],
  float v473[384][384][3][3],
  float v474[1][384][8][8]
) {	// L748


  for (int v476 = 0; v476 < 384; v476 += 1) {	// L751
    for (int v477 = 0; v477 < 3; v477 += 1) {	// L752
      for (int v478 = 0; v478 < 3; v478 += 1) {	// L753
        for (int v479 = 0; v479 < 384; v479 += 1) {	// L754
          for (int v480 = 0; v480 < 8; v480 += 1) {	// L755
            for (int v481 = 0; v481 < 8; v481 += 1) {	// L756
              #pragma HLS pipeline II=1
              #pragma HLS dependence false variable=v472
              #pragma HLS dependence false variable=v474
              #pragma HLS dependence false variable=v473
              float v482 = v472[0][v476][(v480 + v477)][(v481 + v478)];	// L757
              float v483 = v473[v479][v476][v477][v478];	// L758
              float v484 = v474[0][v479][v480][v481];	// L759
              float v485 = v482 * v483;	// L760
              float v486 = v484 + v485;	// L761
              v474[0][v479][v480][v481] = v486;	// L762
            }
          }
        }
      }
    }
  }
}

void kernel525(
  float v487[1][384][8][8],
  float v488[1][384][10][10]
) {	// L771
  for (int v489 = 0; v489 < 384; v489 += 1) {	// L772
    for (int v490 = 0; v490 < 8; v490 += 1) {	// L773
      for (int v491 = 0; v491 < 8; v491 += 1) {	// L774
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v487
        #pragma HLS dependence false variable=v488
        float v492 = v487[0][v489][v490][v491];	// L775
        v488[0][v489][(v490 + 1)][(v491 + 1)] = v492;	// L776
      }
    }
  }
}

void kernel526(
  float v493[1][384][10][10],
  float v494
) {	// L782
  for (int v495 = 0; v495 < 384; v495 += 1) {	// L783
    for (int v496 = 0; v496 < 10; v496 += 1) {	// L784
      for (int v497 = 0; v497 < 10; v497 += 1) {	// L785
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v493
        v493[0][v495][v496][v497] = v494;	// L786
      }
    }
  }
}

void kernel527(
  float v498[1][384][18][18],
  float v499[3][3],
  float v500[1][384][8][8]
) {	// L792
  for (int v501 = 0; v501 < 3; v501 += 1) {	// L793
    for (int v502 = 0; v502 < 3; v502 += 1) {	// L794
      for (int v503 = 0; v503 < 384; v503 += 1) {	// L795
        for (int v504 = 0; v504 < 8; v504 += 1) {	// L796
          for (int v505 = 0; v505 < 8; v505 += 1) {	// L797
            #pragma HLS pipeline II=1
            #pragma HLS dependence false variable=v498
            #pragma HLS dependence false variable=v500
            float v506 = v498[0][v503][((v504 * 2) + v501)][((v505 * 2) + v502)];	// L798
            float v507 = v500[0][v503][v504][v505];	// L799
            float v508 = max(v507, v506);	// L800
            v500[0][v503][v504][v505] = v508;	// L801
          }
        }
      }
    }
  }
}

void kernel528(
  float v509[1][384][8][8],
  float v510
) {	// L809
  for (int v511 = 0; v511 < 384; v511 += 1) {	// L810
    for (int v512 = 0; v512 < 8; v512 += 1) {	// L811
      for (int v513 = 0; v513 < 8; v513 += 1) {	// L812
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v509
        v509[0][v511][v512][v513] = v510;	// L813
      }
    }
  }
}

void kernel529(
  float v514[1][384][16][16],
  float v515[1][384][18][18]
) {	// L819
  for (int v516 = 0; v516 < 384; v516 += 1) {	// L820
    for (int v517 = 0; v517 < 16; v517 += 1) {	// L821
      for (int v518 = 0; v518 < 16; v518 += 1) {	// L822
        #pragma HLS pipeline II=1
        float v519 = v514[0][v516][v517][v518];	// L823
        v515[0][v516][(v517 + 1)][(v518 + 1)] = v519;	// L824
      }
    }
  }
}

void kernel530(
  float v520[1][384][18][18],
  float v521
) {	// L830
  for (int v522 = 0; v522 < 384; v522 += 1) {	// L831
    for (int v523 = 0; v523 < 18; v523 += 1) {	// L832
      for (int v524 = 0; v524 < 18; v524 += 1) {	// L833
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v520
        v520[0][v522][v523][v524] = v521;	// L834
      }
    }
  }
}

void kernel531(
  float v525[1][384][16][16],
  float v526[1][384][16][16]
) {	// L840
  for (int v527 = 0; v527 < 384; v527 += 1) {	// L841
    for (int v528 = 0; v528 < 16; v528 += 1) {	// L842
      for (int v529 = 0; v529 < 16; v529 += 1) {	// L843
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v525
        #pragma HLS dependence false variable=v526
        float v530 = v525[0][v527][v528][v529];	// L844
        v526[0][v527][v528][v529] = v530;	// L845
      }
    }
  }
}

void kernel532(
  float v531[1][384][16][16],
  float v532[1][384][16][16]
) {	// L851
  for (int v533 = 0; v533 < 384; v533 += 1) {	// L852
    for (int v534 = 0; v534 < 16; v534 += 1) {	// L853
      for (int v535 = 0; v535 < 16; v535 += 1) {	// L854
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v531
        #pragma HLS dependence false variable=v532
        float v536 = v531[0][v533][v534][v535];	// L855
        float v537 = v532[0][v533][v534][v535];	// L856
        float v538 = v536 + v537;	// L857
        v532[0][v533][v534][v535] = v538;	// L858
      }
    }
  }
}

void kernel533(
  float v539[1][384][16][16],
  float v540[1][384][16][16],
  float v541[1][384][16][16]
) {	// L864
  for (int v542 = 0; v542 < 384; v542 += 1) {	// L865
    for (int v543 = 0; v543 < 16; v543 += 1) {	// L866
      for (int v544 = 0; v544 < 16; v544 += 1) {	// L867
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v540
        #pragma HLS dependence false variable=v541
        #pragma HLS dependence false variable=v539
        float v545 = v540[0][v542][v543][v544];	// L868
        float v546 = v539[0][v542][v543][v544];	// L869
        float v547 = v545 - v546;	// L870
        v541[0][v542][v543][v544] = v547;	// L871
      }
    }
  }
}

void kernel534(
  float v548[1][384][16][16],
  float v549[1][384][16][16],
  float v550
) {	// L877
  for (int v551 = 0; v551 < 384; v551 += 1) {	// L878
    for (int v552 = 0; v552 < 16; v552 += 1) {	// L879
      for (int v553 = 0; v553 < 16; v553 += 1) {	// L880
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v549
        #pragma HLS dependence false variable=v548
        float v554 = v549[0][v551][v552][v553];	// L881
        float v555 = v548[0][v551][v552][v553];	// L882
        bool v556 = v554 >= v550;	// L883
        float v557 = v556 ? v555 : v550;	// L884
        v549[0][v551][v552][v553] = v557;	// L885
      }
    }
  }
}

void kernel535(
  float v558[1][384][16][16],
  float v559,
  float v560
) {	// L891
  for (int v561 = 0; v561 < 384; v561 += 1) {	// L892
    for (int v562 = 0; v562 < 16; v562 += 1) {	// L893
      for (int v563 = 0; v563 < 16; v563 += 1) {	// L894
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v558
        float v564 = v558[0][v561][v562][v563];	// L895
        bool v565 = v564 >= v560;	// L896
        float v566 = v565 ? v559 : v560;	// L897
        v558[0][v561][v562][v563] = v566;	// L898
      }
    }
  }
}

void kernel537(
  float v567[1][384][16][16],
  float v568
) {	// L904
  for (int v569 = 0; v569 < 384; v569 += 1) {	// L905
    for (int v570 = 0; v570 < 16; v570 += 1) {	// L906
      for (int v571 = 0; v571 < 16; v571 += 1) {	// L907
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v567
        float v572 = v567[0][v569][v570][v571];	// L908
        float v573 = v572 - v568;	// L909
        v567[0][v569][v570][v571] = v573;	// L910
      }
    }
  }
}

void kernel539(
  float v574[1][384][16][16],
  float v575[1][384][16][16],
  float v576[1][384][16][16]
) {	// L916
  for (int v577 = 0; v577 < 384; v577 += 1) {	// L917
    for (int v578 = 0; v578 < 16; v578 += 1) {	// L918
      for (int v579 = 0; v579 < 16; v579 += 1) {	// L919
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v575
        #pragma HLS dependence false variable=v576
        #pragma HLS dependence false variable=v574
        float v580 = v575[0][v577][v578][v579];	// L920
        float v581 = v574[0][v577][v578][v579];	// L921
        float v582 = v580 + v581;	// L922
        v576[0][v577][v578][v579] = v582;	// L923
      }
    }
  }
}

void kernel540(
  float v583[1][384][16][16],
  float v584
) {	// L929
  for (int v585 = 0; v585 < 384; v585 += 1) {	// L930
    for (int v586 = 0; v586 < 16; v586 += 1) {	// L931
      for (int v587 = 0; v587 < 16; v587 += 1) {	// L932
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v583
        float v588 = v583[0][v585][v586][v587];	// L933
        float v589 = v588 / v584;	// L934
        v583[0][v585][v586][v587] = v589;	// L935
      }
    }
  }
}

void kernel545(
  float v590[1][192][18][18],
  float v591[384][192][3][3],
  float v592[1][384][16][16]
) {	// L941


  for (int v594 = 0; v594 < 192; v594 += 1) {	// L944
    for (int v595 = 0; v595 < 3; v595 += 1) {	// L945
      for (int v596 = 0; v596 < 3; v596 += 1) {	// L946
        for (int v597 = 0; v597 < 384; v597 += 1) {	// L947
          for (int v598 = 0; v598 < 16; v598 += 1) {	// L948
            for (int v599 = 0; v599 < 16; v599 += 1) {	// L949
              #pragma HLS pipeline II=1
              #pragma HLS dependence false variable=v590
              #pragma HLS dependence false variable=v592
              #pragma HLS dependence false variable=v591
              float v600 = v590[0][v594][(v598 + v595)][(v599 + v596)];	// L950
              float v601 = v591[v597][v594][v595][v596];	// L951
              float v602 = v592[0][v597][v598][v599];	// L952
              float v603 = v600 * v601;	// L953
              float v604 = v602 + v603;	// L954
              v592[0][v597][v598][v599] = v604;	// L955
            }
          }
        }
      }
    }
  }
}

void kernel546(
  float v605[384],
  float v606[1][384][16][16]
) {	// L964
  float v607[384];	// L965

  memcpy(v607, v605, 384 * sizeof(float));	// L966

  for (int v608 = 0; v608 < 384; v608 += 1) {	// L967
    for (int v609 = 0; v609 < 16; v609 += 1) {	// L968
      for (int v610 = 0; v610 < 16; v610 += 1) {	// L969
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v607
        #pragma HLS dependence false variable=v606
        float v611 = v607[v608];	// L970
        v606[0][v608][v609][v610] = v611;	// L971
      }
    }
  }
}

void kernel547(
  float v612[1][192][16][16],
  float v613[1][192][18][18]
) {	// L977
  for (int v614 = 0; v614 < 192; v614 += 1) {	// L978
    for (int v615 = 0; v615 < 16; v615 += 1) {	// L979
      for (int v616 = 0; v616 < 16; v616 += 1) {	// L980
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v612
        #pragma HLS dependence false variable=v613
        float v617 = v612[0][v614][v615][v616];	// L981
        v613[0][v614][(v615 + 1)][(v616 + 1)] = v617;	// L982
      }
    }
  }
}

void kernel548(
  float v618[1][192][18][18],
  float v619
) {	// L988
  for (int v620 = 0; v620 < 192; v620 += 1) {	// L989
    for (int v621 = 0; v621 < 18; v621 += 1) {	// L990
      for (int v622 = 0; v622 < 18; v622 += 1) {	// L991
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v618
        v618[0][v620][v621][v622] = v619;	// L992
      }
    }
  }
}

void kernel549(
  float v623[1][192][34][34],
  float v624[3][3],
  float v625[1][192][16][16]
) {	// L998
  for (int v626 = 0; v626 < 3; v626 += 1) {	// L999
    for (int v627 = 0; v627 < 3; v627 += 1) {	// L1000
      for (int v628 = 0; v628 < 192; v628 += 1) {	// L1001
        for (int v629 = 0; v629 < 16; v629 += 1) {	// L1002
          for (int v630 = 0; v630 < 16; v630 += 1) {	// L1003
            #pragma HLS pipeline II=1
            #pragma HLS dependence false variable=v623
            #pragma HLS dependence false variable=v625
            float v631 = v623[0][v628][((v629 * 2) + v626)][((v630 * 2) + v627)];	// L1004
            float v632 = v625[0][v628][v629][v630];	// L1005
            float v633 = max(v632, v631);	// L1006
            v625[0][v628][v629][v630] = v633;	// L1007
          }
        }
      }
    }
  }
}

void kernel550(
  float v634[1][192][16][16],
  float v635
) {	// L1015
  for (int v636 = 0; v636 < 192; v636 += 1) {	// L1016
    for (int v637 = 0; v637 < 16; v637 += 1) {	// L1017
      for (int v638 = 0; v638 < 16; v638 += 1) {	// L1018
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v634
        v634[0][v636][v637][v638] = v635;	// L1019
      }
    }
  }
}

void kernel551(
  float v639[1][192][32][32],
  float v640[1][192][34][34]
) {	// L1025
  for (int v641 = 0; v641 < 192; v641 += 1) {	// L1026
    for (int v642 = 0; v642 < 32; v642 += 1) {	// L1027
      for (int v643 = 0; v643 < 32; v643 += 1) {	// L1028
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v639
        #pragma HLS dependence false variable=v640
        float v644 = v639[0][v641][v642][v643];	// L1029
        v640[0][v641][(v642 + 1)][(v643 + 1)] = v644;	// L1030
      }
    }
  }
}

void kernel552(
  float v645[1][192][34][34],
  float v646
) {	// L1036
  for (int v647 = 0; v647 < 192; v647 += 1) {	// L1037
    for (int v648 = 0; v648 < 34; v648 += 1) {	// L1038
      for (int v649 = 0; v649 < 34; v649 += 1) {	// L1039
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v645
        v645[0][v647][v648][v649] = v646;	// L1040
      }
    }
  }
}

void kernel553(
  float v650[1][192][32][32],
  float v651[1][192][32][32]
) {	// L1046
  for (int v652 = 0; v652 < 192; v652 += 1) {	// L1047
    for (int v653 = 0; v653 < 32; v653 += 1) {	// L1048
      for (int v654 = 0; v654 < 32; v654 += 1) {	// L1049
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v650
        #pragma HLS dependence false variable=v651
        float v655 = v650[0][v652][v653][v654];	// L1050
        v651[0][v652][v653][v654] = v655;	// L1051
      }
    }
  }
}

void kernel554(
  float v656[1][192][32][32],
  float v657[1][192][32][32]
) {	// L1057
  for (int v658 = 0; v658 < 192; v658 += 1) {	// L1058
    for (int v659 = 0; v659 < 32; v659 += 1) {	// L1059
      for (int v660 = 0; v660 < 32; v660 += 1) {	// L1060
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v656
        #pragma HLS dependence false variable=v657
        float v661 = v656[0][v658][v659][v660];	// L1061
        float v662 = v657[0][v658][v659][v660];	// L1062
        float v663 = v661 + v662;	// L1063
        v657[0][v658][v659][v660] = v663;	// L1064
      }
    }
  }
}

void kernel555(
  float v664[1][192][32][32],
  float v665[1][192][32][32],
  float v666[1][192][32][32]
) {	// L1070
  for (int v667 = 0; v667 < 192; v667 += 1) {	// L1071
    for (int v668 = 0; v668 < 32; v668 += 1) {	// L1072
      for (int v669 = 0; v669 < 32; v669 += 1) {	// L1073
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v665
        #pragma HLS dependence false variable=v666
        #pragma HLS dependence false variable=v664
        float v670 = v665[0][v667][v668][v669];	// L1074
        float v671 = v664[0][v667][v668][v669];	// L1075
        float v672 = v670 - v671;	// L1076
        v666[0][v667][v668][v669] = v672;	// L1077
      }
    }
  }
}

void kernel556(
  float v673[1][192][32][32],
  float v674[1][192][32][32],
  float v675
) {	// L1083
  for (int v676 = 0; v676 < 192; v676 += 1) {	// L1084
    for (int v677 = 0; v677 < 32; v677 += 1) {	// L1085
      for (int v678 = 0; v678 < 32; v678 += 1) {	// L1086
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v674
        #pragma HLS dependence false variable=v673
        float v679 = v674[0][v676][v677][v678];	// L1087
        float v680 = v673[0][v676][v677][v678];	// L1088
        bool v681 = v679 >= v675;	// L1089
        float v682 = v681 ? v680 : v675;	// L1090
        v674[0][v676][v677][v678] = v682;	// L1091
      }
    }
  }
}

void kernel557(
  float v683[1][192][32][32],
  float v684,
  float v685
) {	// L1097
  for (int v686 = 0; v686 < 192; v686 += 1) {	// L1098
    for (int v687 = 0; v687 < 32; v687 += 1) {	// L1099
      for (int v688 = 0; v688 < 32; v688 += 1) {	// L1100
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v683
        float v689 = v683[0][v686][v687][v688];	// L1101
        bool v690 = v689 >= v685;	// L1102
        float v691 = v690 ? v684 : v685;	// L1103
        v683[0][v686][v687][v688] = v691;	// L1104
      }
    }
  }
}

void kernel559(
  float v692[1][192][32][32],
  float v693
) {	// L1110
  for (int v694 = 0; v694 < 192; v694 += 1) {	// L1111
    for (int v695 = 0; v695 < 32; v695 += 1) {	// L1112
      for (int v696 = 0; v696 < 32; v696 += 1) {	// L1113
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v692
        float v697 = v692[0][v694][v695][v696];	// L1114
        float v698 = v697 - v693;	// L1115
        v692[0][v694][v695][v696] = v698;	// L1116
      }
    }
  }
}

void kernel561(
  float v699[1][192][32][32],
  float v700[1][192][32][32],
  float v701[1][192][32][32]
) {	// L1122
  for (int v702 = 0; v702 < 192; v702 += 1) {	// L1123
    for (int v703 = 0; v703 < 32; v703 += 1) {	// L1124
      for (int v704 = 0; v704 < 32; v704 += 1) {	// L1125
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v700
        #pragma HLS dependence false variable=v701
        #pragma HLS dependence false variable=v699
        float v705 = v700[0][v702][v703][v704];	// L1126
        float v706 = v699[0][v702][v703][v704];	// L1127
        float v707 = v705 + v706;	// L1128
        v701[0][v702][v703][v704] = v707;	// L1129
      }
    }
  }
}

void kernel562(
  float v708[1][192][32][32],
  float v709
) {	// L1135
  for (int v710 = 0; v710 < 192; v710 += 1) {	// L1136
    for (int v711 = 0; v711 < 32; v711 += 1) {	// L1137
      for (int v712 = 0; v712 < 32; v712 += 1) {	// L1138
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v708
        float v713 = v708[0][v710][v711][v712];	// L1139
        float v714 = v713 / v709;	// L1140
        v708[0][v710][v711][v712] = v714;	// L1141
      }
    }
  }
}

void kernel567(
  float v715[1][96][34][34],
  float v716[192][96][3][3],
  float v717[1][192][32][32]
) {	// L1147


  for (int v719 = 0; v719 < 96; v719 += 1) {	// L1150
    for (int v720 = 0; v720 < 3; v720 += 1) {	// L1151
      for (int v721 = 0; v721 < 3; v721 += 1) {	// L1152
        for (int v722 = 0; v722 < 192; v722 += 1) {	// L1153
          for (int v723 = 0; v723 < 32; v723 += 1) {	// L1154
            for (int v724 = 0; v724 < 32; v724 += 1) {	// L1155
              #pragma HLS pipeline II=1
              #pragma HLS dependence false variable=v715
              #pragma HLS dependence false variable=v717
              #pragma HLS dependence false variable=v716
              float v725 = v715[0][v719][(v723 + v720)][(v724 + v721)];	// L1156
              float v726 = v716[v722][v719][v720][v721];	// L1157
              float v727 = v717[0][v722][v723][v724];	// L1158
              float v728 = v725 * v726;	// L1159
              float v729 = v727 + v728;	// L1160
              v717[0][v722][v723][v724] = v729;	// L1161
            }
          }
        }
      }
    }
  }
}

void kernel568(
  float v730[192],
  float v731[1][192][32][32]
) {	// L1170
  float v732[192];	// L1171

  memcpy(v732, v730, 192 * sizeof(float));	// L1172

  for (int v733 = 0; v733 < 192; v733 += 1) {	// L1173
    for (int v734 = 0; v734 < 32; v734 += 1) {	// L1174
      for (int v735 = 0; v735 < 32; v735 += 1) {	// L1175
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v732
        #pragma HLS dependence false variable=v731
        float v736 = v732[v733];	// L1176
        v731[0][v733][v734][v735] = v736;	// L1177
      }
    }
  }
}

void kernel569(
  float v737[1][96][32][32],
  float v738[1][96][34][34]
) {	// L1183
  for (int v739 = 0; v739 < 96; v739 += 1) {	// L1184
    for (int v740 = 0; v740 < 32; v740 += 1) {	// L1185
      for (int v741 = 0; v741 < 32; v741 += 1) {	// L1186
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v737
        #pragma HLS dependence false variable=v738
        float v742 = v737[0][v739][v740][v741];	// L1187
        v738[0][v739][(v740 + 1)][(v741 + 1)] = v742;	// L1188
      }
    }
  }
}

void kernel570(
  float v743[1][96][34][34],
  float v744
) {	// L1194
  for (int v745 = 0; v745 < 96; v745 += 1) {	// L1195
    for (int v746 = 0; v746 < 34; v746 += 1) {	// L1196
      for (int v747 = 0; v747 < 34; v747 += 1) {	// L1197
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v743
        v743[0][v745][v746][v747] = v744;	// L1198
      }
    }
  }
}

void kernel571(
  float v748[1][96][32][32],
  float v749[1][96][32][32]
) {	// L1204
  for (int v750 = 0; v750 < 96; v750 += 1) {	// L1205
    for (int v751 = 0; v751 < 32; v751 += 1) {	// L1206
      for (int v752 = 0; v752 < 32; v752 += 1) {	// L1207
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v748
        #pragma HLS dependence false variable=v749
        float v753 = v748[0][v750][v751][v752];	// L1208
        v749[0][v750][v751][v752] = v753;	// L1209
      }
    }
  }
}

void kernel572(
  float v754[1][96][32][32],
  float v755[1][96][32][32]
) {	// L1215
  for (int v756 = 0; v756 < 96; v756 += 1) {	// L1216
    for (int v757 = 0; v757 < 32; v757 += 1) {	// L1217
      for (int v758 = 0; v758 < 32; v758 += 1) {	// L1218
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v754
        #pragma HLS dependence false variable=v755
        float v759 = v754[0][v756][v757][v758];	// L1219
        float v760 = v755[0][v756][v757][v758];	// L1220
        float v761 = v759 + v760;	// L1221
        v755[0][v756][v757][v758] = v761;	// L1222
      }
    }
  }
}

void kernel573(
  float v762[1][96][32][32],
  float v763[1][96][32][32],
  float v764[1][96][32][32]
) {	// L1228
  for (int v765 = 0; v765 < 96; v765 += 1) {	// L1229
    for (int v766 = 0; v766 < 32; v766 += 1) {	// L1230
      for (int v767 = 0; v767 < 32; v767 += 1) {	// L1231
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v763
        #pragma HLS dependence false variable=v764
        #pragma HLS dependence false variable=v762
        float v768 = v763[0][v765][v766][v767];	// L1232
        float v769 = v762[0][v765][v766][v767];	// L1233
        float v770 = v768 - v769;	// L1234
        v764[0][v765][v766][v767] = v770;	// L1235
      }
    }
  }
}

void kernel574(
  float v771[1][96][32][32],
  float v772[1][96][32][32],
  float v773
) {	// L1241
  for (int v774 = 0; v774 < 96; v774 += 1) {	// L1242
    for (int v775 = 0; v775 < 32; v775 += 1) {	// L1243
      for (int v776 = 0; v776 < 32; v776 += 1) {	// L1244
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v772
        #pragma HLS dependence false variable=v771
        float v777 = v772[0][v774][v775][v776];	// L1245
        float v778 = v771[0][v774][v775][v776];	// L1246
        bool v779 = v777 >= v773;	// L1247
        float v780 = v779 ? v778 : v773;	// L1248
        v772[0][v774][v775][v776] = v780;	// L1249
      }
    }
  }
}

void kernel575(
  float v781[1][96][32][32],
  float v782,
  float v783
) {	// L1255
  for (int v784 = 0; v784 < 96; v784 += 1) {	// L1256
    for (int v785 = 0; v785 < 32; v785 += 1) {	// L1257
      for (int v786 = 0; v786 < 32; v786 += 1) {	// L1258
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v781
        float v787 = v781[0][v784][v785][v786];	// L1259
        bool v788 = v787 >= v783;	// L1260
        float v789 = v788 ? v782 : v783;	// L1261
        v781[0][v784][v785][v786] = v789;	// L1262
      }
    }
  }
}

void kernel577(
  float v790[1][96][32][32],
  float v791
) {	// L1268
  for (int v792 = 0; v792 < 96; v792 += 1) {	// L1269
    for (int v793 = 0; v793 < 32; v793 += 1) {	// L1270
      for (int v794 = 0; v794 < 32; v794 += 1) {	// L1271
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v790
        float v795 = v790[0][v792][v793][v794];	// L1272
        float v796 = v795 - v791;	// L1273
        v790[0][v792][v793][v794] = v796;	// L1274
      }
    }
  }
}

void kernel579(
  float v797[1][96][32][32],
  float v798[1][96][32][32],
  float v799[1][96][32][32]
) {	// L1280
  for (int v800 = 0; v800 < 96; v800 += 1) {	// L1281
    for (int v801 = 0; v801 < 32; v801 += 1) {	// L1282
      for (int v802 = 0; v802 < 32; v802 += 1) {	// L1283
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v798
        #pragma HLS dependence false variable=v799
        #pragma HLS dependence false variable=v797
        float v803 = v798[0][v800][v801][v802];	// L1284
        float v804 = v797[0][v800][v801][v802];	// L1285
        float v805 = v803 + v804;	// L1286
        v799[0][v800][v801][v802] = v805;	// L1287
      }
    }
  }
}

void kernel580(
  float v806[1][96][32][32],
  float v807
) {	// L1293
  for (int v808 = 0; v808 < 96; v808 += 1) {	// L1294
    for (int v809 = 0; v809 < 32; v809 += 1) {	// L1295
      for (int v810 = 0; v810 < 32; v810 += 1) {	// L1296
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v806
        float v811 = v806[0][v808][v809][v810];	// L1297
        float v812 = v811 / v807;	// L1298
        v806[0][v808][v809][v810] = v812;	// L1299
      }
    }
  }
}

void kernel585(
  float v813[1][48][34][34],
  float v814[96][48][3][3],
  float v815[1][96][32][32]
) {	// L1305


  for (int v817 = 0; v817 < 48; v817 += 1) {	// L1308
    for (int v818 = 0; v818 < 3; v818 += 1) {	// L1309
      for (int v819 = 0; v819 < 3; v819 += 1) {	// L1310
        for (int v820 = 0; v820 < 96; v820 += 1) {	// L1311
          for (int v821 = 0; v821 < 32; v821 += 1) {	// L1312
            for (int v822 = 0; v822 < 32; v822 += 1) {	// L1313
              #pragma HLS pipeline II=1
              #pragma HLS dependence false variable=v813
              #pragma HLS dependence false variable=v815
              #pragma HLS dependence false variable=v814
              float v823 = v813[0][v817][(v821 + v818)][(v822 + v819)];	// L1314
              float v824 = v814[v820][v817][v818][v819];	// L1315
              float v825 = v815[0][v820][v821][v822];	// L1316
              float v826 = v823 * v824;	// L1317
              float v827 = v825 + v826;	// L1318
              v815[0][v820][v821][v822] = v827;	// L1319
            }
          }
        }
      }
    }
  }
}

void kernel586(
  float v828[96],
  float v829[1][96][32][32]
) {	// L1328
  float v830[96];	// L1329

  memcpy(v830, v828, 96 * sizeof(float));	// L1330

  for (int v831 = 0; v831 < 96; v831 += 1) {	// L1331
    for (int v832 = 0; v832 < 32; v832 += 1) {	// L1332
      for (int v833 = 0; v833 < 32; v833 += 1) {	// L1333
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v830
        #pragma HLS dependence false variable=v829
        float v834 = v830[v831];	// L1334
        v829[0][v831][v832][v833] = v834;	// L1335
      }
    }
  }
}

void kernel587(
  float v835[1][48][32][32],
  float v836[1][48][34][34]
) {	// L1341
  for (int v837 = 0; v837 < 48; v837 += 1) {	// L1342
    for (int v838 = 0; v838 < 32; v838 += 1) {	// L1343
      for (int v839 = 0; v839 < 32; v839 += 1) {	// L1344
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v835
        #pragma HLS dependence false variable=v836
        float v840 = v835[0][v837][v838][v839];	// L1345
        v836[0][v837][(v838 + 1)][(v839 + 1)] = v840;	// L1346
      }
    }
  }
}

void kernel588(
  float v841[1][48][34][34],
  float v842
) {	// L1352
  for (int v843 = 0; v843 < 48; v843 += 1) {	// L1353
    for (int v844 = 0; v844 < 34; v844 += 1) {	// L1354
      for (int v845 = 0; v845 < 34; v845 += 1) {	// L1355
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v841
        v841[0][v843][v844][v845] = v842;	// L1356
      }
    }
  }
}

void kernel589(
  float v846[1][48][32][32],
  float v847[1][48][32][32]
) {	// L1362
  for (int v848 = 0; v848 < 48; v848 += 1) {	// L1363
    for (int v849 = 0; v849 < 32; v849 += 1) {	// L1364
      for (int v850 = 0; v850 < 32; v850 += 1) {	// L1365
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v846
        #pragma HLS dependence false variable=v847
        float v851 = v846[0][v848][v849][v850];	// L1366
        v847[0][v848][v849][v850] = v851;	// L1367
      }
    }
  }
}

void kernel590(
  float v852[1][48][32][32],
  float v853[1][48][32][32]
) {	// L1373
  for (int v854 = 0; v854 < 48; v854 += 1) {	// L1374
    for (int v855 = 0; v855 < 32; v855 += 1) {	// L1375
      for (int v856 = 0; v856 < 32; v856 += 1) {	// L1376
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v852
        #pragma HLS dependence false variable=v853
        float v857 = v852[0][v854][v855][v856];	// L1377
        float v858 = v853[0][v854][v855][v856];	// L1378
        float v859 = v857 + v858;	// L1379
        v853[0][v854][v855][v856] = v859;	// L1380
      }
    }
  }
}

void kernel591(
  float v860[1][48][32][32],
  float v861[1][48][32][32],
  float v862[1][48][32][32]
) {	// L1386
  for (int v863 = 0; v863 < 48; v863 += 1) {	// L1387
    for (int v864 = 0; v864 < 32; v864 += 1) {	// L1388
      for (int v865 = 0; v865 < 32; v865 += 1) {	// L1389
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v861
        #pragma HLS dependence false variable=v862
        #pragma HLS dependence false variable=v860
        float v866 = v861[0][v863][v864][v865];	// L1390
        float v867 = v860[0][v863][v864][v865];	// L1391
        float v868 = v866 - v867;	// L1392
        v862[0][v863][v864][v865] = v868;	// L1393
      }
    }
  }
}

void kernel592(
  float v869[1][48][32][32],
  float v870[1][48][32][32],
  float v871
) {	// L1399
  for (int v872 = 0; v872 < 48; v872 += 1) {	// L1400
    for (int v873 = 0; v873 < 32; v873 += 1) {	// L1401
      for (int v874 = 0; v874 < 32; v874 += 1) {	// L1402
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v870
        #pragma HLS dependence false variable=v869
        float v875 = v870[0][v872][v873][v874];	// L1403
        float v876 = v869[0][v872][v873][v874];	// L1404
        bool v877 = v875 >= v871;	// L1405
        float v878 = v877 ? v876 : v871;	// L1406
        v870[0][v872][v873][v874] = v878;	// L1407
      }
    }
  }
}

void kernel593(
  float v879[1][48][32][32],
  float v880,
  float v881
) {	// L1413
  for (int v882 = 0; v882 < 48; v882 += 1) {	// L1414
    for (int v883 = 0; v883 < 32; v883 += 1) {	// L1415
      for (int v884 = 0; v884 < 32; v884 += 1) {	// L1416
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v879
        float v885 = v879[0][v882][v883][v884];	// L1417
        bool v886 = v885 >= v881;	// L1418
        float v887 = v886 ? v880 : v881;	// L1419
        v879[0][v882][v883][v884] = v887;	// L1420
      }
    }
  }
}

void kernel595(
  float v888[1][48][32][32],
  float v889
) {	// L1426
  for (int v890 = 0; v890 < 48; v890 += 1) {	// L1427
    for (int v891 = 0; v891 < 32; v891 += 1) {	// L1428
      for (int v892 = 0; v892 < 32; v892 += 1) {	// L1429
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v888
        float v893 = v888[0][v890][v891][v892];	// L1430
        float v894 = v893 - v889;	// L1431
        v888[0][v890][v891][v892] = v894;	// L1432
      }
    }
  }
}

void kernel597(
  float v895[1][48][32][32],
  float v896[1][48][32][32],
  float v897[1][48][32][32]
) {	// L1438
  for (int v898 = 0; v898 < 48; v898 += 1) {	// L1439
    for (int v899 = 0; v899 < 32; v899 += 1) {	// L1440
      for (int v900 = 0; v900 < 32; v900 += 1) {	// L1441
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v896
        #pragma HLS dependence false variable=v897
        #pragma HLS dependence false variable=v895
        float v901 = v896[0][v898][v899][v900];	// L1442
        float v902 = v895[0][v898][v899][v900];	// L1443
        float v903 = v901 + v902;	// L1444
        v897[0][v898][v899][v900] = v903;	// L1445
      }
    }
  }
}

void kernel598(
  float v904[1][48][32][32],
  float v905
) {	// L1451
  for (int v906 = 0; v906 < 48; v906 += 1) {	// L1452
    for (int v907 = 0; v907 < 32; v907 += 1) {	// L1453
      for (int v908 = 0; v908 < 32; v908 += 1) {	// L1454
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v904
        float v909 = v904[0][v906][v907][v908];	// L1455
        float v910 = v909 / v905;	// L1456
        v904[0][v906][v907][v908] = v910;	// L1457
      }
    }
  }
}

void kernel603(
  float v911[1][3][34][34],
  float v912[48][3][3][3],
  float v913[1][48][32][32]
) {	// L1463
  float v914[48][3][3][3];	// L1464

  memcpy(v914, v912, 1296 * sizeof(float));	// L1465

  for (int v915 = 0; v915 < 3; v915 += 1) {	// L1466
    for (int v916 = 0; v916 < 3; v916 += 1) {	// L1467
      for (int v917 = 0; v917 < 3; v917 += 1) {	// L1468
        for (int v918 = 0; v918 < 48; v918 += 1) {	// L1469
          for (int v919 = 0; v919 < 32; v919 += 1) {	// L1470
            for (int v920 = 0; v920 < 32; v920 += 1) {	// L1471
              #pragma HLS pipeline II=1
              #pragma HLS dependence false variable=v911
              #pragma HLS dependence false variable=v913
              #pragma HLS dependence false variable=v914
              float v921 = v911[0][v915][(v919 + v916)][(v920 + v917)];	// L1472
              float v922 = v914[v918][v915][v916][v917];	// L1473
              float v923 = v913[0][v918][v919][v920];	// L1474
              float v924 = v921 * v922;	// L1475
              float v925 = v923 + v924;	// L1476
              v913[0][v918][v919][v920] = v925;	// L1477
            }
          }
        }
      }
    }
  }
}

void kernel604(
  float v926[48],
  float v927[1][48][32][32]
) {	// L1486
  float v928[48];	// L1487

  memcpy(v928, v926, 48 * sizeof(float));	// L1488

  for (int v929 = 0; v929 < 48; v929 += 1) {	// L1489
    for (int v930 = 0; v930 < 32; v930 += 1) {	// L1490
      for (int v931 = 0; v931 < 32; v931 += 1) {	// L1491
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v928
        #pragma HLS dependence false variable=v927
        float v932 = v928[v929];	// L1492
        v927[0][v929][v930][v931] = v932;	// L1493
      }
    }
  }
}

void kernel605(
  float v933[1][3][32][32],
  float v934[1][3][34][34]
) {	// L1499
  for (int v935 = 0; v935 < 3; v935 += 1) {	// L1500
    for (int v936 = 0; v936 < 32; v936 += 1) {	// L1501
      for (int v937 = 0; v937 < 32; v937 += 1) {	// L1502
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v933
        #pragma HLS dependence false variable=v934
        float v938 = v933[0][v935][v936][v937];	// L1503
        v934[0][v935][(v936 + 1)][(v937 + 1)] = v938;	// L1504
      }
    }
  }
}

void kernel606(
  float v939[1][3][34][34],
  float v940
) {	// L1510
  for (int v941 = 0; v941 < 3; v941 += 1) {	// L1511
    for (int v942 = 0; v942 < 34; v942 += 1) {	// L1512
      for (int v943 = 0; v943 < 34; v943 += 1) {	// L1513
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v939
        v939[0][v941][v942][v943] = v940;	// L1514
      }
    }
  }
}

/// The top function
void control(
  ap_int<32> v944[91189248],
  ap_int<32> v945[91189248],
  ap_int<32> v946[91189248]
) {	// L1520
  #pragma HLS interface s_axilite port=return bundle=ctrl
  #pragma hls interface m_axi offset=direct bundle=g0 port=v944
  #pragma hls stable variable=v944
  #pragma hls interface m_axi offset=direct bundle=g0 port=v945
  #pragma hls stable variable=v945
  #pragma hls interface m_axi offset=direct bundle=g0 port=v946
  #pragma hls stable variable=v946

  auto v947 = reinterpret_cast<float(*)[3][34][34]>(v944 + 6684672);
    kernel606(v947, (float)0.000000);	// L1528
  auto v948 = reinterpret_cast<float(*)[3][32][32]>(v944);
  kernel605(v948, v947);	// L1530
  auto v949 = reinterpret_cast<float(*)[48][32][32]>(v945 + 6906624);
  auto v950 = reinterpret_cast<float(*)>(v946 + 87207936);
  kernel604(v950, v949);	// L1533
  auto v951 = reinterpret_cast<float(*)[3][3][3]>(v946 + 88535040);
  kernel603(v947, v951, v949);	// L1535
  auto v952 = reinterpret_cast<float(*)[48][32][32]>(v944 + 196608);
  auto v953 = reinterpret_cast<float(*)[48][32][32]>(v944 + 6684672);
  kernel589(v952, v953);	// L1538
  kernel598(v953, (float)2.000000);	// L1539
  auto v954 = reinterpret_cast<float(*)[48][32][32]>(v946 + 7128576);
  kernel591(v953, v952, v954);	// L1541
  kernel589(v949, v953);	// L1542
  kernel598(v953, (float)2.000000);	// L1543
  kernel597(v953, v954, v949);	// L1544
  kernel589(v949, v953);	// L1545
  kernel595(v953, (float)1.000000);	// L1546
  auto v955 = reinterpret_cast<float(*)[48][32][32]>(v944 + 7128576);
  kernel589(v953, v955);	// L1548
  kernel593(v955, (float)1.000000, (float)0.000000);	// L1549
  kernel592(v949, v953, (float)0.000000);	// L1550
  auto v956 = reinterpret_cast<float(*)[48][32][32]>(v946 + 7350528);
  kernel591(v953, v949, v956);	// L1552
  kernel590(v956, v953);	// L1553
  kernel589(v953, v952);	// L1554
  auto v957 = reinterpret_cast<float(*)[48][34][34]>(v945 + 6684672);
  kernel588(v957, (float)0.000000);	// L1556
  kernel587(v955, v957);	// L1557
  auto v958 = reinterpret_cast<float(*)[96][32][32]>(v944 + 6906624);
  auto v959 = reinterpret_cast<float(*)>(v946 + 84553728);
  kernel586(v959, v958);	// L1560
  auto v960 = reinterpret_cast<float(*)[48][3][3]>(v946 + 85880832);
  kernel585(v957, v960, v958);	// L1562
  auto v961 = reinterpret_cast<float(*)[96][32][32]>(v944 + 393216);
  auto v962 = reinterpret_cast<float(*)[96][32][32]>(v944 + 6684672);
  kernel571(v961, v962);	// L1565
  kernel580(v962, (float)2.000000);	// L1566
  auto v963 = reinterpret_cast<float(*)[96][32][32]>(v945 + 7128576);
  kernel573(v962, v961, v963);	// L1568
  kernel571(v958, v962);	// L1569
  kernel580(v962, (float)2.000000);	// L1570
  auto v964 = reinterpret_cast<float(*)[96][32][32]>(v945 + 6906624);
  kernel579(v962, v963, v964);	// L1572
  kernel571(v964, v962);	// L1573
  kernel577(v962, (float)1.000000);	// L1574
  auto v965 = reinterpret_cast<float(*)[96][32][32]>(v944 + 7128576);
  kernel571(v962, v965);	// L1576
  kernel575(v965, (float)1.000000, (float)0.000000);	// L1577
  kernel574(v964, v962, (float)0.000000);	// L1578
  auto v966 = reinterpret_cast<float(*)[96][32][32]>(v945 + 7350528);
  kernel573(v962, v964, v966);	// L1580
  kernel572(v966, v962);	// L1581
  kernel571(v962, v961);	// L1582
  auto v967 = reinterpret_cast<float(*)[96][34][34]>(v945 + 6684672);
  kernel570(v967, (float)0.000000);	// L1584
  kernel569(v965, v967);	// L1585
  auto v968 = reinterpret_cast<float(*)[192][32][32]>(v945 + 6906624);
  auto v969 = reinterpret_cast<float(*)>(v946 + 81899520);
  kernel568(v969, v968);	// L1588
  auto v970 = reinterpret_cast<float(*)[96][3][3]>(v946 + 83226624);
  kernel567(v967, v970, v968);	// L1590
  auto v971 = reinterpret_cast<float(*)[192][32][32]>(v944 + 589824);
  auto v972 = reinterpret_cast<float(*)[192][32][32]>(v944 + 6684672);
  kernel553(v971, v972);	// L1593
  kernel562(v972, (float)2.000000);	// L1594
  auto v973 = reinterpret_cast<float(*)[192][32][32]>(v946 + 7128576);
  kernel555(v972, v971, v973);	// L1596
  kernel553(v968, v972);	// L1597
  kernel562(v972, (float)2.000000);	// L1598
  kernel561(v972, v973, v968);	// L1599
  kernel553(v968, v972);	// L1600
  kernel559(v972, (float)1.000000);	// L1601
  auto v974 = reinterpret_cast<float(*)[192][32][32]>(v944 + 7128576);
  kernel553(v972, v974);	// L1603
  kernel557(v974, (float)1.000000, (float)0.000000);	// L1604
  kernel556(v968, v972, (float)0.000000);	// L1605
  auto v975 = reinterpret_cast<float(*)[192][32][32]>(v945 + 7350528);
  kernel555(v972, v968, v975);	// L1607
  kernel554(v975, v972);	// L1608
  kernel553(v972, v971);	// L1609
  auto v976 = reinterpret_cast<float(*)[192][34][34]>(v944 + 6684672);
  kernel552(v976, (float)-INFINITY);	// L1611
  kernel551(v974, v976);	// L1612
  auto v977 = reinterpret_cast<float(*)[192][16][16]>(v945 + 6906624);
  kernel550(v977, (float)-INFINITY);	// L1614
  auto v978 = reinterpret_cast<float(*)[3]>(v945 + 7128576);
  kernel549(v976, v978, v977);	// L1616
  auto v979 = reinterpret_cast<float(*)[192][18][18]>(v944 + 6684672);
  kernel548(v979, (float)0.000000);	// L1618
  kernel547(v977, v979);	// L1619
  auto v980 = reinterpret_cast<float(*)[384][16][16]>(v945 + 6906624);
  auto v981 = reinterpret_cast<float(*)>(v946 + 79245312);
  kernel546(v981, v980);	// L1622
  auto v982 = reinterpret_cast<float(*)[192][3][3]>(v946 + 80572416);
  kernel545(v979, v982, v980);	// L1624
  auto v983 = reinterpret_cast<float(*)[384][16][16]>(v944 + 786432);
  auto v984 = reinterpret_cast<float(*)[384][16][16]>(v945 + 6684672);
  kernel531(v983, v984);	// L1627
  kernel540(v984, (float)2.000000);	// L1628
  auto v985 = reinterpret_cast<float(*)[384][16][16]>(v946 + 7350528);
  kernel533(v984, v983, v985);	// L1630
  kernel531(v980, v984);	// L1631
  kernel540(v984, (float)2.000000);	// L1632
  auto v986 = reinterpret_cast<float(*)[384][16][16]>(v944 + 6906624);
  kernel539(v984, v985, v986);	// L1634
  kernel531(v986, v984);	// L1635
  kernel537(v984, (float)1.000000);	// L1636
  auto v987 = reinterpret_cast<float(*)[384][16][16]>(v945 + 7350528);
  kernel531(v984, v987);	// L1638
  kernel535(v987, (float)1.000000, (float)0.000000);	// L1639
  kernel534(v986, v984, (float)0.000000);	// L1640
  auto v988 = reinterpret_cast<float(*)[384][16][16]>(v944 + 7572480);
  kernel533(v984, v986, v988);	// L1642
  kernel532(v988, v984);	// L1643
  kernel531(v984, v983);	// L1644
  auto v989 = reinterpret_cast<float(*)[384][18][18]>(v944 + 6684672);
  kernel530(v989, (float)-INFINITY);	// L1646
  kernel529(v987, v989);	// L1647
  auto v990 = reinterpret_cast<float(*)[384][8][8]>(v944 + 6906624);
  kernel528(v990, (float)-INFINITY);	// L1649
  kernel527(v989, v978, v990);	// L1650
  auto v991 = reinterpret_cast<float(*)[384][10][10]>(v944 + 6684672);
  kernel526(v991, (float)0.000000);	// L1652
  kernel525(v990, v991);	// L1653
  auto v992 = reinterpret_cast<float(*)[384][8][8]>(v945 + 7128576);
  auto v993 = reinterpret_cast<float(*)>(v946 + 76591104);
  kernel9(v993, v992);	// L1656
  auto v994 = reinterpret_cast<float(*)[384][3][3]>(v946 + 77918208);
  kernel523(v991, v994, v992);	// L1658
  auto v995 = reinterpret_cast<float(*)[384][8][8]>(v944 + 983040);
  kernel26(v995, v990);	// L1660
  kernel35(v990, (float)2.000000);	// L1661
  auto v996 = reinterpret_cast<float(*)[384][8][8]>(v945 + 6684672);
  kernel28(v990, v995, v996);	// L1663
  kernel26(v992, v990);	// L1664
  kernel35(v990, (float)2.000000);	// L1665
  auto v997 = reinterpret_cast<float(*)[384][8][8]>(v945 + 7350528);
  kernel34(v990, v996, v997);	// L1667
  kernel26(v997, v990);	// L1668
  kernel32(v990, (float)1.000000);	// L1669
  kernel26(v990, v996);	// L1670
  kernel30(v996, (float)1.000000, (float)0.000000);	// L1671
  kernel29(v997, v990, (float)0.000000);	// L1672
  auto v998 = reinterpret_cast<float(*)[384][8][8]>(v946 + 7572480);
  kernel28(v990, v997, v998);	// L1674
  kernel7(v998, v990);	// L1675
  kernel26(v990, v995);	// L1676
  auto v999 = reinterpret_cast<float(*)[384][64]>(v944 + 7350528);
  auto v1000 = reinterpret_cast<float(*)>(v946 + 73936896);
  kernel42(v1000, v999);	// L1679
  auto v1001 = reinterpret_cast<float(*)[384][1]>(v946 + 75264000);
  kernel83(v996, v1001, v999);	// L1681
  auto v1002 = reinterpret_cast<float(*)[384][64]>(v944 + 1179648);
  auto v1003 = reinterpret_cast<float(*)[384][64]>(v944 + 7572480);
  kernel69(v1002, v1003);	// L1684
  kernel78(v1003, (float)2.000000);	// L1685
  auto v1004 = reinterpret_cast<float(*)[384][64]>(v945 + 7794432);
  kernel71(v1003, v1002, v1004);	// L1687
  kernel69(v999, v1003);	// L1688
  kernel78(v1003, (float)2.000000);	// L1689
  auto v1005 = reinterpret_cast<float(*)[384][64]>(v945 + 7350528);
  kernel77(v1003, v1004, v1005);	// L1691
  kernel69(v1005, v1003);	// L1692
  kernel75(v1003, (float)1.000000);	// L1693
  kernel69(v1003, v1004);	// L1694
  kernel73(v1004, (float)1.000000, (float)0.000000);	// L1695
  kernel72(v1005, v1003, (float)0.000000);	// L1696
  auto v1006 = reinterpret_cast<float(*)[384][64]>(v946 + 8016384);
  kernel71(v1003, v1005, v1006);	// L1698
  kernel70(v1006, v1003);	// L1699
  kernel69(v1003, v1002);	// L1700
  auto v1007 = reinterpret_cast<float(*)[64][384]>(v944 + 7350528);
  kernel68(v1004, v1007);	// L1702
  auto v1008 = reinterpret_cast<float(*)[12][64][32]>(v945 + 7794432);
  kernel67(v1007, v1008);	// L1704
  auto v1009 = reinterpret_cast<float(*)[384][64]>(v945 + 8016384);
  auto v1010 = reinterpret_cast<float(*)>(v946 + 71282688);
  kernel42(v1010, v1009);	// L1707
  auto v1011 = reinterpret_cast<float(*)[384][1]>(v946 + 72609792);
  kernel83(v996, v1011, v1009);	// L1709
  auto v1012 = reinterpret_cast<float(*)[384][64]>(v944 + 1376256);
  kernel69(v1012, v1003);	// L1711
  kernel78(v1003, (float)2.000000);	// L1712
  auto v1013 = reinterpret_cast<float(*)[384][64]>(v945 + 8238336);
  kernel71(v1003, v1012, v1013);	// L1714
  kernel69(v1009, v1003);	// L1715
  kernel78(v1003, (float)2.000000);	// L1716
  kernel77(v1003, v1013, v1009);	// L1717
  kernel69(v1009, v1003);	// L1718
  kernel75(v1003, (float)1.000000);	// L1719
  kernel69(v1003, v1013);	// L1720
  kernel73(v1013, (float)1.000000, (float)0.000000);	// L1721
  kernel72(v1009, v1003, (float)0.000000);	// L1722
  auto v1014 = reinterpret_cast<float(*)[384][64]>(v945 + 8460288);
  kernel71(v1003, v1009, v1014);	// L1724
  kernel70(v1014, v1003);	// L1725
  kernel69(v1003, v1012);	// L1726
  auto v1015 = reinterpret_cast<float(*)[64][384]>(v944 + 8016384);
  kernel68(v1013, v1015);	// L1728
  auto v1016 = reinterpret_cast<float(*)>(v946 + 68628480);
  kernel42(v1016, v1013);	// L1730
  auto v1017 = reinterpret_cast<float(*)[384][1]>(v946 + 69955584);
  kernel83(v996, v1017, v1013);	// L1732
  auto v1018 = reinterpret_cast<float(*)[384][64]>(v944 + 1572864);
  kernel69(v1018, v1003);	// L1734
  kernel78(v1003, (float)2.000000);	// L1735
  auto v1019 = reinterpret_cast<float(*)[384][64]>(v945 + 6684672);
  kernel71(v1003, v1018, v1019);	// L1737
  kernel69(v1013, v1003);	// L1738
  kernel78(v1003, (float)2.000000);	// L1739
  auto v1020 = reinterpret_cast<float(*)[384][64]>(v946 + 8238336);
  kernel77(v1003, v1019, v1020);	// L1741
  kernel69(v1020, v1003);	// L1742
  kernel75(v1003, (float)1.000000);	// L1743
  kernel69(v1003, v1019);	// L1744
  kernel73(v1019, (float)1.000000, (float)0.000000);	// L1745
  kernel72(v1020, v1003, (float)0.000000);	// L1746
  kernel71(v1003, v1020, v1014);	// L1747
  kernel70(v1014, v1003);	// L1748
  kernel69(v1003, v1018);	// L1749
  kernel68(v1019, v1007);	// L1750
  auto v1021 = reinterpret_cast<float(*)[12][64][32]>(v945 + 6684672);
  kernel67(v1007, v1021);	// L1752
  auto v1022 = reinterpret_cast<float(*)[12][32][64]>(v945 + 8238336);
  kernel66(v1015, v1022);	// L1754
  auto v1023 = reinterpret_cast<float(*)[12][64][32]>(v944 + 8460288);
  kernel61(v1008, v1023);	// L1756
  auto v1024 = reinterpret_cast<float(*)[12][32][64]>(v944 + 7794432);
  kernel64(v1022, v1024);	// L1758
  auto v1025 = reinterpret_cast<float(*)[64][64]>(v944 + 8016384);
  kernel452(v1025, (float)0.000000);	// L1760
  auto v1026 = reinterpret_cast<float(*)[64][64]>(v945 + 8238336);
  kernel192(v1025, v1026);	// L1762
  kernel63(v1023, v1024, v1026);	// L1763
  auto v1027 = reinterpret_cast<float(*)[12][64][64]>(v945 + 8682240);
  kernel62(v1026, v1027);	// L1765
  kernel61(v1021, v1023);	// L1766
  auto v1028 = reinterpret_cast<float(*)[64][32]>(v944 + 6684672);
  kernel447(v1028, (float)0.000000);	// L1768
  auto v1029 = reinterpret_cast<float(*)[64][32]>(v945 + 8238336);
  kernel188(v1028, v1029);	// L1770
  kernel60(v1027, v1023, v1029);	// L1771
  auto v1030 = reinterpret_cast<float(*)>(v946 + 89862144);
  kernel59(v1029, v1030, v1023);	// L1773
  auto v1031 = reinterpret_cast<float(*)[64][12][32]>(v945 + 8238336);
  kernel58(v1023, v1031);	// L1775
  auto v1032 = reinterpret_cast<float(*)[64][384]>(v944 + 1769472);
  kernel44(v1032, v1007);	// L1777
  kernel53(v1007, (float)2.000000);	// L1778
  auto v1033 = reinterpret_cast<float(*)[64][384]>(v946 + 8904192);
  kernel46(v1007, v1032, v1033);	// L1780
  kernel54(v1031, v1007);	// L1781
  kernel53(v1007, (float)2.000000);	// L1782
  auto v1034 = reinterpret_cast<float(*)[64][384]>(v945 + 9126144);
  kernel52(v1007, v1033, v1034);	// L1784
  kernel44(v1034, v1007);	// L1785
  kernel50(v1007, (float)0.500000);	// L1786
  auto v1035 = reinterpret_cast<float(*)[64][384]>(v944 + 8904192);
  kernel44(v1007, v1035);	// L1788
  kernel48(v1035, (float)1.000000, (float)0.000000);	// L1789
  kernel47(v1034, v1007, (float)0.000000);	// L1790
  auto v1036 = reinterpret_cast<float(*)[64][384]>(v946 + 9348096);
  kernel46(v1007, v1034, v1036);	// L1792
  kernel45(v1036, v1007);	// L1793
  kernel44(v1007, v1032);	// L1794
  auto v1037 = reinterpret_cast<float(*)[384][64]>(v945 + 9126144);
  kernel43(v1035, v1037);	// L1796
  auto v1038 = reinterpret_cast<float(*)>(v946 + 65974272);
  kernel42(v1038, v1003);	// L1798
  auto v1039 = reinterpret_cast<float(*)[384][1]>(v946 + 67301376);
  kernel41(v1037, v1039, v1003);	// L1800
  auto v1040 = reinterpret_cast<float(*)[384][8][8]>(v946 + 8904192);
  kernel40(v1003, v992, v1040);	// L1802
  auto v1041 = reinterpret_cast<float(*)[384][8][8]>(v944 + 1966080);
  kernel26(v1041, v990);	// L1804
  kernel35(v990, (float)2.000000);	// L1805
  auto v1042 = reinterpret_cast<float(*)[384][8][8]>(v946 + 7128576);
  kernel28(v990, v1041, v1042);	// L1807
  kernel26(v1040, v990);	// L1808
  kernel35(v990, (float)2.000000);	// L1809
  auto v1043 = reinterpret_cast<float(*)[384][8][8]>(v945 + 9126144);
  kernel34(v990, v1042, v1043);	// L1811
  kernel26(v1043, v990);	// L1812
  kernel32(v990, (float)1.000000);	// L1813
  auto v1044 = reinterpret_cast<float(*)[384][8][8]>(v944 + 7128576);
  kernel26(v990, v1044);	// L1815
  kernel30(v1044, (float)1.000000, (float)0.000000);	// L1816
  kernel29(v1043, v990, (float)0.000000);	// L1817
  auto v1045 = reinterpret_cast<float(*)[384][8][8]>(v945 + 9348096);
  kernel28(v990, v1043, v1045);	// L1819
  kernel7(v1045, v990);	// L1820
  kernel26(v990, v1041);	// L1821
  auto v1046 = reinterpret_cast<float(*)[1536][8][8]>(v945 + 9126144);
  auto v1047 = reinterpret_cast<float(*)>(v946 + 63320064);
  kernel25(v1047, v1046);	// L1824
  auto v1048 = reinterpret_cast<float(*)[384][1][1]>(v946 + 64647168);
  kernel24(v1044, v1048, v1046);	// L1826
  auto v1049 = reinterpret_cast<float(*)[1536][8][8]>(v944 + 2162688);
  auto v1050 = reinterpret_cast<float(*)[1536][8][8]>(v944 + 7128576);
  kernel10(v1049, v1050);	// L1829
  kernel19(v1050, (float)2.000000);	// L1830
  auto v1051 = reinterpret_cast<float(*)[1536][8][8]>(v945 + 9348096);
  kernel12(v1050, v1049, v1051);	// L1832
  kernel10(v1046, v1050);	// L1833
  kernel19(v1050, (float)2.000000);	// L1834
  kernel18(v1050, v1051, v1046);	// L1835
  kernel10(v1046, v1050);	// L1836
  kernel16(v1050, (float)1.000000);	// L1837
  kernel10(v1050, v1051);	// L1838
  kernel14(v1051, (float)1.000000, (float)0.000000);	// L1839
  kernel13(v1046, v1050, (float)0.000000);	// L1840
  auto v1052 = reinterpret_cast<float(*)[1536][8][8]>(v946 + 9570048);
  kernel12(v1050, v1046, v1052);	// L1842
  kernel11(v1052, v1050);	// L1843
  kernel10(v1050, v1049);	// L1844
  auto v1053 = reinterpret_cast<float(*)>(v946 + 60665856);
  kernel9(v1053, v990);	// L1846
  auto v1054 = reinterpret_cast<float(*)[1536][1][1]>(v946 + 61992960);
  kernel8(v1051, v1054, v990);	// L1848
  auto v1055 = reinterpret_cast<float(*)[384][8][8]>(v946 + 9126144);
  kernel34(v990, v1040, v1055);	// L1850
  auto v1056 = reinterpret_cast<float(*)[384][8][8]>(v944 + 2359296);
  kernel26(v1056, v990);	// L1852
  kernel35(v990, (float)2.000000);	// L1853
  auto v1057 = reinterpret_cast<float(*)[384][8][8]>(v945 + 8904192);
  kernel28(v990, v1056, v1057);	// L1855
  kernel26(v1055, v990);	// L1856
  kernel35(v990, (float)2.000000);	// L1857
  auto v1058 = reinterpret_cast<float(*)[384][8][8]>(v946 + 9348096);
  kernel34(v990, v1057, v1058);	// L1859
  kernel26(v1058, v990);	// L1860
  kernel32(v990, (float)1.000000);	// L1861
  kernel26(v990, v1057);	// L1862
  kernel30(v1057, (float)1.000000, (float)0.000000);	// L1863
  kernel29(v1058, v990, (float)0.000000);	// L1864
  auto v1059 = reinterpret_cast<float(*)[384][8][8]>(v945 + 9570048);
  kernel28(v990, v1058, v1059);	// L1866
  kernel7(v1059, v990);	// L1867
  kernel26(v990, v1056);	// L1868
  auto v1060 = reinterpret_cast<float(*)[384][64]>(v944 + 9348096);
  auto v1061 = reinterpret_cast<float(*)>(v946 + 58011648);
  kernel42(v1061, v1060);	// L1871
  auto v1062 = reinterpret_cast<float(*)[384][1]>(v946 + 59338752);
  kernel83(v1057, v1062, v1060);	// L1873
  auto v1063 = reinterpret_cast<float(*)[384][64]>(v944 + 2555904);
  kernel69(v1063, v1003);	// L1875
  kernel78(v1003, (float)2.000000);	// L1876
  auto v1064 = reinterpret_cast<float(*)[384][64]>(v946 + 9570048);
  kernel71(v1003, v1063, v1064);	// L1878
  kernel69(v1060, v1003);	// L1879
  kernel78(v1003, (float)2.000000);	// L1880
  auto v1065 = reinterpret_cast<float(*)[384][64]>(v945 + 9348096);
  kernel77(v1003, v1064, v1065);	// L1882
  kernel69(v1065, v1003);	// L1883
  kernel75(v1003, (float)1.000000);	// L1884
  auto v1066 = reinterpret_cast<float(*)[384][64]>(v945 + 9570048);
  kernel69(v1003, v1066);	// L1886
  kernel73(v1066, (float)1.000000, (float)0.000000);	// L1887
  kernel72(v1065, v1003, (float)0.000000);	// L1888
  auto v1067 = reinterpret_cast<float(*)[384][64]>(v945 + 9792000);
  kernel71(v1003, v1065, v1067);	// L1890
  kernel70(v1067, v1003);	// L1891
  kernel69(v1003, v1063);	// L1892
  kernel68(v1066, v1007);	// L1893
  auto v1068 = reinterpret_cast<float(*)[12][64][32]>(v945 + 9348096);
  kernel67(v1007, v1068);	// L1895
  auto v1069 = reinterpret_cast<float(*)>(v946 + 55357440);
  kernel42(v1069, v1066);	// L1897
  auto v1070 = reinterpret_cast<float(*)[384][1]>(v946 + 56684544);
  kernel83(v1057, v1070, v1066);	// L1899
  auto v1071 = reinterpret_cast<float(*)[384][64]>(v944 + 2752512);
  kernel69(v1071, v1003);	// L1901
  kernel78(v1003, (float)2.000000);	// L1902
  auto v1072 = reinterpret_cast<float(*)[384][64]>(v946 + 9792000);
  kernel71(v1003, v1071, v1072);	// L1904
  kernel69(v1066, v1003);	// L1905
  kernel78(v1003, (float)2.000000);	// L1906
  kernel77(v1003, v1072, v1066);	// L1907
  kernel69(v1066, v1003);	// L1908
  kernel75(v1003, (float)1.000000);	// L1909
  auto v1073 = reinterpret_cast<float(*)[384][64]>(v944 + 9792000);
  kernel69(v1003, v1073);	// L1911
  kernel73(v1073, (float)1.000000, (float)0.000000);	// L1912
  kernel72(v1066, v1003, (float)0.000000);	// L1913
  auto v1074 = reinterpret_cast<float(*)[384][64]>(v945 + 10013952);
  kernel71(v1003, v1066, v1074);	// L1915
  kernel70(v1074, v1003);	// L1916
  kernel69(v1003, v1071);	// L1917
  auto v1075 = reinterpret_cast<float(*)[64][384]>(v945 + 9570048);
  kernel68(v1073, v1075);	// L1919
  auto v1076 = reinterpret_cast<float(*)>(v946 + 52703232);
  kernel42(v1076, v1073);	// L1921
  auto v1077 = reinterpret_cast<float(*)[384][1]>(v946 + 54030336);
  kernel83(v1057, v1077, v1073);	// L1923
  auto v1078 = reinterpret_cast<float(*)[384][64]>(v944 + 2949120);
  kernel69(v1078, v1003);	// L1925
  kernel78(v1003, (float)2.000000);	// L1926
  auto v1079 = reinterpret_cast<float(*)[384][64]>(v946 + 8904192);
  kernel71(v1003, v1078, v1079);	// L1928
  kernel69(v1073, v1003);	// L1929
  kernel78(v1003, (float)2.000000);	// L1930
  kernel77(v1003, v1079, v1067);	// L1931
  kernel69(v1067, v1003);	// L1932
  kernel75(v1003, (float)1.000000);	// L1933
  auto v1080 = reinterpret_cast<float(*)[384][64]>(v944 + 8904192);
  kernel69(v1003, v1080);	// L1935
  kernel73(v1080, (float)1.000000, (float)0.000000);	// L1936
  kernel72(v1067, v1003, (float)0.000000);	// L1937
  auto v1081 = reinterpret_cast<float(*)[384][64]>(v946 + 10013952);
  kernel71(v1003, v1067, v1081);	// L1939
  kernel70(v1081, v1003);	// L1940
  kernel69(v1003, v1078);	// L1941
  kernel68(v1080, v1007);	// L1942
  auto v1082 = reinterpret_cast<float(*)[12][64][32]>(v945 + 8904192);
  kernel67(v1007, v1082);	// L1944
  auto v1083 = reinterpret_cast<float(*)[12][32][64]>(v944 + 9792000);
  kernel66(v1075, v1083);	// L1946
  kernel61(v1068, v1023);	// L1947
  kernel64(v1083, v1024);	// L1948
  auto v1084 = reinterpret_cast<float(*)[64][64]>(v944 + 9348096);
  kernel192(v1025, v1084);	// L1950
  kernel63(v1023, v1024, v1084);	// L1951
  kernel62(v1084, v1027);	// L1952
  kernel61(v1082, v1023);	// L1953
  auto v1085 = reinterpret_cast<float(*)[64][32]>(v946 + 8904192);
  kernel188(v1028, v1085);	// L1955
  kernel60(v1027, v1023, v1085);	// L1956
  kernel59(v1085, v1030, v1023);	// L1957
  kernel58(v1023, v1031);	// L1958
  auto v1086 = reinterpret_cast<float(*)[64][384]>(v944 + 3145728);
  kernel44(v1086, v1007);	// L1960
  kernel53(v1007, (float)2.000000);	// L1961
  auto v1087 = reinterpret_cast<float(*)[64][384]>(v945 + 8904192);
  kernel46(v1007, v1086, v1087);	// L1963
  kernel54(v1031, v1007);	// L1964
  kernel53(v1007, (float)2.000000);	// L1965
  kernel52(v1007, v1087, v1036);	// L1966
  kernel44(v1036, v1007);	// L1967
  kernel50(v1007, (float)0.500000);	// L1968
  kernel44(v1007, v1087);	// L1969
  kernel48(v1087, (float)1.000000, (float)0.000000);	// L1970
  kernel47(v1036, v1007, (float)0.000000);	// L1971
  kernel46(v1007, v1036, v1075);	// L1972
  kernel45(v1075, v1007);	// L1973
  kernel44(v1007, v1086);	// L1974
  kernel43(v1087, v1060);	// L1975
  auto v1088 = reinterpret_cast<float(*)>(v946 + 50049024);
  kernel42(v1088, v1003);	// L1977
  auto v1089 = reinterpret_cast<float(*)[384][1]>(v946 + 51376128);
  kernel41(v1060, v1089, v1003);	// L1979
  kernel40(v1003, v1055, v1057);	// L1980
  auto v1090 = reinterpret_cast<float(*)[384][8][8]>(v944 + 3342336);
  kernel26(v1090, v990);	// L1982
  kernel35(v990, (float)2.000000);	// L1983
  kernel28(v990, v1090, v1043);	// L1984
  kernel26(v1057, v990);	// L1985
  kernel35(v990, (float)2.000000);	// L1986
  kernel34(v990, v1043, v1045);	// L1987
  kernel26(v1045, v990);	// L1988
  kernel32(v990, (float)1.000000);	// L1989
  kernel26(v990, v1043);	// L1990
  kernel30(v1043, (float)1.000000, (float)0.000000);	// L1991
  kernel29(v1045, v990, (float)0.000000);	// L1992
  auto v1091 = reinterpret_cast<float(*)[384][8][8]>(v946 + 9570048);
  kernel28(v990, v1045, v1091);	// L1994
  kernel7(v1091, v990);	// L1995
  kernel26(v990, v1090);	// L1996
  auto v1092 = reinterpret_cast<float(*)[1536][8][8]>(v944 + 9348096);
  auto v1093 = reinterpret_cast<float(*)>(v946 + 47394816);
  kernel25(v1093, v1092);	// L1999
  auto v1094 = reinterpret_cast<float(*)[384][1][1]>(v946 + 48721920);
  kernel24(v1043, v1094, v1092);	// L2001
  auto v1095 = reinterpret_cast<float(*)[1536][8][8]>(v944 + 3538944);
  kernel10(v1095, v1050);	// L2003
  kernel19(v1050, (float)2.000000);	// L2004
  auto v1096 = reinterpret_cast<float(*)[1536][8][8]>(v946 + 9126144);
  kernel12(v1050, v1095, v1096);	// L2006
  kernel10(v1092, v1050);	// L2007
  kernel19(v1050, (float)2.000000);	// L2008
  kernel18(v1050, v1096, v1051);	// L2009
  kernel10(v1051, v1050);	// L2010
  kernel16(v1050, (float)1.000000);	// L2011
  kernel10(v1050, v1046);	// L2012
  kernel14(v1046, (float)1.000000, (float)0.000000);	// L2013
  kernel13(v1051, v1050, (float)0.000000);	// L2014
  kernel12(v1050, v1051, v1052);	// L2015
  kernel11(v1052, v1050);	// L2016
  kernel10(v1050, v1095);	// L2017
  auto v1097 = reinterpret_cast<float(*)>(v946 + 44740608);
  kernel9(v1097, v990);	// L2019
  auto v1098 = reinterpret_cast<float(*)[1536][1][1]>(v946 + 46067712);
  kernel8(v1046, v1098, v990);	// L2021
  kernel34(v990, v1057, v1055);	// L2022
  auto v1099 = reinterpret_cast<float(*)[384][8][8]>(v944 + 3735552);
  kernel26(v1099, v990);	// L2024
  kernel35(v990, (float)2.000000);	// L2025
  kernel28(v990, v1099, v1057);	// L2026
  kernel26(v1055, v990);	// L2027
  kernel35(v990, (float)2.000000);	// L2028
  kernel34(v990, v1057, v1058);	// L2029
  kernel26(v1058, v990);	// L2030
  kernel32(v990, (float)1.000000);	// L2031
  auto v1100 = reinterpret_cast<float(*)[384][8][8]>(v944 + 8904192);
  kernel26(v990, v1100);	// L2033
  kernel30(v1100, (float)1.000000, (float)0.000000);	// L2034
  kernel29(v1058, v990, (float)0.000000);	// L2035
  kernel28(v990, v1058, v1059);	// L2036
  kernel7(v1059, v990);	// L2037
  kernel26(v990, v1099);	// L2038
  auto v1101 = reinterpret_cast<float(*)>(v946 + 42086400);
  kernel42(v1101, v1065);	// L2040
  auto v1102 = reinterpret_cast<float(*)[384][1]>(v946 + 43413504);
  kernel83(v1100, v1102, v1065);	// L2042
  auto v1103 = reinterpret_cast<float(*)[384][64]>(v944 + 3932160);
  kernel69(v1103, v1003);	// L2044
  kernel78(v1003, (float)2.000000);	// L2045
  kernel71(v1003, v1103, v1066);	// L2046
  kernel69(v1065, v1003);	// L2047
  kernel78(v1003, (float)2.000000);	// L2048
  kernel77(v1003, v1066, v1065);	// L2049
  kernel69(v1065, v1003);	// L2050
  kernel75(v1003, (float)1.000000);	// L2051
  auto v1104 = reinterpret_cast<float(*)[384][64]>(v944 + 9570048);
  kernel69(v1003, v1104);	// L2053
  kernel73(v1104, (float)1.000000, (float)0.000000);	// L2054
  kernel72(v1065, v1003, (float)0.000000);	// L2055
  kernel71(v1003, v1065, v1072);	// L2056
  kernel70(v1072, v1003);	// L2057
  kernel69(v1003, v1103);	// L2058
  kernel68(v1104, v1007);	// L2059
  kernel67(v1007, v1068);	// L2060
  auto v1105 = reinterpret_cast<float(*)>(v946 + 39432192);
  kernel42(v1105, v1066);	// L2062
  auto v1106 = reinterpret_cast<float(*)[384][1]>(v946 + 40759296);
  kernel83(v1100, v1106, v1066);	// L2064
  auto v1107 = reinterpret_cast<float(*)[384][64]>(v944 + 4128768);
  kernel69(v1107, v1003);	// L2066
  kernel78(v1003, (float)2.000000);	// L2067
  kernel71(v1003, v1107, v1067);	// L2068
  kernel69(v1066, v1003);	// L2069
  kernel78(v1003, (float)2.000000);	// L2070
  kernel77(v1003, v1067, v1064);	// L2071
  kernel69(v1064, v1003);	// L2072
  kernel75(v1003, (float)1.000000);	// L2073
  kernel69(v1003, v1073);	// L2074
  kernel73(v1073, (float)1.000000, (float)0.000000);	// L2075
  kernel72(v1064, v1003, (float)0.000000);	// L2076
  kernel71(v1003, v1064, v1074);	// L2077
  kernel70(v1074, v1003);	// L2078
  kernel69(v1003, v1107);	// L2079
  auto v1108 = reinterpret_cast<float(*)[64][384]>(v944 + 9570048);
  kernel68(v1073, v1108);	// L2081
  auto v1109 = reinterpret_cast<float(*)>(v946 + 36777984);
  kernel42(v1109, v1067);	// L2083
  auto v1110 = reinterpret_cast<float(*)[384][1]>(v946 + 38105088);
  kernel83(v1100, v1110, v1067);	// L2085
  auto v1111 = reinterpret_cast<float(*)[384][64]>(v944 + 4325376);
  kernel69(v1111, v1003);	// L2087
  kernel78(v1003, (float)2.000000);	// L2088
  kernel71(v1003, v1111, v1079);	// L2089
  kernel69(v1067, v1003);	// L2090
  kernel78(v1003, (float)2.000000);	// L2091
  kernel77(v1003, v1079, v1067);	// L2092
  kernel69(v1067, v1003);	// L2093
  kernel75(v1003, (float)1.000000);	// L2094
  auto v1112 = reinterpret_cast<float(*)[384][64]>(v945 + 8904192);
  kernel69(v1003, v1112);	// L2096
  kernel73(v1112, (float)1.000000, (float)0.000000);	// L2097
  kernel72(v1067, v1003, (float)0.000000);	// L2098
  kernel71(v1003, v1067, v1074);	// L2099
  kernel70(v1074, v1003);	// L2100
  kernel69(v1003, v1111);	// L2101
  kernel68(v1112, v1007);	// L2102
  kernel67(v1007, v1082);	// L2103
  auto v1113 = reinterpret_cast<float(*)[12][32][64]>(v945 + 9792000);
  kernel66(v1108, v1113);	// L2105
  kernel61(v1068, v1023);	// L2106
  kernel64(v1113, v1024);	// L2107
  auto v1114 = reinterpret_cast<float(*)[64][64]>(v945 + 9348096);
  kernel192(v1025, v1114);	// L2109
  kernel63(v1023, v1024, v1114);	// L2110
  kernel62(v1114, v1027);	// L2111
  kernel61(v1082, v1023);	// L2112
  auto v1115 = reinterpret_cast<float(*)[64][32]>(v945 + 8904192);
  kernel188(v1028, v1115);	// L2114
  kernel60(v1027, v1023, v1115);	// L2115
  kernel59(v1115, v1030, v1023);	// L2116
  kernel58(v1023, v1031);	// L2117
  auto v1116 = reinterpret_cast<float(*)[64][384]>(v944 + 4521984);
  kernel44(v1116, v1007);	// L2119
  kernel53(v1007, (float)2.000000);	// L2120
  kernel46(v1007, v1116, v1087);	// L2121
  kernel54(v1031, v1007);	// L2122
  kernel53(v1007, (float)2.000000);	// L2123
  auto v1117 = reinterpret_cast<float(*)[64][384]>(v945 + 9348096);
  kernel52(v1007, v1087, v1117);	// L2125
  kernel44(v1117, v1007);	// L2126
  kernel50(v1007, (float)0.500000);	// L2127
  kernel44(v1007, v1035);	// L2128
  kernel48(v1035, (float)1.000000, (float)0.000000);	// L2129
  kernel47(v1117, v1007, (float)0.000000);	// L2130
  auto v1118 = reinterpret_cast<float(*)[64][384]>(v946 + 9570048);
  kernel46(v1007, v1117, v1118);	// L2132
  kernel45(v1118, v1007);	// L2133
  kernel44(v1007, v1116);	// L2134
  kernel43(v1035, v1065);	// L2135
  auto v1119 = reinterpret_cast<float(*)>(v946 + 34123776);
  kernel42(v1119, v1003);	// L2137
  auto v1120 = reinterpret_cast<float(*)[384][1]>(v946 + 35450880);
  kernel41(v1065, v1120, v1003);	// L2139
  kernel40(v1003, v1055, v1057);	// L2140
  auto v1121 = reinterpret_cast<float(*)[384][8][8]>(v944 + 4718592);
  kernel26(v1121, v990);	// L2142
  kernel35(v990, (float)2.000000);	// L2143
  kernel28(v990, v1121, v1043);	// L2144
  kernel26(v1057, v990);	// L2145
  kernel35(v990, (float)2.000000);	// L2146
  kernel34(v990, v1043, v1045);	// L2147
  kernel26(v1045, v990);	// L2148
  kernel32(v990, (float)1.000000);	// L2149
  auto v1122 = reinterpret_cast<float(*)[384][8][8]>(v944 + 9126144);
  kernel26(v990, v1122);	// L2151
  kernel30(v1122, (float)1.000000, (float)0.000000);	// L2152
  kernel29(v1045, v990, (float)0.000000);	// L2153
  kernel28(v990, v1045, v1059);	// L2154
  kernel7(v1059, v990);	// L2155
  kernel26(v990, v1121);	// L2156
  auto v1123 = reinterpret_cast<float(*)>(v946 + 31469568);
  kernel25(v1123, v1051);	// L2158
  auto v1124 = reinterpret_cast<float(*)[384][1][1]>(v946 + 32796672);
  kernel24(v1122, v1124, v1051);	// L2160
  auto v1125 = reinterpret_cast<float(*)[1536][8][8]>(v944 + 4915200);
  kernel10(v1125, v1050);	// L2162
  kernel19(v1050, (float)2.000000);	// L2163
  kernel12(v1050, v1125, v1046);	// L2164
  kernel10(v1051, v1050);	// L2165
  kernel19(v1050, (float)2.000000);	// L2166
  kernel18(v1050, v1046, v1051);	// L2167
  kernel10(v1051, v1050);	// L2168
  kernel16(v1050, (float)1.000000);	// L2169
  kernel10(v1050, v1046);	// L2170
  kernel14(v1046, (float)1.000000, (float)0.000000);	// L2171
  kernel13(v1051, v1050, (float)0.000000);	// L2172
  auto v1126 = reinterpret_cast<float(*)[1536][8][8]>(v945 + 9570048);
  kernel12(v1050, v1051, v1126);	// L2174
  kernel11(v1126, v1050);	// L2175
  kernel10(v1050, v1125);	// L2176
  auto v1127 = reinterpret_cast<float(*)>(v946 + 28815360);
  kernel9(v1127, v990);	// L2178
  auto v1128 = reinterpret_cast<float(*)[1536][1][1]>(v946 + 30142464);
  kernel8(v1046, v1128, v990);	// L2180
  kernel34(v990, v1057, v1055);	// L2181
  auto v1129 = reinterpret_cast<float(*)[384][8][8]>(v944 + 5111808);
  kernel26(v1129, v990);	// L2183
  kernel35(v990, (float)2.000000);	// L2184
  kernel28(v990, v1129, v1057);	// L2185
  kernel26(v1055, v990);	// L2186
  kernel35(v990, (float)2.000000);	// L2187
  kernel34(v990, v1057, v1058);	// L2188
  kernel26(v1058, v990);	// L2189
  kernel32(v990, (float)1.000000);	// L2190
  kernel26(v990, v1100);	// L2191
  kernel30(v1100, (float)1.000000, (float)0.000000);	// L2192
  kernel29(v1058, v990, (float)0.000000);	// L2193
  kernel28(v990, v1058, v1059);	// L2194
  kernel7(v1059, v990);	// L2195
  kernel26(v990, v1129);	// L2196
  auto v1130 = reinterpret_cast<float(*)>(v946 + 26161152);
  kernel42(v1130, v1065);	// L2198
  auto v1131 = reinterpret_cast<float(*)[384][1]>(v946 + 27488256);
  kernel83(v1100, v1131, v1065);	// L2200
  auto v1132 = reinterpret_cast<float(*)[384][64]>(v944 + 5308416);
  kernel69(v1132, v1003);	// L2202
  kernel78(v1003, (float)2.000000);	// L2203
  kernel71(v1003, v1132, v1066);	// L2204
  kernel69(v1065, v1003);	// L2205
  kernel78(v1003, (float)2.000000);	// L2206
  kernel77(v1003, v1066, v1065);	// L2207
  kernel69(v1065, v1003);	// L2208
  kernel75(v1003, (float)1.000000);	// L2209
  kernel69(v1003, v1066);	// L2210
  kernel73(v1066, (float)1.000000, (float)0.000000);	// L2211
  kernel72(v1065, v1003, (float)0.000000);	// L2212
  kernel71(v1003, v1065, v1072);	// L2213
  kernel70(v1072, v1003);	// L2214
  kernel69(v1003, v1132);	// L2215
  kernel68(v1066, v1007);	// L2216
  kernel67(v1007, v1068);	// L2217
  auto v1133 = reinterpret_cast<float(*)>(v946 + 23506944);
  kernel42(v1133, v1066);	// L2219
  auto v1134 = reinterpret_cast<float(*)[384][1]>(v946 + 24834048);
  kernel83(v1100, v1134, v1066);	// L2221
  auto v1135 = reinterpret_cast<float(*)[384][64]>(v944 + 5505024);
  kernel69(v1135, v1003);	// L2223
  kernel78(v1003, (float)2.000000);	// L2224
  kernel71(v1003, v1135, v1067);	// L2225
  kernel69(v1066, v1003);	// L2226
  kernel78(v1003, (float)2.000000);	// L2227
  kernel77(v1003, v1067, v1066);	// L2228
  kernel69(v1066, v1003);	// L2229
  kernel75(v1003, (float)1.000000);	// L2230
  kernel69(v1003, v1073);	// L2231
  kernel73(v1073, (float)1.000000, (float)0.000000);	// L2232
  kernel72(v1066, v1003, (float)0.000000);	// L2233
  kernel71(v1003, v1066, v1074);	// L2234
  kernel70(v1074, v1003);	// L2235
  kernel69(v1003, v1135);	// L2236
  kernel68(v1073, v1075);	// L2237
  auto v1136 = reinterpret_cast<float(*)>(v946 + 20852736);
  kernel42(v1136, v1067);	// L2239
  auto v1137 = reinterpret_cast<float(*)[384][1]>(v946 + 22179840);
  kernel83(v1100, v1137, v1067);	// L2241
  auto v1138 = reinterpret_cast<float(*)[384][64]>(v944 + 5701632);
  kernel69(v1138, v1003);	// L2243
  kernel78(v1003, (float)2.000000);	// L2244
  kernel71(v1003, v1138, v1112);	// L2245
  kernel69(v1067, v1003);	// L2246
  kernel78(v1003, (float)2.000000);	// L2247
  kernel77(v1003, v1112, v1067);	// L2248
  kernel69(v1067, v1003);	// L2249
  kernel75(v1003, (float)1.000000);	// L2250
  kernel69(v1003, v1112);	// L2251
  kernel73(v1112, (float)1.000000, (float)0.000000);	// L2252
  kernel72(v1067, v1003, (float)0.000000);	// L2253
  kernel71(v1003, v1067, v1081);	// L2254
  kernel70(v1081, v1003);	// L2255
  kernel69(v1003, v1138);	// L2256
  kernel68(v1112, v1007);	// L2257
  kernel67(v1007, v1082);	// L2258
  kernel66(v1075, v1113);	// L2259
  kernel61(v1068, v1023);	// L2260
  kernel64(v1113, v1024);	// L2261
  kernel63(v1023, v1024, v1025);	// L2262
  kernel62(v1025, v1027);	// L2263
  kernel61(v1082, v1023);	// L2264
  kernel60(v1027, v1023, v1028);	// L2265
  kernel59(v1028, v1030, v1023);	// L2266
  kernel58(v1023, v1031);	// L2267
  auto v1139 = reinterpret_cast<float(*)[64][384]>(v944 + 5898240);
  kernel44(v1139, v1007);	// L2269
  kernel53(v1007, (float)2.000000);	// L2270
  auto v1140 = reinterpret_cast<float(*)[64][384]>(v946 + 6684672);
  kernel46(v1007, v1139, v1140);	// L2272
  kernel54(v1031, v1007);	// L2273
  kernel53(v1007, (float)2.000000);	// L2274
  auto v1141 = reinterpret_cast<float(*)[64][384]>(v945 + 7794432);
  kernel52(v1007, v1140, v1141);	// L2276
  kernel44(v1141, v1007);	// L2277
  kernel50(v1007, (float)0.500000);	// L2278
  auto v1142 = reinterpret_cast<float(*)[64][384]>(v944 + 6684672);
  kernel44(v1007, v1142);	// L2280
  kernel48(v1142, (float)1.000000, (float)0.000000);	// L2281
  kernel47(v1141, v1007, (float)0.000000);	// L2282
  auto v1143 = reinterpret_cast<float(*)[64][384]>(v946 + 8016384);
  kernel46(v1007, v1141, v1143);	// L2284
  kernel45(v1143, v1007);	// L2285
  kernel44(v1007, v1139);	// L2286
  kernel43(v1142, v1005);	// L2287
  auto v1144 = reinterpret_cast<float(*)>(v946 + 18198528);
  kernel42(v1144, v1003);	// L2289
  auto v1145 = reinterpret_cast<float(*)[384][1]>(v946 + 19525632);
  kernel41(v1005, v1145, v1003);	// L2291
  kernel40(v1003, v1055, v996);	// L2292
  auto v1146 = reinterpret_cast<float(*)[384][8][8]>(v944 + 6094848);
  kernel26(v1146, v990);	// L2294
  kernel35(v990, (float)2.000000);	// L2295
  auto v1147 = reinterpret_cast<float(*)[384][8][8]>(v946 + 7350528);
  kernel28(v990, v1146, v1147);	// L2297
  kernel26(v996, v990);	// L2298
  kernel35(v990, (float)2.000000);	// L2299
  auto v1148 = reinterpret_cast<float(*)[384][8][8]>(v945 + 7572480);
  kernel34(v990, v1147, v1148);	// L2301
  kernel26(v1148, v990);	// L2302
  kernel32(v990, (float)1.000000);	// L2303
  kernel26(v990, v997);	// L2304
  kernel30(v997, (float)1.000000, (float)0.000000);	// L2305
  kernel29(v1148, v990, (float)0.000000);	// L2306
  auto v1149 = reinterpret_cast<float(*)[384][8][8]>(v945 + 7794432);
  kernel28(v990, v1148, v1149);	// L2308
  kernel7(v1149, v990);	// L2309
  kernel26(v990, v1146);	// L2310
  auto v1150 = reinterpret_cast<float(*)[1536][8][8]>(v945 + 7572480);
  auto v1151 = reinterpret_cast<float(*)>(v946 + 15544320);
  kernel25(v1151, v1150);	// L2313
  auto v1152 = reinterpret_cast<float(*)[384][1][1]>(v946 + 16871424);
  kernel24(v997, v1152, v1150);	// L2315
  auto v1153 = reinterpret_cast<float(*)[1536][8][8]>(v944 + 6291456);
  kernel10(v1153, v1050);	// L2317
  kernel19(v1050, (float)2.000000);	// L2318
  auto v1154 = reinterpret_cast<float(*)[1536][8][8]>(v945 + 7350528);
  kernel12(v1050, v1153, v1154);	// L2320
  kernel10(v1150, v1050);	// L2321
  kernel19(v1050, (float)2.000000);	// L2322
  auto v1155 = reinterpret_cast<float(*)[1536][8][8]>(v946 + 7572480);
  kernel18(v1050, v1154, v1155);	// L2324
  kernel10(v1155, v1050);	// L2325
  kernel16(v1050, (float)1.000000);	// L2326
  kernel10(v1050, v1154);	// L2327
  kernel14(v1154, (float)1.000000, (float)0.000000);	// L2328
  kernel13(v1155, v1050, (float)0.000000);	// L2329
  auto v1156 = reinterpret_cast<float(*)[1536][8][8]>(v945 + 7794432);
  kernel12(v1050, v1155, v1156);	// L2331
  kernel11(v1156, v1050);	// L2332
  kernel10(v1050, v1153);	// L2333
  auto v1157 = reinterpret_cast<float(*)>(v946 + 12890112);
  kernel9(v1157, v990);	// L2335
  auto v1158 = reinterpret_cast<float(*)[1536][1][1]>(v946 + 14217216);
  kernel8(v1154, v1158, v990);	// L2337
  kernel7(v996, v990);	// L2338
  auto v1159 = reinterpret_cast<float(*)[384]>(v944 + 6684672);
  kernel6(v1159, (float)0.000000);	// L2340
  kernel5(v990, v1159);	// L2341
  kernel4(v1159, (float)64.000000);	// L2342
  auto v1160 = reinterpret_cast<float(*)[10]>(v944 + 6906624);
  auto v1161 = reinterpret_cast<float(*)[384]>(v946 + 11563008);
  kernel3(v1161, v1160);	// L2345
  auto v1162 = reinterpret_cast<float(*)[10]>(v944 + 6488064);
  kernel2(v1162, (float)0.000000);	// L2347
  kernel1(v1159, v1160, v1162);	// L2348
  auto v1163 = reinterpret_cast<float(*)>(v946 + 10235904);
  kernel0(v1163, v1162);	// L2350
}

