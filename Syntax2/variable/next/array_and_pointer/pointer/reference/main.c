#include<stdio.h>
#include<stdlib.h>


int  main()
{
	int i = 1;
	int &j = i;
	//int &k;

	//k = i;

	printf("i=%d\n",i);
	printf("j=%d\n",j);

	return 0;
}
