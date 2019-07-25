//条件宏，防止头文件被多次引入，引起重复定义
#ifndef USRDEF
#define USRDEF

/*定义常量*/
#define PI 3.1415926

/*带参数的宏*/
#define  plus(a,b)  (a+b)

/*
 * 宏转义特殊符号：
 * 单井号(#):将宏参数转化为字符串
 * 双井号(##):连接符，可以将宏参数转化为标识符的一部分，比如变量名
 */
#define  toStr(x)   #x      //将宏的参数转化为字符串

#define  toVar(x)   var##x  //将宏的参数转化为变量名的一部分


/* 宏定义换行符号：\  */
#define process(a,b)  ((a+b)-\
                      (a-b))

#endif
