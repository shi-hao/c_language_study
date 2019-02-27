/*
 * 多维数组
 * 2维，3维...
 *
 * [行][列]
 */

#include<stdio.h>
void main()
{
	int* p;

	//定义，初始化
	int array1[2][3]={1,2,3,4,5,6};//初始化,按行连续赋值
	int array2[2][3]={{1,2,3},{4,5,6}};//初始化,按行分段赋值
	int array3[][3]={{1,2,3},{4,5,6}};//初始化,按行分段赋值

	//赋值
	array1[0][1] = 10;

	//引用
	printf("array1[0][2]=%d\n",array1[0][2]);
	printf("array2[0][2]=%d\n",array2[0][2]);
	printf("array3[0][2]=%d\n",array3[0][2]);

	//多维数组在内存中按照行存储，即行主序
	p = (int*)array2;
	for(int cnt=0; cnt<6; cnt++)
		printf("%d  ", *p++);
}
