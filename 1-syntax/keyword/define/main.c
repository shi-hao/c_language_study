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

	int toVar(i) = 100;
	int tmp;

	printf("toVar(i) = %d\n", vari);
	printf("PI=%f\n", PI);
	printf("plus(1, 2)=%d\n", plus(1, 2));
	printf("process(1, 2)=%d\n", process(1, 2));
	printf(" %s\n", toStr(i am good ) "?");

	p = &max;
	tmp = GetAge(p);
	printf("max age is %d\n", tmp);
}
