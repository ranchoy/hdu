#include<iostream>
#include<cstdio>
#include<cstring>
#define MAX 30
using namespace std;

char str[MAX];

bool is_yuan(char ch)
{
    char temp[5] = {'a', 'e', 'i', 'o', 'u'};
    for(int i=0; i<5; i++)
    {
        if(ch == temp[i])
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int len;
    bool a,b,c;
    while(~scanf("%s", str) && strcmp(str, "end")!=0)
    {
        // 初始化
        len = strlen(str);
        a = b = c = false;

        // 有元音字母
        for(int i=0; i<len; i++)
        {
            if(is_yuan(str[i]))
            {
                a = true;
                break;
            }
        }

        // 不能三个连续元音|辅音
        for(int i=1; i<len-1; i++)
        {
            if(is_yuan(str[i-1]) && is_yuan(str[i]) && is_yuan(str[i+1]))
            {
                b = true;
                break;
            }

            if(!is_yuan(str[i-1]) && !is_yuan(str[i]) && !is_yuan(str[i+1]))
            {
                b = true;
                break;
            } 
        }

        // 不能连续两个相同的字母，除非ee或oo
        for(int i=0; i<len-1; i++)
        {
            if(str[i]==str[i+1] && (str[i]!='e'&&str[i+1]!='e') && (str[i]!='o'&&str[i+1]!='o'))
            {
                c = true;
                break;
            }
        }

        if(a==true && b==false && c==false)
        {
            printf("<%s> is acceptable.\n",str);
        }
        else
        {
            printf("<%s> is not acceptable.\n",str);
        }
    }
}

/*
a
tv
ptoui
bontres
zoggax
wiinq
eep
houctuh
end

<a> is acceptable.
<tv> is not acceptable.
<ptoui> is not acceptable.
<bontres> is not acceptable.
<zoggax> is not acceptable.
<wiinq> is not acceptable.
<eep> is acceptable.
<houctuh> is acceptable.

*/