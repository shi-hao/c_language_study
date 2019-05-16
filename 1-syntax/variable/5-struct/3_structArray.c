/*
 *
 * 结构体数组，数组每个元素都是一个结构体变量!!
 */

#include<stdio.h>
#include<stdlib.h>

int main(){
	typedef struct st{
		int a;
		float b;
	}ST;

	ST stArray[10];

	stArray[0].a = 10;
	stArray[0].b = 1.1;

	printf("atArray[0].a = %d\n", stArray[0].a);
	printf("atArray[0].b = %f\n", stArray[0].b);

}
