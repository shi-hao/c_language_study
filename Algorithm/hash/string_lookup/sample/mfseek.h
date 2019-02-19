#ifndef _MFSEEK_H_
#define _MFSEEK_H_

//debug print control
#define   debug_print    0

#define     MAX_LINES     (128 * 1024 * 1024)    //max line of a file
#define		MAX_CHAR      1024 //max character number of one line

#define		BUF_LEN       (MAX_CHAR + 2)  //buf len

struct fileInfo{
	FILE * file; //file descriptor to access the file
	unsigned int   cur_max_line;       //current max line number
	unsigned int   lineTotal[MAX_LINES];//total char of every line
};

//struct saving the file infomation
extern struct fileInfo  mfileInfo;

//switch the file descriptor to specific line
extern int switch_line(unsigned int line_num);

//init function 
extern int switch_line_init(char* filename);

//free function
extern int switch_line_free();

#endif
