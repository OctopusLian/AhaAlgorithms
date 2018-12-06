#include<stdio.h>
struct queue{
	int data[100];  //队列的主体
	int head;  //队首
	int tail;  //队尾 
};

int main()
{
	struct queue q;
	int i;
	/*初始化队列*/
	q.head=1;
	q.tail=1;
	for(i=1;i<=9;i++)
	{
		scanf("%d ",&q.data[q.tail]);  //依次向队列插入9个数 
		q.tail++;
	} 
	
	while(q.head<q.tail)//当队列不为空的时候 执行循环 
	{
		printf("%d ",&q.data[q.head]);  //打印队首并将队首出队
		q.head++;
		q.data[q.tail]=q.data[q.head];  //先将新队首的数添加到队尾
		q.tail++;
		q.head++;  //再将队首出队 
	}
	getchar();getchar();
	return 0; 
} 
