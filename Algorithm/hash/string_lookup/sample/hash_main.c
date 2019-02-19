#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/resource.h>

#include"mfseek.h"

/*
 * 应用哈希表算法思路，实现数据库内的字符串检索!
 *
 * 判断输入的字符串是否在数据库中已经存在！
 *
 * 碰撞：
 * 使用链表处理哈希值碰撞问题!!
 *
 */

/*
 *
 *using link list process the hash value collision!
 *
 */
typedef struct hash_table_node{

	unsigned int line_num; //line number
	struct hash_table_node * next; 

}hash_table_node;

typedef struct hash_table_head{

	unsigned len;//the len of hash node
	hash_table_node * next;

}hash_table_head;

//create a hash node
hash_table_node* create_hash_node(){

	return((hash_table_node* )malloc(sizeof(hash_table_node)));

}

#define   PRIME_TBLSIZE   (1024 * 1024 * 26)

//string hash function
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

/*
 * hash table insert function
 * 字符串哈希后的哈希值作为数组的索引值，对应数组中的内容是字符串在文件中的行号
 * 1.对应哈希值的哈希表中，还没有哈希节点，直接插入新的节点，结束。
 * 2.对应哈希值的哈希表中，有节点，必须遍历所有的节点，看是否有相同字符串，如果有，直接退出，不用插入，
 *   如果全都不同，那么碰撞发生，在最后插入新的节点。
 */
int insert_node(hash_table_head table[], unsigned char * str, unsigned int row){

	char buff[MAX_CHAR];
	unsigned int hash;
	hash_table_node * cur;
	hash_table_node * pre;
	hash_table_node * node;
	unsigned int line_num;

	hash = hashpjw(str);
	cur = table[hash].next;

	for(;cur != NULL;){
		line_num = cur->line_num; 
		switch_line(line_num);
		fgets(buff, MAX_CHAR, mfileInfo.file);
		buff[strlen(buff)-1] = 0;//将末尾的换行符号去掉
		if(strcmp(buff, str) == 0)
		{
#if debug_print
			printf("\n  same string %s, %d:%d", str, line_num, row);
#endif
			return -1;
		}else{
#if debug_print
			printf("\n  collision line %d:%s, %d:%s", line_num, buff, row, str);
#endif
		}
		pre = cur;
		cur = cur->next;
	}

	//create hash node
	node = create_hash_node();
	node->line_num = row;
	node->next = NULL;

	//insert the hash node to the table
	if(table[hash].len == 0){
		table[hash].next = node;
	}else{
		pre->next = node;
	}
	table[hash].len++;

#if debug_print
	printf("\n  insert  table[%d]=%d, %s", hash, row, str);
#endif

	return 0;
}

int lookup_hash_table(hash_table_head table[], unsigned char * str){
	char buff[MAX_CHAR];
	unsigned int hash;
	hash_table_node* cur;
	unsigned int line_num;

	hash = hashpjw(str);
	cur = table[hash].next;

	for(;cur != NULL;){
		line_num = cur->line_num; 
		switch_line(line_num);
		fgets(buff, MAX_CHAR, mfileInfo.file);
		buff[strlen(buff)-1] = 0;//将末尾的换行符号去掉
		if(strcmp(buff, str) == 0)
		{
			printf("\n  %s is in the data base line %d", str, line_num);
			return -1;
		}else{
			printf("\n collision!  line %d:%s, %s", line_num, buff, str);
		}
		cur = cur->next;
	}
	printf("\n %s is not in the data base \n", str);

	return 0;
}

//create hash table
int create_hash_table(FILE* file, hash_table_head hash_table[]){
	unsigned int row = 0;
	char buff[MAX_CHAR];

	while(fgets(buff, MAX_CHAR, file)){
		buff[strlen(buff) - 1] = 0;
		row++;
		insert_node(hash_table, buff, row);
	}
}


/*
 * set the stack size
 */
int setStackSize(unsigned int stack_size){
	const rlim_t kStackSize = stack_size * 1024 * 1024;   // min stack size = stack_size MB
	struct rlimit rl;
	int result;

	result = getrlimit(RLIMIT_STACK, &rl);
	if (result == 0)
	{
		if (rl.rlim_cur < kStackSize)
		{
			rl.rlim_cur = kStackSize;
			result = setrlimit(RLIMIT_STACK, &rl);
			if (result != 0)
			{
				printf("setrlimit returned result = %d\n", result);
			}
		}
	}
}


//hash table
hash_table_head hash_table[PRIME_TBLSIZE];

/*
 * main
 */
int main(int argc, char * argv[]){
#define filename "/home/bleach/airack/wordlist_2.txt"

	FILE* data_base;
	char in_str[MAX_CHAR];

	if((data_base = fopen(filename,  "r")) == NULL){
		printf("\n open data base failed \n");
		return -1;
	}

	//load the file
	if(switch_line_init(filename) < 0)
		return-1;

	//init the hash_table
	memset(hash_table, 0, PRIME_TBLSIZE * sizeof(hash_table_head));

	//load the string data base 
	create_hash_table(data_base, hash_table);

	printf("\n string data base load completes, please inpute a string for check\n");
	//check the input string
	while(scanf("%s", in_str)){
		lookup_hash_table(hash_table, in_str);
	}

	fclose(data_base);
	printf("\n exit \n");
}
