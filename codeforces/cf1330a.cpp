#include <bits/stdc++.h>

int main()
{
    int a[202];
    int t, n, x, v, tam;
    scanf(" %d", &t);
    while (t--)
    {
        scanf(" %d %d", &n, &x);
        tam = n + x;
        for (int i = 0; i <= tam; i++)
            a[i] = 0;
        for (int i = 0; i < n; i++)
        {
            int temp;
            scanf(" %d", &temp);
            a[temp-1] = 1;
        }

        for (int i = 0; i <= tam && x != 0; i++)
        {
            if (a[i] == 0)
            {
                a[i] = 1;
                x--;
            }
        }
        for (int i = 0; i <= tam; i++)
            if (a[i] == 0) { v = i; break; }

        printf("%d\n", v);
    }
    return 0;
}