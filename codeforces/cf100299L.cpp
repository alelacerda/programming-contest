#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int t, k,ans;
    scanf("%d",&t);
    while(t--)
    {
        ans = 2;
        scanf("%d",&k);
        for(int i = 2; i <=k; i++) ans *= 2;
        printf("%d\n",ans -1);
    }
    return 0;
}