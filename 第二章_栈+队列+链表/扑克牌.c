#include<stdio.h>
int a[10],book[10],n;
//C语言的全局变量在没有赋值以前默认为0，因此这里的book数组无需全部再次赋初始值
void dfs(int step)  //step表示现在站在第几个盒子面前
{
	int i;
	if(step==n+1)  //如果站在第n+1个盒子面前，则表示前n个盒子已经放好扑克牌了
	{
		for(i=1;i<=n;i++)  //输出一种排列（1~n号盒子中的扑克牌编号）
			printf("%d",a[i]);
		printf("\n");
		return;  //返回之前的一步（最近一次调用dfs函数的地方 
	} 
	/*此时站在第step个盒子面前，按照1、2、3...n的顺序一一尝试*/
	for(i=1;i<=n;i++)
	{
		/*判断扑克牌i是否还在手上*/
		if(book[i]==0)  //book[i]等于0表示i号扑克牌在手上
		{
				a[step]=i;  //将i号扑克牌放入到第step个盒子中
			book[i]=1;  //将book[i]设为1，表示i号扑克牌已经不在手上
			/*第step个盒子已经放好扑克牌，接下来需要走到下一个盒子面前*/
			dfs(step+1);  //通过函数的递归调用来实现
			book[i]=0;  //将刚才尝试的扑克牌收回，才能进行下一次尝试   
		} 
	}
	return; 
} 

int main()
{
	scanf("%d",&n);  //n为1~9之间的整数
	dfs(1);  //首先站在1号小盒子面前
	return 0; 
}
