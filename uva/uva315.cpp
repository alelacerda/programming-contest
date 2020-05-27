#include <bits/stdc++.h>
using namespace std;

#define MAX 112

vector<int> g[MAX];
int num[MAX], low[MAX], p[MAX];
int n, id;
bool av[MAX]; //vértices de articulação

void tarjan(int u){
	num[u] = low[u] = id++;
	int children=0;
	
	for(int i=0; i< (int)g[u].size(); i++){
		int v = g[u][i];
		if(num[v] == -1)
		{
			children++;
			p[v] = u;
			tarjan(v);
			low[u] = min(low[u], low[v]);
			
			if(p[u] == -1 && children>1) av[u] = true;
			
			if(p[u] != -1 && low[v] >= num[u]) av[u] = true;			
		}	
		else if( v != p[u]){
			low[u] = min(low[u], num[v]);
		}
	}
}

int main(){
	while(scanf("%d\n", &n),n){
		for(int i=0; i<=n; i++){
			g[i].clear();
			p[i] = -1;
			num[i] = -1;
			low[i] = 0;
			av[i] = false; 
		}
		int u,v;
		while(scanf("%d", &u), u){
			char c;
			while((c = getchar()) != '\n'){ 
				scanf("%d", &v);
				g[u].push_back(v);
				g[v].push_back(u);
			}
		}
		id=0;
		for(int i=1; i<=n; i++){
			if(num[v] == -1){
				tarjan(i);
			}
		}
		int ans=0;
		for(int i = 1; i<=n; i++)
			if(av[i]==true)
				ans++;
				
		printf("%d\n", ans);	
	}
	return 0;
}
