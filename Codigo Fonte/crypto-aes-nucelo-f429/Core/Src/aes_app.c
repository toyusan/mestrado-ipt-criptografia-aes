/**
 ******************************************************************************
 * @file      	aes_app.c
 * @author    	Airton Toyofuku
 * @date      	14 de jul de 2022
 * @version   	1.0.0
 * @brief     	AES Cryptography Application Code
 ******************************************************************************
 */
/* Private includes ----------------------------------------------------------*/
#include "mbedtls.h"
#include "stdio.h"
#include "string.h"
#include "aes.h"

/* Private typedef -----------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/


/* Public function ----------------------------------------------------------*/

void encrypt_ecb(char * plainText, char * key, unsigned char * outputBuffer){

	mbedtls_aes_context aes;

	mbedtls_aes_init( &aes );
	mbedtls_aes_setkey_enc( &aes, (const unsigned char*) key, strlen(key) * 8 );
	mbedtls_aes_crypt_ecb( &aes, MBEDTLS_AES_ENCRYPT, (const unsigned char*)plainText, outputBuffer);
	mbedtls_aes_free( &aes );

	printf("Original plain text: %s\r\n", plainText);

	printf("Ciphered text: ");
	for (int i = 0; i < 16; i++) {

		printf("%c", (int)outputBuffer[i]);
	}
}

void decrypt_ecb(unsigned char * chipherText, char * key, unsigned char * outputBuffer){

	mbedtls_aes_context aes;

	mbedtls_aes_init( &aes );
	mbedtls_aes_setkey_dec( &aes, (const unsigned char*) key, strlen(key) * 8 );
	mbedtls_aes_crypt_ecb(&aes, MBEDTLS_AES_DECRYPT, (const unsigned char*)chipherText, outputBuffer);
	mbedtls_aes_free( &aes );

	printf("\r\nDeciphered text: ");
	for (int i = 0; i < 16; i++) {
		printf("%c",(char)outputBuffer[i]);
	}
	printf("\r\n");
}

void encrypt_cbc(char * plainText, char * key, unsigned char * outputBuffer){

	mbedtls_aes_context aes;

    unsigned char iv[] = {0xff, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f};

	mbedtls_aes_init( &aes );
	mbedtls_aes_setkey_enc( &aes, (const unsigned char*) key, strlen(key) * 8 );
	mbedtls_aes_crypt_cbc( &aes, MBEDTLS_AES_ENCRYPT,strlen(plainText), iv, (const unsigned char*)plainText, outputBuffer);
	mbedtls_aes_free( &aes );

	printf("Original plain text: %s\r\n", plainText);

	printf("Ciphered text: ");
	for (int i = 0; i < 16; i++) {

		printf("%c", (int)outputBuffer[i]);
	}
}

void decrypt_cbc(unsigned char * chipherText, char * key, unsigned char * outputBuffer){

	mbedtls_aes_context aes;
    unsigned char iv1[] = {0xff, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f};

	mbedtls_aes_init( &aes );
	mbedtls_aes_setkey_dec( &aes, (const unsigned char*) key, strlen(key) * 8 );
	mbedtls_aes_crypt_cbc(&aes, MBEDTLS_AES_DECRYPT,strlen(chipherText), iv1, (const unsigned char*)chipherText, outputBuffer);
	mbedtls_aes_free( &aes );

	printf("\r\nDeciphered text: ");
	for (int i = 0; i < 16; i++) {
		printf("%c",(char)outputBuffer[i]);
	}
	printf("\r\n");
}
/* Private function ----------------------------------------------------------*/


