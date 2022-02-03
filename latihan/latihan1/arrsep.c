#include <stdio.h>

int main(){
    //deklarasi variabel
    int i,j;
    int n,m;
    
    //input panjang array, deklarasi array1 dan mengiis array1
    scanf("%d", &n);
    int arr1[n];
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr1[i]);
    }

    //input panjang array2, deklarasi array2, dan mengisi array2
    scanf("%d", &m);
    int arr2[m];
    for (j = 0; j < m; j++)
    {
        scanf("%d", &arr2[j]);
    }

    //pertambahan separuh
    int tambah1 = 0;
    for (i = 0; i < n/2; i++)
    {
        tambah1 = tambah1 + arr1[i];
    }

    int tambah2 = 0;
    for (i = m/2; i < m; i++)
    {
        tambah2 = tambah2 + arr2[i];
    }


    //syarat ouput
    if (tambah1 == tambah2)
    {
        printf("valid\n");
    }
    else
    {
        printf("tidak valid\n");
    }
    
    return 0;
}