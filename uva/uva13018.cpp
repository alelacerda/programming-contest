#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n,m,count=0;
    while(scanf(" %d %d",&n,&m) != EOF)
    {
        if(count++) printf("\n");
        int c[100] = {}, x=0;
        for(int i = 1; i<=n; i++)
            for(int j = 1; j <= m; j++)
                c[i+j]++;
        for(int i = 1; i <= (n+m); i++)
            x = max(x,c[i]);
        for(int i = 1; i <= (n+m); i++)
        {
            if(c[i] == x) printf("%d\n",i);
        }
    }
    return 0;
}