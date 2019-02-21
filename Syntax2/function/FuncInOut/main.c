/*
 * 测试函数的传入值和返回值的方式
 *1)传入大量数据，使用指针，强烈建议使用const修饰，防止数据破坏和区分2）这
 种情况
 *2)返回结果，使用指针。
 */
#include<stdio.h>
typedef struct member{
	char name;
	int  age;
	int class;
}member, *Pmem;

/*
 *1）使用const修饰传入数据的指针
 *2) 传入指针 
 */
int ProData(int const data[], int size, int *p)
{
	printf("data[0]=%d\n",data[0]);
	*p = 0;
	return 0;
}

/*传入关联性的大量数据，使用结构体，传入指针*/
void ProData2(const Pmem p)
{
	printf("nothing!\n");
}

int main()
{
	int data[5]={1,2,3,4,5};
	int p=8;
	member sh;
	ProData(data,5,&p);
	ProData2(&sh);
	return 1;
}
