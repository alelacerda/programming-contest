#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

set<pair<ii, int> > maca;
int n,m,k,a,b,c,tmax;
int x[8] = {-1,-1,-1, 0, 1, 1, 1, 0};
int y[8] = {-1, 0, 1, 1, 1, 0,-1,-1};
ii inicio;
int ans_dp[21][21][2123];

int lim(ii a) 
{
	return ((a.first < 0 || a.first >= n || a.second < 0 || a.second >= m)? 0 : 1);
}

int dp(ii u, int t)
{
    if( t == tmax) return 0;

    if(ans_dp[u.first][u.second][t] != -1)
        return ans_dp[u.first][u.second][t];

	int total = dp(u,t+1);
    ii v;
	for(int i = 0; i < 8; i++) 
	{
		v.first = u.first + x[i];
		v.second = u.second + y[i];
		if(lim(v))
			total = max(total, dp(v, t+1));
    }
	return ans_dp[u.first][u.second][t] = total + maca.count(make_pair(u, t));
}

int main()
{
    while(scanf(" %d %d %d",&n,&m,&k), n && m && k)
    {
        maca.clear();
        tmax = 0;
        for(int i=0; i<k;i++)
        {
            scanf(" %d %d %d", &a,&b,&c);
            a--; b--;
            maca.insert(make_pair(ii(a,b),c));
            tmax = max(tmax,c+1);
        }
        scanf(" %d %d", &inicio.first, &inicio.second);
        inicio.first--;
        inicio.second--;
        for(int i = 0; i <n; i++)
            for(int j = 0; j < m; j++)
                memset(ans_dp[i][j], -1, sizeof(ans_dp[i][j]));

        printf("%d\n", dp(inicio,0));
    }

    return 0;
}