#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/resource.h>

#include"mfseek.h"

/*
 *  switch the file descriptor to specific line using fseek()!
 *
 *	1. switch_line_init()
 *
 *	2. switch_line()
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
int switch_line(struct fileInfo* mfileInfo, unsigned int line_num){

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

//read every line of a file 
static int load_file(struct fileInfo* mfileInfo){
	char str[BUF_LEN]={0};
	int rowNum=1;

	while(fgets(str, BUF_LEN, mfileInfo->file)){
		int line_len = strlen(str);
#if debug_print
		printf("row %d has %lu char:%s", rowNum, strlen(str), str);
#endif

		if(line_len > MAX_CHAR){
			printf("the characters number of this line is beyond the range\n");
			fclose(mfileInfo->file);
			return -1;
		}

		if(rowNum >= MAX_LINES){
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
	//open file
	mfileInfo->file = fopen(filename, "r");
	if(mfileInfo->file <= 0)
	{
		printf("open file failed\n");
		return -1;
	}

	//load the file infomation
	ret = load_file(mfileInfo);

	return ret;
}

//free 
int switch_line_free(struct fileInfo * mfileInfo){

	fclose(mfileInfo->file);
	return 0;
}
