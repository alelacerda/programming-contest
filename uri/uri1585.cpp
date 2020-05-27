#include <stdio.h>

int main()
{
    int n, d, D;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d %d", &d,&D);
        printf("%d cm2\n",(d*D/2));
    }
    return 0;
}