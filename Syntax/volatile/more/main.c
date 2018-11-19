#include<stdio.h>

//多线程操作变量
volatile int share_var=1;

#ifndef  out_run 	
//设备寄存器映射
volatile int *reg = (int *)0x00000001;
#endif

//#define reg2 (int *)0x00000001 


void main()
{	
	//
	volatile int i=0;

#ifndef  out_run
	while((*reg) == 1);
#endif

	while(share_var == 1);
	while(i == 1);

	i = 1;
	i = 2;
	i = 3;

	share_var = 0;
	share_var = 1;
}
