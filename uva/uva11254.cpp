#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n;
    while(scanf("%d", &n), n != -1)
    {
        int a , b;
        for(b = (int) sqrt(2 * n); b > 0; b--)
        {
            if(( 2 * n + b - b * b) % (2 * b) == 0)
            {
                a = ( 2 * n + b - b * b) / (2 * b);
                break;
            }
        }
        printf("%d = %d + ... + %d\n",n, a, (a + b - 1));
    }
    return 0;
}