#include<bits/stdc++.h>
using namespace std;

#define MAX 1123
typedef pair<int,int> ii;

int n, m;
int grid[MAX][MAX];
bool vis[MAX][MAX];

int di[] = {1,0,-1,0};
int dj[] = {0,1,0,-1};

void bfs(int i, int j){
    queue<ii> q;
    q.push(ii(i,j));
    vis[i][j] = true;
    while(!q.empty()){
        ii u = q.front();
        q.pop();
        for (int k = 0; k < 4; k++) {
            int i2 = u.first + di[k];
            int j2 = u.second + dj[k];
            if (grid[i2][j2] && !vis[i2][j2]){
                    vis[i2][j2] = true;
                    q.push(ii(i2,j2));
            }
        }

    }
}

int main(void) {
    int i, j, ans=0;
    scanf("%d %d", &n, &m);
    for (i = 0; i <n; i++)
        for (j = 0; j <m; j++)
            scanf("%d", &grid[i][j]);
    for (i = 0; i <n; i++)
        for (j = 0; j <m; j++)
            if (grid[i][j] && !vis[i][j]){
                ans++;
                bfs(i, j);
            } 
    printf("%d\n", ans);
    return 0;
}
