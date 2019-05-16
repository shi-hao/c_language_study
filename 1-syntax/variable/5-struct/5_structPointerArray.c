/*
 * 结构体指针数组
 */

#include<stdio.h>
#include<stdlib.h>

int main(){
	typedef struct st{
		int a;
		float b;
	}ST;

	ST * stArray[10];

	stArray[0] = (ST*)malloc(sizeof(ST));

	stArray[0]->a = 10;
	stArray[0]->b = 1.1;

	printf("stArray[0]->a = %d\n", stArray[0]->a);
	printf("stArray[0]->b = %f\n", stArray[0]->b);

}
