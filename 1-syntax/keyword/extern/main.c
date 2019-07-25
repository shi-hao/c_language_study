/*
 ****************************
 *         extern 作用
 *作者:时浩
 *说明：测试extern的作用
 ****************************
 */
#include<stdio.h>

/*声明测试，看在哪个环节报错*/

/*声明函数*/
//extern int fun(int a); 
//extern int fun(int ); 
//int fun(int );

/*声明变量*/
#if 0
extern int a=1;
#else
extern int a;    
#endif

int  main()
{
  int b;
  b = a;
  fun(1);
  printf("success!\n");
  return 0;
}
