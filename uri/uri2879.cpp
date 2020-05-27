#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n,ans=0,x;
    scanf(" %d", &n);
    while(n--)
    {
        scanf(" %d",&x);
        if(x != 1) ans++;
    }
    printf("%d\n", ans);
    return 0;
}