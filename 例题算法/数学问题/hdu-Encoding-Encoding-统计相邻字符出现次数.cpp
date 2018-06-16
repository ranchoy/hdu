//统计相邻相同字符出现的次数,ABBCCCDDCCC=A2B3C2D3C 
#include<iostream>
#include<cstdio>
#include<cstring>
#define MAX 10005
using namespace std;

char str[MAX];

int main()
{
	int cnt,num;
	cin >> cnt;
	while(cnt--)
	{
		scanf("%s", str);
				
		num = 1;
		for(int i=0; i<strlen(str); i++)
		{
			if(str[i]==str[i+1])	
			{
				num ++;
			}	
			else
			{
				if(num==1)
				{
					printf("%c", str[i]);
				}	
				else
				{
					printf("%d%c", num, str[i]);
				}
				num = 1;
			}			
		}
		printf("\n");
	}
	return 0;
}