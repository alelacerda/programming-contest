//lazy propagation
#include <bits/stdc++.h>
using namespace std;
#define MAX 11234567
struct Node
{
    int v, len;
    char type;
};

Node segt[5*MAX];
vector<int> a;
void segtbuild(int p, int l, int r)
{
    int mid = (l+r)/2;
    if(l == r)
    {
        segt[p].v = a[l];
        segt[p].type = -1;
        segt[p].len = 1;
    }
    else
    {
        segtbuild(p*2,l,mid);
        segtbuild(p*2+1,mid+1,r);
        segt[p].v = segt[p*2].v+ segt[p*2+1].v;
        segt[p].type = -1;
        segt[p].len = r-l+1;
    }
}

void set_type(int p, char t)
{
    //inverte
    if(t == 'I')
    {
        switch(segt[p].type)
        {
            case 'F': segt[p].type = 'E'; break;
            case 'E': segt[p].type = 'F'; break;
            case 'I': segt[p].type = -1; break;
            case -1: segt[p].type = 'I'; break;
            default: break;
        }
    }
    //outros casos
    else segt[p].type = t;
}

void cast(int p)
{
    switch (segt[p].type)
    {
        case 'F': segt[p].v = segt[p].len; break;
        case 'E': segt[p].v = 0; break;
        case 'I': segt[p].v = segt[p].len - segt[p].v; break;
        default: return;
    }
    set_type(p*2,segt[p].type);
    set_type(p*2+1,segt[p].type);
    segt[p].type = -1;
}

void update(int p, int l, int r, char t, int i, int j)
{
    int mid = (l+r)/2;
    if(l>=i && r<=j) //dentro do range
    {
        set_type(p,t);
        cast(p); 
        return;
    }
    cast(p);
    if(l > j || r < i) return; //fora do range
    update(p*2,l,mid,t,i,j);
    update(p*2+1,mid+1,r,t,i,j);
    segt[p].v = segt[p*2].v + segt[p*2+1].v;
}

int ans(int p, int l, int r, int i, int j)
{
    int mid = (l+r)/2;
    cast(p);
    if(l >= i && r <= j) return segt[p].v;
    if(l > j || r < i) return 0;
    int p1 = ans(p*2,l,mid,i,j);
    int p2 = ans(p*2+1,mid+1,r,i,j);
    segt[p].v = segt[p*2].v + segt[p*2+1].v;
    
    return (p1+p2);
}
int main(void)
{
    char c,str[52];
    int n,t,test,q,u,v,cas = 1;

    scanf("%d", &test);
    while(cas <= test)
    {
        a.clear();
        printf("Case %d:\n",cas++);
        scanf("%d",&n);
        for(int i = 0; i < n; i++)
        {
            scanf("%d",&t);
            scanf(" %s",str);
            for(int j = 0; j < t; j++)
                for(int k = 0; str[k] !='\0'; k++)
                    a.push_back(str[k]-'0');
        }

        segtbuild(1,0,a.size()-1);
        int cnt = 0;
        scanf("%d",&q);
        for(int i = 0; i < q; i++)
        {
            scanf(" %c %d %d",&c, &u, &v);
            if(c != 'S') update(1,0,a.size()-1,c,u,v);
            else printf("Q%d: %d\n",++cnt,ans(1,0,a.size()-1,u,v));
        }
    }
    return 0;
}