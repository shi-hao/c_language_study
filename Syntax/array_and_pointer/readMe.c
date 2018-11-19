
/*
 *基本变量类型，数组，指针，动态内存分配
 *
 *C语言主要有以下变量类型：
 * char	   short	  int    long    float     double    结构体      共用体
 * char*   short*     int*   long*   float*    double*   struct s*   enum e*
 * char[]  short[]    int[]  long[]  float[]   double[]  struct[]    enum[]
 * char*[] short*[]   int*[] long*[] float*[]  double*[] struct*[]   enum*[]
 *
 * char型数据有一个最特别的特性
 * 数组和动态内存分配作用其实很类似，只不过动态内存分配的内存大小可以在程序中灵活定义，
 * 但是数组大小只能在程序中固定。
 */

#include<stdio.h>
#include<stdlib.h>

int main(){


	//char 数据最特别的特性：可以使用字符串赋值
	//char* 变量可以使用字符串初始化，也可以使用字符串赋值
	//char[] 数组只可以使用字符串初始化
	char var;
	char *p;
	char array[40]="i am a array";
	p = &var;
	p = "i am a string";

	printf("\narray is %s\n", array);
	printf("\np is %s\n", p);


	//数组和动态内存分配
	int var2=40;
	int* pp;
	int array2[40];//此数组相当于分配了 sizeof(int) * 40字节的内存单元，存储40个int数据 
	pp = (int *)malloc(sizeof(int) * 40);//和array2作用其实是一样的

	pp[0]=var2;//pp[0]  等价于 *(pp+0)
	array2[0]=var2;

}
