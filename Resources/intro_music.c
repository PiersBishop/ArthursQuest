#include "../Plugins/hUGEDriver.h"
#include <stddef.h>

static const unsigned char iorder_cnt = 2;

static const unsigned char iP0[] = {
    DN(___,0,0xE00),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
};
static const unsigned char iP1[] = {
    DN(___,0,0xE00),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(C_5,2,0x000),
    DN(___,0,0xE00),
    DN(C_5,2,0x000),
    DN(___,0,0xE00),
    DN(C_5,2,0x000),
    DN(___,0,0xE00),
    DN(D_5,2,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0xE00),
    DN(___,0,0x000),
    DN(C_5,2,0x000),
    DN(___,0,0xE00),
    DN(C_5,2,0x000),
    DN(___,0,0xE00),
    DN(C_5,2,0x000),
    DN(___,0,0xE00),
    DN(F_5,2,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0xE00),
    DN(___,0,0x000),
    DN(G_5,2,0x000),
    DN(___,0,0xE00),
    DN(Gs5,2,0x000),
    DN(___,0,0xE00),
    DN(As5,2,0x000),
    DN(___,0,0xE00),
    DN(C_6,2,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0xE00),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
};
static const unsigned char iP2[] = {
    DN(___,0,0xE00),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
};

static const unsigned char* const iorder1[] = {iP0};
static const unsigned char* const iorder2[] = {iP1};
static const unsigned char* const iorder3[] = {iP2};
static const unsigned char* const iorder4[] = {iP0};

static const unsigned char iduty_instruments[] = {
8,0,240,128,
8,64,240,128,
8,128,240,128,
8,192,240,128,
8,0,241,128,
8,64,241,128,
8,128,241,128,
8,192,241,128,
8,128,240,128,
8,128,240,128,
8,128,240,128,
8,128,240,128,
8,128,240,128,
8,128,240,128,
8,128,240,128,
};
static const unsigned char iwave_instruments[] = {
0,32,0,128,
0,32,1,128,
0,32,2,128,
0,32,3,128,
0,32,4,128,
0,32,5,128,
0,32,6,128,
0,32,7,128,
0,32,8,128,
0,32,9,128,
0,32,10,128,
0,32,11,128,
0,32,12,128,
0,32,13,128,
0,32,14,128,
};
static const unsigned char inoise_instruments[] = {
240,0,0,0,0,0,0,0,
240,0,0,0,0,0,0,0,
240,0,0,0,0,0,0,0,
240,0,0,0,0,0,0,0,
240,0,0,0,0,0,0,0,
240,0,0,0,0,0,0,0,
240,0,0,0,0,0,0,0,
240,0,0,0,0,0,0,0,
240,0,0,0,0,0,0,0,
240,0,0,0,0,0,0,0,
240,0,0,0,0,0,0,0,
240,0,0,0,0,0,0,0,
240,0,0,0,0,0,0,0,
240,0,0,0,0,0,0,0,
240,0,0,0,0,0,0,0,
};

static const unsigned char iwaves[] = {
    0,0,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
    0,0,0,0,255,255,255,255,255,255,255,255,255,255,255,255,
    0,0,0,0,0,0,0,0,255,255,255,255,255,255,255,255,
    0,0,0,0,0,0,0,0,0,0,0,0,255,255,255,255,
    0,1,18,35,52,69,86,103,120,137,154,171,188,205,222,239,
    254,220,186,152,118,84,50,16,18,52,86,120,154,188,222,255,
    122,205,219,117,33,19,104,189,220,151,65,1,71,156,221,184,
    15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,
    254,252,250,248,246,244,242,240,242,244,246,248,250,252,254,255,
    254,221,204,187,170,153,136,119,138,189,241,36,87,138,189,238,
    132,17,97,237,87,71,90,173,206,163,23,121,221,32,3,71,
    26,101,16,68,188,189,198,117,23,116,148,73,203,202,80,130,
    192,200,229,203,226,153,184,235,76,76,34,75,155,57,232,156,
    139,12,120,91,138,41,157,45,132,93,218,119,228,51,126,163,
    221,117,91,132,194,29,163,39,116,155,188,161,180,211,121,131,
    62,84,149,165,180,236,174,219,187,136,219,120,38,219,210,23,
};

const hUGESong_t intro_music = {7, &iorder_cnt, iorder1, iorder2, iorder3,iorder4, iduty_instruments, iwave_instruments, inoise_instruments, NULL, iwaves};
