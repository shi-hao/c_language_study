/*
 *volatile相关测试
 */ 
#include<stdio.h>
int func(void)
{
	return 6;
}
void main()
{

#ifndef VolatileSW 
	int intVar1=0;
#else
	volatile int intVar1=0;
#endif

	/*普通变量*/
	int intVar2=0;
	int intVar3=0;

	/*volatile变量*/
	//  volatile int intVarVol1;
#if 0
	/*非volatile变量赋值*/
	intVar1= intVar1+5;
	intVar1 = func();
#endif
	intVar3 = intVar1 + 2;
	/*使用普通变量的值*/ 
	intVar2 = intVar1 + 6;
	intVar1 = 6;
#if 0  
	/*volatile变量赋值*/
	intVarVol1=5;

	/*使用volatile变量的值*/ 
	intVar2 = intVarVol1 + 6;
#endif
}
