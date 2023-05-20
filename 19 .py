#include "msp430.h"
#include "TI_DES.h"
int main( void )
{
 des_ctx dc1; // Key schedule structure
 unsigned char *cp;
 unsigned char data[] = { 0x69, 0xc4, 0xe0, 0xd8, 0x6a, 0x7b, 0x04, 0x30,
 0xd8, 0xcd, 0xb7, 0x80, 0x70, 0xb4, 0xc5, 0x5a};
 unsigned char key[8] = {0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xfe};
 cp = data;
 Des_Key(&dc1, key, ENDE ); // Sets up key schedule for Encryption and
 Decryption
 DES_Enc_CBC(&dc, cp, 2); //Encrypt Data, Result is stored back into Data
 DES_Dec_CBC(&dc, cp, 2); //Decrypt Data, Result is stored back into Data
return 0;
}
