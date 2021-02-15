#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n, k;
    int pont[1123];

    scanf("%d %d",&n,&k);
    for(int i = 0; i < n; i++) scanf("%d",&pont[i]);
    sort(pont,pont+n, greater<int>());
    while( k < n && pont[k] == pont[k-1])
    {
        k++;
    }
    printf("%d\n",k);

    return 0;
}