#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define PRIME_TBLSIZE  1024

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

void insert_node(unsigned char ** table, unsigned char * str){

	unsigned int tmp;

	tmp = hashpjw(str);

	if( table[tmp] == 0){
		table[tmp] = str;
	}else{
		printf("\n  collision \n");
	}
}


int main(int argc, char * argv[]){
#define str_size  6

	unsigned int tmp;
	unsigned char * hash_table[PRIME_TBLSIZE];

	unsigned char * str[str_size]={
		"i am bob",
		"you are dady",
		"are you bob",
		"let us do it",
		"shihao",
		"ting"
	};

	if(argc < 2){
		printf("\n inpute the hash string \n");
		return -1;
	}

	memset(hash_table, 0, 256 * sizeof(unsigned char*));

	for(tmp=0;tmp<str_size;tmp++){
		insert_node(hash_table, str[tmp]);
	}

	tmp = hashpjw(argv[1]);
	printf("\n %s : %s\n", argv[1], hash_table[hashpjw(argv[1])]);

}
