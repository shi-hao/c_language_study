/*
 * 结构体字节对齐测试！
 * 结构体整体占用字节数并不一定等于各个成员占用字节数的加和。
 * 各个成员在内存上并不是紧密相连的，成员之间有一些字节空隙。
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
#pragma pack(0)

void main()
{
	printf("-------------结构体占用字节数的对齐---------------\n");
	printf("sizeof(null)=%ld\n",sizeof(null));// =0
	printf("sizeof(S1)=%ld\n",sizeof(S1));//结构体整体占用字节数按照2对齐
	printf("sizeof(S2)=%ld\n",sizeof(S2));//结构体整体占用字节数按照4对齐
	printf("sizeof(S3)=%ld\n",sizeof(S3));//结构体整体占用字节数按照1对齐
	printf("sizeof(S4)=%ld\n",sizeof(S4));//结构体整体占用字节数按照4对齐
}
