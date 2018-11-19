/*使用相对路径包含头文件*/
//#include"../inc/file.h"
#include"bleach/file.h"

/*使用默认路径包含头文件*/
#include<stdio.h>

/*使用绝对路径包含头文件*/
#include</home/bleach/a.txt>  //include只是机械的复制，它并不判断文件的类型
#include"/home/bleach/a.txt"  //include只是机械的复制，它并不判断文件的类型


int main()
{
  printf("include\n");
  printf("TestVal=%d\n",TestVal);
  printf("FileTxt=%d\n",FileTxt);
  return 0;
}
