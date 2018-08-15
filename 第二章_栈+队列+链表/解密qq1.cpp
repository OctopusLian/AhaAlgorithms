#include<stdio.h>
int main()
{
	int q[102]={0,6,3,1,7,5,8,9,2,4},head,tail;
	/*初始化队列*/
	head=1;
	tail=10;  //队列中已经有9个元素了，tail指向队尾的后一个位置
	while(head<tail)  //当队列不为空的时候执行循环
	{
		printf("%d ",q[head]);  //打印队首并将队首出队
		head++;
		
		q[tail]=q[head];  //先将新队首的数添加到队尾
		tail++;
		head++;  //再将队首出队 
	} 
	return 0;
}
