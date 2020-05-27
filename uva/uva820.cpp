#include <bits/stdc++.h>
#define MAX 112
#define INF 2147483648

using namespace std;
int n, max_flow, f, s, t, c;
int lg[MAX][MAX];
vector<int> p;

void edkarp(int v, int min_e)
{
    if(v == s) { f=min_e; return;}
    else if(p[v] != -1)
    {
        edkarp(p[v], min(min_e, lg[p[v]][v]));
        lg[v][p[v]] += f;
        lg[p[v]][v] -= f; 
    }
}

int main()
{
    int i=0;
    while(scanf("%d", &n), n)
    {
        scanf("%d %d %d", &s, &t, &c);
        s--; t--;
		memset(lg,0,sizeof(lg));
        int u,v,w;
        while(c--)
        {
            scanf("%d %d %d", &u, &v, &w);
            u--; v--;
            lg[u][v] += w;
            lg[v][u] += w;
        }

        max_flow = 0;
        for(;;)
        {
            f = 0;
            vector<int> dist(n, INT_MAX);
            dist[s] = 0;
            queue<int> q;
            q.push(s);
            p.assign(n,-1);
            while(!q.empty())
            { 
                u = q.front(); q.pop();
                if(u == t) break;
                for(v = 0; v < n; v++)
                {
                    if(dist[v] == INT_MAX && lg[u][v] > 0)
                    { //verifica q a aresta n esgotou
                        dist[v]= dist[u]+1;
                        q.push(v);
                        p[v]=u;
                    }
                }
            }
            
            edkarp(t,INT_MAX);
            if(f == 0) break;
            max_flow += f;
        }
        
        printf("Network %d\n", ++i);
        printf("The bandwidth is %d.\n\n", max_flow);
    }
    
    return 0;
}