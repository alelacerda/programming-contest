#include <bits/stdc++.h>
using namespace std;
#define MAX 112

int lg[MAX][MAX];
int m,w,max_flow,V,f,s,t;
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

int main(void)
{
    while(scanf("%d %d",&m,&w), m)
    {
        memset(lg,0,sizeof(lg));
        V =  m*2 - 2;
        s = 0;
        t = V -1;

        for(int i = 0; i < m-2; i++)
        {
            int id, c, u, v;
            scanf("%d %d",&id,&c);
            id--;
            u = 2*id -1;
            v = u + 1;
            lg[u][v] = c;
            //lg[v][u] = c;            
        }

        for(int i = 0; i < w; i++)
        {
            int id1, id2, c, u1, u2, v1, v2;
            scanf("%d %d %d", &id1, &id2, &c);
            id1--;
            id2--;
            if(id1 != 0 && id1 != m-1)
            {
                u1 = id1 * 2 -1;
                v1 = u1 + 1;
            }
            else
            {
                if(id1 == 0) u1 = v1 = 0;
                else u1 = v1 = V - 1;
            }
            
            if(id2 != 0 && id2 != m-1)
            {
                u2 = id2 * 2 -1;
                v2 = u2 + 1;
            }
            else
            {
                if(id2 == 0) u2 = v2 = 0;
                else u2 = v2 = V - 1;
            }
            lg[v1][u2] = c;
            lg[v2][u1] = c;       
        }

        max_flow = 0;
        for(;;)
        {
            int u,v;
            f = 0;
            int vis[MAX];
            memset(vis, 0, sizeof(vis));
            queue<int> q;
            q.push(s);
            p.assign(V,-1);
            while(!q.empty())
            { 
                u = q.front(); q.pop();
                if(u == t) break;
                for(v = 0; v < V; v++)
                {
                    if(lg[u][v] > 0 && !vis[v])
                    { //verifica q a aresta n esgotou
                        vis[v] = 1;
                        q.push(v);
                        p[v] = u;
                    }
                }
            }
            
            edkarp(t,INT_MAX);
            if(f == 0) break;
            max_flow += f;
        }
        printf("%d\n",max_flow);
    }
    
    return 0;
}