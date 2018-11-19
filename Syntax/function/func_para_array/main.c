/*
 ********************************
 *作者：时浩
 *说明：C函数的相关知识测试
 ********************************
 */
#include<stdio.h>
#if 0
int test = 2; //测试：函数名是否可以和变量的名字相同
#endif
void PrintInfo()
{
	printf("printf info\n");
}
#if 1
int test(int array[5])//测试：数组作为形参，数组的大小是否要定义
#else
int test(int array[])//测试：数组作为形参，数组的大小是否要定义
#endif
{
	char a = 1;
	char test = 2;//测试：函数名是否可以和变量的名字相同
	int PrintInfo = 1;

	printf("test = %d\n",test);

	printf("array size is %d\n",sizeof(array));

	printf("array[9]  is %d\n",array[9]);

#if 0
	PrintInfo();//测试：函数名是否可以和变量的名字相同
#endif

	return a;//测试：返回值与函数定义返回值类型不匹配的问题
}
#if 1
int test2(int array[][2])
#else
int test2(int array[][])
#endif 
#
{
	printf("array[0][1]=%d\n",array[0][1]);
	return 0;
}

/*
 *---纠正一个问题---
 *形参为数组，传入数组，在函数中修改数组元素，在主调函数中，对数组元素有没有影响？？？
 */
void FormatArray(int array[])
{
	printf("array=%x\n",array);
	printf("&array[0]=%x\n",&array[0]);
	printf("&array=%x\n",&array);
	array[0] = 1;
}

void main()
{
	int arr[10];
	int arr2[2][2];
	int arr3[2][3];
	int RetVal;
	char testVal;

	int i;
	int imp[2] = {0,1};

	arr[9] = 0;
	arr2[0][0]=1;
	arr2[0][1]=9;
	arr3[0][1]=9;
	RetVal = test(arr);
	printf("sizeof(arr)=%d\n",sizeof(arr));
	printf("sizeof arr=%d\n",sizeof arr);
	printf("RetVal = %d\n",RetVal);
	printf("--------------------\n");
	testVal = test(arr);
	printf("testVal = %d\n",testVal);//返回值与函数定义返回值类型不匹配的问题
	test2(arr2);   
	test2(&arr2[0]);

	test2(&arr2[0][0]);
	test2(arr2[0]);

	test2(arr3);//数组的维度都可以不一致，但是会报警告

	for(i=0;i<2;i++)
	{
		printf("imp[%d]=%d\n",i,imp[i]);
	}

	printf("imp=%x\n",imp);
	printf("&imp=%x\n",&imp);
	printf("&imp[0]=%x\n",&imp[0]);
	FormatArray(imp);

	for(i=0;i<2;i++)
	{
		printf("imp[%d]=%d\n",i,imp[i]);
	}
}
