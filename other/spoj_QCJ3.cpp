#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n,s,c;
    scanf("%d",&n);
    for(int i = 0; i <n; i++)
    {
        int ans = 0;
        scanf("%d",&s);
        for(int j = 1; j <= s; j++)
        {
            scanf("%d",&c);
            if(c)
            {
                for(int k = 1; k <= c; k++)
                    ans ^= j;
            }
        }
        printf("%s Wins\n", ans? "Tom" : "Hanks");
    }
    return 0;
}