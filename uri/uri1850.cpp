#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define mp make_pair
typedef pair<int,int> ii;
typedef pair<int,ii> iii;

int d[102][102][(1<<7)+1];
int n = 0;
char mat[102][102];

int dir[4][2] = {{0,-1},{-1,0},{0,1},{1,0}};
bool valid(int i, int j)
{
    return (i >= 0 && i < n) && (j >= 0 && mat[i][j] != '\0') ? true : false;
}
int bfs(int a, int b)
{
    memset(d,0,sizeof(d));
    queue<iii> q;
    q.push(mp(0, mp(a,b)));
    d[a][b][0] = 1;

    while(!q.empty())
    {
        iii u = q.front();
        q.pop();
        for(int i = 0; i < 4 ; i++)
        {
            int mask;
            int x = u.s.f + dir[i][0];
            int y = u.s.s + dir[i][1];
            if(valid(x,y) && mat[x][y] != '#')
            {
                char m = mat[x][y];
                if(m >= 'a' && m <= 'g')
                {
                    mask = (1 << (m - 'a')) | u.f;
                    if(d[x][y][mask] == 0)
                    {
                        q.push(mp(mask,mp(x,y)));
                        d[x][y][mask] = d[u.s.f][u.s.s][u.f] +1;
                    }
                }
                else if(m >= 'A' && m <= 'G')
                {
                    if(((1<<(m - 'A')) & u.f) && d[x][y][u.f] == 0)
                    {
                        d[x][y][u.f] = d[u.s.f][u.s.s][u.f] +1;
                        q.push(mp(u.f,mp(x,y)));
                    }
                }
                else if(m == '*')
                {
                    return d[u.s.f][u.s.s][u.f];
                }
                           
                else if(d[x][y][u.f] == 0)
                {
                    d[x][y][u.f] = d[u.s.f][u.s.s][u.f] +1;
                    q.push(mp(u.f,mp(x,y)));
                }
            }
        }
    }
    return -1;
}
int main(void)
{
    int a,b;
    while(scanf(" %s", mat[n++]) != EOF);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; mat[i][j] != '\0'; j++)
        {
            if(mat[i][j] == '@') { a = i; b = j; break;}
        }
    }
    int ans = bfs(a,b);
    if(ans != -1) printf("%d\n", ans);
    else printf("--\n");

    return 0;
}