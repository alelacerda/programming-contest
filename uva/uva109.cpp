#include<bits/stdc++.h>
using namespace std;

#define MAX 112
#define x first
#define y second
typedef pair<int,int>point;
typedef vector<point> polygon;

int test_esq(point a, point b, point c){
    int det = (b.x - a.x)*(c.y - a.y) - (c.x - a.x)*(b.y - a.y);
    if(det > 0) return 1;
    if(det < 0) return -1;
    return 0; // else
}

// dois vetores ab e ac aka det
int cross(point a, point b,point c){
    return (b.x - a.x)*(c.y - a.y) - (c.x - a.x)*(b.y - a.y);
}

bool cmp(point a, point b){
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

// devolve poligono convexo ordenado no sentido antihorario
polygon convexHull(polygon a){
    int n = a.size(), k=0;
    if(n <=3)
        return a;
    
    polygon ans(2*n);
    sort(a.begin(), a.end(), cmp);

    for(int i=0; i<n; i++){
        while(k>= 2 && (cross(ans[k-2], ans[k-1], a[i]) <= 0))
            k--;
        ans[k++] = a[i];
    }
    for(int i=n-1, t = k+1; i>0; i--){
        while(k>= t && (cross(ans[k-2], ans[k-1], a[i-1]) <= 0))
            k--;
        ans[k++] = a[i-1];
    }
    ans.resize(k-1);
    return ans;
}

bool is_inside(polygon p, point q){
    int n = p.size();
    for(int i=0; i<n;i++)
        if(test_esq(p[i], p[(i+1)%n], q) == -1)
            return false;
    return true;
}

double area_p(polygon p){
    int n = p.size();
    double area = 0.0;
    for(int i=0; i<n; i++){
        point p1 = p[i], p2 = p[(i+1)%n];
        area += (p2.x + p1.x) * (p2.y - p1.y);
    }
    area /= 2.0;
    return abs(area);
}

int main(){
    int n, i, j;
    polygon mi;
    vector<polygon> ki;
    while(scanf(" %d", &n), n != -1){
        polygon pt;
        for(i=0; i<n; i++){
            int c,d;
            scanf(" %d %d", &c, &d);
            pt.push_back(point(c,d));
        }
        polygon conv = convexHull(pt); 
        ki.push_back(conv);
    }

    mi.clear();
    int a, b;
    while(scanf(" %d %d", &a, &b) != EOF)
        mi.push_back(point(a,b));


    int qtm = mi.size(), qtr = ki.size();
    double ans=0.0;
    bool boom[qtr];

    for(j=0; j<qtr; j++) boom[j] = false;
    
    for(i=0; i<qtm; i++){ // teste de esquerda pra cada míssel em cada polígono
        for(j=0; j<qtr; j++){
            if(!boom[j] && is_inside(ki[j],mi[i])){
                ans += area_p(ki[j]);
                boom[j] = true;
            }
        }
    }
    printf("%.2f\n", ans);
    return 0;
}