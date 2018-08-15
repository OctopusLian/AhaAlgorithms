#include<stdio.h>
int main()
{
	int a[10],i,total=0,book[10],sum;  //这里用a[1]-a[9]来代替刚才的a~i
	for(a[1]=1;a[1]<=9;a[1]++)
		for(a[2];a[2]<=9;a[2]++)
			for(a[3];a[3]<=9;a[3]++)
				for(a[4];a[4]<=9;a[4]++)
					for(a[5];a[5]<=9;a[5]++)
						for(a[6];a[6]<=9;a[6]++)
							for(a[7];a[7]<=9;a[7]++)
								for(a[8];a[8]<=9;a[8]++)
									for(a[9];a[9]<=9;a[9]++)
									{
										for(i=1;i<=9;i++)  //初始化数组
											book[i]=0;
										for(i=1;i<=9;i++)  //如果某个数出现过就标记一下
											book[a[i]]=1;
										sum=0;
										for(i=1;i<=9;i++)
											sum+=book[i];  //统计供出现了多少个不同的数 
										if(sum==9&&a[1]*100+a[2]*10+a[3]+a[4]*100+a[5]*10+a[6]==a[7]*100+a[8]*10+a[9])
										{
											total++;
											printf("%d%d%d+%d%d%d=%d%d%d\n",a[1],a[2],a[3],a[4],a[5],a[6],a[7],a[8],a[9]);
										} 
									}
	printf("total=%d",total/2);
	return 0;
}
