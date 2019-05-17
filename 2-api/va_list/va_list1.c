/*
 ************************************************************************
 * 实现一个可变参数函数，功能类似printf()函数,支持%s，%d，%f打印参数。
 * 
 * 此函数的实现适合在嵌入式平台下，通过一些物理接口打印数据，比如串口，
 * 将输出函数替换为对应的物理接口的输出函数即可实现格式化打印的功能。
 *
 * 要求：对应的编译环境支持C库函数va_list，sprintf函数。
 *       输入整形和浮点数据长度不能超过19
 *
 *       va_list()  va_start()  va_arg()  va_end()   
 *       sprintf() 
 *       putchar()
 *************************************************************************
 */

#include<stdarg.h>
#include<stdio.h>

void my_printf(const char* fmt,...)
{
	/*定义一个va_list量*/
	va_list ap;

	int tmp;
	double tmpDouble;
	char *p;
	char buff[20]={0};
	int cnt=0;

	va_start(ap, fmt);


	/*根据fmt的内容获取可变参数*/ 
	for(;*fmt;fmt++){

		/*第一步，判断是否是格式符，不是直接输出*/
		if(*fmt != '%'){
#if 1
			/*根据不同平台，调用对应的输出接口*/
			putchar(*fmt);
#endif
			continue;
		}

		/*第二步，如果是格式符，则判断下一个字符*/
		fmt++;

		/*第三步，如果是结束符，则直接退出*/
		if(*fmt == '\0'){
			break;
		}

		/*根据不同的格式，执行不同的操作*/
		switch(*fmt){
			case 'd':  //按照十进制输出
				tmp = va_arg(ap, int);//取出下一个参数
				sprintf(buff,"%d",tmp);//将int数据转化为字符串

#if 1
				/*根据不同平台，调用对应的输出接口*/
				for(cnt=0;buff[cnt];cnt++){
					putchar(buff[cnt]);
				}
#endif
				break;

			case 's':  //按照字符串输出
				p = (char *)va_arg(ap, char *);
#if 1
				/*根据不同平台，调用对应的输出接口*/
				for(;*p;p++){
					putchar(*p);
				}
#endif
				break;

			case 'f':  //输出浮点数
				tmpDouble = va_arg(ap, double);//取出下一个参数
				sprintf(buff,"%f",tmpDouble);//将浮点数据转化为字符串
#if 1
				/*根据不同平台，调用对应的输出接口*/
				for(cnt=0;buff[cnt];cnt++){
					putchar(buff[cnt]);
				}
#endif
				break;

			case '%'://输出百分%%
#if 1
				putchar('%');
#endif
				break;

			default:  //默认处理
				break;
		}
	}
	va_end(ap);
}

/*测试函数*/
void main(){
	my_printf("%d\n",123);
	my_printf("str1=%s,str2=%s,str3=%s\n","123","45","7890");
	my_printf("%f\n",123.123);
	my_printf("%%\n");
	my_printf("%x\n");
}
