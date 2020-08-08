#include <bits/stdc++.h>
using namespace std;

#define MAX 1123

int main(void)
{
    int n,m,i,l,k;
    bitset<MAX> lamps;

    while (scanf("%d %d", &n, &m) != EOF)
    {
        lamps.reset();
        scanf("%d", &l);
        for (int i = 0; i < l; i++)
        {
            scanf("%d", &k);
            lamps[k-1] = 1;
        }
        vector<bitset<MAX>> in(n,bitset<MAX>());
        for (i = 0; i < n; i++)
        {
            scanf("%d", &k);
            while(k--)
            {
                int a;
                scanf(" %d", &a);
                in[i][a - 1] = 1;
            }
        }
        for (i = 0; lamps.count() && i < n * n; i++)
            lamps ^= in[i%n];

        printf("%d\n", lamps.count() ? -1 : i);
    }
    return 0;
}