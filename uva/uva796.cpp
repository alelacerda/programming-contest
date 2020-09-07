#include<bits/stdc++.h>
using namespace std;
#define MAX 112
#define INF 0x3f3f3f3f

int n;
vector<int> adj[MAX];

int tin[MAX];
int low[MAX];
int timer;
vector<pair <int,int>> bridge;

void dfs(int v, int p){
    tin[v] = low[v] = timer++;
    for(int i:adj[v]){
        if(i == p) continue;
        if(tin[i] == -1){
            dfs(i, v);
            low[v] = min(low[v], low[i]);
            if(low[i] > tin[v])
                bridge.push_back(make_pair(min(v,i),max(v,i)));
        } else {
            low[v] = min(low[v], tin[i]);
        }
    }
}

void find_bridges() {
    timer = 0;
    fill(tin, tin + n, -1);
    fill(low, low + n, INF);
    bridge.clear();
    for (int i = 0; i < n; ++i) {
        if (tin[i] == -1)
            dfs(i, -1);
    }
}

int main(){
    while(scanf("%d", &n) != EOF){
        for(int i=0; i< n; i++){
            adj[i].clear();
        }

        for(int j=0; j<n; j++){
            int a,b;
            scanf(" %d (%d)", &a, &b);
            while(b--){
                int c;
                scanf(" %d", &c);
                adj[a].push_back(c);
                adj[c].push_back(a);
            }
        }
        find_bridges();
        sort(bridge.begin(), bridge.end());
        printf("%d critical links\n", (int)bridge.size());
        for(int i=0; i< (int)bridge.size(); i++){
            printf("%d - %d\n", bridge[i].first, bridge[i].second);
        }
        printf("\n");
    }

    return 0;
}