/*
 ******************************************
 *作者 ：bleach 3013/11/05
 *描述 ：const 测试，const常量实际上是一个不可改变值的变量
 *******************************************
 */
#include<stdio.h>
int* DataPro(char const *p, int val)//const有效的保护传入的指针内容被误处理！！！！！
{
	char *q = p;
	const int a=1;
	int b = 2;

	int *int_p;
	int_p = &a;
	*int_p=1;

#if 0 
	*p = 1;  //p指向的内容是不允许被修改的
#endif

#if 0
	*(p+1) = 2;//通过p偏移后的地址的内容同样不允许修改
#endif

	*q = 1; //允许这样的修改方式,不过编译时会报警告，数据类型不完全匹配，原则上不提倡这种做法，因为这样会引入误操作的可能。
#if 1 
	return &a;//const变量的存储位置
#else
	return &b;
#endif
}
void void_func()
{
	int c=6;
}
void main()
{
	/*const常量定义数组大小*/
	const int a=10;
	int array[a];
	char arrayChar[10];
	int *ptest;
	int b;

	//char PrintTest[3]="abc";

	/*const变量必须初始化*/
	const int ConstVar;

	/*const和typedef*/
	typedef char* newType;
	const newType Pchar;
	const char* Pchar2;

	/*const指针和指向const常量的指针*/
	const int *testP1;
	int const *testP2;
	int* const testP3;

	DataPro(arrayChar, 10);

	//Pchar++;  //只读的指针
	Pchar2++;

	testP1 =&b; //允许指向const变量的指针被赋予非const变量的地址
	// *testP1 = 4;  //不允许的操作
	// *(testP1+1) = 4;

	testP1++;
	testP2++;
	//testP3++; //只读的指针

	printf("const 测试\n");

	//printf(PrintTest);

	//printf("\n");

	printf("const 局部变量的值是：%d\n",*(ptest=DataPro(arrayChar, 10)));

	void_func();
	void_func();
	void_func();

	printf("const 局部变量的值是：%d\n",*ptest);

	printf("sizeof(12)=%d\n",sizeof(12));

	printf("sizeof(12.3)=%d\n",sizeof(12.3));
}
