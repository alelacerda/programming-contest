#include <bits/stdc++.h>
using namespace std;
#define MAX 500020
int main(void)
{
    int ans[MAX],n;
    //preprocess
    ans[1] = 1; ans[2] = 2;
    int x = 2;
    for(int i = 3; i < MAX; i++)
    {
        if(x > i) x = 2;
        ans[i] = x;
        x += 2;
    }

    while(scanf("%d",&n),n)
    {
        printf("%d\n",ans[n]);
    }

    return 0;
}