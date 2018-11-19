/*typedef测试*/
#include<stdio.h>

typedef unsigned char * ucharP;
typedef ucharP  ucharP_new;  //嵌套定义

#define name   alias
#define alias  you   //嵌套定义,参数顺序和typedef相反  

#define good better best

void func()
{
  printf("i am func\n");
}

void main()
{
	typedef unsigned char uchar;  //允许在函数体内使用typedef

  #define ls list  //允许出现
  
	uchar i;

#ifdef GOOD
  good  //测试define替换的原则
#endif

	printf("i am printf\n");

}

