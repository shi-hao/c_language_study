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


typedef struct _sys_setting_st_{
	char* ip;
	char* port;
	char* device;
	char* id;
	char* org;
}sys_setting_st;


static int parse_cmd(char*p[], sys_setting_st* setting){
	if(p[0] == NULL)
		return -1;

	if(strcmp(p[0], "ip")==0 && p[1]){
		setting->ip = p[1];
	}else if(strcmp(p[0], "port")==0 && p[1]){
		setting->port = p[1];
	}else if(strcmp(p[0], "device")==0 && p[1]){
		setting->device = p[1];
	}
}

static int parse_line(char* str, char* p[], int param_num){
#define    Token_Delimiter		   ' '
#define    Token_Comment           '#'

#ifdef _WIN32
	int line_len = strlen(str) - 2;//减去末尾的换行符号
#else
	int line_len = strlen(str) - 1;//减去末尾的换行符号
#endif

	char* in = str;
	int text_len = 0;
	int pos = 0;

	for(;line_len>0;in++){
		//len plus 
		line_len--;

		//cal the text char len
		if((*in != Token_Comment) && (*in != Token_Delimiter)){
			text_len++;
			if(line_len > 0)
				continue;
		}

		//Token_Comment or Token_Delimiter or last char
		if(text_len > 0){
			printf("param len = %d \n", text_len);
#if 0
			if(pos<param_num){
				if((p[pos] = (char*)malloc(text_len+1)) <= 0){
					trace_print("malloc error\n");
					return -1;
				}
				memcpy(p[pos], in-text_len, text_len);
				*(p[pos]+text_len) = '\0';
				pos++;
			}
#endif
		}
		text_len = 0;

		if(*in == Token_Comment){
			return -1;
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
#define   max_param   2

	FILE* file;
	char buf[buf_len];
	char* p[max_param];

	sys_setting_st my_setting;

	/*打开文件-update mode reading and writing*/
	file = fopen(filename, "r");
	if(file <= 0)
	{
		printf("文件打开失败");
		return;
	}

	memset(p, 0, sizeof(char*)*max_param);

	while(fgets(buf, buf_len, file)){
		printf(" %lu char:%s",  strlen(buf), buf);
		parse_line(buf, p, max_param);
#if 0
		parse_cmd(p, &my_setting);
#endif
	}

	/*关闭文件*/
	fclose(file);
}
