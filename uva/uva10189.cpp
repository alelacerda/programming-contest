#include <bits/stdc++.h>
using namespace std;

#define MAX 112

int n, m;

int d[8][2] = {{0,-1},{-1,0},{0,1},{1,0},{-1,-1},{-1, 1},{1, -1},{1, 1}};


bool isValid(int i, int j)
{
    return !(i < 0 || i >= n || j < 0 || j >= m);
}

int main()
{
    int tcase = 0; bool first = true;
    while(scanf("%d %d", &n, &m), n && m)
    {
        tcase++;
        char grid[MAX][MAX];
        for(int i = 0; i < n; i++)
            scanf("%s", &grid[i]);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] != '*')
                {
                    int count = 0;
                    for(int k = 0; k < 8; k++)
                    {
                        int a = i + d[k][0]; int b = j + d[k][1];
                        if(isValid(a, b) && grid[a][b] == '*')
                            count++;
                    }
                    grid[i][j] = (char) count + '0';
                }
            }
        if(!first) printf("\n");
        printf("Field #%d:\n", tcase);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
                printf("%c", grid[i][j]);
            printf("\n");
        }
        first = false;
    }
    return 0;
}