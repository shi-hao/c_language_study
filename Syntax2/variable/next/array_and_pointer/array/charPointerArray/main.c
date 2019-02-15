/*
 *字符指针数组，字符串指针数组
 *字符指针数组有一个很特殊的应用，那就是存储字符串。
 */
#include<stdio.h>
void main()
{
	//字符指针变量基本用法
	char *str1;
	char *strArray[10];
	char var = 10;

	str1 = &var;
	strArray[0] = &var;

	printf("\nstr1 = %d\n", *str1);
	printf("\nstrArray[0] = %d\n", *strArray[0]);

	//字符串
	str1 = "i am str1";
	strArray[0] = "i am strArray";

	printf("\nstr1 = %s\n", str1);
	printf("\nstrArray[0] = %s\n", strArray[0]);

	/*定义以及初始化*/
	char* array[2]={
		"i am a string!",
		"string!"
	};

	/*赋值以及引用*/ 
	printf("%s\n",array[0]);
	array[0]="good";
	printf("%s\n",array[0]);
}
