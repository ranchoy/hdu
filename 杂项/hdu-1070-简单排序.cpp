#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX 105
#define INF 0x7f7f7f7f
using namespace std;

struct node {
	char name[MAX];
	int p,v;
	double w;// 每天单价 
} mk[MAX]; 

bool cmp(struct node a, struct node b)
{
	if(a.w < b.w)
	{
		return true;
	}
	else if(a.w == b.w)
	{
		return a.v > b.v;
	}
	return false;
}

int main()
{
	int cnt,n,k;
	scanf("%d", &cnt);
	while(cnt--)
	{
		// 初始化
		k = 0;
		scanf("%d", &n);
		while(n--)
		{
			scanf("%s %d %d", mk[k].name, &mk[k].p, &mk[k].v);
			if(mk[k].v >= 200)
			{
				if(mk[k].v >= 1000)
				{
					mk[k].w =  mk[k].p / 5;
				}
				else if(mk[k].v < 1000)
				{
					mk[k].w = mk[k].p / (mk[k].v/200);
				}
				k ++;
			}
		}
		
		sort(mk, mk+k, cmp);
		printf("%s\n", mk[0].name);
	} 
	return 0;
}
/*
2
2
Yili 10 500
Mengniu 20 1000
4
Yili 10 500
Mengniu 20 1000
Guangming 1 199
Yanpai 40 10000

Mengniu
Mengniu
*/ 