#include <bits/stdc++.h>
#define MAX 1123456
using namespace std;


struct town{
	int x, y;
	town(){}
	town(int _x, int _y): x(_x), y(_y){}
};

struct edge{
	int u, v;
	double w;
	edge(){}
	edge(int _u, int _v, double _w):u(_u), v(_v), w(_w){}
};


edge eg[MAX];
town towns[MAX];
int n, m, tam, teste;
int _p[MAX], rank[MAX];

double dist(town a, town b){
	return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

bool cmp(edge e, edge f){return (e.w < f.w);}


int _find(int u){return ((_p[u]==u)? u : (_p[u]=_find(_p[u])));};

void _union(int u, int v){
        u = _find(u); v = _find(v);
        if(u > v) _p[u] = v;
        else{
            _p[v]= u;
        }
}

int kruskal(){
	int u=0, v=0, sum=0;
	int e=0;

	sort(eg, eg+teste, cmp);
	
	for(int i=0; i<teste && e<n-1; i++){		
		u = eg[i].u; 
		v = eg[i].v;
		
		if(_find(u) != _find(v))
		{
			_union(u,v);
			printf("%d %d\n", u, v);
			e++;
		}
    }
	return sum;	
}

int main(){
	int t,x,y,i,j;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(i = 1; i<=n; i++){
			scanf("%d %d", &x, &y);
			towns[i] = town(x, y);
		}
		
		scanf("%d",&m);
		for(j=0; j<m; j++){
			scanf("%d %d", &x, &y);
			eg[j] = edge(x, y, dist(towns[x], towns[y]));
		}
		
		int u,v, e=0;
		sort(eg, eg+m, cmp);
		
		for(j=1; j<=n; j++){_p[j]=j;}
		
		for(i=0; i<m; i++){		
			u = eg[i].u; 
			v = eg[i].v;
			
			if(_find(u) != _find(v))
			{
				_union(u,v);
				e++;
			}
		}

		teste=0;
		for(i=1; i<=n; i++){
			for(j=i+1; j<=n; j++) //eh um undirected graph
				eg[teste++] = edge(i, j, dist(towns[i], towns[j]));
		}
		if(e==n-1){printf("No new highways need\n");}
		else{kruskal();}
		if(t!=0)printf("\n");
	}
	return 0;
}