#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int z,i,m,l;
    int c = 1, ans, first;
    while(scanf("%d %d %d %d",&z,&i,&m,&l), z)
    {
        ans = 0;
        l = first = (z*l + i)%m;
        do
        {
            ans++;
            l = (z*l + i)%m;
        } while (l != first);
        
        printf("Case %d: %d\n",c,ans); c++;
    }

    return 0;
}