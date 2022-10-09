#include <stdio.h>
#include <iostream>
using namespace std;


unsigned char* KSA(char* key, int keylen){
	unsigned char* s=new unsigned char[256];
	for(int i=0; i<256; i++)
		s[i]=i;

	int j=0;
	for(int i=0; i<256; i++){
		j=(j+s[i]+(unsigned char)key[i % keylen]) % 255;
		swap(s[i], s[j]);
	}
	return s;
}

char PRGA(unsigned char* s, int &i, int &j){
	i=(i+1)%256;
	j=(j+s[i])%256;
	swap(s[i], s[j]);
	return s[(s[i]+s[j])%256];
}

char* RC4(char* key, int keylen, char* input, int inputLen){
	unsigned char* s=KSA(key, keylen);

	char* output=new char[inputLen];
	int i=0,j=0;
	for(int l=0; l<inputLen; l++)
		output[l]=PRGA(s, i, j) ^ input[l];

	return output;
}


char* CRC(char* text, int textLen){
	return "1234";
}


char* WEP_encrypt(char* text, int textLen, int IV, char* key, int keyLen){
	char* textCrc = new char[textLen+4];
	memcpy(textCrc, text, textLen);
	memcpy(textCrc+textLen, CRC(text, textLen), 4);


	char* ivKey=new char[3+keyLen];
	ivKey[0]=IV & 255;
	ivKey[1]=(IV>>8) & 255;
	ivKey[2]=(IV>>16) & 255;
	memcpy(ivKey+3, key, keyLen);

	char* cipher=RC4(ivKey, 3+keyLen, textCrc, textLen+4);
	char* ivCipher=new char[3+textLen+4];
	ivCipher[0]=IV & 255;
	ivCipher[1]=(IV>>8) & 255;
	ivCipher[2]=(IV>>16) & 255;
	for(int i=0; i<textLen+4; i++)
		ivCipher[i+3]=cipher[i];

	return ivCipher;
}


char* WEP_decrypt(char* ivCipher, int ivCipherLen, char* key, int keyLen){
	char* ivKey=new char[keyLen+3];
	ivKey[0]=ivCipher[0];
	ivKey[1]=ivCipher[1];
	ivKey[2]=ivCipher[2];
	memcpy(ivKey+3, key, keyLen);

	int textLen=ivCipherLen-7; 
	char* textCrc=RC4(ivKey, keyLen+3, ivCipher+3, ivCipherLen-3);
	if(memcmp( CRC(textCrc, textLen) , textCrc+textLen , 4) != 0)
		return 0;
	textCrc[textLen]=0;
	return textCrc;
}



int main(){
	char str[]="hello world";
	int strLen=strlen(str);

	
	// SENDER
	char* cipher = WEP_encrypt(str, strLen, 121354, "pass", 4);
	for(int i=0; i<strLen+7; i++)
		cout<<(int)(unsigned char)cipher[i]<<" ";
	cout<<endl;



	// RECIEVER
	char* org=WEP_decrypt(cipher, strLen+7, "pass", 4);
	if(org!=0)
		cout<<org<<endl;
	else
		cout<<"Error";
}

