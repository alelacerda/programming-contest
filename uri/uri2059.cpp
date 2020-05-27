#include <bits/stdc++.h>

int main()
{
    int p,j1,j2,r,a;
    int sum,ans;
    scanf(" %d %d %d %d %d", &p, &j1, &j2, &r, &a);
    sum = j1 +j2;
    if( !r && !a)
    {
        if(p)
        {
            if(sum%2 == 0) ans = 1;
            else ans = 2;
        }
        else
        {
            if(sum%2 == 0) ans = 2;
            else ans = 1;
        }
        
    }

    else if(r && a) ans = 2;
    else if(r && !a) ans = 1;
    else ans = 1;
    printf("Jogador %d ganha!\n",ans);
    return 0;
}