#include<stdio.h>
int main()
{
	int n,m,j,k,i;
	int u[8],v[8],w[8];  //u、v和w的数组大小要根据实际情况来设置，要比m最大值要大1
	int first[6],next[8];  //first要比n的最大值要大1，next要比m的最大值要大1
	int dis[6]={0},book[6]={0};  //book数组用来记录哪些顶点已经在队列中
	int que[101]={0},head=1,tail=1;  //定义一个队列，并初始化队列
	int inf=99999999;
	scanf("%d %d",&n,&m);  //读入n和m，n表示顶点个数，m表示边的条数
	
	//初始化dis数组，这里是1号顶点到其余各个顶点的初始路程
	for(i=1;i<=n;i++)
		dis[i]=inf;
	dis[1]=0;
	
	//初始化book数组，初始化为0，刚开始都不在队列中
	for(i=1;i<=n;i++)
		book[i]=0;
		
	//初始化first数组下标1~n的值为-1，表示1~n顶点暂时都没有边
	for(i=1;i<=n;i++)
		first[i]=-1;
		
	for(i=1;i<=m;i++)
	{
		scanf("%d %d %d",&u[i],&v[i],&w[i]);  //读入每一条边
		//下面两句是建立邻接表的关键
		next[i]=first[u[i]];
		first[u[i]]=i; 
	 } 
	 
	//1号顶点入队
	que[tail]=1;
	tail++;
	book[1]=1;  //标记1号顶点已经入队
	while(head<tail)  //队列不为空的时候循环
	{
		k=first[que[head]];  //当前需要处理的队首顶点
		while(k!=-1)  //扫描当前顶点所有的边
		{
			if(dis[v[k]]>dis[u[k]+w[k]])  //判断是否松弛成功
			{
				dis[v[k]]=dis[u[k]+w[k]];  //更新顶点1到顶点v[k]的路程
				//这的book数组用来判断顶点v[k]是否在队列中
				//如果不使用一个数组来标记的话，判断一个顶点是否在队列中每次都需要从队列的head到tail扫一遍，很浪费时间
				if(book[v[k]]==0)  //0表示不在队列中，将顶点v[k]加入队列中
				{
					//下面两句是入队操作
					que[tail]=v[k];
					tail++;
					book[v[k]]=1;  //同时标记顶点v[k]已经入队 
				 } 
			 } 
			 k=next[k];
		 } 
		//出队
		book[que[head]]=0;
		head++; 
	 } 
	 
	 //输出1号顶点到其余各个顶点的最短路径
	 for(i=1;i<=n;i++)
	 	printf("%d ",dis[i]);
		 
	getchar();getchar();
	return 0; 
 } 
