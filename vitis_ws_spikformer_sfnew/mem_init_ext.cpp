
/// ------------------------------------------------------------------- ///
/// The following code segment is for the initialization of constant 
/// values in external memory.
/// You should copy them to the host software and do some adaptations.
/// ------------------------------------------------------------------- ///

#define HCA_DDR_BASE /** your ddr base address **/

float const_61[48];
float const_62[48][3][3][3];
float const_63[96];
float const_64[96][48][3][3];
float const_65[192];
float const_66[192][96][3][3];
float const_67[384];
float const_68[384][192][3][3];
float const_69[384];
float const_70[384][384][3][3];
float const_71[384];
float const_72[384][384][1];
float const_73[384];
float const_74[384][384][1];
float const_75[384];
float const_76[384][384][1];
float const_77[1];
float const_78[384];
float const_79[384][384][1];
float const_80[1536];
float const_81[1536][384][1][1];
float const_82[384];
float const_83[384][1536][1][1];
float const_84[384];
float const_85[384][384][1];
float const_86[384];
float const_87[384][384][1];
float const_88[384];
float const_89[384][384][1];
float const_90[384];
float const_91[384][384][1];
float const_92[1536];
float const_93[1536][384][1][1];
float const_94[384];
float const_95[384][1536][1][1];
float const_96[384];
float const_97[384][384][1];
float const_98[384];
float const_99[384][384][1];
float const_100[384];
float const_101[384][384][1];
float const_102[384];
float const_103[384][384][1];
float const_104[1536];
float const_105[1536][384][1][1];
float const_106[384];
float const_107[384][1536][1][1];
float const_108[384];
float const_109[384][384][1];
float const_110[384];
float const_111[384][384][1];
float const_112[384];
float const_113[384][384][1];
float const_114[384];
float const_115[384][384][1];
float const_116[1536];
float const_117[1536][384][1][1];
float const_118[384];
float const_119[384][1536][1][1];
float const_120[10][384];
float const_121[10];

/// Read data from external bins
/// You should implement the code reading from external bin files and fill
/// the buffer... Caution the endian!
/// ...
/// ...
/// ...

memcpy((void*)(HCA_DDR_BASE + 290439168), (void*)(const_74), 589824);
memcpy((void*)(HCA_DDR_BASE + 67485696), (void*)(const_117), 2359296);
memcpy((void*)(HCA_DDR_BASE + 216121344), (void*)(const_89), 589824);
memcpy((void*)(HCA_DDR_BASE + 274513920), (void*)(const_75), 1536);
memcpy((void*)(HCA_DDR_BASE + 94027776), (void*)(const_110), 1536);
memcpy((void*)(HCA_DDR_BASE + 295747584), (void*)(const_71), 1536);
memcpy((void*)(HCA_DDR_BASE + 285130752), (void*)(const_73), 1536);
memcpy((void*)(HCA_DDR_BASE + 109953024), (void*)(const_109), 589824);
memcpy((void*)(HCA_DDR_BASE + 316981248), (void*)(const_67), 1536);
memcpy((void*)(HCA_DDR_BASE + 269205504), (void*)(const_79), 589824);
memcpy((void*)(HCA_DDR_BASE + 306364416), (void*)(const_69), 1536);
memcpy((void*)(HCA_DDR_BASE + 258588672), (void*)(const_81), 2359296);
memcpy((void*)(HCA_DDR_BASE + 253280256), (void*)(const_80), 6144);
memcpy((void*)(HCA_DDR_BASE + 226738176), (void*)(const_87), 589824);
memcpy((void*)(HCA_DDR_BASE + 72794112), (void*)(const_114), 1536);
memcpy((void*)(HCA_DDR_BASE + 131186688), (void*)(const_105), 2359296);
memcpy((void*)(HCA_DDR_BASE + 194887680), (void*)(const_93), 2359296);
memcpy((void*)(HCA_DDR_BASE + 237355008), (void*)(const_85), 589824);
memcpy((void*)(HCA_DDR_BASE + 242663424), (void*)(const_82), 1536);
memcpy((void*)(HCA_DDR_BASE + 343523328), (void*)(const_64), 165888);
memcpy((void*)(HCA_DDR_BASE + 152420352), (void*)(const_101), 589824);
memcpy((void*)(HCA_DDR_BASE + 120569856), (void*)(const_107), 2359296);
memcpy((void*)(HCA_DDR_BASE + 348831744), (void*)(const_61), 192);
memcpy((void*)(HCA_DDR_BASE + 232046592), (void*)(const_84), 1536);
memcpy((void*)(HCA_DDR_BASE + 157728768), (void*)(const_98), 1536);
memcpy((void*)(HCA_DDR_BASE + 210812928), (void*)(const_88), 1536);
memcpy((void*)(HCA_DDR_BASE + 301056000), (void*)(const_72), 589824);
memcpy((void*)(HCA_DDR_BASE + 221429760), (void*)(const_86), 1536);
memcpy((void*)(HCA_DDR_BASE + 359448576), (void*)(const_77), 4);
memcpy((void*)(HCA_DDR_BASE + 147111936), (void*)(const_100), 1536);
memcpy((void*)(HCA_DDR_BASE + 178962432), (void*)(const_94), 1536);
memcpy((void*)(HCA_DDR_BASE + 51560448), (void*)(const_118), 1536);
memcpy((void*)(HCA_DDR_BASE + 40943616), (void*)(const_121), 40);
memcpy((void*)(HCA_DDR_BASE + 279822336), (void*)(const_76), 589824);
memcpy((void*)(HCA_DDR_BASE + 141803520), (void*)(const_103), 589824);
memcpy((void*)(HCA_DDR_BASE + 332906496), (void*)(const_66), 663552);
memcpy((void*)(HCA_DDR_BASE + 200196096), (void*)(const_90), 1536);
memcpy((void*)(HCA_DDR_BASE + 56868864), (void*)(const_119), 2359296);
memcpy((void*)(HCA_DDR_BASE + 168345600), (void*)(const_96), 1536);
memcpy((void*)(HCA_DDR_BASE + 125878272), (void*)(const_104), 6144);
memcpy((void*)(HCA_DDR_BASE + 322289664), (void*)(const_68), 2654208);
memcpy((void*)(HCA_DDR_BASE + 46252032), (void*)(const_120), 15360);
memcpy((void*)(HCA_DDR_BASE + 104644608), (void*)(const_108), 1536);
memcpy((void*)(HCA_DDR_BASE + 173654016), (void*)(const_97), 589824);
memcpy((void*)(HCA_DDR_BASE + 83410944), (void*)(const_112), 1536);
memcpy((void*)(HCA_DDR_BASE + 247971840), (void*)(const_83), 2359296);
memcpy((void*)(HCA_DDR_BASE + 184270848), (void*)(const_95), 2359296);
memcpy((void*)(HCA_DDR_BASE + 136495104), (void*)(const_102), 1536);
memcpy((void*)(HCA_DDR_BASE + 88719360), (void*)(const_113), 589824);
memcpy((void*)(HCA_DDR_BASE + 99336192), (void*)(const_111), 589824);
memcpy((void*)(HCA_DDR_BASE + 78102528), (void*)(const_115), 589824);
memcpy((void*)(HCA_DDR_BASE + 62177280), (void*)(const_116), 6144);
memcpy((void*)(HCA_DDR_BASE + 189579264), (void*)(const_92), 6144);
memcpy((void*)(HCA_DDR_BASE + 354140160), (void*)(const_62), 5184);
memcpy((void*)(HCA_DDR_BASE + 327598080), (void*)(const_65), 768);
memcpy((void*)(HCA_DDR_BASE + 338214912), (void*)(const_63), 384);
memcpy((void*)(HCA_DDR_BASE + 115261440), (void*)(const_106), 1536);
memcpy((void*)(HCA_DDR_BASE + 163037184), (void*)(const_99), 589824);
memcpy((void*)(HCA_DDR_BASE + 205504512), (void*)(const_91), 589824);
memcpy((void*)(HCA_DDR_BASE + 263897088), (void*)(const_78), 1536);
memcpy((void*)(HCA_DDR_BASE + 311672832), (void*)(const_70), 5308416);
