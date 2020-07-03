#include <stdio.h>
#include <string.h>

#define MAX 1024

int killed[MAX][MAX];

int x, y, size, n, d;

bool isValid(int i, int j)
{
    return !(i < 0 || i >= MAX || j < 0 || j >= MAX);
}

void addtokilled()
{
    for(int i = x - d; i <= x + d; i++)
        for(int j = y - d; j <= y + d; j++)
        {
            if(isValid(i, j))
            {
                killed[i][j] += size;
            }
        }

}


int main()
{
    int tcases;
    scanf("%d", &tcases);
    while(tcases--)
    {
        scanf("%d", &d);
        scanf("%d", &n);
        memset(killed, 0, sizeof(killed));
        for(int i = 0; i < n; i++)
        {
            scanf("%d %d %d ", &x, &y, &size);
            addtokilled();
        }
        int sum = 0;
        int u, v;
        for(int i = 0; i < MAX; i++)
            for(int j = 0; j < MAX; j++)
            {
                if(killed[i][j] > sum)
                {
                    u = i; v = j; sum = killed[i][j];
                }
            }

        printf("%d %d %d\n", u, v, sum);
    }

    return 0;
}