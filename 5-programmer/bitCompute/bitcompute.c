/*
 ******************************************
 *作者 ：bleach 2013/12/02
 *描述 ：位运算测试
 *******************************************
 */
#include<stdio.h>
void main()
{
	unsigned int result;

	/*******************
	 *无符号数（正数）的位运算
	 ********************
	 */
	/*位与运算*/
	result = 9 & 5;
	printf("9&5 =%d\n", result);

	/*位或运算*/
	result = 9 | 5;
	printf("9|5 =%d\n", result);

	/*位异或运算*/
	result = 9 ^ 5;
	printf("9^5 =%d\n", result);

	/*取反运算*/
	result = ~1;
	printf("~1=%d\n", result);

	/*******************
	 *有符号数（涉及到负数）的位运算
	 ********************
	 */ 

}
