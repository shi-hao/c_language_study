/*******泛型指针测试*********/
#include<stdio.h>

int main()
{
	int *intP;
	char *charP;
	void *p;
	int val = 0x04030201;
	int val2= 0x01020304;

#if 0
	void name;/*不允许使用void定义变量，因为编译时编译器无法给其分配内存，因为void型表示空*/ 
#endif

	intP = &val;
	p = &val2;/*void类型指针的赋值*/

	charP = (char *)intP;/*强制数据类型转换，避免警告*/
	printf("*charP=%x\n",*charP);/*大小端问题测试*/

	/*错误的void指针引用*/ 
#if 0
	*p; 
	printf("*p=%x\n",*p);
#endif

	charP = p;/*void型数据会被自动转换为对应数据类型*/ 
	printf("*charP=%x\n",*charP);/*大小端问题测试*/
	return 0;
}
