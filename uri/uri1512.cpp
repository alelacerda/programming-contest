#include <stdio.h>


int gcd(int a, int b)
{
    if (!b) return a;
    return gcd(b, a%b);
}
int main()
{
    long long n, a, b, ans;
    while(scanf(" %lld %lld %lld",&n, &a, &b), n && a && b)
    {
        
        printf("%lld\n", n/a + n/b - n/((a*b)/gcd(a,b)));
    }
    return 0;
}