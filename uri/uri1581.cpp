#include <stdio.h>
#include <string.h>

int main()
{
    char str1[21], str2[21];
    int n, k, ing;
    scanf("%d",&n);
    while(n--)
    {
        ing = 0;
        scanf("%d",&k);
        scanf("%s",str1);
        while(--k)
        {
            scanf("%s",str2);
            if(strcmp(str1, str2))
            {
                ing = 1;
            }
        }
        if(ing) printf("ingles\n");
        else printf("%s\n",str1);
    }

    return 0;
}