#include <bits/stdc++.h>
using namespace std;

vector<string> tab = {"H", "HE", "LI", "BE", "B", "C", "N", "O",
                      "F", "NE", "NA", "MG", "AL", "SI", "P", "S",
                      "CL", "AR", "K", "CA", "SC", "TI", "V", "CR",
                      "MN", "FE", "CO", "NI", "CU", "ZN", "GA", "GE",
                      "AS", "SE", "BR", "KR", "RB", "SR", "Y", "ZR",
                      "NB", "MO", "TC", "RU", "RH", "PD", "AG", "CD",
                      "IN", "SN", "SB", "TE", "I", "XE", "CS", "BA",
                      "LA", "CE", "PR", "ND", "PM", "SM", "EU", "GD",
                      "TB", "DY", "HO", "ER", "TM", "YB", "LU", "HF",
                      "TA", "W", "RE", "OS", "IR", "PT", "AU", "HG",
                      "TL", "PB", "BI", "PO", "AT", "RN", "FR", "RA",
                      "AC", "TH", "PA", "U", "NP", "PU", "AM", "CM",
                      "BK", "CF", "ES", "FM", "MD", "NO", "LR", "RF",
                      "DB", "SG", "BH", "HS", "MT", "DS", "RG", "CN",
                      "NH", "FL", "MC", "LV", "TS", "OG"};

int dfs(string s)
{
    if(!s.size()) return 1;
    for(int i = 0; i < tab.size(); i++)
    {
        if(s.size() >= tab[i].size())
            if(s.substr(0, tab[i].size()) == tab[i])
                if(dfs(s.substr(tab[i].size(), s.size() - tab[i].size())))
                    return 1;
    }
    return 0;
}
int main(void)
{
    char str[15];
    string s;
    scanf("%s",str);
    s = string(str);
    printf("%s\n", dfs(s)? "YES" : "NO");

    return 0;
}