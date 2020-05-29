#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int k, n, x,first;
    int ans[112345];
    
    while(scanf("%d %d",&k,&n) != EOF)
    {
        memset(ans, 0, sizeof(ans));
        first = 1;
        while(k--)
        {
            scanf("%d",&x);
            if(!ans[x])
            {
                if(!first) printf(" ");
                if(first) first = 0;
                printf("%d",x);
                ans[x] = 1;
            }
        }
        printf("\n");
    }
    return 0;
}