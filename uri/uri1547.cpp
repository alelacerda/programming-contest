#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,qt,s,i,num,dif,certo=1;
    scanf("%d", &n);
    while(n--)
    {
        scanf("%d %d", &qt,&s);
        dif = 101;
        for(i=0;i<qt;i++)
        {
            scanf("%d",&num);
            if(abs(s-num)< dif)
            {
                dif = abs(s-num);
                certo = i+1;
            }
        }
        printf("%d\n",certo);

    }
    return 0;
}