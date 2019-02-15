/*
 *作者：bleach
 *时间：2014.05.07
 * 
 * struct类型是一种扩展数据类型，需要先定义struct
 * 的具体成员，然后才可以定义相应的变量。
 *
 ** 定义
 ** 初始化成员
 ** 各个成员赋值
 ** 引用成员
 ** 同类型struct互相赋值
 ** 同类型struct比较各个成员
 *
 */
#include<stdio.h>

//定义
struct student{
	int num;
	char name[20];
	char sex;
	int age;
	float score;//注意最后的成员也要加分号
}lili, *plili;/*(1)直接定义法*/
struct student lilei,*plilei;/*(2)间接定义*/

/*(3)缺省定义*/
struct{
	int num;
}test, *ptest;

/*(4)使用typedef*/
typedef struct teacher{
	int num;
	char name[20];
	char sex;
	int age;
}sTeacher, *psTeacher;//结构体类型，结构体指针
psTeacher PTeacher;//推荐此种方法

void main()
{
	//各成员初始化
	sTeacher  MrWang={0,"Wang",0,35};//常用方法  
	sTeacher  MrZhou={
		.num = 1,
		.name="Zhou",
		.sex=0,
		.age=30
	};//gcc扩展语法
	sTeacher MrLi ={
	num:1,
	name:"Li",
	sex:0,
	age:40
	};//gcc扩展语法

	//各成员赋值
	MrWang.num = 20;/*唯一的方法*/
	MrWang.age = 40;

	//引用各成员
	printf("MrWang.num=%d\n",MrWang.num);//引用方法1
	printf("MrZhou.num=%d\n",MrZhou.num);
	printf("MrLi.name=%s\n",MrLi.name);
	PTeacher=&MrWang;
	printf("PTeacher->age=%d\n",PTeacher->age);//引用方法2
	printf("(*PTeacher).age=%d\n",(*PTeacher).age);//引用方法3

	/*可以在函数体内定义新的结构体类型*/
	struct inner{
		int a;
		int b;
		int c;
		char d[7];
	};
	//struct变量之间可以直接赋值，但是无法无法直接比较各成员是否相等！！
	struct inner inner_1={1,1,1,"inner_1"};
	struct inner inner_2={2,2,2,"inner_2"};
	printf("inner_1.a=%d\n",inner_1.a);
	printf("inner_1.d=%s\n",inner_1.d);
	inner_1=inner_2;/*同类型的结构体变量之间可以互相赋值*/
	printf("inner_1.a=%d\n",inner_1.a);
	printf("inner_1.d=%s\n",inner_1.d);
}
