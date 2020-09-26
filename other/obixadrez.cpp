#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, t;
    scanf("%d %d", &n, &t);
    // c(n, k) = n!/((n-k)!k!) 
    if(t==0) 
        printf("%d\n", n);
    if(t==1){
        n = n*(n-1);
        printf("%d\n", n);
    }
    if(t==2){
        n = (n*(n-1)*(n-2))/6;
        printf("%d\n", n);
    }
        

    return 0;
}