#include<stdio.h>
#include<stdlib.h>

/* 
 * 大小端的含义
 * 计算机存储数据是按照字节来存储的，不管数据有几个字节，都是按照字节存储。
 * 一个多字节的数据，比如int var = 0x11ff，4字节，如何存储呢？
 * 思路1： 先存储数据的高位(数学意义上的高位)，从高位按顺序存储，0x11, 0xff 
 * 思路2： 先存储数据的低位，按顺序存储，正好和思路1相反，0xff, 0x11 
 * 
 *	思路1被称为大端序，后者被称为小端序
 */


//检测大小端，返回0,表示小端，返回1,则是大端
int checkEndian(){
	
	unsigned short var = 0x11ff;
	if(*((unsigned char*)&var) == 0xff)
		return 0;
	else 
		return 1;
}

int main(){

	int var=0x0a0b0c0d;
	char varr;
	checkEndian()?printf("\n big-endian \n"):printf("\n little-endian \n");

	//大小端不影响数据的移位运算
	printf("\n varr = var>>24 %#.2x \n", varr=var>>24);
	printf("\n varr = var>>16 %#.2x \n", varr=var>>16);
	printf("\n varr = var>>8 %#.2x \n", varr=var>>8);
	printf("\n varr = var %#.2x \n", varr=var);
}
