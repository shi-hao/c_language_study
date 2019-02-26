/*
 * char, short, int, long, float, double
 * 以上6种数据类型，作为形式参数，当函数被调用时，实参只是
 * 将自己的数值传递给了形式参数，实际参数的值并不会改变。
 *
 * 函数在被调用时，会在栈上分配内存空间，形参和函数内部的变量
 * 的存储区域都是在栈帧上面，每个函数被调用时，都有自己的栈帧空间
 * 互相之间是不同的内存区域。
 *
 */

#include<stdio.h>
#include<stdlib.h>

void function(long a, double b){
	a+=100;
	printf("a = %ld in %s \n", a, __func__);

	b+=1.1;
	printf("b = %f in %s \n", b, __func__);
}


int main(){
	long a=100;
	double b=1.1;

	function(a, b);


	printf("a = %ld in %s \n", a, __func__);
	printf("b = %f in %s \n", b, __func__);
}
