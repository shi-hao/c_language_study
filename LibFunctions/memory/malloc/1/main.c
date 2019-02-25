/*
 * malloc 测试
 */
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

typedef struct buffer{
	int capacity;
	int len;
	int offset;
	unsigned char* data;
} buffer;

typedef struct context_buffer{
	buffer incoming_data;
	buffer outcoming_data;
	buffer other_data;
} context_buffer;

typedef struct c_2{
	struct context_buffer * buffers;
	struct buffer buf;
} c_2;

typedef struct item{
	struct buffer * buff;
}item;

typedef struct set{
	int capacity;
	int len;
	int offset;
	struct item * array;
}set;


void main()
{
#define capacity_usr   100
	struct c_2 cc;
	struct context_buffer m;

	m.incoming_data.data = (unsigned char*)malloc(capacity_usr);
	m.incoming_data.capacity = capacity_usr;
	m.incoming_data.len = 0;
	m.incoming_data.offset = 0;

	cc.buffers = &m;
	cc.buf = cc.buffers->incoming_data;

	*(cc.buf.data) = 0xfe;
	cc.buf.len = 1;

	printf("\n cc.buf.capacity = %d\n", cc.buf.capacity);
	printf("\n cc.buf.len = %d\n", cc.buf.len);
	printf("\n cc.buf.data[0] = %#.2x\n", (cc.buf.data)[0]);

	{
		struct buffer m_buf;
		struct set m_set;
		struct item m_item;

		//init buffer 
		m_buf.data = (unsigned char*)malloc(sizeof(unsigned char) * capacity_usr);
		m_buf.capacity = capacity_usr;
		(m_buf.data)[0] = 0xf;

		//init set 
		m_set.array = (struct item*)malloc(sizeof(struct item) * capacity_usr);
		m_set.capacity = capacity_usr;
		m_set.len = 0;
		
		//middle process 
		m_item.buff = &m_buf;

		//add item
		m_set.array[0] = m_item;
		m_set.len++;

		//print
		printf("\n m_set.array->buff->capacity = %d\n", m_set.array->buff->capacity );
		printf("\n *(m_set.array->buff->data) = %d\n",*(m_set.array->buff->data) );

		//free 
		free(m_buf.data);
		free(m_set.array);
	}

	free(m.incoming_data.data);
}
