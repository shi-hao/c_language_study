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
#define PRIME_TBLSIZE  1024
#define MAX_CHAR_COUNT 1024
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
int insert_node(unsigned int* table, unsigned char * str, long row){

	unsigned int tmp;

	tmp = hashpjw(str);

	if( table[tmp] == empty_flag){
		table[tmp] = row;
		printf("\n  insert  table[%d]=%d:%s", tmp, table[tmp], str);
		return 1;
	}else{
		printf("\n  collision  table[%d]=%d:%s", tmp, table[tmp], str);
		return 0;
	}
}

/*
 * 功能  ：格式化读取文件的一行数据，不包括换行符
 * 返回值：一行数据的字节数 
 *         >0 读取到的字节数 
 *         =0 空行，没有内容，只有换行符
 *         <0 文件结束，缓存大小错误
 * 参数： FILE* file  文件指针 
 *        char* format 读取数据的格式，参考fscanf（）
 *        char buf[]   读取数据的存储缓存 
 *        int  bufSize 缓存buf[]的大小
 */
int mmyfscanf(FILE* file, char* format, char buf[], int bufSize)
{
	int cnt=0;
	if(bufSize < 1)
		return -1;

	while(1){

		if(cnt  >= bufSize)//判断缓存大小  
			return bufSize;

		fscanf(file,format,buf+cnt);

		if(feof(file) == 1)
		{
			return -1;
		}

		if((buf[cnt]=='\n') || (buf[cnt]=='\r')) //文件换行符，'\n' '\r'
		{
			buf[cnt]='\0';
			return cnt;
		}

		cnt++;
	}
}

int main(int argc, char * argv[]){
#define str_size  6

	FILE* data_base;

	char buffer[MAX_CHAR_COUNT];
	unsigned int  tmp;
	unsigned int  hash_table[PRIME_TBLSIZE];
	int ret;

	char inpute_str[MAX_CHAR_COUNT];

	if((data_base = fopen("data_base.txt", "a+")) == NULL){
		printf("\n open data base failed \n");
		return -1;
	}

	//load the string data base 
	memset(buffer, 0, MAX_CHAR_COUNT * sizeof(char));
	memset(hash_table, empty_flag, PRIME_TBLSIZE * sizeof(unsigned int));
	unsigned int row=0;
	while(mmyfscanf(data_base,"%c",buffer,MAX_CHAR_COUNT-1) >= 0){
		row++;
		insert_node(hash_table, buffer, row);
		memset(buffer, 0, MAX_CHAR_COUNT * sizeof(char));
	}

	printf("\n");
	//check the input string
	while(scanf("%s", inpute_str)){
		if(insert_node(hash_table, inpute_str, row))
		{
			printf("\n input string is NOT in the data base, write it into data base \n");

			//write the string into the data base
			if(fprintf(data_base,"%s\n",inpute_str) <= 0)
				printf("\n write the string to the data base failed \n");
			fflush(data_base);
			//fsync(data_base);
			row++;
		}
		else
		{
			printf("\n Collision: same string in the data_base OR different strings have same hash value! \n");
		}
	}

	fclose(data_base);
	printf("\n exit \n");
}
