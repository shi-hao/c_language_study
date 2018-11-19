#include<stdio.h>


void main()
{
	int a=1;
#if 1
	a = ((a++) + (a+=1));
	printf("a=%d\n",a);

	a = 1;
	a = ((++a) + (a+=1));
	printf("a=%d\n",a);
#else
	a = ((++a) + (a-=1));
#endif


#if 0
	int a=1;
	printf("(a++) + (a--)=%d\n", (a++) + (a--));
	printf("a=%d\n",a);

	a = 1;
	printf("(++a) + (a--)=%d\n", (++a) + (a--));
	printf("a=%d\n",a);

	a = 1;
	printf("(++a) + (a-=1)=%d\n", (++a) + (a-=1));
	printf("a=%d\n",a);
#endif
}
