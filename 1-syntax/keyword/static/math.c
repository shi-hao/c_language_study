/*
 * static修饰变量或者函数，整体来说，static的作用是隐藏或者说限制使用范围。
 *
 * 修饰函数：限制函数只能在模块内（定义函数的源文件内）使用。
 *
 * 修饰变量
 *   全局变量：限制全局变量只能在模块内（定义变量的源文件内）使用。
 *	 局部变量：使局部变量能够类似全局变量一样保持之前的值，即函数每次被调用，局部变量保存上次
 *             调用的值。
 */

#include<stdio.h>

int glo_sum;
static int sta_glo_sum;

/*
 *数学减运算 
 */
static int minus(int a, int b)
{
	return(a-b);
}

/*
 *数学加运算 
 */
static int plus(int a, int b)
{
	return(a+b);
}

/*
 *数据处理，返回（a,b的和）与（a,b的差）的差
 */
int DataProc(int a, int b)
{
	static int sum = 0;
	sum += minus(plus(a,b),minus(a,b));

	glo_sum += minus(plus(a,b),minus(a,b));
	sta_glo_sum += minus(plus(a,b),minus(a,b));

	printf("sum = %d\n", sum);
	printf("glo_sum = %d\n", glo_sum);
	printf("sta_glo_sum = %d\n", sta_glo_sum);

	return(minus(plus(a,b),minus(a,b)));
}
