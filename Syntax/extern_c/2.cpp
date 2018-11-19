#include<stdio.h>
#include<iostream>
/*使用extern C声明fun1是一个c源文件中定义的函数*/
#if 1
extern "C" 
{
	int fun1();
}
#else
extern int fun1();
#endif
/*声明一个在c源文件中定义的变量*/
#if 0
extern "C"
{
	int a;
}
#else
extern int a;
#endif
int b;


int main()
{
	fun1();
	printf("a=%d\n",a);
	return 0;
}
