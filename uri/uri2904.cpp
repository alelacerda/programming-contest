#include <bits/stdc++.h>
 
using namespace std; 
#define MAX 112345

int main() {
    int n, arcs[MAX], sum = 0;
    scanf("%d", &n);
    set<int> dist;
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arcs[i]);
        sum += arcs[i];
        dist.insert(sum);
    }
    dist.erase(sum);
    dist.insert(0);
    if(sum & 1)
    {
        printf("N\n");
        return 0;
    }
    int half = sum / 2, pairs = 0, s = 0;
    for(int i = 0; i < n; i++)
    {
        s += arcs[i];
        if(dist.find((s + half) % sum) != dist.end())
            pairs++;
    }
    if(pairs >= 4)
        printf("Y\n");
    else
        printf("N\n");
    return 0;
}