#include <bits/stdc++.h>
using namespace std;

#define MAX 1123456
#define INF 112345678

int main()
{
    int p, a, b, c, d, n;
    double max = -INF, diff = 0;

    scanf("%d %d %d %d %d %d", &p, &a, &b, &c, &d, &n);
    for(int i = 1; i <= n; i++)
    {
        double price = p * (sin(a*i + b) + cos(c*i+ d) + 2);
        if(price > max) {max = price; continue;}
     
       if(max - price > diff) {diff = max - price;}
    }
    if(!diff) printf("%.2lf", diff);
    else printf("%lf\n", diff);
    return 0;
}