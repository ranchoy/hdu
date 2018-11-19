// https://www.cnblogs.com/FCWORLD/archive/2011/03/12/1982373.html
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX 10005
using namespace std;

int mod[20] = {1,1,2,6,4,2,2,4,2,8,4,4,8,4,6,8,8,6,8,2}; 

int get_last(char *str)
{
	int len = strlen(str);	
	int a[MAX],temp,res=1;
	
	if(len == 1)
	{
		temp = str[0]-'0';
		return mod[temp];
	}
	else
	{
		for(int i=0; i<len; i++)
		{
			a[i] = str[len-1-i] - '0';
		}
		
		for(; len; len-=!a[len-1])
		{
			res = res * mod[a[1]%2*10 + a[0]] % 5;
			temp = 0;
			for(int i=len-1; i>=0; i--)
			{
				temp = temp*10 + a[i];
				a[i] = temp / 5;
				temp %= 5;
			}
		}
		return res + res%2*5;
	}
}

int main()
{
	int res; 
	char str[MAX];
	while(~scanf("%s", str))
	{
		res = get_last(str);
		printf("%d\n", res);
	}
	return 0;
} 

/*
1 
2 
26 
125 
3125 
9999

1
2
4
8
2
8
*/