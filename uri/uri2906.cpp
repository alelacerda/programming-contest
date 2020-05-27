#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n;
    char st[102];
    string str;
    set<string> s;
    scanf(" %d",&n);
    for(int i = 0; i < n; i++)
    {
        scanf(" %s", st);
        str = string(st);
        for(int j = 0; j <str.size(); j++)
        {
            if(str[j] == '@') break;
            else if (str[j] == '.')
            {
                str.erase(str.begin()+j);
                j--;
            }
            else if(str[j] == '+')
            {
                while(str[j] != '@') str.erase(str.begin()+j);
                break;
            }
        }
        s.insert(str);
    }
    printf("%d\n",s.size());
    return 0;
}