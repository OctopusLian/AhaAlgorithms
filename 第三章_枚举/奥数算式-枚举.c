#include<stdio.h>
int main()
{
	int a,b,c,d,e,f,g,h,i,total=0;
	for(a=1;a<=9;a++)  //第1个数的百位
		for(b=1;b<=9;b++)  //第1个数的十位
			for(c=1;c<=9;c++)  //第1个数的个位
				for(d=1;d<=9;d++)  //第2个数的百位
					for(e=1;e<=9;e++)  //第2个数的十位
						for(f=1;f<=9;f++)  //第2个数的个位
							for(g=1;g<=9;g++)  //第3个数的百位
								for(h=1;h<=9;h++)  //第3个数的十位
									for(i=1;i<=9;i++)  //第3个数的个位 
	{  //接下来要判断每一位上的数互不相等 
		if(a!=b && a!=c && a!=d && a!=e && a!=f && a!=g && a!=h && a!=i
		&& b!=c && b!=d && b!=e && b!=f && b!=g && b!=h && b!=i
		&& c!=d && c!=e && c!=f && c!=g && c!=h && c!=i
		&& d!=e && d!=f && d!=g && d!=h && d!=i
		&& e!=f && e!=g && e!=h && e!=i
		&& f!=g && f!=h && f!=i
		&& g!=h && g!=i
		&& h!=i
		&& a*100+b*10+c+d*100+e*10+f==g*100+h*10+i)
		{
			total++;
			printf("%d%d%d+%d%d%d=%d%d%d\n",a,b,c,d,e,f,g,h,i);
		}
	}
	printf("total=%d",total/2);  //这是关键
	return 0; 
}
