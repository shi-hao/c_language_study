/*
 **********************************************************
 * Author      ： bleach 2013/10/25
 * Description : C语言编译过程测试文件
 **********************************************************
 */

#include<stdio.h>
#include"outline.h"

//条件编译测试
#ifdef outline
#define good  1
#else
#define bad  0
#endif 

void printOK();
//extern void printOK();

/*
 *************************************************************
 *                     main()
 *功能   :测试main函数
 *参数   :无
 *返回值  :无
 *************************************************************
 */
void main()
{
	printf("宏 outline =%d\n",outline);

#if outline
	printf("宏 good =%d\n",good);
#else
	printf("宏 bad =%d\n",bad);
#endif

	printOK();//测试链接做了什么，链接函数实现

	printf("test =%d\n", test);


}

/*
   void printOK()
   {
   printf("ok \n");
   }
 */
