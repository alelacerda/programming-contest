#include <bits/stdc++.h>

int main()
{
    int n, tcase;
    scanf("%d", &tcase);
    while(tcase--)
    {
        scanf(" %d", &n);
        int l = 4*(n-1);
        int d = (n*n - l);
        if(n == 1) printf("0.000\n");
        else printf("%.3f\n", l + d*sqrt(2)); 
        if(tcase) printf("\n");
    }
    
    return 0;
}
