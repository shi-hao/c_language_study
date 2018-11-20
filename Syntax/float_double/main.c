/* 浮点数运算测试
 * 
 * float  有效位数 6-7
 * double 有效位数 15-16 
 *
 */
#include<stdio.h>

void main()
{
	double a,b;
	int cnt;
	b = 340.4+210.0006;
	a = 0.05+0.01;
	printf("0.05+0.01=%0.20f\n",0.05+0.01);

	printf("a = %4.20f\n", a);
	printf("b = %4.20f\n", b);


	printf("a = %4.15f\n", a);
}
