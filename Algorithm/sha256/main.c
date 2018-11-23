#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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

//256-bit 哈希初值
unsigned int const hash_value_init[8] = {
	0x6a09e667,
	0xbb67ae85,
	0x3c6ef372,
	0xa54ff53a,
	0x510e527f,
	0x9b05688c,
	0x1f83d9ab,
	0x5be0cd19
};

unsigned int const hash_value_const[64]={
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

	unsigned char orginal_data[1024]="sfsfffffffffffffffffffffffsssssssssssssssssssssssssssssssfffffffffffffsfsffsffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffsssssssssssssssssssssssssssffffffffffffffffffffffsssssssssssssssssssssssssssssssssssssssssssssssssssssssf";
	unsigned long data_len;
	unsigned char* data;

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
	buffer mbuff;
	buffer_init(&mbuff);

	buffer_add_data(&mbuff, data, strlen(data));

	hash_add_bit(&mbuff);
	hash_add_data_len(&mbuff, data_len);

	printf_buffer(&mbuff);
}
