/*流控关键字*/
#include<stdio.h>


void  main()
{
	//unsigned char flow=1;
	int cnt=0;
	unsigned char ch;

	/*break*/
	//break; //随便的break是不允许的
	for(;;)
	{
		printf("i am break\n");
		break;
	}


	/*continue*/
	//continue;  //随便的continue是不允许的
	for(;cnt<5;cnt++)
	{
		printf("i am continue\n");
		continue;
		printf("i am continue again?\n");
	}


	/*return*/
	ch = getchar();
	if(ch == 'a')
		return;
	else
		//ch = 'a';



	/*goto*/
	if(ch != 'a')
		goto quit;
	else
		goto exit;
quit:
	{
		printf("i am quit\n");
	}
	printf("i am quit again?\n");
exit:
	printf("i am exit\n");
}
