#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t,d,m;
    long long ans;
    scanf(" %d", &t);
    while(t--)
    {
        scanf(" %d %d",&d,&m);
        ans = 1;
        for(int i = 0; i <30; i++)
        {
            if(d<(1 << i)) break;
            ans = ans * (min((1 << (i+1)) - 1, d) - (1 << i) + 2) % m;
        }
        ans--;
        if(ans <0) ans+=m;
        printf("%lld\n",ans);
    }
    return 0;
}