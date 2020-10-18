#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n,ans,x;
    while(scanf("%d",&n),n)
    {
        scanf("%d",&ans);n--;
        while(n--)
        {
            scanf("%d",&x);
            ans = ans ^ x;
        }
        printf("%s\n", ans? "Yes": "No");
    }
    return 0;
}