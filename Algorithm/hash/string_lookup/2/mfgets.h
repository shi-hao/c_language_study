#ifndef _MFSEEK_H_
#define _MFSEEK_H_

//debug print control
#define   debug_print    0

#define  SWITCH_UNSIGNED_INT  (long)4294967296
#define  SWITCH_MAX_LINES     (long)(16 * 1024 * 1024)    //max line of a file
#define  SWITCH_MAX_CHAR      (long)(SWITCH_UNSIGNED_INT/SWITCH_MAX_LINES) //max character number of one line
#define  SWITCH_BUF_LEN       (long)(SWITCH_MAX_CHAR + 2)  //buf len

struct fileInfo{
	FILE * file; //file descriptor to access the file
	unsigned int   cur_max_line;       //current max line number
	unsigned int   lineTotal[SWITCH_MAX_LINES];//total char of all previous lines
};

//init function 
extern int switch_line_init(char* filename, struct fileInfo* mfileInfo);

//fgets
char* switch_line_fgets(char *s, int size, struct fileInfo* mfileInfo, unsigned int line_num);

//free function
extern int switch_line_free(struct fileInfo* mfileInfo);

#endif
