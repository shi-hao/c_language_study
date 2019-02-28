/*
 * 指针类型作为函数形式参数
 * struct*
 */

#include<stdio.h>
#include<stdlib.h>

//struct*
typedef struct stt{
	int* p;
	float* pp;
	double c;
}STT;

void function_st1(STT s){
	*(s.p) = 11;
	*(s.pp) = 11.1;
	s.c = 11;
}

void function_st2(STT* s){
	*(s->p) = 22;
	*(s->pp) = 22.2;
	s->c = 22;
}

void main(){
	int a=100;
	double b=1.1;

	int c=10;
	float d=10.1;

	STT stt_test;
	stt_test.p = &c;
	stt_test.pp = &d;
	stt_test.c = 10;

	printf("\n*stt_test.p=%d, *stt_test.pp=%f, stt_test.c=%f \n", *stt_test.p, *stt_test.pp, stt_test.c);
	printf("c=%d, d=%f \n", c, d);

	function_st1(stt_test);

	printf("\n*stt_test.p=%d, *stt_test.pp=%f, stt_test.c=%f \n", *stt_test.p, *stt_test.pp, stt_test.c);
	printf("c=%d, d=%f \n", c, d);

	function_st2(&stt_test);

	printf("\n*stt_test.p=%d, *stt_test.pp=%f, stt_test.c=%f \n", *stt_test.p, *stt_test.pp, stt_test.c);
	printf("c=%d, d=%f \n", c, d);
}
