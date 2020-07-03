#include <bits/stdc++.h>

#define ll long long int

int ans;

ll getR(ll n)
{
    while(n % 2 == 0) n /= 2;
    return n;
}

void shifts(ll a, ll b)
{
    ll r = getR(a);
    if(getR(b) != r)
        ans = -1;
    else
    {
        b /= a;
        while(b >= 8)
        {
            b /= 8;
            ans++;
        }
        if(b > 1) ans++;
    }
    
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        ll a, b;
        scanf("%lli %lli", &a, &b);
        ans = 0;
        a > b ? shifts(b, a) : shifts(a, b);

        printf("%d\n", ans);
    }

    return 0;
}