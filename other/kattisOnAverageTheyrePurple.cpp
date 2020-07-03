#include <bits/stdc++.h>
using namespace std;
#define MAX 112345

int main(void)
{
    int dist[MAX];
    vector<int> AdjList[MAX];
    int n,m;
    memset(dist,-1,sizeof(dist));
    scanf("%d %d",&n,&m);
    for(int i = 1; i <=n; i++) AdjList[i].clear();
    while(m--)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        AdjList[x].push_back(y);
        AdjList[y].push_back(x);
    }
    queue<int> q;
    q.push(1);
    dist[1] = 0;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i = 0; i < AdjList[u].size(); i++)
        {
            int v = AdjList[u][i];
            if(dist[v] == -1)
            {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    printf("%d\n",dist[n]-1);
    return 0;
}
