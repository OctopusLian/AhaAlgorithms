#include<stdio.h>
int main()
{
	int dis[10],i,k,n,m,u[10],v[10],w[10];
	int inf=99999999;
	scanf("%d %d",&n,&m);  //读入n和m，n表示顶点个数，m表示边的条数
	
	//读入边
	for(i=1;i<=m;i++)
		scanf("%d %d %d",&u[i],&v[i],&w[i]);
	
	//初始化dis数组，这里是1号顶点到其余各个顶点的初始路程
	for(i=1;i<=n;i++)
		dis[i]=inf;
	dis[1]=0;
	
	//Bellman-Ford算法核心语句
	for(k=1;k<=n-1;k++)
		for(i=1;i<=m;i++)
			if(dis[v[i]] > dis[u[i]] + w[i])
				dis[v[i]] = dis[u[i]] + w[i];
				
	//输出最终的结果
	for(i=1;i<=n;i++)
		printf("%d ",dis[i]);
		
	getchar();getchar();
	return 0; 
}
