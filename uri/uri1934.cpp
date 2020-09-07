#include <bits/stdc++.h>
using namespace std;
#define MAX 123
typedef pair<string,int> si;
char str[2];
int main(void)
{
    int n,m;
    string g[MAX][MAX];
    int sumC[MAX], sumR[MAX];
    set<string> words;
    map<string, int> ans;

    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            scanf(" %s", str);
            g[i][j] = string(str);
            words.insert(g[i][j]);
        }
        scanf("%d", &sumR[i]);
    }
    for(int i = 0; i < m; i++)
        scanf("%d", &sumC[i]);

    while(ans.size() < words.size())
    {
        //vertical
        for(int j = 0; j < m; j++)
        {
            map<string,int> nc;
            int sum = 0;
            for(int i = 0; i < n; i++)
            {
                if(ans.find(g[i][j]) == ans.end())
                    nc[g[i][j]]++;
                else
                    sum +=ans[g[i][j]];                    
            }
            if(nc.size() == 1)
            {
                si p = *nc.begin();
                ans[p.first] = (sumC[j] - sum)/p.second;
            }
        }
        //horizontal
        for(int i = 0; i < n; i++)
        {
            map<string,int> nc;
            int sum = 0;
            for(int j = 0; j < m; j++)
            {
                if(ans.find(g[i][j]) == ans.end())
                    nc[g[i][j]]++;
                else
                    sum +=ans[g[i][j]];                    
            }
            if(nc.size() == 1)
            {
                si p = *nc.begin();
                ans[p.first] = (sumR[i] - sum)/p.second;
            }
        }
    }
    for(auto a: ans)
        cout << a.first << " " << a.second << endl;
    return 0;
}