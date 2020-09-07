#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int l,v;
    while(scanf("%d",&l) != EOF)
    {
        int ans = 0;
        while(l--)
        {
            scanf("%d",&v);
            if(v > ans) ans = v;
        }
        if(ans >= 20)
            printf("3\n");
        else if(ans >= 10)
            printf("2\n");
        else
            printf("1\n");        
    }
    return 0;
}