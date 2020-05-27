#include <bits/stdc++.h>
using namespace std;
#define MAX 26
#define INF 1e8

int main(void)
{
    int gy[MAX][MAX],gm[MAX][MAX],n;

    while(scanf("%d",&n),n)
    {
        for(int i = 0; i < MAX; i++)
        {
            for(int j = 0; j < MAX; j++)
                gy[i][j] = gm[i][j] = INF;
            gy[i][i] = gm[i][i] = 0;
        }

        char a,d,x,y;
        int c;
        for(int i = 0; i < n; i++)
        {
            scanf(" %c %c %c %c %d",&a,&d,&x,&y,&c);
            x -= 'A';
            y -= 'A';
            if(a == 'Y')
            {
                gy[x][y] = min(gy[x][y],c);
                if(d == 'B') gy[y][x] = min(gy[y][x],c);
            }
            else 
            {
                gm[x][y] = min(gm[x][y],c);
                if(d == 'B') gm[y][x] = min(gm[y][x],c);
            }
        }

        scanf(" %c %c",&x,&y);
        x -='A'; y -= 'A';
        for(int w = 0; w < MAX; w++)
            for(int u = 0; u < MAX; u++)
                for(int v = 0; v < MAX; v++)
                {
                    gy[u][v] = min( gy[u][v], gy[u][w] + gy[w][v]);
                    gm[u][v] = min( gm[u][v], gm[u][w] + gm[w][v]);
                }

        int ans = INF;
        for(int v = 0; v < MAX; v++)
            if(gy[x][v] + gm[y][v] < ans) ans = gy[x][v] + gm[y][v];

        if(ans == INF) printf("You will never meet.\n");
        else 
        {
            printf("%d",ans);
            for(int v = 0; v < MAX; v++)
                if(gy[x][v] + gm[y][v] == ans) printf(" %c",v+'A');
            printf("\n");
        }

    }
    return 0;
}