#include <bits/stdc++.h>
using namespace std;
int n;
int adjm[112][112];
int vis[112], fvis[112];
int dom[112][112];

void dfs(int u, int ex)
{
    if(u == ex) return;
    vis[u] = 1;
    for(int i = 0; i <n; i++)
        if(adjm[u][i] == 1 && (!vis[i]))
            dfs(i,ex);
}

int main(void)
{
    int t,cases = 0;
    scanf("%d", &t);
    while(t--)
    {
        memset(adjm, 0, sizeof(adjm));
        memset(vis, 0, sizeof(vis));
        memset(dom, 0, sizeof(dom));
        scanf(" %d", &n);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
                scanf(" %d",&adjm[i][j]);
        }
        dfs(0,-1);
        for(int i = 0; i < n; i++)
            fvis[i] = vis[i];
        for(int i = 0; i <n;i++)
        {
            memset(vis, 0, sizeof(vis));
            dfs(0,i);
            for(int j = 0; j <n; j++)
            {
                if(fvis[j] && !vis[j])
                    dom[i][j] = 1;
            }
            dom[i][i] = fvis[i];
        }

        printf("Case %d:\n",++cases);
        printf("+");
        for(int j = 0; j < 2*n-1; j++)
            printf("-");
        printf("+\n");

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                printf("|%c", dom[i][j]? 'Y': 'N');
            }
            printf("|\n+");
            for(int j = 0; j < 2*n-1; j++)
            printf("-");
            printf("+\n");
        }
    }
    return 0;
}