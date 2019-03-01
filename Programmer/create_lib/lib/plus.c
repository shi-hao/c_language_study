/*
 *this is a simple test!
 */
#include<stdio.h>
#include<stdlib.h>


int plus(int a, int b){

	printf("\n call %s \n", __func__);
	return(a+b);

}
