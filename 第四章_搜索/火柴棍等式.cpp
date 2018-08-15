#include<stdio.h>
int fun(int x)
{
	int num=0;  //用来计数的变量，所以需要初始化
	int f[10]={6,2,5,5,4,5,6,3,7,6};  //用一个数组来记录0~9每个数字需要用多少根火柴棍
	while(x/10!=0)  //如果x/10的商不等于0，说明这个数至少有两位
	{
		num += f[x%10];  //获得x的末尾数字并将此数所需要用到的火柴棍根数累加到num中
		x=x/10;  //去掉x的末尾数字，例如x的值为123则现在x的值为12 
	} 
	num += f[x];  //最后加上此时x所需用到的火柴棍的根数（此时x一定是一位数）
	return num;  //返回需要火柴棍的总根数 
}

int main()
{
	int a,b,c,m,sum=0;  //sum用来计数，因此要初始化
	scanf("%d",&m);  //读入火柴棍的个数
	/*开始枚举a和b*/
	for(a=0;a<=1111;a++)
	{
		for(b=0;b<=1111;b++)
		{
			c=a+b;  //计算出c
			if(fun(a)+fun(b)+fun(c)==m-4)
			{
				printf("%d+%d=%d\n",a,b,c);
				sum++;
			} 
		}
	} 
	printf("一共可以拼出%d个不同的等式",sum);
	return 0;
} 
