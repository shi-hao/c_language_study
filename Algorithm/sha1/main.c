#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//位(bit), 字节(byte), 字(32位)
#define   sha1_word              unsigned int 
#define   sha1_block_size_byte   64  

//循环左移运算
#define  S(n, x)  ((n>=0 && n<=32)?((x<<n) | (x>>(32-n))):(0))

#define swap32endian(a)	  (((a&0x000000ff)<<24) | ((a&0x0000ff00)<<8) | ((a&0x00ff0000)>>8) | ((a&0xff000000)>>24))

//数据缓存
typedef struct _buffer_{
	unsigned long capacity;
	unsigned long len;
	unsigned long  offset;
	unsigned char *data;
}buffer,*buffer_p;

#define  sha256_bit         256
#define  sha256_byte        32
#define  sha256_mod_val     64
#define  sha256_mod_val2    56
#define  sha256_bit_add     0x80
#define  buffer_size        1024

//原始数据增补bit位数
int hash_add_bit(buffer_p buff){

	int add_byte;

	if((buff->len % sha256_mod_val) < sha256_mod_val2)
		add_byte = sha256_mod_val2 - (buff->len % sha256_mod_val);
	else 
		add_byte = sha256_mod_val + sha256_mod_val2 - (buff->len % sha256_mod_val);

	if((buff->len + add_byte) <= buff->capacity)
		(buff->data)[buff->len] = 0x80;
	buff->len += add_byte;

	return add_byte;
}

//检测大小端，返回-1,表示小端，返回1,则是大端
int checkEndian(){
	
	unsigned short var = 0x11ff;
	if(*((unsigned char*)&var) == 0xff)
		return -1;
	else 
		return 1;
}

//增补后的数据，增加数据长度bit位长度 
int hash_add_data_len(buffer_p buff, unsigned long len){

#if 0
	//little-endian 
	*(unsigned long *)(buff->data + buff->len) = len;
	buff->len += sizeof(unsigned long);
#else
	//big-endian
	buff->data[buff->len]   = len*8 >> 56;
	buff->data[buff->len+1] = len*8 >> 48;
	buff->data[buff->len+2] = len*8 >> 40;
	buff->data[buff->len+3] = len*8 >> 32;

	buff->data[buff->len+4] = len*8 >> 24;
	buff->data[buff->len+5] = len*8 >> 16;
	buff->data[buff->len+6] = len*8 >> 8;
	buff->data[buff->len+7] = len*8;
	buff->len += sizeof(unsigned long);

	return 0;
#endif
}

//初始化buffer
int buffer_init(buffer_p buff){

	if(buff->data = (unsigned char*)malloc(buffer_size * sizeof(char))){
		buff->capacity = buffer_size;
		buff->len = 0;
		buff->offset = 0;
		memset(buff->data, 0, buff->capacity);
		return 1;
	}
}

//将数据存入buffer
int buffer_add_data(buffer_p buff, char* data, int size){

	if(size < buff->capacity){

		memcpy(buff->data, data, size);
		buff->len = size;

	}else{
		printf("\n buffer overflow \n");
	}
}

//打印buffer数据
int printf_buffer(buffer_p buff){

	for(int tmp=0;tmp < buff->len; tmp++)
		printf("\n buff data[%d] = %#.2x",tmp, (buff->data)[tmp]);
}

int main(int argc, char* argv[]){

	unsigned char  orginal_data[1024]="sfsffffffffffffffffffffffffssssssssssssssssf";
	unsigned long  data_len;
	unsigned char* data;
	unsigned long  m_bit_len;
	unsigned long  m_block_size;
	buffer mbuff;

	sha1_word param_A, param_B, param_C, param_D, param_E;
	sha1_word buf_H[5]={
		0x67452301,
		0xEFCDAB89,
		0x98BADCFE,
		0x10325476,
		0xC3D2E1F0,
	};
	sha1_word buf_W[80]={0};
	sha1_word F,K;

	if(argc < 2)
	{
		printf("\n please input param string \n");
		return 0;
	}
	data = argv[1];

	//unsigned char test = 0x80;
	//printf("\n test = %#.2x \n", test);

	printf("\n data len = %ld \n", strlen(data));
	data_len = strlen(data);

	buffer_init(&mbuff);
	buffer_add_data(&mbuff, data, strlen(data));

	//将数据增补比特位，增加数据长度，最后数据的比特位长度能被512整除
	//计算消息摘要时，每次计算一个块，每个块比特位长度为512
	hash_add_bit(&mbuff);
	hash_add_data_len(&mbuff, data_len);

	//printf_buffer(&mbuff);

	m_bit_len = mbuff.len * 8;
	m_block_size = m_bit_len / 512;
	printf("\n message bit len = %ld, block size = %ld \n", m_bit_len, m_block_size);

	for(unsigned long tmp=0; tmp<mbuff.len; tmp+=sha1_block_size_byte)
	{
		//每个块512位，16个字，w0 w1 ... w15
		memset(buf_W, 0, 80);
		memcpy(buf_W, mbuff.data+tmp, sha1_block_size_byte);
		
		if(checkEndian() == -1){
			printf("\n swap \n");
			for(int ccnt=0; ccnt<16; ccnt++)
				buf_W[ccnt] = swap32endian(buf_W[ccnt]);
		}else{
			printf("\n big endian \n");
		}

//		printf("%#x\n", *(unsigned char*)buf_W);
//		printf("%#x\n", *((unsigned char*)buf_W+1));
//		printf("%#x\n", buf_W[0]);

		//每个块512位，16个字，w0 w1 ... w15，将每个块扩展到80个字
		for(unsigned long cnt=16;cnt<80;cnt++)
		{
			buf_W[cnt] = buf_W[cnt-3]^buf_W[cnt-8]^buf_W[cnt-14]^buf_W[cnt-16]; 
			buf_W[cnt] = S(1, buf_W[cnt]);
		}

		//初始化ABCDE 
		param_A = buf_H[0];
		param_B = buf_H[1];
		param_C = buf_H[2];
		param_D = buf_H[3];
		param_E = buf_H[4];

		//循环计算F，K
		for(unsigned long cnt=0;cnt<80;cnt++){
			sha1_word temp;
			if(cnt>=0 && cnt<=19){
				F = (param_B & param_C) | ((~param_B) & param_D);
				K = 0x5A827999;
			}else if(cnt >= 20 && cnt <= 39){
				F = param_B ^ param_C ^ param_D;
				K = 0x6ED9EBA1;
			}else if(cnt >= 40 && cnt <= 59){
				F = (param_B & param_C) | (param_B & param_D) | (param_C & param_D);
				K = 0x8F1BBCDC;
			}else if(cnt>=60 && cnt<=79){
				F = param_B ^ param_C ^ param_D;
				K = 0xCA62C1D6;
			}

			temp = S(5, param_A) + F + param_E + K + buf_W[cnt];
			param_E = param_D;
			param_D = param_C;
			param_C = S(30, param_B);
			param_B = param_A;
			param_A = temp;
		}

		buf_H[0] += param_A;
		buf_H[1] += param_B;
		buf_H[2] += param_C;
		buf_H[3] += param_D;
		buf_H[4] += param_E;
	}

	printf("\nsha1 hash is: %x %x %x %x %x\n", buf_H[0], buf_H[1], buf_H[2], buf_H[3], buf_H[4]);

	//printf_buffer(&mbuff);
//	printf("\nS(1, 0x80000000)=%#x\n", S(1, 0x80000000));
}
