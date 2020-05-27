#include <bits/stdc++.h>

int main()
{
    int s,t,f,ans;
    scanf(" %d %d %d",&s,&t,&f);
    if(s == 0) s = 24;
    ans = s +t +f;
    if(ans >=24) ans -=24;
    printf("%d\n",ans);
    return 0;
}