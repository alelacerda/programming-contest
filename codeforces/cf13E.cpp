#include <bits/stdc++.h>
using namespace std;
#define MAX 112345
int power[MAX],bnext[MAX], cnt[MAX],n,sze,ans,last;

void update(int i)
{
    int ini = i*sze, endd = ini + sze-1;
    if(endd > n) endd = n;
    for(int j = endd; j >= ini; j--)
    {
        if(j+power[j] > endd) 
        {
            bnext[j] = j + power[j];
            cnt[j] = 1; 
        }
        else 
        {
            bnext[j] = bnext[j+power[j]];
            cnt[j] = 1 + cnt[j+power[j]];
        }
    }
}

void query(int i)
{
    ans = 0;
    while(i <= n)
    {
        last = i;
        ans +=cnt[i];
        i = bnext[i];
    }
    while(last+power[last] <= n) last+=power[last];
}
int main(void)
{
    int m;
    scanf("%d %d",&n,&m);
    sze = sqrt(n);
    for(int i = 1; i <=n; i++) 
    {
        scanf(" %d",&power[i]);
        bnext[i] = i;
        cnt[i] = 0;
    }
    for(int i = 0; i <= n/sze; i++) update(i);

    while(m--)
    {
        int x, i, p;
        scanf("%d",&x);
        if( x == 0) 
        {   
            scanf("%d %d",&i,&p);
            power[i] = p;
            update(i/sze);
        }
        else
        {
            scanf("%d",&i);
            query(i);
            printf("%d %d\n",last, ans);
        }   
    }
    return 0;
}