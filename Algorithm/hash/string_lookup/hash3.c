#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

/*
 * 使用哈希表的算法思路，实现数据库内的字符串检索
 *
 * 1.读取存储在文件中的字符串，产生一个哈希表。
 * 2.读取输入的数据，计算哈希值，判断库中是否有此字符串。
 *
 * 碰撞：
 * 哈希函数没有处理碰撞的情况。
 */


//////////////////////////////////////////////////////////////////////
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

#define		MAX_char    1024  //max character number of one line
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


#define PRIME_TBLSIZE  4096
#define MAX_char 1024
#define empty_flag     0 

//字符串哈希函数
unsigned int hashpjw(const void *key){
	const char *ptr;
	unsigned int  val;

	//hash the key by performing a number of bit operations on it 
	val = 0;
	ptr = key;

	while(*ptr != '\0')
	{
		unsigned int tmp;
		val = (val << 4) + (*ptr);

		if(tmp = (val & 0xf0000000))
		{
			val = val ^ (tmp >> 24);
			val = val ^ tmp;
		}
		ptr++;
	}

	return val % PRIME_TBLSIZE;
}

//哈希表中插入哈希值
//字符串哈希后的哈希值作为数组的索引值，对应数组中的内容是字符串在文件中的行号
int insert_node(FILE* file, unsigned int* table, unsigned char * str, unsigned int row){

	char buff[MAX_char];
	unsigned int hash;

	hash = hashpjw(str);

	if( table[hash] == empty_flag){
		table[hash] = row;
		printf("\n  insert  table[%d]=%d, %s", hash, table[hash], str);
		return 1;
	}else{
		switch_line(file, table[hash]);
		fgets(buff, MAX_char, file);
		buff[strlen(buff)-1] = 0;
		if(strcmp(buff, str) == 0)
			printf("\n  same string  %d:%d", table[hash], row);
		else
			printf("\n  collision  table[%d]=%d, %s", hash, table[hash], str);
		switch_line(file, row+1);
		return 0;
	}
}

int lookup_hash_table(FILE* file, unsigned int* table, unsigned char * str){
	char buff[MAX_char];
	unsigned int hash;
	hash = hashpjw(str);

	if( table[hash] == empty_flag){
		printf("\n %s is not in the data base \n", str);
		return 0;
	}else{
		switch_line(file, table[hash]);
		fgets(buff, MAX_char, file);
		buff[strlen(buff)-1] = 0;
		if(strcmp(buff, str) == 0)
			printf("\n  %s is in the data base hash[%d]:%d", str, hash,  table[hash]);
		else
			printf("\n  collision  table[%d]=%d:%s, %s", hash, table[hash], buff, str);
		return 1;
	}
}

//create the hash table
int create_hash_table(FILE* file, unsigned int* hash_table){
	unsigned int row = 0;
	char buff[MAX_char];

	while(fgets(buff, MAX_char, file)){
		buff[strlen(buff) - 1] = 0;
		row++;
		insert_node(file, hash_table, buff, row);
	}
}



/*
 * main
 */
int main(int argc, char * argv[]){
#define str_size  6

	FILE* data_base;

	unsigned int  tmp;
	unsigned int  hash_table[PRIME_TBLSIZE];
	int ret;

	char inpute_str[MAX_char];

	if((data_base = fopen("data_base.txt", "a+")) == NULL){
		printf("\n open data base failed \n");
		return -1;
	}

	//load the file
	load_file(data_base);

	//init the hash_table
	memset(hash_table, empty_flag, PRIME_TBLSIZE * sizeof(unsigned int));

	//load the string data base 
	create_hash_table(data_base, hash_table);

	printf("\n please inpute a string \n");
	//check the input string
	while(scanf("%s", inpute_str)){
		lookup_hash_table(data_base, hash_table, inpute_str);
	}

	fclose(data_base);
	printf("\n exit \n");
}
