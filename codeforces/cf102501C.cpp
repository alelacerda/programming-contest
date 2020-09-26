#include <bits/stdc++.h>
using namespace std;
#define MAX 1123456
int ans[MAX];

int main()
{
    int n;
    memset(ans, 0, sizeof(0));
    scanf("%d", &n);
    while(n--)
    {
        int a;
        scanf("%d",&a);
        if(a >= 0 && a <MAX)
            ans[a] = 1;
    }
    for(int i = 0; i < MAX; i++)
    {
        if(ans[i] == 0) 
        {
            printf("%d\n",i);
            return 0;
        }
    }
    return 0;
}