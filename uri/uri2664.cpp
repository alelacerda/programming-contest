#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int main(void)
{
    int t, m, n;
    long long ans = 0, dp[2][112345];
    scanf("%d %d %d",&t, &m, &n);
    int range = n - m + 1;
    for(int i = 0; i < range; i++) dp[0][i] = 1;
    int cur = 1;
    for(int i = 1; i < t; i++)
    {
        for(int j = 1; j < range - 1; j++)
            dp[cur][j] = (dp[1-cur][j-1] + dp[1-cur][j+1])%MOD;
        dp[cur][0] = dp[1-cur][1];
        dp[cur][range-1] = dp[1-cur][range-2];
        cur = 1- cur;
    }

    for(int i = 0; i < range; i++)
        ans = (ans+dp[1-cur][i])%MOD;
    printf("%lld\n",ans);

    return 0;
}