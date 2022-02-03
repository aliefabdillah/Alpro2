//Praktikum Searching
/*
    -Sequential Search
    adalah pencarian yang dilakukan dengan mengecek semua data yang
    ada hingga menemukan data yang dicari
    -Kelbihan : data yang dicari selalu ditemukan
    -kekurangan : tidak efisien jika data sangat banyak karena harus mengecek data satu/satu

 */

//contoh progam seqeuntial search
#include <stdio.h>
#include <string.h>
/* 
void seq(int arr[], int n, int cari){
    int i, found;
    found = 0;
    i = 0;

    while ((i<n) && (found == 0))
    {
        if (arr[i] == cari)
        {
            found = 1;
        }
        else
        {
            i++;
        }
    }

    if (found == 1)
    {
        printf("Angka %d ditemukan\n", cari);
    }
    else
    {
        printf("Angka %d tidak ditemukan\n", cari);
    }
}

int main(){
    int n, cari;
    printf("Masukan jumlah data : ");
    scanf("%d", &n);
    int arr[n];

    int i;
    printf("Masukan Data : \n");
    for ( i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Masukan data yang ingin di cari : ");
    scanf("%d", &cari);

    seq(arr, n, cari);

    return 0;   
} 
*/

/* 
    Binary Search 
        adalah pencarian yang dilakukan pada data yang terurut dengan
        membagai sub data menjadi 2 bagian. kelebihannya adalah lebih efisian dari sequential
        kekurangan tidak semua kasus bisa diselesasikan dengan binary search
 */

//contoh progam binary search
/* 
int arr[10] = {12, 13, 25, 34, 45, 54, 55, 61, 79, 83};

int bin(int cari){
    int i,n,k;
    int found = 0;
    i = 0;
    n = 9;

    while ((i<=n) && (found == 0))
    {
        k = (int)(i+n)/2;
        if (arr[k] == cari)
        {
            found = 1;
        }
        else
        {
            if (arr[k] > cari)
            {
                n = k - 1;
            }
            else
            {
                i = k + 1;
            }
        }
    }
            
    return found;
    
}

int main(){
    int cari;
    scanf("%d", &cari);

    if (bin(cari) == 1)
    {
        printf("Data ditemukan\n");
    }
    else
    {
        printf("Data tidak ditemukan\n");
    }
}
 */

//latihan
/* 
void seq(int arr[], int n, int cari){
    int i, found, index;
    index = -1;
    i = 0;

    while ((i<n) && (index == -1))
    {
            if (arr[i] == cari)
            {
                index = i;
            }
            else
            {
                i++;
            }
    }

    if (index != 1)
    {
        printf("%d\n", index);
    }
    else
    {
        printf("angka tidak ada pada data\n");
    }
}

int main(){
    int n, cari;
    scanf("%d", &n);
    int arr[n];

    int i;
    for ( i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &cari);

    seq(arr, n, cari);

    return 0;   
} 
 */

//latihan 2
void seq(int arr[], int n){
    int i;
    
    i = 0;
    int max = 0;
    int max2 = 0;

    while (i<n)
    {
        if(arr[i] > max){
            max2 = max;
            max = arr[i];
        }
        i++;
        
    }
        printf("data terbesar ke dua : %d\n", max2);
}

int main(){
    int n, cari;
    scanf("%d", &n);
    int arr[n];

    int i;
    for ( i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    seq(arr, n);

    return 0;   
} 