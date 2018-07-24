//模拟题
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX 105
using namespace std;

struct node{
	int a,b,c;
} p[MAX];

int judge(node p, int num)
{
	int a = p.a,b = p.b,c = p.c;
	int cnt;
	int x[5],y[5],mark[5];
	memset(mark, 0, sizeof(mark));
	
	x[0] = a/1000;
	x[1] = (a/100)%10;
	x[2] = (a/10)%10;
	x[3] = a%10;
	y[0] = num/1000;
	y[1] = (num/100)%10;
	y[2] = (num/10)%10;
	y[3] = num%10;
	
	//判断是不是在同一个位置
	cnt = 0;
	for(int i=0; i<4; i++)
	{
		if(x[i]==y[i])
		{
			cnt ++;	
		}	
	}

	if(cnt!=c)
	{
		return 0;
	} 
	
	//判断有几个一样的数
	cnt = 0;
	for(int i=0; i<4; i++)
	{
		for(int j=0; j<4; j++)
		{
			if(x[i]==y[j] && mark[j]==0)
			{
				cnt ++;
				mark[j]=1;
				break;
			}
		}
	}

	if(cnt!=b)
	{
		return 0;
	} 

	return 1; 
}

int main()
{
	int n,flag,res,cnt;
	while(~scanf("%d", &n) && n)
	{
		for(int i=0; i<n; i++)
		{
			scanf("%d %d %d", &p[i].a, &p[i].b, &p[i].c);
		}
		
		cnt = 0;
		flag = 1;
		for(int i=1000; i<=9999; i++)
		{
			for(int j=0; j<n; j++)
			{
				flag = judge(p[j], i);
				
				if(flag==0)
				{
					break;
				}
			}
		
			if(flag==1)
			{
				res = i;
				cnt ++;
			}
		}

		if(cnt==1)
		{
			printf("%d\n", res);
		}
		else
		{
			printf("Not sure\n");
		}
	}
	return 0;
} 