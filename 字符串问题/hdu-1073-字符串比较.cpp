#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX 5005
using namespace std;

bool ac,pe,wa;
char a[MAX],b[MAX];
string start,end,src,submit; 


void read(string &s)
{
	s.clear();
	string temp;
	while(getline(cin, temp))
	{
		if(temp != "END")
		{
			s += temp;
			s += "\n";	
		}	
		else
		{
			break;
		}
	}	
} 

void judge(string src, string submit)
{
	int k;
	ac = pe = wa = false;	
	if(src == submit)
	{
		ac = true;
		return;
	}
	
	pe = true;
	k = 0;
	for(int i=0; i<src.length(); i++)
	{
		if(!isspace(src[i]))
		{
			a[k++] = src[i];
		}
	}
	
	k = 0;
	for(int i=0; i<submit.length(); i++)
	{
		if(!isspace(submit[i]))
		{
			b[k++] = submit[i];
		}
	}
	
	if(strcmp(a, b) != 0)
	{
		wa = true;
	}
}
int main()
{
	int cnt;
	cin >> cnt;
	while(cnt--)
	{
		// 初始化
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		 
		cin >> start;
		read(src);
		cin >> start;
		read(submit);
		
		judge(src, submit);
		
		if(ac)
		{
			printf("Accepted\n");
		}
		else if(wa)
		{
			printf("Wrong Answer\n");
		}
		else
		{
			printf("Presentation Error\n");
		}
	}
	return 0;
}

/*
4
START
1 + 2 = 3
END
START
1+2=3
END
START
1 + 2 = 3
END
START
1 + 2 = 3

END
START
1 + 2 = 3
END
START
1 + 2 = 4
END
START
1 + 2 = 3
END
START
1	+	2	=	3
END

Presentation Error
Presentation Error
Wrong Answer
Presentation Error
*/