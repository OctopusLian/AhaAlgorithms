#include<stdio.h>
int dis[7],book[7]={0};
int h[7],pos[7],size;

void swap(int x,int y)
{
	int t;
	t=h[x];
	h[x]=h[y];
	h[y]=t;
	
	//同步更新pos
	t=pos[h[x]];
	pos[h[x]]=pos[h[y]];
	pos[h[y]]=t;
	return; 
 } 
 
 void siftdown(int i)
 {
 	int t,flag=0;
 	while(i*2<=size && flag==0)
 	{
 		//比较i和它左儿子i*2在dis中的值，并用t记录值较小的结点编号 
 		if(dis[h[i]] > dis[h[i*2]])
 			t=i*2;
 		else
 			t=i;
 		//如果它有右儿子，再对右儿子进行讨论 
 		if(i*2+1 <= size)
 		{
 			//如果右儿子的值更小，更新较小的结点编号
			 if(dis[h[t]] > dis[h[i*2+1]])
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
 
 void siftup(int i)
 {
 	int flag=0;
 	if(i==1) return;
 	while(i!=1 && flag==0)
 	{
 		if(dis[h[i]] < dis[h[i/2]])
 			swap(i,i/2);
 		else
 			flag=1;
 		i=i/2;
	 }
	 return;
 }
 
 int pop()
 {
 	int t;
 	t=h[1];
 	pos[t]=0;
 	h[1]=h[size];
 	pos[h[1]]=1;
 	size--;
 	siftdown(1);
 	return t;
 }
 
 int main()
 {
 	int n,m,i,j,k;
 	int u[19],v[19],w[19],first[7],next[19];
 	int inf=99999999;
 	int count=0,sum=0;
 	
 	scanf("%d %d",&n,&m);
 	
 	for(i=1;i<=m;i++)
 		scanf("%d %d %d",&u[i],&v[i],&w[i]);
 		
 	for(i=m+1;i<=2*m;i++)
 	{
 		u[i]=v[i-m];
 		v[i]=u[i-m];
 		w[i]=w[i-m];
	 }
	 
	 for(i=1;i<=n;i++)
	 	first[i]=-1;
	
	 for(i=1;i<=2*m;i++)
	 {
	 	next[i]=first[u[i]];
	 	first[u[i]]=i;
	 }
	 
	 book[1]=1;
	 count++;
	 
	 dis[1]=0;
	 for(i=2;i<=n;i++)
	 	dis[i]=inf;
	 k=first[1];
	 while(k!=-1)
	 {
	 	dis[v[k]]=w[k];
	 	k=next[k];
	 }
	 
	 size=n;
	 for(i=1;i<=size;i++)
	 {
	 	h[i]=i;
	 	pos[i]=i;
	 }
	 for(i=size/2;i>=1;i--)
	 {
	 	siftdown(i);
	 }
	 pop();
	 
	 while(count<n)
	 {
	 	j=pop();
	 	book[j]=1;
	 	count++;
	 	sum=sum+dis[j];
	 	
	 	k=first[j];
	 	while(k!=-1)
	 	{
	 		if(book[v[k]]==0 && dis[v[k]]>w[k])
	 		{
	 			dis[v[k]]=w[k];
	 			siftup(pos[v[k]]);
			 }
			 k=next[k];
		 }
	 }
	 
	 printf("%d",sum);
	 
	 getchar();getchar();
	 return 0;
 }
