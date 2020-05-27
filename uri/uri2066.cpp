#include <bits/stdc++.h>
#define ll long long

ll pal(int x)
{
    x /= 2LL;
    ll ans = 9;
    for(int i = 1; i < x; i++) ans*= 10LL;
    return ans;
}

int main()
{
    ll ans[20];
    ans[1] = 0LL;
    ans[2] = 36LL;
    for(int i = 3; i <= 18; i++)
    {
        if(i%2 == 1)
        {
            ans[i] = ans[i-1]*10LL;
        }
        else
        {
            ans[i] = ans[i-2]*100LL;
            ans[i] += 45LL * pal(i-2);
        }
        
    }
    int k;
    scanf("%d", &k);
    printf("%lld\n", ans[k]);
}

/*
#define MAX 20

long long pal(int x)
{
    x /= 2LL;
    long long ans;
    for(int i = 1; i < x; i++)
        ans *= 10LL;
    return ans;
}

int main()
{
    int k;
    long long int ans[MAX];
    ans[1] = 0LL;
    ans[2] = 36LL;

    for(int i = 3; i <= 18; i++)
    {
        if(i % 2 == 1) 
            ans[i] = ans[i-1] * 10LL;
        else
        {
            ans[i] = ans[i-2]*100LL;
            ans[i] += 45LL * pal(i-2);
        }

    }
    
    scanf("%d", &k);
    printf("%lld\n", ans[k]);

    return 0;
}

*/