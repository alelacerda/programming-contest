#include <bits/stdc++.h>

int main()
{
    int n1, n2, n12;
    scanf("%d %d %d", &n1, &n2, &n12);
    double a = (((n1 + 1) * (n2 + 1)) / (n12 + 1)) - 1;
    int ans = a;
    printf("%d\n", ans);  

    return 0;
}