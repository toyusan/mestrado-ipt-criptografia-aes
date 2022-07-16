/**
 ******************************************************************************
 * @file      	aes_app.h
 * @author    	Airton Toyofuku
 * @date      	14 de jul de 2022
 * @version   	1.0.0
 * @brief     	AES Cryptography Header file
 ******************************************************************************
 */
#ifndef INC_AES_APP_H_
#define INC_AES_APP_H_

/* Includes ------------------------------------------------------------------*/

/* Public typedef ------------------------------------------------------------*/

/* Public function prototypes -----------------------------------------------*/
void encrypt_ecb(char * plainText, char * key, unsigned char * outputBuffer);
void decrypt_ecb(unsigned char * chipherText, char * key, unsigned char * outputBuffer);

void encrypt_cbc(char * plainText, char * key, unsigned char * outputBuffer);
void decrypt_cbc(unsigned char * chipherText, char * key, unsigned char * outputBuffer);

#endif /* INC_AES_APP_H_ */
