/*此文件的用来测试const变量的存储位置*/
#include<stdio.h>

const char  global[1024]={0};
const char  global2[1024];

void main(){
  const char local[1024]={0};

}

