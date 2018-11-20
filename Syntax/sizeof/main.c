/*
 *sizeof测试
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 100

void main()
{
	int a=0;
	int *p;
	int array[10];

	/*测试*/
	printf("sizeof(int)=%ld\n",sizeof(int));
#if 0
	printf("sizeof int=%d\n",sizeof int);
#endif
	printf("sizeof a=%ld\n",sizeof a);
	printf("sizeof 5=%ld\n",sizeof 5);
#if 0
	printf("sizeof5=%d\n",sizeof5);
#endif
	printf("sizeof array=%ld\n",sizeof array);

	a = strcmp("hello\0","hello");
	printf("a=%d\n",a);

    //(char)*p;

	//sizeof strlen 区别
	printf("\nsizeof(\"string\")=%ld\n",sizeof("string"));
	printf("\nstrlen(\"string\")=%ld\n",strlen("string"));
}
