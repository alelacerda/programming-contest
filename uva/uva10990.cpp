#include <bits/stdc++.h>
using namespace std;

#define MAX 2000001

vector<int> totient(MAX);
vector<int> dphi(MAX,-1);

int dp(int n)
{
    if(dphi[n] != -1) return dphi[n];
    return dphi[n] = dp(totient[n]) + 1;
}

void eulerTotient(void)
{
    for(int i = 0; i < MAX; i++)
        totient[i] = i;
    for(int i = 2; i < MAX; i++)
    {
        if(totient[i] == i)
        {
            for(int j = i; j < MAX; j+= i)
                totient[j] -= totient[j]/i;
        }
    }
}

int main(void)
{
    int t,n,m;
    vector<int> ans(MAX);
    
    //calcula pra todos os números possiveis
    eulerTotient();

    dphi[0] = dphi[1] = 0;
    for(int i = 2; i < MAX; i++)
        dp(i);

    ans[0] = 0;
    for(int i = 1; i < MAX; i++)
        ans[i] = ans[i-1] + dphi[i];
    
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d",&m, &n);
        printf("%d\n", ans[n] - ans[m-1]);
    }
    return 0;
}