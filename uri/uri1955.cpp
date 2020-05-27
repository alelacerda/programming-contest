#include <bits/stdc++.h>
using namespace std;

#define V 1123
#define MAX 1123
int matr[MAX][MAX],n;
int colorA[MAX];

bool Bipartite(int G[][V], int s) 
{
   colorA[s] = 1;
   queue <int> q; 
   q.push(s);
   while (!q.empty()) 
   {
      int w = q.front();
      q.pop();
      for (int v = 0; v < n; v++)
      {
         if ((!G[w][v]) && (colorA[v] == -1)){ 
            colorA[v] = 1 - colorA[w];
            q.push(v);
         }
         else if ((!G[w][v]) && (colorA[v] == colorA[w]))
            return false;
      }
   }
   return true;
}

int main()
{
    bool flag = false;
    scanf("%d", &n);
    memset(colorA, -1, sizeof(colorA));
    for(int i = 0; i < n; i++)
    {    for(int  j = 0; j < n; j++)
        {
            int a;
            scanf("%d", &a);
            matr[i][j] = a;
        }
    }
    for(int i=0; i<n; i++)        
        if(colorA[i] == -1){
            if(!Bipartite(matr, i)){flag=true;}
        }
        
    printf("%s\n",flag? "Fail!":"Bazinga!");
    return 0;
}