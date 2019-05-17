/*
 *       		printf简单测试
 *
 * %4.2
 * 对于浮点数--double/float
 *  2表示小数点后保留2位，
 *  4表示位宽，整数位加上小数点位总共4位，但是如果位数超了，还是按照超出的位数来显示。
 * 对于整数--char/short/int/long
 *  2表示整数的位数，不足加前导0，超了，则按实际显示。
 *
 * %#x 
 * 16进制加前导0x
 *
 * %#.4x
 * 16进制输出，输出4位，不足加前导0
 *
 * %c  char  
 * %s  char*
 *
 * %d  char short  int
 * %ld long 
 *
 * %f  float double
 */

#include<stdio.h>
#include<stdlib.h>

void main( int argc, char *agrv[])
{
	int var_int=-1;

	char var_char=-1;

	short var_short=-1;

	long var_long=-1;

	//float double没有无符号这种类型
	float var_float=-1.1;
	double var_double=-1.1;
	double var = 400.56;


	/*  十进制输出 %d */
	//%d  char   short
	printf("var_int=%d\n",var_int);
	printf("var_short=%d\n",var_short);
	printf("var_char=%d\n",var_char);

	//%ld  long int
	printf("var_long=%ld\n",var_long);

	//%f  float double
	printf("var_float=%f\n",var_float);
	printf("var_double=%f\n",var_double);

	/*  十六进制输出 %x */
	//%x  char short int 
	printf("var_int=%#x\n",var_int);
	printf("var_short=%#x\n",var_short);
	printf("400=%#04x\n",400);

	/*  八进制输出 %x */
	//%o
	printf("var_int=%#o\n",var_int);

	/* 字符输出 %c %s */
	//%c  %s  char
	printf("var_char=%c\n",var_char=65);
	//%s char*
	printf("string is = %s\n","i am string");

	//计算顺序
	printf("var_int=%u, var_int++=%u\n",var_int,var_int++);

	printf("var = %4.6f", var);

	if(argc >= 2)
	{
		int tmp;
		tmp = atof(agrv[1]);
		printf("\nagrv[1]=%#.8x\n", tmp);
	}
}
