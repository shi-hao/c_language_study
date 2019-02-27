/*
 *字符数组测试
 */
#include<stdio.h>
#include<string.h>
void main()
{
	/*字符数组定义以及初始化*/
	char TestCharArray[3] = "abc";
	char TestCharArray2[4] = "abc";
	char TestCharArray3[]={'a','b','c'};

	/*赋值测试*/
#if 0 //将0修改为1，打开预处理，进行赋值的错误测试
	TestCharArray3 = "abc";//错误，不允许这样赋值
	TestCharArray3[] = "abc";//错误，不允许这样赋值
	TestCharArray3[3] = "abc";//这样倒是不会报错，但是有问题，首先数组越界访问了，然后实际上是将一个char*指针常量 赋值给了元素[3]
	TestCharArray3[]={'a','b','c'};//错误，不允许这样赋值
#else
	TestCharArray3[1]='a';//唯一合法的赋值方式,给元素[1]赋值。
#endif

	/*测试字符串数组的长度和占用字节数*/
	printf("----测试字符串\"abc\"的长度和占用内存字节数----\n");
	printf("strlen(\"abc\")=%ld\n",strlen("abc"));
	printf("sizeof(\"abc\")=%ld\n",sizeof("abc"));

	/*字符串处理函数根据‘\0’来判断字符串的结束*/
	printf("strlen(TestCharArray)=%ld\n",strlen(TestCharArray));
	printf("strlen(TestCharArray2)=%ld\n",strlen(TestCharArray2));

	/*printf函数也是根据'\0'来判断字符串的结束*/
	printf("%s",TestCharArray);
	printf("\n"); 
	printf("%s",TestCharArray2);
	printf("\n");

	/*引用*/
	printf("%c\n",TestCharArray2[0]);//引用第一个元素
	printf("%c\n",TestCharArray2[4]);//引用第五个元素,数组引用越界，编译器不会报错，要十分小心这点。
}

