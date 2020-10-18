#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int t,n,p;
    scanf("%d",&t);
    while(t--)
    {
        int pos = 0;
        scanf("%d %d",&n, &p);
        int b[21];
        for(int i = 0; i < p; i++)
            scanf("%d", &b[i]);
        
        for(int i = 0; i < (1 << p); i++)
        {
            int sum = 0;
            for(int j = 0; j < p; j++)
            {
                if(i & (1 <<j)) sum += b[j];
            }
            if(sum == n) 
            {
                pos = 1;
                break;
            }
        }
        if(pos) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}