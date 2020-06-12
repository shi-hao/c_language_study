/*
 * 6种基本数据类型，6种对应的指针类型
 * char   short   int   long   float    double
 * char*  short*  int*  long*  float*   double*
 * 在使用上，6种指针用法基本一样，char*指针可以用字符串常量赋值，其他的不可以。
 *
 */
#include<stdio.h>

/*
 * 程序返回字符串，字符串是否被释放?
 *
 * 当使用字符串常量时，如果没有给常量分配存储空间，
 * 那么字符串常量存储在全局数据区，比如，如下。
 * char* name = "i am bob";//name只是个指针变量，并未给字符串分配存储空间
 * char namearry[] = "i am bob";//namearry是数组，本身为字符串分配了存储空间
 * 在程序中直接使用字符串，其实也没有给字符串分配存储空间。
 */

char* test()
{
	return("i am tommy");
}

char* test1()
{
	char* name = "tommy";
	return name;//字符串存储在全局数据区，没有语法问题
}

char* test2()
{
	char namearry[] = {"tommymy"};
	return namearry;//返回函数内部变量地址，segmentation fault
}


/*
 *main()
 */
void main()
{
	//定义
	char*   p_char;
	short*  p_short;
	int*    p_int;
	long*   p_long;
	float*  p_float;
	double* p_double;

	char var_char = 0x60;
	short var_short = 0x1010;

	//& 取地址
	p_char = &var_char;
	p_short = &var_short;

	printf("sizeof(p_char)=%ld\n", sizeof(p_char));

	//* 取内容
	printf("* p_char  = %#x\n", *p_char);
	printf("* p_short = %#x\n", *p_short);

	//char*可以引用字符串常量，这是和其他类型最大的区别
	p_char="i am good char *";
	printf("%s\n", p_char);

#if 0
	//short*会报警告，不建议如此使用
	p_short="i am good short *";
	printf("%s\n", p_short);
#endif

#if 0
	/*
	 当使用char*去存储字符串时，是不允许对字符串进行内容修改的，使用数组
	 存储字符串可以，因为使用char*时，字符串实际上在程序的全局只读数据段内
	 存储，char*只是对其引用
	 */
	*(p_char+1)='a';//是否允许改变内容？--->segmentation fault 段错误
#endif

	p_char = test();//函数返回字符串 
	printf("%s\n", p_char);

	p_char = test1();//函数返回字符串 
	printf("%s\n", p_char);

	p_char = test2();//函数返回字符串 
	printf("%s\n", p_char);

	p_char = "good" "well" "better";  //字符串的合并 
	printf("%s\n", p_char);
}
