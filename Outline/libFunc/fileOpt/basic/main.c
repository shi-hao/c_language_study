/*
 *************************************************************************
 * 文件的特点：
 * 文件每行末尾都有换行符，\n\r或者只有\n，文件结束，末尾有结束符！
 *
 * 经典的C语言文件操作接口：
 * (1)文件指针： FILE *
 * (2)打开文件： fopen()
 * (3)读文件内容：1.读指定字节大小，指定个数的数据
 *                   fread(void* buff, 
 *                       size_t size,
 *			             size_t count, 
 *			             FILE* stream)
 *                       <此函数会读文件中的内容，包括换行符也会读出来>
 *                2.格式化读文件
 *                   fscanf(FILE *stream,
 *                         const char* format,
 *			               ...)
 * (4)写内容到文件：1.写指定字节大小，指定个数的数据到文件
 *                   fwrite( const void* buff, 
 *                           size_t size,
 *			                 size_t count,
 *			                 FILE* stream)
 *                  2.格式化写文件
 *                   fprintf( FILE *stream,
 *                            const char* format,
 *                            ...)
 * (5)移动文件指针：fseek(FILE* stream, long offset, int origin)
 *                  SEEK_CUR  SEEK_END  SEEK_SET
 *
 * (6)文件末尾判断：feof（）推荐使用feof来判断文件结束
 *                  fscanf()返回值
 *                  注意：当读取到文件的最后一个字符时，读完该字符，feof的返
 *                  回值不为1，再执行一次读操作，才会被置为1。
 *
 * (7)文件换行的判断：文档换行是有换行符的，linux和windows的换行符有些不同。
 *                    windows使用\r\n作为换行符，而linux只使用\n作为换行符。
 *            
 * (8)关闭文件：fclose()
 *
 ************************************************************************
 */

#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

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
int myfscanf(FILE* file, char* format, char buf[], int bufSize)
{
	int cnt=0;

	if(bufSize<1)
		return -1;//缓存大小错误 

	cnt=0;
	fscanf(file,format,buf+cnt);

	while(feof(file)!=1){

		if((buf[cnt]=='\n') || (buf[cnt]=='\r')) //文件换行符，'\n' '\r'
		{
			buf[cnt]='\0';
			return cnt;
		}

		cnt++;
		if(cnt>=bufSize)//判断缓存大小  
			return bufSize;

		fscanf(file,format,buf+cnt);
	}

	if(cnt > 0)
		return cnt;//文件结束返回  
	else
		return -1;
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

	while(1){

		if((cnt + 1)>=bufSize)//判断缓存大小  
			return bufSize;

		fscanf(file,format,buf+cnt);

		if(feof(file) == 1)
		{
			buf[cnt]='\0';
			return cnt;
		}

		if((buf[cnt]=='\n') || (buf[cnt]=='\r')) //文件换行符，'\n' '\r'
		{
			buf[cnt]='\0';
			return cnt;
		}

		cnt++;
	}
}

void main()
{
	FILE* file;
	FILE* fileW;
	FILE* filer;
	FILE* filerr;
	int pre[200], cur[6], fut[6];
	int cnt;
	char str[100]={0};

	/*打开文件-update mode reading and writing*/
	file = fopen("data.txt", "a+");
	if(file == 0)
	{
		printf("文件打开失败");
		return;
	}

	/*打开文件-update mode reading and writing*/
	filer = fopen("data.txt", "a+");
	if(file == 0)
	{
		printf("文件打开失败");
		return;
	}


	/*打开文件-update mode reading and writing*/
	filerr = fopen("data.txt", "a+");
	if(file == 0)
	{
		printf("文件打开失败");
		return;
	}

	fileW = fopen("dataW.txt", "a+");
	if(fileW == 0)
	{
		printf("文件打开失败");
		return;
	}

	/*格式化读文件*/ 
	for(cnt=0;cnt<100;cnt++)
	{
		fscanf(file,"%d",pre+cnt);//fscanf()格式化读文件
		if(feof(file)){  //文件结束则退出 
			break;
		}
		printf("pre[%d]=%d\n",cnt,pre[cnt]);
	}


	while(fgets(str, 100,filer) != 0)
	{
		printf("fgets str:%s\n",str);
	}

	int ret;
	while((ret = myfscanf(filerr,"%c",str,100)) >= 0){
		printf("myfscanf %d str:%s\n",ret,str);
		memset(str,0,100);
	}

	fread(str,1,20,file);
	printf("fread str=%s\n",str);

	//格式化写文件
	fprintf(fileW,"%d\n",666);
	fprintf(fileW,"%s\n","i am shi hao");
	fprintf(filerr,"%s\n","i am shi hao");

	/*关闭文件*/
	fclose(file);
	fclose(fileW);
}
