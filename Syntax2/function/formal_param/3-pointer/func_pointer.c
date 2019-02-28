/*
 * 指针作为函数形式参数！
 * 指针作为形式参数。
 * 1.可以传递单个变量地址，也可以传递一段连续内存地址，比如数组首地址，堆内存首地址，内存的长度
 * 要通过其他的变量传入。
 *
 * 2.指针作为形式参数最大的特点是，可以改变传入形参的值。
 */

#include<stdio.h>
#include<stdlib.h>

//
void func(int* p){
	*p = 20;
	printf("*p = %d\n", *p);
}

//pointer used as function formal parameter
void function(char* buff, int size){

	for(int cnt=0;cnt<size;cnt++){
		printf("*(buff+%d) = %#.2x\n", cnt, *(buff+cnt));
	}
}


int main(){
#define  size  10
	char test[5]={'a','b','c','c','d'};
	int a = 100;
	char* p;
	p = (char*)malloc(sizeof(char)*10);

	func(&a);
	function(test,  5);

	function(p, size);
}
