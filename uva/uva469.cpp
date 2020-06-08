#include <bits/stdc++.h>
using namespace std;

#define MAX 112

int n, m, cont, ans;
char mapa[MAX][MAX];
int vis[MAX][MAX];

int dir[8][2] = {{0,-1},{-1,0},{0,1},{1,0},{-1,-1},{-1, 1},{1, -1},{1, 1}};

void dfs(int i, int j) 
{
  int k, a, b;
  if (vis[i][j]) return;
  vis[i][j] = 1;ans++;
  for (k = 0; k < 8; k++) 
  {
    a = i + dir[k][0]; b = j + dir[k][1];
    if (0 <= a && a < n && 0 <= b && b < m && mapa[a][b] == 'W')
        dfs(a, b);
  }
}

int main(void)
{
    int cases;
    char str[MAX];
    scanf("%d ", &cases);
    
    while(cases--)
    {
        memset(mapa,0,sizeof(mapa));
        n = 0;
        while(gets(str))
        {
            if(str[0] == '\0') break;
            if(str[0] == 'W' || str[0] == 'L')
                sscanf(str, "%s", mapa[n++]);
            else
            {
                m = strlen(mapa[0]);
                int i,j;
                sscanf(str,"%d %d",&i,&j);
                memset(vis,0,sizeof(vis));
                ans = 0;
                dfs(i-1,j-1);
                printf("%d\n", ans);
            }
        }
        if(cases) puts("");
    }
    return 0;
}