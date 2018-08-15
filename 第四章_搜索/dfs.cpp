#include<stdio.h>
int a[10],book[10],n;  //C语言的全局变量在没有赋值以前默认为0，因此这里的book数组无需全部再次赋初始值0
void dfs(int step)  //step表示现在站在第几个盒子面前 
{
	int i;
	if(step == n+1)
	{
		//输出一种排列（1~n号盒子中的扑克牌编号) 
		for(i=1;i<=n;i++)
			printf("%d",a[i]);
		printf("\n");
		
		return;  //返回之前的一步（最近调用dfs函数的地方） 
	}
	//此时站在第step个盒子面前，应该放哪张牌呢
	//按照1、2、3...n的顺序一一尝试 
	for(i=1;i<=n;i++)
	{
		//判断扑克牌i是否还在手上 
		if(book[i] == 0) //book[i]等于0表示i号扑克牌仍然在手上 
		{
			a[step]=i;  //将i号扑克牌放入到第step个盒子中
			book[i]=1;  //将book[i]设为1，表示i号扑克牌已经不在手上了
			dfs(step+1);  //这里通过函数的递归调用来实现（自己调用自己）
			book[i]=0;  //将刚才的扑克牌收回，才能进行下一次尝试（这一步很关键） 
		}
	}
	return;
}

int main()
{
	scanf("%d",&n);  //输入的时候要注意n为1~9整数 
	dfs(1);  //首先站在1号小盒子面前 
	getchar();getchar();
	return 0;
} 
