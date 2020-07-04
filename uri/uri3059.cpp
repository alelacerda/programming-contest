#include <bits/stdc++.h>
using namespace std;
#define MAX 1123
int s[MAX][MAX];
int main(void)
{
    
    int n,k,f,ans = 0;
    //memset(sum, 0, sizeof(sum));
    scanf("%d %d %d",&n,&k,&f);
    for(int i = 0; i < n; i++)
    {
        int a;
        scanf(" %d",&a);
        s[i][i] = a;
        for(int j = 0; j < i; j++)
            if(i != j) s[i][j] = a + s[j][j];
    }
    for(int i = 0; i < n; i++)
            for(int j = 0; j < i; j++)
                if(s[i][j] >= k && s[i][j] <= f) ans++;
    printf("%d\n",ans);
    return 0;
}