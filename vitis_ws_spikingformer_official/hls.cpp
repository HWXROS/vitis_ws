
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
) {	// L5
  float v2[10];	// L6
  #pragma HLS resource variable=v2 core=ram_t2p_bram

  memcpy(v2, v0, 10 * sizeof(float));	// L7

  float v3[1][10];	// L8
  #pragma HLS resource variable=v3 core=ram_t2p_bram

  memcpy(v3, v1, 10 * sizeof(float));	// L9

  for (int v4 = 0; v4 < 10; v4 += 1) {	// L10
    #pragma HLS pipeline II=1
    #pragma HLS dependence false variable=v3
    #pragma HLS dependence false variable=v2
    float v5 = v3[0][v4];	// L11
    float v6 = v2[v4];	// L12
    float v7 = v5 + v6;	// L13
    v3[0][v4] = v7;	// L14
  }
  memcpy(v1, v3, 10 * sizeof(float));	// L16

}

void kernel1(
  float v8[1][384],
  float v9[384][10],
  float v10[1][10]
) {	// L19
  float v11[1][10];	// L20
  #pragma HLS resource variable=v11 core=ram_t2p_bram

  memcpy(v11, v10, 10 * sizeof(float));	// L21

  float v12[1][384];	// L22
  #pragma HLS resource variable=v12 core=ram_t2p_bram

  memcpy(v12, v8, 384 * sizeof(float));	// L23

  for (int v13 = 0; v13 < 384; v13 += 1) {	// L24
    for (int v14 = 0; v14 < 10; v14 += 1) {	// L25
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v12
      #pragma HLS dependence false variable=v9
      #pragma HLS dependence false variable=v11
      float v15 = v12[0][v13];	// L26
      float v16 = v9[v13][v14];	// L27
      float v17 = v11[0][v14];	// L28
      float v18 = v15 * v16;	// L29
      float v19 = v17 + v18;	// L30
      v11[0][v14] = v19;	// L31
    }
  }
  memcpy(v10, v11, 10 * sizeof(float));	// L34

}

void kernel2(
  float v20[1][10],
  float v21
) {	// L37
  float v22[1][10];	// L38
  #pragma HLS resource variable=v22 core=ram_t2p_bram

  for (int v23 = 0; v23 < 10; v23 += 1) {	// L39
    #pragma HLS pipeline II=1
    #pragma HLS dependence false variable=v22
    v22[0][v23] = v21;	// L40
  }
  memcpy(v20, v22, 10 * sizeof(float));	// L42

}

void kernel3(
  float v24[1][384],
  float v25
) {	// L45
  for (int v26 = 0; v26 < 384; v26 += 1) {	// L46
    #pragma HLS pipeline II=1
    #pragma HLS dependence false variable=v24
    float v27 = v24[0][v26];	// L47
    float v28 = v27 / v25;	// L48
    v24[0][v26] = v28;	// L49
  }
}

void kernel4(
  float v29[1][384][8][8],
  float v30[1][384]
) {	// L53
  float v31[1][384];	// L54
  #pragma HLS resource variable=v31 core=ram_t2p_bram

  memcpy(v31, v30, 384 * sizeof(float));	// L55

  for (int v32 = 0; v32 < 64; v32 += 1) {	// L56
    for (int v33 = 0; v33 < 384; v33 += 1) {	// L57
      float v34 = v29[0][v33][(v32 / 8)][(v32 % 8)];	// L58
      float v35 = v31[0][v33];	// L59
      float v36 = v34 + v35;	// L60
      v31[0][v33] = v36;	// L61
    }
  }
  memcpy(v30, v31, 384 * sizeof(float));	// L64

}

void kernel5(
  float v37[1][384],
  float v38
) {	// L67
  for (int v39 = 0; v39 < 384; v39 += 1) {	// L68
    #pragma HLS pipeline II=1
    #pragma HLS dependence false variable=v37
    v37[0][v39] = v38;	// L69
  }
}

void kernel6(
  float v40[1][384][8][8],
  float v41[1][384][8][8]
) {	// L73
  for (int v42 = 0; v42 < 384; v42 += 1) {	// L74
    for (int v43 = 0; v43 < 8; v43 += 1) {	// L75
      for (int v44 = 0; v44 < 8; v44 += 1) {	// L76
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v40
        #pragma HLS dependence false variable=v41
        float v45 = v40[0][v42][v43][v44];	// L77
        float v46 = v41[0][v42][v43][v44];	// L78
        float v47 = v45 + v46;	// L79
        v41[0][v42][v43][v44] = v47;	// L80
      }
    }
  }
}

void kernel7(
  float v48[1][1536][8][8],
  float v49[384][1536][1][1],
  float v50[1][384][8][8]
) {	// L86
  ap_int<32> v51[3072];	// L120
  #pragma HLS resource variable=v51 core=ram_t2p_bram

  for (int v52 = 0; v52 < 3072; v52 += 1) {	// L121
    float v53 = v48[0][(v52 / 2)][((v52 * 4) + ((v52 / 2) * -8))][0];	// L122
    bool v54 = v53 != (float)0.000000;	// L123
    ap_int<32> v55 = v54;	// L124
    float v56 = v48[0][(v52 / 2)][((v52 * 4) + ((v52 / 2) * -8))][1];	// L125
    bool v57 = v56 != (float)0.000000;	// L126
    ap_int<32> v58 = v57;	// L127
    ap_int<32> v59 = v58 << (ap_int<32>)1;	// L128
    ap_int<32> v60 = v55 | v59;	// L129
    float v61 = v48[0][(v52 / 2)][((v52 * 4) + ((v52 / 2) * -8))][2];	// L130
    bool v62 = v61 != (float)0.000000;	// L131
    ap_int<32> v63 = v62;	// L132
    ap_int<32> v64 = v63 << (ap_int<32>)2;	// L133
    ap_int<32> v65 = v60 | v64;	// L134
    float v66 = v48[0][(v52 / 2)][((v52 * 4) + ((v52 / 2) * -8))][3];	// L135
    bool v67 = v66 != (float)0.000000;	// L136
    ap_int<32> v68 = v67;	// L137
    ap_int<32> v69 = v68 << (ap_int<32>)3;	// L138
    ap_int<32> v70 = v65 | v69;	// L139
    float v71 = v48[0][(v52 / 2)][((v52 * 4) + ((v52 / 2) * -8))][4];	// L140
    bool v72 = v71 != (float)0.000000;	// L141
    ap_int<32> v73 = v72;	// L142
    ap_int<32> v74 = v73 << (ap_int<32>)4;	// L143
    ap_int<32> v75 = v70 | v74;	// L144
    float v76 = v48[0][(v52 / 2)][((v52 * 4) + ((v52 / 2) * -8))][5];	// L145
    bool v77 = v76 != (float)0.000000;	// L146
    ap_int<32> v78 = v77;	// L147
    ap_int<32> v79 = v78 << (ap_int<32>)5;	// L148
    ap_int<32> v80 = v75 | v79;	// L149
    float v81 = v48[0][(v52 / 2)][((v52 * 4) + ((v52 / 2) * -8))][6];	// L150
    bool v82 = v81 != (float)0.000000;	// L151
    ap_int<32> v83 = v82;	// L152
    ap_int<32> v84 = v83 << (ap_int<32>)6;	// L153
    ap_int<32> v85 = v80 | v84;	// L154
    float v86 = v48[0][(v52 / 2)][((v52 * 4) + ((v52 / 2) * -8))][7];	// L155
    bool v87 = v86 != (float)0.000000;	// L156
    ap_int<32> v88 = v87;	// L157
    ap_int<32> v89 = v88 << (ap_int<32>)7;	// L158
    ap_int<32> v90 = v85 | v89;	// L159
    float v91 = v48[0][(v52 / 2)][(((v52 * 4) + ((v52 / 2) * -8)) + 1)][0];	// L160
    bool v92 = v91 != (float)0.000000;	// L161
    ap_int<32> v93 = v92;	// L162
    ap_int<32> v94 = v93 << (ap_int<32>)8;	// L163
    ap_int<32> v95 = v90 | v94;	// L164
    float v96 = v48[0][(v52 / 2)][(((v52 * 4) + ((v52 / 2) * -8)) + 1)][1];	// L165
    bool v97 = v96 != (float)0.000000;	// L166
    ap_int<32> v98 = v97;	// L167
    ap_int<32> v99 = v98 << (ap_int<32>)9;	// L168
    ap_int<32> v100 = v95 | v99;	// L169
    float v101 = v48[0][(v52 / 2)][(((v52 * 4) + ((v52 / 2) * -8)) + 1)][2];	// L170
    bool v102 = v101 != (float)0.000000;	// L171
    ap_int<32> v103 = v102;	// L172
    ap_int<32> v104 = v103 << (ap_int<32>)10;	// L173
    ap_int<32> v105 = v100 | v104;	// L174
    float v106 = v48[0][(v52 / 2)][(((v52 * 4) + ((v52 / 2) * -8)) + 1)][3];	// L175
    bool v107 = v106 != (float)0.000000;	// L176
    ap_int<32> v108 = v107;	// L177
    ap_int<32> v109 = v108 << (ap_int<32>)11;	// L178
    ap_int<32> v110 = v105 | v109;	// L179
    float v111 = v48[0][(v52 / 2)][(((v52 * 4) + ((v52 / 2) * -8)) + 1)][4];	// L180
    bool v112 = v111 != (float)0.000000;	// L181
    ap_int<32> v113 = v112;	// L182
    ap_int<32> v114 = v113 << (ap_int<32>)12;	// L183
    ap_int<32> v115 = v110 | v114;	// L184
    float v116 = v48[0][(v52 / 2)][(((v52 * 4) + ((v52 / 2) * -8)) + 1)][5];	// L185
    bool v117 = v116 != (float)0.000000;	// L186
    ap_int<32> v118 = v117;	// L187
    ap_int<32> v119 = v118 << (ap_int<32>)13;	// L188
    ap_int<32> v120 = v115 | v119;	// L189
    float v121 = v48[0][(v52 / 2)][(((v52 * 4) + ((v52 / 2) * -8)) + 1)][6];	// L190
    bool v122 = v121 != (float)0.000000;	// L191
    ap_int<32> v123 = v122;	// L192
    ap_int<32> v124 = v123 << (ap_int<32>)14;	// L193
    ap_int<32> v125 = v120 | v124;	// L194
    float v126 = v48[0][(v52 / 2)][(((v52 * 4) + ((v52 / 2) * -8)) + 1)][7];	// L195
    bool v127 = v126 != (float)0.000000;	// L196
    ap_int<32> v128 = v127;	// L197
    ap_int<32> v129 = v128 << (ap_int<32>)15;	// L198
    ap_int<32> v130 = v125 | v129;	// L199
    float v131 = v48[0][(v52 / 2)][(((v52 * 4) + ((v52 / 2) * -8)) + 2)][0];	// L200
    bool v132 = v131 != (float)0.000000;	// L201
    ap_int<32> v133 = v132;	// L202
    ap_int<32> v134 = v133 << (ap_int<32>)16;	// L203
    ap_int<32> v135 = v130 | v134;	// L204
    float v136 = v48[0][(v52 / 2)][(((v52 * 4) + ((v52 / 2) * -8)) + 2)][1];	// L205
    bool v137 = v136 != (float)0.000000;	// L206
    ap_int<32> v138 = v137;	// L207
    ap_int<32> v139 = v138 << (ap_int<32>)17;	// L208
    ap_int<32> v140 = v135 | v139;	// L209
    float v141 = v48[0][(v52 / 2)][(((v52 * 4) + ((v52 / 2) * -8)) + 2)][2];	// L210
    bool v142 = v141 != (float)0.000000;	// L211
    ap_int<32> v143 = v142;	// L212
    ap_int<32> v144 = v143 << (ap_int<32>)18;	// L213
    ap_int<32> v145 = v140 | v144;	// L214
    float v146 = v48[0][(v52 / 2)][(((v52 * 4) + ((v52 / 2) * -8)) + 2)][3];	// L215
    bool v147 = v146 != (float)0.000000;	// L216
    ap_int<32> v148 = v147;	// L217
    ap_int<32> v149 = v148 << (ap_int<32>)19;	// L218
    ap_int<32> v150 = v145 | v149;	// L219
    float v151 = v48[0][(v52 / 2)][(((v52 * 4) + ((v52 / 2) * -8)) + 2)][4];	// L220
    bool v152 = v151 != (float)0.000000;	// L221
    ap_int<32> v153 = v152;	// L222
    ap_int<32> v154 = v153 << (ap_int<32>)20;	// L223
    ap_int<32> v155 = v150 | v154;	// L224
    float v156 = v48[0][(v52 / 2)][(((v52 * 4) + ((v52 / 2) * -8)) + 2)][5];	// L225
    bool v157 = v156 != (float)0.000000;	// L226
    ap_int<32> v158 = v157;	// L227
    ap_int<32> v159 = v158 << (ap_int<32>)21;	// L228
    ap_int<32> v160 = v155 | v159;	// L229
    float v161 = v48[0][(v52 / 2)][(((v52 * 4) + ((v52 / 2) * -8)) + 2)][6];	// L230
    bool v162 = v161 != (float)0.000000;	// L231
    ap_int<32> v163 = v162;	// L232
    ap_int<32> v164 = v163 << (ap_int<32>)22;	// L233
    ap_int<32> v165 = v160 | v164;	// L234
    float v166 = v48[0][(v52 / 2)][(((v52 * 4) + ((v52 / 2) * -8)) + 2)][7];	// L235
    bool v167 = v166 != (float)0.000000;	// L236
    ap_int<32> v168 = v167;	// L237
    ap_int<32> v169 = v168 << (ap_int<32>)23;	// L238
    ap_int<32> v170 = v165 | v169;	// L239
    float v171 = v48[0][(v52 / 2)][(((v52 * 4) + ((v52 / 2) * -8)) + 3)][0];	// L240
    bool v172 = v171 != (float)0.000000;	// L241
    ap_int<32> v173 = v172;	// L242
    ap_int<32> v174 = v173 << (ap_int<32>)24;	// L243
    ap_int<32> v175 = v170 | v174;	// L244
    float v176 = v48[0][(v52 / 2)][(((v52 * 4) + ((v52 / 2) * -8)) + 3)][1];	// L245
    bool v177 = v176 != (float)0.000000;	// L246
    ap_int<32> v178 = v177;	// L247
    ap_int<32> v179 = v178 << (ap_int<32>)25;	// L248
    ap_int<32> v180 = v175 | v179;	// L249
    float v181 = v48[0][(v52 / 2)][(((v52 * 4) + ((v52 / 2) * -8)) + 3)][2];	// L250
    bool v182 = v181 != (float)0.000000;	// L251
    ap_int<32> v183 = v182;	// L252
    ap_int<32> v184 = v183 << (ap_int<32>)26;	// L253
    ap_int<32> v185 = v180 | v184;	// L254
    float v186 = v48[0][(v52 / 2)][(((v52 * 4) + ((v52 / 2) * -8)) + 3)][3];	// L255
    bool v187 = v186 != (float)0.000000;	// L256
    ap_int<32> v188 = v187;	// L257
    ap_int<32> v189 = v188 << (ap_int<32>)27;	// L258
    ap_int<32> v190 = v185 | v189;	// L259
    float v191 = v48[0][(v52 / 2)][(((v52 * 4) + ((v52 / 2) * -8)) + 3)][4];	// L260
    bool v192 = v191 != (float)0.000000;	// L261
    ap_int<32> v193 = v192;	// L262
    ap_int<32> v194 = v193 << (ap_int<32>)28;	// L263
    ap_int<32> v195 = v190 | v194;	// L264
    float v196 = v48[0][(v52 / 2)][(((v52 * 4) + ((v52 / 2) * -8)) + 3)][5];	// L265
    bool v197 = v196 != (float)0.000000;	// L266
    ap_int<32> v198 = v197;	// L267
    ap_int<32> v199 = v198 << (ap_int<32>)29;	// L268
    ap_int<32> v200 = v195 | v199;	// L269
    float v201 = v48[0][(v52 / 2)][(((v52 * 4) + ((v52 / 2) * -8)) + 3)][6];	// L270
    bool v202 = v201 != (float)0.000000;	// L271
    ap_int<32> v203 = v202;	// L272
    ap_int<32> v204 = v203 << (ap_int<32>)30;	// L273
    ap_int<32> v205 = v200 | v204;	// L274
    float v206 = v48[0][(v52 / 2)][(((v52 * 4) + ((v52 / 2) * -8)) + 3)][7];	// L275
    bool v207 = v206 != (float)0.000000;	// L276
    ap_int<32> v208 = v207;	// L277
    ap_int<32> v209 = v208 << (ap_int<32>)31;	// L278
    ap_int<32> v210 = v205 | v209;	// L279
    v51[v52] = v210;	// L280
  }
  float v211[1][384][8][8];	// L282
  #pragma HLS resource variable=v211 core=ram_t2p_bram

  memcpy(v211, v50, 24576 * sizeof(float));	// L283

  auto v212 = reinterpret_cast<float(*)[1536][1][1]>(v49);	// L285

  for (int v213 = 0; v213 < 1536; v213 += 1) {	// L286
    for (int v214 = 0; v214 < 384; v214 += 1) {	// L287
      float v215 = v212[v214][v213][0][0];	// L288
      for (int v216 = 0; v216 < 8; v216 += 1) {	// L289
        for (int v217 = 0; v217 < 8; v217 += 1) {	// L290
          #pragma HLS pipeline II=1
          #pragma HLS dependence false variable=v51
          #pragma HLS dependence false variable=v211
          ap_int<32> v218 = v51[((v213 * 2) + (v216 / 4))];	// L291
          int v219 = ((((v213 * 64) + (v216 * 8)) + v217) % 32);	// L292
          ap_int<32> v220 = v219;	// L293
          ap_int<32> v221 = v218 >> v220;	// L294
          ap_int<32> v222 = v221 & (ap_int<32>)1;	// L295
          bool v223 = v222 != (ap_int<32>)0;	// L296
          float v224 = v211[0][v214][v216][v217];	// L297
          float v225 = v224 + v215;	// L298
          float v226 = v223 ? v225 : v224;	// L299
          v211[0][v214][v216][v217] = v226;	// L300
        }
      }
    }
  }
  memcpy(v50, v211, 24576 * sizeof(float));	// L305

}

void kernel8(
  float v227[384],
  float v228[1][384][8][8]
) {	// L308
  float v229[384];	// L309
  #pragma HLS resource variable=v229 core=ram_t2p_bram

  memcpy(v229, v227, 384 * sizeof(float));	// L310

  for (int v230 = 0; v230 < 384; v230 += 1) {	// L311
    for (int v231 = 0; v231 < 8; v231 += 1) {	// L312
      for (int v232 = 0; v232 < 8; v232 += 1) {	// L313
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v229
        #pragma HLS dependence false variable=v228
        float v233 = v229[v230];	// L314
        v228[0][v230][v231][v232] = v233;	// L315
      }
    }
  }
}

void kernel9(
  float v234[1][1536][8][8],
  float v235[1][1536][8][8]
) {	// L321
  for (int v236 = 0; v236 < 1536; v236 += 1) {	// L322
    for (int v237 = 0; v237 < 8; v237 += 1) {	// L323
      for (int v238 = 0; v238 < 8; v238 += 1) {	// L324
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v234
        #pragma HLS dependence false variable=v235
        float v239 = v234[0][v236][v237][v238];	// L325
        v235[0][v236][v237][v238] = v239;	// L326
      }
    }
  }
}

void kernel10(
  float v240[1][1536][8][8],
  float v241[1][1536][8][8],
  float v242
) {	// L332
  for (int v243 = 0; v243 < 1536; v243 += 1) {	// L334
    for (int v244 = 0; v244 < 8; v244 += 1) {	// L335
      for (int v245 = 0; v245 < 8; v245 += 1) {	// L336
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v241
        #pragma HLS dependence false variable=v240
        float v246 = v241[0][v243][v244][v245];	// L337
        float v247 = v240[0][v243][v244][v245];	// L338
        float v248 = v247 * v246;	// L339
        float v249 = v246 - v248;	// L340
        bool v250 = v247 != (float)0.000000;	// L341
        float v251 = v249 + v242;	// L342
        float v252 = v250 ? v251 : v249;	// L343
        v241[0][v243][v244][v245] = v252;	// L344
      }
    }
  }
}

void kernel11(
  float v253[1][1536][8][8],
  float v254,
  float v255
) {	// L350
  for (int v256 = 0; v256 < 1536; v256 += 1) {	// L351
    for (int v257 = 0; v257 < 8; v257 += 1) {	// L352
      for (int v258 = 0; v258 < 8; v258 += 1) {	// L353
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v253
        float v259 = v253[0][v256][v257][v258];	// L354
        float v260 = v259 - v255;	// L355
        bool v261 = v260 >= v254;	// L356
        float v262 = v261 ? v255 : v254;	// L357
        v253[0][v256][v257][v258] = v262;	// L358
      }
    }
  }
}

void kernel13(
  float v263[1][1536][8][8],
  float v264[1][1536][8][8],
  float v265
) {	// L364
  for (int v266 = 0; v266 < 1536; v266 += 1) {	// L365
    for (int v267 = 0; v267 < 8; v267 += 1) {	// L366
      for (int v268 = 0; v268 < 8; v268 += 1) {	// L367
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v263
        #pragma HLS dependence false variable=v264
        float v269 = v263[0][v266][v267][v268];	// L368
        float v270 = v264[0][v266][v267][v268];	// L369
        float v271 = v270 / v265;	// L370
        float v272 = v269 / v265;	// L371
        float v273 = v269 - v272;	// L372
        float v274 = v273 + v271;	// L373
        v264[0][v266][v267][v268] = v274;	// L374
      }
    }
  }
}

void kernel14(
  float v275[1][384][8][8],
  float v276[1536][384][1][1],
  float v277[1][1536][8][8]
) {	// L380
  ap_int<32> v278[768];	// L414
  #pragma HLS resource variable=v278 core=ram_t2p_bram

  for (int v279 = 0; v279 < 768; v279 += 1) {	// L415
    float v280 = v275[0][(v279 / 2)][((v279 * 4) + ((v279 / 2) * -8))][0];	// L416
    bool v281 = v280 != (float)0.000000;	// L417
    ap_int<32> v282 = v281;	// L418
    float v283 = v275[0][(v279 / 2)][((v279 * 4) + ((v279 / 2) * -8))][1];	// L419
    bool v284 = v283 != (float)0.000000;	// L420
    ap_int<32> v285 = v284;	// L421
    ap_int<32> v286 = v285 << (ap_int<32>)1;	// L422
    ap_int<32> v287 = v282 | v286;	// L423
    float v288 = v275[0][(v279 / 2)][((v279 * 4) + ((v279 / 2) * -8))][2];	// L424
    bool v289 = v288 != (float)0.000000;	// L425
    ap_int<32> v290 = v289;	// L426
    ap_int<32> v291 = v290 << (ap_int<32>)2;	// L427
    ap_int<32> v292 = v287 | v291;	// L428
    float v293 = v275[0][(v279 / 2)][((v279 * 4) + ((v279 / 2) * -8))][3];	// L429
    bool v294 = v293 != (float)0.000000;	// L430
    ap_int<32> v295 = v294;	// L431
    ap_int<32> v296 = v295 << (ap_int<32>)3;	// L432
    ap_int<32> v297 = v292 | v296;	// L433
    float v298 = v275[0][(v279 / 2)][((v279 * 4) + ((v279 / 2) * -8))][4];	// L434
    bool v299 = v298 != (float)0.000000;	// L435
    ap_int<32> v300 = v299;	// L436
    ap_int<32> v301 = v300 << (ap_int<32>)4;	// L437
    ap_int<32> v302 = v297 | v301;	// L438
    float v303 = v275[0][(v279 / 2)][((v279 * 4) + ((v279 / 2) * -8))][5];	// L439
    bool v304 = v303 != (float)0.000000;	// L440
    ap_int<32> v305 = v304;	// L441
    ap_int<32> v306 = v305 << (ap_int<32>)5;	// L442
    ap_int<32> v307 = v302 | v306;	// L443
    float v308 = v275[0][(v279 / 2)][((v279 * 4) + ((v279 / 2) * -8))][6];	// L444
    bool v309 = v308 != (float)0.000000;	// L445
    ap_int<32> v310 = v309;	// L446
    ap_int<32> v311 = v310 << (ap_int<32>)6;	// L447
    ap_int<32> v312 = v307 | v311;	// L448
    float v313 = v275[0][(v279 / 2)][((v279 * 4) + ((v279 / 2) * -8))][7];	// L449
    bool v314 = v313 != (float)0.000000;	// L450
    ap_int<32> v315 = v314;	// L451
    ap_int<32> v316 = v315 << (ap_int<32>)7;	// L452
    ap_int<32> v317 = v312 | v316;	// L453
    float v318 = v275[0][(v279 / 2)][(((v279 * 4) + ((v279 / 2) * -8)) + 1)][0];	// L454
    bool v319 = v318 != (float)0.000000;	// L455
    ap_int<32> v320 = v319;	// L456
    ap_int<32> v321 = v320 << (ap_int<32>)8;	// L457
    ap_int<32> v322 = v317 | v321;	// L458
    float v323 = v275[0][(v279 / 2)][(((v279 * 4) + ((v279 / 2) * -8)) + 1)][1];	// L459
    bool v324 = v323 != (float)0.000000;	// L460
    ap_int<32> v325 = v324;	// L461
    ap_int<32> v326 = v325 << (ap_int<32>)9;	// L462
    ap_int<32> v327 = v322 | v326;	// L463
    float v328 = v275[0][(v279 / 2)][(((v279 * 4) + ((v279 / 2) * -8)) + 1)][2];	// L464
    bool v329 = v328 != (float)0.000000;	// L465
    ap_int<32> v330 = v329;	// L466
    ap_int<32> v331 = v330 << (ap_int<32>)10;	// L467
    ap_int<32> v332 = v327 | v331;	// L468
    float v333 = v275[0][(v279 / 2)][(((v279 * 4) + ((v279 / 2) * -8)) + 1)][3];	// L469
    bool v334 = v333 != (float)0.000000;	// L470
    ap_int<32> v335 = v334;	// L471
    ap_int<32> v336 = v335 << (ap_int<32>)11;	// L472
    ap_int<32> v337 = v332 | v336;	// L473
    float v338 = v275[0][(v279 / 2)][(((v279 * 4) + ((v279 / 2) * -8)) + 1)][4];	// L474
    bool v339 = v338 != (float)0.000000;	// L475
    ap_int<32> v340 = v339;	// L476
    ap_int<32> v341 = v340 << (ap_int<32>)12;	// L477
    ap_int<32> v342 = v337 | v341;	// L478
    float v343 = v275[0][(v279 / 2)][(((v279 * 4) + ((v279 / 2) * -8)) + 1)][5];	// L479
    bool v344 = v343 != (float)0.000000;	// L480
    ap_int<32> v345 = v344;	// L481
    ap_int<32> v346 = v345 << (ap_int<32>)13;	// L482
    ap_int<32> v347 = v342 | v346;	// L483
    float v348 = v275[0][(v279 / 2)][(((v279 * 4) + ((v279 / 2) * -8)) + 1)][6];	// L484
    bool v349 = v348 != (float)0.000000;	// L485
    ap_int<32> v350 = v349;	// L486
    ap_int<32> v351 = v350 << (ap_int<32>)14;	// L487
    ap_int<32> v352 = v347 | v351;	// L488
    float v353 = v275[0][(v279 / 2)][(((v279 * 4) + ((v279 / 2) * -8)) + 1)][7];	// L489
    bool v354 = v353 != (float)0.000000;	// L490
    ap_int<32> v355 = v354;	// L491
    ap_int<32> v356 = v355 << (ap_int<32>)15;	// L492
    ap_int<32> v357 = v352 | v356;	// L493
    float v358 = v275[0][(v279 / 2)][(((v279 * 4) + ((v279 / 2) * -8)) + 2)][0];	// L494
    bool v359 = v358 != (float)0.000000;	// L495
    ap_int<32> v360 = v359;	// L496
    ap_int<32> v361 = v360 << (ap_int<32>)16;	// L497
    ap_int<32> v362 = v357 | v361;	// L498
    float v363 = v275[0][(v279 / 2)][(((v279 * 4) + ((v279 / 2) * -8)) + 2)][1];	// L499
    bool v364 = v363 != (float)0.000000;	// L500
    ap_int<32> v365 = v364;	// L501
    ap_int<32> v366 = v365 << (ap_int<32>)17;	// L502
    ap_int<32> v367 = v362 | v366;	// L503
    float v368 = v275[0][(v279 / 2)][(((v279 * 4) + ((v279 / 2) * -8)) + 2)][2];	// L504
    bool v369 = v368 != (float)0.000000;	// L505
    ap_int<32> v370 = v369;	// L506
    ap_int<32> v371 = v370 << (ap_int<32>)18;	// L507
    ap_int<32> v372 = v367 | v371;	// L508
    float v373 = v275[0][(v279 / 2)][(((v279 * 4) + ((v279 / 2) * -8)) + 2)][3];	// L509
    bool v374 = v373 != (float)0.000000;	// L510
    ap_int<32> v375 = v374;	// L511
    ap_int<32> v376 = v375 << (ap_int<32>)19;	// L512
    ap_int<32> v377 = v372 | v376;	// L513
    float v378 = v275[0][(v279 / 2)][(((v279 * 4) + ((v279 / 2) * -8)) + 2)][4];	// L514
    bool v379 = v378 != (float)0.000000;	// L515
    ap_int<32> v380 = v379;	// L516
    ap_int<32> v381 = v380 << (ap_int<32>)20;	// L517
    ap_int<32> v382 = v377 | v381;	// L518
    float v383 = v275[0][(v279 / 2)][(((v279 * 4) + ((v279 / 2) * -8)) + 2)][5];	// L519
    bool v384 = v383 != (float)0.000000;	// L520
    ap_int<32> v385 = v384;	// L521
    ap_int<32> v386 = v385 << (ap_int<32>)21;	// L522
    ap_int<32> v387 = v382 | v386;	// L523
    float v388 = v275[0][(v279 / 2)][(((v279 * 4) + ((v279 / 2) * -8)) + 2)][6];	// L524
    bool v389 = v388 != (float)0.000000;	// L525
    ap_int<32> v390 = v389;	// L526
    ap_int<32> v391 = v390 << (ap_int<32>)22;	// L527
    ap_int<32> v392 = v387 | v391;	// L528
    float v393 = v275[0][(v279 / 2)][(((v279 * 4) + ((v279 / 2) * -8)) + 2)][7];	// L529
    bool v394 = v393 != (float)0.000000;	// L530
    ap_int<32> v395 = v394;	// L531
    ap_int<32> v396 = v395 << (ap_int<32>)23;	// L532
    ap_int<32> v397 = v392 | v396;	// L533
    float v398 = v275[0][(v279 / 2)][(((v279 * 4) + ((v279 / 2) * -8)) + 3)][0];	// L534
    bool v399 = v398 != (float)0.000000;	// L535
    ap_int<32> v400 = v399;	// L536
    ap_int<32> v401 = v400 << (ap_int<32>)24;	// L537
    ap_int<32> v402 = v397 | v401;	// L538
    float v403 = v275[0][(v279 / 2)][(((v279 * 4) + ((v279 / 2) * -8)) + 3)][1];	// L539
    bool v404 = v403 != (float)0.000000;	// L540
    ap_int<32> v405 = v404;	// L541
    ap_int<32> v406 = v405 << (ap_int<32>)25;	// L542
    ap_int<32> v407 = v402 | v406;	// L543
    float v408 = v275[0][(v279 / 2)][(((v279 * 4) + ((v279 / 2) * -8)) + 3)][2];	// L544
    bool v409 = v408 != (float)0.000000;	// L545
    ap_int<32> v410 = v409;	// L546
    ap_int<32> v411 = v410 << (ap_int<32>)26;	// L547
    ap_int<32> v412 = v407 | v411;	// L548
    float v413 = v275[0][(v279 / 2)][(((v279 * 4) + ((v279 / 2) * -8)) + 3)][3];	// L549
    bool v414 = v413 != (float)0.000000;	// L550
    ap_int<32> v415 = v414;	// L551
    ap_int<32> v416 = v415 << (ap_int<32>)27;	// L552
    ap_int<32> v417 = v412 | v416;	// L553
    float v418 = v275[0][(v279 / 2)][(((v279 * 4) + ((v279 / 2) * -8)) + 3)][4];	// L554
    bool v419 = v418 != (float)0.000000;	// L555
    ap_int<32> v420 = v419;	// L556
    ap_int<32> v421 = v420 << (ap_int<32>)28;	// L557
    ap_int<32> v422 = v417 | v421;	// L558
    float v423 = v275[0][(v279 / 2)][(((v279 * 4) + ((v279 / 2) * -8)) + 3)][5];	// L559
    bool v424 = v423 != (float)0.000000;	// L560
    ap_int<32> v425 = v424;	// L561
    ap_int<32> v426 = v425 << (ap_int<32>)29;	// L562
    ap_int<32> v427 = v422 | v426;	// L563
    float v428 = v275[0][(v279 / 2)][(((v279 * 4) + ((v279 / 2) * -8)) + 3)][6];	// L564
    bool v429 = v428 != (float)0.000000;	// L565
    ap_int<32> v430 = v429;	// L566
    ap_int<32> v431 = v430 << (ap_int<32>)30;	// L567
    ap_int<32> v432 = v427 | v431;	// L568
    float v433 = v275[0][(v279 / 2)][(((v279 * 4) + ((v279 / 2) * -8)) + 3)][7];	// L569
    bool v434 = v433 != (float)0.000000;	// L570
    ap_int<32> v435 = v434;	// L571
    ap_int<32> v436 = v435 << (ap_int<32>)31;	// L572
    ap_int<32> v437 = v432 | v436;	// L573
    v278[v279] = v437;	// L574
  }
  auto v438 = reinterpret_cast<float(*)[384][1][1]>(v276);	// L577

  for (int v439 = 0; v439 < 384; v439 += 1) {	// L578
    for (int v440 = 0; v440 < 1536; v440 += 1) {	// L579
      float v441 = v438[v440][v439][0][0];	// L580
      for (int v442 = 0; v442 < 8; v442 += 1) {	// L581
        for (int v443 = 0; v443 < 8; v443 += 1) {	// L582
          #pragma HLS pipeline II=1
          #pragma HLS dependence false variable=v277
          #pragma HLS dependence false variable=v278
          ap_int<32> v444 = v278[((v439 * 2) + (v442 / 4))];	// L583
          int v445 = ((((v439 * 64) + (v442 * 8)) + v443) % 32);	// L584
          ap_int<32> v446 = v445;	// L585
          ap_int<32> v447 = v444 >> v446;	// L586
          ap_int<32> v448 = v447 & (ap_int<32>)1;	// L587
          bool v449 = v448 != (ap_int<32>)0;	// L588
          float v450 = v277[0][v440][v442][v443];	// L589
          float v451 = v450 + v441;	// L590
          float v452 = v449 ? v451 : v450;	// L591
          v277[0][v440][v442][v443] = v452;	// L592
        }
      }
    }
  }
}

void kernel15(
  float v453[1536],
  float v454[1][1536][8][8]
) {	// L599
  float v455[1536];	// L600
  #pragma HLS resource variable=v455 core=ram_t2p_bram

  memcpy(v455, v453, 1536 * sizeof(float));	// L601

  for (int v456 = 0; v456 < 1536; v456 += 1) {	// L602
    for (int v457 = 0; v457 < 8; v457 += 1) {	// L603
      for (int v458 = 0; v458 < 8; v458 += 1) {	// L604
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v455
        #pragma HLS dependence false variable=v454
        float v459 = v455[v456];	// L605
        v454[0][v456][v457][v458] = v459;	// L606
      }
    }
  }
}

void kernel16(
  float v460[1][384][8][8],
  float v461[1][384][8][8]
) {	// L612
  for (int v462 = 0; v462 < 384; v462 += 1) {	// L613
    for (int v463 = 0; v463 < 8; v463 += 1) {	// L614
      for (int v464 = 0; v464 < 8; v464 += 1) {	// L615
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v460
        #pragma HLS dependence false variable=v461
        float v465 = v460[0][v462][v463][v464];	// L616
        v461[0][v462][v463][v464] = v465;	// L617
      }
    }
  }
}

void kernel17(
  float v466[1][384][8][8],
  float v467[1][384][8][8],
  float v468
) {	// L623
  for (int v469 = 0; v469 < 384; v469 += 1) {	// L625
    for (int v470 = 0; v470 < 8; v470 += 1) {	// L626
      for (int v471 = 0; v471 < 8; v471 += 1) {	// L627
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v467
        #pragma HLS dependence false variable=v466
        float v472 = v467[0][v469][v470][v471];	// L628
        float v473 = v466[0][v469][v470][v471];	// L629
        float v474 = v473 * v472;	// L630
        float v475 = v472 - v474;	// L631
        bool v476 = v473 != (float)0.000000;	// L632
        float v477 = v475 + v468;	// L633
        float v478 = v476 ? v477 : v475;	// L634
        v467[0][v469][v470][v471] = v478;	// L635
      }
    }
  }
}

void kernel18(
  float v479[1][384][8][8],
  float v480,
  float v481
) {	// L641
  for (int v482 = 0; v482 < 384; v482 += 1) {	// L642
    for (int v483 = 0; v483 < 8; v483 += 1) {	// L643
      for (int v484 = 0; v484 < 8; v484 += 1) {	// L644
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v479
        float v485 = v479[0][v482][v483][v484];	// L645
        float v486 = v485 - v481;	// L646
        bool v487 = v486 >= v480;	// L647
        float v488 = v487 ? v481 : v480;	// L648
        v479[0][v482][v483][v484] = v488;	// L649
      }
    }
  }
}

void kernel20(
  float v489[1][384][8][8],
  float v490[1][384][8][8],
  float v491[1][384][8][8],
  float v492
) {	// L655
  for (int v493 = 0; v493 < 384; v493 += 1) {	// L656
    for (int v494 = 0; v494 < 8; v494 += 1) {	// L657
      for (int v495 = 0; v495 < 8; v495 += 1) {	// L658
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v489
        #pragma HLS dependence false variable=v491
        #pragma HLS dependence false variable=v490
        float v496 = v489[0][v493][v494][v495];	// L659
        float v497 = v490[0][v493][v494][v495];	// L660
        float v498 = v497 / v492;	// L661
        float v499 = v496 / v492;	// L662
        float v500 = v496 - v499;	// L663
        float v501 = v500 + v498;	// L664
        v491[0][v493][v494][v495] = v501;	// L665
      }
    }
  }
}

void kernel21(
  float v502[1][384][64],
  float v503[1][384][8][8],
  float v504[1][384][8][8]
) {	// L671
  for (int v505 = 0; v505 < 384; v505 += 1) {	// L672
    for (int v506 = 0; v506 < 8; v506 += 1) {	// L673
      for (int v507 = 0; v507 < 8; v507 += 1) {	// L674
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v503
        #pragma HLS dependence false variable=v504
        #pragma HLS dependence false variable=v502
        float v508 = v503[0][v505][v506][v507];	// L675
        float v509 = v502[0][v505][((v506 * 8) + v507)];	// L676
        float v510 = v508 + v509;	// L677
        v504[0][v505][v506][v507] = v510;	// L678
      }
    }
  }
}

void kernel22(
  float v511[1][384][64],
  float v512[384][384][1],
  float v513[1][384][64]
) {	// L684
  ap_int<32> v514[768];	// L718
  #pragma HLS resource variable=v514 core=ram_t2p_bram

  for (int v515 = 0; v515 < 768; v515 += 1) {	// L719
    float v516 = v511[0][(v515 / 2)][((v515 * 32) + ((v515 / 2) * -64))];	// L720
    bool v517 = v516 != (float)0.000000;	// L721
    ap_int<32> v518 = v517;	// L722
    float v519 = v511[0][(v515 / 2)][(((v515 * 32) + ((v515 / 2) * -64)) + 1)];	// L723
    bool v520 = v519 != (float)0.000000;	// L724
    ap_int<32> v521 = v520;	// L725
    ap_int<32> v522 = v521 << (ap_int<32>)1;	// L726
    ap_int<32> v523 = v518 | v522;	// L727
    float v524 = v511[0][(v515 / 2)][(((v515 * 32) + ((v515 / 2) * -64)) + 2)];	// L728
    bool v525 = v524 != (float)0.000000;	// L729
    ap_int<32> v526 = v525;	// L730
    ap_int<32> v527 = v526 << (ap_int<32>)2;	// L731
    ap_int<32> v528 = v523 | v527;	// L732
    float v529 = v511[0][(v515 / 2)][(((v515 * 32) + ((v515 / 2) * -64)) + 3)];	// L733
    bool v530 = v529 != (float)0.000000;	// L734
    ap_int<32> v531 = v530;	// L735
    ap_int<32> v532 = v531 << (ap_int<32>)3;	// L736
    ap_int<32> v533 = v528 | v532;	// L737
    float v534 = v511[0][(v515 / 2)][(((v515 * 32) + ((v515 / 2) * -64)) + 4)];	// L738
    bool v535 = v534 != (float)0.000000;	// L739
    ap_int<32> v536 = v535;	// L740
    ap_int<32> v537 = v536 << (ap_int<32>)4;	// L741
    ap_int<32> v538 = v533 | v537;	// L742
    float v539 = v511[0][(v515 / 2)][(((v515 * 32) + ((v515 / 2) * -64)) + 5)];	// L743
    bool v540 = v539 != (float)0.000000;	// L744
    ap_int<32> v541 = v540;	// L745
    ap_int<32> v542 = v541 << (ap_int<32>)5;	// L746
    ap_int<32> v543 = v538 | v542;	// L747
    float v544 = v511[0][(v515 / 2)][(((v515 * 32) + ((v515 / 2) * -64)) + 6)];	// L748
    bool v545 = v544 != (float)0.000000;	// L749
    ap_int<32> v546 = v545;	// L750
    ap_int<32> v547 = v546 << (ap_int<32>)6;	// L751
    ap_int<32> v548 = v543 | v547;	// L752
    float v549 = v511[0][(v515 / 2)][(((v515 * 32) + ((v515 / 2) * -64)) + 7)];	// L753
    bool v550 = v549 != (float)0.000000;	// L754
    ap_int<32> v551 = v550;	// L755
    ap_int<32> v552 = v551 << (ap_int<32>)7;	// L756
    ap_int<32> v553 = v548 | v552;	// L757
    float v554 = v511[0][(v515 / 2)][(((v515 * 32) + ((v515 / 2) * -64)) + 8)];	// L758
    bool v555 = v554 != (float)0.000000;	// L759
    ap_int<32> v556 = v555;	// L760
    ap_int<32> v557 = v556 << (ap_int<32>)8;	// L761
    ap_int<32> v558 = v553 | v557;	// L762
    float v559 = v511[0][(v515 / 2)][(((v515 * 32) + ((v515 / 2) * -64)) + 9)];	// L763
    bool v560 = v559 != (float)0.000000;	// L764
    ap_int<32> v561 = v560;	// L765
    ap_int<32> v562 = v561 << (ap_int<32>)9;	// L766
    ap_int<32> v563 = v558 | v562;	// L767
    float v564 = v511[0][(v515 / 2)][(((v515 * 32) + ((v515 / 2) * -64)) + 10)];	// L768
    bool v565 = v564 != (float)0.000000;	// L769
    ap_int<32> v566 = v565;	// L770
    ap_int<32> v567 = v566 << (ap_int<32>)10;	// L771
    ap_int<32> v568 = v563 | v567;	// L772
    float v569 = v511[0][(v515 / 2)][(((v515 * 32) + ((v515 / 2) * -64)) + 11)];	// L773
    bool v570 = v569 != (float)0.000000;	// L774
    ap_int<32> v571 = v570;	// L775
    ap_int<32> v572 = v571 << (ap_int<32>)11;	// L776
    ap_int<32> v573 = v568 | v572;	// L777
    float v574 = v511[0][(v515 / 2)][(((v515 * 32) + ((v515 / 2) * -64)) + 12)];	// L778
    bool v575 = v574 != (float)0.000000;	// L779
    ap_int<32> v576 = v575;	// L780
    ap_int<32> v577 = v576 << (ap_int<32>)12;	// L781
    ap_int<32> v578 = v573 | v577;	// L782
    float v579 = v511[0][(v515 / 2)][(((v515 * 32) + ((v515 / 2) * -64)) + 13)];	// L783
    bool v580 = v579 != (float)0.000000;	// L784
    ap_int<32> v581 = v580;	// L785
    ap_int<32> v582 = v581 << (ap_int<32>)13;	// L786
    ap_int<32> v583 = v578 | v582;	// L787
    float v584 = v511[0][(v515 / 2)][(((v515 * 32) + ((v515 / 2) * -64)) + 14)];	// L788
    bool v585 = v584 != (float)0.000000;	// L789
    ap_int<32> v586 = v585;	// L790
    ap_int<32> v587 = v586 << (ap_int<32>)14;	// L791
    ap_int<32> v588 = v583 | v587;	// L792
    float v589 = v511[0][(v515 / 2)][(((v515 * 32) + ((v515 / 2) * -64)) + 15)];	// L793
    bool v590 = v589 != (float)0.000000;	// L794
    ap_int<32> v591 = v590;	// L795
    ap_int<32> v592 = v591 << (ap_int<32>)15;	// L796
    ap_int<32> v593 = v588 | v592;	// L797
    float v594 = v511[0][(v515 / 2)][(((v515 * 32) + ((v515 / 2) * -64)) + 16)];	// L798
    bool v595 = v594 != (float)0.000000;	// L799
    ap_int<32> v596 = v595;	// L800
    ap_int<32> v597 = v596 << (ap_int<32>)16;	// L801
    ap_int<32> v598 = v593 | v597;	// L802
    float v599 = v511[0][(v515 / 2)][(((v515 * 32) + ((v515 / 2) * -64)) + 17)];	// L803
    bool v600 = v599 != (float)0.000000;	// L804
    ap_int<32> v601 = v600;	// L805
    ap_int<32> v602 = v601 << (ap_int<32>)17;	// L806
    ap_int<32> v603 = v598 | v602;	// L807
    float v604 = v511[0][(v515 / 2)][(((v515 * 32) + ((v515 / 2) * -64)) + 18)];	// L808
    bool v605 = v604 != (float)0.000000;	// L809
    ap_int<32> v606 = v605;	// L810
    ap_int<32> v607 = v606 << (ap_int<32>)18;	// L811
    ap_int<32> v608 = v603 | v607;	// L812
    float v609 = v511[0][(v515 / 2)][(((v515 * 32) + ((v515 / 2) * -64)) + 19)];	// L813
    bool v610 = v609 != (float)0.000000;	// L814
    ap_int<32> v611 = v610;	// L815
    ap_int<32> v612 = v611 << (ap_int<32>)19;	// L816
    ap_int<32> v613 = v608 | v612;	// L817
    float v614 = v511[0][(v515 / 2)][(((v515 * 32) + ((v515 / 2) * -64)) + 20)];	// L818
    bool v615 = v614 != (float)0.000000;	// L819
    ap_int<32> v616 = v615;	// L820
    ap_int<32> v617 = v616 << (ap_int<32>)20;	// L821
    ap_int<32> v618 = v613 | v617;	// L822
    float v619 = v511[0][(v515 / 2)][(((v515 * 32) + ((v515 / 2) * -64)) + 21)];	// L823
    bool v620 = v619 != (float)0.000000;	// L824
    ap_int<32> v621 = v620;	// L825
    ap_int<32> v622 = v621 << (ap_int<32>)21;	// L826
    ap_int<32> v623 = v618 | v622;	// L827
    float v624 = v511[0][(v515 / 2)][(((v515 * 32) + ((v515 / 2) * -64)) + 22)];	// L828
    bool v625 = v624 != (float)0.000000;	// L829
    ap_int<32> v626 = v625;	// L830
    ap_int<32> v627 = v626 << (ap_int<32>)22;	// L831
    ap_int<32> v628 = v623 | v627;	// L832
    float v629 = v511[0][(v515 / 2)][(((v515 * 32) + ((v515 / 2) * -64)) + 23)];	// L833
    bool v630 = v629 != (float)0.000000;	// L834
    ap_int<32> v631 = v630;	// L835
    ap_int<32> v632 = v631 << (ap_int<32>)23;	// L836
    ap_int<32> v633 = v628 | v632;	// L837
    float v634 = v511[0][(v515 / 2)][(((v515 * 32) + ((v515 / 2) * -64)) + 24)];	// L838
    bool v635 = v634 != (float)0.000000;	// L839
    ap_int<32> v636 = v635;	// L840
    ap_int<32> v637 = v636 << (ap_int<32>)24;	// L841
    ap_int<32> v638 = v633 | v637;	// L842
    float v639 = v511[0][(v515 / 2)][(((v515 * 32) + ((v515 / 2) * -64)) + 25)];	// L843
    bool v640 = v639 != (float)0.000000;	// L844
    ap_int<32> v641 = v640;	// L845
    ap_int<32> v642 = v641 << (ap_int<32>)25;	// L846
    ap_int<32> v643 = v638 | v642;	// L847
    float v644 = v511[0][(v515 / 2)][(((v515 * 32) + ((v515 / 2) * -64)) + 26)];	// L848
    bool v645 = v644 != (float)0.000000;	// L849
    ap_int<32> v646 = v645;	// L850
    ap_int<32> v647 = v646 << (ap_int<32>)26;	// L851
    ap_int<32> v648 = v643 | v647;	// L852
    float v649 = v511[0][(v515 / 2)][(((v515 * 32) + ((v515 / 2) * -64)) + 27)];	// L853
    bool v650 = v649 != (float)0.000000;	// L854
    ap_int<32> v651 = v650;	// L855
    ap_int<32> v652 = v651 << (ap_int<32>)27;	// L856
    ap_int<32> v653 = v648 | v652;	// L857
    float v654 = v511[0][(v515 / 2)][(((v515 * 32) + ((v515 / 2) * -64)) + 28)];	// L858
    bool v655 = v654 != (float)0.000000;	// L859
    ap_int<32> v656 = v655;	// L860
    ap_int<32> v657 = v656 << (ap_int<32>)28;	// L861
    ap_int<32> v658 = v653 | v657;	// L862
    float v659 = v511[0][(v515 / 2)][(((v515 * 32) + ((v515 / 2) * -64)) + 29)];	// L863
    bool v660 = v659 != (float)0.000000;	// L864
    ap_int<32> v661 = v660;	// L865
    ap_int<32> v662 = v661 << (ap_int<32>)29;	// L866
    ap_int<32> v663 = v658 | v662;	// L867
    float v664 = v511[0][(v515 / 2)][(((v515 * 32) + ((v515 / 2) * -64)) + 30)];	// L868
    bool v665 = v664 != (float)0.000000;	// L869
    ap_int<32> v666 = v665;	// L870
    ap_int<32> v667 = v666 << (ap_int<32>)30;	// L871
    ap_int<32> v668 = v663 | v667;	// L872
    float v669 = v511[0][(v515 / 2)][(((v515 * 32) + ((v515 / 2) * -64)) + 31)];	// L873
    bool v670 = v669 != (float)0.000000;	// L874
    ap_int<32> v671 = v670;	// L875
    ap_int<32> v672 = v671 << (ap_int<32>)31;	// L876
    ap_int<32> v673 = v668 | v672;	// L877
    v514[v515] = v673;	// L878
  }
  float v674[1][384][64];	// L880
  #pragma HLS resource variable=v674 core=ram_t2p_bram

  memcpy(v674, v513, 24576 * sizeof(float));	// L881

  auto v675 = reinterpret_cast<float(*)[384][1]>(v512);	// L883

  for (int v676 = 0; v676 < 384; v676 += 1) {	// L884
    for (int v677 = 0; v677 < 384; v677 += 1) {	// L885
      float v678 = v675[v677][v676][0];	// L886
      for (int v679 = 0; v679 < 64; v679 += 1) {	// L887
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v514
        #pragma HLS dependence false variable=v674
        ap_int<32> v680 = v514[((v676 * 2) + (v679 / 32))];	// L888
        int v681 = (v679 % 32);	// L889
        ap_int<32> v682 = v681;	// L890
        ap_int<32> v683 = v680 >> v682;	// L891
        ap_int<32> v684 = v683 & (ap_int<32>)1;	// L892
        bool v685 = v684 != (ap_int<32>)0;	// L893
        float v686 = v674[0][v677][v679];	// L894
        float v687 = v686 + v678;	// L895
        float v688 = v685 ? v687 : v686;	// L896
        v674[0][v677][v679] = v688;	// L897
      }
    }
  }
  memcpy(v513, v674, 24576 * sizeof(float));	// L901

}

void kernel23(
  float v689[384],
  float v690[1][384][64]
) {	// L904
  float v691[384];	// L905
  #pragma HLS resource variable=v691 core=ram_t2p_bram

  memcpy(v691, v689, 384 * sizeof(float));	// L906

  for (int v692 = 0; v692 < 384; v692 += 1) {	// L907
    for (int v693 = 0; v693 < 64; v693 += 1) {	// L908
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v691
      #pragma HLS dependence false variable=v690
      float v694 = v691[v692];	// L909
      v690[0][v692][v693] = v694;	// L910
    }
  }
}

void kernel24(
  float v695[1][64][384],
  float v696[1][384][64]
) {	// L915
  for (int v697 = 0; v697 < 384; v697 += 1) {	// L916
    for (int v698 = 0; v698 < 64; v698 += 1) {	// L917
      float v699 = v695[0][v698][v697];	// L918
      v696[0][v697][v698] = v699;	// L919
    }
  }
}

void kernel25(
  float v700[1][64][384],
  float v701[1][64][384]
) {	// L924
  for (int v702 = 0; v702 < 64; v702 += 1) {	// L925
    for (int v703 = 0; v703 < 384; v703 += 1) {	// L926
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v700
      #pragma HLS dependence false variable=v701
      float v704 = v700[0][v702][v703];	// L927
      v701[0][v702][v703] = v704;	// L928
    }
  }
}

void kernel26(
  float v705[1][64][12][32],
  float v706[1][64][384],
  float v707[1][64][384],
  float v708
) {	// L933
  for (int v709 = 0; v709 < 64; v709 += 1) {	// L935
    for (int v710 = 0; v710 < 384; v710 += 1) {	// L936
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v705
      #pragma HLS dependence false variable=v707
      #pragma HLS dependence false variable=v706
      float v711 = v705[0][v709][(v710 / 32)][(v710 % 32)];	// L937
      float v712 = v706[0][v709][v710];	// L938
      float v713 = v712 * v711;	// L939
      float v714 = v711 - v713;	// L940
      bool v715 = v712 != (float)0.000000;	// L941
      float v716 = v714 + v708;	// L942
      float v717 = v715 ? v716 : v714;	// L943
      v707[0][v709][v710] = v717;	// L944
    }
  }
}

void kernel27(
  float v718[1][64][384],
  float v719,
  float v720,
  float v721
) {	// L949
  for (int v722 = 0; v722 < 64; v722 += 1) {	// L950
    for (int v723 = 0; v723 < 384; v723 += 1) {	// L951
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v718
      float v724 = v718[0][v722][v723];	// L952
      float v725 = v724 - v720;	// L953
      bool v726 = v725 >= v721;	// L954
      float v727 = v726 ? v719 : v721;	// L955
      v718[0][v722][v723] = v727;	// L956
    }
  }
}

void kernel28(
  float v728[1][64][12][32],
  float v729[1][64][384]
) {	// L961
  for (int v730 = 0; v730 < 64; v730 += 1) {	// L962
    for (int v731 = 0; v731 < 384; v731 += 1) {	// L963
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v728
      #pragma HLS dependence false variable=v729
      float v732 = v728[0][v730][(v731 / 32)][(v731 % 32)];	// L964
      v729[0][v730][v731] = v732;	// L965
    }
  }
}

void kernel29(
  float v733[1][64][384],
  float v734[1][64][12][32],
  float v735[1][64][12][32],
  float v736
) {	// L970
  for (int v737 = 0; v737 < 64; v737 += 1) {	// L971
    for (int v738 = 0; v738 < 12; v738 += 1) {	// L972
      for (int v739 = 0; v739 < 32; v739 += 1) {	// L973
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v733
        #pragma HLS dependence false variable=v735
        #pragma HLS dependence false variable=v734
        float v740 = v733[0][v737][((v738 * 32) + v739)];	// L974
        float v741 = v734[0][v737][v738][v739];	// L975
        float v742 = v741 / v736;	// L976
        float v743 = v740 / v736;	// L977
        float v744 = v740 - v743;	// L978
        float v745 = v744 + v742;	// L979
        v735[0][v737][v738][v739] = v745;	// L980
      }
    }
  }
}

void kernel30(
  float v746[1][12][64][32],
  float v747[1][64][12][32]
) {	// L986
  for (int v748 = 0; v748 < 64; v748 += 1) {	// L987
    for (int v749 = 0; v749 < 12; v749 += 1) {	// L988
      for (int v750 = 0; v750 < 32; v750 += 1) {	// L989
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v746
        #pragma HLS dependence false variable=v747
        float v751 = v746[0][v749][v748][v750];	// L990
        v747[0][v748][v749][v750] = v751;	// L991
      }
    }
  }
}

void kernel31(
  float v752[1][12][64][32],
  float v753
) {	// L997
  for (int v754 = 0; v754 < 12; v754 += 1) {	// L998
    for (int v755 = 0; v755 < 64; v755 += 1) {	// L999
      for (int v756 = 0; v756 < 32; v756 += 1) {	// L1000
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v752
        float v757 = v752[0][v754][v755][v756];	// L1001
        float v758 = v757 * v753;	// L1002
        v752[0][v754][v755][v756] = v758;	// L1003
      }
    }
  }
}

void kernel32(
  float v759[12][64][32],
  float v760[1][12][64][32]
) {	// L1009
  for (int v761 = 0; v761 < 12; v761 += 1) {	// L1010
    for (int v762 = 0; v762 < 64; v762 += 1) {	// L1011
      for (int v763 = 0; v763 < 32; v763 += 1) {	// L1012
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v759
        #pragma HLS dependence false variable=v760
        float v764 = v759[v761][v762][v763];	// L1013
        v760[0][v761][v762][v763] = v764;	// L1014
      }
    }
  }
}

void kernel33(
  float v765[1][1][12][64][32],
  float v766[12][64][64],
  float v767[12][64][32]
) {	// L1020
  float v768[1][1][12][64][32];	// L1021
  #pragma HLS resource variable=v768 core=ram_t2p_bram

  memcpy(v768, v765, 24576 * sizeof(float));	// L1022

  float v769[12][64][32];	// L1023
  #pragma HLS resource variable=v769 core=ram_t2p_bram

  memcpy(v769, v767, 24576 * sizeof(float));	// L1024

  auto v770 = reinterpret_cast<float(*)[64][64]>(v766);	// L1026

  for (int v771 = 0; v771 < 64; v771 += 1) {	// L1027
    for (int v772 = 0; v772 < 12; v772 += 1) {	// L1028
      for (int v773 = 0; v773 < 64; v773 += 1) {	// L1029
        float v774 = v770[v772][v773][v771];	// L1030
        for (int v775 = 0; v775 < 32; v775 += 1) {	// L1031
          #pragma HLS pipeline II=1
          #pragma HLS dependence false variable=v768
          #pragma HLS dependence false variable=v769
          float v776 = v768[0][0][v772][v771][v775];	// L1032
          float v777 = v769[v772][v773][v775];	// L1033
          float v778 = v774 * v776;	// L1034
          float v779 = v777 + v778;	// L1035
          v769[v772][v773][v775] = v779;	// L1036
        }
      }
    }
  }
  memcpy(v767, v769, 24576 * sizeof(float));	// L1041

}

void kernel34(
  float v780[12][64][32],
  float v781
) {	// L1044
  for (int v782 = 0; v782 < 12; v782 += 1) {	// L1045
    for (int v783 = 0; v783 < 64; v783 += 1) {	// L1046
      for (int v784 = 0; v784 < 32; v784 += 1) {	// L1047
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v780
        v780[v782][v783][v784] = v781;	// L1048
      }
    }
  }
}

void kernel35(
  float v785[1][12][64][32],
  float v786[1][1][12][64][32]
) {	// L1054
  for (int v787 = 0; v787 < 12; v787 += 1) {	// L1055
    for (int v788 = 0; v788 < 64; v788 += 1) {	// L1056
      for (int v789 = 0; v789 < 32; v789 += 1) {	// L1057
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v785
        #pragma HLS dependence false variable=v786
        float v790 = v785[0][v787][v788][v789];	// L1058
        v786[0][0][v787][v788][v789] = v790;	// L1059
      }
    }
  }
}

void kernel36(
  float v791[1][1][12][64][32],
  float v792[1][1][12][32][64],
  float v793[12][64][64]
) {	// L1065
  float v794[1][1][12][32][64];	// L1066
  #pragma HLS resource variable=v794 core=ram_t2p_bram

  memcpy(v794, v792, 24576 * sizeof(float));	// L1067

  auto v795 = reinterpret_cast<float(*)[1][12][64][32]>(v791);	// L1069

  for (int v796 = 0; v796 < 32; v796 += 1) {	// L1070
    for (int v797 = 0; v797 < 12; v797 += 1) {	// L1071
      for (int v798 = 0; v798 < 64; v798 += 1) {	// L1072
        float v799 = v795[0][0][v797][v798][v796];	// L1073
        for (int v800 = 0; v800 < 64; v800 += 1) {	// L1074
          #pragma HLS pipeline II=1
          #pragma HLS dependence false variable=v794
          #pragma HLS dependence false variable=v793
          float v801 = v794[0][0][v797][v796][v800];	// L1075
          float v802 = v793[v797][v798][v800];	// L1076
          float v803 = v799 * v801;	// L1077
          float v804 = v802 + v803;	// L1078
          v793[v797][v798][v800] = v804;	// L1079
        }
      }
    }
  }
}

void kernel37(
  float v805[1][12][32][64],
  float v806[1][1][12][32][64]
) {	// L1086
  for (int v807 = 0; v807 < 12; v807 += 1) {	// L1087
    for (int v808 = 0; v808 < 32; v808 += 1) {	// L1088
      for (int v809 = 0; v809 < 64; v809 += 1) {	// L1089
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v805
        #pragma HLS dependence false variable=v806
        float v810 = v805[0][v807][v808][v809];	// L1090
        v806[0][0][v807][v808][v809] = v810;	// L1091
      }
    }
  }
}

void kernel39(
  float v811[1][64][12][32],
  float v812[1][12][32][64]
) {	// L1097
  for (int v813 = 0; v813 < 12; v813 += 1) {	// L1098
    for (int v814 = 0; v814 < 32; v814 += 1) {	// L1099
      for (int v815 = 0; v815 < 64; v815 += 1) {	// L1100
        float v816 = v811[0][v815][v813][v814];	// L1101
        v812[0][v813][v814][v815] = v816;	// L1102
      }
    }
  }
}

void kernel40(
  float v817[1][64][12][32],
  float v818[1][12][64][32]
) {	// L1108
  for (int v819 = 0; v819 < 12; v819 += 1) {	// L1109
    for (int v820 = 0; v820 < 64; v820 += 1) {	// L1110
      for (int v821 = 0; v821 < 32; v821 += 1) {	// L1111
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v817
        #pragma HLS dependence false variable=v818
        float v822 = v817[0][v820][v819][v821];	// L1112
        v818[0][v819][v820][v821] = v822;	// L1113
      }
    }
  }
}

void kernel41(
  float v823[1][384][64],
  float v824[1][64][12][32]
) {	// L1119
  for (int v825 = 0; v825 < 64; v825 += 1) {	// L1120
    for (int v826 = 0; v826 < 12; v826 += 1) {	// L1121
      for (int v827 = 0; v827 < 32; v827 += 1) {	// L1122
        float v828 = v823[0][((v826 * 32) + v827)][v825];	// L1123
        v824[0][v825][v826][v827] = v828;	// L1124
      }
    }
  }
}

void kernel42(
  float v829[1][384][64],
  float v830[1][384][64]
) {	// L1130
  for (int v831 = 0; v831 < 384; v831 += 1) {	// L1131
    for (int v832 = 0; v832 < 64; v832 += 1) {	// L1132
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v829
      #pragma HLS dependence false variable=v830
      float v833 = v829[0][v831][v832];	// L1133
      v830[0][v831][v832] = v833;	// L1134
    }
  }
}

void kernel43(
  float v834[1][384][64],
  float v835[1][384][64],
  float v836
) {	// L1139
  for (int v837 = 0; v837 < 384; v837 += 1) {	// L1141
    for (int v838 = 0; v838 < 64; v838 += 1) {	// L1142
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v835
      #pragma HLS dependence false variable=v834
      float v839 = v835[0][v837][v838];	// L1143
      float v840 = v834[0][v837][v838];	// L1144
      float v841 = v840 * v839;	// L1145
      float v842 = v839 - v841;	// L1146
      bool v843 = v840 != (float)0.000000;	// L1147
      float v844 = v842 + v836;	// L1148
      float v845 = v843 ? v844 : v842;	// L1149
      v835[0][v837][v838] = v845;	// L1150
    }
  }
}

void kernel44(
  float v846[1][384][64],
  float v847,
  float v848
) {	// L1155
  for (int v849 = 0; v849 < 384; v849 += 1) {	// L1156
    for (int v850 = 0; v850 < 64; v850 += 1) {	// L1157
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v846
      float v851 = v846[0][v849][v850];	// L1158
      float v852 = v851 - v848;	// L1159
      bool v853 = v852 >= v847;	// L1160
      float v854 = v853 ? v848 : v847;	// L1161
      v846[0][v849][v850] = v854;	// L1162
    }
  }
}

void kernel46(
  float v855[1][384][64],
  float v856[1][384][64],
  float v857
) {	// L1167
  for (int v858 = 0; v858 < 384; v858 += 1) {	// L1168
    for (int v859 = 0; v859 < 64; v859 += 1) {	// L1169
      #pragma HLS pipeline II=1
      #pragma HLS dependence false variable=v855
      #pragma HLS dependence false variable=v856
      float v860 = v855[0][v858][v859];	// L1170
      float v861 = v856[0][v858][v859];	// L1171
      float v862 = v861 / v857;	// L1172
      float v863 = v860 / v857;	// L1173
      float v864 = v860 - v863;	// L1174
      float v865 = v864 + v862;	// L1175
      v856[0][v858][v859] = v865;	// L1176
    }
  }
}

void kernel47(
  float v866[1][384][8][8],
  float v867[384][384][1],
  float v868[1][384][64]
) {	// L1181
  ap_int<32> v869[768];	// L1215
  #pragma HLS resource variable=v869 core=ram_t2p_bram

  for (int v870 = 0; v870 < 768; v870 += 1) {	// L1216
    float v871 = v866[0][(v870 / 2)][((v870 * 4) + ((v870 / 2) * -8))][0];	// L1217
    bool v872 = v871 != (float)0.000000;	// L1218
    ap_int<32> v873 = v872;	// L1219
    float v874 = v866[0][(v870 / 2)][((v870 * 4) + ((v870 / 2) * -8))][1];	// L1220
    bool v875 = v874 != (float)0.000000;	// L1221
    ap_int<32> v876 = v875;	// L1222
    ap_int<32> v877 = v876 << (ap_int<32>)1;	// L1223
    ap_int<32> v878 = v873 | v877;	// L1224
    float v879 = v866[0][(v870 / 2)][((v870 * 4) + ((v870 / 2) * -8))][2];	// L1225
    bool v880 = v879 != (float)0.000000;	// L1226
    ap_int<32> v881 = v880;	// L1227
    ap_int<32> v882 = v881 << (ap_int<32>)2;	// L1228
    ap_int<32> v883 = v878 | v882;	// L1229
    float v884 = v866[0][(v870 / 2)][((v870 * 4) + ((v870 / 2) * -8))][3];	// L1230
    bool v885 = v884 != (float)0.000000;	// L1231
    ap_int<32> v886 = v885;	// L1232
    ap_int<32> v887 = v886 << (ap_int<32>)3;	// L1233
    ap_int<32> v888 = v883 | v887;	// L1234
    float v889 = v866[0][(v870 / 2)][((v870 * 4) + ((v870 / 2) * -8))][4];	// L1235
    bool v890 = v889 != (float)0.000000;	// L1236
    ap_int<32> v891 = v890;	// L1237
    ap_int<32> v892 = v891 << (ap_int<32>)4;	// L1238
    ap_int<32> v893 = v888 | v892;	// L1239
    float v894 = v866[0][(v870 / 2)][((v870 * 4) + ((v870 / 2) * -8))][5];	// L1240
    bool v895 = v894 != (float)0.000000;	// L1241
    ap_int<32> v896 = v895;	// L1242
    ap_int<32> v897 = v896 << (ap_int<32>)5;	// L1243
    ap_int<32> v898 = v893 | v897;	// L1244
    float v899 = v866[0][(v870 / 2)][((v870 * 4) + ((v870 / 2) * -8))][6];	// L1245
    bool v900 = v899 != (float)0.000000;	// L1246
    ap_int<32> v901 = v900;	// L1247
    ap_int<32> v902 = v901 << (ap_int<32>)6;	// L1248
    ap_int<32> v903 = v898 | v902;	// L1249
    float v904 = v866[0][(v870 / 2)][((v870 * 4) + ((v870 / 2) * -8))][7];	// L1250
    bool v905 = v904 != (float)0.000000;	// L1251
    ap_int<32> v906 = v905;	// L1252
    ap_int<32> v907 = v906 << (ap_int<32>)7;	// L1253
    ap_int<32> v908 = v903 | v907;	// L1254
    float v909 = v866[0][(v870 / 2)][(((v870 * 4) + ((v870 / 2) * -8)) + 1)][0];	// L1255
    bool v910 = v909 != (float)0.000000;	// L1256
    ap_int<32> v911 = v910;	// L1257
    ap_int<32> v912 = v911 << (ap_int<32>)8;	// L1258
    ap_int<32> v913 = v908 | v912;	// L1259
    float v914 = v866[0][(v870 / 2)][(((v870 * 4) + ((v870 / 2) * -8)) + 1)][1];	// L1260
    bool v915 = v914 != (float)0.000000;	// L1261
    ap_int<32> v916 = v915;	// L1262
    ap_int<32> v917 = v916 << (ap_int<32>)9;	// L1263
    ap_int<32> v918 = v913 | v917;	// L1264
    float v919 = v866[0][(v870 / 2)][(((v870 * 4) + ((v870 / 2) * -8)) + 1)][2];	// L1265
    bool v920 = v919 != (float)0.000000;	// L1266
    ap_int<32> v921 = v920;	// L1267
    ap_int<32> v922 = v921 << (ap_int<32>)10;	// L1268
    ap_int<32> v923 = v918 | v922;	// L1269
    float v924 = v866[0][(v870 / 2)][(((v870 * 4) + ((v870 / 2) * -8)) + 1)][3];	// L1270
    bool v925 = v924 != (float)0.000000;	// L1271
    ap_int<32> v926 = v925;	// L1272
    ap_int<32> v927 = v926 << (ap_int<32>)11;	// L1273
    ap_int<32> v928 = v923 | v927;	// L1274
    float v929 = v866[0][(v870 / 2)][(((v870 * 4) + ((v870 / 2) * -8)) + 1)][4];	// L1275
    bool v930 = v929 != (float)0.000000;	// L1276
    ap_int<32> v931 = v930;	// L1277
    ap_int<32> v932 = v931 << (ap_int<32>)12;	// L1278
    ap_int<32> v933 = v928 | v932;	// L1279
    float v934 = v866[0][(v870 / 2)][(((v870 * 4) + ((v870 / 2) * -8)) + 1)][5];	// L1280
    bool v935 = v934 != (float)0.000000;	// L1281
    ap_int<32> v936 = v935;	// L1282
    ap_int<32> v937 = v936 << (ap_int<32>)13;	// L1283
    ap_int<32> v938 = v933 | v937;	// L1284
    float v939 = v866[0][(v870 / 2)][(((v870 * 4) + ((v870 / 2) * -8)) + 1)][6];	// L1285
    bool v940 = v939 != (float)0.000000;	// L1286
    ap_int<32> v941 = v940;	// L1287
    ap_int<32> v942 = v941 << (ap_int<32>)14;	// L1288
    ap_int<32> v943 = v938 | v942;	// L1289
    float v944 = v866[0][(v870 / 2)][(((v870 * 4) + ((v870 / 2) * -8)) + 1)][7];	// L1290
    bool v945 = v944 != (float)0.000000;	// L1291
    ap_int<32> v946 = v945;	// L1292
    ap_int<32> v947 = v946 << (ap_int<32>)15;	// L1293
    ap_int<32> v948 = v943 | v947;	// L1294
    float v949 = v866[0][(v870 / 2)][(((v870 * 4) + ((v870 / 2) * -8)) + 2)][0];	// L1295
    bool v950 = v949 != (float)0.000000;	// L1296
    ap_int<32> v951 = v950;	// L1297
    ap_int<32> v952 = v951 << (ap_int<32>)16;	// L1298
    ap_int<32> v953 = v948 | v952;	// L1299
    float v954 = v866[0][(v870 / 2)][(((v870 * 4) + ((v870 / 2) * -8)) + 2)][1];	// L1300
    bool v955 = v954 != (float)0.000000;	// L1301
    ap_int<32> v956 = v955;	// L1302
    ap_int<32> v957 = v956 << (ap_int<32>)17;	// L1303
    ap_int<32> v958 = v953 | v957;	// L1304
    float v959 = v866[0][(v870 / 2)][(((v870 * 4) + ((v870 / 2) * -8)) + 2)][2];	// L1305
    bool v960 = v959 != (float)0.000000;	// L1306
    ap_int<32> v961 = v960;	// L1307
    ap_int<32> v962 = v961 << (ap_int<32>)18;	// L1308
    ap_int<32> v963 = v958 | v962;	// L1309
    float v964 = v866[0][(v870 / 2)][(((v870 * 4) + ((v870 / 2) * -8)) + 2)][3];	// L1310
    bool v965 = v964 != (float)0.000000;	// L1311
    ap_int<32> v966 = v965;	// L1312
    ap_int<32> v967 = v966 << (ap_int<32>)19;	// L1313
    ap_int<32> v968 = v963 | v967;	// L1314
    float v969 = v866[0][(v870 / 2)][(((v870 * 4) + ((v870 / 2) * -8)) + 2)][4];	// L1315
    bool v970 = v969 != (float)0.000000;	// L1316
    ap_int<32> v971 = v970;	// L1317
    ap_int<32> v972 = v971 << (ap_int<32>)20;	// L1318
    ap_int<32> v973 = v968 | v972;	// L1319
    float v974 = v866[0][(v870 / 2)][(((v870 * 4) + ((v870 / 2) * -8)) + 2)][5];	// L1320
    bool v975 = v974 != (float)0.000000;	// L1321
    ap_int<32> v976 = v975;	// L1322
    ap_int<32> v977 = v976 << (ap_int<32>)21;	// L1323
    ap_int<32> v978 = v973 | v977;	// L1324
    float v979 = v866[0][(v870 / 2)][(((v870 * 4) + ((v870 / 2) * -8)) + 2)][6];	// L1325
    bool v980 = v979 != (float)0.000000;	// L1326
    ap_int<32> v981 = v980;	// L1327
    ap_int<32> v982 = v981 << (ap_int<32>)22;	// L1328
    ap_int<32> v983 = v978 | v982;	// L1329
    float v984 = v866[0][(v870 / 2)][(((v870 * 4) + ((v870 / 2) * -8)) + 2)][7];	// L1330
    bool v985 = v984 != (float)0.000000;	// L1331
    ap_int<32> v986 = v985;	// L1332
    ap_int<32> v987 = v986 << (ap_int<32>)23;	// L1333
    ap_int<32> v988 = v983 | v987;	// L1334
    float v989 = v866[0][(v870 / 2)][(((v870 * 4) + ((v870 / 2) * -8)) + 3)][0];	// L1335
    bool v990 = v989 != (float)0.000000;	// L1336
    ap_int<32> v991 = v990;	// L1337
    ap_int<32> v992 = v991 << (ap_int<32>)24;	// L1338
    ap_int<32> v993 = v988 | v992;	// L1339
    float v994 = v866[0][(v870 / 2)][(((v870 * 4) + ((v870 / 2) * -8)) + 3)][1];	// L1340
    bool v995 = v994 != (float)0.000000;	// L1341
    ap_int<32> v996 = v995;	// L1342
    ap_int<32> v997 = v996 << (ap_int<32>)25;	// L1343
    ap_int<32> v998 = v993 | v997;	// L1344
    float v999 = v866[0][(v870 / 2)][(((v870 * 4) + ((v870 / 2) * -8)) + 3)][2];	// L1345
    bool v1000 = v999 != (float)0.000000;	// L1346
    ap_int<32> v1001 = v1000;	// L1347
    ap_int<32> v1002 = v1001 << (ap_int<32>)26;	// L1348
    ap_int<32> v1003 = v998 | v1002;	// L1349
    float v1004 = v866[0][(v870 / 2)][(((v870 * 4) + ((v870 / 2) * -8)) + 3)][3];	// L1350
    bool v1005 = v1004 != (float)0.000000;	// L1351
    ap_int<32> v1006 = v1005;	// L1352
    ap_int<32> v1007 = v1006 << (ap_int<32>)27;	// L1353
    ap_int<32> v1008 = v1003 | v1007;	// L1354
    float v1009 = v866[0][(v870 / 2)][(((v870 * 4) + ((v870 / 2) * -8)) + 3)][4];	// L1355
    bool v1010 = v1009 != (float)0.000000;	// L1356
    ap_int<32> v1011 = v1010;	// L1357
    ap_int<32> v1012 = v1011 << (ap_int<32>)28;	// L1358
    ap_int<32> v1013 = v1008 | v1012;	// L1359
    float v1014 = v866[0][(v870 / 2)][(((v870 * 4) + ((v870 / 2) * -8)) + 3)][5];	// L1360
    bool v1015 = v1014 != (float)0.000000;	// L1361
    ap_int<32> v1016 = v1015;	// L1362
    ap_int<32> v1017 = v1016 << (ap_int<32>)29;	// L1363
    ap_int<32> v1018 = v1013 | v1017;	// L1364
    float v1019 = v866[0][(v870 / 2)][(((v870 * 4) + ((v870 / 2) * -8)) + 3)][6];	// L1365
    bool v1020 = v1019 != (float)0.000000;	// L1366
    ap_int<32> v1021 = v1020;	// L1367
    ap_int<32> v1022 = v1021 << (ap_int<32>)30;	// L1368
    ap_int<32> v1023 = v1018 | v1022;	// L1369
    float v1024 = v866[0][(v870 / 2)][(((v870 * 4) + ((v870 / 2) * -8)) + 3)][7];	// L1370
    bool v1025 = v1024 != (float)0.000000;	// L1371
    ap_int<32> v1026 = v1025;	// L1372
    ap_int<32> v1027 = v1026 << (ap_int<32>)31;	// L1373
    ap_int<32> v1028 = v1023 | v1027;	// L1374
    v869[v870] = v1028;	// L1375
  }
  float v1029[1][384][64];	// L1377
  #pragma HLS resource variable=v1029 core=ram_t2p_bram

  memcpy(v1029, v868, 24576 * sizeof(float));	// L1378

  auto v1030 = reinterpret_cast<float(*)[384][1]>(v867);	// L1380

  for (int v1031 = 0; v1031 < 384; v1031 += 1) {	// L1381
    for (int v1032 = 0; v1032 < 384; v1032 += 1) {	// L1382
      float v1033 = v1030[v1032][v1031][0];	// L1383
      for (int v1034 = 0; v1034 < 64; v1034 += 1) {	// L1384
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1029
        #pragma HLS dependence false variable=v869
        ap_int<32> v1035 = v869[((v1031 * 2) + (v1034 / 32))];	// L1385
        int v1036 = (v1034 % 32);	// L1386
        ap_int<32> v1037 = v1036;	// L1387
        ap_int<32> v1038 = v1035 >> v1037;	// L1388
        ap_int<32> v1039 = v1038 & (ap_int<32>)1;	// L1389
        bool v1040 = v1039 != (ap_int<32>)0;	// L1390
        float v1041 = v1029[0][v1032][v1034];	// L1391
        float v1042 = v1041 + v1033;	// L1392
        float v1043 = v1040 ? v1042 : v1041;	// L1393
        v1029[0][v1032][v1034] = v1043;	// L1394
      }
    }
  }
  memcpy(v868, v1029, 24576 * sizeof(float));	// L1398

}

void kernel71(
  float v1044[1][384][8][8],
  float v1045[1][384][8][8],
  float v1046[1][384][8][8]
) {	// L1401
  for (int v1047 = 0; v1047 < 384; v1047 += 1) {	// L1402
    for (int v1048 = 0; v1048 < 8; v1048 += 1) {	// L1403
      for (int v1049 = 0; v1049 < 8; v1049 += 1) {	// L1404
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1045
        #pragma HLS dependence false variable=v1046
        #pragma HLS dependence false variable=v1044
        float v1050 = v1045[0][v1047][v1048][v1049];	// L1405
        float v1051 = v1044[0][v1047][v1048][v1049];	// L1406
        float v1052 = v1050 + v1051;	// L1407
        v1046[0][v1047][v1048][v1049] = v1052;	// L1408
      }
    }
  }
}

void kernel99(
  float v1053[12][64][32],
  float v1054
) {	// L1414
  for (int v1055 = 0; v1055 < 12; v1055 += 1) {	// L1415
    for (int v1056 = 0; v1056 < 64; v1056 += 1) {	// L1416
      for (int v1057 = 0; v1057 < 32; v1057 += 1) {	// L1417
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1053
        v1053[v1055][v1056][v1057] = v1054;	// L1418
      }
    }
  }
}

void kernel102(
  float v1058[12][64][64],
  float v1059[12][64][64]
) {	// L1424
  for (int v1060 = 0; v1060 < 12; v1060 += 1) {	// L1425
    for (int v1061 = 0; v1061 < 64; v1061 += 1) {	// L1426
      for (int v1062 = 0; v1062 < 64; v1062 += 1) {	// L1427
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1058
        #pragma HLS dependence false variable=v1059
        float v1063 = v1058[v1060][v1061][v1062];	// L1428
        v1059[v1060][v1061][v1062] = v1063;	// L1429
      }
    }
  }
}

void kernel165(
  float v1064[12][64][32],
  float v1065
) {	// L1435
  for (int v1066 = 0; v1066 < 12; v1066 += 1) {	// L1436
    for (int v1067 = 0; v1067 < 64; v1067 += 1) {	// L1437
      for (int v1068 = 0; v1068 < 32; v1068 += 1) {	// L1438
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1064
        v1064[v1066][v1067][v1068] = v1065;	// L1439
      }
    }
  }
}

void kernel231(
  float v1069[12][64][32],
  float v1070
) {	// L1445
  for (int v1071 = 0; v1071 < 12; v1071 += 1) {	// L1446
    for (int v1072 = 0; v1072 < 64; v1072 += 1) {	// L1447
      for (int v1073 = 0; v1073 < 32; v1073 += 1) {	// L1448
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1069
        v1069[v1071][v1072][v1073] = v1070;	// L1449
      }
    }
  }
}

void kernel235(
  float v1074[12][64][64],
  float v1075
) {	// L1455
  for (int v1076 = 0; v1076 < 12; v1076 += 1) {	// L1456
    for (int v1077 = 0; v1077 < 64; v1077 += 1) {	// L1457
      for (int v1078 = 0; v1078 < 64; v1078 += 1) {	// L1458
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1074
        v1074[v1076][v1077][v1078] = v1075;	// L1459
      }
    }
  }
}

void kernel270(
  float v1079[1][384][10][10],
  float v1080[384][384][3][3],
  float v1081[1][384][8][8]
) {	// L1465
  float v1082[1][384][10][10];	// L1466
  #pragma HLS resource variable=v1082 core=ram_t2p_uram

  memcpy(v1082, v1079, 38400 * sizeof(float));	// L1467

  float v1083[1][384][8][8];	// L1468
  #pragma HLS resource variable=v1083 core=ram_t2p_bram

  memcpy(v1083, v1081, 24576 * sizeof(float));	// L1469

  auto v1084 = reinterpret_cast<float(*)[384][3][3]>(v1080);	// L1471

  for (int v1085 = 0; v1085 < 384; v1085 += 1) {	// L1472
    for (int v1086 = 0; v1086 < 3; v1086 += 1) {	// L1473
      for (int v1087 = 0; v1087 < 3; v1087 += 1) {	// L1474
        for (int v1088 = 0; v1088 < 384; v1088 += 1) {	// L1475
          float v1089 = v1084[v1088][v1085][v1086][v1087];	// L1476
          for (int v1090 = 0; v1090 < 8; v1090 += 1) {	// L1477
            for (int v1091 = 0; v1091 < 8; v1091 += 1) {	// L1478
              #pragma HLS pipeline II=1
              #pragma HLS dependence false variable=v1082
              #pragma HLS dependence false variable=v1083
              float v1092 = v1082[0][v1085][(v1090 + v1086)][(v1091 + v1087)];	// L1479
              float v1093 = v1083[0][v1088][v1090][v1091];	// L1480
              float v1094 = v1092 * v1089;	// L1481
              float v1095 = v1093 + v1094;	// L1482
              v1083[0][v1088][v1090][v1091] = v1095;	// L1483
            }
          }
        }
      }
    }
  }
  memcpy(v1081, v1083, 24576 * sizeof(float));	// L1490

}

void kernel272(
  float v1096[1][384][8][8],
  float v1097[1][384][10][10]
) {	// L1493
  for (int v1098 = 0; v1098 < 384; v1098 += 1) {	// L1494
    for (int v1099 = 0; v1099 < 8; v1099 += 1) {	// L1495
      for (int v1100 = 0; v1100 < 8; v1100 += 1) {	// L1496
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1096
        #pragma HLS dependence false variable=v1097
        float v1101 = v1096[0][v1098][v1099][v1100];	// L1497
        v1097[0][v1098][(v1099 + 1)][(v1100 + 1)] = v1101;	// L1498
      }
    }
  }
}

void kernel273(
  float v1102[1][384][10][10],
  float v1103
) {	// L1504
  for (int v1104 = 0; v1104 < 384; v1104 += 1) {	// L1505
    for (int v1105 = 0; v1105 < 10; v1105 += 1) {	// L1506
      for (int v1106 = 0; v1106 < 10; v1106 += 1) {	// L1507
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1102
        v1102[0][v1104][v1105][v1106] = v1103;	// L1508
      }
    }
  }
}

void kernel274(
  float v1107[1][384][18][18],
  float v1108[3][3],
  float v1109[1][384][8][8]
) {	// L1514
  for (int v1110 = 0; v1110 < 3; v1110 += 1) {	// L1515
    for (int v1111 = 0; v1111 < 3; v1111 += 1) {	// L1516
      for (int v1112 = 0; v1112 < 384; v1112 += 1) {	// L1517
        for (int v1113 = 0; v1113 < 8; v1113 += 1) {	// L1518
          for (int v1114 = 0; v1114 < 8; v1114 += 1) {	// L1519
            #pragma HLS pipeline II=1
            #pragma HLS dependence false variable=v1107
            #pragma HLS dependence false variable=v1109
            float v1115 = v1107[0][v1112][((v1113 * 2) + v1110)][((v1114 * 2) + v1111)];	// L1520
            float v1116 = v1109[0][v1112][v1113][v1114];	// L1521
            float v1117 = max(v1116, v1115);	// L1522
            v1109[0][v1112][v1113][v1114] = v1117;	// L1523
          }
        }
      }
    }
  }
}

void kernel275(
  float v1118[1][384][8][8],
  float v1119
) {	// L1531
  for (int v1120 = 0; v1120 < 384; v1120 += 1) {	// L1532
    for (int v1121 = 0; v1121 < 8; v1121 += 1) {	// L1533
      for (int v1122 = 0; v1122 < 8; v1122 += 1) {	// L1534
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1118
        v1118[0][v1120][v1121][v1122] = v1119;	// L1535
      }
    }
  }
}

void kernel276(
  float v1123[1][384][16][16],
  float v1124[1][384][18][18]
) {	// L1541
  ap_int<32> v1125[3072];	// L1574
  #pragma HLS resource variable=v1125 core=ram_t2p_bram

  for (int v1126 = 0; v1126 < 3072; v1126 += 1) {	// L1575
    float v1127 = v1123[0][(v1126 / 8)][((v1126 * 2) + ((v1126 / 8) * -16))][0];	// L1576
    bool v1128 = v1127 != (float)0.000000;	// L1577
    ap_int<32> v1129 = v1128;	// L1578
    float v1130 = v1123[0][(v1126 / 8)][((v1126 * 2) + ((v1126 / 8) * -16))][1];	// L1579
    bool v1131 = v1130 != (float)0.000000;	// L1580
    ap_int<32> v1132 = v1131;	// L1581
    ap_int<32> v1133 = v1132 << (ap_int<32>)1;	// L1582
    ap_int<32> v1134 = v1129 | v1133;	// L1583
    float v1135 = v1123[0][(v1126 / 8)][((v1126 * 2) + ((v1126 / 8) * -16))][2];	// L1584
    bool v1136 = v1135 != (float)0.000000;	// L1585
    ap_int<32> v1137 = v1136;	// L1586
    ap_int<32> v1138 = v1137 << (ap_int<32>)2;	// L1587
    ap_int<32> v1139 = v1134 | v1138;	// L1588
    float v1140 = v1123[0][(v1126 / 8)][((v1126 * 2) + ((v1126 / 8) * -16))][3];	// L1589
    bool v1141 = v1140 != (float)0.000000;	// L1590
    ap_int<32> v1142 = v1141;	// L1591
    ap_int<32> v1143 = v1142 << (ap_int<32>)3;	// L1592
    ap_int<32> v1144 = v1139 | v1143;	// L1593
    float v1145 = v1123[0][(v1126 / 8)][((v1126 * 2) + ((v1126 / 8) * -16))][4];	// L1594
    bool v1146 = v1145 != (float)0.000000;	// L1595
    ap_int<32> v1147 = v1146;	// L1596
    ap_int<32> v1148 = v1147 << (ap_int<32>)4;	// L1597
    ap_int<32> v1149 = v1144 | v1148;	// L1598
    float v1150 = v1123[0][(v1126 / 8)][((v1126 * 2) + ((v1126 / 8) * -16))][5];	// L1599
    bool v1151 = v1150 != (float)0.000000;	// L1600
    ap_int<32> v1152 = v1151;	// L1601
    ap_int<32> v1153 = v1152 << (ap_int<32>)5;	// L1602
    ap_int<32> v1154 = v1149 | v1153;	// L1603
    float v1155 = v1123[0][(v1126 / 8)][((v1126 * 2) + ((v1126 / 8) * -16))][6];	// L1604
    bool v1156 = v1155 != (float)0.000000;	// L1605
    ap_int<32> v1157 = v1156;	// L1606
    ap_int<32> v1158 = v1157 << (ap_int<32>)6;	// L1607
    ap_int<32> v1159 = v1154 | v1158;	// L1608
    float v1160 = v1123[0][(v1126 / 8)][((v1126 * 2) + ((v1126 / 8) * -16))][7];	// L1609
    bool v1161 = v1160 != (float)0.000000;	// L1610
    ap_int<32> v1162 = v1161;	// L1611
    ap_int<32> v1163 = v1162 << (ap_int<32>)7;	// L1612
    ap_int<32> v1164 = v1159 | v1163;	// L1613
    float v1165 = v1123[0][(v1126 / 8)][((v1126 * 2) + ((v1126 / 8) * -16))][8];	// L1614
    bool v1166 = v1165 != (float)0.000000;	// L1615
    ap_int<32> v1167 = v1166;	// L1616
    ap_int<32> v1168 = v1167 << (ap_int<32>)8;	// L1617
    ap_int<32> v1169 = v1164 | v1168;	// L1618
    float v1170 = v1123[0][(v1126 / 8)][((v1126 * 2) + ((v1126 / 8) * -16))][9];	// L1619
    bool v1171 = v1170 != (float)0.000000;	// L1620
    ap_int<32> v1172 = v1171;	// L1621
    ap_int<32> v1173 = v1172 << (ap_int<32>)9;	// L1622
    ap_int<32> v1174 = v1169 | v1173;	// L1623
    float v1175 = v1123[0][(v1126 / 8)][((v1126 * 2) + ((v1126 / 8) * -16))][10];	// L1624
    bool v1176 = v1175 != (float)0.000000;	// L1625
    ap_int<32> v1177 = v1176;	// L1626
    ap_int<32> v1178 = v1177 << (ap_int<32>)10;	// L1627
    ap_int<32> v1179 = v1174 | v1178;	// L1628
    float v1180 = v1123[0][(v1126 / 8)][((v1126 * 2) + ((v1126 / 8) * -16))][11];	// L1629
    bool v1181 = v1180 != (float)0.000000;	// L1630
    ap_int<32> v1182 = v1181;	// L1631
    ap_int<32> v1183 = v1182 << (ap_int<32>)11;	// L1632
    ap_int<32> v1184 = v1179 | v1183;	// L1633
    float v1185 = v1123[0][(v1126 / 8)][((v1126 * 2) + ((v1126 / 8) * -16))][12];	// L1634
    bool v1186 = v1185 != (float)0.000000;	// L1635
    ap_int<32> v1187 = v1186;	// L1636
    ap_int<32> v1188 = v1187 << (ap_int<32>)12;	// L1637
    ap_int<32> v1189 = v1184 | v1188;	// L1638
    float v1190 = v1123[0][(v1126 / 8)][((v1126 * 2) + ((v1126 / 8) * -16))][13];	// L1639
    bool v1191 = v1190 != (float)0.000000;	// L1640
    ap_int<32> v1192 = v1191;	// L1641
    ap_int<32> v1193 = v1192 << (ap_int<32>)13;	// L1642
    ap_int<32> v1194 = v1189 | v1193;	// L1643
    float v1195 = v1123[0][(v1126 / 8)][((v1126 * 2) + ((v1126 / 8) * -16))][14];	// L1644
    bool v1196 = v1195 != (float)0.000000;	// L1645
    ap_int<32> v1197 = v1196;	// L1646
    ap_int<32> v1198 = v1197 << (ap_int<32>)14;	// L1647
    ap_int<32> v1199 = v1194 | v1198;	// L1648
    float v1200 = v1123[0][(v1126 / 8)][((v1126 * 2) + ((v1126 / 8) * -16))][15];	// L1649
    bool v1201 = v1200 != (float)0.000000;	// L1650
    ap_int<32> v1202 = v1201;	// L1651
    ap_int<32> v1203 = v1202 << (ap_int<32>)15;	// L1652
    ap_int<32> v1204 = v1199 | v1203;	// L1653
    float v1205 = v1123[0][(v1126 / 8)][(((v1126 * 2) + ((v1126 / 8) * -16)) + 1)][0];	// L1654
    bool v1206 = v1205 != (float)0.000000;	// L1655
    ap_int<32> v1207 = v1206;	// L1656
    ap_int<32> v1208 = v1207 << (ap_int<32>)16;	// L1657
    ap_int<32> v1209 = v1204 | v1208;	// L1658
    float v1210 = v1123[0][(v1126 / 8)][(((v1126 * 2) + ((v1126 / 8) * -16)) + 1)][1];	// L1659
    bool v1211 = v1210 != (float)0.000000;	// L1660
    ap_int<32> v1212 = v1211;	// L1661
    ap_int<32> v1213 = v1212 << (ap_int<32>)17;	// L1662
    ap_int<32> v1214 = v1209 | v1213;	// L1663
    float v1215 = v1123[0][(v1126 / 8)][(((v1126 * 2) + ((v1126 / 8) * -16)) + 1)][2];	// L1664
    bool v1216 = v1215 != (float)0.000000;	// L1665
    ap_int<32> v1217 = v1216;	// L1666
    ap_int<32> v1218 = v1217 << (ap_int<32>)18;	// L1667
    ap_int<32> v1219 = v1214 | v1218;	// L1668
    float v1220 = v1123[0][(v1126 / 8)][(((v1126 * 2) + ((v1126 / 8) * -16)) + 1)][3];	// L1669
    bool v1221 = v1220 != (float)0.000000;	// L1670
    ap_int<32> v1222 = v1221;	// L1671
    ap_int<32> v1223 = v1222 << (ap_int<32>)19;	// L1672
    ap_int<32> v1224 = v1219 | v1223;	// L1673
    float v1225 = v1123[0][(v1126 / 8)][(((v1126 * 2) + ((v1126 / 8) * -16)) + 1)][4];	// L1674
    bool v1226 = v1225 != (float)0.000000;	// L1675
    ap_int<32> v1227 = v1226;	// L1676
    ap_int<32> v1228 = v1227 << (ap_int<32>)20;	// L1677
    ap_int<32> v1229 = v1224 | v1228;	// L1678
    float v1230 = v1123[0][(v1126 / 8)][(((v1126 * 2) + ((v1126 / 8) * -16)) + 1)][5];	// L1679
    bool v1231 = v1230 != (float)0.000000;	// L1680
    ap_int<32> v1232 = v1231;	// L1681
    ap_int<32> v1233 = v1232 << (ap_int<32>)21;	// L1682
    ap_int<32> v1234 = v1229 | v1233;	// L1683
    float v1235 = v1123[0][(v1126 / 8)][(((v1126 * 2) + ((v1126 / 8) * -16)) + 1)][6];	// L1684
    bool v1236 = v1235 != (float)0.000000;	// L1685
    ap_int<32> v1237 = v1236;	// L1686
    ap_int<32> v1238 = v1237 << (ap_int<32>)22;	// L1687
    ap_int<32> v1239 = v1234 | v1238;	// L1688
    float v1240 = v1123[0][(v1126 / 8)][(((v1126 * 2) + ((v1126 / 8) * -16)) + 1)][7];	// L1689
    bool v1241 = v1240 != (float)0.000000;	// L1690
    ap_int<32> v1242 = v1241;	// L1691
    ap_int<32> v1243 = v1242 << (ap_int<32>)23;	// L1692
    ap_int<32> v1244 = v1239 | v1243;	// L1693
    float v1245 = v1123[0][(v1126 / 8)][(((v1126 * 2) + ((v1126 / 8) * -16)) + 1)][8];	// L1694
    bool v1246 = v1245 != (float)0.000000;	// L1695
    ap_int<32> v1247 = v1246;	// L1696
    ap_int<32> v1248 = v1247 << (ap_int<32>)24;	// L1697
    ap_int<32> v1249 = v1244 | v1248;	// L1698
    float v1250 = v1123[0][(v1126 / 8)][(((v1126 * 2) + ((v1126 / 8) * -16)) + 1)][9];	// L1699
    bool v1251 = v1250 != (float)0.000000;	// L1700
    ap_int<32> v1252 = v1251;	// L1701
    ap_int<32> v1253 = v1252 << (ap_int<32>)25;	// L1702
    ap_int<32> v1254 = v1249 | v1253;	// L1703
    float v1255 = v1123[0][(v1126 / 8)][(((v1126 * 2) + ((v1126 / 8) * -16)) + 1)][10];	// L1704
    bool v1256 = v1255 != (float)0.000000;	// L1705
    ap_int<32> v1257 = v1256;	// L1706
    ap_int<32> v1258 = v1257 << (ap_int<32>)26;	// L1707
    ap_int<32> v1259 = v1254 | v1258;	// L1708
    float v1260 = v1123[0][(v1126 / 8)][(((v1126 * 2) + ((v1126 / 8) * -16)) + 1)][11];	// L1709
    bool v1261 = v1260 != (float)0.000000;	// L1710
    ap_int<32> v1262 = v1261;	// L1711
    ap_int<32> v1263 = v1262 << (ap_int<32>)27;	// L1712
    ap_int<32> v1264 = v1259 | v1263;	// L1713
    float v1265 = v1123[0][(v1126 / 8)][(((v1126 * 2) + ((v1126 / 8) * -16)) + 1)][12];	// L1714
    bool v1266 = v1265 != (float)0.000000;	// L1715
    ap_int<32> v1267 = v1266;	// L1716
    ap_int<32> v1268 = v1267 << (ap_int<32>)28;	// L1717
    ap_int<32> v1269 = v1264 | v1268;	// L1718
    float v1270 = v1123[0][(v1126 / 8)][(((v1126 * 2) + ((v1126 / 8) * -16)) + 1)][13];	// L1719
    bool v1271 = v1270 != (float)0.000000;	// L1720
    ap_int<32> v1272 = v1271;	// L1721
    ap_int<32> v1273 = v1272 << (ap_int<32>)29;	// L1722
    ap_int<32> v1274 = v1269 | v1273;	// L1723
    float v1275 = v1123[0][(v1126 / 8)][(((v1126 * 2) + ((v1126 / 8) * -16)) + 1)][14];	// L1724
    bool v1276 = v1275 != (float)0.000000;	// L1725
    ap_int<32> v1277 = v1276;	// L1726
    ap_int<32> v1278 = v1277 << (ap_int<32>)30;	// L1727
    ap_int<32> v1279 = v1274 | v1278;	// L1728
    float v1280 = v1123[0][(v1126 / 8)][(((v1126 * 2) + ((v1126 / 8) * -16)) + 1)][15];	// L1729
    bool v1281 = v1280 != (float)0.000000;	// L1730
    ap_int<32> v1282 = v1281;	// L1731
    ap_int<32> v1283 = v1282 << (ap_int<32>)31;	// L1732
    ap_int<32> v1284 = v1279 | v1283;	// L1733
    v1125[v1126] = v1284;	// L1734
  }
  for (int v1285 = 0; v1285 < 384; v1285 += 1) {	// L1736
    for (int v1286 = 0; v1286 < 16; v1286 += 1) {	// L1737
      for (int v1287 = 0; v1287 < 16; v1287 += 1) {	// L1738
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1125
        #pragma HLS dependence false variable=v1124
        ap_int<32> v1288 = v1125[((v1285 * 8) + (v1286 / 2))];	// L1739
        int v1289 = ((((v1285 * 256) + (v1286 * 16)) + v1287) % 32);	// L1740
        ap_int<32> v1290 = v1289;	// L1741
        ap_int<32> v1291 = v1288 >> v1290;	// L1742
        ap_int<32> v1292 = v1291 & (ap_int<32>)1;	// L1743
        float v1293 = v1292;	// L1744
        v1124[0][v1285][(v1286 + 1)][(v1287 + 1)] = v1293;	// L1745
      }
    }
  }
}

void kernel277(
  float v1294[1][384][18][18],
  float v1295
) {	// L1751
  for (int v1296 = 0; v1296 < 384; v1296 += 1) {	// L1752
    for (int v1297 = 0; v1297 < 18; v1297 += 1) {	// L1753
      for (int v1298 = 0; v1298 < 18; v1298 += 1) {	// L1754
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1294
        v1294[0][v1296][v1297][v1298] = v1295;	// L1755
      }
    }
  }
}

void kernel278(
  float v1299[1][384][16][16],
  float v1300[1][384][16][16]
) {	// L1761
  for (int v1301 = 0; v1301 < 384; v1301 += 1) {	// L1762
    for (int v1302 = 0; v1302 < 16; v1302 += 1) {	// L1763
      for (int v1303 = 0; v1303 < 16; v1303 += 1) {	// L1764
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1299
        #pragma HLS dependence false variable=v1300
        float v1304 = v1299[0][v1301][v1302][v1303];	// L1765
        v1300[0][v1301][v1302][v1303] = v1304;	// L1766
      }
    }
  }
}

void kernel279(
  float v1305[1][384][16][16],
  float v1306[1][384][16][16],
  float v1307
) {	// L1772
  ap_int<32> v1308[3072];	// L1806
  #pragma HLS resource variable=v1308 core=ram_t2p_bram

  for (int v1309 = 0; v1309 < 3072; v1309 += 1) {	// L1807
    float v1310 = v1305[0][(v1309 / 8)][((v1309 * 2) + ((v1309 / 8) * -16))][0];	// L1808
    bool v1311 = v1310 != (float)0.000000;	// L1809
    ap_int<32> v1312 = v1311;	// L1810
    float v1313 = v1305[0][(v1309 / 8)][((v1309 * 2) + ((v1309 / 8) * -16))][1];	// L1811
    bool v1314 = v1313 != (float)0.000000;	// L1812
    ap_int<32> v1315 = v1314;	// L1813
    ap_int<32> v1316 = v1315 << (ap_int<32>)1;	// L1814
    ap_int<32> v1317 = v1312 | v1316;	// L1815
    float v1318 = v1305[0][(v1309 / 8)][((v1309 * 2) + ((v1309 / 8) * -16))][2];	// L1816
    bool v1319 = v1318 != (float)0.000000;	// L1817
    ap_int<32> v1320 = v1319;	// L1818
    ap_int<32> v1321 = v1320 << (ap_int<32>)2;	// L1819
    ap_int<32> v1322 = v1317 | v1321;	// L1820
    float v1323 = v1305[0][(v1309 / 8)][((v1309 * 2) + ((v1309 / 8) * -16))][3];	// L1821
    bool v1324 = v1323 != (float)0.000000;	// L1822
    ap_int<32> v1325 = v1324;	// L1823
    ap_int<32> v1326 = v1325 << (ap_int<32>)3;	// L1824
    ap_int<32> v1327 = v1322 | v1326;	// L1825
    float v1328 = v1305[0][(v1309 / 8)][((v1309 * 2) + ((v1309 / 8) * -16))][4];	// L1826
    bool v1329 = v1328 != (float)0.000000;	// L1827
    ap_int<32> v1330 = v1329;	// L1828
    ap_int<32> v1331 = v1330 << (ap_int<32>)4;	// L1829
    ap_int<32> v1332 = v1327 | v1331;	// L1830
    float v1333 = v1305[0][(v1309 / 8)][((v1309 * 2) + ((v1309 / 8) * -16))][5];	// L1831
    bool v1334 = v1333 != (float)0.000000;	// L1832
    ap_int<32> v1335 = v1334;	// L1833
    ap_int<32> v1336 = v1335 << (ap_int<32>)5;	// L1834
    ap_int<32> v1337 = v1332 | v1336;	// L1835
    float v1338 = v1305[0][(v1309 / 8)][((v1309 * 2) + ((v1309 / 8) * -16))][6];	// L1836
    bool v1339 = v1338 != (float)0.000000;	// L1837
    ap_int<32> v1340 = v1339;	// L1838
    ap_int<32> v1341 = v1340 << (ap_int<32>)6;	// L1839
    ap_int<32> v1342 = v1337 | v1341;	// L1840
    float v1343 = v1305[0][(v1309 / 8)][((v1309 * 2) + ((v1309 / 8) * -16))][7];	// L1841
    bool v1344 = v1343 != (float)0.000000;	// L1842
    ap_int<32> v1345 = v1344;	// L1843
    ap_int<32> v1346 = v1345 << (ap_int<32>)7;	// L1844
    ap_int<32> v1347 = v1342 | v1346;	// L1845
    float v1348 = v1305[0][(v1309 / 8)][((v1309 * 2) + ((v1309 / 8) * -16))][8];	// L1846
    bool v1349 = v1348 != (float)0.000000;	// L1847
    ap_int<32> v1350 = v1349;	// L1848
    ap_int<32> v1351 = v1350 << (ap_int<32>)8;	// L1849
    ap_int<32> v1352 = v1347 | v1351;	// L1850
    float v1353 = v1305[0][(v1309 / 8)][((v1309 * 2) + ((v1309 / 8) * -16))][9];	// L1851
    bool v1354 = v1353 != (float)0.000000;	// L1852
    ap_int<32> v1355 = v1354;	// L1853
    ap_int<32> v1356 = v1355 << (ap_int<32>)9;	// L1854
    ap_int<32> v1357 = v1352 | v1356;	// L1855
    float v1358 = v1305[0][(v1309 / 8)][((v1309 * 2) + ((v1309 / 8) * -16))][10];	// L1856
    bool v1359 = v1358 != (float)0.000000;	// L1857
    ap_int<32> v1360 = v1359;	// L1858
    ap_int<32> v1361 = v1360 << (ap_int<32>)10;	// L1859
    ap_int<32> v1362 = v1357 | v1361;	// L1860
    float v1363 = v1305[0][(v1309 / 8)][((v1309 * 2) + ((v1309 / 8) * -16))][11];	// L1861
    bool v1364 = v1363 != (float)0.000000;	// L1862
    ap_int<32> v1365 = v1364;	// L1863
    ap_int<32> v1366 = v1365 << (ap_int<32>)11;	// L1864
    ap_int<32> v1367 = v1362 | v1366;	// L1865
    float v1368 = v1305[0][(v1309 / 8)][((v1309 * 2) + ((v1309 / 8) * -16))][12];	// L1866
    bool v1369 = v1368 != (float)0.000000;	// L1867
    ap_int<32> v1370 = v1369;	// L1868
    ap_int<32> v1371 = v1370 << (ap_int<32>)12;	// L1869
    ap_int<32> v1372 = v1367 | v1371;	// L1870
    float v1373 = v1305[0][(v1309 / 8)][((v1309 * 2) + ((v1309 / 8) * -16))][13];	// L1871
    bool v1374 = v1373 != (float)0.000000;	// L1872
    ap_int<32> v1375 = v1374;	// L1873
    ap_int<32> v1376 = v1375 << (ap_int<32>)13;	// L1874
    ap_int<32> v1377 = v1372 | v1376;	// L1875
    float v1378 = v1305[0][(v1309 / 8)][((v1309 * 2) + ((v1309 / 8) * -16))][14];	// L1876
    bool v1379 = v1378 != (float)0.000000;	// L1877
    ap_int<32> v1380 = v1379;	// L1878
    ap_int<32> v1381 = v1380 << (ap_int<32>)14;	// L1879
    ap_int<32> v1382 = v1377 | v1381;	// L1880
    float v1383 = v1305[0][(v1309 / 8)][((v1309 * 2) + ((v1309 / 8) * -16))][15];	// L1881
    bool v1384 = v1383 != (float)0.000000;	// L1882
    ap_int<32> v1385 = v1384;	// L1883
    ap_int<32> v1386 = v1385 << (ap_int<32>)15;	// L1884
    ap_int<32> v1387 = v1382 | v1386;	// L1885
    float v1388 = v1305[0][(v1309 / 8)][(((v1309 * 2) + ((v1309 / 8) * -16)) + 1)][0];	// L1886
    bool v1389 = v1388 != (float)0.000000;	// L1887
    ap_int<32> v1390 = v1389;	// L1888
    ap_int<32> v1391 = v1390 << (ap_int<32>)16;	// L1889
    ap_int<32> v1392 = v1387 | v1391;	// L1890
    float v1393 = v1305[0][(v1309 / 8)][(((v1309 * 2) + ((v1309 / 8) * -16)) + 1)][1];	// L1891
    bool v1394 = v1393 != (float)0.000000;	// L1892
    ap_int<32> v1395 = v1394;	// L1893
    ap_int<32> v1396 = v1395 << (ap_int<32>)17;	// L1894
    ap_int<32> v1397 = v1392 | v1396;	// L1895
    float v1398 = v1305[0][(v1309 / 8)][(((v1309 * 2) + ((v1309 / 8) * -16)) + 1)][2];	// L1896
    bool v1399 = v1398 != (float)0.000000;	// L1897
    ap_int<32> v1400 = v1399;	// L1898
    ap_int<32> v1401 = v1400 << (ap_int<32>)18;	// L1899
    ap_int<32> v1402 = v1397 | v1401;	// L1900
    float v1403 = v1305[0][(v1309 / 8)][(((v1309 * 2) + ((v1309 / 8) * -16)) + 1)][3];	// L1901
    bool v1404 = v1403 != (float)0.000000;	// L1902
    ap_int<32> v1405 = v1404;	// L1903
    ap_int<32> v1406 = v1405 << (ap_int<32>)19;	// L1904
    ap_int<32> v1407 = v1402 | v1406;	// L1905
    float v1408 = v1305[0][(v1309 / 8)][(((v1309 * 2) + ((v1309 / 8) * -16)) + 1)][4];	// L1906
    bool v1409 = v1408 != (float)0.000000;	// L1907
    ap_int<32> v1410 = v1409;	// L1908
    ap_int<32> v1411 = v1410 << (ap_int<32>)20;	// L1909
    ap_int<32> v1412 = v1407 | v1411;	// L1910
    float v1413 = v1305[0][(v1309 / 8)][(((v1309 * 2) + ((v1309 / 8) * -16)) + 1)][5];	// L1911
    bool v1414 = v1413 != (float)0.000000;	// L1912
    ap_int<32> v1415 = v1414;	// L1913
    ap_int<32> v1416 = v1415 << (ap_int<32>)21;	// L1914
    ap_int<32> v1417 = v1412 | v1416;	// L1915
    float v1418 = v1305[0][(v1309 / 8)][(((v1309 * 2) + ((v1309 / 8) * -16)) + 1)][6];	// L1916
    bool v1419 = v1418 != (float)0.000000;	// L1917
    ap_int<32> v1420 = v1419;	// L1918
    ap_int<32> v1421 = v1420 << (ap_int<32>)22;	// L1919
    ap_int<32> v1422 = v1417 | v1421;	// L1920
    float v1423 = v1305[0][(v1309 / 8)][(((v1309 * 2) + ((v1309 / 8) * -16)) + 1)][7];	// L1921
    bool v1424 = v1423 != (float)0.000000;	// L1922
    ap_int<32> v1425 = v1424;	// L1923
    ap_int<32> v1426 = v1425 << (ap_int<32>)23;	// L1924
    ap_int<32> v1427 = v1422 | v1426;	// L1925
    float v1428 = v1305[0][(v1309 / 8)][(((v1309 * 2) + ((v1309 / 8) * -16)) + 1)][8];	// L1926
    bool v1429 = v1428 != (float)0.000000;	// L1927
    ap_int<32> v1430 = v1429;	// L1928
    ap_int<32> v1431 = v1430 << (ap_int<32>)24;	// L1929
    ap_int<32> v1432 = v1427 | v1431;	// L1930
    float v1433 = v1305[0][(v1309 / 8)][(((v1309 * 2) + ((v1309 / 8) * -16)) + 1)][9];	// L1931
    bool v1434 = v1433 != (float)0.000000;	// L1932
    ap_int<32> v1435 = v1434;	// L1933
    ap_int<32> v1436 = v1435 << (ap_int<32>)25;	// L1934
    ap_int<32> v1437 = v1432 | v1436;	// L1935
    float v1438 = v1305[0][(v1309 / 8)][(((v1309 * 2) + ((v1309 / 8) * -16)) + 1)][10];	// L1936
    bool v1439 = v1438 != (float)0.000000;	// L1937
    ap_int<32> v1440 = v1439;	// L1938
    ap_int<32> v1441 = v1440 << (ap_int<32>)26;	// L1939
    ap_int<32> v1442 = v1437 | v1441;	// L1940
    float v1443 = v1305[0][(v1309 / 8)][(((v1309 * 2) + ((v1309 / 8) * -16)) + 1)][11];	// L1941
    bool v1444 = v1443 != (float)0.000000;	// L1942
    ap_int<32> v1445 = v1444;	// L1943
    ap_int<32> v1446 = v1445 << (ap_int<32>)27;	// L1944
    ap_int<32> v1447 = v1442 | v1446;	// L1945
    float v1448 = v1305[0][(v1309 / 8)][(((v1309 * 2) + ((v1309 / 8) * -16)) + 1)][12];	// L1946
    bool v1449 = v1448 != (float)0.000000;	// L1947
    ap_int<32> v1450 = v1449;	// L1948
    ap_int<32> v1451 = v1450 << (ap_int<32>)28;	// L1949
    ap_int<32> v1452 = v1447 | v1451;	// L1950
    float v1453 = v1305[0][(v1309 / 8)][(((v1309 * 2) + ((v1309 / 8) * -16)) + 1)][13];	// L1951
    bool v1454 = v1453 != (float)0.000000;	// L1952
    ap_int<32> v1455 = v1454;	// L1953
    ap_int<32> v1456 = v1455 << (ap_int<32>)29;	// L1954
    ap_int<32> v1457 = v1452 | v1456;	// L1955
    float v1458 = v1305[0][(v1309 / 8)][(((v1309 * 2) + ((v1309 / 8) * -16)) + 1)][14];	// L1956
    bool v1459 = v1458 != (float)0.000000;	// L1957
    ap_int<32> v1460 = v1459;	// L1958
    ap_int<32> v1461 = v1460 << (ap_int<32>)30;	// L1959
    ap_int<32> v1462 = v1457 | v1461;	// L1960
    float v1463 = v1305[0][(v1309 / 8)][(((v1309 * 2) + ((v1309 / 8) * -16)) + 1)][15];	// L1961
    bool v1464 = v1463 != (float)0.000000;	// L1962
    ap_int<32> v1465 = v1464;	// L1963
    ap_int<32> v1466 = v1465 << (ap_int<32>)31;	// L1964
    ap_int<32> v1467 = v1462 | v1466;	// L1965
    v1308[v1309] = v1467;	// L1966
  }
  for (int v1468 = 0; v1468 < 384; v1468 += 1) {	// L1968
    for (int v1469 = 0; v1469 < 16; v1469 += 1) {	// L1969
      for (int v1470 = 0; v1470 < 16; v1470 += 1) {	// L1970
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1306
        #pragma HLS dependence false variable=v1308
        float v1471 = v1306[0][v1468][v1469][v1470];	// L1971
        ap_int<32> v1472 = v1308[((v1468 * 8) + (v1469 / 2))];	// L1972
        int v1473 = ((((v1468 * 256) + (v1469 * 16)) + v1470) % 32);	// L1973
        ap_int<32> v1474 = v1473;	// L1974
        ap_int<32> v1475 = v1472 >> v1474;	// L1975
        ap_int<32> v1476 = v1475 & (ap_int<32>)1;	// L1976
        bool v1477 = v1476 != (ap_int<32>)0;	// L1977
        float v1478 = v1476;	// L1978
        float v1479 = v1478 * v1471;	// L1979
        float v1480 = v1471 - v1479;	// L1980
        float v1481 = v1480 + v1307;	// L1981
        float v1482 = v1477 ? v1481 : v1480;	// L1982
        v1306[0][v1468][v1469][v1470] = v1482;	// L1983
      }
    }
  }
}

void kernel280(
  float v1483[1][384][16][16],
  float v1484,
  float v1485
) {	// L1989
  for (int v1486 = 0; v1486 < 384; v1486 += 1) {	// L1990
    for (int v1487 = 0; v1487 < 16; v1487 += 1) {	// L1991
      for (int v1488 = 0; v1488 < 16; v1488 += 1) {	// L1992
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1483
        float v1489 = v1483[0][v1486][v1487][v1488];	// L1993
        float v1490 = v1489 - v1485;	// L1994
        bool v1491 = v1490 >= v1484;	// L1995
        float v1492 = v1491 ? v1485 : v1484;	// L1996
        v1483[0][v1486][v1487][v1488] = v1492;	// L1997
      }
    }
  }
}

void kernel282(
  float v1493[1][384][16][16],
  float v1494[1][384][16][16],
  float v1495
) {	// L2003
  for (int v1496 = 0; v1496 < 384; v1496 += 1) {	// L2004
    for (int v1497 = 0; v1497 < 16; v1497 += 1) {	// L2005
      for (int v1498 = 0; v1498 < 16; v1498 += 1) {	// L2006
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1493
        #pragma HLS dependence false variable=v1494
        float v1499 = v1493[0][v1496][v1497][v1498];	// L2007
        float v1500 = v1494[0][v1496][v1497][v1498];	// L2008
        float v1501 = v1500 / v1495;	// L2009
        float v1502 = v1499 / v1495;	// L2010
        float v1503 = v1499 - v1502;	// L2011
        float v1504 = v1503 + v1501;	// L2012
        v1494[0][v1496][v1497][v1498] = v1504;	// L2013
      }
    }
  }
}

void kernel283(
  float v1505[1][192][18][18],
  float v1506[384][192][3][3],
  float v1507[1][384][16][16]
) {	// L2019
  float v1508[1][384][16][16];	// L2020
  #pragma HLS resource variable=v1508 core=ram_t2p_uram

  memcpy(v1508, v1507, 98304 * sizeof(float));	// L2021

  auto v1509 = reinterpret_cast<float(*)[192][3][3]>(v1506);	// L2023

  for (int v1510 = 0; v1510 < 192; v1510 += 1) {	// L2024
    for (int v1511 = 0; v1511 < 3; v1511 += 1) {	// L2025
      for (int v1512 = 0; v1512 < 3; v1512 += 1) {	// L2026
        for (int v1513 = 0; v1513 < 384; v1513 += 1) {	// L2027
          float v1514 = v1509[v1513][v1510][v1511][v1512];	// L2028
          for (int v1515 = 0; v1515 < 16; v1515 += 1) {	// L2029
            for (int v1516 = 0; v1516 < 16; v1516 += 1) {	// L2030
              #pragma HLS pipeline II=1
              #pragma HLS dependence false variable=v1505
              #pragma HLS dependence false variable=v1508
              float v1517 = v1505[0][v1510][(v1515 + v1511)][(v1516 + v1512)];	// L2031
              float v1518 = v1508[0][v1513][v1515][v1516];	// L2032
              float v1519 = v1517 * v1514;	// L2033
              float v1520 = v1518 + v1519;	// L2034
              v1508[0][v1513][v1515][v1516] = v1520;	// L2035
            }
          }
        }
      }
    }
  }
  memcpy(v1507, v1508, 98304 * sizeof(float));	// L2042

}

void kernel284(
  float v1521[384],
  float v1522[1][384][16][16]
) {	// L2045
  float v1523[384];	// L2046
  #pragma HLS resource variable=v1523 core=ram_t2p_bram

  memcpy(v1523, v1521, 384 * sizeof(float));	// L2047

  for (int v1524 = 0; v1524 < 384; v1524 += 1) {	// L2048
    for (int v1525 = 0; v1525 < 16; v1525 += 1) {	// L2049
      for (int v1526 = 0; v1526 < 16; v1526 += 1) {	// L2050
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1523
        #pragma HLS dependence false variable=v1522
        float v1527 = v1523[v1524];	// L2051
        v1522[0][v1524][v1525][v1526] = v1527;	// L2052
      }
    }
  }
}

void kernel285(
  float v1528[1][192][16][16],
  float v1529[1][192][18][18]
) {	// L2058
  for (int v1530 = 0; v1530 < 192; v1530 += 1) {	// L2059
    for (int v1531 = 0; v1531 < 16; v1531 += 1) {	// L2060
      for (int v1532 = 0; v1532 < 16; v1532 += 1) {	// L2061
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1528
        #pragma HLS dependence false variable=v1529
        float v1533 = v1528[0][v1530][v1531][v1532];	// L2062
        v1529[0][v1530][(v1531 + 1)][(v1532 + 1)] = v1533;	// L2063
      }
    }
  }
}

void kernel286(
  float v1534[1][192][18][18],
  float v1535
) {	// L2069
  for (int v1536 = 0; v1536 < 192; v1536 += 1) {	// L2070
    for (int v1537 = 0; v1537 < 18; v1537 += 1) {	// L2071
      for (int v1538 = 0; v1538 < 18; v1538 += 1) {	// L2072
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1534
        v1534[0][v1536][v1537][v1538] = v1535;	// L2073
      }
    }
  }
}

void kernel287(
  float v1539[1][192][34][34],
  float v1540[3][3],
  float v1541[1][192][16][16]
) {	// L2079
  for (int v1542 = 0; v1542 < 3; v1542 += 1) {	// L2080
    for (int v1543 = 0; v1543 < 3; v1543 += 1) {	// L2081
      for (int v1544 = 0; v1544 < 192; v1544 += 1) {	// L2082
        for (int v1545 = 0; v1545 < 16; v1545 += 1) {	// L2083
          for (int v1546 = 0; v1546 < 16; v1546 += 1) {	// L2084
            #pragma HLS pipeline II=1
            #pragma HLS dependence false variable=v1539
            #pragma HLS dependence false variable=v1541
            float v1547 = v1539[0][v1544][((v1545 * 2) + v1542)][((v1546 * 2) + v1543)];	// L2085
            float v1548 = v1541[0][v1544][v1545][v1546];	// L2086
            float v1549 = max(v1548, v1547);	// L2087
            v1541[0][v1544][v1545][v1546] = v1549;	// L2088
          }
        }
      }
    }
  }
}

void kernel288(
  float v1550[1][192][16][16],
  float v1551
) {	// L2096
  for (int v1552 = 0; v1552 < 192; v1552 += 1) {	// L2097
    for (int v1553 = 0; v1553 < 16; v1553 += 1) {	// L2098
      for (int v1554 = 0; v1554 < 16; v1554 += 1) {	// L2099
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1550
        v1550[0][v1552][v1553][v1554] = v1551;	// L2100
      }
    }
  }
}

void kernel289(
  float v1555[1][192][32][32],
  float v1556[1][192][34][34]
) {	// L2106
  ap_int<32> v1557[6144];	// L2139
  #pragma HLS resource variable=v1557 core=ram_t2p_bram

  for (int v1558 = 0; v1558 < 6144; v1558 += 1) {	// L2140
    float v1559 = v1555[0][(v1558 / 32)][(v1558 % 32)][0];	// L2141
    bool v1560 = v1559 != (float)0.000000;	// L2142
    ap_int<32> v1561 = v1560;	// L2143
    float v1562 = v1555[0][(v1558 / 32)][(v1558 % 32)][1];	// L2144
    bool v1563 = v1562 != (float)0.000000;	// L2145
    ap_int<32> v1564 = v1563;	// L2146
    ap_int<32> v1565 = v1564 << (ap_int<32>)1;	// L2147
    ap_int<32> v1566 = v1561 | v1565;	// L2148
    float v1567 = v1555[0][(v1558 / 32)][(v1558 % 32)][2];	// L2149
    bool v1568 = v1567 != (float)0.000000;	// L2150
    ap_int<32> v1569 = v1568;	// L2151
    ap_int<32> v1570 = v1569 << (ap_int<32>)2;	// L2152
    ap_int<32> v1571 = v1566 | v1570;	// L2153
    float v1572 = v1555[0][(v1558 / 32)][(v1558 % 32)][3];	// L2154
    bool v1573 = v1572 != (float)0.000000;	// L2155
    ap_int<32> v1574 = v1573;	// L2156
    ap_int<32> v1575 = v1574 << (ap_int<32>)3;	// L2157
    ap_int<32> v1576 = v1571 | v1575;	// L2158
    float v1577 = v1555[0][(v1558 / 32)][(v1558 % 32)][4];	// L2159
    bool v1578 = v1577 != (float)0.000000;	// L2160
    ap_int<32> v1579 = v1578;	// L2161
    ap_int<32> v1580 = v1579 << (ap_int<32>)4;	// L2162
    ap_int<32> v1581 = v1576 | v1580;	// L2163
    float v1582 = v1555[0][(v1558 / 32)][(v1558 % 32)][5];	// L2164
    bool v1583 = v1582 != (float)0.000000;	// L2165
    ap_int<32> v1584 = v1583;	// L2166
    ap_int<32> v1585 = v1584 << (ap_int<32>)5;	// L2167
    ap_int<32> v1586 = v1581 | v1585;	// L2168
    float v1587 = v1555[0][(v1558 / 32)][(v1558 % 32)][6];	// L2169
    bool v1588 = v1587 != (float)0.000000;	// L2170
    ap_int<32> v1589 = v1588;	// L2171
    ap_int<32> v1590 = v1589 << (ap_int<32>)6;	// L2172
    ap_int<32> v1591 = v1586 | v1590;	// L2173
    float v1592 = v1555[0][(v1558 / 32)][(v1558 % 32)][7];	// L2174
    bool v1593 = v1592 != (float)0.000000;	// L2175
    ap_int<32> v1594 = v1593;	// L2176
    ap_int<32> v1595 = v1594 << (ap_int<32>)7;	// L2177
    ap_int<32> v1596 = v1591 | v1595;	// L2178
    float v1597 = v1555[0][(v1558 / 32)][(v1558 % 32)][8];	// L2179
    bool v1598 = v1597 != (float)0.000000;	// L2180
    ap_int<32> v1599 = v1598;	// L2181
    ap_int<32> v1600 = v1599 << (ap_int<32>)8;	// L2182
    ap_int<32> v1601 = v1596 | v1600;	// L2183
    float v1602 = v1555[0][(v1558 / 32)][(v1558 % 32)][9];	// L2184
    bool v1603 = v1602 != (float)0.000000;	// L2185
    ap_int<32> v1604 = v1603;	// L2186
    ap_int<32> v1605 = v1604 << (ap_int<32>)9;	// L2187
    ap_int<32> v1606 = v1601 | v1605;	// L2188
    float v1607 = v1555[0][(v1558 / 32)][(v1558 % 32)][10];	// L2189
    bool v1608 = v1607 != (float)0.000000;	// L2190
    ap_int<32> v1609 = v1608;	// L2191
    ap_int<32> v1610 = v1609 << (ap_int<32>)10;	// L2192
    ap_int<32> v1611 = v1606 | v1610;	// L2193
    float v1612 = v1555[0][(v1558 / 32)][(v1558 % 32)][11];	// L2194
    bool v1613 = v1612 != (float)0.000000;	// L2195
    ap_int<32> v1614 = v1613;	// L2196
    ap_int<32> v1615 = v1614 << (ap_int<32>)11;	// L2197
    ap_int<32> v1616 = v1611 | v1615;	// L2198
    float v1617 = v1555[0][(v1558 / 32)][(v1558 % 32)][12];	// L2199
    bool v1618 = v1617 != (float)0.000000;	// L2200
    ap_int<32> v1619 = v1618;	// L2201
    ap_int<32> v1620 = v1619 << (ap_int<32>)12;	// L2202
    ap_int<32> v1621 = v1616 | v1620;	// L2203
    float v1622 = v1555[0][(v1558 / 32)][(v1558 % 32)][13];	// L2204
    bool v1623 = v1622 != (float)0.000000;	// L2205
    ap_int<32> v1624 = v1623;	// L2206
    ap_int<32> v1625 = v1624 << (ap_int<32>)13;	// L2207
    ap_int<32> v1626 = v1621 | v1625;	// L2208
    float v1627 = v1555[0][(v1558 / 32)][(v1558 % 32)][14];	// L2209
    bool v1628 = v1627 != (float)0.000000;	// L2210
    ap_int<32> v1629 = v1628;	// L2211
    ap_int<32> v1630 = v1629 << (ap_int<32>)14;	// L2212
    ap_int<32> v1631 = v1626 | v1630;	// L2213
    float v1632 = v1555[0][(v1558 / 32)][(v1558 % 32)][15];	// L2214
    bool v1633 = v1632 != (float)0.000000;	// L2215
    ap_int<32> v1634 = v1633;	// L2216
    ap_int<32> v1635 = v1634 << (ap_int<32>)15;	// L2217
    ap_int<32> v1636 = v1631 | v1635;	// L2218
    float v1637 = v1555[0][(v1558 / 32)][(v1558 % 32)][16];	// L2219
    bool v1638 = v1637 != (float)0.000000;	// L2220
    ap_int<32> v1639 = v1638;	// L2221
    ap_int<32> v1640 = v1639 << (ap_int<32>)16;	// L2222
    ap_int<32> v1641 = v1636 | v1640;	// L2223
    float v1642 = v1555[0][(v1558 / 32)][(v1558 % 32)][17];	// L2224
    bool v1643 = v1642 != (float)0.000000;	// L2225
    ap_int<32> v1644 = v1643;	// L2226
    ap_int<32> v1645 = v1644 << (ap_int<32>)17;	// L2227
    ap_int<32> v1646 = v1641 | v1645;	// L2228
    float v1647 = v1555[0][(v1558 / 32)][(v1558 % 32)][18];	// L2229
    bool v1648 = v1647 != (float)0.000000;	// L2230
    ap_int<32> v1649 = v1648;	// L2231
    ap_int<32> v1650 = v1649 << (ap_int<32>)18;	// L2232
    ap_int<32> v1651 = v1646 | v1650;	// L2233
    float v1652 = v1555[0][(v1558 / 32)][(v1558 % 32)][19];	// L2234
    bool v1653 = v1652 != (float)0.000000;	// L2235
    ap_int<32> v1654 = v1653;	// L2236
    ap_int<32> v1655 = v1654 << (ap_int<32>)19;	// L2237
    ap_int<32> v1656 = v1651 | v1655;	// L2238
    float v1657 = v1555[0][(v1558 / 32)][(v1558 % 32)][20];	// L2239
    bool v1658 = v1657 != (float)0.000000;	// L2240
    ap_int<32> v1659 = v1658;	// L2241
    ap_int<32> v1660 = v1659 << (ap_int<32>)20;	// L2242
    ap_int<32> v1661 = v1656 | v1660;	// L2243
    float v1662 = v1555[0][(v1558 / 32)][(v1558 % 32)][21];	// L2244
    bool v1663 = v1662 != (float)0.000000;	// L2245
    ap_int<32> v1664 = v1663;	// L2246
    ap_int<32> v1665 = v1664 << (ap_int<32>)21;	// L2247
    ap_int<32> v1666 = v1661 | v1665;	// L2248
    float v1667 = v1555[0][(v1558 / 32)][(v1558 % 32)][22];	// L2249
    bool v1668 = v1667 != (float)0.000000;	// L2250
    ap_int<32> v1669 = v1668;	// L2251
    ap_int<32> v1670 = v1669 << (ap_int<32>)22;	// L2252
    ap_int<32> v1671 = v1666 | v1670;	// L2253
    float v1672 = v1555[0][(v1558 / 32)][(v1558 % 32)][23];	// L2254
    bool v1673 = v1672 != (float)0.000000;	// L2255
    ap_int<32> v1674 = v1673;	// L2256
    ap_int<32> v1675 = v1674 << (ap_int<32>)23;	// L2257
    ap_int<32> v1676 = v1671 | v1675;	// L2258
    float v1677 = v1555[0][(v1558 / 32)][(v1558 % 32)][24];	// L2259
    bool v1678 = v1677 != (float)0.000000;	// L2260
    ap_int<32> v1679 = v1678;	// L2261
    ap_int<32> v1680 = v1679 << (ap_int<32>)24;	// L2262
    ap_int<32> v1681 = v1676 | v1680;	// L2263
    float v1682 = v1555[0][(v1558 / 32)][(v1558 % 32)][25];	// L2264
    bool v1683 = v1682 != (float)0.000000;	// L2265
    ap_int<32> v1684 = v1683;	// L2266
    ap_int<32> v1685 = v1684 << (ap_int<32>)25;	// L2267
    ap_int<32> v1686 = v1681 | v1685;	// L2268
    float v1687 = v1555[0][(v1558 / 32)][(v1558 % 32)][26];	// L2269
    bool v1688 = v1687 != (float)0.000000;	// L2270
    ap_int<32> v1689 = v1688;	// L2271
    ap_int<32> v1690 = v1689 << (ap_int<32>)26;	// L2272
    ap_int<32> v1691 = v1686 | v1690;	// L2273
    float v1692 = v1555[0][(v1558 / 32)][(v1558 % 32)][27];	// L2274
    bool v1693 = v1692 != (float)0.000000;	// L2275
    ap_int<32> v1694 = v1693;	// L2276
    ap_int<32> v1695 = v1694 << (ap_int<32>)27;	// L2277
    ap_int<32> v1696 = v1691 | v1695;	// L2278
    float v1697 = v1555[0][(v1558 / 32)][(v1558 % 32)][28];	// L2279
    bool v1698 = v1697 != (float)0.000000;	// L2280
    ap_int<32> v1699 = v1698;	// L2281
    ap_int<32> v1700 = v1699 << (ap_int<32>)28;	// L2282
    ap_int<32> v1701 = v1696 | v1700;	// L2283
    float v1702 = v1555[0][(v1558 / 32)][(v1558 % 32)][29];	// L2284
    bool v1703 = v1702 != (float)0.000000;	// L2285
    ap_int<32> v1704 = v1703;	// L2286
    ap_int<32> v1705 = v1704 << (ap_int<32>)29;	// L2287
    ap_int<32> v1706 = v1701 | v1705;	// L2288
    float v1707 = v1555[0][(v1558 / 32)][(v1558 % 32)][30];	// L2289
    bool v1708 = v1707 != (float)0.000000;	// L2290
    ap_int<32> v1709 = v1708;	// L2291
    ap_int<32> v1710 = v1709 << (ap_int<32>)30;	// L2292
    ap_int<32> v1711 = v1706 | v1710;	// L2293
    float v1712 = v1555[0][(v1558 / 32)][(v1558 % 32)][31];	// L2294
    bool v1713 = v1712 != (float)0.000000;	// L2295
    ap_int<32> v1714 = v1713;	// L2296
    ap_int<32> v1715 = v1714 << (ap_int<32>)31;	// L2297
    ap_int<32> v1716 = v1711 | v1715;	// L2298
    v1557[v1558] = v1716;	// L2299
  }
  for (int v1717 = 0; v1717 < 192; v1717 += 1) {	// L2301
    for (int v1718 = 0; v1718 < 32; v1718 += 1) {	// L2302
      for (int v1719 = 0; v1719 < 32; v1719 += 1) {	// L2303
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1557
        #pragma HLS dependence false variable=v1556
        ap_int<32> v1720 = v1557[((v1717 * 32) + v1718)];	// L2304
        ap_int<32> v1721 = v1719;	// L2305
        ap_int<32> v1722 = v1720 >> v1721;	// L2306
        ap_int<32> v1723 = v1722 & (ap_int<32>)1;	// L2307
        float v1724 = v1723;	// L2308
        v1556[0][v1717][(v1718 + 1)][(v1719 + 1)] = v1724;	// L2309
      }
    }
  }
}

void kernel290(
  float v1725[1][192][34][34],
  float v1726
) {	// L2315
  for (int v1727 = 0; v1727 < 192; v1727 += 1) {	// L2316
    for (int v1728 = 0; v1728 < 34; v1728 += 1) {	// L2317
      for (int v1729 = 0; v1729 < 34; v1729 += 1) {	// L2318
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1725
        v1725[0][v1727][v1728][v1729] = v1726;	// L2319
      }
    }
  }
}

void kernel291(
  float v1730[1][192][32][32],
  float v1731[1][192][32][32]
) {	// L2325
  for (int v1732 = 0; v1732 < 192; v1732 += 1) {	// L2326
    for (int v1733 = 0; v1733 < 32; v1733 += 1) {	// L2327
      for (int v1734 = 0; v1734 < 32; v1734 += 1) {	// L2328
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1730
        #pragma HLS dependence false variable=v1731
        float v1735 = v1730[0][v1732][v1733][v1734];	// L2329
        v1731[0][v1732][v1733][v1734] = v1735;	// L2330
      }
    }
  }
}

void kernel292(
  float v1736[1][192][32][32],
  float v1737[1][192][32][32],
  float v1738
) {	// L2336
  ap_int<32> v1739[6144];	// L2370
  #pragma HLS resource variable=v1739 core=ram_t2p_bram

  for (int v1740 = 0; v1740 < 6144; v1740 += 1) {	// L2371
    float v1741 = v1736[0][(v1740 / 32)][(v1740 % 32)][0];	// L2372
    bool v1742 = v1741 != (float)0.000000;	// L2373
    ap_int<32> v1743 = v1742;	// L2374
    float v1744 = v1736[0][(v1740 / 32)][(v1740 % 32)][1];	// L2375
    bool v1745 = v1744 != (float)0.000000;	// L2376
    ap_int<32> v1746 = v1745;	// L2377
    ap_int<32> v1747 = v1746 << (ap_int<32>)1;	// L2378
    ap_int<32> v1748 = v1743 | v1747;	// L2379
    float v1749 = v1736[0][(v1740 / 32)][(v1740 % 32)][2];	// L2380
    bool v1750 = v1749 != (float)0.000000;	// L2381
    ap_int<32> v1751 = v1750;	// L2382
    ap_int<32> v1752 = v1751 << (ap_int<32>)2;	// L2383
    ap_int<32> v1753 = v1748 | v1752;	// L2384
    float v1754 = v1736[0][(v1740 / 32)][(v1740 % 32)][3];	// L2385
    bool v1755 = v1754 != (float)0.000000;	// L2386
    ap_int<32> v1756 = v1755;	// L2387
    ap_int<32> v1757 = v1756 << (ap_int<32>)3;	// L2388
    ap_int<32> v1758 = v1753 | v1757;	// L2389
    float v1759 = v1736[0][(v1740 / 32)][(v1740 % 32)][4];	// L2390
    bool v1760 = v1759 != (float)0.000000;	// L2391
    ap_int<32> v1761 = v1760;	// L2392
    ap_int<32> v1762 = v1761 << (ap_int<32>)4;	// L2393
    ap_int<32> v1763 = v1758 | v1762;	// L2394
    float v1764 = v1736[0][(v1740 / 32)][(v1740 % 32)][5];	// L2395
    bool v1765 = v1764 != (float)0.000000;	// L2396
    ap_int<32> v1766 = v1765;	// L2397
    ap_int<32> v1767 = v1766 << (ap_int<32>)5;	// L2398
    ap_int<32> v1768 = v1763 | v1767;	// L2399
    float v1769 = v1736[0][(v1740 / 32)][(v1740 % 32)][6];	// L2400
    bool v1770 = v1769 != (float)0.000000;	// L2401
    ap_int<32> v1771 = v1770;	// L2402
    ap_int<32> v1772 = v1771 << (ap_int<32>)6;	// L2403
    ap_int<32> v1773 = v1768 | v1772;	// L2404
    float v1774 = v1736[0][(v1740 / 32)][(v1740 % 32)][7];	// L2405
    bool v1775 = v1774 != (float)0.000000;	// L2406
    ap_int<32> v1776 = v1775;	// L2407
    ap_int<32> v1777 = v1776 << (ap_int<32>)7;	// L2408
    ap_int<32> v1778 = v1773 | v1777;	// L2409
    float v1779 = v1736[0][(v1740 / 32)][(v1740 % 32)][8];	// L2410
    bool v1780 = v1779 != (float)0.000000;	// L2411
    ap_int<32> v1781 = v1780;	// L2412
    ap_int<32> v1782 = v1781 << (ap_int<32>)8;	// L2413
    ap_int<32> v1783 = v1778 | v1782;	// L2414
    float v1784 = v1736[0][(v1740 / 32)][(v1740 % 32)][9];	// L2415
    bool v1785 = v1784 != (float)0.000000;	// L2416
    ap_int<32> v1786 = v1785;	// L2417
    ap_int<32> v1787 = v1786 << (ap_int<32>)9;	// L2418
    ap_int<32> v1788 = v1783 | v1787;	// L2419
    float v1789 = v1736[0][(v1740 / 32)][(v1740 % 32)][10];	// L2420
    bool v1790 = v1789 != (float)0.000000;	// L2421
    ap_int<32> v1791 = v1790;	// L2422
    ap_int<32> v1792 = v1791 << (ap_int<32>)10;	// L2423
    ap_int<32> v1793 = v1788 | v1792;	// L2424
    float v1794 = v1736[0][(v1740 / 32)][(v1740 % 32)][11];	// L2425
    bool v1795 = v1794 != (float)0.000000;	// L2426
    ap_int<32> v1796 = v1795;	// L2427
    ap_int<32> v1797 = v1796 << (ap_int<32>)11;	// L2428
    ap_int<32> v1798 = v1793 | v1797;	// L2429
    float v1799 = v1736[0][(v1740 / 32)][(v1740 % 32)][12];	// L2430
    bool v1800 = v1799 != (float)0.000000;	// L2431
    ap_int<32> v1801 = v1800;	// L2432
    ap_int<32> v1802 = v1801 << (ap_int<32>)12;	// L2433
    ap_int<32> v1803 = v1798 | v1802;	// L2434
    float v1804 = v1736[0][(v1740 / 32)][(v1740 % 32)][13];	// L2435
    bool v1805 = v1804 != (float)0.000000;	// L2436
    ap_int<32> v1806 = v1805;	// L2437
    ap_int<32> v1807 = v1806 << (ap_int<32>)13;	// L2438
    ap_int<32> v1808 = v1803 | v1807;	// L2439
    float v1809 = v1736[0][(v1740 / 32)][(v1740 % 32)][14];	// L2440
    bool v1810 = v1809 != (float)0.000000;	// L2441
    ap_int<32> v1811 = v1810;	// L2442
    ap_int<32> v1812 = v1811 << (ap_int<32>)14;	// L2443
    ap_int<32> v1813 = v1808 | v1812;	// L2444
    float v1814 = v1736[0][(v1740 / 32)][(v1740 % 32)][15];	// L2445
    bool v1815 = v1814 != (float)0.000000;	// L2446
    ap_int<32> v1816 = v1815;	// L2447
    ap_int<32> v1817 = v1816 << (ap_int<32>)15;	// L2448
    ap_int<32> v1818 = v1813 | v1817;	// L2449
    float v1819 = v1736[0][(v1740 / 32)][(v1740 % 32)][16];	// L2450
    bool v1820 = v1819 != (float)0.000000;	// L2451
    ap_int<32> v1821 = v1820;	// L2452
    ap_int<32> v1822 = v1821 << (ap_int<32>)16;	// L2453
    ap_int<32> v1823 = v1818 | v1822;	// L2454
    float v1824 = v1736[0][(v1740 / 32)][(v1740 % 32)][17];	// L2455
    bool v1825 = v1824 != (float)0.000000;	// L2456
    ap_int<32> v1826 = v1825;	// L2457
    ap_int<32> v1827 = v1826 << (ap_int<32>)17;	// L2458
    ap_int<32> v1828 = v1823 | v1827;	// L2459
    float v1829 = v1736[0][(v1740 / 32)][(v1740 % 32)][18];	// L2460
    bool v1830 = v1829 != (float)0.000000;	// L2461
    ap_int<32> v1831 = v1830;	// L2462
    ap_int<32> v1832 = v1831 << (ap_int<32>)18;	// L2463
    ap_int<32> v1833 = v1828 | v1832;	// L2464
    float v1834 = v1736[0][(v1740 / 32)][(v1740 % 32)][19];	// L2465
    bool v1835 = v1834 != (float)0.000000;	// L2466
    ap_int<32> v1836 = v1835;	// L2467
    ap_int<32> v1837 = v1836 << (ap_int<32>)19;	// L2468
    ap_int<32> v1838 = v1833 | v1837;	// L2469
    float v1839 = v1736[0][(v1740 / 32)][(v1740 % 32)][20];	// L2470
    bool v1840 = v1839 != (float)0.000000;	// L2471
    ap_int<32> v1841 = v1840;	// L2472
    ap_int<32> v1842 = v1841 << (ap_int<32>)20;	// L2473
    ap_int<32> v1843 = v1838 | v1842;	// L2474
    float v1844 = v1736[0][(v1740 / 32)][(v1740 % 32)][21];	// L2475
    bool v1845 = v1844 != (float)0.000000;	// L2476
    ap_int<32> v1846 = v1845;	// L2477
    ap_int<32> v1847 = v1846 << (ap_int<32>)21;	// L2478
    ap_int<32> v1848 = v1843 | v1847;	// L2479
    float v1849 = v1736[0][(v1740 / 32)][(v1740 % 32)][22];	// L2480
    bool v1850 = v1849 != (float)0.000000;	// L2481
    ap_int<32> v1851 = v1850;	// L2482
    ap_int<32> v1852 = v1851 << (ap_int<32>)22;	// L2483
    ap_int<32> v1853 = v1848 | v1852;	// L2484
    float v1854 = v1736[0][(v1740 / 32)][(v1740 % 32)][23];	// L2485
    bool v1855 = v1854 != (float)0.000000;	// L2486
    ap_int<32> v1856 = v1855;	// L2487
    ap_int<32> v1857 = v1856 << (ap_int<32>)23;	// L2488
    ap_int<32> v1858 = v1853 | v1857;	// L2489
    float v1859 = v1736[0][(v1740 / 32)][(v1740 % 32)][24];	// L2490
    bool v1860 = v1859 != (float)0.000000;	// L2491
    ap_int<32> v1861 = v1860;	// L2492
    ap_int<32> v1862 = v1861 << (ap_int<32>)24;	// L2493
    ap_int<32> v1863 = v1858 | v1862;	// L2494
    float v1864 = v1736[0][(v1740 / 32)][(v1740 % 32)][25];	// L2495
    bool v1865 = v1864 != (float)0.000000;	// L2496
    ap_int<32> v1866 = v1865;	// L2497
    ap_int<32> v1867 = v1866 << (ap_int<32>)25;	// L2498
    ap_int<32> v1868 = v1863 | v1867;	// L2499
    float v1869 = v1736[0][(v1740 / 32)][(v1740 % 32)][26];	// L2500
    bool v1870 = v1869 != (float)0.000000;	// L2501
    ap_int<32> v1871 = v1870;	// L2502
    ap_int<32> v1872 = v1871 << (ap_int<32>)26;	// L2503
    ap_int<32> v1873 = v1868 | v1872;	// L2504
    float v1874 = v1736[0][(v1740 / 32)][(v1740 % 32)][27];	// L2505
    bool v1875 = v1874 != (float)0.000000;	// L2506
    ap_int<32> v1876 = v1875;	// L2507
    ap_int<32> v1877 = v1876 << (ap_int<32>)27;	// L2508
    ap_int<32> v1878 = v1873 | v1877;	// L2509
    float v1879 = v1736[0][(v1740 / 32)][(v1740 % 32)][28];	// L2510
    bool v1880 = v1879 != (float)0.000000;	// L2511
    ap_int<32> v1881 = v1880;	// L2512
    ap_int<32> v1882 = v1881 << (ap_int<32>)28;	// L2513
    ap_int<32> v1883 = v1878 | v1882;	// L2514
    float v1884 = v1736[0][(v1740 / 32)][(v1740 % 32)][29];	// L2515
    bool v1885 = v1884 != (float)0.000000;	// L2516
    ap_int<32> v1886 = v1885;	// L2517
    ap_int<32> v1887 = v1886 << (ap_int<32>)29;	// L2518
    ap_int<32> v1888 = v1883 | v1887;	// L2519
    float v1889 = v1736[0][(v1740 / 32)][(v1740 % 32)][30];	// L2520
    bool v1890 = v1889 != (float)0.000000;	// L2521
    ap_int<32> v1891 = v1890;	// L2522
    ap_int<32> v1892 = v1891 << (ap_int<32>)30;	// L2523
    ap_int<32> v1893 = v1888 | v1892;	// L2524
    float v1894 = v1736[0][(v1740 / 32)][(v1740 % 32)][31];	// L2525
    bool v1895 = v1894 != (float)0.000000;	// L2526
    ap_int<32> v1896 = v1895;	// L2527
    ap_int<32> v1897 = v1896 << (ap_int<32>)31;	// L2528
    ap_int<32> v1898 = v1893 | v1897;	// L2529
    v1739[v1740] = v1898;	// L2530
  }
  for (int v1899 = 0; v1899 < 192; v1899 += 1) {	// L2532
    for (int v1900 = 0; v1900 < 32; v1900 += 1) {	// L2533
      for (int v1901 = 0; v1901 < 32; v1901 += 1) {	// L2534
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1737
        #pragma HLS dependence false variable=v1739
        float v1902 = v1737[0][v1899][v1900][v1901];	// L2535
        ap_int<32> v1903 = v1739[((v1899 * 32) + v1900)];	// L2536
        ap_int<32> v1904 = v1901;	// L2537
        ap_int<32> v1905 = v1903 >> v1904;	// L2538
        ap_int<32> v1906 = v1905 & (ap_int<32>)1;	// L2539
        bool v1907 = v1906 != (ap_int<32>)0;	// L2540
        float v1908 = v1906;	// L2541
        float v1909 = v1908 * v1902;	// L2542
        float v1910 = v1902 - v1909;	// L2543
        float v1911 = v1910 + v1738;	// L2544
        float v1912 = v1907 ? v1911 : v1910;	// L2545
        v1737[0][v1899][v1900][v1901] = v1912;	// L2546
      }
    }
  }
}

void kernel293(
  float v1913[1][192][32][32],
  float v1914,
  float v1915
) {	// L2552
  for (int v1916 = 0; v1916 < 192; v1916 += 1) {	// L2553
    for (int v1917 = 0; v1917 < 32; v1917 += 1) {	// L2554
      for (int v1918 = 0; v1918 < 32; v1918 += 1) {	// L2555
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1913
        float v1919 = v1913[0][v1916][v1917][v1918];	// L2556
        float v1920 = v1919 - v1915;	// L2557
        bool v1921 = v1920 >= v1914;	// L2558
        float v1922 = v1921 ? v1915 : v1914;	// L2559
        v1913[0][v1916][v1917][v1918] = v1922;	// L2560
      }
    }
  }
}

void kernel295(
  float v1923[1][192][32][32],
  float v1924[1][192][32][32],
  float v1925
) {	// L2566
  for (int v1926 = 0; v1926 < 192; v1926 += 1) {	// L2567
    for (int v1927 = 0; v1927 < 32; v1927 += 1) {	// L2568
      for (int v1928 = 0; v1928 < 32; v1928 += 1) {	// L2569
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1923
        #pragma HLS dependence false variable=v1924
        float v1929 = v1923[0][v1926][v1927][v1928];	// L2570
        float v1930 = v1924[0][v1926][v1927][v1928];	// L2571
        float v1931 = v1930 / v1925;	// L2572
        float v1932 = v1929 / v1925;	// L2573
        float v1933 = v1929 - v1932;	// L2574
        float v1934 = v1933 + v1931;	// L2575
        v1924[0][v1926][v1927][v1928] = v1934;	// L2576
      }
    }
  }
}

void kernel296(
  float v1935[1][96][34][34],
  float v1936[192][96][3][3],
  float v1937[1][192][32][32]
) {	// L2582
  float v1938[1][192][32][32];	// L2583
  #pragma HLS resource variable=v1938 core=ram_t2p_uram

  memcpy(v1938, v1937, 196608 * sizeof(float));	// L2584

  auto v1939 = reinterpret_cast<float(*)[96][3][3]>(v1936);	// L2586

  for (int v1940 = 0; v1940 < 96; v1940 += 1) {	// L2587
    for (int v1941 = 0; v1941 < 3; v1941 += 1) {	// L2588
      for (int v1942 = 0; v1942 < 3; v1942 += 1) {	// L2589
        for (int v1943 = 0; v1943 < 192; v1943 += 1) {	// L2590
          float v1944 = v1939[v1943][v1940][v1941][v1942];	// L2591
          for (int v1945 = 0; v1945 < 32; v1945 += 1) {	// L2592
            for (int v1946 = 0; v1946 < 32; v1946 += 1) {	// L2593
              #pragma HLS pipeline II=1
              #pragma HLS dependence false variable=v1935
              #pragma HLS dependence false variable=v1938
              float v1947 = v1935[0][v1940][(v1945 + v1941)][(v1946 + v1942)];	// L2594
              float v1948 = v1938[0][v1943][v1945][v1946];	// L2595
              float v1949 = v1947 * v1944;	// L2596
              float v1950 = v1948 + v1949;	// L2597
              v1938[0][v1943][v1945][v1946] = v1950;	// L2598
            }
          }
        }
      }
    }
  }
  memcpy(v1937, v1938, 196608 * sizeof(float));	// L2605

}

void kernel297(
  float v1951[192],
  float v1952[1][192][32][32]
) {	// L2608
  float v1953[192];	// L2609
  #pragma HLS resource variable=v1953 core=ram_t2p_bram

  memcpy(v1953, v1951, 192 * sizeof(float));	// L2610

  for (int v1954 = 0; v1954 < 192; v1954 += 1) {	// L2611
    for (int v1955 = 0; v1955 < 32; v1955 += 1) {	// L2612
      for (int v1956 = 0; v1956 < 32; v1956 += 1) {	// L2613
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1953
        #pragma HLS dependence false variable=v1952
        float v1957 = v1953[v1954];	// L2614
        v1952[0][v1954][v1955][v1956] = v1957;	// L2615
      }
    }
  }
}

void kernel298(
  float v1958[1][96][32][32],
  float v1959[1][96][34][34]
) {	// L2621
  for (int v1960 = 0; v1960 < 96; v1960 += 1) {	// L2622
    for (int v1961 = 0; v1961 < 32; v1961 += 1) {	// L2623
      for (int v1962 = 0; v1962 < 32; v1962 += 1) {	// L2624
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1958
        #pragma HLS dependence false variable=v1959
        float v1963 = v1958[0][v1960][v1961][v1962];	// L2625
        v1959[0][v1960][(v1961 + 1)][(v1962 + 1)] = v1963;	// L2626
      }
    }
  }
}

void kernel299(
  float v1964[1][96][34][34],
  float v1965
) {	// L2632
  for (int v1966 = 0; v1966 < 96; v1966 += 1) {	// L2633
    for (int v1967 = 0; v1967 < 34; v1967 += 1) {	// L2634
      for (int v1968 = 0; v1968 < 34; v1968 += 1) {	// L2635
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1964
        v1964[0][v1966][v1967][v1968] = v1965;	// L2636
      }
    }
  }
}

void kernel300(
  float v1969[1][96][32][32],
  float v1970[1][96][32][32]
) {	// L2642
  for (int v1971 = 0; v1971 < 96; v1971 += 1) {	// L2643
    for (int v1972 = 0; v1972 < 32; v1972 += 1) {	// L2644
      for (int v1973 = 0; v1973 < 32; v1973 += 1) {	// L2645
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1969
        #pragma HLS dependence false variable=v1970
        float v1974 = v1969[0][v1971][v1972][v1973];	// L2646
        v1970[0][v1971][v1972][v1973] = v1974;	// L2647
      }
    }
  }
}

void kernel301(
  float v1975[1][96][32][32],
  float v1976[1][96][32][32],
  float v1977
) {	// L2653
  for (int v1978 = 0; v1978 < 96; v1978 += 1) {	// L2655
    for (int v1979 = 0; v1979 < 32; v1979 += 1) {	// L2656
      for (int v1980 = 0; v1980 < 32; v1980 += 1) {	// L2657
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1976
        #pragma HLS dependence false variable=v1975
        float v1981 = v1976[0][v1978][v1979][v1980];	// L2658
        float v1982 = v1975[0][v1978][v1979][v1980];	// L2659
        float v1983 = v1982 * v1981;	// L2660
        float v1984 = v1981 - v1983;	// L2661
        bool v1985 = v1982 != (float)0.000000;	// L2662
        float v1986 = v1984 + v1977;	// L2663
        float v1987 = v1985 ? v1986 : v1984;	// L2664
        v1976[0][v1978][v1979][v1980] = v1987;	// L2665
      }
    }
  }
}

void kernel302(
  float v1988[1][96][32][32],
  float v1989,
  float v1990
) {	// L2671
  for (int v1991 = 0; v1991 < 96; v1991 += 1) {	// L2672
    for (int v1992 = 0; v1992 < 32; v1992 += 1) {	// L2673
      for (int v1993 = 0; v1993 < 32; v1993 += 1) {	// L2674
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1988
        float v1994 = v1988[0][v1991][v1992][v1993];	// L2675
        float v1995 = v1994 - v1990;	// L2676
        bool v1996 = v1995 >= v1989;	// L2677
        float v1997 = v1996 ? v1990 : v1989;	// L2678
        v1988[0][v1991][v1992][v1993] = v1997;	// L2679
      }
    }
  }
}

void kernel304(
  float v1998[1][96][32][32],
  float v1999[1][96][32][32],
  float v2000
) {	// L2685
  for (int v2001 = 0; v2001 < 96; v2001 += 1) {	// L2686
    for (int v2002 = 0; v2002 < 32; v2002 += 1) {	// L2687
      for (int v2003 = 0; v2003 < 32; v2003 += 1) {	// L2688
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v1998
        #pragma HLS dependence false variable=v1999
        float v2004 = v1998[0][v2001][v2002][v2003];	// L2689
        float v2005 = v1999[0][v2001][v2002][v2003];	// L2690
        float v2006 = v2005 / v2000;	// L2691
        float v2007 = v2004 / v2000;	// L2692
        float v2008 = v2004 - v2007;	// L2693
        float v2009 = v2008 + v2006;	// L2694
        v1999[0][v2001][v2002][v2003] = v2009;	// L2695
      }
    }
  }
}

void kernel305(
  float v2010[1][48][34][34],
  float v2011[96][48][3][3],
  float v2012[1][96][32][32]
) {	// L2701
  auto v2013 = reinterpret_cast<float(*)[48][3][3]>(v2011);	// L2703

  for (int v2014 = 0; v2014 < 48; v2014 += 1) {	// L2704
    for (int v2015 = 0; v2015 < 3; v2015 += 1) {	// L2705
      for (int v2016 = 0; v2016 < 3; v2016 += 1) {	// L2706
        for (int v2017 = 0; v2017 < 96; v2017 += 1) {	// L2707
          float v2018 = v2013[v2017][v2014][v2015][v2016];	// L2708
          for (int v2019 = 0; v2019 < 32; v2019 += 1) {	// L2709
            for (int v2020 = 0; v2020 < 32; v2020 += 1) {	// L2710
              #pragma HLS pipeline II=1
              #pragma HLS dependence false variable=v2010
              #pragma HLS dependence false variable=v2012
              float v2021 = v2010[0][v2014][(v2019 + v2015)][(v2020 + v2016)];	// L2711
              float v2022 = v2012[0][v2017][v2019][v2020];	// L2712
              float v2023 = v2021 * v2018;	// L2713
              float v2024 = v2022 + v2023;	// L2714
              v2012[0][v2017][v2019][v2020] = v2024;	// L2715
            }
          }
        }
      }
    }
  }
}

void kernel306(
  float v2025[96],
  float v2026[1][96][32][32]
) {	// L2724
  float v2027[96];	// L2725
  #pragma HLS resource variable=v2027 core=ram_t2p_bram

  memcpy(v2027, v2025, 96 * sizeof(float));	// L2726

  for (int v2028 = 0; v2028 < 96; v2028 += 1) {	// L2727
    for (int v2029 = 0; v2029 < 32; v2029 += 1) {	// L2728
      for (int v2030 = 0; v2030 < 32; v2030 += 1) {	// L2729
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v2027
        #pragma HLS dependence false variable=v2026
        float v2031 = v2027[v2028];	// L2730
        v2026[0][v2028][v2029][v2030] = v2031;	// L2731
      }
    }
  }
}

void kernel307(
  float v2032[1][48][32][32],
  float v2033[1][48][34][34]
) {	// L2737
  for (int v2034 = 0; v2034 < 48; v2034 += 1) {	// L2738
    for (int v2035 = 0; v2035 < 32; v2035 += 1) {	// L2739
      for (int v2036 = 0; v2036 < 32; v2036 += 1) {	// L2740
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v2032
        #pragma HLS dependence false variable=v2033
        float v2037 = v2032[0][v2034][v2035][v2036];	// L2741
        v2033[0][v2034][(v2035 + 1)][(v2036 + 1)] = v2037;	// L2742
      }
    }
  }
}

void kernel308(
  float v2038[1][48][34][34],
  float v2039
) {	// L2748
  for (int v2040 = 0; v2040 < 48; v2040 += 1) {	// L2749
    for (int v2041 = 0; v2041 < 34; v2041 += 1) {	// L2750
      for (int v2042 = 0; v2042 < 34; v2042 += 1) {	// L2751
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v2038
        v2038[0][v2040][v2041][v2042] = v2039;	// L2752
      }
    }
  }
}

void kernel309(
  float v2043[1][48][32][32],
  float v2044[1][48][32][32]
) {	// L2758
  for (int v2045 = 0; v2045 < 48; v2045 += 1) {	// L2759
    for (int v2046 = 0; v2046 < 32; v2046 += 1) {	// L2760
      for (int v2047 = 0; v2047 < 32; v2047 += 1) {	// L2761
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v2043
        #pragma HLS dependence false variable=v2044
        float v2048 = v2043[0][v2045][v2046][v2047];	// L2762
        v2044[0][v2045][v2046][v2047] = v2048;	// L2763
      }
    }
  }
}

void kernel310(
  float v2049[1][48][32][32],
  float v2050[1][48][32][32],
  float v2051
) {	// L2769
  for (int v2052 = 0; v2052 < 48; v2052 += 1) {	// L2771
    for (int v2053 = 0; v2053 < 32; v2053 += 1) {	// L2772
      for (int v2054 = 0; v2054 < 32; v2054 += 1) {	// L2773
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v2050
        #pragma HLS dependence false variable=v2049
        float v2055 = v2050[0][v2052][v2053][v2054];	// L2774
        float v2056 = v2049[0][v2052][v2053][v2054];	// L2775
        float v2057 = v2056 * v2055;	// L2776
        float v2058 = v2055 - v2057;	// L2777
        bool v2059 = v2056 != (float)0.000000;	// L2778
        float v2060 = v2058 + v2051;	// L2779
        float v2061 = v2059 ? v2060 : v2058;	// L2780
        v2050[0][v2052][v2053][v2054] = v2061;	// L2781
      }
    }
  }
}

void kernel311(
  float v2062[1][48][32][32],
  float v2063,
  float v2064
) {	// L2787
  for (int v2065 = 0; v2065 < 48; v2065 += 1) {	// L2788
    for (int v2066 = 0; v2066 < 32; v2066 += 1) {	// L2789
      for (int v2067 = 0; v2067 < 32; v2067 += 1) {	// L2790
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v2062
        float v2068 = v2062[0][v2065][v2066][v2067];	// L2791
        float v2069 = v2068 - v2064;	// L2792
        bool v2070 = v2069 >= v2063;	// L2793
        float v2071 = v2070 ? v2064 : v2063;	// L2794
        v2062[0][v2065][v2066][v2067] = v2071;	// L2795
      }
    }
  }
}

void kernel313(
  float v2072[1][48][32][32],
  float v2073[1][48][32][32],
  float v2074
) {	// L2801
  for (int v2075 = 0; v2075 < 48; v2075 += 1) {	// L2802
    for (int v2076 = 0; v2076 < 32; v2076 += 1) {	// L2803
      for (int v2077 = 0; v2077 < 32; v2077 += 1) {	// L2804
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v2072
        #pragma HLS dependence false variable=v2073
        float v2078 = v2072[0][v2075][v2076][v2077];	// L2805
        float v2079 = v2073[0][v2075][v2076][v2077];	// L2806
        float v2080 = v2079 / v2074;	// L2807
        float v2081 = v2078 / v2074;	// L2808
        float v2082 = v2078 - v2081;	// L2809
        float v2083 = v2082 + v2080;	// L2810
        v2073[0][v2075][v2076][v2077] = v2083;	// L2811
      }
    }
  }
}

void kernel314(
  float v2084[1][3][34][34],
  float v2085[48][3][3][3],
  float v2086[1][48][32][32]
) {	// L2817
  float v2087[1][3][34][34];	// L2818
  #pragma HLS resource variable=v2087 core=ram_t2p_bram

  memcpy(v2087, v2084, 3468 * sizeof(float));	// L2819

  float v2088[48][3][3][3];	// L2820
  #pragma HLS resource variable=v2088 core=ram_t2p_bram

  memcpy(v2088, v2085, 1296 * sizeof(float));	// L2821

  for (int v2089 = 0; v2089 < 3; v2089 += 1) {	// L2822
    for (int v2090 = 0; v2090 < 3; v2090 += 1) {	// L2823
      for (int v2091 = 0; v2091 < 3; v2091 += 1) {	// L2824
        for (int v2092 = 0; v2092 < 48; v2092 += 1) {	// L2825
          for (int v2093 = 0; v2093 < 32; v2093 += 1) {	// L2826
            for (int v2094 = 0; v2094 < 32; v2094 += 1) {	// L2827
              #pragma HLS pipeline II=1
              #pragma HLS dependence false variable=v2087
              #pragma HLS dependence false variable=v2086
              #pragma HLS dependence false variable=v2088
              float v2095 = v2087[0][v2089][(v2093 + v2090)][(v2094 + v2091)];	// L2828
              float v2096 = v2088[v2092][v2089][v2090][v2091];	// L2829
              float v2097 = v2086[0][v2092][v2093][v2094];	// L2830
              float v2098 = v2095 * v2096;	// L2831
              float v2099 = v2097 + v2098;	// L2832
              v2086[0][v2092][v2093][v2094] = v2099;	// L2833
            }
          }
        }
      }
    }
  }
}

void kernel315(
  float v2100[48],
  float v2101[1][48][32][32]
) {	// L2842
  float v2102[48];	// L2843
  #pragma HLS resource variable=v2102 core=ram_t2p_bram

  memcpy(v2102, v2100, 48 * sizeof(float));	// L2844

  for (int v2103 = 0; v2103 < 48; v2103 += 1) {	// L2845
    for (int v2104 = 0; v2104 < 32; v2104 += 1) {	// L2846
      for (int v2105 = 0; v2105 < 32; v2105 += 1) {	// L2847
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v2102
        #pragma HLS dependence false variable=v2101
        float v2106 = v2102[v2103];	// L2848
        v2101[0][v2103][v2104][v2105] = v2106;	// L2849
      }
    }
  }
}

void kernel316(
  float v2107[1][3][32][32],
  float v2108[1][3][34][34]
) {	// L2855
  for (int v2109 = 0; v2109 < 3; v2109 += 1) {	// L2856
    for (int v2110 = 0; v2110 < 32; v2110 += 1) {	// L2857
      for (int v2111 = 0; v2111 < 32; v2111 += 1) {	// L2858
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v2107
        #pragma HLS dependence false variable=v2108
        float v2112 = v2107[0][v2109][v2110][v2111];	// L2859
        v2108[0][v2109][(v2110 + 1)][(v2111 + 1)] = v2112;	// L2860
      }
    }
  }
}

void kernel317(
  float v2113[1][3][34][34],
  float v2114
) {	// L2866
  for (int v2115 = 0; v2115 < 3; v2115 += 1) {	// L2867
    for (int v2116 = 0; v2116 < 34; v2116 += 1) {	// L2868
      for (int v2117 = 0; v2117 < 34; v2117 += 1) {	// L2869
        #pragma HLS pipeline II=1
        #pragma HLS dependence false variable=v2113
        v2113[0][v2115][v2116][v2117] = v2114;	// L2870
      }
    }
  }
}

/// The top function
void control(
  ap_int<32> v2118[89418240],
  ap_int<32> v2119[89418240],
  ap_int<32> v2120[89418240]
) {	// L2876
  #pragma HLS interface s_axilite port=return bundle=ctrl
  #pragma hls interface m_axi offset=direct bundle=g0 port=v2118
  #pragma hls stable variable=v2118
  #pragma hls interface m_axi offset=direct bundle=g0 port=v2119
  #pragma hls stable variable=v2119
  #pragma hls interface m_axi offset=direct bundle=g0 port=v2120
  #pragma hls stable variable=v2120

  auto v2121 = reinterpret_cast<float(*)[3][34][34]>(v2119 + 6684672);
  kernel317(v2121, (float)0.000000);	// L2885
  auto v2122 = reinterpret_cast<float(*)[3][32][32]>(v2118);
  kernel316(v2122, v2121);	// L2887
  auto v2123 = reinterpret_cast<float(*)[48][32][32]>(v2118 + 6906624);
  auto v2124 = reinterpret_cast<float(*)>(v2120 + 86764032);
  kernel315(v2124, v2123);	// L2890
  auto v2125 = reinterpret_cast<float(*)[3][3][3]>(v2120 + 88091136);
  kernel314(v2121, v2125, v2123);	// L2892
  auto v2126 = reinterpret_cast<float(*)[48][32][32]>(v2118 + 196608);
  kernel313(v2126, v2123, (float)2.000000);	// L2894
  auto v2127 = reinterpret_cast<float(*)[48][32][32]>(v2118 + 6684672);
  kernel309(v2123, v2127);	// L2896
  kernel311(v2127, (float)0.000000, (float)1.000000);	// L2897
  kernel310(v2127, v2123, (float)0.000000);	// L2898
  kernel309(v2123, v2126);	// L2899
  auto v2128 = reinterpret_cast<float(*)[48][34][34]>(v2119 + 6906624);
  kernel308(v2128, (float)0.000000);	// L2901
  kernel307(v2127, v2128);	// L2902
  auto v2129 = reinterpret_cast<float(*)[96][32][32]>(v2119 + 6684672);
  auto v2130 = reinterpret_cast<float(*)>(v2120 + 84109824);
  kernel306(v2130, v2129);	// L2905
  auto v2131 = reinterpret_cast<float(*)[48][3][3]>(v2120 + 85436928);
  kernel305(v2128, v2131, v2129);	// L2907
  auto v2132 = reinterpret_cast<float(*)[96][32][32]>(v2118 + 393216);
  kernel304(v2132, v2129, (float)2.000000);	// L2909
  auto v2133 = reinterpret_cast<float(*)[96][32][32]>(v2118 + 6906624);
  kernel300(v2129, v2133);	// L2911
  kernel302(v2133, (float)0.000000, (float)1.000000);	// L2912
  kernel301(v2133, v2129, (float)0.000000);	// L2913
  kernel300(v2129, v2132);	// L2914
  auto v2134 = reinterpret_cast<float(*)[96][34][34]>(v2119 + 6684672);
  kernel299(v2134, (float)0.000000);	// L2916
  kernel298(v2133, v2134);	// L2917
  auto v2135 = reinterpret_cast<float(*)[192][32][32]>(v2119 + 6906624);
  auto v2136 = reinterpret_cast<float(*)>(v2120 + 81455616);
  kernel297(v2136, v2135);	// L2920
  auto v2137 = reinterpret_cast<float(*)[96][3][3]>(v2120 + 82782720);
  kernel296(v2134, v2137, v2135);	// L2922
  auto v2138 = reinterpret_cast<float(*)[192][32][32]>(v2118 + 589824);
  kernel295(v2138, v2135, (float)2.000000);	// L2924
  auto v2139 = reinterpret_cast<float(*)[192][32][32]>(v2119 + 6684672);
  kernel291(v2135, v2139);	// L2926
  kernel293(v2139, (float)0.000000, (float)1.000000);	// L2927
  kernel292(v2139, v2135, (float)0.000000);	// L2928
  kernel291(v2135, v2138);	// L2929
  auto v2140 = reinterpret_cast<float(*)[192][34][34]>(v2118 + 6906624);
  kernel290(v2140, (float)-INFINITY);	// L2931
  kernel289(v2139, v2140);	// L2932
  auto v2141 = reinterpret_cast<float(*)[192][16][16]>(v2119 + 6684672);
  kernel288(v2141, (float)-INFINITY);	// L2934
  auto v2142 = reinterpret_cast<float(*)[3]>(v2120 + 7128576);
  kernel287(v2140, v2142, v2141);	// L2936
  auto v2143 = reinterpret_cast<float(*)[192][18][18]>(v2118 + 6906624);
  kernel286(v2143, (float)0.000000);	// L2938
  kernel285(v2141, v2143);	// L2939
  auto v2144 = reinterpret_cast<float(*)[384][16][16]>(v2119 + 6684672);
  auto v2145 = reinterpret_cast<float(*)>(v2120 + 78801408);
  kernel284(v2145, v2144);	// L2942
  auto v2146 = reinterpret_cast<float(*)[192][3][3]>(v2120 + 80128512);
  kernel283(v2143, v2146, v2144);	// L2944
  auto v2147 = reinterpret_cast<float(*)[384][16][16]>(v2118 + 786432);
  kernel282(v2147, v2144, (float)2.000000);	// L2946
  auto v2148 = reinterpret_cast<float(*)[384][16][16]>(v2118 + 6906624);
  kernel278(v2144, v2148);	// L2948
  kernel280(v2148, (float)0.000000, (float)1.000000);	// L2949
  kernel279(v2148, v2144, (float)0.000000);	// L2950
  kernel278(v2144, v2147);	// L2951
  auto v2149 = reinterpret_cast<float(*)[384][18][18]>(v2119 + 6684672);
  kernel277(v2149, (float)-INFINITY);	// L2953
  kernel276(v2148, v2149);	// L2954
  auto v2150 = reinterpret_cast<float(*)[384][8][8]>(v2118 + 6906624);
  kernel275(v2150, (float)-INFINITY);	// L2956
  kernel274(v2149, v2142, v2150);	// L2957
  auto v2151 = reinterpret_cast<float(*)[384][10][10]>(v2118 + 6684672);
  kernel273(v2151, (float)0.000000);	// L2959
  kernel272(v2150, v2151);	// L2960
  auto v2152 = reinterpret_cast<float(*)[384][8][8]>(v2120 + 7128576);
  auto v2153 = reinterpret_cast<float(*)>(v2119 + 76147200);
  kernel8(v2153, v2152);	// L2963
  auto v2154 = reinterpret_cast<float(*)[384][3][3]>(v2119 + 77474304);
  kernel270(v2151, v2154, v2152);	// L2965
  auto v2155 = reinterpret_cast<float(*)[384][8][8]>(v2118 + 983040);
  kernel20(v2155, v2152, v2150, (float)2.000000);	// L2967
  auto v2156 = reinterpret_cast<float(*)[384][8][8]>(v2119 + 6684672);
  kernel16(v2150, v2156);	// L2969
  kernel18(v2156, (float)0.000000, (float)1.000000);	// L2970
  kernel17(v2156, v2150, (float)0.000000);	// L2971
  kernel16(v2150, v2155);	// L2972
  auto v2157 = reinterpret_cast<float(*)[384][64]>(v2118 + 7350528);
  auto v2158 = reinterpret_cast<float(*)>(v2120 + 73492992);
  kernel23(v2158, v2157);	// L2975
  auto v2159 = reinterpret_cast<float(*)[384][1]>(v2120 + 74820096);
  kernel47(v2156, v2159, v2157);	// L2977
  auto v2160 = reinterpret_cast<float(*)[384][64]>(v2118 + 1179648);
  kernel46(v2160, v2157, (float)2.000000);	// L2979
  auto v2161 = reinterpret_cast<float(*)[384][64]>(v2119 + 7572480);
  kernel42(v2157, v2161);	// L2981
  kernel44(v2161, (float)0.000000, (float)1.000000);	// L2982
  kernel43(v2161, v2157, (float)0.000000);	// L2983
  kernel42(v2157, v2160);	// L2984
  auto v2162 = reinterpret_cast<float(*)[64][12][32]>(v2118 + 7794432);
  kernel41(v2161, v2162);	// L2986
  auto v2163 = reinterpret_cast<float(*)[12][64][32]>(v2118 + 7572480);
  kernel40(v2162, v2163);	// L2988
  auto v2164 = reinterpret_cast<float(*)>(v2120 + 70838784);
  kernel23(v2164, v2157);	// L2990
  auto v2165 = reinterpret_cast<float(*)[384][1]>(v2120 + 72165888);
  kernel47(v2156, v2165, v2157);	// L2992
  auto v2166 = reinterpret_cast<float(*)[384][64]>(v2118 + 1376256);
  kernel46(v2166, v2157, (float)2.000000);	// L2994
  auto v2167 = reinterpret_cast<float(*)[384][64]>(v2119 + 7794432);
  kernel42(v2157, v2167);	// L2996
  kernel44(v2167, (float)0.000000, (float)1.000000);	// L2997
  kernel43(v2167, v2157, (float)0.000000);	// L2998
  kernel42(v2157, v2166);	// L2999
  auto v2168 = reinterpret_cast<float(*)[64][12][32]>(v2119 + 8016384);
  kernel41(v2167, v2168);	// L3001
  auto v2169 = reinterpret_cast<float(*)>(v2120 + 68184576);
  kernel23(v2169, v2157);	// L3003
  auto v2170 = reinterpret_cast<float(*)[384][1]>(v2120 + 69511680);
  kernel47(v2156, v2170, v2157);	// L3005
  auto v2171 = reinterpret_cast<float(*)[384][64]>(v2118 + 1572864);
  kernel46(v2171, v2157, (float)2.000000);	// L3007
  auto v2172 = reinterpret_cast<float(*)[384][64]>(v2119 + 6684672);
  kernel42(v2157, v2172);	// L3009
  kernel44(v2172, (float)0.000000, (float)1.000000);	// L3010
  kernel43(v2172, v2157, (float)0.000000);	// L3011
  kernel42(v2157, v2171);	// L3012
  auto v2173 = reinterpret_cast<float(*)[64][12][32]>(v2119 + 7794432);
  kernel41(v2172, v2173);	// L3014
  auto v2174 = reinterpret_cast<float(*)[12][64][32]>(v2118 + 8238336);
  kernel40(v2173, v2174);	// L3016
  auto v2175 = reinterpret_cast<float(*)[12][32][64]>(v2118 + 6684672);
  kernel39(v2168, v2175);	// L3018
  auto v2176 = reinterpret_cast<float(*)[1][12][64][32]>(v2119 + 7794432);
  kernel35(v2163, v2176);	// L3020
  auto v2177 = reinterpret_cast<float(*)[1][12][32][64]>(v2119 + 7572480);
  kernel37(v2175, v2177);	// L3022
  auto v2178 = reinterpret_cast<float(*)[64][64]>(v2118 + 8016384);
  kernel235(v2178, (float)0.000000);	// L3024
  auto v2179 = reinterpret_cast<float(*)[64][64]>(v2118 + 8460288);
  kernel102(v2178, v2179);	// L3026
  kernel36(v2176, v2177, v2179);	// L3027
  auto v2180 = reinterpret_cast<float(*)[1][12][64][32]>(v2119 + 7572480);
  kernel35(v2174, v2180);	// L3029
  auto v2181 = reinterpret_cast<float(*)[64][32]>(v2119 + 7794432);
  kernel231(v2181, (float)0.000000);	// L3031
  kernel33(v2180, v2179, v2181);	// L3032
  kernel32(v2181, v2174);	// L3033
  kernel31(v2174, (float)0.125000);	// L3034
  auto v2182 = reinterpret_cast<float(*)[64][12][32]>(v2119 + 7572480);
  kernel30(v2174, v2182);	// L3036
  auto v2183 = reinterpret_cast<float(*)[64][384]>(v2118 + 1769472);
  auto v2184 = reinterpret_cast<float(*)[64][12][32]>(v2120 + 8460288);
  kernel29(v2183, v2182, v2184, (float)2.000000);	// L3039
  auto v2185 = reinterpret_cast<float(*)[64][384]>(v2118 + 8682240);
  kernel28(v2184, v2185);	// L3041
  kernel27(v2185, (float)1.000000, (float)0.500000, (float)0.000000);	// L3042
  auto v2186 = reinterpret_cast<float(*)[64][384]>(v2119 + 8904192);
  kernel26(v2184, v2185, v2186, (float)0.000000);	// L3044
  kernel25(v2186, v2183);	// L3045
  auto v2187 = reinterpret_cast<float(*)[384][64]>(v2119 + 8460288);
  kernel24(v2185, v2187);	// L3047
  auto v2188 = reinterpret_cast<float(*)>(v2120 + 65530368);
  kernel23(v2188, v2157);	// L3049
  auto v2189 = reinterpret_cast<float(*)[384][1]>(v2120 + 66857472);
  kernel22(v2187, v2189, v2157);	// L3051
  auto v2190 = reinterpret_cast<float(*)[384][8][8]>(v2119 + 8460288);
  kernel21(v2157, v2152, v2190);	// L3053
  auto v2191 = reinterpret_cast<float(*)[384][8][8]>(v2118 + 1966080);
  kernel20(v2191, v2190, v2150, (float)2.000000);	// L3055
  auto v2192 = reinterpret_cast<float(*)[384][8][8]>(v2119 + 7128576);
  kernel16(v2150, v2192);	// L3057
  kernel18(v2192, (float)0.000000, (float)1.000000);	// L3058
  kernel17(v2192, v2150, (float)0.000000);	// L3059
  kernel16(v2150, v2191);	// L3060
  auto v2193 = reinterpret_cast<float(*)[1536][8][8]>(v2118 + 8682240);
  auto v2194 = reinterpret_cast<float(*)>(v2120 + 62876160);
  kernel15(v2194, v2193);	// L3063
  auto v2195 = reinterpret_cast<float(*)[384][1][1]>(v2120 + 64203264);
  kernel14(v2192, v2195, v2193);	// L3065
  auto v2196 = reinterpret_cast<float(*)[1536][8][8]>(v2118 + 2162688);
  kernel13(v2196, v2193, (float)2.000000);	// L3067
  auto v2197 = reinterpret_cast<float(*)[1536][8][8]>(v2119 + 7128576);
  kernel9(v2193, v2197);	// L3069
  kernel11(v2197, (float)0.000000, (float)1.000000);	// L3070
  kernel10(v2197, v2193, (float)0.000000);	// L3071
  kernel9(v2193, v2196);	// L3072
  auto v2198 = reinterpret_cast<float(*)>(v2120 + 60221952);
  kernel8(v2198, v2150);	// L3074
  auto v2199 = reinterpret_cast<float(*)[1536][1][1]>(v2120 + 61549056);
  kernel7(v2197, v2199, v2150);	// L3076
  kernel71(v2150, v2190, v2152);	// L3077
  auto v2200 = reinterpret_cast<float(*)[384][8][8]>(v2118 + 2359296);
  kernel20(v2200, v2152, v2150, (float)2.000000);	// L3079
  kernel16(v2150, v2190);	// L3080
  kernel18(v2190, (float)0.000000, (float)1.000000);	// L3081
  kernel17(v2190, v2150, (float)0.000000);	// L3082
  kernel16(v2150, v2200);	// L3083
  auto v2201 = reinterpret_cast<float(*)>(v2120 + 57567744);
  kernel23(v2201, v2157);	// L3085
  auto v2202 = reinterpret_cast<float(*)[384][1]>(v2120 + 58894848);
  kernel47(v2190, v2202, v2157);	// L3087
  auto v2203 = reinterpret_cast<float(*)[384][64]>(v2118 + 2555904);
  kernel46(v2203, v2157, (float)2.000000);	// L3089
  auto v2204 = reinterpret_cast<float(*)[384][64]>(v2119 + 9126144);
  kernel42(v2157, v2204);	// L3091
  kernel44(v2204, (float)0.000000, (float)1.000000);	// L3092
  kernel43(v2204, v2157, (float)0.000000);	// L3093
  kernel42(v2157, v2203);	// L3094
  auto v2205 = reinterpret_cast<float(*)[64][12][32]>(v2118 + 9348096);
  kernel41(v2204, v2205);	// L3096
  auto v2206 = reinterpret_cast<float(*)[12][64][32]>(v2119 + 9126144);
  kernel40(v2205, v2206);	// L3098
  auto v2207 = reinterpret_cast<float(*)>(v2120 + 54913536);
  kernel23(v2207, v2157);	// L3100
  auto v2208 = reinterpret_cast<float(*)[384][1]>(v2120 + 56240640);
  kernel47(v2190, v2208, v2157);	// L3102
  auto v2209 = reinterpret_cast<float(*)[384][64]>(v2118 + 2752512);
  kernel46(v2209, v2157, (float)2.000000);	// L3104
  auto v2210 = reinterpret_cast<float(*)[384][64]>(v2119 + 9348096);
  kernel42(v2157, v2210);	// L3106
  kernel44(v2210, (float)0.000000, (float)1.000000);	// L3107
  kernel43(v2210, v2157, (float)0.000000);	// L3108
  kernel42(v2157, v2209);	// L3109
  auto v2211 = reinterpret_cast<float(*)[64][12][32]>(v2118 + 9570048);
  kernel41(v2210, v2211);	// L3111
  auto v2212 = reinterpret_cast<float(*)>(v2120 + 52259328);
  kernel23(v2212, v2157);	// L3113
  auto v2213 = reinterpret_cast<float(*)[384][1]>(v2120 + 53586432);
  kernel47(v2190, v2213, v2157);	// L3115
  auto v2214 = reinterpret_cast<float(*)[384][64]>(v2118 + 2949120);
  kernel46(v2214, v2157, (float)2.000000);	// L3117
  auto v2215 = reinterpret_cast<float(*)[384][64]>(v2118 + 8460288);
  kernel42(v2157, v2215);	// L3119
  kernel44(v2215, (float)0.000000, (float)1.000000);	// L3120
  kernel43(v2215, v2157, (float)0.000000);	// L3121
  kernel42(v2157, v2214);	// L3122
  auto v2216 = reinterpret_cast<float(*)[64][12][32]>(v2119 + 9348096);
  kernel41(v2215, v2216);	// L3124
  kernel40(v2216, v2174);	// L3125
  kernel39(v2211, v2175);	// L3126
  auto v2217 = reinterpret_cast<float(*)[1][12][64][32]>(v2119 + 8460288);
  kernel35(v2206, v2217);	// L3128
  auto v2218 = reinterpret_cast<float(*)[1][12][32][64]>(v2120 + 9126144);
  kernel37(v2175, v2218);	// L3130
  auto v2219 = reinterpret_cast<float(*)[64][64]>(v2118 + 9348096);
  kernel102(v2178, v2219);	// L3132
  kernel36(v2217, v2218, v2219);	// L3133
  auto v2220 = reinterpret_cast<float(*)[1][12][64][32]>(v2120 + 8460288);
  kernel35(v2174, v2220);	// L3135
  kernel165(v2181, (float)0.000000);	// L3136
  kernel33(v2220, v2219, v2181);	// L3137
  kernel32(v2181, v2174);	// L3138
  kernel31(v2174, (float)0.125000);	// L3139
  kernel30(v2174, v2182);	// L3140
  auto v2221 = reinterpret_cast<float(*)[64][384]>(v2118 + 3145728);
  auto v2222 = reinterpret_cast<float(*)[64][12][32]>(v2118 + 8460288);
  kernel29(v2221, v2182, v2222, (float)2.000000);	// L3143
  auto v2223 = reinterpret_cast<float(*)[64][384]>(v2119 + 9126144);
  kernel28(v2222, v2223);	// L3145
  kernel27(v2223, (float)1.000000, (float)0.500000, (float)0.000000);	// L3146
  kernel26(v2222, v2223, v2186, (float)0.000000);	// L3147
  kernel25(v2186, v2221);	// L3148
  kernel24(v2223, v2215);	// L3149
  auto v2224 = reinterpret_cast<float(*)>(v2120 + 49605120);
  kernel23(v2224, v2157);	// L3151
  auto v2225 = reinterpret_cast<float(*)[384][1]>(v2120 + 50932224);
  kernel22(v2215, v2225, v2157);	// L3153
  kernel21(v2157, v2152, v2190);	// L3154
  auto v2226 = reinterpret_cast<float(*)[384][8][8]>(v2118 + 3342336);
  kernel20(v2226, v2190, v2150, (float)2.000000);	// L3156
  kernel16(v2150, v2192);	// L3157
  kernel18(v2192, (float)0.000000, (float)1.000000);	// L3158
  kernel17(v2192, v2150, (float)0.000000);	// L3159
  kernel16(v2150, v2226);	// L3160
  auto v2227 = reinterpret_cast<float(*)>(v2120 + 46950912);
  kernel15(v2227, v2193);	// L3162
  auto v2228 = reinterpret_cast<float(*)[384][1][1]>(v2120 + 48278016);
  kernel14(v2192, v2228, v2193);	// L3164
  auto v2229 = reinterpret_cast<float(*)[1536][8][8]>(v2118 + 3538944);
  kernel13(v2229, v2193, (float)2.000000);	// L3166
  auto v2230 = reinterpret_cast<float(*)[1536][8][8]>(v2118 + 7128576);
  kernel9(v2193, v2230);	// L3168
  kernel11(v2230, (float)0.000000, (float)1.000000);	// L3169
  kernel10(v2230, v2193, (float)0.000000);	// L3170
  kernel9(v2193, v2229);	// L3171
  auto v2231 = reinterpret_cast<float(*)>(v2120 + 44296704);
  kernel8(v2231, v2150);	// L3173
  auto v2232 = reinterpret_cast<float(*)[1536][1][1]>(v2120 + 45623808);
  kernel7(v2230, v2232, v2150);	// L3175
  kernel71(v2150, v2190, v2152);	// L3176
  auto v2233 = reinterpret_cast<float(*)[384][8][8]>(v2118 + 3735552);
  kernel20(v2233, v2152, v2150, (float)2.000000);	// L3178
  kernel16(v2150, v2190);	// L3179
  kernel18(v2190, (float)0.000000, (float)1.000000);	// L3180
  kernel17(v2190, v2150, (float)0.000000);	// L3181
  kernel16(v2150, v2233);	// L3182
  auto v2234 = reinterpret_cast<float(*)>(v2120 + 41642496);
  kernel23(v2234, v2157);	// L3184
  auto v2235 = reinterpret_cast<float(*)[384][1]>(v2120 + 42969600);
  kernel47(v2190, v2235, v2157);	// L3186
  auto v2236 = reinterpret_cast<float(*)[384][64]>(v2118 + 3932160);
  kernel46(v2236, v2157, (float)2.000000);	// L3188
  kernel42(v2157, v2204);	// L3189
  kernel44(v2204, (float)0.000000, (float)1.000000);	// L3190
  kernel43(v2204, v2157, (float)0.000000);	// L3191
  kernel42(v2157, v2236);	// L3192
  kernel41(v2204, v2205);	// L3193
  kernel40(v2205, v2206);	// L3194
  auto v2237 = reinterpret_cast<float(*)>(v2120 + 38988288);
  kernel23(v2237, v2157);	// L3196
  auto v2238 = reinterpret_cast<float(*)[384][1]>(v2120 + 40315392);
  kernel47(v2190, v2238, v2157);	// L3198
  auto v2239 = reinterpret_cast<float(*)[384][64]>(v2118 + 4128768);
  kernel46(v2239, v2157, (float)2.000000);	// L3200
  auto v2240 = reinterpret_cast<float(*)[384][64]>(v2118 + 9348096);
  kernel42(v2157, v2240);	// L3202
  kernel44(v2240, (float)0.000000, (float)1.000000);	// L3203
  kernel43(v2240, v2157, (float)0.000000);	// L3204
  kernel42(v2157, v2239);	// L3205
  auto v2241 = reinterpret_cast<float(*)[64][12][32]>(v2119 + 9570048);
  kernel41(v2240, v2241);	// L3207
  auto v2242 = reinterpret_cast<float(*)>(v2120 + 36334080);
  kernel23(v2242, v2157);	// L3209
  auto v2243 = reinterpret_cast<float(*)[384][1]>(v2120 + 37661184);
  kernel47(v2190, v2243, v2157);	// L3211
  auto v2244 = reinterpret_cast<float(*)[384][64]>(v2118 + 4325376);
  kernel46(v2244, v2157, (float)2.000000);	// L3213
  kernel42(v2157, v2187);	// L3214
  kernel44(v2187, (float)0.000000, (float)1.000000);	// L3215
  kernel43(v2187, v2157, (float)0.000000);	// L3216
  kernel42(v2157, v2244);	// L3217
  kernel41(v2187, v2216);	// L3218
  kernel40(v2216, v2174);	// L3219
  kernel39(v2241, v2175);	// L3220
  kernel35(v2206, v2217);	// L3221
  kernel37(v2175, v2218);	// L3222
  kernel102(v2178, v2219);	// L3223
  kernel36(v2217, v2218, v2219);	// L3224
  kernel35(v2174, v2217);	// L3225
  kernel99(v2181, (float)0.000000);	// L3226
  kernel33(v2217, v2219, v2181);	// L3227
  kernel32(v2181, v2174);	// L3228
  kernel31(v2174, (float)0.125000);	// L3229
  kernel30(v2174, v2182);	// L3230
  auto v2245 = reinterpret_cast<float(*)[64][384]>(v2118 + 4521984);
  kernel29(v2245, v2182, v2184, (float)2.000000);	// L3232
  auto v2246 = reinterpret_cast<float(*)[64][384]>(v2118 + 9126144);
  kernel28(v2184, v2246);	// L3234
  kernel27(v2246, (float)1.000000, (float)0.500000, (float)0.000000);	// L3235
  kernel26(v2184, v2246, v2186, (float)0.000000);	// L3236
  kernel25(v2186, v2245);	// L3237
  kernel24(v2246, v2187);	// L3238
  auto v2247 = reinterpret_cast<float(*)>(v2120 + 33679872);
  kernel23(v2247, v2157);	// L3240
  auto v2248 = reinterpret_cast<float(*)[384][1]>(v2120 + 35006976);
  kernel22(v2187, v2248, v2157);	// L3242
  kernel21(v2157, v2152, v2190);	// L3243
  auto v2249 = reinterpret_cast<float(*)[384][8][8]>(v2118 + 4718592);
  kernel20(v2249, v2190, v2150, (float)2.000000);	// L3245
  auto v2250 = reinterpret_cast<float(*)[384][8][8]>(v2118 + 7128576);
  kernel16(v2150, v2250);	// L3247
  kernel18(v2250, (float)0.000000, (float)1.000000);	// L3248
  kernel17(v2250, v2150, (float)0.000000);	// L3249
  kernel16(v2150, v2249);	// L3250
  auto v2251 = reinterpret_cast<float(*)>(v2120 + 31025664);
  kernel15(v2251, v2193);	// L3252
  auto v2252 = reinterpret_cast<float(*)[384][1][1]>(v2120 + 32352768);
  kernel14(v2250, v2252, v2193);	// L3254
  auto v2253 = reinterpret_cast<float(*)[1536][8][8]>(v2118 + 4915200);
  kernel13(v2253, v2193, (float)2.000000);	// L3256
  kernel9(v2193, v2197);	// L3257
  kernel11(v2197, (float)0.000000, (float)1.000000);	// L3258
  kernel10(v2197, v2193, (float)0.000000);	// L3259
  kernel9(v2193, v2253);	// L3260
  auto v2254 = reinterpret_cast<float(*)>(v2120 + 28371456);
  kernel8(v2254, v2150);	// L3262
  auto v2255 = reinterpret_cast<float(*)[1536][1][1]>(v2120 + 29698560);
  kernel7(v2197, v2255, v2150);	// L3264
  kernel71(v2150, v2190, v2152);	// L3265
  auto v2256 = reinterpret_cast<float(*)[384][8][8]>(v2118 + 5111808);
  kernel20(v2256, v2152, v2150, (float)2.000000);	// L3267
  kernel16(v2150, v2190);	// L3268
  kernel18(v2190, (float)0.000000, (float)1.000000);	// L3269
  kernel17(v2190, v2150, (float)0.000000);	// L3270
  kernel16(v2150, v2256);	// L3271
  auto v2257 = reinterpret_cast<float(*)>(v2120 + 25717248);
  kernel23(v2257, v2157);	// L3273
  auto v2258 = reinterpret_cast<float(*)[384][1]>(v2120 + 27044352);
  kernel47(v2190, v2258, v2157);	// L3275
  auto v2259 = reinterpret_cast<float(*)[384][64]>(v2118 + 5308416);
  kernel46(v2259, v2157, (float)2.000000);	// L3277
  auto v2260 = reinterpret_cast<float(*)[384][64]>(v2118 + 9126144);
  kernel42(v2157, v2260);	// L3279
  kernel44(v2260, (float)0.000000, (float)1.000000);	// L3280
  kernel43(v2260, v2157, (float)0.000000);	// L3281
  kernel42(v2157, v2259);	// L3282
  kernel41(v2260, v2205);	// L3283
  kernel40(v2205, v2206);	// L3284
  auto v2261 = reinterpret_cast<float(*)>(v2120 + 23063040);
  kernel23(v2261, v2157);	// L3286
  auto v2262 = reinterpret_cast<float(*)[384][1]>(v2120 + 24390144);
  kernel47(v2190, v2262, v2157);	// L3288
  auto v2263 = reinterpret_cast<float(*)[384][64]>(v2118 + 5505024);
  kernel46(v2263, v2157, (float)2.000000);	// L3290
  kernel42(v2157, v2210);	// L3291
  kernel44(v2210, (float)0.000000, (float)1.000000);	// L3292
  kernel43(v2210, v2157, (float)0.000000);	// L3293
  kernel42(v2157, v2263);	// L3294
  kernel41(v2210, v2241);	// L3295
  auto v2264 = reinterpret_cast<float(*)>(v2120 + 20408832);
  kernel23(v2264, v2157);	// L3297
  auto v2265 = reinterpret_cast<float(*)[384][1]>(v2120 + 21735936);
  kernel47(v2190, v2265, v2157);	// L3299
  auto v2266 = reinterpret_cast<float(*)[384][64]>(v2118 + 5701632);
  kernel46(v2266, v2157, (float)2.000000);	// L3301
  kernel42(v2157, v2187);	// L3302
  kernel44(v2187, (float)0.000000, (float)1.000000);	// L3303
  kernel43(v2187, v2157, (float)0.000000);	// L3304
  kernel42(v2157, v2266);	// L3305
  kernel41(v2187, v2216);	// L3306
  kernel40(v2216, v2174);	// L3307
  kernel39(v2241, v2175);	// L3308
  kernel35(v2206, v2217);	// L3309
  kernel37(v2175, v2218);	// L3310
  kernel36(v2217, v2218, v2178);	// L3311
  auto v2267 = reinterpret_cast<float(*)[1][12][64][32]>(v2120 + 6684672);
  kernel35(v2174, v2267);	// L3313
  kernel34(v2181, (float)0.000000);	// L3314
  kernel33(v2267, v2178, v2181);	// L3315
  kernel32(v2181, v2174);	// L3316
  kernel31(v2174, (float)0.125000);	// L3317
  kernel30(v2174, v2182);	// L3318
  auto v2268 = reinterpret_cast<float(*)[64][384]>(v2118 + 5898240);
  auto v2269 = reinterpret_cast<float(*)[64][12][32]>(v2120 + 6684672);
  kernel29(v2268, v2182, v2269, (float)2.000000);	// L3321
  auto v2270 = reinterpret_cast<float(*)[64][384]>(v2118 + 7572480);
  kernel28(v2269, v2270);	// L3323
  kernel27(v2270, (float)1.000000, (float)0.500000, (float)0.000000);	// L3324
  kernel26(v2269, v2270, v2186, (float)0.000000);	// L3325
  kernel25(v2186, v2268);	// L3326
  kernel24(v2270, v2172);	// L3327
  auto v2271 = reinterpret_cast<float(*)>(v2120 + 17754624);
  kernel23(v2271, v2157);	// L3329
  auto v2272 = reinterpret_cast<float(*)[384][1]>(v2120 + 19081728);
  kernel22(v2172, v2272, v2157);	// L3331
  kernel21(v2157, v2152, v2156);	// L3332
  auto v2273 = reinterpret_cast<float(*)[384][8][8]>(v2118 + 6094848);
  kernel20(v2273, v2156, v2150, (float)2.000000);	// L3334
  kernel16(v2150, v2250);	// L3335
  kernel18(v2250, (float)0.000000, (float)1.000000);	// L3336
  kernel17(v2250, v2150, (float)0.000000);	// L3337
  kernel16(v2150, v2273);	// L3338
  auto v2274 = reinterpret_cast<float(*)>(v2120 + 15100416);
  kernel15(v2274, v2193);	// L3340
  auto v2275 = reinterpret_cast<float(*)[384][1][1]>(v2120 + 16427520);
  kernel14(v2250, v2275, v2193);	// L3342
  auto v2276 = reinterpret_cast<float(*)[1536][8][8]>(v2118 + 6291456);
  kernel13(v2276, v2193, (float)2.000000);	// L3344
  kernel9(v2193, v2197);	// L3345
  kernel11(v2197, (float)0.000000, (float)1.000000);	// L3346
  kernel10(v2197, v2193, (float)0.000000);	// L3347
  kernel9(v2193, v2276);	// L3348
  auto v2277 = reinterpret_cast<float(*)>(v2120 + 12446208);
  kernel8(v2277, v2150);	// L3350
  auto v2278 = reinterpret_cast<float(*)[1536][1][1]>(v2120 + 13773312);
  kernel7(v2197, v2278, v2150);	// L3352
  kernel6(v2156, v2150);	// L3353
  auto v2279 = reinterpret_cast<float(*)[384]>(v2119 + 6684672);
  kernel5(v2279, (float)0.000000);	// L3355
  kernel4(v2150, v2279);	// L3356
  kernel3(v2279, (float)64.000000);	// L3357
  auto v2280 = reinterpret_cast<float(*)[10]>(v2118 + 6488064);
  kernel2(v2280, (float)0.000000);	// L3359
  auto v2281 = reinterpret_cast<float(*)[10]>(v2120 + 9792000);
  kernel1(v2279, v2281, v2280);	// L3361
  auto v2282 = reinterpret_cast<float(*)>(v2120 + 11119104);
  kernel0(v2282, v2280);	// L3363
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

