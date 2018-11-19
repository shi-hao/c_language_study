/*
 *大括号的一个独特用法测试
 *指定变量的作用域
 */
#include<stdio.h>
int main()
{
	int a=5;
	int b=6;
	printf("a=%d\n",a);

	/*单独使用的一对大括号*/
	{
		int a=10;/*大括号内变量可以和大括号外的变量重名,大括号内部的变量起作用*/
		int c=7;
		printf("a=%d\n",a);
		printf("b=%d\n",b);/*大括号内的语句可以使用大括号外部的变量*/
	}
#if 0
	printf("c=%d\n",c);/*大括号外的语句不可以使用大括号内部的变量*/
#endif

	/*
	 *if语句结合的大括号内同样可以定义变量
	 */
	if(1)
	{
		unsigned char ch;
		printf("brace in if...else...\n");
	}
	else{
		unsigned char ch;
		printf("same var name--1\n");
	}

	/*
	 *switch语句结合的大括号内定义变量
	 */ 
	switch(1)
	{
		unsigned char ch;
		case 1: 
		{
			unsigned char ch;
			printf("same var name--2\n");
		}
		printf("same var name--3\n");
	}

	return 0;
}
