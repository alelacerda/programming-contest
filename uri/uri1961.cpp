#include <bits/stdc++.h>

int main(void)
{
    int p, n, h1,h2, f = 0;
    scanf(" %d %d", &p, &n);
    scanf(" %d",&h1);
    while(--n)
    {
        scanf(" %d",&h2);
        if(abs(h1-h2)>p) f =1;
        h1 = h2;
    }
    printf("%s\n",f?"GAME OVER":"YOU WIN");
    return 0;
}