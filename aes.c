#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "util.h"
#include "aes.h"

void sboxAssign(uint8 *outData)
{
    int offset = 0;

    if(NULL == outData)
    {
        return ;
    }
    /******************************************************
     0     1     2     3     4     5     6     7     8     9     a     b     c     d     e     f
	0x63, 0x7c, 0x77, 0x7b, 0xf2, 0x6b, 0x6f, 0xc5, 0x30, 0x01, 0x67, 0x2b, 0xfe, 0xd7, 0xab, 0x76, // 0
	0xca, 0x82, 0xc9, 0x7d, 0xfa, 0x59, 0x47, 0xf0, 0xad, 0xd4, 0xa2, 0xaf, 0x9c, 0xa4, 0x72, 0xc0, // 1
	0xb7, 0xfd, 0x93, 0x26, 0x36, 0x3f, 0xf7, 0xcc, 0x34, 0xa5, 0xe5, 0xf1, 0x71, 0xd8, 0x31, 0x15, // 2
	0x04, 0xc7, 0x23, 0xc3, 0x18, 0x96, 0x05, 0x9a, 0x07, 0x12, 0x80, 0xe2, 0xeb, 0x27, 0xb2, 0x75, // 3
	0x09, 0x83, 0x2c, 0x1a, 0x1b, 0x6e, 0x5a, 0xa0, 0x52, 0x3b, 0xd6, 0xb3, 0x29, 0xe3, 0x2f, 0x84, // 4
	0x53, 0xd1, 0x00, 0xed, 0x20, 0xfc, 0xb1, 0x5b, 0x6a, 0xcb, 0xbe, 0x39, 0x4a, 0x4c, 0x58, 0xcf, // 5
	0xd0, 0xef, 0xaa, 0xfb, 0x43, 0x4d, 0x33, 0x85, 0x45, 0xf9, 0x02, 0x7f, 0x50, 0x3c, 0x9f, 0xa8, // 6
	0x51, 0xa3, 0x40, 0x8f, 0x92, 0x9d, 0x38, 0xf5, 0xbc, 0xb6, 0xda, 0x21, 0x10, 0xff, 0xf3, 0xd2, // 7
	0xcd, 0x0c, 0x13, 0xec, 0x5f, 0x97, 0x44, 0x17, 0xc4, 0xa7, 0x7e, 0x3d, 0x64, 0x5d, 0x19, 0x73, // 8
	0x60, 0x81, 0x4f, 0xdc, 0x22, 0x2a, 0x90, 0x88, 0x46, 0xee, 0xb8, 0x14, 0xde, 0x5e, 0x0b, 0xdb, // 9
	0xe0, 0x32, 0x3a, 0x0a, 0x49, 0x06, 0x24, 0x5c, 0xc2, 0xd3, 0xac, 0x62, 0x91, 0x95, 0xe4, 0x79, // a
	0xe7, 0xc8, 0x37, 0x6d, 0x8d, 0xd5, 0x4e, 0xa9, 0x6c, 0x56, 0xf4, 0xea, 0x65, 0x7a, 0xae, 0x08, // b
	0xba, 0x78, 0x25, 0x2e, 0x1c, 0xa6, 0xb4, 0xc6, 0xe8, 0xdd, 0x74, 0x1f, 0x4b, 0xbd, 0x8b, 0x8a, // c
	0x70, 0x3e, 0xb5, 0x66, 0x48, 0x03, 0xf6, 0x0e, 0x61, 0x35, 0x57, 0xb9, 0x86, 0xc1, 0x1d, 0x9e, // d
	0xe1, 0xf8, 0x98, 0x11, 0x69, 0xd9, 0x8e, 0x94, 0x9b, 0x1e, 0x87, 0xe9, 0xce, 0x55, 0x28, 0xdf, // e
	0x8c, 0xa1, 0x89, 0x0d, 0xbf, 0xe6, 0x42, 0x68, 0x41, 0x99, 0x2d, 0x0f, 0xb0, 0x54, 0xbb, 0x16;// f
     ******************************************************/
    outData[offset++] = 0x63;outData[offset++] = 0x7c;outData[offset++] = 0x77;outData[offset++] = 0x7b;
    outData[offset++] = 0xf2;outData[offset++] = 0x6b;outData[offset++] = 0x6f;outData[offset++] = 0xc5;
    outData[offset++] = 0x30;outData[offset++] = 0x01;outData[offset++] = 0x67;outData[offset++] = 0x2b;
    outData[offset++] = 0xfe;outData[offset++] = 0xd7;outData[offset++] = 0xab;outData[offset++] = 0x76;
    outData[offset++] = 0xca;outData[offset++] = 0x82;outData[offset++] = 0xc9;outData[offset++] = 0x7d;
    outData[offset++] = 0xfa;outData[offset++] = 0x59;outData[offset++] = 0x47;outData[offset++] = 0xf0;
    outData[offset++] = 0xad;outData[offset++] = 0xd4;outData[offset++] = 0xa2;outData[offset++] = 0xaf;
    outData[offset++] = 0x9c;outData[offset++] = 0xa4;outData[offset++] = 0x72;outData[offset++] = 0xc0;
    outData[offset++] = 0xb7;outData[offset++] = 0xfd;outData[offset++] = 0x93;outData[offset++] = 0x26;
    outData[offset++] = 0x36;outData[offset++] = 0x3f;outData[offset++] = 0xf7;outData[offset++] = 0xcc;
    outData[offset++] = 0x34;outData[offset++] = 0xa5;outData[offset++] = 0xe5;outData[offset++] = 0xf1;
    outData[offset++] = 0x71;outData[offset++] = 0xd8;outData[offset++] = 0x31;outData[offset++] = 0x15;
    outData[offset++] = 0x04;outData[offset++] = 0xc7;outData[offset++] = 0x23;outData[offset++] = 0xc3;
    outData[offset++] = 0x18;outData[offset++] = 0x96;outData[offset++] = 0x05;outData[offset++] = 0x9a;
    outData[offset++] = 0x07;outData[offset++] = 0x12;outData[offset++] = 0x80;outData[offset++] = 0xe2;
    outData[offset++] = 0xeb;outData[offset++] = 0x27;outData[offset++] = 0xb2;outData[offset++] = 0x75;
    outData[offset++] = 0x09;outData[offset++] = 0x83;outData[offset++] = 0x2c;outData[offset++] = 0x1a;
    outData[offset++] = 0x1b;outData[offset++] = 0x6e;outData[offset++] = 0x5a;outData[offset++] = 0xa0;
    outData[offset++] = 0x52;outData[offset++] = 0x3b;outData[offset++] = 0xd6;outData[offset++] = 0xb3;
    outData[offset++] = 0x29;outData[offset++] = 0xe3;outData[offset++] = 0x2f;outData[offset++] = 0x84;
    outData[offset++] = 0x53;outData[offset++] = 0xd1;outData[offset++] = 0x00;outData[offset++] = 0xed;
    outData[offset++] = 0x20;outData[offset++] = 0xfc;outData[offset++] = 0xb1;outData[offset++] = 0x5b;
    outData[offset++] = 0x6a;outData[offset++] = 0xcb;outData[offset++] = 0xbe;outData[offset++] = 0x39;
    outData[offset++] = 0x4a;outData[offset++] = 0x4c;outData[offset++] = 0x58;outData[offset++] = 0xcf;
    outData[offset++] = 0xd0;outData[offset++] = 0xef;outData[offset++] = 0xaa;outData[offset++] = 0xfb;
    outData[offset++] = 0x43;outData[offset++] = 0x4d;outData[offset++] = 0x33;outData[offset++] = 0x85;
    outData[offset++] = 0x45;outData[offset++] = 0xf9;outData[offset++] = 0x02;outData[offset++] = 0x7f;
    outData[offset++] = 0x50;outData[offset++] = 0x3c;outData[offset++] = 0x9f;outData[offset++] = 0xa8;
    outData[offset++] = 0x51;outData[offset++] = 0xa3;outData[offset++] = 0x40;outData[offset++] = 0x8f;
    outData[offset++] = 0x92;outData[offset++] = 0x9d;outData[offset++] = 0x38;outData[offset++] = 0xf5;
    outData[offset++] = 0xbc;outData[offset++] = 0xb6;outData[offset++] = 0xda;outData[offset++] = 0x21;
    outData[offset++] = 0x10;outData[offset++] = 0xff;outData[offset++] = 0xf3;outData[offset++] = 0xd2;
    outData[offset++] = 0xcd;outData[offset++] = 0x0c;outData[offset++] = 0x13;outData[offset++] = 0xec;
    outData[offset++] = 0x5f;outData[offset++] = 0x97;outData[offset++] = 0x44;outData[offset++] = 0x17;
    outData[offset++] = 0xc4;outData[offset++] = 0xa7;outData[offset++] = 0x7e;outData[offset++] = 0x3d;
    outData[offset++] = 0x64;outData[offset++] = 0x5d;outData[offset++] = 0x19;outData[offset++] = 0x73;
    outData[offset++] = 0x60;outData[offset++] = 0x81;outData[offset++] = 0x4f;outData[offset++] = 0xdc;
    outData[offset++] = 0x22;outData[offset++] = 0x2a;outData[offset++] = 0x90;outData[offset++] = 0x88;
    outData[offset++] = 0x46;outData[offset++] = 0xee;outData[offset++] = 0xb8;outData[offset++] = 0x14;
    outData[offset++] = 0xde;outData[offset++] = 0x5e;outData[offset++] = 0x0b;outData[offset++] = 0xdb;
    outData[offset++] = 0xe0;outData[offset++] = 0x32;outData[offset++] = 0x3a;outData[offset++] = 0x0a;
    outData[offset++] = 0x49;outData[offset++] = 0x06;outData[offset++] = 0x24;outData[offset++] = 0x5c;
    outData[offset++] = 0xc2;outData[offset++] = 0xd3;outData[offset++] = 0xac;outData[offset++] = 0x62;
    outData[offset++] = 0x91;outData[offset++] = 0x95;outData[offset++] = 0xe4;outData[offset++] = 0x79;
    outData[offset++] = 0xe7;outData[offset++] = 0xc8;outData[offset++] = 0x37;outData[offset++] = 0x6d;
    outData[offset++] = 0x8d;outData[offset++] = 0xd5;outData[offset++] = 0x4e;outData[offset++] = 0xa9;
    outData[offset++] = 0x6c;outData[offset++] = 0x56;outData[offset++] = 0xf4;outData[offset++] = 0xea;
    outData[offset++] = 0x65;outData[offset++] = 0x7a;outData[offset++] = 0xae;outData[offset++] = 0x08;
    outData[offset++] = 0xba;outData[offset++] = 0x78;outData[offset++] = 0x25;outData[offset++] = 0x2e;
    outData[offset++] = 0x1c;outData[offset++] = 0xa6;outData[offset++] = 0xb4;outData[offset++] = 0xc6;
    outData[offset++] = 0xe8;outData[offset++] = 0xdd;outData[offset++] = 0x74;outData[offset++] = 0x1f;
    outData[offset++] = 0x4b;outData[offset++] = 0xbd;outData[offset++] = 0x8b;outData[offset++] = 0x8a;
    outData[offset++] = 0x70;outData[offset++] = 0x3e;outData[offset++] = 0xb5;outData[offset++] = 0x66;
    outData[offset++] = 0x48;outData[offset++] = 0x03;outData[offset++] = 0xf6;outData[offset++] = 0x0e;
    outData[offset++] = 0x61;outData[offset++] = 0x35;outData[offset++] = 0x57;outData[offset++] = 0xb9;
    outData[offset++] = 0x86;outData[offset++] = 0xc1;outData[offset++] = 0x1d;outData[offset++] = 0x9e;
    outData[offset++] = 0xe1;outData[offset++] = 0xf8;outData[offset++] = 0x98;outData[offset++] = 0x11;
    outData[offset++] = 0x69;outData[offset++] = 0xd9;outData[offset++] = 0x8e;outData[offset++] = 0x94;
    outData[offset++] = 0x9b;outData[offset++] = 0x1e;outData[offset++] = 0x87;outData[offset++] = 0xe9;
    outData[offset++] = 0xce;outData[offset++] = 0x55;outData[offset++] = 0x28;outData[offset++] = 0xdf;
    outData[offset++] = 0x8c;outData[offset++] = 0xa1;outData[offset++] = 0x89;outData[offset++] = 0x0d;
    outData[offset++] = 0xbf;outData[offset++] = 0xe6;outData[offset++] = 0x42;outData[offset++] = 0x68;
    outData[offset++] = 0x41;outData[offset++] = 0x99;outData[offset++] = 0x2d;outData[offset++] = 0x0f;
    outData[offset++] = 0xb0;outData[offset++] = 0x54;outData[offset++] = 0xbb;outData[offset++] = 0x16;
}

void invSboxAssign(uint8 *outData)
{
    int offset = 0;

    if(NULL == outData)
    {
        return ;
    }

    /************************************************************************************
    // 0     1     2     3     4     5     6     7     8     9     a     b     c     d     e     f
	0x52, 0x09, 0x6a, 0xd5, 0x30, 0x36, 0xa5, 0x38, 0xbf, 0x40, 0xa3, 0x9e, 0x81, 0xf3, 0xd7, 0xfb, // 0
	0x7c, 0xe3, 0x39, 0x82, 0x9b, 0x2f, 0xff, 0x87, 0x34, 0x8e, 0x43, 0x44, 0xc4, 0xde, 0xe9, 0xcb, // 1
	0x54, 0x7b, 0x94, 0x32, 0xa6, 0xc2, 0x23, 0x3d, 0xee, 0x4c, 0x95, 0x0b, 0x42, 0xfa, 0xc3, 0x4e, // 2
	0x08, 0x2e, 0xa1, 0x66, 0x28, 0xd9, 0x24, 0xb2, 0x76, 0x5b, 0xa2, 0x49, 0x6d, 0x8b, 0xd1, 0x25, // 3
	0x72, 0xf8, 0xf6, 0x64, 0x86, 0x68, 0x98, 0x16, 0xd4, 0xa4, 0x5c, 0xcc, 0x5d, 0x65, 0xb6, 0x92, // 4
	0x6c, 0x70, 0x48, 0x50, 0xfd, 0xed, 0xb9, 0xda, 0x5e, 0x15, 0x46, 0x57, 0xa7, 0x8d, 0x9d, 0x84, // 5
	0x90, 0xd8, 0xab, 0x00, 0x8c, 0xbc, 0xd3, 0x0a, 0xf7, 0xe4, 0x58, 0x05, 0xb8, 0xb3, 0x45, 0x06, // 6
	0xd0, 0x2c, 0x1e, 0x8f, 0xca, 0x3f, 0x0f, 0x02, 0xc1, 0xaf, 0xbd, 0x03, 0x01, 0x13, 0x8a, 0x6b, // 7
	0x3a, 0x91, 0x11, 0x41, 0x4f, 0x67, 0xdc, 0xea, 0x97, 0xf2, 0xcf, 0xce, 0xf0, 0xb4, 0xe6, 0x73, // 8
	0x96, 0xac, 0x74, 0x22, 0xe7, 0xad, 0x35, 0x85, 0xe2, 0xf9, 0x37, 0xe8, 0x1c, 0x75, 0xdf, 0x6e, // 9
	0x47, 0xf1, 0x1a, 0x71, 0x1d, 0x29, 0xc5, 0x89, 0x6f, 0xb7, 0x62, 0x0e, 0xaa, 0x18, 0xbe, 0x1b, // a
	0xfc, 0x56, 0x3e, 0x4b, 0xc6, 0xd2, 0x79, 0x20, 0x9a, 0xdb, 0xc0, 0xfe, 0x78, 0xcd, 0x5a, 0xf4, // b
	0x1f, 0xdd, 0xa8, 0x33, 0x88, 0x07, 0xc7, 0x31, 0xb1, 0x12, 0x10, 0x59, 0x27, 0x80, 0xec, 0x5f, // c
	0x60, 0x51, 0x7f, 0xa9, 0x19, 0xb5, 0x4a, 0x0d, 0x2d, 0xe5, 0x7a, 0x9f, 0x93, 0xc9, 0x9c, 0xef, // d
	0xa0, 0xe0, 0x3b, 0x4d, 0xae, 0x2a, 0xf5, 0xb0, 0xc8, 0xeb, 0xbb, 0x3c, 0x83, 0x53, 0x99, 0x61, // e
	0x17, 0x2b, 0x04, 0x7e, 0xba, 0x77, 0xd6, 0x26, 0xe1, 0x69, 0x14, 0x63, 0x55, 0x21, 0x0c, 0x7d};// f
	******************************************************************************/
	outData[offset++] = 0x52;outData[offset++] = 0x09;outData[offset++] = 0x6a;outData[offset++] = 0xd5;
    outData[offset++] = 0x30;outData[offset++] = 0x36;outData[offset++] = 0xa5;outData[offset++] = 0x38;
    outData[offset++] = 0xbf;outData[offset++] = 0x40;outData[offset++] = 0xa3;outData[offset++] = 0x9e;
    outData[offset++] = 0x81;outData[offset++] = 0xf3;outData[offset++] = 0xd7;outData[offset++] = 0xfb;
    outData[offset++] = 0x7c;outData[offset++] = 0xe3;outData[offset++] = 0x39;outData[offset++] = 0x82;
    outData[offset++] = 0x9b;outData[offset++] = 0x2f;outData[offset++] = 0xff;outData[offset++] = 0x87;
    outData[offset++] = 0x34;outData[offset++] = 0x8e;outData[offset++] = 0x43;outData[offset++] = 0x44;
    outData[offset++] = 0xc4;outData[offset++] = 0xde;outData[offset++] = 0xe9;outData[offset++] = 0xcb;
    outData[offset++] = 0x54;outData[offset++] = 0x7b;outData[offset++] = 0x94;outData[offset++] = 0x32;
    outData[offset++] = 0xa6;outData[offset++] = 0xc2;outData[offset++] = 0x23;outData[offset++] = 0x3d;
    outData[offset++] = 0xee;outData[offset++] = 0x4c;outData[offset++] = 0x95;outData[offset++] = 0x0b;
    outData[offset++] = 0x42;outData[offset++] = 0xfa;outData[offset++] = 0xc3;outData[offset++] = 0x4e;
    outData[offset++] = 0x08;outData[offset++] = 0x2e;outData[offset++] = 0xa1;outData[offset++] = 0x66;
    outData[offset++] = 0x28;outData[offset++] = 0xd9;outData[offset++] = 0x24;outData[offset++] = 0xb2;
    outData[offset++] = 0x76;outData[offset++] = 0x5b;outData[offset++] = 0xa2;outData[offset++] = 0x49;
    outData[offset++] = 0x6d;outData[offset++] = 0x8b;outData[offset++] = 0xd1;outData[offset++] = 0x25;
    outData[offset++] = 0x72;outData[offset++] = 0xf8;outData[offset++] = 0xf6;outData[offset++] = 0x64;
    outData[offset++] = 0x86;outData[offset++] = 0x68;outData[offset++] = 0x98;outData[offset++] = 0x16;
    outData[offset++] = 0xd4;outData[offset++] = 0xa4;outData[offset++] = 0x5c;outData[offset++] = 0xcc;
    outData[offset++] = 0x5d;outData[offset++] = 0x65;outData[offset++] = 0xb6;outData[offset++] = 0x92;
    outData[offset++] = 0x6c;outData[offset++] = 0x70;outData[offset++] = 0x48;outData[offset++] = 0x50;
    outData[offset++] = 0xfd;outData[offset++] = 0xed;outData[offset++] = 0xb9;outData[offset++] = 0xda;
    outData[offset++] = 0x5e;outData[offset++] = 0x15;outData[offset++] = 0x46;outData[offset++] = 0x57;
    outData[offset++] = 0xa7;outData[offset++] = 0x8d;outData[offset++] = 0x9d;outData[offset++] = 0x84;
    outData[offset++] = 0x90;outData[offset++] = 0xd8;outData[offset++] = 0xab;outData[offset++] = 0x00;
    outData[offset++] = 0x8c;outData[offset++] = 0xbc;outData[offset++] = 0xd3;outData[offset++] = 0x0a;
    outData[offset++] = 0xf7;outData[offset++] = 0xe4;outData[offset++] = 0x58;outData[offset++] = 0x05;
    outData[offset++] = 0xb8;outData[offset++] = 0xb3;outData[offset++] = 0x45;outData[offset++] = 0x06;
    outData[offset++] = 0xd0;outData[offset++] = 0x2c;outData[offset++] = 0x1e;outData[offset++] = 0x8f;
    outData[offset++] = 0xca;outData[offset++] = 0x3f;outData[offset++] = 0x0f;outData[offset++] = 0x02;
    outData[offset++] = 0xc1;outData[offset++] = 0xaf;outData[offset++] = 0xbd;outData[offset++] = 0x03;
    outData[offset++] = 0x01;outData[offset++] = 0x13;outData[offset++] = 0x8a;outData[offset++] = 0x6b;
    outData[offset++] = 0x3a;outData[offset++] = 0x91;outData[offset++] = 0x11;outData[offset++] = 0x41;
    outData[offset++] = 0x4f;outData[offset++] = 0x67;outData[offset++] = 0xdc;outData[offset++] = 0xea;
    outData[offset++] = 0x97;outData[offset++] = 0xf2;outData[offset++] = 0xcf;outData[offset++] = 0xce;
    outData[offset++] = 0xf0;outData[offset++] = 0xb4;outData[offset++] = 0xe6;outData[offset++] = 0x73;
    outData[offset++] = 0x96;outData[offset++] = 0xac;outData[offset++] = 0x74;outData[offset++] = 0x22;
    outData[offset++] = 0xe7;outData[offset++] = 0xad;outData[offset++] = 0x35;outData[offset++] = 0x85;
    outData[offset++] = 0xe2;outData[offset++] = 0xf9;outData[offset++] = 0x37;outData[offset++] = 0xe8;
    outData[offset++] = 0x1c;outData[offset++] = 0x75;outData[offset++] = 0xdf;outData[offset++] = 0x6e;
    outData[offset++] = 0x47;outData[offset++] = 0xf1;outData[offset++] = 0x1a;outData[offset++] = 0x71;
    outData[offset++] = 0x1d;outData[offset++] = 0x29;outData[offset++] = 0xc5;outData[offset++] = 0x89;
    outData[offset++] = 0x6f;outData[offset++] = 0xb7;outData[offset++] = 0x62;outData[offset++] = 0x0e;
    outData[offset++] = 0xaa;outData[offset++] = 0x18;outData[offset++] = 0xbe;outData[offset++] = 0x1b;
    outData[offset++] = 0xfc;outData[offset++] = 0x56;outData[offset++] = 0x3e;outData[offset++] = 0x4b;
    outData[offset++] = 0xc6;outData[offset++] = 0xd2;outData[offset++] = 0x79;outData[offset++] = 0x20;
    outData[offset++] = 0x9a;outData[offset++] = 0xdb;outData[offset++] = 0xc0;outData[offset++] = 0xfe;
    outData[offset++] = 0x78;outData[offset++] = 0xcd;outData[offset++] = 0x5a;outData[offset++] = 0xf4;
    outData[offset++] = 0x1f;outData[offset++] = 0xdd;outData[offset++] = 0xa8;outData[offset++] = 0x33;
    outData[offset++] = 0x88;outData[offset++] = 0x07;outData[offset++] = 0xc7;outData[offset++] = 0x31;
    outData[offset++] = 0xb1;outData[offset++] = 0x12;outData[offset++] = 0x10;outData[offset++] = 0x59;
    outData[offset++] = 0x27;outData[offset++] = 0x80;outData[offset++] = 0xec;outData[offset++] = 0x5f;
    outData[offset++] = 0x60;outData[offset++] = 0x51;outData[offset++] = 0x7f;outData[offset++] = 0xa9;
    outData[offset++] = 0x19;outData[offset++] = 0xb5;outData[offset++] = 0x4a;outData[offset++] = 0x0d;
    outData[offset++] = 0x2d;outData[offset++] = 0xe5;outData[offset++] = 0x7a;outData[offset++] = 0x9f;
    outData[offset++] = 0x93;outData[offset++] = 0xc9;outData[offset++] = 0x9c;outData[offset++] = 0xef;
    outData[offset++] = 0xa0;outData[offset++] = 0xe0;outData[offset++] = 0x3b;outData[offset++] = 0x4d;
    outData[offset++] = 0xae;outData[offset++] = 0x2a;outData[offset++] = 0xf5;outData[offset++] = 0xb0;
    outData[offset++] = 0xc8;outData[offset++] = 0xeb;outData[offset++] = 0xbb;outData[offset++] = 0x3c;
    outData[offset++] = 0x83;outData[offset++] = 0x53;outData[offset++] = 0x99;outData[offset++] = 0x61;
    outData[offset++] = 0x17;outData[offset++] = 0x2b;outData[offset++] = 0x04;outData[offset++] = 0x7e;
    outData[offset++] = 0xba;outData[offset++] = 0x77;outData[offset++] = 0xd6;outData[offset++] = 0x26;
    outData[offset++] = 0xe1;outData[offset++] = 0x69;outData[offset++] = 0x14;outData[offset++] = 0x63;
    outData[offset++] = 0x55;outData[offset++] = 0x21;outData[offset++] = 0x0c;outData[offset++] = 0x7d;
}

/*
 * Addition in GF(2^8)
 * http://en.wikipedia.org/wiki/Finite_field_arithmetic
 */
uint8 gadd(uint8 a, uint8 b) {
	return a^b;
}

/*
 * Subtraction in GF(2^8)
 * http://en.wikipedia.org/wiki/Finite_field_arithmetic
 */
uint8 gsub(uint8 a, uint8 b) {
	return a^b;
}

/*
 * Multiplication in GF(2^8)
 * http://en.wikipedia.org/wiki/Finite_field_arithmetic
 * Irreducible polynomial m(x) = x8 + x4 + x3 + x + 1
 */
uint8 gmult(uint8 a, uint8 b) {

	uint8 p = 0, i = 0, hbs = 0;

	for (i = 0; i < 8; i++) {
		if (b & 1) {
			p ^= a;
		}

		hbs = a & 0x80;
		a <<= 1;
		if (hbs) a ^= 0x1b; // 0000 0001 0001 1011
		b >>= 1;
	}

	return (uint8)p;
}

/*
 * Addition of 4 byte words
 * m(x) = x4+1
 */
void coef_add(uint8 a[], uint8 b[], uint8 d[]) {

	d[0] = a[0]^b[0];
	d[1] = a[1]^b[1];
	d[2] = a[2]^b[2];
	d[3] = a[3]^b[3];
}

/*
 * Multiplication of 4 byte words
 * m(x) = x4+1
 */
void coef_mult(uint8 *a, uint8 *b, uint8 *d) {

	d[0] = gmult(a[0],b[0])^gmult(a[3],b[1])^gmult(a[2],b[2])^gmult(a[1],b[3]);
	d[1] = gmult(a[1],b[0])^gmult(a[0],b[1])^gmult(a[3],b[2])^gmult(a[2],b[3]);
	d[2] = gmult(a[2],b[0])^gmult(a[1],b[1])^gmult(a[0],b[2])^gmult(a[3],b[3]);
	d[3] = gmult(a[3],b[0])^gmult(a[2],b[1])^gmult(a[1],b[2])^gmult(a[0],b[3]);
}

/*
 * S-box transformation table
 */
static uint8 *s_box = NULL;
/*
 * Inverse S-box transformation table
 */

static uint8 *inv_s_box = NULL;
/*
 * Generates the round constant Rcon[i]
 */
static uint8 R[] = {0x02, 0x00, 0x00, 0x00};

void invSboxInit(void)
{
    if(NULL == inv_s_box)
    {
        inv_s_box = malloc(256);
        if(NULL == inv_s_box)
        {
            return ;
        }
        invSboxAssign(inv_s_box);
    }
}

void aesInit(void)
{
    if(NULL == s_box)
    {
        s_box = malloc(256);
        if(NULL == s_box)
        {
            return ;
        }
        sboxAssign(s_box);
    }

    invSboxInit();
}

void aesDestroy(void)
{
    if(NULL != s_box)
    {
        free(s_box);
        s_box = NULL;
    }

    if(NULL != inv_s_box)
    {
        free(inv_s_box);
        inv_s_box = NULL;
    }
}

uint8 * Rcon(uint8 i) {

	if (i == 1) {
		R[0] = 0x01; // x^(1-1) = x^0 = 1
	} else if (i > 1) {
		R[0] = 0x02;
		i--;
		while (i-1 > 0) {
			R[0] = gmult(R[0], 0x02);
			i--;
		}
	}

	return R;
}

/*
 * Transformation in the Cipher and Inverse Cipher in which a Round
 * Key is added to the State using an XOR operation. The length of a
 * Round Key equals the size of the State (i.e., for Nb = 4, the Round
 * Key length equals 128 bits/16 bytes).
 */
void add_round_key(uint8 *state, uint8 *w, uint8 r) {

	uint8 c;

	for (c = 0; c < AES_NB_LEN; c++) {
		state[AES_NB_LEN*0+c] = state[AES_NB_LEN*0+c]^w[4*AES_NB_LEN*r+4*c+0];   //debug, so it works for AES_NB_LEN !=4
		state[AES_NB_LEN*1+c] = state[AES_NB_LEN*1+c]^w[4*AES_NB_LEN*r+4*c+1];
		state[AES_NB_LEN*2+c] = state[AES_NB_LEN*2+c]^w[4*AES_NB_LEN*r+4*c+2];
		state[AES_NB_LEN*3+c] = state[AES_NB_LEN*3+c]^w[4*AES_NB_LEN*r+4*c+3];
	}
}

/*
 * Transformation in the Cipher that takes all of the columns of the
 * State and mixes their data (independently of one another) to
 * produce new columns.
 */
void mix_columns(uint8 *state) {

	uint8 a[] = {0x02, 0x01, 0x01, 0x03}; // a(x) = {02} + {01}x + {01}x2 + {03}x3
	uint8 i, j, col[4], res[4];

	for (j = 0; j < AES_NB_LEN; j++) {
		for (i = 0; i < 4; i++) {
			col[i] = state[AES_NB_LEN*i+j];
		}

		coef_mult(a, col, res);

		for (i = 0; i < 4; i++) {
			state[AES_NB_LEN*i+j] = res[i];
		}
	}
}

/*
 * Transformation in the Inverse Cipher that is the inverse of
 * MixColumns().
 */
void inv_mix_columns(uint8 *state) {

	uint8 a[] = {0x0e, 0x09, 0x0d, 0x0b}; // a(x) = {0e} + {09}x + {0d}x2 + {0b}x3
	uint8 i, j, col[4], res[4];

	for (j = 0; j < AES_NB_LEN; j++) {
		for (i = 0; i < 4; i++) {
			col[i] = state[AES_NB_LEN*i+j];
		}

		coef_mult(a, col, res);

		for (i = 0; i < 4; i++) {
			state[AES_NB_LEN*i+j] = res[i];
		}
	}
}

/*
 * Transformation in the Cipher that processes the State by cyclically
 * shifting the last three rows of the State by different offsets.
 */
void shift_rows(uint8 *state) {

	uint8 i, k, s, tmp;

	for (i = 1; i < 4; i++) {
		// shift(1,4)=1; shift(2,4)=2; shift(3,4)=3
		// shift(r, 4) = r;
		s = 0;
		while (s < i) {
			tmp = state[AES_NB_LEN*i+0];

			for (k = 1; k < AES_NB_LEN; k++) {
				state[AES_NB_LEN*i+k-1] = state[AES_NB_LEN*i+k];
			}

			state[AES_NB_LEN*i+AES_NB_LEN-1] = tmp;
			s++;
		}
	}
}

/*
 * Transformation in the Inverse Cipher that is the inverse of
 * ShiftRows().
 */
void inv_shift_rows(uint8 *state) {

	uint8 i, k, s, tmp;

	for (i = 1; i < 4; i++) {
		s = 0;
		while (s < i) {
			tmp = state[AES_NB_LEN*i+AES_NB_LEN-1];

			for (k = AES_NB_LEN-1; k > 0; k--) {
				state[AES_NB_LEN*i+k] = state[AES_NB_LEN*i+k-1];
			}

			state[AES_NB_LEN*i+0] = tmp;
			s++;
		}
	}
}

/*
 * Transformation in the Cipher that processes the State using a non-
 * linear byte substitution table (S-box) that operates on each of the
 * State bytes independently.
 */
void sub_bytes(uint8 *state) {

	uint8 i, j;
	uint8 row, col;

	for (i = 0; i < 4; i++) {
		for (j = 0; j < AES_NB_LEN; j++) {
			row = (state[AES_NB_LEN*i+j] & 0xf0) >> 4;
			col = state[AES_NB_LEN*i+j] & 0x0f;
			state[AES_NB_LEN*i+j] = s_box[16*row+col];
		}
	}
}

/*
 * Transformation in the Inverse Cipher that is the inverse of
 * SubBytes().
 */
void inv_sub_bytes(uint8 *state) {

	uint8 i, j;
	uint8 row, col;

	for (i = 0; i < 4; i++) {
		for (j = 0; j < AES_NB_LEN; j++) {
			row = (state[AES_NB_LEN*i+j] & 0xf0) >> 4;
			col = state[AES_NB_LEN*i+j] & 0x0f;
			state[AES_NB_LEN*i+j] = inv_s_box[16*row+col];
		}
	}
}

/*
 * Function used in the Key Expansion routine that takes a four-byte
 * input word and applies an S-box to each of the four bytes to
 * produce an output word.
 */
void sub_word(uint8 *w) {

	uint8 i;

	for (i = 0; i < 4; i++) {
		w[i] = s_box[16*((w[i] & 0xf0) >> 4) + (w[i] & 0x0f)];
	}
}

/*
 * Function used in the Key Expansion routine that takes a four-byte
 * word and performs a cyclic permutation.
 */
void rot_word(uint8 *w) {

	uint8 tmp;
	uint8 i;

	tmp = w[0];

	for (i = 0; i < 3; i++) {
		w[i] = w[i+1];
	}

	w[3] = tmp;
}

/*
 * Key Expansion
 */
void key_expansion(uint8 *key, uint8 *w) {

	uint8 tmp[4];
	uint8 i, j;
	uint8 len = AES_NB_LEN*(AES_NR_LEN+1);

	for (i = 0; i < AES_NK_LEN; i++) {
		w[4*i+0] = key[4*i+0];
		w[4*i+1] = key[4*i+1];
		w[4*i+2] = key[4*i+2];
		w[4*i+3] = key[4*i+3];
	}

	for (i = AES_NK_LEN; i < len; i++) {
		tmp[0] = w[4*(i-1)+0];
		tmp[1] = w[4*(i-1)+1];
		tmp[2] = w[4*(i-1)+2];
		tmp[3] = w[4*(i-1)+3];

		if (i%AES_NK_LEN == 0) {

			rot_word(tmp);
			sub_word(tmp);
			coef_add(tmp, Rcon(i/AES_NK_LEN), tmp);

		} else if (AES_NK_LEN > 6 && i%AES_NK_LEN == 4) {

			sub_word(tmp);

		}

		w[4*i+0] = w[4*(i-AES_NK_LEN)+0]^tmp[0];
		w[4*i+1] = w[4*(i-AES_NK_LEN)+1]^tmp[1];
		w[4*i+2] = w[4*(i-AES_NK_LEN)+2]^tmp[2];
		w[4*i+3] = w[4*(i-AES_NK_LEN)+3]^tmp[3];
	}
}

void cipher(uint8 *in, uint8 *out, uint8 *w) {

	uint8 state[4*AES_NB_LEN];
	uint8 r, i, j;

	for (i = 0; i < 4; i++) {
		for (j = 0; j < AES_NB_LEN; j++) {
			state[AES_NB_LEN*i+j] = in[i+4*j];
		}
	}

	add_round_key(state, w, 0);

	for (r = 1; r < AES_NR_LEN; r++) {
		sub_bytes(state);
		shift_rows(state);
		mix_columns(state);
		add_round_key(state, w, r);
	}

	sub_bytes(state);
	shift_rows(state);
	add_round_key(state, w, AES_NR_LEN);

	for (i = 0; i < 4; i++) {
		for (j = 0; j < AES_NB_LEN; j++) {
			out[i+4*j] = state[AES_NB_LEN*i+j];
		}
	}
}

void inv_cipher(uint8 *in, uint8 *out, uint8 *w) {

	uint8 state[4*AES_NB_LEN];
	uint8 r, i, j;

	for (i = 0; i < 4; i++) {
		for (j = 0; j < AES_NB_LEN; j++) {
			state[AES_NB_LEN*i+j] = in[i+4*j];
		}
	}

	add_round_key(state, w, AES_NR_LEN);

	for (r = AES_NR_LEN-1; r >= 1; r--) {
		inv_shift_rows(state);
		inv_sub_bytes(state);
		add_round_key(state, w, r);
		inv_mix_columns(state);
	}

	inv_shift_rows(state);
	inv_sub_bytes(state);
	add_round_key(state, w, 0);

	for (i = 0; i < 4; i++) {
		for (j = 0; j < AES_NB_LEN; j++) {
			out[i+4*j] = state[AES_NB_LEN*i+j];
		}
	}
}

/**/
uint32 aesECB128Encrypt(uint8 *in, uint8 *out, uint8 *key, uint32 len)
{
    uint8 *w; // expanded key
    uint32 remain = len;
    uint8 data[AES_BLOCK_LEN];
    uint32 readed = 0;

    if(NULL == in || NULL == out || NULL == key || len == 0)
    {
        return 0;
    }

    w = malloc( AES_NB_LEN *(AES_NR_LEN + 1)*4);
    if(NULL == w)
    {
        return 0;
    }

    key_expansion(key, w);

    while(readed < len || remain == 0)
    {
        if(remain == 0)
        {
            // pkcs7 padding (add a whole block)
            memset(data, AES_BLOCK_LEN, AES_BLOCK_LEN);
        }
        else if(remain < AES_BLOCK_LEN)
        {
            // pkcs7 padding
            memcpy(data, in + readed, remain);
            memset(data + remain, AES_BLOCK_LEN - remain, AES_BLOCK_LEN - remain);
        }
        else
        {
            memcpy(data, in + readed, AES_BLOCK_LEN);
        }

        cipher(data, out + readed, w);

        readed += AES_BLOCK_LEN;
        remain -= AES_BLOCK_LEN;
    }

    free(w);

    return readed;
}

uint32 aesECB128Decrypt(uint8 *in, uint8 *out, uint8 *key, uint32 len)
{
    uint8 *w; // expanded key
    uint8 data[AES_BLOCK_LEN];
    uint32 readed = 0;
    int i;
    int repeat = 1;

    if(NULL == in || NULL == out || NULL == key || len == 0)
    {
        return 0;
    }

    w = malloc( AES_NB_LEN *(AES_NR_LEN + 1)*4);
    if(NULL == w)
    {
        return 0;
    }

    key_expansion(key, w);

    while(readed < len)
    {

        memcpy(data, in + readed, AES_BLOCK_LEN);

        inv_cipher(data, out + readed, w);

        readed += AES_BLOCK_LEN;
    }

    // remove pkcs7 padding
    readed -= out[readed - 1];

    free(w);

    return readed;
}

int _main(int argc, char *argv[])
{
    //uint8 key[] = {0xcb,0xf8,0xe9,0x86,0xbe,0xfd,0x4d,0x7c,0xb1,0x8a,0x6c,0xa4,0xac,0x46,0x7d,0x73};
    //uint8 key[] = "611bf7b337a3452b";
    uint8 *key = (uint8 *)argv[1];

    //uint8 in[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0};
    //uint8 in[] = "abc";
    uint8 *in = (uint8 *)argv[2];
    int in_len = strlen(in);

    uint8 out1[128] = {0};
    uint8 out2[128] = {0};
    int len;

    printf("     in: \n");
    printf("--------------\n");
    print_buf(in, in_len);

    aesInit();

    len = (int)aesECB128Encrypt(in, out1, (uint8 *)key, in_len);
    if(len > 0)
    {
        printf("\noutput1: \n");
        printf("--------------\n");
        print_buf(out1, len);
    }

    len = (int)aesECB128Decrypt(out1, out2, (uint8 *)key, len);
    if(len > 0)
    {
        printf("\noutput2: \n");
        printf("--------------\n");
        print_buf(out2, len);
    }

    aesDestroy();
    //len = (int)aesECB128Encrypt(in2, out, (uint8 *)"601bf7b337a3452b", sizeof(in2));
    //len = (int)aesECB128Decrypt(out, tmp, (uint8 *)"601bf7b337a3452b", len);
    return 0;
}

