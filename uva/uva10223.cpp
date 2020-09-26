#include <bits/stdc++.h>
using namespace std;
#define MAX 30

int main(void)
{
    long long int n;
    long long int catalan[MAX];
 
    catalan[0] = catalan[1] = 1;
    for (int i=2; i<MAX; i++)
    {
        catalan[i] = 0;
        for (int j=0; j<i; j++)
            catalan[i] += catalan[j] * catalan[i-j-1];
    }

    while(scanf("%lld",&n)!=EOF)
    {
        for(int i = 1; i <=MAX;i++)
        {
            if(n== catalan[i])
            {
                printf("%d\n",i); 
                break;
            }
        }
    }
    
    return 0;
}
