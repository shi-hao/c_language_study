
#include<stdio.h>
#include<stdlib.h>

#define max  (1024 * 1024 * 256)

typedef struct menber{
	int *age;
	char score[max];
}smember;

smember example;


void check(smember s){
	int cnt=0;
	*s.age = 9;
	for(cnt=0; cnt<max; cnt++){
		s.score[cnt] = cnt;
		printf("\nthis is the %d write\n", cnt);
	}	
}


int main(){
	int a = 19;

	example.age = &a;
	check(example);




}
