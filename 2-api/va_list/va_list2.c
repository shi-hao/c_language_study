#include<stdio.h>
#include<stdarg.h>
#include<stdlib.h>

/*
 * va_list 变量
 * va_start 将va_list变量初始化，另一个参数为函数的第一个参数
 *
 *  可变参数函数，即函数的参数个数和类型不固定，可变参数的第一个参数一般是固定的，用来
 *  解析其后的参数的个数或者类型。
 */

//可变参数函数，第一个参数表示后续参数的个数，后续参数也是int型。
void func(int a,...){

	va_list va;
	int tmp;
	int cnt=1;

	va_start(va, a);
	while(a--){
		tmp = va_arg(va, int);
		printf("\nparm %d = %d", cnt++, tmp);
	}
	va_end(va);
}

int main(int argc, char* argv[]){

	int tmp;
	if(argc < 2)
	{
		printf("\nplease input tmp value\n");
		return 1;
	}

	tmp = atoi(argv[1]);

	func( tmp ,1,2);
}
