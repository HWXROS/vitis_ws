
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
  float v2[10];	// L3
  #pragma HLS resource variable=v2 core=ram_t2p_bram

  memcpy(v2, v0, 10 * sizeof(float));	// L4

  float v3[1][10];	// L5
  #pragma HLS resource variable=v3 core=ram_t2p_bram

  memcpy(v3, v1, 10 * sizeof(float));	// L6

  for (int v4 = 0; v4 < 10; v4 += 1) {	// L7
    #pragma HLS pipeline II=1
    #pragma HLS dependence false variable=v3
    #pragma HLS dependence false variable=v2
    float v5 = v3[0][v4];	// L8
    float v6 = v2[v4];	// L9
    float v7 = v5 + v6;	// L10
    v3[0][v4] = v7;	// L11
  }
  memcpy(v1, v3, 10 * sizeof(float));	// L13

}

void kernel1(
  float v8[1][384],
  float v9[384][10],
  float v10[1][10]
) {	// L16
  float v11[1][10];	// L17
  #pragma HLS resource variable=v11 core=ram_t2p_bram

  memcpy(v11, v10, 10 * sizeof(float));	// L18

  float v12[1][384];	// L19
  #pragma HLS resource variable=v12 core=ram_t2p_bram

  memcpy(v12, v8, 384 * sizeof(float));	// L20

  for (int v13 = 0; v13 < 384; v13 += 1) {	// L21
    for (int v14 = 0; v14 < 10; v14 += 1) {	// L22
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v12
      #pragma HLS dependence false variable=v9
      #pragma HLS dependence false variable=v11
      float v15 = v12[0][v13];	// L23
      float v16 = v9[v13][v14];	// L24
      float v17 = v11[0][v14];	// L25
      float v18 = v15 * v16;	// L26
      float v19 = v17 + v18;	// L27
      v11[0][v14] = v19;	// L28
    }
  }
  memcpy(v10, v11, 10 * sizeof(float));	// L31

}

void kernel2(
  float v20[1][10],
  float v21
) {	// L34
  float v22[1][10];	// L35
  #pragma HLS resource variable=v22 core=ram_t2p_bram

  for (int v23 = 0; v23 < 10; v23 += 1) {	// L36
    #pragma HLS pipeline II=1
    #pragma HLS dependence false variable=v22
    v22[0][v23] = v21;	// L37
  }
  memcpy(v20, v22, 10 * sizeof(float));	// L39

}

void kernel3(
  float v24[1][384],
  float v25
) {	// L42
  float v26[1][384];	// L43
  #pragma HLS resource variable=v26 core=ram_t2p_bram

  memcpy(v26, v24, 384 * sizeof(float));	// L44

  for (int v27 = 0; v27 < 384; v27 += 1) {	// L45
    #pragma HLS pipeline II=1
    #pragma HLS dependence false variable=v26
    float v28 = v26[0][v27];	// L46
    float v29 = v28 / v25;	// L47
    v26[0][v27] = v29;	// L48
  }
  memcpy(v24, v26, 384 * sizeof(float));	// L50

}

void kernel4(
  float v30[1][384][8][8],
  float v31[1][384]
) {	// L53
  float v32[1][384];	// L54
  #pragma HLS resource variable=v32 core=ram_t2p_bram

  memcpy(v32, v31, 384 * sizeof(float));	// L55

  for (int v33 = 0; v33 < 64; v33 += 1) {	// L56
    for (int v34 = 0; v34 < 384; v34 += 1) {	// L57
      float v35 = v30[0][v34][(v33 / 8)][(v33 % 8)];	// L58
      float v36 = v32[0][v34];	// L59
      float v37 = v35 + v36;	// L60
      v32[0][v34] = v37;	// L61
    }
  }
  memcpy(v31, v32, 384 * sizeof(float));	// L64

}

void kernel5(
  float v38[1][384],
  float v39
) {	// L67
  float v40[1][384];	// L68
  #pragma HLS resource variable=v40 core=ram_t2p_bram

  for (int v41 = 0; v41 < 384; v41 += 1) {	// L69
    #pragma HLS pipeline II=1
    #pragma HLS dependence false variable=v40
    v40[0][v41] = v39;	// L70
  }
  memcpy(v38, v40, 384 * sizeof(float));	// L72

}

void kernel6(
  float v42[1][384][8][8],
  float v43[1][384][8][8]
) {	// L75
  for (int v44 = 0; v44 < 384; v44 += 1) {	// L76
    for (int v45 = 0; v45 < 8; v45 += 1) {	// L77
      for (int v46 = 0; v46 < 8; v46 += 1) {	// L78
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v42
        #pragma HLS dependence false variable=v43
        float v47 = v42[0][v44][v45][v46];	// L79
        float v48 = v43[0][v44][v45][v46];	// L80
        float v49 = v47 + v48;	// L81
        v43[0][v44][v45][v46] = v49;	// L82
      }
    }
  }
}

void kernel7(
  float v50[1][1536][8][8],
  float v51[384][1536][1][1],
  float v52[1][384][8][8]
) {	// L88
  float v53[1][384][8][8];	// L89
  #pragma HLS resource variable=v53 core=ram_t2p_bram

  memcpy(v53, v52, 24576 * sizeof(float));	// L90

  auto v54 = reinterpret_cast<float(*)[1536][1][1]>(v51);	// L92

  for (int v55 = 0; v55 < 1536; v55 += 1) {	// L93
    for (int v56 = 0; v56 < 384; v56 += 1) {	// L94
      float v57 = v54[v56][v55][0][0];	// L95
      for (int v58 = 0; v58 < 8; v58 += 1) {	// L96
        for (int v59 = 0; v59 < 8; v59 += 1) {	// L97
          #pragma HLS pipeline II=1
          #pragma HLS dependence false variable=v50
          #pragma HLS dependence false variable=v53
          float v60 = v50[0][v55][v58][v59];	// L98
          float v61 = v53[0][v56][v58][v59];	// L99
          float v62 = v60 * v57;	// L100
          float v63 = v61 + v62;	// L101
          v53[0][v56][v58][v59] = v63;	// L102
        }
      }
    }
  }
  memcpy(v52, v53, 24576 * sizeof(float));	// L107

}

void kernel8(
  float v64[384],
  float v65[1][384][8][8]
) {	// L110
  float v66[384];	// L111
  #pragma HLS resource variable=v66 core=ram_t2p_bram

  memcpy(v66, v64, 384 * sizeof(float));	// L112

  for (int v67 = 0; v67 < 384; v67 += 1) {	// L113
    for (int v68 = 0; v68 < 8; v68 += 1) {	// L114
      for (int v69 = 0; v69 < 8; v69 += 1) {	// L115
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v66
        #pragma HLS dependence false variable=v65
        float v70 = v66[v67];	// L116
        v65[0][v67][v68][v69] = v70;	// L117
      }
    }
  }
}

void kernel9(
  float v71[1][1536][8][8],
  float v72[1][1536][8][8]
) {	// L123
  for (int v73 = 0; v73 < 1536; v73 += 1) {	// L124
    for (int v74 = 0; v74 < 8; v74 += 1) {	// L125
      for (int v75 = 0; v75 < 8; v75 += 1) {	// L126
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v71
        #pragma HLS dependence false variable=v72
        float v76 = v71[0][v73][v74][v75];	// L127
        v72[0][v73][v74][v75] = v76;	// L128
      }
    }
  }
}

void kernel10(
  float v77[1][1536][8][8],
  float v78[1][1536][8][8],
  float v79
) {	// L134
  for (int v80 = 0; v80 < 1536; v80 += 1) {	// L135
    for (int v81 = 0; v81 < 8; v81 += 1) {	// L136
      for (int v82 = 0; v82 < 8; v82 += 1) {	// L137
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v78
        #pragma HLS dependence false variable=v77
        float v83 = v78[0][v80][v81][v82];	// L138
        float v84 = v77[0][v80][v81][v82];	// L139
        float v85 = v84 * v79;	// L140
        float v86 = v84 * v83;	// L141
        float v87 = v83 - v86;	// L142
        float v88 = v87 + v85;	// L143
        v78[0][v80][v81][v82] = v88;	// L144
      }
    }
  }
}

void kernel11(
  float v89[1][1536][8][8],
  float v90,
  float v91
) {	// L150
  for (int v92 = 0; v92 < 1536; v92 += 1) {	// L151
    for (int v93 = 0; v93 < 8; v93 += 1) {	// L152
      for (int v94 = 0; v94 < 8; v94 += 1) {	// L153
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v89
        float v95 = v89[0][v92][v93][v94];	// L154
        float v96 = v95 - v91;	// L155
        bool v97 = v96 >= v90;	// L156
        float v98 = v97 ? v91 : v90;	// L157
        v89[0][v92][v93][v94] = v98;	// L158
      }
    }
  }
}

void kernel13(
  float v99[1][1536][8][8],
  float v100[1][1536][8][8],
  float v101
) {	// L164
  for (int v102 = 0; v102 < 1536; v102 += 1) {	// L165
    for (int v103 = 0; v103 < 8; v103 += 1) {	// L166
      for (int v104 = 0; v104 < 8; v104 += 1) {	// L167
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v99
        #pragma HLS dependence false variable=v100
        float v105 = v99[0][v102][v103][v104];	// L168
        float v106 = v100[0][v102][v103][v104];	// L169
        float v107 = v106 / v101;	// L170
        float v108 = v105 / v101;	// L171
        float v109 = v105 - v108;	// L172
        float v110 = v109 + v107;	// L173
        v100[0][v102][v103][v104] = v110;	// L174
      }
    }
  }
}

void kernel14(
  float v111[1][384][8][8],
  float v112[1536][384][1][1],
  float v113[1][1536][8][8]
) {	// L180
  float v114[1][384][8][8];	// L181
  #pragma HLS resource variable=v114 core=ram_t2p_bram

  memcpy(v114, v111, 24576 * sizeof(float));	// L182

  auto v115 = reinterpret_cast<float(*)[384][1][1]>(v112);	// L184

  for (int v116 = 0; v116 < 384; v116 += 1) {	// L185
    for (int v117 = 0; v117 < 1536; v117 += 1) {	// L186
      float v118 = v115[v117][v116][0][0];	// L187
      for (int v119 = 0; v119 < 8; v119 += 1) {	// L188
        for (int v120 = 0; v120 < 8; v120 += 1) {	// L189
          #pragma HLS pipeline II=1
          #pragma HLS dependence false variable=v114
          #pragma HLS dependence false variable=v113
          float v121 = v114[0][v116][v119][v120];	// L190
          float v122 = v113[0][v117][v119][v120];	// L191
          float v123 = v121 * v118;	// L192
          float v124 = v122 + v123;	// L193
          v113[0][v117][v119][v120] = v124;	// L194
        }
      }
    }
  }
}

void kernel15(
  float v125[1536],
  float v126[1][1536][8][8]
) {	// L201
  float v127[1536];	// L202
  #pragma HLS resource variable=v127 core=ram_t2p_bram

  memcpy(v127, v125, 1536 * sizeof(float));	// L203

  for (int v128 = 0; v128 < 1536; v128 += 1) {	// L204
    for (int v129 = 0; v129 < 8; v129 += 1) {	// L205
      for (int v130 = 0; v130 < 8; v130 += 1) {	// L206
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v127
        #pragma HLS dependence false variable=v126
        float v131 = v127[v128];	// L207
        v126[0][v128][v129][v130] = v131;	// L208
      }
    }
  }
}

void kernel16(
  float v132[1][384][8][8],
  float v133[1][384][8][8]
) {	// L214
  for (int v134 = 0; v134 < 384; v134 += 1) {	// L215
    for (int v135 = 0; v135 < 8; v135 += 1) {	// L216
      for (int v136 = 0; v136 < 8; v136 += 1) {	// L217
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v132
        #pragma HLS dependence false variable=v133
        float v137 = v132[0][v134][v135][v136];	// L218
        v133[0][v134][v135][v136] = v137;	// L219
      }
    }
  }
}

void kernel17(
  float v138[1][384][8][8],
  float v139[1][384][8][8],
  float v140
) {	// L225
  for (int v141 = 0; v141 < 384; v141 += 1) {	// L226
    for (int v142 = 0; v142 < 8; v142 += 1) {	// L227
      for (int v143 = 0; v143 < 8; v143 += 1) {	// L228
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v139
        #pragma HLS dependence false variable=v138
        float v144 = v139[0][v141][v142][v143];	// L229
        float v145 = v138[0][v141][v142][v143];	// L230
        float v146 = v145 * v140;	// L231
        float v147 = v145 * v144;	// L232
        float v148 = v144 - v147;	// L233
        float v149 = v148 + v146;	// L234
        v139[0][v141][v142][v143] = v149;	// L235
      }
    }
  }
}

void kernel18(
  float v150[1][384][8][8],
  float v151,
  float v152
) {	// L241
  for (int v153 = 0; v153 < 384; v153 += 1) {	// L242
    for (int v154 = 0; v154 < 8; v154 += 1) {	// L243
      for (int v155 = 0; v155 < 8; v155 += 1) {	// L244
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v150
        float v156 = v150[0][v153][v154][v155];	// L245
        float v157 = v156 - v152;	// L246
        bool v158 = v157 >= v151;	// L247
        float v159 = v158 ? v152 : v151;	// L248
        v150[0][v153][v154][v155] = v159;	// L249
      }
    }
  }
}

void kernel20(
  float v160[1][384][8][8],
  float v161[1][384][8][8],
  float v162[1][384][8][8],
  float v163
) {	// L255
  for (int v164 = 0; v164 < 384; v164 += 1) {	// L256
    for (int v165 = 0; v165 < 8; v165 += 1) {	// L257
      for (int v166 = 0; v166 < 8; v166 += 1) {	// L258
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v160
        #pragma HLS dependence false variable=v162
        #pragma HLS dependence false variable=v161
        float v167 = v160[0][v164][v165][v166];	// L259
        float v168 = v161[0][v164][v165][v166];	// L260
        float v169 = v168 / v163;	// L261
        float v170 = v167 / v163;	// L262
        float v171 = v167 - v170;	// L263
        float v172 = v171 + v169;	// L264
        v162[0][v164][v165][v166] = v172;	// L265
      }
    }
  }
}

void kernel21(
  float v173[1][384][64],
  float v174[1][384][8][8],
  float v175[1][384][8][8]
) {	// L271
  for (int v176 = 0; v176 < 384; v176 += 1) {	// L272
    for (int v177 = 0; v177 < 8; v177 += 1) {	// L273
      for (int v178 = 0; v178 < 8; v178 += 1) {	// L274
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v174
        #pragma HLS dependence false variable=v175
        #pragma HLS dependence false variable=v173
        float v179 = v174[0][v176][v177][v178];	// L275
        float v180 = v173[0][v176][((v177 * 8) + v178)];	// L276
        float v181 = v179 + v180;	// L277
        v175[0][v176][v177][v178] = v181;	// L278
      }
    }
  }
}

void kernel22(
  float v182[1][384][64],
  float v183[384][384][1],
  float v184[1][384][64]
) {	// L284
  float v185[1][384][64];	// L285
  #pragma HLS resource variable=v185 core=ram_t2p_bram

  memcpy(v185, v182, 24576 * sizeof(float));	// L286

  float v186[1][384][64];	// L287
  #pragma HLS resource variable=v186 core=ram_t2p_bram

  memcpy(v186, v184, 24576 * sizeof(float));	// L288

  auto v187 = reinterpret_cast<float(*)[384][1]>(v183);	// L290

  for (int v188 = 0; v188 < 384; v188 += 1) {	// L291
    for (int v189 = 0; v189 < 384; v189 += 1) {	// L292
      float v190 = v187[v189][v188][0];	// L293
      for (int v191 = 0; v191 < 64; v191 += 1) {	// L294
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v185
        #pragma HLS dependence false variable=v186
        float v192 = v185[0][v188][v191];	// L295
        float v193 = v186[0][v189][v191];	// L296
        float v194 = v192 * v190;	// L297
        float v195 = v193 + v194;	// L298
        v186[0][v189][v191] = v195;	// L299
      }
    }
  }
  memcpy(v184, v186, 24576 * sizeof(float));	// L303

}

void kernel23(
  float v196[384],
  float v197[1][384][64]
) {	// L306
  float v198[384];	// L307
  #pragma HLS resource variable=v198 core=ram_t2p_bram

  memcpy(v198, v196, 384 * sizeof(float));	// L308

  for (int v199 = 0; v199 < 384; v199 += 1) {	// L309
    for (int v200 = 0; v200 < 64; v200 += 1) {	// L310
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v198
      #pragma HLS dependence false variable=v197
      float v201 = v198[v199];	// L311
      v197[0][v199][v200] = v201;	// L312
    }
  }
}

void kernel24(
  float v202[1][64][384],
  float v203[1][384][64]
) {	// L317
  for (int v204 = 0; v204 < 384; v204 += 1) {	// L318
    for (int v205 = 0; v205 < 64; v205 += 1) {	// L319
      float v206 = v202[0][v205][v204];	// L320
      v203[0][v204][v205] = v206;	// L321
    }
  }
}

void kernel25(
  float v207[1][64][384],
  float v208[1][64][384]
) {	// L326
  for (int v209 = 0; v209 < 64; v209 += 1) {	// L327
    for (int v210 = 0; v210 < 384; v210 += 1) {	// L328
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v207
      #pragma HLS dependence false variable=v208
      float v211 = v207[0][v209][v210];	// L329
      v208[0][v209][v210] = v211;	// L330
    }
  }
}

void kernel26(
  float v212[1][64][12][32],
  float v213[1][64][384],
  float v214[1][64][384],
  float v215
) {	// L335
  for (int v216 = 0; v216 < 64; v216 += 1) {	// L336
    for (int v217 = 0; v217 < 384; v217 += 1) {	// L337
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v212
      #pragma HLS dependence false variable=v214
      #pragma HLS dependence false variable=v213
      float v218 = v212[0][v216][(v217 / 32)][(v217 % 32)];	// L338
      float v219 = v213[0][v216][v217];	// L339
      float v220 = v219 * v215;	// L340
      float v221 = v219 * v218;	// L341
      float v222 = v218 - v221;	// L342
      float v223 = v222 + v220;	// L343
      v214[0][v216][v217] = v223;	// L344
    }
  }
}

void kernel27(
  float v224[1][64][384],
  float v225,
  float v226,
  float v227
) {	// L349
  for (int v228 = 0; v228 < 64; v228 += 1) {	// L350
    for (int v229 = 0; v229 < 384; v229 += 1) {	// L351
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v224
      float v230 = v224[0][v228][v229];	// L352
      float v231 = v230 - v226;	// L353
      bool v232 = v231 >= v227;	// L354
      float v233 = v232 ? v225 : v227;	// L355
      v224[0][v228][v229] = v233;	// L356
    }
  }
}

void kernel28(
  float v234[1][64][12][32],
  float v235[1][64][384]
) {	// L361
  for (int v236 = 0; v236 < 64; v236 += 1) {	// L362
    for (int v237 = 0; v237 < 384; v237 += 1) {	// L363
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v234
      #pragma HLS dependence false variable=v235
      float v238 = v234[0][v236][(v237 / 32)][(v237 % 32)];	// L364
      v235[0][v236][v237] = v238;	// L365
    }
  }
}

void kernel29(
  float v239[1][64][384],
  float v240[1][64][12][32],
  float v241[1][64][12][32],
  float v242
) {	// L370
  for (int v243 = 0; v243 < 64; v243 += 1) {	// L371
    for (int v244 = 0; v244 < 12; v244 += 1) {	// L372
      for (int v245 = 0; v245 < 32; v245 += 1) {	// L373
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v239
        #pragma HLS dependence false variable=v241
        #pragma HLS dependence false variable=v240
        float v246 = v239[0][v243][((v244 * 32) + v245)];	// L374
        float v247 = v240[0][v243][v244][v245];	// L375
        float v248 = v247 / v242;	// L376
        float v249 = v246 / v242;	// L377
        float v250 = v246 - v249;	// L378
        float v251 = v250 + v248;	// L379
        v241[0][v243][v244][v245] = v251;	// L380
      }
    }
  }
}

void kernel30(
  float v252[1][12][64][32],
  float v253[1][64][12][32]
) {	// L386
  for (int v254 = 0; v254 < 64; v254 += 1) {	// L387
    for (int v255 = 0; v255 < 12; v255 += 1) {	// L388
      for (int v256 = 0; v256 < 32; v256 += 1) {	// L389
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v252
        #pragma HLS dependence false variable=v253
        float v257 = v252[0][v255][v254][v256];	// L390
        v253[0][v254][v255][v256] = v257;	// L391
      }
    }
  }
}

void kernel31(
  float v258[1][12][64][32],
  float v259
) {	// L397
  for (int v260 = 0; v260 < 12; v260 += 1) {	// L398
    for (int v261 = 0; v261 < 64; v261 += 1) {	// L399
      for (int v262 = 0; v262 < 32; v262 += 1) {	// L400
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v258
        float v263 = v258[0][v260][v261][v262];	// L401
        float v264 = v263 * v259;	// L402
        v258[0][v260][v261][v262] = v264;	// L403
      }
    }
  }
}

void kernel32(
  float v265[12][64][32],
  float v266[1][12][64][32]
) {	// L409
  for (int v267 = 0; v267 < 12; v267 += 1) {	// L410
    for (int v268 = 0; v268 < 64; v268 += 1) {	// L411
      for (int v269 = 0; v269 < 32; v269 += 1) {	// L412
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v265
        #pragma HLS dependence false variable=v266
        float v270 = v265[v267][v268][v269];	// L413
        v266[0][v267][v268][v269] = v270;	// L414
      }
    }
  }
}

void kernel33(
  float v271[1][1][12][64][32],
  float v272[12][64][64],
  float v273[12][64][32]
) {	// L420
  float v274[12][64][32];	// L421
  #pragma HLS resource variable=v274 core=ram_t2p_bram

  memcpy(v274, v273, 24576 * sizeof(float));	// L422

  auto v275 = reinterpret_cast<float(*)[64][64]>(v272);	// L424

  for (int v276 = 0; v276 < 64; v276 += 1) {	// L425
    for (int v277 = 0; v277 < 12; v277 += 1) {	// L426
      for (int v278 = 0; v278 < 64; v278 += 1) {	// L427
        float v279 = v275[v277][v278][v276];	// L428
        for (int v280 = 0; v280 < 32; v280 += 1) {	// L429
          #pragma HLS pipeline II=1
          #pragma HLS dependence false variable=v271
          #pragma HLS dependence false variable=v274
          float v281 = v271[0][0][v277][v276][v280];	// L430
          float v282 = v274[v277][v278][v280];	// L431
          float v283 = v279 * v281;	// L432
          float v284 = v282 + v283;	// L433
          v274[v277][v278][v280] = v284;	// L434
        }
      }
    }
  }
  memcpy(v273, v274, 24576 * sizeof(float));	// L439

}

void kernel34(
  float v285[12][64][32],
  float v286
) {	// L442
  for (int v287 = 0; v287 < 12; v287 += 1) {	// L443
    for (int v288 = 0; v288 < 64; v288 += 1) {	// L444
      for (int v289 = 0; v289 < 32; v289 += 1) {	// L445
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v285
        v285[v287][v288][v289] = v286;	// L446
      }
    }
  }
}

void kernel35(
  float v290[1][12][64][32],
  float v291[1][1][12][64][32]
) {	// L452
  for (int v292 = 0; v292 < 12; v292 += 1) {	// L453
    for (int v293 = 0; v293 < 64; v293 += 1) {	// L454
      for (int v294 = 0; v294 < 32; v294 += 1) {	// L455
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v290
        #pragma HLS dependence false variable=v291
        float v295 = v290[0][v292][v293][v294];	// L456
        v291[0][0][v292][v293][v294] = v295;	// L457
      }
    }
  }
}

void kernel36(
  float v296[1][1][12][64][32],
  float v297[1][1][12][32][64],
  float v298[12][64][64]
) {	// L463
  auto v299 = reinterpret_cast<float(*)[1][12][64][32]>(v296);	// L465

  for (int v300 = 0; v300 < 32; v300 += 1) {	// L466
    for (int v301 = 0; v301 < 12; v301 += 1) {	// L467
      for (int v302 = 0; v302 < 64; v302 += 1) {	// L468
        float v303 = v299[0][0][v301][v302][v300];	// L469
        for (int v304 = 0; v304 < 64; v304 += 1) {	// L470
          #pragma HLS pipeline II=1
          #pragma HLS dependence false variable=v297
          #pragma HLS dependence false variable=v298
          float v305 = v297[0][0][v301][v300][v304];	// L471
          float v306 = v298[v301][v302][v304];	// L472
          float v307 = v303 * v305;	// L473
          float v308 = v306 + v307;	// L474
          v298[v301][v302][v304] = v308;	// L475
        }
      }
    }
  }
}

void kernel37(
  float v309[1][12][32][64],
  float v310[1][1][12][32][64]
) {	// L482
  for (int v311 = 0; v311 < 12; v311 += 1) {	// L483
    for (int v312 = 0; v312 < 32; v312 += 1) {	// L484
      for (int v313 = 0; v313 < 64; v313 += 1) {	// L485
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v309
        #pragma HLS dependence false variable=v310
        float v314 = v309[0][v311][v312][v313];	// L486
        v310[0][0][v311][v312][v313] = v314;	// L487
      }
    }
  }
}

void kernel39(
  float v315[1][64][12][32],
  float v316[1][12][32][64]
) {	// L493
  for (int v317 = 0; v317 < 12; v317 += 1) {	// L494
    for (int v318 = 0; v318 < 32; v318 += 1) {	// L495
      for (int v319 = 0; v319 < 64; v319 += 1) {	// L496
        float v320 = v315[0][v319][v317][v318];	// L497
        v316[0][v317][v318][v319] = v320;	// L498
      }
    }
  }
}

void kernel40(
  float v321[1][64][12][32],
  float v322[1][12][64][32]
) {	// L504
  for (int v323 = 0; v323 < 12; v323 += 1) {	// L505
    for (int v324 = 0; v324 < 64; v324 += 1) {	// L506
      for (int v325 = 0; v325 < 32; v325 += 1) {	// L507
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v321
        #pragma HLS dependence false variable=v322
        float v326 = v321[0][v324][v323][v325];	// L508
        v322[0][v323][v324][v325] = v326;	// L509
      }
    }
  }
}

void kernel41(
  float v327[1][384][64],
  float v328[1][64][12][32]
) {	// L515
  for (int v329 = 0; v329 < 64; v329 += 1) {	// L516
    for (int v330 = 0; v330 < 12; v330 += 1) {	// L517
      for (int v331 = 0; v331 < 32; v331 += 1) {	// L518
        float v332 = v327[0][((v330 * 32) + v331)][v329];	// L519
        v328[0][v329][v330][v331] = v332;	// L520
      }
    }
  }
}

void kernel42(
  float v333[1][384][64],
  float v334[1][384][64]
) {	// L526
  for (int v335 = 0; v335 < 384; v335 += 1) {	// L527
    for (int v336 = 0; v336 < 64; v336 += 1) {	// L528
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v333
      #pragma HLS dependence false variable=v334
      float v337 = v333[0][v335][v336];	// L529
      v334[0][v335][v336] = v337;	// L530
    }
  }
}

void kernel43(
  float v338[1][384][64],
  float v339[1][384][64],
  float v340
) {	// L535
  for (int v341 = 0; v341 < 384; v341 += 1) {	// L536
    for (int v342 = 0; v342 < 64; v342 += 1) {	// L537
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v339
      #pragma HLS dependence false variable=v338
      float v343 = v339[0][v341][v342];	// L538
      float v344 = v338[0][v341][v342];	// L539
      float v345 = v344 * v340;	// L540
      float v346 = v344 * v343;	// L541
      float v347 = v343 - v346;	// L542
      float v348 = v347 + v345;	// L543
      v339[0][v341][v342] = v348;	// L544
    }
  }
}

void kernel44(
  float v349[1][384][64],
  float v350,
  float v351
) {	// L549
  for (int v352 = 0; v352 < 384; v352 += 1) {	// L550
    for (int v353 = 0; v353 < 64; v353 += 1) {	// L551
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v349
      float v354 = v349[0][v352][v353];	// L552
      float v355 = v354 - v351;	// L553
      bool v356 = v355 >= v350;	// L554
      float v357 = v356 ? v351 : v350;	// L555
      v349[0][v352][v353] = v357;	// L556
    }
  }
}

void kernel46(
  float v358[1][384][64],
  float v359[1][384][64],
  float v360
) {	// L561
  for (int v361 = 0; v361 < 384; v361 += 1) {	// L562
    for (int v362 = 0; v362 < 64; v362 += 1) {	// L563
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v358
      #pragma HLS dependence false variable=v359
      float v363 = v358[0][v361][v362];	// L564
      float v364 = v359[0][v361][v362];	// L565
      float v365 = v364 / v360;	// L566
      float v366 = v363 / v360;	// L567
      float v367 = v363 - v366;	// L568
      float v368 = v367 + v365;	// L569
      v359[0][v361][v362] = v368;	// L570
    }
  }
}

void kernel47(
  float v369[1][384][8][8],
  float v370[384][384][1],
  float v371[1][384][64]
) {	// L575
  float v372[1][384][8][8];	// L576
  #pragma HLS resource variable=v372 core=ram_t2p_bram

  memcpy(v372, v369, 24576 * sizeof(float));	// L577

  float v373[1][384][64];	// L578
  #pragma HLS resource variable=v373 core=ram_t2p_bram

  memcpy(v373, v371, 24576 * sizeof(float));	// L579

  auto v374 = reinterpret_cast<float(*)[384][1]>(v370);	// L581

  for (int v375 = 0; v375 < 384; v375 += 1) {	// L582
    for (int v376 = 0; v376 < 384; v376 += 1) {	// L583
      float v377 = v374[v376][v375][0];	// L584
      for (int v378 = 0; v378 < 64; v378 += 1) {	// L585
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v372
        #pragma HLS dependence false variable=v373
        float v379 = v372[0][v375][(v378 / 8)][(v378 % 8)];	// L586
        float v380 = v373[0][v376][v378];	// L587
        float v381 = v379 * v377;	// L588
        float v382 = v380 + v381;	// L589
        v373[0][v376][v378] = v382;	// L590
      }
    }
  }
  memcpy(v371, v373, 24576 * sizeof(float));	// L594

}

void kernel71(
  float v383[1][384][8][8],
  float v384[1][384][8][8],
  float v385[1][384][8][8]
) {	// L597
  for (int v386 = 0; v386 < 384; v386 += 1) {	// L598
    for (int v387 = 0; v387 < 8; v387 += 1) {	// L599
      for (int v388 = 0; v388 < 8; v388 += 1) {	// L600
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v384
        #pragma HLS dependence false variable=v385
        #pragma HLS dependence false variable=v383
        float v389 = v384[0][v386][v387][v388];	// L601
        float v390 = v383[0][v386][v387][v388];	// L602
        float v391 = v389 + v390;	// L603
        v385[0][v386][v387][v388] = v391;	// L604
      }
    }
  }
}

void kernel99(
  float v392[12][64][32],
  float v393
) {	// L610
  for (int v394 = 0; v394 < 12; v394 += 1) {	// L611
    for (int v395 = 0; v395 < 64; v395 += 1) {	// L612
      for (int v396 = 0; v396 < 32; v396 += 1) {	// L613
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v392
        v392[v394][v395][v396] = v393;	// L614
      }
    }
  }
}

void kernel102(
  float v397[12][64][64],
  float v398[12][64][64]
) {	// L620
  for (int v399 = 0; v399 < 12; v399 += 1) {	// L621
    for (int v400 = 0; v400 < 64; v400 += 1) {	// L622
      for (int v401 = 0; v401 < 64; v401 += 1) {	// L623
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v397
        #pragma HLS dependence false variable=v398
        float v402 = v397[v399][v400][v401];	// L624
        v398[v399][v400][v401] = v402;	// L625
      }
    }
  }
}

void kernel165(
  float v403[12][64][32],
  float v404
) {	// L631
  for (int v405 = 0; v405 < 12; v405 += 1) {	// L632
    for (int v406 = 0; v406 < 64; v406 += 1) {	// L633
      for (int v407 = 0; v407 < 32; v407 += 1) {	// L634
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v403
        v403[v405][v406][v407] = v404;	// L635
      }
    }
  }
}

void kernel231(
  float v408[12][64][32],
  float v409
) {	// L641
  for (int v410 = 0; v410 < 12; v410 += 1) {	// L642
    for (int v411 = 0; v411 < 64; v411 += 1) {	// L643
      for (int v412 = 0; v412 < 32; v412 += 1) {	// L644
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v408
        v408[v410][v411][v412] = v409;	// L645
      }
    }
  }
}

void kernel235(
  float v413[12][64][64],
  float v414
) {	// L651
  for (int v415 = 0; v415 < 12; v415 += 1) {	// L652
    for (int v416 = 0; v416 < 64; v416 += 1) {	// L653
      for (int v417 = 0; v417 < 64; v417 += 1) {	// L654
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v413
        v413[v415][v416][v417] = v414;	// L655
      }
    }
  }
}

void kernel270(
  float v418[1][384][10][10],
  float v419[384][384][3][3],
  float v420[1][384][8][8]
) {	// L661
  float v421[1][384][10][10];	// L662
  #pragma HLS resource variable=v421 core=ram_t2p_uram

  memcpy(v421, v418, 38400 * sizeof(float));	// L663

  float v422[1][384][8][8];	// L664
  #pragma HLS resource variable=v422 core=ram_t2p_bram

  memcpy(v422, v420, 24576 * sizeof(float));	// L665

  auto v423 = reinterpret_cast<float(*)[384][3][3]>(v419);	// L667

  for (int v424 = 0; v424 < 384; v424 += 1) {	// L668
    for (int v425 = 0; v425 < 3; v425 += 1) {	// L669
      for (int v426 = 0; v426 < 3; v426 += 1) {	// L670
        for (int v427 = 0; v427 < 384; v427 += 1) {	// L671
          float v428 = v423[v427][v424][v425][v426];	// L672
          for (int v429 = 0; v429 < 8; v429 += 1) {	// L673
            for (int v430 = 0; v430 < 8; v430 += 1) {	// L674
              #pragma HLS pipeline II=1
              #pragma HLS dependence false variable=v421
              #pragma HLS dependence false variable=v422
              float v431 = v421[0][v424][(v429 + v425)][(v430 + v426)];	// L675
              float v432 = v422[0][v427][v429][v430];	// L676
              float v433 = v431 * v428;	// L677
              float v434 = v432 + v433;	// L678
              v422[0][v427][v429][v430] = v434;	// L679
            }
          }
        }
      }
    }
  }
  memcpy(v420, v422, 24576 * sizeof(float));	// L686

}

void kernel272(
  float v435[1][384][8][8],
  float v436[1][384][10][10]
) {	// L689
  for (int v437 = 0; v437 < 384; v437 += 1) {	// L690
    for (int v438 = 0; v438 < 8; v438 += 1) {	// L691
      for (int v439 = 0; v439 < 8; v439 += 1) {	// L692
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v435
        #pragma HLS dependence false variable=v436
        float v440 = v435[0][v437][v438][v439];	// L693
        v436[0][v437][(v438 + 1)][(v439 + 1)] = v440;	// L694
      }
    }
  }
}

void kernel273(
  float v441[1][384][10][10],
  float v442
) {	// L700
  for (int v443 = 0; v443 < 384; v443 += 1) {	// L701
    for (int v444 = 0; v444 < 10; v444 += 1) {	// L702
      for (int v445 = 0; v445 < 10; v445 += 1) {	// L703
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v441
        v441[0][v443][v444][v445] = v442;	// L704
      }
    }
  }
}

void kernel274(
  float v446[1][384][18][18],
  float v447[3][3],
  float v448[1][384][8][8]
) {	// L710
  for (int v449 = 0; v449 < 3; v449 += 1) {	// L711
    for (int v450 = 0; v450 < 3; v450 += 1) {	// L712
      for (int v451 = 0; v451 < 384; v451 += 1) {	// L713
        for (int v452 = 0; v452 < 8; v452 += 1) {	// L714
          for (int v453 = 0; v453 < 8; v453 += 1) {	// L715
            #pragma HLS pipeline II=1
            #pragma HLS dependence false variable=v446
            #pragma HLS dependence false variable=v448
            float v454 = v446[0][v451][((v452 * 2) + v449)][((v453 * 2) + v450)];	// L716
            float v455 = v448[0][v451][v452][v453];	// L717
            float v456 = max(v455, v454);	// L718
            v448[0][v451][v452][v453] = v456;	// L719
          }
        }
      }
    }
  }
}

void kernel275(
  float v457[1][384][8][8],
  float v458
) {	// L727
  for (int v459 = 0; v459 < 384; v459 += 1) {	// L728
    for (int v460 = 0; v460 < 8; v460 += 1) {	// L729
      for (int v461 = 0; v461 < 8; v461 += 1) {	// L730
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v457
        v457[0][v459][v460][v461] = v458;	// L731
      }
    }
  }
}

void kernel276(
  float v462[1][384][16][16],
  float v463[1][384][18][18]
) {	// L737
  for (int v464 = 0; v464 < 384; v464 += 1) {	// L738
    for (int v465 = 0; v465 < 16; v465 += 1) {	// L739
      for (int v466 = 0; v466 < 16; v466 += 1) {	// L740
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v462
        #pragma HLS dependence false variable=v463
        float v467 = v462[0][v464][v465][v466];	// L741
        v463[0][v464][(v465 + 1)][(v466 + 1)] = v467;	// L742
      }
    }
  }
}

void kernel277(
  float v468[1][384][18][18],
  float v469
) {	// L748
  for (int v470 = 0; v470 < 384; v470 += 1) {	// L749
    for (int v471 = 0; v471 < 18; v471 += 1) {	// L750
      for (int v472 = 0; v472 < 18; v472 += 1) {	// L751
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v468
        v468[0][v470][v471][v472] = v469;	// L752
      }
    }
  }
}

void kernel278(
  float v473[1][384][16][16],
  float v474[1][384][16][16]
) {	// L758
  for (int v475 = 0; v475 < 384; v475 += 1) {	// L759
    for (int v476 = 0; v476 < 16; v476 += 1) {	// L760
      for (int v477 = 0; v477 < 16; v477 += 1) {	// L761
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v473
        #pragma HLS dependence false variable=v474
        float v478 = v473[0][v475][v476][v477];	// L762
        v474[0][v475][v476][v477] = v478;	// L763
      }
    }
  }
}

void kernel279(
  float v479[1][384][16][16],
  float v480[1][384][16][16],
  float v481
) {	// L769
  for (int v482 = 0; v482 < 384; v482 += 1) {	// L770
    for (int v483 = 0; v483 < 16; v483 += 1) {	// L771
      for (int v484 = 0; v484 < 16; v484 += 1) {	// L772
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v480
        #pragma HLS dependence false variable=v479
        float v485 = v480[0][v482][v483][v484];	// L773
        float v486 = v479[0][v482][v483][v484];	// L774
        float v487 = v486 * v481;	// L775
        float v488 = v486 * v485;	// L776
        float v489 = v485 - v488;	// L777
        float v490 = v489 + v487;	// L778
        v480[0][v482][v483][v484] = v490;	// L779
      }
    }
  }
}

void kernel280(
  float v491[1][384][16][16],
  float v492,
  float v493
) {	// L785
  for (int v494 = 0; v494 < 384; v494 += 1) {	// L786
    for (int v495 = 0; v495 < 16; v495 += 1) {	// L787
      for (int v496 = 0; v496 < 16; v496 += 1) {	// L788
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v491
        float v497 = v491[0][v494][v495][v496];	// L789
        float v498 = v497 - v493;	// L790
        bool v499 = v498 >= v492;	// L791
        float v500 = v499 ? v493 : v492;	// L792
        v491[0][v494][v495][v496] = v500;	// L793
      }
    }
  }
}

void kernel282(
  float v501[1][384][16][16],
  float v502[1][384][16][16],
  float v503
) {	// L799
  for (int v504 = 0; v504 < 384; v504 += 1) {	// L800
    for (int v505 = 0; v505 < 16; v505 += 1) {	// L801
      for (int v506 = 0; v506 < 16; v506 += 1) {	// L802
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v501
        #pragma HLS dependence false variable=v502
        float v507 = v501[0][v504][v505][v506];	// L803
        float v508 = v502[0][v504][v505][v506];	// L804
        float v509 = v508 / v503;	// L805
        float v510 = v507 / v503;	// L806
        float v511 = v507 - v510;	// L807
        float v512 = v511 + v509;	// L808
        v502[0][v504][v505][v506] = v512;	// L809
      }
    }
  }
}

void kernel283(
  float v513[1][192][18][18],
  float v514[384][192][3][3],
  float v515[1][384][16][16]
) {	// L815
  float v516[1][384][16][16];	// L816
  #pragma HLS resource variable=v516 core=ram_t2p_uram

  memcpy(v516, v515, 98304 * sizeof(float));	// L817

  auto v517 = reinterpret_cast<float(*)[192][3][3]>(v514);	// L819

  for (int v518 = 0; v518 < 192; v518 += 1) {	// L820
    for (int v519 = 0; v519 < 3; v519 += 1) {	// L821
      for (int v520 = 0; v520 < 3; v520 += 1) {	// L822
        for (int v521 = 0; v521 < 384; v521 += 1) {	// L823
          float v522 = v517[v521][v518][v519][v520];	// L824
          for (int v523 = 0; v523 < 16; v523 += 1) {	// L825
            for (int v524 = 0; v524 < 16; v524 += 1) {	// L826
              #pragma HLS pipeline II=1
              #pragma HLS dependence false variable=v513
              #pragma HLS dependence false variable=v516
              float v525 = v513[0][v518][(v523 + v519)][(v524 + v520)];	// L827
              float v526 = v516[0][v521][v523][v524];	// L828
              float v527 = v525 * v522;	// L829
              float v528 = v526 + v527;	// L830
              v516[0][v521][v523][v524] = v528;	// L831
            }
          }
        }
      }
    }
  }
  memcpy(v515, v516, 98304 * sizeof(float));	// L838

}

void kernel284(
  float v529[384],
  float v530[1][384][16][16]
) {	// L841
  float v531[384];	// L842
  #pragma HLS resource variable=v531 core=ram_t2p_bram

  memcpy(v531, v529, 384 * sizeof(float));	// L843

  for (int v532 = 0; v532 < 384; v532 += 1) {	// L844
    for (int v533 = 0; v533 < 16; v533 += 1) {	// L845
      for (int v534 = 0; v534 < 16; v534 += 1) {	// L846
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v531
        #pragma HLS dependence false variable=v530
        float v535 = v531[v532];	// L847
        v530[0][v532][v533][v534] = v535;	// L848
      }
    }
  }
}

void kernel285(
  float v536[1][192][16][16],
  float v537[1][192][18][18]
) {	// L854
  for (int v538 = 0; v538 < 192; v538 += 1) {	// L855
    for (int v539 = 0; v539 < 16; v539 += 1) {	// L856
      for (int v540 = 0; v540 < 16; v540 += 1) {	// L857
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v536
        #pragma HLS dependence false variable=v537
        float v541 = v536[0][v538][v539][v540];	// L858
        v537[0][v538][(v539 + 1)][(v540 + 1)] = v541;	// L859
      }
    }
  }
}

void kernel286(
  float v542[1][192][18][18],
  float v543
) {	// L865
  for (int v544 = 0; v544 < 192; v544 += 1) {	// L866
    for (int v545 = 0; v545 < 18; v545 += 1) {	// L867
      for (int v546 = 0; v546 < 18; v546 += 1) {	// L868
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v542
        v542[0][v544][v545][v546] = v543;	// L869
      }
    }
  }
}

void kernel287(
  float v547[1][192][34][34],
  float v548[3][3],
  float v549[1][192][16][16]
) {	// L875
  for (int v550 = 0; v550 < 3; v550 += 1) {	// L876
    for (int v551 = 0; v551 < 3; v551 += 1) {	// L877
      for (int v552 = 0; v552 < 192; v552 += 1) {	// L878
        for (int v553 = 0; v553 < 16; v553 += 1) {	// L879
          for (int v554 = 0; v554 < 16; v554 += 1) {	// L880
            #pragma HLS pipeline II=1
            #pragma HLS dependence false variable=v547
            #pragma HLS dependence false variable=v549
            float v555 = v547[0][v552][((v553 * 2) + v550)][((v554 * 2) + v551)];	// L881
            float v556 = v549[0][v552][v553][v554];	// L882
            float v557 = max(v556, v555);	// L883
            v549[0][v552][v553][v554] = v557;	// L884
          }
        }
      }
    }
  }
}

void kernel288(
  float v558[1][192][16][16],
  float v559
) {	// L892
  for (int v560 = 0; v560 < 192; v560 += 1) {	// L893
    for (int v561 = 0; v561 < 16; v561 += 1) {	// L894
      for (int v562 = 0; v562 < 16; v562 += 1) {	// L895
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v558
        v558[0][v560][v561][v562] = v559;	// L896
      }
    }
  }
}

void kernel289(
  float v563[1][192][32][32],
  float v564[1][192][34][34]
) {	// L902
  for (int v565 = 0; v565 < 192; v565 += 1) {	// L903
    for (int v566 = 0; v566 < 32; v566 += 1) {	// L904
      for (int v567 = 0; v567 < 32; v567 += 1) {	// L905
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v563
        #pragma HLS dependence false variable=v564
        float v568 = v563[0][v565][v566][v567];	// L906
        v564[0][v565][(v566 + 1)][(v567 + 1)] = v568;	// L907
      }
    }
  }
}

void kernel290(
  float v569[1][192][34][34],
  float v570
) {	// L913
  for (int v571 = 0; v571 < 192; v571 += 1) {	// L914
    for (int v572 = 0; v572 < 34; v572 += 1) {	// L915
      for (int v573 = 0; v573 < 34; v573 += 1) {	// L916
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v569
        v569[0][v571][v572][v573] = v570;	// L917
      }
    }
  }
}

void kernel291(
  float v574[1][192][32][32],
  float v575[1][192][32][32]
) {	// L923
  for (int v576 = 0; v576 < 192; v576 += 1) {	// L924
    for (int v577 = 0; v577 < 32; v577 += 1) {	// L925
      for (int v578 = 0; v578 < 32; v578 += 1) {	// L926
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v574
        #pragma HLS dependence false variable=v575
        float v579 = v574[0][v576][v577][v578];	// L927
        v575[0][v576][v577][v578] = v579;	// L928
      }
    }
  }
}

void kernel292(
  float v580[1][192][32][32],
  float v581[1][192][32][32],
  float v582
) {	// L934
  for (int v583 = 0; v583 < 192; v583 += 1) {	// L935
    for (int v584 = 0; v584 < 32; v584 += 1) {	// L936
      for (int v585 = 0; v585 < 32; v585 += 1) {	// L937
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v581
        #pragma HLS dependence false variable=v580
        float v586 = v581[0][v583][v584][v585];	// L938
        float v587 = v580[0][v583][v584][v585];	// L939
        float v588 = v587 * v582;	// L940
        float v589 = v587 * v586;	// L941
        float v590 = v586 - v589;	// L942
        float v591 = v590 + v588;	// L943
        v581[0][v583][v584][v585] = v591;	// L944
      }
    }
  }
}

void kernel293(
  float v592[1][192][32][32],
  float v593,
  float v594
) {	// L950
  for (int v595 = 0; v595 < 192; v595 += 1) {	// L951
    for (int v596 = 0; v596 < 32; v596 += 1) {	// L952
      for (int v597 = 0; v597 < 32; v597 += 1) {	// L953
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v592
        float v598 = v592[0][v595][v596][v597];	// L954
        float v599 = v598 - v594;	// L955
        bool v600 = v599 >= v593;	// L956
        float v601 = v600 ? v594 : v593;	// L957
        v592[0][v595][v596][v597] = v601;	// L958
      }
    }
  }
}

void kernel295(
  float v602[1][192][32][32],
  float v603[1][192][32][32],
  float v604
) {	// L964
  for (int v605 = 0; v605 < 192; v605 += 1) {	// L965
    for (int v606 = 0; v606 < 32; v606 += 1) {	// L966
      for (int v607 = 0; v607 < 32; v607 += 1) {	// L967
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v602
        #pragma HLS dependence false variable=v603
        float v608 = v602[0][v605][v606][v607];	// L968
        float v609 = v603[0][v605][v606][v607];	// L969
        float v610 = v609 / v604;	// L970
        float v611 = v608 / v604;	// L971
        float v612 = v608 - v611;	// L972
        float v613 = v612 + v610;	// L973
        v603[0][v605][v606][v607] = v613;	// L974
      }
    }
  }
}

void kernel296(
  float v614[1][96][34][34],
  float v615[192][96][3][3],
  float v616[1][192][32][32]
) {	// L980
  float v617[1][192][32][32];	// L981
  #pragma HLS resource variable=v617 core=ram_t2p_uram

  memcpy(v617, v616, 196608 * sizeof(float));	// L982

  auto v618 = reinterpret_cast<float(*)[96][3][3]>(v615);	// L984

  for (int v619 = 0; v619 < 96; v619 += 1) {	// L985
    for (int v620 = 0; v620 < 3; v620 += 1) {	// L986
      for (int v621 = 0; v621 < 3; v621 += 1) {	// L987
        for (int v622 = 0; v622 < 192; v622 += 1) {	// L988
          float v623 = v618[v622][v619][v620][v621];	// L989
          for (int v624 = 0; v624 < 32; v624 += 1) {	// L990
            for (int v625 = 0; v625 < 32; v625 += 1) {	// L991
              #pragma HLS pipeline II=1
              #pragma HLS dependence false variable=v614
              #pragma HLS dependence false variable=v617
              float v626 = v614[0][v619][(v624 + v620)][(v625 + v621)];	// L992
              float v627 = v617[0][v622][v624][v625];	// L993
              float v628 = v626 * v623;	// L994
              float v629 = v627 + v628;	// L995
              v617[0][v622][v624][v625] = v629;	// L996
            }
          }
        }
      }
    }
  }
  memcpy(v616, v617, 196608 * sizeof(float));	// L1003

}

void kernel297(
  float v630[192],
  float v631[1][192][32][32]
) {	// L1006
  float v632[192];	// L1007
  #pragma HLS resource variable=v632 core=ram_t2p_bram

  memcpy(v632, v630, 192 * sizeof(float));	// L1008

  for (int v633 = 0; v633 < 192; v633 += 1) {	// L1009
    for (int v634 = 0; v634 < 32; v634 += 1) {	// L1010
      for (int v635 = 0; v635 < 32; v635 += 1) {	// L1011
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v632
        #pragma HLS dependence false variable=v631
        float v636 = v632[v633];	// L1012
        v631[0][v633][v634][v635] = v636;	// L1013
      }
    }
  }
}

void kernel298(
  float v637[1][96][32][32],
  float v638[1][96][34][34]
) {	// L1019
  for (int v639 = 0; v639 < 96; v639 += 1) {	// L1020
    for (int v640 = 0; v640 < 32; v640 += 1) {	// L1021
      for (int v641 = 0; v641 < 32; v641 += 1) {	// L1022
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v637
        #pragma HLS dependence false variable=v638
        float v642 = v637[0][v639][v640][v641];	// L1023
        v638[0][v639][(v640 + 1)][(v641 + 1)] = v642;	// L1024
      }
    }
  }
}

void kernel299(
  float v643[1][96][34][34],
  float v644
) {	// L1030
  for (int v645 = 0; v645 < 96; v645 += 1) {	// L1031
    for (int v646 = 0; v646 < 34; v646 += 1) {	// L1032
      for (int v647 = 0; v647 < 34; v647 += 1) {	// L1033
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v643
        v643[0][v645][v646][v647] = v644;	// L1034
      }
    }
  }
}

void kernel300(
  float v648[1][96][32][32],
  float v649[1][96][32][32]
) {	// L1040
  for (int v650 = 0; v650 < 96; v650 += 1) {	// L1041
    for (int v651 = 0; v651 < 32; v651 += 1) {	// L1042
      for (int v652 = 0; v652 < 32; v652 += 1) {	// L1043
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v648
        #pragma HLS dependence false variable=v649
        float v653 = v648[0][v650][v651][v652];	// L1044
        v649[0][v650][v651][v652] = v653;	// L1045
      }
    }
  }
}

void kernel301(
  float v654[1][96][32][32],
  float v655[1][96][32][32],
  float v656
) {	// L1051
  for (int v657 = 0; v657 < 96; v657 += 1) {	// L1052
    for (int v658 = 0; v658 < 32; v658 += 1) {	// L1053
      for (int v659 = 0; v659 < 32; v659 += 1) {	// L1054
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v655
        #pragma HLS dependence false variable=v654
        float v660 = v655[0][v657][v658][v659];	// L1055
        float v661 = v654[0][v657][v658][v659];	// L1056
        float v662 = v661 * v656;	// L1057
        float v663 = v661 * v660;	// L1058
        float v664 = v660 - v663;	// L1059
        float v665 = v664 + v662;	// L1060
        v655[0][v657][v658][v659] = v665;	// L1061
      }
    }
  }
}

void kernel302(
  float v666[1][96][32][32],
  float v667,
  float v668
) {	// L1067
  for (int v669 = 0; v669 < 96; v669 += 1) {	// L1068
    for (int v670 = 0; v670 < 32; v670 += 1) {	// L1069
      for (int v671 = 0; v671 < 32; v671 += 1) {	// L1070
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v666
        float v672 = v666[0][v669][v670][v671];	// L1071
        float v673 = v672 - v668;	// L1072
        bool v674 = v673 >= v667;	// L1073
        float v675 = v674 ? v668 : v667;	// L1074
        v666[0][v669][v670][v671] = v675;	// L1075
      }
    }
  }
}

void kernel304(
  float v676[1][96][32][32],
  float v677[1][96][32][32],
  float v678
) {	// L1081
  for (int v679 = 0; v679 < 96; v679 += 1) {	// L1082
    for (int v680 = 0; v680 < 32; v680 += 1) {	// L1083
      for (int v681 = 0; v681 < 32; v681 += 1) {	// L1084
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v676
        #pragma HLS dependence false variable=v677
        float v682 = v676[0][v679][v680][v681];	// L1085
        float v683 = v677[0][v679][v680][v681];	// L1086
        float v684 = v683 / v678;	// L1087
        float v685 = v682 / v678;	// L1088
        float v686 = v682 - v685;	// L1089
        float v687 = v686 + v684;	// L1090
        v677[0][v679][v680][v681] = v687;	// L1091
      }
    }
  }
}

void kernel305(
  float v688[1][48][34][34],
  float v689[96][48][3][3],
  float v690[1][96][32][32]
) {	// L1097
  auto v691 = reinterpret_cast<float(*)[48][3][3]>(v689);	// L1099

  for (int v692 = 0; v692 < 48; v692 += 1) {	// L1100
    for (int v693 = 0; v693 < 3; v693 += 1) {	// L1101
      for (int v694 = 0; v694 < 3; v694 += 1) {	// L1102
        for (int v695 = 0; v695 < 96; v695 += 1) {	// L1103
          float v696 = v691[v695][v692][v693][v694];	// L1104
          for (int v697 = 0; v697 < 32; v697 += 1) {	// L1105
            for (int v698 = 0; v698 < 32; v698 += 1) {	// L1106
              #pragma HLS pipeline II=1
              #pragma HLS dependence false variable=v688
              #pragma HLS dependence false variable=v690
              float v699 = v688[0][v692][(v697 + v693)][(v698 + v694)];	// L1107
              float v700 = v690[0][v695][v697][v698];	// L1108
              float v701 = v699 * v696;	// L1109
              float v702 = v700 + v701;	// L1110
              v690[0][v695][v697][v698] = v702;	// L1111
            }
          }
        }
      }
    }
  }
}

void kernel306(
  float v703[96],
  float v704[1][96][32][32]
) {	// L1120
  float v705[96];	// L1121
  #pragma HLS resource variable=v705 core=ram_t2p_bram

  memcpy(v705, v703, 96 * sizeof(float));	// L1122

  for (int v706 = 0; v706 < 96; v706 += 1) {	// L1123
    for (int v707 = 0; v707 < 32; v707 += 1) {	// L1124
      for (int v708 = 0; v708 < 32; v708 += 1) {	// L1125
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v705
        #pragma HLS dependence false variable=v704
        float v709 = v705[v706];	// L1126
        v704[0][v706][v707][v708] = v709;	// L1127
      }
    }
  }
}

void kernel307(
  float v710[1][48][32][32],
  float v711[1][48][34][34]
) {	// L1133
  for (int v712 = 0; v712 < 48; v712 += 1) {	// L1134
    for (int v713 = 0; v713 < 32; v713 += 1) {	// L1135
      for (int v714 = 0; v714 < 32; v714 += 1) {	// L1136
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v710
        #pragma HLS dependence false variable=v711
        float v715 = v710[0][v712][v713][v714];	// L1137
        v711[0][v712][(v713 + 1)][(v714 + 1)] = v715;	// L1138
      }
    }
  }
}

void kernel308(
  float v716[1][48][34][34],
  float v717
) {	// L1144
  for (int v718 = 0; v718 < 48; v718 += 1) {	// L1145
    for (int v719 = 0; v719 < 34; v719 += 1) {	// L1146
      for (int v720 = 0; v720 < 34; v720 += 1) {	// L1147
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v716
        v716[0][v718][v719][v720] = v717;	// L1148
      }
    }
  }
}

void kernel309(
  float v721[1][48][32][32],
  float v722[1][48][32][32]
) {	// L1154
  for (int v723 = 0; v723 < 48; v723 += 1) {	// L1155
    for (int v724 = 0; v724 < 32; v724 += 1) {	// L1156
      for (int v725 = 0; v725 < 32; v725 += 1) {	// L1157
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v721
        #pragma HLS dependence false variable=v722
        float v726 = v721[0][v723][v724][v725];	// L1158
        v722[0][v723][v724][v725] = v726;	// L1159
      }
    }
  }
}

void kernel310(
  float v727[1][48][32][32],
  float v728[1][48][32][32],
  float v729
) {	// L1165
  for (int v730 = 0; v730 < 48; v730 += 1) {	// L1166
    for (int v731 = 0; v731 < 32; v731 += 1) {	// L1167
      for (int v732 = 0; v732 < 32; v732 += 1) {	// L1168
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v728
        #pragma HLS dependence false variable=v727
        float v733 = v728[0][v730][v731][v732];	// L1169
        float v734 = v727[0][v730][v731][v732];	// L1170
        float v735 = v734 * v729;	// L1171
        float v736 = v734 * v733;	// L1172
        float v737 = v733 - v736;	// L1173
        float v738 = v737 + v735;	// L1174
        v728[0][v730][v731][v732] = v738;	// L1175
      }
    }
  }
}

void kernel311(
  float v739[1][48][32][32],
  float v740,
  float v741
) {	// L1181
  for (int v742 = 0; v742 < 48; v742 += 1) {	// L1182
    for (int v743 = 0; v743 < 32; v743 += 1) {	// L1183
      for (int v744 = 0; v744 < 32; v744 += 1) {	// L1184
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v739
        float v745 = v739[0][v742][v743][v744];	// L1185
        float v746 = v745 - v741;	// L1186
        bool v747 = v746 >= v740;	// L1187
        float v748 = v747 ? v741 : v740;	// L1188
        v739[0][v742][v743][v744] = v748;	// L1189
      }
    }
  }
}

void kernel313(
  float v749[1][48][32][32],
  float v750[1][48][32][32],
  float v751
) {	// L1195
  for (int v752 = 0; v752 < 48; v752 += 1) {	// L1196
    for (int v753 = 0; v753 < 32; v753 += 1) {	// L1197
      for (int v754 = 0; v754 < 32; v754 += 1) {	// L1198
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v749
        #pragma HLS dependence false variable=v750
        float v755 = v749[0][v752][v753][v754];	// L1199
        float v756 = v750[0][v752][v753][v754];	// L1200
        float v757 = v756 / v751;	// L1201
        float v758 = v755 / v751;	// L1202
        float v759 = v755 - v758;	// L1203
        float v760 = v759 + v757;	// L1204
        v750[0][v752][v753][v754] = v760;	// L1205
      }
    }
  }
}

void kernel314(
  float v761[1][3][34][34],
  float v762[48][3][3][3],
  float v763[1][48][32][32]
) {	// L1211
  float v764[48][3][3][3];	// L1212
  #pragma HLS resource variable=v764 core=ram_t2p_bram

  memcpy(v764, v762, 1296 * sizeof(float));	// L1213

  for (int v765 = 0; v765 < 3; v765 += 1) {	// L1214
    for (int v766 = 0; v766 < 3; v766 += 1) {	// L1215
      for (int v767 = 0; v767 < 3; v767 += 1) {	// L1216
        for (int v768 = 0; v768 < 48; v768 += 1) {	// L1217
          for (int v769 = 0; v769 < 32; v769 += 1) {	// L1218
            for (int v770 = 0; v770 < 32; v770 += 1) {	// L1219
              #pragma HLS pipeline II=1
              #pragma HLS dependence false variable=v761
              #pragma HLS dependence false variable=v763
              #pragma HLS dependence false variable=v764
              float v771 = v761[0][v765][(v769 + v766)][(v770 + v767)];	// L1220
              float v772 = v764[v768][v765][v766][v767];	// L1221
              float v773 = v763[0][v768][v769][v770];	// L1222
              float v774 = v771 * v772;	// L1223
              float v775 = v773 + v774;	// L1224
              v763[0][v768][v769][v770] = v775;	// L1225
            }
          }
        }
      }
    }
  }
}

void kernel315(
  float v776[48],
  float v777[1][48][32][32]
) {	// L1234
  float v778[48];	// L1235
  #pragma HLS resource variable=v778 core=ram_t2p_bram

  memcpy(v778, v776, 48 * sizeof(float));	// L1236

  for (int v779 = 0; v779 < 48; v779 += 1) {	// L1237
    for (int v780 = 0; v780 < 32; v780 += 1) {	// L1238
      for (int v781 = 0; v781 < 32; v781 += 1) {	// L1239
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v778
        #pragma HLS dependence false variable=v777
        float v782 = v778[v779];	// L1240
        v777[0][v779][v780][v781] = v782;	// L1241
      }
    }
  }
}

void kernel316(
  float v783[1][3][32][32],
  float v784[1][3][34][34]
) {	// L1247
  for (int v785 = 0; v785 < 3; v785 += 1) {	// L1248
    for (int v786 = 0; v786 < 32; v786 += 1) {	// L1249
      for (int v787 = 0; v787 < 32; v787 += 1) {	// L1250
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v783
        #pragma HLS dependence false variable=v784
        float v788 = v783[0][v785][v786][v787];	// L1251
        v784[0][v785][(v786 + 1)][(v787 + 1)] = v788;	// L1252
      }
    }
  }
}

void kernel317(
  float v789[1][3][34][34],
  float v790
) {	// L1258
  for (int v791 = 0; v791 < 3; v791 += 1) {	// L1259
    for (int v792 = 0; v792 < 34; v792 += 1) {	// L1260
      for (int v793 = 0; v793 < 34; v793 += 1) {	// L1261
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v789
        v789[0][v791][v792][v793] = v790;	// L1262
      }
    }
  }
}

/// The top function
void control(
  ap_int<32> v794[89418240],
  ap_int<32> v795[89418240],
  ap_int<32> v796[89418240]
) {	// L1268
  #pragma HLS interface s_axilite port=return bundle=ctrl
  #pragma hls interface m_axi offset=direct bundle=g0 port=v794
  #pragma hls stable variable=v794
  #pragma hls interface m_axi offset=direct bundle=g0 port=v795
  #pragma hls stable variable=v795
  #pragma hls interface m_axi offset=direct bundle=g0 port=v796
  #pragma hls stable variable=v796

  auto v797 = reinterpret_cast<float(*)[3][34][34]>(v794 + 6684672);
  kernel317(v797, (float)0.000000);	// L1277
  auto v798 = reinterpret_cast<float(*)[3][32][32]>(v794);
  kernel316(v798, v797);	// L1279
  auto v799 = reinterpret_cast<float(*)[48][32][32]>(v795 + 6906624);
  auto v800 = reinterpret_cast<float(*)>(v796 + 86764032);
  kernel315(v800, v799);	// L1282
  auto v801 = reinterpret_cast<float(*)[3][3][3]>(v796 + 88091136);
  kernel314(v797, v801, v799);	// L1284
  auto v802 = reinterpret_cast<float(*)[48][32][32]>(v794 + 196608);
  kernel313(v802, v799, (float)2.000000);	// L1286
  auto v803 = reinterpret_cast<float(*)[48][32][32]>(v794 + 6684672);
  kernel309(v799, v803);	// L1288
  kernel311(v803, (float)0.000000, (float)1.000000);	// L1289
  kernel310(v803, v799, (float)0.000000);	// L1290
  kernel309(v799, v802);	// L1291
  auto v804 = reinterpret_cast<float(*)[48][34][34]>(v795 + 6906624);
  kernel308(v804, (float)0.000000);	// L1293
  kernel307(v803, v804);	// L1294
  auto v805 = reinterpret_cast<float(*)[96][32][32]>(v795 + 6684672);
  auto v806 = reinterpret_cast<float(*)>(v796 + 84109824);
  kernel306(v806, v805);	// L1297
  auto v807 = reinterpret_cast<float(*)[48][3][3]>(v796 + 85436928);
  kernel305(v804, v807, v805);	// L1299
  auto v808 = reinterpret_cast<float(*)[96][32][32]>(v794 + 393216);
  kernel304(v808, v805, (float)2.000000);	// L1301
  auto v809 = reinterpret_cast<float(*)[96][32][32]>(v794 + 6906624);
  kernel300(v805, v809);	// L1303
  kernel302(v809, (float)0.000000, (float)1.000000);	// L1304
  kernel301(v809, v805, (float)0.000000);	// L1305
  kernel300(v805, v808);	// L1306
  auto v810 = reinterpret_cast<float(*)[96][34][34]>(v795 + 6684672);
  kernel299(v810, (float)0.000000);	// L1308
  kernel298(v809, v810);	// L1309
  auto v811 = reinterpret_cast<float(*)[192][32][32]>(v795 + 6906624);
  auto v812 = reinterpret_cast<float(*)>(v796 + 81455616);
  kernel297(v812, v811);	// L1312
  auto v813 = reinterpret_cast<float(*)[96][3][3]>(v796 + 82782720);
  kernel296(v810, v813, v811);	// L1314
  auto v814 = reinterpret_cast<float(*)[192][32][32]>(v794 + 589824);
  kernel295(v814, v811, (float)2.000000);	// L1316
  auto v815 = reinterpret_cast<float(*)[192][32][32]>(v794 + 6684672);
  kernel291(v811, v815);	// L1318
  kernel293(v815, (float)0.000000, (float)1.000000);	// L1319
  kernel292(v815, v811, (float)0.000000);	// L1320
  kernel291(v811, v814);	// L1321
  auto v816 = reinterpret_cast<float(*)[192][34][34]>(v795 + 6906624);
  kernel290(v816, (float)-INFINITY);	// L1323
  kernel289(v815, v816);	// L1324
  auto v817 = reinterpret_cast<float(*)[192][16][16]>(v794 + 6684672);
  kernel288(v817, (float)-INFINITY);	// L1326
  auto v818 = reinterpret_cast<float(*)[3]>(v796 + 7128576);
  kernel287(v816, v818, v817);	// L1328
  auto v819 = reinterpret_cast<float(*)[192][18][18]>(v794 + 6906624);
  kernel286(v819, (float)0.000000);	// L1330
  kernel285(v817, v819);	// L1331
  auto v820 = reinterpret_cast<float(*)[384][16][16]>(v794 + 6684672);
  auto v821 = reinterpret_cast<float(*)>(v796 + 78801408);
  kernel284(v821, v820);	// L1334
  auto v822 = reinterpret_cast<float(*)[192][3][3]>(v796 + 80128512);
  kernel283(v819, v822, v820);	// L1336
  auto v823 = reinterpret_cast<float(*)[384][16][16]>(v794 + 786432);
  kernel282(v823, v820, (float)2.000000);	// L1338
  auto v824 = reinterpret_cast<float(*)[384][16][16]>(v795 + 6906624);
  kernel278(v820, v824);	// L1340
  kernel280(v824, (float)0.000000, (float)1.000000);	// L1341
  kernel279(v824, v820, (float)0.000000);	// L1342
  kernel278(v820, v823);	// L1343
  auto v825 = reinterpret_cast<float(*)[384][18][18]>(v794 + 6684672);
  kernel277(v825, (float)-INFINITY);	// L1345
  kernel276(v824, v825);	// L1346
  auto v826 = reinterpret_cast<float(*)[384][8][8]>(v794 + 6906624);
  kernel275(v826, (float)-INFINITY);	// L1348
  kernel274(v825, v818, v826);	// L1349
  auto v827 = reinterpret_cast<float(*)[384][10][10]>(v794 + 6684672);
  kernel273(v827, (float)0.000000);	// L1351
  kernel272(v826, v827);	// L1352
  auto v828 = reinterpret_cast<float(*)[384][8][8]>(v795 + 7128576);
  auto v829 = reinterpret_cast<float(*)>(v796 + 76147200);
  kernel8(v829, v828);	// L1355
  auto v830 = reinterpret_cast<float(*)[384][3][3]>(v796 + 77474304);
  kernel270(v827, v830, v828);	// L1357
  auto v831 = reinterpret_cast<float(*)[384][8][8]>(v794 + 983040);
  kernel20(v831, v828, v826, (float)2.000000);	// L1359
  auto v832 = reinterpret_cast<float(*)[384][8][8]>(v794 + 6684672);
  kernel16(v826, v832);	// L1361
  kernel18(v832, (float)0.000000, (float)1.000000);	// L1362
  kernel17(v832, v826, (float)0.000000);	// L1363
  kernel16(v826, v831);	// L1364
  auto v833 = reinterpret_cast<float(*)[384][64]>(v795 + 7350528);
  auto v834 = reinterpret_cast<float(*)>(v796 + 73492992);
  kernel23(v834, v833);	// L1367
  auto v835 = reinterpret_cast<float(*)[384][1]>(v796 + 74820096);
  kernel47(v832, v835, v833);	// L1369
  auto v836 = reinterpret_cast<float(*)[384][64]>(v794 + 1179648);
  kernel46(v836, v833, (float)2.000000);	// L1371
  auto v837 = reinterpret_cast<float(*)[384][64]>(v794 + 7572480);
  kernel42(v833, v837);	// L1373
  kernel44(v837, (float)0.000000, (float)1.000000);	// L1374
  kernel43(v837, v833, (float)0.000000);	// L1375
  kernel42(v833, v836);	// L1376
  auto v838 = reinterpret_cast<float(*)[64][12][32]>(v794 + 7794432);
  kernel41(v837, v838);	// L1378
  auto v839 = reinterpret_cast<float(*)[12][64][32]>(v795 + 7572480);
  kernel40(v838, v839);	// L1380
  auto v840 = reinterpret_cast<float(*)>(v796 + 70838784);
  kernel23(v840, v833);	// L1382
  auto v841 = reinterpret_cast<float(*)[384][1]>(v796 + 72165888);
  kernel47(v832, v841, v833);	// L1384
  auto v842 = reinterpret_cast<float(*)[384][64]>(v794 + 1376256);
  kernel46(v842, v833, (float)2.000000);	// L1386
  auto v843 = reinterpret_cast<float(*)[384][64]>(v794 + 7794432);
  kernel42(v833, v843);	// L1388
  kernel44(v843, (float)0.000000, (float)1.000000);	// L1389
  kernel43(v843, v833, (float)0.000000);	// L1390
  kernel42(v833, v842);	// L1391
  auto v844 = reinterpret_cast<float(*)[64][12][32]>(v795 + 8016384);
  kernel41(v843, v844);	// L1393
  auto v845 = reinterpret_cast<float(*)>(v796 + 68184576);
  kernel23(v845, v833);	// L1395
  auto v846 = reinterpret_cast<float(*)[384][1]>(v796 + 69511680);
  kernel47(v832, v846, v833);	// L1397
  auto v847 = reinterpret_cast<float(*)[384][64]>(v794 + 1572864);
  kernel46(v847, v833, (float)2.000000);	// L1399
  auto v848 = reinterpret_cast<float(*)[384][64]>(v794 + 6684672);
  kernel42(v833, v848);	// L1401
  kernel44(v848, (float)0.000000, (float)1.000000);	// L1402
  kernel43(v848, v833, (float)0.000000);	// L1403
  kernel42(v833, v847);	// L1404
  auto v849 = reinterpret_cast<float(*)[64][12][32]>(v795 + 7794432);
  kernel41(v848, v849);	// L1406
  auto v850 = reinterpret_cast<float(*)[12][64][32]>(v794 + 8238336);
  kernel40(v849, v850);	// L1408
  auto v851 = reinterpret_cast<float(*)[12][32][64]>(v794 + 6684672);
  kernel39(v844, v851);	// L1410
  auto v852 = reinterpret_cast<float(*)[1][12][64][32]>(v795 + 7794432);
  kernel35(v839, v852);	// L1412
  auto v853 = reinterpret_cast<float(*)[1][12][32][64]>(v796 + 7572480);
  kernel37(v851, v853);	// L1414
  auto v854 = reinterpret_cast<float(*)[64][64]>(v795 + 8016384);
  kernel235(v854, (float)0.000000);	// L1416
  auto v855 = reinterpret_cast<float(*)[64][64]>(v794 + 8460288);
  kernel102(v854, v855);	// L1418
  kernel36(v852, v853, v855);	// L1419
  auto v856 = reinterpret_cast<float(*)[1][12][64][32]>(v795 + 7572480);
  kernel35(v850, v856);	// L1421
  auto v857 = reinterpret_cast<float(*)[64][32]>(v796 + 7794432);
  kernel231(v857, (float)0.000000);	// L1423
  kernel33(v856, v855, v857);	// L1424
  kernel32(v857, v850);	// L1425
  kernel31(v850, (float)0.125000);	// L1426
  auto v858 = reinterpret_cast<float(*)[64][12][32]>(v795 + 7572480);
  kernel30(v850, v858);	// L1428
  auto v859 = reinterpret_cast<float(*)[64][384]>(v794 + 1769472);
  auto v860 = reinterpret_cast<float(*)[64][12][32]>(v795 + 8460288);
  kernel29(v859, v858, v860, (float)2.000000);	// L1431
  auto v861 = reinterpret_cast<float(*)[64][384]>(v796 + 8682240);
  kernel28(v860, v861);	// L1433
  kernel27(v861, (float)1.000000, (float)0.500000, (float)0.000000);	// L1434
  auto v862 = reinterpret_cast<float(*)[64][384]>(v794 + 8904192);
  kernel26(v860, v861, v862, (float)0.000000);	// L1436
  kernel25(v862, v859);	// L1437
  auto v863 = reinterpret_cast<float(*)[384][64]>(v794 + 8460288);
  kernel24(v861, v863);	// L1439
  auto v864 = reinterpret_cast<float(*)>(v796 + 65530368);
  kernel23(v864, v833);	// L1441
  auto v865 = reinterpret_cast<float(*)[384][1]>(v796 + 66857472);
  kernel22(v863, v865, v833);	// L1443
  auto v866 = reinterpret_cast<float(*)[384][8][8]>(v795 + 8460288);
  kernel21(v833, v828, v866);	// L1445
  auto v867 = reinterpret_cast<float(*)[384][8][8]>(v794 + 1966080);
  kernel20(v867, v866, v826, (float)2.000000);	// L1447
  kernel16(v826, v828);	// L1448
  kernel18(v828, (float)0.000000, (float)1.000000);	// L1449
  kernel17(v828, v826, (float)0.000000);	// L1450
  kernel16(v826, v867);	// L1451
  auto v868 = reinterpret_cast<float(*)[1536][8][8]>(v794 + 8682240);
  auto v869 = reinterpret_cast<float(*)>(v796 + 62876160);
  kernel15(v869, v868);	// L1454
  auto v870 = reinterpret_cast<float(*)[384][1][1]>(v796 + 64203264);
  kernel14(v828, v870, v868);	// L1456
  auto v871 = reinterpret_cast<float(*)[1536][8][8]>(v794 + 2162688);
  kernel13(v871, v868, (float)2.000000);	// L1458
  auto v872 = reinterpret_cast<float(*)[1536][8][8]>(v794 + 7128576);
  kernel9(v868, v872);	// L1460
  kernel11(v872, (float)0.000000, (float)1.000000);	// L1461
  kernel10(v872, v868, (float)0.000000);	// L1462
  kernel9(v868, v871);	// L1463
  auto v873 = reinterpret_cast<float(*)>(v796 + 60221952);
  kernel8(v873, v826);	// L1465
  auto v874 = reinterpret_cast<float(*)[1536][1][1]>(v796 + 61549056);
  kernel7(v872, v874, v826);	// L1467
  auto v875 = reinterpret_cast<float(*)[384][8][8]>(v796 + 7128576);
  kernel71(v826, v866, v875);	// L1469
  auto v876 = reinterpret_cast<float(*)[384][8][8]>(v794 + 2359296);
  kernel20(v876, v875, v826, (float)2.000000);	// L1471
  kernel16(v826, v866);	// L1472
  kernel18(v866, (float)0.000000, (float)1.000000);	// L1473
  kernel17(v866, v826, (float)0.000000);	// L1474
  kernel16(v826, v876);	// L1475
  auto v877 = reinterpret_cast<float(*)>(v796 + 57567744);
  kernel23(v877, v833);	// L1477
  auto v878 = reinterpret_cast<float(*)[384][1]>(v796 + 58894848);
  kernel47(v866, v878, v833);	// L1479
  auto v879 = reinterpret_cast<float(*)[384][64]>(v794 + 2555904);
  kernel46(v879, v833, (float)2.000000);	// L1481
  auto v880 = reinterpret_cast<float(*)[384][64]>(v794 + 9126144);
  kernel42(v833, v880);	// L1483
  kernel44(v880, (float)0.000000, (float)1.000000);	// L1484
  kernel43(v880, v833, (float)0.000000);	// L1485
  kernel42(v833, v879);	// L1486
  auto v881 = reinterpret_cast<float(*)[64][12][32]>(v794 + 9348096);
  kernel41(v880, v881);	// L1488
  auto v882 = reinterpret_cast<float(*)[12][64][32]>(v795 + 9126144);
  kernel40(v881, v882);	// L1490
  auto v883 = reinterpret_cast<float(*)>(v796 + 54913536);
  kernel23(v883, v833);	// L1492
  auto v884 = reinterpret_cast<float(*)[384][1]>(v796 + 56240640);
  kernel47(v866, v884, v833);	// L1494
  auto v885 = reinterpret_cast<float(*)[384][64]>(v794 + 2752512);
  kernel46(v885, v833, (float)2.000000);	// L1496
  auto v886 = reinterpret_cast<float(*)[384][64]>(v794 + 9348096);
  kernel42(v833, v886);	// L1498
  kernel44(v886, (float)0.000000, (float)1.000000);	// L1499
  kernel43(v886, v833, (float)0.000000);	// L1500
  kernel42(v833, v885);	// L1501
  auto v887 = reinterpret_cast<float(*)[64][12][32]>(v795 + 9570048);
  kernel41(v886, v887);	// L1503
  auto v888 = reinterpret_cast<float(*)>(v796 + 52259328);
  kernel23(v888, v833);	// L1505
  auto v889 = reinterpret_cast<float(*)[384][1]>(v796 + 53586432);
  kernel47(v866, v889, v833);	// L1507
  auto v890 = reinterpret_cast<float(*)[384][64]>(v794 + 2949120);
  kernel46(v890, v833, (float)2.000000);	// L1509
  kernel42(v833, v863);	// L1510
  kernel44(v863, (float)0.000000, (float)1.000000);	// L1511
  kernel43(v863, v833, (float)0.000000);	// L1512
  kernel42(v833, v890);	// L1513
  auto v891 = reinterpret_cast<float(*)[64][12][32]>(v795 + 9348096);
  kernel41(v863, v891);	// L1515
  kernel40(v891, v850);	// L1516
  kernel39(v887, v851);	// L1517
  auto v892 = reinterpret_cast<float(*)[1][12][64][32]>(v794 + 8460288);
  kernel35(v882, v892);	// L1519
  auto v893 = reinterpret_cast<float(*)[1][12][32][64]>(v795 + 9126144);
  kernel37(v851, v893);	// L1521
  auto v894 = reinterpret_cast<float(*)[64][64]>(v794 + 9348096);
  kernel102(v854, v894);	// L1523
  kernel36(v892, v893, v894);	// L1524
  auto v895 = reinterpret_cast<float(*)[1][12][64][32]>(v795 + 8460288);
  kernel35(v850, v895);	// L1526
  kernel165(v857, (float)0.000000);	// L1527
  kernel33(v895, v894, v857);	// L1528
  kernel32(v857, v850);	// L1529
  kernel31(v850, (float)0.125000);	// L1530
  kernel30(v850, v858);	// L1531
  auto v896 = reinterpret_cast<float(*)[64][384]>(v794 + 3145728);
  auto v897 = reinterpret_cast<float(*)[64][12][32]>(v794 + 8460288);
  kernel29(v896, v858, v897, (float)2.000000);	// L1534
  auto v898 = reinterpret_cast<float(*)[64][384]>(v795 + 9126144);
  kernel28(v897, v898);	// L1536
  kernel27(v898, (float)1.000000, (float)0.500000, (float)0.000000);	// L1537
  kernel26(v897, v898, v862, (float)0.000000);	// L1538
  kernel25(v862, v896);	// L1539
  kernel24(v898, v863);	// L1540
  auto v899 = reinterpret_cast<float(*)>(v796 + 49605120);
  kernel23(v899, v833);	// L1542
  auto v900 = reinterpret_cast<float(*)[384][1]>(v796 + 50932224);
  kernel22(v863, v900, v833);	// L1544
  kernel21(v833, v875, v866);	// L1545
  auto v901 = reinterpret_cast<float(*)[384][8][8]>(v794 + 3342336);
  kernel20(v901, v866, v826, (float)2.000000);	// L1547
  kernel16(v826, v828);	// L1548
  kernel18(v828, (float)0.000000, (float)1.000000);	// L1549
  kernel17(v828, v826, (float)0.000000);	// L1550
  kernel16(v826, v901);	// L1551
  auto v902 = reinterpret_cast<float(*)>(v796 + 46950912);
  kernel15(v902, v868);	// L1553
  auto v903 = reinterpret_cast<float(*)[384][1][1]>(v796 + 48278016);
  kernel14(v828, v903, v868);	// L1555
  auto v904 = reinterpret_cast<float(*)[1536][8][8]>(v794 + 3538944);
  kernel13(v904, v868, (float)2.000000);	// L1557
  auto v905 = reinterpret_cast<float(*)[1536][8][8]>(v795 + 7128576);
  kernel9(v868, v905);	// L1559
  kernel11(v905, (float)0.000000, (float)1.000000);	// L1560
  kernel10(v905, v868, (float)0.000000);	// L1561
  kernel9(v868, v904);	// L1562
  auto v906 = reinterpret_cast<float(*)>(v796 + 44296704);
  kernel8(v906, v826);	// L1564
  auto v907 = reinterpret_cast<float(*)[1536][1][1]>(v796 + 45623808);
  kernel7(v905, v907, v826);	// L1566
  kernel71(v826, v866, v828);	// L1567
  auto v908 = reinterpret_cast<float(*)[384][8][8]>(v794 + 3735552);
  kernel20(v908, v828, v826, (float)2.000000);	// L1569
  auto v909 = reinterpret_cast<float(*)[384][8][8]>(v794 + 8460288);
  kernel16(v826, v909);	// L1571
  kernel18(v909, (float)0.000000, (float)1.000000);	// L1572
  kernel17(v909, v826, (float)0.000000);	// L1573
  kernel16(v826, v908);	// L1574
  auto v910 = reinterpret_cast<float(*)>(v796 + 41642496);
  kernel23(v910, v833);	// L1576
  auto v911 = reinterpret_cast<float(*)[384][1]>(v796 + 42969600);
  kernel47(v909, v911, v833);	// L1578
  auto v912 = reinterpret_cast<float(*)[384][64]>(v794 + 3932160);
  kernel46(v912, v833, (float)2.000000);	// L1580
  kernel42(v833, v880);	// L1581
  kernel44(v880, (float)0.000000, (float)1.000000);	// L1582
  kernel43(v880, v833, (float)0.000000);	// L1583
  kernel42(v833, v912);	// L1584
  kernel41(v880, v891);	// L1585
  auto v913 = reinterpret_cast<float(*)[12][64][32]>(v794 + 9126144);
  kernel40(v891, v913);	// L1587
  auto v914 = reinterpret_cast<float(*)>(v796 + 38988288);
  kernel23(v914, v833);	// L1589
  auto v915 = reinterpret_cast<float(*)[384][1]>(v796 + 40315392);
  kernel47(v909, v915, v833);	// L1591
  auto v916 = reinterpret_cast<float(*)[384][64]>(v794 + 4128768);
  kernel46(v916, v833, (float)2.000000);	// L1593
  kernel42(v833, v886);	// L1594
  kernel44(v886, (float)0.000000, (float)1.000000);	// L1595
  kernel43(v886, v833, (float)0.000000);	// L1596
  kernel42(v833, v916);	// L1597
  kernel41(v886, v887);	// L1598
  auto v917 = reinterpret_cast<float(*)>(v796 + 36334080);
  kernel23(v917, v833);	// L1600
  auto v918 = reinterpret_cast<float(*)[384][1]>(v796 + 37661184);
  kernel47(v909, v918, v833);	// L1602
  auto v919 = reinterpret_cast<float(*)[384][64]>(v794 + 4325376);
  kernel46(v919, v833, (float)2.000000);	// L1604
  kernel42(v833, v863);	// L1605
  kernel44(v863, (float)0.000000, (float)1.000000);	// L1606
  kernel43(v863, v833, (float)0.000000);	// L1607
  kernel42(v833, v919);	// L1608
  kernel41(v863, v891);	// L1609
  kernel40(v891, v850);	// L1610
  kernel39(v887, v851);	// L1611
  kernel35(v913, v895);	// L1612
  auto v920 = reinterpret_cast<float(*)[1][12][32][64]>(v796 + 9126144);
  kernel37(v851, v920);	// L1614
  kernel102(v854, v894);	// L1615
  kernel36(v895, v920, v894);	// L1616
  kernel35(v850, v895);	// L1617
  kernel99(v857, (float)0.000000);	// L1618
  kernel33(v895, v894, v857);	// L1619
  kernel32(v857, v850);	// L1620
  kernel31(v850, (float)0.125000);	// L1621
  kernel30(v850, v858);	// L1622
  auto v921 = reinterpret_cast<float(*)[64][384]>(v794 + 4521984);
  kernel29(v921, v858, v860, (float)2.000000);	// L1624
  auto v922 = reinterpret_cast<float(*)[64][384]>(v796 + 9126144);
  kernel28(v860, v922);	// L1626
  kernel27(v922, (float)1.000000, (float)0.500000, (float)0.000000);	// L1627
  kernel26(v860, v922, v862, (float)0.000000);	// L1628
  kernel25(v862, v921);	// L1629
  kernel24(v922, v863);	// L1630
  auto v923 = reinterpret_cast<float(*)>(v796 + 33679872);
  kernel23(v923, v833);	// L1632
  auto v924 = reinterpret_cast<float(*)[384][1]>(v796 + 35006976);
  kernel22(v863, v924, v833);	// L1634
  kernel21(v833, v828, v866);	// L1635
  auto v925 = reinterpret_cast<float(*)[384][8][8]>(v794 + 4718592);
  kernel20(v925, v866, v826, (float)2.000000);	// L1637
  kernel16(v826, v828);	// L1638
  kernel18(v828, (float)0.000000, (float)1.000000);	// L1639
  kernel17(v828, v826, (float)0.000000);	// L1640
  kernel16(v826, v925);	// L1641
  auto v926 = reinterpret_cast<float(*)>(v796 + 31025664);
  kernel15(v926, v868);	// L1643
  auto v927 = reinterpret_cast<float(*)[384][1][1]>(v796 + 32352768);
  kernel14(v828, v927, v868);	// L1645
  auto v928 = reinterpret_cast<float(*)[1536][8][8]>(v794 + 4915200);
  kernel13(v928, v868, (float)2.000000);	// L1647
  kernel9(v868, v905);	// L1648
  kernel11(v905, (float)0.000000, (float)1.000000);	// L1649
  kernel10(v905, v868, (float)0.000000);	// L1650
  kernel9(v868, v928);	// L1651
  auto v929 = reinterpret_cast<float(*)>(v796 + 28371456);
  kernel8(v929, v826);	// L1653
  auto v930 = reinterpret_cast<float(*)[1536][1][1]>(v796 + 29698560);
  kernel7(v905, v930, v826);	// L1655
  auto v931 = reinterpret_cast<float(*)[384][8][8]>(v794 + 7128576);
  kernel71(v826, v866, v931);	// L1657
  auto v932 = reinterpret_cast<float(*)[384][8][8]>(v794 + 5111808);
  kernel20(v932, v931, v826, (float)2.000000);	// L1659
  kernel16(v826, v909);	// L1660
  kernel18(v909, (float)0.000000, (float)1.000000);	// L1661
  kernel17(v909, v826, (float)0.000000);	// L1662
  kernel16(v826, v932);	// L1663
  auto v933 = reinterpret_cast<float(*)>(v796 + 25717248);
  kernel23(v933, v833);	// L1665
  auto v934 = reinterpret_cast<float(*)[384][1]>(v796 + 27044352);
  kernel47(v909, v934, v833);	// L1667
  auto v935 = reinterpret_cast<float(*)[384][64]>(v794 + 5308416);
  kernel46(v935, v833, (float)2.000000);	// L1669
  kernel42(v833, v880);	// L1670
  kernel44(v880, (float)0.000000, (float)1.000000);	// L1671
  kernel43(v880, v833, (float)0.000000);	// L1672
  kernel42(v833, v935);	// L1673
  kernel41(v880, v891);	// L1674
  kernel40(v891, v913);	// L1675
  auto v936 = reinterpret_cast<float(*)>(v796 + 23063040);
  kernel23(v936, v833);	// L1677
  auto v937 = reinterpret_cast<float(*)[384][1]>(v796 + 24390144);
  kernel47(v909, v937, v833);	// L1679
  auto v938 = reinterpret_cast<float(*)[384][64]>(v794 + 5505024);
  kernel46(v938, v833, (float)2.000000);	// L1681
  kernel42(v833, v886);	// L1682
  kernel44(v886, (float)0.000000, (float)1.000000);	// L1683
  kernel43(v886, v833, (float)0.000000);	// L1684
  kernel42(v833, v938);	// L1685
  kernel41(v886, v887);	// L1686
  auto v939 = reinterpret_cast<float(*)>(v796 + 20408832);
  kernel23(v939, v833);	// L1688
  auto v940 = reinterpret_cast<float(*)[384][1]>(v796 + 21735936);
  kernel47(v909, v940, v833);	// L1690
  auto v941 = reinterpret_cast<float(*)[384][64]>(v794 + 5701632);
  kernel46(v941, v833, (float)2.000000);	// L1692
  kernel42(v833, v863);	// L1693
  kernel44(v863, (float)0.000000, (float)1.000000);	// L1694
  kernel43(v863, v833, (float)0.000000);	// L1695
  kernel42(v833, v941);	// L1696
  kernel41(v863, v891);	// L1697
  kernel40(v891, v850);	// L1698
  kernel39(v887, v851);	// L1699
  kernel35(v913, v895);	// L1700
  kernel37(v851, v893);	// L1701
  kernel36(v895, v893, v854);	// L1702
  auto v942 = reinterpret_cast<float(*)[1][12][64][32]>(v794 + 6684672);
  kernel35(v850, v942);	// L1704
  kernel34(v857, (float)0.000000);	// L1705
  kernel33(v942, v854, v857);	// L1706
  kernel32(v857, v850);	// L1707
  kernel31(v850, (float)0.125000);	// L1708
  kernel30(v850, v858);	// L1709
  auto v943 = reinterpret_cast<float(*)[64][384]>(v794 + 5898240);
  auto v944 = reinterpret_cast<float(*)[64][12][32]>(v794 + 6684672);
  kernel29(v943, v858, v944, (float)2.000000);	// L1712
  auto v945 = reinterpret_cast<float(*)[64][384]>(v795 + 7572480);
  kernel28(v944, v945);	// L1714
  kernel27(v945, (float)1.000000, (float)0.500000, (float)0.000000);	// L1715
  kernel26(v944, v945, v862, (float)0.000000);	// L1716
  kernel25(v862, v943);	// L1717
  kernel24(v945, v848);	// L1718
  auto v946 = reinterpret_cast<float(*)>(v796 + 17754624);
  kernel23(v946, v833);	// L1720
  auto v947 = reinterpret_cast<float(*)[384][1]>(v796 + 19081728);
  kernel22(v848, v947, v833);	// L1722
  auto v948 = reinterpret_cast<float(*)[384][8][8]>(v796 + 6684672);
  kernel21(v833, v931, v948);	// L1724
  auto v949 = reinterpret_cast<float(*)[384][8][8]>(v794 + 6094848);
  kernel20(v949, v948, v826, (float)2.000000);	// L1726
  kernel16(v826, v828);	// L1727
  kernel18(v828, (float)0.000000, (float)1.000000);	// L1728
  kernel17(v828, v826, (float)0.000000);	// L1729
  kernel16(v826, v949);	// L1730
  auto v950 = reinterpret_cast<float(*)>(v796 + 15100416);
  kernel15(v950, v868);	// L1732
  auto v951 = reinterpret_cast<float(*)[384][1][1]>(v796 + 16427520);
  kernel14(v828, v951, v868);	// L1734
  auto v952 = reinterpret_cast<float(*)[1536][8][8]>(v794 + 6291456);
  kernel13(v952, v868, (float)2.000000);	// L1736
  kernel9(v868, v872);	// L1737
  kernel11(v872, (float)0.000000, (float)1.000000);	// L1738
  kernel10(v872, v868, (float)0.000000);	// L1739
  kernel9(v868, v952);	// L1740
  auto v953 = reinterpret_cast<float(*)>(v796 + 12446208);
  kernel8(v953, v826);	// L1742
  auto v954 = reinterpret_cast<float(*)[1536][1][1]>(v796 + 13773312);
  kernel7(v872, v954, v826);	// L1744
  kernel6(v948, v826);	// L1745
  auto v955 = reinterpret_cast<float(*)[384]>(v795 + 6684672);
  kernel5(v955, (float)0.000000);	// L1747
  kernel4(v826, v955);	// L1748
  kernel3(v955, (float)64.000000);	// L1749
  auto v956 = reinterpret_cast<float(*)[10]>(v794 + 6488064);
  kernel2(v956, (float)0.000000);	// L1751
  auto v957 = reinterpret_cast<float(*)[10]>(v796 + 9792000);
  kernel1(v955, v957, v956);	// L1753
  auto v958 = reinterpret_cast<float(*)>(v796 + 11119104);
  kernel0(v958, v956);	// L1755
}

/// The T-step wrapper (FHCA v1.4: on-chip time-step loop)
/// Drives the single-step control T times; membrane states persist in DDR top_level buffers.
/// input_frames: DDR staging of T input frames (per-step-input);
///   frame t is memcpy'd to the input slot (arg0+0) before step t.
///   frame_elems=0: static input (host pre-writes frame, no copy).
/// out_frames: per-step outputs staged to DDR (out region assumed on
///   arg0 at out_elem_offset); out_elems=0: skip staging.
void control_t(
  ap_int<32> t_v0[89418240],
  ap_int<32> t_v1[89418240],
  ap_int<32> t_v2[89418240],
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

