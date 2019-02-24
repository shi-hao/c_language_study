/*
 * function pointer
 *
 * 函数指针vs返回值为指针的函数:
 *  返回值类型  函数名( 形参表 )
 *  返回值类型  (*函数指针名)( 形参表 )
 *
 */
#include<stdio.h>
#include<stdlib.h>

//函数指针
void (*fp)(int);

//返回值为指针的函数
void* fc(int);

void plus(int a)
{
	printf("a+a=%d\n",a+a);
}

void minus(int a)
{
	printf("a-1=%d\n",a-1);
}

void main()
{
	fp = plus;//赋值
	fp(2);//引用
}