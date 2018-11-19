/*
 *结构体位域成员对齐测试
 */
#include<stdio.h>
#include<memory.h>

#pragma pack(1)
typedef struct {
	unsigned char var_char;
	unsigned int var_int;

	unsigned char bit_char2:6; //独立的位域成员

	unsigned char var_char2;


	unsigned int bit_int1:17; //连续的位域成员
	unsigned int bit_int2:9;
	unsigned char bit_char1:5;

	unsigned int bit_int3:25;

}S1;
#pragma pack()





void main()
{
	S1 sample;
	int size, cnt;
	unsigned char *p;


	size = sizeof(sample);
	printf("sizeof(S1)=%d\n",size);

	/*赋值 */
	memset(&sample,0,size);

	sample.var_char=1;
	sample.var_char2=1;
	sample.var_int=1;

	sample.bit_char2=1;
	sample.bit_int1=1;
	sample.bit_int2=1;
	sample.bit_char1=1;
	sample.bit_int3=1;

	p = (unsigned char *)(&sample);
	for(cnt=0;cnt<size;cnt++)
	{
		printf("p[%d]=%#x\n",cnt,p[cnt]);	
	}
}
