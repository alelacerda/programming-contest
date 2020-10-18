#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n, a, b, c = 1;
    while(scanf("%d", &n), n)
    {
        a = 0;
        b = 0;
        while(n--)
        {
            int x;
            scanf("%d", &x);
            if(x == 0) a++;
            else b++;
        }
        printf("Case %d: %d\n",c, b - a);
        c++;
    }
    return 0;
}
