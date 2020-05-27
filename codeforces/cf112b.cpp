#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int dn, x,y;
    scanf(" %d %d %d", &dn, &x, &y);
    dn /= 2;
    printf("%s\n", (x==dn || x== dn+1) && (y == dn || y == dn +1)? "NO": "YES");
    return 0;
}