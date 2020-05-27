#include <bits/stdc++.h>

int main()
{
    int n,m;
    char a[7];

    scanf(" %d %d", &n,&m);
    for(int i = 0; i < m; i++)
    {
        scanf(" %s", a);
        if(!strcmp(a,"fechou")) n ++;
        else if(!strcmp(a,"clicou")) n--;
    }
    printf("%d\n", n);
    return 0;
}