#include<stdio.h>
#include <time.h> 

#include"mfgets.h"

//get the specific line
int mfgets(char* buf, int len, FILE* file, int line_num){
	int row=0;

	fseek(file, 0, SEEK_SET);
	while(fgets(buf, len, file)){
		row++;
		if(row == line_num)
			return 0;
	}
}


int main(int argc, char* argv[]){
#define  file_name  "/home/bleach/airack/wordlist_2.txt"
#define  buf_len    1024
#define  test_cnt   10

	char buf[buf_len];
	struct fileInfo mfileInfo;
	clock_t t; 
	double time_taken;
	FILE* file;
	int cnt;

	cnt = test_cnt;
	switch_line_init(file_name, &mfileInfo);
	t = clock(); 

	for(;cnt--;){
		switch_line_fgets(buf, buf_len, mfileInfo, 10000000);
		printf("%s", buf);
	}

	t = clock() - t; 
	time_taken = ((double)t)/CLOCKS_PER_SEC; 
	printf("switch_line_fgets() took %f seconds to execute \n", time_taken); 

	file = fopen(file_name, "r");
	t = clock(); 

	cnt = test_cnt;
	for(;cnt--;){
		mfgets(buf, buf_len, file, 10000000);
		printf("%s", buf);
	}

	t = clock() - t; 
	time_taken = ((double)t)/CLOCKS_PER_SEC; 
	printf("mfgets() took %f seconds to execute \n", time_taken); 

	switch_line_free(mfileInfo);
}
