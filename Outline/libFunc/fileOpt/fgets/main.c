/*
 * char *fgets(char *s, int size, FILE *stream)
 *
 * 从stream中读取最多 size-1 个数据，遇到换行和结束符号时，函数返回，并在最末尾添加字符串结束符号'\0',
 * 读出的内容包含换行符
 * 注意：linux下和win下的回车换行是不一样的，请注意。
 *
 */
#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#include<string.h>

#define len  56
typedef struct setting {
	unsigned char *ip;
	unsigned char *port;
	unsigned char *device;
	unsigned char *vpn_mode;
}setting, *setting_p;

#define   MAX_PARAM     2
#define   STAT_START    0
#define   STAT_PRE      1
#define   Token		    ' '

#define   buf_len       256


int parse_line(FILE* file){
	char str[buf_len]={0};
	int row=0;
	while(fgets(str, buf_len, file)){
		printf("row %d has %lu char:%s", row++, strlen(str), str);

		int state; 
		char *p[MAX_PARAM];
		int  line_len;
		char *in;
		char *start;
		int  pos;
		line_len = strlen(str) - 1;//减去末尾的换行符号0xa
		in = str;
		state = STAT_PRE;
		pos = 0;
		while(line_len--){
			if(state == STAT_PRE){
				if(*in != Token){
					start = in;
					state = STAT_START;
				}
				in++;
			}else if(state == STAT_START){
				if((*in == Token) || (line_len == 0)){
					int str_len;
					if(line_len == 0) str_len = in-start+1;
					else str_len = in-start;
					if(pos >= MAX_PARAM){
						printf("param num is out of range\n");
						break;
					}
					p[pos] =(unsigned char*)malloc(str_len + 1);
					memcpy(p[pos], start, str_len);
					*(p[pos] + str_len) = '\0';
					pos++;
					state = STAT_PRE;
				}
				in++;
			}
		}

		for(int i=0;i<MAX_PARAM;i++){
			if(p[i] != NULL){
				printf("param %d is %s\n", i, p[i]);
				free(p[i]);
				p[i] = NULL;
			}
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

	//parse one line data
	parse_line(file);

	/*关闭文件*/
	fclose(file);
}
