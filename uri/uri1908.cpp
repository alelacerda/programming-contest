#include <bits/stdc++.h>
using namespace std;
#define MAX 11234

int main(void)
{
    int n,k,L[MAX],ans = 0;
    queue<int> q;
    scanf(" %d %d",&n,&k);
    vector<set<int>> graphL(k);
    vector<set<int>> graphC(n);
    for(int i = 0; i < k ; i++)
    {
        int l;
        scanf(" %d",&l);
        for(int j = 0; j < l; j++)
        {
            int a;
            scanf("%d",&a);
            graphL[i].insert(a-1);
            graphC[a-1].insert(i);
        }
    }
    
    int dist[MAX];
    memset(dist, -1, sizeof(dist));
    
    for(int i: graphC[0])
    {   
        if(dist[i] == -1)
        {
            dist[i] = 1;
            q.push(i);
        }
    }
    int f = 0;
    while(!f)
    {
        int u = q.front(); q.pop();
        for(auto i: graphL[u])
        {
            if(i == (n-1))
            {
                ans = dist[u];
                f = 1;
                break;
            }
            for(auto j: graphC[i])
            {
                if(dist[j] == -1)
                {
                    dist[j] = dist[u]+1;
                    q.push(j);
                }
            }
            
        }
    }

    printf("%d\n",ans);
    return 0;
}