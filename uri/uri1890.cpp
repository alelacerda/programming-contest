#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int t,c,d,ans,i;
    scanf("%d",&t);
    while(t--)
    {
        ans = 1;
        scanf("%d %d",&c,&d);
        if( c == 0 && d == 0) ans = 0;
        for(i = 0; i < c; i++) ans *=26;
        for(i = 0; i < d; i++) ans *=10;
        printf("%d\n",ans);
    }
    return 0;
}