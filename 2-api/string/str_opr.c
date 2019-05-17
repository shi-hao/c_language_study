/*
 ****************************
 *字符串库函数测试
 ****************************
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main()
{
	char strr[20];
	int int_a;
	long long_a;
	float float_a;
	char str[80];
	char result;
	char *pos;
	/*-----------------------------*/
	/*数据和字符串的转化*/
	printf("数据和字符串的转化：\n");
	/*数据转字符串*/
	sprintf(strr,"%d",110);//整数转字符串
	printf("%s\n",str);

	memset(strr,0,20);

	sprintf(strr,"%f",110.110);//浮点数转字符串
	printf("%s\n",str);

	/*字符串转数据*/
	int_a = atoi("123");//字符串转整型
	printf("int_a=%d\n",int_a);   

	long_a = atol("123");//字符串转长整型
	printf("long_a=%ld\n",long_a);   

	float_a = atof("123.123");//字符串转浮点型
	printf("float_a=%f\n",float_a);   


	/*------------------------------------*/
	/*字符串复制*/
	printf("字符串复制：\n");
	strcpy(str,  "hello world ");//全部复制
	printf("str:%s\n", str);

	strncpy(str, "good", 3);//复制指定个数
	printf("str:%s\n", str);

	strcat(str, "bye");//全部追加
	printf("str:%s\n", str);

	strncat(str, "bye", 2);//追加指定个数
	printf("str:%s\n", str);

	/*------------------------------------*/
	/*字符串比较*/
	printf("字符串比较：\n");
	result = strcmp("i am 1","i am 2");
	printf("result=%d\n", result);

	result = strncmp("i am 1", "i am 2", 4);
	printf("result=%d\n", result);

	//字符串的长短不一致
	result = strcmp("i am 1","i am 123");
	printf("result=%d\n", result);

	/*------------------------------------*/
	/*字符查找*/
	printf("字符串查找：\n");
	pos = strchr("i am a", 'a');
	printf("pos = %lx\n", (long)pos);

	pos = strrchr("i am a", 'a');
	printf("pos = %lx\n", (long)pos);

	//找不到如何返回值
	pos = strchr("i am a", 'x');
	printf("pos = %lx\n", (long)pos);
}
