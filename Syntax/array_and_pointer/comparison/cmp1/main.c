//比较数组和指针取内容时的区别，查看汇编代码
#include<stdio.h>

int func(int a, int b)
{
   return(a+b);
}

int  main(int argc, char* argv[])
{
#if 0
   int *p;
   int array[10];
   int a = 1;

   p=&a;
   
   a=*p;
   a=array[0];
#else
   int a=1;
   a=func(a,a);
#endif
}
