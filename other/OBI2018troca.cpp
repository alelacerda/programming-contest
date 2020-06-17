#include <bits/stdc++.h>
using namespace std;
#define MAX 112345

int main(void)
{
    int up[MAX], down[MAX], op[MAX], sum[MAX];
    int n,t;
    scanf("%d %d", &n, &t);
    for(int i = 1; i <= n; i++) scanf(" %d",&up[i]);
    for(int i = 1; i <= n; i++) scanf(" %d",&down[i]);
    while(t--)
    {
        int i,j;
        scanf("%d %d",&i,&j);
        op[i]++;
        op[j+1]--;
    }
    for(int i = 1; i <= n; i++)
    {
        sum[i] = sum[i-1]+op[i];
    }
    for(int i = 1; i <= n; i++)
    {
        if(i!=1) printf(" ");
        printf("%d", sum[i]%2? down[i] : up[i]);
    }
    printf("\n");    
    return 0;
}