/*
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
#include<string.h>

//定义
struct student{
	int num;
	char name[20];
	char sex;
	int age;
	float score;//注意最后的成员也要加分号
}lili;/*(1)直接定义法*/
struct student lilei;/*(2)间接定义*/

/*(3)缺省定义*/
struct{
	int num;
}test;

/*(4)使用typedef*/
typedef struct teacher{
	int num;
	char name[20];
	char sex;
	int age;
}sTeacher;//结构体类型，结构体指针

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

	/*可以在函数体内定义新的结构体类型*/
	struct inner{
		int a;
		int b;
		int c;
		char d[8];
	};

	//struct变量之间可以直接赋值，结构体的各个域会相互赋值，struct st a, b;  a=b;
	struct inner inner_1={1,1,1,"inner_1"};
	struct inner inner_2={2,2,2,"inner_2"};
	printf("inner_1.a=%d\n",inner_1.a);
	printf("inner_1.d=%s\n",inner_1.d);
	inner_1=inner_2;/*同类型的结构体变量之间可以互相赋值*/
	printf("inner_1.a=%d\n",inner_1.a);
	printf("inner_1.d=%s\n",inner_1.d);


	/*
	 *<compare two instances of structs for equality>
	 *(1)using operator "==", this is wrong, syntax error!!
	 *(2)uisng function "memcmp()", this is unsafe, maybe wrong, not recommended, because
	 *   the struct variables have padding bytes, their values maybe uncertain!!
	 *(3)compare the members one by one, this sames not good, but is a right method
	 */

	//using memcmp() for example
	struct foo{
		char a;
		/* padding */
		double d;
		/* padding */
		char e;
		/* padding */
		int f;
	};
	struct foo foo_1={1,5.4,1,10}, foo_2={1,5.4,1,10};
	if(memcmp(&foo_1, &foo_2, sizeof(struct foo)) == 0)//this is wrong
	{
		printf("struct euqal using memcmp\n");
	}

	if((foo_1.a == foo_2.a) && (foo_1.d == foo_2.d) && (foo_1.e == foo_2.e) && (foo_1.f == foo_2.f))
	{
		printf("struct euqal using members compare\n");
	}

}
