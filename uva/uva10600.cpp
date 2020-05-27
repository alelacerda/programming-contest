#include <bits/stdc++.h>
#define MAX 1123456
#define INF 1123456
using namespace std;

struct edge{
	int u, v, w;
	edge(){}
	edge(int _u, int _v, int _w):u(_u), v(_v), w(_w){}
};

bool cmp(edge e, edge f){return (e.w < f.w);}

edge eg[MAX];
int n,m;
int _p[MAX], vis[MAX], vis_num=0;

int _find(int u){return ((_p[u]==u)? u : (_p[u]=_find(_p[u])));};

void _union(int u, int v){
        u = _find(u); v = _find(v);
        if(u < v) _p[u] = v;
        else{
            _p[v]= u;
        }
}

int kruskal(){
	int u=0, v=0, sum=0;
	int e=0;

	sort(eg, eg+m, cmp);
	
    //escolas sao numeradas de 1 a N
	for(int j=1; j<=n; j++){_p[j]=j;}
	
	for(int i=0; i<m && e<n-1; i++){		
		u = eg[i].u; 
		v = eg[i].v;
		
		if(_find(u) != _find(v))
		{
			_union(u,v);
			sum+=eg[i].w;
			vis[vis_num++]=i;
			e++;
		}
    }
	return sum;	
}

int main(){
	int t, a, b, c, ans1, ans2, i, j;
	
	scanf("%d", &t);
	while(t--){
		memset(vis,0,sizeof(vis));
		
		scanf("%d %d", &n, &m);
		
		
		for(i=0; i<m; i++){
			scanf("%d %d %d", &a, &b, &c);
			eg[i] = edge(a, b, c);
		}
		
		ans1 = kruskal();
		
		int mini = INF;
		for(i=0; i<vis_num; i++){ //pra todo vertice da mst
			
			for(j=1; j<=n; j++){_p[j]=j;}
			
			int u=0, v=0;
			int e=0;
			ans2=0;
			
            for(j=0; j<m && e<n-1; j++)// faz uma nova mst sem o vertice
            {
                if(vis[i]==j) continue;
                
				u = eg[j].u; 
				v = eg[j].v;
				
				if(_find(u) != _find(v))
				{
					_union(u,v);
					ans2+=eg[j].w;
					e++;
				}
                
            }
            if(e==n-1 && ans2<mini)mini=ans2;
		}				
				
		printf("%d %d\n", ans1, mini);
	}
	
	return 0;
}
