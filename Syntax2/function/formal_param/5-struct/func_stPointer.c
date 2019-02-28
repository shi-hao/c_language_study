/*
 * 指针类型作为函数形式参数
 * char* short* int* long* float* double*
 * struct*
 * 指针作为函数形式参数，实参将自己的地址传递给函数，函数能够改变实际参数的值，这是指针作为
 * 形式参数最大的特点。
 */
#include<stdio.h>
#include<stdlib.h>

//char* double*
void function(int* p, double* pp){
	*p = 20;
	*pp = 30;
}

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

	printf("a = %d, b=%f\n", a, b);
	function(&a, &b);
	printf("a = %d, b=%f\n", a, b);

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
