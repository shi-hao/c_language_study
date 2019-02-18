/*
 * char *fgets(char *s, int size, FILE *stream)
 *
 *	从stream中读取最多 size-1 个数据:
 *		1.遇到换行和结束符号时，函数返回，并在最末尾添加字符串结束符号'\0'
 *		2.如果读取行的字符数超过了size-1，函数也会返回，末尾添加结束符'\0'
 *      3.读取内容包含换行符号
 *
 *	注意：linux下和win下的回车换行是不一样的，请注意。
 *
 */

#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#include<string.h>

//max characters number of one line
#define		MAX_char    20
#define		buf_len     (MAX_char + 2)

int read_line(FILE* file){
	char str[buf_len]={0};
	int row=0;
	while(fgets(str, buf_len, file)){
		int line_len = strlen(str);
		printf("row %d has %lu char:%s", row++, strlen(str), str);

		if(line_len > MAX_char){
			printf("the characters number of this line is beyond the range\n");
			break;
		}
	}
}

/*
 * main()
 */
void main()
{
#define  filename    "cmd.txt"
	FILE* file;

	/*打开文件-update mode reading and writing*/
	file = fopen(filename, "r");
	if(file <= 0)
	{
		printf("文件打开失败");
		return;
	}

	//read one line data
	read_line(file);

	/*关闭文件*/
	fclose(file);
}
