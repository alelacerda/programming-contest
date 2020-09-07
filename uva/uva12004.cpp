#include <bits/stdc++.h>

int main()
{
    int t;
    long long int n;
    scanf("%d", &t);           
    for(int tcase = 1; tcase <= t; tcase++)
    {
        scanf("%lld", &n);
        long long int ans = ((n - 1) * n) / 2;
        if (ans % 2 == 0)
            printf("Case %d: %lld\n", tcase, ans / 2);
        else
            printf("Case %d: %lld/2\n", tcase, ans); 
     }

    return 0;
}

