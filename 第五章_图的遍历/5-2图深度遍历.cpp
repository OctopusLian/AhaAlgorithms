#include<stdio.h>
int min=99999999,book[101],n,e[101][101];  //假设99999999为正无穷

//cur是当前所在的城市编号，dis是当前已经走过的路程
void dfs(int cur,int dis)
{
	int j;
	if(dis>min) return;  //如果当前走过的路程已经大于之前找到的最短路，则没有必要再往下尝试了，立即返回
	if(cur == n)  //判断是否到达了目标城市
	{
		if(dis<min) min=dis;  //更新最小值
		return ; 
	 } 
	 
	 for(j=1;j<=n;j++)  //从1号城市到n号城市依次尝试
	 {
	 	if(e[cur][j] != 99999999 && book[j] == 0)
	 	{
	 		book[j] = 1;  //标记城市j已经在路径中
			dfs(j,dis+e[cur][j]) ;  //从城市j再出发，继续寻找目标城市
			book[j] = 0;  //之前一步探索完毕，取消对城市j的标记 
		 }
	  } 
	return;
 } 
 
 int main()
 {
 	int i,j,m,a,b,c;
 	scanf("%d %d",&n,&m);
 	for(i=1;i<=n;i++)  //初始化二维矩阵
	 	for(j=1;j<=n;j++)
		 	if(i == j) e[i][j]=0;
			 else e[i][j]=99999999;
			 
	for(i=1;i<=m;i++)
	{
		scanf("%d %d %d",&a,&b,&c);
		e[a][b] = c;
	 } 
	 
	//从1号城市出发
	book[1]=1;  //标记1号城市已经在路径中
	dfs(1,0);  //1表示当前所在的城市编号，0表示当前已经走过的路程
	printf("%d",min);  //打印1号城市到5号城市的最短路径
	
	return 0; 
 }
