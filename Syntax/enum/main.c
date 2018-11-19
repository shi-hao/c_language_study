/*
 **************************************************
 *-----enum相关测试------
 *定义、初始化、赋值、引用
 ***************************************************
 */
#include<stdio.h>

//定义enum结构时，如果不定义枚举元素的值，那么第一个枚举元素的值为0,以后元素的值依次增1
enum weekday{
 sun,
 mon,
 tue,
 thur,
 fri,
 sat
};

enum enumvalue{
 fir=1,
 sec,   //后面的值是前面的值增1,除非对某个量执行了赋值操作
 thi,  
 four=5,
 fiv,
 six=6
};

int  main()
{
  /*定义enum以及初始化*/
  enum weekday day=sat;

  enum enumvalue value;
  int i =0;

  /*输出*/ 
  printf("day=%d\n",day);
  day = sun;
  printf("day=%d\n",day);

#if 1
  day = 0;//gcc允许这样赋值
#endif

  /*输出*/
  printf("value=%d\n",value);
  value = fir;
  printf("value_fir=%d\n",value);
  value = thi;
  printf("value_thi=%d\n",value);
  value = fiv;
  printf("value_fiv=%d\n",value);
  value = six;
  printf("value_six=%d\n",value);
}
