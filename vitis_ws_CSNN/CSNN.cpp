
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
  float v0[1][10],
  float v1[1][10]
) {	// L2
  for (int v2 = 0; v2 < 10; v2 += 1) {	// L3
    #pragma HLS pipeline II=1
    #pragma HLS dependence false variable=v0
    #pragma HLS dependence false variable=v1
    float v3 = v0[0][v2];	// L4
    v1[0][v2] = v3;	// L5
  }
}

void kernel1(
  float v4[1][10],
  float v5[1][10]
) {	// L9
  for (int v6 = 0; v6 < 10; v6 += 1) {	// L10
    #pragma HLS pipeline II=1
    #pragma HLS dependence false variable=v4
    #pragma HLS dependence false variable=v5
    float v7 = v4[0][v6];	// L11
    float v8 = v5[0][v6];	// L12
    float v9 = v7 + v8;	// L13
    v5[0][v6] = v9;	// L14
  }
}

void kernel2(
  float v10[1][10],
  float v11
) {	// L18
  for (int v12 = 0; v12 < 10; v12 += 1) {	// L19
    #pragma HLS pipeline II=1
    #pragma HLS dependence false variable=v10
    float v13 = v10[0][v12];	// L20
    float v14 = v13 * v11;	// L21
    v10[0][v12] = v14;	// L22
  }
}

void kernel4(
  float v15[1][10],
  float v16[1][10],
  float v17[1][10]
) {	// L26
  for (int v18 = 0; v18 < 10; v18 += 1) {	// L27
    #pragma HLS pipeline II=1
    #pragma HLS dependence false variable=v16
    #pragma HLS dependence false variable=v17
    #pragma HLS dependence false variable=v15
    float v19 = v16[0][v18];	// L28
    float v20 = v15[0][v18];	// L29
    float v21 = v19 - v20;	// L30
    v17[0][v18] = v21;	// L31
  }
}

void kernel5(
  float v22[1][10],
  float v23[1][10],
  float v24[1][10]
) {	// L35
  for (int v25 = 0; v25 < 10; v25 += 1) {	// L36
    #pragma HLS pipeline II=1
    #pragma HLS dependence false variable=v23
    #pragma HLS dependence false variable=v24
    #pragma HLS dependence false variable=v22
    float v26 = v23[0][v25];	// L37
    float v27 = v22[0][v25];	// L38
    float v28 = v26 * v27;	// L39
    v24[0][v25] = v28;	// L40
  }
}

void kernel6(
  float v29[1][10],
  float v30,
  float v31
) {	// L44
  for (int v32 = 0; v32 < 10; v32 += 1) {	// L45
    #pragma HLS pipeline II=1
    #pragma HLS dependence false variable=v29
    float v33 = v29[0][v32];	// L46
    bool v34 = v33 >= v31;	// L47
    float v35 = v34 ? v30 : v31;	// L48
    v29[0][v32] = v35;	// L49
  }
}

void kernel8(
  float v36[1][10],
  float v37
) {	// L53
  for (int v38 = 0; v38 < 10; v38 += 1) {	// L54
    #pragma HLS pipeline II=1
    #pragma HLS dependence false variable=v36
    float v39 = v36[0][v38];	// L55
    float v40 = v39 - v37;	// L56
    v36[0][v38] = v40;	// L57
  }
}

void kernel10(
  float v41[1][10],
  float v42[1][10],
  float v43[1][10]
) {	// L61
  for (int v44 = 0; v44 < 10; v44 += 1) {	// L62
    #pragma HLS pipeline II=1
    #pragma HLS dependence false variable=v42
    #pragma HLS dependence false variable=v43
    #pragma HLS dependence false variable=v41
    float v45 = v42[0][v44];	// L63
    float v46 = v41[0][v44];	// L64
    float v47 = v45 + v46;	// L65
    v43[0][v44] = v47;	// L66
  }
}

void kernel11(
  float v48[1][512],
  float v49[512][10],
  float v50[1][10]
) {	// L70
  float v51[1][512];	// L71
  #pragma HLS resource variable=v51 core=ram_t2p_bram

  memcpy(v51, v48, 512 * sizeof(float));	// L72

  for (int v52 = 0; v52 < 512; v52 += 1) {	// L73
    for (int v53 = 0; v53 < 10; v53 += 1) {	// L74
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v51
      #pragma HLS dependence false variable=v49
      #pragma HLS dependence false variable=v50
      float v54 = v51[0][v52];	// L75
      float v55 = v49[v52][v53];	// L76
      float v56 = v50[0][v53];	// L77
      float v57 = v54 * v55;	// L78
      float v58 = v56 + v57;	// L79
      v50[0][v53] = v58;	// L80
    }
  }
}

void kernel12(
  float v59[1][10],
  float v60
) {	// L85
  for (int v61 = 0; v61 < 10; v61 += 1) {	// L86
    #pragma HLS pipeline II=1
    #pragma HLS dependence false variable=v59
    v59[0][v61] = v60;	// L87
  }
}

void kernel13(
  float v62[1][512],
  float v63[1][512]
) {	// L91
  for (int v64 = 0; v64 < 512; v64 += 1) {	// L92
    #pragma HLS pipeline II=1
    #pragma HLS dependence false variable=v62
    #pragma HLS dependence false variable=v63
    float v65 = v62[0][v64];	// L93
    v63[0][v64] = v65;	// L94
  }
}

void kernel14(
  float v66[1][512],
  float v67[1][512]
) {	// L98
  for (int v68 = 0; v68 < 512; v68 += 1) {	// L99
    #pragma HLS pipeline II=1
    #pragma HLS dependence false variable=v66
    #pragma HLS dependence false variable=v67
    float v69 = v66[0][v68];	// L100
    float v70 = v67[0][v68];	// L101
    float v71 = v69 + v70;	// L102
    v67[0][v68] = v71;	// L103
  }
}

void kernel15(
  float v72[1][512],
  float v73
) {	// L107
  for (int v74 = 0; v74 < 512; v74 += 1) {	// L108
    #pragma HLS pipeline II=1
    #pragma HLS dependence false variable=v72
    float v75 = v72[0][v74];	// L109
    float v76 = v75 * v73;	// L110
    v72[0][v74] = v76;	// L111
  }
}

void kernel17(
  float v77[1][512],
  float v78[1][512],
  float v79[1][512]
) {	// L115
  for (int v80 = 0; v80 < 512; v80 += 1) {	// L116
    #pragma HLS pipeline II=1
    #pragma HLS dependence false variable=v78
    #pragma HLS dependence false variable=v79
    #pragma HLS dependence false variable=v77
    float v81 = v78[0][v80];	// L117
    float v82 = v77[0][v80];	// L118
    float v83 = v81 - v82;	// L119
    v79[0][v80] = v83;	// L120
  }
}

void kernel18(
  float v84[1][512],
  float v85,
  float v86
) {	// L124
  for (int v87 = 0; v87 < 512; v87 += 1) {	// L125
    #pragma HLS pipeline II=1
    #pragma HLS dependence false variable=v84
    float v88 = v84[0][v87];	// L126
    bool v89 = v88 >= v86;	// L127
    float v90 = v89 ? v85 : v86;	// L128
    v84[0][v87] = v90;	// L129
  }
}

void kernel20(
  float v91[1][512],
  float v92
) {	// L133
  for (int v93 = 0; v93 < 512; v93 += 1) {	// L134
    #pragma HLS pipeline II=1
    #pragma HLS dependence false variable=v91
    float v94 = v91[0][v93];	// L135
    float v95 = v94 - v92;	// L136
    v91[0][v93] = v95;	// L137
  }
}

void kernel22(
  float v96[1][512],
  float v97[1][512],
  float v98[1][512]
) {	// L141
  for (int v99 = 0; v99 < 512; v99 += 1) {	// L142
    #pragma HLS pipeline II=1
    #pragma HLS dependence false variable=v97
    #pragma HLS dependence false variable=v98
    #pragma HLS dependence false variable=v96
    float v100 = v97[0][v99];	// L143
    float v101 = v96[0][v99];	// L144
    float v102 = v100 + v101;	// L145
    v98[0][v99] = v102;	// L146
  }
}

void kernel23(
  float v103[1][512],
  float v104
) {	// L150
  for (int v105 = 0; v105 < 512; v105 += 1) {	// L151
    #pragma HLS pipeline II=1
    #pragma HLS dependence false variable=v103
    float v106 = v103[0][v105];	// L152
    float v107 = v106 / v104;	// L153
    v103[0][v105] = v107;	// L154
  }
}

void kernel28(
  float v108[1][32][7][7],
  float v109[1568][512],
  float v110[1][512]
) {	// L158
  float v111[1][32][7][7];	// L159
  #pragma HLS resource variable=v111 core=ram_t2p_bram

  memcpy(v111, v108, 1568 * sizeof(float));	// L160

  for (int v112 = 0; v112 < 1568; v112 += 1) {	// L161
    for (int v113 = 0; v113 < 512; v113 += 1) {	// L162
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v111
      #pragma HLS dependence false variable=v109
      #pragma HLS dependence false variable=v110
      float v114 = v111[0][(v112 / 49)][((v112 % 49) / 7)][(v112 % 7)];	// L163
      float v115 = v109[v112][v113];	// L164
      float v116 = v110[0][v113];	// L165
      float v117 = v114 * v115;	// L166
      float v118 = v116 + v117;	// L167
      v110[0][v113] = v118;	// L168
    }
  }
}

void kernel29(
  float v119[1][512],
  float v120
) {	// L173
  for (int v121 = 0; v121 < 512; v121 += 1) {	// L174
    #pragma HLS pipeline II=1
    #pragma HLS dependence false variable=v119
    v119[0][v121] = v120;	// L175
  }
}

void kernel30(
  float v122[1][32][14][14],
  float v123[2][2],
  float v124[1][32][7][7]
) {	// L179
  for (int v125 = 0; v125 < 2; v125 += 1) {	// L180
    for (int v126 = 0; v126 < 2; v126 += 1) {	// L181
      for (int v127 = 0; v127 < 32; v127 += 1) {	// L182
        for (int v128 = 0; v128 < 7; v128 += 1) {	// L183
          for (int v129 = 0; v129 < 7; v129 += 1) {	// L184
            #pragma HLS pipeline II=1
            #pragma HLS dependence false variable=v122
            #pragma HLS dependence false variable=v124
            float v130 = v122[0][v127][((v128 * 2) + v125)][((v129 * 2) + v126)];	// L185
            float v131 = v124[0][v127][v128][v129];	// L186
            float v132 = max(v131, v130);	// L187
            v124[0][v127][v128][v129] = v132;	// L188
          }
        }
      }
    }
  }
}

void kernel31(
  float v133[1][32][7][7],
  float v134
) {	// L196
  for (int v135 = 0; v135 < 32; v135 += 1) {	// L197
    for (int v136 = 0; v136 < 7; v136 += 1) {	// L198
      for (int v137 = 0; v137 < 7; v137 += 1) {	// L199
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v133
        v133[0][v135][v136][v137] = v134;	// L200
      }
    }
  }
}

void kernel32(
  float v138[1][32][14][14],
  float v139[1][32][14][14]
) {	// L206
  for (int v140 = 0; v140 < 32; v140 += 1) {	// L207
    for (int v141 = 0; v141 < 14; v141 += 1) {	// L208
      for (int v142 = 0; v142 < 14; v142 += 1) {	// L209
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v138
        #pragma HLS dependence false variable=v139
        float v143 = v138[0][v140][v141][v142];	// L210
        v139[0][v140][v141][v142] = v143;	// L211
      }
    }
  }
}

void kernel33(
  float v144[1][32][14][14],
  float v145[1][32][14][14]
) {	// L217
  for (int v146 = 0; v146 < 32; v146 += 1) {	// L218
    for (int v147 = 0; v147 < 14; v147 += 1) {	// L219
      for (int v148 = 0; v148 < 14; v148 += 1) {	// L220
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v144
        #pragma HLS dependence false variable=v145
        float v149 = v144[0][v146][v147][v148];	// L221
        float v150 = v145[0][v146][v147][v148];	// L222
        float v151 = v149 + v150;	// L223
        v145[0][v146][v147][v148] = v151;	// L224
      }
    }
  }
}

void kernel34(
  float v152[1][32][14][14],
  float v153
) {	// L230
  for (int v154 = 0; v154 < 32; v154 += 1) {	// L231
    for (int v155 = 0; v155 < 14; v155 += 1) {	// L232
      for (int v156 = 0; v156 < 14; v156 += 1) {	// L233
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v152
        float v157 = v152[0][v154][v155][v156];	// L234
        float v158 = v157 * v153;	// L235
        v152[0][v154][v155][v156] = v158;	// L236
      }
    }
  }
}

void kernel36(
  float v159[1][32][14][14],
  float v160[1][32][14][14],
  float v161[1][32][14][14]
) {	// L242
  for (int v162 = 0; v162 < 32; v162 += 1) {	// L243
    for (int v163 = 0; v163 < 14; v163 += 1) {	// L244
      for (int v164 = 0; v164 < 14; v164 += 1) {	// L245
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v160
        #pragma HLS dependence false variable=v161
        #pragma HLS dependence false variable=v159
        float v165 = v160[0][v162][v163][v164];	// L246
        float v166 = v159[0][v162][v163][v164];	// L247
        float v167 = v165 - v166;	// L248
        v161[0][v162][v163][v164] = v167;	// L249
      }
    }
  }
}

void kernel37(
  float v168[1][32][14][14],
  float v169[1][32][14][14],
  float v170[1][32][14][14]
) {	// L255
  for (int v171 = 0; v171 < 32; v171 += 1) {	// L256
    for (int v172 = 0; v172 < 14; v172 += 1) {	// L257
      for (int v173 = 0; v173 < 14; v173 += 1) {	// L258
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v169
        #pragma HLS dependence false variable=v170
        #pragma HLS dependence false variable=v168
        float v174 = v169[0][v171][v172][v173];	// L259
        float v175 = v168[0][v171][v172][v173];	// L260
        float v176 = v174 * v175;	// L261
        v170[0][v171][v172][v173] = v176;	// L262
      }
    }
  }
}

void kernel38(
  float v177[1][32][14][14],
  float v178,
  float v179
) {	// L268
  for (int v180 = 0; v180 < 32; v180 += 1) {	// L269
    for (int v181 = 0; v181 < 14; v181 += 1) {	// L270
      for (int v182 = 0; v182 < 14; v182 += 1) {	// L271
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v177
        float v183 = v177[0][v180][v181][v182];	// L272
        bool v184 = v183 >= v179;	// L273
        float v185 = v184 ? v178 : v179;	// L274
        v177[0][v180][v181][v182] = v185;	// L275
      }
    }
  }
}

void kernel40(
  float v186[1][32][14][14],
  float v187
) {	// L281
  for (int v188 = 0; v188 < 32; v188 += 1) {	// L282
    for (int v189 = 0; v189 < 14; v189 += 1) {	// L283
      for (int v190 = 0; v190 < 14; v190 += 1) {	// L284
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v186
        float v191 = v186[0][v188][v189][v190];	// L285
        float v192 = v191 - v187;	// L286
        v186[0][v188][v189][v190] = v192;	// L287
      }
    }
  }
}

void kernel42(
  float v193[1][32][14][14],
  float v194[1][32][14][14],
  float v195[1][32][14][14]
) {	// L293
  for (int v196 = 0; v196 < 32; v196 += 1) {	// L294
    for (int v197 = 0; v197 < 14; v197 += 1) {	// L295
      for (int v198 = 0; v198 < 14; v198 += 1) {	// L296
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v194
        #pragma HLS dependence false variable=v195
        #pragma HLS dependence false variable=v193
        float v199 = v194[0][v196][v197][v198];	// L297
        float v200 = v193[0][v196][v197][v198];	// L298
        float v201 = v199 + v200;	// L299
        v195[0][v196][v197][v198] = v201;	// L300
      }
    }
  }
}

void kernel43(
  float v202[1][32][14][14],
  float v203
) {	// L306
  for (int v204 = 0; v204 < 32; v204 += 1) {	// L307
    for (int v205 = 0; v205 < 14; v205 += 1) {	// L308
      for (int v206 = 0; v206 < 14; v206 += 1) {	// L309
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v202
        float v207 = v202[0][v204][v205][v206];	// L310
        float v208 = v207 / v203;	// L311
        v202[0][v204][v205][v206] = v208;	// L312
      }
    }
  }
}

void kernel48(
  float v209[1][32][16][16],
  float v210[32][32][3][3],
  float v211[1][32][14][14]
) {	// L318
  float v212[32][32][3][3];	// L319
  #pragma HLS resource variable=v212 core=ram_t2p_bram

  memcpy(v212, v210, 9216 * sizeof(float));	// L320

  for (int v213 = 0; v213 < 32; v213 += 1) {	// L321
    for (int v214 = 0; v214 < 3; v214 += 1) {	// L322
      for (int v215 = 0; v215 < 3; v215 += 1) {	// L323
        for (int v216 = 0; v216 < 32; v216 += 1) {	// L324
          for (int v217 = 0; v217 < 14; v217 += 1) {	// L325
            for (int v218 = 0; v218 < 14; v218 += 1) {	// L326
              #pragma HLS pipeline II=1
              #pragma HLS dependence false variable=v209
              #pragma HLS dependence false variable=v211
              #pragma HLS dependence false variable=v212
              float v219 = v209[0][v213][(v217 + v214)][(v218 + v215)];	// L327
              float v220 = v212[v216][v213][v214][v215];	// L328
              float v221 = v211[0][v216][v217][v218];	// L329
              float v222 = v219 * v220;	// L330
              float v223 = v221 + v222;	// L331
              v211[0][v216][v217][v218] = v223;	// L332
            }
          }
        }
      }
    }
  }
}

void kernel49(
  float v224[32],
  float v225[1][32][14][14]
) {	// L341
  float v226[32];	// L342
  #pragma HLS resource variable=v226 core=ram_t2p_bram

  memcpy(v226, v224, 32 * sizeof(float));	// L343

  for (int v227 = 0; v227 < 32; v227 += 1) {	// L344
    for (int v228 = 0; v228 < 14; v228 += 1) {	// L345
      for (int v229 = 0; v229 < 14; v229 += 1) {	// L346
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v226
        #pragma HLS dependence false variable=v225
        float v230 = v226[v227];	// L347
        v225[0][v227][v228][v229] = v230;	// L348
      }
    }
  }
}

void kernel50(
  float v231[1][32][14][14],
  float v232[1][32][16][16]
) {	// L354
  for (int v233 = 0; v233 < 32; v233 += 1) {	// L355
    for (int v234 = 0; v234 < 14; v234 += 1) {	// L356
      for (int v235 = 0; v235 < 14; v235 += 1) {	// L357
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v231
        #pragma HLS dependence false variable=v232
        float v236 = v231[0][v233][v234][v235];	// L358
        v232[0][v233][(v234 + 1)][(v235 + 1)] = v236;	// L359
      }
    }
  }
}

void kernel51(
  float v237[1][32][16][16],
  float v238
) {	// L365
  for (int v239 = 0; v239 < 32; v239 += 1) {	// L366
    for (int v240 = 0; v240 < 16; v240 += 1) {	// L367
      for (int v241 = 0; v241 < 16; v241 += 1) {	// L368
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v237
        v237[0][v239][v240][v241] = v238;	// L369
      }
    }
  }
}

void kernel52(
  float v242[1][32][28][28],
  float v243[2][2],
  float v244[1][32][14][14]
) {	// L375
  for (int v245 = 0; v245 < 2; v245 += 1) {	// L376
    for (int v246 = 0; v246 < 2; v246 += 1) {	// L377
      for (int v247 = 0; v247 < 32; v247 += 1) {	// L378
        for (int v248 = 0; v248 < 14; v248 += 1) {	// L379
          for (int v249 = 0; v249 < 14; v249 += 1) {	// L380
            #pragma HLS pipeline II=1
            #pragma HLS dependence false variable=v242
            #pragma HLS dependence false variable=v244
            float v250 = v242[0][v247][((v248 * 2) + v245)][((v249 * 2) + v246)];	// L381
            float v251 = v244[0][v247][v248][v249];	// L382
            float v252 = max(v251, v250);	// L383
            v244[0][v247][v248][v249] = v252;	// L384
          }
        }
      }
    }
  }
}

void kernel53(
  float v253[1][32][14][14],
  float v254
) {	// L392
  for (int v255 = 0; v255 < 32; v255 += 1) {	// L393
    for (int v256 = 0; v256 < 14; v256 += 1) {	// L394
      for (int v257 = 0; v257 < 14; v257 += 1) {	// L395
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v253
        v253[0][v255][v256][v257] = v254;	// L396
      }
    }
  }
}

void kernel54(
  float v258[1][32][28][28],
  float v259[1][32][28][28]
) {	// L402
  for (int v260 = 0; v260 < 32; v260 += 1) {	// L403
    for (int v261 = 0; v261 < 28; v261 += 1) {	// L404
      for (int v262 = 0; v262 < 28; v262 += 1) {	// L405
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v258
        #pragma HLS dependence false variable=v259
        float v263 = v258[0][v260][v261][v262];	// L406
        v259[0][v260][v261][v262] = v263;	// L407
      }
    }
  }
}

void kernel55(
  float v264[1][32][28][28],
  float v265[1][32][28][28]
) {	// L413
  for (int v266 = 0; v266 < 32; v266 += 1) {	// L414
    for (int v267 = 0; v267 < 28; v267 += 1) {	// L415
      for (int v268 = 0; v268 < 28; v268 += 1) {	// L416
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v264
        #pragma HLS dependence false variable=v265
        float v269 = v264[0][v266][v267][v268];	// L417
        float v270 = v265[0][v266][v267][v268];	// L418
        float v271 = v269 + v270;	// L419
        v265[0][v266][v267][v268] = v271;	// L420
      }
    }
  }
}

void kernel56(
  float v272[1][32][28][28],
  float v273
) {	// L426
  for (int v274 = 0; v274 < 32; v274 += 1) {	// L427
    for (int v275 = 0; v275 < 28; v275 += 1) {	// L428
      for (int v276 = 0; v276 < 28; v276 += 1) {	// L429
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v272
        float v277 = v272[0][v274][v275][v276];	// L430
        float v278 = v277 * v273;	// L431
        v272[0][v274][v275][v276] = v278;	// L432
      }
    }
  }
}

void kernel58(
  float v279[1][32][28][28],
  float v280[1][32][28][28],
  float v281[1][32][28][28]
) {	// L438
  for (int v282 = 0; v282 < 32; v282 += 1) {	// L439
    for (int v283 = 0; v283 < 28; v283 += 1) {	// L440
      for (int v284 = 0; v284 < 28; v284 += 1) {	// L441
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v280
        #pragma HLS dependence false variable=v281
        #pragma HLS dependence false variable=v279
        float v285 = v280[0][v282][v283][v284];	// L442
        float v286 = v279[0][v282][v283][v284];	// L443
        float v287 = v285 - v286;	// L444
        v281[0][v282][v283][v284] = v287;	// L445
      }
    }
  }
}

void kernel59(
  float v288[1][32][28][28],
  float v289[1][32][28][28],
  float v290[1][32][28][28]
) {	// L451
  for (int v291 = 0; v291 < 32; v291 += 1) {	// L452
    for (int v292 = 0; v292 < 28; v292 += 1) {	// L453
      for (int v293 = 0; v293 < 28; v293 += 1) {	// L454
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v289
        #pragma HLS dependence false variable=v290
        #pragma HLS dependence false variable=v288
        float v294 = v289[0][v291][v292][v293];	// L455
        float v295 = v288[0][v291][v292][v293];	// L456
        float v296 = v294 * v295;	// L457
        v290[0][v291][v292][v293] = v296;	// L458
      }
    }
  }
}

void kernel60(
  float v297[1][32][28][28],
  float v298,
  float v299
) {	// L464
  for (int v300 = 0; v300 < 32; v300 += 1) {	// L465
    for (int v301 = 0; v301 < 28; v301 += 1) {	// L466
      for (int v302 = 0; v302 < 28; v302 += 1) {	// L467
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v297
        float v303 = v297[0][v300][v301][v302];	// L468
        bool v304 = v303 >= v299;	// L469
        float v305 = v304 ? v298 : v299;	// L470
        v297[0][v300][v301][v302] = v305;	// L471
      }
    }
  }
}

void kernel62(
  float v306[1][32][28][28],
  float v307
) {	// L477
  for (int v308 = 0; v308 < 32; v308 += 1) {	// L478
    for (int v309 = 0; v309 < 28; v309 += 1) {	// L479
      for (int v310 = 0; v310 < 28; v310 += 1) {	// L480
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v306
        float v311 = v306[0][v308][v309][v310];	// L481
        float v312 = v311 - v307;	// L482
        v306[0][v308][v309][v310] = v312;	// L483
      }
    }
  }
}

void kernel64(
  float v313[1][32][28][28],
  float v314[1][32][28][28],
  float v315[1][32][28][28]
) {	// L489
  for (int v316 = 0; v316 < 32; v316 += 1) {	// L490
    for (int v317 = 0; v317 < 28; v317 += 1) {	// L491
      for (int v318 = 0; v318 < 28; v318 += 1) {	// L492
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v314
        #pragma HLS dependence false variable=v315
        #pragma HLS dependence false variable=v313
        float v319 = v314[0][v316][v317][v318];	// L493
        float v320 = v313[0][v316][v317][v318];	// L494
        float v321 = v319 + v320;	// L495
        v315[0][v316][v317][v318] = v321;	// L496
      }
    }
  }
}

void kernel65(
  float v322[1][1][30][30],
  float v323[32][1][3][3],
  float v324[1][32][28][28]
) {	// L502
  float v325[32][1][3][3];	// L503
  #pragma HLS resource variable=v325 core=ram_t2p_bram

  memcpy(v325, v323, 288 * sizeof(float));	// L504

  for (int v326 = 0; v326 < 3; v326 += 1) {	// L505
    for (int v327 = 0; v327 < 3; v327 += 1) {	// L506
      for (int v328 = 0; v328 < 32; v328 += 1) {	// L507
        for (int v329 = 0; v329 < 28; v329 += 1) {	// L508
          for (int v330 = 0; v330 < 28; v330 += 1) {	// L509
            #pragma HLS pipeline II=1
            #pragma HLS dependence false variable=v322
            #pragma HLS dependence false variable=v324
            #pragma HLS dependence false variable=v325
            float v331 = v322[0][0][(v329 + v326)][(v330 + v327)];	// L510
            float v332 = v325[v328][0][v326][v327];	// L511
            float v333 = v324[0][v328][v329][v330];	// L512
            float v334 = v331 * v332;	// L513
            float v335 = v333 + v334;	// L514
            v324[0][v328][v329][v330] = v335;	// L515
          }
        }
      }
    }
  }
}

void kernel66(
  float v336[32],
  float v337[1][32][28][28]
) {	// L523
  float v338[32];	// L524
  #pragma HLS resource variable=v338 core=ram_t2p_bram

  memcpy(v338, v336, 32 * sizeof(float));	// L525

  for (int v339 = 0; v339 < 32; v339 += 1) {	// L526
    for (int v340 = 0; v340 < 28; v340 += 1) {	// L527
      for (int v341 = 0; v341 < 28; v341 += 1) {	// L528
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v338
        #pragma HLS dependence false variable=v337
        float v342 = v338[v339];	// L529
        v337[0][v339][v340][v341] = v342;	// L530
      }
    }
  }
}

void kernel67(
  float v343[1][1][28][28],
  float v344[1][1][30][30]
) {	// L536
  for (int v345 = 0; v345 < 28; v345 += 1) {	// L537
    for (int v346 = 0; v346 < 28; v346 += 1) {	// L538
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v343
      #pragma HLS dependence false variable=v344
      float v347 = v343[0][0][v345][v346];	// L539
      v344[0][0][(v345 + 1)][(v346 + 1)] = v347;	// L540
    }
  }
}

void kernel68(
  float v348[1][1][30][30],
  float v349
) {	// L545
  for (int v350 = 0; v350 < 30; v350 += 1) {	// L546
    for (int v351 = 0; v351 < 30; v351 += 1) {	// L547
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v348
      v348[0][0][v350][v351] = v349;	// L548
    }
  }
}

/// The top function
void control(
  ap_int<32> v352[5092864],
  ap_int<32> v353[5092864],
  ap_int<32> v354[5092864]
) {	// L553
  #pragma HLS interface s_axilite port=return bundle=ctrl
  #pragma hls interface m_axi offset=direct bundle=g0 port=v352
  #pragma hls stable variable=v352
  #pragma hls interface m_axi offset=direct bundle=g0 port=v353
  #pragma hls stable variable=v353
  #pragma hls interface m_axi offset=direct bundle=g0 port=v354
  #pragma hls stable variable=v354

  auto v355 = reinterpret_cast<float(*)[1][30][30]>(v352 + 150528);
  kernel68(v355, (float)0.000000);	// L560
  auto v356 = reinterpret_cast<float(*)[1][28][28]>(v352);
  kernel67(v356, v355);	// L562
  auto v357 = reinterpret_cast<float(*)[32][28][28]>(v353 + 175616);
  auto v358 = reinterpret_cast<float(*)>(v354 + 3487232);
  kernel66(v358, v357);	// L565
  auto v359 = reinterpret_cast<float(*)[1][3][3]>(v354 + 4290048);
  kernel65(v355, v359, v357);	// L567
  auto v360 = reinterpret_cast<float(*)[32][28][28]>(v352 + 25088);
  auto v361 = reinterpret_cast<float(*)[32][28][28]>(v352 + 150528);
  kernel64(v357, v360, v361);	// L570
  kernel54(v361, v357);	// L571
  kernel62(v357, (float)1.000000);	// L572
  auto v362 = reinterpret_cast<float(*)[32][28][28]>(v352 + 200704);
  kernel54(v357, v362);	// L574
  kernel60(v362, (float)1.000000, (float)0.000000);	// L575
  kernel59(v361, v362, v357);	// L576
  auto v363 = reinterpret_cast<float(*)[32][28][28]>(v352 + 225792);
  kernel58(v357, v361, v363);	// L578
  kernel54(v362, v357);	// L579
  kernel56(v357, (float)0.000000);	// L580
  kernel55(v363, v357);	// L581
  kernel54(v357, v360);	// L582
  auto v364 = reinterpret_cast<float(*)[32][14][14]>(v352 + 150528);
  kernel53(v364, (float)-INFINITY);	// L584
  auto v365 = reinterpret_cast<float(*)[2]>(v352 + 175616);
  kernel52(v362, v365, v364);	// L586
  auto v366 = reinterpret_cast<float(*)[32][16][16]>(v352 + 200704);
  kernel51(v366, (float)0.000000);	// L588
  kernel50(v364, v366);	// L589
  auto v367 = reinterpret_cast<float(*)[32][14][14]>(v353 + 225792);
  auto v368 = reinterpret_cast<float(*)>(v354 + 1881600);
  kernel49(v368, v367);	// L592
  auto v369 = reinterpret_cast<float(*)[32][3][3]>(v354 + 2684416);
  kernel48(v366, v369, v367);	// L594
  auto v370 = reinterpret_cast<float(*)[32][14][14]>(v352 + 50176);
  kernel32(v370, v364);	// L596
  kernel43(v364, (float)2.000000);	// L597
  auto v371 = reinterpret_cast<float(*)[32][14][14]>(v353 + 200704);
  kernel36(v364, v370, v371);	// L599
  kernel32(v367, v364);	// L600
  kernel43(v364, (float)2.000000);	// L601
  auto v372 = reinterpret_cast<float(*)[32][14][14]>(v354 + 225792);
  kernel42(v364, v371, v372);	// L603
  kernel32(v372, v364);	// L604
  kernel40(v364, (float)1.000000);	// L605
  kernel32(v364, v371);	// L606
  kernel38(v371, (float)1.000000, (float)0.000000);	// L607
  kernel37(v372, v371, v364);	// L608
  auto v373 = reinterpret_cast<float(*)[32][14][14]>(v353 + 250880);
  kernel36(v364, v372, v373);	// L610
  kernel32(v371, v364);	// L611
  kernel34(v364, (float)0.000000);	// L612
  kernel33(v373, v364);	// L613
  kernel32(v364, v370);	// L614
  auto v374 = reinterpret_cast<float(*)[32][7][7]>(v354 + 150528);
  kernel31(v374, (float)-INFINITY);	// L616
  kernel30(v371, v365, v374);	// L617
  auto v375 = reinterpret_cast<float(*)[512]>(v352 + 175616);
  kernel29(v375, (float)0.000000);	// L619
  auto v376 = reinterpret_cast<float(*)[512]>(v353 + 1078784);
  kernel28(v374, v376, v375);	// L621
  auto v377 = reinterpret_cast<float(*)[512]>(v352 + 75264);
  auto v378 = reinterpret_cast<float(*)[512]>(v352 + 150528);
  kernel13(v377, v378);	// L624
  kernel23(v378, (float)0.858491);	// L625
  auto v379 = reinterpret_cast<float(*)[512]>(v353 + 200704);
  kernel17(v378, v377, v379);	// L627
  kernel13(v375, v378);	// L628
  kernel23(v378, (float)0.858491);	// L629
  kernel22(v378, v379, v375);	// L630
  kernel13(v375, v378);	// L631
  kernel20(v378, (float)1.000000);	// L632
  kernel13(v378, v379);	// L633
  kernel18(v379, (float)1.000000, (float)0.000000);	// L634
  auto v380 = reinterpret_cast<float(*)[512]>(v354 + 225792);
  kernel17(v379, v375, v380);	// L636
  kernel13(v379, v378);	// L637
  kernel15(v378, (float)0.000000);	// L638
  kernel14(v380, v378);	// L639
  kernel13(v378, v377);	// L640
  auto v381 = reinterpret_cast<float(*)[10]>(v352 + 150528);
  kernel12(v381, (float)0.000000);	// L642
  auto v382 = reinterpret_cast<float(*)[10]>(v354 + 275968);
  kernel11(v379, v382, v381);	// L644
  auto v383 = reinterpret_cast<float(*)[10]>(v352 + 100352);
  auto v384 = reinterpret_cast<float(*)[10]>(v354 + 175616);
  kernel10(v381, v383, v384);	// L647
  kernel0(v384, v381);	// L648
  kernel8(v381, (float)1.000000);	// L649
  auto v385 = reinterpret_cast<float(*)[10]>(v352 + 125440);
  kernel0(v381, v385);	// L651
  kernel6(v385, (float)1.000000, (float)0.000000);	// L652
  kernel5(v384, v385, v381);	// L653
  auto v386 = reinterpret_cast<float(*)[10]>(v353 + 200704);
  kernel4(v381, v384, v386);	// L655
  kernel0(v385, v381);	// L656
  kernel2(v381, (float)0.000000);	// L657
  kernel1(v386, v381);	// L658
  kernel0(v381, v383);	// L659
}

