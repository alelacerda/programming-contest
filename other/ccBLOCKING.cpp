#include<bits/stdc++.h>
using namespace std;
#define MAX 112

int n;
int a[MAX][MAX], b[MAX][MAX], c[MAX];
int match[MAX], watch[MAX], proposed[MAX];

void s_marriage(){
    int m, w, flag =1;
    for(m=0; m<n; m++){match[m]=-1; proposed[m]=0; watch[m]=-1;}
    while(flag){
        flag =0;
        for(int i=0; i<n; i++){
            while(match[i] == -1){
                flag =1;
                int w = a[i][proposed[i]++];
                if(watch[w] == -1){
                    watch[w]=i;
                    match[i]=w;
                }else
                {
                    int j=watch[w];
                    if(b[w][i] > b[w][j]){
                        watch[w] = i;
                        match[i] = w;
                        match[j] = -1;
                    }
                }
            }
            
        }
    }  
}

bool cmp(int a, int b){
    return c[a]<c[b];
}

int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n;j++){
            scanf("%d", &c[j]);
            a[i][j] = j;
            b[j][i] = c[j];
        }
        sort(a[i], a[i]+n, cmp);
    }

    s_marriage();

    for(int i=0; i<n; i++)
        printf("%d ",match[i]+1);  
    puts("");
    return 0;
}