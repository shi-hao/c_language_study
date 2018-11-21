#include<stdio.h>
#include<stdlib.h>


#define capacity_len  10

typedef struct _buffer_ {
	int capacity;
	int len;
	int offset;
	char * data;
}buffer, *buffer_p;

typedef struct _buffer_set_ {

	buffer in;
	buffer out;

	buffer_p data;

} buffer_set, *buffer_set_p;


int my_malloc(buffer_p p){

	p->capacity = capacity_len;
	p->data = (char *)malloc(sizeof(char) * p->capacity);
	if(p->data == 0)
		return 1;
	p->len = 0;
	p->offset = 0;

	return 0;
}

int init_buffer_set(buffer_set_p p){
	
	int ret;
	
	ret = my_malloc(&p->in);
	if(ret) return ret;
	my_malloc(&p->out);
	if(ret) return ret;
}

int process_data(buffer_p p){

	for(int tmp=0;tmp < p->capacity;tmp++){
		*(p->data+tmp) = tmp;
		p->len++;
	}


}

int printf_data(buffer_p p){

	for(int tmp=0;tmp< p->len;tmp++){
		printf("\n %#.8x\n", (p->data)[tmp]);
	}

}


int main(){

	buffer_set m_set;
	init_buffer_set(&m_set);

	m_set.data = &m_set.in;
	process_data(m_set.data);

	printf_data(&m_set.in);
    
}
