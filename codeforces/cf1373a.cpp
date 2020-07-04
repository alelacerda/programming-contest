#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        unsigned long long int a,b,c;
        scanf("%llu %llu %llu", &a, &b, &c);
        if(a < c) printf("1 ");
        else printf("-1 ");

        if(b*a > c) printf("%llu", b);
        else printf("-1");
        printf("\n");
    }
    return 0;
}