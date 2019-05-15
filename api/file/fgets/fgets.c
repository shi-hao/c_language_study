/*
 * char *fgets(char *s, int size, FILE *stream)
 *
 *	从stream中读取最多 size-1 个数据:
 *		1.遇到换行和结束符号时，函数返回，并在最末尾添加字符串结束符号'\0'
 *		2.如果读取行的字符数超过了size-1，函数也会返回，末尾添加结束符'\0',下次调用fgets继续  
 *		  读取文件内容，则从上次的位置继续读取内容，并不会换行！！
 *      3.读取内容包含换行符号
 *
 *	注意：
 *		1.linux下和win下的回车换行是不一样的，请注意。
 *		2.如果想逐行读取文件内的数据，使用fgets时，缓存的大小要足够大，就可以保证每次调用
 *		  读取的都是一整行数据，而不会发生错乱行!!!
 *  
 */

#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#include<string.h>

#define		buf_len    1024 

/*
 *read every line of the file
 */
int read_line(FILE* file, char* buf, int len){
	int row=0;
	while(fgets(buf, len, file)){
		int line_len = strlen(buf);

		//process one line
		printf("row %d has %lu char:%s", row++, strlen(buf), buf);
	}
}

/*
 * main()
 */
void main()
{
#define  filename    "cmd.txt"
	FILE* file;
	char buf[buf_len];

	/*打开文件-update mode reading and writing*/
	file = fopen(filename, "r");
	if(file <= 0)
	{
		printf("文件打开失败");
		return;
	}

	//read every line data
	read_line(file, buf, buf_len);

	/*关闭文件*/
	fclose(file);
}
