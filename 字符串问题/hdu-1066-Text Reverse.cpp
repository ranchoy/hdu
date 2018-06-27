//字符串处理问题
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX 1010
using namespace std;

char str[MAX];
int arr[MAX];

int main()
{
	
	int cnt,len,j; 
	scanf("%d", &cnt);
	getchar();
	while(cnt--)
	{	
		memset(arr, 0, sizeof(arr));
		gets(str);

		len = strlen(str);
		j = 0;
		arr[0] = 0;
		for(int i=0; i<len; i++)
		{
			if(str[i]==' ')
			{
				arr[++j] = i; 
			}
		}
		arr[++j] = len;
		
		for(int i=arr[1]-1; i>=0; i--)
		{
			printf("%c", str[i]);
		}
		if(j>1)
		{
			for(int i=2; i<=j; i++)
			{
				cout << " ";
				for(int k=arr[i]-1; k>=arr[i-1]+1; k--)
				{
					cout << str[k];
				}
			}
		}
		cout << endl;	
	}
	return 0;
}