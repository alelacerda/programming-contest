#include <stdio.h>
#include <math.h>

int casas[45123];
int enc[45123];
int binsearch(int a, int first, int last)
{
    int mid = (first +last)/2;
    if(casas[mid] == a) return mid;
    if(casas[mid] < a) return binsearch(a, mid+1, last);
    return binsearch(a, first, mid-1);
}

int main()
{
    int n, m;
    int ans = 0, pos = 0, prox_pos;

    scanf(" %d %d", &n, &m);
    for(int i = 0; i < n; i++)
        scanf(" %d", &casas[i]);
    for(int i = 0; i < m; i++)
        scanf(" %d", &enc[i]);
    
    for(int i = 0; i < m; i++)
    {
        prox_pos = binsearch(enc[i],0,n-1);
        ans += abs(pos - prox_pos);
        pos = prox_pos;
    }
    printf("%d\n", ans);
    return 0;
}