#include <stdio.h>

int main()
{
    int tam, ans=0,k=0;
    char tab[101][101];

    scanf("%d", &tam);
    for(int i = 0; i < tam; i++)
    {
        scanf(" %[^\n]", tab[i]);
    }
    
    for(int i = 0; i < tam; i++)
    {
        if(i%2 == 0)
        {
            for(int j = 0; j < tam; j++)
            {    
                if(tab[i][j] == 'o') k++;
                else if(tab[i][j] == 'A') 
                {
                    if(k>ans) ans = k;
                    k = 0;
                }
            }
        }
        else
        {
            for(int j = tam-1; j >= 0; j--)
            {    
                if(tab[i][j] == 'o') k++;
                else if(tab[i][j] == 'A')
                {
                    if(k>ans) ans = k;
                    k = 0;
                }
            }
        }    
    }
    if(k>ans) ans = k;
    printf("%d\n", ans);
    return 0;
}