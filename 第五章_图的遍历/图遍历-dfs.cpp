#include<stdio.h>
int book[101],sum,n,e[101][101];
void dfs(int cur)  //cur是当前所在的顶点编号
{
	int i;
	printf("%d ",cur);
	sum++;  //每访问一个顶点，sum就加1
	if(sum==n) return ;  //所有的顶点都已经访问过则直接退出
	for(i=1;i<=n;i++)  //从1号顶点到n号顶点依次尝试，看哪些顶点与当前顶点cur有边相连
	{
		if(e[cur][i]==1 && book[i]==0)  //判断当前顶点cur到顶点i是否有边，并判断顶点i是否已访问过
		{
			book[i]=1;  //标记顶点i已经访问过
			dfs(i);  //从顶点i再出发继续遍历 
		} 
	} 
	return;
} 

int main()
{
	int i,j,m,a,b;
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
	/*从1号顶点出发*/ 
	book[1]=1;  //标记1号顶点已访问
	dfs(1);  //从1号顶点开始遍历 
	return 0;	
}
