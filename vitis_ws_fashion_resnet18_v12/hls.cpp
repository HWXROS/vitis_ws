
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
  float v20[10][512],
  float v21[512][10]
) {	// L32
  for (int v22 = 0; v22 < 512; v22 += 1) {	// L33
    for (int v23 = 0; v23 < 10; v23 += 1) {	// L34
      float v24 = v20[v23][v22];	// L35
      v21[v22][v23] = v24;	// L36
    }
  }
}

void kernel4(
  float v25[1][512][1][1],
  float v26
) {	// L41
  for (int v27 = 0; v27 < 512; v27 += 1) {	// L42
    float v28 = v25[0][v27][0][0];	// L43
    float v29 = v28 / v26;	// L44
    v25[0][v27][0][0] = v29;	// L45
  }
}

void kernel5(
  float v30[1][512][3][3],
  float v31[3][3],
  float v32[1][512][1][1]
) {	// L49
  for (int v33 = 0; v33 < 3; v33 += 1) {	// L50
    for (int v34 = 0; v34 < 3; v34 += 1) {	// L51
      for (int v35 = 0; v35 < 512; v35 += 1) {	// L52
        float v36 = v30[0][v35][v33][v34];	// L53
        float v37 = v32[0][v35][0][0];	// L54
        float v38 = v37 + v36;	// L55
        v32[0][v35][0][0] = v38;	// L56
      }
    }
  }
}

void kernel6(
  float v39[1][512][1][1],
  float v40
) {	// L62
  for (int v41 = 0; v41 < 512; v41 += 1) {	// L63
    v39[0][v41][0][0] = v40;	// L64
  }
}

void kernel7(
  float v42[1][512][3][3],
  float v43[1][512][3][3]
) {	// L68
  for (int v44 = 0; v44 < 512; v44 += 1) {	// L69
    for (int v45 = 0; v45 < 3; v45 += 1) {	// L70
      for (int v46 = 0; v46 < 3; v46 += 1) {	// L71
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v42
        #pragma HLS dependence false variable=v43
        float v47 = v42[0][v44][v45][v46];	// L72
        v43[0][v44][v45][v46] = v47;	// L73
      }
    }
  }
}

void kernel8(
  float v48[1][512][3][3],
  float v49[1][512][3][3]
) {	// L79
  for (int v50 = 0; v50 < 512; v50 += 1) {	// L80
    for (int v51 = 0; v51 < 3; v51 += 1) {	// L81
      for (int v52 = 0; v52 < 3; v52 += 1) {	// L82
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v48
        #pragma HLS dependence false variable=v49
        float v53 = v48[0][v50][v51][v52];	// L83
        float v54 = v49[0][v50][v51][v52];	// L84
        float v55 = v53 + v54;	// L85
        v49[0][v50][v51][v52] = v55;	// L86
      }
    }
  }
}

void kernel9(
  float v56[1][512][3][3],
  float v57
) {	// L92
  for (int v58 = 0; v58 < 512; v58 += 1) {	// L93
    for (int v59 = 0; v59 < 3; v59 += 1) {	// L94
      for (int v60 = 0; v60 < 3; v60 += 1) {	// L95
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v56
        float v61 = v56[0][v58][v59][v60];	// L96
        float v62 = v61 * v57;	// L97
        v56[0][v58][v59][v60] = v62;	// L98
      }
    }
  }
}

void kernel11(
  float v63[1][512][3][3],
  float v64[1][512][3][3],
  float v65[1][512][3][3]
) {	// L104
  for (int v66 = 0; v66 < 512; v66 += 1) {	// L105
    for (int v67 = 0; v67 < 3; v67 += 1) {	// L106
      for (int v68 = 0; v68 < 3; v68 += 1) {	// L107
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v64
        #pragma HLS dependence false variable=v65
        #pragma HLS dependence false variable=v63
        float v69 = v64[0][v66][v67][v68];	// L108
        float v70 = v63[0][v66][v67][v68];	// L109
        float v71 = v69 - v70;	// L110
        v65[0][v66][v67][v68] = v71;	// L111
      }
    }
  }
}

void kernel12(
  float v72[1][512][3][3],
  float v73[1][512][3][3],
  float v74[1][512][3][3]
) {	// L117
  for (int v75 = 0; v75 < 512; v75 += 1) {	// L118
    for (int v76 = 0; v76 < 3; v76 += 1) {	// L119
      for (int v77 = 0; v77 < 3; v77 += 1) {	// L120
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v73
        #pragma HLS dependence false variable=v74
        #pragma HLS dependence false variable=v72
        float v78 = v73[0][v75][v76][v77];	// L121
        float v79 = v72[0][v75][v76][v77];	// L122
        float v80 = v78 * v79;	// L123
        v74[0][v75][v76][v77] = v80;	// L124
      }
    }
  }
}

void kernel13(
  float v81[1][512][3][3],
  float v82,
  float v83
) {	// L130
  for (int v84 = 0; v84 < 512; v84 += 1) {	// L131
    for (int v85 = 0; v85 < 3; v85 += 1) {	// L132
      for (int v86 = 0; v86 < 3; v86 += 1) {	// L133
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v81
        float v87 = v81[0][v84][v85][v86];	// L134
        bool v88 = v87 >= v83;	// L135
        float v89 = v88 ? v82 : v83;	// L136
        v81[0][v84][v85][v86] = v89;	// L137
      }
    }
  }
}

void kernel15(
  float v90[1][512][3][3],
  float v91
) {	// L143
  for (int v92 = 0; v92 < 512; v92 += 1) {	// L144
    for (int v93 = 0; v93 < 3; v93 += 1) {	// L145
      for (int v94 = 0; v94 < 3; v94 += 1) {	// L146
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v90
        float v95 = v90[0][v92][v93][v94];	// L147
        float v96 = v95 - v91;	// L148
        v90[0][v92][v93][v94] = v96;	// L149
      }
    }
  }
}

void kernel17(
  float v97[1][512][3][3],
  float v98[1][512][3][3],
  float v99[1][512][3][3]
) {	// L155
  for (int v100 = 0; v100 < 512; v100 += 1) {	// L156
    for (int v101 = 0; v101 < 3; v101 += 1) {	// L157
      for (int v102 = 0; v102 < 3; v102 += 1) {	// L158
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v98
        #pragma HLS dependence false variable=v99
        #pragma HLS dependence false variable=v97
        float v103 = v98[0][v100][v101][v102];	// L159
        float v104 = v97[0][v100][v101][v102];	// L160
        float v105 = v103 + v104;	// L161
        v99[0][v100][v101][v102] = v105;	// L162
      }
    }
  }
}

void kernel19(
  float v106[1][512][5][5],
  float v107[512][512][3][3],
  float v108[1][512][3][3]
) {	// L168
  auto v109 = reinterpret_cast<float(*)[512][3][3]>(v107);	// L170

  for (int v110 = 0; v110 < 512; v110 += 1) {	// L171
    for (int v111 = 0; v111 < 3; v111 += 1) {	// L172
      for (int v112 = 0; v112 < 3; v112 += 1) {	// L173
        for (int v113 = 0; v113 < 512; v113 += 1) {	// L174
          for (int v114 = 0; v114 < 3; v114 += 1) {	// L175
            for (int v115 = 0; v115 < 3; v115 += 1) {	// L176
              #pragma HLS pipeline II=1
              #pragma HLS dependence false variable=v106
              #pragma HLS dependence false variable=v108
              #pragma HLS dependence false variable=v109
              float v116 = v106[0][v110][(v114 + v111)][(v115 + v112)];	// L177
              float v117 = v109[v113][v110][v111][v112];	// L178
              float v118 = v108[0][v113][v114][v115];	// L179
              float v119 = v116 * v117;	// L180
              float v120 = v118 + v119;	// L181
              v108[0][v113][v114][v115] = v120;	// L182
            }
          }
        }
      }
    }
  }
}

void kernel20(
  float v121[512],
  float v122[1][512][3][3]
) {	// L191
  float v123[512];	// L192
  #pragma HLS resource variable=v123 core=ram_t2p_bram

  memcpy(v123, v121, 512 * sizeof(float));	// L193

  for (int v124 = 0; v124 < 512; v124 += 1) {	// L194
    for (int v125 = 0; v125 < 3; v125 += 1) {	// L195
      for (int v126 = 0; v126 < 3; v126 += 1) {	// L196
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v123
        #pragma HLS dependence false variable=v122
        float v127 = v123[v124];	// L197
        v122[0][v124][v125][v126] = v127;	// L198
      }
    }
  }
}

void kernel21(
  float v128[1][512][3][3],
  float v129[1][512][5][5]
) {	// L204
  for (int v130 = 0; v130 < 512; v130 += 1) {	// L205
    for (int v131 = 0; v131 < 3; v131 += 1) {	// L206
      for (int v132 = 0; v132 < 3; v132 += 1) {	// L207
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v128
        #pragma HLS dependence false variable=v129
        float v133 = v128[0][v130][v131][v132];	// L208
        v129[0][v130][(v131 + 1)][(v132 + 1)] = v133;	// L209
      }
    }
  }
}

void kernel22(
  float v134[1][512][5][5],
  float v135
) {	// L215
  for (int v136 = 0; v136 < 512; v136 += 1) {	// L216
    for (int v137 = 0; v137 < 5; v137 += 1) {	// L217
      for (int v138 = 0; v138 < 5; v138 += 1) {	// L218
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v134
        v134[0][v136][v137][v138] = v135;	// L219
      }
    }
  }
}

void kernel37(
  float v139[1][512][5][5],
  float v140
) {	// L225
  for (int v141 = 0; v141 < 512; v141 += 1) {	// L226
    for (int v142 = 0; v142 < 5; v142 += 1) {	// L227
      for (int v143 = 0; v143 < 5; v143 += 1) {	// L228
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v139
        v139[0][v141][v142][v143] = v140;	// L229
      }
    }
  }
}

void kernel50(
  float v144[1][256][6][6],
  float v145[512][256][1][1],
  float v146[1][512][3][3]
) {	// L235
  auto v147 = reinterpret_cast<float(*)[256][1][1]>(v145);	// L237

  for (int v148 = 0; v148 < 256; v148 += 1) {	// L238
    for (int v149 = 0; v149 < 512; v149 += 1) {	// L239
      for (int v150 = 0; v150 < 3; v150 += 1) {	// L240
        for (int v151 = 0; v151 < 3; v151 += 1) {	// L241
          #pragma HLS pipeline II=1
          #pragma HLS dependence false variable=v144
          #pragma HLS dependence false variable=v146
          #pragma HLS dependence false variable=v147
          float v152 = v144[0][v148][(v150 * 2)][(v151 * 2)];	// L242
          float v153 = v147[v149][v148][0][0];	// L243
          float v154 = v146[0][v149][v150][v151];	// L244
          float v155 = v152 * v153;	// L245
          float v156 = v154 + v155;	// L246
          v146[0][v149][v150][v151] = v156;	// L247
        }
      }
    }
  }
}

void kernel55(
  float v157[1][512][5][5],
  float v158
) {	// L254
  for (int v159 = 0; v159 < 512; v159 += 1) {	// L255
    for (int v160 = 0; v160 < 5; v160 += 1) {	// L256
      for (int v161 = 0; v161 < 5; v161 += 1) {	// L257
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v157
        v157[0][v159][v160][v161] = v158;	// L258
      }
    }
  }
}

void kernel67(
  float v162[1][256][8][8],
  float v163[512][256][3][3],
  float v164[1][512][3][3]
) {	// L264
  auto v165 = reinterpret_cast<float(*)[256][3][3]>(v163);	// L266

  for (int v166 = 0; v166 < 256; v166 += 1) {	// L267
    for (int v167 = 0; v167 < 3; v167 += 1) {	// L268
      for (int v168 = 0; v168 < 3; v168 += 1) {	// L269
        for (int v169 = 0; v169 < 512; v169 += 1) {	// L270
          for (int v170 = 0; v170 < 3; v170 += 1) {	// L271
            for (int v171 = 0; v171 < 3; v171 += 1) {	// L272
              #pragma HLS pipeline II=1
              #pragma HLS dependence false variable=v162
              #pragma HLS dependence false variable=v164
              #pragma HLS dependence false variable=v165
              float v172 = v162[0][v166][((v170 * 2) + v167)][((v171 * 2) + v168)];	// L273
              float v173 = v165[v169][v166][v167][v168];	// L274
              float v174 = v164[0][v169][v170][v171];	// L275
              float v175 = v172 * v173;	// L276
              float v176 = v174 + v175;	// L277
              v164[0][v169][v170][v171] = v176;	// L278
            }
          }
        }
      }
    }
  }
}

void kernel69(
  float v177[1][256][6][6],
  float v178[1][256][8][8]
) {	// L287
  for (int v179 = 0; v179 < 256; v179 += 1) {	// L288
    for (int v180 = 0; v180 < 6; v180 += 1) {	// L289
      for (int v181 = 0; v181 < 6; v181 += 1) {	// L290
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v177
        #pragma HLS dependence false variable=v178
        float v182 = v177[0][v179][v180][v181];	// L291
        v178[0][v179][(v180 + 1)][(v181 + 1)] = v182;	// L292
      }
    }
  }
}

void kernel70(
  float v183[1][256][8][8],
  float v184
) {	// L298
  for (int v185 = 0; v185 < 256; v185 += 1) {	// L299
    for (int v186 = 0; v186 < 8; v186 += 1) {	// L300
      for (int v187 = 0; v187 < 8; v187 += 1) {	// L301
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v183
        v183[0][v185][v186][v187] = v184;	// L302
      }
    }
  }
}

void kernel71(
  float v188[1][256][6][6],
  float v189[1][256][6][6]
) {	// L308
  for (int v190 = 0; v190 < 256; v190 += 1) {	// L309
    for (int v191 = 0; v191 < 6; v191 += 1) {	// L310
      for (int v192 = 0; v192 < 6; v192 += 1) {	// L311
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v188
        #pragma HLS dependence false variable=v189
        float v193 = v188[0][v190][v191][v192];	// L312
        v189[0][v190][v191][v192] = v193;	// L313
      }
    }
  }
}

void kernel72(
  float v194[1][256][6][6],
  float v195[1][256][6][6]
) {	// L319
  for (int v196 = 0; v196 < 256; v196 += 1) {	// L320
    for (int v197 = 0; v197 < 6; v197 += 1) {	// L321
      for (int v198 = 0; v198 < 6; v198 += 1) {	// L322
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v194
        #pragma HLS dependence false variable=v195
        float v199 = v194[0][v196][v197][v198];	// L323
        float v200 = v195[0][v196][v197][v198];	// L324
        float v201 = v199 + v200;	// L325
        v195[0][v196][v197][v198] = v201;	// L326
      }
    }
  }
}

void kernel73(
  float v202[1][256][6][6],
  float v203
) {	// L332
  for (int v204 = 0; v204 < 256; v204 += 1) {	// L333
    for (int v205 = 0; v205 < 6; v205 += 1) {	// L334
      for (int v206 = 0; v206 < 6; v206 += 1) {	// L335
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v202
        float v207 = v202[0][v204][v205][v206];	// L336
        float v208 = v207 * v203;	// L337
        v202[0][v204][v205][v206] = v208;	// L338
      }
    }
  }
}

void kernel75(
  float v209[1][256][6][6],
  float v210[1][256][6][6],
  float v211[1][256][6][6]
) {	// L344
  for (int v212 = 0; v212 < 256; v212 += 1) {	// L345
    for (int v213 = 0; v213 < 6; v213 += 1) {	// L346
      for (int v214 = 0; v214 < 6; v214 += 1) {	// L347
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v210
        #pragma HLS dependence false variable=v211
        #pragma HLS dependence false variable=v209
        float v215 = v210[0][v212][v213][v214];	// L348
        float v216 = v209[0][v212][v213][v214];	// L349
        float v217 = v215 - v216;	// L350
        v211[0][v212][v213][v214] = v217;	// L351
      }
    }
  }
}

void kernel76(
  float v218[1][256][6][6],
  float v219[1][256][6][6],
  float v220[1][256][6][6]
) {	// L357
  for (int v221 = 0; v221 < 256; v221 += 1) {	// L358
    for (int v222 = 0; v222 < 6; v222 += 1) {	// L359
      for (int v223 = 0; v223 < 6; v223 += 1) {	// L360
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v219
        #pragma HLS dependence false variable=v220
        #pragma HLS dependence false variable=v218
        float v224 = v219[0][v221][v222][v223];	// L361
        float v225 = v218[0][v221][v222][v223];	// L362
        float v226 = v224 * v225;	// L363
        v220[0][v221][v222][v223] = v226;	// L364
      }
    }
  }
}

void kernel77(
  float v227[1][256][6][6],
  float v228,
  float v229
) {	// L370
  for (int v230 = 0; v230 < 256; v230 += 1) {	// L371
    for (int v231 = 0; v231 < 6; v231 += 1) {	// L372
      for (int v232 = 0; v232 < 6; v232 += 1) {	// L373
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v227
        float v233 = v227[0][v230][v231][v232];	// L374
        bool v234 = v233 >= v229;	// L375
        float v235 = v234 ? v228 : v229;	// L376
        v227[0][v230][v231][v232] = v235;	// L377
      }
    }
  }
}

void kernel79(
  float v236[1][256][6][6],
  float v237
) {	// L383
  for (int v238 = 0; v238 < 256; v238 += 1) {	// L384
    for (int v239 = 0; v239 < 6; v239 += 1) {	// L385
      for (int v240 = 0; v240 < 6; v240 += 1) {	// L386
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v236
        float v241 = v236[0][v238][v239][v240];	// L387
        float v242 = v241 - v237;	// L388
        v236[0][v238][v239][v240] = v242;	// L389
      }
    }
  }
}

void kernel81(
  float v243[1][256][6][6],
  float v244[1][256][6][6],
  float v245[1][256][6][6]
) {	// L395
  for (int v246 = 0; v246 < 256; v246 += 1) {	// L396
    for (int v247 = 0; v247 < 6; v247 += 1) {	// L397
      for (int v248 = 0; v248 < 6; v248 += 1) {	// L398
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v244
        #pragma HLS dependence false variable=v245
        #pragma HLS dependence false variable=v243
        float v249 = v244[0][v246][v247][v248];	// L399
        float v250 = v243[0][v246][v247][v248];	// L400
        float v251 = v249 + v250;	// L401
        v245[0][v246][v247][v248] = v251;	// L402
      }
    }
  }
}

void kernel83(
  float v252[1][256][8][8],
  float v253[256][256][3][3],
  float v254[1][256][6][6]
) {	// L408
  auto v255 = reinterpret_cast<float(*)[256][3][3]>(v253);	// L410

  for (int v256 = 0; v256 < 256; v256 += 1) {	// L411
    for (int v257 = 0; v257 < 3; v257 += 1) {	// L412
      for (int v258 = 0; v258 < 3; v258 += 1) {	// L413
        for (int v259 = 0; v259 < 256; v259 += 1) {	// L414
          for (int v260 = 0; v260 < 6; v260 += 1) {	// L415
            for (int v261 = 0; v261 < 6; v261 += 1) {	// L416
              #pragma HLS pipeline II=1
              #pragma HLS dependence false variable=v252
              #pragma HLS dependence false variable=v254
              #pragma HLS dependence false variable=v255
              float v262 = v252[0][v256][(v260 + v257)][(v261 + v258)];	// L417
              float v263 = v255[v259][v256][v257][v258];	// L418
              float v264 = v254[0][v259][v260][v261];	// L419
              float v265 = v262 * v263;	// L420
              float v266 = v264 + v265;	// L421
              v254[0][v259][v260][v261] = v266;	// L422
            }
          }
        }
      }
    }
  }
}

void kernel84(
  float v267[256],
  float v268[1][256][6][6]
) {	// L431
  float v269[256];	// L432
  #pragma HLS resource variable=v269 core=ram_t2p_bram

  memcpy(v269, v267, 256 * sizeof(float));	// L433

  for (int v270 = 0; v270 < 256; v270 += 1) {	// L434
    for (int v271 = 0; v271 < 6; v271 += 1) {	// L435
      for (int v272 = 0; v272 < 6; v272 += 1) {	// L436
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v269
        #pragma HLS dependence false variable=v268
        float v273 = v269[v270];	// L437
        v268[0][v270][v271][v272] = v273;	// L438
      }
    }
  }
}

void kernel86(
  float v274[1][256][8][8],
  float v275
) {	// L444
  for (int v276 = 0; v276 < 256; v276 += 1) {	// L445
    for (int v277 = 0; v277 < 8; v277 += 1) {	// L446
      for (int v278 = 0; v278 < 8; v278 += 1) {	// L447
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v274
        v274[0][v276][v277][v278] = v275;	// L448
      }
    }
  }
}

void kernel101(
  float v279[1][256][8][8],
  float v280
) {	// L454
  for (int v281 = 0; v281 < 256; v281 += 1) {	// L455
    for (int v282 = 0; v282 < 8; v282 += 1) {	// L456
      for (int v283 = 0; v283 < 8; v283 += 1) {	// L457
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v279
        v279[0][v281][v282][v283] = v280;	// L458
      }
    }
  }
}

void kernel114(
  float v284[1][128][12][12],
  float v285[256][128][1][1],
  float v286[1][256][6][6]
) {	// L464
  auto v287 = reinterpret_cast<float(*)[128][1][1]>(v285);	// L466

  for (int v288 = 0; v288 < 128; v288 += 1) {	// L467
    for (int v289 = 0; v289 < 256; v289 += 1) {	// L468
      for (int v290 = 0; v290 < 6; v290 += 1) {	// L469
        for (int v291 = 0; v291 < 6; v291 += 1) {	// L470
          #pragma HLS pipeline II=1
          #pragma HLS dependence false variable=v284
          #pragma HLS dependence false variable=v286
          #pragma HLS dependence false variable=v287
          float v292 = v284[0][v288][(v290 * 2)][(v291 * 2)];	// L471
          float v293 = v287[v289][v288][0][0];	// L472
          float v294 = v286[0][v289][v290][v291];	// L473
          float v295 = v292 * v293;	// L474
          float v296 = v294 + v295;	// L475
          v286[0][v289][v290][v291] = v296;	// L476
        }
      }
    }
  }
}

void kernel119(
  float v297[1][256][8][8],
  float v298
) {	// L483
  for (int v299 = 0; v299 < 256; v299 += 1) {	// L484
    for (int v300 = 0; v300 < 8; v300 += 1) {	// L485
      for (int v301 = 0; v301 < 8; v301 += 1) {	// L486
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v297
        v297[0][v299][v300][v301] = v298;	// L487
      }
    }
  }
}

void kernel131(
  float v302[1][128][14][14],
  float v303[256][128][3][3],
  float v304[1][256][6][6]
) {	// L493
  auto v305 = reinterpret_cast<float(*)[128][3][3]>(v303);	// L495

  for (int v306 = 0; v306 < 128; v306 += 1) {	// L496
    for (int v307 = 0; v307 < 3; v307 += 1) {	// L497
      for (int v308 = 0; v308 < 3; v308 += 1) {	// L498
        for (int v309 = 0; v309 < 256; v309 += 1) {	// L499
          for (int v310 = 0; v310 < 6; v310 += 1) {	// L500
            for (int v311 = 0; v311 < 6; v311 += 1) {	// L501
              #pragma HLS pipeline II=1
              #pragma HLS dependence false variable=v302
              #pragma HLS dependence false variable=v304
              #pragma HLS dependence false variable=v305
              float v312 = v302[0][v306][((v310 * 2) + v307)][((v311 * 2) + v308)];	// L502
              float v313 = v305[v309][v306][v307][v308];	// L503
              float v314 = v304[0][v309][v310][v311];	// L504
              float v315 = v312 * v313;	// L505
              float v316 = v314 + v315;	// L506
              v304[0][v309][v310][v311] = v316;	// L507
            }
          }
        }
      }
    }
  }
}

void kernel133(
  float v317[1][128][12][12],
  float v318[1][128][14][14]
) {	// L516
  for (int v319 = 0; v319 < 128; v319 += 1) {	// L517
    for (int v320 = 0; v320 < 12; v320 += 1) {	// L518
      for (int v321 = 0; v321 < 12; v321 += 1) {	// L519
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v317
        #pragma HLS dependence false variable=v318
        float v322 = v317[0][v319][v320][v321];	// L520
        v318[0][v319][(v320 + 1)][(v321 + 1)] = v322;	// L521
      }
    }
  }
}

void kernel134(
  float v323[1][128][14][14],
  float v324
) {	// L527
  for (int v325 = 0; v325 < 128; v325 += 1) {	// L528
    for (int v326 = 0; v326 < 14; v326 += 1) {	// L529
      for (int v327 = 0; v327 < 14; v327 += 1) {	// L530
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v323
        v323[0][v325][v326][v327] = v324;	// L531
      }
    }
  }
}

void kernel135(
  float v328[1][128][12][12],
  float v329[1][128][12][12]
) {	// L537
  for (int v330 = 0; v330 < 128; v330 += 1) {	// L538
    for (int v331 = 0; v331 < 12; v331 += 1) {	// L539
      for (int v332 = 0; v332 < 12; v332 += 1) {	// L540
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v328
        #pragma HLS dependence false variable=v329
        float v333 = v328[0][v330][v331][v332];	// L541
        v329[0][v330][v331][v332] = v333;	// L542
      }
    }
  }
}

void kernel136(
  float v334[1][128][12][12],
  float v335[1][128][12][12]
) {	// L548
  for (int v336 = 0; v336 < 128; v336 += 1) {	// L549
    for (int v337 = 0; v337 < 12; v337 += 1) {	// L550
      for (int v338 = 0; v338 < 12; v338 += 1) {	// L551
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v334
        #pragma HLS dependence false variable=v335
        float v339 = v334[0][v336][v337][v338];	// L552
        float v340 = v335[0][v336][v337][v338];	// L553
        float v341 = v339 + v340;	// L554
        v335[0][v336][v337][v338] = v341;	// L555
      }
    }
  }
}

void kernel137(
  float v342[1][128][12][12],
  float v343
) {	// L561
  for (int v344 = 0; v344 < 128; v344 += 1) {	// L562
    for (int v345 = 0; v345 < 12; v345 += 1) {	// L563
      for (int v346 = 0; v346 < 12; v346 += 1) {	// L564
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v342
        float v347 = v342[0][v344][v345][v346];	// L565
        float v348 = v347 * v343;	// L566
        v342[0][v344][v345][v346] = v348;	// L567
      }
    }
  }
}

void kernel139(
  float v349[1][128][12][12],
  float v350[1][128][12][12],
  float v351[1][128][12][12]
) {	// L573
  for (int v352 = 0; v352 < 128; v352 += 1) {	// L574
    for (int v353 = 0; v353 < 12; v353 += 1) {	// L575
      for (int v354 = 0; v354 < 12; v354 += 1) {	// L576
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v350
        #pragma HLS dependence false variable=v351
        #pragma HLS dependence false variable=v349
        float v355 = v350[0][v352][v353][v354];	// L577
        float v356 = v349[0][v352][v353][v354];	// L578
        float v357 = v355 - v356;	// L579
        v351[0][v352][v353][v354] = v357;	// L580
      }
    }
  }
}

void kernel140(
  float v358[1][128][12][12],
  float v359[1][128][12][12],
  float v360[1][128][12][12]
) {	// L586
  for (int v361 = 0; v361 < 128; v361 += 1) {	// L587
    for (int v362 = 0; v362 < 12; v362 += 1) {	// L588
      for (int v363 = 0; v363 < 12; v363 += 1) {	// L589
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v359
        #pragma HLS dependence false variable=v360
        #pragma HLS dependence false variable=v358
        float v364 = v359[0][v361][v362][v363];	// L590
        float v365 = v358[0][v361][v362][v363];	// L591
        float v366 = v364 * v365;	// L592
        v360[0][v361][v362][v363] = v366;	// L593
      }
    }
  }
}

void kernel141(
  float v367[1][128][12][12],
  float v368,
  float v369
) {	// L599
  for (int v370 = 0; v370 < 128; v370 += 1) {	// L600
    for (int v371 = 0; v371 < 12; v371 += 1) {	// L601
      for (int v372 = 0; v372 < 12; v372 += 1) {	// L602
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v367
        float v373 = v367[0][v370][v371][v372];	// L603
        bool v374 = v373 >= v369;	// L604
        float v375 = v374 ? v368 : v369;	// L605
        v367[0][v370][v371][v372] = v375;	// L606
      }
    }
  }
}

void kernel143(
  float v376[1][128][12][12],
  float v377
) {	// L612
  for (int v378 = 0; v378 < 128; v378 += 1) {	// L613
    for (int v379 = 0; v379 < 12; v379 += 1) {	// L614
      for (int v380 = 0; v380 < 12; v380 += 1) {	// L615
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v376
        float v381 = v376[0][v378][v379][v380];	// L616
        float v382 = v381 - v377;	// L617
        v376[0][v378][v379][v380] = v382;	// L618
      }
    }
  }
}

void kernel145(
  float v383[1][128][12][12],
  float v384[1][128][12][12],
  float v385[1][128][12][12]
) {	// L624
  for (int v386 = 0; v386 < 128; v386 += 1) {	// L625
    for (int v387 = 0; v387 < 12; v387 += 1) {	// L626
      for (int v388 = 0; v388 < 12; v388 += 1) {	// L627
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v384
        #pragma HLS dependence false variable=v385
        #pragma HLS dependence false variable=v383
        float v389 = v384[0][v386][v387][v388];	// L628
        float v390 = v383[0][v386][v387][v388];	// L629
        float v391 = v389 + v390;	// L630
        v385[0][v386][v387][v388] = v391;	// L631
      }
    }
  }
}

void kernel147(
  float v392[1][128][14][14],
  float v393[128][128][3][3],
  float v394[1][128][12][12]
) {	// L637
  auto v395 = reinterpret_cast<float(*)[128][3][3]>(v393);	// L639

  for (int v396 = 0; v396 < 128; v396 += 1) {	// L640
    for (int v397 = 0; v397 < 3; v397 += 1) {	// L641
      for (int v398 = 0; v398 < 3; v398 += 1) {	// L642
        for (int v399 = 0; v399 < 128; v399 += 1) {	// L643
          for (int v400 = 0; v400 < 12; v400 += 1) {	// L644
            for (int v401 = 0; v401 < 12; v401 += 1) {	// L645
              #pragma HLS pipeline II=1
              #pragma HLS dependence false variable=v392
              #pragma HLS dependence false variable=v394
              #pragma HLS dependence false variable=v395
              float v402 = v392[0][v396][(v400 + v397)][(v401 + v398)];	// L646
              float v403 = v395[v399][v396][v397][v398];	// L647
              float v404 = v394[0][v399][v400][v401];	// L648
              float v405 = v402 * v403;	// L649
              float v406 = v404 + v405;	// L650
              v394[0][v399][v400][v401] = v406;	// L651
            }
          }
        }
      }
    }
  }
}

void kernel148(
  float v407[128],
  float v408[1][128][12][12]
) {	// L660
  float v409[128];	// L661
  #pragma HLS resource variable=v409 core=ram_t2p_bram

  memcpy(v409, v407, 128 * sizeof(float));	// L662

  for (int v410 = 0; v410 < 128; v410 += 1) {	// L663
    for (int v411 = 0; v411 < 12; v411 += 1) {	// L664
      for (int v412 = 0; v412 < 12; v412 += 1) {	// L665
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v409
        #pragma HLS dependence false variable=v408
        float v413 = v409[v410];	// L666
        v408[0][v410][v411][v412] = v413;	// L667
      }
    }
  }
}

void kernel150(
  float v414[1][128][14][14],
  float v415
) {	// L673
  for (int v416 = 0; v416 < 128; v416 += 1) {	// L674
    for (int v417 = 0; v417 < 14; v417 += 1) {	// L675
      for (int v418 = 0; v418 < 14; v418 += 1) {	// L676
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v414
        v414[0][v416][v417][v418] = v415;	// L677
      }
    }
  }
}

void kernel165(
  float v419[1][128][14][14],
  float v420
) {	// L683
  for (int v421 = 0; v421 < 128; v421 += 1) {	// L684
    for (int v422 = 0; v422 < 14; v422 += 1) {	// L685
      for (int v423 = 0; v423 < 14; v423 += 1) {	// L686
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v419
        v419[0][v421][v422][v423] = v420;	// L687
      }
    }
  }
}

void kernel178(
  float v424[1][64][24][24],
  float v425[128][64][1][1],
  float v426[1][128][12][12]
) {	// L693
  float v427[128][64][1][1];	// L694
  #pragma HLS resource variable=v427 core=ram_t2p_bram

  memcpy(v427, v425, 8192 * sizeof(float));	// L695

  for (int v428 = 0; v428 < 64; v428 += 1) {	// L696
    for (int v429 = 0; v429 < 128; v429 += 1) {	// L697
      for (int v430 = 0; v430 < 12; v430 += 1) {	// L698
        for (int v431 = 0; v431 < 12; v431 += 1) {	// L699
          #pragma HLS pipeline II=1
          #pragma HLS dependence false variable=v424
          #pragma HLS dependence false variable=v426
          #pragma HLS dependence false variable=v427
          float v432 = v424[0][v428][(v430 * 2)][(v431 * 2)];	// L700
          float v433 = v427[v429][v428][0][0];	// L701
          float v434 = v426[0][v429][v430][v431];	// L702
          float v435 = v432 * v433;	// L703
          float v436 = v434 + v435;	// L704
          v426[0][v429][v430][v431] = v436;	// L705
        }
      }
    }
  }
}

void kernel183(
  float v437[1][128][14][14],
  float v438
) {	// L712
  for (int v439 = 0; v439 < 128; v439 += 1) {	// L713
    for (int v440 = 0; v440 < 14; v440 += 1) {	// L714
      for (int v441 = 0; v441 < 14; v441 += 1) {	// L715
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v437
        v437[0][v439][v440][v441] = v438;	// L716
      }
    }
  }
}

void kernel195(
  float v442[1][64][26][26],
  float v443[128][64][3][3],
  float v444[1][128][12][12]
) {	// L722
  auto v445 = reinterpret_cast<float(*)[64][3][3]>(v443);	// L724

  for (int v446 = 0; v446 < 64; v446 += 1) {	// L725
    for (int v447 = 0; v447 < 3; v447 += 1) {	// L726
      for (int v448 = 0; v448 < 3; v448 += 1) {	// L727
        for (int v449 = 0; v449 < 128; v449 += 1) {	// L728
          for (int v450 = 0; v450 < 12; v450 += 1) {	// L729
            for (int v451 = 0; v451 < 12; v451 += 1) {	// L730
              #pragma HLS pipeline II=1
              #pragma HLS dependence false variable=v442
              #pragma HLS dependence false variable=v444
              #pragma HLS dependence false variable=v445
              float v452 = v442[0][v446][((v450 * 2) + v447)][((v451 * 2) + v448)];	// L731
              float v453 = v445[v449][v446][v447][v448];	// L732
              float v454 = v444[0][v449][v450][v451];	// L733
              float v455 = v452 * v453;	// L734
              float v456 = v454 + v455;	// L735
              v444[0][v449][v450][v451] = v456;	// L736
            }
          }
        }
      }
    }
  }
}

void kernel197(
  float v457[1][64][24][24],
  float v458[1][64][26][26]
) {	// L745
  for (int v459 = 0; v459 < 64; v459 += 1) {	// L746
    for (int v460 = 0; v460 < 24; v460 += 1) {	// L747
      for (int v461 = 0; v461 < 24; v461 += 1) {	// L748
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v457
        #pragma HLS dependence false variable=v458
        float v462 = v457[0][v459][v460][v461];	// L749
        v458[0][v459][(v460 + 1)][(v461 + 1)] = v462;	// L750
      }
    }
  }
}

void kernel198(
  float v463[1][64][26][26],
  float v464
) {	// L756
  for (int v465 = 0; v465 < 64; v465 += 1) {	// L757
    for (int v466 = 0; v466 < 26; v466 += 1) {	// L758
      for (int v467 = 0; v467 < 26; v467 += 1) {	// L759
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v463
        v463[0][v465][v466][v467] = v464;	// L760
      }
    }
  }
}

void kernel199(
  float v468[1][64][24][24],
  float v469[1][64][24][24]
) {	// L766
  for (int v470 = 0; v470 < 64; v470 += 1) {	// L767
    for (int v471 = 0; v471 < 24; v471 += 1) {	// L768
      for (int v472 = 0; v472 < 24; v472 += 1) {	// L769
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v468
        #pragma HLS dependence false variable=v469
        float v473 = v468[0][v470][v471][v472];	// L770
        v469[0][v470][v471][v472] = v473;	// L771
      }
    }
  }
}

void kernel200(
  float v474[1][64][24][24],
  float v475[1][64][24][24]
) {	// L777
  for (int v476 = 0; v476 < 64; v476 += 1) {	// L778
    for (int v477 = 0; v477 < 24; v477 += 1) {	// L779
      for (int v478 = 0; v478 < 24; v478 += 1) {	// L780
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v474
        #pragma HLS dependence false variable=v475
        float v479 = v474[0][v476][v477][v478];	// L781
        float v480 = v475[0][v476][v477][v478];	// L782
        float v481 = v479 + v480;	// L783
        v475[0][v476][v477][v478] = v481;	// L784
      }
    }
  }
}

void kernel201(
  float v482[1][64][24][24],
  float v483
) {	// L790
  for (int v484 = 0; v484 < 64; v484 += 1) {	// L791
    for (int v485 = 0; v485 < 24; v485 += 1) {	// L792
      for (int v486 = 0; v486 < 24; v486 += 1) {	// L793
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v482
        float v487 = v482[0][v484][v485][v486];	// L794
        float v488 = v487 * v483;	// L795
        v482[0][v484][v485][v486] = v488;	// L796
      }
    }
  }
}

void kernel203(
  float v489[1][64][24][24],
  float v490[1][64][24][24],
  float v491[1][64][24][24]
) {	// L802
  for (int v492 = 0; v492 < 64; v492 += 1) {	// L803
    for (int v493 = 0; v493 < 24; v493 += 1) {	// L804
      for (int v494 = 0; v494 < 24; v494 += 1) {	// L805
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v490
        #pragma HLS dependence false variable=v491
        #pragma HLS dependence false variable=v489
        float v495 = v490[0][v492][v493][v494];	// L806
        float v496 = v489[0][v492][v493][v494];	// L807
        float v497 = v495 - v496;	// L808
        v491[0][v492][v493][v494] = v497;	// L809
      }
    }
  }
}

void kernel204(
  float v498[1][64][24][24],
  float v499[1][64][24][24],
  float v500[1][64][24][24]
) {	// L815
  for (int v501 = 0; v501 < 64; v501 += 1) {	// L816
    for (int v502 = 0; v502 < 24; v502 += 1) {	// L817
      for (int v503 = 0; v503 < 24; v503 += 1) {	// L818
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v499
        #pragma HLS dependence false variable=v500
        #pragma HLS dependence false variable=v498
        float v504 = v499[0][v501][v502][v503];	// L819
        float v505 = v498[0][v501][v502][v503];	// L820
        float v506 = v504 * v505;	// L821
        v500[0][v501][v502][v503] = v506;	// L822
      }
    }
  }
}

void kernel205(
  float v507[1][64][24][24],
  float v508,
  float v509
) {	// L828
  for (int v510 = 0; v510 < 64; v510 += 1) {	// L829
    for (int v511 = 0; v511 < 24; v511 += 1) {	// L830
      for (int v512 = 0; v512 < 24; v512 += 1) {	// L831
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v507
        float v513 = v507[0][v510][v511][v512];	// L832
        bool v514 = v513 >= v509;	// L833
        float v515 = v514 ? v508 : v509;	// L834
        v507[0][v510][v511][v512] = v515;	// L835
      }
    }
  }
}

void kernel207(
  float v516[1][64][24][24],
  float v517
) {	// L841
  for (int v518 = 0; v518 < 64; v518 += 1) {	// L842
    for (int v519 = 0; v519 < 24; v519 += 1) {	// L843
      for (int v520 = 0; v520 < 24; v520 += 1) {	// L844
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v516
        float v521 = v516[0][v518][v519][v520];	// L845
        float v522 = v521 - v517;	// L846
        v516[0][v518][v519][v520] = v522;	// L847
      }
    }
  }
}

void kernel209(
  float v523[1][64][24][24],
  float v524[1][64][24][24],
  float v525[1][64][24][24]
) {	// L853
  for (int v526 = 0; v526 < 64; v526 += 1) {	// L854
    for (int v527 = 0; v527 < 24; v527 += 1) {	// L855
      for (int v528 = 0; v528 < 24; v528 += 1) {	// L856
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v524
        #pragma HLS dependence false variable=v525
        #pragma HLS dependence false variable=v523
        float v529 = v524[0][v526][v527][v528];	// L857
        float v530 = v523[0][v526][v527][v528];	// L858
        float v531 = v529 + v530;	// L859
        v525[0][v526][v527][v528] = v531;	// L860
      }
    }
  }
}

void kernel211(
  float v532[1][64][26][26],
  float v533[64][64][3][3],
  float v534[1][64][24][24]
) {	// L866
  auto v535 = reinterpret_cast<float(*)[64][3][3]>(v533);	// L868

  for (int v536 = 0; v536 < 64; v536 += 1) {	// L869
    for (int v537 = 0; v537 < 3; v537 += 1) {	// L870
      for (int v538 = 0; v538 < 3; v538 += 1) {	// L871
        for (int v539 = 0; v539 < 64; v539 += 1) {	// L872
          for (int v540 = 0; v540 < 24; v540 += 1) {	// L873
            for (int v541 = 0; v541 < 24; v541 += 1) {	// L874
              #pragma HLS pipeline II=1
              #pragma HLS dependence false variable=v532
              #pragma HLS dependence false variable=v534
              #pragma HLS dependence false variable=v535
              float v542 = v532[0][v536][(v540 + v537)][(v541 + v538)];	// L875
              float v543 = v535[v539][v536][v537][v538];	// L876
              float v544 = v534[0][v539][v540][v541];	// L877
              float v545 = v542 * v543;	// L878
              float v546 = v544 + v545;	// L879
              v534[0][v539][v540][v541] = v546;	// L880
            }
          }
        }
      }
    }
  }
}

void kernel212(
  float v547[64],
  float v548[1][64][24][24]
) {	// L889
  float v549[64];	// L890
  #pragma HLS resource variable=v549 core=ram_t2p_bram

  memcpy(v549, v547, 64 * sizeof(float));	// L891

  for (int v550 = 0; v550 < 64; v550 += 1) {	// L892
    for (int v551 = 0; v551 < 24; v551 += 1) {	// L893
      for (int v552 = 0; v552 < 24; v552 += 1) {	// L894
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v549
        #pragma HLS dependence false variable=v548
        float v553 = v549[v550];	// L895
        v548[0][v550][v551][v552] = v553;	// L896
      }
    }
  }
}

void kernel214(
  float v554[1][64][26][26],
  float v555
) {	// L902
  for (int v556 = 0; v556 < 64; v556 += 1) {	// L903
    for (int v557 = 0; v557 < 26; v557 += 1) {	// L904
      for (int v558 = 0; v558 < 26; v558 += 1) {	// L905
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v554
        v554[0][v556][v557][v558] = v555;	// L906
      }
    }
  }
}

void kernel229(
  float v559[1][64][26][26],
  float v560
) {	// L912
  for (int v561 = 0; v561 < 64; v561 += 1) {	// L913
    for (int v562 = 0; v562 < 26; v562 += 1) {	// L914
      for (int v563 = 0; v563 < 26; v563 += 1) {	// L915
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v559
        v559[0][v561][v562][v563] = v560;	// L916
      }
    }
  }
}

void kernel245(
  float v564[1][64][26][26],
  float v565
) {	// L922
  for (int v566 = 0; v566 < 64; v566 += 1) {	// L923
    for (int v567 = 0; v567 < 26; v567 += 1) {	// L924
      for (int v568 = 0; v568 < 26; v568 += 1) {	// L925
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v564
        v564[0][v566][v567][v568] = v565;	// L926
      }
    }
  }
}

void kernel260(
  float v569[1][64][26][26],
  float v570
) {	// L932
  for (int v571 = 0; v571 < 64; v571 += 1) {	// L933
    for (int v572 = 0; v572 < 26; v572 += 1) {	// L934
      for (int v573 = 0; v573 < 26; v573 += 1) {	// L935
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v569
        v569[0][v571][v572][v573] = v570;	// L936
      }
    }
  }
}

void kernel261(
  float v574[1][64][50][50],
  float v575[3][3],
  float v576[1][64][24][24]
) {	// L942
  for (int v577 = 0; v577 < 3; v577 += 1) {	// L943
    for (int v578 = 0; v578 < 3; v578 += 1) {	// L944
      for (int v579 = 0; v579 < 64; v579 += 1) {	// L945
        for (int v580 = 0; v580 < 24; v580 += 1) {	// L946
          for (int v581 = 0; v581 < 24; v581 += 1) {	// L947
            #pragma HLS pipeline II=1
            #pragma HLS dependence false variable=v574
            #pragma HLS dependence false variable=v576
            float v582 = v574[0][v579][((v580 * 2) + v577)][((v581 * 2) + v578)];	// L948
            float v583 = v576[0][v579][v580][v581];	// L949
            float v584 = max(v583, v582);	// L950
            v576[0][v579][v580][v581] = v584;	// L951
          }
        }
      }
    }
  }
}

void kernel262(
  float v585[1][64][24][24],
  float v586
) {	// L959
  for (int v587 = 0; v587 < 64; v587 += 1) {	// L960
    for (int v588 = 0; v588 < 24; v588 += 1) {	// L961
      for (int v589 = 0; v589 < 24; v589 += 1) {	// L962
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v585
        v585[0][v587][v588][v589] = v586;	// L963
      }
    }
  }
}

void kernel263(
  float v590[1][64][48][48],
  float v591[1][64][50][50]
) {	// L969
  for (int v592 = 0; v592 < 64; v592 += 1) {	// L970
    for (int v593 = 0; v593 < 48; v593 += 1) {	// L971
      for (int v594 = 0; v594 < 48; v594 += 1) {	// L972
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v590
        #pragma HLS dependence false variable=v591
        float v595 = v590[0][v592][v593][v594];	// L973
        v591[0][v592][(v593 + 1)][(v594 + 1)] = v595;	// L974
      }
    }
  }
}

void kernel264(
  float v596[1][64][50][50],
  float v597
) {	// L980
  for (int v598 = 0; v598 < 64; v598 += 1) {	// L981
    for (int v599 = 0; v599 < 50; v599 += 1) {	// L982
      for (int v600 = 0; v600 < 50; v600 += 1) {	// L983
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v596
        v596[0][v598][v599][v600] = v597;	// L984
      }
    }
  }
}

void kernel265(
  float v601[1][64][48][48],
  float v602[1][64][48][48]
) {	// L990
  for (int v603 = 0; v603 < 64; v603 += 1) {	// L991
    for (int v604 = 0; v604 < 48; v604 += 1) {	// L992
      for (int v605 = 0; v605 < 48; v605 += 1) {	// L993
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v601
        #pragma HLS dependence false variable=v602
        float v606 = v601[0][v603][v604][v605];	// L994
        v602[0][v603][v604][v605] = v606;	// L995
      }
    }
  }
}

void kernel266(
  float v607[1][64][48][48],
  float v608[1][64][48][48]
) {	// L1001
  for (int v609 = 0; v609 < 64; v609 += 1) {	// L1002
    for (int v610 = 0; v610 < 48; v610 += 1) {	// L1003
      for (int v611 = 0; v611 < 48; v611 += 1) {	// L1004
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v607
        #pragma HLS dependence false variable=v608
        float v612 = v607[0][v609][v610][v611];	// L1005
        float v613 = v608[0][v609][v610][v611];	// L1006
        float v614 = v612 + v613;	// L1007
        v608[0][v609][v610][v611] = v614;	// L1008
      }
    }
  }
}

void kernel267(
  float v615[1][64][48][48],
  float v616
) {	// L1014
  for (int v617 = 0; v617 < 64; v617 += 1) {	// L1015
    for (int v618 = 0; v618 < 48; v618 += 1) {	// L1016
      for (int v619 = 0; v619 < 48; v619 += 1) {	// L1017
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v615
        float v620 = v615[0][v617][v618][v619];	// L1018
        float v621 = v620 * v616;	// L1019
        v615[0][v617][v618][v619] = v621;	// L1020
      }
    }
  }
}

void kernel269(
  float v622[1][64][48][48],
  float v623[1][64][48][48],
  float v624[1][64][48][48]
) {	// L1026
  for (int v625 = 0; v625 < 64; v625 += 1) {	// L1027
    for (int v626 = 0; v626 < 48; v626 += 1) {	// L1028
      for (int v627 = 0; v627 < 48; v627 += 1) {	// L1029
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v623
        #pragma HLS dependence false variable=v624
        #pragma HLS dependence false variable=v622
        float v628 = v623[0][v625][v626][v627];	// L1030
        float v629 = v622[0][v625][v626][v627];	// L1031
        float v630 = v628 - v629;	// L1032
        v624[0][v625][v626][v627] = v630;	// L1033
      }
    }
  }
}

void kernel270(
  float v631[1][64][48][48],
  float v632[1][64][48][48],
  float v633[1][64][48][48]
) {	// L1039
  for (int v634 = 0; v634 < 64; v634 += 1) {	// L1040
    for (int v635 = 0; v635 < 48; v635 += 1) {	// L1041
      for (int v636 = 0; v636 < 48; v636 += 1) {	// L1042
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v632
        #pragma HLS dependence false variable=v633
        #pragma HLS dependence false variable=v631
        float v637 = v632[0][v634][v635][v636];	// L1043
        float v638 = v631[0][v634][v635][v636];	// L1044
        float v639 = v637 * v638;	// L1045
        v633[0][v634][v635][v636] = v639;	// L1046
      }
    }
  }
}

void kernel271(
  float v640[1][64][48][48],
  float v641,
  float v642
) {	// L1052
  for (int v643 = 0; v643 < 64; v643 += 1) {	// L1053
    for (int v644 = 0; v644 < 48; v644 += 1) {	// L1054
      for (int v645 = 0; v645 < 48; v645 += 1) {	// L1055
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v640
        float v646 = v640[0][v643][v644][v645];	// L1056
        bool v647 = v646 >= v642;	// L1057
        float v648 = v647 ? v641 : v642;	// L1058
        v640[0][v643][v644][v645] = v648;	// L1059
      }
    }
  }
}

void kernel273(
  float v649[1][64][48][48],
  float v650
) {	// L1065
  for (int v651 = 0; v651 < 64; v651 += 1) {	// L1066
    for (int v652 = 0; v652 < 48; v652 += 1) {	// L1067
      for (int v653 = 0; v653 < 48; v653 += 1) {	// L1068
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v649
        float v654 = v649[0][v651][v652][v653];	// L1069
        float v655 = v654 - v650;	// L1070
        v649[0][v651][v652][v653] = v655;	// L1071
      }
    }
  }
}

void kernel275(
  float v656[1][64][48][48],
  float v657[1][64][48][48],
  float v658[1][64][48][48]
) {	// L1077
  for (int v659 = 0; v659 < 64; v659 += 1) {	// L1078
    for (int v660 = 0; v660 < 48; v660 += 1) {	// L1079
      for (int v661 = 0; v661 < 48; v661 += 1) {	// L1080
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v657
        #pragma HLS dependence false variable=v658
        #pragma HLS dependence false variable=v656
        float v662 = v657[0][v659][v660][v661];	// L1081
        float v663 = v656[0][v659][v660][v661];	// L1082
        float v664 = v662 + v663;	// L1083
        v658[0][v659][v660][v661] = v664;	// L1084
      }
    }
  }
}

void kernel276(
  float v665[1][1][102][102],
  float v666[64][1][7][7],
  float v667[1][64][48][48]
) {	// L1090
  float v668[64][1][7][7];	// L1091
  #pragma HLS resource variable=v668 core=ram_t2p_bram

  memcpy(v668, v666, 3136 * sizeof(float));	// L1092

  for (int v669 = 0; v669 < 7; v669 += 1) {	// L1093
    for (int v670 = 0; v670 < 7; v670 += 1) {	// L1094
      for (int v671 = 0; v671 < 64; v671 += 1) {	// L1095
        for (int v672 = 0; v672 < 48; v672 += 1) {	// L1096
          for (int v673 = 0; v673 < 48; v673 += 1) {	// L1097
            #pragma HLS pipeline II=1
            #pragma HLS dependence false variable=v665
            #pragma HLS dependence false variable=v667
            #pragma HLS dependence false variable=v668
            float v674 = v665[0][0][((v672 * 2) + v669)][((v673 * 2) + v670)];	// L1098
            float v675 = v668[v671][0][v669][v670];	// L1099
            float v676 = v667[0][v671][v672][v673];	// L1100
            float v677 = v674 * v675;	// L1101
            float v678 = v676 + v677;	// L1102
            v667[0][v671][v672][v673] = v678;	// L1103
          }
        }
      }
    }
  }
}

void kernel277(
  float v679[64],
  float v680[1][64][48][48]
) {	// L1111
  float v681[64];	// L1112
  #pragma HLS resource variable=v681 core=ram_t2p_bram

  memcpy(v681, v679, 64 * sizeof(float));	// L1113

  for (int v682 = 0; v682 < 64; v682 += 1) {	// L1114
    for (int v683 = 0; v683 < 48; v683 += 1) {	// L1115
      for (int v684 = 0; v684 < 48; v684 += 1) {	// L1116
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v681
        #pragma HLS dependence false variable=v680
        float v685 = v681[v682];	// L1117
        v680[0][v682][v683][v684] = v685;	// L1118
      }
    }
  }
}

void kernel278(
  float v686[1][1][96][96],
  float v687[1][1][102][102]
) {	// L1124
  for (int v688 = 0; v688 < 96; v688 += 1) {	// L1125
    for (int v689 = 0; v689 < 96; v689 += 1) {	// L1126
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v686
      #pragma HLS dependence false variable=v687
      float v690 = v686[0][0][v688][v689];	// L1127
      v687[0][0][(v688 + 3)][(v689 + 3)] = v690;	// L1128
    }
  }
}

void kernel279(
  float v691[1][1][102][102],
  float v692
) {	// L1133
  for (int v693 = 0; v693 < 102; v693 += 1) {	// L1134
    for (int v694 = 0; v694 < 102; v694 += 1) {	// L1135
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v691
      v691[0][0][v693][v694] = v692;	// L1136
    }
  }
}

/// The top function
void control(
  ap_int<32> v695[102852096],
  ap_int<32> v696[102852096],
  ap_int<32> v697[102852096]
) {	// L1141
  #pragma HLS interface s_axilite port=return bundle=ctrl
  #pragma hls interface m_axi offset=direct bundle=g0 port=v695
  #pragma hls stable variable=v695
  #pragma hls interface m_axi offset=direct bundle=g0 port=v696
  #pragma hls stable variable=v696
  #pragma hls interface m_axi offset=direct bundle=g0 port=v697
  #pragma hls stable variable=v697

  auto v698 = reinterpret_cast<float(*)[1][102][102]>(v696 + 2801664);
  kernel279(v698, (float)0.000000);	// L1147
  auto v699 = reinterpret_cast<float(*)[1][96][96]>(v695);
  kernel278(v699, v698);	// L1149
  auto v700 = reinterpret_cast<float(*)[64][48][48]>(v695 + 2961664);
  auto v701 = reinterpret_cast<float(*)>(v697 + 93414912);
  kernel277(v701, v700);	// L1152
  auto v702 = reinterpret_cast<float(*)[1][7][7]>(v697 + 95774208);
  kernel276(v698, v702, v700);	// L1154
  auto v703 = reinterpret_cast<float(*)[64][48][48]>(v695 + 147456);
  auto v704 = reinterpret_cast<float(*)[64][48][48]>(v696 + 2801664);
  kernel275(v700, v703, v704);	// L1157
  kernel265(v704, v700);	// L1158
  kernel273(v700, (float)1.000000);	// L1159
  auto v705 = reinterpret_cast<float(*)[64][48][48]>(v696 + 3121664);
  kernel265(v700, v705);	// L1161
  kernel271(v705, (float)1.000000, (float)0.000000);	// L1162
  kernel270(v704, v705, v700);	// L1163
  auto v706 = reinterpret_cast<float(*)[64][48][48]>(v697 + 3281664);
  kernel269(v700, v704, v706);	// L1165
  kernel265(v705, v700);	// L1166
  kernel267(v700, (float)0.000000);	// L1167
  kernel266(v706, v700);	// L1168
  kernel265(v700, v703);	// L1169
  auto v707 = reinterpret_cast<float(*)[64][50][50]>(v695 + 2801664);
  kernel264(v707, (float)-INFINITY);	// L1171
  kernel263(v705, v707);	// L1172
  auto v708 = reinterpret_cast<float(*)[64][24][24]>(v696 + 2961664);
  kernel262(v708, (float)-INFINITY);	// L1174
  auto v709 = reinterpret_cast<float(*)[3]>(v697 + 3121664);
  kernel261(v707, v709, v708);	// L1176
  auto v710 = reinterpret_cast<float(*)[64][26][26]>(v695 + 2801664);
  kernel260(v710, (float)0.000000);	// L1178
  kernel197(v708, v710);	// L1179
  auto v711 = reinterpret_cast<float(*)[64][24][24]>(v696 + 3281664);
  auto v712 = reinterpret_cast<float(*)>(v697 + 88696320);
  kernel212(v712, v711);	// L1182
  auto v713 = reinterpret_cast<float(*)[64][3][3]>(v697 + 91055616);
  kernel211(v710, v713, v711);	// L1184
  auto v714 = reinterpret_cast<float(*)[64][24][24]>(v695 + 294912);
  auto v715 = reinterpret_cast<float(*)[64][24][24]>(v697 + 2801664);
  kernel209(v711, v714, v715);	// L1187
  kernel199(v715, v711);	// L1188
  kernel207(v711, (float)1.000000);	// L1189
  auto v716 = reinterpret_cast<float(*)[64][24][24]>(v696 + 3441664);
  kernel199(v711, v716);	// L1191
  kernel205(v716, (float)1.000000, (float)0.000000);	// L1192
  kernel204(v715, v716, v711);	// L1193
  auto v717 = reinterpret_cast<float(*)[64][24][24]>(v695 + 3601664);
  kernel203(v711, v715, v717);	// L1195
  kernel199(v716, v711);	// L1196
  kernel201(v711, (float)0.000000);	// L1197
  kernel200(v717, v711);	// L1198
  kernel199(v711, v714);	// L1199
  kernel245(v710, (float)0.000000);	// L1200
  kernel197(v716, v710);	// L1201
  auto v718 = reinterpret_cast<float(*)>(v697 + 83977728);
  kernel212(v718, v711);	// L1203
  auto v719 = reinterpret_cast<float(*)[64][3][3]>(v697 + 86337024);
  kernel211(v710, v719, v711);	// L1205
  kernel200(v708, v711);	// L1206
  auto v720 = reinterpret_cast<float(*)[64][24][24]>(v695 + 442368);
  auto v721 = reinterpret_cast<float(*)[64][24][24]>(v695 + 2801664);
  kernel209(v711, v720, v721);	// L1209
  kernel199(v721, v711);	// L1210
  kernel207(v711, (float)1.000000);	// L1211
  auto v722 = reinterpret_cast<float(*)[64][24][24]>(v697 + 2961664);
  kernel199(v711, v722);	// L1213
  kernel205(v722, (float)1.000000, (float)0.000000);	// L1214
  kernel204(v721, v722, v711);	// L1215
  auto v723 = reinterpret_cast<float(*)[64][24][24]>(v695 + 3441664);
  kernel203(v711, v721, v723);	// L1217
  kernel199(v722, v711);	// L1218
  kernel201(v711, (float)0.000000);	// L1219
  kernel200(v723, v711);	// L1220
  kernel199(v711, v720);	// L1221
  kernel229(v710, (float)0.000000);	// L1222
  kernel197(v722, v710);	// L1223
  auto v724 = reinterpret_cast<float(*)>(v697 + 79259136);
  kernel212(v724, v711);	// L1225
  auto v725 = reinterpret_cast<float(*)[64][3][3]>(v697 + 81618432);
  kernel211(v710, v725, v711);	// L1227
  auto v726 = reinterpret_cast<float(*)[64][24][24]>(v695 + 589824);
  kernel209(v711, v726, v715);	// L1229
  kernel199(v715, v711);	// L1230
  kernel207(v711, (float)1.000000);	// L1231
  kernel199(v711, v723);	// L1232
  kernel205(v723, (float)1.000000, (float)0.000000);	// L1233
  kernel204(v715, v723, v711);	// L1234
  kernel203(v711, v715, v717);	// L1235
  kernel199(v723, v711);	// L1236
  kernel201(v711, (float)0.000000);	// L1237
  kernel200(v717, v711);	// L1238
  kernel199(v711, v726);	// L1239
  kernel214(v710, (float)0.000000);	// L1240
  kernel197(v723, v710);	// L1241
  auto v727 = reinterpret_cast<float(*)>(v697 + 74540544);
  kernel212(v727, v711);	// L1243
  auto v728 = reinterpret_cast<float(*)[64][3][3]>(v697 + 76899840);
  kernel211(v710, v728, v711);	// L1245
  kernel200(v722, v711);	// L1246
  auto v729 = reinterpret_cast<float(*)[64][24][24]>(v695 + 737280);
  kernel209(v711, v729, v715);	// L1248
  kernel199(v715, v711);	// L1249
  kernel207(v711, (float)1.000000);	// L1250
  auto v730 = reinterpret_cast<float(*)[64][24][24]>(v695 + 2961664);
  kernel199(v711, v730);	// L1252
  kernel205(v730, (float)1.000000, (float)0.000000);	// L1253
  kernel204(v715, v730, v711);	// L1254
  kernel203(v711, v715, v723);	// L1255
  kernel199(v730, v711);	// L1256
  kernel201(v711, (float)0.000000);	// L1257
  kernel200(v723, v711);	// L1258
  kernel199(v711, v729);	// L1259
  auto v731 = reinterpret_cast<float(*)[64][26][26]>(v696 + 2801664);
  kernel198(v731, (float)0.000000);	// L1261
  kernel197(v730, v731);	// L1262
  auto v732 = reinterpret_cast<float(*)[128][12][12]>(v695 + 3281664);
  auto v733 = reinterpret_cast<float(*)>(v697 + 69821952);
  kernel148(v733, v732);	// L1265
  auto v734 = reinterpret_cast<float(*)[64][3][3]>(v697 + 72181248);
  kernel195(v731, v734, v732);	// L1267
  auto v735 = reinterpret_cast<float(*)[128][12][12]>(v695 + 884736);
  auto v736 = reinterpret_cast<float(*)[128][12][12]>(v697 + 2801664);
  kernel145(v732, v735, v736);	// L1270
  kernel135(v736, v732);	// L1271
  kernel143(v732, (float)1.000000);	// L1272
  auto v737 = reinterpret_cast<float(*)[128][12][12]>(v695 + 3441664);
  kernel135(v732, v737);	// L1274
  kernel141(v737, (float)1.000000, (float)0.000000);	// L1275
  kernel140(v736, v737, v732);	// L1276
  auto v738 = reinterpret_cast<float(*)[128][12][12]>(v696 + 3601664);
  kernel139(v732, v736, v738);	// L1278
  kernel135(v737, v732);	// L1279
  kernel137(v732, (float)0.000000);	// L1280
  kernel136(v738, v732);	// L1281
  kernel135(v732, v735);	// L1282
  auto v739 = reinterpret_cast<float(*)[128][14][14]>(v696 + 2801664);
  kernel183(v739, (float)0.000000);	// L1284
  kernel133(v737, v739);	// L1285
  auto v740 = reinterpret_cast<float(*)>(v697 + 65103360);
  kernel148(v740, v737);	// L1287
  auto v741 = reinterpret_cast<float(*)[128][3][3]>(v697 + 67462656);
  kernel147(v739, v741, v737);	// L1289
  auto v742 = reinterpret_cast<float(*)>(v697 + 60384768);
  kernel148(v742, v732);	// L1291
  auto v743 = reinterpret_cast<float(*)[64][1][1]>(v697 + 62744064);
  kernel178(v730, v743, v732);	// L1293
  kernel136(v737, v732);	// L1294
  auto v744 = reinterpret_cast<float(*)[128][12][12]>(v695 + 1032192);
  auto v745 = reinterpret_cast<float(*)[128][12][12]>(v696 + 2801664);
  kernel145(v732, v744, v745);	// L1297
  kernel135(v745, v732);	// L1298
  kernel143(v732, (float)1.000000);	// L1299
  auto v746 = reinterpret_cast<float(*)[128][12][12]>(v696 + 2961664);
  kernel135(v732, v746);	// L1301
  kernel141(v746, (float)1.000000, (float)0.000000);	// L1302
  kernel140(v745, v746, v732);	// L1303
  auto v747 = reinterpret_cast<float(*)[128][12][12]>(v696 + 3441664);
  kernel139(v732, v745, v747);	// L1305
  kernel135(v746, v732);	// L1306
  kernel137(v732, (float)0.000000);	// L1307
  kernel136(v747, v732);	// L1308
  kernel135(v732, v744);	// L1309
  kernel165(v739, (float)0.000000);	// L1310
  kernel133(v746, v739);	// L1311
  auto v748 = reinterpret_cast<float(*)>(v697 + 55666176);
  kernel148(v748, v732);	// L1313
  auto v749 = reinterpret_cast<float(*)[128][3][3]>(v697 + 58025472);
  kernel147(v739, v749, v732);	// L1315
  auto v750 = reinterpret_cast<float(*)[128][12][12]>(v695 + 1179648);
  kernel145(v732, v750, v745);	// L1317
  kernel135(v745, v732);	// L1318
  kernel143(v732, (float)1.000000);	// L1319
  auto v751 = reinterpret_cast<float(*)[128][12][12]>(v697 + 3441664);
  kernel135(v732, v751);	// L1321
  kernel141(v751, (float)1.000000, (float)0.000000);	// L1322
  kernel140(v745, v751, v732);	// L1323
  kernel139(v732, v745, v738);	// L1324
  kernel135(v751, v732);	// L1325
  kernel137(v732, (float)0.000000);	// L1326
  kernel136(v738, v732);	// L1327
  kernel135(v732, v750);	// L1328
  kernel150(v739, (float)0.000000);	// L1329
  kernel133(v751, v739);	// L1330
  auto v752 = reinterpret_cast<float(*)>(v697 + 50947584);
  kernel148(v752, v732);	// L1332
  auto v753 = reinterpret_cast<float(*)[128][3][3]>(v697 + 53306880);
  kernel147(v739, v753, v732);	// L1334
  kernel136(v746, v732);	// L1335
  auto v754 = reinterpret_cast<float(*)[128][12][12]>(v695 + 1327104);
  kernel145(v732, v754, v745);	// L1337
  kernel135(v745, v732);	// L1338
  kernel143(v732, (float)1.000000);	// L1339
  kernel135(v732, v746);	// L1340
  kernel141(v746, (float)1.000000, (float)0.000000);	// L1341
  kernel140(v745, v746, v732);	// L1342
  kernel139(v732, v745, v751);	// L1343
  kernel135(v746, v732);	// L1344
  kernel137(v732, (float)0.000000);	// L1345
  kernel136(v751, v732);	// L1346
  kernel135(v732, v754);	// L1347
  auto v755 = reinterpret_cast<float(*)[128][14][14]>(v695 + 2801664);
  kernel134(v755, (float)0.000000);	// L1349
  kernel133(v746, v755);	// L1350
  auto v756 = reinterpret_cast<float(*)[256][6][6]>(v696 + 3281664);
  auto v757 = reinterpret_cast<float(*)>(v697 + 46228992);
  kernel84(v757, v756);	// L1353
  auto v758 = reinterpret_cast<float(*)[128][3][3]>(v697 + 48588288);
  kernel131(v755, v758, v756);	// L1355
  auto v759 = reinterpret_cast<float(*)[256][6][6]>(v695 + 1474560);
  auto v760 = reinterpret_cast<float(*)[256][6][6]>(v697 + 2801664);
  kernel81(v756, v759, v760);	// L1358
  kernel71(v760, v756);	// L1359
  kernel79(v756, (float)1.000000);	// L1360
  auto v761 = reinterpret_cast<float(*)[256][6][6]>(v695 + 3441664);
  kernel71(v756, v761);	// L1362
  kernel77(v761, (float)1.000000, (float)0.000000);	// L1363
  kernel76(v760, v761, v756);	// L1364
  auto v762 = reinterpret_cast<float(*)[256][6][6]>(v695 + 3601664);
  kernel75(v756, v760, v762);	// L1366
  kernel71(v761, v756);	// L1367
  kernel73(v756, (float)0.000000);	// L1368
  kernel72(v762, v756);	// L1369
  kernel71(v756, v759);	// L1370
  auto v763 = reinterpret_cast<float(*)[256][8][8]>(v695 + 2801664);
  kernel119(v763, (float)0.000000);	// L1372
  kernel69(v761, v763);	// L1373
  auto v764 = reinterpret_cast<float(*)[256][6][6]>(v696 + 3441664);
  auto v765 = reinterpret_cast<float(*)>(v697 + 41510400);
  kernel84(v765, v764);	// L1376
  auto v766 = reinterpret_cast<float(*)[256][3][3]>(v697 + 43869696);
  kernel83(v763, v766, v764);	// L1378
  auto v767 = reinterpret_cast<float(*)>(v697 + 36791808);
  kernel84(v767, v756);	// L1380
  auto v768 = reinterpret_cast<float(*)[128][1][1]>(v697 + 39151104);
  kernel114(v746, v768, v756);	// L1382
  kernel72(v764, v756);	// L1383
  auto v769 = reinterpret_cast<float(*)[256][6][6]>(v695 + 1622016);
  auto v770 = reinterpret_cast<float(*)[256][6][6]>(v695 + 2801664);
  kernel81(v756, v769, v770);	// L1386
  kernel71(v770, v756);	// L1387
  kernel79(v756, (float)1.000000);	// L1388
  auto v771 = reinterpret_cast<float(*)[256][6][6]>(v695 + 2961664);
  kernel71(v756, v771);	// L1390
  kernel77(v771, (float)1.000000, (float)0.000000);	// L1391
  kernel76(v770, v771, v756);	// L1392
  auto v772 = reinterpret_cast<float(*)[256][6][6]>(v697 + 3441664);
  kernel75(v756, v770, v772);	// L1394
  kernel71(v771, v756);	// L1395
  kernel73(v756, (float)0.000000);	// L1396
  kernel72(v772, v756);	// L1397
  kernel71(v756, v769);	// L1398
  auto v773 = reinterpret_cast<float(*)[256][8][8]>(v696 + 2801664);
  kernel101(v773, (float)0.000000);	// L1400
  kernel69(v771, v773);	// L1401
  auto v774 = reinterpret_cast<float(*)>(v697 + 32073216);
  kernel84(v774, v756);	// L1403
  auto v775 = reinterpret_cast<float(*)[256][3][3]>(v697 + 34432512);
  kernel83(v773, v775, v756);	// L1405
  auto v776 = reinterpret_cast<float(*)[256][6][6]>(v695 + 1769472);
  kernel81(v756, v776, v760);	// L1407
  kernel71(v760, v756);	// L1408
  kernel79(v756, (float)1.000000);	// L1409
  kernel71(v756, v761);	// L1410
  kernel77(v761, (float)1.000000, (float)0.000000);	// L1411
  kernel76(v760, v761, v756);	// L1412
  kernel75(v756, v760, v762);	// L1413
  kernel71(v761, v756);	// L1414
  kernel73(v756, (float)0.000000);	// L1415
  kernel72(v762, v756);	// L1416
  kernel71(v756, v776);	// L1417
  kernel86(v763, (float)0.000000);	// L1418
  kernel69(v761, v763);	// L1419
  auto v777 = reinterpret_cast<float(*)>(v697 + 27354624);
  kernel84(v777, v756);	// L1421
  auto v778 = reinterpret_cast<float(*)[256][3][3]>(v697 + 29713920);
  kernel83(v763, v778, v756);	// L1423
  kernel72(v771, v756);	// L1424
  auto v779 = reinterpret_cast<float(*)[256][6][6]>(v695 + 1916928);
  kernel81(v756, v779, v770);	// L1426
  kernel71(v770, v756);	// L1427
  kernel79(v756, (float)1.000000);	// L1428
  kernel71(v756, v771);	// L1429
  kernel77(v771, (float)1.000000, (float)0.000000);	// L1430
  kernel76(v770, v771, v756);	// L1431
  kernel75(v756, v770, v772);	// L1432
  kernel71(v771, v756);	// L1433
  kernel73(v756, (float)0.000000);	// L1434
  kernel72(v772, v756);	// L1435
  kernel71(v756, v779);	// L1436
  kernel70(v763, (float)0.000000);	// L1437
  kernel69(v771, v763);	// L1438
  auto v780 = reinterpret_cast<float(*)[512][3][3]>(v695 + 3281664);
  auto v781 = reinterpret_cast<float(*)>(v697 + 22636032);
  kernel20(v781, v780);	// L1441
  auto v782 = reinterpret_cast<float(*)[256][3][3]>(v697 + 24995328);
  kernel67(v763, v782, v780);	// L1443
  auto v783 = reinterpret_cast<float(*)[512][3][3]>(v695 + 2064384);
  auto v784 = reinterpret_cast<float(*)[512][3][3]>(v696 + 2801664);
  kernel17(v780, v783, v784);	// L1446
  kernel7(v784, v780);	// L1447
  kernel15(v780, (float)1.000000);	// L1448
  auto v785 = reinterpret_cast<float(*)[512][3][3]>(v696 + 3441664);
  kernel7(v780, v785);	// L1450
  kernel13(v785, (float)1.000000, (float)0.000000);	// L1451
  kernel12(v784, v785, v780);	// L1452
  auto v786 = reinterpret_cast<float(*)[512][3][3]>(v697 + 3601664);
  kernel11(v780, v784, v786);	// L1454
  kernel7(v785, v780);	// L1455
  kernel9(v780, (float)0.000000);	// L1456
  kernel8(v786, v780);	// L1457
  kernel7(v780, v783);	// L1458
  auto v787 = reinterpret_cast<float(*)[512][5][5]>(v695 + 2801664);
  kernel55(v787, (float)0.000000);	// L1460
  kernel21(v785, v787);	// L1461
  auto v788 = reinterpret_cast<float(*)[512][3][3]>(v695 + 3441664);
  auto v789 = reinterpret_cast<float(*)>(v697 + 17917440);
  kernel20(v789, v788);	// L1464
  auto v790 = reinterpret_cast<float(*)[512][3][3]>(v697 + 20276736);
  kernel19(v787, v790, v788);	// L1466
  auto v791 = reinterpret_cast<float(*)>(v697 + 13198848);
  kernel20(v791, v780);	// L1468
  auto v792 = reinterpret_cast<float(*)[256][1][1]>(v697 + 15558144);
  kernel50(v771, v792, v780);	// L1470
  kernel8(v788, v780);	// L1471
  auto v793 = reinterpret_cast<float(*)[512][3][3]>(v695 + 2211840);
  kernel17(v780, v793, v784);	// L1473
  kernel7(v784, v780);	// L1474
  kernel15(v780, (float)1.000000);	// L1475
  auto v794 = reinterpret_cast<float(*)[512][3][3]>(v697 + 2961664);
  kernel7(v780, v794);	// L1477
  kernel13(v794, (float)1.000000, (float)0.000000);	// L1478
  kernel12(v784, v794, v780);	// L1479
  auto v795 = reinterpret_cast<float(*)[512][3][3]>(v697 + 3441664);
  kernel11(v780, v784, v795);	// L1481
  kernel7(v794, v780);	// L1482
  kernel9(v780, (float)0.000000);	// L1483
  kernel8(v795, v780);	// L1484
  kernel7(v780, v793);	// L1485
  kernel37(v787, (float)0.000000);	// L1486
  kernel21(v794, v787);	// L1487
  auto v796 = reinterpret_cast<float(*)>(v697 + 8480256);
  kernel20(v796, v780);	// L1489
  auto v797 = reinterpret_cast<float(*)[512][3][3]>(v697 + 10839552);
  kernel19(v787, v797, v780);	// L1491
  auto v798 = reinterpret_cast<float(*)[512][3][3]>(v695 + 2359296);
  kernel17(v780, v798, v784);	// L1493
  kernel7(v784, v780);	// L1494
  kernel15(v780, (float)1.000000);	// L1495
  kernel7(v780, v785);	// L1496
  kernel13(v785, (float)1.000000, (float)0.000000);	// L1497
  kernel12(v784, v785, v780);	// L1498
  kernel11(v780, v784, v786);	// L1499
  kernel7(v785, v780);	// L1500
  kernel9(v780, (float)0.000000);	// L1501
  kernel8(v786, v780);	// L1502
  kernel7(v780, v798);	// L1503
  kernel22(v787, (float)0.000000);	// L1504
  kernel21(v785, v787);	// L1505
  auto v799 = reinterpret_cast<float(*)>(v697 + 3761664);
  kernel20(v799, v780);	// L1507
  auto v800 = reinterpret_cast<float(*)[512][3][3]>(v697 + 6120960);
  kernel19(v787, v800, v780);	// L1509
  kernel8(v794, v780);	// L1510
  auto v801 = reinterpret_cast<float(*)[512][3][3]>(v695 + 2506752);
  kernel17(v780, v801, v784);	// L1512
  kernel7(v784, v780);	// L1513
  kernel15(v780, (float)1.000000);	// L1514
  auto v802 = reinterpret_cast<float(*)[512][3][3]>(v696 + 2961664);
  kernel7(v780, v802);	// L1516
  kernel13(v802, (float)1.000000, (float)0.000000);	// L1517
  kernel12(v784, v802, v780);	// L1518
  kernel11(v780, v784, v785);	// L1519
  kernel7(v802, v780);	// L1520
  kernel9(v780, (float)0.000000);	// L1521
  kernel8(v785, v780);	// L1522
  kernel7(v780, v801);	// L1523
  auto v803 = reinterpret_cast<float(*)[512][1][1]>(v696 + 2801664);
  kernel6(v803, (float)0.000000);	// L1525
  kernel5(v802, v709, v803);	// L1526
  kernel4(v803, (float)9.000000);	// L1527
  auto v804 = reinterpret_cast<float(*)[10]>(v697 + 2961664);
  auto v805 = reinterpret_cast<float(*)[512]>(v696 + 100492800);
  kernel3(v805, v804);	// L1530
  auto v806 = reinterpret_cast<float(*)[10]>(v695 + 2654208);
  kernel2(v806, (float)0.000000);	// L1532
  kernel1(v803, v804, v806);	// L1533
  auto v807 = reinterpret_cast<float(*)>(v697 + 98133504);
  kernel0(v807, v806);	// L1535
}

/// The T-step wrapper (FHCA v1.4: on-chip time-step loop)
/// Drives the single-step control T times; membrane states persist in DDR top_level buffers.
/// input_frames: DDR staging of T input frames (per-step-input);
///   frame t is memcpy'd to the input slot (arg0+0) before step t.
///   frame_elems=0: static input (host pre-writes frame, no copy).
/// out_frames: per-step outputs staged to DDR (out region assumed on
///   arg0 at out_elem_offset); out_elems=0: skip staging.
void control_t(
  ap_int<32> t_v0[102852096],
  ap_int<32> t_v1[102852096],
  ap_int<32> t_v2[102852096],
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

