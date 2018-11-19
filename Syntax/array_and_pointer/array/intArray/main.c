/*
 *普通数据数组测试
 */
#include<stdio.h>
#include<string.h>
void main()
{
  /*数组大小常量*/  
  const int size = 5;
  int count;

  /*数组定义以及初始化*/
  int  TestArray[3] = {0,1,2};//初始化全部元素
  int  TestArrayNullSize[]={0,1,2};//省略数组的大小，必须初始化全部的元素来指定数组的大小
  int  TestArray2[4] = {1,2};//初始化部分元素
  int  TestArray3[5]={0};//特殊的情况
  int  TestArray4[5]={1};//特殊的情况
  int  TestArray6[5];//不初始化任何的元素
#if 0
  int  TestArray5[size]={0,1,2,3,4};//使用常量定义的数组不能在定义时进行初始化的操作
#else
  int  TestArray5[size];
#endif

  /*测试*/
  printf("TestArray2[2]=%d\n",TestArray2[2]);//初始化部分元素，输出编译器数组的默认值
  printf("TestArray3[1]=%d\n",TestArray3[1]);//特殊情况的测试
  printf("TestArray4[1]=%d\n",TestArray4[1]);//特殊情况的测试
  printf("TestArray5[1]=%d\n",TestArray5[1]);//const变量定义数组的大小
  printf("TestArray6[1]=%d\n",TestArray6[1]);//不初始化任何元素的测试
#if 1
  TestArray5[2]=2;
#endif

  printf("count=%d\n",count);
  
   /*赋值测试*/
   for(count=0;count<3;count++)
   {
     TestArray[count]=count;
     printf("TestArray[%d]=%d\n",count,TestArray[count]);
   }
   for(count=2;count>=0;count--)
   {
     TestArray[count]=count;
     printf("TestArray[%d]=%d\n",count,TestArray[count]);
   }
  
  /*引用*/
  printf("TestArray[3]=%d\n",TestArray[3]);//数组的越界访问，编译器不会报错
}
