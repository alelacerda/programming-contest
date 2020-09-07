#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int months,ndr;
    double dpay, loan, dep[112];
    while(scanf("%d %lf %lf %d",&months, &dpay, &loan, &ndr), months > 0)
    {
        memset(dep,0, sizeof(dep));
        while(ndr--)
        {
            int m; double p;
            scanf("%d %lf", &m, &p);
            for(int i = m; i < months; i++) dep[i] = p;
        }
        int ans = 0;
        double mp = (loan/months), val = (loan + dpay) * (1 - dep[0]), curLoan = loan;
        while(val < curLoan)
        {
            ans++;
            curLoan -= mp;
            val = val * (1-dep[ans]);
        }

        printf("%d %s\n",ans, ans != 1? "months" : "month");

    }
    return 0;
}