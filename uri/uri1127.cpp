#include <bits/stdc++.h>
using namespace std;

#define MAX 112345
map<string, int> notes;


int s[MAX], p[MAX],tom[MAX],b[MAX];
int m,t;

void kmpre(void)
{
    int i = 0, j = -1;
    b[0] = -1;
    while (i < t)
    {
        while(j >= 0 && tom[i] != tom[j]) j = b[j];
        b[++i] = ++j;
    }
}

bool kmp(void)
{
    int i = 0, j = 0;
    kmpre();
    while(i < m)
    {
        while(j >= 0 && s[i] != tom[j]) j = b[j];
        i++; j++;
        if(j == t) return true;
    }
    return false;
}

int main(void)
{
    notes["C"] = 0;
    notes["B#"] = 0;
    notes["C#"] = 1;
    notes["Db"] = 1;
    notes["D"] = 2;
    notes["D#"] = 3;
    notes["Eb"] = 3;
    notes["E"] = 4;
    notes["Fb"] = 4;
    notes["F"] = 5;
    notes["E#"] = 5;
    notes["F#"] = 6;
    notes["Gb"] = 6;
    notes["G"] = 7;
    notes["Ab"] = 8;
    notes["G#"] = 8;
    notes["A"] = 9;
    notes["A#"] = 10;
    notes["Bb"] = 10;
    notes["B"] = 11;
    notes["Cb"] = 11;

    int flag;
    char c[3];

    while(scanf("%d %d",&m,&t), m)
    {
        flag = 0;
        for(int i = 0; i < m; i++)
        {
            scanf(" %s",c);
            s[i] = notes[c];
        }
        for(int i = 0; i < t; i++)
        {
            scanf(" %s",c);
            p[i] = notes[c];
        }
        

        for(int i = 0; !flag && i < 12; i++)
        {
            
            for(int j = 0; j < t; j++)
                tom[j] = (p[j]+i)%12;
            
            if(kmp())
            {
                printf("S\n");
                flag = 1;
            }
        }
        if(!flag) printf("N\n");
    }

    return 0;
}