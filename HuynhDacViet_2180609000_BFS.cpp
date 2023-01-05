#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct Graph
{
    int n;
    int a[MAX][MAX];
} DoThi;

int LuuVet[MAX];
int ChuaXet[MAX];
struct Queue
{
    int size;
    /* data */ int arr[MAX];
                
};

void CreateQueue(Queue &Q)
{
    Q.size=0;
}

int PushInVal(Queue &Q,int value)
{
    if(Q.size+1>=100)
    {
        return 0;
    }
    else
    {
        Q.arr[Q.size]=value;
        Q.size++;
        return 1;
    }
}
int PushOutVal(Queue &Q,int &value)
{
    if(Q.size<=0)
    {
        return 0;
    }
    else
    {
        value =Q.arr[0];
        for(int i=0;i<Q.size;i++)
        {
            Q.arr[i]=Q.arr[i+1];
        }
        Q.size--;
        return 1;
    }
}
int IsEmpty(Queue Q)
{
    if(Q.size<=0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int docFile(char test1[100], DoThi &g)
{
    FILE *f;
    f = fopen(test1, "rt");
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



void BFS(int v ,DoThi g)
{
    Queue Q;
    CreateQueue(Q);
    PushInVal(Q,v);
    while (/* condition */!IsEmpty(Q))
    {
        /* code */PushOutVal(Q,v);
        ChuaXet[v]=1;
        for(int j=0;j<g.n;j++)
        {
            if(g.a[v][j]!=0 && ChuaXet[j]==0)
            {
                PushInVal(Q,j);
                    if(LuuVet[j]==-1)
                    {
                        LuuVet[j]=v;
                    }
            }
        }
    }
    
}

void duyetBFS(int dinhBatDau, int dinhKetThuc, DoThi g)
{
    int i;
    for ( i = 0; i < g.n; i++)
    {
        LuuVet[i] = -1;
        ChuaXet[i] = 0;
       
    }
    BFS(dinhBatDau, g);
    if (ChuaXet[dinhKetThuc] == 1)
    {
        printf("Duong di BFS tu dinh %d den dinh %d la: \n", dinhBatDau, dinhKetThuc);
         i = dinhKetThuc;
        printf("%d", dinhKetThuc);
        while (i != dinhBatDau)
        {
            i = LuuVet[i];
            printf("%4d ", i);
            
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
    docFile("test1.txt", g);
    printfMatrix(g);
    printf("Nhap dinh bat dau:",dinhbatdau);
    scanf("%d",&dinhbatdau);
    printf("Nhap dinh ket thuc:",dinhketthuc);
    scanf("%d",&dinhketthuc);
    duyetBFS(dinhbatdau,dinhketthuc,g);
    printf("\n");
    for(int i=0;i<g.n;i++)
    {
        printf("%d\t",LuuVet[i]);
    }
}