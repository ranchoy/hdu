#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#define LL long long
using namespace std;

set<int> st;

int main()
{
	__int64 cnt,n,a,b,res;
	scanf("%d", &cnt);
	while(cnt--)
	{
		res = 1;
		st.clear();
		scanf("%I64d", &n);
		while(n--)
		{
			scanf("%d", &a);
			if(st.count(a))	
			{
				res ++;
				st.clear();
			}
			st.insert(a);
		}	
		
		cout << res << endl;
	} 
	return 0;
}