#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int a1, a2, a3, ans;
    int r1,r2,r3;

    scanf("%d %d %d",&a1,&a2,&a3);
    
    r1 = 2 * a2 + 4 * a3;
    r2 = 2 * a1 + 2 * a3;
    r3 = 4 * a1 + 2 * a2;

    ans = min(r1, min(r2,r3));
    printf("%d\n",ans);

    return 0;
}