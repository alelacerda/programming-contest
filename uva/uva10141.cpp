#include <bits/stdc++.h>
using namespace std;
#define MAX 90
int main(void)
{
    int n, p, r, first = 1, maxR, c = 1;
    double d, minD;
    char pName[MAX], bpName[MAX],lixo[MAX];

    while(scanf("%d %d", &n, &p), n || p)
    {
        gets(lixo);
        minD = -1;
        maxR = 0;

        if(first) first = 0;
        else printf("\n");

        for(int i = 0; i < n; i++)
        {
            gets(lixo);
        }
        
        for(int i = 0; i < p; i++)
        {
            gets(pName);
            scanf("%lf %d", &d, &r);
            gets(lixo);
            for(int j = 0; j < r; j++)
            {
                gets(lixo);
            }

            if(r > maxR || (r == maxR && (minD < 0 || d < minD)))
            {
                minD = d;
                maxR = r;
                strcpy(bpName, pName);
            }
        }
        printf("RFP #%d\n%s\n",c,bpName);
        c++;
    }
    return 0;
}