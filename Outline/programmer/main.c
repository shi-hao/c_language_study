/*
**********************************************************
* Author      ： bleach 2014/01/08
* Description : 程序员易犯的错误
**********************************************************
*/
#include <stdio.h>

void main()
{
   /*有符号数据*/
   signed int    SignIntVar;
   signed short  SignShortVar;
   signed char   SignCharVar;

   /*无符号数据*/
   unsigned int    UnsignIntVar;
   unsigned short  UnsignShortVar;
   unsigned char   UnsignCharVar;

  /*-----多字节 赋值给 少字节测试-----*/
  /*1. 无符号赋值有符号*/
  UnsignIntVar = 0xffffffff；
  UnsignShortVar = 0x00ff； 
  printf("UnsignIntVar = %h\n",UnsignIntVar);
  printf("SignCharVar = UnsignIntVar, SignCharVar=%h\n",SignCharVar = UnsignIntVar);
  printf("UnsignShortVar = %h\n",UnsignShortVar);
  printf("SignCharVar = UnsignShortVar, SignCharVar=%h\n",SignCharVar = UnsignShortVar);
  printf("------------------------\n");


  /*2. 有符号赋值无符号*/
  SignIntVar = 0xffffffff； 
  printf("SignIntVar = %h\n",SignIntVar);
  printf("UnsignCharVar = SignIntVar, UnsignCharVar=%h\n",UnsignCharVar = SignIntVar);
  SignIntVar = 0x7fffffff； 
  printf("SignIntVar = %h\n",SignIntVar);
  printf("UnsignCharVar = SignIntVar, UnsignCharVar=%h\n",UnsignCharVar = SignIntVar);
  
  SignShortVar = 0xffff； 
  printf("SignIntVar = %h\n",SignShortVar);
  printf("UnsignCharVar = SignShortVar, UnsignCharVar=%h\n",UnsignCharVar = SignShortVar);
  SignShortVar = 0x7fff； 
  printf("SignIntVar = %h\n",SignIntVar);
  printf("UnsignCharVar = SignShortVar, UnsignCharVar=%h\n",UnsignCharVar = SignShortVar);
  printf("------------------------\n");

  /*3. 相同符号数据赋值*/
  

}
