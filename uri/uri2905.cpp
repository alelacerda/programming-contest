#include <bits/stdc++.h>
using namespace std;
#define MAX 11234
#define INF 1123456789
typedef long long ll;

int n, d[MAX];
double ans[MAX], c[MAX];

void dp(int i)
{
    if (i == 0) ans[i] = c[i];
    else ans[i] = min(ans[i], ans[i-1]+c[i]);
    int inter = d[i];
    if(inter < 120)
        ans[i+1] = min(ans[i+1],ans[i-1] + c[i] + c[i+1]*0.5);
    double tot = 0;
    inter += d[i+1];
    for(int j = 2; j < 6 && inter < 120; j++)
    {
        tot += c[i + j];
        ans[i+j] = min(ans[i+j], ans[i-1] + c[i] + c[i+1]*0.5 + tot*0.25);
        inter += d[i+j];
    }
}
int main(void)
{
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d %lf",&d[i], &c[i]);
        //c[i] *=100;
        ans[i] = INF;
    }
    for(int i = 0; i < n; i++)
        dp(i);
    
    printf("%.2f\n",ans[n-1]);
    return 0;
}