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
	}
}

int main(){
	char test[5]={'a','b','c','c','d'};

	function(test, 5);
}
