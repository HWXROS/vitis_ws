
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
  float v53[1][384][8][8];	// L90
  #pragma HLS resource variable=v53 core=ram_t2p_bram

  memcpy(v53, v52, 24576 * sizeof(float));	// L91

  auto v54 = reinterpret_cast<float(*)[1536][1][1]>(v51);	// L93

  for (int v55 = 0; v55 < 1536; v55 += 1) {	// L94
    for (int v56 = 0; v56 < 384; v56 += 1) {	// L95
      float v57 = v54[v56][v55][0][0];	// L96
      for (int v58 = 0; v58 < 8; v58 += 1) {	// L97
        for (int v59 = 0; v59 < 8; v59 += 1) {	// L98
          #pragma HLS pipeline II=1
          #pragma HLS dependence false variable=v50
          #pragma HLS dependence false variable=v53
          float v60 = v50[0][v55][v58][v59];	// L99
          float v61 = v53[0][v56][v58][v59];	// L100
          bool v62 = v60 != (float)0.000000;	// L101
          float v63 = v61 + v57;	// L102
          float v64 = v62 ? v63 : v61;	// L103
          v53[0][v56][v58][v59] = v64;	// L104
        }
      }
    }
  }
  memcpy(v52, v53, 24576 * sizeof(float));	// L109

}

void kernel8(
  float v65[384],
  float v66[1][384][8][8]
) {	// L112
  float v67[384];	// L113
  #pragma HLS resource variable=v67 core=ram_t2p_bram

  memcpy(v67, v65, 384 * sizeof(float));	// L114

  for (int v68 = 0; v68 < 384; v68 += 1) {	// L115
    for (int v69 = 0; v69 < 8; v69 += 1) {	// L116
      for (int v70 = 0; v70 < 8; v70 += 1) {	// L117
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v67
        #pragma HLS dependence false variable=v66
        float v71 = v67[v68];	// L118
        v66[0][v68][v69][v70] = v71;	// L119
      }
    }
  }
}

void kernel9(
  float v72[1][1536][8][8],
  float v73[1][1536][8][8]
) {	// L125
  for (int v74 = 0; v74 < 1536; v74 += 1) {	// L126
    for (int v75 = 0; v75 < 8; v75 += 1) {	// L127
      for (int v76 = 0; v76 < 8; v76 += 1) {	// L128
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v72
        #pragma HLS dependence false variable=v73
        float v77 = v72[0][v74][v75][v76];	// L129
        v73[0][v74][v75][v76] = v77;	// L130
      }
    }
  }
}

void kernel10(
  float v78[1][1536][8][8],
  float v79[1][1536][8][8],
  float v80
) {	// L136
  for (int v81 = 0; v81 < 1536; v81 += 1) {	// L138
    for (int v82 = 0; v82 < 8; v82 += 1) {	// L139
      for (int v83 = 0; v83 < 8; v83 += 1) {	// L140
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v79
        #pragma HLS dependence false variable=v78
        float v84 = v79[0][v81][v82][v83];	// L141
        float v85 = v78[0][v81][v82][v83];	// L142
        float v86 = v85 * v84;	// L143
        float v87 = v84 - v86;	// L144
        bool v88 = v85 != (float)0.000000;	// L145
        float v89 = v87 + v80;	// L146
        float v90 = v88 ? v89 : v87;	// L147
        v79[0][v81][v82][v83] = v90;	// L148
      }
    }
  }
}

void kernel11(
  float v91[1][1536][8][8],
  float v92,
  float v93
) {	// L154
  for (int v94 = 0; v94 < 1536; v94 += 1) {	// L155
    for (int v95 = 0; v95 < 8; v95 += 1) {	// L156
      for (int v96 = 0; v96 < 8; v96 += 1) {	// L157
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v91
        float v97 = v91[0][v94][v95][v96];	// L158
        float v98 = v97 - v93;	// L159
        bool v99 = v98 >= v92;	// L160
        float v100 = v99 ? v93 : v92;	// L161
        v91[0][v94][v95][v96] = v100;	// L162
      }
    }
  }
}

void kernel13(
  float v101[1][1536][8][8],
  float v102[1][1536][8][8],
  float v103
) {	// L168
  for (int v104 = 0; v104 < 1536; v104 += 1) {	// L169
    for (int v105 = 0; v105 < 8; v105 += 1) {	// L170
      for (int v106 = 0; v106 < 8; v106 += 1) {	// L171
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v101
        #pragma HLS dependence false variable=v102
        float v107 = v101[0][v104][v105][v106];	// L172
        float v108 = v102[0][v104][v105][v106];	// L173
        float v109 = v108 / v103;	// L174
        float v110 = v107 / v103;	// L175
        float v111 = v107 - v110;	// L176
        float v112 = v111 + v109;	// L177
        v102[0][v104][v105][v106] = v112;	// L178
      }
    }
  }
}

void kernel14(
  float v113[1][384][8][8],
  float v114[1536][384][1][1],
  float v115[1][1536][8][8]
) {	// L184
  float v116[1][384][8][8];	// L186
  #pragma HLS resource variable=v116 core=ram_t2p_bram

  memcpy(v116, v113, 24576 * sizeof(float));	// L187

  auto v117 = reinterpret_cast<float(*)[384][1][1]>(v114);	// L189

  for (int v118 = 0; v118 < 384; v118 += 1) {	// L190
    for (int v119 = 0; v119 < 1536; v119 += 1) {	// L191
      float v120 = v117[v119][v118][0][0];	// L192
      for (int v121 = 0; v121 < 8; v121 += 1) {	// L193
        for (int v122 = 0; v122 < 8; v122 += 1) {	// L194
          #pragma HLS pipeline II=1
          #pragma HLS dependence false variable=v116
          #pragma HLS dependence false variable=v115
          float v123 = v116[0][v118][v121][v122];	// L195
          float v124 = v115[0][v119][v121][v122];	// L196
          bool v125 = v123 != (float)0.000000;	// L197
          float v126 = v124 + v120;	// L198
          float v127 = v125 ? v126 : v124;	// L199
          v115[0][v119][v121][v122] = v127;	// L200
        }
      }
    }
  }
}

void kernel15(
  float v128[1536],
  float v129[1][1536][8][8]
) {	// L207
  float v130[1536];	// L208
  #pragma HLS resource variable=v130 core=ram_t2p_bram

  memcpy(v130, v128, 1536 * sizeof(float));	// L209

  for (int v131 = 0; v131 < 1536; v131 += 1) {	// L210
    for (int v132 = 0; v132 < 8; v132 += 1) {	// L211
      for (int v133 = 0; v133 < 8; v133 += 1) {	// L212
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v130
        #pragma HLS dependence false variable=v129
        float v134 = v130[v131];	// L213
        v129[0][v131][v132][v133] = v134;	// L214
      }
    }
  }
}

void kernel16(
  float v135[1][384][8][8],
  float v136[1][384][8][8]
) {	// L220
  for (int v137 = 0; v137 < 384; v137 += 1) {	// L221
    for (int v138 = 0; v138 < 8; v138 += 1) {	// L222
      for (int v139 = 0; v139 < 8; v139 += 1) {	// L223
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v135
        #pragma HLS dependence false variable=v136
        float v140 = v135[0][v137][v138][v139];	// L224
        v136[0][v137][v138][v139] = v140;	// L225
      }
    }
  }
}

void kernel17(
  float v141[1][384][8][8],
  float v142[1][384][8][8],
  float v143
) {	// L231
  for (int v144 = 0; v144 < 384; v144 += 1) {	// L233
    for (int v145 = 0; v145 < 8; v145 += 1) {	// L234
      for (int v146 = 0; v146 < 8; v146 += 1) {	// L235
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v142
        #pragma HLS dependence false variable=v141
        float v147 = v142[0][v144][v145][v146];	// L236
        float v148 = v141[0][v144][v145][v146];	// L237
        float v149 = v148 * v147;	// L238
        float v150 = v147 - v149;	// L239
        bool v151 = v148 != (float)0.000000;	// L240
        float v152 = v150 + v143;	// L241
        float v153 = v151 ? v152 : v150;	// L242
        v142[0][v144][v145][v146] = v153;	// L243
      }
    }
  }
}

void kernel18(
  float v154[1][384][8][8],
  float v155,
  float v156
) {	// L249
  for (int v157 = 0; v157 < 384; v157 += 1) {	// L250
    for (int v158 = 0; v158 < 8; v158 += 1) {	// L251
      for (int v159 = 0; v159 < 8; v159 += 1) {	// L252
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v154
        float v160 = v154[0][v157][v158][v159];	// L253
        float v161 = v160 - v156;	// L254
        bool v162 = v161 >= v155;	// L255
        float v163 = v162 ? v156 : v155;	// L256
        v154[0][v157][v158][v159] = v163;	// L257
      }
    }
  }
}

void kernel20(
  float v164[1][384][8][8],
  float v165[1][384][8][8],
  float v166[1][384][8][8],
  float v167
) {	// L263
  for (int v168 = 0; v168 < 384; v168 += 1) {	// L264
    for (int v169 = 0; v169 < 8; v169 += 1) {	// L265
      for (int v170 = 0; v170 < 8; v170 += 1) {	// L266
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v164
        #pragma HLS dependence false variable=v166
        #pragma HLS dependence false variable=v165
        float v171 = v164[0][v168][v169][v170];	// L267
        float v172 = v165[0][v168][v169][v170];	// L268
        float v173 = v172 / v167;	// L269
        float v174 = v171 / v167;	// L270
        float v175 = v171 - v174;	// L271
        float v176 = v175 + v173;	// L272
        v166[0][v168][v169][v170] = v176;	// L273
      }
    }
  }
}

void kernel21(
  float v177[1][384][64],
  float v178[1][384][8][8],
  float v179[1][384][8][8]
) {	// L279
  for (int v180 = 0; v180 < 384; v180 += 1) {	// L280
    for (int v181 = 0; v181 < 8; v181 += 1) {	// L281
      for (int v182 = 0; v182 < 8; v182 += 1) {	// L282
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v178
        #pragma HLS dependence false variable=v179
        #pragma HLS dependence false variable=v177
        float v183 = v178[0][v180][v181][v182];	// L283
        float v184 = v177[0][v180][((v181 * 8) + v182)];	// L284
        float v185 = v183 + v184;	// L285
        v179[0][v180][v181][v182] = v185;	// L286
      }
    }
  }
}

void kernel22(
  float v186[1][384][64],
  float v187[384][384][1],
  float v188[1][384][64]
) {	// L292
  float v189[1][384][64];	// L294
  #pragma HLS resource variable=v189 core=ram_t2p_bram

  memcpy(v189, v186, 24576 * sizeof(float));	// L295

  float v190[1][384][64];	// L296
  #pragma HLS resource variable=v190 core=ram_t2p_bram

  memcpy(v190, v188, 24576 * sizeof(float));	// L297

  auto v191 = reinterpret_cast<float(*)[384][1]>(v187);	// L299

  for (int v192 = 0; v192 < 384; v192 += 1) {	// L300
    for (int v193 = 0; v193 < 384; v193 += 1) {	// L301
      float v194 = v191[v193][v192][0];	// L302
      for (int v195 = 0; v195 < 64; v195 += 1) {	// L303
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v189
        #pragma HLS dependence false variable=v190
        float v196 = v189[0][v192][v195];	// L304
        float v197 = v190[0][v193][v195];	// L305
        bool v198 = v196 != (float)0.000000;	// L306
        float v199 = v197 + v194;	// L307
        float v200 = v198 ? v199 : v197;	// L308
        v190[0][v193][v195] = v200;	// L309
      }
    }
  }
  memcpy(v188, v190, 24576 * sizeof(float));	// L313

}

void kernel23(
  float v201[384],
  float v202[1][384][64]
) {	// L316
  float v203[384];	// L317
  #pragma HLS resource variable=v203 core=ram_t2p_bram

  memcpy(v203, v201, 384 * sizeof(float));	// L318

  for (int v204 = 0; v204 < 384; v204 += 1) {	// L319
    for (int v205 = 0; v205 < 64; v205 += 1) {	// L320
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v203
      #pragma HLS dependence false variable=v202
      float v206 = v203[v204];	// L321
      v202[0][v204][v205] = v206;	// L322
    }
  }
}

void kernel24(
  float v207[1][64][384],
  float v208[1][384][64]
) {	// L327
  for (int v209 = 0; v209 < 384; v209 += 1) {	// L328
    for (int v210 = 0; v210 < 64; v210 += 1) {	// L329
      float v211 = v207[0][v210][v209];	// L330
      v208[0][v209][v210] = v211;	// L331
    }
  }
}

void kernel25(
  float v212[1][64][384],
  float v213[1][64][384]
) {	// L336
  for (int v214 = 0; v214 < 64; v214 += 1) {	// L337
    for (int v215 = 0; v215 < 384; v215 += 1) {	// L338
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v212
      #pragma HLS dependence false variable=v213
      float v216 = v212[0][v214][v215];	// L339
      v213[0][v214][v215] = v216;	// L340
    }
  }
}

void kernel26(
  float v217[1][64][12][32],
  float v218[1][64][384],
  float v219[1][64][384],
  float v220
) {	// L345
  for (int v221 = 0; v221 < 64; v221 += 1) {	// L347
    for (int v222 = 0; v222 < 384; v222 += 1) {	// L348
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v217
      #pragma HLS dependence false variable=v219
      #pragma HLS dependence false variable=v218
      float v223 = v217[0][v221][(v222 / 32)][(v222 % 32)];	// L349
      float v224 = v218[0][v221][v222];	// L350
      float v225 = v224 * v223;	// L351
      float v226 = v223 - v225;	// L352
      bool v227 = v224 != (float)0.000000;	// L353
      float v228 = v226 + v220;	// L354
      float v229 = v227 ? v228 : v226;	// L355
      v219[0][v221][v222] = v229;	// L356
    }
  }
}

void kernel27(
  float v230[1][64][384],
  float v231,
  float v232,
  float v233
) {	// L361
  for (int v234 = 0; v234 < 64; v234 += 1) {	// L362
    for (int v235 = 0; v235 < 384; v235 += 1) {	// L363
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v230
      float v236 = v230[0][v234][v235];	// L364
      float v237 = v236 - v232;	// L365
      bool v238 = v237 >= v233;	// L366
      float v239 = v238 ? v231 : v233;	// L367
      v230[0][v234][v235] = v239;	// L368
    }
  }
}

void kernel28(
  float v240[1][64][12][32],
  float v241[1][64][384]
) {	// L373
  for (int v242 = 0; v242 < 64; v242 += 1) {	// L374
    for (int v243 = 0; v243 < 384; v243 += 1) {	// L375
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v240
      #pragma HLS dependence false variable=v241
      float v244 = v240[0][v242][(v243 / 32)][(v243 % 32)];	// L376
      v241[0][v242][v243] = v244;	// L377
    }
  }
}

void kernel29(
  float v245[1][64][384],
  float v246[1][64][12][32],
  float v247[1][64][12][32],
  float v248
) {	// L382
  for (int v249 = 0; v249 < 64; v249 += 1) {	// L383
    for (int v250 = 0; v250 < 12; v250 += 1) {	// L384
      for (int v251 = 0; v251 < 32; v251 += 1) {	// L385
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v245
        #pragma HLS dependence false variable=v247
        #pragma HLS dependence false variable=v246
        float v252 = v245[0][v249][((v250 * 32) + v251)];	// L386
        float v253 = v246[0][v249][v250][v251];	// L387
        float v254 = v253 / v248;	// L388
        float v255 = v252 / v248;	// L389
        float v256 = v252 - v255;	// L390
        float v257 = v256 + v254;	// L391
        v247[0][v249][v250][v251] = v257;	// L392
      }
    }
  }
}

void kernel30(
  float v258[1][12][64][32],
  float v259[1][64][12][32]
) {	// L398
  for (int v260 = 0; v260 < 64; v260 += 1) {	// L399
    for (int v261 = 0; v261 < 12; v261 += 1) {	// L400
      for (int v262 = 0; v262 < 32; v262 += 1) {	// L401
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v258
        #pragma HLS dependence false variable=v259
        float v263 = v258[0][v261][v260][v262];	// L402
        v259[0][v260][v261][v262] = v263;	// L403
      }
    }
  }
}

void kernel31(
  float v264[1][12][64][32],
  float v265
) {	// L409
  for (int v266 = 0; v266 < 12; v266 += 1) {	// L410
    for (int v267 = 0; v267 < 64; v267 += 1) {	// L411
      for (int v268 = 0; v268 < 32; v268 += 1) {	// L412
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v264
        float v269 = v264[0][v266][v267][v268];	// L413
        float v270 = v269 * v265;	// L414
        v264[0][v266][v267][v268] = v270;	// L415
      }
    }
  }
}

void kernel32(
  float v271[12][64][32],
  float v272[1][12][64][32]
) {	// L421
  for (int v273 = 0; v273 < 12; v273 += 1) {	// L422
    for (int v274 = 0; v274 < 64; v274 += 1) {	// L423
      for (int v275 = 0; v275 < 32; v275 += 1) {	// L424
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v271
        #pragma HLS dependence false variable=v272
        float v276 = v271[v273][v274][v275];	// L425
        v272[0][v273][v274][v275] = v276;	// L426
      }
    }
  }
}

void kernel33(
  float v277[1][1][12][64][32],
  float v278[12][64][64],
  float v279[12][64][32]
) {	// L432
  float v280[12][64][32];	// L433
  #pragma HLS resource variable=v280 core=ram_t2p_bram

  memcpy(v280, v279, 24576 * sizeof(float));	// L434

  auto v281 = reinterpret_cast<float(*)[64][64]>(v278);	// L436

  for (int v282 = 0; v282 < 64; v282 += 1) {	// L437
    for (int v283 = 0; v283 < 12; v283 += 1) {	// L438
      for (int v284 = 0; v284 < 64; v284 += 1) {	// L439
        float v285 = v281[v283][v284][v282];	// L440
        for (int v286 = 0; v286 < 32; v286 += 1) {	// L441
          #pragma HLS pipeline II=1
          #pragma HLS dependence false variable=v277
          #pragma HLS dependence false variable=v280
          float v287 = v277[0][0][v283][v282][v286];	// L442
          float v288 = v280[v283][v284][v286];	// L443
          float v289 = v285 * v287;	// L444
          float v290 = v288 + v289;	// L445
          v280[v283][v284][v286] = v290;	// L446
        }
      }
    }
  }
  memcpy(v279, v280, 24576 * sizeof(float));	// L451

}

void kernel34(
  float v291[12][64][32],
  float v292
) {	// L454
  for (int v293 = 0; v293 < 12; v293 += 1) {	// L455
    for (int v294 = 0; v294 < 64; v294 += 1) {	// L456
      for (int v295 = 0; v295 < 32; v295 += 1) {	// L457
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v291
        v291[v293][v294][v295] = v292;	// L458
      }
    }
  }
}

void kernel35(
  float v296[1][12][64][32],
  float v297[1][1][12][64][32]
) {	// L464
  for (int v298 = 0; v298 < 12; v298 += 1) {	// L465
    for (int v299 = 0; v299 < 64; v299 += 1) {	// L466
      for (int v300 = 0; v300 < 32; v300 += 1) {	// L467
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v296
        #pragma HLS dependence false variable=v297
        float v301 = v296[0][v298][v299][v300];	// L468
        v297[0][0][v298][v299][v300] = v301;	// L469
      }
    }
  }
}

void kernel36(
  float v302[1][1][12][64][32],
  float v303[1][1][12][32][64],
  float v304[12][64][64]
) {	// L475
  auto v305 = reinterpret_cast<float(*)[1][12][64][32]>(v302);	// L477

  for (int v306 = 0; v306 < 32; v306 += 1) {	// L478
    for (int v307 = 0; v307 < 12; v307 += 1) {	// L479
      for (int v308 = 0; v308 < 64; v308 += 1) {	// L480
        float v309 = v305[0][0][v307][v308][v306];	// L481
        for (int v310 = 0; v310 < 64; v310 += 1) {	// L482
          #pragma HLS pipeline II=1
          #pragma HLS dependence false variable=v303
          #pragma HLS dependence false variable=v304
          float v311 = v303[0][0][v307][v306][v310];	// L483
          float v312 = v304[v307][v308][v310];	// L484
          float v313 = v309 * v311;	// L485
          float v314 = v312 + v313;	// L486
          v304[v307][v308][v310] = v314;	// L487
        }
      }
    }
  }
}

void kernel37(
  float v315[1][12][32][64],
  float v316[1][1][12][32][64]
) {	// L494
  for (int v317 = 0; v317 < 12; v317 += 1) {	// L495
    for (int v318 = 0; v318 < 32; v318 += 1) {	// L496
      for (int v319 = 0; v319 < 64; v319 += 1) {	// L497
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v315
        #pragma HLS dependence false variable=v316
        float v320 = v315[0][v317][v318][v319];	// L498
        v316[0][0][v317][v318][v319] = v320;	// L499
      }
    }
  }
}

void kernel39(
  float v321[1][64][12][32],
  float v322[1][12][32][64]
) {	// L505
  for (int v323 = 0; v323 < 12; v323 += 1) {	// L506
    for (int v324 = 0; v324 < 32; v324 += 1) {	// L507
      for (int v325 = 0; v325 < 64; v325 += 1) {	// L508
        float v326 = v321[0][v325][v323][v324];	// L509
        v322[0][v323][v324][v325] = v326;	// L510
      }
    }
  }
}

void kernel40(
  float v327[1][64][12][32],
  float v328[1][12][64][32]
) {	// L516
  for (int v329 = 0; v329 < 12; v329 += 1) {	// L517
    for (int v330 = 0; v330 < 64; v330 += 1) {	// L518
      for (int v331 = 0; v331 < 32; v331 += 1) {	// L519
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v327
        #pragma HLS dependence false variable=v328
        float v332 = v327[0][v330][v329][v331];	// L520
        v328[0][v329][v330][v331] = v332;	// L521
      }
    }
  }
}

void kernel41(
  float v333[1][384][64],
  float v334[1][64][12][32]
) {	// L527
  for (int v335 = 0; v335 < 64; v335 += 1) {	// L528
    for (int v336 = 0; v336 < 12; v336 += 1) {	// L529
      for (int v337 = 0; v337 < 32; v337 += 1) {	// L530
        float v338 = v333[0][((v336 * 32) + v337)][v335];	// L531
        v334[0][v335][v336][v337] = v338;	// L532
      }
    }
  }
}

void kernel42(
  float v339[1][384][64],
  float v340[1][384][64]
) {	// L538
  for (int v341 = 0; v341 < 384; v341 += 1) {	// L539
    for (int v342 = 0; v342 < 64; v342 += 1) {	// L540
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v339
      #pragma HLS dependence false variable=v340
      float v343 = v339[0][v341][v342];	// L541
      v340[0][v341][v342] = v343;	// L542
    }
  }
}

void kernel43(
  float v344[1][384][64],
  float v345[1][384][64],
  float v346
) {	// L547
  for (int v347 = 0; v347 < 384; v347 += 1) {	// L549
    for (int v348 = 0; v348 < 64; v348 += 1) {	// L550
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v345
      #pragma HLS dependence false variable=v344
      float v349 = v345[0][v347][v348];	// L551
      float v350 = v344[0][v347][v348];	// L552
      float v351 = v350 * v349;	// L553
      float v352 = v349 - v351;	// L554
      bool v353 = v350 != (float)0.000000;	// L555
      float v354 = v352 + v346;	// L556
      float v355 = v353 ? v354 : v352;	// L557
      v345[0][v347][v348] = v355;	// L558
    }
  }
}

void kernel44(
  float v356[1][384][64],
  float v357,
  float v358
) {	// L563
  for (int v359 = 0; v359 < 384; v359 += 1) {	// L564
    for (int v360 = 0; v360 < 64; v360 += 1) {	// L565
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v356
      float v361 = v356[0][v359][v360];	// L566
      float v362 = v361 - v358;	// L567
      bool v363 = v362 >= v357;	// L568
      float v364 = v363 ? v358 : v357;	// L569
      v356[0][v359][v360] = v364;	// L570
    }
  }
}

void kernel46(
  float v365[1][384][64],
  float v366[1][384][64],
  float v367
) {	// L575
  for (int v368 = 0; v368 < 384; v368 += 1) {	// L576
    for (int v369 = 0; v369 < 64; v369 += 1) {	// L577
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v365
      #pragma HLS dependence false variable=v366
      float v370 = v365[0][v368][v369];	// L578
      float v371 = v366[0][v368][v369];	// L579
      float v372 = v371 / v367;	// L580
      float v373 = v370 / v367;	// L581
      float v374 = v370 - v373;	// L582
      float v375 = v374 + v372;	// L583
      v366[0][v368][v369] = v375;	// L584
    }
  }
}

void kernel47(
  float v376[1][384][8][8],
  float v377[384][384][1],
  float v378[1][384][64]
) {	// L589
  float v379[1][384][8][8];	// L591
  #pragma HLS resource variable=v379 core=ram_t2p_bram

  memcpy(v379, v376, 24576 * sizeof(float));	// L592

  float v380[1][384][64];	// L593
  #pragma HLS resource variable=v380 core=ram_t2p_bram

  memcpy(v380, v378, 24576 * sizeof(float));	// L594

  auto v381 = reinterpret_cast<float(*)[384][1]>(v377);	// L596

  for (int v382 = 0; v382 < 384; v382 += 1) {	// L597
    for (int v383 = 0; v383 < 384; v383 += 1) {	// L598
      float v384 = v381[v383][v382][0];	// L599
      for (int v385 = 0; v385 < 64; v385 += 1) {	// L600
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v379
        #pragma HLS dependence false variable=v380
        float v386 = v379[0][v382][(v385 / 8)][(v385 % 8)];	// L601
        float v387 = v380[0][v383][v385];	// L602
        bool v388 = v386 != (float)0.000000;	// L603
        float v389 = v387 + v384;	// L604
        float v390 = v388 ? v389 : v387;	// L605
        v380[0][v383][v385] = v390;	// L606
      }
    }
  }
  memcpy(v378, v380, 24576 * sizeof(float));	// L610

}

void kernel71(
  float v391[1][384][8][8],
  float v392[1][384][8][8],
  float v393[1][384][8][8]
) {	// L613
  for (int v394 = 0; v394 < 384; v394 += 1) {	// L614
    for (int v395 = 0; v395 < 8; v395 += 1) {	// L615
      for (int v396 = 0; v396 < 8; v396 += 1) {	// L616
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v392
        #pragma HLS dependence false variable=v393
        #pragma HLS dependence false variable=v391
        float v397 = v392[0][v394][v395][v396];	// L617
        float v398 = v391[0][v394][v395][v396];	// L618
        float v399 = v397 + v398;	// L619
        v393[0][v394][v395][v396] = v399;	// L620
      }
    }
  }
}

void kernel99(
  float v400[12][64][32],
  float v401
) {	// L626
  for (int v402 = 0; v402 < 12; v402 += 1) {	// L627
    for (int v403 = 0; v403 < 64; v403 += 1) {	// L628
      for (int v404 = 0; v404 < 32; v404 += 1) {	// L629
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v400
        v400[v402][v403][v404] = v401;	// L630
      }
    }
  }
}

void kernel102(
  float v405[12][64][64],
  float v406[12][64][64]
) {	// L636
  for (int v407 = 0; v407 < 12; v407 += 1) {	// L637
    for (int v408 = 0; v408 < 64; v408 += 1) {	// L638
      for (int v409 = 0; v409 < 64; v409 += 1) {	// L639
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v405
        #pragma HLS dependence false variable=v406
        float v410 = v405[v407][v408][v409];	// L640
        v406[v407][v408][v409] = v410;	// L641
      }
    }
  }
}

void kernel165(
  float v411[12][64][32],
  float v412
) {	// L647
  for (int v413 = 0; v413 < 12; v413 += 1) {	// L648
    for (int v414 = 0; v414 < 64; v414 += 1) {	// L649
      for (int v415 = 0; v415 < 32; v415 += 1) {	// L650
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v411
        v411[v413][v414][v415] = v412;	// L651
      }
    }
  }
}

void kernel231(
  float v416[12][64][32],
  float v417
) {	// L657
  for (int v418 = 0; v418 < 12; v418 += 1) {	// L658
    for (int v419 = 0; v419 < 64; v419 += 1) {	// L659
      for (int v420 = 0; v420 < 32; v420 += 1) {	// L660
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v416
        v416[v418][v419][v420] = v417;	// L661
      }
    }
  }
}

void kernel235(
  float v421[12][64][64],
  float v422
) {	// L667
  for (int v423 = 0; v423 < 12; v423 += 1) {	// L668
    for (int v424 = 0; v424 < 64; v424 += 1) {	// L669
      for (int v425 = 0; v425 < 64; v425 += 1) {	// L670
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v421
        v421[v423][v424][v425] = v422;	// L671
      }
    }
  }
}

void kernel270(
  float v426[1][384][10][10],
  float v427[384][384][3][3],
  float v428[1][384][8][8]
) {	// L677
  float v429[1][384][10][10];	// L678
  #pragma HLS resource variable=v429 core=ram_t2p_uram

  memcpy(v429, v426, 38400 * sizeof(float));	// L679

  float v430[1][384][8][8];	// L680
  #pragma HLS resource variable=v430 core=ram_t2p_bram

  memcpy(v430, v428, 24576 * sizeof(float));	// L681

  auto v431 = reinterpret_cast<float(*)[384][3][3]>(v427);	// L683

  for (int v432 = 0; v432 < 384; v432 += 1) {	// L684
    for (int v433 = 0; v433 < 3; v433 += 1) {	// L685
      for (int v434 = 0; v434 < 3; v434 += 1) {	// L686
        for (int v435 = 0; v435 < 384; v435 += 1) {	// L687
          float v436 = v431[v435][v432][v433][v434];	// L688
          for (int v437 = 0; v437 < 8; v437 += 1) {	// L689
            for (int v438 = 0; v438 < 8; v438 += 1) {	// L690
              #pragma HLS pipeline II=1
              #pragma HLS dependence false variable=v429
              #pragma HLS dependence false variable=v430
              float v439 = v429[0][v432][(v437 + v433)][(v438 + v434)];	// L691
              float v440 = v430[0][v435][v437][v438];	// L692
              float v441 = v439 * v436;	// L693
              float v442 = v440 + v441;	// L694
              v430[0][v435][v437][v438] = v442;	// L695
            }
          }
        }
      }
    }
  }
  memcpy(v428, v430, 24576 * sizeof(float));	// L702

}

void kernel272(
  float v443[1][384][8][8],
  float v444[1][384][10][10]
) {	// L705
  for (int v445 = 0; v445 < 384; v445 += 1) {	// L706
    for (int v446 = 0; v446 < 8; v446 += 1) {	// L707
      for (int v447 = 0; v447 < 8; v447 += 1) {	// L708
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v443
        #pragma HLS dependence false variable=v444
        float v448 = v443[0][v445][v446][v447];	// L709
        v444[0][v445][(v446 + 1)][(v447 + 1)] = v448;	// L710
      }
    }
  }
}

void kernel273(
  float v449[1][384][10][10],
  float v450
) {	// L716
  for (int v451 = 0; v451 < 384; v451 += 1) {	// L717
    for (int v452 = 0; v452 < 10; v452 += 1) {	// L718
      for (int v453 = 0; v453 < 10; v453 += 1) {	// L719
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v449
        v449[0][v451][v452][v453] = v450;	// L720
      }
    }
  }
}

void kernel274(
  float v454[1][384][18][18],
  float v455[3][3],
  float v456[1][384][8][8]
) {	// L726
  for (int v457 = 0; v457 < 3; v457 += 1) {	// L727
    for (int v458 = 0; v458 < 3; v458 += 1) {	// L728
      for (int v459 = 0; v459 < 384; v459 += 1) {	// L729
        for (int v460 = 0; v460 < 8; v460 += 1) {	// L730
          for (int v461 = 0; v461 < 8; v461 += 1) {	// L731
            #pragma HLS pipeline II=1
            #pragma HLS dependence false variable=v454
            #pragma HLS dependence false variable=v456
            float v462 = v454[0][v459][((v460 * 2) + v457)][((v461 * 2) + v458)];	// L732
            float v463 = v456[0][v459][v460][v461];	// L733
            float v464 = max(v463, v462);	// L734
            v456[0][v459][v460][v461] = v464;	// L735
          }
        }
      }
    }
  }
}

void kernel275(
  float v465[1][384][8][8],
  float v466
) {	// L743
  for (int v467 = 0; v467 < 384; v467 += 1) {	// L744
    for (int v468 = 0; v468 < 8; v468 += 1) {	// L745
      for (int v469 = 0; v469 < 8; v469 += 1) {	// L746
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v465
        v465[0][v467][v468][v469] = v466;	// L747
      }
    }
  }
}

void kernel276(
  float v470[1][384][16][16],
  float v471[1][384][18][18]
) {	// L753
  for (int v472 = 0; v472 < 384; v472 += 1) {	// L754
    for (int v473 = 0; v473 < 16; v473 += 1) {	// L755
      for (int v474 = 0; v474 < 16; v474 += 1) {	// L756
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v470
        #pragma HLS dependence false variable=v471
        float v475 = v470[0][v472][v473][v474];	// L757
        v471[0][v472][(v473 + 1)][(v474 + 1)] = v475;	// L758
      }
    }
  }
}

void kernel277(
  float v476[1][384][18][18],
  float v477
) {	// L764
  for (int v478 = 0; v478 < 384; v478 += 1) {	// L765
    for (int v479 = 0; v479 < 18; v479 += 1) {	// L766
      for (int v480 = 0; v480 < 18; v480 += 1) {	// L767
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v476
        v476[0][v478][v479][v480] = v477;	// L768
      }
    }
  }
}

void kernel278(
  float v481[1][384][16][16],
  float v482[1][384][16][16]
) {	// L774
  for (int v483 = 0; v483 < 384; v483 += 1) {	// L775
    for (int v484 = 0; v484 < 16; v484 += 1) {	// L776
      for (int v485 = 0; v485 < 16; v485 += 1) {	// L777
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v481
        #pragma HLS dependence false variable=v482
        float v486 = v481[0][v483][v484][v485];	// L778
        v482[0][v483][v484][v485] = v486;	// L779
      }
    }
  }
}

void kernel279(
  float v487[1][384][16][16],
  float v488[1][384][16][16],
  float v489
) {	// L785
  for (int v490 = 0; v490 < 384; v490 += 1) {	// L787
    for (int v491 = 0; v491 < 16; v491 += 1) {	// L788
      for (int v492 = 0; v492 < 16; v492 += 1) {	// L789
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v488
        #pragma HLS dependence false variable=v487
        float v493 = v488[0][v490][v491][v492];	// L790
        float v494 = v487[0][v490][v491][v492];	// L791
        float v495 = v494 * v493;	// L792
        float v496 = v493 - v495;	// L793
        bool v497 = v494 != (float)0.000000;	// L794
        float v498 = v496 + v489;	// L795
        float v499 = v497 ? v498 : v496;	// L796
        v488[0][v490][v491][v492] = v499;	// L797
      }
    }
  }
}

void kernel280(
  float v500[1][384][16][16],
  float v501,
  float v502
) {	// L803
  for (int v503 = 0; v503 < 384; v503 += 1) {	// L804
    for (int v504 = 0; v504 < 16; v504 += 1) {	// L805
      for (int v505 = 0; v505 < 16; v505 += 1) {	// L806
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v500
        float v506 = v500[0][v503][v504][v505];	// L807
        float v507 = v506 - v502;	// L808
        bool v508 = v507 >= v501;	// L809
        float v509 = v508 ? v502 : v501;	// L810
        v500[0][v503][v504][v505] = v509;	// L811
      }
    }
  }
}

void kernel282(
  float v510[1][384][16][16],
  float v511[1][384][16][16],
  float v512
) {	// L817
  for (int v513 = 0; v513 < 384; v513 += 1) {	// L818
    for (int v514 = 0; v514 < 16; v514 += 1) {	// L819
      for (int v515 = 0; v515 < 16; v515 += 1) {	// L820
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v510
        #pragma HLS dependence false variable=v511
        float v516 = v510[0][v513][v514][v515];	// L821
        float v517 = v511[0][v513][v514][v515];	// L822
        float v518 = v517 / v512;	// L823
        float v519 = v516 / v512;	// L824
        float v520 = v516 - v519;	// L825
        float v521 = v520 + v518;	// L826
        v511[0][v513][v514][v515] = v521;	// L827
      }
    }
  }
}

void kernel283(
  float v522[1][192][18][18],
  float v523[384][192][3][3],
  float v524[1][384][16][16]
) {	// L833
  float v525[1][384][16][16];	// L834
  #pragma HLS resource variable=v525 core=ram_t2p_uram

  memcpy(v525, v524, 98304 * sizeof(float));	// L835

  auto v526 = reinterpret_cast<float(*)[192][3][3]>(v523);	// L837

  for (int v527 = 0; v527 < 192; v527 += 1) {	// L838
    for (int v528 = 0; v528 < 3; v528 += 1) {	// L839
      for (int v529 = 0; v529 < 3; v529 += 1) {	// L840
        for (int v530 = 0; v530 < 384; v530 += 1) {	// L841
          float v531 = v526[v530][v527][v528][v529];	// L842
          for (int v532 = 0; v532 < 16; v532 += 1) {	// L843
            for (int v533 = 0; v533 < 16; v533 += 1) {	// L844
              #pragma HLS pipeline II=1
              #pragma HLS dependence false variable=v522
              #pragma HLS dependence false variable=v525
              float v534 = v522[0][v527][(v532 + v528)][(v533 + v529)];	// L845
              float v535 = v525[0][v530][v532][v533];	// L846
              float v536 = v534 * v531;	// L847
              float v537 = v535 + v536;	// L848
              v525[0][v530][v532][v533] = v537;	// L849
            }
          }
        }
      }
    }
  }
  memcpy(v524, v525, 98304 * sizeof(float));	// L856

}

void kernel284(
  float v538[384],
  float v539[1][384][16][16]
) {	// L859
  float v540[384];	// L860
  #pragma HLS resource variable=v540 core=ram_t2p_bram

  memcpy(v540, v538, 384 * sizeof(float));	// L861

  for (int v541 = 0; v541 < 384; v541 += 1) {	// L862
    for (int v542 = 0; v542 < 16; v542 += 1) {	// L863
      for (int v543 = 0; v543 < 16; v543 += 1) {	// L864
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v540
        #pragma HLS dependence false variable=v539
        float v544 = v540[v541];	// L865
        v539[0][v541][v542][v543] = v544;	// L866
      }
    }
  }
}

void kernel285(
  float v545[1][192][16][16],
  float v546[1][192][18][18]
) {	// L872
  for (int v547 = 0; v547 < 192; v547 += 1) {	// L873
    for (int v548 = 0; v548 < 16; v548 += 1) {	// L874
      for (int v549 = 0; v549 < 16; v549 += 1) {	// L875
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v545
        #pragma HLS dependence false variable=v546
        float v550 = v545[0][v547][v548][v549];	// L876
        v546[0][v547][(v548 + 1)][(v549 + 1)] = v550;	// L877
      }
    }
  }
}

void kernel286(
  float v551[1][192][18][18],
  float v552
) {	// L883
  for (int v553 = 0; v553 < 192; v553 += 1) {	// L884
    for (int v554 = 0; v554 < 18; v554 += 1) {	// L885
      for (int v555 = 0; v555 < 18; v555 += 1) {	// L886
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v551
        v551[0][v553][v554][v555] = v552;	// L887
      }
    }
  }
}

void kernel287(
  float v556[1][192][34][34],
  float v557[3][3],
  float v558[1][192][16][16]
) {	// L893
  for (int v559 = 0; v559 < 3; v559 += 1) {	// L894
    for (int v560 = 0; v560 < 3; v560 += 1) {	// L895
      for (int v561 = 0; v561 < 192; v561 += 1) {	// L896
        for (int v562 = 0; v562 < 16; v562 += 1) {	// L897
          for (int v563 = 0; v563 < 16; v563 += 1) {	// L898
            #pragma HLS pipeline II=1
            #pragma HLS dependence false variable=v556
            #pragma HLS dependence false variable=v558
            float v564 = v556[0][v561][((v562 * 2) + v559)][((v563 * 2) + v560)];	// L899
            float v565 = v558[0][v561][v562][v563];	// L900
            float v566 = max(v565, v564);	// L901
            v558[0][v561][v562][v563] = v566;	// L902
          }
        }
      }
    }
  }
}

void kernel288(
  float v567[1][192][16][16],
  float v568
) {	// L910
  for (int v569 = 0; v569 < 192; v569 += 1) {	// L911
    for (int v570 = 0; v570 < 16; v570 += 1) {	// L912
      for (int v571 = 0; v571 < 16; v571 += 1) {	// L913
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v567
        v567[0][v569][v570][v571] = v568;	// L914
      }
    }
  }
}

void kernel289(
  float v572[1][192][32][32],
  float v573[1][192][34][34]
) {	// L920
  for (int v574 = 0; v574 < 192; v574 += 1) {	// L921
    for (int v575 = 0; v575 < 32; v575 += 1) {	// L922
      for (int v576 = 0; v576 < 32; v576 += 1) {	// L923
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v572
        #pragma HLS dependence false variable=v573
        float v577 = v572[0][v574][v575][v576];	// L924
        v573[0][v574][(v575 + 1)][(v576 + 1)] = v577;	// L925
      }
    }
  }
}

void kernel290(
  float v578[1][192][34][34],
  float v579
) {	// L931
  for (int v580 = 0; v580 < 192; v580 += 1) {	// L932
    for (int v581 = 0; v581 < 34; v581 += 1) {	// L933
      for (int v582 = 0; v582 < 34; v582 += 1) {	// L934
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v578
        v578[0][v580][v581][v582] = v579;	// L935
      }
    }
  }
}

void kernel291(
  float v583[1][192][32][32],
  float v584[1][192][32][32]
) {	// L941
  for (int v585 = 0; v585 < 192; v585 += 1) {	// L942
    for (int v586 = 0; v586 < 32; v586 += 1) {	// L943
      for (int v587 = 0; v587 < 32; v587 += 1) {	// L944
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v583
        #pragma HLS dependence false variable=v584
        float v588 = v583[0][v585][v586][v587];	// L945
        v584[0][v585][v586][v587] = v588;	// L946
      }
    }
  }
}

void kernel292(
  float v589[1][192][32][32],
  float v590[1][192][32][32],
  float v591
) {	// L952
  for (int v592 = 0; v592 < 192; v592 += 1) {	// L954
    for (int v593 = 0; v593 < 32; v593 += 1) {	// L955
      for (int v594 = 0; v594 < 32; v594 += 1) {	// L956
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v590
        #pragma HLS dependence false variable=v589
        float v595 = v590[0][v592][v593][v594];	// L957
        float v596 = v589[0][v592][v593][v594];	// L958
        float v597 = v596 * v595;	// L959
        float v598 = v595 - v597;	// L960
        bool v599 = v596 != (float)0.000000;	// L961
        float v600 = v598 + v591;	// L962
        float v601 = v599 ? v600 : v598;	// L963
        v590[0][v592][v593][v594] = v601;	// L964
      }
    }
  }
}

void kernel293(
  float v602[1][192][32][32],
  float v603,
  float v604
) {	// L970
  for (int v605 = 0; v605 < 192; v605 += 1) {	// L971
    for (int v606 = 0; v606 < 32; v606 += 1) {	// L972
      for (int v607 = 0; v607 < 32; v607 += 1) {	// L973
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v602
        float v608 = v602[0][v605][v606][v607];	// L974
        float v609 = v608 - v604;	// L975
        bool v610 = v609 >= v603;	// L976
        float v611 = v610 ? v604 : v603;	// L977
        v602[0][v605][v606][v607] = v611;	// L978
      }
    }
  }
}

void kernel295(
  float v612[1][192][32][32],
  float v613[1][192][32][32],
  float v614
) {	// L984
  for (int v615 = 0; v615 < 192; v615 += 1) {	// L985
    for (int v616 = 0; v616 < 32; v616 += 1) {	// L986
      for (int v617 = 0; v617 < 32; v617 += 1) {	// L987
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v612
        #pragma HLS dependence false variable=v613
        float v618 = v612[0][v615][v616][v617];	// L988
        float v619 = v613[0][v615][v616][v617];	// L989
        float v620 = v619 / v614;	// L990
        float v621 = v618 / v614;	// L991
        float v622 = v618 - v621;	// L992
        float v623 = v622 + v620;	// L993
        v613[0][v615][v616][v617] = v623;	// L994
      }
    }
  }
}

void kernel296(
  float v624[1][96][34][34],
  float v625[192][96][3][3],
  float v626[1][192][32][32]
) {	// L1000
  float v627[1][192][32][32];	// L1001
  #pragma HLS resource variable=v627 core=ram_t2p_uram

  memcpy(v627, v626, 196608 * sizeof(float));	// L1002

  auto v628 = reinterpret_cast<float(*)[96][3][3]>(v625);	// L1004

  for (int v629 = 0; v629 < 96; v629 += 1) {	// L1005
    for (int v630 = 0; v630 < 3; v630 += 1) {	// L1006
      for (int v631 = 0; v631 < 3; v631 += 1) {	// L1007
        for (int v632 = 0; v632 < 192; v632 += 1) {	// L1008
          float v633 = v628[v632][v629][v630][v631];	// L1009
          for (int v634 = 0; v634 < 32; v634 += 1) {	// L1010
            for (int v635 = 0; v635 < 32; v635 += 1) {	// L1011
              #pragma HLS pipeline II=1
              #pragma HLS dependence false variable=v624
              #pragma HLS dependence false variable=v627
              float v636 = v624[0][v629][(v634 + v630)][(v635 + v631)];	// L1012
              float v637 = v627[0][v632][v634][v635];	// L1013
              float v638 = v636 * v633;	// L1014
              float v639 = v637 + v638;	// L1015
              v627[0][v632][v634][v635] = v639;	// L1016
            }
          }
        }
      }
    }
  }
  memcpy(v626, v627, 196608 * sizeof(float));	// L1023

}

void kernel297(
  float v640[192],
  float v641[1][192][32][32]
) {	// L1026
  float v642[192];	// L1027
  #pragma HLS resource variable=v642 core=ram_t2p_bram

  memcpy(v642, v640, 192 * sizeof(float));	// L1028

  for (int v643 = 0; v643 < 192; v643 += 1) {	// L1029
    for (int v644 = 0; v644 < 32; v644 += 1) {	// L1030
      for (int v645 = 0; v645 < 32; v645 += 1) {	// L1031
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v642
        #pragma HLS dependence false variable=v641
        float v646 = v642[v643];	// L1032
        v641[0][v643][v644][v645] = v646;	// L1033
      }
    }
  }
}

void kernel298(
  float v647[1][96][32][32],
  float v648[1][96][34][34]
) {	// L1039
  for (int v649 = 0; v649 < 96; v649 += 1) {	// L1040
    for (int v650 = 0; v650 < 32; v650 += 1) {	// L1041
      for (int v651 = 0; v651 < 32; v651 += 1) {	// L1042
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v647
        #pragma HLS dependence false variable=v648
        float v652 = v647[0][v649][v650][v651];	// L1043
        v648[0][v649][(v650 + 1)][(v651 + 1)] = v652;	// L1044
      }
    }
  }
}

void kernel299(
  float v653[1][96][34][34],
  float v654
) {	// L1050
  for (int v655 = 0; v655 < 96; v655 += 1) {	// L1051
    for (int v656 = 0; v656 < 34; v656 += 1) {	// L1052
      for (int v657 = 0; v657 < 34; v657 += 1) {	// L1053
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v653
        v653[0][v655][v656][v657] = v654;	// L1054
      }
    }
  }
}

void kernel300(
  float v658[1][96][32][32],
  float v659[1][96][32][32]
) {	// L1060
  for (int v660 = 0; v660 < 96; v660 += 1) {	// L1061
    for (int v661 = 0; v661 < 32; v661 += 1) {	// L1062
      for (int v662 = 0; v662 < 32; v662 += 1) {	// L1063
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v658
        #pragma HLS dependence false variable=v659
        float v663 = v658[0][v660][v661][v662];	// L1064
        v659[0][v660][v661][v662] = v663;	// L1065
      }
    }
  }
}

void kernel301(
  float v664[1][96][32][32],
  float v665[1][96][32][32],
  float v666
) {	// L1071
  for (int v667 = 0; v667 < 96; v667 += 1) {	// L1073
    for (int v668 = 0; v668 < 32; v668 += 1) {	// L1074
      for (int v669 = 0; v669 < 32; v669 += 1) {	// L1075
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v665
        #pragma HLS dependence false variable=v664
        float v670 = v665[0][v667][v668][v669];	// L1076
        float v671 = v664[0][v667][v668][v669];	// L1077
        float v672 = v671 * v670;	// L1078
        float v673 = v670 - v672;	// L1079
        bool v674 = v671 != (float)0.000000;	// L1080
        float v675 = v673 + v666;	// L1081
        float v676 = v674 ? v675 : v673;	// L1082
        v665[0][v667][v668][v669] = v676;	// L1083
      }
    }
  }
}

void kernel302(
  float v677[1][96][32][32],
  float v678,
  float v679
) {	// L1089
  for (int v680 = 0; v680 < 96; v680 += 1) {	// L1090
    for (int v681 = 0; v681 < 32; v681 += 1) {	// L1091
      for (int v682 = 0; v682 < 32; v682 += 1) {	// L1092
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v677
        float v683 = v677[0][v680][v681][v682];	// L1093
        float v684 = v683 - v679;	// L1094
        bool v685 = v684 >= v678;	// L1095
        float v686 = v685 ? v679 : v678;	// L1096
        v677[0][v680][v681][v682] = v686;	// L1097
      }
    }
  }
}

void kernel304(
  float v687[1][96][32][32],
  float v688[1][96][32][32],
  float v689
) {	// L1103
  for (int v690 = 0; v690 < 96; v690 += 1) {	// L1104
    for (int v691 = 0; v691 < 32; v691 += 1) {	// L1105
      for (int v692 = 0; v692 < 32; v692 += 1) {	// L1106
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v687
        #pragma HLS dependence false variable=v688
        float v693 = v687[0][v690][v691][v692];	// L1107
        float v694 = v688[0][v690][v691][v692];	// L1108
        float v695 = v694 / v689;	// L1109
        float v696 = v693 / v689;	// L1110
        float v697 = v693 - v696;	// L1111
        float v698 = v697 + v695;	// L1112
        v688[0][v690][v691][v692] = v698;	// L1113
      }
    }
  }
}

void kernel305(
  float v699[1][48][34][34],
  float v700[96][48][3][3],
  float v701[1][96][32][32]
) {	// L1119
  auto v702 = reinterpret_cast<float(*)[48][3][3]>(v700);	// L1121

  for (int v703 = 0; v703 < 48; v703 += 1) {	// L1122
    for (int v704 = 0; v704 < 3; v704 += 1) {	// L1123
      for (int v705 = 0; v705 < 3; v705 += 1) {	// L1124
        for (int v706 = 0; v706 < 96; v706 += 1) {	// L1125
          float v707 = v702[v706][v703][v704][v705];	// L1126
          for (int v708 = 0; v708 < 32; v708 += 1) {	// L1127
            for (int v709 = 0; v709 < 32; v709 += 1) {	// L1128
              #pragma HLS pipeline II=1
              #pragma HLS dependence false variable=v699
              #pragma HLS dependence false variable=v701
              float v710 = v699[0][v703][(v708 + v704)][(v709 + v705)];	// L1129
              float v711 = v701[0][v706][v708][v709];	// L1130
              float v712 = v710 * v707;	// L1131
              float v713 = v711 + v712;	// L1132
              v701[0][v706][v708][v709] = v713;	// L1133
            }
          }
        }
      }
    }
  }
}

void kernel306(
  float v714[96],
  float v715[1][96][32][32]
) {	// L1142
  float v716[96];	// L1143
  #pragma HLS resource variable=v716 core=ram_t2p_bram

  memcpy(v716, v714, 96 * sizeof(float));	// L1144

  for (int v717 = 0; v717 < 96; v717 += 1) {	// L1145
    for (int v718 = 0; v718 < 32; v718 += 1) {	// L1146
      for (int v719 = 0; v719 < 32; v719 += 1) {	// L1147
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v716
        #pragma HLS dependence false variable=v715
        float v720 = v716[v717];	// L1148
        v715[0][v717][v718][v719] = v720;	// L1149
      }
    }
  }
}

void kernel307(
  float v721[1][48][32][32],
  float v722[1][48][34][34]
) {	// L1155
  for (int v723 = 0; v723 < 48; v723 += 1) {	// L1156
    for (int v724 = 0; v724 < 32; v724 += 1) {	// L1157
      for (int v725 = 0; v725 < 32; v725 += 1) {	// L1158
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v721
        #pragma HLS dependence false variable=v722
        float v726 = v721[0][v723][v724][v725];	// L1159
        v722[0][v723][(v724 + 1)][(v725 + 1)] = v726;	// L1160
      }
    }
  }
}

void kernel308(
  float v727[1][48][34][34],
  float v728
) {	// L1166
  for (int v729 = 0; v729 < 48; v729 += 1) {	// L1167
    for (int v730 = 0; v730 < 34; v730 += 1) {	// L1168
      for (int v731 = 0; v731 < 34; v731 += 1) {	// L1169
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v727
        v727[0][v729][v730][v731] = v728;	// L1170
      }
    }
  }
}

void kernel309(
  float v732[1][48][32][32],
  float v733[1][48][32][32]
) {	// L1176
  for (int v734 = 0; v734 < 48; v734 += 1) {	// L1177
    for (int v735 = 0; v735 < 32; v735 += 1) {	// L1178
      for (int v736 = 0; v736 < 32; v736 += 1) {	// L1179
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v732
        #pragma HLS dependence false variable=v733
        float v737 = v732[0][v734][v735][v736];	// L1180
        v733[0][v734][v735][v736] = v737;	// L1181
      }
    }
  }
}

void kernel310(
  float v738[1][48][32][32],
  float v739[1][48][32][32],
  float v740
) {	// L1187
  for (int v741 = 0; v741 < 48; v741 += 1) {	// L1189
    for (int v742 = 0; v742 < 32; v742 += 1) {	// L1190
      for (int v743 = 0; v743 < 32; v743 += 1) {	// L1191
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v739
        #pragma HLS dependence false variable=v738
        float v744 = v739[0][v741][v742][v743];	// L1192
        float v745 = v738[0][v741][v742][v743];	// L1193
        float v746 = v745 * v744;	// L1194
        float v747 = v744 - v746;	// L1195
        bool v748 = v745 != (float)0.000000;	// L1196
        float v749 = v747 + v740;	// L1197
        float v750 = v748 ? v749 : v747;	// L1198
        v739[0][v741][v742][v743] = v750;	// L1199
      }
    }
  }
}

void kernel311(
  float v751[1][48][32][32],
  float v752,
  float v753
) {	// L1205
  for (int v754 = 0; v754 < 48; v754 += 1) {	// L1206
    for (int v755 = 0; v755 < 32; v755 += 1) {	// L1207
      for (int v756 = 0; v756 < 32; v756 += 1) {	// L1208
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v751
        float v757 = v751[0][v754][v755][v756];	// L1209
        float v758 = v757 - v753;	// L1210
        bool v759 = v758 >= v752;	// L1211
        float v760 = v759 ? v753 : v752;	// L1212
        v751[0][v754][v755][v756] = v760;	// L1213
      }
    }
  }
}

void kernel313(
  float v761[1][48][32][32],
  float v762[1][48][32][32],
  float v763
) {	// L1219
  for (int v764 = 0; v764 < 48; v764 += 1) {	// L1220
    for (int v765 = 0; v765 < 32; v765 += 1) {	// L1221
      for (int v766 = 0; v766 < 32; v766 += 1) {	// L1222
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v761
        #pragma HLS dependence false variable=v762
        float v767 = v761[0][v764][v765][v766];	// L1223
        float v768 = v762[0][v764][v765][v766];	// L1224
        float v769 = v768 / v763;	// L1225
        float v770 = v767 / v763;	// L1226
        float v771 = v767 - v770;	// L1227
        float v772 = v771 + v769;	// L1228
        v762[0][v764][v765][v766] = v772;	// L1229
      }
    }
  }
}

void kernel314(
  float v773[1][3][34][34],
  float v774[48][3][3][3],
  float v775[1][48][32][32]
) {	// L1235
  float v776[48][3][3][3];	// L1236
  #pragma HLS resource variable=v776 core=ram_t2p_bram

  memcpy(v776, v774, 1296 * sizeof(float));	// L1237

  for (int v777 = 0; v777 < 3; v777 += 1) {	// L1238
    for (int v778 = 0; v778 < 3; v778 += 1) {	// L1239
      for (int v779 = 0; v779 < 3; v779 += 1) {	// L1240
        for (int v780 = 0; v780 < 48; v780 += 1) {	// L1241
          for (int v781 = 0; v781 < 32; v781 += 1) {	// L1242
            for (int v782 = 0; v782 < 32; v782 += 1) {	// L1243
              #pragma HLS pipeline II=1
              #pragma HLS dependence false variable=v773
              #pragma HLS dependence false variable=v775
              #pragma HLS dependence false variable=v776
              float v783 = v773[0][v777][(v781 + v778)][(v782 + v779)];	// L1244
              float v784 = v776[v780][v777][v778][v779];	// L1245
              float v785 = v775[0][v780][v781][v782];	// L1246
              float v786 = v783 * v784;	// L1247
              float v787 = v785 + v786;	// L1248
              v775[0][v780][v781][v782] = v787;	// L1249
            }
          }
        }
      }
    }
  }
}

void kernel315(
  float v788[48],
  float v789[1][48][32][32]
) {	// L1258
  float v790[48];	// L1259
  #pragma HLS resource variable=v790 core=ram_t2p_bram

  memcpy(v790, v788, 48 * sizeof(float));	// L1260

  for (int v791 = 0; v791 < 48; v791 += 1) {	// L1261
    for (int v792 = 0; v792 < 32; v792 += 1) {	// L1262
      for (int v793 = 0; v793 < 32; v793 += 1) {	// L1263
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v790
        #pragma HLS dependence false variable=v789
        float v794 = v790[v791];	// L1264
        v789[0][v791][v792][v793] = v794;	// L1265
      }
    }
  }
}

void kernel316(
  float v795[1][3][32][32],
  float v796[1][3][34][34]
) {	// L1271
  for (int v797 = 0; v797 < 3; v797 += 1) {	// L1272
    for (int v798 = 0; v798 < 32; v798 += 1) {	// L1273
      for (int v799 = 0; v799 < 32; v799 += 1) {	// L1274
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v795
        #pragma HLS dependence false variable=v796
        float v800 = v795[0][v797][v798][v799];	// L1275
        v796[0][v797][(v798 + 1)][(v799 + 1)] = v800;	// L1276
      }
    }
  }
}

void kernel317(
  float v801[1][3][34][34],
  float v802
) {	// L1282
  for (int v803 = 0; v803 < 3; v803 += 1) {	// L1283
    for (int v804 = 0; v804 < 34; v804 += 1) {	// L1284
      for (int v805 = 0; v805 < 34; v805 += 1) {	// L1285
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v801
        v801[0][v803][v804][v805] = v802;	// L1286
      }
    }
  }
}

/// The top function
void control(
  ap_int<32> v806[89418240],
  ap_int<32> v807[89418240],
  ap_int<32> v808[89418240]
) {	// L1292
  #pragma HLS interface s_axilite port=return bundle=ctrl
  #pragma hls interface m_axi offset=direct bundle=g0 port=v806
  #pragma hls stable variable=v806
  #pragma hls interface m_axi offset=direct bundle=g0 port=v807
  #pragma hls stable variable=v807
  #pragma hls interface m_axi offset=direct bundle=g0 port=v808
  #pragma hls stable variable=v808

  auto v809 = reinterpret_cast<float(*)[3][34][34]>(v807 + 6684672);
  kernel317(v809, (float)0.000000);	// L1301
  auto v810 = reinterpret_cast<float(*)[3][32][32]>(v806);
  kernel316(v810, v809);	// L1303
  auto v811 = reinterpret_cast<float(*)[48][32][32]>(v806 + 6906624);
  auto v812 = reinterpret_cast<float(*)>(v808 + 86764032);
  kernel315(v812, v811);	// L1306
  auto v813 = reinterpret_cast<float(*)[3][3][3]>(v808 + 88091136);
  kernel314(v809, v813, v811);	// L1308
  auto v814 = reinterpret_cast<float(*)[48][32][32]>(v806 + 196608);
  kernel313(v814, v811, (float)2.000000);	// L1310
  auto v815 = reinterpret_cast<float(*)[48][32][32]>(v807 + 6684672);
  kernel309(v811, v815);	// L1312
  kernel311(v815, (float)0.000000, (float)1.000000);	// L1313
  kernel310(v815, v811, (float)0.000000);	// L1314
  kernel309(v811, v814);	// L1315
  auto v816 = reinterpret_cast<float(*)[48][34][34]>(v806 + 6906624);
  kernel308(v816, (float)0.000000);	// L1317
  kernel307(v815, v816);	// L1318
  auto v817 = reinterpret_cast<float(*)[96][32][32]>(v807 + 6684672);
  auto v818 = reinterpret_cast<float(*)>(v808 + 84109824);
  kernel306(v818, v817);	// L1321
  auto v819 = reinterpret_cast<float(*)[48][3][3]>(v808 + 85436928);
  kernel305(v816, v819, v817);	// L1323
  auto v820 = reinterpret_cast<float(*)[96][32][32]>(v806 + 393216);
  kernel304(v820, v817, (float)2.000000);	// L1325
  auto v821 = reinterpret_cast<float(*)[96][32][32]>(v807 + 6906624);
  kernel300(v817, v821);	// L1327
  kernel302(v821, (float)0.000000, (float)1.000000);	// L1328
  kernel301(v821, v817, (float)0.000000);	// L1329
  kernel300(v817, v820);	// L1330
  auto v822 = reinterpret_cast<float(*)[96][34][34]>(v806 + 6684672);
  kernel299(v822, (float)0.000000);	// L1332
  kernel298(v821, v822);	// L1333
  auto v823 = reinterpret_cast<float(*)[192][32][32]>(v806 + 6906624);
  auto v824 = reinterpret_cast<float(*)>(v808 + 81455616);
  kernel297(v824, v823);	// L1336
  auto v825 = reinterpret_cast<float(*)[96][3][3]>(v808 + 82782720);
  kernel296(v822, v825, v823);	// L1338
  auto v826 = reinterpret_cast<float(*)[192][32][32]>(v806 + 589824);
  kernel295(v826, v823, (float)2.000000);	// L1340
  auto v827 = reinterpret_cast<float(*)[192][32][32]>(v807 + 6684672);
  kernel291(v823, v827);	// L1342
  kernel293(v827, (float)0.000000, (float)1.000000);	// L1343
  kernel292(v827, v823, (float)0.000000);	// L1344
  kernel291(v823, v826);	// L1345
  auto v828 = reinterpret_cast<float(*)[192][34][34]>(v806 + 6906624);
  kernel290(v828, (float)-INFINITY);	// L1347
  kernel289(v827, v828);	// L1348
  auto v829 = reinterpret_cast<float(*)[192][16][16]>(v806 + 6684672);
  kernel288(v829, (float)-INFINITY);	// L1350
  auto v830 = reinterpret_cast<float(*)[3]>(v808 + 7128576);
  kernel287(v828, v830, v829);	// L1352
  auto v831 = reinterpret_cast<float(*)[192][18][18]>(v806 + 6906624);
  kernel286(v831, (float)0.000000);	// L1354
  kernel285(v829, v831);	// L1355
  auto v832 = reinterpret_cast<float(*)[384][16][16]>(v807 + 6684672);
  auto v833 = reinterpret_cast<float(*)>(v808 + 78801408);
  kernel284(v833, v832);	// L1358
  auto v834 = reinterpret_cast<float(*)[192][3][3]>(v808 + 80128512);
  kernel283(v831, v834, v832);	// L1360
  auto v835 = reinterpret_cast<float(*)[384][16][16]>(v806 + 786432);
  kernel282(v835, v832, (float)2.000000);	// L1362
  auto v836 = reinterpret_cast<float(*)[384][16][16]>(v807 + 6906624);
  kernel278(v832, v836);	// L1364
  kernel280(v836, (float)0.000000, (float)1.000000);	// L1365
  kernel279(v836, v832, (float)0.000000);	// L1366
  kernel278(v832, v835);	// L1367
  auto v837 = reinterpret_cast<float(*)[384][18][18]>(v806 + 6684672);
  kernel277(v837, (float)-INFINITY);	// L1369
  kernel276(v836, v837);	// L1370
  auto v838 = reinterpret_cast<float(*)[384][8][8]>(v807 + 6906624);
  kernel275(v838, (float)-INFINITY);	// L1372
  kernel274(v837, v830, v838);	// L1373
  auto v839 = reinterpret_cast<float(*)[384][10][10]>(v806 + 6684672);
  kernel273(v839, (float)0.000000);	// L1375
  kernel272(v838, v839);	// L1376
  auto v840 = reinterpret_cast<float(*)[384][8][8]>(v807 + 7128576);
  auto v841 = reinterpret_cast<float(*)>(v808 + 76147200);
  kernel8(v841, v840);	// L1379
  auto v842 = reinterpret_cast<float(*)[384][3][3]>(v808 + 77474304);
  kernel270(v839, v842, v840);	// L1381
  auto v843 = reinterpret_cast<float(*)[384][8][8]>(v806 + 983040);
  kernel20(v843, v840, v838, (float)2.000000);	// L1383
  auto v844 = reinterpret_cast<float(*)[384][8][8]>(v806 + 6684672);
  kernel16(v838, v844);	// L1385
  kernel18(v844, (float)0.000000, (float)1.000000);	// L1386
  kernel17(v844, v838, (float)0.000000);	// L1387
  kernel16(v838, v843);	// L1388
  auto v845 = reinterpret_cast<float(*)[384][64]>(v806 + 7350528);
  auto v846 = reinterpret_cast<float(*)>(v808 + 73492992);
  kernel23(v846, v845);	// L1391
  auto v847 = reinterpret_cast<float(*)[384][1]>(v808 + 74820096);
  kernel47(v844, v847, v845);	// L1393
  auto v848 = reinterpret_cast<float(*)[384][64]>(v806 + 1179648);
  kernel46(v848, v845, (float)2.000000);	// L1395
  auto v849 = reinterpret_cast<float(*)[384][64]>(v806 + 7572480);
  kernel42(v845, v849);	// L1397
  kernel44(v849, (float)0.000000, (float)1.000000);	// L1398
  kernel43(v849, v845, (float)0.000000);	// L1399
  kernel42(v845, v848);	// L1400
  auto v850 = reinterpret_cast<float(*)[64][12][32]>(v807 + 7794432);
  kernel41(v849, v850);	// L1402
  auto v851 = reinterpret_cast<float(*)[12][64][32]>(v806 + 7572480);
  kernel40(v850, v851);	// L1404
  auto v852 = reinterpret_cast<float(*)>(v808 + 70838784);
  kernel23(v852, v845);	// L1406
  auto v853 = reinterpret_cast<float(*)[384][1]>(v808 + 72165888);
  kernel47(v844, v853, v845);	// L1408
  auto v854 = reinterpret_cast<float(*)[384][64]>(v806 + 1376256);
  kernel46(v854, v845, (float)2.000000);	// L1410
  auto v855 = reinterpret_cast<float(*)[384][64]>(v806 + 7794432);
  kernel42(v845, v855);	// L1412
  kernel44(v855, (float)0.000000, (float)1.000000);	// L1413
  kernel43(v855, v845, (float)0.000000);	// L1414
  kernel42(v845, v854);	// L1415
  auto v856 = reinterpret_cast<float(*)[64][12][32]>(v807 + 8016384);
  kernel41(v855, v856);	// L1417
  auto v857 = reinterpret_cast<float(*)>(v808 + 68184576);
  kernel23(v857, v845);	// L1419
  auto v858 = reinterpret_cast<float(*)[384][1]>(v808 + 69511680);
  kernel47(v844, v858, v845);	// L1421
  auto v859 = reinterpret_cast<float(*)[384][64]>(v806 + 1572864);
  kernel46(v859, v845, (float)2.000000);	// L1423
  auto v860 = reinterpret_cast<float(*)[384][64]>(v806 + 6684672);
  kernel42(v845, v860);	// L1425
  kernel44(v860, (float)0.000000, (float)1.000000);	// L1426
  kernel43(v860, v845, (float)0.000000);	// L1427
  kernel42(v845, v859);	// L1428
  kernel41(v860, v850);	// L1429
  auto v861 = reinterpret_cast<float(*)[12][64][32]>(v806 + 8238336);
  kernel40(v850, v861);	// L1431
  auto v862 = reinterpret_cast<float(*)[12][32][64]>(v806 + 6684672);
  kernel39(v856, v862);	// L1433
  auto v863 = reinterpret_cast<float(*)[1][12][64][32]>(v806 + 7794432);
  kernel35(v851, v863);	// L1435
  auto v864 = reinterpret_cast<float(*)[1][12][32][64]>(v807 + 7572480);
  kernel37(v862, v864);	// L1437
  auto v865 = reinterpret_cast<float(*)[64][64]>(v806 + 8016384);
  kernel235(v865, (float)0.000000);	// L1439
  auto v866 = reinterpret_cast<float(*)[64][64]>(v808 + 8460288);
  kernel102(v865, v866);	// L1441
  kernel36(v863, v864, v866);	// L1442
  auto v867 = reinterpret_cast<float(*)[1][12][64][32]>(v807 + 7572480);
  kernel35(v861, v867);	// L1444
  auto v868 = reinterpret_cast<float(*)[64][32]>(v806 + 7794432);
  kernel231(v868, (float)0.000000);	// L1446
  kernel33(v867, v866, v868);	// L1447
  kernel32(v868, v861);	// L1448
  kernel31(v861, (float)0.125000);	// L1449
  auto v869 = reinterpret_cast<float(*)[64][12][32]>(v807 + 7572480);
  kernel30(v861, v869);	// L1451
  auto v870 = reinterpret_cast<float(*)[64][384]>(v806 + 1769472);
  auto v871 = reinterpret_cast<float(*)[64][12][32]>(v808 + 8460288);
  kernel29(v870, v869, v871, (float)2.000000);	// L1454
  auto v872 = reinterpret_cast<float(*)[64][384]>(v806 + 8682240);
  kernel28(v871, v872);	// L1456
  kernel27(v872, (float)1.000000, (float)0.500000, (float)0.000000);	// L1457
  auto v873 = reinterpret_cast<float(*)[64][384]>(v806 + 8904192);
  kernel26(v871, v872, v873, (float)0.000000);	// L1459
  kernel25(v873, v870);	// L1460
  auto v874 = reinterpret_cast<float(*)[384][64]>(v807 + 8460288);
  kernel24(v872, v874);	// L1462
  auto v875 = reinterpret_cast<float(*)>(v808 + 65530368);
  kernel23(v875, v845);	// L1464
  auto v876 = reinterpret_cast<float(*)[384][1]>(v808 + 66857472);
  kernel22(v874, v876, v845);	// L1466
  auto v877 = reinterpret_cast<float(*)[384][8][8]>(v806 + 8460288);
  kernel21(v845, v840, v877);	// L1468
  auto v878 = reinterpret_cast<float(*)[384][8][8]>(v806 + 1966080);
  kernel20(v878, v877, v838, (float)2.000000);	// L1470
  auto v879 = reinterpret_cast<float(*)[384][8][8]>(v806 + 7128576);
  kernel16(v838, v879);	// L1472
  kernel18(v879, (float)0.000000, (float)1.000000);	// L1473
  kernel17(v879, v838, (float)0.000000);	// L1474
  kernel16(v838, v878);	// L1475
  auto v880 = reinterpret_cast<float(*)[1536][8][8]>(v806 + 8682240);
  auto v881 = reinterpret_cast<float(*)>(v808 + 62876160);
  kernel15(v881, v880);	// L1478
  auto v882 = reinterpret_cast<float(*)[384][1][1]>(v808 + 64203264);
  kernel14(v879, v882, v880);	// L1480
  auto v883 = reinterpret_cast<float(*)[1536][8][8]>(v806 + 2162688);
  kernel13(v883, v880, (float)2.000000);	// L1482
  auto v884 = reinterpret_cast<float(*)[1536][8][8]>(v807 + 7128576);
  kernel9(v880, v884);	// L1484
  kernel11(v884, (float)0.000000, (float)1.000000);	// L1485
  kernel10(v884, v880, (float)0.000000);	// L1486
  kernel9(v880, v883);	// L1487
  auto v885 = reinterpret_cast<float(*)>(v808 + 60221952);
  kernel8(v885, v838);	// L1489
  auto v886 = reinterpret_cast<float(*)[1536][1][1]>(v808 + 61549056);
  kernel7(v884, v886, v838);	// L1491
  auto v887 = reinterpret_cast<float(*)[384][8][8]>(v808 + 7128576);
  kernel71(v838, v877, v887);	// L1493
  auto v888 = reinterpret_cast<float(*)[384][8][8]>(v806 + 2359296);
  kernel20(v888, v887, v838, (float)2.000000);	// L1495
  kernel16(v838, v877);	// L1496
  kernel18(v877, (float)0.000000, (float)1.000000);	// L1497
  kernel17(v877, v838, (float)0.000000);	// L1498
  kernel16(v838, v888);	// L1499
  auto v889 = reinterpret_cast<float(*)>(v808 + 57567744);
  kernel23(v889, v845);	// L1501
  auto v890 = reinterpret_cast<float(*)[384][1]>(v808 + 58894848);
  kernel47(v877, v890, v845);	// L1503
  auto v891 = reinterpret_cast<float(*)[384][64]>(v806 + 2555904);
  kernel46(v891, v845, (float)2.000000);	// L1505
  auto v892 = reinterpret_cast<float(*)[384][64]>(v807 + 9126144);
  kernel42(v845, v892);	// L1507
  kernel44(v892, (float)0.000000, (float)1.000000);	// L1508
  kernel43(v892, v845, (float)0.000000);	// L1509
  kernel42(v845, v891);	// L1510
  auto v893 = reinterpret_cast<float(*)[64][12][32]>(v807 + 9348096);
  kernel41(v892, v893);	// L1512
  auto v894 = reinterpret_cast<float(*)[12][64][32]>(v806 + 9126144);
  kernel40(v893, v894);	// L1514
  auto v895 = reinterpret_cast<float(*)>(v808 + 54913536);
  kernel23(v895, v845);	// L1516
  auto v896 = reinterpret_cast<float(*)[384][1]>(v808 + 56240640);
  kernel47(v877, v896, v845);	// L1518
  auto v897 = reinterpret_cast<float(*)[384][64]>(v806 + 2752512);
  kernel46(v897, v845, (float)2.000000);	// L1520
  auto v898 = reinterpret_cast<float(*)[384][64]>(v806 + 9348096);
  kernel42(v845, v898);	// L1522
  kernel44(v898, (float)0.000000, (float)1.000000);	// L1523
  kernel43(v898, v845, (float)0.000000);	// L1524
  kernel42(v845, v897);	// L1525
  auto v899 = reinterpret_cast<float(*)[64][12][32]>(v807 + 9570048);
  kernel41(v898, v899);	// L1527
  auto v900 = reinterpret_cast<float(*)>(v808 + 52259328);
  kernel23(v900, v845);	// L1529
  auto v901 = reinterpret_cast<float(*)[384][1]>(v808 + 53586432);
  kernel47(v877, v901, v845);	// L1531
  auto v902 = reinterpret_cast<float(*)[384][64]>(v806 + 2949120);
  kernel46(v902, v845, (float)2.000000);	// L1533
  auto v903 = reinterpret_cast<float(*)[384][64]>(v806 + 8460288);
  kernel42(v845, v903);	// L1535
  kernel44(v903, (float)0.000000, (float)1.000000);	// L1536
  kernel43(v903, v845, (float)0.000000);	// L1537
  kernel42(v845, v902);	// L1538
  kernel41(v903, v893);	// L1539
  kernel40(v893, v861);	// L1540
  kernel39(v899, v862);	// L1541
  auto v904 = reinterpret_cast<float(*)[1][12][64][32]>(v807 + 8460288);
  kernel35(v894, v904);	// L1543
  auto v905 = reinterpret_cast<float(*)[1][12][32][64]>(v807 + 9126144);
  kernel37(v862, v905);	// L1545
  auto v906 = reinterpret_cast<float(*)[64][64]>(v808 + 9348096);
  kernel102(v865, v906);	// L1547
  kernel36(v904, v905, v906);	// L1548
  kernel35(v861, v904);	// L1549
  kernel165(v868, (float)0.000000);	// L1550
  kernel33(v904, v906, v868);	// L1551
  kernel32(v868, v861);	// L1552
  kernel31(v861, (float)0.125000);	// L1553
  kernel30(v861, v869);	// L1554
  auto v907 = reinterpret_cast<float(*)[64][384]>(v806 + 3145728);
  auto v908 = reinterpret_cast<float(*)[64][12][32]>(v807 + 8460288);
  kernel29(v907, v869, v908, (float)2.000000);	// L1557
  auto v909 = reinterpret_cast<float(*)[64][384]>(v808 + 9126144);
  kernel28(v908, v909);	// L1559
  kernel27(v909, (float)1.000000, (float)0.500000, (float)0.000000);	// L1560
  kernel26(v908, v909, v873, (float)0.000000);	// L1561
  kernel25(v873, v907);	// L1562
  kernel24(v909, v903);	// L1563
  auto v910 = reinterpret_cast<float(*)>(v808 + 49605120);
  kernel23(v910, v845);	// L1565
  auto v911 = reinterpret_cast<float(*)[384][1]>(v808 + 50932224);
  kernel22(v903, v911, v845);	// L1567
  auto v912 = reinterpret_cast<float(*)[384][8][8]>(v807 + 8460288);
  kernel21(v845, v887, v912);	// L1569
  auto v913 = reinterpret_cast<float(*)[384][8][8]>(v806 + 3342336);
  kernel20(v913, v912, v838, (float)2.000000);	// L1571
  kernel16(v838, v840);	// L1572
  kernel18(v840, (float)0.000000, (float)1.000000);	// L1573
  kernel17(v840, v838, (float)0.000000);	// L1574
  kernel16(v838, v913);	// L1575
  auto v914 = reinterpret_cast<float(*)>(v808 + 46950912);
  kernel15(v914, v880);	// L1577
  auto v915 = reinterpret_cast<float(*)[384][1][1]>(v808 + 48278016);
  kernel14(v840, v915, v880);	// L1579
  auto v916 = reinterpret_cast<float(*)[1536][8][8]>(v806 + 3538944);
  kernel13(v916, v880, (float)2.000000);	// L1581
  kernel9(v880, v884);	// L1582
  kernel11(v884, (float)0.000000, (float)1.000000);	// L1583
  kernel10(v884, v880, (float)0.000000);	// L1584
  kernel9(v880, v916);	// L1585
  auto v917 = reinterpret_cast<float(*)>(v808 + 44296704);
  kernel8(v917, v838);	// L1587
  auto v918 = reinterpret_cast<float(*)[1536][1][1]>(v808 + 45623808);
  kernel7(v884, v918, v838);	// L1589
  kernel71(v838, v912, v879);	// L1590
  auto v919 = reinterpret_cast<float(*)[384][8][8]>(v806 + 3735552);
  kernel20(v919, v879, v838, (float)2.000000);	// L1592
  kernel16(v838, v877);	// L1593
  kernel18(v877, (float)0.000000, (float)1.000000);	// L1594
  kernel17(v877, v838, (float)0.000000);	// L1595
  kernel16(v838, v919);	// L1596
  auto v920 = reinterpret_cast<float(*)>(v808 + 41642496);
  kernel23(v920, v845);	// L1598
  auto v921 = reinterpret_cast<float(*)[384][1]>(v808 + 42969600);
  kernel47(v877, v921, v845);	// L1600
  auto v922 = reinterpret_cast<float(*)[384][64]>(v806 + 3932160);
  kernel46(v922, v845, (float)2.000000);	// L1602
  kernel42(v845, v892);	// L1603
  kernel44(v892, (float)0.000000, (float)1.000000);	// L1604
  kernel43(v892, v845, (float)0.000000);	// L1605
  kernel42(v845, v922);	// L1606
  auto v923 = reinterpret_cast<float(*)[64][12][32]>(v806 + 9348096);
  kernel41(v892, v923);	// L1608
  auto v924 = reinterpret_cast<float(*)[12][64][32]>(v807 + 9126144);
  kernel40(v923, v924);	// L1610
  auto v925 = reinterpret_cast<float(*)>(v808 + 38988288);
  kernel23(v925, v845);	// L1612
  auto v926 = reinterpret_cast<float(*)[384][1]>(v808 + 40315392);
  kernel47(v877, v926, v845);	// L1614
  auto v927 = reinterpret_cast<float(*)[384][64]>(v806 + 4128768);
  kernel46(v927, v845, (float)2.000000);	// L1616
  kernel42(v845, v898);	// L1617
  kernel44(v898, (float)0.000000, (float)1.000000);	// L1618
  kernel43(v898, v845, (float)0.000000);	// L1619
  kernel42(v845, v927);	// L1620
  kernel41(v898, v899);	// L1621
  auto v928 = reinterpret_cast<float(*)>(v808 + 36334080);
  kernel23(v928, v845);	// L1623
  auto v929 = reinterpret_cast<float(*)[384][1]>(v808 + 37661184);
  kernel47(v877, v929, v845);	// L1625
  auto v930 = reinterpret_cast<float(*)[384][64]>(v806 + 4325376);
  kernel46(v930, v845, (float)2.000000);	// L1627
  kernel42(v845, v903);	// L1628
  kernel44(v903, (float)0.000000, (float)1.000000);	// L1629
  kernel43(v903, v845, (float)0.000000);	// L1630
  kernel42(v845, v930);	// L1631
  kernel41(v903, v893);	// L1632
  kernel40(v893, v861);	// L1633
  kernel39(v899, v862);	// L1634
  auto v931 = reinterpret_cast<float(*)[1][12][64][32]>(v806 + 8460288);
  kernel35(v924, v931);	// L1636
  kernel37(v862, v905);	// L1637
  kernel102(v865, v906);	// L1638
  kernel36(v931, v905, v906);	// L1639
  kernel35(v861, v904);	// L1640
  kernel99(v868, (float)0.000000);	// L1641
  kernel33(v904, v906, v868);	// L1642
  kernel32(v868, v861);	// L1643
  kernel31(v861, (float)0.125000);	// L1644
  kernel30(v861, v869);	// L1645
  auto v932 = reinterpret_cast<float(*)[64][384]>(v806 + 4521984);
  kernel29(v932, v869, v908, (float)2.000000);	// L1647
  auto v933 = reinterpret_cast<float(*)[64][384]>(v806 + 9126144);
  kernel28(v908, v933);	// L1649
  kernel27(v933, (float)1.000000, (float)0.500000, (float)0.000000);	// L1650
  kernel26(v908, v933, v873, (float)0.000000);	// L1651
  kernel25(v873, v932);	// L1652
  kernel24(v933, v874);	// L1653
  auto v934 = reinterpret_cast<float(*)>(v808 + 33679872);
  kernel23(v934, v845);	// L1655
  auto v935 = reinterpret_cast<float(*)[384][1]>(v808 + 35006976);
  kernel22(v874, v935, v845);	// L1657
  auto v936 = reinterpret_cast<float(*)[384][8][8]>(v808 + 8460288);
  kernel21(v845, v879, v936);	// L1659
  auto v937 = reinterpret_cast<float(*)[384][8][8]>(v806 + 4718592);
  kernel20(v937, v936, v838, (float)2.000000);	// L1661
  kernel16(v838, v840);	// L1662
  kernel18(v840, (float)0.000000, (float)1.000000);	// L1663
  kernel17(v840, v838, (float)0.000000);	// L1664
  kernel16(v838, v937);	// L1665
  auto v938 = reinterpret_cast<float(*)>(v808 + 31025664);
  kernel15(v938, v880);	// L1667
  auto v939 = reinterpret_cast<float(*)[384][1][1]>(v808 + 32352768);
  kernel14(v840, v939, v880);	// L1669
  auto v940 = reinterpret_cast<float(*)[1536][8][8]>(v806 + 4915200);
  kernel13(v940, v880, (float)2.000000);	// L1671
  auto v941 = reinterpret_cast<float(*)[1536][8][8]>(v806 + 7128576);
  kernel9(v880, v941);	// L1673
  kernel11(v941, (float)0.000000, (float)1.000000);	// L1674
  kernel10(v941, v880, (float)0.000000);	// L1675
  kernel9(v880, v940);	// L1676
  auto v942 = reinterpret_cast<float(*)>(v808 + 28371456);
  kernel8(v942, v838);	// L1678
  auto v943 = reinterpret_cast<float(*)[1536][1][1]>(v808 + 29698560);
  kernel7(v941, v943, v838);	// L1680
  kernel71(v838, v936, v887);	// L1681
  auto v944 = reinterpret_cast<float(*)[384][8][8]>(v806 + 5111808);
  kernel20(v944, v887, v838, (float)2.000000);	// L1683
  kernel16(v838, v912);	// L1684
  kernel18(v912, (float)0.000000, (float)1.000000);	// L1685
  kernel17(v912, v838, (float)0.000000);	// L1686
  kernel16(v838, v944);	// L1687
  auto v945 = reinterpret_cast<float(*)>(v808 + 25717248);
  kernel23(v945, v845);	// L1689
  auto v946 = reinterpret_cast<float(*)[384][1]>(v808 + 27044352);
  kernel47(v912, v946, v845);	// L1691
  auto v947 = reinterpret_cast<float(*)[384][64]>(v806 + 5308416);
  kernel46(v947, v845, (float)2.000000);	// L1693
  auto v948 = reinterpret_cast<float(*)[384][64]>(v806 + 9126144);
  kernel42(v845, v948);	// L1695
  kernel44(v948, (float)0.000000, (float)1.000000);	// L1696
  kernel43(v948, v845, (float)0.000000);	// L1697
  kernel42(v845, v947);	// L1698
  kernel41(v948, v893);	// L1699
  kernel40(v893, v894);	// L1700
  auto v949 = reinterpret_cast<float(*)>(v808 + 23063040);
  kernel23(v949, v845);	// L1702
  auto v950 = reinterpret_cast<float(*)[384][1]>(v808 + 24390144);
  kernel47(v912, v950, v845);	// L1704
  auto v951 = reinterpret_cast<float(*)[384][64]>(v806 + 5505024);
  kernel46(v951, v845, (float)2.000000);	// L1706
  auto v952 = reinterpret_cast<float(*)[384][64]>(v807 + 9348096);
  kernel42(v845, v952);	// L1708
  kernel44(v952, (float)0.000000, (float)1.000000);	// L1709
  kernel43(v952, v845, (float)0.000000);	// L1710
  kernel42(v845, v951);	// L1711
  kernel41(v952, v899);	// L1712
  auto v953 = reinterpret_cast<float(*)>(v808 + 20408832);
  kernel23(v953, v845);	// L1714
  auto v954 = reinterpret_cast<float(*)[384][1]>(v808 + 21735936);
  kernel47(v912, v954, v845);	// L1716
  auto v955 = reinterpret_cast<float(*)[384][64]>(v806 + 5701632);
  kernel46(v955, v845, (float)2.000000);	// L1718
  kernel42(v845, v903);	// L1719
  kernel44(v903, (float)0.000000, (float)1.000000);	// L1720
  kernel43(v903, v845, (float)0.000000);	// L1721
  kernel42(v845, v955);	// L1722
  kernel41(v903, v893);	// L1723
  kernel40(v893, v861);	// L1724
  kernel39(v899, v862);	// L1725
  kernel35(v894, v904);	// L1726
  auto v956 = reinterpret_cast<float(*)[1][12][32][64]>(v808 + 9126144);
  kernel37(v862, v956);	// L1728
  kernel36(v904, v956, v865);	// L1729
  auto v957 = reinterpret_cast<float(*)[1][12][64][32]>(v807 + 6684672);
  kernel35(v861, v957);	// L1731
  kernel34(v868, (float)0.000000);	// L1732
  kernel33(v957, v865, v868);	// L1733
  kernel32(v868, v861);	// L1734
  kernel31(v861, (float)0.125000);	// L1735
  kernel30(v861, v869);	// L1736
  auto v958 = reinterpret_cast<float(*)[64][384]>(v806 + 5898240);
  auto v959 = reinterpret_cast<float(*)[64][12][32]>(v807 + 6684672);
  kernel29(v958, v869, v959, (float)2.000000);	// L1739
  auto v960 = reinterpret_cast<float(*)[64][384]>(v808 + 7572480);
  kernel28(v959, v960);	// L1741
  kernel27(v960, (float)1.000000, (float)0.500000, (float)0.000000);	// L1742
  kernel26(v959, v960, v873, (float)0.000000);	// L1743
  kernel25(v873, v958);	// L1744
  auto v961 = reinterpret_cast<float(*)[384][64]>(v807 + 6684672);
  kernel24(v960, v961);	// L1746
  auto v962 = reinterpret_cast<float(*)>(v808 + 17754624);
  kernel23(v962, v845);	// L1748
  auto v963 = reinterpret_cast<float(*)[384][1]>(v808 + 19081728);
  kernel22(v961, v963, v845);	// L1750
  auto v964 = reinterpret_cast<float(*)[384][8][8]>(v808 + 6684672);
  kernel21(v845, v887, v964);	// L1752
  auto v965 = reinterpret_cast<float(*)[384][8][8]>(v806 + 6094848);
  kernel20(v965, v964, v838, (float)2.000000);	// L1754
  kernel16(v838, v879);	// L1755
  kernel18(v879, (float)0.000000, (float)1.000000);	// L1756
  kernel17(v879, v838, (float)0.000000);	// L1757
  kernel16(v838, v965);	// L1758
  auto v966 = reinterpret_cast<float(*)>(v808 + 15100416);
  kernel15(v966, v880);	// L1760
  auto v967 = reinterpret_cast<float(*)[384][1][1]>(v808 + 16427520);
  kernel14(v879, v967, v880);	// L1762
  auto v968 = reinterpret_cast<float(*)[1536][8][8]>(v806 + 6291456);
  kernel13(v968, v880, (float)2.000000);	// L1764
  kernel9(v880, v884);	// L1765
  kernel11(v884, (float)0.000000, (float)1.000000);	// L1766
  kernel10(v884, v880, (float)0.000000);	// L1767
  kernel9(v880, v968);	// L1768
  auto v969 = reinterpret_cast<float(*)>(v808 + 12446208);
  kernel8(v969, v838);	// L1770
  auto v970 = reinterpret_cast<float(*)[1536][1][1]>(v808 + 13773312);
  kernel7(v884, v970, v838);	// L1772
  kernel6(v964, v838);	// L1773
  auto v971 = reinterpret_cast<float(*)[384]>(v807 + 6684672);
  kernel5(v971, (float)0.000000);	// L1775
  kernel4(v838, v971);	// L1776
  kernel3(v971, (float)64.000000);	// L1777
  auto v972 = reinterpret_cast<float(*)[10]>(v806 + 6488064);
  kernel2(v972, (float)0.000000);	// L1779
  auto v973 = reinterpret_cast<float(*)[10]>(v808 + 9792000);
  kernel1(v971, v973, v972);	// L1781
  auto v974 = reinterpret_cast<float(*)>(v808 + 11119104);
  kernel0(v974, v972);	// L1783
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

