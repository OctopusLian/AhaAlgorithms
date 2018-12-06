#include<stdio.h>
int main()
{
	int i,j,n,m,a,b,cur,book[101]={0},e[101][101];
	int que[10001],head,tail;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(i==j) e[i][j]=0;
			else e[i][j]=99999999;  //假设99999999为正无穷

	/*读入顶点之间的边*/
	for(i=1;i<=m;i++)
	{
		scanf("%d %d",&a,&b);
		e[a][b]=1;
		e[b][a]=1;  //这里是无向图，所以需要e[b][a]也赋为1 
	}
	head=1;
	tail=1;
	
	que[tail]=1;
	tail++;
	book[1]=1;  //标记1号顶点已访问
	
	while(head<tail && tail<=n)
	{
		cur=que[head];  //当前正在访问的顶点编号
		for(i=1;i<=n;i++)  //从1~n依次尝试
		{
			if(e[cur][i]==1 && book[i]==0)
			{
				que[tail]=i;
				tail++;
				book[i]=1;
			}
			if(tail>n) break;
		} 
		head++;  //当一个顶点扩展结束后，head++，然后才能继续往下扩展 
	}
	for(i=1;i<=tail;i++)
		printf("%d ",que[i]);
	return 0;	
} 
