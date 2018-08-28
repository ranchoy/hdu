/**
1.取出这些砖块的最大高度和第二大高度
2.第二大高度乘上最大高度和第二大高度之间的距离，再减去中间的砖块，得出最大高度和第二大高度之间可以注入多少水
3.分别向最大高度和第二大高度之外的部分递归，得出最后的值
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX 1005
using namespace std;

int arr[MAX],res=0;

void solve(int start, int end)
{
	int first=0,second=0;
	int first_idx=0,second_idx=0;
	
	if(end - start <= 1)
	{
		return;
	}
	
	for(int i=start; i<=end; i++)
	{
		if(arr[i] > first)
		{
			second = first;
			second_idx = first_idx;
			first = arr[i];
			first_idx = i;
		}
		else if(arr[i] > second)
		{
			second = arr[i];
			second_idx = i;
		}
	}
	
	first = arr[first_idx];
	second = arr[second_idx];
	//获取左侧墙的索引
	int start_idx = min(first_idx, second_idx);
	//获取右侧墙的索引
	int end_idx = max(first_idx, second_idx);
	//计算距离
    int dist = end_idx - start_idx;
	if(dist > 1)
	{
		res = res + (dist - 1) * second;
		//减去这两堵墙之间的砖数
		for(int i=start_idx+1; i<end_idx; i++)
		{
			res -= arr[i];
		}
	}
	//开始递归处理左侧墙距离开始位置能放多少水
	solve(start, start_idx);
	//开始递归处理右侧墙距离结束位置能放多少水
	solve(end_idx, end);
}

int main()
{
	int cnt,n;
	cin >> cnt;
	while(cnt--)
	{
		//初始化
		res = 0;
		memset(arr, 0, sizeof(arr)); 
		cin >> n;
		for(int i=0; i<n; i++)
		{
			scanf("%d", &arr[i]);
		}

		solve(0, n-1);
		printf("%d\n", res);
	}
	return 0;	
} 
/**
4
9
2 5 1 2 3 4 7 7 6
10

10
2 5 1 3 1 2 1 7 7 6
17

9
6 1 4 6 7 5 1 6 4
13

9
9 6 1 2 3 4 50 1 9
37
*/