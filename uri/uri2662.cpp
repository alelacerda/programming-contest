#include <bits/stdc++.h>
using namespace std;


int padrao[] = {1,0,1,0,1,1,0,1,0,1,0,1};
int s_padrao[] = {1,0,1,0,1,1,0,1,0,1,0,1};
char notas[][11] = {"do","do#","re","re#","mi","fa","fa#","sol","sol#","la","la#","si","desafinado"};
int vis[12];

bool comp()
{
    for(int i = 0; i < 12; i++)
    {   
        if((vis[i] == 1) && (s_padrao[i] == 0))
            return false;
    }
    return true;
}

int main(void)
{
    int n, a;
    memset(vis,0,sizeof(vis));
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&a);
        vis[(a-1)%12] = 1;
    }

    if(comp())
    {
        printf("%s\n",notas[0]);
        return 0;
    }

    for(int i = 1; i < 12; i++)
    {
        for(int j = 0; j < 12; j++)
            s_padrao[(j+i)%12] = padrao[j];

        if(comp())
        {
            printf("%s\n",notas[i]);
            return 0;
        }
    }

    printf("%s\n",notas[12]);
    return 0;
}