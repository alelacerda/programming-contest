#include <bits/stdc++.h>
using namespace std;
#define MAX 512345
typedef pair<int,int> ii;
typedef long long ll;

ii point[MAX];
ll freq[MAX];
int n,p,q;
int bit[MAX];

void cordcomp(void)
{
    map<ll,int> comp;
    int indx = 0;
    for(int i = 1; i <=n; i++)
    {
        freq[i] =(ll)q * point[i].second - (ll)p * point[i].first;
        comp[freq[i]] = 0;
    }
    for(auto &j: comp)
        j.second = ++indx;
    for(int i = 1; i <= n; i++)
        freq[i] = comp[freq[i]];
}

void update(int i, int v)
{
    while(i < MAX)
    {
        bit[i] += v;
        i += i&-i;
    }
}

int sum(int i)
{
    int ans = 0;
    while(i > 0)
    {
        ans += bit[i];
        i -= i&-i;
    }
    return ans;
}

int main(void)
{
    ll ans = 0;
    scanf("%d %d %d",&n,&p,&q);
    if(q<0)
    {
        p *= -1; q *= -1;
    }
    for(int i = 1; i <= n; i++) 
        scanf("%d %d",&point[i].first, &point[i].second);
    sort(point+1, point+n+1);
    cordcomp();
    
    for(int i = 1; i <=n; i++)
    {
        ans += (ll)sum(freq[i]);
        update(freq[i],1);
    }
    printf("%lld\n",ans);
    return 0;
}