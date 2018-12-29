/*
 *char *fgets(char *s, int size, FILE *stream)
 *
 *从stream中读取最多 size-1 个数据，遇到换行和结束符号时，函数返回，并在最末尾添加字符串结束符号'\0',
 *测试发现，添加的是0xa
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

#define   MAX_PARAM   2
#define   STAT_START  0
#define   STAT_PRE    1
#define   Token		   ' '

#define buf_len 256
void main()
{
	FILE* file;
	int pre[200], cur[6], fut[6];
	int cnt;
	char str[buf_len]={0};
	char* p[MAX_PARAM];

	/*打开文件-update mode reading and writing*/
	file = fopen("cmd.txt", "r");
	if(file <= 0)
	{
		printf("文件打开失败");
		return;
	}


	//读取一行数据
	while(fgets(str, buf_len, file)){
		printf("%lu %s",strlen(str),str);
		//		for(int i=0;i<buf_len;i++)
		//			printf(" %#x ", str[i]);

		//		char* string, *found;
		//		string = strdup(str);
		//		while((found = strsep(&string, " ")) != NULL){
		//			printf("%lu : %s\n", strlen(found), found);
		//		}

		int state; 
		char *p[MAX_PARAM];
		int  line_len;
		char *in;
		char *start;
		int  pos;
		line_len = strlen(str) - 1;
		in = str;
		state = STAT_PRE;
		pos = 0;
		while(line_len--){
			if(pos >= MAX_PARAM){
				printf("param num is out of range\n");
				break;
			}

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
					p[pos] =(unsigned char*)malloc(str_len + 1);
					memcpy(p[pos], start, str_len);
					*(p[pos] + str_len) = '\0';
					pos++;
					state = STAT_PRE;
				}
				in++;
			}
		}

		if((p[0] != NULL) && (p[1] != NULL))
			printf("%s %s\n", p[0], p[1]);
		free(p[0]);
		free(p[1]);
		p[0] = NULL;
		p[1] = NULL;
	}

	/*关闭文件*/
	fclose(file);
}
