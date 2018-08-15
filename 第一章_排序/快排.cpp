#include<stdio.h>
int a[10],n;  //定义全局变量
void quicksort(int left,int right)
{
	int i,j,t,temp;
	if(left>right)
		return;
	
	temp=a[left];  //temp中存的基准数
	i=left;
	j=right;
	while(i!=j)
	{
		while(a[j]>=temp && i<j)  //顺序很重要，要先从右往左找
			j--;
		while(a[i]<=temp && i<j)  //再从左往右找
			i++;
		/*交换两个数在数组中的位置*/
		if(i<j)  //当哨兵i和哨兵j没有相遇时
		{
			t=a[i];
			a[i]=a[j];
			a[j]=t;
		} 
	} 
	/*最终将基准数归位*/
	a[left]=a[i];
	a[i]=temp;
	
	quicksort(left,i-1);  //继续处理左边的，这里是一个递归的过程
	quicksort(i+1,right);  //继续处理右边的，这里是一个递归的过程
	return; 
} 

int main()
{
	int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	
	quicksort(1,n);  //快速排序调用
	for(i=1;i<=n;i++)
		printf("%d ",a[i]);  //输出排序后的结果
		
	return 0; 
}
