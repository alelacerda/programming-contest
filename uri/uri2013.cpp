#include <bits/stdc++.h>
char n[23],dig[10];
int size,ans;

int dim(int i)
{
    while(--i >= 0)
    {
        if(dig[i] < 2)
        {
            ans = i;
            return 1;
        }
    }
    return 0;
}

void fill(int a)
{
    for(int i = a; i < size; i++)
    {
        for(int j = 9; j >= 0; j--)
        {
            if(dig[j]<2)
            {
                n[i] = j + '0'; dig[j]++;
                break;
            }
        }
    }
}
int main(void)
{
    scanf(" %s", n);
    size = strlen(n);
    int i;
    memset(dig, 0, sizeof(dig));
    for (i = 0; i < size; i++)
    {
        dig[n[i] - '0']++;
        if(dig[n[i]-'0'] > 2) break;
    }

    while(i != size && i >=0)
    {
        if(dim(n[i] - '0'))
        {
            dig[n[i] - '0']--;
            dig[ans]++;
            n[i] = ans +'0';
            fill(i+1);
            break;
        }
        
        dig[n[i]-'0']--;i--;
    }
    if(n[0] == '0') printf("%s\n", n+1);
    else printf("%s\n",n);
    return 0;
}