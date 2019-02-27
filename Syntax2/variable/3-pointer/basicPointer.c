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
 */
char* test()
{
	return("i am good");
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
	*p_char='a';//是否允许改变内容？--->segmentation fault 段错误
#endif

	p_char = test();//函数返回字符串 
	printf("%s\n", p_char);

	p_char = "good" "well" "better";  //字符串的合并 
	printf("%s\n", p_char);
}
