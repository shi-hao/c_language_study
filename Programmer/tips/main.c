/*
 *测试内容：
 *C语言不允许在变量定义语句之前出现任何的C语言的其他操作语句。
 *
 *现在很多编译器已经允许这种操作，变量的定义不要求必须出现在函数的开始。
 *
 */
#include<stdio.h>
void main()
{
	int a;

	/*测试1*/
#if 1
	printf("请输入a的值");
	scanf("%d\n",&a);
#endif

	int b;

	/*测试2*/
#if 0
	b=1;
#endif
	int c;

	printf("测试结束\n");
}
