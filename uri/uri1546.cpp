#include <stdio.h>

int main()
{
    int n, k, i;
    scanf("%d", &n);
    while(n--)
    {
        scanf("%d", &k);
        while(k--)
        {
            scanf("%d",&i);
            if(i==1) printf("Rolien\n");
            else if(i==2) printf("Naej\n");
            else if(i==3) printf("Elehcim\n");
            else printf("Odranoel\n");
        }
    }
    return 0;
}