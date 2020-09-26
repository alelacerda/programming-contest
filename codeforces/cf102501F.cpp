#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second
typedef pair<double,double> point;
typedef vector<point> polygon;

double area(polygon p){
    int tam = p.size();
	double area = 0.0;
	for (int i = 0; i < tam; i++) {
	point p1 = p[i], p2 = p[(i+1)%tam];
	area += (p2.x+p1.x)*(p2.y-p1.y);
	}
	area /= 2.0;
	return abs(area);
}

int main(){
    int n;  
    scanf("%d", &n);
    double total=0.0;
    for(int i=0; i<n; i++){
        polygon p;
        int lados; scanf("%d", &lados);
        while (lados--)
        {    
            point new_pair;
            scanf("%lf %lf", &new_pair.x, &new_pair.y);
            p.push_back(new_pair);
        }
        total += area(p);
    }
    printf("%lld\n", (long long)total);
    return 0;
}