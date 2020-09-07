#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, j=1;
    while(scanf("%d", &n) != EOF){
        int i,a,sum = 0;
        bool flag = true;
        for(i = 0; i<n; i++){
            scanf(" %d", &a);
            
            if(sum == a && flag){
                printf("Instancia %d\n", j++);
                printf("%d\n", a);
                flag = false;
            }
            sum+=a;
        }
        if(flag){
            printf("Instancia %d\n", j++);
            printf("nao achei\n");
        }
        printf("\n");
    }
    return 0;
}