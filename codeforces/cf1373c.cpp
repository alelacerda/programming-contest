#include <bits/stdc++.h>

#define MAX 1123456
char s[MAX];
typedef long long int ll;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf(" %s", s);
        ll ans = strlen(s);
        ll cur=0,mn=0;
        for(int i=0; i< (int)strlen(s);i++){
            if(s[i] == '+') cur += 1;
            else cur-=1;
            if(cur < mn){
                mn = cur;
                ans += (ll)i + 1;
            }
        }
        printf("%lld\n", ans);  
    }

    return 0;
}