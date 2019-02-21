#include<stdlib.h>
#include<stdio.h>


/*
 *函数形参传数值和传地址的主要区别在于：
 * 传数值仅仅将变量的数值传入了函数，而传地址，不仅将变量的数值传入了函数，而且可以在函数
 * 中改变变量的数值。
 *
 *在设计函数时，函数的参数和返回值有一定的套路可以遵循
 *
 * 参数：
 *(1)传入单个数据，直接传递单个变量的值或者地址都可以，很简单。
 *(2)传入多个数据，如果传入的多个数据之间有一定的逻辑关系，可以考虑使用结构体传入,
 *   如果多个数据之间没有一定的逻辑关系，那只能使用数组，传递指针。
 *
 * 返回值：
 *(1)返回单个数据，直接使用return，或者函数参数使用传地址，直接在函数内部更新返回值。
 *(2)返回多个数据，多个数据之间有关联，考虑结构体进行封装，没有关联，那么只能在函数参数中传入
 *   指针，用来在函数中更新返回结果。
 * 
 */

//范例1
//计算两个数之和
//返回值通过return和传入地址来实现
int cal_sum(int a, int b, int* result){

	*result = a + b;
	return a+b;
}

//范例2
//计算多个数据之和
//传入多个数据，返回单个数据
int cal_many_sum(int * data, int num, int* result){
	
	*result = 0;
	for(int tmp=0;tmp<num;tmp++)
	{
		*result += data[tmp];
	}
	return *result;
}

//范例3
typedef struct  _student_ {
	char * name;
	int age;

}student;
//传入多个数据，返回多个数据，使用结构体封装数据
student checkeinfo(student s){

	printf("\ns.name=%s", s.name);
	printf("\ns.age=%d", s.age);

	s.age++;

	return s;
}

//范例4
//传入多个数据，返回多个数据
int cal_plus(int * in, int inSize, int* out, int outSize){
	int tmp;
	for(tmp=0;tmp<inSize;tmp++){
		if(tmp >= outSize)
			break;
		out[tmp] = in[tmp] + 1;
	}
	return tmp;
}

//范例5
//传入多个数据，返回多个数据
int cal_plus2(int * in, int inSize){
	int tmp;
	for(tmp=0;tmp<inSize;tmp++){
		in[tmp]++;
	}
	return tmp;
}


int main(){

#define num  10
	int a,b,result;
	int data[num];
	int in[num]={1};
	int out[num];
	student s;
	s.name = "bob";
	s.age = 30;

	cal_sum(a, b, &result);
	cal_many_sum(data, num, &result);
	s = checkeinfo(s);
	s = checkeinfo(s);

	cal_plus(in, num, out, num);
	printf("\nout[9] = %d",out[9]);
	cal_plus2(in, num);
	printf("\nin[9] = %d",in[9]);
}
