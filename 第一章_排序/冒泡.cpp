#include<stdio.h>
struct student
{
	char name[21];
	int score;
};  //创建一个结构体用来存储学生的姓名和分数 
int main()
{
	struct student a[100],t;
	int i,j,n;
	scanf("%d",&n);
	for(i=1;i<=n;i++)  //循环读入n个数到数组中 
		scanf("%s %d",&a[i].name,&a[i].score);
	/*按分数从高到低进行排序*/
	for(i=1;i<=n-1;i++)
	{
		for(j=1;j<n-i;j++)  //从第一位开始比较直到最后一个尚未归位的数 
		{
			if(a[j].score<a[j+1].score);  //比较大小并转换
			{
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			} 
		}
	}
	for(i=1;i<=n;i++)  //输出结果
		printf("%s\n",a[i].name);
		
	return 0; 
}
