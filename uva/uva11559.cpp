#include <bits/stdc++.h>
using namespace std;


#define INF 1123456
int main()
{
    int n, b, h, w;
    
    while(scanf("%d %d %d %d", &n, &b, &h, &w) != EOF)
    {
        int ans = INF;
        for(int i = 0; i < h; i++)
        {
            int p;
            scanf("%d", &p);
            for(int j = 0; j < w; j++) 
            {
                int beds;
                scanf("%d", &beds);
                if(p*n < ans && beds >= n && p*n <= b)
                    ans = p * n;
            }
        }
        if(ans == INF) printf("stay home\n");
        else printf("%d\n", ans);

    }

    return 0;
}