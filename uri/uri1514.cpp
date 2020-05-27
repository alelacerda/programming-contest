#include <stdio.h>
#include <string.h>

int main()
{
    int n, m, soma, f1, f2, f3, f4;
    int tab[101][101];

    while(scanf("%d %d", &n, &m), n && m)
    {
        soma = 0;
        f1 = 1;
        f2 = 1;
        f3 = 1;
        f4 = 1;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m ; j++)
            {
                scanf(" %d",&tab[i][j]);
            }
            getchar();
        }
        for(int i = 0;i < n; i++)
        {
            for(int j = 0; j < m ; j++)
            {
                soma += tab[i][j];
            }
            if(f4 && soma == 0) f4 = 0;
            if(f1 && soma == m) f1 = 0;
            soma = 0;
        }
        for(int i = 0;i < m; i++)
        {
            for(int j = 0; j < n ; j++)
            {

                soma += tab[j][i];
            }
            if(f2 && soma == 0) f2 = 0;
            if(f3 && soma == n) f3 = 0;
            soma = 0;
        }

        printf("%d\n",f1+f2+f3+f4);
    }
    
    return 0;
}
