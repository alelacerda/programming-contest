#include <stdio.h>

int main()
{
    int n, m, a, b, ka, kb;
    char img[51][51];

    while(scanf(" %d %d", &n,&m), n && m)
    {
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                scanf(" %c", &img[i][j]);
        
        scanf(" %d %d", &a, &b);
        a /= n;
        b /= m;

        for(int i = 0; i < n; i++)
        {   
            for(int ka = 0 ; ka < a; ka++)
            {
                for(int j = 0; j < m; j++)
                {
                    for(int kb = 0; kb < b; kb ++)
                    {
                        printf("%c", img[i][j]);
                    }
                }
                printf("\n");
            }
        }
        printf("\n");
    }
    return 0;
}