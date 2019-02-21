/*****************************
 *本文件对数组，指针作为函数形参进行一定的测试
 *1）数组作为形参，格式要求，传参要求
 *2）指针作为形参，传入普通变量地址，传入数组地址
 *3) 结构体类型，共用体类型，枚举类型可以作为形参吗？？
 ******************************/
#include<stdio.h>
/*
 *结构体，共用体，枚举类型
 */
struct struct1{
	int a;
	int b;
}tststr;

union union1{
	int a;
	char b;
}tstuni;

enum enum1{
	fir=0,
	sec,
	thir,
}tstenu;
#if 1
void funtst(struct struct1 a, union union1 b, enum enum1 c)
{
	printf("i am just a test\n");
}
#endif
/*
 *数组作为函数形参，有其要求，具体可以看上一级目录里面的main.c测试文件
 *函数体内部对数组元素操作时，最好也用数组的形式取方位元素，不要在用指针形式
 *去访问，形成良好的习惯。
 */
void test(int array[], int array2[][2])
{
	printf("array[2]=%d\n",array[2]);
	printf("array2[0][1]=%d\n",array2[0][1]);
}
/*
 *指针作为参数，难点是传入数组的地址
 */
void test2(int *array, int *array2, int (*arrayRow)[2])
{
	printf("array[0]=%d\n",array[0]);
#if 0
	printf("array2[0][0]=%d\n",array2[0][0]); /*不能这样引用二维数组*/
#endif
	printf("arrayRow[0][0]=%d\n",arrayRow[0][0]);
}

void func(int a){
	a = 100;
	printf("a = %d\n", a);
}

int main(void)
{
	int array[5]={0,1,2,3,4};
	int array2[2][2]={{0,1},{2,3}};

#if 1
	funtst(tststr,tstuni,tstenu);
#endif

	/*以下四种方法虽然在调用时都能得到想要的结果，但是提倡使用第一种方法*/
	test(array,array2);/*直接以数组名作为实参数传入*/
	test(&array[0],&array2[0]);
	test(&array[0],&array2[0][0]);/*取地址作为实参数传入*/
	test(&array[0],array2[0]);

	test2(array,array2,array2);

	func(100);
	return 0;
}
