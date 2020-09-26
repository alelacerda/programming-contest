#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n, a, b;
    while(scanf("%lld %lld %lld", &n, &a, &b), n){
        map<ll, int> m;
        ll mortos=0;
        ll next = 0;
        ll x=0;
        m[next] = 1;
        while(m[next] < 3){
            next = ((a * x)%n + b) % n;
            m[next]++;   
            x = (next*next)%n;  
        }
        for(auto i:m){
            if(i.second == 2) mortos++;
        }
        printf("%lld\n", n-mortos-1);        
    }

    return 0;
}