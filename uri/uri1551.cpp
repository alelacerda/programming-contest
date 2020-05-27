#include <stdio.h>
#include <string.h>


int main()
{
    char str[1123];
    int n, total, i;
    int alf[26];

    scanf("%d",&n);
    while(n--)
    {
        total = 0;i = 0;

        memset(alf,0,sizeof(alf));
        scanf(" %[^\n]", str);
        
        while(str[i] != '\0')
        {
            if(str[i] != ' ' && str[i] != ',')
                alf[str[i]-'a']++;
            i++;
        }

        for(i = 0; i<26; i++)
        {
            if(alf[i]>= 1) total++;
        }

        if(total == 26) printf("frase completa\n");
        else if (total >= 13) printf("frase quase completa\n");
        else printf("frase mal elaborada\n");
    }

    return 0;
}