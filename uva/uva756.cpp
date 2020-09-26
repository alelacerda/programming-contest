#include <bits/stdc++.h>

int inv(int n, int m)
{
    for(int x=1; x <= m; x++)
    {
        if((n * x) % m == 1)
            return x;
    }
}
int main(void)
{
    int c = 0,p,e,i,d;
    int inv23 = inv(28*33,23)*28*33;
    int inv28 = inv(23*33,28)*23*33;
    int inv33 = inv(23*28,33)*23*28;
    while(scanf("%d %d %d %d",&p,&e,&i,&d), p != -1)
    {   
        c++;
        int ans = p*inv23 + e*inv28 + i*inv33 - d;
        ans +=21251;
        ans %=21252;
        printf("Case %d: the next triple peak occurs in %d days.\n",c,ans+1);
    }
    return 0;
}