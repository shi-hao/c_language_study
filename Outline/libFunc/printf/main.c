/*printf简单测试*/

#include<stdio.h>

void main()
{
	int var_int=-1;
	unsigned int var_unint=1;

	signed char var_char=-1;
	unsigned char var_unchar=1;


	short var_short=-1;
	unsigned short var_unshort=1;

	long int var_long=-1;
	unsigned long int var_unlong=1;

	//float double没有无符号这种类型
	float var_float=-1.1;
	double var_double=-1.1;


	/*  十进制输出 %d */
	//%d  char  short short
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

	/*  八进制输出 %x */
	//%o
	printf("var_int=%#o\n",var_int);

	/* 字符输出 %c %s */
	//%c  %s  char
	printf("var_char=%c\n",var_char=65);
	//%s char*
	printf("string is = %s\n","i am string");


	//计算顺序
	printf("var_unint=%u, var_unint++=%u\n",var_unint,var_unint++);
}
