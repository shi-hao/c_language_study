/*防止重复包含预处理宏*/
#ifndef USRDEF
#define USRDEF

/*c++调用预处理宏*/
#ifdef cplusplus_
 extern "C" {
#endif

/*定义常量*/
#define PI 3.1415926

/*带参数的宏*/
#define  plus(a,b)  (a+b)//定义运算

#define  before(x)  B_##x //##，将宏的参数转化位标识符的一部分
//#define  behind(x)  Bx##

//#define  toChar(x)   #@x  //#@，将宏的参数转化为字符或字符串
//#define  toStr(x,str)   #@xstr
 
#define  toStr2(x)   #x//将宏的参数转化为字符串

/*多行宏的连接符*/
#define process(a,b)  ((a+b)-\
                      (a-b))

#ifdef cplusplus_
 }
#endif

#endif
