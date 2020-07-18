#include<bits/stdc++.h>
using namespace std;

char grid[11][11];
int di[] = {-1, 1,-1, 1};
int dj[] = {-1,-1, 1, 1};

int capture(int i, int j) {
    int m=0;
    for(int k=0; k<4; k++){
        int i2  = i + di[k], j2 = j + dj[k];
        int i3 = i + 2*di[k], j3 = j + 2*dj[k];
        if(grid[i2][j2] == 'B' && grid[i3][j3] == '#'){
            grid[i2][j2] = 'W';
            grid[i2][j2] = '#';
            grid[i][j] = '#';
            m = max(m, 1+capture(i3, j3));
            grid[i3][j3] = '#';
            grid[i2][j2] = 'B';
            grid[i][j] = 'W';
        }
    }
    return m;
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--){
        int i, j;
        int m=0;
        for (i = 0; i < 10; i++) scanf(" %s", grid[i]);
        for (i = 0; i < 10; i++)
            for (j = 0; j < 10; j++)
                if(grid[i][j] == 'W')
                    m = max(m,capture(i,j));

        printf("%d\n", m);
        memset(grid, 0, sizeof(grid));
    }
    return 0;
}
