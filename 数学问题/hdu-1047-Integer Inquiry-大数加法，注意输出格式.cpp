#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
	int cnt,n,m,idx,len,yu,temp,flag;
	int arr[2000];
	char str[105];
	scanf("%d", &cnt);
	while(cnt--)
    {
    	flag = 0;
        // 初始化
        len = 0;
        memset(arr, 0, sizeof(arr)); 
        while(scanf("%s", str) != EOF)
        {
        	flag ++;
        	if(str[0] == '0')
        	{
        		break;
			}
            yu = 0;
            m = strlen(str);
            for(int i=m-1; i>=0; i--)
            {
                idx = m - i - 1;
                temp = arr[idx] + (str[i]-'0') + yu;
                arr[idx] = temp%10;
                yu = temp/10;
            }

            while(yu)
            {
                temp = arr[m] + yu;
                arr[m] = temp%10;
                yu = temp/10;
                m ++;
            }
            len = max(len, m);
        }
        
		if(flag == 1)// 特殊情况0时输出0
		{
			printf("0\n");
		}
		else
		{
			for(int i=len-1; i>=0; i--)
        	{
            	printf("%d", arr[i]);
        	}printf("\n");
		}

        if(cnt != 0)
        {
            printf("\n");
        }
    }
	return 0;
} 

/*
3
0
0

1111
9999
9999
0
21109

123456789012345678901234567890
123456789012345678901234567890
123456789012345678901234567890
0
370370367037037036703703703670
*/