/*
 ************************************************
 * 在一些平台下，使用函数atoi()将字符串转化为数据时，如果字符串中有非数字的字符，
 * 会导致segmentation fault的错误。
 ************************************************** 
 */
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>

int main(int argc, char* argv[]){

	char strInt[]="123456";
	char strStr[]="#@@12fds56";
	int  var;

	if(argc < 2){
		printf("\n please input a string: transfer ascii string to number \n");
		return 1;
	}

	var = atoi(strInt);
	var = atoi(strStr);

	var = atoi(argv[1]);
	printf("var = %d\n", var);

	return 0;
}
