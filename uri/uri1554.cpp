#include <stdio.h>

#define INF 11234567
int main()
{
    int branca_x, branca_y, c, n, menor, ans, b;
    int bola_x, bola_y;

    scanf("%d",&c);
    while(c--)
    {
        menor = INF; ans = 0; b = 0;
        
        scanf("%d",&n);
        scanf("%d %d", &branca_x, &branca_y);
        
        while(n--)
        {
            b++;
            scanf("%d %d", &bola_x, &bola_y);
            int x = (branca_x - bola_x) * (branca_x - bola_x) + (branca_y - bola_y) * (branca_y - bola_y);
            if(x < menor)
            {
                menor = x;
                ans = b;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
//35 min + 20 