#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    return (b == 0? a : gcd(b,a%b));
}
int lcm(int a, int b)
{
    return ((a*b)/gcd(a,b));
}
int main(void)
{
    int a,b;
    scanf("%d.%d",&a,&b);
    printf("%d\n",lcm(36000,a*100 +b)/(a*100 +b));
    return 0;
}