#include<bits/stdc++.h>
using namespace std;

#define MAX 25

char grid[MAX][MAX];

int main(){
    int i, j, n;
    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf(" %s", grid[i]);
    int numb=0, numw=0, cb=0, cw=0;
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            if (grid[i][j] == 'W'){
                numw++;
                cb=0; cw++;
            }
            if (grid[i][j] == 'B'){
                numb++;
                cw=0; cb++;
            }
            if(cb == 3 || cw == 3){
                printf("0\n");
                return 0;
            }
        }
        if(numw != numb){
            printf("0\n");
            return 0;
        } 
        numw=0; numb=0;
        cw=0; cb=0;
    }

    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            if (grid[j][i] == 'W'){
                numw++;
                cb=0;
                cw++;
            }
            if (grid[j][i] == 'B'){
                numb++;
                cw=0;
                cb++;
            }
            if(cb == 3 || cw == 3){
                printf("0\n");
                return 0;
            }
        }
        if(numw != numb){
            printf("0\n");
            return 0;
        } 
        numw=0; numb=0;
        cw=0; cb=0;
    }
    printf("1\n");        
    return 0;
}