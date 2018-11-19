/*
 ************************************
 *作者：bleach
 *时间：2014.05.07
 *说明：struct定义、初始化、赋值、引用
 *************************************
 */
#include<stdio.h>
/*--定义结构体类型以及变量--*/
struct student{
	int num;
	char name[20];
	char sex;
	int age;
	float score;//-----注意最后的成员也要加分号------
} LiLi, *PLiLi;/*(1)直接定义法*/
struct student LiLei,HanMeiMei,*PLiLei;/*(2)间接定义*/
/*(3)缺省定义*/
struct {
	int num;
}test, *Ptest;
/*(4)使用typedef*/
typedef struct teacher{
	int num;
	char name[20];
	char sex;
	int age;
}StructTeacher, *PStructTeacher;//结构体类型，结构体指针
PStructTeacher PTeacher;

struct {
	unsigned char var;
}char_var;

struct {
	unsigned short var; 
}short_var;

struct {
	char var1;
	char var2;
	char var3;
}char_var2;


/****************************************/
//几种重名的问题
struct name{
	char id;
	char age;   //成员名和外部的变量重名是可以的！
	char name;  //结构体内成员名和结构体类型名重名是可以的！
}myname;

int id;
int age;

struct name name; //结构变量名与结构体类型名重名是可以的！

/***************************************/

void main()
{
	/*结构体变量初始化*/
	StructTeacher  MrWang={0,"Wang",0,35};//常用方法  
	StructTeacher  MrZhou={
		.num = 1,
		.name="Zhou",
		.sex=0,
		.age=30
	};//gcc扩展语法
	StructTeacher MrLi ={
num:1,
	name:"Li",
	sex:0,
	age:40
	};//gcc扩展语法
	/*可以在函数体内定义新的结构体类型*/
	struct err{
		int a;
		int b;
		int c;
		char d[7];
	}errInit={1};/*有问题的初始化方法*/
	printf("errInit.b=%d\n",errInit.b);

	/*结构体变量赋值*/
	MrWang.num = 20;/*唯一的方法*/
	MrWang.age = 40;

	struct err err_1={1,1,1,"err_11"};
	struct err err_2={2,2,2,"err_2"};
	printf("err_1.a=%d\n",err_1.a);
	printf("err_1.d=%s\n",err_1.d);
	err_1=err_2;/*同类型的结构体变量之间可以互相赋值*/
	printf("err_1.a=%d\n",err_1.a);
	printf("err_1.d=%s\n",err_1.d);

	/*结构体变量引用*/
	printf("MrWang.num=%d\n",MrWang.num);//引用方法1
	printf("MrZhou.num=%d\n",MrZhou.num);
	printf("MrLi.name=%s\n",MrLi.name);
	PTeacher=&MrWang;
	printf("PTeacher->age=%d\n",PTeacher->age);//引用方法2
	printf("(*PTeacher).age=%d\n",(*PTeacher).age);//引用方法3

	printf("sizeof(char_var)=%d\n",sizeof(char_var));//引用方法3
	printf("sizeof(char_var2)=%d\n",sizeof(char_var2));//引用方法3
	printf("sizeof(short_var)=%d\n",sizeof(short_var));//引用方法3
}
