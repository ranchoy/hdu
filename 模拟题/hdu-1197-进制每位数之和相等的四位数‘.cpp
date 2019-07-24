// 输出使得十进制，十二进制，十六进制的每一位数字之和相等的四位数
#include<iostream>
using namespace std;

int change(int n,int m)
{
    int temp,res=0;
    while(n)
    {
        temp = n % m;
        res += temp;
        n = n / m;
    }
    return res;
} 

int main()
{
    int a,b,c;
    for(int i=1000; i<10000; i++)
    {
        a = change(i, 10);
        b = change(i, 12);
        c = change(i, 16);
        if(a==b && b==c)
        {
            printf("%d\n", i);
        }
    }
}