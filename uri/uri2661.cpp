#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    unsigned long long n, fat = 0;

    scanf("%llu", &n);

    for(int i = 2; i * i <= n; i++)
    {
        if(n%i == 0)
        {
            fat++;
            while(n%i==0)
                n /= i;
        }
    }
    if(n!=1) fat++;
    printf("%llu\n",(1l << fat) - fat - 1);

    return 0;
}