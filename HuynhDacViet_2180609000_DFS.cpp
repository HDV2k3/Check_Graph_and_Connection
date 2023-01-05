#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct Graph
{
    int n;
    int a[MAX][MAX];
} DoThi;

int docFile(char test[100], DoThi &g)
{
    FILE *f;
    f = fopen(test, "rt");
    if (f == NULL)
    {
        printf("Khong mo duoc file");
        return 0;
    }
    fscanf(f, "%d", &g.n);
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

void printfMatrix(DoThi g)
{
    for (int i = 0; i < g.n; i++)
    {
        for (int j = 0; j < g.n; j++)
        {
            printf("%d ", g.a[i][j]);
        }
        printf("\n");
    }
}

int ChuaXet[MAX];
int LuuVet[MAX];

void DFS(int v, DoThi g)
{
    ChuaXet[v] = 1;
    
    for (int i = 0; i < g.n; i++)
    {
        if (g.a[v][i] != 0 && ChuaXet[i] == 0)
        {
            LuuVet[i] = v;
            DFS(i, g);
        }
    }
}

void duyetDFS(int dinhBatDau, int dinhKetThuc, DoThi g)
{
    int i;
    for ( i = 0; i < g.n; i++)
    {
        LuuVet[i] = -1;
        ChuaXet[i] = 0;
       
    }
    DFS(dinhBatDau, g);
    if (ChuaXet[dinhKetThuc] == 1)
    {
        printf("Duong di DFS tu dinh %d den dinh %d la:\n", dinhBatDau, dinhKetThuc);
         i = dinhKetThuc;
        printf("%d ",dinhKetThuc);
        while (i != dinhBatDau)
        {
            i = LuuVet[i];
            printf("%d ",i);
            
        }
    }
    else
    {
        printf("\nKhong Co Duong di!");
    }
}


int main()
{
    int dinhbatdau;
    int dinhketthuc;
    DoThi g;
    docFile("test.txt", g);
    printfMatrix(g);
    printf("Nhap dinh bat dau:",dinhbatdau);
    scanf("%d",&dinhbatdau);
    printf("Nhap dinh ket thuc:",dinhketthuc);
    scanf("%d",&dinhketthuc);
    duyetDFS(dinhbatdau,dinhketthuc,g);
    printf("\n");
    for(int i=0;i<g.n;i++)
    {
        
        printf("%d\t",LuuVet[i]);
    }
}