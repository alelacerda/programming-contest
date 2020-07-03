#include<bits/stdc++.h>
using namespace std;

#define MAX 500

int n, tam;
char a[MAX][MAX]; // anagramas
bool p[MAX]; // paridades 0 = even 1 = odd

vector<int> g[MAX];
int match[MAX];
bool vis[MAX];

bool paridade(int k){
    int i, j, res =0;
    for(i=0; i<(tam-1); i++)
        for(j = i+1; j<tam; j++)
            if(a[k][i] > a[k][j]) res++;
    if(res & 1) // verifica paridade das inversões
        return true; // odd
    else
        return false; // even
}

bool isSwapFree(int i, int j){
    int k, dif=0;
    for(k = 0; k < tam ; k++)
        if(a[i][k] != a[j][k]) dif++;
    if(dif > 2) return true;
    else return false;
}

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
    int i, j;
    scanf("%d", &n);
    for(i = 0; i<n; i++)
        scanf(" %s", a[i]);
    tam = strlen(a[0]);

    for(i=0; i<n; i++)
        p[i] = paridade(i);

    // monta grafo
    int num=0;
    for(i=0; i<n; i++){
        if(p[i])continue;
        num++;
        for(j=0; j<n;j ++){
            if(i == j)continue;
            if(p[j] && !isSwapFree(i,j))
                g[i].push_back(j);
        }
    }

    int ans=0;
    memset(match, -1, sizeof(match));    
    for(i=0;i<n;i++){
        memset(vis, false, sizeof(vis));
        ans += aug(i);
    }

    printf("%d\n", (n-ans));

    return 0;
}