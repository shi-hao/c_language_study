#include<stdio.h>
#include<stdlib.h>

int main(){

	//定义结构
	struct st{
		int len;
		unsigned char* data;
	};

	struct st my_st;

	//结构体数组
	struct st st_array[10];

	//结构体指针数组
	struct st * st_pointer_array[10];
	
	//结构体指针变量，此种方式和 结构体数组 类似，相当于定义了10个结构体变量
	struct st * st_pointer_var;
	int capacity = 10;
	st_pointer_var = (struct st*)malloc(sizeof(struct st) * capacity);

	//赋值
	st_pointer_array[0] = &my_st;//结构体指针数组的每个元素都是结构体指针变量

	st_array[0] = my_st;//结构体数组的每个元素都是结构体变量

	st_pointer_var[0] = my_st;//
	*(st_pointer_var+0) = my_st;//以上两种方法一样，给结构体变量的内容赋值


	printf("\n st_pointer_array[0]->len = %d\n",st_pointer_array[0]->len);
	printf("\n st_array[0].len =  %d\n", st_array[0].len);
	printf("\n st_pointer_var->len = %d\n", st_pointer_var->len );


	printf("\n sizeof(st_array)=%ld\n",sizeof(st_array));
	printf("\n sizeof(st_pointer_array)=%ld\n",sizeof(st_pointer_array));
}
