/*
 ***********************************************
 *             
 *Author     : bleach 2014/01/16
 *Description: 函数指针数组测试
 *************************************************
 */
#include<stdio.h>

/*指针变量定义*/
void (*funp[3])();
void (*funp3)();
long funp2[2];

void (*funcP1)(int);
void (*funcP2)();

/*函数定义*/
void plus()
{
  printf("1+1=%d\n",1+1);
}
void minus()
{
  printf("2-1=%d\n",2-1);
}
void test()
{
  printf("test\n");
}

void NullFunc(int i)
{
  printf("i am null func\n");
}

void main()
{
  int tstval = 12;
  int * tstp = &tstval;
  
  /*变量初始化*/
  funp[0] = plus;
  funp[1] = minus;
 
  /*输出*/
  (*funp[0])();
  (*funp[1])();
  
  funp[0]();
  funp[1]();

  /*测试强制转换为函数指针类型*/
  funp2[0] = (int)minus;
  (*((void (*)(void))funp2[0]))();//将数据 强制转换为 函数指针类型
  ((void (*)(void))funp2[0])();//将数据 强制转换为 函数指针类型-->(void(*)(void))
#if 0  //以下两种转换方法是不行的
  (void (*)(void))(funp2[0])();//将数据 强制转换为 函数指针类型-->(void(*)(void))
  (void (*)(void))funp2[0]();//将数据 强制转换为 函数指针类型-->(void(*)(void))
#endif

  /*测试函数指针赋值的另一种情况*/
  funp[2] = *test;
  funp3 = *test;

  (*funp[2])();
  (*funp3)();
  
  funp[2]();
  funp3();

  printf("*tstp = %d\n",*tstp);
   //printf("**tstp = %d\n",**tstp);
	funcP1 = NullFunc;
	funcP1(tstval);
	funcP2 = NullFunc;
	funcP2(tstval);
}

