#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    char s1[112], s2[112];
    scanf(" %s", s1);
    strlwr(s1);
    scanf(" %s", s2);
    strlwr(s2);
    printf("%d\n",strcmp(s1,s2));
    return 0;
}