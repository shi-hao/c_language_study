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

	typedef struct _item_{
		int   len;
		char* name;
	}item;
	item * my_item;

	//相当于定义了10个char型变量，效果等价于char array[10]
	var1 = (char*)malloc(sizeof(var1) * capacity);

	//相当于定义了10个int型变量，效果等价于int array[10]
	var2 = (int *)malloc(sizeof(var2) * capacity);

	//相当于定义了10个struct st结构体变量，效果等价于struct st array[10]
	my_item = (item *)malloc(sizeof(item) * capacity);

	var1[0] = 25;
	var2[0] = 26;

	printf("\n var1[0] = %d \n", var1[0]);
	printf("\n var2[0] = %d \n", var2[0]);

	//第一个元素
	my_item[0].len = 0;
	my_item[0].name = "i am my_item.name";

	//第一个元素
	my_item->name = "i am my_item.name";
	my_item->len = 10;

	printf("\n my_item[0].len = %d \n", my_item[0].len);
	printf("\n my_item[0].name = %s \n", my_item->name);

	//第二个元素
	(my_item + 1)->name = "i am another my_item.name";
	(my_item + 1)->len = 10;

	printf("\n (my_item+1)->len = %d \n", my_item[1].len);
	printf("\n (my_item+1)->.name = %s \n", (my_item+1)->name);


	////////////////////////////////////////////
	typedef struct _set_{
		int len;
		int offset;
		item * head;
	} set;
	set my_set;

	my_set.len = capacity;
	my_set.offset = 0;
	my_set.head = my_item;

	for(;my_set.offset < my_set.len;){
		printf("\n  %s \n", (my_set.head + my_set.offset)->name);
		my_set.offset++;
	}
	free(my_set.head);
}
