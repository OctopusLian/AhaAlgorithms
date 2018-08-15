#include<stdio.h>
int main()
{
	int n,m,i,j,k,min,t1,t2,t3;
	int e[7][7],dis[7],book[7]={0};
	int inf=99999999;
	int count=0,sum=0;
	scanf("%d %d",&n,&m);
	
	//初始化 
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(i==j) e[i][j]=0;
				else e[i][j]=inf;
				
	//开始读入边 
	for(i=1;i<=m;i++)
	{
		scanf("%d %d %d",&t1,&t2,&t3);
		e[t1][t2]=t3;
		e[t2][t1]=t3;
	}
	
	//初始化dis数组
	for(i=1;i<=n;i++)
		dis[i]=e[1][i];
	
	book[1]=1;
	count++;
	while(count<n)
	{
		min=inf;
		for(i=1;i<=n;i++)
		{
			if(book[i]==0 && dis[i]<min)
			{
				min=dis[i];
				j=i;
			}
		}
		book[j]=1;
		count++;
		sum=sum+dis[j];
		
		for(k=1;k<=n;k++)
		{
			if(book[k]==0 && dis[k]>e[j][k])
				dis[k]=e[j][k];
		}
	}
	
	printf("%d",sum);
	
	getchar();getchar();
	return 0;

	
	
 } 
