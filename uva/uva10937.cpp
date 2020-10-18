#include <bits/stdc++.h>
using namespace std;
#define MAX 55
#define INF 112345
#define LSOne(S) ((S) & -(S))

typedef pair<int,int> ii;
typedef pair<ii, ii> pii;

int memo[1<<11][11]; // n by 2 to the power of n
char m[MAX][MAX];
bool vis[MAX][MAX];

map<pii,int> dist;
vector<ii> tres;

int di[] = {1,0,-1,0};
int dj[] = {0,1,0,-1};
int angryD[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
int h, w, sX, sY, treasure, limit;
/*
//isso aqui ta errado provavelmente
int tsp(int u, int mask) {                        // mask = free coordinates
  if (mask == 0) return dist[u][0];              // close the loop
  int &ans = memo[u][mask];
  if (ans != -1) return ans;                     // computed before
  ans = 2000000000;
  int m = mask;
  while (m) {                                    // up to O(n)
    int two_pow_v = LSOne(m);                    // but this is fast
    int v = __builtin_ctz(two_pow_v)+1;          // offset v by +1
    ans = min(ans, dist[u][v] + dp(v, mask^two_pow_v)); // keep the min
    m -= two_pow_v;
  }
  return ans;
}
*/

int tsp (int mask, int u)
{
    if(memo[mask][u] != -1) return memo[mask][u];
    if(mask == limit) return memo[mask][u] = dist[pii(ii(sX,sY),tres[u])] ;
    int ans =  1e9;
    if(mask == 0)
    {
        for (int i = 0; i < treasure ; i++)
            if(!(mask&(1<<i)))
                ans = min(ans, dist[pii(ii(sX,sY),tres[i])] + tsp(mask|(1<<i), i));       
    }
    else
    {
        for (int i = 0; i < treasure ;i++)
            if(!(mask&(1<<i)))
                ans = min(ans, dist[pii(tres[u],tres[i])] + tsp( mask|(1<<i) , i));
    }
    return memo[mask][u] = ans;
}


//a partir daqui deve estar certo mas não sei 
bool check(int i, int j)
{
    return (i >=0 && i <h && j >=0 && j < w);
}

int main()
{
    bool notPos = false;
    while(scanf(" %d %d", &h, &w), h && w)
    {
        tres.clear();
        dist.clear();
        //treasure = 0;
        //sX=0;sY=0;
        notPos = false;
        for(int i = 0; i < h; i++)
            scanf(" %s", m[i]);

        memset(memo, -1, sizeof(memo));
        memset(vis, false, sizeof(vis));
        //int treasure, sX, sY;
        for(int i = 0; i < h; i++)
        {
            for(int j = 0; j < w; j++)
            {
                if(m[i][j] == '!') tres.push_back(ii(i,j));
                if(m[i][j] == '@') { sX = i; sY = j; tres.push_back(ii(i,j)); }
                if(m[i][j] == '*') 
                {
                    for(int k =0; k<8; k++)
                    {
                        int i2 = i + angryD[k][0];
                        int j2= j + angryD[k][1];
                        if(check(i2,j2)) 
                        {
                            if(m[i2][j2] == '.') m[i2][j2] = '#';
                            else if(m[i2][j2] == '@' || m[i2][j2] == '!') notPos = true;
                        }
                    }
                }
            }
        }
        treasure = tres.size();
        for(int i = 0; i < treasure; i++)
        {
            ii u = tres[i];
            queue<ii> q;
            dist[pii(u,u)] = 0; 
            q.push(ii(u));
            while(!q.empty())
            {
                ii v = q.front(); q.pop();
                for(int j = 0; j < 4; j++)
                {
                    int dr = v.first + di[j], dc = v.second+dj[j];
                    if( check(dr,dc) && 
                        (m[dr][dc] == '!' || m[dr][dc] == '.' || m[dr][dc] == '@')
                        && dist.count(pii(u,ii(dr,dc))) == 0) // !dist.count(pii(u,ii(dr,dc))
                        {
                            dist[pii(u,ii(dr,dc))] = dist[pii(u,v)] +1;
                            q.push(ii(dr,dc));
                        }
                }
            }
        }
        
        for(int i = 0; i < treasure; i++)
        {
            if(dist.count(pii(ii(sX,sY),tres[i])) == 0)
            {
                notPos = true; break;
            }
        }
        
        if(notPos)
        {
            printf("-1\n");
            continue;
        }
        /*
        
        for(int i=0; i<= (1<<treasure); i++)
            for(int j=0; j <= treasure; j++)
                dp[i][j] = -1;
        */
       limit = (1<<treasure)-1;

        //menos aqui, aqui não vi se ta certo ainda
        printf("%d\n", tsp(0,0));    
    }
    return 0;
}