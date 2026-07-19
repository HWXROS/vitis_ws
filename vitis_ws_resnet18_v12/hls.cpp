
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
  float v0[1000],
  float v1[1][1000]
) {	// L2
  float v2[1000];	// L3
  #pragma HLS resource variable=v2 core=ram_t2p_bram

  memcpy(v2, v0, 1000 * sizeof(float));	// L4

  float v3[1][1000];	// L5
  #pragma HLS resource variable=v3 core=ram_t2p_bram

  memcpy(v3, v1, 1000 * sizeof(float));	// L6

  for (int v4 = 0; v4 < 1000; v4 += 1) {	// L7
    #pragma HLS pipeline II=1
    #pragma HLS dependence false variable=v3
    #pragma HLS dependence false variable=v2
    float v5 = v3[0][v4];	// L8
    float v6 = v2[v4];	// L9
    float v7 = v5 + v6;	// L10
    v3[0][v4] = v7;	// L11
  }
  memcpy(v1, v3, 1000 * sizeof(float));	// L13

}

void kernel1(
  float v8[1][512][1][1],
  float v9[512][1000],
  float v10[1][1000]
) {	// L16
  float v11[1][1000];	// L17
  #pragma HLS resource variable=v11 core=ram_t2p_bram

  memcpy(v11, v10, 1000 * sizeof(float));	// L18

  float v12[1][512][1][1];	// L19
  #pragma HLS resource variable=v12 core=ram_t2p_bram

  memcpy(v12, v8, 512 * sizeof(float));	// L20

  for (int v13 = 0; v13 < 512; v13 += 1) {	// L21
    for (int v14 = 0; v14 < 1000; v14 += 1) {	// L22
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v12
      #pragma HLS dependence false variable=v9
      #pragma HLS dependence false variable=v11
      float v15 = v12[0][v13][0][0];	// L23
      float v16 = v9[v13][v14];	// L24
      float v17 = v11[0][v14];	// L25
      float v18 = v15 * v16;	// L26
      float v19 = v17 + v18;	// L27
      v11[0][v14] = v19;	// L28
    }
  }
  memcpy(v10, v11, 1000 * sizeof(float));	// L31

}

void kernel2(
  float v20[1][1000],
  float v21
) {	// L34
  float v22[1][1000];	// L35
  #pragma HLS resource variable=v22 core=ram_t2p_bram

  for (int v23 = 0; v23 < 1000; v23 += 1) {	// L36
    #pragma HLS pipeline II=1
    #pragma HLS dependence false variable=v22
    v22[0][v23] = v21;	// L37
  }
  memcpy(v20, v22, 1000 * sizeof(float));	// L39

}

void kernel3(
  float v24[1][512][1][1],
  float v25
) {	// L42
  float v26[1][512][1][1];	// L43
  #pragma HLS resource variable=v26 core=ram_t2p_bram

  memcpy(v26, v24, 512 * sizeof(float));	// L44

  for (int v27 = 0; v27 < 512; v27 += 1) {	// L45
    float v28 = v26[0][v27][0][0];	// L46
    float v29 = v28 / v25;	// L47
    v26[0][v27][0][0] = v29;	// L48
  }
  memcpy(v24, v26, 512 * sizeof(float));	// L50

}

void kernel4(
  float v30[1][512][7][7],
  float v31[7][7],
  float v32[1][512][1][1]
) {	// L53
  float v33[1][512][1][1];	// L54
  #pragma HLS resource variable=v33 core=ram_t2p_bram

  memcpy(v33, v32, 512 * sizeof(float));	// L55

  for (int v34 = 0; v34 < 7; v34 += 1) {	// L56
    for (int v35 = 0; v35 < 7; v35 += 1) {	// L57
      for (int v36 = 0; v36 < 512; v36 += 1) {	// L58
        float v37 = v30[0][v36][v34][v35];	// L59
        float v38 = v33[0][v36][0][0];	// L60
        float v39 = v38 + v37;	// L61
        v33[0][v36][0][0] = v39;	// L62
      }
    }
  }
  memcpy(v32, v33, 512 * sizeof(float));	// L66

}

void kernel5(
  float v40[1][512][1][1],
  float v41
) {	// L69
  float v42[1][512][1][1];	// L70
  #pragma HLS resource variable=v42 core=ram_t2p_bram

  for (int v43 = 0; v43 < 512; v43 += 1) {	// L71
    v42[0][v43][0][0] = v41;	// L72
  }
  memcpy(v40, v42, 512 * sizeof(float));	// L74

}

void kernel6(
  float v44[1][512][7][7],
  float v45[1][512][7][7]
) {	// L77
  for (int v46 = 0; v46 < 512; v46 += 1) {	// L78
    for (int v47 = 0; v47 < 7; v47 += 1) {	// L79
      for (int v48 = 0; v48 < 7; v48 += 1) {	// L80
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v44
        #pragma HLS dependence false variable=v45
        float v49 = v44[0][v46][v47][v48];	// L81
        v45[0][v46][v47][v48] = v49;	// L82
      }
    }
  }
}

void kernel7(
  float v50[1][512][7][7],
  float v51[1][512][7][7],
  float v52
) {	// L88
  float v53[1][512][7][7];	// L89
  #pragma HLS resource variable=v53 core=ram_t2p_bram

  memcpy(v53, v51, 25088 * sizeof(float));	// L90

  for (int v54 = 0; v54 < 512; v54 += 1) {	// L91
    for (int v55 = 0; v55 < 7; v55 += 1) {	// L92
      for (int v56 = 0; v56 < 7; v56 += 1) {	// L93
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v53
        #pragma HLS dependence false variable=v50
        float v57 = v53[0][v54][v55][v56];	// L94
        float v58 = v50[0][v54][v55][v56];	// L95
        float v59 = v58 * v52;	// L96
        float v60 = v58 * v57;	// L97
        float v61 = v57 - v60;	// L98
        float v62 = v61 + v59;	// L99
        v53[0][v54][v55][v56] = v62;	// L100
      }
    }
  }
  memcpy(v51, v53, 25088 * sizeof(float));	// L104

}

void kernel8(
  float v63[1][512][7][7],
  float v64,
  float v65
) {	// L107
  float v66[1][512][7][7];	// L108
  #pragma HLS resource variable=v66 core=ram_t2p_bram

  memcpy(v66, v63, 25088 * sizeof(float));	// L109

  for (int v67 = 0; v67 < 512; v67 += 1) {	// L110
    for (int v68 = 0; v68 < 7; v68 += 1) {	// L111
      for (int v69 = 0; v69 < 7; v69 += 1) {	// L112
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v66
        float v70 = v66[0][v67][v68][v69];	// L113
        float v71 = v70 - v65;	// L114
        bool v72 = v71 >= v64;	// L115
        float v73 = v72 ? v65 : v64;	// L116
        v66[0][v67][v68][v69] = v73;	// L117
      }
    }
  }
  memcpy(v63, v66, 25088 * sizeof(float));	// L121

}

void kernel10(
  float v74[1][512][7][7],
  float v75[1][512][7][7],
  float v76[1][512][7][7]
) {	// L124
  float v77[1][512][7][7];	// L125
  #pragma HLS resource variable=v77 core=ram_t2p_bram

  memcpy(v77, v76, 25088 * sizeof(float));	// L126

  for (int v78 = 0; v78 < 512; v78 += 1) {	// L127
    for (int v79 = 0; v79 < 7; v79 += 1) {	// L128
      for (int v80 = 0; v80 < 7; v80 += 1) {	// L129
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v75
        #pragma HLS dependence false variable=v77
        #pragma HLS dependence false variable=v74
        float v81 = v75[0][v78][v79][v80];	// L130
        float v82 = v74[0][v78][v79][v80];	// L131
        float v83 = v81 + v82;	// L132
        float v84 = v77[0][v78][v79][v80];	// L133
        float v85 = v84 + v83;	// L134
        v77[0][v78][v79][v80] = v85;	// L135
      }
    }
  }
  memcpy(v76, v77, 25088 * sizeof(float));	// L139

}

void kernel11(
  float v86[1][512][9][9],
  float v87[512][512][3][3],
  float v88[1][512][7][7]
) {	// L142
  float v89[1][512][9][9];	// L143
  #pragma HLS resource variable=v89 core=ram_t2p_uram

  memcpy(v89, v86, 41472 * sizeof(float));	// L144

  float v90[1][512][7][7];	// L145
  #pragma HLS resource variable=v90 core=ram_t2p_bram

  memcpy(v90, v88, 25088 * sizeof(float));	// L146

  auto v91 = reinterpret_cast<float(*)[512][3][3]>(v87);	// L148

  for (int v92 = 0; v92 < 512; v92 += 1) {	// L149
    for (int v93 = 0; v93 < 3; v93 += 1) {	// L150
      for (int v94 = 0; v94 < 3; v94 += 1) {	// L151
        for (int v95 = 0; v95 < 512; v95 += 1) {	// L152
          float v96 = v91[v95][v92][v93][v94];	// L153
          for (int v97 = 0; v97 < 7; v97 += 1) {	// L154
            for (int v98 = 0; v98 < 7; v98 += 1) {	// L155
              #pragma HLS pipeline II=1
              #pragma HLS dependence false variable=v89
              #pragma HLS dependence false variable=v90
              float v99 = v89[0][v92][(v97 + v93)][(v98 + v94)];	// L156
              float v100 = v90[0][v95][v97][v98];	// L157
              float v101 = v99 * v96;	// L158
              float v102 = v100 + v101;	// L159
              v90[0][v95][v97][v98] = v102;	// L160
            }
          }
        }
      }
    }
  }
  memcpy(v88, v90, 25088 * sizeof(float));	// L167

}

void kernel12(
  float v103[512],
  float v104[1][512][7][7]
) {	// L170
  float v105[512];	// L171
  #pragma HLS resource variable=v105 core=ram_t2p_bram

  memcpy(v105, v103, 512 * sizeof(float));	// L172

  for (int v106 = 0; v106 < 512; v106 += 1) {	// L173
    for (int v107 = 0; v107 < 7; v107 += 1) {	// L174
      for (int v108 = 0; v108 < 7; v108 += 1) {	// L175
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v105
        #pragma HLS dependence false variable=v104
        float v109 = v105[v106];	// L176
        v104[0][v106][v107][v108] = v109;	// L177
      }
    }
  }
}

void kernel13(
  float v110[1][512][7][7],
  float v111[1][512][9][9]
) {	// L183
  for (int v112 = 0; v112 < 512; v112 += 1) {	// L184
    for (int v113 = 0; v113 < 7; v113 += 1) {	// L185
      for (int v114 = 0; v114 < 7; v114 += 1) {	// L186
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v110
        #pragma HLS dependence false variable=v111
        float v115 = v110[0][v112][v113][v114];	// L187
        v111[0][v112][(v113 + 1)][(v114 + 1)] = v115;	// L188
      }
    }
  }
}

void kernel14(
  float v116[1][512][9][9],
  float v117
) {	// L194
  for (int v118 = 0; v118 < 512; v118 += 1) {	// L195
    for (int v119 = 0; v119 < 9; v119 += 1) {	// L196
      for (int v120 = 0; v120 < 9; v120 += 1) {	// L197
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v116
        v116[0][v118][v119][v120] = v117;	// L198
      }
    }
  }
}

void kernel19(
  float v121[1][512][7][7],
  float v122[1][512][7][7]
) {	// L204
  float v123[1][512][7][7];	// L205
  #pragma HLS resource variable=v123 core=ram_t2p_bram

  memcpy(v123, v122, 25088 * sizeof(float));	// L206

  for (int v124 = 0; v124 < 512; v124 += 1) {	// L207
    for (int v125 = 0; v125 < 7; v125 += 1) {	// L208
      for (int v126 = 0; v126 < 7; v126 += 1) {	// L209
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v121
        #pragma HLS dependence false variable=v123
        float v127 = v121[0][v124][v125][v126];	// L210
        float v128 = v123[0][v124][v125][v126];	// L211
        float v129 = v127 + v128;	// L212
        v123[0][v124][v125][v126] = v129;	// L213
      }
    }
  }
  memcpy(v122, v123, 25088 * sizeof(float));	// L217

}

void kernel23(
  float v130[1][512][9][9],
  float v131
) {	// L220
  for (int v132 = 0; v132 < 512; v132 += 1) {	// L221
    for (int v133 = 0; v133 < 9; v133 += 1) {	// L222
      for (int v134 = 0; v134 < 9; v134 += 1) {	// L223
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v130
        v130[0][v132][v133][v134] = v131;	// L224
      }
    }
  }
}

void kernel29(
  float v135[1][256][14][14],
  float v136[512][256][1][1],
  float v137[1][512][7][7]
) {	// L230
  float v138[1][512][7][7];	// L231
  #pragma HLS resource variable=v138 core=ram_t2p_bram

  memcpy(v138, v137, 25088 * sizeof(float));	// L232

  auto v139 = reinterpret_cast<float(*)[256][1][1]>(v136);	// L234

  for (int v140 = 0; v140 < 256; v140 += 1) {	// L235
    for (int v141 = 0; v141 < 512; v141 += 1) {	// L236
      float v142 = v139[v141][v140][0][0];	// L237
      for (int v143 = 0; v143 < 7; v143 += 1) {	// L238
        for (int v144 = 0; v144 < 7; v144 += 1) {	// L239
          #pragma HLS pipeline II=1
          #pragma HLS dependence false variable=v135
          #pragma HLS dependence false variable=v138
          float v145 = v135[0][v140][(v143 * 2)][(v144 * 2)];	// L240
          float v146 = v138[0][v141][v143][v144];	// L241
          float v147 = v145 * v142;	// L242
          float v148 = v146 + v147;	// L243
          v138[0][v141][v143][v144] = v148;	// L244
        }
      }
    }
  }
  memcpy(v137, v138, 25088 * sizeof(float));	// L249

}

void kernel34(
  float v149[1][512][9][9],
  float v150
) {	// L252
  for (int v151 = 0; v151 < 512; v151 += 1) {	// L253
    for (int v152 = 0; v152 < 9; v152 += 1) {	// L254
      for (int v153 = 0; v153 < 9; v153 += 1) {	// L255
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v149
        v149[0][v151][v152][v153] = v150;	// L256
      }
    }
  }
}

void kernel40(
  float v154[1][256][16][16],
  float v155[512][256][3][3],
  float v156[1][512][7][7]
) {	// L262
  float v157[1][512][7][7];	// L263
  #pragma HLS resource variable=v157 core=ram_t2p_bram

  memcpy(v157, v156, 25088 * sizeof(float));	// L264

  auto v158 = reinterpret_cast<float(*)[256][3][3]>(v155);	// L266

  for (int v159 = 0; v159 < 256; v159 += 1) {	// L267
    for (int v160 = 0; v160 < 3; v160 += 1) {	// L268
      for (int v161 = 0; v161 < 3; v161 += 1) {	// L269
        for (int v162 = 0; v162 < 512; v162 += 1) {	// L270
          float v163 = v158[v162][v159][v160][v161];	// L271
          for (int v164 = 0; v164 < 7; v164 += 1) {	// L272
            for (int v165 = 0; v165 < 7; v165 += 1) {	// L273
              #pragma HLS pipeline II=1
              #pragma HLS dependence false variable=v154
              #pragma HLS dependence false variable=v157
              float v166 = v154[0][v159][((v164 * 2) + v160)][((v165 * 2) + v161)];	// L274
              float v167 = v157[0][v162][v164][v165];	// L275
              float v168 = v166 * v163;	// L276
              float v169 = v167 + v168;	// L277
              v157[0][v162][v164][v165] = v169;	// L278
            }
          }
        }
      }
    }
  }
  memcpy(v156, v157, 25088 * sizeof(float));	// L285

}

void kernel42(
  float v170[1][256][14][14],
  float v171[1][256][16][16]
) {	// L288
  for (int v172 = 0; v172 < 256; v172 += 1) {	// L289
    for (int v173 = 0; v173 < 14; v173 += 1) {	// L290
      for (int v174 = 0; v174 < 14; v174 += 1) {	// L291
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v170
        #pragma HLS dependence false variable=v171
        float v175 = v170[0][v172][v173][v174];	// L292
        v171[0][v172][(v173 + 1)][(v174 + 1)] = v175;	// L293
      }
    }
  }
}

void kernel43(
  float v176[1][256][16][16],
  float v177
) {	// L299
  for (int v178 = 0; v178 < 256; v178 += 1) {	// L300
    for (int v179 = 0; v179 < 16; v179 += 1) {	// L301
      for (int v180 = 0; v180 < 16; v180 += 1) {	// L302
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v176
        v176[0][v178][v179][v180] = v177;	// L303
      }
    }
  }
}

void kernel44(
  float v181[1][256][14][14],
  float v182[1][256][14][14]
) {	// L309
  for (int v183 = 0; v183 < 256; v183 += 1) {	// L310
    for (int v184 = 0; v184 < 14; v184 += 1) {	// L311
      for (int v185 = 0; v185 < 14; v185 += 1) {	// L312
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v181
        #pragma HLS dependence false variable=v182
        float v186 = v181[0][v183][v184][v185];	// L313
        v182[0][v183][v184][v185] = v186;	// L314
      }
    }
  }
}

void kernel45(
  float v187[1][256][14][14],
  float v188[1][256][14][14],
  float v189
) {	// L320
  for (int v190 = 0; v190 < 256; v190 += 1) {	// L321
    for (int v191 = 0; v191 < 14; v191 += 1) {	// L322
      for (int v192 = 0; v192 < 14; v192 += 1) {	// L323
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v188
        #pragma HLS dependence false variable=v187
        float v193 = v188[0][v190][v191][v192];	// L324
        float v194 = v187[0][v190][v191][v192];	// L325
        float v195 = v194 * v189;	// L326
        float v196 = v194 * v193;	// L327
        float v197 = v193 - v196;	// L328
        float v198 = v197 + v195;	// L329
        v188[0][v190][v191][v192] = v198;	// L330
      }
    }
  }
}

void kernel46(
  float v199[1][256][14][14],
  float v200,
  float v201
) {	// L336
  for (int v202 = 0; v202 < 256; v202 += 1) {	// L337
    for (int v203 = 0; v203 < 14; v203 += 1) {	// L338
      for (int v204 = 0; v204 < 14; v204 += 1) {	// L339
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v199
        float v205 = v199[0][v202][v203][v204];	// L340
        float v206 = v205 - v201;	// L341
        bool v207 = v206 >= v200;	// L342
        float v208 = v207 ? v201 : v200;	// L343
        v199[0][v202][v203][v204] = v208;	// L344
      }
    }
  }
}

void kernel48(
  float v209[1][256][14][14],
  float v210[1][256][14][14],
  float v211[1][256][14][14]
) {	// L350
  for (int v212 = 0; v212 < 256; v212 += 1) {	// L351
    for (int v213 = 0; v213 < 14; v213 += 1) {	// L352
      for (int v214 = 0; v214 < 14; v214 += 1) {	// L353
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v210
        #pragma HLS dependence false variable=v211
        #pragma HLS dependence false variable=v209
        float v215 = v210[0][v212][v213][v214];	// L354
        float v216 = v209[0][v212][v213][v214];	// L355
        float v217 = v215 + v216;	// L356
        float v218 = v211[0][v212][v213][v214];	// L357
        float v219 = v218 + v217;	// L358
        v211[0][v212][v213][v214] = v219;	// L359
      }
    }
  }
}

void kernel49(
  float v220[1][256][16][16],
  float v221[256][256][3][3],
  float v222[1][256][14][14]
) {	// L365
  float v223[1][256][16][16];	// L366
  #pragma HLS resource variable=v223 core=ram_t2p_uram

  memcpy(v223, v220, 65536 * sizeof(float));	// L367

  float v224[1][256][14][14];	// L368
  #pragma HLS resource variable=v224 core=ram_t2p_uram

  memcpy(v224, v222, 50176 * sizeof(float));	// L369

  auto v225 = reinterpret_cast<float(*)[256][3][3]>(v221);	// L371

  for (int v226 = 0; v226 < 256; v226 += 1) {	// L372
    for (int v227 = 0; v227 < 3; v227 += 1) {	// L373
      for (int v228 = 0; v228 < 3; v228 += 1) {	// L374
        for (int v229 = 0; v229 < 256; v229 += 1) {	// L375
          float v230 = v225[v229][v226][v227][v228];	// L376
          for (int v231 = 0; v231 < 14; v231 += 1) {	// L377
            for (int v232 = 0; v232 < 14; v232 += 1) {	// L378
              #pragma HLS pipeline II=1
              #pragma HLS dependence false variable=v223
              #pragma HLS dependence false variable=v224
              float v233 = v223[0][v226][(v231 + v227)][(v232 + v228)];	// L379
              float v234 = v224[0][v229][v231][v232];	// L380
              float v235 = v233 * v230;	// L381
              float v236 = v234 + v235;	// L382
              v224[0][v229][v231][v232] = v236;	// L383
            }
          }
        }
      }
    }
  }
  memcpy(v222, v224, 50176 * sizeof(float));	// L390

}

void kernel50(
  float v237[256],
  float v238[1][256][14][14]
) {	// L393
  float v239[256];	// L394
  #pragma HLS resource variable=v239 core=ram_t2p_bram

  memcpy(v239, v237, 256 * sizeof(float));	// L395

  for (int v240 = 0; v240 < 256; v240 += 1) {	// L396
    for (int v241 = 0; v241 < 14; v241 += 1) {	// L397
      for (int v242 = 0; v242 < 14; v242 += 1) {	// L398
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v239
        #pragma HLS dependence false variable=v238
        float v243 = v239[v240];	// L399
        v238[0][v240][v241][v242] = v243;	// L400
      }
    }
  }
}

void kernel52(
  float v244[1][256][16][16],
  float v245
) {	// L406
  for (int v246 = 0; v246 < 256; v246 += 1) {	// L407
    for (int v247 = 0; v247 < 16; v247 += 1) {	// L408
      for (int v248 = 0; v248 < 16; v248 += 1) {	// L409
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v244
        v244[0][v246][v247][v248] = v245;	// L410
      }
    }
  }
}

void kernel57(
  float v249[1][256][14][14],
  float v250[1][256][14][14]
) {	// L416
  for (int v251 = 0; v251 < 256; v251 += 1) {	// L417
    for (int v252 = 0; v252 < 14; v252 += 1) {	// L418
      for (int v253 = 0; v253 < 14; v253 += 1) {	// L419
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v249
        #pragma HLS dependence false variable=v250
        float v254 = v249[0][v251][v252][v253];	// L420
        float v255 = v250[0][v251][v252][v253];	// L421
        float v256 = v254 + v255;	// L422
        v250[0][v251][v252][v253] = v256;	// L423
      }
    }
  }
}

void kernel61(
  float v257[1][256][16][16],
  float v258
) {	// L429
  for (int v259 = 0; v259 < 256; v259 += 1) {	// L430
    for (int v260 = 0; v260 < 16; v260 += 1) {	// L431
      for (int v261 = 0; v261 < 16; v261 += 1) {	// L432
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v257
        v257[0][v259][v260][v261] = v258;	// L433
      }
    }
  }
}

void kernel67(
  float v262[1][128][28][28],
  float v263[256][128][1][1],
  float v264[1][256][14][14]
) {	// L439
  auto v265 = reinterpret_cast<float(*)[128][1][1]>(v263);	// L441

  for (int v266 = 0; v266 < 128; v266 += 1) {	// L442
    for (int v267 = 0; v267 < 256; v267 += 1) {	// L443
      float v268 = v265[v267][v266][0][0];	// L444
      for (int v269 = 0; v269 < 14; v269 += 1) {	// L445
        for (int v270 = 0; v270 < 14; v270 += 1) {	// L446
          #pragma HLS pipeline II=1
          #pragma HLS dependence false variable=v262
          #pragma HLS dependence false variable=v264
          float v271 = v262[0][v266][(v269 * 2)][(v270 * 2)];	// L447
          float v272 = v264[0][v267][v269][v270];	// L448
          float v273 = v271 * v268;	// L449
          float v274 = v272 + v273;	// L450
          v264[0][v267][v269][v270] = v274;	// L451
        }
      }
    }
  }
}

void kernel72(
  float v275[1][256][16][16],
  float v276
) {	// L458
  for (int v277 = 0; v277 < 256; v277 += 1) {	// L459
    for (int v278 = 0; v278 < 16; v278 += 1) {	// L460
      for (int v279 = 0; v279 < 16; v279 += 1) {	// L461
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v275
        v275[0][v277][v278][v279] = v276;	// L462
      }
    }
  }
}

void kernel78(
  float v280[1][128][30][30],
  float v281[256][128][3][3],
  float v282[1][256][14][14]
) {	// L468
  float v283[1][256][14][14];	// L469
  #pragma HLS resource variable=v283 core=ram_t2p_uram

  memcpy(v283, v282, 50176 * sizeof(float));	// L470

  auto v284 = reinterpret_cast<float(*)[128][3][3]>(v281);	// L472

  for (int v285 = 0; v285 < 128; v285 += 1) {	// L473
    for (int v286 = 0; v286 < 3; v286 += 1) {	// L474
      for (int v287 = 0; v287 < 3; v287 += 1) {	// L475
        for (int v288 = 0; v288 < 256; v288 += 1) {	// L476
          float v289 = v284[v288][v285][v286][v287];	// L477
          for (int v290 = 0; v290 < 14; v290 += 1) {	// L478
            for (int v291 = 0; v291 < 14; v291 += 1) {	// L479
              #pragma HLS pipeline II=1
              #pragma HLS dependence false variable=v280
              #pragma HLS dependence false variable=v283
              float v292 = v280[0][v285][((v290 * 2) + v286)][((v291 * 2) + v287)];	// L480
              float v293 = v283[0][v288][v290][v291];	// L481
              float v294 = v292 * v289;	// L482
              float v295 = v293 + v294;	// L483
              v283[0][v288][v290][v291] = v295;	// L484
            }
          }
        }
      }
    }
  }
  memcpy(v282, v283, 50176 * sizeof(float));	// L491

}

void kernel80(
  float v296[1][128][28][28],
  float v297[1][128][30][30]
) {	// L494
  for (int v298 = 0; v298 < 128; v298 += 1) {	// L495
    for (int v299 = 0; v299 < 28; v299 += 1) {	// L496
      for (int v300 = 0; v300 < 28; v300 += 1) {	// L497
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v296
        #pragma HLS dependence false variable=v297
        float v301 = v296[0][v298][v299][v300];	// L498
        v297[0][v298][(v299 + 1)][(v300 + 1)] = v301;	// L499
      }
    }
  }
}

void kernel81(
  float v302[1][128][30][30],
  float v303
) {	// L505
  for (int v304 = 0; v304 < 128; v304 += 1) {	// L506
    for (int v305 = 0; v305 < 30; v305 += 1) {	// L507
      for (int v306 = 0; v306 < 30; v306 += 1) {	// L508
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v302
        v302[0][v304][v305][v306] = v303;	// L509
      }
    }
  }
}

void kernel82(
  float v307[1][128][28][28],
  float v308[1][128][28][28]
) {	// L515
  for (int v309 = 0; v309 < 128; v309 += 1) {	// L516
    for (int v310 = 0; v310 < 28; v310 += 1) {	// L517
      for (int v311 = 0; v311 < 28; v311 += 1) {	// L518
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v307
        #pragma HLS dependence false variable=v308
        float v312 = v307[0][v309][v310][v311];	// L519
        v308[0][v309][v310][v311] = v312;	// L520
      }
    }
  }
}

void kernel83(
  float v313[1][128][28][28],
  float v314[1][128][28][28],
  float v315
) {	// L526
  for (int v316 = 0; v316 < 128; v316 += 1) {	// L527
    for (int v317 = 0; v317 < 28; v317 += 1) {	// L528
      for (int v318 = 0; v318 < 28; v318 += 1) {	// L529
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v314
        #pragma HLS dependence false variable=v313
        float v319 = v314[0][v316][v317][v318];	// L530
        float v320 = v313[0][v316][v317][v318];	// L531
        float v321 = v320 * v315;	// L532
        float v322 = v320 * v319;	// L533
        float v323 = v319 - v322;	// L534
        float v324 = v323 + v321;	// L535
        v314[0][v316][v317][v318] = v324;	// L536
      }
    }
  }
}

void kernel84(
  float v325[1][128][28][28],
  float v326,
  float v327
) {	// L542
  for (int v328 = 0; v328 < 128; v328 += 1) {	// L543
    for (int v329 = 0; v329 < 28; v329 += 1) {	// L544
      for (int v330 = 0; v330 < 28; v330 += 1) {	// L545
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v325
        float v331 = v325[0][v328][v329][v330];	// L546
        float v332 = v331 - v327;	// L547
        bool v333 = v332 >= v326;	// L548
        float v334 = v333 ? v327 : v326;	// L549
        v325[0][v328][v329][v330] = v334;	// L550
      }
    }
  }
}

void kernel86(
  float v335[1][128][28][28],
  float v336[1][128][28][28],
  float v337[1][128][28][28]
) {	// L556
  for (int v338 = 0; v338 < 128; v338 += 1) {	// L557
    for (int v339 = 0; v339 < 28; v339 += 1) {	// L558
      for (int v340 = 0; v340 < 28; v340 += 1) {	// L559
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v336
        #pragma HLS dependence false variable=v337
        #pragma HLS dependence false variable=v335
        float v341 = v336[0][v338][v339][v340];	// L560
        float v342 = v335[0][v338][v339][v340];	// L561
        float v343 = v341 + v342;	// L562
        float v344 = v337[0][v338][v339][v340];	// L563
        float v345 = v344 + v343;	// L564
        v337[0][v338][v339][v340] = v345;	// L565
      }
    }
  }
}

void kernel87(
  float v346[1][128][30][30],
  float v347[128][128][3][3],
  float v348[1][128][28][28]
) {	// L571
  float v349[1][128][28][28];	// L572
  #pragma HLS resource variable=v349 core=ram_t2p_uram

  memcpy(v349, v348, 100352 * sizeof(float));	// L573

  auto v350 = reinterpret_cast<float(*)[128][3][3]>(v347);	// L575

  for (int v351 = 0; v351 < 128; v351 += 1) {	// L576
    for (int v352 = 0; v352 < 3; v352 += 1) {	// L577
      for (int v353 = 0; v353 < 3; v353 += 1) {	// L578
        for (int v354 = 0; v354 < 128; v354 += 1) {	// L579
          float v355 = v350[v354][v351][v352][v353];	// L580
          for (int v356 = 0; v356 < 28; v356 += 1) {	// L581
            for (int v357 = 0; v357 < 28; v357 += 1) {	// L582
              #pragma HLS pipeline II=1
              #pragma HLS dependence false variable=v346
              #pragma HLS dependence false variable=v349
              float v358 = v346[0][v351][(v356 + v352)][(v357 + v353)];	// L583
              float v359 = v349[0][v354][v356][v357];	// L584
              float v360 = v358 * v355;	// L585
              float v361 = v359 + v360;	// L586
              v349[0][v354][v356][v357] = v361;	// L587
            }
          }
        }
      }
    }
  }
  memcpy(v348, v349, 100352 * sizeof(float));	// L594

}

void kernel88(
  float v362[128],
  float v363[1][128][28][28]
) {	// L597
  float v364[128];	// L598
  #pragma HLS resource variable=v364 core=ram_t2p_bram

  memcpy(v364, v362, 128 * sizeof(float));	// L599

  for (int v365 = 0; v365 < 128; v365 += 1) {	// L600
    for (int v366 = 0; v366 < 28; v366 += 1) {	// L601
      for (int v367 = 0; v367 < 28; v367 += 1) {	// L602
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v364
        #pragma HLS dependence false variable=v363
        float v368 = v364[v365];	// L603
        v363[0][v365][v366][v367] = v368;	// L604
      }
    }
  }
}

void kernel90(
  float v369[1][128][30][30],
  float v370
) {	// L610
  for (int v371 = 0; v371 < 128; v371 += 1) {	// L611
    for (int v372 = 0; v372 < 30; v372 += 1) {	// L612
      for (int v373 = 0; v373 < 30; v373 += 1) {	// L613
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v369
        v369[0][v371][v372][v373] = v370;	// L614
      }
    }
  }
}

void kernel95(
  float v374[1][128][28][28],
  float v375[1][128][28][28]
) {	// L620
  for (int v376 = 0; v376 < 128; v376 += 1) {	// L621
    for (int v377 = 0; v377 < 28; v377 += 1) {	// L622
      for (int v378 = 0; v378 < 28; v378 += 1) {	// L623
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v374
        #pragma HLS dependence false variable=v375
        float v379 = v374[0][v376][v377][v378];	// L624
        float v380 = v375[0][v376][v377][v378];	// L625
        float v381 = v379 + v380;	// L626
        v375[0][v376][v377][v378] = v381;	// L627
      }
    }
  }
}

void kernel99(
  float v382[1][128][30][30],
  float v383
) {	// L633
  for (int v384 = 0; v384 < 128; v384 += 1) {	// L634
    for (int v385 = 0; v385 < 30; v385 += 1) {	// L635
      for (int v386 = 0; v386 < 30; v386 += 1) {	// L636
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v382
        v382[0][v384][v385][v386] = v383;	// L637
      }
    }
  }
}

void kernel105(
  float v387[1][64][56][56],
  float v388[128][64][1][1],
  float v389[1][128][28][28]
) {	// L643
  float v390[128][64][1][1];	// L644
  #pragma HLS resource variable=v390 core=ram_t2p_bram

  memcpy(v390, v388, 8192 * sizeof(float));	// L645

  for (int v391 = 0; v391 < 64; v391 += 1) {	// L646
    for (int v392 = 0; v392 < 128; v392 += 1) {	// L647
      for (int v393 = 0; v393 < 28; v393 += 1) {	// L648
        for (int v394 = 0; v394 < 28; v394 += 1) {	// L649
          #pragma HLS pipeline II=1
          #pragma HLS dependence false variable=v387
          #pragma HLS dependence false variable=v389
          #pragma HLS dependence false variable=v390
          float v395 = v387[0][v391][(v393 * 2)][(v394 * 2)];	// L650
          float v396 = v390[v392][v391][0][0];	// L651
          float v397 = v389[0][v392][v393][v394];	// L652
          float v398 = v395 * v396;	// L653
          float v399 = v397 + v398;	// L654
          v389[0][v392][v393][v394] = v399;	// L655
        }
      }
    }
  }
}

void kernel110(
  float v400[1][128][30][30],
  float v401
) {	// L662
  for (int v402 = 0; v402 < 128; v402 += 1) {	// L663
    for (int v403 = 0; v403 < 30; v403 += 1) {	// L664
      for (int v404 = 0; v404 < 30; v404 += 1) {	// L665
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v400
        v400[0][v402][v403][v404] = v401;	// L666
      }
    }
  }
}

void kernel116(
  float v405[1][64][58][58],
  float v406[128][64][3][3],
  float v407[1][128][28][28]
) {	// L672
  auto v408 = reinterpret_cast<float(*)[64][3][3]>(v406);	// L674

  for (int v409 = 0; v409 < 64; v409 += 1) {	// L675
    for (int v410 = 0; v410 < 3; v410 += 1) {	// L676
      for (int v411 = 0; v411 < 3; v411 += 1) {	// L677
        for (int v412 = 0; v412 < 128; v412 += 1) {	// L678
          float v413 = v408[v412][v409][v410][v411];	// L679
          for (int v414 = 0; v414 < 28; v414 += 1) {	// L680
            for (int v415 = 0; v415 < 28; v415 += 1) {	// L681
              #pragma HLS pipeline II=1
              #pragma HLS dependence false variable=v405
              #pragma HLS dependence false variable=v407
              float v416 = v405[0][v409][((v414 * 2) + v410)][((v415 * 2) + v411)];	// L682
              float v417 = v407[0][v412][v414][v415];	// L683
              float v418 = v416 * v413;	// L684
              float v419 = v417 + v418;	// L685
              v407[0][v412][v414][v415] = v419;	// L686
            }
          }
        }
      }
    }
  }
}

void kernel118(
  float v420[1][64][56][56],
  float v421[1][64][58][58]
) {	// L695
  for (int v422 = 0; v422 < 64; v422 += 1) {	// L696
    for (int v423 = 0; v423 < 56; v423 += 1) {	// L697
      for (int v424 = 0; v424 < 56; v424 += 1) {	// L698
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v420
        #pragma HLS dependence false variable=v421
        float v425 = v420[0][v422][v423][v424];	// L699
        v421[0][v422][(v423 + 1)][(v424 + 1)] = v425;	// L700
      }
    }
  }
}

void kernel119(
  float v426[1][64][58][58],
  float v427
) {	// L706
  for (int v428 = 0; v428 < 64; v428 += 1) {	// L707
    for (int v429 = 0; v429 < 58; v429 += 1) {	// L708
      for (int v430 = 0; v430 < 58; v430 += 1) {	// L709
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v426
        v426[0][v428][v429][v430] = v427;	// L710
      }
    }
  }
}

void kernel120(
  float v431[1][64][56][56],
  float v432[1][64][56][56]
) {	// L716
  for (int v433 = 0; v433 < 64; v433 += 1) {	// L717
    for (int v434 = 0; v434 < 56; v434 += 1) {	// L718
      for (int v435 = 0; v435 < 56; v435 += 1) {	// L719
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v431
        #pragma HLS dependence false variable=v432
        float v436 = v431[0][v433][v434][v435];	// L720
        v432[0][v433][v434][v435] = v436;	// L721
      }
    }
  }
}

void kernel121(
  float v437[1][64][56][56],
  float v438[1][64][56][56],
  float v439
) {	// L727
  for (int v440 = 0; v440 < 64; v440 += 1) {	// L728
    for (int v441 = 0; v441 < 56; v441 += 1) {	// L729
      for (int v442 = 0; v442 < 56; v442 += 1) {	// L730
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v438
        #pragma HLS dependence false variable=v437
        float v443 = v438[0][v440][v441][v442];	// L731
        float v444 = v437[0][v440][v441][v442];	// L732
        float v445 = v444 * v439;	// L733
        float v446 = v444 * v443;	// L734
        float v447 = v443 - v446;	// L735
        float v448 = v447 + v445;	// L736
        v438[0][v440][v441][v442] = v448;	// L737
      }
    }
  }
}

void kernel122(
  float v449[1][64][56][56],
  float v450,
  float v451
) {	// L743
  for (int v452 = 0; v452 < 64; v452 += 1) {	// L744
    for (int v453 = 0; v453 < 56; v453 += 1) {	// L745
      for (int v454 = 0; v454 < 56; v454 += 1) {	// L746
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v449
        float v455 = v449[0][v452][v453][v454];	// L747
        float v456 = v455 - v451;	// L748
        bool v457 = v456 >= v450;	// L749
        float v458 = v457 ? v451 : v450;	// L750
        v449[0][v452][v453][v454] = v458;	// L751
      }
    }
  }
}

void kernel124(
  float v459[1][64][56][56],
  float v460[1][64][56][56],
  float v461[1][64][56][56]
) {	// L757
  for (int v462 = 0; v462 < 64; v462 += 1) {	// L758
    for (int v463 = 0; v463 < 56; v463 += 1) {	// L759
      for (int v464 = 0; v464 < 56; v464 += 1) {	// L760
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v460
        #pragma HLS dependence false variable=v461
        #pragma HLS dependence false variable=v459
        float v465 = v460[0][v462][v463][v464];	// L761
        float v466 = v459[0][v462][v463][v464];	// L762
        float v467 = v465 + v466;	// L763
        float v468 = v461[0][v462][v463][v464];	// L764
        float v469 = v468 + v467;	// L765
        v461[0][v462][v463][v464] = v469;	// L766
      }
    }
  }
}

void kernel125(
  float v470[1][64][58][58],
  float v471[64][64][3][3],
  float v472[1][64][56][56]
) {	// L772
  float v473[1][64][56][56];	// L773
  #pragma HLS resource variable=v473 core=ram_t2p_uram

  memcpy(v473, v472, 200704 * sizeof(float));	// L774

  auto v474 = reinterpret_cast<float(*)[64][3][3]>(v471);	// L776

  for (int v475 = 0; v475 < 64; v475 += 1) {	// L777
    for (int v476 = 0; v476 < 3; v476 += 1) {	// L778
      for (int v477 = 0; v477 < 3; v477 += 1) {	// L779
        for (int v478 = 0; v478 < 64; v478 += 1) {	// L780
          float v479 = v474[v478][v475][v476][v477];	// L781
          for (int v480 = 0; v480 < 56; v480 += 1) {	// L782
            for (int v481 = 0; v481 < 56; v481 += 1) {	// L783
              #pragma HLS pipeline II=1
              #pragma HLS dependence false variable=v470
              #pragma HLS dependence false variable=v473
              float v482 = v470[0][v475][(v480 + v476)][(v481 + v477)];	// L784
              float v483 = v473[0][v478][v480][v481];	// L785
              float v484 = v482 * v479;	// L786
              float v485 = v483 + v484;	// L787
              v473[0][v478][v480][v481] = v485;	// L788
            }
          }
        }
      }
    }
  }
  memcpy(v472, v473, 200704 * sizeof(float));	// L795

}

void kernel126(
  float v486[64],
  float v487[1][64][56][56]
) {	// L798
  float v488[64];	// L799
  #pragma HLS resource variable=v488 core=ram_t2p_bram

  memcpy(v488, v486, 64 * sizeof(float));	// L800

  for (int v489 = 0; v489 < 64; v489 += 1) {	// L801
    for (int v490 = 0; v490 < 56; v490 += 1) {	// L802
      for (int v491 = 0; v491 < 56; v491 += 1) {	// L803
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v488
        #pragma HLS dependence false variable=v487
        float v492 = v488[v489];	// L804
        v487[0][v489][v490][v491] = v492;	// L805
      }
    }
  }
}

void kernel128(
  float v493[1][64][58][58],
  float v494
) {	// L811
  for (int v495 = 0; v495 < 64; v495 += 1) {	// L812
    for (int v496 = 0; v496 < 58; v496 += 1) {	// L813
      for (int v497 = 0; v497 < 58; v497 += 1) {	// L814
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v493
        v493[0][v495][v496][v497] = v494;	// L815
      }
    }
  }
}

void kernel133(
  float v498[1][64][56][56],
  float v499[1][64][56][56]
) {	// L821
  for (int v500 = 0; v500 < 64; v500 += 1) {	// L822
    for (int v501 = 0; v501 < 56; v501 += 1) {	// L823
      for (int v502 = 0; v502 < 56; v502 += 1) {	// L824
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v498
        #pragma HLS dependence false variable=v499
        float v503 = v498[0][v500][v501][v502];	// L825
        float v504 = v499[0][v500][v501][v502];	// L826
        float v505 = v503 + v504;	// L827
        v499[0][v500][v501][v502] = v505;	// L828
      }
    }
  }
}

void kernel137(
  float v506[1][64][58][58],
  float v507
) {	// L834
  for (int v508 = 0; v508 < 64; v508 += 1) {	// L835
    for (int v509 = 0; v509 < 58; v509 += 1) {	// L836
      for (int v510 = 0; v510 < 58; v510 += 1) {	// L837
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v506
        v506[0][v508][v509][v510] = v507;	// L838
      }
    }
  }
}

void kernel146(
  float v511[1][64][58][58],
  float v512
) {	// L844
  for (int v513 = 0; v513 < 64; v513 += 1) {	// L845
    for (int v514 = 0; v514 < 58; v514 += 1) {	// L846
      for (int v515 = 0; v515 < 58; v515 += 1) {	// L847
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v511
        v511[0][v513][v514][v515] = v512;	// L848
      }
    }
  }
}

void kernel155(
  float v516[1][64][58][58],
  float v517
) {	// L854
  for (int v518 = 0; v518 < 64; v518 += 1) {	// L855
    for (int v519 = 0; v519 < 58; v519 += 1) {	// L856
      for (int v520 = 0; v520 < 58; v520 += 1) {	// L857
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v516
        v516[0][v518][v519][v520] = v517;	// L858
      }
    }
  }
}

void kernel156(
  float v521[1][64][114][114],
  float v522[3][3],
  float v523[1][64][56][56]
) {	// L864
  for (int v524 = 0; v524 < 3; v524 += 1) {	// L865
    for (int v525 = 0; v525 < 3; v525 += 1) {	// L866
      for (int v526 = 0; v526 < 64; v526 += 1) {	// L867
        for (int v527 = 0; v527 < 56; v527 += 1) {	// L868
          for (int v528 = 0; v528 < 56; v528 += 1) {	// L869
            #pragma HLS pipeline II=1
            #pragma HLS dependence false variable=v521
            #pragma HLS dependence false variable=v523
            float v529 = v521[0][v526][((v527 * 2) + v524)][((v528 * 2) + v525)];	// L870
            float v530 = v523[0][v526][v527][v528];	// L871
            float v531 = max(v530, v529);	// L872
            v523[0][v526][v527][v528] = v531;	// L873
          }
        }
      }
    }
  }
}

void kernel157(
  float v532[1][64][56][56],
  float v533
) {	// L881
  for (int v534 = 0; v534 < 64; v534 += 1) {	// L882
    for (int v535 = 0; v535 < 56; v535 += 1) {	// L883
      for (int v536 = 0; v536 < 56; v536 += 1) {	// L884
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v532
        v532[0][v534][v535][v536] = v533;	// L885
      }
    }
  }
}

void kernel158(
  float v537[1][64][112][112],
  float v538[1][64][114][114]
) {	// L891
  for (int v539 = 0; v539 < 64; v539 += 1) {	// L892
    for (int v540 = 0; v540 < 112; v540 += 1) {	// L893
      for (int v541 = 0; v541 < 112; v541 += 1) {	// L894
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v537
        #pragma HLS dependence false variable=v538
        float v542 = v537[0][v539][v540][v541];	// L895
        v538[0][v539][(v540 + 1)][(v541 + 1)] = v542;	// L896
      }
    }
  }
}

void kernel159(
  float v543[1][64][114][114],
  float v544
) {	// L902
  for (int v545 = 0; v545 < 64; v545 += 1) {	// L903
    for (int v546 = 0; v546 < 114; v546 += 1) {	// L904
      for (int v547 = 0; v547 < 114; v547 += 1) {	// L905
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v543
        v543[0][v545][v546][v547] = v544;	// L906
      }
    }
  }
}

void kernel160(
  float v548[1][64][112][112],
  float v549[1][64][112][112]
) {	// L912
  for (int v550 = 0; v550 < 64; v550 += 1) {	// L913
    for (int v551 = 0; v551 < 112; v551 += 1) {	// L914
      for (int v552 = 0; v552 < 112; v552 += 1) {	// L915
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v548
        #pragma HLS dependence false variable=v549
        float v553 = v548[0][v550][v551][v552];	// L916
        v549[0][v550][v551][v552] = v553;	// L917
      }
    }
  }
}

void kernel161(
  float v554[1][64][112][112],
  float v555[1][64][112][112],
  float v556
) {	// L923
  for (int v557 = 0; v557 < 64; v557 += 1) {	// L924
    for (int v558 = 0; v558 < 112; v558 += 1) {	// L925
      for (int v559 = 0; v559 < 112; v559 += 1) {	// L926
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v555
        #pragma HLS dependence false variable=v554
        float v560 = v555[0][v557][v558][v559];	// L927
        float v561 = v554[0][v557][v558][v559];	// L928
        float v562 = v561 * v556;	// L929
        float v563 = v561 * v560;	// L930
        float v564 = v560 - v563;	// L931
        float v565 = v564 + v562;	// L932
        v555[0][v557][v558][v559] = v565;	// L933
      }
    }
  }
}

void kernel162(
  float v566[1][64][112][112],
  float v567,
  float v568
) {	// L939
  for (int v569 = 0; v569 < 64; v569 += 1) {	// L940
    for (int v570 = 0; v570 < 112; v570 += 1) {	// L941
      for (int v571 = 0; v571 < 112; v571 += 1) {	// L942
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v566
        float v572 = v566[0][v569][v570][v571];	// L943
        float v573 = v572 - v568;	// L944
        bool v574 = v573 >= v567;	// L945
        float v575 = v574 ? v568 : v567;	// L946
        v566[0][v569][v570][v571] = v575;	// L947
      }
    }
  }
}

void kernel164(
  float v576[1][64][112][112],
  float v577[1][64][112][112]
) {	// L953
  for (int v578 = 0; v578 < 64; v578 += 1) {	// L954
    for (int v579 = 0; v579 < 112; v579 += 1) {	// L955
      for (int v580 = 0; v580 < 112; v580 += 1) {	// L956
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v576
        #pragma HLS dependence false variable=v577
        float v581 = v576[0][v578][v579][v580];	// L957
        float v582 = v577[0][v578][v579][v580];	// L958
        float v583 = v581 + v582;	// L959
        v577[0][v578][v579][v580] = v583;	// L960
      }
    }
  }
}

void kernel165(
  float v584[1][3][230][230],
  float v585[64][3][7][7],
  float v586[1][64][112][112]
) {	// L966
  float v587[1][3][230][230];	// L967
  #pragma HLS resource variable=v587 core=ram_t2p_uram

  memcpy(v587, v584, 158700 * sizeof(float));	// L968

  float v588[64][3][7][7];	// L969
  #pragma HLS resource variable=v588 core=ram_t2p_bram

  memcpy(v588, v585, 9408 * sizeof(float));	// L970

  for (int v589 = 0; v589 < 3; v589 += 1) {	// L971
    for (int v590 = 0; v590 < 7; v590 += 1) {	// L972
      for (int v591 = 0; v591 < 7; v591 += 1) {	// L973
        for (int v592 = 0; v592 < 64; v592 += 1) {	// L974
          for (int v593 = 0; v593 < 112; v593 += 1) {	// L975
            for (int v594 = 0; v594 < 112; v594 += 1) {	// L976
              #pragma HLS pipeline II=1
              #pragma HLS dependence false variable=v587
              #pragma HLS dependence false variable=v586
              #pragma HLS dependence false variable=v588
              float v595 = v587[0][v589][((v593 * 2) + v590)][((v594 * 2) + v591)];	// L977
              float v596 = v588[v592][v589][v590][v591];	// L978
              float v597 = v586[0][v592][v593][v594];	// L979
              float v598 = v595 * v596;	// L980
              float v599 = v597 + v598;	// L981
              v586[0][v592][v593][v594] = v599;	// L982
            }
          }
        }
      }
    }
  }
}

void kernel166(
  float v600[64],
  float v601[1][64][112][112]
) {	// L991
  float v602[64];	// L992
  #pragma HLS resource variable=v602 core=ram_t2p_bram

  memcpy(v602, v600, 64 * sizeof(float));	// L993

  for (int v603 = 0; v603 < 64; v603 += 1) {	// L994
    for (int v604 = 0; v604 < 112; v604 += 1) {	// L995
      for (int v605 = 0; v605 < 112; v605 += 1) {	// L996
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v602
        #pragma HLS dependence false variable=v601
        float v606 = v602[v603];	// L997
        v601[0][v603][v604][v605] = v606;	// L998
      }
    }
  }
}

void kernel167(
  float v607[1][3][224][224],
  float v608[1][3][230][230]
) {	// L1004
  for (int v609 = 0; v609 < 3; v609 += 1) {	// L1005
    for (int v610 = 0; v610 < 224; v610 += 1) {	// L1006
      for (int v611 = 0; v611 < 224; v611 += 1) {	// L1007
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v607
        #pragma HLS dependence false variable=v608
        float v612 = v607[0][v609][v610][v611];	// L1008
        v608[0][v609][(v610 + 3)][(v611 + 3)] = v612;	// L1009
      }
    }
  }
}

void kernel168(
  float v613[1][3][230][230],
  float v614
) {	// L1015
  for (int v615 = 0; v615 < 3; v615 += 1) {	// L1016
    for (int v616 = 0; v616 < 230; v616 += 1) {	// L1017
      for (int v617 = 0; v617 < 230; v617 += 1) {	// L1018
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v613
        v613[0][v615][v616][v617] = v614;	// L1019
      }
    }
  }
}

/// The top function
void control(
  ap_int<32> v618[117670912],
  ap_int<32> v619[117670912],
  ap_int<32> v620[117670912]
) {	// L1025
  #pragma HLS interface s_axilite port=return bundle=ctrl
  #pragma hls interface m_axi offset=direct bundle=g0 port=v618
  #pragma hls stable variable=v618
  #pragma hls interface m_axi offset=direct bundle=g0 port=v619
  #pragma hls stable variable=v619
  #pragma hls interface m_axi offset=direct bundle=g0 port=v620
  #pragma hls stable variable=v620

  auto v621 = reinterpret_cast<float(*)[3][230][230]>(v619 + 15253504);
  kernel168(v621, (float)0.000000);	// L1031
  auto v622 = reinterpret_cast<float(*)[3][224][224]>(v618);
  kernel167(v622, v621);	// L1033
  auto v623 = reinterpret_cast<float(*)[64][112][112]>(v618 + 16085248);
  auto v624 = reinterpret_cast<float(*)>(v620 + 112952320);
  kernel166(v624, v623);	// L1036
  auto v625 = reinterpret_cast<float(*)[3][7][7]>(v620 + 115311616);
  kernel165(v621, v625, v623);	// L1038
  auto v626 = reinterpret_cast<float(*)[64][112][112]>(v618 + 802816);
  kernel164(v626, v623);	// L1040
  auto v627 = reinterpret_cast<float(*)[64][112][112]>(v618 + 15253504);
  kernel160(v623, v627);	// L1042
  kernel162(v627, (float)0.000000, (float)1.000000);	// L1043
  kernel161(v627, v623, (float)0.000000);	// L1044
  kernel160(v623, v626);	// L1045
  auto v628 = reinterpret_cast<float(*)[64][114][114]>(v618 + 16085248);
  kernel159(v628, (float)-INFINITY);	// L1047
  kernel158(v627, v628);	// L1048
  auto v629 = reinterpret_cast<float(*)[64][56][56]>(v618 + 15253504);
  kernel157(v629, (float)-INFINITY);	// L1050
  auto v630 = reinterpret_cast<float(*)[3]>(v619 + 16916992);
  kernel156(v628, v630, v629);	// L1052
  auto v631 = reinterpret_cast<float(*)[64][58][58]>(v618 + 16085248);
  kernel155(v631, (float)0.000000);	// L1054
  kernel118(v629, v631);	// L1055
  auto v632 = reinterpret_cast<float(*)[64][56][56]>(v619 + 16916992);
  auto v633 = reinterpret_cast<float(*)>(v620 + 108233728);
  kernel126(v633, v632);	// L1058
  auto v634 = reinterpret_cast<float(*)[64][3][3]>(v620 + 110593024);
  kernel125(v631, v634, v632);	// L1060
  auto v635 = reinterpret_cast<float(*)[64][56][56]>(v618 + 1605632);
  kernel133(v635, v632);	// L1062
  auto v636 = reinterpret_cast<float(*)[64][56][56]>(v618 + 16085248);
  kernel120(v632, v636);	// L1064
  kernel122(v636, (float)0.000000, (float)1.000000);	// L1065
  kernel121(v636, v632, (float)0.000000);	// L1066
  kernel120(v632, v635);	// L1067
  auto v637 = reinterpret_cast<float(*)[64][58][58]>(v618 + 17748736);
  kernel146(v637, (float)0.000000);	// L1069
  kernel118(v636, v637);	// L1070
  auto v638 = reinterpret_cast<float(*)>(v620 + 103515136);
  kernel126(v638, v632);	// L1072
  auto v639 = reinterpret_cast<float(*)[64][3][3]>(v620 + 105874432);
  kernel125(v637, v639, v632);	// L1074
  auto v640 = reinterpret_cast<float(*)[64][56][56]>(v618 + 2408448);
  kernel124(v629, v640, v632);	// L1076
  kernel120(v632, v629);	// L1077
  kernel122(v629, (float)0.000000, (float)1.000000);	// L1078
  kernel121(v629, v632, (float)0.000000);	// L1079
  kernel120(v632, v640);	// L1080
  kernel137(v631, (float)0.000000);	// L1081
  kernel118(v629, v631);	// L1082
  auto v641 = reinterpret_cast<float(*)>(v620 + 98796544);
  kernel126(v641, v632);	// L1084
  auto v642 = reinterpret_cast<float(*)[64][3][3]>(v620 + 101155840);
  kernel125(v631, v642, v632);	// L1086
  auto v643 = reinterpret_cast<float(*)[64][56][56]>(v618 + 3211264);
  kernel133(v643, v632);	// L1088
  kernel120(v632, v636);	// L1089
  kernel122(v636, (float)0.000000, (float)1.000000);	// L1090
  kernel121(v636, v632, (float)0.000000);	// L1091
  kernel120(v632, v643);	// L1092
  kernel128(v637, (float)0.000000);	// L1093
  kernel118(v636, v637);	// L1094
  auto v644 = reinterpret_cast<float(*)>(v620 + 94077952);
  kernel126(v644, v632);	// L1096
  auto v645 = reinterpret_cast<float(*)[64][3][3]>(v620 + 96437248);
  kernel125(v637, v645, v632);	// L1098
  auto v646 = reinterpret_cast<float(*)[64][56][56]>(v618 + 4014080);
  kernel124(v629, v646, v632);	// L1100
  kernel120(v632, v629);	// L1101
  kernel122(v629, (float)0.000000, (float)1.000000);	// L1102
  kernel121(v629, v632, (float)0.000000);	// L1103
  kernel120(v632, v646);	// L1104
  auto v647 = reinterpret_cast<float(*)[64][58][58]>(v619 + 16085248);
  kernel119(v647, (float)0.000000);	// L1106
  kernel118(v629, v647);	// L1107
  auto v648 = reinterpret_cast<float(*)[128][28][28]>(v618 + 16916992);
  auto v649 = reinterpret_cast<float(*)>(v620 + 89359360);
  kernel88(v649, v648);	// L1110
  auto v650 = reinterpret_cast<float(*)[64][3][3]>(v620 + 91718656);
  kernel116(v647, v650, v648);	// L1112
  auto v651 = reinterpret_cast<float(*)[128][28][28]>(v618 + 4816896);
  kernel95(v651, v648);	// L1114
  auto v652 = reinterpret_cast<float(*)[128][28][28]>(v618 + 16085248);
  kernel82(v648, v652);	// L1116
  kernel84(v652, (float)0.000000, (float)1.000000);	// L1117
  kernel83(v652, v648, (float)0.000000);	// L1118
  kernel82(v648, v651);	// L1119
  auto v653 = reinterpret_cast<float(*)[128][30][30]>(v619 + 17748736);
  kernel110(v653, (float)0.000000);	// L1121
  kernel80(v652, v653);	// L1122
  auto v654 = reinterpret_cast<float(*)>(v620 + 84640768);
  kernel88(v654, v652);	// L1124
  auto v655 = reinterpret_cast<float(*)[128][3][3]>(v620 + 87000064);
  kernel87(v653, v655, v652);	// L1126
  auto v656 = reinterpret_cast<float(*)>(v620 + 79922176);
  kernel88(v656, v648);	// L1128
  auto v657 = reinterpret_cast<float(*)[64][1][1]>(v620 + 82281472);
  kernel105(v629, v657, v648);	// L1130
  auto v658 = reinterpret_cast<float(*)[128][28][28]>(v618 + 5619712);
  kernel86(v652, v658, v648);	// L1132
  auto v659 = reinterpret_cast<float(*)[128][28][28]>(v618 + 15253504);
  kernel82(v648, v659);	// L1134
  kernel84(v659, (float)0.000000, (float)1.000000);	// L1135
  kernel83(v659, v648, (float)0.000000);	// L1136
  kernel82(v648, v658);	// L1137
  auto v660 = reinterpret_cast<float(*)[128][30][30]>(v619 + 16085248);
  kernel99(v660, (float)0.000000);	// L1139
  kernel80(v659, v660);	// L1140
  auto v661 = reinterpret_cast<float(*)>(v620 + 75203584);
  kernel88(v661, v648);	// L1142
  auto v662 = reinterpret_cast<float(*)[128][3][3]>(v620 + 77562880);
  kernel87(v660, v662, v648);	// L1144
  auto v663 = reinterpret_cast<float(*)[128][28][28]>(v618 + 6422528);
  kernel95(v663, v648);	// L1146
  auto v664 = reinterpret_cast<float(*)[128][28][28]>(v619 + 16085248);
  kernel82(v648, v664);	// L1148
  kernel84(v664, (float)0.000000, (float)1.000000);	// L1149
  kernel83(v664, v648, (float)0.000000);	// L1150
  kernel82(v648, v663);	// L1151
  kernel90(v653, (float)0.000000);	// L1152
  kernel80(v664, v653);	// L1153
  auto v665 = reinterpret_cast<float(*)>(v620 + 70484992);
  kernel88(v665, v648);	// L1155
  auto v666 = reinterpret_cast<float(*)[128][3][3]>(v620 + 72844288);
  kernel87(v653, v666, v648);	// L1157
  auto v667 = reinterpret_cast<float(*)[128][28][28]>(v618 + 7225344);
  kernel86(v659, v667, v648);	// L1159
  auto v668 = reinterpret_cast<float(*)[128][28][28]>(v619 + 15253504);
  kernel82(v648, v668);	// L1161
  kernel84(v668, (float)0.000000, (float)1.000000);	// L1162
  kernel83(v668, v648, (float)0.000000);	// L1163
  kernel82(v648, v667);	// L1164
  auto v669 = reinterpret_cast<float(*)[128][30][30]>(v618 + 16085248);
  kernel81(v669, (float)0.000000);	// L1166
  kernel80(v668, v669);	// L1167
  auto v670 = reinterpret_cast<float(*)[256][14][14]>(v619 + 16916992);
  auto v671 = reinterpret_cast<float(*)>(v620 + 65766400);
  kernel50(v671, v670);	// L1170
  auto v672 = reinterpret_cast<float(*)[128][3][3]>(v620 + 68125696);
  kernel78(v669, v672, v670);	// L1172
  auto v673 = reinterpret_cast<float(*)[256][14][14]>(v618 + 8028160);
  kernel57(v673, v670);	// L1174
  auto v674 = reinterpret_cast<float(*)[256][14][14]>(v618 + 16085248);
  kernel44(v670, v674);	// L1176
  kernel46(v674, (float)0.000000, (float)1.000000);	// L1177
  kernel45(v674, v670, (float)0.000000);	// L1178
  kernel44(v670, v673);	// L1179
  auto v675 = reinterpret_cast<float(*)[256][16][16]>(v618 + 17748736);
  kernel72(v675, (float)0.000000);	// L1181
  kernel42(v674, v675);	// L1182
  auto v676 = reinterpret_cast<float(*)[256][14][14]>(v620 + 16085248);
  auto v677 = reinterpret_cast<float(*)>(v619 + 61047808);
  kernel50(v677, v676);	// L1185
  auto v678 = reinterpret_cast<float(*)[256][3][3]>(v619 + 63407104);
  kernel49(v675, v678, v676);	// L1187
  auto v679 = reinterpret_cast<float(*)>(v620 + 56329216);
  kernel50(v679, v670);	// L1189
  auto v680 = reinterpret_cast<float(*)[128][1][1]>(v620 + 58688512);
  kernel67(v668, v680, v670);	// L1191
  auto v681 = reinterpret_cast<float(*)[256][14][14]>(v618 + 8830976);
  kernel48(v676, v681, v670);	// L1193
  auto v682 = reinterpret_cast<float(*)[256][14][14]>(v619 + 15253504);
  kernel44(v670, v682);	// L1195
  kernel46(v682, (float)0.000000, (float)1.000000);	// L1196
  kernel45(v682, v670, (float)0.000000);	// L1197
  kernel44(v670, v681);	// L1198
  auto v683 = reinterpret_cast<float(*)[256][16][16]>(v618 + 16085248);
  kernel61(v683, (float)0.000000);	// L1200
  kernel42(v682, v683);	// L1201
  auto v684 = reinterpret_cast<float(*)>(v620 + 51610624);
  kernel50(v684, v670);	// L1203
  auto v685 = reinterpret_cast<float(*)[256][3][3]>(v620 + 53969920);
  kernel49(v683, v685, v670);	// L1205
  auto v686 = reinterpret_cast<float(*)[256][14][14]>(v618 + 9633792);
  kernel57(v686, v670);	// L1207
  kernel44(v670, v674);	// L1208
  kernel46(v674, (float)0.000000, (float)1.000000);	// L1209
  kernel45(v674, v670, (float)0.000000);	// L1210
  kernel44(v670, v686);	// L1211
  kernel52(v675, (float)0.000000);	// L1212
  kernel42(v674, v675);	// L1213
  auto v687 = reinterpret_cast<float(*)>(v620 + 46892032);
  kernel50(v687, v670);	// L1215
  auto v688 = reinterpret_cast<float(*)[256][3][3]>(v620 + 49251328);
  kernel49(v675, v688, v670);	// L1217
  auto v689 = reinterpret_cast<float(*)[256][14][14]>(v618 + 10436608);
  kernel48(v682, v689, v670);	// L1219
  kernel44(v670, v682);	// L1220
  kernel46(v682, (float)0.000000, (float)1.000000);	// L1221
  kernel45(v682, v670, (float)0.000000);	// L1222
  kernel44(v670, v689);	// L1223
  auto v690 = reinterpret_cast<float(*)[256][16][16]>(v619 + 16085248);
  kernel43(v690, (float)0.000000);	// L1225
  kernel42(v682, v690);	// L1226
  auto v691 = reinterpret_cast<float(*)[512][7][7]>(v618 + 16916992);
  auto v692 = reinterpret_cast<float(*)>(v620 + 42173440);
  kernel12(v692, v691);	// L1229
  auto v693 = reinterpret_cast<float(*)[256][3][3]>(v620 + 44532736);
  kernel40(v690, v693, v691);	// L1231
  auto v694 = reinterpret_cast<float(*)[512][7][7]>(v618 + 11239424);
  kernel19(v694, v691);	// L1233
  auto v695 = reinterpret_cast<float(*)[512][7][7]>(v619 + 16085248);
  kernel6(v691, v695);	// L1235
  kernel8(v695, (float)0.000000, (float)1.000000);	// L1236
  kernel7(v695, v691, (float)0.000000);	// L1237
  kernel6(v691, v694);	// L1238
  auto v696 = reinterpret_cast<float(*)[512][9][9]>(v618 + 17748736);
  kernel34(v696, (float)0.000000);	// L1240
  kernel13(v695, v696);	// L1241
  auto v697 = reinterpret_cast<float(*)>(v620 + 37454848);
  kernel12(v697, v695);	// L1243
  auto v698 = reinterpret_cast<float(*)[512][3][3]>(v620 + 39814144);
  kernel11(v696, v698, v695);	// L1245
  auto v699 = reinterpret_cast<float(*)>(v620 + 32736256);
  kernel12(v699, v691);	// L1247
  auto v700 = reinterpret_cast<float(*)[256][1][1]>(v620 + 35095552);
  kernel29(v682, v700, v691);	// L1249
  auto v701 = reinterpret_cast<float(*)[512][7][7]>(v618 + 12042240);
  kernel10(v695, v701, v691);	// L1251
  auto v702 = reinterpret_cast<float(*)[512][7][7]>(v619 + 15253504);
  kernel6(v691, v702);	// L1253
  kernel8(v702, (float)0.000000, (float)1.000000);	// L1254
  kernel7(v702, v691, (float)0.000000);	// L1255
  kernel6(v691, v701);	// L1256
  auto v703 = reinterpret_cast<float(*)[512][9][9]>(v618 + 16085248);
  kernel23(v703, (float)0.000000);	// L1258
  kernel13(v702, v703);	// L1259
  auto v704 = reinterpret_cast<float(*)>(v620 + 28017664);
  kernel12(v704, v691);	// L1261
  auto v705 = reinterpret_cast<float(*)[512][3][3]>(v620 + 30376960);
  kernel11(v703, v705, v691);	// L1263
  auto v706 = reinterpret_cast<float(*)[512][7][7]>(v618 + 12845056);
  kernel19(v706, v691);	// L1265
  auto v707 = reinterpret_cast<float(*)[512][7][7]>(v618 + 16085248);
  kernel6(v691, v707);	// L1267
  kernel8(v707, (float)0.000000, (float)1.000000);	// L1268
  kernel7(v707, v691, (float)0.000000);	// L1269
  kernel6(v691, v706);	// L1270
  auto v708 = reinterpret_cast<float(*)[512][9][9]>(v619 + 17748736);
  kernel14(v708, (float)0.000000);	// L1272
  kernel13(v707, v708);	// L1273
  auto v709 = reinterpret_cast<float(*)>(v620 + 23299072);
  kernel12(v709, v691);	// L1275
  auto v710 = reinterpret_cast<float(*)[512][3][3]>(v620 + 25658368);
  kernel11(v708, v710, v691);	// L1277
  auto v711 = reinterpret_cast<float(*)[512][7][7]>(v618 + 13647872);
  kernel10(v702, v711, v691);	// L1279
  kernel6(v691, v702);	// L1280
  kernel8(v702, (float)0.000000, (float)1.000000);	// L1281
  kernel7(v702, v691, (float)0.000000);	// L1282
  kernel6(v691, v711);	// L1283
  auto v712 = reinterpret_cast<float(*)[512][1][1]>(v618 + 16085248);
  kernel5(v712, (float)0.000000);	// L1285
  auto v713 = reinterpret_cast<float(*)[7]>(v620 + 16916992);
  kernel4(v702, v713, v712);	// L1287
  kernel3(v712, (float)49.000000);	// L1288
  auto v714 = reinterpret_cast<float(*)[1000]>(v618 + 14450688);
  kernel2(v714, (float)0.000000);	// L1290
  auto v715 = reinterpret_cast<float(*)[1000]>(v620 + 18580480);
  kernel1(v712, v715, v714);	// L1292
  auto v716 = reinterpret_cast<float(*)>(v620 + 20939776);
  kernel0(v716, v714);	// L1294
}

/// The T-step wrapper (FHCA v1.4: on-chip time-step loop)
/// Drives the single-step control T times; membrane states persist in DDR top_level buffers.
/// input_frames: DDR staging of T input frames (per-step-input);
///   frame t is memcpy'd to the input slot (arg0+0) before step t.
///   frame_elems=0: static input (host pre-writes frame, no copy).
/// out_frames: per-step outputs staged to DDR (out region assumed on
///   arg0 at out_elem_offset); out_elems=0: skip staging.
void control_t(
  ap_int<32> t_v0[117670912],
  ap_int<32> t_v1[117670912],
  ap_int<32> t_v2[117670912],
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

