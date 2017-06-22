#include<stdio.h>
#include <string.h>
#include "util.h"
#include "aes.h"

int main(int argc, char *argv[])
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

    printf("     in: ");
    print_buf(in, in_len);

    aesInit();

    len = (int)aesECB128Encrypt(in, out1, (uint8 *)key, in_len);
    if(len > 0)
    {
        printf("output1: ");
        print_buf(out1, len);
    }

    len = (int)aesECB128Decrypt(out1, out2, (uint8 *)key, len);
    if(len > 0)
    {
        printf("output2: ");
        print_buf(out2, len);
    }

    aesDestroy();
    //len = (int)aesECB128Encrypt(in2, out, (uint8 *)"601bf7b337a3452b", sizeof(in2));
    //len = (int)aesECB128Decrypt(out, tmp, (uint8 *)"601bf7b337a3452b", len);
    return 0;
}

