#include <bits/stdc++.h>
using namespace std;

#define MAX 212

int n,q;
int query[MAX];
vector<int> v[MAX];
vector<int> g[MAX];
int match[MAX];
bool vis[MAX];

int aug(int u){
    for(int i=0; i<(int)g[u].size(); i++){
        int j = g[u][i];
        if(!vis[j]){
            vis[j]=true;
            if(match[j] == -1||aug(match[j])){
                match[j]=u;    
                return 1;
            }
        }
    }
    return 0;
}

int main(){
    int a,b,c;
    bool flag;
    while(scanf("%d %d", &n, &q) != EOF){
        flag=false;
        for(int i=0;i<n;i++)v[i].clear();
            //do housekeeping stuff

        for(int i=0; i<n; i++){
            scanf(" %d", &b);
            if(b==n)flag=true;
            while(b--){
                scanf(" %d", &c);
                c--;
                v[i].push_back(c);
            }
        }

        for(int i=0; i<q; i++){
            for(int i=0;i<n;i++)g[i].clear();
            memset(query, 0, sizeof(query));
            
            scanf(" %d", &b);
            if(!b){
                if(flag){printf("N\n");}
                else{printf("Y\n");}
                continue;
            }

            for(int i=0; i<b; i++){
                scanf(" %d", &a);
                a--;
                query[a]=1;
            }
            
            for(int i=0; i<n; i++){
                for(int j=0; j<v[i].size(); j++){
                    if(query[v[i][j]]){   //TODO
                        //printf("%d %d\n", i,v[i][j] );
                        g[i].push_back(v[i][j]);}
                }
            }

            int ans=0;   
            memset(match, -1, sizeof(match));         
            for(int i=0; i<n*2; i++){
                memset(vis, false, sizeof(vis));
                ans += aug(i);
            }
            if(ans == b){printf("Y\n");}
            else{printf("N\n");}
        }
    }
    return 0;
}