#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX 210
using namespace std;

int main()
{
	int x,y,dir;
	char str[MAX];
	while(scanf("%s",str)!=EOF)
	{
		x = 300;
		y = 420;
		dir = 1;
		printf("%d %d moveto\n", x, y);
		x = x + 10;
		printf("%d %d lineto\n", x, y);
		for(int i=0; str[i]!='\0'; i++)
		{
			if(str[i]=='A')
			{
				dir = (dir + 1) % 4;
			}
			else if(str[i]=='V')
			{
				dir = (dir - 1) % 4;
			}

            if(dir==0)
            {
                dir = 4;
            }
            switch(dir)
            {
                case 1:
                    x = x + 10;
                    printf("%d %d lineto\n", x, y);
                    break;
                case 2:
                    y = y - 10;
                    printf("%d %d lineto\n", x, y);
                    break;
                case 3:
                    x = x - 10;
                    printf("%d %d lineto\n", x, y);
                    break;
                case 4:
                    y = y + 10;
                    printf("%d %d lineto\n", x, y);
                    break;
                default:
                    break; 
            }
		}
		printf("stroke\nshowpage\n");
	}
	return 0;	
} 