/*
 *数组和指针的比较
 */
#define print(data,format)  printf(#data"=%"#format"\n", data)
#include<stdio.h>
void main()
{
	int i;
	int array[2][3][4]={1};
	int *p,*r;
	char *q;
	/*指针*/
	int (*r1)[3][4]=array;
	int (*r2)[4]=array[0];
	int *r3=array[0][0];

	p=&i;
	r=&i;
	r++;

	print(r-p,d);

	printf("array[2][3][4]\n");

	/*测试1*//*指针偏移量*/
	print(&array,x);      
	print(&array+1,x);      

	print(array,x);      
	print(array+1,x);      

	print(array[0],x);      
	print(array[0]+1,x);      

	print(array[0][0],x);      
	print(array[0][0]+1,x);      

	/*测试2*/
	printf("---------------\n");
	print(&array[1][1][1],x);      
	print(&array[1][1][0],x);      
	print(array[1][1],x);      

	print(&array[1][1],x);      
	print(&array[1][0],x);      
	print(array[1],x);      

	print(&array[1],x);      
	print(&array[0],x);      
	print(array,x);      

	/*测试3*/
	print(r1[0][0][0],x);      
	print(*(*(r2+0*3+0)+0),x);      
	print(*(r3+0*3+0*4+0),x);      
}
