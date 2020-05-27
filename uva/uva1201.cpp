#include <bits/stdc++.h>
#define MAX 512

using namespace std;

int n, m;
vector<int> g[MAX];
bool vis[MAX];
int matched[MAX];

struct ride{
	int x1, y1, x2, y2;
	int temp;
	int dis;
	void read(){
		int h, min;
		scanf("%d:%d %d %d %d %d", &h, &min, &x1, &y1, &x2, &y2);
		temp = h*60 + min;
		dis = (abs(x1 - x2) + abs(y1 - y2)); 
	};
	
}rides[MAX];

bool match(int u){
	for (int i = 0; i <(int) g[u].size(); i++) {
		int j = g[u][i];
		if (!vis[j]) {
			vis[j] = true;
			if (!matched[j] || match(matched[j])) {
				matched[j] = u;
				return true;
			}
		}
	}
	return false;
}

bool cond(int a, int b){
	int time, dist;
	dist = (abs(rides[b].x1 - rides[a].x2) + abs(rides[b].y1 - rides[a].y2));
	time = rides[a].temp + rides[a].dis + dist;
	return(time < rides[b].temp);
}

int main(){
	scanf(" %d", &n);
	while(n--){
		scanf(" %d", &m);
		for(int i =1; i<=m; i++){
			g[i].clear();
			rides[i].read();
		}
		
		for(int i =1; i<=m; i++){
			for(int j= 1; j<=m; j++){
				if(cond(i, j) && (i!= j))
					g[i].push_back(j);
			}
		}	
		int ans=0;
		memset(matched, 0, sizeof(matched));
		for(int i = 1; i<=m; i++){
			memset(vis, false, sizeof(vis));
			if(match(i))ans++;
		}		
		printf("%d\n", m - ans);
	}
	
	return 0;
}

