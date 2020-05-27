#include <stdio.h>
typedef long long ll;

char nomes[112345][11];
ll v[112345];
int n;

ll valor_nome(int a)
{
    ll valor = 0;
    for(int i = 0; nomes[a][i] != '\0'; i++)
    {
        valor += (ll)nomes[a][i];
    }
    return valor;
}

ll sum_r(int a)
{
    ll sum=0;
    int p = 1;
    for(int i = a+1; i < n; i++)
    {
        sum += p*v[i];
        p++;
    }
    return sum;
}
ll sum_l(int a)
{
    int p = 1;
    ll sum=0;
    for(int i = a; i >= 0; i--)
    {
        sum += p*v[i];
        p++;
    }
    return sum;
}
int bs(int l, int r)
{
    if (r >= l) 
    { 
        int mid = l + (r - l) / 2; 
        ll sr = sum_r(mid);
        ll sl = sum_l(mid);
   
        if (sr == sl) 
            return mid;  
        if (sr < sl) 
            return bs(l, mid - 1); 
        return bs(mid + 1, r); 
    } 
    return -1; 
}

int main()
{
    int ans;

    while(scanf(" %d",&n),n)
    {
        for(int i = 0; i < n; i++)
        {    
            scanf(" %s", nomes[i]);
            v[i] = valor_nome(i);
        }
        ans = bs(0,n);

        printf("%s\n", ans >= 0? nomes[ans]: "Impossibilidade de empate.");
    }

    return 0;
}
