#include<stdio.h>
#include<stdlib.h>

int main(){

	char* data;
	char buff[100]={0};
	scanf("%s", buff);
	printf("%s", buff);
	free(data);
}
