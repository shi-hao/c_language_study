/*
 *ansi c基本数据类型
 */
#include<stdio.h>

/*
 *main()
 */
void main()
{
	int result;
	char* p;

	/*基本数据类型占用字节数*/
	printf("sizeof(char)=%ld\n", sizeof(char));
	printf("sizeof(int)=%ld\n", sizeof(int));
	printf("sizeof(long)=%ld\n", sizeof(long));
	printf("sizeof(float)=%ld\n", sizeof(float));
	printf("sizeof(double)=%ld\n", sizeof(double));
	printf("sizeof(char *p)=%ld\n", sizeof(p));
}
