#include<stdio.h>
int main()
{
	int book[1001],i,j,t,n;  //我们需要1001个桶，来表示0~1000之间每一个数出现的次数
	for(i=0;i<=1000;i++)
		book[i]=0;
	scanf("%d",&n); 
	
	for(i=1;i<=n;i++)  //循环读入n个数，并进行桶排序 
	{
		scanf("%d",&t);
		book[t]++;
	} 
	
	for(i=1000;i>=0;i--)  //依次判断a[0]~a[10]
		for(j=1;j<=book[i];j++)
			printf("%d ",i);
	
	return 0; 
}
