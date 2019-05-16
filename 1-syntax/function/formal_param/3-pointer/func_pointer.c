/*
 * 指针作为函数形式参数！
 * 指针作为形式参数。
 * 1.可以传递单个变量地址，也可以传递一段连续内存地址，比如数组首地址，堆内存首地址，内存的长度
 * 要通过其他的变量传入。
 *
 * 2.指针作为形式参数最大的特点是，可以改变传入的实参的值。
 *
 * 形参如果是指针，只需要在栈帧上分配8字节的内存，然后存储一个地址。
 * 如果不是指针，那么要在栈帧上根据变量的类型，分配对应的内存。
 */

#include<stdio.h>
#include<stdlib.h>

//
void func(int* p){
	*p = 20;
}

//pointer used as function formal parameter
void function(char* buff, int size){

	for(int cnt=0;cnt<size;cnt++){
		*(buff+cnt) = cnt;
	}
}


int main(){
#define  size  10
	int a = 100;
	printf("a = %d\n", a);
	func(&a);
	printf("a = %d\n", a);

	char test[size] = {"abcbcbcbg"};
	for(int cnt=0;cnt<size;cnt++){
		printf("test[%d] = %#.2x\n", cnt, test[cnt]);
	}
	function(test,  size);
	for(int cnt=0;cnt<size;cnt++){
		printf("test[%d] = %#.2x\n", cnt, test[cnt]);
	}

	char* p;
	p = (char*)malloc(sizeof(char)*size);
	function(p, size);
	for(int cnt=0;cnt<size;cnt++){
		printf("*(p+cnt) = %#.2x\n", *(p+cnt));
	}
}
