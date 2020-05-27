#include <bits/stdc++.h>
char num[32];
int tam;

void base(int n, int b)
{
    tam = 0;
    while(n)
    {
        num[tam++] = n%b;
        n /= b;
    }
}

int palindromo()
{
    for(int i = 0; i < tam/2; i++)
    {
        if(num[i] != num[tam-(i+1)]) return 0;
    }
    return 1;
}
int main()
{
    int t,n,f,imp;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d",&n);
        f = 1;
        imp = 0;
        for(int i = 2; i <=16; i++)
        {
            base(n,i);
            if(palindromo())
            {
                imp = 1;
                if(!f) printf(" ");
                printf("%d",i);
                f = 0;
            }
            
        }
        if(!imp) printf("-1");
        printf("\n");
    }
    return 0;
}