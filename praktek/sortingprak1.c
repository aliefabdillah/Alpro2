// Materi Sorting 1
/* insertion sort
    mengambil sebuah data sisip pada data yang diurutkan
    dan menggeser data yang lebih besar dari data sisip agar ditempatkan
    di data yang benar
*/

/* selection sort
    mencari nilai terkecil terlebih atau terbesar dahulu bergantung pada pengurutan
    menaik atau menurun yang kemudian ditempatkan pada tempat paling depan, kemudian mencari
    nilai terkecil atau terbesar ke dua sepanjang jumlah elemen array dikurangi 1, setelah ketemu 
    elemen kedua ditukar dengan nilai minimum
*/

//contoh progam insertion sort

#include <stdio.h>
#include <string.h>

/*
void printArr(int n, int arr[]){
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

}

int main(){
    int i,j, key;
    int arr[6] = {8, 5, 7, 1, 9, 3};

    for ( i = 1; i < 6; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && key < arr[j])
        {
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = key;
    }

    printf(6, arr);
    return 0;
}
*/

//contoh progam selection sort
/*
void printArr(int n, int arr[]){
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

}

int main(){
    int i,j, temp, min;
    int arr[6] = {8, 5, 7, 1, 9, 3};

    for ( i = 0; i < (6-1); i++)
    {
        min = i;
        j = i - 1;

        for (j = i+1; j < 6; j++)
        {
            if (arr[min] > arr[j])
            {
                min = j;
            }
        }
        
        temp = arr[i];
        arr[i] = arr[min];
        arr[min]= temp;
    }

    printf(6, arr);
    return 0;
}
*/

//latihan 
void sorting_nilai(int n, int sisip_nilai, char sisip_nama[], char nama[][50], int nilai[]);
void sorting_nama(int n, int sisip_nilai, char sisip_nama[], char nama[][50], int nilai[]);

int main(){
    int i,j,n;
    int sisip_nilai; 
    char sisip_nama[50];

    scanf("%d", &n);
    char nama[n][50];
    int nilai[n];

    for (i = 0; i < n; i++)
    {
        scanf("%s", &nama[i]);
        scanf("%d", &nilai[i]);
    }

    char pilihan;
    scanf(" %c", &pilihan);

    if (pilihan == 'A')
    {
        sorting_nama(n, sisip_nilai, sisip_nama, nama, nilai);
    }
    if (pilihan == 'B')
    {
        sorting_nilai(n, sisip_nilai, sisip_nama, nama, nilai);
    }

    return 0;
}

void sorting_nilai(int n, int sisip_nilai, char sisip_nama[], char nama[][50], int nilai[]){
    int i,j;
    int min_nilai;
    for (i = 0; i < n; i++)
    {
        min_nilai = i;
        for ( j = i+1; j < n; j++)
        {
            if (nilai[min_nilai] < nilai[j])
            {
                min_nilai = j;
            }
        }
        //tukar nilai
        sisip_nilai = nilai[i];
        nilai[i] = nilai[min_nilai];
        nilai[min_nilai] = sisip_nilai;

        //tukar nama
        strcpy(sisip_nama, nama[i]);
        strcpy(nama[i], nama[min_nilai]);
        strcpy(nama[min_nilai], sisip_nama);
    }
    
    for (i = 0; i < n; i++)
    {
        printf("%s %d\n", nama[i], nilai[i]);
    }

}

void sorting_nama(int n, int sisip_nilai, char sisip_nama[], char nama[][50], int nilai[]){
    int i,j, k;
    int min_nama;
    for ( i = 1; i < n; i++)
    {
        strcpy(sisip_nama, nama[i]);
        sisip_nilai = nilai[i];
        j = i - 1;
        while ((j >= 0) && (strcmp(sisip_nama, nama[j]) < 0)) //bisa  < 0 atau == -1 (artinya ascending atau naik), kalo desecndi atau turun == 1 / > 0
        {
            strcpy(nama[j+1], nama[j]);
            nilai[j+1] = nilai[j];
            j--;   
        }
        strcpy(nama[j+1], sisip_nama);
        nilai[j+1] = sisip_nilai;
    }

    for (i = 0; i < n; i++)
    {
        printf("%s %d\n", nama[i], nilai[i]);
    }
    
}
