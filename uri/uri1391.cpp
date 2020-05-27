#include <bits/stdc++.h>

using namespace std;
#define MAX 11234
#define INF 1234567
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vector<vii> AdjList;
vector<vii> AdjList2;

int dis[MAX], dis2[MAX];
int prev[MAX];
int vis[MAX];
int n, m, best;

void dijkstra(int s,vector<vii> &AdjL, int (&dist)[MAX])
{
    for (int i = 0; i < n; i++) { dist[i] = INF; vis[i] = 0; }
    priority_queue< ii, vector<ii>, greater<ii> > pq; 
    pq.push(ii(dist[s] = 0, s));

    while(!pq.empty())
    {
        int u = pq.top().second; pq.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(int i = 0; i < (int) AdjL[u].size(); i++)
        {
            ii v = AdjL[u][i];
            if(dist[u] + v.second < dist[v.first])
            {
                dist[v.first] = dist[u] + v.second;
                pq.push(ii(dist[v.first], v.first));
            }
        }
    }
}

int main()
{
    while(scanf("%d %d", &n, &m), n && m)  //n Vertex m Edges
    {
        AdjList.assign(n, vii());
        AdjList2.assign(n, vii());
        int s, d;
        scanf("%d %d", &s, &d);
        for(int i = 0; i < m; i++)
        {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            AdjList[u].push_back(ii(v, w));
            AdjList2[v].push_back(ii(u, w));
        }
        
        dijkstra(s, AdjList, dis);
        dijkstra(d, AdjList2, dis2);
        
        for (int i = 0 ; i < n ; i++)
		{
			for (int j = 0 ; j < (int)AdjList[i].size(); j++)
			{
				if (dis[i] + AdjList[i][j].second + dis2[AdjList[i][j].first] == dis[d])
					AdjList[i].erase(AdjList[i].begin() + j);
			}
		}
        dijkstra(s, AdjList, dis);
        best = dis[d];
        
        if(best == INF) best = -1;
        printf("%d\n",best);
    }
    return 0;
}
