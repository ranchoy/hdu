#include<iostream>
#include<cstdio>
#include<cstring>
#define MAX 105
using namespace std;

int arr[MAX][MAX];

//h(n) = h(n-1)*(4*n-2)/(n+1);
void catelan()
{
	int len,yu,temp;
	arr[1][0] = arr[1][1] = 1;
	arr[2][0] = 1;
    arr[2][1] = 2;
	len = 1;
	for(int i=3; i<=105; i++)
	{
		yu = 0;
		for(int j=1; j<=len; j++) //大数乘法 
		{
			temp = arr[i-1][j]*(4*i-2) + yu; //h(n)是由h(n-1)来的 
			yu = temp/10;
			arr[i][j] = temp%10;
		}
		while(yu)
		{
			arr[i][++len] = yu%10;
			yu /= 10; 
		} 
		
		for(int j=len; j>=1; j--) //大数除法 
		{
			temp = arr[i][j] + yu*10;
			arr[i][j] = temp/(i+1);
			yu = temp%(i+1);
		}
		while(arr[i][len]==0)
		{
			len --;
		}
		arr[i][0] = len;//a[i][0]存长度
	}
}

int main()
{
	catelan();
    int n;
	while(~scanf("%d", &n))
	{
		for(int i=arr[n][0]; i>=1; i--)
		{
			printf("%d",arr[n][i]);	
		} 
		printf("\n");
	}
	return 0;	
} 