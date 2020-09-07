#include <bits/stdc++.h>
#define MAX 40
using namespace std;

int stk[MAX];
int qtd,m,mi;

void flip(int n)
{
    printf("%d ",qtd-n+1);
    int temp[32];
    for(int i=0;i<=n;i++)
        temp[i]=stk[i];
    for(int i = 0, j = n;i <= n; i++,j--){
        stk[i]=temp[j];
        if(stk[i] == m) mi = i ;
    }
}

void pancakeSort(int n)
{
    for(int size = n; size >= 0; size--)
    {
        m = 0;
        for(int i = 0; i <= size; i++)
            if(stk[i] > m) { m = stk[i]; mi = i;}
        if(mi != size)
        {
            if(mi != 0) 
            {   flip(mi);printf("%d ",qtd-mi+1);
            }
            flip(size);
        }
    }
}

int main()
{
    char line[150];
    while(gets(line))
    {   
        memset(stk, 0, sizeof(stk));
        qtd = 0;
        for(int i = 0; line[i]; i++)
        {
            if(line[i] == ' ') 
            {
                printf("%d ", stk[qtd]);qtd++;
            }
            else {stk[qtd] *= 10; stk[qtd] += line[i] - '0';}
        }
        printf("%d\n",stk[qtd]);
        pancakeSort(qtd);
        printf("0\n");
    }
    

    return 0;
}