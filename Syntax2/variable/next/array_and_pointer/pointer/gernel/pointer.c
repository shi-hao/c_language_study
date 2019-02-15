/*
 ******************************************
 *Author      : shihao 2013/11/19
 *Description : 指针测试
 ******************************************
 */
#include<stdio.h>

void PrintfTest()
{
   printf("函数指针测试!\n");
}
void main()
{
  /*一维数组，二维数组和指针测试*/
  unsigned int a[5][6]={0};
  unsigned int b[9];
  unsigned int *p, *q;

  /*字符串指针测试*/
  unsigned char* CharP;
  unsigned int* IntP;

  /*函数指针测试*/
  void (*funcP)();

  /*指针引用变量的方法*/
  unsigned int*PRef; 
  unsigned int Ref = 1;
  unsigned int*PRef2;
  unsigned int Ref2[1] = {2}; 

  /*指针的值测试*/
  unsigned int test = 0x01000002;
  unsigned int* testP = &test;

  unsigned char cnt;

  a[2][3] = 1;
  b[6]=1;

  a[0][0] = 1; 
  a[0][1] = 2;
  a[1][0] = 3;
  
  p = a[0];
  q = b;

  /*指针变量运算*/
  printf("p=%x\n",p);
  printf("q-p=%d\n",q-p);
  printf("p-1=%x\n",p-1);
#if 0
  printf("q+p=%d\n",q+p);
  printf("q*p=%d\n",q*p);
  printf("q/p=%d\n",q/p);
#endif
  
  
  /*通过指针访问二维数组元素*/
  printf("*(p+2+5*3)=%d\n",*(p+2+5*3));
 
  printf("*(p+3+6*2)=%d\n",*(p+3+6*2)); 
  
  /*通过指针访问一维数组元素*/
  printf("*(q+6)=%d\n",*(q+6));
  
  /*测试二维数组是按行还是按列存储*/
  for(cnt=0;cnt<30;cnt++)
     printf("%d\n",*(p+cnt));
  
  /*测试字符串指针*/
  CharP = "CharP:This is a test!";
  IntP ="IntP:This is a test!";//这种复制也是可以的但是这样不利于引用字符串的每一个字节
                               //int型数据占4字节，每个字节都会填入一字节的字符常量值
  
  printf("%s\n",CharP);
  printf("%d\n",*CharP);
  printf("%d\n",*(CharP+4));
  printf("%d\n",*IntP);
  printf("%d\n",(char)((*IntP)>>24));


  /*测试函数指针*/
  funcP = PrintfTest;
  funcP(); 

  /*指针引用测试*/
  PRef = &Ref;
  printf("PRef[0]=%d\n", PRef[0]);
  printf("PRef[1]=%d\n", PRef[1]);
  printf("*PRef=%d\n",*PRef);

  PRef2 = Ref2;
  printf("PRef2[0]=%d\n", PRef2[0]);
  printf("PRef2[1]=%d\n", PRef2[1]);
  printf("*PRef2=%d\n",*PRef2);

  
  /*指针值测试*/
  printf("*(char*)(testP)=%d\n", *(char*)(testP));

  //指针互相赋值测试 
  {
	  int *i, *j;
	  int x=100;
	  i = &x;
	  j = i;
	  printf("\n\nj=%d\n\n", *j);
  }
}

