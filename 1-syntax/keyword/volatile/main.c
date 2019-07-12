/*
 *volatile跟编译器代码优化相关，使用volatile修饰的编码，可以避免编译器对代码的优化！！
 */ 

void main()
{
	volatile int var1;
	int var2=0;

	var1 = 2;
	var1 = 3;

	var2 = 4;
	var2 = 5;
}
