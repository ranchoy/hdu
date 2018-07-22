//博弈题目，你可以跳到下个月或者下一天（两个人比赛），如果先手者先到达2001-11-4则YES,否则NO 
//注意到2001-11-4中11+4为奇数，不论加月数还是天数(m+d奇偶不断变化)
//有特殊时间9-30和11-30奇偶性不变
//只要保证轮到先手者那天为偶数就行了 
#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int cnt,y,m,d;
	cin >> cnt;
	while(cnt--)
	{
		scanf("%d %d %d", &y, &m, &d);
		
		if((m+d)%2==0 || (d==30&&(m==9||m==11)))
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
	return 0;
}