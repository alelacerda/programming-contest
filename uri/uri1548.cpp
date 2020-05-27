#include <stdio.h>

int nota[1123];
int maior_nota(int a)
{
    int maior = 0;
    for(int i = 0; i<a; i++)
    {
        if(nota[i] > nota[maior])
            maior = i;
    }
    nota[maior] = -1;
    return maior;
}
int main()
{
    int n,m,ans;
    
    scanf(" %d",&n);
    while(n--)
    {
        scanf(" %d",&m);
        for(int i = 0; i < m; i++)
            scanf(" %d",&nota[i]);

        ans = 0;

        for(int i = 0; i < m; i++)
        {
            if(maior_nota(m) == i) ans++;
        }

        printf("%d\n", ans);
    }

    return 0;
}