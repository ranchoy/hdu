#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define INF 0x7f7f7f7f
using namespace std;

struct node {
	char name[105];
	int dead,need;	
} work[20];

struct list {
	int score,cur_time,past,cur_work_idx;// 结果，当前时间，上一个状态，当前完成的作业下标 
} dp[1<<15];

void print(int n)
{
	if(dp[n].cur_work_idx == -1)
	{
		return;
	}
	else
	{
		print(dp[n].past);
		
		printf("%s\n", work[dp[n].cur_work_idx].name);
	}
}

int main()
{
	int cnt,n;
	int end,past,cur_score,cur_work;
	scanf("%d", &cnt);
	while(cnt--)
	{
		// 初始化
		memset(dp, 0, sizeof(dp)); 
		dp[0].cur_work_idx = -1;// 递归结束条件 
		
		scanf("%d", &n);
		for(int i=0; i<n; i++)
		{
			scanf("%s %d %d", work[i].name, &work[i].dead, &work[i].need);
		}

		end = (int)(1<<n) - 1;// 最终状态，作业全1
		for(int i=1; i<=end; i++)
		{
			dp[i].score = INF;
			for(int j=n-1; j>=0; j--)
			{
				cur_work = 1<<j;
				if(i & cur_work)// i状态下要完成作业j 
				{
					past = i - cur_work;// 上一个状态
					cur_score = dp[past].cur_time + work[j].need - work[j].dead;
					if(cur_score < 0)
					{
						cur_score = 0;
					}
					if(dp[i].score > dp[past].score + cur_score) 
					{
						dp[i].score = dp[past].score + cur_score;
						dp[i].cur_time = dp[past].cur_time + work[j].need;
						dp[i].past = past;
						dp[i].cur_work_idx = j;
					}
				}
			}	
		} 
		
		printf("%d\n", dp[end].score);
		print(end);
	}
	return 0;
} 

/*
2
3
Computer 3 3
English 20 1
Math 3 2
3
Computer 3 3
English 6 3
Math 6 3

2
Computer
Math
English
3
Computer
English
Math
*/