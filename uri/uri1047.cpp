#include <bits/stdc++.h>

int main()
{
    int hi,mini,hf, minf;
    scanf("%d %d %d %d",&hi,&mini,&hf,&minf);
    hi = hi*60 + mini; hf = hf*60 + minf;
    int ans;
    if(hi > hf)
    {
        ans = 24*60 - hi + hf;
        printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", ans/60, ans%60);
    }
    else if(hi < hf)
    {
        ans = hf - hi;
        printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", ans/60, ans%60);
    }
    else
        printf("O JOGO DUROU 24 HORA(S) E 0 MINUTO(S)\n");
    return 0;
}