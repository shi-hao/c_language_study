#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/resource.h>

#include"mfseek.h"

/*
 *  switch the file descriptor to specific line using fseek()!
 *
 *  1. switch_line_init()
 *	2. switch_line()
 *	3. mfileInfo.file  //access the specific of the file 
 *	   mfileInfo.cur_max_line  //total line of the file
 *	4. switch_line_free
 */

struct fileInfo  mfileInfo={0,0,{0}};

//switch the file descriptor to the line_num line
int switch_line(unsigned int line_num){

	if(line_num > 0 && line_num <= mfileInfo.cur_max_line)
	{
		//switch to specific line
		fseek(mfileInfo.file, mfileInfo.lineTotal[line_num-1], SEEK_SET);
		return 0;
	}else{
		printf("\n line_num is out of range, current max line is %d\n", mfileInfo.cur_max_line);
		return -1;
	}
}

//read every line of a file 
static int load_file(FILE* file){
	char str[BUF_LEN]={0};
	int rowNum=1;

	while(fgets(str, BUF_LEN, file)){
		int line_len = strlen(str);
#if debug_print
		printf("row %d has %lu char:%s", rowNum, strlen(str), str);
#endif

		if(line_len > MAX_CHAR){
			printf("the characters number of this line is beyond the range\n");
			fclose(mfileInfo.file);
			return -1;
		}

		if(rowNum >= MAX_LINES){
			printf("\n line number is beyond the range \n");
			fclose(mfileInfo.file);
			return -1;
		}

		mfileInfo.lineTotal[rowNum] = line_len + mfileInfo.lineTotal[rowNum-1];
		mfileInfo.cur_max_line = rowNum;

		rowNum++;
	}
	return 0;
}

//init 
int switch_line_init(char* filename){
	int ret;
	//open file
	mfileInfo.file = fopen(filename, "r");
	if(mfileInfo.file <= 0)
	{
		printf("open file failed\n");
		return -1;
	}

	//load the file infomation
	ret = load_file(mfileInfo.file);

	return ret;
}

//free 
int switch_line_free(){

	fclose(mfileInfo.file);
	return 0;
}
