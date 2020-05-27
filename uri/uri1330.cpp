#include <bits/stdc++.h>
using namespace std;

#define MAX 112
#define MAX2 11234
#define INF 1123456
#define f first
#define s second
typedef pair<int,int> ii;


int dimn, dimm;
int grid[MAX][MAX];
ii lg[MAX][MAX][6];
int d[MAX][MAX];
int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
ii m[MAX][MAX];
int dist[MAX][MAX];
bool bfs()
{
    queue<ii> q;
    int k = INF;
    for (int i = 0; i < dimn; i++)
        for (int j = 0; j < dimm; j++)
        {
            ii u = make_pair(i, j);
            if (grid[i][j] != -1)
            {
                if (grid[i][j] == 1 && m[u.f][u.s].f == u.f && m[u.f][u.s].s == u.s)
                {
                    dist[u.f][u.s] = 0;
                    q.push(u);
                }
                else dist[u.f][u.s] = INF;
            }
        }

    while (!q.empty())
    {
        ii u = q.front(); q.pop();
        if (dist[u.f][u.s] < k)
        {
            for (int i = 0; i < d[u.f][u.s]; i++)
            {
                ii v = lg[u.f][u.s][i];
                if (grid[v.f][v.s] != -1)
                {
                    if (v.f == m[v.f][v.s].f && v.s == m[v.f][v.s].s && k == INF)
                        k = dist[u.f][u.s] + 1;
                    else if (dist[m[v.f][v.s].f][m[v.f][v.s].s] == INF)
                    {
                        dist[m[v.f][v.s].f][m[v.f][v.s].s] = dist[u.f][u.s] + 1;
                        q.push(m[v.f][v.s]);
                    }
                }
            }
        }
    }
    return (k != INF);
}
bool dfs(ii u)
{
    for (int i = 0; i < d[u.f][u.s]; i++)
    {
        ii v = lg[u.f][u.s][i];
        if (grid[v.f][v.s] != -1)
        {
            if (m[v.f][v.s].f == v.f && m[v.f][v.s].s == v.s
                || dist[m[v.f][v.s].f][m[v.f][v.s].s] == dist[u.f][u.s] + 1
                && dfs(m[v.f][v.s]))
            {
                m[v.f][v.s].f = u.f;
                m[v.f][v.s].s = u.s;
                m[u.f][u.s].f = v.f;
                m[u.f][u.s].s = v.s;
                return true;
            }
        }
    }
    return false;
}
int hopcroftkarp()
{
    for (int i = 0; i < dimn; i++)
    {
        for (int j = 0; j < dimm; j++)
        {
            if (grid[i][j] != -1)
                m[i][j] = make_pair(i, j);
            else if(grid[i][j] == -1) m[i][j] = make_pair(-1, -1);
        }
    }

    int ans = 0;
    while (bfs())
    {
        for (int i = 0; i < dimn; i++)
        {
            for (int j = 0; j < dimm; j++)
            {
                if (m[i][j].f == i && m[i][j].s == j && dfs(make_pair(i, j)))
                    ans++;
            }
        }
    }
    return ans;
}
int main(void)
{
    int k, x, y;
    while (scanf("%d %d", &dimn, &dimm), dimn)
    {
        scanf("%d", &k);
        memset(grid, 0, sizeof(grid));
        memset(d, 0, sizeof(d));
        memset(lg, 0, sizeof(lg));
        while (k--)
        {
            scanf("%d %d", &x, &y);
            x--; y--;
            grid[x][y] = -1; //lago
        }
        for (int i = 0; i < dimn; i++)
            for (int j = 0; j < dimm; j++)
            {
                if (grid[i][j] != -1 && grid[i][j] != 2)
                {
                    ii u = make_pair(i, j);
                    grid[i][j] = 1;
                    for (int l = 0; l < 4; l++)
                    {
                        int a = i + dir[l][0], b = j + dir[l][1];
                        if (a >= 0 && a < dimn && b >= 0 && b < dimm
                            && grid[a][b] != -1 && grid[a][b] != 1)
                        {
                            ii v = make_pair(a, b);
                            lg[u.f][u.s][d[u.f][u.s]++] = v;
                            grid[a][b] = 2;
                        }
                    }
                }
            }
        printf("%d\n", hopcroftkarp());
    }
    return 0;
}

