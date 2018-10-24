// 参考：https://blog.csdn.net/qq_31607947/article/details/76561168
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
	int m,n,res;
	int cm,cn,lm,ln,rm,rn;
	while(~scanf("%d %d", &m, &n))
	{
		cm = (int)ceil(sqrt(m));
		cn = (int)ceil(sqrt(n));
		
		lm = (cm*cm - m)/2 + 1;
		ln = (cn*cn - n)/2 + 1;
		
		rm = (m - (cm-1)*(cm-1) - 1)/2 + 1;
		rn = (n - (cn-1)*(cn-1) - 1)/2 + 1;
		
		res = abs(cm - cn) + abs(lm - ln) + abs(rm - rn);
		cout << res << endl;
	}
	return 0;	
} 


/*
6 12 

3
*/ 