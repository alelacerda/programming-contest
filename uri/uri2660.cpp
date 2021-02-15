#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b)
{
    if( b == 0) return a;
    return gcd(b, a%b);
}
ll lcm(ll a, ll b)
{ 
    return (a/gcd(a,b))*b;
}

int main(void)
{
    int n, l;
    ll t = 1;
    scanf("%d %d", &n, &l);
    for(int i = 0; i < n; i++)
    {
        ll x;
        scanf("%lld",&x);
        t = lcm(t,x);
    }

    int ans = 1;
    ll ans_lcm = t;
    for(int i = 2; i <= l; i++)
    {
        ll j = lcm(t,i);
        if(j <= l && j > ans_lcm)
        {
            ans_lcm = j;
            ans = i;
        }
    }

    printf("%d\n",ans);
    return 0;
}