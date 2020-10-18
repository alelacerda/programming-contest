#include<bits/stdc++.h>
using namespace std;

int isPrime(int n){
    for(int i=2; i*i<=n;i++){
        if(n%i ==0){
            return 0;
        }
    }
    return 1;
}

int main(){
    int a,b;
    int primos[10010];
    memset(primos, 0, sizeof(primos));
    for(int i=0; i <=10010; i++)
        primos[i] = isPrime(i*i + i + 41);
    
    while(scanf("%d%d", &a, &b) != EOF){
        int sum = 0;
        for (int i = a; i <= b; i++) 
            sum += primos[i];
        printf("%.2f\n", sum * 1.0 / (b - a + 1) * 100 + 1e-8);
    }
    return 0;
}