#include<stdio.h>
struct note{
	int x;  //横坐标
	int y;  //纵坐标
	int f;  //父亲在队列中的编号（本题不需要输出路径，可以不需要f） 
	int s;  //步数 
};
int main()
{
	struct note que[2501];  //因为地图大小不超过50*50，因此队列扩展不会超过2500个
	
	int a[51][51] = {0};  //用来存储地图 
	int book[51][51] = {0};  //数组book的作用是记录哪些点已经在队列中了，防止一个点被重复扩展，并全部初始化为0
	//定义一个用于表示走的方向的数组
	int next[4][2] = {  //顺时针方向 
	{0,1}, //向右走 
	{1,0},  //向下走 
	{0,-1},  //向左走 
	{-1,0},  //向上走 
	};

	int head,tail;
	int i,j,k,n,m,startx,starty,p,q,tx,ty,flag;
	
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	scanf("%d %d %d %d",&startx,&starty,&p,&q);
	
	//队列初始化
	head = 1;
	tail = 1;
	//往队列插入迷宫入口坐标 
	que[tail].x = startx;
	que[tail].y = starty;
	que[tail].f = 0;
	que[tail].s = 0;
	tail++;
	book[startx][starty] = 1;
	
	flag = 0;  //用来标记是否到达目标点，0表示暂时没有到达， 1表示已到达
	while(head < tail){  //当队列不为空时循环 
		for(k=0;k<=3;k++)  //枚举四个方向 
		{
			//计算下一个点的坐标 
			tx = que[head].x + next[k][0];
			ty = que[head].y + next[k][1];
			if(tx < 1 || tx > n || ty < 1 || ty > m)  //判断是否越界 
				continue;
			if(a[tx][ty] == 0 && book[tx][ty] == 0)  //判断是否是障碍物或者已经在路径中 
				{
					book[tx][ty] = 1;  //把这个点标记为已经走过。注意bfs每个点通常情况下只入队一次，和深搜不同，不需要将book数组还原
					//插入新的点到队列中
					que[tail].x = tx;
					que[tail].y = ty;
					que[tail].f = head;  //因为这个点是从head扩展出来的，所以它的父亲是head，本题不需要求路径，因此可省略 
					que[tail].s = que[head].s+1;  //步数是父亲的步数+1
					tail++; 
					
				}
			if(tx == p && ty == q)  //如果到目标点了，停止扩展，任务结束，退出循环 
			{
				flag = 1;  //重要！两句不要写反 
				break;
			}
		}
		if(flag == 1)
			break;
		head++;  //当一个点扩展结束后，才能对后面的点再进行扩展 
	}	
	printf("%d",que[tail-1].s);  //打印队列中末尾最后一个点，也就是目标点的步数 
 	//注意tail是指向队列队尾（最后一位）的下一个位置，所以这里需要减1 
	getchar();getchar();
	return 0;		 
}
