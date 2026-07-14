
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
  #pragma HLS resource variable=v9 core=ram_t2p_bram

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
  float v30[1][64][384],
  float v31[1][384]
) {	// L49
  for (int v32 = 0; v32 < 64; v32 += 1) {	// L50
    for (int v33 = 0; v33 < 384; v33 += 1) {	// L51
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v30
      #pragma HLS dependence false variable=v31
      float v34 = v30[0][v32][v33];	// L52
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
  float v40[1][64][384],
  float v41[1][64][384],
  float v42[1][64][384]
) {	// L66
  for (int v43 = 0; v43 < 64; v43 += 1) {	// L67
    for (int v44 = 0; v44 < 384; v44 += 1) {	// L68
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v41
      #pragma HLS dependence false variable=v42
      #pragma HLS dependence false variable=v40
      float v45 = v41[0][v43][v44];	// L69
      float v46 = v40[0][v43][v44];	// L70
      float v47 = v45 + v46;	// L71
      v42[0][v43][v44] = v47;	// L72
    }
  }
}

void kernel8(
  float v48[1][64][384],
  float v49[1][64][384]
) {	// L77
  for (int v50 = 0; v50 < 64; v50 += 1) {	// L78
    for (int v51 = 0; v51 < 384; v51 += 1) {	// L79
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v48
      #pragma HLS dependence false variable=v49
      float v52 = v48[0][v50][v51];	// L80
      v49[0][v50][v51] = v52;	// L81
    }
  }
}

void kernel9(
  float v53[1][64][384],
  float v54[1][64][384]
) {	// L86
  for (int v55 = 0; v55 < 64; v55 += 1) {	// L87
    for (int v56 = 0; v56 < 384; v56 += 1) {	// L88
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v53
      #pragma HLS dependence false variable=v54
      float v57 = v53[0][v55][v56];	// L89
      float v58 = v54[0][v55][v56];	// L90
      float v59 = v57 + v58;	// L91
      v54[0][v55][v56] = v59;	// L92
    }
  }
}

void kernel10(
  float v60[1][64][384],
  float v61
) {	// L97
  for (int v62 = 0; v62 < 64; v62 += 1) {	// L98
    for (int v63 = 0; v63 < 384; v63 += 1) {	// L99
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v60
      float v64 = v60[0][v62][v63];	// L100
      float v65 = v64 * v61;	// L101
      v60[0][v62][v63] = v65;	// L102
    }
  }
}

void kernel12(
  float v66[1][64][384],
  float v67[1][64][384],
  float v68[1][64][384]
) {	// L107
  for (int v69 = 0; v69 < 64; v69 += 1) {	// L108
    for (int v70 = 0; v70 < 384; v70 += 1) {	// L109
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v67
      #pragma HLS dependence false variable=v68
      #pragma HLS dependence false variable=v66
      float v71 = v67[0][v69][v70];	// L110
      float v72 = v66[0][v69][v70];	// L111
      float v73 = v71 - v72;	// L112
      v68[0][v69][v70] = v73;	// L113
    }
  }
}

void kernel13(
  float v74[1][64][384],
  float v75[1][64][384],
  float v76[1][64][384]
) {	// L118
  for (int v77 = 0; v77 < 64; v77 += 1) {	// L119
    for (int v78 = 0; v78 < 384; v78 += 1) {	// L120
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v75
      #pragma HLS dependence false variable=v76
      #pragma HLS dependence false variable=v74
      float v79 = v75[0][v77][v78];	// L121
      float v80 = v74[0][v77][v78];	// L122
      float v81 = v79 * v80;	// L123
      v76[0][v77][v78] = v81;	// L124
    }
  }
}

void kernel14(
  float v82[1][64][384],
  float v83,
  float v84
) {	// L129
  for (int v85 = 0; v85 < 64; v85 += 1) {	// L130
    for (int v86 = 0; v86 < 384; v86 += 1) {	// L131
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v82
      float v87 = v82[0][v85][v86];	// L132
      bool v88 = v87 >= v84;	// L133
      float v89 = v88 ? v83 : v84;	// L134
      v82[0][v85][v86] = v89;	// L135
    }
  }
}

void kernel16(
  float v90[1][64][384],
  float v91
) {	// L140
  for (int v92 = 0; v92 < 64; v92 += 1) {	// L141
    for (int v93 = 0; v93 < 384; v93 += 1) {	// L142
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v90
      float v94 = v90[0][v92][v93];	// L143
      float v95 = v94 - v91;	// L144
      v90[0][v92][v93] = v95;	// L145
    }
  }
}

void kernel19(
  float v96[1][64][384],
  float v97
) {	// L150
  for (int v98 = 0; v98 < 64; v98 += 1) {	// L151
    for (int v99 = 0; v99 < 384; v99 += 1) {	// L152
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v96
      float v100 = v96[0][v98][v99];	// L153
      float v101 = v100 / v97;	// L154
      v96[0][v98][v99] = v101;	// L155
    }
  }
}

void kernel24(
  float v102[1][64][384],
  float v103[384],
  float v104[1][64][384]
) {	// L160
  for (int v105 = 0; v105 < 64; v105 += 1) {	// L161
    for (int v106 = 0; v106 < 384; v106 += 1) {	// L162
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v103
      #pragma HLS dependence false variable=v104
      #pragma HLS dependence false variable=v102
      float v107 = v103[v106];	// L163
      float v108 = v102[0][v105][v106];	// L164
      float v109 = v107 + v108;	// L165
      v104[0][v105][v106] = v109;	// L166
    }
  }
}

void kernel25(
  float v110[1][64][1536],
  float v111[1][1536][384],
  float v112[1][64][384]
) {	// L171
  float v113[1][64][1536];	// L172
  #pragma HLS resource variable=v113 core=ram_t2p_bram

  memcpy(v113, v110, 98304 * sizeof(float));	// L173

  for (int v114 = 0; v114 < 1536; v114 += 1) {	// L174
    for (int v115 = 0; v115 < 64; v115 += 1) {	// L175
      for (int v116 = 0; v116 < 384; v116 += 1) {	// L176
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v113
        #pragma HLS dependence false variable=v111
        #pragma HLS dependence false variable=v112
        float v117 = v113[0][v115][v114];	// L177
        float v118 = v111[0][v114][v116];	// L178
        float v119 = v112[0][v115][v116];	// L179
        float v120 = v117 * v118;	// L180
        float v121 = v119 + v120;	// L181
        v112[0][v115][v116] = v121;	// L182
      }
    }
  }
}

void kernel26(
  float v122[1536][384],
  float v123[1][1536][384]
) {	// L188
  for (int v124 = 0; v124 < 1536; v124 += 1) {	// L189
    for (int v125 = 0; v125 < 384; v125 += 1) {	// L190
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v122
      #pragma HLS dependence false variable=v123
      float v126 = v122[v124][v125];	// L191
      v123[0][v124][v125] = v126;	// L192
    }
  }
}

void kernel27(
  float v127[1][64][1536],
  float v128[1][64][1536]
) {	// L197
  for (int v129 = 0; v129 < 64; v129 += 1) {	// L198
    for (int v130 = 0; v130 < 1536; v130 += 1) {	// L199
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v127
      #pragma HLS dependence false variable=v128
      float v131 = v127[0][v129][v130];	// L200
      v128[0][v129][v130] = v131;	// L201
    }
  }
}

void kernel28(
  float v132[1][64][1536],
  float v133[1][64][1536]
) {	// L206
  for (int v134 = 0; v134 < 64; v134 += 1) {	// L207
    for (int v135 = 0; v135 < 1536; v135 += 1) {	// L208
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v132
      #pragma HLS dependence false variable=v133
      float v136 = v132[0][v134][v135];	// L209
      v133[0][v134][v135] = v136;	// L210
    }
  }
}

void kernel29(
  float v137[1][64][1536],
  float v138[1][64][1536]
) {	// L215
  for (int v139 = 0; v139 < 64; v139 += 1) {	// L216
    for (int v140 = 0; v140 < 1536; v140 += 1) {	// L217
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v137
      #pragma HLS dependence false variable=v138
      float v141 = v137[0][v139][v140];	// L218
      float v142 = v138[0][v139][v140];	// L219
      float v143 = v141 + v142;	// L220
      v138[0][v139][v140] = v143;	// L221
    }
  }
}

void kernel30(
  float v144[1][64][1536],
  float v145
) {	// L226
  for (int v146 = 0; v146 < 64; v146 += 1) {	// L227
    for (int v147 = 0; v147 < 1536; v147 += 1) {	// L228
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v144
      float v148 = v144[0][v146][v147];	// L229
      float v149 = v148 * v145;	// L230
      v144[0][v146][v147] = v149;	// L231
    }
  }
}

void kernel32(
  float v150[1][64][1536],
  float v151[1][64][1536],
  float v152[1][64][1536]
) {	// L236
  for (int v153 = 0; v153 < 64; v153 += 1) {	// L237
    for (int v154 = 0; v154 < 1536; v154 += 1) {	// L238
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v151
      #pragma HLS dependence false variable=v152
      #pragma HLS dependence false variable=v150
      float v155 = v151[0][v153][v154];	// L239
      float v156 = v150[0][v153][v154];	// L240
      float v157 = v155 - v156;	// L241
      v152[0][v153][v154] = v157;	// L242
    }
  }
}

void kernel33(
  float v158[1][64][1536],
  float v159[1][64][1536],
  float v160[1][64][1536]
) {	// L247
  for (int v161 = 0; v161 < 64; v161 += 1) {	// L248
    for (int v162 = 0; v162 < 1536; v162 += 1) {	// L249
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v159
      #pragma HLS dependence false variable=v160
      #pragma HLS dependence false variable=v158
      float v163 = v159[0][v161][v162];	// L250
      float v164 = v158[0][v161][v162];	// L251
      float v165 = v163 * v164;	// L252
      v160[0][v161][v162] = v165;	// L253
    }
  }
}

void kernel34(
  float v166[1][64][1536],
  float v167,
  float v168
) {	// L258
  for (int v169 = 0; v169 < 64; v169 += 1) {	// L259
    for (int v170 = 0; v170 < 1536; v170 += 1) {	// L260
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v166
      float v171 = v166[0][v169][v170];	// L261
      bool v172 = v171 >= v168;	// L262
      float v173 = v172 ? v167 : v168;	// L263
      v166[0][v169][v170] = v173;	// L264
    }
  }
}

void kernel36(
  float v174[1][64][1536],
  float v175
) {	// L269
  for (int v176 = 0; v176 < 64; v176 += 1) {	// L270
    for (int v177 = 0; v177 < 1536; v177 += 1) {	// L271
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v174
      float v178 = v174[0][v176][v177];	// L272
      float v179 = v178 - v175;	// L273
      v174[0][v176][v177] = v179;	// L274
    }
  }
}

void kernel38(
  float v180[1][64][1536],
  float v181[1][64][1536],
  float v182[1][64][1536]
) {	// L279
  for (int v183 = 0; v183 < 64; v183 += 1) {	// L280
    for (int v184 = 0; v184 < 1536; v184 += 1) {	// L281
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v181
      #pragma HLS dependence false variable=v182
      #pragma HLS dependence false variable=v180
      float v185 = v181[0][v183][v184];	// L282
      float v186 = v180[0][v183][v184];	// L283
      float v187 = v185 + v186;	// L284
      v182[0][v183][v184] = v187;	// L285
    }
  }
}

void kernel39(
  float v188[1][64][1536],
  float v189
) {	// L290
  for (int v190 = 0; v190 < 64; v190 += 1) {	// L291
    for (int v191 = 0; v191 < 1536; v191 += 1) {	// L292
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v188
      float v192 = v188[0][v190][v191];	// L293
      float v193 = v192 / v189;	// L294
      v188[0][v190][v191] = v193;	// L295
    }
  }
}

void kernel44(
  float v194[1][64][1536],
  float v195[1536],
  float v196[1][64][1536]
) {	// L300
  for (int v197 = 0; v197 < 64; v197 += 1) {	// L301
    for (int v198 = 0; v198 < 1536; v198 += 1) {	// L302
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v195
      #pragma HLS dependence false variable=v196
      #pragma HLS dependence false variable=v194
      float v199 = v195[v198];	// L303
      float v200 = v194[0][v197][v198];	// L304
      float v201 = v199 + v200;	// L305
      v196[0][v197][v198] = v201;	// L306
    }
  }
}

void kernel45(
  float v202[1][64][384],
  float v203[1][384][1536],
  float v204[1][64][1536]
) {	// L311
  float v205[1][64][384];	// L312
  #pragma HLS resource variable=v205 core=ram_t2p_bram

  memcpy(v205, v202, 24576 * sizeof(float));	// L313

  for (int v206 = 0; v206 < 384; v206 += 1) {	// L314
    for (int v207 = 0; v207 < 64; v207 += 1) {	// L315
      for (int v208 = 0; v208 < 1536; v208 += 1) {	// L316
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v205
        #pragma HLS dependence false variable=v203
        #pragma HLS dependence false variable=v204
        float v209 = v205[0][v207][v206];	// L317
        float v210 = v203[0][v206][v208];	// L318
        float v211 = v204[0][v207][v208];	// L319
        float v212 = v209 * v210;	// L320
        float v213 = v211 + v212;	// L321
        v204[0][v207][v208] = v213;	// L322
      }
    }
  }
}

void kernel46(
  float v214[384][1536],
  float v215[1][384][1536]
) {	// L328
  for (int v216 = 0; v216 < 384; v216 += 1) {	// L329
    for (int v217 = 0; v217 < 1536; v217 += 1) {	// L330
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v214
      #pragma HLS dependence false variable=v215
      float v218 = v214[v216][v217];	// L331
      v215[0][v216][v217] = v218;	// L332
    }
  }
}

void kernel47(
  float v219[1][64][384],
  float v220[1][64][384]
) {	// L337
  for (int v221 = 0; v221 < 64; v221 += 1) {	// L338
    for (int v222 = 0; v222 < 384; v222 += 1) {	// L339
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v219
      #pragma HLS dependence false variable=v220
      float v223 = v219[0][v221][v222];	// L340
      v220[0][v221][v222] = v223;	// L341
    }
  }
}

void kernel48(
  float v224[384],
  float v225[1][64][384],
  float v226[1][64][384]
) {	// L346
  for (int v227 = 0; v227 < 64; v227 += 1) {	// L347
    for (int v228 = 0; v228 < 384; v228 += 1) {	// L348
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v225
      #pragma HLS dependence false variable=v226
      #pragma HLS dependence false variable=v224
      float v229 = v225[0][v227][v228];	// L349
      float v230 = v224[v228];	// L350
      float v231 = v229 + v230;	// L351
      v226[0][v227][v228] = v231;	// L352
    }
  }
}

void kernel49(
  float v232[384],
  float v233[1][64][384]
) {	// L357
  for (int v234 = 0; v234 < 64; v234 += 1) {	// L358
    for (int v235 = 0; v235 < 384; v235 += 1) {	// L359
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v233
      #pragma HLS dependence false variable=v232
      float v236 = v233[0][v234][v235];	// L360
      float v237 = v232[v235];	// L361
      float v238 = v236 * v237;	// L362
      v233[0][v234][v235] = v238;	// L363
    }
  }
}

void kernel50(
  float v239[1][64][384],
  float v240[1][64][384]
) {	// L368
  for (int v241 = 0; v241 < 64; v241 += 1) {	// L369
    for (int v242 = 0; v242 < 384; v242 += 1) {	// L370
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v239
      #pragma HLS dependence false variable=v240
      float v243 = v239[0][v241][v242];	// L371
      float v244 = v240[0][v241][v242];	// L372
      float v245 = v243 * v244;	// L373
      v240[0][v241][v242] = v245;	// L374
    }
  }
}

void kernel51(
  float v246[1][64][1],
  float v247[1][64][384]
) {	// L379
  float v248[1][64][1];	// L380
  #pragma HLS resource variable=v248 core=ram_t2p_bram

  memcpy(v248, v246, 64 * sizeof(float));	// L381

  for (int v249 = 0; v249 < 64; v249 += 1) {	// L382
    for (int v250 = 0; v250 < 384; v250 += 1) {	// L383
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v248
      #pragma HLS dependence false variable=v247
      float v251 = v248[0][v249][0];	// L384
      v247[0][v249][v250] = v251;	// L385
    }
  }
}

void kernel52(
  float v252[1][64][1]
) {	// L390
  for (int v253 = 0; v253 < 64; v253 += 1) {	// L391
    float v254 = v252[0][v253][0];	// L392
    float v255 = 1.0 / sqrt(v254);	// L393
    v252[0][v253][0] = v255;	// L394
  }
}

void kernel53(
  float v256[1][64][1],
  float v257
) {	// L398
  for (int v258 = 0; v258 < 64; v258 += 1) {	// L399
    float v259 = v256[0][v258][0];	// L400
    float v260 = v259 + v257;	// L401
    v256[0][v258][0] = v260;	// L402
  }
}

void kernel54(
  float v261[1][64][1],
  float v262
) {	// L406
  for (int v263 = 0; v263 < 64; v263 += 1) {	// L407
    float v264 = v261[0][v263][0];	// L408
    float v265 = v264 / v262;	// L409
    v261[0][v263][0] = v265;	// L410
  }
}

void kernel55(
  float v266[1][64][1],
  float v267[1][64][1]
) {	// L414
  for (int v268 = 0; v268 < 64; v268 += 1) {	// L415
    float v269 = v266[0][v268][0];	// L416
    v267[0][v268][0] = v269;	// L417
  }
}

void kernel56(
  float v270[1][64][384],
  float v271[1][64][1]
) {	// L421
  for (int v272 = 0; v272 < 384; v272 += 1) {	// L422
    for (int v273 = 0; v273 < 64; v273 += 1) {	// L423
      float v274 = v270[0][v273][v272];	// L424
      float v275 = v271[0][v273][0];	// L425
      float v276 = v274 + v275;	// L426
      v271[0][v273][0] = v276;	// L427
    }
  }
}

void kernel82(
  float v277[1][64][384],
  float v278[1][384][384],
  float v279[1][64][384]
) {	// L432
  float v280[1][64][384];	// L433
  #pragma HLS resource variable=v280 core=ram_t2p_bram

  memcpy(v280, v277, 24576 * sizeof(float));	// L434

  for (int v281 = 0; v281 < 384; v281 += 1) {	// L435
    for (int v282 = 0; v282 < 64; v282 += 1) {	// L436
      for (int v283 = 0; v283 < 384; v283 += 1) {	// L437
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v280
        #pragma HLS dependence false variable=v278
        #pragma HLS dependence false variable=v279
        float v284 = v280[0][v282][v281];	// L438
        float v285 = v278[0][v281][v283];	// L439
        float v286 = v279[0][v282][v283];	// L440
        float v287 = v284 * v285;	// L441
        float v288 = v286 + v287;	// L442
        v279[0][v282][v283] = v288;	// L443
      }
    }
  }
}

void kernel84(
  float v289[384][384],
  float v290[1][384][384]
) {	// L449
  for (int v291 = 0; v291 < 384; v291 += 1) {	// L450
    for (int v292 = 0; v292 < 384; v292 += 1) {	// L451
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v289
      #pragma HLS dependence false variable=v290
      float v293 = v289[v291][v292];	// L452
      v290[0][v291][v292] = v293;	// L453
    }
  }
}

void kernel98(
  float v294[1][64][12][32],
  float v295[1][64][384]
) {	// L458
  for (int v296 = 0; v296 < 64; v296 += 1) {	// L459
    for (int v297 = 0; v297 < 384; v297 += 1) {	// L460
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v294
      #pragma HLS dependence false variable=v295
      float v298 = v294[0][v296][(v297 / 32)][(v297 % 32)];	// L461
      v295[0][v296][v297] = v298;	// L462
    }
  }
}

void kernel102(
  float v299[12][64][32],
  float v300[1][64][12][32]
) {	// L467
  for (int v301 = 0; v301 < 64; v301 += 1) {	// L468
    for (int v302 = 0; v302 < 12; v302 += 1) {	// L469
      for (int v303 = 0; v303 < 32; v303 += 1) {	// L470
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v299
        #pragma HLS dependence false variable=v300
        float v304 = v299[v302][v301][v303];	// L471
        v300[0][v301][v302][v303] = v304;	// L472
      }
    }
  }
}

void kernel103(
  float v305[1][12][64][64],
  float v306[1][12][64][32],
  float v307[12][64][32]
) {	// L478
  float v308[1][12][64][64];	// L479
  #pragma HLS resource variable=v308 core=ram_t2p_bram

  memcpy(v308, v305, 49152 * sizeof(float));	// L480

  for (int v309 = 0; v309 < 64; v309 += 1) {	// L481
    for (int v310 = 0; v310 < 12; v310 += 1) {	// L482
      for (int v311 = 0; v311 < 64; v311 += 1) {	// L483
        for (int v312 = 0; v312 < 32; v312 += 1) {	// L484
          #pragma HLS pipeline II=1
          #pragma HLS dependence false variable=v308
          #pragma HLS dependence false variable=v306
          #pragma HLS dependence false variable=v307
          float v313 = v308[0][v310][v311][v309];	// L485
          float v314 = v306[0][v310][v309][v312];	// L486
          float v315 = v307[v310][v311][v312];	// L487
          float v316 = v313 * v314;	// L488
          float v317 = v315 + v316;	// L489
          v307[v310][v311][v312] = v317;	// L490
        }
      }
    }
  }
}

void kernel104(
  float v318[1][12][64][32],
  float v319[1][12][64][32]
) {	// L497
  for (int v320 = 0; v320 < 12; v320 += 1) {	// L498
    for (int v321 = 0; v321 < 64; v321 += 1) {	// L499
      for (int v322 = 0; v322 < 32; v322 += 1) {	// L500
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v318
        #pragma HLS dependence false variable=v319
        float v323 = v318[0][v320][v321][v322];	// L501
        v319[0][v320][v321][v322] = v323;	// L502
      }
    }
  }
}

void kernel105(
  float v324[1][12][64][64],
  float v325[1][12][64][64]
) {	// L508
  for (int v326 = 0; v326 < 12; v326 += 1) {	// L509
    for (int v327 = 0; v327 < 64; v327 += 1) {	// L510
      for (int v328 = 0; v328 < 64; v328 += 1) {	// L511
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v324
        #pragma HLS dependence false variable=v325
        float v329 = v324[0][v326][v327][v328];	// L512
        v325[0][v326][v327][v328] = v329;	// L513
      }
    }
  }
}

void kernel106(
  float v330[12][64][64],
  float v331[1],
  float v332[1][12][64][64]
) {	// L519
  float v333[1];	// L520
  memcpy(v333, v331, 1 * sizeof(float));	// L521

  for (int v334 = 0; v334 < 12; v334 += 1) {	// L522
    for (int v335 = 0; v335 < 64; v335 += 1) {	// L523
      for (int v336 = 0; v336 < 64; v336 += 1) {	// L524
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v330
        #pragma HLS dependence false variable=v332
        #pragma HLS dependence false variable=v333
        float v337 = v330[v334][v335][v336];	// L525
        float v338 = v333[0];	// L526
        float v339 = v337 * v338;	// L527
        v332[0][v334][v335][v336] = v339;	// L528
      }
    }
  }
}

void kernel107(
  float v340[1][12][64][32],
  float v341[1][12][32][64],
  float v342[12][64][64]
) {	// L534
  float v343[1][12][64][32];	// L535
  #pragma HLS resource variable=v343 core=ram_t2p_bram

  memcpy(v343, v340, 24576 * sizeof(float));	// L536

  for (int v344 = 0; v344 < 32; v344 += 1) {	// L537
    for (int v345 = 0; v345 < 12; v345 += 1) {	// L538
      for (int v346 = 0; v346 < 64; v346 += 1) {	// L539
        for (int v347 = 0; v347 < 64; v347 += 1) {	// L540
          #pragma HLS pipeline II=1
          #pragma HLS dependence false variable=v343
          #pragma HLS dependence false variable=v341
          #pragma HLS dependence false variable=v342
          float v348 = v343[0][v345][v346][v344];	// L541
          float v349 = v341[0][v345][v344][v347];	// L542
          float v350 = v342[v345][v346][v347];	// L543
          float v351 = v348 * v349;	// L544
          float v352 = v350 + v351;	// L545
          v342[v345][v346][v347] = v352;	// L546
        }
      }
    }
  }
}

void kernel108(
  float v353[1][12][32][64],
  float v354[1][12][32][64]
) {	// L553
  for (int v355 = 0; v355 < 12; v355 += 1) {	// L554
    for (int v356 = 0; v356 < 32; v356 += 1) {	// L555
      for (int v357 = 0; v357 < 64; v357 += 1) {	// L556
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v353
        #pragma HLS dependence false variable=v354
        float v358 = v353[0][v355][v356][v357];	// L557
        v354[0][v355][v356][v357] = v358;	// L558
      }
    }
  }
}

void kernel110(
  float v359[1][64][384],
  float v360[1][12][32][64]
) {	// L564
  for (int v361 = 0; v361 < 12; v361 += 1) {	// L565
    for (int v362 = 0; v362 < 32; v362 += 1) {	// L566
      for (int v363 = 0; v363 < 64; v363 += 1) {	// L567
        float v364 = v359[0][v363][((v361 * 32) + v362)];	// L568
        v360[0][v361][v362][v363] = v364;	// L569
      }
    }
  }
}

void kernel111(
  float v365[1][64][384],
  float v366[1][12][64][32]
) {	// L575
  for (int v367 = 0; v367 < 12; v367 += 1) {	// L576
    for (int v368 = 0; v368 < 64; v368 += 1) {	// L577
      for (int v369 = 0; v369 < 32; v369 += 1) {	// L578
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v365
        #pragma HLS dependence false variable=v366
        float v370 = v365[0][v368][((v367 * 32) + v369)];	// L579
        v366[0][v367][v368][v369] = v370;	// L580
      }
    }
  }
}

void kernel174(
  float v371[384],
  float v372[1][64][384]
) {	// L586
  for (int v373 = 0; v373 < 64; v373 += 1) {	// L587
    for (int v374 = 0; v374 < 384; v374 += 1) {	// L588
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v372
      #pragma HLS dependence false variable=v371
      float v375 = v372[0][v373][v374];	// L589
      float v376 = v371[v374];	// L590
      float v377 = v375 + v376;	// L591
      v372[0][v373][v374] = v377;	// L592
    }
  }
}

void kernel291(
  float v378[12][64][32],
  float v379[12][64][32]
) {	// L597
  for (int v380 = 0; v380 < 12; v380 += 1) {	// L598
    for (int v381 = 0; v381 < 64; v381 += 1) {	// L599
      for (int v382 = 0; v382 < 32; v382 += 1) {	// L600
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v378
        #pragma HLS dependence false variable=v379
        float v383 = v378[v380][v381][v382];	// L601
        v379[v380][v381][v382] = v383;	// L602
      }
    }
  }
}

void kernel296(
  float v384[12][64][64],
  float v385[12][64][64]
) {	// L608
  for (int v386 = 0; v386 < 12; v386 += 1) {	// L609
    for (int v387 = 0; v387 < 64; v387 += 1) {	// L610
      for (int v388 = 0; v388 < 64; v388 += 1) {	// L611
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v384
        #pragma HLS dependence false variable=v385
        float v389 = v384[v386][v387][v388];	// L612
        v385[v386][v387][v388] = v389;	// L613
      }
    }
  }
}

void kernel610(
  float v390[1][64][1536],
  float v391
) {	// L619
  for (int v392 = 0; v392 < 64; v392 += 1) {	// L620
    for (int v393 = 0; v393 < 1536; v393 += 1) {	// L621
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v390
      v390[0][v392][v393] = v391;	// L622
    }
  }
}

void kernel630(
  float v394[1][8][8][384],
  float v395[1][64][384],
  float v396[1][64][384]
) {	// L627
  for (int v397 = 0; v397 < 64; v397 += 1) {	// L628
    for (int v398 = 0; v398 < 384; v398 += 1) {	// L629
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v394
      #pragma HLS dependence false variable=v396
      #pragma HLS dependence false variable=v395
      float v399 = v394[0][(v397 / 8)][(v397 % 8)][v398];	// L630
      float v400 = v395[0][v397][v398];	// L631
      float v401 = v399 + v400;	// L632
      v396[0][v397][v398] = v401;	// L633
    }
  }
}

void kernel671(
  float v402[12][64][32],
  float v403
) {	// L638
  for (int v404 = 0; v404 < 12; v404 += 1) {	// L639
    for (int v405 = 0; v405 < 64; v405 += 1) {	// L640
      for (int v406 = 0; v406 < 32; v406 += 1) {	// L641
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v402
        v402[v404][v405][v406] = v403;	// L642
      }
    }
  }
}

void kernel677(
  float v407[12][64][64],
  float v408
) {	// L648
  for (int v409 = 0; v409 < 12; v409 += 1) {	// L649
    for (int v410 = 0; v410 < 64; v410 += 1) {	// L650
      for (int v411 = 0; v411 < 64; v411 += 1) {	// L651
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v407
        v407[v409][v410][v411] = v408;	// L652
      }
    }
  }
}

void kernel742(
  float v412[1][64][384],
  float v413
) {	// L658
  for (int v414 = 0; v414 < 64; v414 += 1) {	// L659
    for (int v415 = 0; v415 < 384; v415 += 1) {	// L660
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v412
      v412[0][v414][v415] = v413;	// L661
    }
  }
}

void kernel756(
  float v416[1][8][8][384],
  float v417[1][64][384],
  float v418[1][64][384]
) {	// L666
  for (int v419 = 0; v419 < 64; v419 += 1) {	// L667
    for (int v420 = 0; v420 < 384; v420 += 1) {	// L668
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v416
      #pragma HLS dependence false variable=v418
      #pragma HLS dependence false variable=v417
      float v421 = v416[0][(v419 / 8)][(v419 % 8)][v420];	// L669
      float v422 = v417[0][v419][v420];	// L670
      float v423 = v421 - v422;	// L671
      v418[0][v419][v420] = v423;	// L672
    }
  }
}

void kernel759(
  float v424[1][8][8][384],
  float v425[1][64][1]
) {	// L677
  for (int v426 = 0; v426 < 384; v426 += 1) {	// L678
    for (int v427 = 0; v427 < 64; v427 += 1) {	// L679
      float v428 = v424[0][(v427 / 8)][(v427 % 8)][v426];	// L680
      float v429 = v425[0][v427][0];	// L681
      float v430 = v428 + v429;	// L682
      v425[0][v427][0] = v430;	// L683
    }
  }
}

void kernel761(
  float v431[1][64][1],
  float v432
) {	// L688
  for (int v433 = 0; v433 < 64; v433 += 1) {	// L689
    v431[0][v433][0] = v432;	// L690
  }
}

void kernel762(
  float v434[1][384][8][8],
  float v435[1][8][8][384]
) {	// L694
  for (int v436 = 0; v436 < 8; v436 += 1) {	// L695
    for (int v437 = 0; v437 < 8; v437 += 1) {	// L696
      for (int v438 = 0; v438 < 384; v438 += 1) {	// L697
        float v439 = v434[0][v438][v436][v437];	// L698
        v435[0][v436][v437][v438] = v439;	// L699
      }
    }
  }
}

void kernel763(
  float v440[1][384][8][8],
  float v441[1][384][8][8],
  float v442[1][384][8][8]
) {	// L705
  for (int v443 = 0; v443 < 384; v443 += 1) {	// L706
    for (int v444 = 0; v444 < 8; v444 += 1) {	// L707
      for (int v445 = 0; v445 < 8; v445 += 1) {	// L708
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v441
        #pragma HLS dependence false variable=v442
        #pragma HLS dependence false variable=v440
        float v446 = v441[0][v443][v444][v445];	// L709
        float v447 = v440[0][v443][v444][v445];	// L710
        float v448 = v446 + v447;	// L711
        v442[0][v443][v444][v445] = v448;	// L712
      }
    }
  }
}

void kernel764(
  float v449[1][384][8][8],
  float v450[1][384][8][8]
) {	// L718
  for (int v451 = 0; v451 < 384; v451 += 1) {	// L719
    for (int v452 = 0; v452 < 8; v452 += 1) {	// L720
      for (int v453 = 0; v453 < 8; v453 += 1) {	// L721
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v449
        #pragma HLS dependence false variable=v450
        float v454 = v449[0][v451][v452][v453];	// L722
        v450[0][v451][v452][v453] = v454;	// L723
      }
    }
  }
}

void kernel765(
  float v455[1][384][8][8],
  float v456[1][384][8][8]
) {	// L729
  for (int v457 = 0; v457 < 384; v457 += 1) {	// L730
    for (int v458 = 0; v458 < 8; v458 += 1) {	// L731
      for (int v459 = 0; v459 < 8; v459 += 1) {	// L732
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v455
        #pragma HLS dependence false variable=v456
        float v460 = v455[0][v457][v458][v459];	// L733
        float v461 = v456[0][v457][v458][v459];	// L734
        float v462 = v460 + v461;	// L735
        v456[0][v457][v458][v459] = v462;	// L736
      }
    }
  }
}

void kernel766(
  float v463[1][384][8][8],
  float v464
) {	// L742
  for (int v465 = 0; v465 < 384; v465 += 1) {	// L743
    for (int v466 = 0; v466 < 8; v466 += 1) {	// L744
      for (int v467 = 0; v467 < 8; v467 += 1) {	// L745
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v463
        float v468 = v463[0][v465][v466][v467];	// L746
        float v469 = v468 * v464;	// L747
        v463[0][v465][v466][v467] = v469;	// L748
      }
    }
  }
}

void kernel768(
  float v470[1][384][8][8],
  float v471[1][384][8][8],
  float v472[1][384][8][8]
) {	// L754
  for (int v473 = 0; v473 < 384; v473 += 1) {	// L755
    for (int v474 = 0; v474 < 8; v474 += 1) {	// L756
      for (int v475 = 0; v475 < 8; v475 += 1) {	// L757
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v471
        #pragma HLS dependence false variable=v472
        #pragma HLS dependence false variable=v470
        float v476 = v471[0][v473][v474][v475];	// L758
        float v477 = v470[0][v473][v474][v475];	// L759
        float v478 = v476 - v477;	// L760
        v472[0][v473][v474][v475] = v478;	// L761
      }
    }
  }
}

void kernel769(
  float v479[1][384][8][8],
  float v480[1][384][8][8],
  float v481[1][384][8][8]
) {	// L767
  for (int v482 = 0; v482 < 384; v482 += 1) {	// L768
    for (int v483 = 0; v483 < 8; v483 += 1) {	// L769
      for (int v484 = 0; v484 < 8; v484 += 1) {	// L770
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v480
        #pragma HLS dependence false variable=v481
        #pragma HLS dependence false variable=v479
        float v485 = v480[0][v482][v483][v484];	// L771
        float v486 = v479[0][v482][v483][v484];	// L772
        float v487 = v485 * v486;	// L773
        v481[0][v482][v483][v484] = v487;	// L774
      }
    }
  }
}

void kernel770(
  float v488[1][384][8][8],
  float v489,
  float v490
) {	// L780
  for (int v491 = 0; v491 < 384; v491 += 1) {	// L781
    for (int v492 = 0; v492 < 8; v492 += 1) {	// L782
      for (int v493 = 0; v493 < 8; v493 += 1) {	// L783
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v488
        float v494 = v488[0][v491][v492][v493];	// L784
        bool v495 = v494 >= v490;	// L785
        float v496 = v495 ? v489 : v490;	// L786
        v488[0][v491][v492][v493] = v496;	// L787
      }
    }
  }
}

void kernel772(
  float v497[1][384][8][8],
  float v498
) {	// L793
  for (int v499 = 0; v499 < 384; v499 += 1) {	// L794
    for (int v500 = 0; v500 < 8; v500 += 1) {	// L795
      for (int v501 = 0; v501 < 8; v501 += 1) {	// L796
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v497
        float v502 = v497[0][v499][v500][v501];	// L797
        float v503 = v502 - v498;	// L798
        v497[0][v499][v500][v501] = v503;	// L799
      }
    }
  }
}

void kernel775(
  float v504[1][384][8][8],
  float v505
) {	// L805
  for (int v506 = 0; v506 < 384; v506 += 1) {	// L806
    for (int v507 = 0; v507 < 8; v507 += 1) {	// L807
      for (int v508 = 0; v508 < 8; v508 += 1) {	// L808
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v504
        float v509 = v504[0][v506][v507][v508];	// L809
        float v510 = v509 / v505;	// L810
        v504[0][v506][v507][v508] = v510;	// L811
      }
    }
  }
}

void kernel780(
  float v511[1][384][10][10],
  float v512[384][384][3][3],
  float v513[1][384][8][8]
) {	// L817
  float v514[384][384][3][3];	// L818
  #pragma HLS resource variable=v514 core=ram_t2p_bram

  memcpy(v514, v512, 1327104 * sizeof(float));	// L819

  for (int v515 = 0; v515 < 384; v515 += 1) {	// L820
    for (int v516 = 0; v516 < 3; v516 += 1) {	// L821
      for (int v517 = 0; v517 < 3; v517 += 1) {	// L822
        for (int v518 = 0; v518 < 384; v518 += 1) {	// L823
          for (int v519 = 0; v519 < 8; v519 += 1) {	// L824
            for (int v520 = 0; v520 < 8; v520 += 1) {	// L825
              #pragma HLS pipeline II=1
              #pragma HLS dependence false variable=v511
              #pragma HLS dependence false variable=v513
              #pragma HLS dependence false variable=v514
              float v521 = v511[0][v515][(v519 + v516)][(v520 + v517)];	// L826
              float v522 = v514[v518][v515][v516][v517];	// L827
              float v523 = v513[0][v518][v519][v520];	// L828
              float v524 = v521 * v522;	// L829
              float v525 = v523 + v524;	// L830
              v513[0][v518][v519][v520] = v525;	// L831
            }
          }
        }
      }
    }
  }
}

void kernel781(
  float v526[384],
  float v527[1][384][8][8]
) {	// L840
  float v528[384];	// L841
  #pragma HLS resource variable=v528 core=ram_t2p_bram

  memcpy(v528, v526, 384 * sizeof(float));	// L842

  for (int v529 = 0; v529 < 384; v529 += 1) {	// L843
    for (int v530 = 0; v530 < 8; v530 += 1) {	// L844
      for (int v531 = 0; v531 < 8; v531 += 1) {	// L845
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v528
        #pragma HLS dependence false variable=v527
        float v532 = v528[v529];	// L846
        v527[0][v529][v530][v531] = v532;	// L847
      }
    }
  }
}

void kernel782(
  float v533[1][384][8][8],
  float v534[1][384][10][10]
) {	// L853
  for (int v535 = 0; v535 < 384; v535 += 1) {	// L854
    for (int v536 = 0; v536 < 8; v536 += 1) {	// L855
      for (int v537 = 0; v537 < 8; v537 += 1) {	// L856
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v533
        #pragma HLS dependence false variable=v534
        float v538 = v533[0][v535][v536][v537];	// L857
        v534[0][v535][(v536 + 1)][(v537 + 1)] = v538;	// L858
      }
    }
  }
}

void kernel783(
  float v539[1][384][10][10],
  float v540
) {	// L864
  for (int v541 = 0; v541 < 384; v541 += 1) {	// L865
    for (int v542 = 0; v542 < 10; v542 += 1) {	// L866
      for (int v543 = 0; v543 < 10; v543 += 1) {	// L867
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v539
        v539[0][v541][v542][v543] = v540;	// L868
      }
    }
  }
}

void kernel784(
  float v544[1][384][18][18],
  float v545[3][3],
  float v546[1][384][8][8]
) {	// L874
  for (int v547 = 0; v547 < 3; v547 += 1) {	// L875
    for (int v548 = 0; v548 < 3; v548 += 1) {	// L876
      for (int v549 = 0; v549 < 384; v549 += 1) {	// L877
        for (int v550 = 0; v550 < 8; v550 += 1) {	// L878
          for (int v551 = 0; v551 < 8; v551 += 1) {	// L879
            #pragma HLS pipeline II=1
            #pragma HLS dependence false variable=v544
            #pragma HLS dependence false variable=v546
            float v552 = v544[0][v549][((v550 * 2) + v547)][((v551 * 2) + v548)];	// L880
            float v553 = v546[0][v549][v550][v551];	// L881
            float v554 = max(v553, v552);	// L882
            v546[0][v549][v550][v551] = v554;	// L883
          }
        }
      }
    }
  }
}

void kernel785(
  float v555[1][384][8][8],
  float v556
) {	// L891
  for (int v557 = 0; v557 < 384; v557 += 1) {	// L892
    for (int v558 = 0; v558 < 8; v558 += 1) {	// L893
      for (int v559 = 0; v559 < 8; v559 += 1) {	// L894
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v555
        v555[0][v557][v558][v559] = v556;	// L895
      }
    }
  }
}

void kernel786(
  float v560[1][384][16][16],
  float v561[1][384][18][18]
) {	// L901
  for (int v562 = 0; v562 < 384; v562 += 1) {	// L902
    for (int v563 = 0; v563 < 16; v563 += 1) {	// L903
      for (int v564 = 0; v564 < 16; v564 += 1) {	// L904
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v560
        #pragma HLS dependence false variable=v561
        float v565 = v560[0][v562][v563][v564];	// L905
        v561[0][v562][(v563 + 1)][(v564 + 1)] = v565;	// L906
      }
    }
  }
}

void kernel787(
  float v566[1][384][18][18],
  float v567
) {	// L912
  for (int v568 = 0; v568 < 384; v568 += 1) {	// L913
    for (int v569 = 0; v569 < 18; v569 += 1) {	// L914
      for (int v570 = 0; v570 < 18; v570 += 1) {	// L915
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v566
        v566[0][v568][v569][v570] = v567;	// L916
      }
    }
  }
}

void kernel788(
  float v571[1][384][16][16],
  float v572[1][384][16][16]
) {	// L922
  for (int v573 = 0; v573 < 384; v573 += 1) {	// L923
    for (int v574 = 0; v574 < 16; v574 += 1) {	// L924
      for (int v575 = 0; v575 < 16; v575 += 1) {	// L925
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v571
        #pragma HLS dependence false variable=v572
        float v576 = v571[0][v573][v574][v575];	// L926
        v572[0][v573][v574][v575] = v576;	// L927
      }
    }
  }
}

void kernel789(
  float v577[1][384][16][16],
  float v578[1][384][16][16]
) {	// L933
  for (int v579 = 0; v579 < 384; v579 += 1) {	// L934
    for (int v580 = 0; v580 < 16; v580 += 1) {	// L935
      for (int v581 = 0; v581 < 16; v581 += 1) {	// L936
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v577
        #pragma HLS dependence false variable=v578
        float v582 = v577[0][v579][v580][v581];	// L937
        float v583 = v578[0][v579][v580][v581];	// L938
        float v584 = v582 + v583;	// L939
        v578[0][v579][v580][v581] = v584;	// L940
      }
    }
  }
}

void kernel790(
  float v585[1][384][16][16],
  float v586
) {	// L946
  for (int v587 = 0; v587 < 384; v587 += 1) {	// L947
    for (int v588 = 0; v588 < 16; v588 += 1) {	// L948
      for (int v589 = 0; v589 < 16; v589 += 1) {	// L949
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v585
        float v590 = v585[0][v587][v588][v589];	// L950
        float v591 = v590 * v586;	// L951
        v585[0][v587][v588][v589] = v591;	// L952
      }
    }
  }
}

void kernel792(
  float v592[1][384][16][16],
  float v593[1][384][16][16],
  float v594[1][384][16][16]
) {	// L958
  for (int v595 = 0; v595 < 384; v595 += 1) {	// L959
    for (int v596 = 0; v596 < 16; v596 += 1) {	// L960
      for (int v597 = 0; v597 < 16; v597 += 1) {	// L961
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v593
        #pragma HLS dependence false variable=v594
        #pragma HLS dependence false variable=v592
        float v598 = v593[0][v595][v596][v597];	// L962
        float v599 = v592[0][v595][v596][v597];	// L963
        float v600 = v598 - v599;	// L964
        v594[0][v595][v596][v597] = v600;	// L965
      }
    }
  }
}

void kernel793(
  float v601[1][384][16][16],
  float v602[1][384][16][16],
  float v603[1][384][16][16]
) {	// L971
  for (int v604 = 0; v604 < 384; v604 += 1) {	// L972
    for (int v605 = 0; v605 < 16; v605 += 1) {	// L973
      for (int v606 = 0; v606 < 16; v606 += 1) {	// L974
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v602
        #pragma HLS dependence false variable=v603
        #pragma HLS dependence false variable=v601
        float v607 = v602[0][v604][v605][v606];	// L975
        float v608 = v601[0][v604][v605][v606];	// L976
        float v609 = v607 * v608;	// L977
        v603[0][v604][v605][v606] = v609;	// L978
      }
    }
  }
}

void kernel794(
  float v610[1][384][16][16],
  float v611,
  float v612
) {	// L984
  for (int v613 = 0; v613 < 384; v613 += 1) {	// L985
    for (int v614 = 0; v614 < 16; v614 += 1) {	// L986
      for (int v615 = 0; v615 < 16; v615 += 1) {	// L987
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v610
        float v616 = v610[0][v613][v614][v615];	// L988
        bool v617 = v616 >= v612;	// L989
        float v618 = v617 ? v611 : v612;	// L990
        v610[0][v613][v614][v615] = v618;	// L991
      }
    }
  }
}

void kernel796(
  float v619[1][384][16][16],
  float v620
) {	// L997
  for (int v621 = 0; v621 < 384; v621 += 1) {	// L998
    for (int v622 = 0; v622 < 16; v622 += 1) {	// L999
      for (int v623 = 0; v623 < 16; v623 += 1) {	// L1000
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v619
        float v624 = v619[0][v621][v622][v623];	// L1001
        float v625 = v624 - v620;	// L1002
        v619[0][v621][v622][v623] = v625;	// L1003
      }
    }
  }
}

void kernel798(
  float v626[1][384][16][16],
  float v627[1][384][16][16],
  float v628[1][384][16][16]
) {	// L1009
  for (int v629 = 0; v629 < 384; v629 += 1) {	// L1010
    for (int v630 = 0; v630 < 16; v630 += 1) {	// L1011
      for (int v631 = 0; v631 < 16; v631 += 1) {	// L1012
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v627
        #pragma HLS dependence false variable=v628
        #pragma HLS dependence false variable=v626
        float v632 = v627[0][v629][v630][v631];	// L1013
        float v633 = v626[0][v629][v630][v631];	// L1014
        float v634 = v632 + v633;	// L1015
        v628[0][v629][v630][v631] = v634;	// L1016
      }
    }
  }
}

void kernel799(
  float v635[1][384][16][16],
  float v636
) {	// L1022
  for (int v637 = 0; v637 < 384; v637 += 1) {	// L1023
    for (int v638 = 0; v638 < 16; v638 += 1) {	// L1024
      for (int v639 = 0; v639 < 16; v639 += 1) {	// L1025
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v635
        float v640 = v635[0][v637][v638][v639];	// L1026
        float v641 = v640 / v636;	// L1027
        v635[0][v637][v638][v639] = v641;	// L1028
      }
    }
  }
}

void kernel804(
  float v642[1][192][18][18],
  float v643[384][192][3][3],
  float v644[1][384][16][16]
) {	// L1034
  float v645[384][192][3][3];	// L1035
  #pragma HLS resource variable=v645 core=ram_t2p_bram

  memcpy(v645, v643, 663552 * sizeof(float));	// L1036

  for (int v646 = 0; v646 < 192; v646 += 1) {	// L1037
    for (int v647 = 0; v647 < 3; v647 += 1) {	// L1038
      for (int v648 = 0; v648 < 3; v648 += 1) {	// L1039
        for (int v649 = 0; v649 < 384; v649 += 1) {	// L1040
          for (int v650 = 0; v650 < 16; v650 += 1) {	// L1041
            for (int v651 = 0; v651 < 16; v651 += 1) {	// L1042
              #pragma HLS pipeline II=1
              #pragma HLS dependence false variable=v642
              #pragma HLS dependence false variable=v644
              #pragma HLS dependence false variable=v645
              float v652 = v642[0][v646][(v650 + v647)][(v651 + v648)];	// L1043
              float v653 = v645[v649][v646][v647][v648];	// L1044
              float v654 = v644[0][v649][v650][v651];	// L1045
              float v655 = v652 * v653;	// L1046
              float v656 = v654 + v655;	// L1047
              v644[0][v649][v650][v651] = v656;	// L1048
            }
          }
        }
      }
    }
  }
}

void kernel805(
  float v657[384],
  float v658[1][384][16][16]
) {	// L1057
  float v659[384];	// L1058
  #pragma HLS resource variable=v659 core=ram_t2p_bram

  memcpy(v659, v657, 384 * sizeof(float));	// L1059

  for (int v660 = 0; v660 < 384; v660 += 1) {	// L1060
    for (int v661 = 0; v661 < 16; v661 += 1) {	// L1061
      for (int v662 = 0; v662 < 16; v662 += 1) {	// L1062
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v659
        #pragma HLS dependence false variable=v658
        float v663 = v659[v660];	// L1063
        v658[0][v660][v661][v662] = v663;	// L1064
      }
    }
  }
}

void kernel806(
  float v664[1][192][16][16],
  float v665[1][192][18][18]
) {	// L1070
  for (int v666 = 0; v666 < 192; v666 += 1) {	// L1071
    for (int v667 = 0; v667 < 16; v667 += 1) {	// L1072
      for (int v668 = 0; v668 < 16; v668 += 1) {	// L1073
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v664
        #pragma HLS dependence false variable=v665
        float v669 = v664[0][v666][v667][v668];	// L1074
        v665[0][v666][(v667 + 1)][(v668 + 1)] = v669;	// L1075
      }
    }
  }
}

void kernel807(
  float v670[1][192][18][18],
  float v671
) {	// L1081
  for (int v672 = 0; v672 < 192; v672 += 1) {	// L1082
    for (int v673 = 0; v673 < 18; v673 += 1) {	// L1083
      for (int v674 = 0; v674 < 18; v674 += 1) {	// L1084
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v670
        v670[0][v672][v673][v674] = v671;	// L1085
      }
    }
  }
}

void kernel808(
  float v675[1][192][34][34],
  float v676[3][3],
  float v677[1][192][16][16]
) {	// L1091
  for (int v678 = 0; v678 < 3; v678 += 1) {	// L1092
    for (int v679 = 0; v679 < 3; v679 += 1) {	// L1093
      for (int v680 = 0; v680 < 192; v680 += 1) {	// L1094
        for (int v681 = 0; v681 < 16; v681 += 1) {	// L1095
          for (int v682 = 0; v682 < 16; v682 += 1) {	// L1096
            #pragma HLS pipeline II=1
            #pragma HLS dependence false variable=v675
            #pragma HLS dependence false variable=v677
            float v683 = v675[0][v680][((v681 * 2) + v678)][((v682 * 2) + v679)];	// L1097
            float v684 = v677[0][v680][v681][v682];	// L1098
            float v685 = max(v684, v683);	// L1099
            v677[0][v680][v681][v682] = v685;	// L1100
          }
        }
      }
    }
  }
}

void kernel809(
  float v686[1][192][16][16],
  float v687
) {	// L1108
  for (int v688 = 0; v688 < 192; v688 += 1) {	// L1109
    for (int v689 = 0; v689 < 16; v689 += 1) {	// L1110
      for (int v690 = 0; v690 < 16; v690 += 1) {	// L1111
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v686
        v686[0][v688][v689][v690] = v687;	// L1112
      }
    }
  }
}

void kernel810(
  float v691[1][192][32][32],
  float v692[1][192][34][34]
) {	// L1118
  for (int v693 = 0; v693 < 192; v693 += 1) {	// L1119
    for (int v694 = 0; v694 < 32; v694 += 1) {	// L1120
      for (int v695 = 0; v695 < 32; v695 += 1) {	// L1121
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v691
        #pragma HLS dependence false variable=v692
        float v696 = v691[0][v693][v694][v695];	// L1122
        v692[0][v693][(v694 + 1)][(v695 + 1)] = v696;	// L1123
      }
    }
  }
}

void kernel811(
  float v697[1][192][34][34],
  float v698
) {	// L1129
  for (int v699 = 0; v699 < 192; v699 += 1) {	// L1130
    for (int v700 = 0; v700 < 34; v700 += 1) {	// L1131
      for (int v701 = 0; v701 < 34; v701 += 1) {	// L1132
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v697
        v697[0][v699][v700][v701] = v698;	// L1133
      }
    }
  }
}

void kernel812(
  float v702[1][192][32][32],
  float v703[1][192][32][32]
) {	// L1139
  for (int v704 = 0; v704 < 192; v704 += 1) {	// L1140
    for (int v705 = 0; v705 < 32; v705 += 1) {	// L1141
      for (int v706 = 0; v706 < 32; v706 += 1) {	// L1142
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v702
        #pragma HLS dependence false variable=v703
        float v707 = v702[0][v704][v705][v706];	// L1143
        v703[0][v704][v705][v706] = v707;	// L1144
      }
    }
  }
}

void kernel813(
  float v708[1][192][32][32],
  float v709[1][192][32][32]
) {	// L1150
  for (int v710 = 0; v710 < 192; v710 += 1) {	// L1151
    for (int v711 = 0; v711 < 32; v711 += 1) {	// L1152
      for (int v712 = 0; v712 < 32; v712 += 1) {	// L1153
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v708
        #pragma HLS dependence false variable=v709
        float v713 = v708[0][v710][v711][v712];	// L1154
        float v714 = v709[0][v710][v711][v712];	// L1155
        float v715 = v713 + v714;	// L1156
        v709[0][v710][v711][v712] = v715;	// L1157
      }
    }
  }
}

void kernel814(
  float v716[1][192][32][32],
  float v717
) {	// L1163
  for (int v718 = 0; v718 < 192; v718 += 1) {	// L1164
    for (int v719 = 0; v719 < 32; v719 += 1) {	// L1165
      for (int v720 = 0; v720 < 32; v720 += 1) {	// L1166
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v716
        float v721 = v716[0][v718][v719][v720];	// L1167
        float v722 = v721 * v717;	// L1168
        v716[0][v718][v719][v720] = v722;	// L1169
      }
    }
  }
}

void kernel816(
  float v723[1][192][32][32],
  float v724[1][192][32][32],
  float v725[1][192][32][32]
) {	// L1175
  for (int v726 = 0; v726 < 192; v726 += 1) {	// L1176
    for (int v727 = 0; v727 < 32; v727 += 1) {	// L1177
      for (int v728 = 0; v728 < 32; v728 += 1) {	// L1178
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v724
        #pragma HLS dependence false variable=v725
        #pragma HLS dependence false variable=v723
        float v729 = v724[0][v726][v727][v728];	// L1179
        float v730 = v723[0][v726][v727][v728];	// L1180
        float v731 = v729 - v730;	// L1181
        v725[0][v726][v727][v728] = v731;	// L1182
      }
    }
  }
}

void kernel817(
  float v732[1][192][32][32],
  float v733[1][192][32][32],
  float v734[1][192][32][32]
) {	// L1188
  for (int v735 = 0; v735 < 192; v735 += 1) {	// L1189
    for (int v736 = 0; v736 < 32; v736 += 1) {	// L1190
      for (int v737 = 0; v737 < 32; v737 += 1) {	// L1191
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v733
        #pragma HLS dependence false variable=v734
        #pragma HLS dependence false variable=v732
        float v738 = v733[0][v735][v736][v737];	// L1192
        float v739 = v732[0][v735][v736][v737];	// L1193
        float v740 = v738 * v739;	// L1194
        v734[0][v735][v736][v737] = v740;	// L1195
      }
    }
  }
}

void kernel818(
  float v741[1][192][32][32],
  float v742,
  float v743
) {	// L1201
  for (int v744 = 0; v744 < 192; v744 += 1) {	// L1202
    for (int v745 = 0; v745 < 32; v745 += 1) {	// L1203
      for (int v746 = 0; v746 < 32; v746 += 1) {	// L1204
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v741
        float v747 = v741[0][v744][v745][v746];	// L1205
        bool v748 = v747 >= v743;	// L1206
        float v749 = v748 ? v742 : v743;	// L1207
        v741[0][v744][v745][v746] = v749;	// L1208
      }
    }
  }
}

void kernel820(
  float v750[1][192][32][32],
  float v751
) {	// L1214
  for (int v752 = 0; v752 < 192; v752 += 1) {	// L1215
    for (int v753 = 0; v753 < 32; v753 += 1) {	// L1216
      for (int v754 = 0; v754 < 32; v754 += 1) {	// L1217
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v750
        float v755 = v750[0][v752][v753][v754];	// L1218
        float v756 = v755 - v751;	// L1219
        v750[0][v752][v753][v754] = v756;	// L1220
      }
    }
  }
}

void kernel822(
  float v757[1][192][32][32],
  float v758[1][192][32][32],
  float v759[1][192][32][32]
) {	// L1226
  for (int v760 = 0; v760 < 192; v760 += 1) {	// L1227
    for (int v761 = 0; v761 < 32; v761 += 1) {	// L1228
      for (int v762 = 0; v762 < 32; v762 += 1) {	// L1229
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v758
        #pragma HLS dependence false variable=v759
        #pragma HLS dependence false variable=v757
        float v763 = v758[0][v760][v761][v762];	// L1230
        float v764 = v757[0][v760][v761][v762];	// L1231
        float v765 = v763 + v764;	// L1232
        v759[0][v760][v761][v762] = v765;	// L1233
      }
    }
  }
}

void kernel823(
  float v766[1][192][32][32],
  float v767
) {	// L1239
  for (int v768 = 0; v768 < 192; v768 += 1) {	// L1240
    for (int v769 = 0; v769 < 32; v769 += 1) {	// L1241
      for (int v770 = 0; v770 < 32; v770 += 1) {	// L1242
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v766
        float v771 = v766[0][v768][v769][v770];	// L1243
        float v772 = v771 / v767;	// L1244
        v766[0][v768][v769][v770] = v772;	// L1245
      }
    }
  }
}

void kernel828(
  float v773[1][96][34][34],
  float v774[192][96][3][3],
  float v775[1][192][32][32]
) {	// L1251
  float v776[192][96][3][3];	// L1252
  #pragma HLS resource variable=v776 core=ram_t2p_bram

  memcpy(v776, v774, 165888 * sizeof(float));	// L1253

  for (int v777 = 0; v777 < 96; v777 += 1) {	// L1254
    for (int v778 = 0; v778 < 3; v778 += 1) {	// L1255
      for (int v779 = 0; v779 < 3; v779 += 1) {	// L1256
        for (int v780 = 0; v780 < 192; v780 += 1) {	// L1257
          for (int v781 = 0; v781 < 32; v781 += 1) {	// L1258
            for (int v782 = 0; v782 < 32; v782 += 1) {	// L1259
              #pragma HLS pipeline II=1
              #pragma HLS dependence false variable=v773
              #pragma HLS dependence false variable=v775
              #pragma HLS dependence false variable=v776
              float v783 = v773[0][v777][(v781 + v778)][(v782 + v779)];	// L1260
              float v784 = v776[v780][v777][v778][v779];	// L1261
              float v785 = v775[0][v780][v781][v782];	// L1262
              float v786 = v783 * v784;	// L1263
              float v787 = v785 + v786;	// L1264
              v775[0][v780][v781][v782] = v787;	// L1265
            }
          }
        }
      }
    }
  }
}

void kernel829(
  float v788[192],
  float v789[1][192][32][32]
) {	// L1274
  float v790[192];	// L1275
  #pragma HLS resource variable=v790 core=ram_t2p_bram

  memcpy(v790, v788, 192 * sizeof(float));	// L1276

  for (int v791 = 0; v791 < 192; v791 += 1) {	// L1277
    for (int v792 = 0; v792 < 32; v792 += 1) {	// L1278
      for (int v793 = 0; v793 < 32; v793 += 1) {	// L1279
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v790
        #pragma HLS dependence false variable=v789
        float v794 = v790[v791];	// L1280
        v789[0][v791][v792][v793] = v794;	// L1281
      }
    }
  }
}

void kernel830(
  float v795[1][96][32][32],
  float v796[1][96][34][34]
) {	// L1287
  for (int v797 = 0; v797 < 96; v797 += 1) {	// L1288
    for (int v798 = 0; v798 < 32; v798 += 1) {	// L1289
      for (int v799 = 0; v799 < 32; v799 += 1) {	// L1290
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v795
        #pragma HLS dependence false variable=v796
        float v800 = v795[0][v797][v798][v799];	// L1291
        v796[0][v797][(v798 + 1)][(v799 + 1)] = v800;	// L1292
      }
    }
  }
}

void kernel831(
  float v801[1][96][34][34],
  float v802
) {	// L1298
  for (int v803 = 0; v803 < 96; v803 += 1) {	// L1299
    for (int v804 = 0; v804 < 34; v804 += 1) {	// L1300
      for (int v805 = 0; v805 < 34; v805 += 1) {	// L1301
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v801
        v801[0][v803][v804][v805] = v802;	// L1302
      }
    }
  }
}

void kernel832(
  float v806[1][96][32][32],
  float v807[1][96][32][32]
) {	// L1308
  for (int v808 = 0; v808 < 96; v808 += 1) {	// L1309
    for (int v809 = 0; v809 < 32; v809 += 1) {	// L1310
      for (int v810 = 0; v810 < 32; v810 += 1) {	// L1311
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v806
        #pragma HLS dependence false variable=v807
        float v811 = v806[0][v808][v809][v810];	// L1312
        v807[0][v808][v809][v810] = v811;	// L1313
      }
    }
  }
}

void kernel833(
  float v812[1][96][32][32],
  float v813[1][96][32][32]
) {	// L1319
  for (int v814 = 0; v814 < 96; v814 += 1) {	// L1320
    for (int v815 = 0; v815 < 32; v815 += 1) {	// L1321
      for (int v816 = 0; v816 < 32; v816 += 1) {	// L1322
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v812
        #pragma HLS dependence false variable=v813
        float v817 = v812[0][v814][v815][v816];	// L1323
        float v818 = v813[0][v814][v815][v816];	// L1324
        float v819 = v817 + v818;	// L1325
        v813[0][v814][v815][v816] = v819;	// L1326
      }
    }
  }
}

void kernel834(
  float v820[1][96][32][32],
  float v821
) {	// L1332
  for (int v822 = 0; v822 < 96; v822 += 1) {	// L1333
    for (int v823 = 0; v823 < 32; v823 += 1) {	// L1334
      for (int v824 = 0; v824 < 32; v824 += 1) {	// L1335
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v820
        float v825 = v820[0][v822][v823][v824];	// L1336
        float v826 = v825 * v821;	// L1337
        v820[0][v822][v823][v824] = v826;	// L1338
      }
    }
  }
}

void kernel836(
  float v827[1][96][32][32],
  float v828[1][96][32][32],
  float v829[1][96][32][32]
) {	// L1344
  for (int v830 = 0; v830 < 96; v830 += 1) {	// L1345
    for (int v831 = 0; v831 < 32; v831 += 1) {	// L1346
      for (int v832 = 0; v832 < 32; v832 += 1) {	// L1347
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v828
        #pragma HLS dependence false variable=v829
        #pragma HLS dependence false variable=v827
        float v833 = v828[0][v830][v831][v832];	// L1348
        float v834 = v827[0][v830][v831][v832];	// L1349
        float v835 = v833 - v834;	// L1350
        v829[0][v830][v831][v832] = v835;	// L1351
      }
    }
  }
}

void kernel837(
  float v836[1][96][32][32],
  float v837[1][96][32][32],
  float v838[1][96][32][32]
) {	// L1357
  for (int v839 = 0; v839 < 96; v839 += 1) {	// L1358
    for (int v840 = 0; v840 < 32; v840 += 1) {	// L1359
      for (int v841 = 0; v841 < 32; v841 += 1) {	// L1360
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v837
        #pragma HLS dependence false variable=v838
        #pragma HLS dependence false variable=v836
        float v842 = v837[0][v839][v840][v841];	// L1361
        float v843 = v836[0][v839][v840][v841];	// L1362
        float v844 = v842 * v843;	// L1363
        v838[0][v839][v840][v841] = v844;	// L1364
      }
    }
  }
}

void kernel838(
  float v845[1][96][32][32],
  float v846,
  float v847
) {	// L1370
  for (int v848 = 0; v848 < 96; v848 += 1) {	// L1371
    for (int v849 = 0; v849 < 32; v849 += 1) {	// L1372
      for (int v850 = 0; v850 < 32; v850 += 1) {	// L1373
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v845
        float v851 = v845[0][v848][v849][v850];	// L1374
        bool v852 = v851 >= v847;	// L1375
        float v853 = v852 ? v846 : v847;	// L1376
        v845[0][v848][v849][v850] = v853;	// L1377
      }
    }
  }
}

void kernel840(
  float v854[1][96][32][32],
  float v855
) {	// L1383
  for (int v856 = 0; v856 < 96; v856 += 1) {	// L1384
    for (int v857 = 0; v857 < 32; v857 += 1) {	// L1385
      for (int v858 = 0; v858 < 32; v858 += 1) {	// L1386
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v854
        float v859 = v854[0][v856][v857][v858];	// L1387
        float v860 = v859 - v855;	// L1388
        v854[0][v856][v857][v858] = v860;	// L1389
      }
    }
  }
}

void kernel842(
  float v861[1][96][32][32],
  float v862[1][96][32][32],
  float v863[1][96][32][32]
) {	// L1395
  for (int v864 = 0; v864 < 96; v864 += 1) {	// L1396
    for (int v865 = 0; v865 < 32; v865 += 1) {	// L1397
      for (int v866 = 0; v866 < 32; v866 += 1) {	// L1398
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v862
        #pragma HLS dependence false variable=v863
        #pragma HLS dependence false variable=v861
        float v867 = v862[0][v864][v865][v866];	// L1399
        float v868 = v861[0][v864][v865][v866];	// L1400
        float v869 = v867 + v868;	// L1401
        v863[0][v864][v865][v866] = v869;	// L1402
      }
    }
  }
}

void kernel843(
  float v870[1][96][32][32],
  float v871
) {	// L1408
  for (int v872 = 0; v872 < 96; v872 += 1) {	// L1409
    for (int v873 = 0; v873 < 32; v873 += 1) {	// L1410
      for (int v874 = 0; v874 < 32; v874 += 1) {	// L1411
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v870
        float v875 = v870[0][v872][v873][v874];	// L1412
        float v876 = v875 / v871;	// L1413
        v870[0][v872][v873][v874] = v876;	// L1414
      }
    }
  }
}

void kernel848(
  float v877[1][48][34][34],
  float v878[96][48][3][3],
  float v879[1][96][32][32]
) {	// L1420
  float v880[96][48][3][3];	// L1421
  #pragma HLS resource variable=v880 core=ram_t2p_bram

  memcpy(v880, v878, 41472 * sizeof(float));	// L1422

  for (int v881 = 0; v881 < 48; v881 += 1) {	// L1423
    for (int v882 = 0; v882 < 3; v882 += 1) {	// L1424
      for (int v883 = 0; v883 < 3; v883 += 1) {	// L1425
        for (int v884 = 0; v884 < 96; v884 += 1) {	// L1426
          for (int v885 = 0; v885 < 32; v885 += 1) {	// L1427
            for (int v886 = 0; v886 < 32; v886 += 1) {	// L1428
              #pragma HLS pipeline II=1
              #pragma HLS dependence false variable=v877
              #pragma HLS dependence false variable=v879
              #pragma HLS dependence false variable=v880
              float v887 = v877[0][v881][(v885 + v882)][(v886 + v883)];	// L1429
              float v888 = v880[v884][v881][v882][v883];	// L1430
              float v889 = v879[0][v884][v885][v886];	// L1431
              float v890 = v887 * v888;	// L1432
              float v891 = v889 + v890;	// L1433
              v879[0][v884][v885][v886] = v891;	// L1434
            }
          }
        }
      }
    }
  }
}

void kernel849(
  float v892[96],
  float v893[1][96][32][32]
) {	// L1443
  float v894[96];	// L1444
  #pragma HLS resource variable=v894 core=ram_t2p_bram

  memcpy(v894, v892, 96 * sizeof(float));	// L1445

  for (int v895 = 0; v895 < 96; v895 += 1) {	// L1446
    for (int v896 = 0; v896 < 32; v896 += 1) {	// L1447
      for (int v897 = 0; v897 < 32; v897 += 1) {	// L1448
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v894
        #pragma HLS dependence false variable=v893
        float v898 = v894[v895];	// L1449
        v893[0][v895][v896][v897] = v898;	// L1450
      }
    }
  }
}

void kernel850(
  float v899[1][48][32][32],
  float v900[1][48][34][34]
) {	// L1456
  for (int v901 = 0; v901 < 48; v901 += 1) {	// L1457
    for (int v902 = 0; v902 < 32; v902 += 1) {	// L1458
      for (int v903 = 0; v903 < 32; v903 += 1) {	// L1459
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v899
        #pragma HLS dependence false variable=v900
        float v904 = v899[0][v901][v902][v903];	// L1460
        v900[0][v901][(v902 + 1)][(v903 + 1)] = v904;	// L1461
      }
    }
  }
}

void kernel851(
  float v905[1][48][34][34],
  float v906
) {	// L1467
  for (int v907 = 0; v907 < 48; v907 += 1) {	// L1468
    for (int v908 = 0; v908 < 34; v908 += 1) {	// L1469
      for (int v909 = 0; v909 < 34; v909 += 1) {	// L1470
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v905
        v905[0][v907][v908][v909] = v906;	// L1471
      }
    }
  }
}

void kernel852(
  float v910[1][48][32][32],
  float v911[1][48][32][32]
) {	// L1477
  for (int v912 = 0; v912 < 48; v912 += 1) {	// L1478
    for (int v913 = 0; v913 < 32; v913 += 1) {	// L1479
      for (int v914 = 0; v914 < 32; v914 += 1) {	// L1480
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v910
        #pragma HLS dependence false variable=v911
        float v915 = v910[0][v912][v913][v914];	// L1481
        v911[0][v912][v913][v914] = v915;	// L1482
      }
    }
  }
}

void kernel853(
  float v916[1][48][32][32],
  float v917[1][48][32][32]
) {	// L1488
  for (int v918 = 0; v918 < 48; v918 += 1) {	// L1489
    for (int v919 = 0; v919 < 32; v919 += 1) {	// L1490
      for (int v920 = 0; v920 < 32; v920 += 1) {	// L1491
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v916
        #pragma HLS dependence false variable=v917
        float v921 = v916[0][v918][v919][v920];	// L1492
        float v922 = v917[0][v918][v919][v920];	// L1493
        float v923 = v921 + v922;	// L1494
        v917[0][v918][v919][v920] = v923;	// L1495
      }
    }
  }
}

void kernel854(
  float v924[1][48][32][32],
  float v925
) {	// L1501
  for (int v926 = 0; v926 < 48; v926 += 1) {	// L1502
    for (int v927 = 0; v927 < 32; v927 += 1) {	// L1503
      for (int v928 = 0; v928 < 32; v928 += 1) {	// L1504
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v924
        float v929 = v924[0][v926][v927][v928];	// L1505
        float v930 = v929 * v925;	// L1506
        v924[0][v926][v927][v928] = v930;	// L1507
      }
    }
  }
}

void kernel856(
  float v931[1][48][32][32],
  float v932[1][48][32][32],
  float v933[1][48][32][32]
) {	// L1513
  for (int v934 = 0; v934 < 48; v934 += 1) {	// L1514
    for (int v935 = 0; v935 < 32; v935 += 1) {	// L1515
      for (int v936 = 0; v936 < 32; v936 += 1) {	// L1516
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v932
        #pragma HLS dependence false variable=v933
        #pragma HLS dependence false variable=v931
        float v937 = v932[0][v934][v935][v936];	// L1517
        float v938 = v931[0][v934][v935][v936];	// L1518
        float v939 = v937 - v938;	// L1519
        v933[0][v934][v935][v936] = v939;	// L1520
      }
    }
  }
}

void kernel857(
  float v940[1][48][32][32],
  float v941[1][48][32][32],
  float v942[1][48][32][32]
) {	// L1526
  for (int v943 = 0; v943 < 48; v943 += 1) {	// L1527
    for (int v944 = 0; v944 < 32; v944 += 1) {	// L1528
      for (int v945 = 0; v945 < 32; v945 += 1) {	// L1529
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v941
        #pragma HLS dependence false variable=v942
        #pragma HLS dependence false variable=v940
        float v946 = v941[0][v943][v944][v945];	// L1530
        float v947 = v940[0][v943][v944][v945];	// L1531
        float v948 = v946 * v947;	// L1532
        v942[0][v943][v944][v945] = v948;	// L1533
      }
    }
  }
}

void kernel858(
  float v949[1][48][32][32],
  float v950,
  float v951
) {	// L1539
  for (int v952 = 0; v952 < 48; v952 += 1) {	// L1540
    for (int v953 = 0; v953 < 32; v953 += 1) {	// L1541
      for (int v954 = 0; v954 < 32; v954 += 1) {	// L1542
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v949
        float v955 = v949[0][v952][v953][v954];	// L1543
        bool v956 = v955 >= v951;	// L1544
        float v957 = v956 ? v950 : v951;	// L1545
        v949[0][v952][v953][v954] = v957;	// L1546
      }
    }
  }
}

void kernel860(
  float v958[1][48][32][32],
  float v959
) {	// L1552
  for (int v960 = 0; v960 < 48; v960 += 1) {	// L1553
    for (int v961 = 0; v961 < 32; v961 += 1) {	// L1554
      for (int v962 = 0; v962 < 32; v962 += 1) {	// L1555
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v958
        float v963 = v958[0][v960][v961][v962];	// L1556
        float v964 = v963 - v959;	// L1557
        v958[0][v960][v961][v962] = v964;	// L1558
      }
    }
  }
}

void kernel862(
  float v965[1][48][32][32],
  float v966[1][48][32][32],
  float v967[1][48][32][32]
) {	// L1564
  for (int v968 = 0; v968 < 48; v968 += 1) {	// L1565
    for (int v969 = 0; v969 < 32; v969 += 1) {	// L1566
      for (int v970 = 0; v970 < 32; v970 += 1) {	// L1567
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v966
        #pragma HLS dependence false variable=v967
        #pragma HLS dependence false variable=v965
        float v971 = v966[0][v968][v969][v970];	// L1568
        float v972 = v965[0][v968][v969][v970];	// L1569
        float v973 = v971 + v972;	// L1570
        v967[0][v968][v969][v970] = v973;	// L1571
      }
    }
  }
}

void kernel863(
  float v974[1][48][32][32],
  float v975
) {	// L1577
  for (int v976 = 0; v976 < 48; v976 += 1) {	// L1578
    for (int v977 = 0; v977 < 32; v977 += 1) {	// L1579
      for (int v978 = 0; v978 < 32; v978 += 1) {	// L1580
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v974
        float v979 = v974[0][v976][v977][v978];	// L1581
        float v980 = v979 / v975;	// L1582
        v974[0][v976][v977][v978] = v980;	// L1583
      }
    }
  }
}

void kernel868(
  float v981[1][3][34][34],
  float v982[48][3][3][3],
  float v983[1][48][32][32]
) {	// L1589
  float v984[48][3][3][3];	// L1590
  #pragma HLS resource variable=v984 core=ram_t2p_bram

  memcpy(v984, v982, 1296 * sizeof(float));	// L1591

  for (int v985 = 0; v985 < 3; v985 += 1) {	// L1592
    for (int v986 = 0; v986 < 3; v986 += 1) {	// L1593
      for (int v987 = 0; v987 < 3; v987 += 1) {	// L1594
        for (int v988 = 0; v988 < 48; v988 += 1) {	// L1595
          for (int v989 = 0; v989 < 32; v989 += 1) {	// L1596
            for (int v990 = 0; v990 < 32; v990 += 1) {	// L1597
              #pragma HLS pipeline II=1
              #pragma HLS dependence false variable=v981
              #pragma HLS dependence false variable=v983
              #pragma HLS dependence false variable=v984
              float v991 = v981[0][v985][(v989 + v986)][(v990 + v987)];	// L1598
              float v992 = v984[v988][v985][v986][v987];	// L1599
              float v993 = v983[0][v988][v989][v990];	// L1600
              float v994 = v991 * v992;	// L1601
              float v995 = v993 + v994;	// L1602
              v983[0][v988][v989][v990] = v995;	// L1603
            }
          }
        }
      }
    }
  }
}

void kernel869(
  float v996[48],
  float v997[1][48][32][32]
) {	// L1612
  float v998[48];	// L1613
  #pragma HLS resource variable=v998 core=ram_t2p_bram

  memcpy(v998, v996, 48 * sizeof(float));	// L1614

  for (int v999 = 0; v999 < 48; v999 += 1) {	// L1615
    for (int v1000 = 0; v1000 < 32; v1000 += 1) {	// L1616
      for (int v1001 = 0; v1001 < 32; v1001 += 1) {	// L1617
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v998
        #pragma HLS dependence false variable=v997
        float v1002 = v998[v999];	// L1618
        v997[0][v999][v1000][v1001] = v1002;	// L1619
      }
    }
  }
}

void kernel870(
  float v1003[1][3][32][32],
  float v1004[1][3][34][34]
) {	// L1625
  for (int v1005 = 0; v1005 < 3; v1005 += 1) {	// L1626
    for (int v1006 = 0; v1006 < 32; v1006 += 1) {	// L1627
      for (int v1007 = 0; v1007 < 32; v1007 += 1) {	// L1628
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1003
        #pragma HLS dependence false variable=v1004
        float v1008 = v1003[0][v1005][v1006][v1007];	// L1629
        v1004[0][v1005][(v1006 + 1)][(v1007 + 1)] = v1008;	// L1630
      }
    }
  }
}

void kernel871(
  float v1009[1][3][34][34],
  float v1010
) {	// L1636
  for (int v1011 = 0; v1011 < 3; v1011 += 1) {	// L1637
    for (int v1012 = 0; v1012 < 34; v1012 += 1) {	// L1638
      for (int v1013 = 0; v1013 < 34; v1013 += 1) {	// L1639
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1009
        v1009[0][v1011][v1012][v1013] = v1010;	// L1640
      }
    }
  }
}

/// The top function
void control(
  ap_int<32> v1014[121454592],
  ap_int<32> v1015[121454592],
  ap_int<32> v1016[121454592]
) {	// L1646
  #pragma HLS interface s_axilite port=return bundle=ctrl
  #pragma hls interface m_axi offset=direct bundle=g0 port=v1014
  #pragma hls stable variable=v1014
  #pragma hls interface m_axi offset=direct bundle=g0 port=v1015
  #pragma hls stable variable=v1015
  #pragma hls interface m_axi offset=direct bundle=g0 port=v1016
  #pragma hls stable variable=v1016

  auto v1017 = reinterpret_cast<float(*)[3][34][34]>(v1015 + 6881280);
  kernel871(v1017, (float)0.000000);	// L1656
  auto v1018 = reinterpret_cast<float(*)[3][32][32]>(v1014);
  kernel870(v1018, v1017);	// L1658
  auto v1019 = reinterpret_cast<float(*)[48][32][32]>(v1014 + 7471104);
  auto v1020 = reinterpret_cast<float(*)>(v1016 + 117473280);
  kernel869(v1020, v1019);	// L1661
  auto v1021 = reinterpret_cast<float(*)[3][3][3]>(v1016 + 118800384);
  kernel868(v1017, v1021, v1019);	// L1663
  auto v1022 = reinterpret_cast<float(*)[48][32][32]>(v1014 + 196608);
  auto v1023 = reinterpret_cast<float(*)[48][32][32]>(v1014 + 6881280);
  kernel852(v1022, v1023);	// L1666
  kernel863(v1023, (float)2.000000);	// L1667
  auto v1024 = reinterpret_cast<float(*)[48][32][32]>(v1015 + 8060928);
  kernel856(v1023, v1022, v1024);	// L1669
  kernel852(v1019, v1023);	// L1670
  kernel863(v1023, (float)2.000000);	// L1671
  auto v1025 = reinterpret_cast<float(*)[48][32][32]>(v1016 + 7471104);
  kernel862(v1023, v1024, v1025);	// L1673
  kernel852(v1025, v1023);	// L1674
  kernel860(v1023, (float)1.000000);	// L1675
  auto v1026 = reinterpret_cast<float(*)[48][32][32]>(v1014 + 8060928);
  kernel852(v1023, v1026);	// L1677
  kernel858(v1026, (float)1.000000, (float)0.000000);	// L1678
  kernel857(v1025, v1026, v1023);	// L1679
  auto v1027 = reinterpret_cast<float(*)[48][32][32]>(v1015 + 8650752);
  kernel856(v1023, v1025, v1027);	// L1681
  kernel852(v1026, v1023);	// L1682
  kernel854(v1023, (float)0.000000);	// L1683
  kernel853(v1027, v1023);	// L1684
  kernel852(v1023, v1022);	// L1685
  auto v1028 = reinterpret_cast<float(*)[48][34][34]>(v1015 + 6881280);
  kernel851(v1028, (float)0.000000);	// L1687
  kernel850(v1026, v1028);	// L1688
  auto v1029 = reinterpret_cast<float(*)[96][32][32]>(v1014 + 7471104);
  auto v1030 = reinterpret_cast<float(*)>(v1016 + 114819072);
  kernel849(v1030, v1029);	// L1691
  auto v1031 = reinterpret_cast<float(*)[48][3][3]>(v1016 + 116146176);
  kernel848(v1028, v1031, v1029);	// L1693
  auto v1032 = reinterpret_cast<float(*)[96][32][32]>(v1014 + 393216);
  auto v1033 = reinterpret_cast<float(*)[96][32][32]>(v1015 + 6881280);
  kernel832(v1032, v1033);	// L1696
  kernel843(v1033, (float)2.000000);	// L1697
  auto v1034 = reinterpret_cast<float(*)[96][32][32]>(v1016 + 8060928);
  kernel836(v1033, v1032, v1034);	// L1699
  kernel832(v1029, v1033);	// L1700
  kernel843(v1033, (float)2.000000);	// L1701
  kernel842(v1033, v1034, v1029);	// L1702
  kernel832(v1029, v1033);	// L1703
  kernel840(v1033, (float)1.000000);	// L1704
  auto v1035 = reinterpret_cast<float(*)[96][32][32]>(v1015 + 8060928);
  kernel832(v1033, v1035);	// L1706
  kernel838(v1035, (float)1.000000, (float)0.000000);	// L1707
  kernel837(v1029, v1035, v1033);	// L1708
  auto v1036 = reinterpret_cast<float(*)[96][32][32]>(v1014 + 8650752);
  kernel836(v1033, v1029, v1036);	// L1710
  kernel832(v1035, v1033);	// L1711
  kernel834(v1033, (float)0.000000);	// L1712
  kernel833(v1036, v1033);	// L1713
  kernel832(v1033, v1032);	// L1714
  auto v1037 = reinterpret_cast<float(*)[96][34][34]>(v1014 + 6881280);
  kernel831(v1037, (float)0.000000);	// L1716
  kernel830(v1035, v1037);	// L1717
  auto v1038 = reinterpret_cast<float(*)[192][32][32]>(v1015 + 7471104);
  auto v1039 = reinterpret_cast<float(*)>(v1016 + 112164864);
  kernel829(v1039, v1038);	// L1720
  auto v1040 = reinterpret_cast<float(*)[96][3][3]>(v1016 + 113491968);
  kernel828(v1037, v1040, v1038);	// L1722
  auto v1041 = reinterpret_cast<float(*)[192][32][32]>(v1014 + 589824);
  auto v1042 = reinterpret_cast<float(*)[192][32][32]>(v1014 + 6881280);
  kernel812(v1041, v1042);	// L1725
  kernel823(v1042, (float)2.000000);	// L1726
  auto v1043 = reinterpret_cast<float(*)[192][32][32]>(v1016 + 8060928);
  kernel816(v1042, v1041, v1043);	// L1728
  kernel812(v1038, v1042);	// L1729
  kernel823(v1042, (float)2.000000);	// L1730
  kernel822(v1042, v1043, v1038);	// L1731
  kernel812(v1038, v1042);	// L1732
  kernel820(v1042, (float)1.000000);	// L1733
  auto v1044 = reinterpret_cast<float(*)[192][32][32]>(v1014 + 8060928);
  kernel812(v1042, v1044);	// L1735
  kernel818(v1044, (float)1.000000, (float)0.000000);	// L1736
  kernel817(v1038, v1044, v1042);	// L1737
  auto v1045 = reinterpret_cast<float(*)[192][32][32]>(v1016 + 8650752);
  kernel816(v1042, v1038, v1045);	// L1739
  kernel812(v1044, v1042);	// L1740
  kernel814(v1042, (float)0.000000);	// L1741
  kernel813(v1045, v1042);	// L1742
  kernel812(v1042, v1041);	// L1743
  auto v1046 = reinterpret_cast<float(*)[192][34][34]>(v1015 + 6881280);
  kernel811(v1046, (float)-INFINITY);	// L1745
  kernel810(v1044, v1046);	// L1746
  auto v1047 = reinterpret_cast<float(*)[192][16][16]>(v1014 + 7471104);
  kernel809(v1047, (float)-INFINITY);	// L1748
  auto v1048 = reinterpret_cast<float(*)[3]>(v1014 + 8060928);
  kernel808(v1046, v1048, v1047);	// L1750
  auto v1049 = reinterpret_cast<float(*)[192][18][18]>(v1015 + 6881280);
  kernel807(v1049, (float)0.000000);	// L1752
  kernel806(v1047, v1049);	// L1753
  auto v1050 = reinterpret_cast<float(*)[384][16][16]>(v1014 + 7471104);
  auto v1051 = reinterpret_cast<float(*)>(v1016 + 109510656);
  kernel805(v1051, v1050);	// L1756
  auto v1052 = reinterpret_cast<float(*)[192][3][3]>(v1016 + 110837760);
  kernel804(v1049, v1052, v1050);	// L1758
  auto v1053 = reinterpret_cast<float(*)[384][16][16]>(v1014 + 786432);
  auto v1054 = reinterpret_cast<float(*)[384][16][16]>(v1015 + 6881280);
  kernel788(v1053, v1054);	// L1761
  kernel799(v1054, (float)2.000000);	// L1762
  auto v1055 = reinterpret_cast<float(*)[384][16][16]>(v1016 + 8650752);
  kernel792(v1054, v1053, v1055);	// L1764
  kernel788(v1050, v1054);	// L1765
  kernel799(v1054, (float)2.000000);	// L1766
  kernel798(v1054, v1055, v1050);	// L1767
  kernel788(v1050, v1054);	// L1768
  kernel796(v1054, (float)1.000000);	// L1769
  auto v1056 = reinterpret_cast<float(*)[384][16][16]>(v1014 + 8650752);
  kernel788(v1054, v1056);	// L1771
  kernel794(v1056, (float)1.000000, (float)0.000000);	// L1772
  kernel793(v1050, v1056, v1054);	// L1773
  auto v1057 = reinterpret_cast<float(*)[384][16][16]>(v1016 + 9240576);
  kernel792(v1054, v1050, v1057);	// L1775
  kernel788(v1056, v1054);	// L1776
  kernel790(v1054, (float)0.000000);	// L1777
  kernel789(v1057, v1054);	// L1778
  kernel788(v1054, v1053);	// L1779
  auto v1058 = reinterpret_cast<float(*)[384][18][18]>(v1015 + 6881280);
  kernel787(v1058, (float)-INFINITY);	// L1781
  kernel786(v1056, v1058);	// L1782
  auto v1059 = reinterpret_cast<float(*)[384][8][8]>(v1016 + 7471104);
  kernel785(v1059, (float)-INFINITY);	// L1784
  kernel784(v1058, v1048, v1059);	// L1785
  auto v1060 = reinterpret_cast<float(*)[384][10][10]>(v1014 + 6881280);
  kernel783(v1060, (float)0.000000);	// L1787
  kernel782(v1059, v1060);	// L1788
  auto v1061 = reinterpret_cast<float(*)[384][8][8]>(v1015 + 8060928);
  auto v1062 = reinterpret_cast<float(*)>(v1016 + 106856448);
  kernel781(v1062, v1061);	// L1791
  auto v1063 = reinterpret_cast<float(*)[384][3][3]>(v1016 + 108183552);
  kernel780(v1060, v1063, v1061);	// L1793
  auto v1064 = reinterpret_cast<float(*)[384][8][8]>(v1014 + 983040);
  auto v1065 = reinterpret_cast<float(*)[384][8][8]>(v1015 + 8650752);
  kernel764(v1064, v1065);	// L1796
  kernel775(v1065, (float)2.000000);	// L1797
  auto v1066 = reinterpret_cast<float(*)[384][8][8]>(v1016 + 6881280);
  kernel768(v1065, v1064, v1066);	// L1799
  kernel764(v1061, v1065);	// L1800
  kernel775(v1065, (float)2.000000);	// L1801
  auto v1067 = reinterpret_cast<float(*)[384][8][8]>(v1014 + 8060928);
  kernel763(v1065, v1066, v1067);	// L1803
  kernel764(v1067, v1065);	// L1804
  kernel772(v1065, (float)1.000000);	// L1805
  kernel764(v1065, v1066);	// L1806
  kernel770(v1066, (float)1.000000, (float)0.000000);	// L1807
  kernel769(v1067, v1066, v1065);	// L1808
  auto v1068 = reinterpret_cast<float(*)[384][8][8]>(v1016 + 9240576);
  kernel768(v1065, v1067, v1068);	// L1810
  kernel764(v1066, v1065);	// L1811
  kernel766(v1065, (float)0.000000);	// L1812
  kernel765(v1068, v1065);	// L1813
  kernel764(v1065, v1064);	// L1814
  kernel763(v1059, v1066, v1065);	// L1815
  auto v1069 = reinterpret_cast<float(*)[8][8][384]>(v1014 + 6881280);
  kernel762(v1065, v1069);	// L1817
  auto v1070 = reinterpret_cast<float(*)[64][1]>(v1014 + 7471104);
  kernel761(v1070, (float)0.000000);	// L1819
  auto v1071 = reinterpret_cast<float(*)[64][1]>(v1015 + 8060928);
  kernel55(v1070, v1071);	// L1821
  kernel759(v1069, v1071);	// L1822
  kernel54(v1071, (float)384.000000);	// L1823
  auto v1072 = reinterpret_cast<float(*)[64][384]>(v1014 + 8650752);
  kernel51(v1071, v1072);	// L1825
  auto v1073 = reinterpret_cast<float(*)[64][384]>(v1015 + 9240576);
  kernel756(v1069, v1072, v1073);	// L1827
  kernel50(v1073, v1072);	// L1828
  auto v1074 = reinterpret_cast<float(*)[64][1]>(v1015 + 9830400);
  kernel55(v1070, v1074);	// L1830
  kernel56(v1072, v1074);	// L1831
  kernel55(v1074, v1071);	// L1832
  kernel54(v1071, (float)384.000000);	// L1833
  kernel53(v1071, (float)0.000010);	// L1834
  kernel52(v1071);	// L1835
  kernel51(v1071, v1072);	// L1836
  kernel50(v1073, v1072);	// L1837
  auto v1075 = reinterpret_cast<float(*)>(v1016 + 105529344);
  kernel49(v1075, v1072);	// L1839
  auto v1076 = reinterpret_cast<float(*)>(v1016 + 104202240);
  kernel174(v1076, v1072);	// L1841
  kernel47(v1072, v1073);	// L1842
  auto v1077 = reinterpret_cast<float(*)[384][384]>(v1014 + 9830400);
  auto v1078 = reinterpret_cast<float(*)[384]>(v1016 + 49790976);
  kernel84(v1078, v1077);	// L1845
  auto v1079 = reinterpret_cast<float(*)[64][384]>(v1014 + 10420224);
  kernel742(v1079, (float)0.000000);	// L1847
  auto v1080 = reinterpret_cast<float(*)[64][384]>(v1016 + 11010048);
  kernel8(v1079, v1080);	// L1849
  kernel82(v1073, v1077, v1080);	// L1850
  auto v1081 = reinterpret_cast<float(*)[64][384]>(v1015 + 11599872);
  auto v1082 = reinterpret_cast<float(*)>(v1014 + 102875136);
  kernel24(v1080, v1082, v1081);	// L1853
  auto v1083 = reinterpret_cast<float(*)[64][384]>(v1014 + 1179648);
  kernel8(v1083, v1072);	// L1855
  kernel19(v1072, (float)2.000000);	// L1856
  auto v1084 = reinterpret_cast<float(*)[64][384]>(v1015 + 11010048);
  kernel12(v1072, v1083, v1084);	// L1858
  kernel8(v1081, v1072);	// L1859
  kernel19(v1072, (float)2.000000);	// L1860
  auto v1085 = reinterpret_cast<float(*)[64][384]>(v1016 + 11599872);
  kernel7(v1072, v1084, v1085);	// L1862
  kernel8(v1085, v1072);	// L1863
  kernel16(v1072, (float)1.000000);	// L1864
  auto v1086 = reinterpret_cast<float(*)[64][384]>(v1014 + 11010048);
  kernel8(v1072, v1086);	// L1866
  kernel14(v1086, (float)1.000000, (float)0.000000);	// L1867
  kernel13(v1085, v1086, v1072);	// L1868
  auto v1087 = reinterpret_cast<float(*)[64][384]>(v1015 + 12189696);
  kernel12(v1072, v1085, v1087);	// L1870
  kernel8(v1086, v1072);	// L1871
  kernel10(v1072, (float)0.000000);	// L1872
  kernel9(v1087, v1072);	// L1873
  kernel8(v1072, v1083);	// L1874
  auto v1088 = reinterpret_cast<float(*)[12][64][32]>(v1015 + 11599872);
  kernel111(v1086, v1088);	// L1876
  auto v1089 = reinterpret_cast<float(*)[384]>(v1016 + 48463872);
  kernel84(v1089, v1077);	// L1878
  kernel8(v1079, v1086);	// L1879
  kernel82(v1073, v1077, v1086);	// L1880
  auto v1090 = reinterpret_cast<float(*)>(v1016 + 101548032);
  kernel24(v1086, v1090, v1087);	// L1882
  auto v1091 = reinterpret_cast<float(*)[64][384]>(v1014 + 1376256);
  kernel8(v1091, v1072);	// L1884
  kernel19(v1072, (float)2.000000);	// L1885
  kernel12(v1072, v1091, v1080);	// L1886
  kernel8(v1087, v1072);	// L1887
  kernel19(v1072, (float)2.000000);	// L1888
  kernel7(v1072, v1080, v1087);	// L1889
  kernel8(v1087, v1072);	// L1890
  kernel16(v1072, (float)1.000000);	// L1891
  kernel8(v1072, v1086);	// L1892
  kernel14(v1086, (float)1.000000, (float)0.000000);	// L1893
  kernel13(v1087, v1086, v1072);	// L1894
  auto v1092 = reinterpret_cast<float(*)[64][384]>(v1015 + 12779520);
  kernel12(v1072, v1087, v1092);	// L1896
  kernel8(v1086, v1072);	// L1897
  kernel10(v1072, (float)0.000000);	// L1898
  kernel9(v1092, v1072);	// L1899
  kernel8(v1072, v1091);	// L1900
  auto v1093 = reinterpret_cast<float(*)[384]>(v1016 + 47136768);
  kernel84(v1093, v1077);	// L1902
  auto v1094 = reinterpret_cast<float(*)[64][384]>(v1014 + 12189696);
  kernel8(v1079, v1094);	// L1904
  kernel82(v1073, v1077, v1094);	// L1905
  auto v1095 = reinterpret_cast<float(*)>(v1016 + 100220928);
  kernel24(v1094, v1095, v1073);	// L1907
  auto v1096 = reinterpret_cast<float(*)[64][384]>(v1014 + 1572864);
  kernel8(v1096, v1072);	// L1909
  kernel19(v1072, (float)2.000000);	// L1910
  kernel12(v1072, v1096, v1087);	// L1911
  kernel8(v1073, v1072);	// L1912
  kernel19(v1072, (float)2.000000);	// L1913
  kernel7(v1072, v1087, v1073);	// L1914
  kernel8(v1073, v1072);	// L1915
  kernel16(v1072, (float)1.000000);	// L1916
  kernel8(v1072, v1094);	// L1917
  kernel14(v1094, (float)1.000000, (float)0.000000);	// L1918
  kernel13(v1073, v1094, v1072);	// L1919
  auto v1097 = reinterpret_cast<float(*)[64][384]>(v1016 + 12779520);
  kernel12(v1072, v1073, v1097);	// L1921
  kernel8(v1094, v1072);	// L1922
  kernel10(v1072, (float)0.000000);	// L1923
  kernel9(v1097, v1072);	// L1924
  kernel8(v1072, v1096);	// L1925
  auto v1098 = reinterpret_cast<float(*)[12][64][32]>(v1015 + 9240576);
  kernel111(v1094, v1098);	// L1927
  auto v1099 = reinterpret_cast<float(*)[12][32][64]>(v1015 + 12189696);
  kernel110(v1086, v1099);	// L1929
  auto v1100 = reinterpret_cast<float(*)[12][64][32]>(v1014 + 12779520);
  kernel104(v1088, v1100);	// L1931
  auto v1101 = reinterpret_cast<float(*)[12][32][64]>(v1014 + 11010048);
  kernel108(v1099, v1101);	// L1933
  auto v1102 = reinterpret_cast<float(*)[64][64]>(v1014 + 11599872);
  kernel677(v1102, (float)0.000000);	// L1935
  auto v1103 = reinterpret_cast<float(*)[64][64]>(v1014 + 12189696);
  kernel296(v1102, v1103);	// L1937
  kernel107(v1100, v1101, v1103);	// L1938
  auto v1104 = reinterpret_cast<float(*)[12][64][64]>(v1015 + 13369344);
  auto v1105 = reinterpret_cast<float(*)>(v1016 + 120127488);
  kernel106(v1103, v1105, v1104);	// L1941
  auto v1106 = reinterpret_cast<float(*)[12][64][64]>(v1014 + 12189696);
  kernel105(v1104, v1106);	// L1943
  kernel104(v1098, v1100);	// L1944
  auto v1107 = reinterpret_cast<float(*)[64][32]>(v1014 + 9240576);
  kernel671(v1107, (float)0.000000);	// L1946
  auto v1108 = reinterpret_cast<float(*)[64][32]>(v1014 + 13369344);
  kernel291(v1107, v1108);	// L1948
  kernel103(v1106, v1100, v1108);	// L1949
  auto v1109 = reinterpret_cast<float(*)[64][12][32]>(v1015 + 13959168);
  kernel102(v1108, v1109);	// L1951
  auto v1110 = reinterpret_cast<float(*)[64][384]>(v1014 + 1769472);
  kernel8(v1110, v1072);	// L1953
  kernel19(v1072, (float)2.000000);	// L1954
  auto v1111 = reinterpret_cast<float(*)[64][384]>(v1016 + 13369344);
  kernel12(v1072, v1110, v1111);	// L1956
  kernel98(v1109, v1072);	// L1957
  kernel19(v1072, (float)2.000000);	// L1958
  auto v1112 = reinterpret_cast<float(*)[64][384]>(v1015 + 14548992);
  kernel7(v1072, v1111, v1112);	// L1960
  kernel8(v1112, v1072);	// L1961
  kernel16(v1072, (float)0.500000);	// L1962
  auto v1113 = reinterpret_cast<float(*)[64][384]>(v1015 + 13369344);
  kernel8(v1072, v1113);	// L1964
  kernel14(v1113, (float)1.000000, (float)0.000000);	// L1965
  kernel13(v1112, v1113, v1072);	// L1966
  auto v1114 = reinterpret_cast<float(*)[64][384]>(v1016 + 15138816);
  kernel12(v1072, v1112, v1114);	// L1968
  kernel8(v1113, v1072);	// L1969
  kernel10(v1072, (float)0.000000);	// L1970
  kernel9(v1114, v1072);	// L1971
  kernel8(v1072, v1110);	// L1972
  kernel47(v1113, v1072);	// L1973
  auto v1115 = reinterpret_cast<float(*)[384]>(v1016 + 45809664);
  kernel84(v1115, v1077);	// L1975
  kernel8(v1079, v1113);	// L1976
  kernel82(v1072, v1077, v1113);	// L1977
  auto v1116 = reinterpret_cast<float(*)>(v1016 + 98893824);
  kernel24(v1113, v1116, v1112);	// L1979
  auto v1117 = reinterpret_cast<float(*)[64][384]>(v1014 + 1966080);
  kernel8(v1117, v1072);	// L1981
  kernel19(v1072, (float)2.000000);	// L1982
  kernel12(v1072, v1117, v1113);	// L1983
  kernel8(v1112, v1072);	// L1984
  kernel19(v1072, (float)2.000000);	// L1985
  auto v1118 = reinterpret_cast<float(*)[64][384]>(v1016 + 14548992);
  kernel7(v1072, v1113, v1118);	// L1987
  kernel8(v1118, v1072);	// L1988
  kernel16(v1072, (float)1.000000);	// L1989
  kernel8(v1072, v1113);	// L1990
  kernel14(v1113, (float)1.000000, (float)0.000000);	// L1991
  kernel13(v1118, v1113, v1072);	// L1992
  auto v1119 = reinterpret_cast<float(*)[64][384]>(v1015 + 15138816);
  kernel12(v1072, v1118, v1119);	// L1994
  kernel8(v1113, v1072);	// L1995
  kernel10(v1072, (float)0.000000);	// L1996
  kernel9(v1119, v1072);	// L1997
  kernel8(v1072, v1117);	// L1998
  auto v1120 = reinterpret_cast<float(*)[64][384]>(v1014 + 14548992);
  kernel630(v1069, v1113, v1120);	// L2000
  auto v1121 = reinterpret_cast<float(*)[64][1]>(v1015 + 6881280);
  kernel55(v1070, v1121);	// L2002
  kernel56(v1120, v1121);	// L2003
  kernel55(v1121, v1071);	// L2004
  kernel54(v1071, (float)384.000000);	// L2005
  kernel51(v1071, v1072);	// L2006
  auto v1122 = reinterpret_cast<float(*)[64][384]>(v1015 + 6881280);
  kernel12(v1072, v1120, v1122);	// L2008
  kernel50(v1122, v1072);	// L2009
  auto v1123 = reinterpret_cast<float(*)[64][1]>(v1015 + 13369344);
  kernel55(v1070, v1123);	// L2011
  kernel56(v1072, v1123);	// L2012
  kernel55(v1123, v1071);	// L2013
  kernel54(v1071, (float)384.000000);	// L2014
  kernel53(v1071, (float)0.000010);	// L2015
  kernel52(v1071);	// L2016
  kernel51(v1071, v1072);	// L2017
  kernel50(v1122, v1072);	// L2018
  auto v1124 = reinterpret_cast<float(*)>(v1016 + 97566720);
  kernel49(v1124, v1072);	// L2020
  auto v1125 = reinterpret_cast<float(*)>(v1016 + 96239616);
  kernel48(v1125, v1072, v1122);	// L2022
  kernel47(v1122, v1072);	// L2023
  auto v1126 = reinterpret_cast<float(*)[384][1536]>(v1015 + 6881280);
  auto v1127 = reinterpret_cast<float(*)[1536]>(v1016 + 44482560);
  kernel46(v1127, v1126);	// L2026
  auto v1128 = reinterpret_cast<float(*)[64][1536]>(v1014 + 13369344);
  kernel610(v1128, (float)0.000000);	// L2028
  auto v1129 = reinterpret_cast<float(*)[64][1536]>(v1014 + 15138816);
  kernel28(v1128, v1129);	// L2030
  kernel45(v1072, v1126, v1129);	// L2031
  auto v1130 = reinterpret_cast<float(*)[64][1536]>(v1015 + 15728640);
  auto v1131 = reinterpret_cast<float(*)>(v1016 + 94912512);
  kernel44(v1129, v1131, v1130);	// L2034
  auto v1132 = reinterpret_cast<float(*)[64][1536]>(v1014 + 2162688);
  auto v1133 = reinterpret_cast<float(*)[64][1536]>(v1014 + 16318464);
  kernel28(v1132, v1133);	// L2037
  kernel39(v1133, (float)2.000000);	// L2038
  auto v1134 = reinterpret_cast<float(*)[64][1536]>(v1015 + 15138816);
  kernel32(v1133, v1132, v1134);	// L2040
  kernel28(v1130, v1133);	// L2041
  kernel39(v1133, (float)2.000000);	// L2042
  auto v1135 = reinterpret_cast<float(*)[64][1536]>(v1016 + 15728640);
  kernel38(v1133, v1134, v1135);	// L2044
  kernel28(v1135, v1133);	// L2045
  kernel36(v1133, (float)1.000000);	// L2046
  kernel28(v1133, v1134);	// L2047
  kernel34(v1134, (float)1.000000, (float)0.000000);	// L2048
  kernel33(v1135, v1134, v1133);	// L2049
  auto v1136 = reinterpret_cast<float(*)[64][1536]>(v1015 + 16908288);
  kernel32(v1133, v1135, v1136);	// L2051
  kernel28(v1134, v1133);	// L2052
  kernel30(v1133, (float)0.000000);	// L2053
  kernel29(v1136, v1133);	// L2054
  kernel28(v1133, v1132);	// L2055
  kernel27(v1134, v1133);	// L2056
  auto v1137 = reinterpret_cast<float(*)[1536][384]>(v1014 + 15138816);
  auto v1138 = reinterpret_cast<float(*)[384]>(v1016 + 43155456);
  kernel26(v1138, v1137);	// L2059
  auto v1139 = reinterpret_cast<float(*)[64][384]>(v1015 + 15728640);
  kernel8(v1079, v1139);	// L2061
  kernel25(v1133, v1137, v1139);	// L2062
  auto v1140 = reinterpret_cast<float(*)[64][384]>(v1014 + 16908288);
  auto v1141 = reinterpret_cast<float(*)>(v1016 + 93585408);
  kernel24(v1139, v1141, v1140);	// L2065
  auto v1142 = reinterpret_cast<float(*)[64][384]>(v1014 + 2359296);
  kernel8(v1142, v1072);	// L2067
  kernel19(v1072, (float)2.000000);	// L2068
  kernel12(v1072, v1142, v1139);	// L2069
  kernel8(v1140, v1072);	// L2070
  kernel19(v1072, (float)2.000000);	// L2071
  auto v1143 = reinterpret_cast<float(*)[64][384]>(v1016 + 16908288);
  kernel7(v1072, v1139, v1143);	// L2073
  kernel8(v1143, v1072);	// L2074
  kernel16(v1072, (float)1.000000);	// L2075
  auto v1144 = reinterpret_cast<float(*)[64][384]>(v1016 + 15728640);
  kernel8(v1072, v1144);	// L2077
  kernel14(v1144, (float)1.000000, (float)0.000000);	// L2078
  kernel13(v1143, v1144, v1072);	// L2079
  auto v1145 = reinterpret_cast<float(*)[64][384]>(v1015 + 17498112);
  kernel12(v1072, v1143, v1145);	// L2081
  kernel8(v1144, v1072);	// L2082
  kernel10(v1072, (float)0.000000);	// L2083
  kernel9(v1145, v1072);	// L2084
  kernel8(v1072, v1142);	// L2085
  auto v1146 = reinterpret_cast<float(*)[64][384]>(v1015 + 16908288);
  kernel7(v1144, v1120, v1146);	// L2087
  auto v1147 = reinterpret_cast<float(*)[64][1]>(v1014 + 14548992);
  kernel55(v1070, v1147);	// L2089
  kernel56(v1146, v1147);	// L2090
  kernel55(v1147, v1071);	// L2091
  kernel54(v1071, (float)384.000000);	// L2092
  kernel51(v1071, v1072);	// L2093
  kernel12(v1072, v1146, v1118);	// L2094
  kernel50(v1118, v1072);	// L2095
  auto v1148 = reinterpret_cast<float(*)[64][1]>(v1015 + 15728640);
  kernel55(v1070, v1148);	// L2097
  kernel56(v1072, v1148);	// L2098
  kernel55(v1148, v1071);	// L2099
  kernel54(v1071, (float)384.000000);	// L2100
  kernel53(v1071, (float)0.000010);	// L2101
  kernel52(v1071);	// L2102
  kernel51(v1071, v1072);	// L2103
  kernel50(v1118, v1072);	// L2104
  auto v1149 = reinterpret_cast<float(*)>(v1016 + 92258304);
  kernel49(v1149, v1072);	// L2106
  auto v1150 = reinterpret_cast<float(*)>(v1016 + 90931200);
  kernel174(v1150, v1072);	// L2108
  kernel47(v1072, v1112);	// L2109
  auto v1151 = reinterpret_cast<float(*)[384]>(v1016 + 41828352);
  kernel84(v1151, v1077);	// L2111
  auto v1152 = reinterpret_cast<float(*)[64][384]>(v1014 + 15728640);
  kernel8(v1079, v1152);	// L2113
  kernel82(v1112, v1077, v1152);	// L2114
  auto v1153 = reinterpret_cast<float(*)>(v1016 + 89604096);
  kernel24(v1152, v1153, v1145);	// L2116
  auto v1154 = reinterpret_cast<float(*)[64][384]>(v1014 + 2555904);
  kernel8(v1154, v1072);	// L2118
  kernel19(v1072, (float)2.000000);	// L2119
  kernel12(v1072, v1154, v1139);	// L2120
  kernel8(v1145, v1072);	// L2121
  kernel19(v1072, (float)2.000000);	// L2122
  auto v1155 = reinterpret_cast<float(*)[64][384]>(v1016 + 17498112);
  kernel7(v1072, v1139, v1155);	// L2124
  kernel8(v1155, v1072);	// L2125
  kernel16(v1072, (float)1.000000);	// L2126
  kernel8(v1072, v1152);	// L2127
  kernel14(v1152, (float)1.000000, (float)0.000000);	// L2128
  kernel13(v1155, v1152, v1072);	// L2129
  auto v1156 = reinterpret_cast<float(*)[64][384]>(v1015 + 18087936);
  kernel12(v1072, v1155, v1156);	// L2131
  kernel8(v1152, v1072);	// L2132
  kernel10(v1072, (float)0.000000);	// L2133
  kernel9(v1156, v1072);	// L2134
  kernel8(v1072, v1154);	// L2135
  auto v1157 = reinterpret_cast<float(*)[12][64][32]>(v1015 + 17498112);
  kernel111(v1152, v1157);	// L2137
  auto v1158 = reinterpret_cast<float(*)[384]>(v1016 + 40501248);
  kernel84(v1158, v1077);	// L2139
  kernel8(v1079, v1152);	// L2140
  kernel82(v1112, v1077, v1152);	// L2141
  auto v1159 = reinterpret_cast<float(*)>(v1016 + 88276992);
  kernel24(v1152, v1159, v1156);	// L2143
  auto v1160 = reinterpret_cast<float(*)[64][384]>(v1014 + 2752512);
  kernel8(v1160, v1072);	// L2145
  kernel19(v1072, (float)2.000000);	// L2146
  kernel12(v1072, v1160, v1139);	// L2147
  kernel8(v1156, v1072);	// L2148
  kernel19(v1072, (float)2.000000);	// L2149
  auto v1161 = reinterpret_cast<float(*)[64][384]>(v1016 + 18087936);
  kernel7(v1072, v1139, v1161);	// L2151
  kernel8(v1161, v1072);	// L2152
  kernel16(v1072, (float)1.000000);	// L2153
  kernel8(v1072, v1152);	// L2154
  kernel14(v1152, (float)1.000000, (float)0.000000);	// L2155
  kernel13(v1161, v1152, v1072);	// L2156
  auto v1162 = reinterpret_cast<float(*)[64][384]>(v1015 + 18677760);
  kernel12(v1072, v1161, v1162);	// L2158
  kernel8(v1152, v1072);	// L2159
  kernel10(v1072, (float)0.000000);	// L2160
  kernel9(v1162, v1072);	// L2161
  kernel8(v1072, v1160);	// L2162
  auto v1163 = reinterpret_cast<float(*)[384]>(v1016 + 39174144);
  kernel84(v1163, v1077);	// L2164
  kernel8(v1079, v1156);	// L2165
  kernel82(v1112, v1077, v1156);	// L2166
  auto v1164 = reinterpret_cast<float(*)>(v1016 + 86949888);
  kernel24(v1156, v1164, v1120);	// L2168
  auto v1165 = reinterpret_cast<float(*)[64][384]>(v1014 + 2949120);
  kernel8(v1165, v1072);	// L2170
  kernel19(v1072, (float)2.000000);	// L2171
  kernel12(v1072, v1165, v1156);	// L2172
  kernel8(v1120, v1072);	// L2173
  kernel19(v1072, (float)2.000000);	// L2174
  kernel7(v1072, v1156, v1112);	// L2175
  kernel8(v1112, v1072);	// L2176
  kernel16(v1072, (float)1.000000);	// L2177
  kernel8(v1072, v1161);	// L2178
  kernel14(v1161, (float)1.000000, (float)0.000000);	// L2179
  kernel13(v1112, v1161, v1072);	// L2180
  auto v1166 = reinterpret_cast<float(*)[64][384]>(v1016 + 18677760);
  kernel12(v1072, v1112, v1166);	// L2182
  kernel8(v1161, v1072);	// L2183
  kernel10(v1072, (float)0.000000);	// L2184
  kernel9(v1166, v1072);	// L2185
  kernel8(v1072, v1165);	// L2186
  auto v1167 = reinterpret_cast<float(*)[12][64][32]>(v1015 + 14548992);
  kernel111(v1161, v1167);	// L2188
  auto v1168 = reinterpret_cast<float(*)[12][32][64]>(v1015 + 18087936);
  kernel110(v1152, v1168);	// L2190
  kernel104(v1157, v1100);	// L2191
  kernel108(v1168, v1101);	// L2192
  auto v1169 = reinterpret_cast<float(*)[64][64]>(v1015 + 15728640);
  kernel296(v1102, v1169);	// L2194
  kernel107(v1100, v1101, v1169);	// L2195
  auto v1170 = reinterpret_cast<float(*)[12][64][64]>(v1015 + 17498112);
  kernel106(v1169, v1105, v1170);	// L2197
  kernel105(v1170, v1106);	// L2198
  kernel104(v1167, v1100);	// L2199
  auto v1171 = reinterpret_cast<float(*)[64][32]>(v1015 + 14548992);
  kernel291(v1107, v1171);	// L2201
  kernel103(v1106, v1100, v1171);	// L2202
  kernel102(v1171, v1109);	// L2203
  auto v1172 = reinterpret_cast<float(*)[64][384]>(v1014 + 3145728);
  kernel8(v1172, v1072);	// L2205
  kernel19(v1072, (float)2.000000);	// L2206
  kernel12(v1072, v1172, v1118);	// L2207
  kernel98(v1109, v1072);	// L2208
  kernel19(v1072, (float)2.000000);	// L2209
  kernel7(v1072, v1118, v1139);	// L2210
  kernel8(v1139, v1072);	// L2211
  kernel16(v1072, (float)0.500000);	// L2212
  kernel8(v1072, v1112);	// L2213
  kernel14(v1112, (float)1.000000, (float)0.000000);	// L2214
  kernel13(v1139, v1112, v1072);	// L2215
  kernel12(v1072, v1139, v1145);	// L2216
  kernel8(v1112, v1072);	// L2217
  kernel10(v1072, (float)0.000000);	// L2218
  kernel9(v1145, v1072);	// L2219
  kernel8(v1072, v1172);	// L2220
  kernel47(v1112, v1072);	// L2221
  auto v1173 = reinterpret_cast<float(*)[384]>(v1016 + 37847040);
  kernel84(v1173, v1077);	// L2223
  kernel8(v1079, v1120);	// L2224
  kernel82(v1072, v1077, v1120);	// L2225
  auto v1174 = reinterpret_cast<float(*)>(v1016 + 85622784);
  kernel24(v1120, v1174, v1139);	// L2227
  auto v1175 = reinterpret_cast<float(*)[64][384]>(v1014 + 3342336);
  kernel8(v1175, v1072);	// L2229
  kernel19(v1072, (float)2.000000);	// L2230
  kernel12(v1072, v1175, v1112);	// L2231
  kernel8(v1139, v1072);	// L2232
  kernel19(v1072, (float)2.000000);	// L2233
  kernel7(v1072, v1112, v1139);	// L2234
  kernel8(v1139, v1072);	// L2235
  kernel16(v1072, (float)1.000000);	// L2236
  kernel8(v1072, v1118);	// L2237
  kernel14(v1118, (float)1.000000, (float)0.000000);	// L2238
  kernel13(v1139, v1118, v1072);	// L2239
  kernel12(v1072, v1139, v1145);	// L2240
  kernel8(v1118, v1072);	// L2241
  kernel10(v1072, (float)0.000000);	// L2242
  kernel9(v1145, v1072);	// L2243
  kernel8(v1072, v1175);	// L2244
  kernel7(v1118, v1146, v1152);	// L2245
  auto v1176 = reinterpret_cast<float(*)[64][1]>(v1015 + 14548992);
  kernel55(v1070, v1176);	// L2247
  kernel56(v1152, v1176);	// L2248
  kernel55(v1176, v1071);	// L2249
  kernel54(v1071, (float)384.000000);	// L2250
  kernel51(v1071, v1072);	// L2251
  kernel12(v1072, v1152, v1112);	// L2252
  kernel50(v1112, v1072);	// L2253
  auto v1177 = reinterpret_cast<float(*)[64][1]>(v1015 + 16908288);
  kernel55(v1070, v1177);	// L2255
  kernel56(v1072, v1177);	// L2256
  kernel55(v1177, v1071);	// L2257
  kernel54(v1071, (float)384.000000);	// L2258
  kernel53(v1071, (float)0.000010);	// L2259
  kernel52(v1071);	// L2260
  kernel51(v1071, v1072);	// L2261
  kernel50(v1112, v1072);	// L2262
  auto v1178 = reinterpret_cast<float(*)>(v1016 + 84295680);
  kernel49(v1178, v1072);	// L2264
  auto v1179 = reinterpret_cast<float(*)>(v1016 + 82968576);
  kernel48(v1179, v1072, v1112);	// L2266
  kernel47(v1112, v1072);	// L2267
  auto v1180 = reinterpret_cast<float(*)[1536]>(v1016 + 36519936);
  kernel46(v1180, v1126);	// L2269
  auto v1181 = reinterpret_cast<float(*)[64][1536]>(v1016 + 14548992);
  kernel28(v1128, v1181);	// L2271
  kernel45(v1072, v1126, v1181);	// L2272
  auto v1182 = reinterpret_cast<float(*)>(v1014 + 81641472);
  kernel44(v1181, v1182, v1136);	// L2274
  auto v1183 = reinterpret_cast<float(*)[64][1536]>(v1014 + 3538944);
  kernel28(v1183, v1133);	// L2276
  kernel39(v1133, (float)2.000000);	// L2277
  auto v1184 = reinterpret_cast<float(*)[64][1536]>(v1015 + 14548992);
  kernel32(v1133, v1183, v1184);	// L2279
  kernel28(v1136, v1133);	// L2280
  kernel39(v1133, (float)2.000000);	// L2281
  kernel38(v1133, v1184, v1136);	// L2282
  kernel28(v1136, v1133);	// L2283
  kernel36(v1133, (float)1.000000);	// L2284
  auto v1185 = reinterpret_cast<float(*)[64][1536]>(v1014 + 14548992);
  kernel28(v1133, v1185);	// L2286
  kernel34(v1185, (float)1.000000, (float)0.000000);	// L2287
  kernel33(v1136, v1185, v1133);	// L2288
  auto v1186 = reinterpret_cast<float(*)[64][1536]>(v1016 + 17498112);
  kernel32(v1133, v1136, v1186);	// L2290
  kernel28(v1185, v1133);	// L2291
  kernel30(v1133, (float)0.000000);	// L2292
  kernel29(v1186, v1133);	// L2293
  kernel28(v1133, v1183);	// L2294
  kernel27(v1185, v1133);	// L2295
  auto v1187 = reinterpret_cast<float(*)[384]>(v1016 + 35192832);
  kernel26(v1187, v1137);	// L2297
  kernel8(v1079, v1112);	// L2298
  kernel25(v1133, v1137, v1112);	// L2299
  auto v1188 = reinterpret_cast<float(*)>(v1016 + 80314368);
  kernel24(v1112, v1188, v1146);	// L2301
  auto v1189 = reinterpret_cast<float(*)[64][384]>(v1014 + 3735552);
  kernel8(v1189, v1072);	// L2303
  kernel19(v1072, (float)2.000000);	// L2304
  kernel12(v1072, v1189, v1112);	// L2305
  kernel8(v1146, v1072);	// L2306
  kernel19(v1072, (float)2.000000);	// L2307
  kernel7(v1072, v1112, v1143);	// L2308
  kernel8(v1143, v1072);	// L2309
  kernel16(v1072, (float)1.000000);	// L2310
  kernel8(v1072, v1112);	// L2311
  kernel14(v1112, (float)1.000000, (float)0.000000);	// L2312
  kernel13(v1143, v1112, v1072);	// L2313
  kernel12(v1072, v1143, v1145);	// L2314
  kernel8(v1112, v1072);	// L2315
  kernel10(v1072, (float)0.000000);	// L2316
  kernel9(v1145, v1072);	// L2317
  kernel8(v1072, v1189);	// L2318
  kernel7(v1112, v1152, v1143);	// L2319
  kernel55(v1070, v1147);	// L2320
  kernel56(v1143, v1147);	// L2321
  kernel55(v1147, v1071);	// L2322
  kernel54(v1071, (float)384.000000);	// L2323
  kernel51(v1071, v1072);	// L2324
  kernel12(v1072, v1143, v1112);	// L2325
  kernel50(v1112, v1072);	// L2326
  kernel55(v1070, v1148);	// L2327
  kernel56(v1072, v1148);	// L2328
  kernel55(v1148, v1071);	// L2329
  kernel54(v1071, (float)384.000000);	// L2330
  kernel53(v1071, (float)0.000010);	// L2331
  kernel52(v1071);	// L2332
  kernel51(v1071, v1072);	// L2333
  kernel50(v1112, v1072);	// L2334
  auto v1190 = reinterpret_cast<float(*)>(v1016 + 78987264);
  kernel49(v1190, v1072);	// L2336
  auto v1191 = reinterpret_cast<float(*)>(v1016 + 77660160);
  kernel174(v1191, v1072);	// L2338
  kernel47(v1072, v1112);	// L2339
  auto v1192 = reinterpret_cast<float(*)[384]>(v1016 + 33865728);
  kernel84(v1192, v1077);	// L2341
  kernel8(v1079, v1144);	// L2342
  kernel82(v1112, v1077, v1144);	// L2343
  auto v1193 = reinterpret_cast<float(*)>(v1014 + 76333056);
  kernel24(v1144, v1193, v1145);	// L2345
  auto v1194 = reinterpret_cast<float(*)[64][384]>(v1014 + 3932160);
  kernel8(v1194, v1072);	// L2347
  kernel19(v1072, (float)2.000000);	// L2348
  kernel12(v1072, v1194, v1139);	// L2349
  kernel8(v1145, v1072);	// L2350
  kernel19(v1072, (float)2.000000);	// L2351
  kernel7(v1072, v1139, v1155);	// L2352
  kernel8(v1155, v1072);	// L2353
  kernel16(v1072, (float)1.000000);	// L2354
  kernel8(v1072, v1152);	// L2355
  kernel14(v1152, (float)1.000000, (float)0.000000);	// L2356
  kernel13(v1155, v1152, v1072);	// L2357
  kernel12(v1072, v1155, v1156);	// L2358
  kernel8(v1152, v1072);	// L2359
  kernel10(v1072, (float)0.000000);	// L2360
  kernel9(v1156, v1072);	// L2361
  kernel8(v1072, v1194);	// L2362
  kernel111(v1152, v1157);	// L2363
  auto v1195 = reinterpret_cast<float(*)[384]>(v1016 + 32538624);
  kernel84(v1195, v1077);	// L2365
  kernel8(v1079, v1152);	// L2366
  kernel82(v1112, v1077, v1152);	// L2367
  auto v1196 = reinterpret_cast<float(*)>(v1016 + 75005952);
  kernel24(v1152, v1196, v1156);	// L2369
  auto v1197 = reinterpret_cast<float(*)[64][384]>(v1014 + 4128768);
  kernel8(v1197, v1072);	// L2371
  kernel19(v1072, (float)2.000000);	// L2372
  kernel12(v1072, v1197, v1139);	// L2373
  kernel8(v1156, v1072);	// L2374
  kernel19(v1072, (float)2.000000);	// L2375
  kernel7(v1072, v1139, v1161);	// L2376
  kernel8(v1161, v1072);	// L2377
  kernel16(v1072, (float)1.000000);	// L2378
  kernel8(v1072, v1139);	// L2379
  kernel14(v1139, (float)1.000000, (float)0.000000);	// L2380
  kernel13(v1161, v1139, v1072);	// L2381
  kernel12(v1072, v1161, v1162);	// L2382
  kernel8(v1139, v1072);	// L2383
  kernel10(v1072, (float)0.000000);	// L2384
  kernel9(v1162, v1072);	// L2385
  kernel8(v1072, v1197);	// L2386
  auto v1198 = reinterpret_cast<float(*)[384]>(v1016 + 31211520);
  kernel84(v1198, v1077);	// L2388
  kernel8(v1079, v1161);	// L2389
  kernel82(v1112, v1077, v1161);	// L2390
  auto v1199 = reinterpret_cast<float(*)>(v1014 + 73678848);
  kernel24(v1161, v1199, v1112);	// L2392
  auto v1200 = reinterpret_cast<float(*)[64][384]>(v1014 + 4325376);
  kernel8(v1200, v1072);	// L2394
  kernel19(v1072, (float)2.000000);	// L2395
  kernel12(v1072, v1200, v1156);	// L2396
  kernel8(v1112, v1072);	// L2397
  kernel19(v1072, (float)2.000000);	// L2398
  kernel7(v1072, v1156, v1118);	// L2399
  kernel8(v1118, v1072);	// L2400
  kernel16(v1072, (float)1.000000);	// L2401
  kernel8(v1072, v1156);	// L2402
  kernel14(v1156, (float)1.000000, (float)0.000000);	// L2403
  kernel13(v1118, v1156, v1072);	// L2404
  kernel12(v1072, v1118, v1162);	// L2405
  kernel8(v1156, v1072);	// L2406
  kernel10(v1072, (float)0.000000);	// L2407
  kernel9(v1162, v1072);	// L2408
  kernel8(v1072, v1200);	// L2409
  auto v1201 = reinterpret_cast<float(*)[12][64][32]>(v1014 + 14548992);
  kernel111(v1156, v1201);	// L2411
  auto v1202 = reinterpret_cast<float(*)[12][32][64]>(v1014 + 18087936);
  kernel110(v1139, v1202);	// L2413
  kernel104(v1157, v1100);	// L2414
  kernel108(v1202, v1101);	// L2415
  kernel296(v1102, v1169);	// L2416
  kernel107(v1100, v1101, v1169);	// L2417
  auto v1203 = reinterpret_cast<float(*)[12][64][64]>(v1014 + 17498112);
  kernel106(v1169, v1105, v1203);	// L2419
  kernel105(v1203, v1106);	// L2420
  kernel104(v1201, v1100);	// L2421
  kernel291(v1107, v1171);	// L2422
  kernel103(v1106, v1100, v1171);	// L2423
  kernel102(v1171, v1109);	// L2424
  auto v1204 = reinterpret_cast<float(*)[64][384]>(v1014 + 4521984);
  kernel8(v1204, v1072);	// L2426
  kernel19(v1072, (float)2.000000);	// L2427
  kernel12(v1072, v1204, v1112);	// L2428
  kernel98(v1109, v1072);	// L2429
  kernel19(v1072, (float)2.000000);	// L2430
  kernel7(v1072, v1112, v1144);	// L2431
  kernel8(v1144, v1072);	// L2432
  kernel16(v1072, (float)0.500000);	// L2433
  kernel8(v1072, v1112);	// L2434
  kernel14(v1112, (float)1.000000, (float)0.000000);	// L2435
  kernel13(v1144, v1112, v1072);	// L2436
  kernel12(v1072, v1144, v1145);	// L2437
  kernel8(v1112, v1072);	// L2438
  kernel10(v1072, (float)0.000000);	// L2439
  kernel9(v1145, v1072);	// L2440
  kernel8(v1072, v1204);	// L2441
  kernel47(v1112, v1072);	// L2442
  auto v1205 = reinterpret_cast<float(*)[384]>(v1016 + 29884416);
  kernel84(v1205, v1077);	// L2444
  kernel8(v1079, v1120);	// L2445
  kernel82(v1072, v1077, v1120);	// L2446
  auto v1206 = reinterpret_cast<float(*)>(v1016 + 72351744);
  kernel24(v1120, v1206, v1139);	// L2448
  auto v1207 = reinterpret_cast<float(*)[64][384]>(v1014 + 4718592);
  kernel8(v1207, v1072);	// L2450
  kernel19(v1072, (float)2.000000);	// L2451
  kernel12(v1072, v1207, v1112);	// L2452
  kernel8(v1139, v1072);	// L2453
  kernel19(v1072, (float)2.000000);	// L2454
  kernel7(v1072, v1112, v1144);	// L2455
  kernel8(v1144, v1072);	// L2456
  kernel16(v1072, (float)1.000000);	// L2457
  kernel8(v1072, v1112);	// L2458
  kernel14(v1112, (float)1.000000, (float)0.000000);	// L2459
  kernel13(v1144, v1112, v1072);	// L2460
  kernel12(v1072, v1144, v1145);	// L2461
  kernel8(v1112, v1072);	// L2462
  kernel10(v1072, (float)0.000000);	// L2463
  kernel9(v1145, v1072);	// L2464
  kernel8(v1072, v1207);	// L2465
  kernel7(v1112, v1143, v1144);	// L2466
  kernel55(v1070, v1176);	// L2467
  kernel56(v1144, v1176);	// L2468
  kernel55(v1176, v1071);	// L2469
  kernel54(v1071, (float)384.000000);	// L2470
  kernel51(v1071, v1072);	// L2471
  kernel12(v1072, v1144, v1112);	// L2472
  kernel50(v1112, v1072);	// L2473
  auto v1208 = reinterpret_cast<float(*)[64][1]>(v1014 + 16908288);
  kernel55(v1070, v1208);	// L2475
  kernel56(v1072, v1208);	// L2476
  kernel55(v1208, v1071);	// L2477
  kernel54(v1071, (float)384.000000);	// L2478
  kernel53(v1071, (float)0.000010);	// L2479
  kernel52(v1071);	// L2480
  kernel51(v1071, v1072);	// L2481
  kernel50(v1112, v1072);	// L2482
  auto v1209 = reinterpret_cast<float(*)>(v1016 + 71024640);
  kernel49(v1209, v1072);	// L2484
  auto v1210 = reinterpret_cast<float(*)>(v1016 + 69697536);
  kernel48(v1210, v1072, v1112);	// L2486
  kernel47(v1112, v1072);	// L2487
  auto v1211 = reinterpret_cast<float(*)[1536]>(v1016 + 28557312);
  kernel46(v1211, v1126);	// L2489
  kernel28(v1128, v1185);	// L2490
  kernel45(v1072, v1126, v1185);	// L2491
  auto v1212 = reinterpret_cast<float(*)>(v1016 + 68370432);
  kernel44(v1185, v1212, v1136);	// L2493
  auto v1213 = reinterpret_cast<float(*)[64][1536]>(v1014 + 4915200);
  kernel28(v1213, v1133);	// L2495
  kernel39(v1133, (float)2.000000);	// L2496
  kernel32(v1133, v1213, v1184);	// L2497
  kernel28(v1136, v1133);	// L2498
  kernel39(v1133, (float)2.000000);	// L2499
  auto v1214 = reinterpret_cast<float(*)[64][1536]>(v1016 + 16908288);
  kernel38(v1133, v1184, v1214);	// L2501
  kernel28(v1214, v1133);	// L2502
  kernel36(v1133, (float)1.000000);	// L2503
  kernel28(v1133, v1184);	// L2504
  kernel34(v1184, (float)1.000000, (float)0.000000);	// L2505
  kernel33(v1214, v1184, v1133);	// L2506
  auto v1215 = reinterpret_cast<float(*)[64][1536]>(v1015 + 17498112);
  kernel32(v1133, v1214, v1215);	// L2508
  kernel28(v1184, v1133);	// L2509
  kernel30(v1133, (float)0.000000);	// L2510
  kernel29(v1215, v1133);	// L2511
  kernel28(v1133, v1213);	// L2512
  kernel27(v1184, v1133);	// L2513
  auto v1216 = reinterpret_cast<float(*)[384]>(v1016 + 27230208);
  kernel26(v1216, v1137);	// L2515
  kernel8(v1079, v1120);	// L2516
  kernel25(v1133, v1137, v1120);	// L2517
  auto v1217 = reinterpret_cast<float(*)>(v1016 + 67043328);
  kernel24(v1120, v1217, v1146);	// L2519
  auto v1218 = reinterpret_cast<float(*)[64][384]>(v1014 + 5111808);
  kernel8(v1218, v1072);	// L2521
  kernel19(v1072, (float)2.000000);	// L2522
  kernel12(v1072, v1218, v1112);	// L2523
  kernel8(v1146, v1072);	// L2524
  kernel19(v1072, (float)2.000000);	// L2525
  kernel7(v1072, v1112, v1146);	// L2526
  kernel8(v1146, v1072);	// L2527
  kernel16(v1072, (float)1.000000);	// L2528
  kernel8(v1072, v1112);	// L2529
  kernel14(v1112, (float)1.000000, (float)0.000000);	// L2530
  kernel13(v1146, v1112, v1072);	// L2531
  kernel12(v1072, v1146, v1145);	// L2532
  kernel8(v1112, v1072);	// L2533
  kernel10(v1072, (float)0.000000);	// L2534
  kernel9(v1145, v1072);	// L2535
  kernel8(v1072, v1218);	// L2536
  kernel7(v1112, v1144, v1143);	// L2537
  kernel55(v1070, v1147);	// L2538
  kernel56(v1143, v1147);	// L2539
  kernel55(v1147, v1071);	// L2540
  kernel54(v1071, (float)384.000000);	// L2541
  kernel51(v1071, v1072);	// L2542
  kernel12(v1072, v1143, v1112);	// L2543
  kernel50(v1112, v1072);	// L2544
  kernel55(v1070, v1148);	// L2545
  kernel56(v1072, v1148);	// L2546
  kernel55(v1148, v1071);	// L2547
  kernel54(v1071, (float)384.000000);	// L2548
  kernel53(v1071, (float)0.000010);	// L2549
  kernel52(v1071);	// L2550
  kernel51(v1071, v1072);	// L2551
  kernel50(v1112, v1072);	// L2552
  auto v1219 = reinterpret_cast<float(*)>(v1016 + 65716224);
  kernel49(v1219, v1072);	// L2554
  auto v1220 = reinterpret_cast<float(*)>(v1016 + 64389120);
  kernel174(v1220, v1072);	// L2556
  kernel47(v1072, v1112);	// L2557
  auto v1221 = reinterpret_cast<float(*)[384]>(v1016 + 25903104);
  kernel84(v1221, v1077);	// L2559
  kernel8(v1079, v1139);	// L2560
  kernel82(v1112, v1077, v1139);	// L2561
  auto v1222 = reinterpret_cast<float(*)[64][384]>(v1014 + 17498112);
  auto v1223 = reinterpret_cast<float(*)>(v1016 + 63062016);
  kernel24(v1139, v1223, v1222);	// L2564
  auto v1224 = reinterpret_cast<float(*)[64][384]>(v1014 + 5308416);
  kernel8(v1224, v1072);	// L2566
  kernel19(v1072, (float)2.000000);	// L2567
  kernel12(v1072, v1224, v1139);	// L2568
  kernel8(v1222, v1072);	// L2569
  kernel19(v1072, (float)2.000000);	// L2570
  kernel7(v1072, v1139, v1145);	// L2571
  kernel8(v1145, v1072);	// L2572
  kernel16(v1072, (float)1.000000);	// L2573
  kernel8(v1072, v1152);	// L2574
  kernel14(v1152, (float)1.000000, (float)0.000000);	// L2575
  kernel13(v1145, v1152, v1072);	// L2576
  kernel12(v1072, v1145, v1161);	// L2577
  kernel8(v1152, v1072);	// L2578
  kernel10(v1072, (float)0.000000);	// L2579
  kernel9(v1161, v1072);	// L2580
  kernel8(v1072, v1224);	// L2581
  kernel111(v1152, v1157);	// L2582
  auto v1225 = reinterpret_cast<float(*)[384]>(v1016 + 24576000);
  kernel84(v1225, v1077);	// L2584
  kernel8(v1079, v1152);	// L2585
  kernel82(v1112, v1077, v1152);	// L2586
  auto v1226 = reinterpret_cast<float(*)>(v1016 + 61734912);
  kernel24(v1152, v1226, v1156);	// L2588
  auto v1227 = reinterpret_cast<float(*)[64][384]>(v1014 + 5505024);
  kernel8(v1227, v1072);	// L2590
  kernel19(v1072, (float)2.000000);	// L2591
  kernel12(v1072, v1227, v1139);	// L2592
  kernel8(v1156, v1072);	// L2593
  kernel19(v1072, (float)2.000000);	// L2594
  kernel7(v1072, v1139, v1156);	// L2595
  kernel8(v1156, v1072);	// L2596
  kernel16(v1072, (float)1.000000);	// L2597
  kernel8(v1072, v1144);	// L2598
  kernel14(v1144, (float)1.000000, (float)0.000000);	// L2599
  kernel13(v1156, v1144, v1072);	// L2600
  kernel12(v1072, v1156, v1162);	// L2601
  kernel8(v1144, v1072);	// L2602
  kernel10(v1072, (float)0.000000);	// L2603
  kernel9(v1162, v1072);	// L2604
  kernel8(v1072, v1227);	// L2605
  auto v1228 = reinterpret_cast<float(*)[384]>(v1016 + 23248896);
  kernel84(v1228, v1077);	// L2607
  kernel8(v1079, v1156);	// L2608
  kernel82(v1112, v1077, v1156);	// L2609
  auto v1229 = reinterpret_cast<float(*)>(v1016 + 60407808);
  kernel24(v1156, v1229, v1120);	// L2611
  auto v1230 = reinterpret_cast<float(*)[64][384]>(v1014 + 5701632);
  kernel8(v1230, v1072);	// L2613
  kernel19(v1072, (float)2.000000);	// L2614
  kernel12(v1072, v1230, v1156);	// L2615
  kernel8(v1120, v1072);	// L2616
  kernel19(v1072, (float)2.000000);	// L2617
  kernel7(v1072, v1156, v1112);	// L2618
  kernel8(v1112, v1072);	// L2619
  kernel16(v1072, (float)1.000000);	// L2620
  auto v1231 = reinterpret_cast<float(*)[64][384]>(v1014 + 18087936);
  kernel8(v1072, v1231);	// L2622
  kernel14(v1231, (float)1.000000, (float)0.000000);	// L2623
  kernel13(v1112, v1231, v1072);	// L2624
  kernel12(v1072, v1112, v1162);	// L2625
  kernel8(v1231, v1072);	// L2626
  kernel10(v1072, (float)0.000000);	// L2627
  kernel9(v1162, v1072);	// L2628
  kernel8(v1072, v1230);	// L2629
  kernel111(v1231, v1167);	// L2630
  kernel110(v1144, v1168);	// L2631
  kernel104(v1157, v1100);	// L2632
  kernel108(v1168, v1101);	// L2633
  kernel107(v1100, v1101, v1102);	// L2634
  auto v1232 = reinterpret_cast<float(*)[12][64][64]>(v1015 + 11010048);
  kernel106(v1102, v1105, v1232);	// L2636
  kernel105(v1232, v1106);	// L2637
  kernel104(v1167, v1100);	// L2638
  kernel103(v1106, v1100, v1107);	// L2639
  kernel102(v1107, v1109);	// L2640
  auto v1233 = reinterpret_cast<float(*)[64][384]>(v1014 + 5898240);
  kernel8(v1233, v1072);	// L2642
  kernel19(v1072, (float)2.000000);	// L2643
  kernel12(v1072, v1233, v1073);	// L2644
  kernel98(v1109, v1072);	// L2645
  kernel19(v1072, (float)2.000000);	// L2646
  kernel7(v1072, v1073, v1084);	// L2647
  kernel8(v1084, v1072);	// L2648
  kernel16(v1072, (float)0.500000);	// L2649
  auto v1234 = reinterpret_cast<float(*)[64][384]>(v1014 + 9240576);
  kernel8(v1072, v1234);	// L2651
  kernel14(v1234, (float)1.000000, (float)0.000000);	// L2652
  kernel13(v1084, v1234, v1072);	// L2653
  kernel12(v1072, v1084, v1085);	// L2654
  kernel8(v1234, v1072);	// L2655
  kernel10(v1072, (float)0.000000);	// L2656
  kernel9(v1085, v1072);	// L2657
  kernel8(v1072, v1233);	// L2658
  kernel47(v1234, v1072);	// L2659
  auto v1235 = reinterpret_cast<float(*)[384]>(v1016 + 21921792);
  kernel84(v1235, v1077);	// L2661
  kernel8(v1079, v1073);	// L2662
  kernel82(v1072, v1077, v1073);	// L2663
  auto v1236 = reinterpret_cast<float(*)[64][384]>(v1014 + 9830400);
  auto v1237 = reinterpret_cast<float(*)>(v1016 + 59080704);
  kernel24(v1073, v1237, v1236);	// L2666
  auto v1238 = reinterpret_cast<float(*)[64][384]>(v1014 + 6094848);
  kernel8(v1238, v1072);	// L2668
  kernel19(v1072, (float)2.000000);	// L2669
  auto v1239 = reinterpret_cast<float(*)[64][384]>(v1016 + 9240576);
  kernel12(v1072, v1238, v1239);	// L2671
  kernel8(v1236, v1072);	// L2672
  kernel19(v1072, (float)2.000000);	// L2673
  auto v1240 = reinterpret_cast<float(*)[64][384]>(v1015 + 9830400);
  kernel7(v1072, v1239, v1240);	// L2675
  kernel8(v1240, v1072);	// L2676
  kernel16(v1072, (float)1.000000);	// L2677
  kernel8(v1072, v1073);	// L2678
  kernel14(v1073, (float)1.000000, (float)0.000000);	// L2679
  kernel13(v1240, v1073, v1072);	// L2680
  kernel12(v1072, v1240, v1080);	// L2681
  kernel8(v1073, v1072);	// L2682
  kernel10(v1072, (float)0.000000);	// L2683
  kernel9(v1080, v1072);	// L2684
  kernel8(v1072, v1238);	// L2685
  kernel7(v1073, v1143, v1236);	// L2686
  auto v1241 = reinterpret_cast<float(*)[64][1]>(v1015 + 9240576);
  kernel55(v1070, v1241);	// L2688
  kernel56(v1236, v1241);	// L2689
  kernel55(v1241, v1071);	// L2690
  kernel54(v1071, (float)384.000000);	// L2691
  kernel51(v1071, v1072);	// L2692
  kernel12(v1072, v1236, v1073);	// L2693
  kernel50(v1073, v1072);	// L2694
  kernel56(v1072, v1070);	// L2695
  kernel55(v1070, v1071);	// L2696
  kernel54(v1071, (float)384.000000);	// L2697
  kernel53(v1071, (float)0.000010);	// L2698
  kernel52(v1071);	// L2699
  kernel51(v1071, v1072);	// L2700
  kernel50(v1073, v1072);	// L2701
  auto v1242 = reinterpret_cast<float(*)>(v1016 + 57753600);
  kernel49(v1242, v1072);	// L2703
  auto v1243 = reinterpret_cast<float(*)[64][384]>(v1015 + 7471104);
  auto v1244 = reinterpret_cast<float(*)>(v1016 + 56426496);
  kernel48(v1244, v1072, v1243);	// L2706
  kernel47(v1243, v1072);	// L2707
  auto v1245 = reinterpret_cast<float(*)[1536]>(v1016 + 20594688);
  kernel46(v1245, v1126);	// L2709
  kernel45(v1072, v1126, v1128);	// L2710
  auto v1246 = reinterpret_cast<float(*)[64][1536]>(v1015 + 6881280);
  auto v1247 = reinterpret_cast<float(*)>(v1016 + 55099392);
  kernel44(v1128, v1247, v1246);	// L2713
  auto v1248 = reinterpret_cast<float(*)[64][1536]>(v1014 + 6291456);
  kernel28(v1248, v1133);	// L2715
  kernel39(v1133, (float)2.000000);	// L2716
  auto v1249 = reinterpret_cast<float(*)[64][1536]>(v1015 + 7471104);
  kernel32(v1133, v1248, v1249);	// L2718
  kernel28(v1246, v1133);	// L2719
  kernel39(v1133, (float)2.000000);	// L2720
  auto v1250 = reinterpret_cast<float(*)[64][1536]>(v1016 + 6881280);
  kernel38(v1133, v1249, v1250);	// L2722
  kernel28(v1250, v1133);	// L2723
  kernel36(v1133, (float)1.000000);	// L2724
  kernel28(v1133, v1249);	// L2725
  kernel34(v1249, (float)1.000000, (float)0.000000);	// L2726
  kernel33(v1250, v1249, v1133);	// L2727
  auto v1251 = reinterpret_cast<float(*)[64][1536]>(v1015 + 8060928);
  kernel32(v1133, v1250, v1251);	// L2729
  kernel28(v1249, v1133);	// L2730
  kernel30(v1133, (float)0.000000);	// L2731
  kernel29(v1251, v1133);	// L2732
  kernel28(v1133, v1248);	// L2733
  kernel27(v1249, v1133);	// L2734
  auto v1252 = reinterpret_cast<float(*)[384]>(v1016 + 19267584);
  kernel26(v1252, v1137);	// L2736
  kernel25(v1133, v1137, v1079);	// L2737
  auto v1253 = reinterpret_cast<float(*)>(v1016 + 53772288);
  kernel24(v1079, v1253, v1122);	// L2739
  auto v1254 = reinterpret_cast<float(*)[64][384]>(v1014 + 6488064);
  kernel8(v1254, v1072);	// L2741
  kernel19(v1072, (float)2.000000);	// L2742
  kernel12(v1072, v1254, v1243);	// L2743
  kernel8(v1122, v1072);	// L2744
  kernel19(v1072, (float)2.000000);	// L2745
  auto v1255 = reinterpret_cast<float(*)[64][384]>(v1016 + 6881280);
  kernel7(v1072, v1243, v1255);	// L2747
  kernel8(v1255, v1072);	// L2748
  kernel16(v1072, (float)1.000000);	// L2749
  auto v1256 = reinterpret_cast<float(*)[64][384]>(v1014 + 7471104);
  kernel8(v1072, v1256);	// L2751
  kernel14(v1256, (float)1.000000, (float)0.000000);	// L2752
  kernel13(v1255, v1256, v1072);	// L2753
  auto v1257 = reinterpret_cast<float(*)[64][384]>(v1015 + 8060928);
  kernel12(v1072, v1255, v1257);	// L2755
  kernel8(v1256, v1072);	// L2756
  kernel10(v1072, (float)0.000000);	// L2757
  kernel9(v1257, v1072);	// L2758
  kernel8(v1072, v1254);	// L2759
  kernel7(v1256, v1236, v1072);	// L2760
  auto v1258 = reinterpret_cast<float(*)[384]>(v1015 + 6881280);
  kernel6(v1258, (float)0.000000);	// L2762
  kernel5(v1072, v1258);	// L2763
  kernel4(v1258, (float)64.000000);	// L2764
  auto v1259 = reinterpret_cast<float(*)[10]>(v1014 + 7471104);
  auto v1260 = reinterpret_cast<float(*)[384]>(v1016 + 52445184);
  kernel3(v1260, v1259);	// L2767
  auto v1261 = reinterpret_cast<float(*)[10]>(v1014 + 6684672);
  kernel2(v1261, (float)0.000000);	// L2769
  kernel1(v1258, v1259, v1261);	// L2770
  auto v1262 = reinterpret_cast<float(*)>(v1016 + 51118080);
  kernel0(v1262, v1261);	// L2772
}

