#include<stdio.h>
int n,m,e[9][9],root;
int num[9],low[9],index;
//求两个数中较小一个数的函数
int min(int a,int b)
{
	return a < b ? a : b;
 } 
 //割点算法的核心
 void dfs(int cur,int father)
 {
 	int i;
 	
 	index++;
 	num[cur]=index;
 	low[cur]=index;
 	for(i=1;i<=n;i++)
 	{
 		if(e[cur][i]==1)
 		{
 			if(num[i]==0)
 			{
 				dfs(i,cur);
 				low[cur]=min(low[i],low[cur]);
 				if(low[i] > num[cur])
 					printf("%d-%d\n",cur,i);
			 }
			 else if(i!=father)
			 {
			 	low[cur]=min(low[cur],num[i]);
			 }
		 }
	 }
	 return;
  } 
  
  int main()
  {
  	int i,j,x,y;
  	scanf("%d %d",&n,&m);
  	for(i=1;i<=n;i++)
  		for(j=1;j<=n;j++)
  			e[i][j]=0;
  			
  	for(i=1;i<=m;i++)
  	{
  		scanf("%d %d",&x,&y);
  		e[x][y]=1;
  		e[y][x]=1;
	  }
	root=1;
	dfs(1,root);
	
	getchar();getchar();
	return 0;
  }
