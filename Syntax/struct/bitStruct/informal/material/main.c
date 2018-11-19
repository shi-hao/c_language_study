/*位结构*/
#include<stdio.h>
/*定义位结构类型*/
struct bitstc{
 unsigned bit0area:2;
 unsigned bit1area:3;
 unsigned bit2area:4;
 unsigned bit3area:16;
}test={1,1,1,0x8001};

struct bitstci2{
 unsigned bit0area:2;
 unsigned bit1area:3;
 unsigned bit2area:4;
 unsigned bit3area:24;
}test3={1,1,1};

struct mix{
char i;//占用第0字节
short j;//占用第2-3字节
unsigned char k:4;//占用第4字节的0-3位
unsigned short l:8;//占用第4字节的4-7和第五字节的0-3位
unsigned char m:4;//占用第5字节的4-7位
}test2={1,2,1,1,0};

struct {
 //unsigned double err:10;  //不允许出现double float
 //unsigned long   long_bit:64; //最大比特数为32
 //unsigned long   long_bit1:65;
 unsigned bit3:32;
 //unsigned bit4:33; //最大比特数为32
};

#pragma pack(1)
struct mix2{
  unsigned rel:12;
	unsigned tel:12;
	unsigned char TADDR[3];
};
#pragma pack()

#pragma pack(1)
struct mix3{
  unsigned tel:13;
	unsigned rel:8;
}mix3_var;
#pragma pack()

struct mix2 mix2_var={0,0,{0,0,0}};

void main()
{
	unsigned int var=0x000000ff;

	printf("-------------------------\n");
	if(*(unsigned char*)(&var) == 0xff)
		printf("little endian\n");
	else
		printf("big endian\n");
  printf("-------------------------\n");	

  printf("sizeof(test3)=%d\n",sizeof(test3));

  /*测试位结构的位对齐的方式*/
  printf("sizeof(test)=%d\n",sizeof(test));
  printf("&test=0x%x\n",*((unsigned char*)&test));//输出结果位0x25，即0010 0101, 0-1位bit0area,2-4位bit1area,5-7位+下字节0位bit2area 
  printf("&test=0x%x\n",*(((unsigned char*)&test)+1));//输出结果0x2，二字节的1-7+第三字节0-7+第四字节的0位bit3area
  printf("&test=0x%x\n",*(((unsigned char*)&test)+2));//输出结果0x0,
  printf("&test=0x%x\n",*(((unsigned char*)&test)+3));//输出结果0x1
  
  /*测试混合结构的对齐的方式*/
  printf("sizeof(test2)=%d\n",sizeof(test2));//结构体整体占用字节数按照2对齐
  printf("&test2=0x%x\n",*((unsigned char*)&test2)); 
  printf("&test2=0x%x\n",*(((unsigned char*)&test2)+1));
  printf("&test2=0x%x\n",*(((unsigned char*)&test2)+2));
  printf("&test2=0x%x\n",*(((unsigned char*)&test2)+3));
  printf("&test2=0x%x\n",*(((unsigned char*)&test2)+4));

	mix2_var.rel=0x505;
	mix2_var.tel=0x505;
	memset(mix2_var.TADDR,1,3);

	printf("1st byte=%x\n",*(unsigned char*)(&mix2_var));
	printf("2nd byte=%x\n",*((unsigned char*)(&mix2_var)+1));
	printf("3rd byte=%x\n",*((unsigned char*)(&mix2_var)+2));
	printf("4th byte=%x\n",*((unsigned char*)(&mix2_var)+3));

	printf("sizeof(mix2_var)=%d\n",sizeof(mix2_var));
	printf("sizeof(mix3_var)=%d\n",sizeof(mix3_var));
}
