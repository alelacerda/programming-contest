#include <bits/stdc++.h>
using namespace std;

int n;

struct restrict
{
    int a;
    int b;
    int c;
    restrict(int _a, int _b, int _c)
    {
        a = _a;
        b = _b;
        c = _c;
    }
};
int find(int x, int p[])
{
    int i;
    for( i = 0; i < n; i++)
    {
        if(x == p[i]) break;
    }
    return i;
}

int seats(int i, int j, int p[])
{
    return abs(find(i,p)-find(j,p));
}

int main(void)
{
    int m;
    vector<restrict> r;

    while(scanf("%d %d",&n,&m), n)
    {
        int p[8] = {0,1,2,3,4,5,6,7};
        int ans = 0;
        r.clear();
        for(int i = 0; i < m; i++)
        {
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            r.push_back(restrict(a,b,c));
        }
        do{
            int f = 1;
            for (int i = 0; i < r.size(); i++)
            {
                int a = r[i].a;
                int b = r[i].b;
                int c = r[i].c;
                if((c < 0 && seats(a,b,p) < abs(c))
                    || (c > 0 && seats(a,b,p) > c)) 
                    {
                        f = 0;break;
                    }
            }
            if(f) ans++;
        }while(next_permutation(p,p+n));

        printf("%d\n",ans);
    }
    return 0;
}