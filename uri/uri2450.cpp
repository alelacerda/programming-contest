#include <stdio.h>
#include <string.h>

int tab[501][501];

int main()
{
    int n, m;
    int v[501], ans = 1;   

    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m ; j++)
        {
            scanf(" %d",&tab[i][j]);
        }
    }
    for(int i = 0; i < n; i++)
        v[i] = m + i;

    for(int i = 0; i < n; i++)
        for(int j = m-1; j >=0 ; j--)
            if(tab[i][j] != 0)
                v[i] = j;

    for(int i = 1; i < n; i++)
        if(v[i]<= v[i-1])
            ans = 0;
    
    printf("%c\n", ans? 'S': 'N');
    return 0;
}