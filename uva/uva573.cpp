#include <bits/stdc++.h>

int main(void)
{
    int h, u, d, f, day;
    
    while(scanf("%d %d %d %d", &h, &u, &d, &f), h)
    {
        double currH = 0, currU = u, currF = (u*f)/100.0;
        day = 0;
        bool ans = false;
        while(currH <= h && currH >= 0)
        {
            day++;
            if(currU > 0) currH += currU;
            if(currH > h) { ans = true; break; }
            currH -= d;
            currU -= currF;
        }

        if(ans) printf("success on day %d\n", day);
        else printf("failure on day %d\n", day);
    }

    return 0;
}