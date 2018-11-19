/*
 *优先级以及结合性测试
 *对于运算符的优先级和结合性不再做过多的测试，只要理解就可以，使用括号和避免使用过于长的语句是一个良好的习惯。
 *本文件测试计算次序的问题
 */
#include<stdio.h>
/*funA*/
int funA()
{
  printf("i am funA!\n");
  return 1;
}
/*funB*/
int funB()
{
  printf("i am funB!\n");
  return 1;
}
/*funC*/
int funC()
{
  printf("i am funC!\n");
  return 1;
}
void main()
{
  int sum;
  int i=5,j=5;
  sum = funA() + funB()*funC();  
  printf("i+++j=%d\n",i+++j);
  printf("j=%d\n",j);
}
