/*
 * ansi c基本数据类型
 * char short int long float double
 * 占用字节数不同，表示数据的范围不同
 *
 */
#include<stdio.h>

/*
 *main()
 */
void main()
{
	//
	char charvar;
	short shortvar;
	int intvar;
	long longvar;
	float floatvar;
	double doublevar;

	//字符常量可以给char,short,int,long赋值
	charvar = 'a';
	shortvar = 'b';
	intvar = 'c';

	printf("charvar = %d\n", charvar);
	printf("shortvar = %d\n", shortvar);
	printf("floatvar = %f\n", floatvar);

	/*基本数据类型占用字节数*/
	printf("sizeof(char)=%ld\n", sizeof(char));
	printf("sizeof(short)=%ld\n", sizeof(short));
	printf("sizeof(int)=%ld\n", sizeof(int));
	printf("sizeof(long)=%ld\n", sizeof(long));
	printf("sizeof(float)=%ld\n", sizeof(float));
	printf("sizeof(double)=%ld\n", sizeof(double));
}
