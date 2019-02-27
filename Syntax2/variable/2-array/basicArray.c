/*
 *  6种数据类型数组 
 *  char[], short[], int[], long[], float[], double[] 
 *	char数组和其他数组最大的区别:可以使用字符串常量赋值。
 */

#include<stdio.h>
#include<string.h>

#define   size   10

void main()
{
	//定义，初始化
	char charArray[4]="abc";//char数组的长度要比字符串长度至少大1
	short shortArray[6];

	int intArray[7]={1,2,4};//初始化部分元素
	long longArray[8];//不初始化元素
	float floatArray[9]={0};//初始化所有元素为0
	double doubleArray[10];

	//赋值
	intArray[5] = 10;
	floatArray[0] = 1.1; 

	//引用
	printf("%c\n",charArray[0]);
	printf("%d\n",intArray[1]);
	printf("%f\n",floatArray[0]);

	//数组越界访问
	printf("%f\n", floatArray[10]);
}
