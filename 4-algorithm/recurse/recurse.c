#include<stdio.h>
#include<stdlib.h>

//递归解决问题的思路是大事化小，直至可以解决。
//编程实现很简单，函数自己调用自己。
//递归函数设计的关键是:何时递归，何时结束

//阶乘
long factorial(unsigned int i){
	printf("i = %d\n", i);
	if(i <= 1){
		return 1;
	}else{
		long res = i * factorial(i - 1);
		printf("i = %d\n", i);
		return(res);
	}
}

int main(){
	printf("factorial(%d) = %ld\n", 10, factorial(10));
}
