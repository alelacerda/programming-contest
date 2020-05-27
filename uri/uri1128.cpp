#include <bits/stdc++.h>

using namespace std;
#define UNVISITED -1
#define MAX 2123
vector<int> adj[MAX];

int dfs_num[MAX], dfs_low[MAX], visited[MAX];
stack<int> S;
int dfsNumCnt, numSCC;
void tarjanSCC(int u, int lvl)
{
    dfs_low[u] = dfs_num[u] = lvl;
    S.push(u);
    visited[u] = 1;
    for(int i = adj[u].size()-1; i >= 0; i--)
    {
        int v = adj[u][i];
        if(dfs_num[v] == -1)//não visitado
            tarjanSCC(v, lvl+1);
        if(visited[v])
            dfs_low[u] = min(dfs_low[u],dfs_low[v]);
    }
    if(dfs_low[u] == lvl)
    {
        while(1)
        {
            int v = S.top(); S.pop(); visited[v] = 1;
            if(u == v) break;
        }
        numSCC++;
    }
}

int main()
{
    int n, m, v, w, p;
    
    while(scanf(" %d %d", &n, &m), n && m)
    {
        for(int i = 1; i <= n;i++)
            adj[i].clear();
        while(m--)
        {
            scanf(" %d %d %d", &v, &w, &p);
            adj[v].push_back(w);
            if(p == 2)
                adj[w].push_back(v);
        }

        memset(dfs_num,-1,sizeof(dfs_num));
        memset(dfs_low,0,sizeof(dfs_low));
        memset(visited,0,sizeof(visited));
        numSCC = 0;

        for(int i = 1; i <= n; i++)
            if(dfs_num[i] == -1)
                tarjanSCC(i,0);

        printf("%d\n", (numSCC == 1)? 1 : 0); 
    }

    return 0;
}