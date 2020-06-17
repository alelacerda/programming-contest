#include<bits/stdc++.h>
using namespace std;

#define MAX 11234
#define INF 112345678

int n, k, c;
int prefixsum[MAX];
int dp[MAX][MAX];

int main(){
    int a;
    scanf(" %d %d %d", &n, &k, &c);
    prefixsum[0] = 0;
    for(int i=1; i<=n; i++){
        scanf(" %d", &a);
        prefixsum[i] = prefixsum[i-1] + a;
    }
    
    for(int i=0; i<=n; i++)
        dp[i][0] = 0;

    for(int j=1; j<=k; j++)
        dp[0][j] = INF;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=k; j++){
            //valor anterior
            dp[i][j] = dp[i-1][j];

            if(i >= c){
                dp[i][j] = min(dp[i][j] 
                , dp[i-c][j-1] + (prefixsum[i]-prefixsum[i-c])); 
            }
       }
    }

    printf("%d\n", (prefixsum[n] - dp[n][k]));
    
    return 0;
}