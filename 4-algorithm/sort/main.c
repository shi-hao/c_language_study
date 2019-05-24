#include<stdio.h>
#include<stdlib.h>


//按照从小到大顺序
//插入排序
int insert_sort(unsigned char* data, int size){

	unsigned char tmp;
	for(int i=0; i<size; i++){
		for(int j=i-1; j>=0; j--){
		    tmp = data[j+1];
			if(data[j] < data[j+1])
				break;
			else{
				data[j+1] = data[j];
				data[j] = tmp;
			}
		}
	}
}

//快速排序


int main(){
#define data_size  10

	unsigned char data[data_size]={9,8,7,6,5,4,3,2,1,0};

	insert_sort(data, data_size);

	printf("\n");
	for(int i=0;i<data_size;i++)
		printf(" %d ", data[i]);

}
