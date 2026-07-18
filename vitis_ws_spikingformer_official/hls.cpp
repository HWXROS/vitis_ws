
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
  float v20[1][384],
  float v21
) {	// L32
  for (int v22 = 0; v22 < 384; v22 += 1) {	// L33
    #pragma HLS pipeline II=1
    #pragma HLS dependence false variable=v20
    float v23 = v20[0][v22];	// L34
    float v24 = v23 / v21;	// L35
    v20[0][v22] = v24;	// L36
  }
}

void kernel4(
  float v25[1][384][8][8],
  float v26[1][384]
) {	// L40
  for (int v27 = 0; v27 < 64; v27 += 1) {	// L41
    for (int v28 = 0; v28 < 384; v28 += 1) {	// L42
      float v29 = v25[0][v28][(v27 / 8)][(v27 % 8)];	// L43
      float v30 = v26[0][v28];	// L44
      float v31 = v29 + v30;	// L45
      v26[0][v28] = v31;	// L46
    }
  }
}

void kernel5(
  float v32[1][384],
  float v33
) {	// L51
  for (int v34 = 0; v34 < 384; v34 += 1) {	// L52
    #pragma HLS pipeline II=1
    #pragma HLS dependence false variable=v32
    v32[0][v34] = v33;	// L53
  }
}

void kernel6(
  float v35[1][384][8][8],
  float v36[1][384][8][8]
) {	// L57
  for (int v37 = 0; v37 < 384; v37 += 1) {	// L58
    for (int v38 = 0; v38 < 8; v38 += 1) {	// L59
      for (int v39 = 0; v39 < 8; v39 += 1) {	// L60
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v35
        #pragma HLS dependence false variable=v36
        float v40 = v35[0][v37][v38][v39];	// L61
        float v41 = v36[0][v37][v38][v39];	// L62
        float v42 = v40 + v41;	// L63
        v36[0][v37][v38][v39] = v42;	// L64
      }
    }
  }
}

void kernel7(
  float v43[1][1536][8][8],
  float v44[384][1536][1][1],
  float v45[1][384][8][8]
) {	// L70
  auto v46 = reinterpret_cast<float(*)[1536][1][1]>(v44);	// L72

  for (int v47 = 0; v47 < 1536; v47 += 1) {	// L73
    for (int v48 = 0; v48 < 384; v48 += 1) {	// L74
      for (int v49 = 0; v49 < 8; v49 += 1) {	// L75
        for (int v50 = 0; v50 < 8; v50 += 1) {	// L76
          #pragma HLS pipeline II=1
          #pragma HLS dependence false variable=v43
          #pragma HLS dependence false variable=v45
          #pragma HLS dependence false variable=v46
          float v51 = v43[0][v47][v49][v50];	// L77
          float v52 = v46[v48][v47][0][0];	// L78
          float v53 = v45[0][v48][v49][v50];	// L79
          float v54 = v51 * v52;	// L80
          float v55 = v53 + v54;	// L81
          v45[0][v48][v49][v50] = v55;	// L82
        }
      }
    }
  }
}

void kernel8(
  float v56[384],
  float v57[1][384][8][8]
) {	// L89
  float v58[384];	// L90
  #pragma HLS resource variable=v58 core=ram_t2p_bram

  memcpy(v58, v56, 384 * sizeof(float));	// L91

  for (int v59 = 0; v59 < 384; v59 += 1) {	// L92
    for (int v60 = 0; v60 < 8; v60 += 1) {	// L93
      for (int v61 = 0; v61 < 8; v61 += 1) {	// L94
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v58
        #pragma HLS dependence false variable=v57
        float v62 = v58[v59];	// L95
        v57[0][v59][v60][v61] = v62;	// L96
      }
    }
  }
}

void kernel9(
  float v63[1][1536][8][8],
  float v64[1][1536][8][8]
) {	// L102
  for (int v65 = 0; v65 < 1536; v65 += 1) {	// L103
    for (int v66 = 0; v66 < 8; v66 += 1) {	// L104
      for (int v67 = 0; v67 < 8; v67 += 1) {	// L105
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v63
        #pragma HLS dependence false variable=v64
        float v68 = v63[0][v65][v66][v67];	// L106
        v64[0][v65][v66][v67] = v68;	// L107
      }
    }
  }
}

void kernel10(
  float v69[1][1536][8][8],
  float v70[1][1536][8][8],
  float v71
) {	// L113
  for (int v72 = 0; v72 < 1536; v72 += 1) {	// L114
    for (int v73 = 0; v73 < 8; v73 += 1) {	// L115
      for (int v74 = 0; v74 < 8; v74 += 1) {	// L116
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v70
        #pragma HLS dependence false variable=v69
        float v75 = v70[0][v72][v73][v74];	// L117
        float v76 = v69[0][v72][v73][v74];	// L118
        float v77 = v76 * v71;	// L119
        float v78 = v76 * v75;	// L120
        float v79 = v75 - v78;	// L121
        float v80 = v79 + v77;	// L122
        v70[0][v72][v73][v74] = v80;	// L123
      }
    }
  }
}

void kernel11(
  float v81[1][1536][8][8],
  float v82,
  float v83
) {	// L129
  for (int v84 = 0; v84 < 1536; v84 += 1) {	// L130
    for (int v85 = 0; v85 < 8; v85 += 1) {	// L131
      for (int v86 = 0; v86 < 8; v86 += 1) {	// L132
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v81
        float v87 = v81[0][v84][v85][v86];	// L133
        float v88 = v87 - v83;	// L134
        bool v89 = v88 >= v82;	// L135
        float v90 = v89 ? v83 : v82;	// L136
        v81[0][v84][v85][v86] = v90;	// L137
      }
    }
  }
}

void kernel13(
  float v91[1][1536][8][8],
  float v92[1][1536][8][8],
  float v93
) {	// L143
  for (int v94 = 0; v94 < 1536; v94 += 1) {	// L144
    for (int v95 = 0; v95 < 8; v95 += 1) {	// L145
      for (int v96 = 0; v96 < 8; v96 += 1) {	// L146
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v91
        #pragma HLS dependence false variable=v92
        float v97 = v91[0][v94][v95][v96];	// L147
        float v98 = v92[0][v94][v95][v96];	// L148
        float v99 = v98 / v93;	// L149
        float v100 = v97 / v93;	// L150
        float v101 = v97 - v100;	// L151
        float v102 = v101 + v99;	// L152
        v92[0][v94][v95][v96] = v102;	// L153
      }
    }
  }
}

void kernel14(
  float v103[1][384][8][8],
  float v104[1536][384][1][1],
  float v105[1][1536][8][8]
) {	// L159
  auto v106 = reinterpret_cast<float(*)[384][1][1]>(v104);	// L161

  for (int v107 = 0; v107 < 384; v107 += 1) {	// L162
    for (int v108 = 0; v108 < 1536; v108 += 1) {	// L163
      for (int v109 = 0; v109 < 8; v109 += 1) {	// L164
        for (int v110 = 0; v110 < 8; v110 += 1) {	// L165
          #pragma HLS pipeline II=1
          #pragma HLS dependence false variable=v103
          #pragma HLS dependence false variable=v105
          #pragma HLS dependence false variable=v106
          float v111 = v103[0][v107][v109][v110];	// L166
          float v112 = v106[v108][v107][0][0];	// L167
          float v113 = v105[0][v108][v109][v110];	// L168
          float v114 = v111 * v112;	// L169
          float v115 = v113 + v114;	// L170
          v105[0][v108][v109][v110] = v115;	// L171
        }
      }
    }
  }
}

void kernel15(
  float v116[1536],
  float v117[1][1536][8][8]
) {	// L178
  float v118[1536];	// L179
  #pragma HLS resource variable=v118 core=ram_t2p_bram

  memcpy(v118, v116, 1536 * sizeof(float));	// L180

  for (int v119 = 0; v119 < 1536; v119 += 1) {	// L181
    for (int v120 = 0; v120 < 8; v120 += 1) {	// L182
      for (int v121 = 0; v121 < 8; v121 += 1) {	// L183
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v118
        #pragma HLS dependence false variable=v117
        float v122 = v118[v119];	// L184
        v117[0][v119][v120][v121] = v122;	// L185
      }
    }
  }
}

void kernel16(
  float v123[1][384][8][8],
  float v124[1][384][8][8]
) {	// L191
  for (int v125 = 0; v125 < 384; v125 += 1) {	// L192
    for (int v126 = 0; v126 < 8; v126 += 1) {	// L193
      for (int v127 = 0; v127 < 8; v127 += 1) {	// L194
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v123
        #pragma HLS dependence false variable=v124
        float v128 = v123[0][v125][v126][v127];	// L195
        v124[0][v125][v126][v127] = v128;	// L196
      }
    }
  }
}

void kernel17(
  float v129[1][384][8][8],
  float v130[1][384][8][8],
  float v131
) {	// L202
  for (int v132 = 0; v132 < 384; v132 += 1) {	// L203
    for (int v133 = 0; v133 < 8; v133 += 1) {	// L204
      for (int v134 = 0; v134 < 8; v134 += 1) {	// L205
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v130
        #pragma HLS dependence false variable=v129
        float v135 = v130[0][v132][v133][v134];	// L206
        float v136 = v129[0][v132][v133][v134];	// L207
        float v137 = v136 * v131;	// L208
        float v138 = v136 * v135;	// L209
        float v139 = v135 - v138;	// L210
        float v140 = v139 + v137;	// L211
        v130[0][v132][v133][v134] = v140;	// L212
      }
    }
  }
}

void kernel18(
  float v141[1][384][8][8],
  float v142,
  float v143
) {	// L218
  for (int v144 = 0; v144 < 384; v144 += 1) {	// L219
    for (int v145 = 0; v145 < 8; v145 += 1) {	// L220
      for (int v146 = 0; v146 < 8; v146 += 1) {	// L221
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v141
        float v147 = v141[0][v144][v145][v146];	// L222
        float v148 = v147 - v143;	// L223
        bool v149 = v148 >= v142;	// L224
        float v150 = v149 ? v143 : v142;	// L225
        v141[0][v144][v145][v146] = v150;	// L226
      }
    }
  }
}

void kernel20(
  float v151[1][384][8][8],
  float v152[1][384][8][8],
  float v153[1][384][8][8],
  float v154
) {	// L232
  for (int v155 = 0; v155 < 384; v155 += 1) {	// L233
    for (int v156 = 0; v156 < 8; v156 += 1) {	// L234
      for (int v157 = 0; v157 < 8; v157 += 1) {	// L235
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v151
        #pragma HLS dependence false variable=v153
        #pragma HLS dependence false variable=v152
        float v158 = v151[0][v155][v156][v157];	// L236
        float v159 = v152[0][v155][v156][v157];	// L237
        float v160 = v159 / v154;	// L238
        float v161 = v158 / v154;	// L239
        float v162 = v158 - v161;	// L240
        float v163 = v162 + v160;	// L241
        v153[0][v155][v156][v157] = v163;	// L242
      }
    }
  }
}

void kernel21(
  float v164[1][384][64],
  float v165[1][384][8][8],
  float v166[1][384][8][8]
) {	// L248
  for (int v167 = 0; v167 < 384; v167 += 1) {	// L249
    for (int v168 = 0; v168 < 8; v168 += 1) {	// L250
      for (int v169 = 0; v169 < 8; v169 += 1) {	// L251
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v165
        #pragma HLS dependence false variable=v166
        #pragma HLS dependence false variable=v164
        float v170 = v165[0][v167][v168][v169];	// L252
        float v171 = v164[0][v167][((v168 * 8) + v169)];	// L253
        float v172 = v170 + v171;	// L254
        v166[0][v167][v168][v169] = v172;	// L255
      }
    }
  }
}

void kernel22(
  float v173[1][384][64],
  float v174[384][384][1],
  float v175[1][384][64]
) {	// L261
  auto v176 = reinterpret_cast<float(*)[384][1]>(v174);	// L263

  for (int v177 = 0; v177 < 384; v177 += 1) {	// L264
    for (int v178 = 0; v178 < 384; v178 += 1) {	// L265
      for (int v179 = 0; v179 < 64; v179 += 1) {	// L266
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v173
        #pragma HLS dependence false variable=v175
        #pragma HLS dependence false variable=v176
        float v180 = v173[0][v177][v179];	// L267
        float v181 = v176[v178][v177][0];	// L268
        float v182 = v175[0][v178][v179];	// L269
        float v183 = v180 * v181;	// L270
        float v184 = v182 + v183;	// L271
        v175[0][v178][v179] = v184;	// L272
      }
    }
  }
}

void kernel23(
  float v185[384],
  float v186[1][384][64]
) {	// L278
  float v187[384];	// L279
  #pragma HLS resource variable=v187 core=ram_t2p_bram

  memcpy(v187, v185, 384 * sizeof(float));	// L280

  for (int v188 = 0; v188 < 384; v188 += 1) {	// L281
    for (int v189 = 0; v189 < 64; v189 += 1) {	// L282
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v187
      #pragma HLS dependence false variable=v186
      float v190 = v187[v188];	// L283
      v186[0][v188][v189] = v190;	// L284
    }
  }
}

void kernel24(
  float v191[1][64][384],
  float v192[1][384][64]
) {	// L289
  for (int v193 = 0; v193 < 384; v193 += 1) {	// L290
    for (int v194 = 0; v194 < 64; v194 += 1) {	// L291
      float v195 = v191[0][v194][v193];	// L292
      v192[0][v193][v194] = v195;	// L293
    }
  }
}

void kernel25(
  float v196[1][64][384],
  float v197[1][64][384]
) {	// L298
  for (int v198 = 0; v198 < 64; v198 += 1) {	// L299
    for (int v199 = 0; v199 < 384; v199 += 1) {	// L300
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v196
      #pragma HLS dependence false variable=v197
      float v200 = v196[0][v198][v199];	// L301
      v197[0][v198][v199] = v200;	// L302
    }
  }
}

void kernel26(
  float v201[1][64][12][32],
  float v202[1][64][384],
  float v203[1][64][384],
  float v204
) {	// L307
  for (int v205 = 0; v205 < 64; v205 += 1) {	// L308
    for (int v206 = 0; v206 < 384; v206 += 1) {	// L309
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v201
      #pragma HLS dependence false variable=v203
      #pragma HLS dependence false variable=v202
      float v207 = v201[0][v205][(v206 / 32)][(v206 % 32)];	// L310
      float v208 = v202[0][v205][v206];	// L311
      float v209 = v208 * v204;	// L312
      float v210 = v208 * v207;	// L313
      float v211 = v207 - v210;	// L314
      float v212 = v211 + v209;	// L315
      v203[0][v205][v206] = v212;	// L316
    }
  }
}

void kernel27(
  float v213[1][64][384],
  float v214,
  float v215,
  float v216
) {	// L321
  for (int v217 = 0; v217 < 64; v217 += 1) {	// L322
    for (int v218 = 0; v218 < 384; v218 += 1) {	// L323
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v213
      float v219 = v213[0][v217][v218];	// L324
      float v220 = v219 - v215;	// L325
      bool v221 = v220 >= v216;	// L326
      float v222 = v221 ? v214 : v216;	// L327
      v213[0][v217][v218] = v222;	// L328
    }
  }
}

void kernel28(
  float v223[1][64][12][32],
  float v224[1][64][384]
) {	// L333
  for (int v225 = 0; v225 < 64; v225 += 1) {	// L334
    for (int v226 = 0; v226 < 384; v226 += 1) {	// L335
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v223
      #pragma HLS dependence false variable=v224
      float v227 = v223[0][v225][(v226 / 32)][(v226 % 32)];	// L336
      v224[0][v225][v226] = v227;	// L337
    }
  }
}

void kernel29(
  float v228[1][64][384],
  float v229[1][64][12][32],
  float v230[1][64][12][32],
  float v231
) {	// L342
  for (int v232 = 0; v232 < 64; v232 += 1) {	// L343
    for (int v233 = 0; v233 < 12; v233 += 1) {	// L344
      for (int v234 = 0; v234 < 32; v234 += 1) {	// L345
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v228
        #pragma HLS dependence false variable=v230
        #pragma HLS dependence false variable=v229
        float v235 = v228[0][v232][((v233 * 32) + v234)];	// L346
        float v236 = v229[0][v232][v233][v234];	// L347
        float v237 = v236 / v231;	// L348
        float v238 = v235 / v231;	// L349
        float v239 = v235 - v238;	// L350
        float v240 = v239 + v237;	// L351
        v230[0][v232][v233][v234] = v240;	// L352
      }
    }
  }
}

void kernel30(
  float v241[1][12][64][32],
  float v242[1][64][12][32]
) {	// L358
  for (int v243 = 0; v243 < 64; v243 += 1) {	// L359
    for (int v244 = 0; v244 < 12; v244 += 1) {	// L360
      for (int v245 = 0; v245 < 32; v245 += 1) {	// L361
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v241
        #pragma HLS dependence false variable=v242
        float v246 = v241[0][v244][v243][v245];	// L362
        v242[0][v243][v244][v245] = v246;	// L363
      }
    }
  }
}

void kernel31(
  float v247[1][12][64][32],
  float v248
) {	// L369
  for (int v249 = 0; v249 < 12; v249 += 1) {	// L370
    for (int v250 = 0; v250 < 64; v250 += 1) {	// L371
      for (int v251 = 0; v251 < 32; v251 += 1) {	// L372
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v247
        float v252 = v247[0][v249][v250][v251];	// L373
        float v253 = v252 * v248;	// L374
        v247[0][v249][v250][v251] = v253;	// L375
      }
    }
  }
}

void kernel32(
  float v254[12][64][32],
  float v255[1][12][64][32]
) {	// L381
  for (int v256 = 0; v256 < 12; v256 += 1) {	// L382
    for (int v257 = 0; v257 < 64; v257 += 1) {	// L383
      for (int v258 = 0; v258 < 32; v258 += 1) {	// L384
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v254
        #pragma HLS dependence false variable=v255
        float v259 = v254[v256][v257][v258];	// L385
        v255[0][v256][v257][v258] = v259;	// L386
      }
    }
  }
}

void kernel33(
  float v260[1][1][12][64][32],
  float v261[12][64][64],
  float v262[12][64][32]
) {	// L392
  auto v263 = reinterpret_cast<float(*)[64][64]>(v261);	// L394

  for (int v264 = 0; v264 < 64; v264 += 1) {	// L395
    for (int v265 = 0; v265 < 12; v265 += 1) {	// L396
      for (int v266 = 0; v266 < 64; v266 += 1) {	// L397
        for (int v267 = 0; v267 < 32; v267 += 1) {	// L398
          #pragma HLS pipeline II=1
          #pragma HLS dependence false variable=v263
          #pragma HLS dependence false variable=v260
          #pragma HLS dependence false variable=v262
          float v268 = v263[v265][v266][v264];	// L399
          float v269 = v260[0][0][v265][v264][v267];	// L400
          float v270 = v262[v265][v266][v267];	// L401
          float v271 = v268 * v269;	// L402
          float v272 = v270 + v271;	// L403
          v262[v265][v266][v267] = v272;	// L404
        }
      }
    }
  }
}

void kernel34(
  float v273[12][64][32],
  float v274
) {	// L411
  for (int v275 = 0; v275 < 12; v275 += 1) {	// L412
    for (int v276 = 0; v276 < 64; v276 += 1) {	// L413
      for (int v277 = 0; v277 < 32; v277 += 1) {	// L414
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v273
        v273[v275][v276][v277] = v274;	// L415
      }
    }
  }
}

void kernel35(
  float v278[1][12][64][32],
  float v279[1][1][12][64][32]
) {	// L421
  for (int v280 = 0; v280 < 12; v280 += 1) {	// L422
    for (int v281 = 0; v281 < 64; v281 += 1) {	// L423
      for (int v282 = 0; v282 < 32; v282 += 1) {	// L424
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v278
        #pragma HLS dependence false variable=v279
        float v283 = v278[0][v280][v281][v282];	// L425
        v279[0][0][v280][v281][v282] = v283;	// L426
      }
    }
  }
}

void kernel36(
  float v284[1][1][12][64][32],
  float v285[1][1][12][32][64],
  float v286[12][64][64]
) {	// L432
  auto v287 = reinterpret_cast<float(*)[1][12][64][32]>(v284);	// L434

  for (int v288 = 0; v288 < 32; v288 += 1) {	// L435
    for (int v289 = 0; v289 < 12; v289 += 1) {	// L436
      for (int v290 = 0; v290 < 64; v290 += 1) {	// L437
        for (int v291 = 0; v291 < 64; v291 += 1) {	// L438
          #pragma HLS pipeline II=1
          #pragma HLS dependence false variable=v287
          #pragma HLS dependence false variable=v285
          #pragma HLS dependence false variable=v286
          float v292 = v287[0][0][v289][v290][v288];	// L439
          float v293 = v285[0][0][v289][v288][v291];	// L440
          float v294 = v286[v289][v290][v291];	// L441
          float v295 = v292 * v293;	// L442
          float v296 = v294 + v295;	// L443
          v286[v289][v290][v291] = v296;	// L444
        }
      }
    }
  }
}

void kernel37(
  float v297[1][12][32][64],
  float v298[1][1][12][32][64]
) {	// L451
  for (int v299 = 0; v299 < 12; v299 += 1) {	// L452
    for (int v300 = 0; v300 < 32; v300 += 1) {	// L453
      for (int v301 = 0; v301 < 64; v301 += 1) {	// L454
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v297
        #pragma HLS dependence false variable=v298
        float v302 = v297[0][v299][v300][v301];	// L455
        v298[0][0][v299][v300][v301] = v302;	// L456
      }
    }
  }
}

void kernel39(
  float v303[1][64][12][32],
  float v304[1][12][32][64]
) {	// L462
  for (int v305 = 0; v305 < 12; v305 += 1) {	// L463
    for (int v306 = 0; v306 < 32; v306 += 1) {	// L464
      for (int v307 = 0; v307 < 64; v307 += 1) {	// L465
        float v308 = v303[0][v307][v305][v306];	// L466
        v304[0][v305][v306][v307] = v308;	// L467
      }
    }
  }
}

void kernel40(
  float v309[1][64][12][32],
  float v310[1][12][64][32]
) {	// L473
  for (int v311 = 0; v311 < 12; v311 += 1) {	// L474
    for (int v312 = 0; v312 < 64; v312 += 1) {	// L475
      for (int v313 = 0; v313 < 32; v313 += 1) {	// L476
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v309
        #pragma HLS dependence false variable=v310
        float v314 = v309[0][v312][v311][v313];	// L477
        v310[0][v311][v312][v313] = v314;	// L478
      }
    }
  }
}

void kernel41(
  float v315[1][384][64],
  float v316[1][64][12][32]
) {	// L484
  for (int v317 = 0; v317 < 64; v317 += 1) {	// L485
    for (int v318 = 0; v318 < 12; v318 += 1) {	// L486
      for (int v319 = 0; v319 < 32; v319 += 1) {	// L487
        float v320 = v315[0][((v318 * 32) + v319)][v317];	// L488
        v316[0][v317][v318][v319] = v320;	// L489
      }
    }
  }
}

void kernel42(
  float v321[1][384][64],
  float v322[1][384][64]
) {	// L495
  for (int v323 = 0; v323 < 384; v323 += 1) {	// L496
    for (int v324 = 0; v324 < 64; v324 += 1) {	// L497
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v321
      #pragma HLS dependence false variable=v322
      float v325 = v321[0][v323][v324];	// L498
      v322[0][v323][v324] = v325;	// L499
    }
  }
}

void kernel43(
  float v326[1][384][64],
  float v327[1][384][64],
  float v328
) {	// L504
  for (int v329 = 0; v329 < 384; v329 += 1) {	// L505
    for (int v330 = 0; v330 < 64; v330 += 1) {	// L506
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v327
      #pragma HLS dependence false variable=v326
      float v331 = v327[0][v329][v330];	// L507
      float v332 = v326[0][v329][v330];	// L508
      float v333 = v332 * v328;	// L509
      float v334 = v332 * v331;	// L510
      float v335 = v331 - v334;	// L511
      float v336 = v335 + v333;	// L512
      v327[0][v329][v330] = v336;	// L513
    }
  }
}

void kernel44(
  float v337[1][384][64],
  float v338,
  float v339
) {	// L518
  for (int v340 = 0; v340 < 384; v340 += 1) {	// L519
    for (int v341 = 0; v341 < 64; v341 += 1) {	// L520
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v337
      float v342 = v337[0][v340][v341];	// L521
      float v343 = v342 - v339;	// L522
      bool v344 = v343 >= v338;	// L523
      float v345 = v344 ? v339 : v338;	// L524
      v337[0][v340][v341] = v345;	// L525
    }
  }
}

void kernel46(
  float v346[1][384][64],
  float v347[1][384][64],
  float v348
) {	// L530
  for (int v349 = 0; v349 < 384; v349 += 1) {	// L531
    for (int v350 = 0; v350 < 64; v350 += 1) {	// L532
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v346
      #pragma HLS dependence false variable=v347
      float v351 = v346[0][v349][v350];	// L533
      float v352 = v347[0][v349][v350];	// L534
      float v353 = v352 / v348;	// L535
      float v354 = v351 / v348;	// L536
      float v355 = v351 - v354;	// L537
      float v356 = v355 + v353;	// L538
      v347[0][v349][v350] = v356;	// L539
    }
  }
}

void kernel47(
  float v357[1][384][8][8],
  float v358[384][384][1],
  float v359[1][384][64]
) {	// L544
  auto v360 = reinterpret_cast<float(*)[384][1]>(v358);	// L546

  for (int v361 = 0; v361 < 384; v361 += 1) {	// L547
    for (int v362 = 0; v362 < 384; v362 += 1) {	// L548
      for (int v363 = 0; v363 < 64; v363 += 1) {	// L549
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v357
        #pragma HLS dependence false variable=v359
        #pragma HLS dependence false variable=v360
        float v364 = v357[0][v361][(v363 / 8)][(v363 % 8)];	// L550
        float v365 = v360[v362][v361][0];	// L551
        float v366 = v359[0][v362][v363];	// L552
        float v367 = v364 * v365;	// L553
        float v368 = v366 + v367;	// L554
        v359[0][v362][v363] = v368;	// L555
      }
    }
  }
}

void kernel71(
  float v369[1][384][8][8],
  float v370[1][384][8][8],
  float v371[1][384][8][8]
) {	// L561
  for (int v372 = 0; v372 < 384; v372 += 1) {	// L562
    for (int v373 = 0; v373 < 8; v373 += 1) {	// L563
      for (int v374 = 0; v374 < 8; v374 += 1) {	// L564
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v370
        #pragma HLS dependence false variable=v371
        #pragma HLS dependence false variable=v369
        float v375 = v370[0][v372][v373][v374];	// L565
        float v376 = v369[0][v372][v373][v374];	// L566
        float v377 = v375 + v376;	// L567
        v371[0][v372][v373][v374] = v377;	// L568
      }
    }
  }
}

void kernel99(
  float v378[12][64][32],
  float v379
) {	// L574
  for (int v380 = 0; v380 < 12; v380 += 1) {	// L575
    for (int v381 = 0; v381 < 64; v381 += 1) {	// L576
      for (int v382 = 0; v382 < 32; v382 += 1) {	// L577
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v378
        v378[v380][v381][v382] = v379;	// L578
      }
    }
  }
}

void kernel102(
  float v383[12][64][64],
  float v384[12][64][64]
) {	// L584
  for (int v385 = 0; v385 < 12; v385 += 1) {	// L585
    for (int v386 = 0; v386 < 64; v386 += 1) {	// L586
      for (int v387 = 0; v387 < 64; v387 += 1) {	// L587
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v383
        #pragma HLS dependence false variable=v384
        float v388 = v383[v385][v386][v387];	// L588
        v384[v385][v386][v387] = v388;	// L589
      }
    }
  }
}

void kernel165(
  float v389[12][64][32],
  float v390
) {	// L595
  for (int v391 = 0; v391 < 12; v391 += 1) {	// L596
    for (int v392 = 0; v392 < 64; v392 += 1) {	// L597
      for (int v393 = 0; v393 < 32; v393 += 1) {	// L598
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v389
        v389[v391][v392][v393] = v390;	// L599
      }
    }
  }
}

void kernel231(
  float v394[12][64][32],
  float v395
) {	// L605
  for (int v396 = 0; v396 < 12; v396 += 1) {	// L606
    for (int v397 = 0; v397 < 64; v397 += 1) {	// L607
      for (int v398 = 0; v398 < 32; v398 += 1) {	// L608
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v394
        v394[v396][v397][v398] = v395;	// L609
      }
    }
  }
}

void kernel235(
  float v399[12][64][64],
  float v400
) {	// L615
  for (int v401 = 0; v401 < 12; v401 += 1) {	// L616
    for (int v402 = 0; v402 < 64; v402 += 1) {	// L617
      for (int v403 = 0; v403 < 64; v403 += 1) {	// L618
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v399
        v399[v401][v402][v403] = v400;	// L619
      }
    }
  }
}

void kernel270(
  float v404[1][384][10][10],
  float v405[384][384][3][3],
  float v406[1][384][8][8]
) {	// L625
  auto v407 = reinterpret_cast<float(*)[384][3][3]>(v405);	// L627

  for (int v408 = 0; v408 < 384; v408 += 1) {	// L628
    for (int v409 = 0; v409 < 3; v409 += 1) {	// L629
      for (int v410 = 0; v410 < 3; v410 += 1) {	// L630
        for (int v411 = 0; v411 < 384; v411 += 1) {	// L631
          for (int v412 = 0; v412 < 8; v412 += 1) {	// L632
            for (int v413 = 0; v413 < 8; v413 += 1) {	// L633
              #pragma HLS pipeline II=1
              #pragma HLS dependence false variable=v404
              #pragma HLS dependence false variable=v406
              #pragma HLS dependence false variable=v407
              float v414 = v404[0][v408][(v412 + v409)][(v413 + v410)];	// L634
              float v415 = v407[v411][v408][v409][v410];	// L635
              float v416 = v406[0][v411][v412][v413];	// L636
              float v417 = v414 * v415;	// L637
              float v418 = v416 + v417;	// L638
              v406[0][v411][v412][v413] = v418;	// L639
            }
          }
        }
      }
    }
  }
}

void kernel272(
  float v419[1][384][8][8],
  float v420[1][384][10][10]
) {	// L648
  for (int v421 = 0; v421 < 384; v421 += 1) {	// L649
    for (int v422 = 0; v422 < 8; v422 += 1) {	// L650
      for (int v423 = 0; v423 < 8; v423 += 1) {	// L651
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v419
        #pragma HLS dependence false variable=v420
        float v424 = v419[0][v421][v422][v423];	// L652
        v420[0][v421][(v422 + 1)][(v423 + 1)] = v424;	// L653
      }
    }
  }
}

void kernel273(
  float v425[1][384][10][10],
  float v426
) {	// L659
  for (int v427 = 0; v427 < 384; v427 += 1) {	// L660
    for (int v428 = 0; v428 < 10; v428 += 1) {	// L661
      for (int v429 = 0; v429 < 10; v429 += 1) {	// L662
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v425
        v425[0][v427][v428][v429] = v426;	// L663
      }
    }
  }
}

void kernel274(
  float v430[1][384][18][18],
  float v431[3][3],
  float v432[1][384][8][8]
) {	// L669
  for (int v433 = 0; v433 < 3; v433 += 1) {	// L670
    for (int v434 = 0; v434 < 3; v434 += 1) {	// L671
      for (int v435 = 0; v435 < 384; v435 += 1) {	// L672
        for (int v436 = 0; v436 < 8; v436 += 1) {	// L673
          for (int v437 = 0; v437 < 8; v437 += 1) {	// L674
            #pragma HLS pipeline II=1
            #pragma HLS dependence false variable=v430
            #pragma HLS dependence false variable=v432
            float v438 = v430[0][v435][((v436 * 2) + v433)][((v437 * 2) + v434)];	// L675
            float v439 = v432[0][v435][v436][v437];	// L676
            float v440 = max(v439, v438);	// L677
            v432[0][v435][v436][v437] = v440;	// L678
          }
        }
      }
    }
  }
}

void kernel275(
  float v441[1][384][8][8],
  float v442
) {	// L686
  for (int v443 = 0; v443 < 384; v443 += 1) {	// L687
    for (int v444 = 0; v444 < 8; v444 += 1) {	// L688
      for (int v445 = 0; v445 < 8; v445 += 1) {	// L689
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v441
        v441[0][v443][v444][v445] = v442;	// L690
      }
    }
  }
}

void kernel276(
  float v446[1][384][16][16],
  float v447[1][384][18][18]
) {	// L696
  for (int v448 = 0; v448 < 384; v448 += 1) {	// L697
    for (int v449 = 0; v449 < 16; v449 += 1) {	// L698
      for (int v450 = 0; v450 < 16; v450 += 1) {	// L699
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v446
        #pragma HLS dependence false variable=v447
        float v451 = v446[0][v448][v449][v450];	// L700
        v447[0][v448][(v449 + 1)][(v450 + 1)] = v451;	// L701
      }
    }
  }
}

void kernel277(
  float v452[1][384][18][18],
  float v453
) {	// L707
  for (int v454 = 0; v454 < 384; v454 += 1) {	// L708
    for (int v455 = 0; v455 < 18; v455 += 1) {	// L709
      for (int v456 = 0; v456 < 18; v456 += 1) {	// L710
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v452
        v452[0][v454][v455][v456] = v453;	// L711
      }
    }
  }
}

void kernel278(
  float v457[1][384][16][16],
  float v458[1][384][16][16]
) {	// L717
  for (int v459 = 0; v459 < 384; v459 += 1) {	// L718
    for (int v460 = 0; v460 < 16; v460 += 1) {	// L719
      for (int v461 = 0; v461 < 16; v461 += 1) {	// L720
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v457
        #pragma HLS dependence false variable=v458
        float v462 = v457[0][v459][v460][v461];	// L721
        v458[0][v459][v460][v461] = v462;	// L722
      }
    }
  }
}

void kernel279(
  float v463[1][384][16][16],
  float v464[1][384][16][16],
  float v465
) {	// L728
  for (int v466 = 0; v466 < 384; v466 += 1) {	// L729
    for (int v467 = 0; v467 < 16; v467 += 1) {	// L730
      for (int v468 = 0; v468 < 16; v468 += 1) {	// L731
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v464
        #pragma HLS dependence false variable=v463
        float v469 = v464[0][v466][v467][v468];	// L732
        float v470 = v463[0][v466][v467][v468];	// L733
        float v471 = v470 * v465;	// L734
        float v472 = v470 * v469;	// L735
        float v473 = v469 - v472;	// L736
        float v474 = v473 + v471;	// L737
        v464[0][v466][v467][v468] = v474;	// L738
      }
    }
  }
}

void kernel280(
  float v475[1][384][16][16],
  float v476,
  float v477
) {	// L744
  for (int v478 = 0; v478 < 384; v478 += 1) {	// L745
    for (int v479 = 0; v479 < 16; v479 += 1) {	// L746
      for (int v480 = 0; v480 < 16; v480 += 1) {	// L747
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v475
        float v481 = v475[0][v478][v479][v480];	// L748
        float v482 = v481 - v477;	// L749
        bool v483 = v482 >= v476;	// L750
        float v484 = v483 ? v477 : v476;	// L751
        v475[0][v478][v479][v480] = v484;	// L752
      }
    }
  }
}

void kernel282(
  float v485[1][384][16][16],
  float v486[1][384][16][16],
  float v487
) {	// L758
  for (int v488 = 0; v488 < 384; v488 += 1) {	// L759
    for (int v489 = 0; v489 < 16; v489 += 1) {	// L760
      for (int v490 = 0; v490 < 16; v490 += 1) {	// L761
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v485
        #pragma HLS dependence false variable=v486
        float v491 = v485[0][v488][v489][v490];	// L762
        float v492 = v486[0][v488][v489][v490];	// L763
        float v493 = v492 / v487;	// L764
        float v494 = v491 / v487;	// L765
        float v495 = v491 - v494;	// L766
        float v496 = v495 + v493;	// L767
        v486[0][v488][v489][v490] = v496;	// L768
      }
    }
  }
}

void kernel283(
  float v497[1][192][18][18],
  float v498[384][192][3][3],
  float v499[1][384][16][16]
) {	// L774
  auto v500 = reinterpret_cast<float(*)[192][3][3]>(v498);	// L776

  for (int v501 = 0; v501 < 192; v501 += 1) {	// L777
    for (int v502 = 0; v502 < 3; v502 += 1) {	// L778
      for (int v503 = 0; v503 < 3; v503 += 1) {	// L779
        for (int v504 = 0; v504 < 384; v504 += 1) {	// L780
          for (int v505 = 0; v505 < 16; v505 += 1) {	// L781
            for (int v506 = 0; v506 < 16; v506 += 1) {	// L782
              #pragma HLS pipeline II=1
              #pragma HLS dependence false variable=v497
              #pragma HLS dependence false variable=v499
              #pragma HLS dependence false variable=v500
              float v507 = v497[0][v501][(v505 + v502)][(v506 + v503)];	// L783
              float v508 = v500[v504][v501][v502][v503];	// L784
              float v509 = v499[0][v504][v505][v506];	// L785
              float v510 = v507 * v508;	// L786
              float v511 = v509 + v510;	// L787
              v499[0][v504][v505][v506] = v511;	// L788
            }
          }
        }
      }
    }
  }
}

void kernel284(
  float v512[384],
  float v513[1][384][16][16]
) {	// L797
  float v514[384];	// L798
  #pragma HLS resource variable=v514 core=ram_t2p_bram

  memcpy(v514, v512, 384 * sizeof(float));	// L799

  for (int v515 = 0; v515 < 384; v515 += 1) {	// L800
    for (int v516 = 0; v516 < 16; v516 += 1) {	// L801
      for (int v517 = 0; v517 < 16; v517 += 1) {	// L802
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v514
        #pragma HLS dependence false variable=v513
        float v518 = v514[v515];	// L803
        v513[0][v515][v516][v517] = v518;	// L804
      }
    }
  }
}

void kernel285(
  float v519[1][192][16][16],
  float v520[1][192][18][18]
) {	// L810
  for (int v521 = 0; v521 < 192; v521 += 1) {	// L811
    for (int v522 = 0; v522 < 16; v522 += 1) {	// L812
      for (int v523 = 0; v523 < 16; v523 += 1) {	// L813
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v519
        #pragma HLS dependence false variable=v520
        float v524 = v519[0][v521][v522][v523];	// L814
        v520[0][v521][(v522 + 1)][(v523 + 1)] = v524;	// L815
      }
    }
  }
}

void kernel286(
  float v525[1][192][18][18],
  float v526
) {	// L821
  for (int v527 = 0; v527 < 192; v527 += 1) {	// L822
    for (int v528 = 0; v528 < 18; v528 += 1) {	// L823
      for (int v529 = 0; v529 < 18; v529 += 1) {	// L824
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v525
        v525[0][v527][v528][v529] = v526;	// L825
      }
    }
  }
}

void kernel287(
  float v530[1][192][34][34],
  float v531[3][3],
  float v532[1][192][16][16]
) {	// L831
  for (int v533 = 0; v533 < 3; v533 += 1) {	// L832
    for (int v534 = 0; v534 < 3; v534 += 1) {	// L833
      for (int v535 = 0; v535 < 192; v535 += 1) {	// L834
        for (int v536 = 0; v536 < 16; v536 += 1) {	// L835
          for (int v537 = 0; v537 < 16; v537 += 1) {	// L836
            #pragma HLS pipeline II=1
            #pragma HLS dependence false variable=v530
            #pragma HLS dependence false variable=v532
            float v538 = v530[0][v535][((v536 * 2) + v533)][((v537 * 2) + v534)];	// L837
            float v539 = v532[0][v535][v536][v537];	// L838
            float v540 = max(v539, v538);	// L839
            v532[0][v535][v536][v537] = v540;	// L840
          }
        }
      }
    }
  }
}

void kernel288(
  float v541[1][192][16][16],
  float v542
) {	// L848
  for (int v543 = 0; v543 < 192; v543 += 1) {	// L849
    for (int v544 = 0; v544 < 16; v544 += 1) {	// L850
      for (int v545 = 0; v545 < 16; v545 += 1) {	// L851
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v541
        v541[0][v543][v544][v545] = v542;	// L852
      }
    }
  }
}

void kernel289(
  float v546[1][192][32][32],
  float v547[1][192][34][34]
) {	// L858
  for (int v548 = 0; v548 < 192; v548 += 1) {	// L859
    for (int v549 = 0; v549 < 32; v549 += 1) {	// L860
      for (int v550 = 0; v550 < 32; v550 += 1) {	// L861
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v546
        #pragma HLS dependence false variable=v547
        float v551 = v546[0][v548][v549][v550];	// L862
        v547[0][v548][(v549 + 1)][(v550 + 1)] = v551;	// L863
      }
    }
  }
}

void kernel290(
  float v552[1][192][34][34],
  float v553
) {	// L869
  for (int v554 = 0; v554 < 192; v554 += 1) {	// L870
    for (int v555 = 0; v555 < 34; v555 += 1) {	// L871
      for (int v556 = 0; v556 < 34; v556 += 1) {	// L872
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v552
        v552[0][v554][v555][v556] = v553;	// L873
      }
    }
  }
}

void kernel291(
  float v557[1][192][32][32],
  float v558[1][192][32][32]
) {	// L879
  for (int v559 = 0; v559 < 192; v559 += 1) {	// L880
    for (int v560 = 0; v560 < 32; v560 += 1) {	// L881
      for (int v561 = 0; v561 < 32; v561 += 1) {	// L882
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v557
        #pragma HLS dependence false variable=v558
        float v562 = v557[0][v559][v560][v561];	// L883
        v558[0][v559][v560][v561] = v562;	// L884
      }
    }
  }
}

void kernel292(
  float v563[1][192][32][32],
  float v564[1][192][32][32],
  float v565
) {	// L890
  for (int v566 = 0; v566 < 192; v566 += 1) {	// L891
    for (int v567 = 0; v567 < 32; v567 += 1) {	// L892
      for (int v568 = 0; v568 < 32; v568 += 1) {	// L893
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v564
        #pragma HLS dependence false variable=v563
        float v569 = v564[0][v566][v567][v568];	// L894
        float v570 = v563[0][v566][v567][v568];	// L895
        float v571 = v570 * v565;	// L896
        float v572 = v570 * v569;	// L897
        float v573 = v569 - v572;	// L898
        float v574 = v573 + v571;	// L899
        v564[0][v566][v567][v568] = v574;	// L900
      }
    }
  }
}

void kernel293(
  float v575[1][192][32][32],
  float v576,
  float v577
) {	// L906
  for (int v578 = 0; v578 < 192; v578 += 1) {	// L907
    for (int v579 = 0; v579 < 32; v579 += 1) {	// L908
      for (int v580 = 0; v580 < 32; v580 += 1) {	// L909
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v575
        float v581 = v575[0][v578][v579][v580];	// L910
        float v582 = v581 - v577;	// L911
        bool v583 = v582 >= v576;	// L912
        float v584 = v583 ? v577 : v576;	// L913
        v575[0][v578][v579][v580] = v584;	// L914
      }
    }
  }
}

void kernel295(
  float v585[1][192][32][32],
  float v586[1][192][32][32],
  float v587
) {	// L920
  for (int v588 = 0; v588 < 192; v588 += 1) {	// L921
    for (int v589 = 0; v589 < 32; v589 += 1) {	// L922
      for (int v590 = 0; v590 < 32; v590 += 1) {	// L923
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v585
        #pragma HLS dependence false variable=v586
        float v591 = v585[0][v588][v589][v590];	// L924
        float v592 = v586[0][v588][v589][v590];	// L925
        float v593 = v592 / v587;	// L926
        float v594 = v591 / v587;	// L927
        float v595 = v591 - v594;	// L928
        float v596 = v595 + v593;	// L929
        v586[0][v588][v589][v590] = v596;	// L930
      }
    }
  }
}

void kernel296(
  float v597[1][96][34][34],
  float v598[192][96][3][3],
  float v599[1][192][32][32]
) {	// L936
  auto v600 = reinterpret_cast<float(*)[96][3][3]>(v598);	// L938

  for (int v601 = 0; v601 < 96; v601 += 1) {	// L939
    for (int v602 = 0; v602 < 3; v602 += 1) {	// L940
      for (int v603 = 0; v603 < 3; v603 += 1) {	// L941
        for (int v604 = 0; v604 < 192; v604 += 1) {	// L942
          for (int v605 = 0; v605 < 32; v605 += 1) {	// L943
            for (int v606 = 0; v606 < 32; v606 += 1) {	// L944
              #pragma HLS pipeline II=1
              #pragma HLS dependence false variable=v597
              #pragma HLS dependence false variable=v599
              #pragma HLS dependence false variable=v600
              float v607 = v597[0][v601][(v605 + v602)][(v606 + v603)];	// L945
              float v608 = v600[v604][v601][v602][v603];	// L946
              float v609 = v599[0][v604][v605][v606];	// L947
              float v610 = v607 * v608;	// L948
              float v611 = v609 + v610;	// L949
              v599[0][v604][v605][v606] = v611;	// L950
            }
          }
        }
      }
    }
  }
}

void kernel297(
  float v612[192],
  float v613[1][192][32][32]
) {	// L959
  float v614[192];	// L960
  #pragma HLS resource variable=v614 core=ram_t2p_bram

  memcpy(v614, v612, 192 * sizeof(float));	// L961

  for (int v615 = 0; v615 < 192; v615 += 1) {	// L962
    for (int v616 = 0; v616 < 32; v616 += 1) {	// L963
      for (int v617 = 0; v617 < 32; v617 += 1) {	// L964
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v614
        #pragma HLS dependence false variable=v613
        float v618 = v614[v615];	// L965
        v613[0][v615][v616][v617] = v618;	// L966
      }
    }
  }
}

void kernel298(
  float v619[1][96][32][32],
  float v620[1][96][34][34]
) {	// L972
  for (int v621 = 0; v621 < 96; v621 += 1) {	// L973
    for (int v622 = 0; v622 < 32; v622 += 1) {	// L974
      for (int v623 = 0; v623 < 32; v623 += 1) {	// L975
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v619
        #pragma HLS dependence false variable=v620
        float v624 = v619[0][v621][v622][v623];	// L976
        v620[0][v621][(v622 + 1)][(v623 + 1)] = v624;	// L977
      }
    }
  }
}

void kernel299(
  float v625[1][96][34][34],
  float v626
) {	// L983
  for (int v627 = 0; v627 < 96; v627 += 1) {	// L984
    for (int v628 = 0; v628 < 34; v628 += 1) {	// L985
      for (int v629 = 0; v629 < 34; v629 += 1) {	// L986
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v625
        v625[0][v627][v628][v629] = v626;	// L987
      }
    }
  }
}

void kernel300(
  float v630[1][96][32][32],
  float v631[1][96][32][32]
) {	// L993
  for (int v632 = 0; v632 < 96; v632 += 1) {	// L994
    for (int v633 = 0; v633 < 32; v633 += 1) {	// L995
      for (int v634 = 0; v634 < 32; v634 += 1) {	// L996
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v630
        #pragma HLS dependence false variable=v631
        float v635 = v630[0][v632][v633][v634];	// L997
        v631[0][v632][v633][v634] = v635;	// L998
      }
    }
  }
}

void kernel301(
  float v636[1][96][32][32],
  float v637[1][96][32][32],
  float v638
) {	// L1004
  for (int v639 = 0; v639 < 96; v639 += 1) {	// L1005
    for (int v640 = 0; v640 < 32; v640 += 1) {	// L1006
      for (int v641 = 0; v641 < 32; v641 += 1) {	// L1007
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v637
        #pragma HLS dependence false variable=v636
        float v642 = v637[0][v639][v640][v641];	// L1008
        float v643 = v636[0][v639][v640][v641];	// L1009
        float v644 = v643 * v638;	// L1010
        float v645 = v643 * v642;	// L1011
        float v646 = v642 - v645;	// L1012
        float v647 = v646 + v644;	// L1013
        v637[0][v639][v640][v641] = v647;	// L1014
      }
    }
  }
}

void kernel302(
  float v648[1][96][32][32],
  float v649,
  float v650
) {	// L1020
  for (int v651 = 0; v651 < 96; v651 += 1) {	// L1021
    for (int v652 = 0; v652 < 32; v652 += 1) {	// L1022
      for (int v653 = 0; v653 < 32; v653 += 1) {	// L1023
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v648
        float v654 = v648[0][v651][v652][v653];	// L1024
        float v655 = v654 - v650;	// L1025
        bool v656 = v655 >= v649;	// L1026
        float v657 = v656 ? v650 : v649;	// L1027
        v648[0][v651][v652][v653] = v657;	// L1028
      }
    }
  }
}

void kernel304(
  float v658[1][96][32][32],
  float v659[1][96][32][32],
  float v660
) {	// L1034
  for (int v661 = 0; v661 < 96; v661 += 1) {	// L1035
    for (int v662 = 0; v662 < 32; v662 += 1) {	// L1036
      for (int v663 = 0; v663 < 32; v663 += 1) {	// L1037
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v658
        #pragma HLS dependence false variable=v659
        float v664 = v658[0][v661][v662][v663];	// L1038
        float v665 = v659[0][v661][v662][v663];	// L1039
        float v666 = v665 / v660;	// L1040
        float v667 = v664 / v660;	// L1041
        float v668 = v664 - v667;	// L1042
        float v669 = v668 + v666;	// L1043
        v659[0][v661][v662][v663] = v669;	// L1044
      }
    }
  }
}

void kernel305(
  float v670[1][48][34][34],
  float v671[96][48][3][3],
  float v672[1][96][32][32]
) {	// L1050
  auto v673 = reinterpret_cast<float(*)[48][3][3]>(v671);	// L1052

  for (int v674 = 0; v674 < 48; v674 += 1) {	// L1053
    for (int v675 = 0; v675 < 3; v675 += 1) {	// L1054
      for (int v676 = 0; v676 < 3; v676 += 1) {	// L1055
        for (int v677 = 0; v677 < 96; v677 += 1) {	// L1056
          for (int v678 = 0; v678 < 32; v678 += 1) {	// L1057
            for (int v679 = 0; v679 < 32; v679 += 1) {	// L1058
              #pragma HLS pipeline II=1
              #pragma HLS dependence false variable=v670
              #pragma HLS dependence false variable=v672
              #pragma HLS dependence false variable=v673
              float v680 = v670[0][v674][(v678 + v675)][(v679 + v676)];	// L1059
              float v681 = v673[v677][v674][v675][v676];	// L1060
              float v682 = v672[0][v677][v678][v679];	// L1061
              float v683 = v680 * v681;	// L1062
              float v684 = v682 + v683;	// L1063
              v672[0][v677][v678][v679] = v684;	// L1064
            }
          }
        }
      }
    }
  }
}

void kernel306(
  float v685[96],
  float v686[1][96][32][32]
) {	// L1073
  float v687[96];	// L1074
  #pragma HLS resource variable=v687 core=ram_t2p_bram

  memcpy(v687, v685, 96 * sizeof(float));	// L1075

  for (int v688 = 0; v688 < 96; v688 += 1) {	// L1076
    for (int v689 = 0; v689 < 32; v689 += 1) {	// L1077
      for (int v690 = 0; v690 < 32; v690 += 1) {	// L1078
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v687
        #pragma HLS dependence false variable=v686
        float v691 = v687[v688];	// L1079
        v686[0][v688][v689][v690] = v691;	// L1080
      }
    }
  }
}

void kernel307(
  float v692[1][48][32][32],
  float v693[1][48][34][34]
) {	// L1086
  for (int v694 = 0; v694 < 48; v694 += 1) {	// L1087
    for (int v695 = 0; v695 < 32; v695 += 1) {	// L1088
      for (int v696 = 0; v696 < 32; v696 += 1) {	// L1089
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v692
        #pragma HLS dependence false variable=v693
        float v697 = v692[0][v694][v695][v696];	// L1090
        v693[0][v694][(v695 + 1)][(v696 + 1)] = v697;	// L1091
      }
    }
  }
}

void kernel308(
  float v698[1][48][34][34],
  float v699
) {	// L1097
  for (int v700 = 0; v700 < 48; v700 += 1) {	// L1098
    for (int v701 = 0; v701 < 34; v701 += 1) {	// L1099
      for (int v702 = 0; v702 < 34; v702 += 1) {	// L1100
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v698
        v698[0][v700][v701][v702] = v699;	// L1101
      }
    }
  }
}

void kernel309(
  float v703[1][48][32][32],
  float v704[1][48][32][32]
) {	// L1107
  for (int v705 = 0; v705 < 48; v705 += 1) {	// L1108
    for (int v706 = 0; v706 < 32; v706 += 1) {	// L1109
      for (int v707 = 0; v707 < 32; v707 += 1) {	// L1110
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v703
        #pragma HLS dependence false variable=v704
        float v708 = v703[0][v705][v706][v707];	// L1111
        v704[0][v705][v706][v707] = v708;	// L1112
      }
    }
  }
}

void kernel310(
  float v709[1][48][32][32],
  float v710[1][48][32][32],
  float v711
) {	// L1118
  for (int v712 = 0; v712 < 48; v712 += 1) {	// L1119
    for (int v713 = 0; v713 < 32; v713 += 1) {	// L1120
      for (int v714 = 0; v714 < 32; v714 += 1) {	// L1121
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v710
        #pragma HLS dependence false variable=v709
        float v715 = v710[0][v712][v713][v714];	// L1122
        float v716 = v709[0][v712][v713][v714];	// L1123
        float v717 = v716 * v711;	// L1124
        float v718 = v716 * v715;	// L1125
        float v719 = v715 - v718;	// L1126
        float v720 = v719 + v717;	// L1127
        v710[0][v712][v713][v714] = v720;	// L1128
      }
    }
  }
}

void kernel311(
  float v721[1][48][32][32],
  float v722,
  float v723
) {	// L1134
  for (int v724 = 0; v724 < 48; v724 += 1) {	// L1135
    for (int v725 = 0; v725 < 32; v725 += 1) {	// L1136
      for (int v726 = 0; v726 < 32; v726 += 1) {	// L1137
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v721
        float v727 = v721[0][v724][v725][v726];	// L1138
        float v728 = v727 - v723;	// L1139
        bool v729 = v728 >= v722;	// L1140
        float v730 = v729 ? v723 : v722;	// L1141
        v721[0][v724][v725][v726] = v730;	// L1142
      }
    }
  }
}

void kernel313(
  float v731[1][48][32][32],
  float v732[1][48][32][32],
  float v733
) {	// L1148
  for (int v734 = 0; v734 < 48; v734 += 1) {	// L1149
    for (int v735 = 0; v735 < 32; v735 += 1) {	// L1150
      for (int v736 = 0; v736 < 32; v736 += 1) {	// L1151
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v731
        #pragma HLS dependence false variable=v732
        float v737 = v731[0][v734][v735][v736];	// L1152
        float v738 = v732[0][v734][v735][v736];	// L1153
        float v739 = v738 / v733;	// L1154
        float v740 = v737 / v733;	// L1155
        float v741 = v737 - v740;	// L1156
        float v742 = v741 + v739;	// L1157
        v732[0][v734][v735][v736] = v742;	// L1158
      }
    }
  }
}

void kernel314(
  float v743[1][3][34][34],
  float v744[48][3][3][3],
  float v745[1][48][32][32]
) {	// L1164
  float v746[48][3][3][3];	// L1165
  #pragma HLS resource variable=v746 core=ram_t2p_bram

  memcpy(v746, v744, 1296 * sizeof(float));	// L1166

  for (int v747 = 0; v747 < 3; v747 += 1) {	// L1167
    for (int v748 = 0; v748 < 3; v748 += 1) {	// L1168
      for (int v749 = 0; v749 < 3; v749 += 1) {	// L1169
        for (int v750 = 0; v750 < 48; v750 += 1) {	// L1170
          for (int v751 = 0; v751 < 32; v751 += 1) {	// L1171
            for (int v752 = 0; v752 < 32; v752 += 1) {	// L1172
              #pragma HLS pipeline II=1
              #pragma HLS dependence false variable=v743
              #pragma HLS dependence false variable=v745
              #pragma HLS dependence false variable=v746
              float v753 = v743[0][v747][(v751 + v748)][(v752 + v749)];	// L1173
              float v754 = v746[v750][v747][v748][v749];	// L1174
              float v755 = v745[0][v750][v751][v752];	// L1175
              float v756 = v753 * v754;	// L1176
              float v757 = v755 + v756;	// L1177
              v745[0][v750][v751][v752] = v757;	// L1178
            }
          }
        }
      }
    }
  }
}

void kernel315(
  float v758[48],
  float v759[1][48][32][32]
) {	// L1187
  float v760[48];	// L1188
  #pragma HLS resource variable=v760 core=ram_t2p_bram

  memcpy(v760, v758, 48 * sizeof(float));	// L1189

  for (int v761 = 0; v761 < 48; v761 += 1) {	// L1190
    for (int v762 = 0; v762 < 32; v762 += 1) {	// L1191
      for (int v763 = 0; v763 < 32; v763 += 1) {	// L1192
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v760
        #pragma HLS dependence false variable=v759
        float v764 = v760[v761];	// L1193
        v759[0][v761][v762][v763] = v764;	// L1194
      }
    }
  }
}

void kernel316(
  float v765[1][3][32][32],
  float v766[1][3][34][34]
) {	// L1200
  for (int v767 = 0; v767 < 3; v767 += 1) {	// L1201
    for (int v768 = 0; v768 < 32; v768 += 1) {	// L1202
      for (int v769 = 0; v769 < 32; v769 += 1) {	// L1203
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v765
        #pragma HLS dependence false variable=v766
        float v770 = v765[0][v767][v768][v769];	// L1204
        v766[0][v767][(v768 + 1)][(v769 + 1)] = v770;	// L1205
      }
    }
  }
}

void kernel317(
  float v771[1][3][34][34],
  float v772
) {	// L1211
  for (int v773 = 0; v773 < 3; v773 += 1) {	// L1212
    for (int v774 = 0; v774 < 34; v774 += 1) {	// L1213
      for (int v775 = 0; v775 < 34; v775 += 1) {	// L1214
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v771
        v771[0][v773][v774][v775] = v772;	// L1215
      }
    }
  }
}

/// The top function
void control(
  ap_int<32> v776[89418240],
  ap_int<32> v777[89418240],
  ap_int<32> v778[89418240]
) {	// L1221
  #pragma HLS interface s_axilite port=return bundle=ctrl
  #pragma hls interface m_axi offset=direct bundle=g0 port=v776
  #pragma hls stable variable=v776
  #pragma hls interface m_axi offset=direct bundle=g0 port=v777
  #pragma hls stable variable=v777
  #pragma hls interface m_axi offset=direct bundle=g0 port=v778
  #pragma hls stable variable=v778

  auto v779 = reinterpret_cast<float(*)[3][34][34]>(v777 + 6684672);
  kernel317(v779, (float)0.000000);	// L1230
  auto v780 = reinterpret_cast<float(*)[3][32][32]>(v776);
  kernel316(v780, v779);	// L1232
  auto v781 = reinterpret_cast<float(*)[48][32][32]>(v776 + 6906624);
  auto v782 = reinterpret_cast<float(*)>(v778 + 86764032);
  kernel315(v782, v781);	// L1235
  auto v783 = reinterpret_cast<float(*)[3][3][3]>(v778 + 88091136);
  kernel314(v779, v783, v781);	// L1237
  auto v784 = reinterpret_cast<float(*)[48][32][32]>(v776 + 196608);
  kernel313(v784, v781, (float)2.000000);	// L1239
  auto v785 = reinterpret_cast<float(*)[48][32][32]>(v777 + 6684672);
  kernel309(v781, v785);	// L1241
  kernel311(v785, (float)0.000000, (float)1.000000);	// L1242
  kernel310(v785, v781, (float)0.000000);	// L1243
  kernel309(v781, v784);	// L1244
  auto v786 = reinterpret_cast<float(*)[48][34][34]>(v776 + 6906624);
  kernel308(v786, (float)0.000000);	// L1246
  kernel307(v785, v786);	// L1247
  auto v787 = reinterpret_cast<float(*)[96][32][32]>(v777 + 6684672);
  auto v788 = reinterpret_cast<float(*)>(v778 + 84109824);
  kernel306(v788, v787);	// L1250
  auto v789 = reinterpret_cast<float(*)[48][3][3]>(v778 + 85436928);
  kernel305(v786, v789, v787);	// L1252
  auto v790 = reinterpret_cast<float(*)[96][32][32]>(v776 + 393216);
  kernel304(v790, v787, (float)2.000000);	// L1254
  auto v791 = reinterpret_cast<float(*)[96][32][32]>(v776 + 6906624);
  kernel300(v787, v791);	// L1256
  kernel302(v791, (float)0.000000, (float)1.000000);	// L1257
  kernel301(v791, v787, (float)0.000000);	// L1258
  kernel300(v787, v790);	// L1259
  auto v792 = reinterpret_cast<float(*)[96][34][34]>(v777 + 6684672);
  kernel299(v792, (float)0.000000);	// L1261
  kernel298(v791, v792);	// L1262
  auto v793 = reinterpret_cast<float(*)[192][32][32]>(v776 + 6906624);
  auto v794 = reinterpret_cast<float(*)>(v778 + 81455616);
  kernel297(v794, v793);	// L1265
  auto v795 = reinterpret_cast<float(*)[96][3][3]>(v778 + 82782720);
  kernel296(v792, v795, v793);	// L1267
  auto v796 = reinterpret_cast<float(*)[192][32][32]>(v776 + 589824);
  kernel295(v796, v793, (float)2.000000);	// L1269
  auto v797 = reinterpret_cast<float(*)[192][32][32]>(v776 + 6684672);
  kernel291(v793, v797);	// L1271
  kernel293(v797, (float)0.000000, (float)1.000000);	// L1272
  kernel292(v797, v793, (float)0.000000);	// L1273
  kernel291(v793, v796);	// L1274
  auto v798 = reinterpret_cast<float(*)[192][34][34]>(v776 + 6906624);
  kernel290(v798, (float)-INFINITY);	// L1276
  kernel289(v797, v798);	// L1277
  auto v799 = reinterpret_cast<float(*)[192][16][16]>(v777 + 6684672);
  kernel288(v799, (float)-INFINITY);	// L1279
  auto v800 = reinterpret_cast<float(*)[3]>(v778 + 7128576);
  kernel287(v798, v800, v799);	// L1281
  auto v801 = reinterpret_cast<float(*)[192][18][18]>(v776 + 6906624);
  kernel286(v801, (float)0.000000);	// L1283
  kernel285(v799, v801);	// L1284
  auto v802 = reinterpret_cast<float(*)[384][16][16]>(v777 + 6684672);
  auto v803 = reinterpret_cast<float(*)>(v778 + 78801408);
  kernel284(v803, v802);	// L1287
  auto v804 = reinterpret_cast<float(*)[192][3][3]>(v778 + 80128512);
  kernel283(v801, v804, v802);	// L1289
  auto v805 = reinterpret_cast<float(*)[384][16][16]>(v776 + 786432);
  kernel282(v805, v802, (float)2.000000);	// L1291
  auto v806 = reinterpret_cast<float(*)[384][16][16]>(v776 + 6906624);
  kernel278(v802, v806);	// L1293
  kernel280(v806, (float)0.000000, (float)1.000000);	// L1294
  kernel279(v806, v802, (float)0.000000);	// L1295
  kernel278(v802, v805);	// L1296
  auto v807 = reinterpret_cast<float(*)[384][18][18]>(v777 + 6684672);
  kernel277(v807, (float)-INFINITY);	// L1298
  kernel276(v806, v807);	// L1299
  auto v808 = reinterpret_cast<float(*)[384][8][8]>(v776 + 6906624);
  kernel275(v808, (float)-INFINITY);	// L1301
  kernel274(v807, v800, v808);	// L1302
  auto v809 = reinterpret_cast<float(*)[384][10][10]>(v777 + 6684672);
  kernel273(v809, (float)0.000000);	// L1304
  kernel272(v808, v809);	// L1305
  auto v810 = reinterpret_cast<float(*)[384][8][8]>(v776 + 7128576);
  auto v811 = reinterpret_cast<float(*)>(v778 + 76147200);
  kernel8(v811, v810);	// L1308
  auto v812 = reinterpret_cast<float(*)[384][3][3]>(v778 + 77474304);
  kernel270(v809, v812, v810);	// L1310
  auto v813 = reinterpret_cast<float(*)[384][8][8]>(v776 + 983040);
  kernel20(v813, v810, v808, (float)2.000000);	// L1312
  auto v814 = reinterpret_cast<float(*)[384][8][8]>(v777 + 6684672);
  kernel16(v808, v814);	// L1314
  kernel18(v814, (float)0.000000, (float)1.000000);	// L1315
  kernel17(v814, v808, (float)0.000000);	// L1316
  kernel16(v808, v813);	// L1317
  auto v815 = reinterpret_cast<float(*)[384][64]>(v776 + 7350528);
  auto v816 = reinterpret_cast<float(*)>(v778 + 73492992);
  kernel23(v816, v815);	// L1320
  auto v817 = reinterpret_cast<float(*)[384][1]>(v778 + 74820096);
  kernel47(v814, v817, v815);	// L1322
  auto v818 = reinterpret_cast<float(*)[384][64]>(v776 + 1179648);
  kernel46(v818, v815, (float)2.000000);	// L1324
  auto v819 = reinterpret_cast<float(*)[384][64]>(v776 + 7572480);
  kernel42(v815, v819);	// L1326
  kernel44(v819, (float)0.000000, (float)1.000000);	// L1327
  kernel43(v819, v815, (float)0.000000);	// L1328
  kernel42(v815, v818);	// L1329
  auto v820 = reinterpret_cast<float(*)[64][12][32]>(v777 + 7794432);
  kernel41(v819, v820);	// L1331
  auto v821 = reinterpret_cast<float(*)[12][64][32]>(v776 + 7572480);
  kernel40(v820, v821);	// L1333
  auto v822 = reinterpret_cast<float(*)>(v778 + 70838784);
  kernel23(v822, v815);	// L1335
  auto v823 = reinterpret_cast<float(*)[384][1]>(v778 + 72165888);
  kernel47(v814, v823, v815);	// L1337
  auto v824 = reinterpret_cast<float(*)[384][64]>(v776 + 1376256);
  kernel46(v824, v815, (float)2.000000);	// L1339
  auto v825 = reinterpret_cast<float(*)[384][64]>(v776 + 7794432);
  kernel42(v815, v825);	// L1341
  kernel44(v825, (float)0.000000, (float)1.000000);	// L1342
  kernel43(v825, v815, (float)0.000000);	// L1343
  kernel42(v815, v824);	// L1344
  auto v826 = reinterpret_cast<float(*)[64][12][32]>(v777 + 8016384);
  kernel41(v825, v826);	// L1346
  auto v827 = reinterpret_cast<float(*)>(v778 + 68184576);
  kernel23(v827, v815);	// L1348
  auto v828 = reinterpret_cast<float(*)[384][1]>(v778 + 69511680);
  kernel47(v814, v828, v815);	// L1350
  auto v829 = reinterpret_cast<float(*)[384][64]>(v776 + 1572864);
  kernel46(v829, v815, (float)2.000000);	// L1352
  auto v830 = reinterpret_cast<float(*)[384][64]>(v776 + 6684672);
  kernel42(v815, v830);	// L1354
  kernel44(v830, (float)0.000000, (float)1.000000);	// L1355
  kernel43(v830, v815, (float)0.000000);	// L1356
  kernel42(v815, v829);	// L1357
  kernel41(v830, v820);	// L1358
  auto v831 = reinterpret_cast<float(*)[12][64][32]>(v776 + 8238336);
  kernel40(v820, v831);	// L1360
  auto v832 = reinterpret_cast<float(*)[12][32][64]>(v776 + 6684672);
  kernel39(v826, v832);	// L1362
  auto v833 = reinterpret_cast<float(*)[1][12][64][32]>(v777 + 7794432);
  kernel35(v821, v833);	// L1364
  auto v834 = reinterpret_cast<float(*)[1][12][32][64]>(v778 + 7572480);
  kernel37(v832, v834);	// L1366
  auto v835 = reinterpret_cast<float(*)[64][64]>(v776 + 8016384);
  kernel235(v835, (float)0.000000);	// L1368
  auto v836 = reinterpret_cast<float(*)[64][64]>(v776 + 8460288);
  kernel102(v835, v836);	// L1370
  kernel36(v833, v834, v836);	// L1371
  auto v837 = reinterpret_cast<float(*)[1][12][64][32]>(v777 + 7572480);
  kernel35(v831, v837);	// L1373
  auto v838 = reinterpret_cast<float(*)[64][32]>(v777 + 7794432);
  kernel231(v838, (float)0.000000);	// L1375
  kernel33(v837, v836, v838);	// L1376
  kernel32(v838, v831);	// L1377
  kernel31(v831, (float)0.125000);	// L1378
  auto v839 = reinterpret_cast<float(*)[64][12][32]>(v777 + 7572480);
  kernel30(v831, v839);	// L1380
  auto v840 = reinterpret_cast<float(*)[64][384]>(v776 + 1769472);
  auto v841 = reinterpret_cast<float(*)[64][12][32]>(v776 + 8460288);
  kernel29(v840, v839, v841, (float)2.000000);	// L1383
  auto v842 = reinterpret_cast<float(*)[64][384]>(v777 + 8682240);
  kernel28(v841, v842);	// L1385
  kernel27(v842, (float)1.000000, (float)0.500000, (float)0.000000);	// L1386
  auto v843 = reinterpret_cast<float(*)[64][384]>(v777 + 8904192);
  kernel26(v841, v842, v843, (float)0.000000);	// L1388
  kernel25(v843, v840);	// L1389
  auto v844 = reinterpret_cast<float(*)[384][64]>(v777 + 8460288);
  kernel24(v842, v844);	// L1391
  auto v845 = reinterpret_cast<float(*)>(v778 + 65530368);
  kernel23(v845, v815);	// L1393
  auto v846 = reinterpret_cast<float(*)[384][1]>(v778 + 66857472);
  kernel22(v844, v846, v815);	// L1395
  auto v847 = reinterpret_cast<float(*)[384][8][8]>(v778 + 8460288);
  kernel21(v815, v810, v847);	// L1397
  auto v848 = reinterpret_cast<float(*)[384][8][8]>(v776 + 1966080);
  kernel20(v848, v847, v808, (float)2.000000);	// L1399
  kernel16(v808, v810);	// L1400
  kernel18(v810, (float)0.000000, (float)1.000000);	// L1401
  kernel17(v810, v808, (float)0.000000);	// L1402
  kernel16(v808, v848);	// L1403
  auto v849 = reinterpret_cast<float(*)[1536][8][8]>(v777 + 8682240);
  auto v850 = reinterpret_cast<float(*)>(v778 + 62876160);
  kernel15(v850, v849);	// L1406
  auto v851 = reinterpret_cast<float(*)[384][1][1]>(v778 + 64203264);
  kernel14(v810, v851, v849);	// L1408
  auto v852 = reinterpret_cast<float(*)[1536][8][8]>(v776 + 2162688);
  kernel13(v852, v849, (float)2.000000);	// L1410
  auto v853 = reinterpret_cast<float(*)[1536][8][8]>(v777 + 7128576);
  kernel9(v849, v853);	// L1412
  kernel11(v853, (float)0.000000, (float)1.000000);	// L1413
  kernel10(v853, v849, (float)0.000000);	// L1414
  kernel9(v849, v852);	// L1415
  auto v854 = reinterpret_cast<float(*)>(v778 + 60221952);
  kernel8(v854, v808);	// L1417
  auto v855 = reinterpret_cast<float(*)[1536][1][1]>(v778 + 61549056);
  kernel7(v853, v855, v808);	// L1419
  auto v856 = reinterpret_cast<float(*)[384][8][8]>(v777 + 7128576);
  kernel71(v808, v847, v856);	// L1421
  auto v857 = reinterpret_cast<float(*)[384][8][8]>(v776 + 2359296);
  kernel20(v857, v856, v808, (float)2.000000);	// L1423
  auto v858 = reinterpret_cast<float(*)[384][8][8]>(v776 + 8460288);
  kernel16(v808, v858);	// L1425
  kernel18(v858, (float)0.000000, (float)1.000000);	// L1426
  kernel17(v858, v808, (float)0.000000);	// L1427
  kernel16(v808, v857);	// L1428
  auto v859 = reinterpret_cast<float(*)>(v778 + 57567744);
  kernel23(v859, v815);	// L1430
  auto v860 = reinterpret_cast<float(*)[384][1]>(v778 + 58894848);
  kernel47(v858, v860, v815);	// L1432
  auto v861 = reinterpret_cast<float(*)[384][64]>(v776 + 2555904);
  kernel46(v861, v815, (float)2.000000);	// L1434
  auto v862 = reinterpret_cast<float(*)[384][64]>(v777 + 9126144);
  kernel42(v815, v862);	// L1436
  kernel44(v862, (float)0.000000, (float)1.000000);	// L1437
  kernel43(v862, v815, (float)0.000000);	// L1438
  kernel42(v815, v861);	// L1439
  auto v863 = reinterpret_cast<float(*)[64][12][32]>(v776 + 9348096);
  kernel41(v862, v863);	// L1441
  auto v864 = reinterpret_cast<float(*)[12][64][32]>(v776 + 9126144);
  kernel40(v863, v864);	// L1443
  auto v865 = reinterpret_cast<float(*)>(v778 + 54913536);
  kernel23(v865, v815);	// L1445
  auto v866 = reinterpret_cast<float(*)[384][1]>(v778 + 56240640);
  kernel47(v858, v866, v815);	// L1447
  auto v867 = reinterpret_cast<float(*)[384][64]>(v776 + 2752512);
  kernel46(v867, v815, (float)2.000000);	// L1449
  auto v868 = reinterpret_cast<float(*)[384][64]>(v777 + 9348096);
  kernel42(v815, v868);	// L1451
  kernel44(v868, (float)0.000000, (float)1.000000);	// L1452
  kernel43(v868, v815, (float)0.000000);	// L1453
  kernel42(v815, v867);	// L1454
  auto v869 = reinterpret_cast<float(*)[64][12][32]>(v777 + 9570048);
  kernel41(v868, v869);	// L1456
  auto v870 = reinterpret_cast<float(*)>(v778 + 52259328);
  kernel23(v870, v815);	// L1458
  auto v871 = reinterpret_cast<float(*)[384][1]>(v778 + 53586432);
  kernel47(v858, v871, v815);	// L1460
  auto v872 = reinterpret_cast<float(*)[384][64]>(v776 + 2949120);
  kernel46(v872, v815, (float)2.000000);	// L1462
  kernel42(v815, v844);	// L1463
  kernel44(v844, (float)0.000000, (float)1.000000);	// L1464
  kernel43(v844, v815, (float)0.000000);	// L1465
  kernel42(v815, v872);	// L1466
  kernel41(v844, v863);	// L1467
  kernel40(v863, v831);	// L1468
  kernel39(v869, v832);	// L1469
  auto v873 = reinterpret_cast<float(*)[1][12][64][32]>(v777 + 8460288);
  kernel35(v864, v873);	// L1471
  auto v874 = reinterpret_cast<float(*)[1][12][32][64]>(v777 + 9126144);
  kernel37(v832, v874);	// L1473
  auto v875 = reinterpret_cast<float(*)[64][64]>(v777 + 9348096);
  kernel102(v835, v875);	// L1475
  kernel36(v873, v874, v875);	// L1476
  auto v876 = reinterpret_cast<float(*)[1][12][64][32]>(v776 + 8460288);
  kernel35(v831, v876);	// L1478
  kernel165(v838, (float)0.000000);	// L1479
  kernel33(v876, v875, v838);	// L1480
  kernel32(v838, v831);	// L1481
  kernel31(v831, (float)0.125000);	// L1482
  kernel30(v831, v839);	// L1483
  auto v877 = reinterpret_cast<float(*)[64][384]>(v776 + 3145728);
  kernel29(v877, v839, v841, (float)2.000000);	// L1485
  auto v878 = reinterpret_cast<float(*)[64][384]>(v778 + 9126144);
  kernel28(v841, v878);	// L1487
  kernel27(v878, (float)1.000000, (float)0.500000, (float)0.000000);	// L1488
  kernel26(v841, v878, v843, (float)0.000000);	// L1489
  kernel25(v843, v877);	// L1490
  auto v879 = reinterpret_cast<float(*)[384][64]>(v776 + 8460288);
  kernel24(v878, v879);	// L1492
  auto v880 = reinterpret_cast<float(*)>(v778 + 49605120);
  kernel23(v880, v815);	// L1494
  auto v881 = reinterpret_cast<float(*)[384][1]>(v778 + 50932224);
  kernel22(v879, v881, v815);	// L1496
  auto v882 = reinterpret_cast<float(*)[384][8][8]>(v777 + 8460288);
  kernel21(v815, v856, v882);	// L1498
  auto v883 = reinterpret_cast<float(*)[384][8][8]>(v776 + 3342336);
  kernel20(v883, v882, v808, (float)2.000000);	// L1500
  kernel16(v808, v810);	// L1501
  kernel18(v810, (float)0.000000, (float)1.000000);	// L1502
  kernel17(v810, v808, (float)0.000000);	// L1503
  kernel16(v808, v883);	// L1504
  auto v884 = reinterpret_cast<float(*)>(v778 + 46950912);
  kernel15(v884, v849);	// L1506
  auto v885 = reinterpret_cast<float(*)[384][1][1]>(v778 + 48278016);
  kernel14(v810, v885, v849);	// L1508
  auto v886 = reinterpret_cast<float(*)[1536][8][8]>(v776 + 3538944);
  kernel13(v886, v849, (float)2.000000);	// L1510
  auto v887 = reinterpret_cast<float(*)[1536][8][8]>(v776 + 7128576);
  kernel9(v849, v887);	// L1512
  kernel11(v887, (float)0.000000, (float)1.000000);	// L1513
  kernel10(v887, v849, (float)0.000000);	// L1514
  kernel9(v849, v886);	// L1515
  auto v888 = reinterpret_cast<float(*)>(v778 + 44296704);
  kernel8(v888, v808);	// L1517
  auto v889 = reinterpret_cast<float(*)[1536][1][1]>(v778 + 45623808);
  kernel7(v887, v889, v808);	// L1519
  kernel71(v808, v882, v856);	// L1520
  auto v890 = reinterpret_cast<float(*)[384][8][8]>(v776 + 3735552);
  kernel20(v890, v856, v808, (float)2.000000);	// L1522
  kernel16(v808, v882);	// L1523
  kernel18(v882, (float)0.000000, (float)1.000000);	// L1524
  kernel17(v882, v808, (float)0.000000);	// L1525
  kernel16(v808, v890);	// L1526
  auto v891 = reinterpret_cast<float(*)>(v778 + 41642496);
  kernel23(v891, v815);	// L1528
  auto v892 = reinterpret_cast<float(*)[384][1]>(v778 + 42969600);
  kernel47(v882, v892, v815);	// L1530
  auto v893 = reinterpret_cast<float(*)[384][64]>(v776 + 3932160);
  kernel46(v893, v815, (float)2.000000);	// L1532
  kernel42(v815, v862);	// L1533
  kernel44(v862, (float)0.000000, (float)1.000000);	// L1534
  kernel43(v862, v815, (float)0.000000);	// L1535
  kernel42(v815, v893);	// L1536
  kernel41(v862, v863);	// L1537
  kernel40(v863, v864);	// L1538
  auto v894 = reinterpret_cast<float(*)>(v778 + 38988288);
  kernel23(v894, v815);	// L1540
  auto v895 = reinterpret_cast<float(*)[384][1]>(v778 + 40315392);
  kernel47(v882, v895, v815);	// L1542
  auto v896 = reinterpret_cast<float(*)[384][64]>(v776 + 4128768);
  kernel46(v896, v815, (float)2.000000);	// L1544
  auto v897 = reinterpret_cast<float(*)[384][64]>(v776 + 9348096);
  kernel42(v815, v897);	// L1546
  kernel44(v897, (float)0.000000, (float)1.000000);	// L1547
  kernel43(v897, v815, (float)0.000000);	// L1548
  kernel42(v815, v896);	// L1549
  kernel41(v897, v869);	// L1550
  auto v898 = reinterpret_cast<float(*)>(v778 + 36334080);
  kernel23(v898, v815);	// L1552
  auto v899 = reinterpret_cast<float(*)[384][1]>(v778 + 37661184);
  kernel47(v882, v899, v815);	// L1554
  auto v900 = reinterpret_cast<float(*)[384][64]>(v776 + 4325376);
  kernel46(v900, v815, (float)2.000000);	// L1556
  kernel42(v815, v844);	// L1557
  kernel44(v844, (float)0.000000, (float)1.000000);	// L1558
  kernel43(v844, v815, (float)0.000000);	// L1559
  kernel42(v815, v900);	// L1560
  kernel41(v844, v863);	// L1561
  kernel40(v863, v831);	// L1562
  kernel39(v869, v832);	// L1563
  kernel35(v864, v873);	// L1564
  kernel37(v832, v874);	// L1565
  kernel102(v835, v875);	// L1566
  kernel36(v873, v874, v875);	// L1567
  kernel35(v831, v873);	// L1568
  kernel99(v838, (float)0.000000);	// L1569
  kernel33(v873, v875, v838);	// L1570
  kernel32(v838, v831);	// L1571
  kernel31(v831, (float)0.125000);	// L1572
  kernel30(v831, v839);	// L1573
  auto v901 = reinterpret_cast<float(*)[64][384]>(v776 + 4521984);
  auto v902 = reinterpret_cast<float(*)[64][12][32]>(v777 + 8460288);
  kernel29(v901, v839, v902, (float)2.000000);	// L1576
  auto v903 = reinterpret_cast<float(*)[64][384]>(v776 + 9126144);
  kernel28(v902, v903);	// L1578
  kernel27(v903, (float)1.000000, (float)0.500000, (float)0.000000);	// L1579
  kernel26(v902, v903, v843, (float)0.000000);	// L1580
  kernel25(v843, v901);	// L1581
  kernel24(v903, v844);	// L1582
  auto v904 = reinterpret_cast<float(*)>(v778 + 33679872);
  kernel23(v904, v815);	// L1584
  auto v905 = reinterpret_cast<float(*)[384][1]>(v778 + 35006976);
  kernel22(v844, v905, v815);	// L1586
  kernel21(v815, v856, v847);	// L1587
  auto v906 = reinterpret_cast<float(*)[384][8][8]>(v776 + 4718592);
  kernel20(v906, v847, v808, (float)2.000000);	// L1589
  kernel16(v808, v810);	// L1590
  kernel18(v810, (float)0.000000, (float)1.000000);	// L1591
  kernel17(v810, v808, (float)0.000000);	// L1592
  kernel16(v808, v906);	// L1593
  auto v907 = reinterpret_cast<float(*)>(v778 + 31025664);
  kernel15(v907, v849);	// L1595
  auto v908 = reinterpret_cast<float(*)[384][1][1]>(v778 + 32352768);
  kernel14(v810, v908, v849);	// L1597
  auto v909 = reinterpret_cast<float(*)[1536][8][8]>(v776 + 4915200);
  kernel13(v909, v849, (float)2.000000);	// L1599
  kernel9(v849, v853);	// L1600
  kernel11(v853, (float)0.000000, (float)1.000000);	// L1601
  kernel10(v853, v849, (float)0.000000);	// L1602
  kernel9(v849, v909);	// L1603
  auto v910 = reinterpret_cast<float(*)>(v778 + 28371456);
  kernel8(v910, v808);	// L1605
  auto v911 = reinterpret_cast<float(*)[1536][1][1]>(v778 + 29698560);
  kernel7(v853, v911, v808);	// L1607
  kernel71(v808, v847, v856);	// L1608
  auto v912 = reinterpret_cast<float(*)[384][8][8]>(v776 + 5111808);
  kernel20(v912, v856, v808, (float)2.000000);	// L1610
  kernel16(v808, v882);	// L1611
  kernel18(v882, (float)0.000000, (float)1.000000);	// L1612
  kernel17(v882, v808, (float)0.000000);	// L1613
  kernel16(v808, v912);	// L1614
  auto v913 = reinterpret_cast<float(*)>(v778 + 25717248);
  kernel23(v913, v815);	// L1616
  auto v914 = reinterpret_cast<float(*)[384][1]>(v778 + 27044352);
  kernel47(v882, v914, v815);	// L1618
  auto v915 = reinterpret_cast<float(*)[384][64]>(v776 + 5308416);
  kernel46(v915, v815, (float)2.000000);	// L1620
  auto v916 = reinterpret_cast<float(*)[384][64]>(v776 + 9126144);
  kernel42(v815, v916);	// L1622
  kernel44(v916, (float)0.000000, (float)1.000000);	// L1623
  kernel43(v916, v815, (float)0.000000);	// L1624
  kernel42(v815, v915);	// L1625
  kernel41(v916, v863);	// L1626
  auto v917 = reinterpret_cast<float(*)[12][64][32]>(v777 + 9126144);
  kernel40(v863, v917);	// L1628
  auto v918 = reinterpret_cast<float(*)>(v778 + 23063040);
  kernel23(v918, v815);	// L1630
  auto v919 = reinterpret_cast<float(*)[384][1]>(v778 + 24390144);
  kernel47(v882, v919, v815);	// L1632
  auto v920 = reinterpret_cast<float(*)[384][64]>(v776 + 5505024);
  kernel46(v920, v815, (float)2.000000);	// L1634
  kernel42(v815, v897);	// L1635
  kernel44(v897, (float)0.000000, (float)1.000000);	// L1636
  kernel43(v897, v815, (float)0.000000);	// L1637
  kernel42(v815, v920);	// L1638
  kernel41(v897, v869);	// L1639
  auto v921 = reinterpret_cast<float(*)>(v778 + 20408832);
  kernel23(v921, v815);	// L1641
  auto v922 = reinterpret_cast<float(*)[384][1]>(v778 + 21735936);
  kernel47(v882, v922, v815);	// L1643
  auto v923 = reinterpret_cast<float(*)[384][64]>(v776 + 5701632);
  kernel46(v923, v815, (float)2.000000);	// L1645
  kernel42(v815, v879);	// L1646
  kernel44(v879, (float)0.000000, (float)1.000000);	// L1647
  kernel43(v879, v815, (float)0.000000);	// L1648
  kernel42(v815, v923);	// L1649
  auto v924 = reinterpret_cast<float(*)[64][12][32]>(v777 + 9348096);
  kernel41(v879, v924);	// L1651
  kernel40(v924, v831);	// L1652
  kernel39(v869, v832);	// L1653
  kernel35(v917, v873);	// L1654
  auto v925 = reinterpret_cast<float(*)[1][12][32][64]>(v778 + 9126144);
  kernel37(v832, v925);	// L1656
  kernel36(v873, v925, v835);	// L1657
  auto v926 = reinterpret_cast<float(*)[1][12][64][32]>(v777 + 6684672);
  kernel35(v831, v926);	// L1659
  kernel34(v838, (float)0.000000);	// L1660
  kernel33(v926, v835, v838);	// L1661
  kernel32(v838, v831);	// L1662
  kernel31(v831, (float)0.125000);	// L1663
  kernel30(v831, v839);	// L1664
  auto v927 = reinterpret_cast<float(*)[64][384]>(v776 + 5898240);
  auto v928 = reinterpret_cast<float(*)[64][12][32]>(v777 + 6684672);
  kernel29(v927, v839, v928, (float)2.000000);	// L1667
  auto v929 = reinterpret_cast<float(*)[64][384]>(v776 + 7572480);
  kernel28(v928, v929);	// L1669
  kernel27(v929, (float)1.000000, (float)0.500000, (float)0.000000);	// L1670
  kernel26(v928, v929, v843, (float)0.000000);	// L1671
  kernel25(v843, v927);	// L1672
  auto v930 = reinterpret_cast<float(*)[384][64]>(v777 + 6684672);
  kernel24(v929, v930);	// L1674
  auto v931 = reinterpret_cast<float(*)>(v778 + 17754624);
  kernel23(v931, v815);	// L1676
  auto v932 = reinterpret_cast<float(*)[384][1]>(v778 + 19081728);
  kernel22(v930, v932, v815);	// L1678
  kernel21(v815, v856, v814);	// L1679
  auto v933 = reinterpret_cast<float(*)[384][8][8]>(v776 + 6094848);
  kernel20(v933, v814, v808, (float)2.000000);	// L1681
  kernel16(v808, v810);	// L1682
  kernel18(v810, (float)0.000000, (float)1.000000);	// L1683
  kernel17(v810, v808, (float)0.000000);	// L1684
  kernel16(v808, v933);	// L1685
  auto v934 = reinterpret_cast<float(*)>(v778 + 15100416);
  kernel15(v934, v849);	// L1687
  auto v935 = reinterpret_cast<float(*)[384][1][1]>(v778 + 16427520);
  kernel14(v810, v935, v849);	// L1689
  auto v936 = reinterpret_cast<float(*)[1536][8][8]>(v776 + 6291456);
  kernel13(v936, v849, (float)2.000000);	// L1691
  kernel9(v849, v887);	// L1692
  kernel11(v887, (float)0.000000, (float)1.000000);	// L1693
  kernel10(v887, v849, (float)0.000000);	// L1694
  kernel9(v849, v936);	// L1695
  auto v937 = reinterpret_cast<float(*)>(v778 + 12446208);
  kernel8(v937, v808);	// L1697
  auto v938 = reinterpret_cast<float(*)[1536][1][1]>(v778 + 13773312);
  kernel7(v887, v938, v808);	// L1699
  kernel6(v814, v808);	// L1700
  auto v939 = reinterpret_cast<float(*)[384]>(v776 + 6684672);
  kernel5(v939, (float)0.000000);	// L1702
  kernel4(v808, v939);	// L1703
  kernel3(v939, (float)64.000000);	// L1704
  auto v940 = reinterpret_cast<float(*)[10]>(v776 + 6488064);
  kernel2(v940, (float)0.000000);	// L1706
  auto v941 = reinterpret_cast<float(*)[10]>(v778 + 9792000);
  kernel1(v939, v941, v940);	// L1708
  auto v942 = reinterpret_cast<float(*)>(v778 + 11119104);
  kernel0(v942, v940);	// L1710
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

