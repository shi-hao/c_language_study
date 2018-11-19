#include<stdio.h>
void main()
{
  int a,b;

  a = 2;
  b = 0;

  b = (++a)-2;
  printf("a=%d\n",a);

  a=(a--)-2;
  printf("a=%d\n",a);
    
  printf("for 1!\n");
  for(a=0;a<2;a++)
  {
    printf("a=%d\n",a);
  }

  printf("for 2!\n");
  for(a=0;a<2;++a)
  {
    printf("a=%d\n",a);
  }

  printf("while 1!\n");
  a=0;
  while(++a<2)
  {
    printf("a=%d\n",a);
  }

  printf("while 2!\n");
  a=0;
  while(a++<2)
  {
    printf("a=%d\n",a);
  }
}
