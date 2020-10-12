#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, cont=1;
    scanf("%d", &t);
    while(t--){
        int l,w,h;
        scanf("%d %d %d", &l, &w, &h);
        if(l>20 || w>20 || h>20)
            printf("Case %d: bad\n", cont);
        else
            printf("Case %d: good\n", cont);
        cont++;
    }

    return 0;
}