/*
 * 应用哈希表算法思路，实现数据库内的字符串检索!
 *
 * 判断输入的字符串是否在数据库中已经存在！
 *
 * hash collision：
 * using the linked list to solve the hash collision!
 *
 * performance:
 * database contains 14365003 lines and 156511269 chars.
 * --wc wordlist_2.txt
 *    14365003  14365003 156511269 wordlist_2.txt
 *
 * this program takes about 30 seconds to load the database.
 * --top
 *    3680 bleach    20   0  944684 932136   1244 S  89.7  5.7   0:29.80 hash.elf
 *
 * after loading the database, time complexity of algorithm is constant.
 * --O(t) = constant
 *
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/resource.h>

#include"mfgets.h"

#define  DEBUG_PRINT  0

/*
 *
 * using link list process the hash value collision!
 *
 * hash node struct
 *
 */
typedef struct hash_table_node{

	unsigned int node_len;//the len of hash node
	unsigned int line_num; //line number
	struct hash_table_node* next; 

}hash_table_node;

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
 * 字符串哈希后的哈希值作为数组的索引值，对应数组中的内容是字符串在文件中的行号。
 *
 * 1.对应哈希值的哈希表中，还没有哈希节点，直接插入新的节点，结束。
 * 2.对应哈希值的哈希表中，有节点，必须遍历所有的节点，看是否有相同字符串，如果有，直接退出，不用插入，
 *   如果全都不同，那么碰撞发生，在最后插入新的节点。
 */

//switch_line struct
struct fileInfo mfileInfo; 

int insert_node(hash_table_node table[], unsigned char * str, unsigned int row){

	char buff[SWITCH_MAX_CHAR];
	unsigned int hash;
	hash_table_node * cur;
	hash_table_node * pre;
	hash_table_node * node;
	unsigned int line_num;

	//hash string
	hash = hashpjw(str);

	pre = &table[hash];
	cur = table[hash].next;

	for(;cur!=NULL;){
		line_num = cur->line_num; 
		//fgets the line_num line
		switch_line_fgets(buff, SWITCH_MAX_CHAR, mfileInfo, line_num);

		buff[strlen(buff)-1] = 0;//将末尾的换行符号去掉
		if(strcmp(buff, str) == 0)
		{
#if DEBUG_PRINT
			printf("\n  same string previous %d:%s, current %d:%s", line_num,str, row, str);
#endif
			return -1;
		}else{
#if DEBUG_PRINT
			printf("\n  collision line previous %d:%s, current %d:%s", line_num, buff, row, str);
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
	pre->next = node;
	table[hash].node_len++;

#if DEBUG_PRINT
	printf("\n  insert  table[%d]=%d, %s", hash, row, str);
#endif

	return 0;
}

/*
 * look up  the data base whether the input string is in the data base.
 */
int lookup_hash_table(hash_table_node table[], unsigned char * str){
	char buff[SWITCH_MAX_CHAR];
	unsigned int hash;
	hash_table_node* cur;
	unsigned int line_num;
	int ret=-1;

	//hash string
	hash = hashpjw(str);

	cur = table[hash].next;
	for(;cur != NULL;){
		line_num = cur->line_num; 
		//fgets the line_num line
		switch_line_fgets(buff, SWITCH_MAX_CHAR, mfileInfo, line_num);
		buff[strlen(buff)-1] = 0;//将末尾的换行符号去掉
		if(strcmp(buff, str) == 0)
		{
			printf("\n %s is in the data base line %d", str, line_num);
			ret = 0;
		}else{
			printf("\n collision!  line %d:%s, %s", line_num, buff, str);
		}
		cur = cur->next;
	}

	if(ret)
		printf("\n %s is not in the data base \n", str);

	return ret;
}

//create hash table
int create_hash_table(FILE* file, hash_table_node hash_table[]){
	unsigned int row = 0;
	char buff[SWITCH_MAX_CHAR];

	while(fgets(buff, SWITCH_MAX_CHAR, file)){
		buff[strlen(buff) - 1] = 0;
		row++;
		insert_node(hash_table, buff, row);
	}
}

//hash table
hash_table_node hash_table[PRIME_TBLSIZE];

/*
 * main
 */
int main(int argc, char * argv[]){
#define filename "/home/bleach/airack/wordlist_2.txt"
//#define filename "./data_base.txt"

	FILE* data_base;
	char in_str[SWITCH_MAX_CHAR];

	if((data_base = fopen(filename,  "r")) == NULL){
		printf("\n open data base failed \n");
		return -1;
	}

	//switch line init
	if(switch_line_init(filename, &mfileInfo) < 0)
		return-1;

	//init the hash_table
	memset(hash_table, 0, PRIME_TBLSIZE * sizeof(hash_table_node));

	//load the string data base 
	create_hash_table(data_base, hash_table);

	printf("\n string data base load completes, please input a string for lookup \n");
	//check the input string
	while(scanf("%s", in_str)){
		lookup_hash_table(hash_table, in_str);
	}

	//free all
	fclose(data_base);
	switch_line_free(mfileInfo);
}
