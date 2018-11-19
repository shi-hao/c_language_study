/*宏测试*/
#include<stdio.h>
#include"usrdef.h"

struct{
	int age;
	int sex;
} max={10,0}, *p;

//访问结构体成员，使用##运算符,注意gcc不识别这种用法
#if 1
#define GetAge(t)  t->age;
#else 
#define GetAge(t)  t##->age;
#endif

void main(int argc,  char* argv[]){

	int tmp;

	//##运算符测试
	int  before(i);

	p = &max;
	tmp = GetAge(p);

	printf("max age is %d\n", tmp);
	printf(" %s\n", toStr2(i am good) "?");


	tmp = 0;
	printf("((tmp++)<1)=%d\n", (tmp++)<1);
	printf("((++tmp)<1)=%d\n", (++tmp)<1);

	tmp = 0;
	printf("tmp++ + tmp = %d", tmp++ + tmp);
}
