#include<stdio.h>
#include<stdlib.h>

//递归解决问题的思路是大事化小，直至可以解决。
//编程实现很简单，函数自己调用自己。
//递归函数设计的关键是如何设置结束条件。

//阶乘
long factorial(unsigned int i){
	if(i <= 1){
		return 1;
	}else{
		return(i * factorial(i - 1));
	}
}

int main(){
	printf("factorial(%d) = %ld\n", 10, factorial(10));
}
