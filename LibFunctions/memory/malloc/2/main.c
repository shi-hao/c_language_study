/*
 * malloc 测试
 * malloc动态内存分配，作用跟数组类似，所以有时候，malloc也被称为动态数组
 */
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

void main()
{
#define capacity  10

	char * var1;
	int * var2;

	struct st{
		int len;
		char* name;
	} *m_st;

	var1 = (char*)malloc(sizeof(var1) * capacity);//相当于定义了10个char型变量，效果等价于char array[10]
	var2 = (int *)malloc(sizeof(var2) * capacity);//相当于定义了10个int型变量，效果等价于int array[10]
	m_st = (struct st *)malloc(sizeof(struct st) * capacity);//相当于定义了10个struct st结构体变量，效果等价于
															 //struct st array[10]
	var1[0] = 25;
	var2[0] = 26;
	m_st[0].len = 0;
	m_st[0].name = "i am m_st.name";
	m_st->len = 10;

	(m_st + 1)->name = "i am another m_st.name";
	(m_st + 1)->len = 10;

	printf("\n var1[0] = %d \n", var1[0]);
	printf("\n var2[0] = %d \n", var2[0]);
	printf("\n m_st[0].len = %d \n", m_st[0].len);
	printf("\n m_st[0].name = %s \n", m_st->name);

	printf("\n (m_st+1)->len = %d \n", m_st[1].len);
	printf("\n (m_st+1)->.name = %s \n", (m_st+1)->name);
}
