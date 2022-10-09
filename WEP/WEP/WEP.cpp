#include <stdio.h>
#include <iostream>
#include<math.h>
#include<conio.h>
#include <Windows.h>
#include<string.h>
using namespace std;

//Public  Variables
bool IVi[16][24];
///// --------------------------------------- CRC32 ---------------------------------------

static int crc_32_tab[] = { /* CRC polynomial 0xedb88320 */
0x00000000, 0x77073096, 0xee0e612c, 0x990951ba, 0x076dc419, 0x706af48f,
0xe963a535, 0x9e6495a3, 0x0edb8832, 0x79dcb8a4, 0xe0d5e91e, 0x97d2d988,
0x09b64c2b, 0x7eb17cbd, 0xe7b82d07, 0x90bf1d91, 0x1db71064, 0x6ab020f2,
0xf3b97148, 0x84be41de, 0x1adad47d, 0x6ddde4eb, 0xf4d4b551, 0x83d385c7,
0x136c9856, 0x646ba8c0, 0xfd62f97a, 0x8a65c9ec, 0x14015c4f, 0x63066cd9,
0xfa0f3d63, 0x8d080df5, 0x3b6e20c8, 0x4c69105e, 0xd56041e4, 0xa2677172,
0x3c03e4d1, 0x4b04d447, 0xd20d85fd, 0xa50ab56b, 0x35b5a8fa, 0x42b2986c,
0xdbbbc9d6, 0xacbcf940, 0x32d86ce3, 0x45df5c75, 0xdcd60dcf, 0xabd13d59,
0x26d930ac, 0x51de003a, 0xc8d75180, 0xbfd06116, 0x21b4f4b5, 0x56b3c423,
0xcfba9599, 0xb8bda50f, 0x2802b89e, 0x5f058808, 0xc60cd9b2, 0xb10be924,
0x2f6f7c87, 0x58684c11, 0xc1611dab, 0xb6662d3d, 0x76dc4190, 0x01db7106,
0x98d220bc, 0xefd5102a, 0x71b18589, 0x06b6b51f, 0x9fbfe4a5, 0xe8b8d433,
0x7807c9a2, 0x0f00f934, 0x9609a88e, 0xe10e9818, 0x7f6a0dbb, 0x086d3d2d,
0x91646c97, 0xe6635c01, 0x6b6b51f4, 0x1c6c6162, 0x856530d8, 0xf262004e,
0x6c0695ed, 0x1b01a57b, 0x8208f4c1, 0xf50fc457, 0x65b0d9c6, 0x12b7e950,
0x8bbeb8ea, 0xfcb9887c, 0x62dd1ddf, 0x15da2d49, 0x8cd37cf3, 0xfbd44c65,
0x4db26158, 0x3ab551ce, 0xa3bc0074, 0xd4bb30e2, 0x4adfa541, 0x3dd895d7,
0xa4d1c46d, 0xd3d6f4fb, 0x4369e96a, 0x346ed9fc, 0xad678846, 0xda60b8d0,
0x44042d73, 0x33031de5, 0xaa0a4c5f, 0xdd0d7cc9, 0x5005713c, 0x270241aa,
0xbe0b1010, 0xc90c2086, 0x5768b525, 0x206f85b3, 0xb966d409, 0xce61e49f,
0x5edef90e, 0x29d9c998, 0xb0d09822, 0xc7d7a8b4, 0x59b33d17, 0x2eb40d81,
0xb7bd5c3b, 0xc0ba6cad, 0xedb88320, 0x9abfb3b6, 0x03b6e20c, 0x74b1d29a,
0xead54739, 0x9dd277af, 0x04db2615, 0x73dc1683, 0xe3630b12, 0x94643b84,
0x0d6d6a3e, 0x7a6a5aa8, 0xe40ecf0b, 0x9309ff9d, 0x0a00ae27, 0x7d079eb1,
0xf00f9344, 0x8708a3d2, 0x1e01f268, 0x6906c2fe, 0xf762575d, 0x806567cb,
0x196c3671, 0x6e6b06e7, 0xfed41b76, 0x89d32be0, 0x10da7a5a, 0x67dd4acc,
0xf9b9df6f, 0x8ebeeff9, 0x17b7be43, 0x60b08ed5, 0xd6d6a3e8, 0xa1d1937e,
0x38d8c2c4, 0x4fdff252, 0xd1bb67f1, 0xa6bc5767, 0x3fb506dd, 0x48b2364b,
0xd80d2bda, 0xaf0a1b4c, 0x36034af6, 0x41047a60, 0xdf60efc3, 0xa867df55,
0x316e8eef, 0x4669be79, 0xcb61b38c, 0xbc66831a, 0x256fd2a0, 0x5268e236,
0xcc0c7795, 0xbb0b4703, 0x220216b9, 0x5505262f, 0xc5ba3bbe, 0xb2bd0b28,
0x2bb45a92, 0x5cb36a04, 0xc2d7ffa7, 0xb5d0cf31, 0x2cd99e8b, 0x5bdeae1d,
0x9b64c2b0, 0xec63f226, 0x756aa39c, 0x026d930a, 0x9c0906a9, 0xeb0e363f,
0x72076785, 0x05005713, 0x95bf4a82, 0xe2b87a14, 0x7bb12bae, 0x0cb61b38,
0x92d28e9b, 0xe5d5be0d, 0x7cdcefb7, 0x0bdbdf21, 0x86d3d2d4, 0xf1d4e242,
0x68ddb3f8, 0x1fda836e, 0x81be16cd, 0xf6b9265b, 0x6fb077e1, 0x18b74777,
0x88085ae6, 0xff0f6a70, 0x66063bca, 0x11010b5c, 0x8f659eff, 0xf862ae69,
0x616bffd3, 0x166ccf45, 0xa00ae278, 0xd70dd2ee, 0x4e048354, 0x3903b3c2,
0xa7672661, 0xd06016f7, 0x4969474d, 0x3e6e77db, 0xaed16a4a, 0xd9d65adc,
0x40df0b66, 0x37d83bf0, 0xa9bcae53, 0xdebb9ec5, 0x47b2cf7f, 0x30b5ffe9,
0xbdbdf21c, 0xcabac28a, 0x53b39330, 0x24b4a3a6, 0xbad03605, 0xcdd70693,
0x54de5729, 0x23d967bf, 0xb3667a2e, 0xc4614ab8, 0x5d681b02, 0x2a6f2b94,
0xb40bbe37, 0xc30c8ea1, 0x5a05df1b, 0x2d02ef8d
};

int UPDC32(int octet, int crc) {
	return (crc_32_tab[((crc) ^ (octet)) & 0xff] ^ ((crc) >> 8));
}

char* CRC(char *buf, size_t len) {
	register int oldcrc32;
	oldcrc32 = 0xFFFFFFFF;
	for ( ; len; --len, ++buf)
		oldcrc32 = UPDC32(*buf, oldcrc32);

	oldcrc32=~oldcrc32;

	char *res=new char[5];
	memcpy(res, &oldcrc32, 4);
	res[4]=0;

	return res;
}

///// --------------------------------------- ----- ---------------------------------------
///// --------------------------------------- ----- ---------------------------------------



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

void IV(int n)
{
	int x=0;
	if (n>=1 && n<=2)
		x=1;
	else if (n>2 && n<=4)
		x=2;
	else if (n>4 && n<=8)
		x=3;
	else if (n>8 && n<=16)
		x=4;

	cout<<"\nPattern bit is : "<<x;

	bool  PatternBit[16][4],TempPattern[4]={0};
	int bit;
	bool find=false;
	//int cnt=0;
	for(int i=0;i<n;)
	{
		cout<<"\nEnter Pattern "<<(i+1)<<" (input 0 or 1): ";
		find=true;
		for (int j=0;j<x;j++)
		{	
			do {
			cin>>bit;
			if (bit==0)
				TempPattern[j]=bit;
			else if (bit==1)
				TempPattern[j]=bit;
			}while (bit<0 || bit>1);
		}
		for (int j=0;j<i;j++)
		{	
			find=false;
			for (int k=0;k<x;k++)
			{
				if (TempPattern[k]!=PatternBit[j][k])
				{
					find=true;
					break;
				}
			}
			if(find==false)
				break;
		}
		if (find==true)
		{
			for (int k=0;k<x;k++)
				PatternBit[i][k]=TempPattern[k];
			i++;
		}
	}

	for(int i=0;i<n;i++)
	{
		cout<<"\nPattern "<<(i+1)<<" : ";
		for (int j=0;j<x;j++)
		{
			cout<<PatternBit[i][j];
		}
	}

	cout<<"\nEnter location of active pattern (between 0-7): ";
	int k;
	bool location[8]={0};
	int loc[4];

	for (int i=0;i<x;i++)
	{
		do {
		cin>>k;
		}while (k<0 || k>7);
		location[k]=1;
		loc[i]=k;
	}
	cout<<"\n\nlocation:\n";
	for (int i=0;i<8;i++)
		cout<<location[i];

	
	for(int i=0;i<n;i++)
	{
		for (int j=0;j<x;j++)
		{
			IVi[i][loc[j]]=PatternBit[i][j];
		}
	}

	cout<<"\nIV Patterns:\n\n";
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<24;j++)
		{
			cout<<IVi[i][j];
			if (j==7 || j==15)
				cout<<"  ";
		}
		cout<<endl<<endl;
	}
}
char GetHex(char ch)
{
	switch(ch)
	{
	case '0':
	case '1':
	case '2':	
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	case 'a':
	case 'A':
	case 'b':
	case 'B':
	case 'c':
	case 'C':
	case 'd':
	case 'D':
	case 'f':
	case 'F':
		return ch;
		break;
	default ://cout<<"Invalid character in hexadecimal";
			return 0;
			break;
	}

}
char* Security()
{
	system("cls");
	cout<<"Enter security code:";
	cout<<"\n1- 5 case-sensitive characters";
	cout<<"\n2- 13 case-sensitive characters";
	cout<<"\n3- 10 hexadecimal characters";
	cout<<"\n4- 26 hexadecimal characters";
	int n;
	cout<<"\nEnter between 1-4: "; 
	do{
		cin>>n;
	}while (n<1 || n>4);

	char pass1[6],pass2[14],pass3[11],pass4[27];
	char *Pass;
	cout<<"\nEnter password: ";
	char ch;
	int i=0;
	switch (n)
	{
	case 1:
		for (i=0;i<5;i++)
		{
			ch=getche();
			pass1[i]=ch;
		}
		pass1[i]='\0';
		Pass=new char[strlen(pass1)];
		strcpy(Pass,pass1);
		return Pass;
		break;
	case 2:
		for (i=0;i<13;i++)
		{
			ch=getche();
			pass2[i]=ch;
		}
		pass2[i]='\0';
		Pass=new char[strlen(pass2)];
		strcpy(Pass,pass2);
		return Pass;
		break;
	case 3:
		for (i=0;i<10;)
		{
			ch=getche();
			if (GetHex(ch))
			{
				pass3[i]=ch;
				i++;
			}
		}

		pass3[i]='\0';
		Pass=new char[strlen(pass3)];
		strcpy(Pass,pass3);
		return Pass;
		break;
	case 4:
		for (i=0;i<26;)
		{
			ch=getche();
			if (GetHex(ch))
			{
				pass4[i]=ch;
				i++;
			}
		}
		pass4[i]='\0';
		Pass=new char[strlen(pass4)];
		strcpy(Pass,pass4);
		return Pass;
		
		break;
	}
}
long int ConvertTo10(bool bit[])
{
	long int sum=0,p=1;
	
	for (int i=23;i>=0;i--)
	{
		sum=bit[i]*p+sum;
		p*=2;
	}
	return sum;
}

void main()
{
	/*bool b[24]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0};
	ConvertTo10(b);
	*///printf ("\n%s",result);
	//cout<<"\n"<<Security();
	char* result,*cipher,*org;
	cout<<"Enter number of users (1<n<16): ";
	int n;
	do {
	cin>>n;
	}while (n<1 || n>16);
	
	IV(n);

	char str[100];
	bool iv[24];
	result=Security();
	long int cntIV=0;
	for (int k=0;k<MAXINT16;k++)
	{
	system("cls");
	cout<<"\nEnter your data: ";
	cin>>str;

	for (int i=0;i<n;i++)
	{
		for(int j=0;j<24;j++)
		{
			iv[j]=IVi[i][j];
		}
		cntIV=ConvertTo10(iv)+k;
			cipher=WEP_encrypt(str, strlen(str), cntIV, result, strlen(result));
			cout<<"Cipher: "<<endl;
			for(int i=0; i<strlen(str)+7; i++)
				cout<<(int)(unsigned char)cipher[i]<<" ";
			
			org=WEP_decrypt(cipher, strlen(str)+7, result, strlen(result));
		if(org!=0)
			cout<<"\nDecrypt: "<<org<<endl;
	}
	getch();
	}
	//// SENDER
	//char* cipher = WEP_encrypt(str, strLen, 121354, "pass", 4);
	//for(int i=0; i<strLen+7; i++)
	//	cout<<(int)(unsigned char)cipher[i]<<" ";
	//cout<<endl;



	//// RECIEVER
	//char* org=WEP_decrypt(cipher, strLen+7, "pass", 4);
	//if(org!=0)
	//	cout<<org<<endl;
	//else
	//	cout<<"Error";
	
	getch();
	
}


