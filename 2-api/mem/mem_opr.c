/*
 *内存处理标准库函数测试
 */
#include<string.h>
#include<stdio.h>

void main()
{
	char str[80];
	char result;
	char* p;

	printf("sizeof(long)=%ld\n", sizeof(long));
	printf("sizeof(int)=%d\n", sizeof(int));

	/*------------------*/
	/*内存复制*/
	memcpy(str, "i am 1", 4);
	printf("str:%s\n",str);

	memmove(str, "i am 1", 6);
	printf("str:%s\n",str);

	memset(str,'x', 10);
	printf("str:%s\n",str);


	/*------------------*/
	/*内存比较*/
	result = memcmp("i am 1", "i am 2", 6);
	printf("result=%d\n",result);

	/*------------------*/
	/*内存查找*/
	result =  memchr("i am 1", 'm', 6);
	printf("result=%x\n", result);
}
