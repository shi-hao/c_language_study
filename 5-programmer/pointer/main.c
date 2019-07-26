#include<stdio.h>
#include<stdlib.h>


void main(){
	int i;
	int *p;
	int **pp;
	int ***ppp;

	i = 100;

	p   = &i;
	pp  = &p;
	ppp = &pp;

	*p     = 1;
	**pp   = 2;
	***ppp = 3;

	printf("i = %d\n", i);
}
