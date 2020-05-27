#include <stdio.h>
#include <math.h>

int main()
{
    int v[11];
    for(int i = 0; i <11; i++)
    {
        scanf("%d",&v[i]);
    }
    for(int i = 10; i >=0; i--)
    {
        float f,a,b;
        a = sqrt(abs(v[i]));
        b = v[i]*v[i]*v[i]*5;
        f = a+b;

        if(f < 400)
        {
            printf("f(%d) = %.2f\n",v[i],f);
        }
        else
        {
            printf("f(%d) = MAGNA NIMIS!\n",v[i]);
        }
    }
    return 0;
}

/*per nextum in unam tum XI conscribementis fac sic
    vestibulo perlegementum da varo.
    morde varo.
    seqis cumula varum.
cis

per nextum in unam tum XI conscribementis fac sic
    seqis decumulamenta da varo.
    varum privamentum fodementum da aresulto.
    varum tum III elevamentum tum V multiplicamentum da bresulto.
    aresultum tum bresultum addementum da resulto.

    si CD tum resultum non praestantiam fac sic
        dictum sic f(%d) = %.2f cis tum varum tum resultum egresso describe.
        novumversum egresso scribe.
    cis
    si CD tum resultum praestantiam fac sic
        dictum sic f(%d) = MAGNA NIMIS! cis tum varum egresso describe.
        novumversum egresso scribe.        
    cis
cis*/