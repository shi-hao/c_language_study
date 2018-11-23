#include<stdio.h>
#include<stdlib.h>


//检测大小端，返回0,表示小端，返回1,则是大端
int checkEndian(){
	
	unsigned short var = 0x11ff;
	if(*((unsigned char*)&var) == 0xff)
		return 0;
	else 
		return 1;
}

int main(){

	int var=0x0a0b0c0d;
	char varr;
	checkEndian()?printf("\n big-endian \n"):printf("\n little-endian \n");

	printf("\n varr = var>>24 %#.2x \n", varr=var>>24);
	printf("\n varr = var>>16 %#.2x \n", varr=var>>16);
	printf("\n varr = var>>8 %#.2x \n", varr=var>>8);
	printf("\n varr = var %#.2x \n", varr=var);

}
