#include<stdio.h>

extern int DataProc(int a, int b);
extern int glo_sum;
extern int sta_glo_sum;

int main(){

	DataProc(1, 2);
	DataProc(1, 2);
	printf("glo_sum = %d\n", glo_sum);
	//printf("sta_glo_sum = %d\n", sta_glo_sum);
}


