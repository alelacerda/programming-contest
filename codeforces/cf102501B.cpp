#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    map<string, int> m;
    map<string, int>::iterator it;
    for(int i=0; i<n; i++){
        char animal[20];
        scanf("%s", animal);
        m[animal]++;
    }
    bool flag=true;
    for (it = m.begin(); it != m.end() && flag; it++){
        if(it->second > (n - it->second)){
            cout << it->first << endl;
            flag = false;
        }
    }
    if(flag) printf("NONE\n");
    return 0;
}