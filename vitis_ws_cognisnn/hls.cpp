
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
  float v2[1][11];	// L3
  #pragma HLS resource variable=v2 core=ram_t2p_bram

  memcpy(v2, v1, 11 * sizeof(float));	// L4

  for (int v3 = 0; v3 < 11; v3 += 1) {	// L5
    #pragma HLS pipeline II=1
    #pragma HLS dependence false variable=v2
    #pragma HLS dependence false variable=v0
    float v4 = v2[0][v3];	// L6
    float v5 = v0[v3];	// L7
    float v6 = v4 + v5;	// L8
    v2[0][v3] = v6;	// L9
  }
  memcpy(v1, v2, 11 * sizeof(float));	// L11

}

void kernel1(
  float v7[1][32][1][1],
  float v8[32][11],
  float v9[1][11]
) {	// L14
  float v10[1][11];	// L15
  #pragma HLS resource variable=v10 core=ram_t2p_bram

  memcpy(v10, v9, 11 * sizeof(float));	// L16

  float v11[1][32][1][1];	// L17
  #pragma HLS resource variable=v11 core=ram_t2p_bram

  memcpy(v11, v7, 32 * sizeof(float));	// L18

  for (int v12 = 0; v12 < 32; v12 += 1) {	// L19
    for (int v13 = 0; v13 < 11; v13 += 1) {	// L20
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v11
      #pragma HLS dependence false variable=v8
      #pragma HLS dependence false variable=v10
      float v14 = v11[0][v12][0][0];	// L21
      float v15 = v8[v12][v13];	// L22
      float v16 = v10[0][v13];	// L23
      float v17 = v14 * v15;	// L24
      float v18 = v16 + v17;	// L25
      v10[0][v13] = v18;	// L26
    }
  }
  memcpy(v9, v10, 11 * sizeof(float));	// L29

}

void kernel2(
  float v19[1][11],
  float v20
) {	// L32
  for (int v21 = 0; v21 < 11; v21 += 1) {	// L33
    #pragma HLS pipeline II=1
    #pragma HLS dependence false variable=v19
    v19[0][v21] = v20;	// L34
  }
}

void kernel3(
  float v22[1][32][1][1],
  float v23
) {	// L38
  for (int v24 = 0; v24 < 32; v24 += 1) {	// L39
    float v25 = v22[0][v24][0][0];	// L40
    float v26 = v25 / v23;	// L41
    v22[0][v24][0][0] = v26;	// L42
  }
}

void kernel4(
  float v27[1][32][2][2],
  float v28[2][2],
  float v29[1][32][1][1]
) {	// L46
  float v30[1][32][1][1];	// L47
  #pragma HLS resource variable=v30 core=ram_t2p_bram

  memcpy(v30, v29, 32 * sizeof(float));	// L48

  for (int v31 = 0; v31 < 2; v31 += 1) {	// L49
    for (int v32 = 0; v32 < 2; v32 += 1) {	// L50
      for (int v33 = 0; v33 < 32; v33 += 1) {	// L51
        float v34 = v27[0][v33][v31][v32];	// L52
        float v35 = v30[0][v33][0][0];	// L53
        float v36 = v35 + v34;	// L54
        v30[0][v33][0][0] = v36;	// L55
      }
    }
  }
  memcpy(v29, v30, 32 * sizeof(float));	// L59

}

void kernel5(
  float v37[1][32][1][1],
  float v38
) {	// L62
  for (int v39 = 0; v39 < 32; v39 += 1) {	// L63
    v37[0][v39][0][0] = v38;	// L64
  }
}

void kernel6(
  float v40[1][32][2][2],
  float v41[1][32][2][2],
  float v42[1][32][2][2],
  float v43
) {	// L68
  for (int v44 = 0; v44 < 32; v44 += 1) {	// L69
    for (int v45 = 0; v45 < 2; v45 += 1) {	// L70
      for (int v46 = 0; v46 < 2; v46 += 1) {	// L71
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v40
        #pragma HLS dependence false variable=v42
        #pragma HLS dependence false variable=v41
        float v47 = v40[0][v44][v45][v46];	// L72
        float v48 = v41[0][v44][v45][v46];	// L73
        float v49 = v43 - v48;	// L74
        float v50 = v43 - v47;	// L75
        float v51 = v50 * v49;	// L76
        float v52 = v43 - v51;	// L77
        v42[0][v44][v45][v46] = v52;	// L78
      }
    }
  }
}

void kernel7(
  float v53[1][32][2][2],
  float v54[1][32][2][2]
) {	// L84
  for (int v55 = 0; v55 < 32; v55 += 1) {	// L85
    for (int v56 = 0; v56 < 2; v56 += 1) {	// L86
      for (int v57 = 0; v57 < 2; v57 += 1) {	// L87
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v53
        #pragma HLS dependence false variable=v54
        float v58 = v53[0][v55][v56][v57];	// L88
        v54[0][v55][v56][v57] = v58;	// L89
      }
    }
  }
}

void kernel8(
  float v59[1][32][2][2],
  float v60[1][32][2][2],
  float v61
) {	// L95
  float v62[1][32][2][2];	// L96
  #pragma HLS resource variable=v62 core=ram_t2p_bram

  memcpy(v62, v60, 128 * sizeof(float));	// L97

  for (int v63 = 0; v63 < 32; v63 += 1) {	// L98
    for (int v64 = 0; v64 < 2; v64 += 1) {	// L99
      for (int v65 = 0; v65 < 2; v65 += 1) {	// L100
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v62
        #pragma HLS dependence false variable=v59
        float v66 = v62[0][v63][v64][v65];	// L101
        float v67 = v59[0][v63][v64][v65];	// L102
        float v68 = v67 * v61;	// L103
        float v69 = v66 - v67;	// L104
        float v70 = v69 + v68;	// L105
        v62[0][v63][v64][v65] = v70;	// L106
      }
    }
  }
  memcpy(v60, v62, 128 * sizeof(float));	// L110

}

void kernel9(
  float v71[1][32][2][2],
  float v72,
  float v73
) {	// L113
  for (int v74 = 0; v74 < 32; v74 += 1) {	// L114
    for (int v75 = 0; v75 < 2; v75 += 1) {	// L115
      for (int v76 = 0; v76 < 2; v76 += 1) {	// L116
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v71
        float v77 = v71[0][v74][v75][v76];	// L117
        float v78 = v77 - v73;	// L118
        bool v79 = v78 >= v72;	// L119
        float v80 = v79 ? v73 : v72;	// L120
        v71[0][v74][v75][v76] = v80;	// L121
      }
    }
  }
}

void kernel11(
  float v81[1][32][2][2],
  float v82[1][32][2][2],
  float v83[1][32][2][2],
  float v84
) {	// L127
  for (int v85 = 0; v85 < 32; v85 += 1) {	// L128
    for (int v86 = 0; v86 < 2; v86 += 1) {	// L129
      for (int v87 = 0; v87 < 2; v87 += 1) {	// L130
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v81
        #pragma HLS dependence false variable=v83
        #pragma HLS dependence false variable=v82
        float v88 = v81[0][v85][v86][v87];	// L131
        float v89 = v82[0][v85][v86][v87];	// L132
        float v90 = v89 / v84;	// L133
        float v91 = v88 / v84;	// L134
        float v92 = v88 - v91;	// L135
        float v93 = v92 + v90;	// L136
        v83[0][v85][v86][v87] = v93;	// L137
      }
    }
  }
}

void kernel12(
  float v94[1][32][4][4],
  float v95[32][32][3][3],
  float v96[1][32][2][2]
) {	// L143
  float v97[1][32][4][4];	// L144
  #pragma HLS resource variable=v97 core=ram_t2p_bram

  memcpy(v97, v94, 512 * sizeof(float));	// L145

  float v98[1][32][2][2];	// L146
  #pragma HLS resource variable=v98 core=ram_t2p_bram

  memcpy(v98, v96, 128 * sizeof(float));	// L147

  float v99[32][32][3][3];	// L148
  #pragma HLS resource variable=v99 core=ram_t2p_bram

  memcpy(v99, v95, 9216 * sizeof(float));	// L149

  for (int v100 = 0; v100 < 32; v100 += 1) {	// L150
    for (int v101 = 0; v101 < 3; v101 += 1) {	// L151
      for (int v102 = 0; v102 < 3; v102 += 1) {	// L152
        for (int v103 = 0; v103 < 32; v103 += 1) {	// L153
          for (int v104 = 0; v104 < 2; v104 += 1) {	// L154
            for (int v105 = 0; v105 < 2; v105 += 1) {	// L155
              #pragma HLS pipeline II=1
              #pragma HLS dependence false variable=v97
              #pragma HLS dependence false variable=v98
              #pragma HLS dependence false variable=v99
              float v106 = v97[0][v100][(v104 + v101)][(v105 + v102)];	// L156
              float v107 = v99[v103][v100][v101][v102];	// L157
              float v108 = v98[0][v103][v104][v105];	// L158
              float v109 = v106 * v107;	// L159
              float v110 = v108 + v109;	// L160
              v98[0][v103][v104][v105] = v110;	// L161
            }
          }
        }
      }
    }
  }
  memcpy(v96, v98, 128 * sizeof(float));	// L168

}

void kernel13(
  float v111[1][32][2][2],
  float v112[1][32][4][4]
) {	// L171
  for (int v113 = 0; v113 < 32; v113 += 1) {	// L172
    for (int v114 = 0; v114 < 2; v114 += 1) {	// L173
      for (int v115 = 0; v115 < 2; v115 += 1) {	// L174
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v111
        #pragma HLS dependence false variable=v112
        float v116 = v111[0][v113][v114][v115];	// L175
        v112[0][v113][(v114 + 1)][(v115 + 1)] = v116;	// L176
      }
    }
  }
}

void kernel14(
  float v117[1][32][4][4],
  float v118
) {	// L182
  for (int v119 = 0; v119 < 32; v119 += 1) {	// L183
    for (int v120 = 0; v120 < 4; v120 += 1) {	// L184
      for (int v121 = 0; v121 < 4; v121 += 1) {	// L185
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v117
        v117[0][v119][v120][v121] = v118;	// L186
      }
    }
  }
}

void kernel22(
  float v122[32],
  float v123[1][32][2][2]
) {	// L192
  float v124[32];	// L193
  #pragma HLS resource variable=v124 core=ram_t2p_bram

  memcpy(v124, v122, 32 * sizeof(float));	// L194

  for (int v125 = 0; v125 < 32; v125 += 1) {	// L195
    for (int v126 = 0; v126 < 2; v126 += 1) {	// L196
      for (int v127 = 0; v127 < 2; v127 += 1) {	// L197
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v124
        #pragma HLS dependence false variable=v123
        float v128 = v124[v125];	// L198
        v123[0][v125][v126][v127] = v128;	// L199
      }
    }
  }
}

void kernel24(
  float v129[1][32][4][4],
  float v130
) {	// L205
  for (int v131 = 0; v131 < 32; v131 += 1) {	// L206
    for (int v132 = 0; v132 < 4; v132 += 1) {	// L207
      for (int v133 = 0; v133 < 4; v133 += 1) {	// L208
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v129
        v129[0][v131][v132][v133] = v130;	// L209
      }
    }
  }
}

void kernel25(
  float v134[1][32][2][2],
  float v135
) {	// L215
  float v136[1][32][2][2];	// L216
  #pragma HLS resource variable=v136 core=ram_t2p_bram

  memcpy(v136, v134, 128 * sizeof(float));	// L217

  for (int v137 = 0; v137 < 32; v137 += 1) {	// L218
    for (int v138 = 0; v138 < 2; v138 += 1) {	// L219
      for (int v139 = 0; v139 < 2; v139 += 1) {	// L220
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v136
        float v140 = v136[0][v137][v138][v139];	// L221
        float v141 = v140 / v135;	// L222
        v136[0][v137][v138][v139] = v141;	// L223
      }
    }
  }
  memcpy(v134, v136, 128 * sizeof(float));	// L227

}

void kernel26(
  float v142[1][32][4][4],
  float v143[2][2],
  float v144[1][32][2][2]
) {	// L230
  float v145[1][32][2][2];	// L231
  #pragma HLS resource variable=v145 core=ram_t2p_bram

  memcpy(v145, v144, 128 * sizeof(float));	// L232

  for (int v146 = 0; v146 < 2; v146 += 1) {	// L233
    for (int v147 = 0; v147 < 2; v147 += 1) {	// L234
      for (int v148 = 0; v148 < 32; v148 += 1) {	// L235
        for (int v149 = 0; v149 < 2; v149 += 1) {	// L236
          for (int v150 = 0; v150 < 2; v150 += 1) {	// L237
            #pragma HLS pipeline II=1
            #pragma HLS dependence false variable=v142
            #pragma HLS dependence false variable=v145
            float v151 = v142[0][v148][((v149 * 2) + v146)][((v150 * 2) + v147)];	// L238
            float v152 = v145[0][v148][v149][v150];	// L239
            float v153 = v152 + v151;	// L240
            v145[0][v148][v149][v150] = v153;	// L241
          }
        }
      }
    }
  }
  memcpy(v144, v145, 128 * sizeof(float));	// L247

}

void kernel27(
  float v154[1][32][2][2],
  float v155
) {	// L250
  for (int v156 = 0; v156 < 32; v156 += 1) {	// L251
    for (int v157 = 0; v157 < 2; v157 += 1) {	// L252
      for (int v158 = 0; v158 < 2; v158 += 1) {	// L253
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v154
        v154[0][v156][v157][v158] = v155;	// L254
      }
    }
  }
}

void kernel28(
  float v159[1][32][4][4],
  float v160[1][32][4][4],
  float v161[1][32][4][4],
  float v162
) {	// L260
  for (int v163 = 0; v163 < 32; v163 += 1) {	// L261
    for (int v164 = 0; v164 < 4; v164 += 1) {	// L262
      for (int v165 = 0; v165 < 4; v165 += 1) {	// L263
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v159
        #pragma HLS dependence false variable=v161
        #pragma HLS dependence false variable=v160
        float v166 = v159[0][v163][v164][v165];	// L264
        float v167 = v160[0][v163][v164][v165];	// L265
        float v168 = v162 - v167;	// L266
        float v169 = v162 - v166;	// L267
        float v170 = v169 * v168;	// L268
        float v171 = v162 - v170;	// L269
        v161[0][v163][v164][v165] = v171;	// L270
      }
    }
  }
}

void kernel29(
  float v172[1][32][4][4],
  float v173[1][32][4][4]
) {	// L276
  for (int v174 = 0; v174 < 32; v174 += 1) {	// L277
    for (int v175 = 0; v175 < 4; v175 += 1) {	// L278
      for (int v176 = 0; v176 < 4; v176 += 1) {	// L279
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v172
        #pragma HLS dependence false variable=v173
        float v177 = v172[0][v174][v175][v176];	// L280
        v173[0][v174][v175][v176] = v177;	// L281
      }
    }
  }
}

void kernel30(
  float v178[1][32][4][4],
  float v179[1][32][4][4],
  float v180
) {	// L287
  for (int v181 = 0; v181 < 32; v181 += 1) {	// L288
    for (int v182 = 0; v182 < 4; v182 += 1) {	// L289
      for (int v183 = 0; v183 < 4; v183 += 1) {	// L290
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v179
        #pragma HLS dependence false variable=v178
        float v184 = v179[0][v181][v182][v183];	// L291
        float v185 = v178[0][v181][v182][v183];	// L292
        float v186 = v185 * v180;	// L293
        float v187 = v184 - v185;	// L294
        float v188 = v187 + v186;	// L295
        v179[0][v181][v182][v183] = v188;	// L296
      }
    }
  }
}

void kernel31(
  float v189[1][32][4][4],
  float v190,
  float v191
) {	// L302
  for (int v192 = 0; v192 < 32; v192 += 1) {	// L303
    for (int v193 = 0; v193 < 4; v193 += 1) {	// L304
      for (int v194 = 0; v194 < 4; v194 += 1) {	// L305
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v189
        float v195 = v189[0][v192][v193][v194];	// L306
        float v196 = v195 - v191;	// L307
        bool v197 = v196 >= v190;	// L308
        float v198 = v197 ? v191 : v190;	// L309
        v189[0][v192][v193][v194] = v198;	// L310
      }
    }
  }
}

void kernel33(
  float v199[1][32][4][4],
  float v200[1][32][4][4],
  float v201[1][32][4][4],
  float v202
) {	// L316
  for (int v203 = 0; v203 < 32; v203 += 1) {	// L317
    for (int v204 = 0; v204 < 4; v204 += 1) {	// L318
      for (int v205 = 0; v205 < 4; v205 += 1) {	// L319
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v199
        #pragma HLS dependence false variable=v201
        #pragma HLS dependence false variable=v200
        float v206 = v199[0][v203][v204][v205];	// L320
        float v207 = v200[0][v203][v204][v205];	// L321
        float v208 = v207 / v202;	// L322
        float v209 = v206 / v202;	// L323
        float v210 = v206 - v209;	// L324
        float v211 = v210 + v208;	// L325
        v201[0][v203][v204][v205] = v211;	// L326
      }
    }
  }
}

void kernel34(
  float v212[1][32][6][6],
  float v213[32][32][3][3],
  float v214[1][32][4][4]
) {	// L332
  float v215[1][32][6][6];	// L333
  #pragma HLS resource variable=v215 core=ram_t2p_bram

  memcpy(v215, v212, 1152 * sizeof(float));	// L334

  float v216[1][32][4][4];	// L335
  #pragma HLS resource variable=v216 core=ram_t2p_bram

  memcpy(v216, v214, 512 * sizeof(float));	// L336

  float v217[32][32][3][3];	// L337
  #pragma HLS resource variable=v217 core=ram_t2p_bram

  memcpy(v217, v213, 9216 * sizeof(float));	// L338

  for (int v218 = 0; v218 < 32; v218 += 1) {	// L339
    for (int v219 = 0; v219 < 3; v219 += 1) {	// L340
      for (int v220 = 0; v220 < 3; v220 += 1) {	// L341
        for (int v221 = 0; v221 < 32; v221 += 1) {	// L342
          for (int v222 = 0; v222 < 4; v222 += 1) {	// L343
            for (int v223 = 0; v223 < 4; v223 += 1) {	// L344
              #pragma HLS pipeline II=1
              #pragma HLS dependence false variable=v215
              #pragma HLS dependence false variable=v216
              #pragma HLS dependence false variable=v217
              float v224 = v215[0][v218][(v222 + v219)][(v223 + v220)];	// L345
              float v225 = v217[v221][v218][v219][v220];	// L346
              float v226 = v216[0][v221][v222][v223];	// L347
              float v227 = v224 * v225;	// L348
              float v228 = v226 + v227;	// L349
              v216[0][v221][v222][v223] = v228;	// L350
            }
          }
        }
      }
    }
  }
  memcpy(v214, v216, 512 * sizeof(float));	// L357

}

void kernel35(
  float v229[1][32][4][4],
  float v230[1][32][6][6]
) {	// L360
  for (int v231 = 0; v231 < 32; v231 += 1) {	// L361
    for (int v232 = 0; v232 < 4; v232 += 1) {	// L362
      for (int v233 = 0; v233 < 4; v233 += 1) {	// L363
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v229
        #pragma HLS dependence false variable=v230
        float v234 = v229[0][v231][v232][v233];	// L364
        v230[0][v231][(v232 + 1)][(v233 + 1)] = v234;	// L365
      }
    }
  }
}

void kernel36(
  float v235[1][32][6][6],
  float v236
) {	// L371
  for (int v237 = 0; v237 < 32; v237 += 1) {	// L372
    for (int v238 = 0; v238 < 6; v238 += 1) {	// L373
      for (int v239 = 0; v239 < 6; v239 += 1) {	// L374
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v235
        v235[0][v237][v238][v239] = v236;	// L375
      }
    }
  }
}

void kernel44(
  float v240[32],
  float v241[1][32][4][4]
) {	// L381
  float v242[32];	// L382
  #pragma HLS resource variable=v242 core=ram_t2p_bram

  memcpy(v242, v240, 32 * sizeof(float));	// L383

  for (int v243 = 0; v243 < 32; v243 += 1) {	// L384
    for (int v244 = 0; v244 < 4; v244 += 1) {	// L385
      for (int v245 = 0; v245 < 4; v245 += 1) {	// L386
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v242
        #pragma HLS dependence false variable=v241
        float v246 = v242[v243];	// L387
        v241[0][v243][v244][v245] = v246;	// L388
      }
    }
  }
}

void kernel46(
  float v247[1][32][6][6],
  float v248
) {	// L394
  for (int v249 = 0; v249 < 32; v249 += 1) {	// L395
    for (int v250 = 0; v250 < 6; v250 += 1) {	// L396
      for (int v251 = 0; v251 < 6; v251 += 1) {	// L397
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v247
        v247[0][v249][v250][v251] = v248;	// L398
      }
    }
  }
}

void kernel47(
  float v252[1][32][4][4],
  float v253[1][32][4][4],
  float v254[1][32][4][4],
  float v255,
  float v256,
  float v257,
  float v258,
  float v259
) {	// L404
  for (int v260 = 0; v260 < 32; v260 += 1) {	// L405
    for (int v261 = 0; v261 < 4; v261 += 1) {	// L406
      for (int v262 = 0; v262 < 4; v262 += 1) {	// L407
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v253
        #pragma HLS dependence false variable=v252
        #pragma HLS dependence false variable=v254
        float v263 = v252[0][v260][v261][v262];	// L408
        float v264 = v254[0][v260][v261][v262];	// L409
        float v265 = v253[0][v260][v261][v262];	// L410
        float v266 = v265 / v259;	// L411
        float v267 = v266 * v258;	// L412
        float v268 = v264 / v259;	// L413
        float v269 = v268 * v257;	// L414
        float v270 = v263 / v256;	// L415
        float v271 = v270 * v255;	// L416
        float v272 = v271 + v269;	// L417
        float v273 = v272 + v267;	// L418
        v254[0][v260][v261][v262] = v273;	// L419
      }
    }
  }
}

void kernel48(
  float v274[1][32][8][8],
  float v275[2][2],
  float v276[1][32][4][4]
) {	// L425
  float v277[1][32][4][4];	// L426
  #pragma HLS resource variable=v277 core=ram_t2p_bram

  memcpy(v277, v276, 512 * sizeof(float));	// L427

  for (int v278 = 0; v278 < 2; v278 += 1) {	// L428
    for (int v279 = 0; v279 < 2; v279 += 1) {	// L429
      for (int v280 = 0; v280 < 32; v280 += 1) {	// L430
        for (int v281 = 0; v281 < 4; v281 += 1) {	// L431
          for (int v282 = 0; v282 < 4; v282 += 1) {	// L432
            #pragma HLS pipeline II=1
            #pragma HLS dependence false variable=v274
            #pragma HLS dependence false variable=v277
            float v283 = v274[0][v280][((v281 * 2) + v278)][((v282 * 2) + v279)];	// L433
            float v284 = v277[0][v280][v281][v282];	// L434
            float v285 = v284 + v283;	// L435
            v277[0][v280][v281][v282] = v285;	// L436
          }
        }
      }
    }
  }
  memcpy(v276, v277, 512 * sizeof(float));	// L442

}

void kernel49(
  float v286[1][32][16][16],
  float v287[4][4],
  float v288[1][32][4][4]
) {	// L445
  float v289[1][32][16][16];	// L446
  #pragma HLS resource variable=v289 core=ram_t2p_bram

  memcpy(v289, v286, 8192 * sizeof(float));	// L447

  float v290[1][32][4][4];	// L448
  #pragma HLS resource variable=v290 core=ram_t2p_bram

  memcpy(v290, v288, 512 * sizeof(float));	// L449

  for (int v291 = 0; v291 < 4; v291 += 1) {	// L450
    for (int v292 = 0; v292 < 4; v292 += 1) {	// L451
      for (int v293 = 0; v293 < 32; v293 += 1) {	// L452
        for (int v294 = 0; v294 < 4; v294 += 1) {	// L453
          for (int v295 = 0; v295 < 4; v295 += 1) {	// L454
            #pragma HLS pipeline II=1
            #pragma HLS dependence false variable=v289
            #pragma HLS dependence false variable=v290
            float v296 = v289[0][v293][((v294 * 4) + v291)][((v295 * 4) + v292)];	// L455
            float v297 = v290[0][v293][v294][v295];	// L456
            float v298 = v297 + v296;	// L457
            v290[0][v293][v294][v295] = v298;	// L458
          }
        }
      }
    }
  }
  memcpy(v288, v290, 512 * sizeof(float));	// L464

}

void kernel53(
  float v299[1][32][4][4],
  float v300
) {	// L467
  for (int v301 = 0; v301 < 32; v301 += 1) {	// L468
    for (int v302 = 0; v302 < 4; v302 += 1) {	// L469
      for (int v303 = 0; v303 < 4; v303 += 1) {	// L470
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v299
        v299[0][v301][v302][v303] = v300;	// L471
      }
    }
  }
}

void kernel54(
  float v304[1][32][8][8],
  float v305[1][32][8][8],
  float v306[1][32][8][8],
  float v307
) {	// L477
  for (int v308 = 0; v308 < 32; v308 += 1) {	// L478
    for (int v309 = 0; v309 < 8; v309 += 1) {	// L479
      for (int v310 = 0; v310 < 8; v310 += 1) {	// L480
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v304
        #pragma HLS dependence false variable=v306
        #pragma HLS dependence false variable=v305
        float v311 = v304[0][v308][v309][v310];	// L481
        float v312 = v305[0][v308][v309][v310];	// L482
        float v313 = v307 - v312;	// L483
        float v314 = v307 - v311;	// L484
        float v315 = v314 * v313;	// L485
        float v316 = v307 - v315;	// L486
        v306[0][v308][v309][v310] = v316;	// L487
      }
    }
  }
}

void kernel55(
  float v317[1][32][8][8],
  float v318[1][32][8][8]
) {	// L493
  for (int v319 = 0; v319 < 32; v319 += 1) {	// L494
    for (int v320 = 0; v320 < 8; v320 += 1) {	// L495
      for (int v321 = 0; v321 < 8; v321 += 1) {	// L496
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v317
        #pragma HLS dependence false variable=v318
        float v322 = v317[0][v319][v320][v321];	// L497
        v318[0][v319][v320][v321] = v322;	// L498
      }
    }
  }
}

void kernel56(
  float v323[1][32][8][8],
  float v324[1][32][8][8],
  float v325
) {	// L504
  for (int v326 = 0; v326 < 32; v326 += 1) {	// L505
    for (int v327 = 0; v327 < 8; v327 += 1) {	// L506
      for (int v328 = 0; v328 < 8; v328 += 1) {	// L507
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v324
        #pragma HLS dependence false variable=v323
        float v329 = v324[0][v326][v327][v328];	// L508
        float v330 = v323[0][v326][v327][v328];	// L509
        float v331 = v330 * v325;	// L510
        float v332 = v329 - v330;	// L511
        float v333 = v332 + v331;	// L512
        v324[0][v326][v327][v328] = v333;	// L513
      }
    }
  }
}

void kernel57(
  float v334[1][32][8][8],
  float v335,
  float v336
) {	// L519
  for (int v337 = 0; v337 < 32; v337 += 1) {	// L520
    for (int v338 = 0; v338 < 8; v338 += 1) {	// L521
      for (int v339 = 0; v339 < 8; v339 += 1) {	// L522
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v334
        float v340 = v334[0][v337][v338][v339];	// L523
        float v341 = v340 - v336;	// L524
        bool v342 = v341 >= v335;	// L525
        float v343 = v342 ? v336 : v335;	// L526
        v334[0][v337][v338][v339] = v343;	// L527
      }
    }
  }
}

void kernel59(
  float v344[1][32][8][8],
  float v345[1][32][8][8],
  float v346[1][32][8][8],
  float v347
) {	// L533
  for (int v348 = 0; v348 < 32; v348 += 1) {	// L534
    for (int v349 = 0; v349 < 8; v349 += 1) {	// L535
      for (int v350 = 0; v350 < 8; v350 += 1) {	// L536
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v344
        #pragma HLS dependence false variable=v346
        #pragma HLS dependence false variable=v345
        float v351 = v344[0][v348][v349][v350];	// L537
        float v352 = v345[0][v348][v349][v350];	// L538
        float v353 = v352 / v347;	// L539
        float v354 = v351 / v347;	// L540
        float v355 = v351 - v354;	// L541
        float v356 = v355 + v353;	// L542
        v346[0][v348][v349][v350] = v356;	// L543
      }
    }
  }
}

void kernel60(
  float v357[1][32][10][10],
  float v358[32][32][3][3],
  float v359[1][32][8][8]
) {	// L549
  float v360[1][32][10][10];	// L550
  #pragma HLS resource variable=v360 core=ram_t2p_bram

  memcpy(v360, v357, 3200 * sizeof(float));	// L551

  float v361[1][32][8][8];	// L552
  #pragma HLS resource variable=v361 core=ram_t2p_bram

  memcpy(v361, v359, 2048 * sizeof(float));	// L553

  float v362[32][32][3][3];	// L554
  #pragma HLS resource variable=v362 core=ram_t2p_bram

  memcpy(v362, v358, 9216 * sizeof(float));	// L555

  for (int v363 = 0; v363 < 32; v363 += 1) {	// L556
    for (int v364 = 0; v364 < 3; v364 += 1) {	// L557
      for (int v365 = 0; v365 < 3; v365 += 1) {	// L558
        for (int v366 = 0; v366 < 32; v366 += 1) {	// L559
          for (int v367 = 0; v367 < 8; v367 += 1) {	// L560
            for (int v368 = 0; v368 < 8; v368 += 1) {	// L561
              #pragma HLS pipeline II=1
              #pragma HLS dependence false variable=v360
              #pragma HLS dependence false variable=v361
              #pragma HLS dependence false variable=v362
              float v369 = v360[0][v363][(v367 + v364)][(v368 + v365)];	// L562
              float v370 = v362[v366][v363][v364][v365];	// L563
              float v371 = v361[0][v366][v367][v368];	// L564
              float v372 = v369 * v370;	// L565
              float v373 = v371 + v372;	// L566
              v361[0][v366][v367][v368] = v373;	// L567
            }
          }
        }
      }
    }
  }
  memcpy(v359, v361, 2048 * sizeof(float));	// L574

}

void kernel61(
  float v374[1][32][8][8],
  float v375[1][32][10][10]
) {	// L577
  for (int v376 = 0; v376 < 32; v376 += 1) {	// L578
    for (int v377 = 0; v377 < 8; v377 += 1) {	// L579
      for (int v378 = 0; v378 < 8; v378 += 1) {	// L580
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v374
        #pragma HLS dependence false variable=v375
        float v379 = v374[0][v376][v377][v378];	// L581
        v375[0][v376][(v377 + 1)][(v378 + 1)] = v379;	// L582
      }
    }
  }
}

void kernel62(
  float v380[1][32][10][10],
  float v381
) {	// L588
  for (int v382 = 0; v382 < 32; v382 += 1) {	// L589
    for (int v383 = 0; v383 < 10; v383 += 1) {	// L590
      for (int v384 = 0; v384 < 10; v384 += 1) {	// L591
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v380
        v380[0][v382][v383][v384] = v381;	// L592
      }
    }
  }
}

void kernel70(
  float v385[32],
  float v386[1][32][8][8]
) {	// L598
  float v387[32];	// L599
  #pragma HLS resource variable=v387 core=ram_t2p_bram

  memcpy(v387, v385, 32 * sizeof(float));	// L600

  for (int v388 = 0; v388 < 32; v388 += 1) {	// L601
    for (int v389 = 0; v389 < 8; v389 += 1) {	// L602
      for (int v390 = 0; v390 < 8; v390 += 1) {	// L603
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v387
        #pragma HLS dependence false variable=v386
        float v391 = v387[v388];	// L604
        v386[0][v388][v389][v390] = v391;	// L605
      }
    }
  }
}

void kernel72(
  float v392[1][32][10][10],
  float v393
) {	// L611
  for (int v394 = 0; v394 < 32; v394 += 1) {	// L612
    for (int v395 = 0; v395 < 10; v395 += 1) {	// L613
      for (int v396 = 0; v396 < 10; v396 += 1) {	// L614
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v392
        v392[0][v394][v395][v396] = v393;	// L615
      }
    }
  }
}

void kernel73(
  float v397[1][32][8][8],
  float v398
) {	// L621
  for (int v399 = 0; v399 < 32; v399 += 1) {	// L622
    for (int v400 = 0; v400 < 8; v400 += 1) {	// L623
      for (int v401 = 0; v401 < 8; v401 += 1) {	// L624
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v397
        float v402 = v397[0][v399][v400][v401];	// L625
        float v403 = v402 / v398;	// L626
        v397[0][v399][v400][v401] = v403;	// L627
      }
    }
  }
}

void kernel75(
  float v404[1][32][16][16],
  float v405[2][2],
  float v406[1][32][8][8]
) {	// L633
  float v407[1][32][16][16];	// L634
  #pragma HLS resource variable=v407 core=ram_t2p_bram

  memcpy(v407, v404, 8192 * sizeof(float));	// L635

  float v408[1][32][8][8];	// L636
  #pragma HLS resource variable=v408 core=ram_t2p_bram

  memcpy(v408, v406, 2048 * sizeof(float));	// L637

  for (int v409 = 0; v409 < 2; v409 += 1) {	// L638
    for (int v410 = 0; v410 < 2; v410 += 1) {	// L639
      for (int v411 = 0; v411 < 32; v411 += 1) {	// L640
        for (int v412 = 0; v412 < 8; v412 += 1) {	// L641
          for (int v413 = 0; v413 < 8; v413 += 1) {	// L642
            #pragma HLS pipeline II=1
            #pragma HLS dependence false variable=v407
            #pragma HLS dependence false variable=v408
            float v414 = v407[0][v411][((v412 * 2) + v409)][((v413 * 2) + v410)];	// L643
            float v415 = v408[0][v411][v412][v413];	// L644
            float v416 = v415 + v414;	// L645
            v408[0][v411][v412][v413] = v416;	// L646
          }
        }
      }
    }
  }
  memcpy(v406, v408, 2048 * sizeof(float));	// L652

}

void kernel76(
  float v417[1][32][8][8],
  float v418
) {	// L655
  for (int v419 = 0; v419 < 32; v419 += 1) {	// L656
    for (int v420 = 0; v420 < 8; v420 += 1) {	// L657
      for (int v421 = 0; v421 < 8; v421 += 1) {	// L658
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v417
        v417[0][v419][v420][v421] = v418;	// L659
      }
    }
  }
}

void kernel77(
  float v422[1][32][16][16],
  float v423[1][32][16][16],
  float v424[1][32][16][16],
  float v425
) {	// L665
  float v426[1][32][16][16];	// L666
  #pragma HLS resource variable=v426 core=ram_t2p_bram

  memcpy(v426, v423, 8192 * sizeof(float));	// L667

  float v427[1][32][16][16];	// L668
  #pragma HLS resource variable=v427 core=ram_t2p_bram

  memcpy(v427, v422, 8192 * sizeof(float));	// L669

  for (int v428 = 0; v428 < 32; v428 += 1) {	// L670
    for (int v429 = 0; v429 < 16; v429 += 1) {	// L671
      for (int v430 = 0; v430 < 16; v430 += 1) {	// L672
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v427
        #pragma HLS dependence false variable=v424
        #pragma HLS dependence false variable=v426
        float v431 = v427[0][v428][v429][v430];	// L673
        float v432 = v426[0][v428][v429][v430];	// L674
        float v433 = v425 - v432;	// L675
        float v434 = v425 - v431;	// L676
        float v435 = v434 * v433;	// L677
        float v436 = v425 - v435;	// L678
        v424[0][v428][v429][v430] = v436;	// L679
      }
    }
  }
}

void kernel78(
  float v437[1][32][16][16],
  float v438[1][32][16][16]
) {	// L685
  float v439[1][32][16][16];	// L686
  #pragma HLS resource variable=v439 core=ram_t2p_bram

  memcpy(v439, v437, 8192 * sizeof(float));	// L687

  for (int v440 = 0; v440 < 32; v440 += 1) {	// L688
    for (int v441 = 0; v441 < 16; v441 += 1) {	// L689
      for (int v442 = 0; v442 < 16; v442 += 1) {	// L690
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v439
        #pragma HLS dependence false variable=v438
        float v443 = v439[0][v440][v441][v442];	// L691
        v438[0][v440][v441][v442] = v443;	// L692
      }
    }
  }
}

void kernel79(
  float v444[1][32][16][16],
  float v445[1][32][16][16],
  float v446
) {	// L698
  float v447[1][32][16][16];	// L699
  #pragma HLS resource variable=v447 core=ram_t2p_bram

  memcpy(v447, v445, 8192 * sizeof(float));	// L700

  for (int v448 = 0; v448 < 32; v448 += 1) {	// L701
    for (int v449 = 0; v449 < 16; v449 += 1) {	// L702
      for (int v450 = 0; v450 < 16; v450 += 1) {	// L703
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v447
        #pragma HLS dependence false variable=v444
        float v451 = v447[0][v448][v449][v450];	// L704
        float v452 = v444[0][v448][v449][v450];	// L705
        float v453 = v452 * v446;	// L706
        float v454 = v451 - v452;	// L707
        float v455 = v454 + v453;	// L708
        v447[0][v448][v449][v450] = v455;	// L709
      }
    }
  }
  memcpy(v445, v447, 8192 * sizeof(float));	// L713

}

void kernel80(
  float v456[1][32][16][16],
  float v457,
  float v458
) {	// L716
  float v459[1][32][16][16];	// L717
  #pragma HLS resource variable=v459 core=ram_t2p_bram

  memcpy(v459, v456, 8192 * sizeof(float));	// L718

  for (int v460 = 0; v460 < 32; v460 += 1) {	// L719
    for (int v461 = 0; v461 < 16; v461 += 1) {	// L720
      for (int v462 = 0; v462 < 16; v462 += 1) {	// L721
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v459
        float v463 = v459[0][v460][v461][v462];	// L722
        float v464 = v463 - v458;	// L723
        bool v465 = v464 >= v457;	// L724
        float v466 = v465 ? v458 : v457;	// L725
        v459[0][v460][v461][v462] = v466;	// L726
      }
    }
  }
  memcpy(v456, v459, 8192 * sizeof(float));	// L730

}

void kernel82(
  float v467[1][32][16][16],
  float v468[1][32][16][16],
  float v469[1][32][16][16],
  float v470
) {	// L733
  float v471[1][32][16][16];	// L734
  #pragma HLS resource variable=v471 core=ram_t2p_bram

  memcpy(v471, v467, 8192 * sizeof(float));	// L735

  float v472[1][32][16][16];	// L736
  #pragma HLS resource variable=v472 core=ram_t2p_bram

  memcpy(v472, v468, 8192 * sizeof(float));	// L737

  float v473[1][32][16][16];	// L738
  #pragma HLS resource variable=v473 core=ram_t2p_bram

  for (int v474 = 0; v474 < 32; v474 += 1) {	// L739
    for (int v475 = 0; v475 < 16; v475 += 1) {	// L740
      for (int v476 = 0; v476 < 16; v476 += 1) {	// L741
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v471
        #pragma HLS dependence false variable=v473
        #pragma HLS dependence false variable=v472
        float v477 = v471[0][v474][v475][v476];	// L742
        float v478 = v472[0][v474][v475][v476];	// L743
        float v479 = v478 / v470;	// L744
        float v480 = v477 / v470;	// L745
        float v481 = v477 - v480;	// L746
        float v482 = v481 + v479;	// L747
        v473[0][v474][v475][v476] = v482;	// L748
      }
    }
  }
  memcpy(v469, v473, 8192 * sizeof(float));	// L752

}

void kernel83(
  float v483[1][32][18][18],
  float v484[32][32][3][3],
  float v485[1][32][16][16]
) {	// L755
  float v486[1][32][18][18];	// L756
  #pragma HLS resource variable=v486 core=ram_t2p_bram

  memcpy(v486, v483, 10368 * sizeof(float));	// L757

  float v487[1][32][16][16];	// L758
  #pragma HLS resource variable=v487 core=ram_t2p_bram

  memcpy(v487, v485, 8192 * sizeof(float));	// L759

  float v488[32][32][3][3];	// L760
  #pragma HLS resource variable=v488 core=ram_t2p_bram

  memcpy(v488, v484, 9216 * sizeof(float));	// L761

  for (int v489 = 0; v489 < 32; v489 += 1) {	// L762
    for (int v490 = 0; v490 < 3; v490 += 1) {	// L763
      for (int v491 = 0; v491 < 3; v491 += 1) {	// L764
        for (int v492 = 0; v492 < 32; v492 += 1) {	// L765
          for (int v493 = 0; v493 < 16; v493 += 1) {	// L766
            for (int v494 = 0; v494 < 16; v494 += 1) {	// L767
              #pragma HLS pipeline II=1
              #pragma HLS dependence false variable=v486
              #pragma HLS dependence false variable=v487
              #pragma HLS dependence false variable=v488
              float v495 = v486[0][v489][(v493 + v490)][(v494 + v491)];	// L768
              float v496 = v488[v492][v489][v490][v491];	// L769
              float v497 = v487[0][v492][v493][v494];	// L770
              float v498 = v495 * v496;	// L771
              float v499 = v497 + v498;	// L772
              v487[0][v492][v493][v494] = v499;	// L773
            }
          }
        }
      }
    }
  }
  memcpy(v485, v487, 8192 * sizeof(float));	// L780

}

void kernel84(
  float v500[1][32][16][16],
  float v501[1][32][18][18]
) {	// L783
  float v502[1][32][16][16];	// L784
  #pragma HLS resource variable=v502 core=ram_t2p_bram

  memcpy(v502, v500, 8192 * sizeof(float));	// L785

  float v503[1][32][18][18];	// L786
  #pragma HLS resource variable=v503 core=ram_t2p_bram

  for (int v504 = 0; v504 < 32; v504 += 1) {	// L787
    for (int v505 = 0; v505 < 16; v505 += 1) {	// L788
      for (int v506 = 0; v506 < 16; v506 += 1) {	// L789
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v502
        #pragma HLS dependence false variable=v503
        float v507 = v502[0][v504][v505][v506];	// L790
        v503[0][v504][(v505 + 1)][(v506 + 1)] = v507;	// L791
      }
    }
  }
  memcpy(v501, v503, 10368 * sizeof(float));	// L795

}

void kernel85(
  float v508[1][32][18][18],
  float v509
) {	// L798
  float v510[1][32][18][18];	// L799
  #pragma HLS resource variable=v510 core=ram_t2p_bram

  for (int v511 = 0; v511 < 32; v511 += 1) {	// L800
    for (int v512 = 0; v512 < 18; v512 += 1) {	// L801
      for (int v513 = 0; v513 < 18; v513 += 1) {	// L802
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v510
        v510[0][v511][v512][v513] = v509;	// L803
      }
    }
  }
  memcpy(v508, v510, 10368 * sizeof(float));	// L807

}

void kernel93(
  float v514[32],
  float v515[1][32][16][16]
) {	// L810
  float v516[1][32][16][16];	// L811
  #pragma HLS resource variable=v516 core=ram_t2p_bram

  float v517[32];	// L812
  #pragma HLS resource variable=v517 core=ram_t2p_bram

  memcpy(v517, v514, 32 * sizeof(float));	// L813

  for (int v518 = 0; v518 < 32; v518 += 1) {	// L814
    for (int v519 = 0; v519 < 16; v519 += 1) {	// L815
      for (int v520 = 0; v520 < 16; v520 += 1) {	// L816
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v517
        #pragma HLS dependence false variable=v516
        float v521 = v517[v518];	// L817
        v516[0][v518][v519][v520] = v521;	// L818
      }
    }
  }
  memcpy(v515, v516, 8192 * sizeof(float));	// L822

}

void kernel95(
  float v522[1][32][18][18],
  float v523
) {	// L825
  float v524[1][32][18][18];	// L826
  #pragma HLS resource variable=v524 core=ram_t2p_bram

  for (int v525 = 0; v525 < 32; v525 += 1) {	// L827
    for (int v526 = 0; v526 < 18; v526 += 1) {	// L828
      for (int v527 = 0; v527 < 18; v527 += 1) {	// L829
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v524
        v524[0][v525][v526][v527] = v523;	// L830
      }
    }
  }
  memcpy(v522, v524, 10368 * sizeof(float));	// L834

}

void kernel96(
  float v528[1][32][16][16],
  float v529[1][32][16][16],
  float v530,
  float v531,
  float v532
) {	// L837
  float v533[1][32][16][16];	// L838
  #pragma HLS resource variable=v533 core=ram_t2p_bram

  memcpy(v533, v528, 8192 * sizeof(float));	// L839

  float v534[1][32][16][16];	// L840
  #pragma HLS resource variable=v534 core=ram_t2p_bram

  memcpy(v534, v529, 8192 * sizeof(float));	// L841

  for (int v535 = 0; v535 < 32; v535 += 1) {	// L842
    for (int v536 = 0; v536 < 16; v536 += 1) {	// L843
      for (int v537 = 0; v537 < 16; v537 += 1) {	// L844
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v534
        #pragma HLS dependence false variable=v533
        float v538 = v534[0][v535][v536][v537];	// L845
        float v539 = v533[0][v535][v536][v537];	// L846
        float v540 = v539 * v531;	// L847
        float v541 = v538 / v532;	// L848
        float v542 = v541 * v530;	// L849
        float v543 = v542 + v540;	// L850
        v534[0][v535][v536][v537] = v543;	// L851
      }
    }
  }
  memcpy(v529, v534, 8192 * sizeof(float));	// L855

}

void kernel97(
  float v544[1][32][32][32],
  float v545[2][2],
  float v546[1][32][16][16]
) {	// L858
  float v547[1][32][16][16];	// L859
  #pragma HLS resource variable=v547 core=ram_t2p_bram

  memcpy(v547, v546, 8192 * sizeof(float));	// L860

  for (int v548 = 0; v548 < 2; v548 += 1) {	// L861
    for (int v549 = 0; v549 < 2; v549 += 1) {	// L862
      for (int v550 = 0; v550 < 32; v550 += 1) {	// L863
        for (int v551 = 0; v551 < 16; v551 += 1) {	// L864
          for (int v552 = 0; v552 < 16; v552 += 1) {	// L865
            #pragma HLS pipeline II=1
            #pragma HLS dependence false variable=v544
            #pragma HLS dependence false variable=v547
            float v553 = v544[0][v550][((v551 * 2) + v548)][((v552 * 2) + v549)];	// L866
            float v554 = v547[0][v550][v551][v552];	// L867
            float v555 = v554 + v553;	// L868
            v547[0][v550][v551][v552] = v555;	// L869
          }
        }
      }
    }
  }
  memcpy(v546, v547, 8192 * sizeof(float));	// L875

}

void kernel98(
  float v556[1][32][16][16],
  float v557
) {	// L878
  float v558[1][32][16][16];	// L879
  #pragma HLS resource variable=v558 core=ram_t2p_bram

  memcpy(v558, v556, 8192 * sizeof(float));	// L880

  for (int v559 = 0; v559 < 32; v559 += 1) {	// L881
    for (int v560 = 0; v560 < 16; v560 += 1) {	// L882
      for (int v561 = 0; v561 < 16; v561 += 1) {	// L883
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v558
        float v562 = v558[0][v559][v560][v561];	// L884
        float v563 = v562 / v557;	// L885
        v558[0][v559][v560][v561] = v563;	// L886
      }
    }
  }
  memcpy(v556, v558, 8192 * sizeof(float));	// L890

}

void kernel101(
  float v564[1][32][16][16],
  float v565
) {	// L893
  float v566[1][32][16][16];	// L894
  #pragma HLS resource variable=v566 core=ram_t2p_bram

  for (int v567 = 0; v567 < 32; v567 += 1) {	// L895
    for (int v568 = 0; v568 < 16; v568 += 1) {	// L896
      for (int v569 = 0; v569 < 16; v569 += 1) {	// L897
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v566
        v566[0][v567][v568][v569] = v565;	// L898
      }
    }
  }
  memcpy(v564, v566, 8192 * sizeof(float));	// L902

}

void kernel102(
  float v570[1][32][32][32],
  float v571[1][32][32][32],
  float v572[1][32][32][32],
  float v573
) {	// L905
  for (int v574 = 0; v574 < 32; v574 += 1) {	// L906
    for (int v575 = 0; v575 < 32; v575 += 1) {	// L907
      for (int v576 = 0; v576 < 32; v576 += 1) {	// L908
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v570
        #pragma HLS dependence false variable=v572
        #pragma HLS dependence false variable=v571
        float v577 = v570[0][v574][v575][v576];	// L909
        float v578 = v571[0][v574][v575][v576];	// L910
        float v579 = v573 - v578;	// L911
        float v580 = v573 - v577;	// L912
        float v581 = v580 * v579;	// L913
        float v582 = v573 - v581;	// L914
        v572[0][v574][v575][v576] = v582;	// L915
      }
    }
  }
}

void kernel103(
  float v583[1][32][32][32],
  float v584[1][32][32][32]
) {	// L921
  for (int v585 = 0; v585 < 32; v585 += 1) {	// L922
    for (int v586 = 0; v586 < 32; v586 += 1) {	// L923
      for (int v587 = 0; v587 < 32; v587 += 1) {	// L924
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v583
        #pragma HLS dependence false variable=v584
        float v588 = v583[0][v585][v586][v587];	// L925
        v584[0][v585][v586][v587] = v588;	// L926
      }
    }
  }
}

void kernel104(
  float v589[1][32][32][32],
  float v590[1][32][32][32],
  float v591
) {	// L932
  for (int v592 = 0; v592 < 32; v592 += 1) {	// L933
    for (int v593 = 0; v593 < 32; v593 += 1) {	// L934
      for (int v594 = 0; v594 < 32; v594 += 1) {	// L935
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v590
        #pragma HLS dependence false variable=v589
        float v595 = v590[0][v592][v593][v594];	// L936
        float v596 = v589[0][v592][v593][v594];	// L937
        float v597 = v596 * v591;	// L938
        float v598 = v595 - v596;	// L939
        float v599 = v598 + v597;	// L940
        v590[0][v592][v593][v594] = v599;	// L941
      }
    }
  }
}

void kernel105(
  float v600[1][32][32][32],
  float v601,
  float v602
) {	// L947
  for (int v603 = 0; v603 < 32; v603 += 1) {	// L948
    for (int v604 = 0; v604 < 32; v604 += 1) {	// L949
      for (int v605 = 0; v605 < 32; v605 += 1) {	// L950
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v600
        float v606 = v600[0][v603][v604][v605];	// L951
        float v607 = v606 - v602;	// L952
        bool v608 = v607 >= v601;	// L953
        float v609 = v608 ? v602 : v601;	// L954
        v600[0][v603][v604][v605] = v609;	// L955
      }
    }
  }
}

void kernel107(
  float v610[1][32][32][32],
  float v611[1][32][32][32],
  float v612[1][32][32][32],
  float v613
) {	// L961
  for (int v614 = 0; v614 < 32; v614 += 1) {	// L962
    for (int v615 = 0; v615 < 32; v615 += 1) {	// L963
      for (int v616 = 0; v616 < 32; v616 += 1) {	// L964
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v610
        #pragma HLS dependence false variable=v612
        #pragma HLS dependence false variable=v611
        float v617 = v610[0][v614][v615][v616];	// L965
        float v618 = v611[0][v614][v615][v616];	// L966
        float v619 = v618 / v613;	// L967
        float v620 = v617 / v613;	// L968
        float v621 = v617 - v620;	// L969
        float v622 = v621 + v619;	// L970
        v612[0][v614][v615][v616] = v622;	// L971
      }
    }
  }
}

void kernel108(
  float v623[1][32][34][34],
  float v624[32][32][3][3],
  float v625[1][32][32][32]
) {	// L977
  float v626[1][32][32][32];	// L978
  #pragma HLS resource variable=v626 core=ram_t2p_uram

  memcpy(v626, v625, 32768 * sizeof(float));	// L979

  float v627[32][32][3][3];	// L980
  #pragma HLS resource variable=v627 core=ram_t2p_bram

  memcpy(v627, v624, 9216 * sizeof(float));	// L981

  for (int v628 = 0; v628 < 32; v628 += 1) {	// L982
    for (int v629 = 0; v629 < 3; v629 += 1) {	// L983
      for (int v630 = 0; v630 < 3; v630 += 1) {	// L984
        for (int v631 = 0; v631 < 32; v631 += 1) {	// L985
          for (int v632 = 0; v632 < 32; v632 += 1) {	// L986
            for (int v633 = 0; v633 < 32; v633 += 1) {	// L987
              #pragma HLS pipeline II=1
              #pragma HLS dependence false variable=v623
              #pragma HLS dependence false variable=v626
              #pragma HLS dependence false variable=v627
              float v634 = v623[0][v628][(v632 + v629)][(v633 + v630)];	// L988
              float v635 = v627[v631][v628][v629][v630];	// L989
              float v636 = v626[0][v631][v632][v633];	// L990
              float v637 = v634 * v635;	// L991
              float v638 = v636 + v637;	// L992
              v626[0][v631][v632][v633] = v638;	// L993
            }
          }
        }
      }
    }
  }
  memcpy(v625, v626, 32768 * sizeof(float));	// L1000

}

void kernel109(
  float v639[1][32][32][32],
  float v640[1][32][34][34]
) {	// L1003
  for (int v641 = 0; v641 < 32; v641 += 1) {	// L1004
    for (int v642 = 0; v642 < 32; v642 += 1) {	// L1005
      for (int v643 = 0; v643 < 32; v643 += 1) {	// L1006
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v639
        #pragma HLS dependence false variable=v640
        float v644 = v639[0][v641][v642][v643];	// L1007
        v640[0][v641][(v642 + 1)][(v643 + 1)] = v644;	// L1008
      }
    }
  }
}

void kernel110(
  float v645[1][32][34][34],
  float v646
) {	// L1014
  for (int v647 = 0; v647 < 32; v647 += 1) {	// L1015
    for (int v648 = 0; v648 < 34; v648 += 1) {	// L1016
      for (int v649 = 0; v649 < 34; v649 += 1) {	// L1017
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v645
        v645[0][v647][v648][v649] = v646;	// L1018
      }
    }
  }
}

void kernel118(
  float v650[32],
  float v651[1][32][32][32]
) {	// L1024
  float v652[32];	// L1025
  #pragma HLS resource variable=v652 core=ram_t2p_bram

  memcpy(v652, v650, 32 * sizeof(float));	// L1026

  for (int v653 = 0; v653 < 32; v653 += 1) {	// L1027
    for (int v654 = 0; v654 < 32; v654 += 1) {	// L1028
      for (int v655 = 0; v655 < 32; v655 += 1) {	// L1029
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v652
        #pragma HLS dependence false variable=v651
        float v656 = v652[v653];	// L1030
        v651[0][v653][v654][v655] = v656;	// L1031
      }
    }
  }
}

void kernel120(
  float v657[1][32][34][34],
  float v658
) {	// L1037
  for (int v659 = 0; v659 < 32; v659 += 1) {	// L1038
    for (int v660 = 0; v660 < 34; v660 += 1) {	// L1039
      for (int v661 = 0; v661 < 34; v661 += 1) {	// L1040
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v657
        v657[0][v659][v660][v661] = v658;	// L1041
      }
    }
  }
}

void kernel121(
  float v662[1][32][32][32],
  float v663
) {	// L1047
  for (int v664 = 0; v664 < 32; v664 += 1) {	// L1048
    for (int v665 = 0; v665 < 32; v665 += 1) {	// L1049
      for (int v666 = 0; v666 < 32; v666 += 1) {	// L1050
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v662
        float v667 = v662[0][v664][v665][v666];	// L1051
        float v668 = v667 / v663;	// L1052
        v662[0][v664][v665][v666] = v668;	// L1053
      }
    }
  }
}

void kernel123(
  float v669[1][32][64][64],
  float v670[2][2],
  float v671[1][32][32][32]
) {	// L1059
  for (int v672 = 0; v672 < 2; v672 += 1) {	// L1060
    for (int v673 = 0; v673 < 2; v673 += 1) {	// L1061
      for (int v674 = 0; v674 < 32; v674 += 1) {	// L1062
        for (int v675 = 0; v675 < 32; v675 += 1) {	// L1063
          for (int v676 = 0; v676 < 32; v676 += 1) {	// L1064
            #pragma HLS pipeline II=1
            #pragma HLS dependence false variable=v669
            #pragma HLS dependence false variable=v671
            float v677 = v669[0][v674][((v675 * 2) + v672)][((v676 * 2) + v673)];	// L1065
            float v678 = v671[0][v674][v675][v676];	// L1066
            float v679 = v678 + v677;	// L1067
            v671[0][v674][v675][v676] = v679;	// L1068
          }
        }
      }
    }
  }
}

void kernel124(
  float v680[1][32][32][32],
  float v681
) {	// L1076
  for (int v682 = 0; v682 < 32; v682 += 1) {	// L1077
    for (int v683 = 0; v683 < 32; v683 += 1) {	// L1078
      for (int v684 = 0; v684 < 32; v684 += 1) {	// L1079
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v680
        v680[0][v682][v683][v684] = v681;	// L1080
      }
    }
  }
}

void kernel125(
  float v685[1][32][64][64],
  float v686[1][32][64][64],
  float v687[1][32][64][64],
  float v688
) {	// L1086
  for (int v689 = 0; v689 < 32; v689 += 1) {	// L1087
    for (int v690 = 0; v690 < 64; v690 += 1) {	// L1088
      for (int v691 = 0; v691 < 64; v691 += 1) {	// L1089
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v685
        #pragma HLS dependence false variable=v687
        #pragma HLS dependence false variable=v686
        float v692 = v685[0][v689][v690][v691];	// L1090
        float v693 = v686[0][v689][v690][v691];	// L1091
        float v694 = v688 - v693;	// L1092
        float v695 = v688 - v692;	// L1093
        float v696 = v695 * v694;	// L1094
        float v697 = v688 - v696;	// L1095
        v687[0][v689][v690][v691] = v697;	// L1096
      }
    }
  }
}

void kernel126(
  float v698[1][32][64][64],
  float v699[1][32][64][64]
) {	// L1102
  for (int v700 = 0; v700 < 32; v700 += 1) {	// L1103
    for (int v701 = 0; v701 < 64; v701 += 1) {	// L1104
      for (int v702 = 0; v702 < 64; v702 += 1) {	// L1105
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v698
        #pragma HLS dependence false variable=v699
        float v703 = v698[0][v700][v701][v702];	// L1106
        v699[0][v700][v701][v702] = v703;	// L1107
      }
    }
  }
}

void kernel127(
  float v704[1][32][64][64],
  float v705[1][32][64][64],
  float v706
) {	// L1113
  for (int v707 = 0; v707 < 32; v707 += 1) {	// L1114
    for (int v708 = 0; v708 < 64; v708 += 1) {	// L1115
      for (int v709 = 0; v709 < 64; v709 += 1) {	// L1116
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v705
        #pragma HLS dependence false variable=v704
        float v710 = v705[0][v707][v708][v709];	// L1117
        float v711 = v704[0][v707][v708][v709];	// L1118
        float v712 = v711 * v706;	// L1119
        float v713 = v710 - v711;	// L1120
        float v714 = v713 + v712;	// L1121
        v705[0][v707][v708][v709] = v714;	// L1122
      }
    }
  }
}

void kernel128(
  float v715[1][32][64][64],
  float v716,
  float v717
) {	// L1128
  for (int v718 = 0; v718 < 32; v718 += 1) {	// L1129
    for (int v719 = 0; v719 < 64; v719 += 1) {	// L1130
      for (int v720 = 0; v720 < 64; v720 += 1) {	// L1131
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v715
        float v721 = v715[0][v718][v719][v720];	// L1132
        float v722 = v721 - v717;	// L1133
        bool v723 = v722 >= v716;	// L1134
        float v724 = v723 ? v717 : v716;	// L1135
        v715[0][v718][v719][v720] = v724;	// L1136
      }
    }
  }
}

void kernel130(
  float v725[1][32][64][64],
  float v726[1][32][64][64],
  float v727[1][32][64][64],
  float v728
) {	// L1142
  for (int v729 = 0; v729 < 32; v729 += 1) {	// L1143
    for (int v730 = 0; v730 < 64; v730 += 1) {	// L1144
      for (int v731 = 0; v731 < 64; v731 += 1) {	// L1145
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v725
        #pragma HLS dependence false variable=v727
        #pragma HLS dependence false variable=v726
        float v732 = v725[0][v729][v730][v731];	// L1146
        float v733 = v726[0][v729][v730][v731];	// L1147
        float v734 = v733 / v728;	// L1148
        float v735 = v732 / v728;	// L1149
        float v736 = v732 - v735;	// L1150
        float v737 = v736 + v734;	// L1151
        v727[0][v729][v730][v731] = v737;	// L1152
      }
    }
  }
}

void kernel131(
  float v738[1][32][66][66],
  float v739[32][32][3][3],
  float v740[1][32][64][64]
) {	// L1158
  float v741[1][32][64][64];	// L1159
  #pragma HLS resource variable=v741 core=ram_t2p_uram

  memcpy(v741, v740, 131072 * sizeof(float));	// L1160

  float v742[32][32][3][3];	// L1161
  #pragma HLS resource variable=v742 core=ram_t2p_bram

  memcpy(v742, v739, 9216 * sizeof(float));	// L1162

  for (int v743 = 0; v743 < 32; v743 += 1) {	// L1163
    for (int v744 = 0; v744 < 3; v744 += 1) {	// L1164
      for (int v745 = 0; v745 < 3; v745 += 1) {	// L1165
        for (int v746 = 0; v746 < 32; v746 += 1) {	// L1166
          for (int v747 = 0; v747 < 64; v747 += 1) {	// L1167
            for (int v748 = 0; v748 < 64; v748 += 1) {	// L1168
              #pragma HLS pipeline II=1
              #pragma HLS dependence false variable=v738
              #pragma HLS dependence false variable=v741
              #pragma HLS dependence false variable=v742
              float v749 = v738[0][v743][(v747 + v744)][(v748 + v745)];	// L1169
              float v750 = v742[v746][v743][v744][v745];	// L1170
              float v751 = v741[0][v746][v747][v748];	// L1171
              float v752 = v749 * v750;	// L1172
              float v753 = v751 + v752;	// L1173
              v741[0][v746][v747][v748] = v753;	// L1174
            }
          }
        }
      }
    }
  }
  memcpy(v740, v741, 131072 * sizeof(float));	// L1181

}

void kernel132(
  float v754[1][32][64][64],
  float v755[1][32][66][66]
) {	// L1184
  for (int v756 = 0; v756 < 32; v756 += 1) {	// L1185
    for (int v757 = 0; v757 < 64; v757 += 1) {	// L1186
      for (int v758 = 0; v758 < 64; v758 += 1) {	// L1187
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v754
        #pragma HLS dependence false variable=v755
        float v759 = v754[0][v756][v757][v758];	// L1188
        v755[0][v756][(v757 + 1)][(v758 + 1)] = v759;	// L1189
      }
    }
  }
}

void kernel133(
  float v760[1][32][66][66],
  float v761
) {	// L1195
  for (int v762 = 0; v762 < 32; v762 += 1) {	// L1196
    for (int v763 = 0; v763 < 66; v763 += 1) {	// L1197
      for (int v764 = 0; v764 < 66; v764 += 1) {	// L1198
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v760
        v760[0][v762][v763][v764] = v761;	// L1199
      }
    }
  }
}

void kernel141(
  float v765[32],
  float v766[1][32][64][64]
) {	// L1205
  float v767[32];	// L1206
  #pragma HLS resource variable=v767 core=ram_t2p_bram

  memcpy(v767, v765, 32 * sizeof(float));	// L1207

  for (int v768 = 0; v768 < 32; v768 += 1) {	// L1208
    for (int v769 = 0; v769 < 64; v769 += 1) {	// L1209
      for (int v770 = 0; v770 < 64; v770 += 1) {	// L1210
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v767
        #pragma HLS dependence false variable=v766
        float v771 = v767[v768];	// L1211
        v766[0][v768][v769][v770] = v771;	// L1212
      }
    }
  }
}

void kernel143(
  float v772[1][32][66][66],
  float v773
) {	// L1218
  for (int v774 = 0; v774 < 32; v774 += 1) {	// L1219
    for (int v775 = 0; v775 < 66; v775 += 1) {	// L1220
      for (int v776 = 0; v776 < 66; v776 += 1) {	// L1221
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v772
        v772[0][v774][v775][v776] = v773;	// L1222
      }
    }
  }
}

void kernel144(
  float v777[1][32][64][64],
  float v778
) {	// L1228
  for (int v779 = 0; v779 < 32; v779 += 1) {	// L1229
    for (int v780 = 0; v780 < 64; v780 += 1) {	// L1230
      for (int v781 = 0; v781 < 64; v781 += 1) {	// L1231
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v777
        float v782 = v777[0][v779][v780][v781];	// L1232
        float v783 = v782 / v778;	// L1233
        v777[0][v779][v780][v781] = v783;	// L1234
      }
    }
  }
}

void kernel145(
  float v784[1][32][128][128],
  float v785[2][2],
  float v786[1][32][64][64]
) {	// L1240
  for (int v787 = 0; v787 < 2; v787 += 1) {	// L1241
    for (int v788 = 0; v788 < 2; v788 += 1) {	// L1242
      for (int v789 = 0; v789 < 32; v789 += 1) {	// L1243
        for (int v790 = 0; v790 < 64; v790 += 1) {	// L1244
          for (int v791 = 0; v791 < 64; v791 += 1) {	// L1245
            #pragma HLS pipeline II=1
            #pragma HLS dependence false variable=v784
            #pragma HLS dependence false variable=v786
            float v792 = v784[0][v789][((v790 * 2) + v787)][((v791 * 2) + v788)];	// L1246
            float v793 = v786[0][v789][v790][v791];	// L1247
            float v794 = v793 + v792;	// L1248
            v786[0][v789][v790][v791] = v794;	// L1249
          }
        }
      }
    }
  }
}

void kernel146(
  float v795[1][32][64][64],
  float v796
) {	// L1257
  for (int v797 = 0; v797 < 32; v797 += 1) {	// L1258
    for (int v798 = 0; v798 < 64; v798 += 1) {	// L1259
      for (int v799 = 0; v799 < 64; v799 += 1) {	// L1260
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v795
        v795[0][v797][v798][v799] = v796;	// L1261
      }
    }
  }
}

void kernel147(
  float v800[1][32][128][128],
  float v801[1][32][128][128],
  float v802[1][32][128][128],
  float v803
) {	// L1267
  for (int v804 = 0; v804 < 32; v804 += 1) {	// L1268
    for (int v805 = 0; v805 < 128; v805 += 1) {	// L1269
      for (int v806 = 0; v806 < 128; v806 += 1) {	// L1270
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v800
        #pragma HLS dependence false variable=v802
        #pragma HLS dependence false variable=v801
        float v807 = v800[0][v804][v805][v806];	// L1271
        float v808 = v801[0][v804][v805][v806];	// L1272
        float v809 = v803 - v808;	// L1273
        float v810 = v803 - v807;	// L1274
        float v811 = v810 * v809;	// L1275
        float v812 = v803 - v811;	// L1276
        v802[0][v804][v805][v806] = v812;	// L1277
      }
    }
  }
}

void kernel148(
  float v813[1][32][128][128],
  float v814[1][32][128][128]
) {	// L1283
  for (int v815 = 0; v815 < 32; v815 += 1) {	// L1284
    for (int v816 = 0; v816 < 128; v816 += 1) {	// L1285
      for (int v817 = 0; v817 < 128; v817 += 1) {	// L1286
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v813
        #pragma HLS dependence false variable=v814
        float v818 = v813[0][v815][v816][v817];	// L1287
        v814[0][v815][v816][v817] = v818;	// L1288
      }
    }
  }
}

void kernel149(
  float v819[1][32][128][128],
  float v820[1][32][128][128],
  float v821
) {	// L1294
  for (int v822 = 0; v822 < 32; v822 += 1) {	// L1295
    for (int v823 = 0; v823 < 128; v823 += 1) {	// L1296
      for (int v824 = 0; v824 < 128; v824 += 1) {	// L1297
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v820
        #pragma HLS dependence false variable=v819
        float v825 = v820[0][v822][v823][v824];	// L1298
        float v826 = v819[0][v822][v823][v824];	// L1299
        float v827 = v826 * v821;	// L1300
        float v828 = v825 - v826;	// L1301
        float v829 = v828 + v827;	// L1302
        v820[0][v822][v823][v824] = v829;	// L1303
      }
    }
  }
}

void kernel150(
  float v830[1][32][128][128],
  float v831,
  float v832
) {	// L1309
  for (int v833 = 0; v833 < 32; v833 += 1) {	// L1310
    for (int v834 = 0; v834 < 128; v834 += 1) {	// L1311
      for (int v835 = 0; v835 < 128; v835 += 1) {	// L1312
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v830
        float v836 = v830[0][v833][v834][v835];	// L1313
        float v837 = v836 - v832;	// L1314
        bool v838 = v837 >= v831;	// L1315
        float v839 = v838 ? v832 : v831;	// L1316
        v830[0][v833][v834][v835] = v839;	// L1317
      }
    }
  }
}

void kernel152(
  float v840[1][32][128][128],
  float v841[1][32][128][128],
  float v842[1][32][128][128],
  float v843
) {	// L1323
  for (int v844 = 0; v844 < 32; v844 += 1) {	// L1324
    for (int v845 = 0; v845 < 128; v845 += 1) {	// L1325
      for (int v846 = 0; v846 < 128; v846 += 1) {	// L1326
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v840
        #pragma HLS dependence false variable=v842
        #pragma HLS dependence false variable=v841
        float v847 = v840[0][v844][v845][v846];	// L1327
        float v848 = v841[0][v844][v845][v846];	// L1328
        float v849 = v848 / v843;	// L1329
        float v850 = v847 / v843;	// L1330
        float v851 = v847 - v850;	// L1331
        float v852 = v851 + v849;	// L1332
        v842[0][v844][v845][v846] = v852;	// L1333
      }
    }
  }
}

void kernel153(
  float v853[1][32][130][130],
  float v854[32][32][3][3],
  float v855[1][32][128][128]
) {	// L1339
  float v856[1][32][128][128];	// L1340
  #pragma HLS resource variable=v856 core=ram_t2p_uram

  memcpy(v856, v855, 524288 * sizeof(float));	// L1341

  float v857[32][32][3][3];	// L1342
  #pragma HLS resource variable=v857 core=ram_t2p_bram

  memcpy(v857, v854, 9216 * sizeof(float));	// L1343

  for (int v858 = 0; v858 < 32; v858 += 1) {	// L1344
    for (int v859 = 0; v859 < 3; v859 += 1) {	// L1345
      for (int v860 = 0; v860 < 3; v860 += 1) {	// L1346
        for (int v861 = 0; v861 < 32; v861 += 1) {	// L1347
          for (int v862 = 0; v862 < 128; v862 += 1) {	// L1348
            for (int v863 = 0; v863 < 128; v863 += 1) {	// L1349
              #pragma HLS pipeline II=1
              #pragma HLS dependence false variable=v853
              #pragma HLS dependence false variable=v856
              #pragma HLS dependence false variable=v857
              float v864 = v853[0][v858][(v862 + v859)][(v863 + v860)];	// L1350
              float v865 = v857[v861][v858][v859][v860];	// L1351
              float v866 = v856[0][v861][v862][v863];	// L1352
              float v867 = v864 * v865;	// L1353
              float v868 = v866 + v867;	// L1354
              v856[0][v861][v862][v863] = v868;	// L1355
            }
          }
        }
      }
    }
  }
  memcpy(v855, v856, 524288 * sizeof(float));	// L1362

}

void kernel154(
  float v869[1][32][128][128],
  float v870[1][32][130][130]
) {	// L1365
  for (int v871 = 0; v871 < 32; v871 += 1) {	// L1366
    for (int v872 = 0; v872 < 128; v872 += 1) {	// L1367
      for (int v873 = 0; v873 < 128; v873 += 1) {	// L1368
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v869
        #pragma HLS dependence false variable=v870
        float v874 = v869[0][v871][v872][v873];	// L1369
        v870[0][v871][(v872 + 1)][(v873 + 1)] = v874;	// L1370
      }
    }
  }
}

void kernel155(
  float v875[1][32][130][130],
  float v876
) {	// L1376
  for (int v877 = 0; v877 < 32; v877 += 1) {	// L1377
    for (int v878 = 0; v878 < 130; v878 += 1) {	// L1378
      for (int v879 = 0; v879 < 130; v879 += 1) {	// L1379
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v875
        v875[0][v877][v878][v879] = v876;	// L1380
      }
    }
  }
}

void kernel164(
  float v880[1][32][130][130],
  float v881
) {	// L1386
  for (int v882 = 0; v882 < 32; v882 += 1) {	// L1387
    for (int v883 = 0; v883 < 130; v883 += 1) {	// L1388
      for (int v884 = 0; v884 < 130; v884 += 1) {	// L1389
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v880
        v880[0][v882][v883][v884] = v881;	// L1390
      }
    }
  }
}

void kernel170(
  float v885[1][2][130][130],
  float v886[32][2][3][3],
  float v887[1][32][128][128]
) {	// L1396
  float v888[32][2][3][3];	// L1397
  #pragma HLS resource variable=v888 core=ram_t2p_bram

  memcpy(v888, v886, 576 * sizeof(float));	// L1398

  for (int v889 = 0; v889 < 2; v889 += 1) {	// L1399
    for (int v890 = 0; v890 < 3; v890 += 1) {	// L1400
      for (int v891 = 0; v891 < 3; v891 += 1) {	// L1401
        for (int v892 = 0; v892 < 32; v892 += 1) {	// L1402
          for (int v893 = 0; v893 < 128; v893 += 1) {	// L1403
            for (int v894 = 0; v894 < 128; v894 += 1) {	// L1404
              #pragma HLS pipeline II=1
              #pragma HLS dependence false variable=v885
              #pragma HLS dependence false variable=v887
              #pragma HLS dependence false variable=v888
              float v895 = v885[0][v889][(v893 + v890)][(v894 + v891)];	// L1405
              float v896 = v888[v892][v889][v890][v891];	// L1406
              float v897 = v887[0][v892][v893][v894];	// L1407
              float v898 = v895 * v896;	// L1408
              float v899 = v897 + v898;	// L1409
              v887[0][v892][v893][v894] = v899;	// L1410
            }
          }
        }
      }
    }
  }
}

void kernel172(
  float v900[32],
  float v901[1][32][128][128]
) {	// L1419
  float v902[32];	// L1420
  #pragma HLS resource variable=v902 core=ram_t2p_bram

  memcpy(v902, v900, 32 * sizeof(float));	// L1421

  for (int v903 = 0; v903 < 32; v903 += 1) {	// L1422
    for (int v904 = 0; v904 < 128; v904 += 1) {	// L1423
      for (int v905 = 0; v905 < 128; v905 += 1) {	// L1424
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v902
        #pragma HLS dependence false variable=v901
        float v906 = v902[v903];	// L1425
        v901[0][v903][v904][v905] = v906;	// L1426
      }
    }
  }
}

void kernel173(
  float v907[1][2][128][128],
  float v908[1][2][130][130]
) {	// L1432
  for (int v909 = 0; v909 < 2; v909 += 1) {	// L1433
    for (int v910 = 0; v910 < 128; v910 += 1) {	// L1434
      for (int v911 = 0; v911 < 128; v911 += 1) {	// L1435
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v907
        #pragma HLS dependence false variable=v908
        float v912 = v907[0][v909][v910][v911];	// L1436
        v908[0][v909][(v910 + 1)][(v911 + 1)] = v912;	// L1437
      }
    }
  }
}

void kernel174(
  float v913[1][2][130][130],
  float v914
) {	// L1443
  for (int v915 = 0; v915 < 2; v915 += 1) {	// L1444
    for (int v916 = 0; v916 < 130; v916 += 1) {	// L1445
      for (int v917 = 0; v917 < 130; v917 += 1) {	// L1446
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v913
        v913[0][v915][v916][v917] = v914;	// L1447
      }
    }
  }
}

/// The top function
void control(
  ap_int<32> v918[12864384],
  ap_int<32> v919[12864384],
  ap_int<32> v920[12864384]
) {	// L1453
  #pragma HLS interface s_axilite port=return bundle=ctrl
  #pragma hls interface m_axi offset=direct bundle=g0 port=v918
  #pragma hls stable variable=v918
  #pragma hls interface m_axi offset=direct bundle=g0 port=v919
  #pragma hls stable variable=v919
  #pragma hls interface m_axi offset=direct bundle=g0 port=v920
  #pragma hls stable variable=v920

  auto v921 = reinterpret_cast<float(*)[2][130][130]>(v919 + 8912896);
  kernel174(v921, (float)0.000000);	// L1465
  auto v922 = reinterpret_cast<float(*)[2][128][128]>(v918);
  kernel173(v922, v921);	// L1467
  auto v923 = reinterpret_cast<float(*)[32][128][128]>(v919 + 9453696);
  auto v924 = reinterpret_cast<float(*)>(v920 + 12845952);
  kernel172(v924, v923);	// L1470
  auto v925 = reinterpret_cast<float(*)[32][128][128]>(v918 + 9994496);
  kernel148(v923, v925);	// L1472
  auto v926 = reinterpret_cast<float(*)[2][3][3]>(v920 + 12855168);
  kernel170(v921, v926, v925);	// L1474
  auto v927 = reinterpret_cast<float(*)[32][128][128]>(v918 + 524288);
  auto v928 = reinterpret_cast<float(*)[32][128][128]>(v918 + 8912896);
  kernel152(v927, v925, v928, (float)-0.000000);	// L1477
  kernel148(v928, v925);	// L1478
  kernel150(v925, (float)0.000000, (float)1.000000);	// L1479
  kernel149(v925, v928, (float)0.000000);	// L1480
  kernel148(v928, v927);	// L1481
  auto v929 = reinterpret_cast<float(*)[32][130][130]>(v918 + 10535296);
  kernel164(v929, (float)0.000000);	// L1483
  kernel154(v925, v929);	// L1484
  auto v930 = reinterpret_cast<float(*)[32][128][128]>(v919 + 9994496);
  kernel148(v923, v930);	// L1486
  auto v931 = reinterpret_cast<float(*)[32][3][3]>(v920 + 12836736);
  kernel153(v929, v931, v930);	// L1488
  auto v932 = reinterpret_cast<float(*)[32][128][128]>(v918 + 1048576);
  kernel152(v932, v930, v928, (float)-0.000000);	// L1490
  kernel148(v928, v925);	// L1491
  kernel150(v925, (float)0.000000, (float)1.000000);	// L1492
  kernel149(v925, v928, (float)0.000000);	// L1493
  kernel148(v928, v932);	// L1494
  auto v933 = reinterpret_cast<float(*)[32][130][130]>(v919 + 10535296);
  kernel155(v933, (float)0.000000);	// L1496
  kernel154(v925, v933);	// L1497
  auto v934 = reinterpret_cast<float(*)[32][3][3]>(v920 + 12827520);
  kernel153(v933, v934, v923);	// L1499
  auto v935 = reinterpret_cast<float(*)[32][128][128]>(v918 + 1572864);
  kernel152(v935, v923, v928, (float)-0.000000);	// L1501
  kernel148(v928, v923);	// L1502
  kernel150(v923, (float)0.000000, (float)1.000000);	// L1503
  kernel149(v923, v928, (float)0.000000);	// L1504
  kernel148(v928, v935);	// L1505
  kernel147(v925, v923, v928, (float)1.000000);	// L1506
  auto v936 = reinterpret_cast<float(*)[32][64][64]>(v919 + 9453696);
  kernel146(v936, (float)0.000000);	// L1508
  auto v937 = reinterpret_cast<float(*)[2]>(v919 + 9994496);
  kernel145(v928, v937, v936);	// L1510
  kernel144(v936, (float)4.000000);	// L1511
  auto v938 = reinterpret_cast<float(*)[32][66][66]>(v918 + 8912896);
  kernel143(v938, (float)0.000000);	// L1513
  kernel132(v936, v938);	// L1514
  auto v939 = reinterpret_cast<float(*)[32][64][64]>(v918 + 10535296);
  kernel141(v924, v939);	// L1516
  auto v940 = reinterpret_cast<float(*)[32][64][64]>(v919 + 11076096);
  kernel126(v939, v940);	// L1518
  auto v941 = reinterpret_cast<float(*)[32][3][3]>(v920 + 12818304);
  kernel131(v938, v941, v940);	// L1520
  auto v942 = reinterpret_cast<float(*)[32][64][64]>(v918 + 2097152);
  kernel130(v942, v940, v936, (float)-0.000000);	// L1522
  auto v943 = reinterpret_cast<float(*)[32][64][64]>(v920 + 8912896);
  kernel126(v936, v943);	// L1524
  kernel128(v943, (float)0.000000, (float)1.000000);	// L1525
  kernel127(v943, v936, (float)0.000000);	// L1526
  kernel126(v936, v942);	// L1527
  auto v944 = reinterpret_cast<float(*)[32][66][66]>(v918 + 11076096);
  kernel133(v944, (float)0.000000);	// L1529
  kernel132(v943, v944);	// L1530
  auto v945 = reinterpret_cast<float(*)[32][3][3]>(v920 + 12809088);
  kernel131(v944, v945, v939);	// L1532
  auto v946 = reinterpret_cast<float(*)[32][64][64]>(v918 + 2621440);
  kernel130(v946, v939, v936, (float)-0.000000);	// L1534
  kernel126(v936, v939);	// L1535
  kernel128(v939, (float)0.000000, (float)1.000000);	// L1536
  kernel127(v939, v936, (float)0.000000);	// L1537
  kernel126(v936, v946);	// L1538
  kernel125(v943, v939, v936, (float)1.000000);	// L1539
  auto v947 = reinterpret_cast<float(*)[32][32][32]>(v920 + 8912896);
  kernel124(v947, (float)0.000000);	// L1541
  kernel123(v936, v937, v947);	// L1542
  auto v948 = reinterpret_cast<float(*)[32][32][32]>(v918 + 9453696);
  kernel103(v947, v948);	// L1544
  kernel121(v948, (float)4.000000);	// L1545
  auto v949 = reinterpret_cast<float(*)[32][34][34]>(v918 + 10535296);
  kernel120(v949, (float)0.000000);	// L1547
  kernel109(v948, v949);	// L1548
  auto v950 = reinterpret_cast<float(*)[32][32][32]>(v918 + 11076096);
  kernel118(v924, v950);	// L1550
  auto v951 = reinterpret_cast<float(*)[32][32][32]>(v919 + 11616896);
  kernel103(v950, v951);	// L1552
  auto v952 = reinterpret_cast<float(*)[32][3][3]>(v920 + 12799872);
  kernel108(v949, v952, v951);	// L1554
  auto v953 = reinterpret_cast<float(*)[32][32][32]>(v918 + 3145728);
  kernel107(v953, v951, v947, (float)-0.000000);	// L1556
  auto v954 = reinterpret_cast<float(*)[32][32][32]>(v919 + 10535296);
  kernel103(v947, v954);	// L1558
  kernel105(v954, (float)0.000000, (float)1.000000);	// L1559
  kernel104(v954, v947, (float)0.000000);	// L1560
  kernel103(v947, v953);	// L1561
  auto v955 = reinterpret_cast<float(*)[32][34][34]>(v918 + 11616896);
  kernel110(v955, (float)0.000000);	// L1563
  kernel109(v954, v955);	// L1564
  auto v956 = reinterpret_cast<float(*)[32][3][3]>(v920 + 12790656);
  kernel108(v955, v956, v950);	// L1566
  auto v957 = reinterpret_cast<float(*)[32][32][32]>(v918 + 3670016);
  kernel107(v957, v950, v947, (float)-0.000000);	// L1568
  kernel103(v947, v950);	// L1569
  kernel105(v950, (float)0.000000, (float)1.000000);	// L1570
  kernel104(v950, v947, (float)0.000000);	// L1571
  kernel103(v947, v957);	// L1572
  kernel102(v954, v950, v947, (float)1.000000);	// L1573
  auto v958 = reinterpret_cast<float(*)[32][16][16]>(v920 + 10535296);
  kernel101(v958, (float)0.000000);	// L1575
  auto v959 = reinterpret_cast<float(*)[32][16][16]>(v918 + 11076096);
  kernel78(v958, v959);	// L1577
  kernel97(v947, v937, v959);	// L1578
  kernel98(v959, (float)4.000000);	// L1579
  kernel97(v948, v937, v958);	// L1580
  kernel96(v959, v958, (float)0.731261, (float)0.730867, (float)4.000000);	// L1581
  auto v960 = reinterpret_cast<float(*)[32][18][18]>(v918 + 8912896);
  kernel95(v960, (float)0.000000);	// L1583
  kernel84(v958, v960);	// L1584
  auto v961 = reinterpret_cast<float(*)[32][16][16]>(v918 + 9453696);
  kernel93(v924, v961);	// L1586
  auto v962 = reinterpret_cast<float(*)[32][16][16]>(v919 + 11616896);
  kernel78(v961, v962);	// L1588
  auto v963 = reinterpret_cast<float(*)[32][3][3]>(v920 + 12781440);
  kernel83(v960, v963, v962);	// L1590
  auto v964 = reinterpret_cast<float(*)[32][16][16]>(v918 + 4194304);
  kernel82(v964, v962, v958, (float)-0.000000);	// L1592
  auto v965 = reinterpret_cast<float(*)[32][16][16]>(v919 + 8912896);
  kernel78(v958, v965);	// L1594
  kernel80(v965, (float)0.000000, (float)1.000000);	// L1595
  kernel79(v965, v958, (float)0.000000);	// L1596
  kernel78(v958, v964);	// L1597
  auto v966 = reinterpret_cast<float(*)[32][18][18]>(v919 + 11616896);
  kernel85(v966, (float)0.000000);	// L1599
  kernel84(v965, v966);	// L1600
  auto v967 = reinterpret_cast<float(*)[32][3][3]>(v920 + 12772224);
  kernel83(v966, v967, v961);	// L1602
  auto v968 = reinterpret_cast<float(*)[32][16][16]>(v918 + 4718592);
  kernel82(v968, v961, v958, (float)-0.000000);	// L1604
  kernel78(v958, v961);	// L1605
  kernel80(v961, (float)0.000000, (float)1.000000);	// L1606
  kernel79(v961, v958, (float)0.000000);	// L1607
  kernel78(v958, v968);	// L1608
  kernel77(v965, v961, v958, (float)1.000000);	// L1609
  auto v969 = reinterpret_cast<float(*)[32][8][8]>(v918 + 8912896);
  kernel76(v969, (float)0.000000);	// L1611
  kernel75(v958, v937, v969);	// L1612
  auto v970 = reinterpret_cast<float(*)[32][8][8]>(v920 + 9453696);
  kernel55(v969, v970);	// L1614
  kernel73(v970, (float)4.000000);	// L1615
  auto v971 = reinterpret_cast<float(*)[32][10][10]>(v918 + 10535296);
  kernel72(v971, (float)0.000000);	// L1617
  kernel61(v970, v971);	// L1618
  auto v972 = reinterpret_cast<float(*)[32][8][8]>(v918 + 11616896);
  kernel70(v924, v972);	// L1620
  auto v973 = reinterpret_cast<float(*)[32][8][8]>(v919 + 12157696);
  kernel55(v972, v973);	// L1622
  auto v974 = reinterpret_cast<float(*)[32][3][3]>(v920 + 12763008);
  kernel60(v971, v974, v973);	// L1624
  auto v975 = reinterpret_cast<float(*)[32][8][8]>(v918 + 5242880);
  kernel59(v975, v973, v969, (float)-0.000000);	// L1626
  auto v976 = reinterpret_cast<float(*)[32][8][8]>(v919 + 10535296);
  kernel55(v969, v976);	// L1628
  kernel57(v976, (float)0.000000, (float)1.000000);	// L1629
  kernel56(v976, v969, (float)0.000000);	// L1630
  kernel55(v969, v975);	// L1631
  auto v977 = reinterpret_cast<float(*)[32][10][10]>(v918 + 12157696);
  kernel62(v977, (float)0.000000);	// L1633
  kernel61(v976, v977);	// L1634
  auto v978 = reinterpret_cast<float(*)[32][3][3]>(v920 + 12753792);
  kernel60(v977, v978, v972);	// L1636
  auto v979 = reinterpret_cast<float(*)[32][8][8]>(v918 + 5767168);
  kernel59(v979, v972, v969, (float)-0.000000);	// L1638
  auto v980 = reinterpret_cast<float(*)[32][8][8]>(v920 + 11616896);
  kernel55(v969, v980);	// L1640
  kernel57(v980, (float)0.000000, (float)1.000000);	// L1641
  kernel56(v980, v969, (float)0.000000);	// L1642
  kernel55(v969, v979);	// L1643
  kernel54(v976, v980, v969, (float)1.000000);	// L1644
  auto v981 = reinterpret_cast<float(*)[32][4][4]>(v918 + 10535296);
  kernel53(v981, (float)0.000000);	// L1646
  auto v982 = reinterpret_cast<float(*)[32][4][4]>(v919 + 11616896);
  kernel29(v981, v982);	// L1648
  kernel48(v969, v937, v982);	// L1649
  auto v983 = reinterpret_cast<float(*)[32][4][4]>(v920 + 8912896);
  kernel29(v981, v983);	// L1651
  auto v984 = reinterpret_cast<float(*)[4]>(v919 + 12157696);
  kernel49(v959, v984, v983);	// L1653
  kernel48(v970, v937, v981);	// L1654
  kernel47(v983, v982, v981, (float)0.730819, (float)16.000000, (float)0.729963, (float)0.732428, (float)4.000000);	// L1655
  auto v985 = reinterpret_cast<float(*)[32][6][6]>(v918 + 8912896);
  kernel46(v985, (float)0.000000);	// L1657
  kernel35(v981, v985);	// L1658
  auto v986 = reinterpret_cast<float(*)[32][4][4]>(v918 + 9453696);
  kernel44(v924, v986);	// L1660
  auto v987 = reinterpret_cast<float(*)[32][4][4]>(v919 + 11076096);
  kernel29(v986, v987);	// L1662
  auto v988 = reinterpret_cast<float(*)[32][3][3]>(v920 + 12744576);
  kernel34(v985, v988, v987);	// L1664
  auto v989 = reinterpret_cast<float(*)[32][4][4]>(v918 + 6291456);
  kernel33(v989, v987, v981, (float)-0.000000);	// L1666
  kernel29(v981, v983);	// L1667
  kernel31(v983, (float)0.000000, (float)1.000000);	// L1668
  kernel30(v983, v981, (float)0.000000);	// L1669
  kernel29(v981, v989);	// L1670
  auto v990 = reinterpret_cast<float(*)[32][6][6]>(v919 + 11076096);
  kernel36(v990, (float)0.000000);	// L1672
  kernel35(v983, v990);	// L1673
  auto v991 = reinterpret_cast<float(*)[32][3][3]>(v920 + 12735360);
  kernel34(v990, v991, v986);	// L1675
  auto v992 = reinterpret_cast<float(*)[32][4][4]>(v918 + 6815744);
  kernel33(v992, v986, v981, (float)-0.000000);	// L1677
  auto v993 = reinterpret_cast<float(*)[32][4][4]>(v919 + 9453696);
  kernel29(v981, v993);	// L1679
  kernel31(v993, (float)0.000000, (float)1.000000);	// L1680
  kernel30(v993, v981, (float)0.000000);	// L1681
  kernel29(v981, v992);	// L1682
  kernel28(v983, v993, v981, (float)1.000000);	// L1683
  auto v994 = reinterpret_cast<float(*)[32][2][2]>(v919 + 8912896);
  kernel27(v994, (float)0.000000);	// L1685
  kernel26(v981, v937, v994);	// L1686
  kernel25(v994, (float)4.000000);	// L1687
  kernel24(v986, (float)0.000000);	// L1688
  kernel13(v994, v986);	// L1689
  auto v995 = reinterpret_cast<float(*)[32][2][2]>(v918 + 10535296);
  kernel22(v924, v995);	// L1691
  auto v996 = reinterpret_cast<float(*)[32][2][2]>(v919 + 11076096);
  kernel7(v995, v996);	// L1693
  auto v997 = reinterpret_cast<float(*)[32][3][3]>(v920 + 12726144);
  kernel12(v986, v997, v996);	// L1695
  auto v998 = reinterpret_cast<float(*)[32][2][2]>(v918 + 7340032);
  kernel11(v998, v996, v994, (float)-0.000000);	// L1697
  auto v999 = reinterpret_cast<float(*)[32][2][2]>(v918 + 9453696);
  kernel7(v994, v999);	// L1699
  kernel9(v999, (float)0.000000, (float)1.000000);	// L1700
  kernel8(v999, v994, (float)0.000000);	// L1701
  kernel7(v994, v998);	// L1702
  auto v1000 = reinterpret_cast<float(*)[32][4][4]>(v918 + 11076096);
  kernel14(v1000, (float)0.000000);	// L1704
  kernel13(v999, v1000);	// L1705
  auto v1001 = reinterpret_cast<float(*)[32][3][3]>(v920 + 12716928);
  kernel12(v1000, v1001, v995);	// L1707
  auto v1002 = reinterpret_cast<float(*)[32][2][2]>(v918 + 7864320);
  kernel11(v1002, v995, v994, (float)-0.000000);	// L1709
  kernel7(v994, v995);	// L1710
  kernel9(v995, (float)0.000000, (float)1.000000);	// L1711
  kernel8(v995, v994, (float)0.000000);	// L1712
  kernel7(v994, v1002);	// L1713
  kernel6(v999, v995, v994, (float)1.000000);	// L1714
  auto v1003 = reinterpret_cast<float(*)[32][1][1]>(v918 + 9453696);
  kernel5(v1003, (float)0.000000);	// L1716
  kernel4(v994, v937, v1003);	// L1717
  kernel3(v1003, (float)4.000000);	// L1718
  auto v1004 = reinterpret_cast<float(*)[11]>(v918 + 8388608);
  kernel2(v1004, (float)0.000000);	// L1720
  auto v1005 = reinterpret_cast<float(*)[11]>(v920 + 12698496);
  kernel1(v1003, v1005, v1004);	// L1722
  auto v1006 = reinterpret_cast<float(*)>(v920 + 12707712);
  kernel0(v1006, v1004);	// L1724
}

/// The T-step wrapper (FHCA v1.4: on-chip time-step loop)
/// Drives the single-step control T times; membrane states persist in DDR top_level buffers.
/// input_frames: DDR staging of T input frames (per-step-input);
///   frame t is memcpy'd to the input slot (arg0+0) before step t.
///   frame_elems=0: static input (host pre-writes frame, no copy).
/// out_frames: per-step outputs staged to DDR (out region assumed on
///   arg0 at out_elem_offset); out_elems=0: skip staging.
void control_t(
  ap_int<32> t_v0[12864384],
  ap_int<32> t_v1[12864384],
  ap_int<32> t_v2[12864384],
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

