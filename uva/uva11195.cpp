#include <bits/stdc++.h>
using namespace std;

bitset<30> row, ldiag, rdiag;
char board[16][16];
int n,ans;

void backtrack(int p)
{
    if(p == n) 
    {
        ans++;
        return;
    }
    for(int c = 0; c < n; c++)
    {
        if(board[c][p] != '*' && !row[c] && !ldiag[c - p + n - 1] && !rdiag[c + p]) //ve se a pos é valida pra rainha
        {
            row[c] = ldiag[c - p + n - 1] = rdiag[c + p] = true;
            backtrack(p + 1);
            row[c] = ldiag[c - p + n - 1] = rdiag[c + p] = false; //reset
        }
    }
}

int main(void)
{
    int tc = 1;
    while(scanf("%d",&n), n)
    {
        row.reset(); ldiag.reset(); rdiag.reset();
        for(int i = 0; i < n; i++) scanf(" %s",board[i]);
        ans = 0;
        backtrack(0);
        printf("Case %d: %d\n", tc, ans); 
        tc++;
    }
    return 0;
}