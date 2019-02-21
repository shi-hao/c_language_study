/*
 *struct pointer
 */

#include<stdio.h>
#include<stdlib.h>

/*
 *定义结构体指针的4种方法
 */
struct student{
	int num;
	char name[20];
	char sex;
	int age;
	float score;
}*pstudent;/*(1)直接定义法*/
struct student *pstudent;/*(2)间接定义*/

/*(3)缺省定义*/
struct{
	int num;
}*ptest;

/*(4)使用typedef*/
typedef struct teacher{
	int num;
	char name[20];
	char sex;
	int age;
}teacher, *psTeacher;//结构体指针
psTeacher PTeacher;//定义结构体指针
teacher * PTeacher;

int main(){
	//定义结构
	struct st{
		int len;
		unsigned char* data;
	};
	struct st my_st = {10, "i am struct my_st"};
	printf("my_st.len = %d\n", my_st.len );
	printf("my_st.data = %s\n", my_st.data );

	struct st * st_pointer_var;
	st_pointer_var = &my_st;
	printf("(*st_pointer_var).len = %d\n", (*st_pointer_var).len );

	//结构体指针引用成员的独特之处，推荐此方法
	printf("st_pointer_var->len = %d\n", st_pointer_var->len );
	printf("st_pointer_var->data = %s\n", st_pointer_var->data );
}
