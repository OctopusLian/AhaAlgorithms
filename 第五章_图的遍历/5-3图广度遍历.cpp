#include<stdio.h>
struct note{
	int x;  //城市编号
	int s;  //转机次数 
}; 

int main()
{
	struct note que[2501];
	int e[51][51]={0},book[51]={0};
	int head,tail;
	int i,j,n,m,a,b,cur,start,end,flag=0;
	scanf("%d %d %d %d",&n,&m,&start,&end);
	for(i=1;i<=n;i++)  //初始化二维矩阵
		for(j=1;j<=n;j++)
			if(i==j) e[i][j]=0;
				else e[i][j]=99999999;
				
	for(i=1;i<=m;i++)  //读入城市之间的航班
	{
		scanf("%d %d",&a,&b);
		e[a][b]=1;  //注意这里是无向图
		e[b][a]=1; 
	 } 
	 
	 head=1;  //队列初始化 
	 tail=1;
	 
	 que[tail].x=start;  //从start号城市出发，将start号城市加入队列
	 que[tail].s=0;
	 tail++;
	 book[start]=1;  //标记start号城市已经在队列中
	 
	 while(head<tail)  //当队列不为空的时候循环
	 {
	 	cur=que[head].x;  //当前队列中首城市的编号
		for(j=1;j<=n;j++)  //从1~n依次尝试
		{
			if(e[cur][j] != 99999999 && book[j] == 0)  //从城市cur到城市j是否有航班并且判断城市j是否已经在队列中 
			{
				//如果从城市cur到城市j有航班并且城市j不在队列中，则将j号城市入队
				que[tail].x=j;
				que[tail].s=que[head].s+1;  //转机次数+1
				tail++;
				book[j]=1;  //标记城市j已经在队列中 
			}
			//如果到达目标城市，停止扩展，任务结束并退出循环
			if(que[tail-1].x == end)
			{
				flag=1;
				break;
			 } 
		 } 
		if(flag == 1)
			break;
		head++;  //继续扩展 
	  } 
	  
	  //打印队列中末尾最后一个（目标城市）的转机次数
	  printf("%d",que[tail-1].s);  //注意tail是指向队列队尾（即最后一位）的下一个位置，所以这里需要-1
	  
	  return 0; 
}
