#include <bits/stdc++.h>
using namespace std;
#define MAX 11234
typedef long long ll;

struct Building
{
    int h,c;
};

Building b[MAX];
int n;

bool comp(Building a, Building b)
{
    if(a.h == b.h) return a.c < b.c;
    return a.h < b.h;
}
ll func(int x)
{
    ll ans = 0;
    for(int i = 0; i < n; i++)
        ans += abs(b[x].h - b[i].h) * b[i].c;
    
    return ans;
}

ll ts(int l, int r)
{
    int m1, m2;
    
    while( r - l >= 3)
    {
        m1 = (2 * l + r)/3;
        m2 = (l + 2 * r)/3;

        if(func(m1) > func(m2))
            l = m1;
        else
            r = m2;        
    }
    ll ans = func(l);
    while(l <= r)
    {
        ans = min(ans, func(l));
        l++;
    }
    return ans;
}
int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        
        scanf("%d",&n);
        for(int i = 0; i < n; i++)
            scanf("%d",&b[i].h);
        for(int i = 0; i < n; i++)
            scanf("%d",&b[i].c);
        sort(b, b + n,comp);
        printf("%lld\n",ts(0,n-1));
        
    }
    
    return 0;
}