/*
 * sha256 算法
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//位(bit), 字节(byte), 字(32位)
#define   sha256_word               unsigned int 
#define   sha256_block_size_bit     512
#define   sha256_block_size_byte    64  
#define   sha256_block_size_word    8

//循环左移运算
#define  SL(n, x)  ((n>=0 && n<=32)?((x<<n) | (x>>(32-n))):(0))
#define  SR(n, x)  ((n>=0 && n<=32)?((x>>n) | (x<<(32-n))):(0))

#define swap32endian(a)	(((a&0x000000ff)<<24)|((a&0x0000ff00)<<8)|((a&0x00ff0000)>>8)|((a&0xff000000)>>24))

//数据缓存
typedef struct _buffer_{
	int capacity;
	int len;
	int offset;
	unsigned char *data;
}buffer,*buffer_p;

#define  sha256_bit         256
#define  sha256_byte        32
#define  sha256_mod_val     64
#define  sha256_mod_val2    56
#define  sha256_bit_add     0x80
#define  buffer_size        1024

//----------------------------------------------------------------------
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
#endif
}

//打印哈希值
int mprintHash(sha256_word* data, int word_len, char* name){

	printf("\n %d-bit %s value is \n",word_len*4*8, name);
	for(int i=0; i<word_len; i++)
		printf(" %#.8x ", data[i]);
	printf("\n");
}

//--------------------------------------------------------------------
//初始化buffer
int buffer_init(buffer_p buff){

	if(buff->data = (unsigned char*)malloc(buffer_size * sizeof(char))){
		buff->capacity = buffer_size;
		buff->len = 0;
		buff->offset = 0;
		memset(buff->data, 0, buff->capacity);
		return 1;
	}
	return -1;
}

//释放buffer 
int buffer_free(buffer_p buff){

	free(buff->data);
	return 1;
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
//------------------------------------------------------------------
//检测大小端
int checkEndian(){

	unsigned short var = 0x11ff;
	if(*((unsigned char*)&var) == 0xff)
		return -1;
	else 
		return 1;
}

int main(int argc, char* argv[]){

#define buf_W_size   64

	unsigned char  orginal_data[1024]="sfsffffffffffffffffffffffffssssssssssssssssf";
	unsigned long  data_len;
	unsigned char* data;
	unsigned long  m_bit_len, m_block_size;;

	buffer mbuff;

	sha256_word param_A, param_B, param_C, param_D, param_E, param_F, param_G, param_H;
	sha256_word S0,S1,CH;
	sha256_word buf_W[buf_W_size]={0};
	unsigned int const sha256_K[64]={
		0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5,
		0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
		0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
		0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
		0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 
		0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da, 
		0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 
		0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967, 
		0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 
		0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85, 
		0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 
		0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070, 
		0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 
		0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3, 
		0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 
		0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
	};
	sha256_word buf_H[sha256_block_size_word]={
		0x6a09e667,
		0xbb67ae85,
		0x3c6ef372,
		0xa54ff53a,
		0x510e527f,
		0x9b05688c,
		0x1f83d9ab,
		0x5be0cd19
	};

	if(argc < 2)
	{
		printf("\n please input param string \n");
		return 0;
	}
	data = argv[1];

	//unsigned char test = 0x80;
	//printf("\n test = %#.2x \n", test);

	printf("\n input string len = %ld \n", data_len = strlen(data));

	buffer_init(&mbuff);
	buffer_add_data(&mbuff, data, strlen(data));

	//将数据增补比特位，增加数据长度，最后数据的比特位长度能被512整除
	//计算消息摘要时，每次计算一个块，每个块比特位长度为512
	hash_add_bit(&mbuff);
	hash_add_data_len(&mbuff, data_len);

	//printf_buffer(&mbuff);

	m_bit_len = mbuff.len * 8;
	m_block_size = m_bit_len / sha256_block_size_bit;
	printf("\n message bit len = %ld, block size = %ld \n", m_bit_len, m_block_size);

	//printf("\nSL(1, 0x80000000)=%#x\n", SL(1, 0x80000000));
	//printf("\nSR(1, 0x80000000)=%#x\n", SR(1, 0x80000000));

	for(unsigned long tmp=0; tmp<mbuff.len; tmp+=sha256_block_size_byte)
	{
		//每个块512位，16个字，w0 w1 ... w15
		memset(buf_W, 0, buf_W_size);
		memcpy(buf_W, mbuff.data+tmp, sha256_block_size_byte);

		//大小端数据转换
		if(checkEndian() == -1){
			printf("\n swap data endian\n");
			for(int i=0; i<sha256_block_size_byte; i++)
				buf_W[i] = swap32endian(buf_W[i]);
		}else{
			printf("\n big endian \n");
		}

	//	printf("%#x\n", *(unsigned char*)buf_W);
	//	printf("%#x\n", *((unsigned char*)buf_W+1));
	//	printf("%#x\n", buf_W[0]);

		//每个块512位，16个字，w0 w1 ... w15，将每个块扩展到64个字
		for(unsigned long i=16; i<buf_W_size; i++)
		{
			S0 = SR(7,buf_W[i-15]) ^ SR(18,buf_W[i-15]) ^ (buf_W[i-15]>>3);
			S1 = SR(17,buf_W[i-2]) ^ SR(19,buf_W[i-2])  ^ (buf_W[i-2]>>10);
			buf_W[i] = buf_W[i-16] + S0 + buf_W[i-7] + S1;
		}

		//初始化ABCDE 
		param_A = buf_H[0];
		param_B = buf_H[1];
		param_C = buf_H[2];
		param_D = buf_H[3];
		param_E = buf_H[4];
		param_F = buf_H[5];
		param_G = buf_H[6];
		param_H = buf_H[7];

		for(unsigned long cnt=0; cnt<buf_W_size; cnt++){
			sha256_word temp1,temp2,maj;

			S1 = SR(6, param_E) ^ SR(11, param_E) ^ SR(25, param_E);
			CH = (param_E & param_F) ^ ((~param_E) &  param_G);
			temp1 = param_H + S1 + CH + sha256_K[cnt] + buf_W[cnt];
			S0 = SR(2, param_A) ^ SR(13, param_A) ^ SR(22, param_A);
			maj = (param_A  &  param_B) ^ (param_A  &  param_C) ^ (param_B  &  param_C);
			temp2 = S0 + maj;

			param_H = param_G;
			param_G = param_F;
			param_F = param_E;
			param_E = param_D + temp1;
			param_D = param_C;
			param_C = param_B;
			param_B = param_A;
			param_A = temp1 + temp2;
		}

		buf_H[0] += param_A;
		buf_H[1] += param_B;
		buf_H[2] += param_C;
		buf_H[3] += param_D;
		buf_H[4] += param_E;
		buf_H[5] += param_F;
		buf_H[6] += param_G;
		buf_H[7] += param_H;
	}

	buffer_free(&mbuff);
	mprintHash(buf_H, sha256_block_size_word, "sha256");
}
