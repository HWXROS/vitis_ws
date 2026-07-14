
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
  auto v51 = reinterpret_cast<float(*)[1536][1][1]>(v49);

  for (int v52 = 0; v52 < 1536; v52 += 1) {	// L82
    for (int v53 = 0; v53 < 384; v53 += 1) {	// L83
      for (int v54 = 0; v54 < 8; v54 += 1) {	// L84
        for (int v55 = 0; v55 < 8; v55 += 1) {	// L85
          #pragma HLS pipeline II=1
          #pragma HLS dependence false variable=v48
          #pragma HLS dependence false variable=v50
          #pragma HLS dependence false variable=v51
          float v56 = v48[0][v52][v54][v55];	// L86
          float v57 = v51[v53][v52][0][0];	// L87
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
  #pragma HLS resource variable=v63 core=ram_t2p_bram

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
  float v83
) {	// L135
  for (int v84 = 0; v84 < 1536; v84 += 1) {	// L136
    for (int v85 = 0; v85 < 8; v85 += 1) {	// L137
      for (int v86 = 0; v86 < 8; v86 += 1) {	// L138
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v82
        float v87 = v82[0][v84][v85][v86];	// L139
        float v88 = v87 * v83;	// L140
        v82[0][v84][v85][v86] = v88;	// L141
      }
    }
  }
}

void kernel14(
  float v89[1][1536][8][8],
  float v90[1][1536][8][8],
  float v91[1][1536][8][8]
) {	// L147
  for (int v92 = 0; v92 < 1536; v92 += 1) {	// L148
    for (int v93 = 0; v93 < 8; v93 += 1) {	// L149
      for (int v94 = 0; v94 < 8; v94 += 1) {	// L150
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v90
        #pragma HLS dependence false variable=v91
        #pragma HLS dependence false variable=v89
        float v95 = v90[0][v92][v93][v94];	// L151
        float v96 = v89[0][v92][v93][v94];	// L152
        float v97 = v95 - v96;	// L153
        v91[0][v92][v93][v94] = v97;	// L154
      }
    }
  }
}

void kernel15(
  float v98[1][1536][8][8],
  float v99[1][1536][8][8],
  float v100[1][1536][8][8]
) {	// L160
  for (int v101 = 0; v101 < 1536; v101 += 1) {	// L161
    for (int v102 = 0; v102 < 8; v102 += 1) {	// L162
      for (int v103 = 0; v103 < 8; v103 += 1) {	// L163
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v99
        #pragma HLS dependence false variable=v100
        #pragma HLS dependence false variable=v98
        float v104 = v99[0][v101][v102][v103];	// L164
        float v105 = v98[0][v101][v102][v103];	// L165
        float v106 = v104 * v105;	// L166
        v100[0][v101][v102][v103] = v106;	// L167
      }
    }
  }
}

void kernel16(
  float v107[1][1536][8][8],
  float v108,
  float v109
) {	// L173
  for (int v110 = 0; v110 < 1536; v110 += 1) {	// L174
    for (int v111 = 0; v111 < 8; v111 += 1) {	// L175
      for (int v112 = 0; v112 < 8; v112 += 1) {	// L176
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v107
        float v113 = v107[0][v110][v111][v112];	// L177
        bool v114 = v113 >= v109;	// L178
        float v115 = v114 ? v108 : v109;	// L179
        v107[0][v110][v111][v112] = v115;	// L180
      }
    }
  }
}

void kernel18(
  float v116[1][1536][8][8],
  float v117
) {	// L186
  for (int v118 = 0; v118 < 1536; v118 += 1) {	// L187
    for (int v119 = 0; v119 < 8; v119 += 1) {	// L188
      for (int v120 = 0; v120 < 8; v120 += 1) {	// L189
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v116
        float v121 = v116[0][v118][v119][v120];	// L190
        float v122 = v121 - v117;	// L191
        v116[0][v118][v119][v120] = v122;	// L192
      }
    }
  }
}

void kernel20(
  float v123[1][1536][8][8],
  float v124[1][1536][8][8],
  float v125[1][1536][8][8]
) {	// L198
  for (int v126 = 0; v126 < 1536; v126 += 1) {	// L199
    for (int v127 = 0; v127 < 8; v127 += 1) {	// L200
      for (int v128 = 0; v128 < 8; v128 += 1) {	// L201
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v124
        #pragma HLS dependence false variable=v125
        #pragma HLS dependence false variable=v123
        float v129 = v124[0][v126][v127][v128];	// L202
        float v130 = v123[0][v126][v127][v128];	// L203
        float v131 = v129 + v130;	// L204
        v125[0][v126][v127][v128] = v131;	// L205
      }
    }
  }
}

void kernel21(
  float v132[1][1536][8][8],
  float v133
) {	// L211
  for (int v134 = 0; v134 < 1536; v134 += 1) {	// L212
    for (int v135 = 0; v135 < 8; v135 += 1) {	// L213
      for (int v136 = 0; v136 < 8; v136 += 1) {	// L214
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v132
        float v137 = v132[0][v134][v135][v136];	// L215
        float v138 = v137 / v133;	// L216
        v132[0][v134][v135][v136] = v138;	// L217
      }
    }
  }
}

void kernel26(
  float v139[1][384][8][8],
  float v140[1536][384][1][1],
  float v141[1][1536][8][8]
) {	// L223
  auto v142 = reinterpret_cast<float(*)[384][1][1]>(v140);

  for (int v143 = 0; v143 < 384; v143 += 1) {	// L226
    for (int v144 = 0; v144 < 1536; v144 += 1) {	// L227
      for (int v145 = 0; v145 < 8; v145 += 1) {	// L228
        for (int v146 = 0; v146 < 8; v146 += 1) {	// L229
          #pragma HLS pipeline II=1
          #pragma HLS dependence false variable=v139
          #pragma HLS dependence false variable=v141
          #pragma HLS dependence false variable=v142
          float v147 = v139[0][v143][v145][v146];	// L230
          float v148 = v142[v144][v143][0][0];	// L231
          float v149 = v141[0][v144][v145][v146];	// L232
          float v150 = v147 * v148;	// L233
          float v151 = v149 + v150;	// L234
          v141[0][v144][v145][v146] = v151;	// L235
        }
      }
    }
  }
}

void kernel27(
  float v152[1536],
  float v153[1][1536][8][8]
) {	// L242
  float v154[1536];	// L243
  #pragma HLS resource variable=v154 core=ram_t2p_bram

  memcpy(v154, v152, 1536 * sizeof(float));	// L244

  for (int v155 = 0; v155 < 1536; v155 += 1) {	// L245
    for (int v156 = 0; v156 < 8; v156 += 1) {	// L246
      for (int v157 = 0; v157 < 8; v157 += 1) {	// L247
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v154
        #pragma HLS dependence false variable=v153
        float v158 = v154[v155];	// L248
        v153[0][v155][v156][v157] = v158;	// L249
      }
    }
  }
}

void kernel28(
  float v159[1][384][8][8],
  float v160[1][384][8][8]
) {	// L255
  for (int v161 = 0; v161 < 384; v161 += 1) {	// L256
    for (int v162 = 0; v162 < 8; v162 += 1) {	// L257
      for (int v163 = 0; v163 < 8; v163 += 1) {	// L258
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v159
        #pragma HLS dependence false variable=v160
        float v164 = v159[0][v161][v162][v163];	// L259
        v160[0][v161][v162][v163] = v164;	// L260
      }
    }
  }
}

void kernel30(
  float v165[1][384][8][8],
  float v166
) {	// L266
  for (int v167 = 0; v167 < 384; v167 += 1) {	// L267
    for (int v168 = 0; v168 < 8; v168 += 1) {	// L268
      for (int v169 = 0; v169 < 8; v169 += 1) {	// L269
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v165
        float v170 = v165[0][v167][v168][v169];	// L270
        float v171 = v170 * v166;	// L271
        v165[0][v167][v168][v169] = v171;	// L272
      }
    }
  }
}

void kernel32(
  float v172[1][384][8][8],
  float v173[1][384][8][8],
  float v174[1][384][8][8]
) {	// L278
  for (int v175 = 0; v175 < 384; v175 += 1) {	// L279
    for (int v176 = 0; v176 < 8; v176 += 1) {	// L280
      for (int v177 = 0; v177 < 8; v177 += 1) {	// L281
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v173
        #pragma HLS dependence false variable=v174
        #pragma HLS dependence false variable=v172
        float v178 = v173[0][v175][v176][v177];	// L282
        float v179 = v172[0][v175][v176][v177];	// L283
        float v180 = v178 - v179;	// L284
        v174[0][v175][v176][v177] = v180;	// L285
      }
    }
  }
}

void kernel33(
  float v181[1][384][8][8],
  float v182[1][384][8][8],
  float v183[1][384][8][8]
) {	// L291
  for (int v184 = 0; v184 < 384; v184 += 1) {	// L292
    for (int v185 = 0; v185 < 8; v185 += 1) {	// L293
      for (int v186 = 0; v186 < 8; v186 += 1) {	// L294
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v182
        #pragma HLS dependence false variable=v183
        #pragma HLS dependence false variable=v181
        float v187 = v182[0][v184][v185][v186];	// L295
        float v188 = v181[0][v184][v185][v186];	// L296
        float v189 = v187 * v188;	// L297
        v183[0][v184][v185][v186] = v189;	// L298
      }
    }
  }
}

void kernel34(
  float v190[1][384][8][8],
  float v191,
  float v192
) {	// L304
  for (int v193 = 0; v193 < 384; v193 += 1) {	// L305
    for (int v194 = 0; v194 < 8; v194 += 1) {	// L306
      for (int v195 = 0; v195 < 8; v195 += 1) {	// L307
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v190
        float v196 = v190[0][v193][v194][v195];	// L308
        bool v197 = v196 >= v192;	// L309
        float v198 = v197 ? v191 : v192;	// L310
        v190[0][v193][v194][v195] = v198;	// L311
      }
    }
  }
}

void kernel36(
  float v199[1][384][8][8],
  float v200
) {	// L317
  for (int v201 = 0; v201 < 384; v201 += 1) {	// L318
    for (int v202 = 0; v202 < 8; v202 += 1) {	// L319
      for (int v203 = 0; v203 < 8; v203 += 1) {	// L320
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v199
        float v204 = v199[0][v201][v202][v203];	// L321
        float v205 = v204 - v200;	// L322
        v199[0][v201][v202][v203] = v205;	// L323
      }
    }
  }
}

void kernel38(
  float v206[1][384][8][8],
  float v207[1][384][8][8],
  float v208[1][384][8][8]
) {	// L329
  for (int v209 = 0; v209 < 384; v209 += 1) {	// L330
    for (int v210 = 0; v210 < 8; v210 += 1) {	// L331
      for (int v211 = 0; v211 < 8; v211 += 1) {	// L332
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v207
        #pragma HLS dependence false variable=v208
        #pragma HLS dependence false variable=v206
        float v212 = v207[0][v209][v210][v211];	// L333
        float v213 = v206[0][v209][v210][v211];	// L334
        float v214 = v212 + v213;	// L335
        v208[0][v209][v210][v211] = v214;	// L336
      }
    }
  }
}

void kernel39(
  float v215[1][384][8][8],
  float v216
) {	// L342
  for (int v217 = 0; v217 < 384; v217 += 1) {	// L343
    for (int v218 = 0; v218 < 8; v218 += 1) {	// L344
      for (int v219 = 0; v219 < 8; v219 += 1) {	// L345
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v215
        float v220 = v215[0][v217][v218][v219];	// L346
        float v221 = v220 / v216;	// L347
        v215[0][v217][v218][v219] = v221;	// L348
      }
    }
  }
}

void kernel44(
  float v222[1][384][64],
  float v223[1][384][8][8],
  float v224[1][384][8][8]
) {	// L354
  for (int v225 = 0; v225 < 384; v225 += 1) {	// L355
    for (int v226 = 0; v226 < 8; v226 += 1) {	// L356
      for (int v227 = 0; v227 < 8; v227 += 1) {	// L357
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v223
        #pragma HLS dependence false variable=v224
        #pragma HLS dependence false variable=v222
        float v228 = v223[0][v225][v226][v227];	// L358
        float v229 = v222[0][v225][((v226 * 8) + v227)];	// L359
        float v230 = v228 + v229;	// L360
        v224[0][v225][v226][v227] = v230;	// L361
      }
    }
  }
}

void kernel45(
  float v231[1][384][64],
  float v232[384][384][1],
  float v233[1][384][64]
) {	// L367
  auto v234 = reinterpret_cast<float(*)[384][1]>(v232);

  for (int v235 = 0; v235 < 384; v235 += 1) {	// L370
    for (int v236 = 0; v236 < 384; v236 += 1) {	// L371
      for (int v237 = 0; v237 < 64; v237 += 1) {	// L372
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v231
        #pragma HLS dependence false variable=v233
        #pragma HLS dependence false variable=v234
        float v238 = v231[0][v235][v237];	// L373
        float v239 = v234[v236][v235][0];	// L374
        float v240 = v233[0][v236][v237];	// L375
        float v241 = v238 * v239;	// L376
        float v242 = v240 + v241;	// L377
        v233[0][v236][v237] = v242;	// L378
      }
    }
  }
}

void kernel46(
  float v243[384],
  float v244[1][384][64]
) {	// L384
  float v245[384];	// L385
  #pragma HLS resource variable=v245 core=ram_t2p_bram

  memcpy(v245, v243, 384 * sizeof(float));	// L386

  for (int v246 = 0; v246 < 384; v246 += 1) {	// L387
    for (int v247 = 0; v247 < 64; v247 += 1) {	// L388
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v245
      #pragma HLS dependence false variable=v244
      float v248 = v245[v246];	// L389
      v244[0][v246][v247] = v248;	// L390
    }
  }
}

void kernel47(
  float v249[1][64][384],
  float v250[1][384][64]
) {	// L395
  for (int v251 = 0; v251 < 384; v251 += 1) {	// L396
    for (int v252 = 0; v252 < 64; v252 += 1) {	// L397
      float v253 = v249[0][v252][v251];	// L398
      v250[0][v251][v252] = v253;	// L399
    }
  }
}

void kernel48(
  float v254[1][64][384],
  float v255[1][64][384]
) {	// L404
  for (int v256 = 0; v256 < 64; v256 += 1) {	// L405
    for (int v257 = 0; v257 < 384; v257 += 1) {	// L406
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v254
      #pragma HLS dependence false variable=v255
      float v258 = v254[0][v256][v257];	// L407
      v255[0][v256][v257] = v258;	// L408
    }
  }
}

void kernel49(
  float v259[1][64][384],
  float v260[1][64][384]
) {	// L413
  for (int v261 = 0; v261 < 64; v261 += 1) {	// L414
    for (int v262 = 0; v262 < 384; v262 += 1) {	// L415
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v259
      #pragma HLS dependence false variable=v260
      float v263 = v259[0][v261][v262];	// L416
      float v264 = v260[0][v261][v262];	// L417
      float v265 = v263 + v264;	// L418
      v260[0][v261][v262] = v265;	// L419
    }
  }
}

void kernel50(
  float v266[1][64][384],
  float v267
) {	// L424
  for (int v268 = 0; v268 < 64; v268 += 1) {	// L425
    for (int v269 = 0; v269 < 384; v269 += 1) {	// L426
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v266
      float v270 = v266[0][v268][v269];	// L427
      float v271 = v270 * v267;	// L428
      v266[0][v268][v269] = v271;	// L429
    }
  }
}

void kernel52(
  float v272[1][64][384],
  float v273[1][64][384],
  float v274[1][64][384]
) {	// L434
  for (int v275 = 0; v275 < 64; v275 += 1) {	// L435
    for (int v276 = 0; v276 < 384; v276 += 1) {	// L436
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v273
      #pragma HLS dependence false variable=v274
      #pragma HLS dependence false variable=v272
      float v277 = v273[0][v275][v276];	// L437
      float v278 = v272[0][v275][v276];	// L438
      float v279 = v277 - v278;	// L439
      v274[0][v275][v276] = v279;	// L440
    }
  }
}

void kernel53(
  float v280[1][64][384],
  float v281[1][64][384],
  float v282[1][64][384]
) {	// L445
  for (int v283 = 0; v283 < 64; v283 += 1) {	// L446
    for (int v284 = 0; v284 < 384; v284 += 1) {	// L447
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v281
      #pragma HLS dependence false variable=v282
      #pragma HLS dependence false variable=v280
      float v285 = v281[0][v283][v284];	// L448
      float v286 = v280[0][v283][v284];	// L449
      float v287 = v285 * v286;	// L450
      v282[0][v283][v284] = v287;	// L451
    }
  }
}

void kernel54(
  float v288[1][64][384],
  float v289,
  float v290
) {	// L456
  for (int v291 = 0; v291 < 64; v291 += 1) {	// L457
    for (int v292 = 0; v292 < 384; v292 += 1) {	// L458
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v288
      float v293 = v288[0][v291][v292];	// L459
      bool v294 = v293 >= v290;	// L460
      float v295 = v294 ? v289 : v290;	// L461
      v288[0][v291][v292] = v295;	// L462
    }
  }
}

void kernel56(
  float v296[1][64][384],
  float v297
) {	// L467
  for (int v298 = 0; v298 < 64; v298 += 1) {	// L468
    for (int v299 = 0; v299 < 384; v299 += 1) {	// L469
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v296
      float v300 = v296[0][v298][v299];	// L470
      float v301 = v300 - v297;	// L471
      v296[0][v298][v299] = v301;	// L472
    }
  }
}

void kernel58(
  float v302[1][64][384],
  float v303[1][64][384],
  float v304[1][64][384]
) {	// L477
  for (int v305 = 0; v305 < 64; v305 += 1) {	// L478
    for (int v306 = 0; v306 < 384; v306 += 1) {	// L479
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v303
      #pragma HLS dependence false variable=v304
      #pragma HLS dependence false variable=v302
      float v307 = v303[0][v305][v306];	// L480
      float v308 = v302[0][v305][v306];	// L481
      float v309 = v307 + v308;	// L482
      v304[0][v305][v306] = v309;	// L483
    }
  }
}

void kernel59(
  float v310[1][64][384],
  float v311
) {	// L488
  for (int v312 = 0; v312 < 64; v312 += 1) {	// L489
    for (int v313 = 0; v313 < 384; v313 += 1) {	// L490
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v310
      float v314 = v310[0][v312][v313];	// L491
      float v315 = v314 / v311;	// L492
      v310[0][v312][v313] = v315;	// L493
    }
  }
}

void kernel60(
  float v316[1][64][12][32],
  float v317[1][64][384]
) {	// L498
  for (int v318 = 0; v318 < 64; v318 += 1) {	// L499
    for (int v319 = 0; v319 < 384; v319 += 1) {	// L500
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v316
      #pragma HLS dependence false variable=v317
      float v320 = v316[0][v318][(v319 / 32)][(v319 % 32)];	// L501
      v317[0][v318][v319] = v320;	// L502
    }
  }
}

void kernel64(
  float v321[1][12][64][32],
  float v322[1][64][12][32]
) {	// L507
  for (int v323 = 0; v323 < 64; v323 += 1) {	// L508
    for (int v324 = 0; v324 < 12; v324 += 1) {	// L509
      for (int v325 = 0; v325 < 32; v325 += 1) {	// L510
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v321
        #pragma HLS dependence false variable=v322
        float v326 = v321[0][v324][v323][v325];	// L511
        v322[0][v323][v324][v325] = v326;	// L512
      }
    }
  }
}

void kernel65(
  float v327[12][64][32],
  float v328[1],
  float v329[1][12][64][32]
) {	// L518
  float v330[1];	// L519
  memcpy(v330, v328, 1 * sizeof(float));	// L520

  for (int v331 = 0; v331 < 12; v331 += 1) {	// L521
    for (int v332 = 0; v332 < 64; v332 += 1) {	// L522
      for (int v333 = 0; v333 < 32; v333 += 1) {	// L523
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v327
        #pragma HLS dependence false variable=v329
        #pragma HLS dependence false variable=v330
        float v334 = v327[v331][v332][v333];	// L524
        float v335 = v330[0];	// L525
        float v336 = v334 * v335;	// L526
        v329[0][v331][v332][v333] = v336;	// L527
      }
    }
  }
}

void kernel66(
  float v337[1][12][64][64],
  float v338[1][12][64][32],
  float v339[12][64][32]
) {	// L533
  auto v340 = reinterpret_cast<float(*)[12][64][64]>(v337);

  for (int v341 = 0; v341 < 64; v341 += 1) {	// L536
    for (int v342 = 0; v342 < 12; v342 += 1) {	// L537
      for (int v343 = 0; v343 < 64; v343 += 1) {	// L538
        for (int v344 = 0; v344 < 32; v344 += 1) {	// L539
          #pragma HLS pipeline II=1
          #pragma HLS dependence false variable=v340
          #pragma HLS dependence false variable=v338
          #pragma HLS dependence false variable=v339
          float v345 = v340[0][v342][v343][v341];	// L540
          float v346 = v338[0][v342][v341][v344];	// L541
          float v347 = v339[v342][v343][v344];	// L542
          float v348 = v345 * v346;	// L543
          float v349 = v347 + v348;	// L544
          v339[v342][v343][v344] = v349;	// L545
        }
      }
    }
  }
}

void kernel67(
  float v350[1][12][64][32],
  float v351[1][12][64][32]
) {	// L552
  for (int v352 = 0; v352 < 12; v352 += 1) {	// L553
    for (int v353 = 0; v353 < 64; v353 += 1) {	// L554
      for (int v354 = 0; v354 < 32; v354 += 1) {	// L555
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v350
        #pragma HLS dependence false variable=v351
        float v355 = v350[0][v352][v353][v354];	// L556
        v351[0][v352][v353][v354] = v355;	// L557
      }
    }
  }
}

void kernel68(
  float v356[12][64][64],
  float v357[1][12][64][64]
) {	// L563
  for (int v358 = 0; v358 < 12; v358 += 1) {	// L564
    for (int v359 = 0; v359 < 64; v359 += 1) {	// L565
      for (int v360 = 0; v360 < 64; v360 += 1) {	// L566
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v356
        #pragma HLS dependence false variable=v357
        float v361 = v356[v358][v359][v360];	// L567
        v357[0][v358][v359][v360] = v361;	// L568
      }
    }
  }
}

void kernel69(
  float v362[1][12][64][32],
  float v363[1][12][32][64],
  float v364[12][64][64]
) {	// L574
  auto v365 = reinterpret_cast<float(*)[12][64][32]>(v362);

  for (int v366 = 0; v366 < 32; v366 += 1) {	// L577
    for (int v367 = 0; v367 < 12; v367 += 1) {	// L578
      for (int v368 = 0; v368 < 64; v368 += 1) {	// L579
        for (int v369 = 0; v369 < 64; v369 += 1) {	// L580
          #pragma HLS pipeline II=1
          #pragma HLS dependence false variable=v365
          #pragma HLS dependence false variable=v363
          #pragma HLS dependence false variable=v364
          float v370 = v365[0][v367][v368][v366];	// L581
          float v371 = v363[0][v367][v366][v369];	// L582
          float v372 = v364[v367][v368][v369];	// L583
          float v373 = v370 * v371;	// L584
          float v374 = v372 + v373;	// L585
          v364[v367][v368][v369] = v374;	// L586
        }
      }
    }
  }
}

void kernel70(
  float v375[1][12][32][64],
  float v376[1][12][32][64]
) {	// L593
  for (int v377 = 0; v377 < 12; v377 += 1) {	// L594
    for (int v378 = 0; v378 < 32; v378 += 1) {	// L595
      for (int v379 = 0; v379 < 64; v379 += 1) {	// L596
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v375
        #pragma HLS dependence false variable=v376
        float v380 = v375[0][v377][v378][v379];	// L597
        v376[0][v377][v378][v379] = v380;	// L598
      }
    }
  }
}

void kernel72(
  float v381[1][64][384],
  float v382[1][12][32][64]
) {	// L604
  for (int v383 = 0; v383 < 12; v383 += 1) {	// L605
    for (int v384 = 0; v384 < 32; v384 += 1) {	// L606
      for (int v385 = 0; v385 < 64; v385 += 1) {	// L607
        float v386 = v381[0][v385][((v383 * 32) + v384)];	// L608
        v382[0][v383][v384][v385] = v386;	// L609
      }
    }
  }
}

void kernel73(
  float v387[1][64][384],
  float v388[1][12][64][32]
) {	// L615
  for (int v389 = 0; v389 < 12; v389 += 1) {	// L616
    for (int v390 = 0; v390 < 64; v390 += 1) {	// L617
      for (int v391 = 0; v391 < 32; v391 += 1) {	// L618
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v387
        #pragma HLS dependence false variable=v388
        float v392 = v387[0][v390][((v389 * 32) + v391)];	// L619
        v388[0][v389][v390][v391] = v392;	// L620
      }
    }
  }
}

void kernel74(
  float v393[1][384][64],
  float v394[1][64][384]
) {	// L626
  for (int v395 = 0; v395 < 64; v395 += 1) {	// L627
    for (int v396 = 0; v396 < 384; v396 += 1) {	// L628
      float v397 = v393[0][v396][v395];	// L629
      v394[0][v395][v396] = v397;	// L630
    }
  }
}

void kernel75(
  float v398[1][384][64],
  float v399[1][384][64]
) {	// L635
  for (int v400 = 0; v400 < 384; v400 += 1) {	// L636
    for (int v401 = 0; v401 < 64; v401 += 1) {	// L637
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v398
      #pragma HLS dependence false variable=v399
      float v402 = v398[0][v400][v401];	// L638
      v399[0][v400][v401] = v402;	// L639
    }
  }
}

void kernel76(
  float v403[1][384][64],
  float v404[1][384][64]
) {	// L644
  for (int v405 = 0; v405 < 384; v405 += 1) {	// L645
    for (int v406 = 0; v406 < 64; v406 += 1) {	// L646
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v403
      #pragma HLS dependence false variable=v404
      float v407 = v403[0][v405][v406];	// L647
      float v408 = v404[0][v405][v406];	// L648
      float v409 = v407 + v408;	// L649
      v404[0][v405][v406] = v409;	// L650
    }
  }
}

void kernel77(
  float v410[1][384][64],
  float v411
) {	// L655
  for (int v412 = 0; v412 < 384; v412 += 1) {	// L656
    for (int v413 = 0; v413 < 64; v413 += 1) {	// L657
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v410
      float v414 = v410[0][v412][v413];	// L658
      float v415 = v414 * v411;	// L659
      v410[0][v412][v413] = v415;	// L660
    }
  }
}

void kernel79(
  float v416[1][384][64],
  float v417[1][384][64],
  float v418[1][384][64]
) {	// L665
  for (int v419 = 0; v419 < 384; v419 += 1) {	// L666
    for (int v420 = 0; v420 < 64; v420 += 1) {	// L667
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v417
      #pragma HLS dependence false variable=v418
      #pragma HLS dependence false variable=v416
      float v421 = v417[0][v419][v420];	// L668
      float v422 = v416[0][v419][v420];	// L669
      float v423 = v421 - v422;	// L670
      v418[0][v419][v420] = v423;	// L671
    }
  }
}

void kernel80(
  float v424[1][384][64],
  float v425[1][384][64],
  float v426[1][384][64]
) {	// L676
  for (int v427 = 0; v427 < 384; v427 += 1) {	// L677
    for (int v428 = 0; v428 < 64; v428 += 1) {	// L678
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v425
      #pragma HLS dependence false variable=v426
      #pragma HLS dependence false variable=v424
      float v429 = v425[0][v427][v428];	// L679
      float v430 = v424[0][v427][v428];	// L680
      float v431 = v429 * v430;	// L681
      v426[0][v427][v428] = v431;	// L682
    }
  }
}

void kernel81(
  float v432[1][384][64],
  float v433,
  float v434
) {	// L687
  for (int v435 = 0; v435 < 384; v435 += 1) {	// L688
    for (int v436 = 0; v436 < 64; v436 += 1) {	// L689
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v432
      float v437 = v432[0][v435][v436];	// L690
      bool v438 = v437 >= v434;	// L691
      float v439 = v438 ? v433 : v434;	// L692
      v432[0][v435][v436] = v439;	// L693
    }
  }
}

void kernel83(
  float v440[1][384][64],
  float v441
) {	// L698
  for (int v442 = 0; v442 < 384; v442 += 1) {	// L699
    for (int v443 = 0; v443 < 64; v443 += 1) {	// L700
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v440
      float v444 = v440[0][v442][v443];	// L701
      float v445 = v444 - v441;	// L702
      v440[0][v442][v443] = v445;	// L703
    }
  }
}

void kernel85(
  float v446[1][384][64],
  float v447[1][384][64],
  float v448[1][384][64]
) {	// L708
  for (int v449 = 0; v449 < 384; v449 += 1) {	// L709
    for (int v450 = 0; v450 < 64; v450 += 1) {	// L710
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v447
      #pragma HLS dependence false variable=v448
      #pragma HLS dependence false variable=v446
      float v451 = v447[0][v449][v450];	// L711
      float v452 = v446[0][v449][v450];	// L712
      float v453 = v451 + v452;	// L713
      v448[0][v449][v450] = v453;	// L714
    }
  }
}

void kernel86(
  float v454[1][384][64],
  float v455
) {	// L719
  for (int v456 = 0; v456 < 384; v456 += 1) {	// L720
    for (int v457 = 0; v457 < 64; v457 += 1) {	// L721
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v454
      float v458 = v454[0][v456][v457];	// L722
      float v459 = v458 / v455;	// L723
      v454[0][v456][v457] = v459;	// L724
    }
  }
}

void kernel91(
  float v460[1][384][8][8],
  float v461[384][384][1],
  float v462[1][384][64]
) {	// L729
  auto v463 = reinterpret_cast<float(*)[384][1]>(v461);

  for (int v464 = 0; v464 < 384; v464 += 1) {	// L732
    for (int v465 = 0; v465 < 384; v465 += 1) {	// L733
      for (int v466 = 0; v466 < 64; v466 += 1) {	// L734
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v460
        #pragma HLS dependence false variable=v462
        #pragma HLS dependence false variable=v463
        float v467 = v460[0][v464][(v466 / 8)][(v466 % 8)];	// L735
        float v468 = v463[v465][v464][0];	// L736
        float v469 = v462[0][v465][v466];	// L737
        float v470 = v467 * v468;	// L738
        float v471 = v469 + v470;	// L739
        v462[0][v465][v466] = v471;	// L740
      }
    }
  }
}

void kernel208(
  float v472[12][64][32],
  float v473[12][64][32]
) {	// L746
  for (int v474 = 0; v474 < 12; v474 += 1) {	// L747
    for (int v475 = 0; v475 < 64; v475 += 1) {	// L748
      for (int v476 = 0; v476 < 32; v476 += 1) {	// L749
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v472
        #pragma HLS dependence false variable=v473
        float v477 = v472[v474][v475][v476];	// L750
        v473[v474][v475][v476] = v477;	// L751
      }
    }
  }
}

void kernel212(
  float v478[12][64][64],
  float v479[12][64][64]
) {	// L757
  for (int v480 = 0; v480 < 12; v480 += 1) {	// L758
    for (int v481 = 0; v481 < 64; v481 += 1) {	// L759
      for (int v482 = 0; v482 < 64; v482 += 1) {	// L760
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v478
        #pragma HLS dependence false variable=v479
        float v483 = v478[v480][v481][v482];	// L761
        v479[v480][v481][v482] = v483;	// L762
      }
    }
  }
}

void kernel495(
  float v484[12][64][32],
  float v485
) {	// L768
  for (int v486 = 0; v486 < 12; v486 += 1) {	// L769
    for (int v487 = 0; v487 < 64; v487 += 1) {	// L770
      for (int v488 = 0; v488 < 32; v488 += 1) {	// L771
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v484
        v484[v486][v487][v488] = v485;	// L772
      }
    }
  }
}

void kernel500(
  float v489[12][64][64],
  float v490
) {	// L778
  for (int v491 = 0; v491 < 12; v491 += 1) {	// L779
    for (int v492 = 0; v492 < 64; v492 += 1) {	// L780
      for (int v493 = 0; v493 < 64; v493 += 1) {	// L781
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v489
        v489[v491][v492][v493] = v490;	// L782
      }
    }
  }
}

void kernel579(
  float v494[1][384][10][10],
  float v495[384][384][3][3],
  float v496[1][384][8][8]
) {	// L788
  auto v497 = reinterpret_cast<float(*)[384][3][3]>(v495);

  for (int v498 = 0; v498 < 384; v498 += 1) {	// L791
    for (int v499 = 0; v499 < 3; v499 += 1) {	// L792
      for (int v500 = 0; v500 < 3; v500 += 1) {	// L793
        for (int v501 = 0; v501 < 384; v501 += 1) {	// L794
          for (int v502 = 0; v502 < 8; v502 += 1) {	// L795
            for (int v503 = 0; v503 < 8; v503 += 1) {	// L796
              #pragma HLS pipeline II=1
              #pragma HLS dependence false variable=v494
              #pragma HLS dependence false variable=v496
              #pragma HLS dependence false variable=v497
              float v504 = v494[0][v498][(v502 + v499)][(v503 + v500)];	// L797
              float v505 = v497[v501][v498][v499][v500];	// L798
              float v506 = v496[0][v501][v502][v503];	// L799
              float v507 = v504 * v505;	// L800
              float v508 = v506 + v507;	// L801
              v496[0][v501][v502][v503] = v508;	// L802
            }
          }
        }
      }
    }
  }
}

void kernel581(
  float v509[1][384][8][8],
  float v510[1][384][10][10]
) {	// L811
  for (int v511 = 0; v511 < 384; v511 += 1) {	// L812
    for (int v512 = 0; v512 < 8; v512 += 1) {	// L813
      for (int v513 = 0; v513 < 8; v513 += 1) {	// L814
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v509
        #pragma HLS dependence false variable=v510
        float v514 = v509[0][v511][v512][v513];	// L815
        v510[0][v511][(v512 + 1)][(v513 + 1)] = v514;	// L816
      }
    }
  }
}

void kernel582(
  float v515[1][384][10][10],
  float v516
) {	// L822
  for (int v517 = 0; v517 < 384; v517 += 1) {	// L823
    for (int v518 = 0; v518 < 10; v518 += 1) {	// L824
      for (int v519 = 0; v519 < 10; v519 += 1) {	// L825
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v515
        v515[0][v517][v518][v519] = v516;	// L826
      }
    }
  }
}

void kernel583(
  float v520[1][384][18][18],
  float v521[3][3],
  float v522[1][384][8][8]
) {	// L832
  for (int v523 = 0; v523 < 3; v523 += 1) {	// L833
    for (int v524 = 0; v524 < 3; v524 += 1) {	// L834
      for (int v525 = 0; v525 < 384; v525 += 1) {	// L835
        for (int v526 = 0; v526 < 8; v526 += 1) {	// L836
          for (int v527 = 0; v527 < 8; v527 += 1) {	// L837
            #pragma HLS pipeline II=1
            #pragma HLS dependence false variable=v520
            #pragma HLS dependence false variable=v522
            float v528 = v520[0][v525][((v526 * 2) + v523)][((v527 * 2) + v524)];	// L838
            float v529 = v522[0][v525][v526][v527];	// L839
            float v530 = max(v529, v528);	// L840
            v522[0][v525][v526][v527] = v530;	// L841
          }
        }
      }
    }
  }
}

void kernel584(
  float v531[1][384][8][8],
  float v532
) {	// L849
  for (int v533 = 0; v533 < 384; v533 += 1) {	// L850
    for (int v534 = 0; v534 < 8; v534 += 1) {	// L851
      for (int v535 = 0; v535 < 8; v535 += 1) {	// L852
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v531
        v531[0][v533][v534][v535] = v532;	// L853
      }
    }
  }
}

void kernel585(
  float v536[1][384][16][16],
  float v537[1][384][18][18]
) {	// L859
  for (int v538 = 0; v538 < 384; v538 += 1) {	// L860
    for (int v539 = 0; v539 < 16; v539 += 1) {	// L861
      for (int v540 = 0; v540 < 16; v540 += 1) {	// L862
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v536
        #pragma HLS dependence false variable=v537
        float v541 = v536[0][v538][v539][v540];	// L863
        v537[0][v538][(v539 + 1)][(v540 + 1)] = v541;	// L864
      }
    }
  }
}

void kernel586(
  float v542[1][384][18][18],
  float v543
) {	// L870
  for (int v544 = 0; v544 < 384; v544 += 1) {	// L871
    for (int v545 = 0; v545 < 18; v545 += 1) {	// L872
      for (int v546 = 0; v546 < 18; v546 += 1) {	// L873
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v542
        v542[0][v544][v545][v546] = v543;	// L874
      }
    }
  }
}

void kernel587(
  float v547[1][384][16][16],
  float v548[1][384][16][16]
) {	// L880
  for (int v549 = 0; v549 < 384; v549 += 1) {	// L881
    for (int v550 = 0; v550 < 16; v550 += 1) {	// L882
      for (int v551 = 0; v551 < 16; v551 += 1) {	// L883
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v547
        #pragma HLS dependence false variable=v548
        float v552 = v547[0][v549][v550][v551];	// L884
        v548[0][v549][v550][v551] = v552;	// L885
      }
    }
  }
}

void kernel588(
  float v553[1][384][16][16],
  float v554[1][384][16][16]
) {	// L891
  for (int v555 = 0; v555 < 384; v555 += 1) {	// L892
    for (int v556 = 0; v556 < 16; v556 += 1) {	// L893
      for (int v557 = 0; v557 < 16; v557 += 1) {	// L894
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v553
        #pragma HLS dependence false variable=v554
        float v558 = v553[0][v555][v556][v557];	// L895
        float v559 = v554[0][v555][v556][v557];	// L896
        float v560 = v558 + v559;	// L897
        v554[0][v555][v556][v557] = v560;	// L898
      }
    }
  }
}

void kernel589(
  float v561[1][384][16][16],
  float v562
) {	// L904
  for (int v563 = 0; v563 < 384; v563 += 1) {	// L905
    for (int v564 = 0; v564 < 16; v564 += 1) {	// L906
      for (int v565 = 0; v565 < 16; v565 += 1) {	// L907
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v561
        float v566 = v561[0][v563][v564][v565];	// L908
        float v567 = v566 * v562;	// L909
        v561[0][v563][v564][v565] = v567;	// L910
      }
    }
  }
}

void kernel591(
  float v568[1][384][16][16],
  float v569[1][384][16][16],
  float v570[1][384][16][16]
) {	// L916
  for (int v571 = 0; v571 < 384; v571 += 1) {	// L917
    for (int v572 = 0; v572 < 16; v572 += 1) {	// L918
      for (int v573 = 0; v573 < 16; v573 += 1) {	// L919
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v569
        #pragma HLS dependence false variable=v570
        #pragma HLS dependence false variable=v568
        float v574 = v569[0][v571][v572][v573];	// L920
        float v575 = v568[0][v571][v572][v573];	// L921
        float v576 = v574 - v575;	// L922
        v570[0][v571][v572][v573] = v576;	// L923
      }
    }
  }
}

void kernel592(
  float v577[1][384][16][16],
  float v578[1][384][16][16],
  float v579[1][384][16][16]
) {	// L929
  for (int v580 = 0; v580 < 384; v580 += 1) {	// L930
    for (int v581 = 0; v581 < 16; v581 += 1) {	// L931
      for (int v582 = 0; v582 < 16; v582 += 1) {	// L932
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v578
        #pragma HLS dependence false variable=v579
        #pragma HLS dependence false variable=v577
        float v583 = v578[0][v580][v581][v582];	// L933
        float v584 = v577[0][v580][v581][v582];	// L934
        float v585 = v583 * v584;	// L935
        v579[0][v580][v581][v582] = v585;	// L936
      }
    }
  }
}

void kernel593(
  float v586[1][384][16][16],
  float v587,
  float v588
) {	// L942
  for (int v589 = 0; v589 < 384; v589 += 1) {	// L943
    for (int v590 = 0; v590 < 16; v590 += 1) {	// L944
      for (int v591 = 0; v591 < 16; v591 += 1) {	// L945
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v586
        float v592 = v586[0][v589][v590][v591];	// L946
        bool v593 = v592 >= v588;	// L947
        float v594 = v593 ? v587 : v588;	// L948
        v586[0][v589][v590][v591] = v594;	// L949
      }
    }
  }
}

void kernel595(
  float v595[1][384][16][16],
  float v596
) {	// L955
  for (int v597 = 0; v597 < 384; v597 += 1) {	// L956
    for (int v598 = 0; v598 < 16; v598 += 1) {	// L957
      for (int v599 = 0; v599 < 16; v599 += 1) {	// L958
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v595
        float v600 = v595[0][v597][v598][v599];	// L959
        float v601 = v600 - v596;	// L960
        v595[0][v597][v598][v599] = v601;	// L961
      }
    }
  }
}

void kernel597(
  float v602[1][384][16][16],
  float v603[1][384][16][16],
  float v604[1][384][16][16]
) {	// L967
  for (int v605 = 0; v605 < 384; v605 += 1) {	// L968
    for (int v606 = 0; v606 < 16; v606 += 1) {	// L969
      for (int v607 = 0; v607 < 16; v607 += 1) {	// L970
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v603
        #pragma HLS dependence false variable=v604
        #pragma HLS dependence false variable=v602
        float v608 = v603[0][v605][v606][v607];	// L971
        float v609 = v602[0][v605][v606][v607];	// L972
        float v610 = v608 + v609;	// L973
        v604[0][v605][v606][v607] = v610;	// L974
      }
    }
  }
}

void kernel598(
  float v611[1][384][16][16],
  float v612
) {	// L980
  for (int v613 = 0; v613 < 384; v613 += 1) {	// L981
    for (int v614 = 0; v614 < 16; v614 += 1) {	// L982
      for (int v615 = 0; v615 < 16; v615 += 1) {	// L983
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v611
        float v616 = v611[0][v613][v614][v615];	// L984
        float v617 = v616 / v612;	// L985
        v611[0][v613][v614][v615] = v617;	// L986
      }
    }
  }
}

void kernel603(
  float v618[1][192][18][18],
  float v619[384][192][3][3],
  float v620[1][384][16][16]
) {	// L992
  auto v621 = reinterpret_cast<float(*)[192][3][3]>(v619);

  for (int v622 = 0; v622 < 192; v622 += 1) {	// L995
    for (int v623 = 0; v623 < 3; v623 += 1) {	// L996
      for (int v624 = 0; v624 < 3; v624 += 1) {	// L997
        for (int v625 = 0; v625 < 384; v625 += 1) {	// L998
          for (int v626 = 0; v626 < 16; v626 += 1) {	// L999
            for (int v627 = 0; v627 < 16; v627 += 1) {	// L1000
              #pragma HLS pipeline II=1
              #pragma HLS dependence false variable=v618
              #pragma HLS dependence false variable=v620
              #pragma HLS dependence false variable=v621
              float v628 = v618[0][v622][(v626 + v623)][(v627 + v624)];	// L1001
              float v629 = v621[v625][v622][v623][v624];	// L1002
              float v630 = v620[0][v625][v626][v627];	// L1003
              float v631 = v628 * v629;	// L1004
              float v632 = v630 + v631;	// L1005
              v620[0][v625][v626][v627] = v632;	// L1006
            }
          }
        }
      }
    }
  }
}

void kernel604(
  float v633[384],
  float v634[1][384][16][16]
) {	// L1015
  float v635[384];	// L1016
  #pragma HLS resource variable=v635 core=ram_t2p_bram

  memcpy(v635, v633, 384 * sizeof(float));	// L1017

  for (int v636 = 0; v636 < 384; v636 += 1) {	// L1018
    for (int v637 = 0; v637 < 16; v637 += 1) {	// L1019
      for (int v638 = 0; v638 < 16; v638 += 1) {	// L1020
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v635
        #pragma HLS dependence false variable=v634
        float v639 = v635[v636];	// L1021
        v634[0][v636][v637][v638] = v639;	// L1022
      }
    }
  }
}

void kernel605(
  float v640[1][192][16][16],
  float v641[1][192][18][18]
) {	// L1028
  for (int v642 = 0; v642 < 192; v642 += 1) {	// L1029
    for (int v643 = 0; v643 < 16; v643 += 1) {	// L1030
      for (int v644 = 0; v644 < 16; v644 += 1) {	// L1031
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v640
        #pragma HLS dependence false variable=v641
        float v645 = v640[0][v642][v643][v644];	// L1032
        v641[0][v642][(v643 + 1)][(v644 + 1)] = v645;	// L1033
      }
    }
  }
}

void kernel606(
  float v646[1][192][18][18],
  float v647
) {	// L1039
  for (int v648 = 0; v648 < 192; v648 += 1) {	// L1040
    for (int v649 = 0; v649 < 18; v649 += 1) {	// L1041
      for (int v650 = 0; v650 < 18; v650 += 1) {	// L1042
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v646
        v646[0][v648][v649][v650] = v647;	// L1043
      }
    }
  }
}

void kernel607(
  float v651[1][192][34][34],
  float v652[3][3],
  float v653[1][192][16][16]
) {	// L1049
  for (int v654 = 0; v654 < 3; v654 += 1) {	// L1050
    for (int v655 = 0; v655 < 3; v655 += 1) {	// L1051
      for (int v656 = 0; v656 < 192; v656 += 1) {	// L1052
        for (int v657 = 0; v657 < 16; v657 += 1) {	// L1053
          for (int v658 = 0; v658 < 16; v658 += 1) {	// L1054
            #pragma HLS pipeline II=1
            #pragma HLS dependence false variable=v651
            #pragma HLS dependence false variable=v653
            float v659 = v651[0][v656][((v657 * 2) + v654)][((v658 * 2) + v655)];	// L1055
            float v660 = v653[0][v656][v657][v658];	// L1056
            float v661 = max(v660, v659);	// L1057
            v653[0][v656][v657][v658] = v661;	// L1058
          }
        }
      }
    }
  }
}

void kernel608(
  float v662[1][192][16][16],
  float v663
) {	// L1066
  for (int v664 = 0; v664 < 192; v664 += 1) {	// L1067
    for (int v665 = 0; v665 < 16; v665 += 1) {	// L1068
      for (int v666 = 0; v666 < 16; v666 += 1) {	// L1069
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v662
        v662[0][v664][v665][v666] = v663;	// L1070
      }
    }
  }
}

void kernel609(
  float v667[1][192][32][32],
  float v668[1][192][34][34]
) {	// L1076
  for (int v669 = 0; v669 < 192; v669 += 1) {	// L1077
    for (int v670 = 0; v670 < 32; v670 += 1) {	// L1078
      for (int v671 = 0; v671 < 32; v671 += 1) {	// L1079
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v667
        #pragma HLS dependence false variable=v668
        float v672 = v667[0][v669][v670][v671];	// L1080
        v668[0][v669][(v670 + 1)][(v671 + 1)] = v672;	// L1081
      }
    }
  }
}

void kernel610(
  float v673[1][192][34][34],
  float v674
) {	// L1087
  for (int v675 = 0; v675 < 192; v675 += 1) {	// L1088
    for (int v676 = 0; v676 < 34; v676 += 1) {	// L1089
      for (int v677 = 0; v677 < 34; v677 += 1) {	// L1090
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v673
        v673[0][v675][v676][v677] = v674;	// L1091
      }
    }
  }
}

void kernel611(
  float v678[1][192][32][32],
  float v679[1][192][32][32]
) {	// L1097
  for (int v680 = 0; v680 < 192; v680 += 1) {	// L1098
    for (int v681 = 0; v681 < 32; v681 += 1) {	// L1099
      for (int v682 = 0; v682 < 32; v682 += 1) {	// L1100
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v678
        #pragma HLS dependence false variable=v679
        float v683 = v678[0][v680][v681][v682];	// L1101
        v679[0][v680][v681][v682] = v683;	// L1102
      }
    }
  }
}

void kernel612(
  float v684[1][192][32][32],
  float v685[1][192][32][32]
) {	// L1108
  for (int v686 = 0; v686 < 192; v686 += 1) {	// L1109
    for (int v687 = 0; v687 < 32; v687 += 1) {	// L1110
      for (int v688 = 0; v688 < 32; v688 += 1) {	// L1111
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v684
        #pragma HLS dependence false variable=v685
        float v689 = v684[0][v686][v687][v688];	// L1112
        float v690 = v685[0][v686][v687][v688];	// L1113
        float v691 = v689 + v690;	// L1114
        v685[0][v686][v687][v688] = v691;	// L1115
      }
    }
  }
}

void kernel613(
  float v692[1][192][32][32],
  float v693
) {	// L1121
  for (int v694 = 0; v694 < 192; v694 += 1) {	// L1122
    for (int v695 = 0; v695 < 32; v695 += 1) {	// L1123
      for (int v696 = 0; v696 < 32; v696 += 1) {	// L1124
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v692
        float v697 = v692[0][v694][v695][v696];	// L1125
        float v698 = v697 * v693;	// L1126
        v692[0][v694][v695][v696] = v698;	// L1127
      }
    }
  }
}

void kernel615(
  float v699[1][192][32][32],
  float v700[1][192][32][32],
  float v701[1][192][32][32]
) {	// L1133
  for (int v702 = 0; v702 < 192; v702 += 1) {	// L1134
    for (int v703 = 0; v703 < 32; v703 += 1) {	// L1135
      for (int v704 = 0; v704 < 32; v704 += 1) {	// L1136
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v700
        #pragma HLS dependence false variable=v701
        #pragma HLS dependence false variable=v699
        float v705 = v700[0][v702][v703][v704];	// L1137
        float v706 = v699[0][v702][v703][v704];	// L1138
        float v707 = v705 - v706;	// L1139
        v701[0][v702][v703][v704] = v707;	// L1140
      }
    }
  }
}

void kernel616(
  float v708[1][192][32][32],
  float v709[1][192][32][32],
  float v710[1][192][32][32]
) {	// L1146
  for (int v711 = 0; v711 < 192; v711 += 1) {	// L1147
    for (int v712 = 0; v712 < 32; v712 += 1) {	// L1148
      for (int v713 = 0; v713 < 32; v713 += 1) {	// L1149
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v709
        #pragma HLS dependence false variable=v710
        #pragma HLS dependence false variable=v708
        float v714 = v709[0][v711][v712][v713];	// L1150
        float v715 = v708[0][v711][v712][v713];	// L1151
        float v716 = v714 * v715;	// L1152
        v710[0][v711][v712][v713] = v716;	// L1153
      }
    }
  }
}

void kernel617(
  float v717[1][192][32][32],
  float v718,
  float v719
) {	// L1159
  for (int v720 = 0; v720 < 192; v720 += 1) {	// L1160
    for (int v721 = 0; v721 < 32; v721 += 1) {	// L1161
      for (int v722 = 0; v722 < 32; v722 += 1) {	// L1162
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v717
        float v723 = v717[0][v720][v721][v722];	// L1163
        bool v724 = v723 >= v719;	// L1164
        float v725 = v724 ? v718 : v719;	// L1165
        v717[0][v720][v721][v722] = v725;	// L1166
      }
    }
  }
}

void kernel619(
  float v726[1][192][32][32],
  float v727
) {	// L1172
  for (int v728 = 0; v728 < 192; v728 += 1) {	// L1173
    for (int v729 = 0; v729 < 32; v729 += 1) {	// L1174
      for (int v730 = 0; v730 < 32; v730 += 1) {	// L1175
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v726
        float v731 = v726[0][v728][v729][v730];	// L1176
        float v732 = v731 - v727;	// L1177
        v726[0][v728][v729][v730] = v732;	// L1178
      }
    }
  }
}

void kernel621(
  float v733[1][192][32][32],
  float v734[1][192][32][32],
  float v735[1][192][32][32]
) {	// L1184
  for (int v736 = 0; v736 < 192; v736 += 1) {	// L1185
    for (int v737 = 0; v737 < 32; v737 += 1) {	// L1186
      for (int v738 = 0; v738 < 32; v738 += 1) {	// L1187
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v734
        #pragma HLS dependence false variable=v735
        #pragma HLS dependence false variable=v733
        float v739 = v734[0][v736][v737][v738];	// L1188
        float v740 = v733[0][v736][v737][v738];	// L1189
        float v741 = v739 + v740;	// L1190
        v735[0][v736][v737][v738] = v741;	// L1191
      }
    }
  }
}

void kernel622(
  float v742[1][192][32][32],
  float v743
) {	// L1197
  for (int v744 = 0; v744 < 192; v744 += 1) {	// L1198
    for (int v745 = 0; v745 < 32; v745 += 1) {	// L1199
      for (int v746 = 0; v746 < 32; v746 += 1) {	// L1200
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v742
        float v747 = v742[0][v744][v745][v746];	// L1201
        float v748 = v747 / v743;	// L1202
        v742[0][v744][v745][v746] = v748;	// L1203
      }
    }
  }
}

void kernel627(
  float v749[1][96][34][34],
  float v750[192][96][3][3],
  float v751[1][192][32][32]
) {	// L1209
  auto v752 = reinterpret_cast<float(*)[96][3][3]>(v750);

  for (int v753 = 0; v753 < 96; v753 += 1) {	// L1212
    for (int v754 = 0; v754 < 3; v754 += 1) {	// L1213
      for (int v755 = 0; v755 < 3; v755 += 1) {	// L1214
        for (int v756 = 0; v756 < 192; v756 += 1) {	// L1215
          for (int v757 = 0; v757 < 32; v757 += 1) {	// L1216
            for (int v758 = 0; v758 < 32; v758 += 1) {	// L1217
              #pragma HLS pipeline II=1
              #pragma HLS dependence false variable=v749
              #pragma HLS dependence false variable=v751
              #pragma HLS dependence false variable=v752
              float v759 = v749[0][v753][(v757 + v754)][(v758 + v755)];	// L1218
              float v760 = v752[v756][v753][v754][v755];	// L1219
              float v761 = v751[0][v756][v757][v758];	// L1220
              float v762 = v759 * v760;	// L1221
              float v763 = v761 + v762;	// L1222
              v751[0][v756][v757][v758] = v763;	// L1223
            }
          }
        }
      }
    }
  }
}

void kernel628(
  float v764[192],
  float v765[1][192][32][32]
) {	// L1232
  float v766[192];	// L1233
  #pragma HLS resource variable=v766 core=ram_t2p_bram

  memcpy(v766, v764, 192 * sizeof(float));	// L1234

  for (int v767 = 0; v767 < 192; v767 += 1) {	// L1235
    for (int v768 = 0; v768 < 32; v768 += 1) {	// L1236
      for (int v769 = 0; v769 < 32; v769 += 1) {	// L1237
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v766
        #pragma HLS dependence false variable=v765
        float v770 = v766[v767];	// L1238
        v765[0][v767][v768][v769] = v770;	// L1239
      }
    }
  }
}

void kernel629(
  float v771[1][96][32][32],
  float v772[1][96][34][34]
) {	// L1245
  for (int v773 = 0; v773 < 96; v773 += 1) {	// L1246
    for (int v774 = 0; v774 < 32; v774 += 1) {	// L1247
      for (int v775 = 0; v775 < 32; v775 += 1) {	// L1248
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v771
        #pragma HLS dependence false variable=v772
        float v776 = v771[0][v773][v774][v775];	// L1249
        v772[0][v773][(v774 + 1)][(v775 + 1)] = v776;	// L1250
      }
    }
  }
}

void kernel630(
  float v777[1][96][34][34],
  float v778
) {	// L1256
  for (int v779 = 0; v779 < 96; v779 += 1) {	// L1257
    for (int v780 = 0; v780 < 34; v780 += 1) {	// L1258
      for (int v781 = 0; v781 < 34; v781 += 1) {	// L1259
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v777
        v777[0][v779][v780][v781] = v778;	// L1260
      }
    }
  }
}

void kernel631(
  float v782[1][96][32][32],
  float v783[1][96][32][32]
) {	// L1266
  for (int v784 = 0; v784 < 96; v784 += 1) {	// L1267
    for (int v785 = 0; v785 < 32; v785 += 1) {	// L1268
      for (int v786 = 0; v786 < 32; v786 += 1) {	// L1269
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v782
        #pragma HLS dependence false variable=v783
        float v787 = v782[0][v784][v785][v786];	// L1270
        v783[0][v784][v785][v786] = v787;	// L1271
      }
    }
  }
}

void kernel632(
  float v788[1][96][32][32],
  float v789[1][96][32][32]
) {	// L1277
  for (int v790 = 0; v790 < 96; v790 += 1) {	// L1278
    for (int v791 = 0; v791 < 32; v791 += 1) {	// L1279
      for (int v792 = 0; v792 < 32; v792 += 1) {	// L1280
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v788
        #pragma HLS dependence false variable=v789
        float v793 = v788[0][v790][v791][v792];	// L1281
        float v794 = v789[0][v790][v791][v792];	// L1282
        float v795 = v793 + v794;	// L1283
        v789[0][v790][v791][v792] = v795;	// L1284
      }
    }
  }
}

void kernel633(
  float v796[1][96][32][32],
  float v797
) {	// L1290
  for (int v798 = 0; v798 < 96; v798 += 1) {	// L1291
    for (int v799 = 0; v799 < 32; v799 += 1) {	// L1292
      for (int v800 = 0; v800 < 32; v800 += 1) {	// L1293
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v796
        float v801 = v796[0][v798][v799][v800];	// L1294
        float v802 = v801 * v797;	// L1295
        v796[0][v798][v799][v800] = v802;	// L1296
      }
    }
  }
}

void kernel635(
  float v803[1][96][32][32],
  float v804[1][96][32][32],
  float v805[1][96][32][32]
) {	// L1302
  for (int v806 = 0; v806 < 96; v806 += 1) {	// L1303
    for (int v807 = 0; v807 < 32; v807 += 1) {	// L1304
      for (int v808 = 0; v808 < 32; v808 += 1) {	// L1305
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v804
        #pragma HLS dependence false variable=v805
        #pragma HLS dependence false variable=v803
        float v809 = v804[0][v806][v807][v808];	// L1306
        float v810 = v803[0][v806][v807][v808];	// L1307
        float v811 = v809 - v810;	// L1308
        v805[0][v806][v807][v808] = v811;	// L1309
      }
    }
  }
}

void kernel636(
  float v812[1][96][32][32],
  float v813[1][96][32][32],
  float v814[1][96][32][32]
) {	// L1315
  for (int v815 = 0; v815 < 96; v815 += 1) {	// L1316
    for (int v816 = 0; v816 < 32; v816 += 1) {	// L1317
      for (int v817 = 0; v817 < 32; v817 += 1) {	// L1318
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v813
        #pragma HLS dependence false variable=v814
        #pragma HLS dependence false variable=v812
        float v818 = v813[0][v815][v816][v817];	// L1319
        float v819 = v812[0][v815][v816][v817];	// L1320
        float v820 = v818 * v819;	// L1321
        v814[0][v815][v816][v817] = v820;	// L1322
      }
    }
  }
}

void kernel637(
  float v821[1][96][32][32],
  float v822,
  float v823
) {	// L1328
  for (int v824 = 0; v824 < 96; v824 += 1) {	// L1329
    for (int v825 = 0; v825 < 32; v825 += 1) {	// L1330
      for (int v826 = 0; v826 < 32; v826 += 1) {	// L1331
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v821
        float v827 = v821[0][v824][v825][v826];	// L1332
        bool v828 = v827 >= v823;	// L1333
        float v829 = v828 ? v822 : v823;	// L1334
        v821[0][v824][v825][v826] = v829;	// L1335
      }
    }
  }
}

void kernel639(
  float v830[1][96][32][32],
  float v831
) {	// L1341
  for (int v832 = 0; v832 < 96; v832 += 1) {	// L1342
    for (int v833 = 0; v833 < 32; v833 += 1) {	// L1343
      for (int v834 = 0; v834 < 32; v834 += 1) {	// L1344
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v830
        float v835 = v830[0][v832][v833][v834];	// L1345
        float v836 = v835 - v831;	// L1346
        v830[0][v832][v833][v834] = v836;	// L1347
      }
    }
  }
}

void kernel641(
  float v837[1][96][32][32],
  float v838[1][96][32][32],
  float v839[1][96][32][32]
) {	// L1353
  for (int v840 = 0; v840 < 96; v840 += 1) {	// L1354
    for (int v841 = 0; v841 < 32; v841 += 1) {	// L1355
      for (int v842 = 0; v842 < 32; v842 += 1) {	// L1356
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v838
        #pragma HLS dependence false variable=v839
        #pragma HLS dependence false variable=v837
        float v843 = v838[0][v840][v841][v842];	// L1357
        float v844 = v837[0][v840][v841][v842];	// L1358
        float v845 = v843 + v844;	// L1359
        v839[0][v840][v841][v842] = v845;	// L1360
      }
    }
  }
}

void kernel642(
  float v846[1][96][32][32],
  float v847
) {	// L1366
  for (int v848 = 0; v848 < 96; v848 += 1) {	// L1367
    for (int v849 = 0; v849 < 32; v849 += 1) {	// L1368
      for (int v850 = 0; v850 < 32; v850 += 1) {	// L1369
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v846
        float v851 = v846[0][v848][v849][v850];	// L1370
        float v852 = v851 / v847;	// L1371
        v846[0][v848][v849][v850] = v852;	// L1372
      }
    }
  }
}

void kernel647(
  float v853[1][48][34][34],
  float v854[96][48][3][3],
  float v855[1][96][32][32]
) {	// L1378
  auto v856 = reinterpret_cast<float(*)[48][3][3]>(v854);

  for (int v857 = 0; v857 < 48; v857 += 1) {	// L1381
    for (int v858 = 0; v858 < 3; v858 += 1) {	// L1382
      for (int v859 = 0; v859 < 3; v859 += 1) {	// L1383
        for (int v860 = 0; v860 < 96; v860 += 1) {	// L1384
          for (int v861 = 0; v861 < 32; v861 += 1) {	// L1385
            for (int v862 = 0; v862 < 32; v862 += 1) {	// L1386
              #pragma HLS pipeline II=1
              #pragma HLS dependence false variable=v853
              #pragma HLS dependence false variable=v855
              #pragma HLS dependence false variable=v856
              float v863 = v853[0][v857][(v861 + v858)][(v862 + v859)];	// L1387
              float v864 = v856[v860][v857][v858][v859];	// L1388
              float v865 = v855[0][v860][v861][v862];	// L1389
              float v866 = v863 * v864;	// L1390
              float v867 = v865 + v866;	// L1391
              v855[0][v860][v861][v862] = v867;	// L1392
            }
          }
        }
      }
    }
  }
}

void kernel648(
  float v868[96],
  float v869[1][96][32][32]
) {	// L1401
  float v870[96];	// L1402
  #pragma HLS resource variable=v870 core=ram_t2p_bram

  memcpy(v870, v868, 96 * sizeof(float));	// L1403

  for (int v871 = 0; v871 < 96; v871 += 1) {	// L1404
    for (int v872 = 0; v872 < 32; v872 += 1) {	// L1405
      for (int v873 = 0; v873 < 32; v873 += 1) {	// L1406
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v870
        #pragma HLS dependence false variable=v869
        float v874 = v870[v871];	// L1407
        v869[0][v871][v872][v873] = v874;	// L1408
      }
    }
  }
}

void kernel649(
  float v875[1][48][32][32],
  float v876[1][48][34][34]
) {	// L1414
  for (int v877 = 0; v877 < 48; v877 += 1) {	// L1415
    for (int v878 = 0; v878 < 32; v878 += 1) {	// L1416
      for (int v879 = 0; v879 < 32; v879 += 1) {	// L1417
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v875
        #pragma HLS dependence false variable=v876
        float v880 = v875[0][v877][v878][v879];	// L1418
        v876[0][v877][(v878 + 1)][(v879 + 1)] = v880;	// L1419
      }
    }
  }
}

void kernel650(
  float v881[1][48][34][34],
  float v882
) {	// L1425
  for (int v883 = 0; v883 < 48; v883 += 1) {	// L1426
    for (int v884 = 0; v884 < 34; v884 += 1) {	// L1427
      for (int v885 = 0; v885 < 34; v885 += 1) {	// L1428
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v881
        v881[0][v883][v884][v885] = v882;	// L1429
      }
    }
  }
}

void kernel651(
  float v886[1][48][32][32],
  float v887[1][48][32][32]
) {	// L1435
  for (int v888 = 0; v888 < 48; v888 += 1) {	// L1436
    for (int v889 = 0; v889 < 32; v889 += 1) {	// L1437
      for (int v890 = 0; v890 < 32; v890 += 1) {	// L1438
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v886
        #pragma HLS dependence false variable=v887
        float v891 = v886[0][v888][v889][v890];	// L1439
        v887[0][v888][v889][v890] = v891;	// L1440
      }
    }
  }
}

void kernel652(
  float v892[1][48][32][32],
  float v893[1][48][32][32]
) {	// L1446
  for (int v894 = 0; v894 < 48; v894 += 1) {	// L1447
    for (int v895 = 0; v895 < 32; v895 += 1) {	// L1448
      for (int v896 = 0; v896 < 32; v896 += 1) {	// L1449
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v892
        #pragma HLS dependence false variable=v893
        float v897 = v892[0][v894][v895][v896];	// L1450
        float v898 = v893[0][v894][v895][v896];	// L1451
        float v899 = v897 + v898;	// L1452
        v893[0][v894][v895][v896] = v899;	// L1453
      }
    }
  }
}

void kernel653(
  float v900[1][48][32][32],
  float v901
) {	// L1459
  for (int v902 = 0; v902 < 48; v902 += 1) {	// L1460
    for (int v903 = 0; v903 < 32; v903 += 1) {	// L1461
      for (int v904 = 0; v904 < 32; v904 += 1) {	// L1462
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v900
        float v905 = v900[0][v902][v903][v904];	// L1463
        float v906 = v905 * v901;	// L1464
        v900[0][v902][v903][v904] = v906;	// L1465
      }
    }
  }
}

void kernel655(
  float v907[1][48][32][32],
  float v908[1][48][32][32],
  float v909[1][48][32][32]
) {	// L1471
  for (int v910 = 0; v910 < 48; v910 += 1) {	// L1472
    for (int v911 = 0; v911 < 32; v911 += 1) {	// L1473
      for (int v912 = 0; v912 < 32; v912 += 1) {	// L1474
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v908
        #pragma HLS dependence false variable=v909
        #pragma HLS dependence false variable=v907
        float v913 = v908[0][v910][v911][v912];	// L1475
        float v914 = v907[0][v910][v911][v912];	// L1476
        float v915 = v913 - v914;	// L1477
        v909[0][v910][v911][v912] = v915;	// L1478
      }
    }
  }
}

void kernel656(
  float v916[1][48][32][32],
  float v917[1][48][32][32],
  float v918[1][48][32][32]
) {	// L1484
  for (int v919 = 0; v919 < 48; v919 += 1) {	// L1485
    for (int v920 = 0; v920 < 32; v920 += 1) {	// L1486
      for (int v921 = 0; v921 < 32; v921 += 1) {	// L1487
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v917
        #pragma HLS dependence false variable=v918
        #pragma HLS dependence false variable=v916
        float v922 = v917[0][v919][v920][v921];	// L1488
        float v923 = v916[0][v919][v920][v921];	// L1489
        float v924 = v922 * v923;	// L1490
        v918[0][v919][v920][v921] = v924;	// L1491
      }
    }
  }
}

void kernel657(
  float v925[1][48][32][32],
  float v926,
  float v927
) {	// L1497
  for (int v928 = 0; v928 < 48; v928 += 1) {	// L1498
    for (int v929 = 0; v929 < 32; v929 += 1) {	// L1499
      for (int v930 = 0; v930 < 32; v930 += 1) {	// L1500
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v925
        float v931 = v925[0][v928][v929][v930];	// L1501
        bool v932 = v931 >= v927;	// L1502
        float v933 = v932 ? v926 : v927;	// L1503
        v925[0][v928][v929][v930] = v933;	// L1504
      }
    }
  }
}

void kernel659(
  float v934[1][48][32][32],
  float v935
) {	// L1510
  for (int v936 = 0; v936 < 48; v936 += 1) {	// L1511
    for (int v937 = 0; v937 < 32; v937 += 1) {	// L1512
      for (int v938 = 0; v938 < 32; v938 += 1) {	// L1513
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v934
        float v939 = v934[0][v936][v937][v938];	// L1514
        float v940 = v939 - v935;	// L1515
        v934[0][v936][v937][v938] = v940;	// L1516
      }
    }
  }
}

void kernel661(
  float v941[1][48][32][32],
  float v942[1][48][32][32],
  float v943[1][48][32][32]
) {	// L1522
  for (int v944 = 0; v944 < 48; v944 += 1) {	// L1523
    for (int v945 = 0; v945 < 32; v945 += 1) {	// L1524
      for (int v946 = 0; v946 < 32; v946 += 1) {	// L1525
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v942
        #pragma HLS dependence false variable=v943
        #pragma HLS dependence false variable=v941
        float v947 = v942[0][v944][v945][v946];	// L1526
        float v948 = v941[0][v944][v945][v946];	// L1527
        float v949 = v947 + v948;	// L1528
        v943[0][v944][v945][v946] = v949;	// L1529
      }
    }
  }
}

void kernel662(
  float v950[1][48][32][32],
  float v951
) {	// L1535
  for (int v952 = 0; v952 < 48; v952 += 1) {	// L1536
    for (int v953 = 0; v953 < 32; v953 += 1) {	// L1537
      for (int v954 = 0; v954 < 32; v954 += 1) {	// L1538
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v950
        float v955 = v950[0][v952][v953][v954];	// L1539
        float v956 = v955 / v951;	// L1540
        v950[0][v952][v953][v954] = v956;	// L1541
      }
    }
  }
}

void kernel667(
  float v957[1][3][34][34],
  float v958[48][3][3][3],
  float v959[1][48][32][32]
) {	// L1547
  float v960[48][3][3][3];	// L1548
  #pragma HLS resource variable=v960 core=ram_t2p_bram

  memcpy(v960, v958, 1296 * sizeof(float));	// L1549

  for (int v961 = 0; v961 < 3; v961 += 1) {	// L1550
    for (int v962 = 0; v962 < 3; v962 += 1) {	// L1551
      for (int v963 = 0; v963 < 3; v963 += 1) {	// L1552
        for (int v964 = 0; v964 < 48; v964 += 1) {	// L1553
          for (int v965 = 0; v965 < 32; v965 += 1) {	// L1554
            for (int v966 = 0; v966 < 32; v966 += 1) {	// L1555
              #pragma HLS pipeline II=1
              #pragma HLS dependence false variable=v957
              #pragma HLS dependence false variable=v959
              #pragma HLS dependence false variable=v960
              float v967 = v957[0][v961][(v965 + v962)][(v966 + v963)];	// L1556
              float v968 = v960[v964][v961][v962][v963];	// L1557
              float v969 = v959[0][v964][v965][v966];	// L1558
              float v970 = v967 * v968;	// L1559
              float v971 = v969 + v970;	// L1560
              v959[0][v964][v965][v966] = v971;	// L1561
            }
          }
        }
      }
    }
  }
}

void kernel668(
  float v972[48],
  float v973[1][48][32][32]
) {	// L1570
  float v974[48];	// L1571
  #pragma HLS resource variable=v974 core=ram_t2p_bram

  memcpy(v974, v972, 48 * sizeof(float));	// L1572

  for (int v975 = 0; v975 < 48; v975 += 1) {	// L1573
    for (int v976 = 0; v976 < 32; v976 += 1) {	// L1574
      for (int v977 = 0; v977 < 32; v977 += 1) {	// L1575
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v974
        #pragma HLS dependence false variable=v973
        float v978 = v974[v975];	// L1576
        v973[0][v975][v976][v977] = v978;	// L1577
      }
    }
  }
}

void kernel669(
  float v979[1][3][32][32],
  float v980[1][3][34][34]
) {	// L1583
  for (int v981 = 0; v981 < 3; v981 += 1) {	// L1584
    for (int v982 = 0; v982 < 32; v982 += 1) {	// L1585
      for (int v983 = 0; v983 < 32; v983 += 1) {	// L1586
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v979
        #pragma HLS dependence false variable=v980
        float v984 = v979[0][v981][v982][v983];	// L1587
        v980[0][v981][(v982 + 1)][(v983 + 1)] = v984;	// L1588
      }
    }
  }
}

void kernel670(
  float v985[1][3][34][34],
  float v986
) {	// L1594
  for (int v987 = 0; v987 < 3; v987 += 1) {	// L1595
    for (int v988 = 0; v988 < 34; v988 += 1) {	// L1596
      for (int v989 = 0; v989 < 34; v989 += 1) {	// L1597
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v985
        v985[0][v987][v988][v989] = v986;	// L1598
      }
    }
  }
}

/// The top function
void control(
  ap_int<32> v990[91189248],
  ap_int<32> v991[91189248],
  ap_int<32> v992[91189248]
) {	// L1604
  #pragma HLS interface s_axilite port=return bundle=ctrl
  #pragma hls interface m_axi offset=direct bundle=g0 port=v990
  #pragma hls stable variable=v990
  #pragma hls interface m_axi offset=direct bundle=g0 port=v991
  #pragma hls stable variable=v991
  #pragma hls interface m_axi offset=direct bundle=g0 port=v992
  #pragma hls stable variable=v992

  auto v993 = reinterpret_cast<float(*)[3][34][34]>(v991 + 6684672);
  kernel670(v993, (float)0.000000);	// L1612
  auto v994 = reinterpret_cast<float(*)[3][32][32]>(v990);
  kernel669(v994, v993);	// L1614
  auto v995 = reinterpret_cast<float(*)[48][32][32]>(v990 + 6906624);
  auto v996 = reinterpret_cast<float(*)>(v992 + 87207936);
  kernel668(v996, v995);	// L1617
  auto v997 = reinterpret_cast<float(*)[3][3][3]>(v992 + 88535040);
  kernel667(v993, v997, v995);	// L1619
  auto v998 = reinterpret_cast<float(*)[48][32][32]>(v990 + 196608);
  auto v999 = reinterpret_cast<float(*)[48][32][32]>(v990 + 6684672);
  kernel651(v998, v999);	// L1622
  kernel662(v999, (float)2.000000);	// L1623
  auto v1000 = reinterpret_cast<float(*)[48][32][32]>(v991 + 7128576);
  kernel655(v999, v998, v1000);	// L1625
  kernel651(v995, v999);	// L1626
  kernel662(v999, (float)2.000000);	// L1627
  auto v1001 = reinterpret_cast<float(*)[48][32][32]>(v992 + 6906624);
  kernel661(v999, v1000, v1001);	// L1629
  kernel651(v1001, v999);	// L1630
  kernel659(v999, (float)1.000000);	// L1631
  auto v1002 = reinterpret_cast<float(*)[48][32][32]>(v990 + 7128576);
  kernel651(v999, v1002);	// L1633
  kernel657(v1002, (float)1.000000, (float)0.000000);	// L1634
  kernel656(v1001, v1002, v999);	// L1635
  auto v1003 = reinterpret_cast<float(*)[48][32][32]>(v991 + 7350528);
  kernel655(v999, v1001, v1003);	// L1637
  kernel651(v1002, v999);	// L1638
  kernel653(v999, (float)0.000000);	// L1639
  kernel652(v1003, v999);	// L1640
  kernel651(v999, v998);	// L1641
  auto v1004 = reinterpret_cast<float(*)[48][34][34]>(v990 + 6684672);
  kernel650(v1004, (float)0.000000);	// L1643
  kernel649(v1002, v1004);	// L1644
  auto v1005 = reinterpret_cast<float(*)[96][32][32]>(v991 + 6906624);
  auto v1006 = reinterpret_cast<float(*)>(v992 + 84553728);
  kernel648(v1006, v1005);	// L1647
  auto v1007 = reinterpret_cast<float(*)[48][3][3]>(v992 + 85880832);
  kernel647(v1004, v1007, v1005);	// L1649
  auto v1008 = reinterpret_cast<float(*)[96][32][32]>(v990 + 393216);
  auto v1009 = reinterpret_cast<float(*)[96][32][32]>(v990 + 6684672);
  kernel631(v1008, v1009);	// L1652
  kernel642(v1009, (float)2.000000);	// L1653
  auto v1010 = reinterpret_cast<float(*)[96][32][32]>(v991 + 7128576);
  kernel635(v1009, v1008, v1010);	// L1655
  kernel631(v1005, v1009);	// L1656
  kernel642(v1009, (float)2.000000);	// L1657
  auto v1011 = reinterpret_cast<float(*)[96][32][32]>(v992 + 6906624);
  kernel641(v1009, v1010, v1011);	// L1659
  kernel631(v1011, v1009);	// L1660
  kernel639(v1009, (float)1.000000);	// L1661
  kernel631(v1009, v1010);	// L1662
  kernel637(v1010, (float)1.000000, (float)0.000000);	// L1663
  kernel636(v1011, v1010, v1009);	// L1664
  auto v1012 = reinterpret_cast<float(*)[96][32][32]>(v991 + 7350528);
  kernel635(v1009, v1011, v1012);	// L1666
  kernel631(v1010, v1009);	// L1667
  kernel633(v1009, (float)0.000000);	// L1668
  kernel632(v1012, v1009);	// L1669
  kernel631(v1009, v1008);	// L1670
  auto v1013 = reinterpret_cast<float(*)[96][34][34]>(v990 + 6684672);
  kernel630(v1013, (float)0.000000);	// L1672
  kernel629(v1010, v1013);	// L1673
  auto v1014 = reinterpret_cast<float(*)[192][32][32]>(v991 + 6906624);
  auto v1015 = reinterpret_cast<float(*)>(v992 + 81899520);
  kernel628(v1015, v1014);	// L1676
  auto v1016 = reinterpret_cast<float(*)[96][3][3]>(v992 + 83226624);
  kernel627(v1013, v1016, v1014);	// L1678
  auto v1017 = reinterpret_cast<float(*)[192][32][32]>(v990 + 589824);
  auto v1018 = reinterpret_cast<float(*)[192][32][32]>(v991 + 6684672);
  kernel611(v1017, v1018);	// L1681
  kernel622(v1018, (float)2.000000);	// L1682
  auto v1019 = reinterpret_cast<float(*)[192][32][32]>(v992 + 7128576);
  kernel615(v1018, v1017, v1019);	// L1684
  kernel611(v1014, v1018);	// L1685
  kernel622(v1018, (float)2.000000);	// L1686
  auto v1020 = reinterpret_cast<float(*)[192][32][32]>(v990 + 6906624);
  kernel621(v1018, v1019, v1020);	// L1688
  kernel611(v1020, v1018);	// L1689
  kernel619(v1018, (float)1.000000);	// L1690
  auto v1021 = reinterpret_cast<float(*)[192][32][32]>(v990 + 7128576);
  kernel611(v1018, v1021);	// L1692
  kernel617(v1021, (float)1.000000, (float)0.000000);	// L1693
  kernel616(v1020, v1021, v1018);	// L1694
  auto v1022 = reinterpret_cast<float(*)[192][32][32]>(v990 + 7350528);
  kernel615(v1018, v1020, v1022);	// L1696
  kernel611(v1021, v1018);	// L1697
  kernel613(v1018, (float)0.000000);	// L1698
  kernel612(v1022, v1018);	// L1699
  kernel611(v1018, v1017);	// L1700
  auto v1023 = reinterpret_cast<float(*)[192][34][34]>(v991 + 6684672);
  kernel610(v1023, (float)-INFINITY);	// L1702
  kernel609(v1021, v1023);	// L1703
  auto v1024 = reinterpret_cast<float(*)[192][16][16]>(v990 + 6906624);
  kernel608(v1024, (float)-INFINITY);	// L1705
  auto v1025 = reinterpret_cast<float(*)[3]>(v990 + 7128576);
  kernel607(v1023, v1025, v1024);	// L1707
  auto v1026 = reinterpret_cast<float(*)[192][18][18]>(v991 + 6684672);
  kernel606(v1026, (float)0.000000);	// L1709
  kernel605(v1024, v1026);	// L1710
  auto v1027 = reinterpret_cast<float(*)[384][16][16]>(v991 + 6906624);
  auto v1028 = reinterpret_cast<float(*)>(v992 + 79245312);
  kernel604(v1028, v1027);	// L1713
  auto v1029 = reinterpret_cast<float(*)[192][3][3]>(v992 + 80572416);
  kernel603(v1026, v1029, v1027);	// L1715
  auto v1030 = reinterpret_cast<float(*)[384][16][16]>(v990 + 786432);
  auto v1031 = reinterpret_cast<float(*)[384][16][16]>(v990 + 6684672);
  kernel587(v1030, v1031);	// L1718
  kernel598(v1031, (float)2.000000);	// L1719
  auto v1032 = reinterpret_cast<float(*)[384][16][16]>(v992 + 7350528);
  kernel591(v1031, v1030, v1032);	// L1721
  kernel587(v1027, v1031);	// L1722
  kernel598(v1031, (float)2.000000);	// L1723
  kernel597(v1031, v1032, v1027);	// L1724
  kernel587(v1027, v1031);	// L1725
  kernel595(v1031, (float)1.000000);	// L1726
  auto v1033 = reinterpret_cast<float(*)[384][16][16]>(v991 + 7350528);
  kernel587(v1031, v1033);	// L1728
  kernel593(v1033, (float)1.000000, (float)0.000000);	// L1729
  kernel592(v1027, v1033, v1031);	// L1730
  auto v1034 = reinterpret_cast<float(*)[384][16][16]>(v991 + 7572480);
  kernel591(v1031, v1027, v1034);	// L1732
  kernel587(v1033, v1031);	// L1733
  kernel589(v1031, (float)0.000000);	// L1734
  kernel588(v1034, v1031);	// L1735
  kernel587(v1031, v1030);	// L1736
  auto v1035 = reinterpret_cast<float(*)[384][18][18]>(v992 + 6684672);
  kernel586(v1035, (float)-INFINITY);	// L1738
  kernel585(v1033, v1035);	// L1739
  auto v1036 = reinterpret_cast<float(*)[384][8][8]>(v991 + 6906624);
  kernel584(v1036, (float)-INFINITY);	// L1741
  kernel583(v1035, v1025, v1036);	// L1742
  auto v1037 = reinterpret_cast<float(*)[384][10][10]>(v990 + 6684672);
  kernel582(v1037, (float)0.000000);	// L1744
  kernel581(v1036, v1037);	// L1745
  auto v1038 = reinterpret_cast<float(*)[384][8][8]>(v990 + 7128576);
  auto v1039 = reinterpret_cast<float(*)>(v992 + 76591104);
  kernel9(v1039, v1038);	// L1748
  auto v1040 = reinterpret_cast<float(*)[384][3][3]>(v992 + 77918208);
  kernel579(v1037, v1040, v1038);	// L1750
  auto v1041 = reinterpret_cast<float(*)[384][8][8]>(v990 + 983040);
  kernel28(v1041, v1036);	// L1752
  kernel39(v1036, (float)2.000000);	// L1753
  auto v1042 = reinterpret_cast<float(*)[384][8][8]>(v992 + 6684672);
  kernel32(v1036, v1041, v1042);	// L1755
  kernel28(v1038, v1036);	// L1756
  kernel39(v1036, (float)2.000000);	// L1757
  auto v1043 = reinterpret_cast<float(*)[384][8][8]>(v992 + 7350528);
  kernel38(v1036, v1042, v1043);	// L1759
  kernel28(v1043, v1036);	// L1760
  kernel36(v1036, (float)1.000000);	// L1761
  auto v1044 = reinterpret_cast<float(*)[384][8][8]>(v990 + 6684672);
  kernel28(v1036, v1044);	// L1763
  kernel34(v1044, (float)1.000000, (float)0.000000);	// L1764
  kernel33(v1043, v1044, v1036);	// L1765
  auto v1045 = reinterpret_cast<float(*)[384][8][8]>(v990 + 7572480);
  kernel32(v1036, v1043, v1045);	// L1767
  kernel28(v1044, v1036);	// L1768
  kernel30(v1036, (float)0.000000);	// L1769
  kernel7(v1045, v1036);	// L1770
  kernel28(v1036, v1041);	// L1771
  auto v1046 = reinterpret_cast<float(*)[384][64]>(v991 + 7350528);
  auto v1047 = reinterpret_cast<float(*)>(v992 + 73936896);
  kernel46(v1047, v1046);	// L1774
  auto v1048 = reinterpret_cast<float(*)[384][1]>(v992 + 75264000);
  kernel91(v1044, v1048, v1046);	// L1776
  auto v1049 = reinterpret_cast<float(*)[384][64]>(v990 + 1179648);
  auto v1050 = reinterpret_cast<float(*)[384][64]>(v990 + 7572480);
  kernel75(v1049, v1050);	// L1779
  kernel86(v1050, (float)2.000000);	// L1780
  auto v1051 = reinterpret_cast<float(*)[384][64]>(v992 + 7794432);
  kernel79(v1050, v1049, v1051);	// L1782
  kernel75(v1046, v1050);	// L1783
  kernel86(v1050, (float)2.000000);	// L1784
  kernel85(v1050, v1051, v1046);	// L1785
  kernel75(v1046, v1050);	// L1786
  kernel83(v1050, (float)1.000000);	// L1787
  auto v1052 = reinterpret_cast<float(*)[384][64]>(v991 + 7794432);
  kernel75(v1050, v1052);	// L1789
  kernel81(v1052, (float)1.000000, (float)0.000000);	// L1790
  kernel80(v1046, v1052, v1050);	// L1791
  auto v1053 = reinterpret_cast<float(*)[384][64]>(v992 + 8016384);
  kernel79(v1050, v1046, v1053);	// L1793
  kernel75(v1052, v1050);	// L1794
  kernel77(v1050, (float)0.000000);	// L1795
  kernel76(v1053, v1050);	// L1796
  kernel75(v1050, v1049);	// L1797
  auto v1054 = reinterpret_cast<float(*)[64][384]>(v990 + 7350528);
  kernel74(v1052, v1054);	// L1799
  auto v1055 = reinterpret_cast<float(*)[12][64][32]>(v991 + 7794432);
  kernel73(v1054, v1055);	// L1801
  auto v1056 = reinterpret_cast<float(*)[384][64]>(v991 + 8016384);
  auto v1057 = reinterpret_cast<float(*)>(v992 + 71282688);
  kernel46(v1057, v1056);	// L1804
  auto v1058 = reinterpret_cast<float(*)[384][1]>(v992 + 72609792);
  kernel91(v1044, v1058, v1056);	// L1806
  auto v1059 = reinterpret_cast<float(*)[384][64]>(v990 + 1376256);
  kernel75(v1059, v1050);	// L1808
  kernel86(v1050, (float)2.000000);	// L1809
  auto v1060 = reinterpret_cast<float(*)[384][64]>(v991 + 8238336);
  kernel79(v1050, v1059, v1060);	// L1811
  kernel75(v1056, v1050);	// L1812
  kernel86(v1050, (float)2.000000);	// L1813
  kernel85(v1050, v1060, v1053);	// L1814
  kernel75(v1053, v1050);	// L1815
  kernel83(v1050, (float)1.000000);	// L1816
  kernel75(v1050, v1060);	// L1817
  kernel81(v1060, (float)1.000000, (float)0.000000);	// L1818
  kernel80(v1053, v1060, v1050);	// L1819
  auto v1061 = reinterpret_cast<float(*)[384][64]>(v991 + 8460288);
  kernel79(v1050, v1053, v1061);	// L1821
  kernel75(v1060, v1050);	// L1822
  kernel77(v1050, (float)0.000000);	// L1823
  kernel76(v1061, v1050);	// L1824
  kernel75(v1050, v1059);	// L1825
  auto v1062 = reinterpret_cast<float(*)[64][384]>(v990 + 8016384);
  kernel74(v1060, v1062);	// L1827
  auto v1063 = reinterpret_cast<float(*)>(v992 + 68628480);
  kernel46(v1063, v1060);	// L1829
  auto v1064 = reinterpret_cast<float(*)[384][1]>(v992 + 69955584);
  kernel91(v1044, v1064, v1060);	// L1831
  auto v1065 = reinterpret_cast<float(*)[384][64]>(v990 + 1572864);
  kernel75(v1065, v1050);	// L1833
  kernel86(v1050, (float)2.000000);	// L1834
  auto v1066 = reinterpret_cast<float(*)[384][64]>(v992 + 6684672);
  kernel79(v1050, v1065, v1066);	// L1836
  kernel75(v1060, v1050);	// L1837
  kernel86(v1050, (float)2.000000);	// L1838
  kernel85(v1050, v1066, v1060);	// L1839
  kernel75(v1060, v1050);	// L1840
  kernel83(v1050, (float)1.000000);	// L1841
  auto v1067 = reinterpret_cast<float(*)[384][64]>(v991 + 6684672);
  kernel75(v1050, v1067);	// L1843
  kernel81(v1067, (float)1.000000, (float)0.000000);	// L1844
  kernel80(v1060, v1067, v1050);	// L1845
  auto v1068 = reinterpret_cast<float(*)[384][64]>(v992 + 8460288);
  kernel79(v1050, v1060, v1068);	// L1847
  kernel75(v1067, v1050);	// L1848
  kernel77(v1050, (float)0.000000);	// L1849
  kernel76(v1068, v1050);	// L1850
  kernel75(v1050, v1065);	// L1851
  kernel74(v1067, v1054);	// L1852
  auto v1069 = reinterpret_cast<float(*)[12][64][32]>(v991 + 6684672);
  kernel73(v1054, v1069);	// L1854
  auto v1070 = reinterpret_cast<float(*)[12][32][64]>(v991 + 8238336);
  kernel72(v1062, v1070);	// L1856
  auto v1071 = reinterpret_cast<float(*)[12][64][32]>(v990 + 8460288);
  kernel67(v1055, v1071);	// L1858
  auto v1072 = reinterpret_cast<float(*)[12][32][64]>(v990 + 7794432);
  kernel70(v1070, v1072);	// L1860
  auto v1073 = reinterpret_cast<float(*)[64][64]>(v991 + 8016384);
  kernel500(v1073, (float)0.000000);	// L1862
  auto v1074 = reinterpret_cast<float(*)[64][64]>(v990 + 8238336);
  kernel212(v1073, v1074);	// L1864
  kernel69(v1071, v1072, v1074);	// L1865
  auto v1075 = reinterpret_cast<float(*)[12][64][64]>(v991 + 8682240);
  kernel68(v1074, v1075);	// L1867
  kernel67(v1069, v1071);	// L1868
  auto v1076 = reinterpret_cast<float(*)[64][32]>(v990 + 6684672);
  kernel495(v1076, (float)0.000000);	// L1870
  auto v1077 = reinterpret_cast<float(*)[64][32]>(v992 + 8238336);
  kernel208(v1076, v1077);	// L1872
  kernel66(v1075, v1071, v1077);	// L1873
  auto v1078 = reinterpret_cast<float(*)>(v992 + 89862144);
  kernel65(v1077, v1078, v1071);	// L1875
  auto v1079 = reinterpret_cast<float(*)[64][12][32]>(v991 + 8238336);
  kernel64(v1071, v1079);	// L1877
  auto v1080 = reinterpret_cast<float(*)[64][384]>(v990 + 1769472);
  kernel48(v1080, v1054);	// L1879
  kernel59(v1054, (float)2.000000);	// L1880
  auto v1081 = reinterpret_cast<float(*)[64][384]>(v991 + 8904192);
  kernel52(v1054, v1080, v1081);	// L1882
  kernel60(v1079, v1054);	// L1883
  kernel59(v1054, (float)2.000000);	// L1884
  auto v1082 = reinterpret_cast<float(*)[64][384]>(v992 + 9126144);
  kernel58(v1054, v1081, v1082);	// L1886
  kernel48(v1082, v1054);	// L1887
  kernel56(v1054, (float)0.500000);	// L1888
  kernel48(v1054, v1081);	// L1889
  kernel54(v1081, (float)1.000000, (float)0.000000);	// L1890
  kernel53(v1082, v1081, v1054);	// L1891
  auto v1083 = reinterpret_cast<float(*)[64][384]>(v991 + 9348096);
  kernel52(v1054, v1082, v1083);	// L1893
  kernel48(v1081, v1054);	// L1894
  kernel50(v1054, (float)0.000000);	// L1895
  kernel49(v1083, v1054);	// L1896
  kernel48(v1054, v1080);	// L1897
  auto v1084 = reinterpret_cast<float(*)[384][64]>(v991 + 9126144);
  kernel47(v1081, v1084);	// L1899
  auto v1085 = reinterpret_cast<float(*)>(v992 + 65974272);
  kernel46(v1085, v1050);	// L1901
  auto v1086 = reinterpret_cast<float(*)[384][1]>(v992 + 67301376);
  kernel45(v1084, v1086, v1050);	// L1903
  auto v1087 = reinterpret_cast<float(*)[384][8][8]>(v990 + 8904192);
  kernel44(v1050, v1038, v1087);	// L1905
  auto v1088 = reinterpret_cast<float(*)[384][8][8]>(v990 + 1966080);
  kernel28(v1088, v1036);	// L1907
  kernel39(v1036, (float)2.000000);	// L1908
  kernel32(v1036, v1088, v1038);	// L1909
  kernel28(v1087, v1036);	// L1910
  kernel39(v1036, (float)2.000000);	// L1911
  auto v1089 = reinterpret_cast<float(*)[384][8][8]>(v992 + 9126144);
  kernel38(v1036, v1038, v1089);	// L1913
  kernel28(v1089, v1036);	// L1914
  kernel36(v1036, (float)1.000000);	// L1915
  kernel28(v1036, v1038);	// L1916
  kernel34(v1038, (float)1.000000, (float)0.000000);	// L1917
  kernel33(v1089, v1038, v1036);	// L1918
  auto v1090 = reinterpret_cast<float(*)[384][8][8]>(v990 + 9348096);
  kernel32(v1036, v1089, v1090);	// L1920
  kernel28(v1038, v1036);	// L1921
  kernel30(v1036, (float)0.000000);	// L1922
  kernel7(v1090, v1036);	// L1923
  kernel28(v1036, v1088);	// L1924
  auto v1091 = reinterpret_cast<float(*)[1536][8][8]>(v991 + 9126144);
  auto v1092 = reinterpret_cast<float(*)>(v992 + 63320064);
  kernel27(v1092, v1091);	// L1927
  auto v1093 = reinterpret_cast<float(*)[384][1][1]>(v992 + 64647168);
  kernel26(v1038, v1093, v1091);	// L1929
  auto v1094 = reinterpret_cast<float(*)[1536][8][8]>(v990 + 2162688);
  auto v1095 = reinterpret_cast<float(*)[1536][8][8]>(v990 + 7128576);
  kernel10(v1094, v1095);	// L1932
  kernel21(v1095, (float)2.000000);	// L1933
  auto v1096 = reinterpret_cast<float(*)[1536][8][8]>(v991 + 9348096);
  kernel14(v1095, v1094, v1096);	// L1935
  kernel10(v1091, v1095);	// L1936
  kernel21(v1095, (float)2.000000);	// L1937
  kernel20(v1095, v1096, v1091);	// L1938
  kernel10(v1091, v1095);	// L1939
  kernel18(v1095, (float)1.000000);	// L1940
  auto v1097 = reinterpret_cast<float(*)[1536][8][8]>(v990 + 9348096);
  kernel10(v1095, v1097);	// L1942
  kernel16(v1097, (float)1.000000, (float)0.000000);	// L1943
  kernel15(v1091, v1097, v1095);	// L1944
  auto v1098 = reinterpret_cast<float(*)[1536][8][8]>(v992 + 9570048);
  kernel14(v1095, v1091, v1098);	// L1946
  kernel10(v1097, v1095);	// L1947
  kernel12(v1095, (float)0.000000);	// L1948
  kernel11(v1098, v1095);	// L1949
  kernel10(v1095, v1094);	// L1950
  auto v1099 = reinterpret_cast<float(*)>(v992 + 60665856);
  kernel9(v1099, v1036);	// L1952
  auto v1100 = reinterpret_cast<float(*)[1536][1][1]>(v992 + 61992960);
  kernel8(v1097, v1100, v1036);	// L1954
  auto v1101 = reinterpret_cast<float(*)[384][8][8]>(v991 + 9126144);
  kernel38(v1036, v1087, v1101);	// L1956
  auto v1102 = reinterpret_cast<float(*)[384][8][8]>(v990 + 2359296);
  kernel28(v1102, v1036);	// L1958
  kernel39(v1036, (float)2.000000);	// L1959
  auto v1103 = reinterpret_cast<float(*)[384][8][8]>(v992 + 8904192);
  kernel32(v1036, v1102, v1103);	// L1961
  kernel28(v1101, v1036);	// L1962
  kernel39(v1036, (float)2.000000);	// L1963
  auto v1104 = reinterpret_cast<float(*)[384][8][8]>(v992 + 9348096);
  kernel38(v1036, v1103, v1104);	// L1965
  kernel28(v1104, v1036);	// L1966
  kernel36(v1036, (float)1.000000);	// L1967
  kernel28(v1036, v1087);	// L1968
  kernel34(v1087, (float)1.000000, (float)0.000000);	// L1969
  kernel33(v1104, v1087, v1036);	// L1970
  auto v1105 = reinterpret_cast<float(*)[384][8][8]>(v990 + 9570048);
  kernel32(v1036, v1104, v1105);	// L1972
  kernel28(v1087, v1036);	// L1973
  kernel30(v1036, (float)0.000000);	// L1974
  kernel7(v1105, v1036);	// L1975
  kernel28(v1036, v1102);	// L1976
  auto v1106 = reinterpret_cast<float(*)[384][64]>(v991 + 9348096);
  auto v1107 = reinterpret_cast<float(*)>(v992 + 58011648);
  kernel46(v1107, v1106);	// L1979
  auto v1108 = reinterpret_cast<float(*)[384][1]>(v992 + 59338752);
  kernel91(v1087, v1108, v1106);	// L1981
  auto v1109 = reinterpret_cast<float(*)[384][64]>(v990 + 2555904);
  kernel75(v1109, v1050);	// L1983
  kernel86(v1050, (float)2.000000);	// L1984
  auto v1110 = reinterpret_cast<float(*)[384][64]>(v991 + 9570048);
  kernel79(v1050, v1109, v1110);	// L1986
  kernel75(v1106, v1050);	// L1987
  kernel86(v1050, (float)2.000000);	// L1988
  kernel85(v1050, v1110, v1106);	// L1989
  kernel75(v1106, v1050);	// L1990
  kernel83(v1050, (float)1.000000);	// L1991
  kernel75(v1050, v1110);	// L1992
  kernel81(v1110, (float)1.000000, (float)0.000000);	// L1993
  kernel80(v1106, v1110, v1050);	// L1994
  auto v1111 = reinterpret_cast<float(*)[384][64]>(v992 + 9792000);
  kernel79(v1050, v1106, v1111);	// L1996
  kernel75(v1110, v1050);	// L1997
  kernel77(v1050, (float)0.000000);	// L1998
  kernel76(v1111, v1050);	// L1999
  kernel75(v1050, v1109);	// L2000
  kernel74(v1110, v1054);	// L2001
  auto v1112 = reinterpret_cast<float(*)[12][64][32]>(v991 + 9348096);
  kernel73(v1054, v1112);	// L2003
  auto v1113 = reinterpret_cast<float(*)[384][64]>(v990 + 9570048);
  auto v1114 = reinterpret_cast<float(*)>(v992 + 55357440);
  kernel46(v1114, v1113);	// L2006
  auto v1115 = reinterpret_cast<float(*)[384][1]>(v992 + 56684544);
  kernel91(v1087, v1115, v1113);	// L2008
  auto v1116 = reinterpret_cast<float(*)[384][64]>(v990 + 2752512);
  kernel75(v1116, v1050);	// L2010
  kernel86(v1050, (float)2.000000);	// L2011
  kernel79(v1050, v1116, v1111);	// L2012
  kernel75(v1113, v1050);	// L2013
  kernel86(v1050, (float)2.000000);	// L2014
  kernel85(v1050, v1111, v1110);	// L2015
  kernel75(v1110, v1050);	// L2016
  kernel83(v1050, (float)1.000000);	// L2017
  auto v1117 = reinterpret_cast<float(*)[384][64]>(v990 + 9792000);
  kernel75(v1050, v1117);	// L2019
  kernel81(v1117, (float)1.000000, (float)0.000000);	// L2020
  kernel80(v1110, v1117, v1050);	// L2021
  auto v1118 = reinterpret_cast<float(*)[384][64]>(v992 + 10013952);
  kernel79(v1050, v1110, v1118);	// L2023
  kernel75(v1117, v1050);	// L2024
  kernel77(v1050, (float)0.000000);	// L2025
  kernel76(v1118, v1050);	// L2026
  kernel75(v1050, v1116);	// L2027
  auto v1119 = reinterpret_cast<float(*)[64][384]>(v990 + 9570048);
  kernel74(v1117, v1119);	// L2029
  auto v1120 = reinterpret_cast<float(*)[384][64]>(v991 + 9792000);
  auto v1121 = reinterpret_cast<float(*)>(v992 + 52703232);
  kernel46(v1121, v1120);	// L2032
  auto v1122 = reinterpret_cast<float(*)[384][1]>(v992 + 54030336);
  kernel91(v1087, v1122, v1120);	// L2034
  auto v1123 = reinterpret_cast<float(*)[384][64]>(v990 + 2949120);
  kernel75(v1123, v1050);	// L2036
  kernel86(v1050, (float)2.000000);	// L2037
  auto v1124 = reinterpret_cast<float(*)[384][64]>(v991 + 8904192);
  kernel79(v1050, v1123, v1124);	// L2039
  kernel75(v1120, v1050);	// L2040
  kernel86(v1050, (float)2.000000);	// L2041
  kernel85(v1050, v1124, v1120);	// L2042
  kernel75(v1120, v1050);	// L2043
  kernel83(v1050, (float)1.000000);	// L2044
  auto v1125 = reinterpret_cast<float(*)[384][64]>(v992 + 8904192);
  kernel75(v1050, v1125);	// L2046
  kernel81(v1125, (float)1.000000, (float)0.000000);	// L2047
  kernel80(v1120, v1125, v1050);	// L2048
  auto v1126 = reinterpret_cast<float(*)[384][64]>(v991 + 10013952);
  kernel79(v1050, v1120, v1126);	// L2050
  kernel75(v1125, v1050);	// L2051
  kernel77(v1050, (float)0.000000);	// L2052
  kernel76(v1126, v1050);	// L2053
  kernel75(v1050, v1123);	// L2054
  kernel74(v1125, v1054);	// L2055
  auto v1127 = reinterpret_cast<float(*)[12][64][32]>(v991 + 8904192);
  kernel73(v1054, v1127);	// L2057
  auto v1128 = reinterpret_cast<float(*)[12][32][64]>(v991 + 9792000);
  kernel72(v1119, v1128);	// L2059
  kernel67(v1112, v1071);	// L2060
  kernel70(v1128, v1072);	// L2061
  auto v1129 = reinterpret_cast<float(*)[64][64]>(v990 + 9348096);
  kernel212(v1073, v1129);	// L2063
  kernel69(v1071, v1072, v1129);	// L2064
  kernel68(v1129, v1075);	// L2065
  kernel67(v1127, v1071);	// L2066
  auto v1130 = reinterpret_cast<float(*)[64][32]>(v992 + 8904192);
  kernel208(v1076, v1130);	// L2068
  kernel66(v1075, v1071, v1130);	// L2069
  kernel65(v1130, v1078, v1071);	// L2070
  kernel64(v1071, v1079);	// L2071
  auto v1131 = reinterpret_cast<float(*)[64][384]>(v990 + 3145728);
  kernel48(v1131, v1054);	// L2073
  kernel59(v1054, (float)2.000000);	// L2074
  auto v1132 = reinterpret_cast<float(*)[64][384]>(v992 + 8904192);
  kernel52(v1054, v1131, v1132);	// L2076
  kernel60(v1079, v1054);	// L2077
  kernel59(v1054, (float)2.000000);	// L2078
  kernel58(v1054, v1132, v1083);	// L2079
  kernel48(v1083, v1054);	// L2080
  kernel56(v1054, (float)0.500000);	// L2081
  auto v1133 = reinterpret_cast<float(*)[64][384]>(v990 + 8904192);
  kernel48(v1054, v1133);	// L2083
  kernel54(v1133, (float)1.000000, (float)0.000000);	// L2084
  kernel53(v1083, v1133, v1054);	// L2085
  auto v1134 = reinterpret_cast<float(*)[64][384]>(v992 + 9570048);
  kernel52(v1054, v1083, v1134);	// L2087
  kernel48(v1133, v1054);	// L2088
  kernel50(v1054, (float)0.000000);	// L2089
  kernel49(v1134, v1054);	// L2090
  kernel48(v1054, v1131);	// L2091
  kernel47(v1133, v1106);	// L2092
  auto v1135 = reinterpret_cast<float(*)>(v992 + 50049024);
  kernel46(v1135, v1050);	// L2094
  auto v1136 = reinterpret_cast<float(*)[384][1]>(v992 + 51376128);
  kernel45(v1106, v1136, v1050);	// L2096
  kernel44(v1050, v1101, v1103);	// L2097
  auto v1137 = reinterpret_cast<float(*)[384][8][8]>(v990 + 3342336);
  kernel28(v1137, v1036);	// L2099
  kernel39(v1036, (float)2.000000);	// L2100
  kernel32(v1036, v1137, v1089);	// L2101
  kernel28(v1103, v1036);	// L2102
  kernel39(v1036, (float)2.000000);	// L2103
  kernel38(v1036, v1089, v1090);	// L2104
  kernel28(v1090, v1036);	// L2105
  kernel36(v1036, (float)1.000000);	// L2106
  auto v1138 = reinterpret_cast<float(*)[384][8][8]>(v990 + 9126144);
  kernel28(v1036, v1138);	// L2108
  kernel34(v1138, (float)1.000000, (float)0.000000);	// L2109
  kernel33(v1090, v1138, v1036);	// L2110
  auto v1139 = reinterpret_cast<float(*)[384][8][8]>(v992 + 9570048);
  kernel32(v1036, v1090, v1139);	// L2112
  kernel28(v1138, v1036);	// L2113
  kernel30(v1036, (float)0.000000);	// L2114
  kernel7(v1139, v1036);	// L2115
  kernel28(v1036, v1137);	// L2116
  auto v1140 = reinterpret_cast<float(*)>(v992 + 47394816);
  kernel27(v1140, v1096);	// L2118
  auto v1141 = reinterpret_cast<float(*)[384][1][1]>(v992 + 48721920);
  kernel26(v1138, v1141, v1096);	// L2120
  auto v1142 = reinterpret_cast<float(*)[1536][8][8]>(v990 + 3538944);
  kernel10(v1142, v1095);	// L2122
  kernel21(v1095, (float)2.000000);	// L2123
  auto v1143 = reinterpret_cast<float(*)[1536][8][8]>(v992 + 9126144);
  kernel14(v1095, v1142, v1143);	// L2125
  kernel10(v1096, v1095);	// L2126
  kernel21(v1095, (float)2.000000);	// L2127
  kernel20(v1095, v1143, v1096);	// L2128
  kernel10(v1096, v1095);	// L2129
  kernel18(v1095, (float)1.000000);	// L2130
  kernel10(v1095, v1091);	// L2131
  kernel16(v1091, (float)1.000000, (float)0.000000);	// L2132
  kernel15(v1096, v1091, v1095);	// L2133
  auto v1144 = reinterpret_cast<float(*)[1536][8][8]>(v991 + 9570048);
  kernel14(v1095, v1096, v1144);	// L2135
  kernel10(v1091, v1095);	// L2136
  kernel12(v1095, (float)0.000000);	// L2137
  kernel11(v1144, v1095);	// L2138
  kernel10(v1095, v1142);	// L2139
  auto v1145 = reinterpret_cast<float(*)>(v992 + 44740608);
  kernel9(v1145, v1036);	// L2141
  auto v1146 = reinterpret_cast<float(*)[1536][1][1]>(v992 + 46067712);
  kernel8(v1091, v1146, v1036);	// L2143
  kernel38(v1036, v1103, v1138);	// L2144
  auto v1147 = reinterpret_cast<float(*)[384][8][8]>(v990 + 3735552);
  kernel28(v1147, v1036);	// L2146
  kernel39(v1036, (float)2.000000);	// L2147
  kernel32(v1036, v1147, v1103);	// L2148
  kernel28(v1138, v1036);	// L2149
  kernel39(v1036, (float)2.000000);	// L2150
  kernel38(v1036, v1103, v1090);	// L2151
  kernel28(v1090, v1036);	// L2152
  kernel36(v1036, (float)1.000000);	// L2153
  kernel28(v1036, v1087);	// L2154
  kernel34(v1087, (float)1.000000, (float)0.000000);	// L2155
  kernel33(v1090, v1087, v1036);	// L2156
  kernel32(v1036, v1090, v1139);	// L2157
  kernel28(v1087, v1036);	// L2158
  kernel30(v1036, (float)0.000000);	// L2159
  kernel7(v1139, v1036);	// L2160
  kernel28(v1036, v1147);	// L2161
  auto v1148 = reinterpret_cast<float(*)>(v992 + 42086400);
  kernel46(v1148, v1106);	// L2163
  auto v1149 = reinterpret_cast<float(*)[384][1]>(v992 + 43413504);
  kernel91(v1087, v1149, v1106);	// L2165
  auto v1150 = reinterpret_cast<float(*)[384][64]>(v990 + 3932160);
  kernel75(v1150, v1050);	// L2167
  kernel86(v1050, (float)2.000000);	// L2168
  kernel79(v1050, v1150, v1110);	// L2169
  kernel75(v1106, v1050);	// L2170
  kernel86(v1050, (float)2.000000);	// L2171
  auto v1151 = reinterpret_cast<float(*)[384][64]>(v992 + 9348096);
  kernel85(v1050, v1110, v1151);	// L2173
  kernel75(v1151, v1050);	// L2174
  kernel83(v1050, (float)1.000000);	// L2175
  kernel75(v1050, v1110);	// L2176
  kernel81(v1110, (float)1.000000, (float)0.000000);	// L2177
  kernel80(v1151, v1110, v1050);	// L2178
  kernel79(v1050, v1151, v1120);	// L2179
  kernel75(v1110, v1050);	// L2180
  kernel77(v1050, (float)0.000000);	// L2181
  kernel76(v1120, v1050);	// L2182
  kernel75(v1050, v1150);	// L2183
  kernel74(v1110, v1054);	// L2184
  kernel73(v1054, v1112);	// L2185
  auto v1152 = reinterpret_cast<float(*)>(v992 + 39432192);
  kernel46(v1152, v1110);	// L2187
  auto v1153 = reinterpret_cast<float(*)[384][1]>(v992 + 40759296);
  kernel91(v1087, v1153, v1110);	// L2189
  auto v1154 = reinterpret_cast<float(*)[384][64]>(v990 + 4128768);
  kernel75(v1154, v1050);	// L2191
  kernel86(v1050, (float)2.000000);	// L2192
  kernel79(v1050, v1154, v1120);	// L2193
  kernel75(v1110, v1050);	// L2194
  kernel86(v1050, (float)2.000000);	// L2195
  auto v1155 = reinterpret_cast<float(*)[384][64]>(v992 + 9570048);
  kernel85(v1050, v1120, v1155);	// L2197
  kernel75(v1155, v1050);	// L2198
  kernel83(v1050, (float)1.000000);	// L2199
  kernel75(v1050, v1117);	// L2200
  kernel81(v1117, (float)1.000000, (float)0.000000);	// L2201
  kernel80(v1155, v1117, v1050);	// L2202
  kernel79(v1050, v1155, v1126);	// L2203
  kernel75(v1117, v1050);	// L2204
  kernel77(v1050, (float)0.000000);	// L2205
  kernel76(v1126, v1050);	// L2206
  kernel75(v1050, v1154);	// L2207
  auto v1156 = reinterpret_cast<float(*)[64][384]>(v991 + 9570048);
  kernel74(v1117, v1156);	// L2209
  auto v1157 = reinterpret_cast<float(*)>(v992 + 36777984);
  kernel46(v1157, v1120);	// L2211
  auto v1158 = reinterpret_cast<float(*)[384][1]>(v992 + 38105088);
  kernel91(v1087, v1158, v1120);	// L2213
  auto v1159 = reinterpret_cast<float(*)[384][64]>(v990 + 4325376);
  kernel75(v1159, v1050);	// L2215
  kernel86(v1050, (float)2.000000);	// L2216
  kernel79(v1050, v1159, v1124);	// L2217
  kernel75(v1120, v1050);	// L2218
  kernel86(v1050, (float)2.000000);	// L2219
  kernel85(v1050, v1124, v1120);	// L2220
  kernel75(v1120, v1050);	// L2221
  kernel83(v1050, (float)1.000000);	// L2222
  kernel75(v1050, v1125);	// L2223
  kernel81(v1125, (float)1.000000, (float)0.000000);	// L2224
  kernel80(v1120, v1125, v1050);	// L2225
  kernel79(v1050, v1120, v1118);	// L2226
  kernel75(v1125, v1050);	// L2227
  kernel77(v1050, (float)0.000000);	// L2228
  kernel76(v1118, v1050);	// L2229
  kernel75(v1050, v1159);	// L2230
  kernel74(v1125, v1054);	// L2231
  kernel73(v1054, v1127);	// L2232
  kernel72(v1156, v1128);	// L2233
  kernel67(v1112, v1071);	// L2234
  kernel70(v1128, v1072);	// L2235
  kernel212(v1073, v1129);	// L2236
  kernel69(v1071, v1072, v1129);	// L2237
  kernel68(v1129, v1075);	// L2238
  kernel67(v1127, v1071);	// L2239
  auto v1160 = reinterpret_cast<float(*)[64][32]>(v991 + 8904192);
  kernel208(v1076, v1160);	// L2241
  kernel66(v1075, v1071, v1160);	// L2242
  kernel65(v1160, v1078, v1071);	// L2243
  kernel64(v1071, v1079);	// L2244
  auto v1161 = reinterpret_cast<float(*)[64][384]>(v990 + 4521984);
  kernel48(v1161, v1054);	// L2246
  kernel59(v1054, (float)2.000000);	// L2247
  kernel52(v1054, v1161, v1132);	// L2248
  kernel60(v1079, v1054);	// L2249
  kernel59(v1054, (float)2.000000);	// L2250
  kernel58(v1054, v1132, v1083);	// L2251
  kernel48(v1083, v1054);	// L2252
  kernel56(v1054, (float)0.500000);	// L2253
  kernel48(v1054, v1133);	// L2254
  kernel54(v1133, (float)1.000000, (float)0.000000);	// L2255
  kernel53(v1083, v1133, v1054);	// L2256
  kernel52(v1054, v1083, v1134);	// L2257
  kernel48(v1133, v1054);	// L2258
  kernel50(v1054, (float)0.000000);	// L2259
  kernel49(v1134, v1054);	// L2260
  kernel48(v1054, v1161);	// L2261
  kernel47(v1133, v1106);	// L2262
  auto v1162 = reinterpret_cast<float(*)>(v992 + 34123776);
  kernel46(v1162, v1050);	// L2264
  auto v1163 = reinterpret_cast<float(*)[384][1]>(v992 + 35450880);
  kernel45(v1106, v1163, v1050);	// L2266
  kernel44(v1050, v1138, v1087);	// L2267
  auto v1164 = reinterpret_cast<float(*)[384][8][8]>(v990 + 4718592);
  kernel28(v1164, v1036);	// L2269
  kernel39(v1036, (float)2.000000);	// L2270
  kernel32(v1036, v1164, v1138);	// L2271
  kernel28(v1087, v1036);	// L2272
  kernel39(v1036, (float)2.000000);	// L2273
  kernel38(v1036, v1138, v1104);	// L2274
  kernel28(v1104, v1036);	// L2275
  kernel36(v1036, (float)1.000000);	// L2276
  kernel28(v1036, v1138);	// L2277
  kernel34(v1138, (float)1.000000, (float)0.000000);	// L2278
  kernel33(v1104, v1138, v1036);	// L2279
  kernel32(v1036, v1104, v1105);	// L2280
  kernel28(v1138, v1036);	// L2281
  kernel30(v1036, (float)0.000000);	// L2282
  kernel7(v1105, v1036);	// L2283
  kernel28(v1036, v1164);	// L2284
  auto v1165 = reinterpret_cast<float(*)>(v992 + 31469568);
  kernel27(v1165, v1096);	// L2286
  auto v1166 = reinterpret_cast<float(*)[384][1][1]>(v992 + 32796672);
  kernel26(v1138, v1166, v1096);	// L2288
  auto v1167 = reinterpret_cast<float(*)[1536][8][8]>(v990 + 4915200);
  kernel10(v1167, v1095);	// L2290
  kernel21(v1095, (float)2.000000);	// L2291
  kernel14(v1095, v1167, v1091);	// L2292
  kernel10(v1096, v1095);	// L2293
  kernel21(v1095, (float)2.000000);	// L2294
  kernel20(v1095, v1091, v1096);	// L2295
  kernel10(v1096, v1095);	// L2296
  kernel18(v1095, (float)1.000000);	// L2297
  auto v1168 = reinterpret_cast<float(*)[1536][8][8]>(v990 + 9126144);
  kernel10(v1095, v1168);	// L2299
  kernel16(v1168, (float)1.000000, (float)0.000000);	// L2300
  kernel15(v1096, v1168, v1095);	// L2301
  kernel14(v1095, v1096, v1098);	// L2302
  kernel10(v1168, v1095);	// L2303
  kernel12(v1095, (float)0.000000);	// L2304
  kernel11(v1098, v1095);	// L2305
  kernel10(v1095, v1167);	// L2306
  auto v1169 = reinterpret_cast<float(*)>(v992 + 28815360);
  kernel9(v1169, v1036);	// L2308
  auto v1170 = reinterpret_cast<float(*)[1536][1][1]>(v992 + 30142464);
  kernel8(v1168, v1170, v1036);	// L2310
  kernel38(v1036, v1087, v1089);	// L2311
  auto v1171 = reinterpret_cast<float(*)[384][8][8]>(v990 + 5111808);
  kernel28(v1171, v1036);	// L2313
  kernel39(v1036, (float)2.000000);	// L2314
  kernel32(v1036, v1171, v1103);	// L2315
  kernel28(v1089, v1036);	// L2316
  kernel39(v1036, (float)2.000000);	// L2317
  kernel38(v1036, v1103, v1090);	// L2318
  kernel28(v1090, v1036);	// L2319
  kernel36(v1036, (float)1.000000);	// L2320
  auto v1172 = reinterpret_cast<float(*)[384][8][8]>(v991 + 8904192);
  kernel28(v1036, v1172);	// L2322
  kernel34(v1172, (float)1.000000, (float)0.000000);	// L2323
  kernel33(v1090, v1172, v1036);	// L2324
  kernel32(v1036, v1090, v1105);	// L2325
  kernel28(v1172, v1036);	// L2326
  kernel30(v1036, (float)0.000000);	// L2327
  kernel7(v1105, v1036);	// L2328
  kernel28(v1036, v1171);	// L2329
  auto v1173 = reinterpret_cast<float(*)[384][64]>(v990 + 9348096);
  auto v1174 = reinterpret_cast<float(*)>(v992 + 26161152);
  kernel46(v1174, v1173);	// L2332
  auto v1175 = reinterpret_cast<float(*)[384][1]>(v992 + 27488256);
  kernel91(v1172, v1175, v1173);	// L2334
  auto v1176 = reinterpret_cast<float(*)[384][64]>(v990 + 5308416);
  kernel75(v1176, v1050);	// L2336
  kernel86(v1050, (float)2.000000);	// L2337
  kernel79(v1050, v1176, v1110);	// L2338
  kernel75(v1173, v1050);	// L2339
  kernel86(v1050, (float)2.000000);	// L2340
  kernel85(v1050, v1110, v1151);	// L2341
  kernel75(v1151, v1050);	// L2342
  kernel83(v1050, (float)1.000000);	// L2343
  kernel75(v1050, v1110);	// L2344
  kernel81(v1110, (float)1.000000, (float)0.000000);	// L2345
  kernel80(v1151, v1110, v1050);	// L2346
  kernel79(v1050, v1151, v1120);	// L2347
  kernel75(v1110, v1050);	// L2348
  kernel77(v1050, (float)0.000000);	// L2349
  kernel76(v1120, v1050);	// L2350
  kernel75(v1050, v1176);	// L2351
  kernel74(v1110, v1054);	// L2352
  kernel73(v1054, v1112);	// L2353
  auto v1177 = reinterpret_cast<float(*)>(v992 + 23506944);
  kernel46(v1177, v1110);	// L2355
  auto v1178 = reinterpret_cast<float(*)[384][1]>(v992 + 24834048);
  kernel91(v1172, v1178, v1110);	// L2357
  auto v1179 = reinterpret_cast<float(*)[384][64]>(v990 + 5505024);
  kernel75(v1179, v1050);	// L2359
  kernel86(v1050, (float)2.000000);	// L2360
  kernel79(v1050, v1179, v1120);	// L2361
  kernel75(v1110, v1050);	// L2362
  kernel86(v1050, (float)2.000000);	// L2363
  kernel85(v1050, v1120, v1155);	// L2364
  kernel75(v1155, v1050);	// L2365
  kernel83(v1050, (float)1.000000);	// L2366
  kernel75(v1050, v1117);	// L2367
  kernel81(v1117, (float)1.000000, (float)0.000000);	// L2368
  kernel80(v1155, v1117, v1050);	// L2369
  kernel79(v1050, v1155, v1126);	// L2370
  kernel75(v1117, v1050);	// L2371
  kernel77(v1050, (float)0.000000);	// L2372
  kernel76(v1126, v1050);	// L2373
  kernel75(v1050, v1179);	// L2374
  kernel74(v1117, v1156);	// L2375
  auto v1180 = reinterpret_cast<float(*)>(v992 + 20852736);
  kernel46(v1180, v1117);	// L2377
  auto v1181 = reinterpret_cast<float(*)[384][1]>(v992 + 22179840);
  kernel91(v1172, v1181, v1117);	// L2379
  auto v1182 = reinterpret_cast<float(*)[384][64]>(v990 + 5701632);
  kernel75(v1182, v1050);	// L2381
  kernel86(v1050, (float)2.000000);	// L2382
  kernel79(v1050, v1182, v1124);	// L2383
  kernel75(v1117, v1050);	// L2384
  kernel86(v1050, (float)2.000000);	// L2385
  kernel85(v1050, v1124, v1111);	// L2386
  kernel75(v1111, v1050);	// L2387
  kernel83(v1050, (float)1.000000);	// L2388
  kernel75(v1050, v1124);	// L2389
  kernel81(v1124, (float)1.000000, (float)0.000000);	// L2390
  kernel80(v1111, v1124, v1050);	// L2391
  kernel79(v1050, v1111, v1126);	// L2392
  kernel75(v1124, v1050);	// L2393
  kernel77(v1050, (float)0.000000);	// L2394
  kernel76(v1126, v1050);	// L2395
  kernel75(v1050, v1182);	// L2396
  kernel74(v1124, v1054);	// L2397
  kernel73(v1054, v1127);	// L2398
  kernel72(v1156, v1128);	// L2399
  kernel67(v1112, v1071);	// L2400
  kernel70(v1128, v1072);	// L2401
  kernel69(v1071, v1072, v1073);	// L2402
  kernel68(v1073, v1075);	// L2403
  kernel67(v1127, v1071);	// L2404
  kernel66(v1075, v1071, v1076);	// L2405
  kernel65(v1076, v1078, v1071);	// L2406
  kernel64(v1071, v1079);	// L2407
  auto v1183 = reinterpret_cast<float(*)[64][384]>(v990 + 5898240);
  kernel48(v1183, v1054);	// L2409
  kernel59(v1054, (float)2.000000);	// L2410
  auto v1184 = reinterpret_cast<float(*)[64][384]>(v992 + 6684672);
  kernel52(v1054, v1183, v1184);	// L2412
  kernel60(v1079, v1054);	// L2413
  kernel59(v1054, (float)2.000000);	// L2414
  auto v1185 = reinterpret_cast<float(*)[64][384]>(v991 + 7794432);
  kernel58(v1054, v1184, v1185);	// L2416
  kernel48(v1185, v1054);	// L2417
  kernel56(v1054, (float)0.500000);	// L2418
  auto v1186 = reinterpret_cast<float(*)[64][384]>(v990 + 6684672);
  kernel48(v1054, v1186);	// L2420
  kernel54(v1186, (float)1.000000, (float)0.000000);	// L2421
  kernel53(v1185, v1186, v1054);	// L2422
  auto v1187 = reinterpret_cast<float(*)[64][384]>(v992 + 8016384);
  kernel52(v1054, v1185, v1187);	// L2424
  kernel48(v1186, v1054);	// L2425
  kernel50(v1054, (float)0.000000);	// L2426
  kernel49(v1187, v1054);	// L2427
  kernel48(v1054, v1183);	// L2428
  kernel47(v1186, v1046);	// L2429
  auto v1188 = reinterpret_cast<float(*)>(v992 + 18198528);
  kernel46(v1188, v1050);	// L2431
  auto v1189 = reinterpret_cast<float(*)[384][1]>(v992 + 19525632);
  kernel45(v1046, v1189, v1050);	// L2433
  kernel44(v1050, v1089, v1044);	// L2434
  auto v1190 = reinterpret_cast<float(*)[384][8][8]>(v990 + 6094848);
  kernel28(v1190, v1036);	// L2436
  kernel39(v1036, (float)2.000000);	// L2437
  kernel32(v1036, v1190, v1043);	// L2438
  kernel28(v1044, v1036);	// L2439
  kernel39(v1036, (float)2.000000);	// L2440
  kernel38(v1036, v1043, v1045);	// L2441
  kernel28(v1045, v1036);	// L2442
  kernel36(v1036, (float)1.000000);	// L2443
  auto v1191 = reinterpret_cast<float(*)[384][8][8]>(v990 + 7350528);
  kernel28(v1036, v1191);	// L2445
  kernel34(v1191, (float)1.000000, (float)0.000000);	// L2446
  kernel33(v1045, v1191, v1036);	// L2447
  auto v1192 = reinterpret_cast<float(*)[384][8][8]>(v990 + 7794432);
  kernel32(v1036, v1045, v1192);	// L2449
  kernel28(v1191, v1036);	// L2450
  kernel30(v1036, (float)0.000000);	// L2451
  kernel7(v1192, v1036);	// L2452
  kernel28(v1036, v1190);	// L2453
  auto v1193 = reinterpret_cast<float(*)[1536][8][8]>(v991 + 7572480);
  auto v1194 = reinterpret_cast<float(*)>(v992 + 15544320);
  kernel27(v1194, v1193);	// L2456
  auto v1195 = reinterpret_cast<float(*)[384][1][1]>(v992 + 16871424);
  kernel26(v1191, v1195, v1193);	// L2458
  auto v1196 = reinterpret_cast<float(*)[1536][8][8]>(v990 + 6291456);
  kernel10(v1196, v1095);	// L2460
  kernel21(v1095, (float)2.000000);	// L2461
  auto v1197 = reinterpret_cast<float(*)[1536][8][8]>(v991 + 7350528);
  kernel14(v1095, v1196, v1197);	// L2463
  kernel10(v1193, v1095);	// L2464
  kernel21(v1095, (float)2.000000);	// L2465
  kernel20(v1095, v1197, v1193);	// L2466
  kernel10(v1193, v1095);	// L2467
  kernel18(v1095, (float)1.000000);	// L2468
  auto v1198 = reinterpret_cast<float(*)[1536][8][8]>(v990 + 7350528);
  kernel10(v1095, v1198);	// L2470
  kernel16(v1198, (float)1.000000, (float)0.000000);	// L2471
  kernel15(v1193, v1198, v1095);	// L2472
  auto v1199 = reinterpret_cast<float(*)[1536][8][8]>(v992 + 7794432);
  kernel14(v1095, v1193, v1199);	// L2474
  kernel10(v1198, v1095);	// L2475
  kernel12(v1095, (float)0.000000);	// L2476
  kernel11(v1199, v1095);	// L2477
  kernel10(v1095, v1196);	// L2478
  auto v1200 = reinterpret_cast<float(*)>(v992 + 12890112);
  kernel9(v1200, v1036);	// L2480
  auto v1201 = reinterpret_cast<float(*)[1536][1][1]>(v992 + 14217216);
  kernel8(v1198, v1201, v1036);	// L2482
  kernel7(v1044, v1036);	// L2483
  auto v1202 = reinterpret_cast<float(*)[384]>(v991 + 6684672);
  kernel6(v1202, (float)0.000000);	// L2485
  kernel5(v1036, v1202);	// L2486
  kernel4(v1202, (float)64.000000);	// L2487
  auto v1203 = reinterpret_cast<float(*)[10]>(v992 + 6906624);
  auto v1204 = reinterpret_cast<float(*)[384]>(v991 + 11563008);
  kernel3(v1204, v1203);	// L2490
  auto v1205 = reinterpret_cast<float(*)[10]>(v990 + 6488064);
  kernel2(v1205, (float)0.000000);	// L2492
  kernel1(v1202, v1203, v1205);	// L2493
  auto v1206 = reinterpret_cast<float(*)>(v992 + 10235904);
  kernel0(v1206, v1205);	// L2495
}

