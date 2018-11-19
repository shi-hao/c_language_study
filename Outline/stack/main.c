/*
 *测试stack的大小
 *
 *首先使用指令 ulimit -s 查看堆栈默认的大小。
 *运行程序，根据count值来推算堆栈大小。
 */
#include<stdio.h>
#include<sys/resource.h>
/*递归，测试stack的大小*/
void Recur()
{
	static int count = 0;
	char data[1024]={0};

	count++;
	printf("count = %d\n",count);

	Recur();	 
}

/*大数组*/
void HighStack()
{
	char data[1024*1024*10]={0};
}

char data_glo[1024*1024*10]={0};
/*测试*/
void main()
{
	//char data[1024*1024*10]={0};
	struct rlimit lmt;
	//Recur();
	//HighStack();
	getrlimit(RLIMIT_STACK,&lmt);
	printf("rlim_cur=%luMB rlim_max=%luMB\n",lmt.rlim_cur/1024/1024, lmt.rlim_max/1024/1024);
	printf("......\n");
}
