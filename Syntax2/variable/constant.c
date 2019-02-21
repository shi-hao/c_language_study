/*
 * c语言基本常量主要有以下几种：
 * 字符常量，使用单引号：'a' 'b'
 * 字符串常量，使用双引号："abc"
 * 正/负整数： 123  -123
 * 正/负小数： 12.23  -12.34
 *
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	//存储字符串常量有两种方式，字符指针和字符数组，char* char[]
	char* str = "i am char*";
	char str_array[]="i am char array";


	printf("%c \n", 'a');
	printf("%d \n", 'a');
	printf("%s \n", "abc");

	//字符串常量占用字节数比实际的字符串长度多一个字节，多结束符'\0'
	printf("strlen(%s)=%ld\n", "abc", strlen("abc"));
	printf("sizeof(%s)=%ld\n", "abc", sizeof("abc"));

	printf("%d \n", -123);
	printf("%f \n", -12.34);
}
