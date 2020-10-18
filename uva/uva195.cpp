#include <bits/stdc++.h>
using namespace std;
#define MAX 
bool cmp(char a, char b)
{
    if(tolower(a) == tolower(b))
        return a < b;
    return tolower(a) < tolower(b);
}
int main(void)
{
    int n;
    string str;
    scanf("%d", &n);
    while(n--)
    {
        cin >> str;
        sort(str.begin(), str.end(), cmp);
        do
        {
            cout << str << endl;
        } while (next_permutation(str.begin(), str.end(), cmp));
    }
    return 0;
}