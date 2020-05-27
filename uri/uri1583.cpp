#include <stdio.h>
#include <string.h>

struct Cont 
{
    int i,j;
};
char matriz[64][64];
int visi[64][64];
Cont contaminacao[1123456];

int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int m, n, tam;


void floodfill(int a, int b)
{
    if(visi[a][b]) return;
    int ia,ib;
    
	visi[a][b] = 1;
	matriz[a][b] = 'T';
 
	for(int i = 0; i < 4; i++)
	{
		ia = a + dir[i][0]; 
        ib = b + dir[i][1];
		if((ia >= 0 && ia < n) && (ib >= 0 && ib < m))
			if(matriz[ia][ib] == 'T' || matriz[ia][ib] == 'A')
				floodfill(ia, ib);
	}
}

int main()
{
    while((scanf("%d %d",&n,&m)) &&  (n || m))
    {   
        getchar();
        memset(visi, 0, sizeof (visi));
        tam = 0;
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {    
                scanf("%c",&matriz[i][j]);
                if(matriz[i][j] == 'T')
                {
                    contaminacao[tam].i = i;
                    contaminacao[tam].j = j;
                    tam++;
                }
            }
            getchar();
        }

        for(int i = 0; i < tam; i++)
        {
            floodfill(contaminacao[i].i,contaminacao[i].j);
        }

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {    
                printf("%c", matriz[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}