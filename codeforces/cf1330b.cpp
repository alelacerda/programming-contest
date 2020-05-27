#include <bits/stdc++.h>
#define SIZE 212345
int t,n,k,max;
int a[SIZE];
int ans[SIZE][2]; 

int check_perm(int num, int ini, int fim)
{
    int aux[SIZE+1];
    for(int i = 1; i <= num; i++)
        aux[i] = 0;
    for(int i = ini; i < fim; i++)
        aux[a[i]] = 1;
    for(int i = 1; i <=num; i++)
        if(!aux[i]) return 0;
    return 1;
}
int main()
{
    scanf(" %d", &t);
    while(t--)
    {
        max = 0;
        k = 0;
        scanf(" %d",&n);
        for(int i = 0; i <n; i++)
        {
            scanf(" %d", &a[i]);
            if(a[i]> max) max = a[i];
        }
        
        if(check_perm(max,0,max) && check_perm(n-max,max,n))
        {
            ans[k][0] = max;
            ans[k++][1] = n-max;
        }
        if(max*2 != n && check_perm(n-max,0,n-max) && check_perm(max,n-max,n))
        {
            ans[k][0] = n -max;
            ans[k++][1] = max;
        }
        printf("%d\n",k);
        for(int i = 0; i <k; i++)
            printf("%d %d\n",ans[i][0], ans[i][1]);
    }
    return 0;
}