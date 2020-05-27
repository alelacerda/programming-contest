#include <stdio.h>
#include <math.h>

int main()
{
    int n, m, ans = 0, fec[1123];

    scanf(" %d %d", &n, &m);
    for(int i = 0; i < n; i++)
        scanf(" %d", &fec[i]);

    for(int i = 0; i < n; i++)
    {
        ans += abs(fec[i] - m);
        fec[i+1] += m - fec[i];
        fec[i] = m;
    }
    printf("%d\n", ans);
    return 0;
}