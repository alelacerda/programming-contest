#include <bits/stdc++.h>
using namespace std;
#define MAX 1123
int memo[MAX],path[MAX],n=0;
struct Elephant
{
    int w;
    int iq;
    int id;
}e[MAX];
bool cmp(Elephant a, Elephant b)
{
    return a.iq>b.iq;
}
int dp(int i)
{
    if(memo[i] !=-1) return memo[i];
    int max=0;
 
    for(int j=i+1;j<n;j++)
    {
        if(e[j].w>e[i].w)
        {
            int x = dp(j);
            if(x>max)
            {
                max=x;
                path[i]=j;
            }
        }
    }
 
    return memo[i]= 1+max; 
}
void print_path(int i)
{
    if(i==-1) return;
    printf("%d\n",e[i].id);
    print_path(path[i]);
}
int main(void)
{
    int ans=-1,j;

    while(scanf(" %d %d", &e[n].w, &e[n].iq) != EOF)
    {
        e[n].id = n+1;n++;
    }
    sort(e,e+n,cmp);
    memset(memo,-1,sizeof(memo));
    memset(path,-1,sizeof(path));

    for(int i =0; i <n; i++)
    {
        int x =dp(i);
        if(x>ans)
        {
            ans = x;
            j = i;
        }
    }
    printf("%d\n",ans);
    print_path(j);

    return 0;
}