/*
 * char*[] short*[] int*[] long*[] float*[] double*[]
 * 一般比较有用的是char*[]，可以用来存储多个字符串。
 *
 * function*[]
 * 函数指针数组是很有用的一种数组，可以用来存储接口函数。
 * 在很多操作系统中，函数中断接口注册及调用是使用了函数指针数组的编程技术实现的。
 * int  *func();          //返回值为指针的函数
 * int (*func_p)();       //函数指针
 * int (*func_array[])(); //函数指针数组
 *
 * void*[]
 * void指针的适用性很好，也可以用作函数指针数组，缺点就是用起来稍微有些麻烦。
 */

#include<stdio.h>
#include<stdlib.h>

int jump(char* s){
	printf("%s jump high\n", s);
}

int run(char* s){
	printf("%s run away\n", s);
}

int back(char* s){
	printf("%s back away\n", s);
}

#define size 5
char* list[size]={
	"today is sunday!",
	"i want to have a holiday!",
	"go ahead!",
	"tommorow is a mystery, today is a gift!",
	"let's go!"
};

int main(){
#define  ssize  3

	//function pointer array
	int(*call_list[ssize])(char*);

	//char pointer array
	char* name[ssize]={"bob", "jeny","tom"};

	//void pointer
	void* array[2];

	//function pointer array
	call_list[0] = jump;
	call_list[1] = run;
	call_list[2] = back;
	
	//call function array
	for(int cnt=0; cnt<ssize; cnt++){
		call_list[cnt](name[cnt]);
	}
   
	//void* used as function pointer
	array[0] = jump;
	array[1] = run;

	//call function
	((int(*)(char*))array[0])(name[0]);
	((int(*)(char*))array[1])(name[1]);

	//char* array
	for(int cnt=0; cnt<size; cnt++)
	  printf("%s \n", list[cnt]);
}
