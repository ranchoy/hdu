#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

double a,b,c,k,d;
double jifen(double x)
{
	return a*x*x*x/3 - (2*a*b+k)*x*x/2 + (a*b*b+c-d)*x;
}

int main()
{
	int cnt;
	double x1,x2,x3,y1,y2,y3;
	
	cin >> cnt;
	while(cnt--)
	{
		scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3);
		//y = a(x-b)^2 + c
		//y = kx + d;
		b = x1;
		c = y1;
		a = (y2-y1)/( (x2-b)*(x2-b) );
		k = (y3-y2)/(x3-x2);
		d = y2 - k*x2;
		printf("%.2lf\n", jifen(x3) - jifen(x2)); 
	}
	return 0;
}