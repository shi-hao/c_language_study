/*
 *全局变量定义
 */
static int static_global_i;
int global_i=1;

//int global_j=1;//全局变量名重复的问题测试

/*
 *数学减运算 
 */
static int minus(int a, int b)
{
	return(a-b);
}
/*
 *数学加运算 
 */
static int plus(int a, int b)
{
	return(a+b);
}
/*
 *数据处理，返回（a,b的和）与（a,b的差）的差
 */
int DataProcess(int a, int b)
{
	return(minus(plus(a,b),minus(a,b)));
}
/*
 *静态局部变量测试
 */
int staticVariable()
{
	int static local_i;
	return(local_i++);
}
