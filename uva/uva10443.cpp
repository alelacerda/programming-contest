#include <bits/stdc++.h>
using namespace std;
#define MAX 112
char grid[MAX][MAX];
int r,c;

int war(int i, int j)
{
    char a;

    if(grid[i][j] == 'R') a = 'P';
    else if(grid[i][j] == 'S') a = 'R';
    else a = 'S';

    if( (i > 0) && grid[i-1][j] == a) return -1;
    if( (j > 0) && grid[i][j-1] == a) return -1;
    if( (i < r-1) && grid[i+1][j] == a) return -1;
    if( (j < c-1) && grid[i][j+1] == a) return -1;

    return 1;
}

int main(void)
{
    int t, n, i, j, first = 1;
    int res[MAX][MAX];

    scanf("%d", &t);
    while(t--)
    {
        if(first) first = 0;
        else printf("\n");
        scanf("%d %d %d", &r, &c, &n);
        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                char a;
                scanf(" %c", &a);
                grid[i][j] = a;
            }
        }

        while(n--)
        {
            for(i = 0; i < r; i++)
            {
                for(j = 0; j < c; j++)
                {
                    res[i][j] = war(i,j);
                }
            }

            for(i = 0; i < r; i++)
            {
                for(j = 0; j < c; j++)
                {
                    if(res[i][j] == -1)
                    {
                        if(grid[i][j] == 'P') grid[i][j] = 'S';
                        else if(grid[i][j] == 'S') grid[i][j] = 'R';
                        else grid[i][j] = 'P';
                    }
                }
            }
        }
        
        for(i = 0; i < r; i++)
        {
            for(j = 0; j < c; j++)
                printf("%c", grid[i][j]);
            printf("\n");
        }
       
    }
    return 0;
}