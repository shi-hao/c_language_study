/*
 ********************************************************************************
 * 文件同步:
 * 通常在写文件时，即调用了写文件的接口，被写入的内容并没有立刻被写入磁盘，
 * 存入文件，而是系统有一个缓存，会先将内容存入缓存，这种现象称为写延迟，写延迟
 * 是出于效率的考虑，频繁的写磁盘会增加系统运行负荷。
 * 其实这中现象很常见，比如平时编辑文档，内容也不是实时保存的，一般的编辑器都需要
 * 手动保存，写入磁盘，这是一个道理。
 *
 * 下面main函数执行后，使用ctrl+c中断程序运行，会发现文件的内容为空，这是为什么呢？
 * 因为fclose函数会作一次文件同步，ctrl+c意外中断程序执行，内容还在系统缓存中，并没有
 * 写入磁盘中，所以文件内容为空,有接口函数可以主动进行文件的同步。
 * 
 * 文件同步常用接口函数：
 * fflush()
 * fsync()
 *
 * fflush是libc.a中提供的方法，
 * fsync是系统提供的系统调用。
 *
 * 2.原形
 * fflush接受一个参数FILE *.
 * fflush(FILE *);
 *
 * fsync接受的是一个Int型的文件描述符。
 * fsync(int fd);
 *
 * 3.功能
 * fflush:是把C库中的缓冲调用write函数写到磁盘[其实是写到内核的缓冲区]。
 *
 * fsync：是把内核缓冲刷到磁盘上。
 *
 * c库缓冲-----fflush---------〉内核缓冲--------fsync-----〉磁盘
 ***********************************************************************************
 */

#include<stdio.h>
#include<stdlib.h>


/*
 * 功能  ：格式化读取文件的一行数据，不包括换行符
 * 返回值：一行数据的字节数 
 *         >0 读取到的字节数 
 *         =0 空行，没有内容，只有换行符
 *         <0 文件结束，缓存大小错误
 * 参数： FILE* file  文件指针 
 *        char* format 读取数据的格式，参考fscanf（）
 *        char buf[]   读取数据的存储缓存 
 *        int  bufSize 缓存buf[]的大小
 */
int myfscanf(FILE* file, char* format, char buf[], int bufSize)
{
	int cnt=0;

	if(bufSize<1)
		return -1;//缓存大小错误 

	cnt=0;
	fscanf(file,format,buf+cnt);

	while(feof(file)!=1){

		if((buf[cnt]=='\n') || (buf[cnt]=='\r')) //文件换行符，'\n' '\r'
		{
			buf[cnt]='\0';
			return cnt;
		}

		cnt++;
		if(cnt>=bufSize)//判断缓存大小  
			return bufSize;

		fscanf(file,format,buf+cnt);
	}

	return -1;//文件结束返回  
}

void main()
{
	FILE* file;
	FILE* fileW;
	int pre[200], cur[6], fut[6];
	int cnt;
	char str[100]={0};

	/*打开文件-update mode reading and writing*/
	fileW = fopen("dataW.txt", "a+");
	if(fileW == 0)
	{
		printf("文件打开失败");
		return;
	}
	while(1){
		//格式化写文件
		fprintf(fileW,"%d\n",666);
		printf("\nwrite\n");

#if 1
		//文件同步 
		fflush(fileW);
		fsync(fileW);
#endif
		sleep(1);
	}

	/*关闭文件*/
	fclose(fileW);
}
