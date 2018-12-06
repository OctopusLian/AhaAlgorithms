#include<stdio.h>
struct queue{
	int data[1000];  //数组data用来存储队列中的元素 
	int head;  //head用来存储队头 
	int tail;  //tail用来存储队尾 
}; 

struct stack{
	int data[10];  //数组data用来存储栈中的元素 
	int top;  //top用来存储栈顶 
};

int main()
{
	struct queue q1,q2;  //q1用来模拟小哼手中的牌,q2用来模拟小哈手中的牌 
	struct stack s;  //栈变量s用来模拟桌上的牌 
	int book[10];
	int i,t;
	/*初始化队列q1和q2为空，因为此时两人手中都还没有牌*/ 
	q1.head=1;q1.tail=1;
	q2.head=1;q2.tail=1;
	s.top=0;  //初始化栈s为空，因为最开始的时候桌上也没有牌 
	for(i=1;i<=9;i++)
		book[i]=0;
	for(i=1;i<=6;i++){  //先读入6张牌，放到小哼手上 
		scanf("%d",&q1.data[q1.tail]);  //读入一个数到队尾 
		q1.tail++;  //队尾往后挪一位 
	}
	
	for(i=1;i<=6;i++){  //再读入6张牌，放到小哈手上 
		scanf("%d",&q2.data[q2.tail]);
		q2.tail++;
	}
	
	while(q1.head<q1.tail && q2.head<q2.tail){  //当队列不为空的时候执行循环 
		t=q1.data[q1.head];  //小哼先亮出一张牌 
		if(book[t]==0)   
		{
			q1.head++;  //小哼已经打出一张牌，所以要把打出的牌出队 
			s.top++;
			s.data[s.top]=t;  //再把打出的牌放到桌上，即入栈 
			book[t]=1;
		}
		else
		{
			q1.head++;  //小哼已经打出一张牌，所以要把打出的牌出队 
			q1.data[q1.tail]=t;  //因为此轮可以赢牌，所以紧接着把刚才打出的牌又放到手中牌的末尾 
			q1.tail++;
			while(s.data[s.top]!=t)  //把桌上可以赢得的牌依次放到手中牌的末尾 
			{
				book[s.data[s.top]]=0;  //取消标记
				q1.data[q1.tail]=s.data[s.top];  //依次放入队尾 
				q1.tail++;
				s.top--;   //栈中少了一张牌，所以栈顶要减1 
			}
			book[s.data[s.top]]=0;
			q1.data[q1.tail]=s.data[s.top];
			q1.tail++;
			s.top--;
		}
		if(q1.head==q1.tail) break;
		
		t=q2.data[q2.head];
		if(book[t]==0)
		{
			q2.head++;
			s.top++;
			s.data[s.top]=t;
			book[t]=1;
		}
		else
		{
			q2.head++;
			q2.data[q2.tail]=t;
			q2.tail++;
			while(s.data[s.top]!=t)
			{
				book[s.data[s.top]]=0;
				q2.data[q2.tail]=s.data[s.top];
				q2.tail++;
				s.top--;
			}
			book[s.data[s.top]]=0;
			q2.data[q2.tail]=s.data[s.top];
			q2.tail++;
			s.top--;
		}
	}
	if(q2.head==q2.tail)//如果小哼获胜那么小哈手中一定没有牌了（队列q2为空） 
	{
		printf("小哼win\n");
		printf("小哼当前手中的牌是");
		for(i=q1.head;i<=q1.tail-1;i++)
			printf(" %d",q1.data[i]);
		if(s.top>0)  //如果桌上有牌则依次输出桌上的牌 
		{
			printf("\n桌上的牌是");
			for(i=1;i<=s.top;i++)
				printf(" %d",s.data[i]);
		}
		else
			printf("\n桌上已经没有牌了");
	}
	else
	{
		printf("小哈win\n");
		printf("小哈当前手中的牌是");
		for(i=q2.head;i<=q2.tail-1;i++)
			printf(" %d",q2.data[i]);
		if(s.top>0)
		{
			printf("\n桌上的牌是");
			for(i=1;i<=s.top;i++)
				printf(" %d",s.data[i]);
		}
		else
			printf("\n桌上已经没有牌了");
	} 
	return 0;
}
