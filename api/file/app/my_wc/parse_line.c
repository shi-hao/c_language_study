/*
 * char *fgets(char *s, int size, FILE *stream)
 *
 * 从stream中读取最多 size-1 个数据，遇到换行和结束符号时，函数返回，并在最末尾
 * 添加字符串结束符号'\0',读出的内容包含换行符
 *
 * 注意：linux下和win下的回车换行是不一样的，请注意。
 * 
 * This project read every line of a file then parse them!
 *
 */
#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#include<string.h>

#define trace_print(STR)  (printf("file <%s> in line <%d> in function <%s>:<%s>",__FILE__, __LINE__, __FUNCTION__, STR))


unsigned int total_char;
unsigned int total_word;
unsigned int total_line;

static int parse_line(char* str){
#define    Token_Delimiter		   ' '

	char* in = str;
	int text_len = 0;
	int pos = 0;
	int line_len = strlen(str);

	for(;line_len>0;in++){
		//length--
		line_len--;

		//cal the text char len
		if((*in != 0x0d) && (*in != 0x0a) && (*in != Token_Delimiter) ){
			text_len++;
			if(line_len > 0)
				continue;
		}

		//
		if(text_len > 0){
			total_word++;
			total_char+=text_len;
		}
		text_len = 0;

		if(*in == 0x0a){
			total_line++;
		}
	}
} 


/*
 * main()
 */
void main()
{
#define   filename    "cmd.txt"
#define   buf_len     1024  //每行的字符数目不能超过此值，否则解析会发生错误

	FILE* file;
	char buf[buf_len];

	/*打开文件-update mode reading and writing*/
	file = fopen(filename, "r");
	if(file <= 0)
	{
		printf("文件打开失败");
		return;
	}

	while(fgets(buf, buf_len, file)){
		printf(" %lu char:%s",  strlen(buf), buf);
		parse_line(buf);
	}

	printf("line:%d, word:%d, char:%d", total_line, total_word, total_char);

	/*关闭文件*/
	fclose(file);
}
