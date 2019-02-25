
/*
 * 有2种方法存储字符串，字符指针或者字符数组，char*  char[]
 */
#include<stdio.h>

/*
 *main()
 */
void main()
{
	char *str="i am char*";
	char array[] = "bob";

	printf("str is %s\n", str);
	printf("array is %s\n", array);
}
