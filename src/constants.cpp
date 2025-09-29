#include "./constants.h"

f64 atomic_masses[119] = {
  0.0,
  1.008,
  4.002602,
  6.94,
  9.012182,
  10.81,
  12.011,
  14.007,
  15.999,
  18.9984032,
  20.1797,
  22.98976928,
  24.305,
  26.9815386,
  28.085,
  30.973762,
  32.06,
  35.45,
  39.948,
  39.0983,
  40.078,
  44.955912,
  47.867,
  50.9415,
  51.9961,
  54.938045,
  55.845,
  58.933195,
  58.6934,
  63.546,
  65.38,
  69.723,
  72.63,
  74.9216,
  78.96,
  79.904,
  83.798,
  85.4678,
  87.62,
  88.90585,
  91.224,
  92.90638,
  95.96,
  97.0,
  101.07,
  102.9055,
  106.42,
  107.8682,
  112.411,
  114.818,
  118.71,
  121.76,
  127.6,
  126.90447,
  131.293,
  132.9054519,
  137.327,
  138.90547,
  140.116,
  140.90765,
  144.242,
  145.0,
  150.36,
  151.964,
  157.25,
  158.92535,
  162.5,
  164.93032,
  167.259,
  168.93421,
  173.054,
  174.9668,
  178.49,
  180.94788,
  183.84,
  186.207,
  190.23,
  192.217,
  195.084,
  196.966569,
  200.592,
  204.38,
  207.2,
  208.9804,
  209.0,
  210.0,
  222.0,
  223.0,
  226.0,
  227.0,
  232.03806,
  231.03588,
  238.02891,
  237.0,
  244.0,
  243.0,
  247.0,
  247.0,
  251.0,
  252.0,
  257.0,
  258.0,
  259.0,
  262.0,
  267.0,
  270.0,
  271.0,
  270.0,
  277.0,
  276.0,
  281.0,
  282.0,
  285.0,
  285.0,
  289.0,
  289.0,
  293.0,
  294.0,
  294.0,
};

f64 atomic_radi[119] = {
  0.0,
  0.32,
  0.46,
  1.33,
  1.02,
  0.85,
  0.75,
  0.71,
  0.63,
  0.64,
  0.67,
  1.55,
  1.39,
  1.26,
  1.16,
  1.11,
  1.03,
  0.99,
  0.96,
  1.96,
  1.71,
  1.48,
  1.36,
  1.34,
  1.22,
  1.19,
  1.16,
  1.11,
  1.1,
  1.12,
  1.18,
  1.24,
  1.21,
  1.21,
  1.16,
  1.14,
  1.17,
  2.1,
  1.85,
  1.63,
  1.54,
  1.47,
  1.38,
  1.28,
  1.25,
  1.25,
  1.2,
  1.28,
  1.36,
  1.42,
  1.4,
  1.4,
  1.36,
  1.33,
  1.31,
  2.32,
  1.96,
  1.8,
  1.63,
  1.76,
  1.74,
  1.73,
  1.72,
  1.68,
  1.69,
  1.68,
  1.67,
  1.66,
  1.65,
  1.64,
  1.7,
  1.62,
  1.52,
  1.46,
  1.37,
  1.31,
  1.29,
  1.22,
  1.23,
  1.24,
  1.33,
  1.44,
  1.44,
  1.51,
  1.45,
  1.47,
  1.42,
  2.23,
  2.01,
  1.86,
  1.75,
  1.69,
  1.7,
  1.71,
  1.72,
  1.66,
  1.66,
  1.68,
  1.68,
  1.65,
  1.67,
  1.73,
  1.76,
  1.61,
  1.57,
  1.49,
  1.43,
  1.41,
  1.34,
  1.29,
  1.28,
  1.21,
  1.22,
  1.36,
  1.43,
  1.62,
  1.75,
  1.65,
  1.57,
};

i32 atomic_colors_hex[110] = { //From Jmol
  0xFF1493,
  0xFFFFFF, // H  1
  0xD9FFFF, // He 2
  0xCC80FF, // Li 3
  0xC2FF00, // Be 4
  0xFFB5B5, // B  5
  0x909090, // C  6 - changed from ghemical
  0x3050F8, // N  7 - changed from ghemical
  0xFF0D0D, // O  8
  0x90E050, // F  9 - changed from ghemical
  0xB3E3F5, // Ne 10
  0xAB5CF2, // Na 11
  0x8AFF00, // Mg 12
  0xBFA6A6, // Al 13
  0xF0C8A0, // Si 14 - changed from ghemical
  0xFF8000, // P  15
  0xFFFF30, // S  16
  0x1FF01F, // Cl 17
  0x80D1E3, // Ar 18
  0x8F40D4, // K  19
  0x3DFF00, // Ca 20
  0xE6E6E6, // Sc 21
  0xBFC2C7, // Ti 22
  0xA6A6AB, // V  23
  0x8A99C7, // Cr 24
  0x9C7AC7, // Mn 25
  0xE06633, // Fe 26 - changed from ghemical
  0xF090A0, // Co 27 - changed from ghemical
  0x50D050, // Ni 28 - changed from ghemical
  0xC88033, // Cu 29 - changed from ghemical
  0x7D80B0, // Zn 30
  0xC28F8F, // Ga 31
  0x668F8F, // Ge 32
  0xBD80E3, // As 33
  0xFFA100, // Se 34
  0xA62929, // Br 35
  0x5CB8D1, // Kr 36
  0x702EB0, // Rb 37
  0x00FF00, // Sr 38
  0x94FFFF, // Y  39
  0x94E0E0, // Zr 40
  0x73C2C9, // Nb 41
  0x54B5B5, // Mo 42
  0x3B9E9E, // Tc 43
  0x248F8F, // Ru 44
  0x0A7D8C, // Rh 45
  0x006985, // Pd 46
  0xC0C0C0, // Ag 47 - changed from ghemical
  0xFFD98F, // Cd 48
  0xA67573, // In 49
  0x668080, // Sn 50
  0x9E63B5, // Sb 51
  0xD47A00, // Te 52
  0x940094, // I  53
  0x429EB0, // Xe 54
  0x57178F, // Cs 55
  0x00C900, // Ba 56
  0x70D4FF, // La 57
  0xFFFFC7, // Ce 58
  0xD9FFC7, // Pr 59
  0xC7FFC7, // Nd 60
  0xA3FFC7, // Pm 61
  0x8FFFC7, // Sm 62
  0x61FFC7, // Eu 63
  0x45FFC7, // Gd 64
  0x30FFC7, // Tb 65
  0x1FFFC7, // Dy 66
  0x00FF9C, // Ho 67
  0x00E675, // Er 68
  0x00D452, // Tm 69
  0x00BF38, // Yb 70
  0x00AB24, // Lu 71
  0x4DC2FF, // Hf 72
  0x4DA6FF, // Ta 73
  0x2194D6, // W  74
  0x267DAB, // Re 75
  0x266696, // Os 76
  0x175487, // Ir 77
  0xD0D0E0, // Pt 78 - changed from ghemical
  0xFFD123, // Au 79 - changed from ghemical
  0xB8B8D0, // Hg 80 - changed from ghemical
  0xA6544D, // Tl 81
  0x575961, // Pb 82
  0x9E4FB5, // Bi 83
  0xAB5C00, // Po 84
  0x754F45, // At 85
  0x428296, // Rn 86
  0x420066, // Fr 87
  0x007D00, // Ra 88
  0x70ABFA, // Ac 89
  0x00BAFF, // Th 90
  0x00A1FF, // Pa 91
  0x008FFF, // U  92
  0x0080FF, // Np 93
  0x006BFF, // Pu 94
  0x545CF2, // Am 95
  0x785CE3, // Cm 96
  0x8A4FE3, // Bk 97
  0xA136D4, // Cf 98
  0xB31FD4, // Es 99
  0xB31FBA, // Fm 100
  0xB30DA6, // Md 101
  0xBD0D87, // No 102
  0xC70066, // Lr 103
  0xCC0059, // Rf 104
  0xD1004F, // Db 105
  0xD90045, // Sg 106
  0xE00038, // Bh 107
  0xE6002E, // Hs 108
  0xEB0026, // Mt 109
};

i16 atomic_colors_term[110] = {
  198,
  15,
  195,
  177,
  154,
  217,
  246,
  236,
  9,
  119,
  159,
  135,
  118,
  250,
  223,
  208,
  11,
  10,
  116,
  99,
  82,
  254,
  7,
  248,
  103,
  140,
  173,
  210,
  77,
  179,
  103,
  250,
  66,
  141,
  214,
  131,
  74,
  63,
  10,
  123,
  116,
  116,
  73,
  238,
  236,
  30,
  24,
  7,
  222,
  138,
  66,
  133,
  172,
  90,
  238,
  54,
  40,
  81,
  230,
  194,
  194,
  158,
  122,
  86,
  86,
  237,
  50,
  42,
  48,
  41,
  47,
  34,
  74,
  75,
  32,
  236,
  236,
  24,
  252,
  220,
  146,
  131,
  240,
  134,
  130,
  243,
  238,
  53,
  2,
  75,
  39,
  39,
  33,
  33,
  27,
  63,
  98,
  99,
  135,
  128,
  127,
  127,
  126,
  161,
  161,
  161,
  161,
  161,
  161,
  197,
};

u8 atomic_symbol_to_number(char *symbol)
{
  u16 total_num = symbol[0]*256 + symbol[1];
  switch (total_num)
  {
    case 0x4800: // 1 -> H
      return 1;
    case 0x4865: // 2 -> He
      return 2;
    case 0x4c69: // 3 -> Li
      return 3;
    case 0x4265: // 4 -> Be
      return 4;
    case 0x4200: // 5 -> B
      return 5;
    case 0x4300: // 6 -> C
      return 6;
    case 0x4e00: // 7 -> N
      return 7;
    case 0x4f00: // 8 -> O
      return 8;
    case 0x4600: // 9 -> F
      return 9;
    case 0x4e65: // 10 -> Ne
      return 10;
    case 0x4e61: // 11 -> Na
      return 11;
    case 0x4d67: // 12 -> Mg
      return 12;
    case 0x416c: // 13 -> Al
      return 13;
    case 0x5369: // 14 -> Si
      return 14;
    case 0x5000: // 15 -> P
      return 15;
    case 0x5300: // 16 -> S
      return 16;
    case 0x436c: // 17 -> Cl
      return 17;
    case 0x4172: // 18 -> Ar
      return 18;
    case 0x4b00: // 19 -> K
      return 19;
    case 0x4361: // 20 -> Ca
      return 20;
    case 0x5363: // 21 -> Sc
      return 21;
    case 0x5469: // 22 -> Ti
      return 22;
    case 0x5600: // 23 -> V
      return 23;
    case 0x4372: // 24 -> Cr
      return 24;
    case 0x4d6e: // 25 -> Mn
      return 25;
    case 0x4665: // 26 -> Fe
      return 26;
    case 0x436f: // 27 -> Co
      return 27;
    case 0x4e69: // 28 -> Ni
      return 28;
    case 0x4375: // 29 -> Cu
      return 29;
    case 0x5a6e: // 30 -> Zn
      return 30;
    case 0x4761: // 31 -> Ga
      return 31;
    case 0x4765: // 32 -> Ge
      return 32;
    case 0x4173: // 33 -> As
      return 33;
    case 0x5365: // 34 -> Se
      return 34;
    case 0x4272: // 35 -> Br
      return 35;
    case 0x4b72: // 36 -> Kr
      return 36;
    case 0x5262: // 37 -> Rb
      return 37;
    case 0x5372: // 38 -> Sr
      return 38;
    case 0x5900: // 39 -> Y
      return 39;
    case 0x5a72: // 40 -> Zr
      return 40;
    case 0x4e62: // 41 -> Nb
      return 41;
    case 0x4d6f: // 42 -> Mo
      return 42;
    case 0x5463: // 43 -> Tc
      return 43;
    case 0x5275: // 44 -> Ru
      return 44;
    case 0x5268: // 45 -> Rh
      return 45;
    case 0x5064: // 46 -> Pd
      return 46;
    case 0x4167: // 47 -> Ag
      return 47;
    case 0x4364: // 48 -> Cd
      return 48;
    case 0x496e: // 49 -> In
      return 49;
    case 0x536e: // 50 -> Sn
      return 50;
    case 0x5362: // 51 -> Sb
      return 51;
    case 0x5465: // 52 -> Te
      return 52;
    case 0x4900: // 53 -> I
      return 53;
    case 0x5865: // 54 -> Xe
      return 54;
    case 0x4373: // 55 -> Cs
      return 55;
    case 0x4261: // 56 -> Ba
      return 56;
    case 0x4c61: // 57 -> La
      return 57;
    case 0x4365: // 58 -> Ce
      return 58;
    case 0x5072: // 59 -> Pr
      return 59;
    case 0x4e64: // 60 -> Nd
      return 60;
    case 0x506d: // 61 -> Pm
      return 61;
    case 0x536d: // 62 -> Sm
      return 62;
    case 0x4575: // 63 -> Eu
      return 63;
    case 0x4764: // 64 -> Gd
      return 64;
    case 0x5462: // 65 -> Tb
      return 65;
    case 0x4479: // 66 -> Dy
      return 66;
    case 0x486f: // 67 -> Ho
      return 67;
    case 0x4572: // 68 -> Er
      return 68;
    case 0x546d: // 69 -> Tm
      return 69;
    case 0x5962: // 70 -> Yb
      return 70;
    case 0x4c75: // 71 -> Lu
      return 71;
    case 0x4866: // 72 -> Hf
      return 72;
    case 0x5461: // 73 -> Ta
      return 73;
    case 0x5700: // 74 -> W
      return 74;
    case 0x5265: // 75 -> Re
      return 75;
    case 0x4f73: // 76 -> Os
      return 76;
    case 0x4972: // 77 -> Ir
      return 77;
    case 0x5074: // 78 -> Pt
      return 78;
    case 0x4175: // 79 -> Au
      return 79;
    case 0x4867: // 80 -> Hg
      return 80;
    case 0x546c: // 81 -> Tl
      return 81;
    case 0x5062: // 82 -> Pb
      return 82;
    case 0x4269: // 83 -> Bi
      return 83;
    case 0x506f: // 84 -> Po
      return 84;
    case 0x4174: // 85 -> At
      return 85;
    case 0x526e: // 86 -> Rn
      return 86;
    case 0x4672: // 87 -> Fr
      return 87;
    case 0x5261: // 88 -> Ra
      return 88;
    case 0x4163: // 89 -> Ac
      return 89;
    case 0x5468: // 90 -> Th
      return 90;
    case 0x5061: // 91 -> Pa
      return 91;
    case 0x5500: // 92 -> U
      return 92;
    case 0x4e70: // 93 -> Np
      return 93;
    case 0x5075: // 94 -> Pu
      return 94;
    case 0x416d: // 95 -> Am
      return 95;
    case 0x436d: // 96 -> Cm
      return 96;
    case 0x426b: // 97 -> Bk
      return 97;
    case 0x4366: // 98 -> Cf
      return 98;
    case 0x4573: // 99 -> Es
      return 99;
    case 0x466d: // 100 -> Fm
      return 100;
    case 0x4d64: // 101 -> Md
      return 101;
    case 0x4e6f: // 102 -> No
      return 102;
    case 0x4c72: // 103 -> Lr
      return 103;
    case 0x5266: // 104 -> Rf
      return 104;
    case 0x4462: // 105 -> Db
      return 105;
    case 0x5367: // 106 -> Sg
      return 106;
    case 0x4268: // 107 -> Bh
      return 107;
    case 0x4873: // 108 -> Hs
      return 108;
    case 0x4d74: // 109 -> Mt
      return 109;
    case 0x4473: // 110 -> Ds
      return 110;
    case 0x5575: // 111 -> Uuu
      return 111;
    case 0x5576: // 112 -> Uub
      return 112;
    case 0x5577: // 113 -> Uut
      return 113;
    case 0x5578: // 114 -> Uuq
      return 114;
    case 0x5579: // 115 -> Uup
      return 115;
    case 0x557A: // 116 -> Uuh
      return 116;
    case 0x557B: // 117 -> Uus
      return 117;
    case 0x557C: // 118 -> Uuo
      return 118;
  }
  return 0;
}
