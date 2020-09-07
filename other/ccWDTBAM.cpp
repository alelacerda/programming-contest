#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int t;
    char ans[1123], c[1123];
    int w[1123];
    int i,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i = 0; i < n; i++)
            scanf(" %c",&ans[i]);
        for(i = 0; i < n; i++)
            scanf(" %c",&c[i]);
        for(i = 0; i < n+1; i++)
            scanf(" %d",&w[i]);

        int cans=0;
        for(i = 0; i < n; i++)
            if(ans[i] == c[i]) cans++;
        if(cans == n)
            printf("%d\n",w[n]);
        else
        {
            int res = 0;
            for(i = 0; i <= cans; i++)
                res = max(res, w[i]);
            printf("%d\n",res);
        }
    }
    return 0;
}