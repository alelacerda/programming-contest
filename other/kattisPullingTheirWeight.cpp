#include <bits/stdc++.h>
using namespace std;
#define MAX 112345
#define MAXW 21234

int main(void)
{
    int m,sum=0,a[MAX];
    int rep[MAXW],presum[MAX];
    set<int> t;

    scanf("%d",&m);
    memset(rep,0,sizeof(rep));
    for(int i = 0; i < m; i++)
    {
        scanf("%d",&a[i]);
        t.insert(a[i]);
        t.insert(a[i]+1);
        rep[a[i]]++;
    }
    for(auto j: t)
    {
        sum += j * rep[j];
        presum[j] = sum;
    }
    for(auto j: t)
    {
        if(presum[j] == (sum - presum[j] + j*rep[j]))
        {
            printf("%d\n",j);
            return 0;
        }
    }
}