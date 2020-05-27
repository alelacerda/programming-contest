#include <stdio.h>

int main()
{
    int n;
    char a;
    scanf("%c%d",&a,&n);
    if(n % 2 == 0) printf("0\n");
    else printf("1\n");

    return 0;
}