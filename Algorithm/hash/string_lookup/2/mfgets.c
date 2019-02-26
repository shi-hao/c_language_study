#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/resource.h>

#include"mfgets.h"

/*
 *  fgets the specific line!!
 *
 *	1. switch_line_init()
 *
 *	2. switch_line_fgets()
 *
 *	3. switch_line_free()
 *
 *  struct fileInfo{
 *		FILE* file; //the file descriptor at the specific line of the file
 *		unsigned int cur_max_line; //the maximum line of the file
 *		unsigned int lineTotal[];//storing the total char number of all previous lines
 *	}
 */


//switch the file descriptor to the line_num line
static int switch_line(struct fileInfo* mfileInfo, unsigned int line_num){

	if(line_num > 0 && line_num <= mfileInfo->cur_max_line)
	{
		//switch to specific line
		fseek(mfileInfo->file, mfileInfo->lineTotal[line_num-1], SEEK_SET);
		return 0;
	}else{
		printf("\n line_num is out of range, current max line is %d\n", mfileInfo->cur_max_line);
		return -1;
	}
}

//fgets the line line_num
char* switch_line_fgets(char *s, int size, struct fileInfo* mfileInfo, unsigned int line_num){
	char* ret;

	//switch line
	switch_line(mfileInfo, line_num);

	//fgets
	ret = fgets(s, size, mfileInfo->file);

	return ret;
}

//read every line of a file 
static int switch_line_load_file(struct fileInfo* mfileInfo){
	char str[SWITCH_BUF_LEN]={0};
	int rowNum=1;

	while(fgets(str, SWITCH_BUF_LEN, mfileInfo->file)){
		int line_len = strlen(str);
#if SWTICH_DEBUG_PRINT
		printf("row %d has %lu char:%s", rowNum, strlen(str), str);
#endif

		if(line_len > SWITCH_MAX_CHAR){
			printf("the characters number of this line is beyond the range\n");
			fclose(mfileInfo->file);
			return -1;
		}

		if(rowNum >= SWITCH_MAX_LINES){
			printf("\n line number is beyond the range \n");
			fclose(mfileInfo->file);
			return -1;
		}

		mfileInfo->lineTotal[rowNum] = line_len + mfileInfo->lineTotal[rowNum-1];
		mfileInfo->cur_max_line = rowNum;

		rowNum++;
	}
	return 0;
}

//init 
int switch_line_init(char* filename, struct fileInfo * mfileInfo){
	int ret;
	printf("\nswitch_line_init, max line:%ld, max char one line:%ld\n", SWITCH_MAX_LINES, SWITCH_MAX_CHAR);

	//open file
	mfileInfo->file = fopen(filename, "r");
	if(mfileInfo->file <= 0)
	{
		printf("open file failed\n");
		return -1;
	}

	//load the file infomation
	ret = switch_line_load_file(mfileInfo);

	return ret;
}

//free 
int switch_line_free(struct fileInfo* mfileInfo){

	fclose(mfileInfo->file);
	return 0;
}
