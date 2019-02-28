/*
 * 指针数组作为函数形式参数！
 * 此处仅仅测试:基本数据类型一级指针的一维数组
 * char*[]  short*[] int*[] long*[] float*[] double*[]
 *
 * 典型应用，main函数的第二个参数就是char*[]，char*[] 等价于 char**
 * 
 */

#include<stdio.h>
#include<stdlib.h>


//pointer array used as function formal parameter
void function(char* buff[], int size){

	for(int cnt=0;cnt<size;cnt++){
		printf("buff[%d] = %s\n", cnt, buff[cnt]);
	}
}

//pointer array used as function formal parameter
void function2(char** buff, int size){

	for(int cnt=0;cnt<size;cnt++){
		printf("buff[%d] = %s\n", cnt, buff[cnt]);
	}
}

int main(int argc, char* argv[]){
#define size 2

	char* array[size] = {
		"today is a gift",
		"bye bye!"
	};

	for(int cnt=0; cnt<argc; cnt++)
		printf("%s \n", argv[cnt]);

	function(array, size);
	function2(array, size);
}
