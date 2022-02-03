//Materi Searching
/* 
    - Mencari Berdasarkan Sesuatu Pada 
    kumpulan data

    -Macam Macam Searching atau Pencarian
        - Pencarian Beruntun (sequential Search)
        - Pencarian Biner (Binary Search) 
*/

/* 
    Pencarian Beruntun
        -Pencarian dilakukan dengan memeriksa semua data yang ada
        sampai ditemukan data yang dicari
        - Selalu Menemukan yang dicari
        - tidak ada syarat awal dan bisa untuk semua kasus
        - kurang efisien
 */

#include <stdio.h>
#include <string.h>
//Contoh Progam Pencarian Beruntun

/* typedef struct{
    char nim[50];
    char nama[50];
    float nilai;
}nilai_matkul;

nilai_matkul tabel[5];

void isi( int i, char nim[], char nama[], float nilai){
    strcpy(tabel[i].nim, nim);
    strcpy(tabel[i].nama, nama);
    tabel[i].nilai = nilai;
}

int main(){
    char nim_cari[50];
    int ketemu;
    int i;
    int indeks;

    isi(0, "13507701", "Nana", 64.75);
    isi(1, "13507702", "Rudi", 75.11);
    isi(2, "13507703", "Dea", 84.63);
    isi(3, "13507704", "Ilham", 77.07);
    isi(4, "13507705", "Tiara", 66.70);

    strcpy(nim_cari, "13507703");
    ketemu = 0;
    i = 0;
    while ((i < 5) && (ketemu == 0))
    {
        if (strcmp(tabel[i].nim, nim_cari) == 0)
        {
            ketemu = 1;
            indeks = i;
        }
        else
        {
            i++;
        }
    }
    
    if (ketemu == 1)
    {
        printf("Nim : %s\n", tabel[indeks].nim);
        printf("Nama : %s\n", tabel[indeks].nama);
        printf("Nilai : %0.2f\n", tabel[indeks].nilai);
    }
    else
    {
        printf("Data Tidak Ditemukan\n");
    }
    
    return 0;
    
} */

//latihan Pencarian Beruntun
/* void isi( int i, char nim[][50], char nama[][50], float nilai[], int panjang){
    for ( i = 0; i < panjang; i++)
    {
        scanf("%s", nim[i]);
        scanf("%s", nama[i]);
        scanf("%f", &nilai[i]);
    }
}

void search(char nama[][50], int panjang){
    int ketemu;
    int i;
    int j;

    ketemu = 0;
    for ( i = 0; i < panjang; i++)
    {
        for ( j = 0; j < 1; j++)
        {
            if (nama[i][j] == 'A');
            {
                ketemu++;
            }
        } 
    }
    
    if (ketemu > 1)
    {
        printf("Lebih dari/sama dengan 2\n");
    }
    else
    {
        printf("Kurang dari 2\n");
    }
}

int main(){
    int panjang;
    scanf("%d", &panjang);

    char nim[panjang][50];
    char nama[panjang][50];
    float nilai[panjang];

    isi(0, nim, nama, nilai, panjang);

    search(nama, panjang);
    return 0;
    
} */

/* 
    -Pencarian Biner
    Syarat Pencarian biner:
        -Data harus di urut terlebih dahulu
        -tidak untuk semua kasus
        -lebih efisien
 */

//contoh progam binary search
/* int array[10] = {15, 18, 23, 28, 28, 34, 67, 67, 89, 98};

int main(){
    int i, j, k;
    int bil_cari; 
    int ketemu;

    i = 0;
    j = 9;
    k = 0;
    bil_cari = 100;

    while ((ketemu == 0) && (i<=j))
    {
        k = (int)(i+j)/2;
        if (array[k] == bil_cari)
        {
            ketemu = 1;
        }
        else
        {
            if (array[k] > bil_cari)
            {
                j = k - 1;
            }
            else
            {
                i = k + 1;
            }
        }
    }

    if (ketemu == 1)
    {
        printf("nilai ada pada data\n");
    }
    else
    {
        printf("error 404 // not found :)\n");
    }
    
    return 0;
} */

//latihan binary search array urut turun
/* 
void sorting(int panjang, int arr[]){
    int i, j;
    int temp;

    for (i = 1; i < panjang; i++)
    {
        temp = arr[i];
        j = i - 1;
        while ((temp > arr[j]) && (j >= 0))
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }

}

void search(int panjang, int arr[], int bil_cari){
    int i,j,k;
    int ketemu;

    i=0;
    j=panjang-1;
    k = 0;
    ketemu = 0;

    while ((ketemu == 0) && (i<=j))
    {
        k = (int)(i+j)/2;
        if (arr[k] == bil_cari)
        {
            ketemu = 1;
        }
        else
        {
            if (arr[k] > bil_cari)
            {
                i = k + 1;
            }
            else
            {
                j = k - 1;
            }
        }
    }

    if (ketemu == 1)
    {   
        for ( i = 0; i < panjang; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\nangka ada pada data\n");
    }
    else
    {
        for ( i = 0; i < panjang; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\nga ada bro sorry :v\n");
    }
    
}

int cek_urut(int panjang, int arr[], int bil_cari){
    int i;
    int cek;

    i = 0;
    cek = 0;
    while ((i<panjang) && (cek == 0))
    {
        if (arr[i] < arr[i+1])
        {
            cek = 1;
        }
        i++;
    }

    return cek;
}

int main(){
    int i;
    int panjang;
    int tanda;
    scanf("%d", &panjang);

    int arr[panjang];
    for (i = 0; i < panjang; i++)
    {
        scanf("%d", &arr[i]);
    }

    int bil_cari;
    printf("angka yang ingin dicari :");
    scanf("%d", &bil_cari);
    
    tanda = cek_urut(panjang, arr, bil_cari);
    if (tanda == 1)
    {
        sorting(panjang, arr);
        search(panjang, arr, bil_cari);
    }
    else
    {
        search(panjang, arr, bil_cari);
    }
    
    return 0;
}
 */

