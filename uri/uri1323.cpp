#include <bits/stdc++.h>



int main()
{
    int n;
    while(scanf("%d", &n), n)
    {
        int ans = 0;
        for(int i = n; i > 0; i--)
        {
            ans += i * i;
        }
        printf("%d\n", ans);
    }
}