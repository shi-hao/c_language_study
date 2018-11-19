/*
 *逗号运算符和条件运算符测试
 */
#include<stdio.h>
#define print(x)  printf("%d\n",x)

void main()
{
  int a=1,b=0;
  /*逗号运算符*/
  a+3,a+4;
  print(a),print(b);//表达式中可以出现函数调用

  /*条件运算符*/  
  a?print(a):print(0);//表达式中可以出现函数调用
}
