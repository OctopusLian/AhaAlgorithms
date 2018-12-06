#include<stdio.h>
int n,m,p,q,min=99999999;
int a[51][51],book[51][51];
void dfs(int x,int y,int step)
{
    int next[4][2]={
    {0,1},//向右走
    {1,0},//向下走
    {0,-1},//向左走
    {-1,0},//向上走 
    };
    int tx,ty,k;
    if(x==p && y==p)  //判断是否到达小哈的位置 
    {
        if(step<min)
            min=step;  //更新最小值
        return; 
    }
    /*枚举四种走法*/ 
    for(k=0;k<=3;k++)
    {
        /*计算下一个点的坐标*/
        tx=x+next[k][0];
        ty=y+next[k][1];
        if(tx<1 || tx>n || ty<1 || ty>m)  //判断是否越界
            continue;
        /*判断该点是否为障碍物或者已经在路径中*/
        if(a[tx][ty]==0 && book[tx][ty]==0)
        {
            book[tx][ty]=1;  //标记这个点已经走过
            dfs(tx,ty,step+1);  //开始尝试下一个点
            book[tx][ty]=0;  //尝试结束，取消这个点的标记 
        } 
    }
    return;
} 

int main()
{
    int i,j,startx,starty;
    scanf("%d %d",&n,&m);  //读入n和m，n为行，m为列
    /*读入迷宫*/
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
    scanf("%d %d %d %d",&startx,&starty,&p,&q);  //读入起点和终点坐标
    /*从起点开始搜索*/
    book[startx][starty]=1;  //标记起点已经在路径中，防止后面重复走
    dfs(startx,starty,0);  //第一个参数是起点的x坐标，以此类推是起点的y坐标，初始步数为0
    printf("%d",min);  //输出最短步数
    return 0; 
}
