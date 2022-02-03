#include <stdio.h>
#include <string.h>

void sorting(int n, char arr1[][50], int m, char arr2[][50], int o, char arr3[][50]){
    int i, j;
    char sisip[50];

    //sorting arr1
    for ( i = 0; i < n; i++)
    {
        strcpy(sisip, arr1[i]);
        j = i - 1;
        while ((j >= 0) && (strcmp(sisip, arr1[j]) > 0))
        {
            strcpy(arr1[j+1], arr1[j]);
            j--;
        }
        strcpy(arr1[j+1], sisip);
    }

    //sorting arr2
    for ( i = 0; i < m; i++)
    {
        strcpy(sisip, arr2[i]);
        j = i - 1;
        while ((j >= 0) && (strcmp(sisip, arr2[j]) > 0))
        {
            strcpy(arr2[j+1], arr2[j]);
            j--;
        }
        strcpy(arr2[j+1], sisip);
    }

    //sorting arr3
    for ( i = 0; i < o; i++)
    {
        strcpy(sisip, arr3[i]);
        j = i - 1;
        while ((j >= 0) && (strcmp(sisip, arr3[j]) > 0))
        {
            strcpy(arr3[j+1], arr3[j]);
            j--;
        }
        strcpy(arr3[j+1], sisip);
    }

    
}

void urut_desc(int n, char arr1[][50], int m, char arr2[][50], char temp[][50]){
    int i = 0,j = 0,k = 0,l = 0;

    while ((i < n) && (j < m))
    {
        if (strcmp(arr1[i], arr2[j]) > 0)
        {
            strcpy(temp[k], arr1[i]);
            i++;
            k++;
        }
        else if (strcmp(arr2[j], arr1[i]) > 0)
        {
            strcpy(temp[k], arr2[j]);
            j++;
            k++;
        }
        else
        {
            strcpy(temp[k], arr1[i]);
            i++;
            k++;

            strcpy(temp[k], arr2[j]);
            j++;
            k++;
        }
    }

    if (i < n)
    {
        for ( l = i; l < n; l++)
        {
            strcpy(temp[k], arr1[l]);
            k++;
        }
    }

    if (j < m)
    {
        for ( l = j; l < m; l++)
        {
            strcpy(temp[k], arr2[l]);
            k++;
        }
    }
}

void cetak(int n, int m, int o, char hasil[][50]){
    int i;

    printf("\n");
    for ( i = 0; i < n+m+o; i++)
    {
        printf("%s\n", hasil[i]);
    }
}

int main(){
    int i;

    int n;
    scanf("%d", &n);
    char arr1[n][50];
    for ( i = 0; i < n; i++)
    {
        scanf("%s", &arr1[i]);
    }

    int m;
    scanf("%d", &m);
    char arr2[m][50];
    for ( i = 0; i < m; i++)
    {
        scanf("%s", &arr2[i]);
    }

    int o;
    scanf("%d", &o);
    char arr3[o][50];
    for ( i = 0; i < o; i++)
    {
        scanf("%s", &arr3[i]);
    }
    
    char temp[n+m][50];         //gabungan arra1 dan 2
    char hasil[n+m+o][50];      //gabungan temp dengan array 3

    sorting(n, arr1, m, arr2, o, arr3);
    urut_desc(n, arr1, m, arr2, temp);
    urut_desc(n+m, temp, o, arr3, hasil);
    cetak(n, m, o, hasil);

    return 0;
}