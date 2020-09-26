#include<bits/stdc++.h>
using namespace std;


int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n,k;
        scanf("%d %d", &n, &k);
        double power, left;
        power = k* log10(n);
        power = power - floor(power);
        left = pow(10, power)*100;
        n%=1000;
        long long right = 1;
        while(k){
            if(k & 1) right = (right * n) % 1000;
            n = (n*n) % 1000;
            k>>=1;
        }
        printf("%d...%03d\n", (int)left,(int)right);
    }

    return 0;
}