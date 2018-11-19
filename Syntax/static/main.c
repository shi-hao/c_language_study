/*
 *printf("a+b=%d\n", plus(a,b));
 *printf("%d\n",static_global_i);
 *这两条语句在编译汇编生成目标文件时，都不会报错，但是链接时就会出现问题。
 *提示函数和变量没有定义。
 */
#include<stdio.h>
extern int global_i; 
extern int static_global_i;

int global_j=2; //全局变量名重复的问题测试

int NoInitGolVar;
static int StaticNoInitGolVar;

void main()
{
	int a=1,b=2;
	int NoInitVar;
	static int StaticNoInitVar;

	//printf("a+b=%d\n", plus(a,b));//静态函数调用测试
	printf("非静态函数-->DataProcess(a,b)=%d\n",DataProcess(a,b));//非静态函数调用

	printf("静态局部变量第一次调用值为%d\n",staticVariable());
	printf("静态局部变量第二次调用值为%d\n",staticVariable());//静态局部变量

	printf("非静态全局变量-->global_i=%d\n",global_i);//非静态全局变量
	//printf("%d\n",static_global_i);//静态全局变量

	printf("非静态全局变量-->global_j=%d\n",global_j);//非静态全局变量

	/*未初始化全局变量，未初始化全局静态变量*/
	printf("NoInitGolVar=%d\n",NoInitGolVar);
	printf("StaticNoInitGolVar=%d\n",StaticNoInitGolVar);

	/*未初始化局部变量和未初始化静态局部变量*/
	printf("NoInitVar=%d\n",NoInitVar);
	printf("StaticNoInitVar=%d\n",StaticNoInitVar);
}
