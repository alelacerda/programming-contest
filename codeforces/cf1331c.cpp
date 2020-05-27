#include <stdio.h>

//and after happily lived ever they
// 0    1     2     3     4    5
//and they lived happily ever after
// 0    5    3    2       4    1
int main()
{
    int n,b[6],aux;
    scanf("%d", &n);
    for(int i = 0; i < 6; i++)
    {
        b[i] = n % 2;
        n /=2 ;
    }
    aux = b[0];
    b[0] = b[4];
    b[4] = aux;
    aux = b[3];
    b[3] = b[2];
    b[2] = aux;
    n = 0;
    for(int i = 0; i<6;i++)
    {
        if(b[i])
            n |= (1<<i);
    }
    printf("%d\n", n);
    return 0;
}