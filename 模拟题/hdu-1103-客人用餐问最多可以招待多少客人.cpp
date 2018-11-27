// 题意：客人用餐，有x（2人），y（4人），z（6人）三种类型桌子，客人用餐30分钟，可以等待时间<=30分钟，问最多可以招待多少客人
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX 101
using namespace std;

int a[MAX],b[MAX],c[MAX];// a[i]表示1-2客人在位子i在a[i]时候走

int main()
{
    char str[20];
    int x,y,z,res,*time_min;// 时间最早的位子
    int h,m,num,table;
    while(~scanf("%d %d %d", &x, &y, &z) && (x+y+z))
    {
        // 初始化
        res = 0;
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        memset(c, 0, sizeof(c));

        while(scanf("%s", str) && str[0]!='#')
        {
            sscanf(str, "%d:%d", &h, &m);
            m += h * 60;
            scanf("%d", &num);// 新来的人
            
            table = (num&1) ? num+1 : num;
            if(table == 2)
            {
                time_min = min_element(a, a+x);
                if(*time_min <= m+30)
                {
                    if(*time_min <= m)
                    {
                        *time_min = m + 30;// 位子时间按照m+30走
                    }
                    else
                    {
                        *time_min += 30;// num这些人等一会，按照tiem_min+30时走
                    }
                    res += num;
                }
            }
            else if(table == 4)
            {
                time_min = min_element(b, b+y);
                if(*time_min <= m+30)
                {
                    if(*time_min <= m) 
                    {
                        *time_min = m + 30;
                    }
                    else
                    {
                        *time_min += 30;
                    }
                    res += num;
                }
            }
            else
            {
                time_min = min_element(c, c+z);
                if(*time_min <= m+30)
                {
                    if(*time_min <= m) 
                    {
                        *time_min = m + 30;
                    }
                    else
                    {
                        *time_min += 30;
                    }
                    res += num;
                }
            }
        }
        cout << res << endl;
    }
    return 0;
}

/*
1 1 1
10:40 1
10:50 2
11:00 4
#
1 1 1
10:40 1
10:50 2
11:00 2
#
1 2 1
10:30 1
10:40 3
10:50 2
11:00 1
11:20 5
#
0 0 0
*/