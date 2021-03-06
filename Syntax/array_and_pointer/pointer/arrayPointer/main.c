/*
 * 数组和指针相关测试：
 *@一维数组和指针
 *@二维数组和指针
 *关于指针变量的基本知识本文件不做相关测试，本文件主要测试指向数组的指针变量如何赋值，如何通过指针引用数组元素。
 *核心内容：
 *@一维数组指针的赋值，引用数组元素
 *@二维数组指针的赋值，引用数组元素
 */
#include<stdio.h>

void main()
{
	/*指针和数组定义*/
	int *p,*q;//,普通指针
	int (*row_p)[3];//行指针
	int array[3]={0};
	int array2[2][3]={0};

	/*测试开始*/

	/*一维数组指针的赋值和通过指针引用元素*/
	p=array;//赋值方法1

	printf("*(p+1)=%d\n",*(p+1));/*三种引用元素array[1]的方法*/
	printf("p[1]=%d\n",p[1]);
	printf("*(array+1)=%d\n",*(array+1));

	p=&array[0];//赋值方法2

	printf("*(p+1)=%d\n",*(p+1));/*三种引用元素array[1]的方法*/
	printf("p[1]=%d\n",p[1]);
	printf("*(array+1)=%d\n",*(array+1));

	/*二维数组指针的赋值和通过指针引用元素*/
	/*普通指针*/            /*---不推荐这种方法来访问二维数组---*/
	q=array2[0];//赋值方法1

	printf("(*(q+3*1+1))=%d\n",*(q+3*1+1));//两种应用方式，实际上也就是一种方式，而且要看是按行还是按列来存储的数组
	printf("(*(array2[0]+3*1+1))=%d\n",*(array2[0]+3*1+1));

	q=&array2[0][0];//赋值方法2

	printf("(*(q+3*1+1))=%d\n",*(q+3*1+1));//两种应用方式，实际上也就是一种方式，而且要看是按行还是按列来存储的数组

	/*行指针*/  /*提倡使用行指针来访问二维数组*/
	row_p=array2;//赋值方法1 

	printf("(*(*(row_p+1)+1))=%d\n",*(*(row_p+1)+1));/*三种访问数组元素的方法*/
	printf("(*(row_p[1]+1))=%d\n",*(row_p[1]+1));
	printf("row_p[1][1]=%d\n",row_p[1][1]);

	row_p=&array2[0];//赋值方法2

	printf("(*(*(row_p+1)+1))=%d\n",*(*(row_p+1)+1));
	printf("(*(row_p[1]+1))=%d\n",*(row_p[1]+1));
	printf("row_p[1][1]=%d\n",row_p[1][1]);

}
