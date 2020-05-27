#include <stdio.h>

int main()
{
    int n, r, b, c, x, y;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d %d", &x, &y);
        r = (3 * x *3 *x) + (y*y);
        b = 2*(x*x) +(5*5*y*y);
        c = (-100*x) + (y*y*y);
        if(r > b && r > c) printf("Rafael ganhou\n");
        else if(b > r && b > c) printf("Beto ganhou\n");
        else printf("Carlos ganhou\n"); 
    }
    return 0;
}