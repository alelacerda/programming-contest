#include <bits/stdc++.h>
using namespace std;
#define MAX 112345
typedef long long ll;

int main(void)
{
    int n, m, first = 1;
    ll sufsum[MAX];
    int l[MAX];

    scanf(" %d %d", &n, &m);
    
    for(int i = 1; i <=m; i++)
    {
        scanf(" %d", &l[i]);
        if(l[i] + i - 1 > n)
        {
            printf("-1\n");
            return 0;
        } 
    }

    for(int i = m; i > 0; i--)
        sufsum[i] = sufsum[i+1] + l[i];
    if(sufsum[1] < n)
    {
        printf("-1\n");
        return 0;
    }
    for(int i = 1; i <= m; i++)
    {
        if(!first) printf(" ");
        printf("%lld", max((ll)i,n - sufsum[i]+1));
        first = 0;
    }
    printf("\n");
    
    return 0;
}