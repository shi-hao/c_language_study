/*
 *main函数参数测试
 */
#include<stdio.h>

/*
 *理论上，参数必须是int和char *[]两个参数， 
 *但是，测试发现，可以有多余的参数，不过这个参数的值不确定！！！！
 */
#ifdef Test
void main(int argc,  char *argv[],  char extra)
#else
void main(int argc, char *argv[])
#endif
{
	int cnt;
	printf("argc=%d\n", argc);

	for(cnt=0;cnt<argc;cnt++)
	{
		printf("argv[%d]=%s\n", cnt, argv[cnt]);
	}
#ifdef Test
	printf("extra=%d\n", extra);
#endif
}


void funcTest(){
	int a;
	int b;
}

void funcTest2(){
}

void funcTest3(){
}

void funcTest4(){
}
