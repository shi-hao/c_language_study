# c language file operation api  

## 文件的特点  
文件每行末尾都有换行符，\n\r或者只有\n，文件结束，末尾有结束符！  
  
## 经典的C语言文件操作接口  
(1)文件指针  
	FILE *  

(2)打开文件  
    fopen()  

(3)读文件内容  
fread(void* buff,   size_t size,  size_t count,   FILE* stream)  

fscanf(FILE *stream,  const char* format,   ...)  

int fgetc(FILE *stream)

char *fgets(char *s, int size, FILE *stream)

(4)写内容到文件  
fwrite( const void* buff,   size_t size,  size_t count,  FILE* stream)  

fprintf( FILE *stream,  const char* format,   ...)  

(5)移动文件指针  
fseek(FILE* stream, long offset, int origin)  
	
SEEK_CUR  SEEK_END  SEEK_SET  
  
(6)文件末尾判断  
feof（）推荐使用feof来判断文件结束  
                 注意：当读取到文件的最后一个字符时，读完该字符，feof的返  
                 回值不为1，再执行一次读操作，才会被置为1。  
  
(7)文件换行的判断  
文档换行是有换行符的，linux和windows的换行符有些不同，windows使用\r\n作为换行符，  
而linux只使用\n作为换行符。  
             
(8)关闭文件  
fclose()   
