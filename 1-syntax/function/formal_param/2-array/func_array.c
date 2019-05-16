/*
 * 数组作为函数形式参数！
 * 数组作为形式参数，不需要指明数组的大小，数组的大小要通过其他变量传入。
 */

#include<stdio.h>
#include<stdlib.h>

//array used as function formal parameter
void function(char array[], int size){

	for(int cnt=0;cnt<size;cnt++){
		printf("array[%d]=%c\n", cnt, array[cnt]);
		array[cnt] = 'L';
	}
}

int main(){
#define  size  5
	char test[size]={'a','b','c','c','d'};

	for(int cnt=0;cnt<size;cnt++){
		printf("test[%d]=%c\n", cnt, test[cnt]);
	}

	function(test, size);

	for(int cnt=0;cnt<size;cnt++){
		printf("test[%d]=%c\n", cnt, test[cnt]);
	}
}
