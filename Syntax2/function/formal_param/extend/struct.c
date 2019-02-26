/*
 * 结构体作为函数形参
 */
#include<stdio.h>
#include<stdlib.h>


typedef struct person{
	int age;
	int class;
	int number;
}person;


void function(person me){
	me.age+=1;
	me.class-=1;
	me.number+=2;

	printf("\nme.age=%d, me.class=%d, me.number=%d in %s \n", me.age, me.class, me.number, __func__);
}


int main(){
	person me={20, 4, 2};
	printf("\nme.age=%d, me.class=%d, me.number=%d in %s \n", me.age, me.class, me.number, __func__);
	function(me);
}
