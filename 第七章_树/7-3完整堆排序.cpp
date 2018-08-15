#include<stdio.h>
int h[101];
int n;

void swap(int x,int y)
{
	int t;
	t=h[x];
	h[x]=h[y];
	h[y]=t;
	return;
 } 
 
//向下调整函数
void siftdown(int i)
{
	int t,flag=0;
	while(i*2<=n && flag==0)
	{
		if(h[i] > h[i*2])
			t=i*2;
		else
			t=i;
		//如果它有右儿子，再对右儿子进行讨论 
		if(i*2+1 <= n)
		{
			if(h[t] > h[i*2+1])
				t=i*2+1;
		}
		//如果发现最小的结点编号不是自己，说明子结点中有比父节点更小的
		if(t!=i)
		{
			swap(t,i);
			i=t;
		 } 
		else
			flag=1;
	}
	return;
 } 
 
//建立堆的函数
void creat()
{
	int i;
	for(i=n/2;i>=1;i--)
	{
		siftdown(i);
	}
	return;
 } 
 
 //堆排序
 void heapsort()
 {
 	while(n>1)
 	{
 		swap(1,n);
 		n--;
 		siftdown(1);
	 }
	 return;
  } 
  
  int main()
{
	int i,num;
	scanf("%d",&num);
	
	for(i=1;i<=num;i++)
		scanf("%d",&h[i]);
	n=num;
	creat();
	
	heapsort();
	
	for(i=1;i<=num;i++)
		printf("%d ",h[i]);
	
	getchar();
	getchar();
	return 0;
}
