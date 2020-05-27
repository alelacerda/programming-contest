#include <stdio.h>

int main()
{
    int n,j = 0;
    scanf("%d", &n);
    for(int i = 2 ; j !=2 && i <n; i++)
    {
        if(n%i == 0)
        {
            printf("%d",i);
            j++;
            if(i * i == n)
            {    printf("%d",i);
                j++;
            }
        }
    }
    printf("\n");
    return 0;
}