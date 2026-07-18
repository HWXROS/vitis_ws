
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
  float v6[1][512][1][1],
  float v7[512][10],
  float v8[1][10]
) {	// L11
  float v9[1][512][1][1];	// L12
  #pragma HLS resource variable=v9 core=ram_t2p_bram

  memcpy(v9, v6, 512 * sizeof(float));	// L13

  for (int v10 = 0; v10 < 512; v10 += 1) {	// L14
    for (int v11 = 0; v11 < 10; v11 += 1) {	// L15
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
  float v20[1][512][1][1],
  float v21
) {	// L32
  for (int v22 = 0; v22 < 512; v22 += 1) {	// L33
    float v23 = v20[0][v22][0][0];	// L34
    float v24 = v23 / v21;	// L35
    v20[0][v22][0][0] = v24;	// L36
  }
}

void kernel4(
  float v25[1][512][3][3],
  float v26[3][3],
  float v27[1][512][1][1]
) {	// L40
  for (int v28 = 0; v28 < 3; v28 += 1) {	// L41
    for (int v29 = 0; v29 < 3; v29 += 1) {	// L42
      for (int v30 = 0; v30 < 512; v30 += 1) {	// L43
        float v31 = v25[0][v30][v28][v29];	// L44
        float v32 = v27[0][v30][0][0];	// L45
        float v33 = v32 + v31;	// L46
        v27[0][v30][0][0] = v33;	// L47
      }
    }
  }
}

void kernel5(
  float v34[1][512][1][1],
  float v35
) {	// L53
  for (int v36 = 0; v36 < 512; v36 += 1) {	// L54
    v34[0][v36][0][0] = v35;	// L55
  }
}

void kernel6(
  float v37[1][512][3][3],
  float v38[1][512][3][3]
) {	// L59
  for (int v39 = 0; v39 < 512; v39 += 1) {	// L60
    for (int v40 = 0; v40 < 3; v40 += 1) {	// L61
      for (int v41 = 0; v41 < 3; v41 += 1) {	// L62
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v37
        #pragma HLS dependence false variable=v38
        float v42 = v37[0][v39][v40][v41];	// L63
        v38[0][v39][v40][v41] = v42;	// L64
      }
    }
  }
}

void kernel7(
  float v43[1][512][3][3],
  float v44[1][512][3][3],
  float v45
) {	// L70
  for (int v46 = 0; v46 < 512; v46 += 1) {	// L71
    for (int v47 = 0; v47 < 3; v47 += 1) {	// L72
      for (int v48 = 0; v48 < 3; v48 += 1) {	// L73
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v44
        #pragma HLS dependence false variable=v43
        float v49 = v44[0][v46][v47][v48];	// L74
        float v50 = v43[0][v46][v47][v48];	// L75
        float v51 = v50 * v45;	// L76
        float v52 = v50 * v49;	// L77
        float v53 = v49 - v52;	// L78
        float v54 = v53 + v51;	// L79
        v44[0][v46][v47][v48] = v54;	// L80
      }
    }
  }
}

void kernel8(
  float v55[1][512][3][3],
  float v56,
  float v57
) {	// L86
  for (int v58 = 0; v58 < 512; v58 += 1) {	// L87
    for (int v59 = 0; v59 < 3; v59 += 1) {	// L88
      for (int v60 = 0; v60 < 3; v60 += 1) {	// L89
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v55
        float v61 = v55[0][v58][v59][v60];	// L90
        float v62 = v61 - v57;	// L91
        bool v63 = v62 >= v56;	// L92
        float v64 = v63 ? v57 : v56;	// L93
        v55[0][v58][v59][v60] = v64;	// L94
      }
    }
  }
}

void kernel10(
  float v65[1][512][3][3],
  float v66[1][512][3][3],
  float v67[1][512][3][3]
) {	// L100
  for (int v68 = 0; v68 < 512; v68 += 1) {	// L101
    for (int v69 = 0; v69 < 3; v69 += 1) {	// L102
      for (int v70 = 0; v70 < 3; v70 += 1) {	// L103
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v66
        #pragma HLS dependence false variable=v67
        #pragma HLS dependence false variable=v65
        float v71 = v66[0][v68][v69][v70];	// L104
        float v72 = v65[0][v68][v69][v70];	// L105
        float v73 = v71 + v72;	// L106
        float v74 = v67[0][v68][v69][v70];	// L107
        float v75 = v74 + v73;	// L108
        v67[0][v68][v69][v70] = v75;	// L109
      }
    }
  }
}

void kernel11(
  float v76[1][512][5][5],
  float v77[512][512][3][3],
  float v78[1][512][3][3]
) {	// L115
  auto v79 = reinterpret_cast<float(*)[512][3][3]>(v77);	// L117

  for (int v80 = 0; v80 < 512; v80 += 1) {	// L118
    for (int v81 = 0; v81 < 3; v81 += 1) {	// L119
      for (int v82 = 0; v82 < 3; v82 += 1) {	// L120
        for (int v83 = 0; v83 < 512; v83 += 1) {	// L121
          for (int v84 = 0; v84 < 3; v84 += 1) {	// L122
            for (int v85 = 0; v85 < 3; v85 += 1) {	// L123
              #pragma HLS pipeline II=1
              #pragma HLS dependence false variable=v76
              #pragma HLS dependence false variable=v78
              #pragma HLS dependence false variable=v79
              float v86 = v76[0][v80][(v84 + v81)][(v85 + v82)];	// L124
              float v87 = v79[v83][v80][v81][v82];	// L125
              float v88 = v78[0][v83][v84][v85];	// L126
              float v89 = v86 * v87;	// L127
              float v90 = v88 + v89;	// L128
              v78[0][v83][v84][v85] = v90;	// L129
            }
          }
        }
      }
    }
  }
}

void kernel12(
  float v91[512],
  float v92[1][512][3][3]
) {	// L138
  float v93[512];	// L139
  #pragma HLS resource variable=v93 core=ram_t2p_bram

  memcpy(v93, v91, 512 * sizeof(float));	// L140

  for (int v94 = 0; v94 < 512; v94 += 1) {	// L141
    for (int v95 = 0; v95 < 3; v95 += 1) {	// L142
      for (int v96 = 0; v96 < 3; v96 += 1) {	// L143
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v93
        #pragma HLS dependence false variable=v92
        float v97 = v93[v94];	// L144
        v92[0][v94][v95][v96] = v97;	// L145
      }
    }
  }
}

void kernel13(
  float v98[1][512][3][3],
  float v99[1][512][5][5]
) {	// L151
  for (int v100 = 0; v100 < 512; v100 += 1) {	// L152
    for (int v101 = 0; v101 < 3; v101 += 1) {	// L153
      for (int v102 = 0; v102 < 3; v102 += 1) {	// L154
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v98
        #pragma HLS dependence false variable=v99
        float v103 = v98[0][v100][v101][v102];	// L155
        v99[0][v100][(v101 + 1)][(v102 + 1)] = v103;	// L156
      }
    }
  }
}

void kernel14(
  float v104[1][512][5][5],
  float v105
) {	// L162
  for (int v106 = 0; v106 < 512; v106 += 1) {	// L163
    for (int v107 = 0; v107 < 5; v107 += 1) {	// L164
      for (int v108 = 0; v108 < 5; v108 += 1) {	// L165
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v104
        v104[0][v106][v107][v108] = v105;	// L166
      }
    }
  }
}

void kernel19(
  float v109[1][512][3][3],
  float v110[1][512][3][3]
) {	// L172
  for (int v111 = 0; v111 < 512; v111 += 1) {	// L173
    for (int v112 = 0; v112 < 3; v112 += 1) {	// L174
      for (int v113 = 0; v113 < 3; v113 += 1) {	// L175
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v109
        #pragma HLS dependence false variable=v110
        float v114 = v109[0][v111][v112][v113];	// L176
        float v115 = v110[0][v111][v112][v113];	// L177
        float v116 = v114 + v115;	// L178
        v110[0][v111][v112][v113] = v116;	// L179
      }
    }
  }
}

void kernel23(
  float v117[1][512][5][5],
  float v118
) {	// L185
  for (int v119 = 0; v119 < 512; v119 += 1) {	// L186
    for (int v120 = 0; v120 < 5; v120 += 1) {	// L187
      for (int v121 = 0; v121 < 5; v121 += 1) {	// L188
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v117
        v117[0][v119][v120][v121] = v118;	// L189
      }
    }
  }
}

void kernel29(
  float v122[1][256][6][6],
  float v123[512][256][1][1],
  float v124[1][512][3][3]
) {	// L195
  auto v125 = reinterpret_cast<float(*)[256][1][1]>(v123);	// L197

  for (int v126 = 0; v126 < 256; v126 += 1) {	// L198
    for (int v127 = 0; v127 < 512; v127 += 1) {	// L199
      for (int v128 = 0; v128 < 3; v128 += 1) {	// L200
        for (int v129 = 0; v129 < 3; v129 += 1) {	// L201
          #pragma HLS pipeline II=1
          #pragma HLS dependence false variable=v122
          #pragma HLS dependence false variable=v124
          #pragma HLS dependence false variable=v125
          float v130 = v122[0][v126][(v128 * 2)][(v129 * 2)];	// L202
          float v131 = v125[v127][v126][0][0];	// L203
          float v132 = v124[0][v127][v128][v129];	// L204
          float v133 = v130 * v131;	// L205
          float v134 = v132 + v133;	// L206
          v124[0][v127][v128][v129] = v134;	// L207
        }
      }
    }
  }
}

void kernel34(
  float v135[1][512][5][5],
  float v136
) {	// L214
  for (int v137 = 0; v137 < 512; v137 += 1) {	// L215
    for (int v138 = 0; v138 < 5; v138 += 1) {	// L216
      for (int v139 = 0; v139 < 5; v139 += 1) {	// L217
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v135
        v135[0][v137][v138][v139] = v136;	// L218
      }
    }
  }
}

void kernel40(
  float v140[1][256][8][8],
  float v141[512][256][3][3],
  float v142[1][512][3][3]
) {	// L224
  auto v143 = reinterpret_cast<float(*)[256][3][3]>(v141);	// L226

  for (int v144 = 0; v144 < 256; v144 += 1) {	// L227
    for (int v145 = 0; v145 < 3; v145 += 1) {	// L228
      for (int v146 = 0; v146 < 3; v146 += 1) {	// L229
        for (int v147 = 0; v147 < 512; v147 += 1) {	// L230
          for (int v148 = 0; v148 < 3; v148 += 1) {	// L231
            for (int v149 = 0; v149 < 3; v149 += 1) {	// L232
              #pragma HLS pipeline II=1
              #pragma HLS dependence false variable=v140
              #pragma HLS dependence false variable=v142
              #pragma HLS dependence false variable=v143
              float v150 = v140[0][v144][((v148 * 2) + v145)][((v149 * 2) + v146)];	// L233
              float v151 = v143[v147][v144][v145][v146];	// L234
              float v152 = v142[0][v147][v148][v149];	// L235
              float v153 = v150 * v151;	// L236
              float v154 = v152 + v153;	// L237
              v142[0][v147][v148][v149] = v154;	// L238
            }
          }
        }
      }
    }
  }
}

void kernel42(
  float v155[1][256][6][6],
  float v156[1][256][8][8]
) {	// L247
  for (int v157 = 0; v157 < 256; v157 += 1) {	// L248
    for (int v158 = 0; v158 < 6; v158 += 1) {	// L249
      for (int v159 = 0; v159 < 6; v159 += 1) {	// L250
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v155
        #pragma HLS dependence false variable=v156
        float v160 = v155[0][v157][v158][v159];	// L251
        v156[0][v157][(v158 + 1)][(v159 + 1)] = v160;	// L252
      }
    }
  }
}

void kernel43(
  float v161[1][256][8][8],
  float v162
) {	// L258
  for (int v163 = 0; v163 < 256; v163 += 1) {	// L259
    for (int v164 = 0; v164 < 8; v164 += 1) {	// L260
      for (int v165 = 0; v165 < 8; v165 += 1) {	// L261
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v161
        v161[0][v163][v164][v165] = v162;	// L262
      }
    }
  }
}

void kernel44(
  float v166[1][256][6][6],
  float v167[1][256][6][6]
) {	// L268
  for (int v168 = 0; v168 < 256; v168 += 1) {	// L269
    for (int v169 = 0; v169 < 6; v169 += 1) {	// L270
      for (int v170 = 0; v170 < 6; v170 += 1) {	// L271
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v166
        #pragma HLS dependence false variable=v167
        float v171 = v166[0][v168][v169][v170];	// L272
        v167[0][v168][v169][v170] = v171;	// L273
      }
    }
  }
}

void kernel45(
  float v172[1][256][6][6],
  float v173[1][256][6][6],
  float v174
) {	// L279
  for (int v175 = 0; v175 < 256; v175 += 1) {	// L280
    for (int v176 = 0; v176 < 6; v176 += 1) {	// L281
      for (int v177 = 0; v177 < 6; v177 += 1) {	// L282
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v173
        #pragma HLS dependence false variable=v172
        float v178 = v173[0][v175][v176][v177];	// L283
        float v179 = v172[0][v175][v176][v177];	// L284
        float v180 = v179 * v174;	// L285
        float v181 = v179 * v178;	// L286
        float v182 = v178 - v181;	// L287
        float v183 = v182 + v180;	// L288
        v173[0][v175][v176][v177] = v183;	// L289
      }
    }
  }
}

void kernel46(
  float v184[1][256][6][6],
  float v185,
  float v186
) {	// L295
  for (int v187 = 0; v187 < 256; v187 += 1) {	// L296
    for (int v188 = 0; v188 < 6; v188 += 1) {	// L297
      for (int v189 = 0; v189 < 6; v189 += 1) {	// L298
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v184
        float v190 = v184[0][v187][v188][v189];	// L299
        float v191 = v190 - v186;	// L300
        bool v192 = v191 >= v185;	// L301
        float v193 = v192 ? v186 : v185;	// L302
        v184[0][v187][v188][v189] = v193;	// L303
      }
    }
  }
}

void kernel48(
  float v194[1][256][6][6],
  float v195[1][256][6][6],
  float v196[1][256][6][6]
) {	// L309
  for (int v197 = 0; v197 < 256; v197 += 1) {	// L310
    for (int v198 = 0; v198 < 6; v198 += 1) {	// L311
      for (int v199 = 0; v199 < 6; v199 += 1) {	// L312
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v195
        #pragma HLS dependence false variable=v196
        #pragma HLS dependence false variable=v194
        float v200 = v195[0][v197][v198][v199];	// L313
        float v201 = v194[0][v197][v198][v199];	// L314
        float v202 = v200 + v201;	// L315
        float v203 = v196[0][v197][v198][v199];	// L316
        float v204 = v203 + v202;	// L317
        v196[0][v197][v198][v199] = v204;	// L318
      }
    }
  }
}

void kernel49(
  float v205[1][256][8][8],
  float v206[256][256][3][3],
  float v207[1][256][6][6]
) {	// L324
  auto v208 = reinterpret_cast<float(*)[256][3][3]>(v206);	// L326

  for (int v209 = 0; v209 < 256; v209 += 1) {	// L327
    for (int v210 = 0; v210 < 3; v210 += 1) {	// L328
      for (int v211 = 0; v211 < 3; v211 += 1) {	// L329
        for (int v212 = 0; v212 < 256; v212 += 1) {	// L330
          for (int v213 = 0; v213 < 6; v213 += 1) {	// L331
            for (int v214 = 0; v214 < 6; v214 += 1) {	// L332
              #pragma HLS pipeline II=1
              #pragma HLS dependence false variable=v205
              #pragma HLS dependence false variable=v207
              #pragma HLS dependence false variable=v208
              float v215 = v205[0][v209][(v213 + v210)][(v214 + v211)];	// L333
              float v216 = v208[v212][v209][v210][v211];	// L334
              float v217 = v207[0][v212][v213][v214];	// L335
              float v218 = v215 * v216;	// L336
              float v219 = v217 + v218;	// L337
              v207[0][v212][v213][v214] = v219;	// L338
            }
          }
        }
      }
    }
  }
}

void kernel50(
  float v220[256],
  float v221[1][256][6][6]
) {	// L347
  float v222[256];	// L348
  #pragma HLS resource variable=v222 core=ram_t2p_bram

  memcpy(v222, v220, 256 * sizeof(float));	// L349

  for (int v223 = 0; v223 < 256; v223 += 1) {	// L350
    for (int v224 = 0; v224 < 6; v224 += 1) {	// L351
      for (int v225 = 0; v225 < 6; v225 += 1) {	// L352
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v222
        #pragma HLS dependence false variable=v221
        float v226 = v222[v223];	// L353
        v221[0][v223][v224][v225] = v226;	// L354
      }
    }
  }
}

void kernel52(
  float v227[1][256][8][8],
  float v228
) {	// L360
  for (int v229 = 0; v229 < 256; v229 += 1) {	// L361
    for (int v230 = 0; v230 < 8; v230 += 1) {	// L362
      for (int v231 = 0; v231 < 8; v231 += 1) {	// L363
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v227
        v227[0][v229][v230][v231] = v228;	// L364
      }
    }
  }
}

void kernel57(
  float v232[1][256][6][6],
  float v233[1][256][6][6]
) {	// L370
  for (int v234 = 0; v234 < 256; v234 += 1) {	// L371
    for (int v235 = 0; v235 < 6; v235 += 1) {	// L372
      for (int v236 = 0; v236 < 6; v236 += 1) {	// L373
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v232
        #pragma HLS dependence false variable=v233
        float v237 = v232[0][v234][v235][v236];	// L374
        float v238 = v233[0][v234][v235][v236];	// L375
        float v239 = v237 + v238;	// L376
        v233[0][v234][v235][v236] = v239;	// L377
      }
    }
  }
}

void kernel61(
  float v240[1][256][8][8],
  float v241
) {	// L383
  for (int v242 = 0; v242 < 256; v242 += 1) {	// L384
    for (int v243 = 0; v243 < 8; v243 += 1) {	// L385
      for (int v244 = 0; v244 < 8; v244 += 1) {	// L386
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v240
        v240[0][v242][v243][v244] = v241;	// L387
      }
    }
  }
}

void kernel67(
  float v245[1][128][12][12],
  float v246[256][128][1][1],
  float v247[1][256][6][6]
) {	// L393
  auto v248 = reinterpret_cast<float(*)[128][1][1]>(v246);	// L395

  for (int v249 = 0; v249 < 128; v249 += 1) {	// L396
    for (int v250 = 0; v250 < 256; v250 += 1) {	// L397
      for (int v251 = 0; v251 < 6; v251 += 1) {	// L398
        for (int v252 = 0; v252 < 6; v252 += 1) {	// L399
          #pragma HLS pipeline II=1
          #pragma HLS dependence false variable=v245
          #pragma HLS dependence false variable=v247
          #pragma HLS dependence false variable=v248
          float v253 = v245[0][v249][(v251 * 2)][(v252 * 2)];	// L400
          float v254 = v248[v250][v249][0][0];	// L401
          float v255 = v247[0][v250][v251][v252];	// L402
          float v256 = v253 * v254;	// L403
          float v257 = v255 + v256;	// L404
          v247[0][v250][v251][v252] = v257;	// L405
        }
      }
    }
  }
}

void kernel72(
  float v258[1][256][8][8],
  float v259
) {	// L412
  for (int v260 = 0; v260 < 256; v260 += 1) {	// L413
    for (int v261 = 0; v261 < 8; v261 += 1) {	// L414
      for (int v262 = 0; v262 < 8; v262 += 1) {	// L415
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v258
        v258[0][v260][v261][v262] = v259;	// L416
      }
    }
  }
}

void kernel78(
  float v263[1][128][14][14],
  float v264[256][128][3][3],
  float v265[1][256][6][6]
) {	// L422
  auto v266 = reinterpret_cast<float(*)[128][3][3]>(v264);	// L424

  for (int v267 = 0; v267 < 128; v267 += 1) {	// L425
    for (int v268 = 0; v268 < 3; v268 += 1) {	// L426
      for (int v269 = 0; v269 < 3; v269 += 1) {	// L427
        for (int v270 = 0; v270 < 256; v270 += 1) {	// L428
          for (int v271 = 0; v271 < 6; v271 += 1) {	// L429
            for (int v272 = 0; v272 < 6; v272 += 1) {	// L430
              #pragma HLS pipeline II=1
              #pragma HLS dependence false variable=v263
              #pragma HLS dependence false variable=v265
              #pragma HLS dependence false variable=v266
              float v273 = v263[0][v267][((v271 * 2) + v268)][((v272 * 2) + v269)];	// L431
              float v274 = v266[v270][v267][v268][v269];	// L432
              float v275 = v265[0][v270][v271][v272];	// L433
              float v276 = v273 * v274;	// L434
              float v277 = v275 + v276;	// L435
              v265[0][v270][v271][v272] = v277;	// L436
            }
          }
        }
      }
    }
  }
}

void kernel80(
  float v278[1][128][12][12],
  float v279[1][128][14][14]
) {	// L445
  for (int v280 = 0; v280 < 128; v280 += 1) {	// L446
    for (int v281 = 0; v281 < 12; v281 += 1) {	// L447
      for (int v282 = 0; v282 < 12; v282 += 1) {	// L448
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v278
        #pragma HLS dependence false variable=v279
        float v283 = v278[0][v280][v281][v282];	// L449
        v279[0][v280][(v281 + 1)][(v282 + 1)] = v283;	// L450
      }
    }
  }
}

void kernel81(
  float v284[1][128][14][14],
  float v285
) {	// L456
  for (int v286 = 0; v286 < 128; v286 += 1) {	// L457
    for (int v287 = 0; v287 < 14; v287 += 1) {	// L458
      for (int v288 = 0; v288 < 14; v288 += 1) {	// L459
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v284
        v284[0][v286][v287][v288] = v285;	// L460
      }
    }
  }
}

void kernel82(
  float v289[1][128][12][12],
  float v290[1][128][12][12]
) {	// L466
  for (int v291 = 0; v291 < 128; v291 += 1) {	// L467
    for (int v292 = 0; v292 < 12; v292 += 1) {	// L468
      for (int v293 = 0; v293 < 12; v293 += 1) {	// L469
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v289
        #pragma HLS dependence false variable=v290
        float v294 = v289[0][v291][v292][v293];	// L470
        v290[0][v291][v292][v293] = v294;	// L471
      }
    }
  }
}

void kernel83(
  float v295[1][128][12][12],
  float v296[1][128][12][12],
  float v297
) {	// L477
  for (int v298 = 0; v298 < 128; v298 += 1) {	// L478
    for (int v299 = 0; v299 < 12; v299 += 1) {	// L479
      for (int v300 = 0; v300 < 12; v300 += 1) {	// L480
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v296
        #pragma HLS dependence false variable=v295
        float v301 = v296[0][v298][v299][v300];	// L481
        float v302 = v295[0][v298][v299][v300];	// L482
        float v303 = v302 * v297;	// L483
        float v304 = v302 * v301;	// L484
        float v305 = v301 - v304;	// L485
        float v306 = v305 + v303;	// L486
        v296[0][v298][v299][v300] = v306;	// L487
      }
    }
  }
}

void kernel84(
  float v307[1][128][12][12],
  float v308,
  float v309
) {	// L493
  for (int v310 = 0; v310 < 128; v310 += 1) {	// L494
    for (int v311 = 0; v311 < 12; v311 += 1) {	// L495
      for (int v312 = 0; v312 < 12; v312 += 1) {	// L496
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v307
        float v313 = v307[0][v310][v311][v312];	// L497
        float v314 = v313 - v309;	// L498
        bool v315 = v314 >= v308;	// L499
        float v316 = v315 ? v309 : v308;	// L500
        v307[0][v310][v311][v312] = v316;	// L501
      }
    }
  }
}

void kernel86(
  float v317[1][128][12][12],
  float v318[1][128][12][12],
  float v319[1][128][12][12]
) {	// L507
  for (int v320 = 0; v320 < 128; v320 += 1) {	// L508
    for (int v321 = 0; v321 < 12; v321 += 1) {	// L509
      for (int v322 = 0; v322 < 12; v322 += 1) {	// L510
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v318
        #pragma HLS dependence false variable=v319
        #pragma HLS dependence false variable=v317
        float v323 = v318[0][v320][v321][v322];	// L511
        float v324 = v317[0][v320][v321][v322];	// L512
        float v325 = v323 + v324;	// L513
        float v326 = v319[0][v320][v321][v322];	// L514
        float v327 = v326 + v325;	// L515
        v319[0][v320][v321][v322] = v327;	// L516
      }
    }
  }
}

void kernel87(
  float v328[1][128][14][14],
  float v329[128][128][3][3],
  float v330[1][128][12][12]
) {	// L522
  auto v331 = reinterpret_cast<float(*)[128][3][3]>(v329);	// L524

  for (int v332 = 0; v332 < 128; v332 += 1) {	// L525
    for (int v333 = 0; v333 < 3; v333 += 1) {	// L526
      for (int v334 = 0; v334 < 3; v334 += 1) {	// L527
        for (int v335 = 0; v335 < 128; v335 += 1) {	// L528
          for (int v336 = 0; v336 < 12; v336 += 1) {	// L529
            for (int v337 = 0; v337 < 12; v337 += 1) {	// L530
              #pragma HLS pipeline II=1
              #pragma HLS dependence false variable=v328
              #pragma HLS dependence false variable=v330
              #pragma HLS dependence false variable=v331
              float v338 = v328[0][v332][(v336 + v333)][(v337 + v334)];	// L531
              float v339 = v331[v335][v332][v333][v334];	// L532
              float v340 = v330[0][v335][v336][v337];	// L533
              float v341 = v338 * v339;	// L534
              float v342 = v340 + v341;	// L535
              v330[0][v335][v336][v337] = v342;	// L536
            }
          }
        }
      }
    }
  }
}

void kernel88(
  float v343[128],
  float v344[1][128][12][12]
) {	// L545
  float v345[128];	// L546
  #pragma HLS resource variable=v345 core=ram_t2p_bram

  memcpy(v345, v343, 128 * sizeof(float));	// L547

  for (int v346 = 0; v346 < 128; v346 += 1) {	// L548
    for (int v347 = 0; v347 < 12; v347 += 1) {	// L549
      for (int v348 = 0; v348 < 12; v348 += 1) {	// L550
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v345
        #pragma HLS dependence false variable=v344
        float v349 = v345[v346];	// L551
        v344[0][v346][v347][v348] = v349;	// L552
      }
    }
  }
}

void kernel90(
  float v350[1][128][14][14],
  float v351
) {	// L558
  for (int v352 = 0; v352 < 128; v352 += 1) {	// L559
    for (int v353 = 0; v353 < 14; v353 += 1) {	// L560
      for (int v354 = 0; v354 < 14; v354 += 1) {	// L561
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v350
        v350[0][v352][v353][v354] = v351;	// L562
      }
    }
  }
}

void kernel95(
  float v355[1][128][12][12],
  float v356[1][128][12][12]
) {	// L568
  for (int v357 = 0; v357 < 128; v357 += 1) {	// L569
    for (int v358 = 0; v358 < 12; v358 += 1) {	// L570
      for (int v359 = 0; v359 < 12; v359 += 1) {	// L571
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v355
        #pragma HLS dependence false variable=v356
        float v360 = v355[0][v357][v358][v359];	// L572
        float v361 = v356[0][v357][v358][v359];	// L573
        float v362 = v360 + v361;	// L574
        v356[0][v357][v358][v359] = v362;	// L575
      }
    }
  }
}

void kernel99(
  float v363[1][128][14][14],
  float v364
) {	// L581
  for (int v365 = 0; v365 < 128; v365 += 1) {	// L582
    for (int v366 = 0; v366 < 14; v366 += 1) {	// L583
      for (int v367 = 0; v367 < 14; v367 += 1) {	// L584
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v363
        v363[0][v365][v366][v367] = v364;	// L585
      }
    }
  }
}

void kernel105(
  float v368[1][64][24][24],
  float v369[128][64][1][1],
  float v370[1][128][12][12]
) {	// L591
  float v371[128][64][1][1];	// L592
  #pragma HLS resource variable=v371 core=ram_t2p_bram

  memcpy(v371, v369, 8192 * sizeof(float));	// L593

  for (int v372 = 0; v372 < 64; v372 += 1) {	// L594
    for (int v373 = 0; v373 < 128; v373 += 1) {	// L595
      for (int v374 = 0; v374 < 12; v374 += 1) {	// L596
        for (int v375 = 0; v375 < 12; v375 += 1) {	// L597
          #pragma HLS pipeline II=1
          #pragma HLS dependence false variable=v368
          #pragma HLS dependence false variable=v370
          #pragma HLS dependence false variable=v371
          float v376 = v368[0][v372][(v374 * 2)][(v375 * 2)];	// L598
          float v377 = v371[v373][v372][0][0];	// L599
          float v378 = v370[0][v373][v374][v375];	// L600
          float v379 = v376 * v377;	// L601
          float v380 = v378 + v379;	// L602
          v370[0][v373][v374][v375] = v380;	// L603
        }
      }
    }
  }
}

void kernel110(
  float v381[1][128][14][14],
  float v382
) {	// L610
  for (int v383 = 0; v383 < 128; v383 += 1) {	// L611
    for (int v384 = 0; v384 < 14; v384 += 1) {	// L612
      for (int v385 = 0; v385 < 14; v385 += 1) {	// L613
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v381
        v381[0][v383][v384][v385] = v382;	// L614
      }
    }
  }
}

void kernel116(
  float v386[1][64][26][26],
  float v387[128][64][3][3],
  float v388[1][128][12][12]
) {	// L620
  auto v389 = reinterpret_cast<float(*)[64][3][3]>(v387);	// L622

  for (int v390 = 0; v390 < 64; v390 += 1) {	// L623
    for (int v391 = 0; v391 < 3; v391 += 1) {	// L624
      for (int v392 = 0; v392 < 3; v392 += 1) {	// L625
        for (int v393 = 0; v393 < 128; v393 += 1) {	// L626
          for (int v394 = 0; v394 < 12; v394 += 1) {	// L627
            for (int v395 = 0; v395 < 12; v395 += 1) {	// L628
              #pragma HLS pipeline II=1
              #pragma HLS dependence false variable=v386
              #pragma HLS dependence false variable=v388
              #pragma HLS dependence false variable=v389
              float v396 = v386[0][v390][((v394 * 2) + v391)][((v395 * 2) + v392)];	// L629
              float v397 = v389[v393][v390][v391][v392];	// L630
              float v398 = v388[0][v393][v394][v395];	// L631
              float v399 = v396 * v397;	// L632
              float v400 = v398 + v399;	// L633
              v388[0][v393][v394][v395] = v400;	// L634
            }
          }
        }
      }
    }
  }
}

void kernel118(
  float v401[1][64][24][24],
  float v402[1][64][26][26]
) {	// L643
  for (int v403 = 0; v403 < 64; v403 += 1) {	// L644
    for (int v404 = 0; v404 < 24; v404 += 1) {	// L645
      for (int v405 = 0; v405 < 24; v405 += 1) {	// L646
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v401
        #pragma HLS dependence false variable=v402
        float v406 = v401[0][v403][v404][v405];	// L647
        v402[0][v403][(v404 + 1)][(v405 + 1)] = v406;	// L648
      }
    }
  }
}

void kernel119(
  float v407[1][64][26][26],
  float v408
) {	// L654
  for (int v409 = 0; v409 < 64; v409 += 1) {	// L655
    for (int v410 = 0; v410 < 26; v410 += 1) {	// L656
      for (int v411 = 0; v411 < 26; v411 += 1) {	// L657
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v407
        v407[0][v409][v410][v411] = v408;	// L658
      }
    }
  }
}

void kernel120(
  float v412[1][64][24][24],
  float v413[1][64][24][24]
) {	// L664
  for (int v414 = 0; v414 < 64; v414 += 1) {	// L665
    for (int v415 = 0; v415 < 24; v415 += 1) {	// L666
      for (int v416 = 0; v416 < 24; v416 += 1) {	// L667
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v412
        #pragma HLS dependence false variable=v413
        float v417 = v412[0][v414][v415][v416];	// L668
        v413[0][v414][v415][v416] = v417;	// L669
      }
    }
  }
}

void kernel121(
  float v418[1][64][24][24],
  float v419[1][64][24][24],
  float v420
) {	// L675
  for (int v421 = 0; v421 < 64; v421 += 1) {	// L676
    for (int v422 = 0; v422 < 24; v422 += 1) {	// L677
      for (int v423 = 0; v423 < 24; v423 += 1) {	// L678
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v419
        #pragma HLS dependence false variable=v418
        float v424 = v419[0][v421][v422][v423];	// L679
        float v425 = v418[0][v421][v422][v423];	// L680
        float v426 = v425 * v420;	// L681
        float v427 = v425 * v424;	// L682
        float v428 = v424 - v427;	// L683
        float v429 = v428 + v426;	// L684
        v419[0][v421][v422][v423] = v429;	// L685
      }
    }
  }
}

void kernel122(
  float v430[1][64][24][24],
  float v431,
  float v432
) {	// L691
  for (int v433 = 0; v433 < 64; v433 += 1) {	// L692
    for (int v434 = 0; v434 < 24; v434 += 1) {	// L693
      for (int v435 = 0; v435 < 24; v435 += 1) {	// L694
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v430
        float v436 = v430[0][v433][v434][v435];	// L695
        float v437 = v436 - v432;	// L696
        bool v438 = v437 >= v431;	// L697
        float v439 = v438 ? v432 : v431;	// L698
        v430[0][v433][v434][v435] = v439;	// L699
      }
    }
  }
}

void kernel124(
  float v440[1][64][24][24],
  float v441[1][64][24][24],
  float v442[1][64][24][24]
) {	// L705
  for (int v443 = 0; v443 < 64; v443 += 1) {	// L706
    for (int v444 = 0; v444 < 24; v444 += 1) {	// L707
      for (int v445 = 0; v445 < 24; v445 += 1) {	// L708
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v441
        #pragma HLS dependence false variable=v442
        #pragma HLS dependence false variable=v440
        float v446 = v441[0][v443][v444][v445];	// L709
        float v447 = v440[0][v443][v444][v445];	// L710
        float v448 = v446 + v447;	// L711
        float v449 = v442[0][v443][v444][v445];	// L712
        float v450 = v449 + v448;	// L713
        v442[0][v443][v444][v445] = v450;	// L714
      }
    }
  }
}

void kernel125(
  float v451[1][64][26][26],
  float v452[64][64][3][3],
  float v453[1][64][24][24]
) {	// L720
  auto v454 = reinterpret_cast<float(*)[64][3][3]>(v452);	// L722

  for (int v455 = 0; v455 < 64; v455 += 1) {	// L723
    for (int v456 = 0; v456 < 3; v456 += 1) {	// L724
      for (int v457 = 0; v457 < 3; v457 += 1) {	// L725
        for (int v458 = 0; v458 < 64; v458 += 1) {	// L726
          for (int v459 = 0; v459 < 24; v459 += 1) {	// L727
            for (int v460 = 0; v460 < 24; v460 += 1) {	// L728
              #pragma HLS pipeline II=1
              #pragma HLS dependence false variable=v451
              #pragma HLS dependence false variable=v453
              #pragma HLS dependence false variable=v454
              float v461 = v451[0][v455][(v459 + v456)][(v460 + v457)];	// L729
              float v462 = v454[v458][v455][v456][v457];	// L730
              float v463 = v453[0][v458][v459][v460];	// L731
              float v464 = v461 * v462;	// L732
              float v465 = v463 + v464;	// L733
              v453[0][v458][v459][v460] = v465;	// L734
            }
          }
        }
      }
    }
  }
}

void kernel126(
  float v466[64],
  float v467[1][64][24][24]
) {	// L743
  float v468[64];	// L744
  #pragma HLS resource variable=v468 core=ram_t2p_bram

  memcpy(v468, v466, 64 * sizeof(float));	// L745

  for (int v469 = 0; v469 < 64; v469 += 1) {	// L746
    for (int v470 = 0; v470 < 24; v470 += 1) {	// L747
      for (int v471 = 0; v471 < 24; v471 += 1) {	// L748
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v468
        #pragma HLS dependence false variable=v467
        float v472 = v468[v469];	// L749
        v467[0][v469][v470][v471] = v472;	// L750
      }
    }
  }
}

void kernel128(
  float v473[1][64][26][26],
  float v474
) {	// L756
  for (int v475 = 0; v475 < 64; v475 += 1) {	// L757
    for (int v476 = 0; v476 < 26; v476 += 1) {	// L758
      for (int v477 = 0; v477 < 26; v477 += 1) {	// L759
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v473
        v473[0][v475][v476][v477] = v474;	// L760
      }
    }
  }
}

void kernel133(
  float v478[1][64][24][24],
  float v479[1][64][24][24]
) {	// L766
  for (int v480 = 0; v480 < 64; v480 += 1) {	// L767
    for (int v481 = 0; v481 < 24; v481 += 1) {	// L768
      for (int v482 = 0; v482 < 24; v482 += 1) {	// L769
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v478
        #pragma HLS dependence false variable=v479
        float v483 = v478[0][v480][v481][v482];	// L770
        float v484 = v479[0][v480][v481][v482];	// L771
        float v485 = v483 + v484;	// L772
        v479[0][v480][v481][v482] = v485;	// L773
      }
    }
  }
}

void kernel137(
  float v486[1][64][26][26],
  float v487
) {	// L779
  for (int v488 = 0; v488 < 64; v488 += 1) {	// L780
    for (int v489 = 0; v489 < 26; v489 += 1) {	// L781
      for (int v490 = 0; v490 < 26; v490 += 1) {	// L782
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v486
        v486[0][v488][v489][v490] = v487;	// L783
      }
    }
  }
}

void kernel146(
  float v491[1][64][26][26],
  float v492
) {	// L789
  for (int v493 = 0; v493 < 64; v493 += 1) {	// L790
    for (int v494 = 0; v494 < 26; v494 += 1) {	// L791
      for (int v495 = 0; v495 < 26; v495 += 1) {	// L792
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v491
        v491[0][v493][v494][v495] = v492;	// L793
      }
    }
  }
}

void kernel155(
  float v496[1][64][26][26],
  float v497
) {	// L799
  for (int v498 = 0; v498 < 64; v498 += 1) {	// L800
    for (int v499 = 0; v499 < 26; v499 += 1) {	// L801
      for (int v500 = 0; v500 < 26; v500 += 1) {	// L802
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v496
        v496[0][v498][v499][v500] = v497;	// L803
      }
    }
  }
}

void kernel156(
  float v501[1][64][50][50],
  float v502[3][3],
  float v503[1][64][24][24]
) {	// L809
  for (int v504 = 0; v504 < 3; v504 += 1) {	// L810
    for (int v505 = 0; v505 < 3; v505 += 1) {	// L811
      for (int v506 = 0; v506 < 64; v506 += 1) {	// L812
        for (int v507 = 0; v507 < 24; v507 += 1) {	// L813
          for (int v508 = 0; v508 < 24; v508 += 1) {	// L814
            #pragma HLS pipeline II=1
            #pragma HLS dependence false variable=v501
            #pragma HLS dependence false variable=v503
            float v509 = v501[0][v506][((v507 * 2) + v504)][((v508 * 2) + v505)];	// L815
            float v510 = v503[0][v506][v507][v508];	// L816
            float v511 = max(v510, v509);	// L817
            v503[0][v506][v507][v508] = v511;	// L818
          }
        }
      }
    }
  }
}

void kernel157(
  float v512[1][64][24][24],
  float v513
) {	// L826
  for (int v514 = 0; v514 < 64; v514 += 1) {	// L827
    for (int v515 = 0; v515 < 24; v515 += 1) {	// L828
      for (int v516 = 0; v516 < 24; v516 += 1) {	// L829
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v512
        v512[0][v514][v515][v516] = v513;	// L830
      }
    }
  }
}

void kernel158(
  float v517[1][64][48][48],
  float v518[1][64][50][50]
) {	// L836
  for (int v519 = 0; v519 < 64; v519 += 1) {	// L837
    for (int v520 = 0; v520 < 48; v520 += 1) {	// L838
      for (int v521 = 0; v521 < 48; v521 += 1) {	// L839
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v517
        #pragma HLS dependence false variable=v518
        float v522 = v517[0][v519][v520][v521];	// L840
        v518[0][v519][(v520 + 1)][(v521 + 1)] = v522;	// L841
      }
    }
  }
}

void kernel159(
  float v523[1][64][50][50],
  float v524
) {	// L847
  for (int v525 = 0; v525 < 64; v525 += 1) {	// L848
    for (int v526 = 0; v526 < 50; v526 += 1) {	// L849
      for (int v527 = 0; v527 < 50; v527 += 1) {	// L850
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v523
        v523[0][v525][v526][v527] = v524;	// L851
      }
    }
  }
}

void kernel160(
  float v528[1][64][48][48],
  float v529[1][64][48][48]
) {	// L857
  for (int v530 = 0; v530 < 64; v530 += 1) {	// L858
    for (int v531 = 0; v531 < 48; v531 += 1) {	// L859
      for (int v532 = 0; v532 < 48; v532 += 1) {	// L860
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v528
        #pragma HLS dependence false variable=v529
        float v533 = v528[0][v530][v531][v532];	// L861
        v529[0][v530][v531][v532] = v533;	// L862
      }
    }
  }
}

void kernel161(
  float v534[1][64][48][48],
  float v535[1][64][48][48],
  float v536
) {	// L868
  for (int v537 = 0; v537 < 64; v537 += 1) {	// L869
    for (int v538 = 0; v538 < 48; v538 += 1) {	// L870
      for (int v539 = 0; v539 < 48; v539 += 1) {	// L871
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v535
        #pragma HLS dependence false variable=v534
        float v540 = v535[0][v537][v538][v539];	// L872
        float v541 = v534[0][v537][v538][v539];	// L873
        float v542 = v541 * v536;	// L874
        float v543 = v541 * v540;	// L875
        float v544 = v540 - v543;	// L876
        float v545 = v544 + v542;	// L877
        v535[0][v537][v538][v539] = v545;	// L878
      }
    }
  }
}

void kernel162(
  float v546[1][64][48][48],
  float v547,
  float v548
) {	// L884
  for (int v549 = 0; v549 < 64; v549 += 1) {	// L885
    for (int v550 = 0; v550 < 48; v550 += 1) {	// L886
      for (int v551 = 0; v551 < 48; v551 += 1) {	// L887
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v546
        float v552 = v546[0][v549][v550][v551];	// L888
        float v553 = v552 - v548;	// L889
        bool v554 = v553 >= v547;	// L890
        float v555 = v554 ? v548 : v547;	// L891
        v546[0][v549][v550][v551] = v555;	// L892
      }
    }
  }
}

void kernel164(
  float v556[1][64][48][48],
  float v557[1][64][48][48]
) {	// L898
  for (int v558 = 0; v558 < 64; v558 += 1) {	// L899
    for (int v559 = 0; v559 < 48; v559 += 1) {	// L900
      for (int v560 = 0; v560 < 48; v560 += 1) {	// L901
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v556
        #pragma HLS dependence false variable=v557
        float v561 = v556[0][v558][v559][v560];	// L902
        float v562 = v557[0][v558][v559][v560];	// L903
        float v563 = v561 + v562;	// L904
        v557[0][v558][v559][v560] = v563;	// L905
      }
    }
  }
}

void kernel165(
  float v564[1][1][102][102],
  float v565[64][1][7][7],
  float v566[1][64][48][48]
) {	// L911
  float v567[64][1][7][7];	// L912
  #pragma HLS resource variable=v567 core=ram_t2p_bram

  memcpy(v567, v565, 3136 * sizeof(float));	// L913

  for (int v568 = 0; v568 < 7; v568 += 1) {	// L914
    for (int v569 = 0; v569 < 7; v569 += 1) {	// L915
      for (int v570 = 0; v570 < 64; v570 += 1) {	// L916
        for (int v571 = 0; v571 < 48; v571 += 1) {	// L917
          for (int v572 = 0; v572 < 48; v572 += 1) {	// L918
            #pragma HLS pipeline II=1
            #pragma HLS dependence false variable=v564
            #pragma HLS dependence false variable=v566
            #pragma HLS dependence false variable=v567
            float v573 = v564[0][0][((v571 * 2) + v568)][((v572 * 2) + v569)];	// L919
            float v574 = v567[v570][0][v568][v569];	// L920
            float v575 = v566[0][v570][v571][v572];	// L921
            float v576 = v573 * v574;	// L922
            float v577 = v575 + v576;	// L923
            v566[0][v570][v571][v572] = v577;	// L924
          }
        }
      }
    }
  }
}

void kernel166(
  float v578[64],
  float v579[1][64][48][48]
) {	// L932
  float v580[64];	// L933
  #pragma HLS resource variable=v580 core=ram_t2p_bram

  memcpy(v580, v578, 64 * sizeof(float));	// L934

  for (int v581 = 0; v581 < 64; v581 += 1) {	// L935
    for (int v582 = 0; v582 < 48; v582 += 1) {	// L936
      for (int v583 = 0; v583 < 48; v583 += 1) {	// L937
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v580
        #pragma HLS dependence false variable=v579
        float v584 = v580[v581];	// L938
        v579[0][v581][v582][v583] = v584;	// L939
      }
    }
  }
}

void kernel167(
  float v585[1][1][96][96],
  float v586[1][1][102][102]
) {	// L945
  for (int v587 = 0; v587 < 96; v587 += 1) {	// L946
    for (int v588 = 0; v588 < 96; v588 += 1) {	// L947
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v585
      #pragma HLS dependence false variable=v586
      float v589 = v585[0][0][v587][v588];	// L948
      v586[0][0][(v587 + 3)][(v588 + 3)] = v589;	// L949
    }
  }
}

void kernel168(
  float v590[1][1][102][102],
  float v591
) {	// L954
  for (int v592 = 0; v592 < 102; v592 += 1) {	// L955
    for (int v593 = 0; v593 < 102; v593 += 1) {	// L956
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v590
      v590[0][0][v592][v593] = v591;	// L957
    }
  }
}

/// The top function
void control(
  ap_int<32> v594[102692096],
  ap_int<32> v595[102692096],
  ap_int<32> v596[102692096]
) {	// L962
  #pragma HLS interface s_axilite port=return bundle=ctrl
  #pragma hls interface m_axi offset=direct bundle=g0 port=v594
  #pragma hls stable variable=v594
  #pragma hls interface m_axi offset=direct bundle=g0 port=v595
  #pragma hls stable variable=v595
  #pragma hls interface m_axi offset=direct bundle=g0 port=v596
  #pragma hls stable variable=v596

  auto v597 = reinterpret_cast<float(*)[1][102][102]>(v594 + 2801664);
  kernel168(v597, (float)0.000000);	// L968
  auto v598 = reinterpret_cast<float(*)[1][96][96]>(v594);
  kernel167(v598, v597);	// L970
  auto v599 = reinterpret_cast<float(*)[64][48][48]>(v595 + 2961664);
  auto v600 = reinterpret_cast<float(*)>(v596 + 95614208);
  kernel166(v600, v599);	// L973
  auto v601 = reinterpret_cast<float(*)[1][7][7]>(v596 + 97973504);
  kernel165(v597, v601, v599);	// L975
  auto v602 = reinterpret_cast<float(*)[64][48][48]>(v594 + 147456);
  kernel164(v602, v599);	// L977
  auto v603 = reinterpret_cast<float(*)[64][48][48]>(v594 + 2801664);
  kernel160(v599, v603);	// L979
  kernel162(v603, (float)0.000000, (float)1.000000);	// L980
  kernel161(v603, v599, (float)0.000000);	// L981
  kernel160(v599, v602);	// L982
  auto v604 = reinterpret_cast<float(*)[64][50][50]>(v595 + 2961664);
  kernel159(v604, (float)-INFINITY);	// L984
  kernel158(v603, v604);	// L985
  auto v605 = reinterpret_cast<float(*)[64][24][24]>(v594 + 2801664);
  kernel157(v605, (float)-INFINITY);	// L987
  auto v606 = reinterpret_cast<float(*)[3]>(v594 + 3121664);
  kernel156(v604, v606, v605);	// L989
  auto v607 = reinterpret_cast<float(*)[64][26][26]>(v595 + 2961664);
  kernel155(v607, (float)0.000000);	// L991
  kernel118(v605, v607);	// L992
  auto v608 = reinterpret_cast<float(*)[64][24][24]>(v595 + 3281664);
  auto v609 = reinterpret_cast<float(*)>(v596 + 90895616);
  kernel126(v609, v608);	// L995
  auto v610 = reinterpret_cast<float(*)[64][3][3]>(v596 + 93254912);
  kernel125(v607, v610, v608);	// L997
  auto v611 = reinterpret_cast<float(*)[64][24][24]>(v594 + 294912);
  kernel133(v611, v608);	// L999
  auto v612 = reinterpret_cast<float(*)[64][24][24]>(v595 + 2961664);
  kernel120(v608, v612);	// L1001
  kernel122(v612, (float)0.000000, (float)1.000000);	// L1002
  kernel121(v612, v608, (float)0.000000);	// L1003
  kernel120(v608, v611);	// L1004
  auto v613 = reinterpret_cast<float(*)[64][26][26]>(v594 + 3441664);
  kernel146(v613, (float)0.000000);	// L1006
  kernel118(v612, v613);	// L1007
  auto v614 = reinterpret_cast<float(*)>(v596 + 86177024);
  kernel126(v614, v608);	// L1009
  auto v615 = reinterpret_cast<float(*)[64][3][3]>(v596 + 88536320);
  kernel125(v613, v615, v608);	// L1011
  auto v616 = reinterpret_cast<float(*)[64][24][24]>(v594 + 442368);
  kernel124(v605, v616, v608);	// L1013
  auto v617 = reinterpret_cast<float(*)[64][24][24]>(v596 + 2801664);
  kernel120(v608, v617);	// L1015
  kernel122(v617, (float)0.000000, (float)1.000000);	// L1016
  kernel121(v617, v608, (float)0.000000);	// L1017
  kernel120(v608, v616);	// L1018
  auto v618 = reinterpret_cast<float(*)[64][26][26]>(v594 + 2961664);
  kernel137(v618, (float)0.000000);	// L1020
  kernel118(v617, v618);	// L1021
  auto v619 = reinterpret_cast<float(*)>(v596 + 81458432);
  kernel126(v619, v608);	// L1023
  auto v620 = reinterpret_cast<float(*)[64][3][3]>(v596 + 83817728);
  kernel125(v618, v620, v608);	// L1025
  auto v621 = reinterpret_cast<float(*)[64][24][24]>(v594 + 589824);
  kernel133(v621, v608);	// L1027
  auto v622 = reinterpret_cast<float(*)[64][24][24]>(v594 + 2961664);
  kernel120(v608, v622);	// L1029
  kernel122(v622, (float)0.000000, (float)1.000000);	// L1030
  kernel121(v622, v608, (float)0.000000);	// L1031
  kernel120(v608, v621);	// L1032
  auto v623 = reinterpret_cast<float(*)[64][26][26]>(v595 + 3441664);
  kernel128(v623, (float)0.000000);	// L1034
  kernel118(v622, v623);	// L1035
  auto v624 = reinterpret_cast<float(*)>(v596 + 76739840);
  kernel126(v624, v608);	// L1037
  auto v625 = reinterpret_cast<float(*)[64][3][3]>(v596 + 79099136);
  kernel125(v623, v625, v608);	// L1039
  auto v626 = reinterpret_cast<float(*)[64][24][24]>(v594 + 737280);
  kernel124(v617, v626, v608);	// L1041
  auto v627 = reinterpret_cast<float(*)[64][24][24]>(v595 + 2801664);
  kernel120(v608, v627);	// L1043
  kernel122(v627, (float)0.000000, (float)1.000000);	// L1044
  kernel121(v627, v608, (float)0.000000);	// L1045
  kernel120(v608, v626);	// L1046
  kernel119(v607, (float)0.000000);	// L1047
  kernel118(v627, v607);	// L1048
  auto v628 = reinterpret_cast<float(*)[128][12][12]>(v594 + 3281664);
  auto v629 = reinterpret_cast<float(*)>(v596 + 72021248);
  kernel88(v629, v628);	// L1051
  auto v630 = reinterpret_cast<float(*)[64][3][3]>(v596 + 74380544);
  kernel116(v607, v630, v628);	// L1053
  auto v631 = reinterpret_cast<float(*)[128][12][12]>(v594 + 884736);
  kernel95(v631, v628);	// L1055
  auto v632 = reinterpret_cast<float(*)[128][12][12]>(v595 + 2961664);
  kernel82(v628, v632);	// L1057
  kernel84(v632, (float)0.000000, (float)1.000000);	// L1058
  kernel83(v632, v628, (float)0.000000);	// L1059
  kernel82(v628, v631);	// L1060
  auto v633 = reinterpret_cast<float(*)[128][14][14]>(v594 + 3441664);
  kernel110(v633, (float)0.000000);	// L1062
  kernel80(v632, v633);	// L1063
  auto v634 = reinterpret_cast<float(*)[128][12][12]>(v594 + 2961664);
  auto v635 = reinterpret_cast<float(*)>(v596 + 67302656);
  kernel88(v635, v634);	// L1066
  auto v636 = reinterpret_cast<float(*)[128][3][3]>(v596 + 69661952);
  kernel87(v633, v636, v634);	// L1068
  auto v637 = reinterpret_cast<float(*)>(v596 + 62584064);
  kernel88(v637, v628);	// L1070
  auto v638 = reinterpret_cast<float(*)[64][1][1]>(v596 + 64943360);
  kernel105(v627, v638, v628);	// L1072
  auto v639 = reinterpret_cast<float(*)[128][12][12]>(v594 + 1032192);
  kernel86(v634, v639, v628);	// L1074
  auto v640 = reinterpret_cast<float(*)[128][12][12]>(v595 + 2801664);
  kernel82(v628, v640);	// L1076
  kernel84(v640, (float)0.000000, (float)1.000000);	// L1077
  kernel83(v640, v628, (float)0.000000);	// L1078
  kernel82(v628, v639);	// L1079
  auto v641 = reinterpret_cast<float(*)[128][14][14]>(v594 + 2961664);
  kernel99(v641, (float)0.000000);	// L1081
  kernel80(v640, v641);	// L1082
  auto v642 = reinterpret_cast<float(*)>(v596 + 57865472);
  kernel88(v642, v628);	// L1084
  auto v643 = reinterpret_cast<float(*)[128][3][3]>(v596 + 60224768);
  kernel87(v641, v643, v628);	// L1086
  auto v644 = reinterpret_cast<float(*)[128][12][12]>(v594 + 1179648);
  kernel95(v644, v628);	// L1088
  kernel82(v628, v632);	// L1089
  kernel84(v632, (float)0.000000, (float)1.000000);	// L1090
  kernel83(v632, v628, (float)0.000000);	// L1091
  kernel82(v628, v644);	// L1092
  kernel90(v633, (float)0.000000);	// L1093
  kernel80(v632, v633);	// L1094
  auto v645 = reinterpret_cast<float(*)>(v596 + 53146880);
  kernel88(v645, v628);	// L1096
  auto v646 = reinterpret_cast<float(*)[128][3][3]>(v596 + 55506176);
  kernel87(v633, v646, v628);	// L1098
  auto v647 = reinterpret_cast<float(*)[128][12][12]>(v594 + 1327104);
  kernel86(v640, v647, v628);	// L1100
  kernel82(v628, v640);	// L1101
  kernel84(v640, (float)0.000000, (float)1.000000);	// L1102
  kernel83(v640, v628, (float)0.000000);	// L1103
  kernel82(v628, v647);	// L1104
  kernel81(v641, (float)0.000000);	// L1105
  kernel80(v640, v641);	// L1106
  auto v648 = reinterpret_cast<float(*)[256][6][6]>(v594 + 3281664);
  auto v649 = reinterpret_cast<float(*)>(v596 + 48428288);
  kernel50(v649, v648);	// L1109
  auto v650 = reinterpret_cast<float(*)[128][3][3]>(v596 + 50787584);
  kernel78(v641, v650, v648);	// L1111
  auto v651 = reinterpret_cast<float(*)[256][6][6]>(v594 + 1474560);
  kernel57(v651, v648);	// L1113
  auto v652 = reinterpret_cast<float(*)[256][6][6]>(v594 + 2961664);
  kernel44(v648, v652);	// L1115
  kernel46(v652, (float)0.000000, (float)1.000000);	// L1116
  kernel45(v652, v648, (float)0.000000);	// L1117
  kernel44(v648, v651);	// L1118
  auto v653 = reinterpret_cast<float(*)[256][8][8]>(v595 + 3441664);
  kernel72(v653, (float)0.000000);	// L1120
  kernel42(v652, v653);	// L1121
  auto v654 = reinterpret_cast<float(*)>(v596 + 43709696);
  kernel50(v654, v652);	// L1123
  auto v655 = reinterpret_cast<float(*)[256][3][3]>(v596 + 46068992);
  kernel49(v653, v655, v652);	// L1125
  auto v656 = reinterpret_cast<float(*)>(v596 + 38991104);
  kernel50(v656, v648);	// L1127
  auto v657 = reinterpret_cast<float(*)[128][1][1]>(v596 + 41350400);
  kernel67(v640, v657, v648);	// L1129
  auto v658 = reinterpret_cast<float(*)[256][6][6]>(v594 + 1622016);
  kernel48(v652, v658, v648);	// L1131
  auto v659 = reinterpret_cast<float(*)[256][6][6]>(v595 + 2801664);
  kernel44(v648, v659);	// L1133
  kernel46(v659, (float)0.000000, (float)1.000000);	// L1134
  kernel45(v659, v648, (float)0.000000);	// L1135
  kernel44(v648, v658);	// L1136
  auto v660 = reinterpret_cast<float(*)[256][8][8]>(v595 + 2961664);
  kernel61(v660, (float)0.000000);	// L1138
  kernel42(v659, v660);	// L1139
  auto v661 = reinterpret_cast<float(*)>(v596 + 34272512);
  kernel50(v661, v648);	// L1141
  auto v662 = reinterpret_cast<float(*)[256][3][3]>(v596 + 36631808);
  kernel49(v660, v662, v648);	// L1143
  auto v663 = reinterpret_cast<float(*)[256][6][6]>(v594 + 1769472);
  kernel57(v663, v648);	// L1145
  auto v664 = reinterpret_cast<float(*)[256][6][6]>(v595 + 2961664);
  kernel44(v648, v664);	// L1147
  kernel46(v664, (float)0.000000, (float)1.000000);	// L1148
  kernel45(v664, v648, (float)0.000000);	// L1149
  kernel44(v648, v663);	// L1150
  kernel52(v653, (float)0.000000);	// L1151
  kernel42(v664, v653);	// L1152
  auto v665 = reinterpret_cast<float(*)>(v596 + 29553920);
  kernel50(v665, v648);	// L1154
  auto v666 = reinterpret_cast<float(*)[256][3][3]>(v596 + 31913216);
  kernel49(v653, v666, v648);	// L1156
  auto v667 = reinterpret_cast<float(*)[256][6][6]>(v594 + 1916928);
  kernel48(v659, v667, v648);	// L1158
  auto v668 = reinterpret_cast<float(*)[256][6][6]>(v594 + 2801664);
  kernel44(v648, v668);	// L1160
  kernel46(v668, (float)0.000000, (float)1.000000);	// L1161
  kernel45(v668, v648, (float)0.000000);	// L1162
  kernel44(v648, v667);	// L1163
  auto v669 = reinterpret_cast<float(*)[256][8][8]>(v594 + 2961664);
  kernel43(v669, (float)0.000000);	// L1165
  kernel42(v668, v669);	// L1166
  auto v670 = reinterpret_cast<float(*)[512][3][3]>(v595 + 3281664);
  auto v671 = reinterpret_cast<float(*)>(v596 + 24835328);
  kernel12(v671, v670);	// L1169
  auto v672 = reinterpret_cast<float(*)[256][3][3]>(v596 + 27194624);
  kernel40(v669, v672, v670);	// L1171
  auto v673 = reinterpret_cast<float(*)[512][3][3]>(v594 + 2064384);
  kernel19(v673, v670);	// L1173
  auto v674 = reinterpret_cast<float(*)[512][3][3]>(v594 + 2961664);
  kernel6(v670, v674);	// L1175
  kernel8(v674, (float)0.000000, (float)1.000000);	// L1176
  kernel7(v674, v670, (float)0.000000);	// L1177
  kernel6(v670, v673);	// L1178
  auto v675 = reinterpret_cast<float(*)[512][5][5]>(v594 + 3441664);
  kernel34(v675, (float)0.000000);	// L1180
  kernel13(v674, v675);	// L1181
  auto v676 = reinterpret_cast<float(*)[512][3][3]>(v596 + 2961664);
  auto v677 = reinterpret_cast<float(*)>(v595 + 20116736);
  kernel12(v677, v676);	// L1184
  auto v678 = reinterpret_cast<float(*)[512][3][3]>(v595 + 22476032);
  kernel11(v675, v678, v676);	// L1186
  auto v679 = reinterpret_cast<float(*)>(v596 + 15398144);
  kernel12(v679, v670);	// L1188
  auto v680 = reinterpret_cast<float(*)[256][1][1]>(v596 + 17757440);
  kernel29(v668, v680, v670);	// L1190
  auto v681 = reinterpret_cast<float(*)[512][3][3]>(v594 + 2211840);
  kernel10(v676, v681, v670);	// L1192
  auto v682 = reinterpret_cast<float(*)[512][3][3]>(v594 + 2801664);
  kernel6(v670, v682);	// L1194
  kernel8(v682, (float)0.000000, (float)1.000000);	// L1195
  kernel7(v682, v670, (float)0.000000);	// L1196
  kernel6(v670, v681);	// L1197
  auto v683 = reinterpret_cast<float(*)[512][5][5]>(v595 + 2961664);
  kernel23(v683, (float)0.000000);	// L1199
  kernel13(v682, v683);	// L1200
  auto v684 = reinterpret_cast<float(*)>(v596 + 10679552);
  kernel12(v684, v670);	// L1202
  auto v685 = reinterpret_cast<float(*)[512][3][3]>(v596 + 13038848);
  kernel11(v683, v685, v670);	// L1204
  auto v686 = reinterpret_cast<float(*)[512][3][3]>(v594 + 2359296);
  kernel19(v686, v670);	// L1206
  kernel6(v670, v674);	// L1207
  kernel8(v674, (float)0.000000, (float)1.000000);	// L1208
  kernel7(v674, v670, (float)0.000000);	// L1209
  kernel6(v670, v686);	// L1210
  kernel14(v675, (float)0.000000);	// L1211
  kernel13(v674, v675);	// L1212
  auto v687 = reinterpret_cast<float(*)>(v596 + 5960960);
  kernel12(v687, v670);	// L1214
  auto v688 = reinterpret_cast<float(*)[512][3][3]>(v596 + 8320256);
  kernel11(v675, v688, v670);	// L1216
  auto v689 = reinterpret_cast<float(*)[512][3][3]>(v594 + 2506752);
  kernel10(v682, v689, v670);	// L1218
  auto v690 = reinterpret_cast<float(*)[512][3][3]>(v595 + 2801664);
  kernel6(v670, v690);	// L1220
  kernel8(v690, (float)0.000000, (float)1.000000);	// L1221
  kernel7(v690, v670, (float)0.000000);	// L1222
  kernel6(v670, v689);	// L1223
  auto v691 = reinterpret_cast<float(*)[512][1][1]>(v596 + 2961664);
  kernel5(v691, (float)0.000000);	// L1225
  kernel4(v690, v606, v691);	// L1226
  kernel3(v691, (float)9.000000);	// L1227
  auto v692 = reinterpret_cast<float(*)[10]>(v594 + 2654208);
  kernel2(v692, (float)0.000000);	// L1229
  auto v693 = reinterpret_cast<float(*)[10]>(v595 + 3601664);
  kernel1(v691, v693, v692);	// L1231
  auto v694 = reinterpret_cast<float(*)>(v596 + 100332800);
  kernel0(v694, v692);	// L1233
}

/// The T-step wrapper (FHCA v1.4: on-chip time-step loop)
/// Drives the single-step control T times; membrane states persist in DDR top_level buffers.
/// input_frames: DDR staging of T input frames (per-step-input);
///   frame t is memcpy'd to the input slot (arg0+0) before step t.
///   frame_elems=0: static input (host pre-writes frame, no copy).
/// out_frames: per-step outputs staged to DDR (out region assumed on
///   arg0 at out_elem_offset); out_elems=0: skip staging.
void control_t(
  ap_int<32> t_v0[102692096],
  ap_int<32> t_v1[102692096],
  ap_int<32> t_v2[102692096],
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

