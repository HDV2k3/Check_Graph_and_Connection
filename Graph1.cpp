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

void PrintMatrix(DoThi g)
{
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
    printf("\nSo dinh cua do thi la: %d", g.n);
    printf("\nMa tran do thi:\n");
    PrintMatrix(g);

    if (check_Hop_Le(g) == 0)
        printf("\nDo thi khong hop le");
    else
        printf("\nDo thi hop le");

    if (check_Vo_Huong(g) == 0)
        printf("\nDo thi vo huong");
    else
        printf("\nDo thi co huong");

    return 0;
}
 

 //xét liên thông

 
// #include <stdio.h>
// #define MAX 100

// typedef struct Graph
// {
//     int n;
//     int a[MAX][MAX];
// } DoThi;

// int docFile(char test[100], DoThi &g)
// {
//     FILE *f;
//     f = fopen(test, "rt");
//     if (f == NULL)
//     {
//         printf("Khong mo duoc file");
//         return 0;
//     }
//     fscanf(f, "%d", &g.n);
//     for (int i = 0; i < g.n; i++)
//     {
//         for (int j = 0; j < g.n; j++)
//         {
//             fscanf(f, "%d", &g.a[i][j]);
//         }
//     }
//     fclose(f);
//     return 1;
// }

// void printfMatrix(DoThi g)
// {
//     for (int i = 0; i < g.n; i++)
//     {
//         for (int j = 0; j < g.n; j++)
//         {
//             printf("%d ", g.a[i][j]);
//         }
//         printf("\n");
//     }
// }

// void CacDinhLienThong(DoThi g, int nhan[MAX], int i)
// {
//     for (int j = 0; j < g.n; j++)
//     {
//         if (g.a[i][j] != 0 && nhan[j] != nhan[i])
//         {
//             nhan[j] = nhan[i];
//             CacDinhLienThong(g, nhan, j);
//         }   
//     }
// }

// void XetLienThong(DoThi g)
// {

//     int Nhan[MAX];
//     int i;
//     for (i = 0; i < g.n; i++)
//         Nhan[i] = 0;
//     int SoThanhPhanLT = 0;
//     for (i = 0; i < g.n; i++)
//     {
//         if (Nhan[i] == 0)
//         {
//             SoThanhPhanLT++;
//             Nhan[i] = SoThanhPhanLT;
//         }
//         if (Nhan[i] != 0)
//             CacDinhLienThong(g, Nhan, i);
//     }
//     printf("So thanh phan lien thong la %d\n", SoThanhPhanLT);
//     for (i = 1; i <= SoThanhPhanLT; i++)
//     {
//         printf("Thanh phan lien thong thu %d gom cac dinh: ", i);
//         for (int j = 0; j < g.n; j++)
//         {
//             if (Nhan[j] == i)
//                 printf(" %d ", j );
//         }
//         printf("\n");
//     }
// }

// int main()
// {
//     DoThi g;
//     docFile("test.txt", g);
//     printfMatrix(g);
//     printf("\n");
//     XetLienThong(g);
//     return 0;
// }

