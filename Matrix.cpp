#include"stdio.h"
#define MAX 100
#include"stdlib.h"

typedef struct Graph
{
    int n;
    int a[MAX][MAX];
}DoThi;


int DocFile(char test[100],DoThi &g)
{
    FILE *f;

    f=fopen(test,"rt");
     if (f == NULL)
    {
        printf("Khong mo duoc file");
        return 0;
    }
    fscanf(f,"%d", &g.n);
    for (int i = 0; i < g.n; i++)
    {
        for (int j = 0; j < g.n; j++)
        {
            fscanf(f, "%d", &g.a[i][j]);
        }
    }
    fclose(f);
    return 1;
}

void PrintMatrix(DoThi g)
{
	  printf("\nSo dinh cua do thi la: %d", g.n);
    printf("\nMa tran do thi:\n");
    for(int i=0;i<g.n;i++)
    {
        for(int j=0;j<g.n;j++)
        {
            printf("%4d\t",g.a[i][j]);
        }
        printf("\n");
    }
}

int check_Hop_Le(DoThi g)
{
    for(int i=0;i<g.n;i++)
    {
        if(g.a[i][i] != 0)
        {
            return 0;
        }
    }
    return 1;
}

int check_Vo_Huong(DoThi g)
{
    for(int i=0;i<g.n;i++)
    {
        for(int j=0;j<g.n;j++)
        {
            if(g.a[i][j] != g.a[j][i])
            return 0;
        }
    }
    return 1;
}

int main()
{
    DoThi g;
    DocFile("test.txt",g);
    PrintMatrix(g);
    if (check_Hop_Le(g)== 0 )
        printf("\nDo thi khong hop le");
    else
        printf("\nDo thi hop le");

    if (check_Vo_Huong(g) == 0 )
        printf("\nDo thi vo huong");
    else
        printf("\nDo thi co huong");

    return 0;
}



