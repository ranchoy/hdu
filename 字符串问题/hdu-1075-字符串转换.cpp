#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<algorithm>
using namespace std;

string a,b;
map<string, string> mp;

int main()
{
    char str[3005];

    cin >> a;
    while(cin >> a)
    {
        if(a == "END")
        {
            break;
        }
        cin >> b;
        mp[b] = a;
    }

    cin >> a;
    getchar();
    while(true)
    {
        gets(str);
		if(strcmp(str, "END") == 0)
		{
			break;
		}
		a = "";
        for(int i=0; i<strlen(str); i++)
        {
            if(islower(str[i]))
            {
                a += str[i];
            }
            else
            {
                if(mp.find(a) != mp.end())
                {
                    cout << mp[a];
                }
                else
                {
                    cout << a;
                }
                a = "";
                cout << str[i];
            }
        }
        cout << endl;
    }
    return 0;
}

/*
START
from fiwo
hello difh
mars riwosf
earth fnnvk
like fiiwj
END
START
difh, i'm fiwo riwosf.
i fiiwj fnnvk!
END

hello, i'm from mars.
i like earth!
*/