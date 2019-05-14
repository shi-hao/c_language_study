/*
 * malloc 测试
 * 动态内存分配，执行时数据结构，数据段，文本段，堆，栈，因为数据段和栈中的内存的大小是固定，动态内存分配
 * 是使用堆中的内存，内存长度可以根据需要自由申请。
 * void* malloc(size_t size);
 * 形式参数：内存的大小，以字节为单位
 * 返回值  ：void* 指针
 *
 */

#include<string.h>
#include<stdio.h>
#include<stdlib.h>

void main()
{
#define capacity  10

	////////////////////////////////////////////
	char * var1;
	int  * var2;

	struct st{
		int   len;
		char* name;
	} *myst;

	//相当于定义了10个char型变量，效果等价于char array[10]
	var1 = (char*)malloc(sizeof(var1) * capacity);

	//相当于定义了10个int型变量，效果等价于int array[10]
	var2 = (int *)malloc(sizeof(var2) * capacity);

	//相当于定义了10个struct st结构体变量，效果等价于struct st array[10]
	myst = (struct st *)malloc(sizeof(struct st) * capacity);

	var1[0] = 25;
	var2[0] = 26;

	printf("\n var1[0] = %d \n", var1[0]);
	printf("\n var2[0] = %d \n", var2[0]);

	//第一个元素
	myst[0].len = 0;
	myst[0].name = "i am myst.name";

	//第一个元素
	myst->name = "i am myst.name";
	myst->len = 10;

	printf("\n myst[0].len = %d \n", myst[0].len);
	printf("\n myst[0].name = %s \n", myst->name);

	//第二个元素
	(myst + 1)->name = "i am another myst.name";
	(myst + 1)->len = 10;

	printf("\n (myst+1)->len = %d \n", myst[1].len);
	printf("\n (myst+1)->.name = %s \n", (myst+1)->name);


	////////////////////////////////////////////
	struct myst_set{
		int len;
		int offset;
		struct st * head;
	} myst_set_obj;

	myst_set_obj.len = capacity;
	myst_set_obj.offset = 0;
	myst_set_obj.head = myst;

	for(;myst_set_obj.offset < myst_set_obj.len;){
		printf("\n  %s \n", (myst_set_obj.head + myst_set_obj.offset)->name);
		myst_set_obj.offset++;
	}
	free(myst_set_obj.head);
}
