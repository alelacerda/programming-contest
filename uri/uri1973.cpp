#include <bits/stdc++.h>

#define MAX 1123456

long long int farms[MAX];
bool visited[MAX];

bool isEven(int a)
{
    return !(a&1);
}

int main()
{
    long long int n, finished = 0, stolen = 0, total = 0, vis = 0;
    bool is_even;
    memset(visited, 0, sizeof(visited));
    
    scanf("%lli", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%lli", &farms[i+1]);
        total += farms[i+1];
    }
    
    int i = 1;
    while(true)
    {   
        if(i < 1 || i > n) break;
        is_even =  isEven(farms[i]);
        if(!visited[i]) { visited[i] = true; vis++; }
        if(farms[i] > 0) { farms[i]--; stolen++;}
        is_even ? i-- : i++;
    }
    printf("%lli %lli\n", vis, (total - stolen));

    return 0;
}