/*
 *
 * 泛型指针测试
 * void *指针称为泛型号指针，特点，可以接收任何类型的地址，
 * 在给其他指针赋值时，类型自动转换为对应类型。
 *
 */
#include<stdio.h>

int main()
{
	//void pointer
	void  *p;

	//int* char*
	short *shortP;
	char  *charP;

	//val
	int val = 0x04030201;

	printf("\nsizeof(p)=%ld\n", sizeof(p));
	
	p = &val;//void * = int *
	printf("val = %#x\n", val);

	shortP = p; //void* 自动转化为short *类型，不需要类型转换
	printf("*shortP = %#.4x\n", *shortP);

	charP = p;//void *自动转换为char *类型，不需要类型转换 
	printf("*charP = %#.2x\n", *charP);

	return 0;
}
