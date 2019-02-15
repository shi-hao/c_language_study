/*
 * 共用体测试
 * 所有成员占用相同的内存空间，内存字节数是最大成员的字节数
 *
 */

#include<stdio.h>

/*定义共用体类型*/
union {
	int a;
	char b;
	short c;
} unionMe={1}, unionU={.a=1,.b=1,.c=1};//定义共用体并初始化

#if 0
unionH={.a:1,.b:1,.c:1};//定义共用体并初始化
#endif


void main()
{
	/*输出共用体的内容*/
	printf("unionMe.a=%d\n",unionMe.a); 
	printf("unionMe.b=%d\n",unionMe.b); 
	printf("unionMe.c=%d\n",unionMe.c); 

	/*共用体赋值*/
#if 0
	unionMe={1,2,3};
#endif

	unionMe.a=1;
}
