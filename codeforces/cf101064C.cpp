#include <bits/stdc++.h>
using namespace std;
#define MAX 112345
#define INF 11234567
int dist[MAX];

int main()
{
    int h, w, a;
    scanf("%d %d", &h, &w);
    memset(dist, 0, sizeof(dist));
    for(int i = 0; i < h; i++)
    {
        scanf("%d", &a);
        dist[i] = w - a;
    }
    for(int i = 0; i < h; i++)
    {
        scanf("%d", &a);
        dist[i] -= a;
        }
    int xMin = INF;
    for(int i = 0; i < h; i++) if(dist[i] < xMin) xMin = dist[i];


    double ans = xMin / 2.0;

    cout << ans << endl;

    return 0;
}