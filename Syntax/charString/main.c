/*字符串常量测试*/
#include<stdio.h>

/*
 * 程序返回字符串，字符串是否被释放?
 */
char * test()
{
	return("i am good");
}

/*
 *main()
 */
void main()
{
	char *p="i am good char *";

	printf("%s\n", p);

#if 0
	*p='a';//是否允许改变内容？--->segmentation fault 段错误
#endif

	p = test();//函数返回字符串 
	printf("%s\n", p);

	p = "good" "well" "better";  //字符串的合并 
	printf("%s\n", p);
}
