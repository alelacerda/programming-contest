#include <bits/stdc++.h>
using namespace std;
#define MAX 112345
#define LB 1e-4

int n,a;
int c[MAX];

double height(double x)
{
    double ans = 0.;
    for(int i = n- 1; i >=0; i--)
    {
        if(x >= c[i]) break;
        ans += (double) c[i] - x;
    }
    return ans;
}
double calc()
{
    double beg = 0., endd = (double)c[n-1], mid;

    while( beg <= endd)
    {
        mid = (beg + endd)/2.0;
        double h = height(mid);
        if(fabs(h - (double)a) < LB) return mid;

        if(h < a) endd = mid;
        else beg = mid;
    }
    return -1;
}
int main(void)
{

    while(scanf("%d %d",&n,&a), n)
    {
        int sum = 0;
        for(int i = 0; i < n; i++)
        {
            scanf("%d",&c[i]);
            sum += c[i];
        }
        if(sum < a) 
        {
            printf("-.-\n");continue;
        }
        if( sum == a)
        {
            printf(":D\n");continue;
        }
        sort(c, c+n);
        double ans = calc();
        if(ans == -1) printf("-.-\n");
        else printf("%.4lf\n",ans);
    }
    return 0;
}