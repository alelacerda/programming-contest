#include <bits/stdc++.h>
using namespace std;

char m[8][8];
int isA[8][8];
int p[9][2] = { {0,0},{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1} };



int valid(int i, int j)
{
    return (i >= 0 && i < 8 && j >= 0 && j < 8);
}
void attackP(int i, int j)
{
    int k = i + 1;
    while (valid(k, j))
    {
        isA[k][j] = 1;
        if(m[k][j] != 0) break;
        k++;
    }
    k = i - 1;
    while (valid(k, j))
    {
        isA[k][j] = 1;
        if(m[k][j] != 0) break;
        k--;
    }
    k = j + 1;
    while (valid(i, k))
    {
        isA[i][k] = 1;
        if(m[i][k] != 0) break;
        k++;
    }
    k = j - 1;
    while (valid(i, k))
    {
        isA[i][k] = 1;
        if(m[i][k] != 0) break;
        k--;
    }
}
void attackD(int i, int j)
{
    int k = i - 1, l = j - 1;
    while (valid(k, l))
    {
        isA[k][l] = 1;
        if(m[k][l] != 0) break;
        k--; l--;
    }
    k = i - 1;
    l = j + 1;
    while (valid(k, l))
    {
        isA[k][l] = 1;
        if(m[k][l] != 0) break;
        k--; l++;
    }
    k = i + 1;
    l = j + 1;
    while (valid(k, l))
    {
        isA[k][l] = 1;
        if(m[k][l] != 0) break;
        k++; l++;
    }
    k = i + 1;
    l = j - 1;
    while (valid(k, l))
    {
        isA[k][l] = 1;
        if(m[k][l] != 0) break;
        k++; l--;
    }
}

void attack(int i, int j)
{
    int k;
    switch (m[i][j])
    {
    case 'P':
        if (valid(i - 1, j - 1)) isA[i - 1][j - 1] = 1;
        if (valid(i - 1, j + 1)) isA[i - 1][j + 1] = 1;
        return;
    case 'T':
        attackP(i, j);
        return;
    case 'B':
        attackD(i, j);
        return;
    case 'R':
        attackP(i, j);
        attackD(i, j);
        return;
    case 'W':
        for (int a = 1; a < 9; a++)
        {
            if (valid(i+p[a][0], j+p[a][1]))
                isA[i+p[a][0]][j+p[a][1]] = 1;
        }
    }
}

int king(int i, int j)
{
    for (int k = 0; k < 9; k++)
    {
        if (valid(i + p[k][0], j + p[k][1]) 
            && isA[i+p[k][0]][j+p[k][1]] == 0)
                return 0;
    }
    return 1;
}
int main(void)
{
    int n,x;
    char a,b;
    char str[3];
    while (scanf("%d", &n) != EOF)
    {
        memset(isA, 0, sizeof(isA));
        memset(m, 0, sizeof(m));
        char ri, rj;
        for (int i = 0; i < n; i++)
        {
            scanf(" %c",&a);
            scanf("%c",&b);
            scanf("%d",&x);
            m[x - 1][b - 'a'] = a;
        }
        scanf(" %c",&a);
        scanf("%c",&b);
        scanf("%d",&x);
        ri = x - 1;
        rj = b - 'a';
        for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++)
                if (m[i][j] != 0) attack(i, j);
        printf("%s\n", king(ri, rj) ? "SIM" : "NAO");
    }
    return 0;
}