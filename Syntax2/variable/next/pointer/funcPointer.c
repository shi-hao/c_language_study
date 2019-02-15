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
void (*funcP)(int);//--定义

//返回值为指针的函数
void* function(int);

/*函数定义*/
void plus(int a)
{
	printf("a+a=%d\n",a+a);
}

void minus(int a)
{
	printf("a-1=%d\n",a-1);
}

void test(int a)
{
	printf("test\n");
}

void error(int a){
	printf("error\n");
}

void main(int argc, char* argv[])
{
	int param;
	if(argc >= 2)
	{
		param = atoi(argv[1]);
	}

	switch(param){
		case 1:
			funcP = plus;//赋值
			break;
		case 2:
			funcP = minus;
			break;
		case 3:
			funcP = test;
			break;
		default:
			funcP = error;
			break;
	}

	funcP(2);//引用
}
