// 考点：map的使用
#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<algorithm>
using namespace std;

map<string, string> mp;
map<string, string>::iterator it;

int main()
{
    bool flag;
    string s,temp;
    while(cin>>s && s!="XXXXXX")
    {
        temp = s;
        sort(temp.begin(), temp.end());
        mp[s] = temp;
    }

    while(cin>>s)
    {
        flag = false;
        if(s == "XXXXXX") break;

        sort(s.begin(), s.end());
        for(it=mp.begin(); it!=mp.end(); it++)
        {
            if(it->second == s)
            {
                flag = true;
                cout << it->first << endl;
            }
        }

        if(!flag)
            printf("NOT A VALID WORD\n");
        printf("******\n");
    }
    return 0;
}

/*
tarp
given
score
refund
only
trap
work
earn
course
pepper
part
XXXXXX
resco
nfudre
aptr
sett
oresuc
XXXXXX

score
******
refund
******
part
tarp
trap
******
NOT A VALID WORD
******
course
******
*/