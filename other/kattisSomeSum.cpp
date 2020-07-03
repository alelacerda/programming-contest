#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n;
    scanf("%d",&n);
    if(n%4 == 0) { printf("Even\n"); return 0;}
    if(n%4 == 2) { printf("Odd\n"); return 0;}
    printf("Either\n");
    return 0;
}