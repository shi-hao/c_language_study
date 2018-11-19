/*
 * 结构体字节对齐测试！
 * 字节对齐，一般指的是变量的首地址
 */

#include<stdio.h>

//#pragma pack(1) //强制按照1字节对齐

struct {

} null;

typedef struct {
	char var1;
	short var2;
}S1;

typedef struct {
	char var1;
	short  var2;
	double var3;
}S2;

typedef struct {
	char var1;
	char var2;
	char var3;
}S3;

typedef struct {
	int var1;
	S2  var2;
	short var3;
}S4;

void main()
{
    char charVar;
	short shortVar;
	int intVar;
	long longVar;
	float floatVar;
	double doubleVar;

	printf("-----------基本数据类型占用字节数测试--------------------\n");
	printf("sizeof(char)=%ld\n",sizeof(char));
	printf("sizeof(short)=%ld\n",sizeof(short));
	printf("sizeof(int)=%ld\n",sizeof(int)); 
	printf("sizeof(long)=%ld\n",sizeof(long)); 
	printf("sizeof(float)=%ld\n",sizeof(float));
	printf("sizeof(double)=%ld\n",sizeof(double));

	printf("-------------------------------\n");
	printf("-------------基本数据类型字节对齐测试------------------\n");
	printf("(&charVar)%%1=%d %#x %ld\n",((int)(&charVar))%1, (int)&charVar, sizeof(char *));
	printf("(&shortVar)%%2=%d %#x \n",((int)(&shortVar))%2, (int)&shortVar);
	printf("(&intVar)%%4=%d %#x \n",((int)(&intVar))%4, (int)&intVar);
	printf("(&longVar)%%4=%d %#x \n",(int)(&longVar)%4, (int)&longVar);
	printf("(&floatVar)%%4=%d %#x \n",(int)(&floatVar)%4,  (int)&floatVar);
	printf("(&doubleVar)%%8=%d %#x\n",(int)(&doubleVar)%8, (int)&doubleVar);
	printf("-------------------------------\n");

	printf("-------------结构整体占用字节数的对齐---------------\n");
	printf("sizeof(null)=%ld\n",sizeof(null));// =0
	printf("sizeof(S1)=%ld\n",sizeof(S1));//结构体整体占用字节数按照2对齐
	printf("sizeof(S2)=%ld\n",sizeof(S2));//结构体整体占用字节数按照4对齐
	printf("sizeof(S3)=%ld\n",sizeof(S3));//结构体整体占用字节数按照1对齐
	printf("sizeof(S4)=%ld\n",sizeof(S4));//结构体整体占用字节数按照4对齐
}
