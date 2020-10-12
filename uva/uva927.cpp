#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int find_n(int d, int k){
    int p=0;
    for(int n=1; ; n++){
        int intervp = p;
        p += n*d;
        if(intervp < k && k<=p) return n;
    }
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int i, d, k, c[25], n;
        scanf("%d", &i);
        for(int k=0; k<=i; k++){ // c0 até ci
            scanf("%d", &c[k]);
        }
        scanf("%d", &d);
        scanf("%d", &k);
        n = find_n(d,k);
        ll result = 0;
        ll cn = 1;
        for(int k=0; k<=i; k++){
            result += c[k]*cn;
            cn *=n;
        }
        printf("%llu\n",result);
    }
    return 0;
}
/*
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int a,d, k, c[25];
        scanf("%d", &a);
        for(int i=0; i<=a; i++){
            scanf("%d", &c[i]);
        }
        scanf("%d", &d);
        scanf("%d", &k);
        int n=1;
        while(n*(n+1)/2*d < k){n++;}

        long long result = 0;
        for(int i=a; i>=0;i--){
            result = result * n + c[i];
        }
        printf("%llu\n",result);
    }

    return 0;
}
*/