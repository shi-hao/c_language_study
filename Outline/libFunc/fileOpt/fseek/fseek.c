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
 *
 *	int fseek(FILE *stream, long offset, int whence);
 *  SEEK_SET, SEEK_CUR, or SEEK_END
 * 
 *	this code switchs the file descriptor to specific line using fseek!!!!
 *
 */

#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#include<string.h>


#define     MAX_line    100    //max line of a file
struct _fileInfo_{
	unsigned int   cur_max_line;       //current max line number
	unsigned int   lineTotal[MAX_line];//total char of every line
};
struct _fileInfo_  mfileInfo={0,{0}};


//switch the file descriptor to the line_num line
int switch_line(FILE* file, unsigned int line_num){

	if(line_num > 0 && line_num <= mfileInfo.cur_max_line)
	{
		//switch to specific line
		fseek(file, mfileInfo.lineTotal[line_num-1], SEEK_SET);
		return 0;
	}else{
		printf("line_num error \n");
		return -1;
	}
}

#define		MAX_char    100  //max character number of one line
#define		buf_len     (MAX_char + 2)  //buf len
//read every line of a file 
int load_file(FILE* file){
	char str[buf_len]={0};
	int rowNum=1;
	fseek(file, 0, SEEK_SET);
	while(fgets(str, buf_len, file)){
		int line_len = strlen(str);
		printf("row %d has %lu char:%s", rowNum, strlen(str), str);

		if(line_len > MAX_char){
			printf("the characters number of this line is beyond the range\n");
			fseek(file, 0, SEEK_SET);
			return -1;
		}

		mfileInfo.lineTotal[rowNum] = line_len + mfileInfo.lineTotal[rowNum-1];
		mfileInfo.cur_max_line = rowNum;

		rowNum++;
	}
	fseek(file, 0, SEEK_SET);
	return 0;
}
/////////////////////////////////////////////////////////////////////////////


/*
 * main()
 */
void main(int argc, char* argv[])
{
#define  filename    "txt_base.txt"
	FILE* file;
	char str[buf_len]={0};
	unsigned int line_num; 

	if(argc >= 2)
		line_num = atoi(argv[1]);
	else
		line_num= 3;

	/*打开文件-update mode reading and writing*/
	file = fopen(filename, "r");
	if(file <= 0)
	{
		printf("文件打开失败");
		return;
	}

	//read every line data
	load_file(file);

	//switch to some line 
	switch_line(file, line_num);

	//read the line_num line
	if(fgets(str, buf_len, file))
		printf("line %d is :%s", line_num,  str);

	/*关闭文件*/
	fclose(file);
}
