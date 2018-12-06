#include<stdio.h>
int main()
{
	char a[20][21];
	int i,j,sum,map=0,p,q,x,y,n,m;
	scanf("%d %d",&n,&m);  //n表示有多少行字符，m表示每行有多少列 
	
	for(i=0;i<=n-1;i++)  //读入n行字符 
		scanf("%s",a[i]);
		
	for(i=0;i<=n-1;i++)
	{
		for(j=0;j<=m-1;j++)
		{
			if(a[i][j]=='.')  //判断这个点是不是平地，是平地才可以被放置炸弹 
			{
				sum=0;  //用来计数，表示可以消灭的敌人数，需要初始化 
				x=i;y=j;  //向上统计可以消灭的敌人数 
				while(a[x][y]!='#')  //判断是不是墙，如果不是墙就继续 
				{
					if(a[x][y]=='G')  //如果当前点是敌人 
						sum++;  //计数 
					x--;  //否则继续向上统计 
				}
				
				x=i;y=j;  //向下统计可以消灭的敌人数 
				while(a[x][y]!='#')
				{
					if(a[x][y]=='G')
						sum++;
					x++;  //继续向下统计 
				}
				
				x=i;y=j;  //向左统计可以消灭的敌人数 
				while(a[x][y]!='#')
				{
					if(a[x][y]!='G')
						sum++;
					y--;  //继续向左统计 
				}
				
				x=i;y=j;  //向右统计可以消灭的敌人数 
				while(a[x][y]!='#')
				{
					if(a[x][y]!='G')
						sum++;
					y++;  //继续向右统计 
				}
				/*更新map的值*/ 
				if(sum>map)  //如果当前点所能消灭的敌人总数大于map 
				{
					map=sum;  //则更新map 
					p=i;  //用p，q记录当前点的坐标 
					q=j;
				}
			}
		}
	}
	
	printf("将炸弹放置在(%d,%d),最多可以消灭%d个敌人\n",p,q,map);
	return 0; 
}
