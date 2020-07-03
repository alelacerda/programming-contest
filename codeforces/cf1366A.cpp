#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n;
    long long a,b,c;
    scanf("%d", &n);
    while(n--)
    {
        scanf("%lld %lld",&a,&b);
        c = (a+b)/3;
        printf("%lld\n", min(min(a,b),c));
    }
    return 0;
}