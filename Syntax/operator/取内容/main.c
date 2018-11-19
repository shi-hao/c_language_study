/*****
 *取内容和取地址运算符深入分析
 **********/
#include<stdio.h>

void main()
{
	int i,j;

	/*所有的数据类型*/
	int int_var;
	char char_var;
	float float_var;
	double double_var;
	/*数组*/
	char array[10];

	/*扩展类型*/
	struct {

		int a;
	}struct_var;
	union {
		int a;
	}union_var;
	enum {
		yestoday,
		today,
		tomorrow
	}enum_var;


	int *p;


	/*&--取地址操作*/
	&int_var;//操作数可以是int,char,float,double
	&char_var;
	&float_var;
	&double_var;

	&p;//操作数可以是指针变量

	&array[0];//操作数可以是数组元素  

	&struct_var;//可以是扩展数据类型
	&enum_var;
	&union_var;


	/**--取内容操作*/
	*p;  /*只允许是指针变量或者常量*/
	*array;
	*(unsigned char *)0x10101010;
}
