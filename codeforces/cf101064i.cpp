#include <bits/stdc++.h>
using namespace std;

#define MAXN 11234

int n,m;
vector<int> g[MAXN];
set<int> aux[MAXN];
bool vis[MAXN];

void dfs(int u, int p){
    vis[u] =true;
    for(int i=0; i<(int)g[u].size(); i++){
        int v = g[u][i];
        if(!vis[v]){
            dfs(v,u);
        }
    }

    aux[u].erase(p);
    while(aux[u].size() > 1){ 
        int a = *aux[u].begin();
        aux[u].erase(a);    //apaga edge 1
        aux[a].erase(u);
        int b = *aux[u].begin();
        aux[u].erase(b);    //apaga edge 2
        aux[b].erase(u);
        printf("%d %d %d\n", a, u, b);
    }

    if(!aux[u].empty()){
        int a = *aux[u].begin();
        aux[u].erase(a);    //apaga ultima edge de u
        aux[a].erase(u);
        int b = p;
        aux[p].erase(u);    //apaga edge entre o pai e o pai do pai
        printf("%d %d %d\n", a, u, b);
    }
}


int main(){

    scanf("%d %d", &n, &m);

    for(int i=0; i<m; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        aux[u].insert(v);
        g[v].push_back(u);
        aux[v].insert(u);
    }

    printf("%d\n", m/2);
    dfs(1,-1);

    return 0;
}