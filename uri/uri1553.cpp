#include <stdio.h>

int main()
{
    int n,k,p,i,ans;
    int v[100]={};
    scanf("%d %d",&n,&k);
    while(n != 0 && k!=0)
    {
        ans = 0;
        for(i=0; i<n;i++)
        {
            scanf("%d",&p);
            v[p]++;
        }
        for(i=0; i<100; i++)
        {
            if(v[i]>=k) ans++;
        }
        for(i=0; i<100; i++)
        {
            v[i] = 0;
        }
        printf("%d\n",ans);
        scanf("%d %d",&n,&k);
    }
    return 0;
}