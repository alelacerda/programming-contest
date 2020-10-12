#include<bits/stdc++.h>
using namespace std;

bool cmd(int a,int b){
    return (a>b);
}

int main(){
    int a,b,c,x,y;
    bool arr[54]; 
    while(scanf("%d %d %d %d %d", &a, &b, &c, &x, &y), a!=0){
        memset(arr, false, sizeof(arr));
        arr[53]=true;
        int a1[3], a2[2], w, i;
        a1[0]=a;a1[1]=b;a1[2]=c;a2[0]=x;a2[1]=y;
        sort(a1, a1+3, cmd);
        sort(a2, a2+2, cmd);
        //printf("%d %d %d %d %d\n",  a2[0], a2[1], a1[0], a1[1], a1[2]);
        arr[a] = true; arr[b] = true; arr[c] = true;
        arr[x] = true; arr[y] = true;
        if(a2[0]>a1[0] && a2[1]>a1[0]){
            i=1;
            while(arr[i] == true){i++;}
            printf("%d\n", i<53?i:-1);
        }else if(a2[0]>a1[0] && a2[1]>a1[1] || a2[0]>a1[1] && a2[1]>a1[1]){
            i=a1[1];
            while(arr[i] == true){i++;}
            printf("%d\n", i<53?i:-1);
        }
        else if(a2[0]>a1[0] && a2[1]>a1[2] || a2[0]>a1[0] && a2[1]<a1[2]){
            i=a1[0];
            while(arr[i] == true){i++;}
            printf("%d\n", i<53?i:-1);
        }
        else{printf("-1\n");}
    }

    return 0;
}