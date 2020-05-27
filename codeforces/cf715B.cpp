#include <bits/stdc++.h>
using namespace std;
#define MAXN 1123
#define MAXM 11234
#define mp make_pair
#define INF 1e9+5;

int n, m, l, s, t;
typedef pair<int, int> ii;

vector<int> adj[MAXN];
int weight[MAXN][MAXN];
int dij[MAXN], dij2[MAXN];
int fir[MAXM], sec[MAXM];
bool vis[MAXN];
bool desco[MAXN][MAXN];

void dijkstra()
{
	memset(vis, false, sizeof(vis));
    dij[s] = 0;
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push(ii(0, s));
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        
        if(vis[u])continue;
        vis[u]=true;
        for (int i = 0; i < (int)adj[u].size(); i++)
        {
            int v = adj[u][i];
            int w = weight[u][v];
            if (dij[u] + w < dij[v])
            {
                dij[v] = dij[u] + w;
                pq.push(ii(dij[v], v));
            }
        }
    }
}

bool dijkstra2(int need)
{
	memset(vis, false, sizeof(vis));
	dij2[s] = 0;
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	pq.push(ii(0, s));
	while (!pq.empty())
	{
		int u = pq.top().second;
		pq.pop();
		
		if(vis[u])continue;
		vis[u]=true;
		for (int i = 0; i < (int)adj[u].size(); i++)
		{
			int v = adj[u][i];
            int w = weight[u][v];
			if ((dij2[u] + w < dij2[v])
			&& (desco[u][v])
			 && (dij2[u] + w < dij[v] + need))
			{
				//o peso novo de v é igual a distância de v com peso 1 
				// + o que falta para completar l - o que já percorreu
				w = weight[u][v] = weight[v][u] = dij[v] + need - dij2[u];
			}
			if (dij2[u] + w < dij2[v])
            {
                dij2[v] = dij2[u] + w;
                pq.push(ii(dij2[v], v));
            }
		}
	}
	
	if(dij2[t] != l) return false;
	return true;
}

int main()
{
	memset(desco, false, sizeof(desco));
    scanf("%d %d %d %d %d", &n, &m, &l, &s, &t);
    int u, v, w;
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &u, &v, &w);
        if (w == 0)
        {
			weight[u][v] = 1; desco[u][v] = true;
			weight[v][u] = 1; desco[v][u] = true;
        }
        else{
			weight[u][v] = w;
			weight[v][u] = w;
        }
        adj[u].push_back(v);
		adj[v].push_back(u);
        fir[i] = u; sec[i] = v;
    }

    for (int i = 0; i < n; i++)
    {
        dij[i] = INF;
        dij2[i] = INF;
    }
    
    //condições iniciais pra ver se precisa mesmo fazer o segundo dijskstra
    dijkstra();
    int need = l - dij[t];
    if (need < 0)
    {
        printf("NO\n"); return 0;
    }
    if (dij[t] == l)
    {
        printf("YES\n");
        for (int i = 0; i < m; i++)
        {
            u = fir[i]; v = sec[i];
            printf("%d %d %d\n", u, v, weight[u][v]);
        }
        return 0;
    }
    
    bool aux = dijkstra2(need);
    
    if (!aux)
    {
        printf("NO\n"); return 0;
    }
 
    printf("YES\n");
    for (int i = 0; i < m; i++)
    {
        u = fir[i]; v = sec[i];
        printf("%d %d %d\n", u, v, weight[u][v]);
    }
	
    return 0;
}
