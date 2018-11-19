/*位域测试*/
#include<stdio.h>
#include<memory.h>

//#pragma pack(1)
/*孤立的位域成员*/
typedef struct {
	unsigned short short_var2;
	//	 unsigned char char_var2;
	unsigned int bit_var1:14;
	unsigned char char_var;
	unsigned int bit_var2:18;
}S1;
//#pragma pack()

/*连续的位域成员*/
#pragma pack(1)
typedef struct {
	unsigned char char_var;
	unsigned char bit_var1:7;
	unsigned bit_var2:7;
	unsigned bit_var3:14;
	unsigned bit_var4:25;
	unsigned bit_var5:27;
}S2;
#pragma pack()

void main()
{

	int tmp,cnt;
	unsigned char *p;
	S2 S2_var;

	/*孤立的位域成员占用字节数*/
	S1 S1_var;
	tmp = sizeof(S1);
	memset(&S1_var,0,tmp);

	S1_var.short_var2 = 1;
	S1_var.bit_var1 = 1;
	S1_var.char_var = 1;
	S1_var.bit_var2 = 1;
	//S1_var.char_var2 = 1;

	printf("sizeof(S1)=%d\n",sizeof(S1));
	p = (unsigned char *)(&S1_var);
	for(cnt=0;cnt<tmp;cnt++)
	{
		printf("p[%d]=%x\n",cnt,p[cnt]);
	}

	/*连续的位域成员*/
	printf("sizeof(S2)=%d\n",sizeof(S2));
	tmp = sizeof(S2);
	memset(&S2_var,0,tmp);

	S2_var.bit_var1=1;
	S2_var.bit_var2=1;
	S2_var.bit_var3=1;
	S2_var.bit_var3=1;
	S2_var.bit_var4=1;
	S2_var.bit_var5=1;

	p = (unsigned char *)(&S2_var);
	for(cnt=0;cnt<tmp;cnt++)
	{
		printf("p[%d]=%#x\n",cnt,p[cnt]);
	}
}
