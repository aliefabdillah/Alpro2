// Materi Sorting 2
/*
    BUBBLE SORT
    Bubble Sort adalah algoritma pengurutan dengan cara
    mengecek dua data yang bersebelahan.
*/

/*
    QUICK SORT
    Merupakan algoritma sorting yang bekerja dengan cara 
    memisahkan data menjadi sub-bagian dan memiliki patokan/pivot
    ada beberapa varian quick sort : pivot pinggir, pivot tengah.
*/

#include <stdio.h>
#include <string.h>
//contoh progam bubble sort
/*
void bubbleSort(int data[], int n){
    int i, temp, swap;

    do
    {
        swap = 0;
        for (i = 0; i < n-1; i++)
        {
            if (data[i] > data[i+1])
            {
                temp = data[i];
                data[i] = data[i+1];
                data[i+1] = temp;
                //tanda ada data yang ditukar
                swap = 1;
            }
        }
        
    } while (swap == 1);
    
}

void print(int data[], int n){
    int i;
    for ( i = 0; i < n; i++)
    {
        if (i != n-1)
        {
            printf("%d ", data[i]);
        }
        else
        {
            printf("%d\n", data[i]);
        }
    }
}

int main(){
    int data[] = {64, 34, 25, 12, 22, 90, 11};
    int n = 7;

    //print data awal
    print(data, n);
    //panggil prosedur bubblesort
    bubbleSort(data, n);
    //print data akhir (setelah sorting)
    print(data, n);

    return 0;
}
*/

//contoh progam quicksort
/*
    ada 2 jenis quicksort : pivot tengah dan pinggir
*/

//contoh progam pivot tengah
/*
void pivot_tengah(int data[], int kiri, int kanan){
    int i,j,temp;
    i = kiri;
    j = kanan;
    int pivot = data[(kanan+kiri)/2];

    do
    {
        while ((data[i] < pivot) && (i <= j))
        {
            i++;
        }
        while ((data[j] > pivot) && (i <= j))
        {
            j--;
        }

        if (i<j)
        {
            temp = data[i];
            data[i] = data[j];
            data[j] = temp;

            i++;
            j--;
        }
    } while (i<j);
    
    if ((kiri < j) && (j < kanan))
    {
        pivot_tengah(data, kiri, j);
    }
    if ((i < kanan) && (i > kiri))
    {
        pivot_tengah(data, i, kanan);
    }
}

void print(int data[], int n){
    int i;
    for ( i = 0; i < n; i++)
    {
        if (i != n-1)
        {
            printf("%d ", data[i]);
        }
        else
        {
            printf("%d\n", data[i]);
        }
    }
}

int main(){
    int data[9] = {64, 34, 25, 12, 22, 90, 11, 78, 41};
    int n = 9;

    //print data awal
    print(data, n);
    //panggil prosedur bubblesort
    pivot_tengah(data, 0, n-1);
    //print data akhir (setelah sorting)
    print(data, n);

    return 0;
}
*/

//contoh pivot pinggir
/*
void pivot_pinggir(int data[], int kiri, int kanan){
    int i,j,temp;
    i = kiri;
    j = kanan;

    do
    {
        while ((data[i] < data[kanan]) && (i <= j))
        {
            i++;
        }
        while ((data[j] > data[kiri]) && (i <= j))
        {
            j--;
        }

        if (i<j)
        {
            temp = data[i];
            data[i] = data[j];
            data[j] = temp;

            i++;
            j--;
        }
    } while (i<j);
    
    if ((kiri < j) && (j < kanan))
    {
        pivot_pinggir(data, kiri, j);
    }
    if ((i < kanan) && (i > kiri))
    {
        pivot_pinggir(data, i, kanan);
    }
}

void print(int data[], int n){
    int i;
    for ( i = 0; i < n; i++)
    {
        if (i != n-1)
        {
            printf("%d ", data[i]);
        }
        else
        {
            printf("%d\n", data[i]);
        }
    }
}

int main(){
    int data[9] = {64, 34, 25, 12, 22, 90, 11, 78, 41};
    int n = 9;

    //print data awal
    print(data, n);
    //panggil prosedur bubblesort
    pivot_pinggir(data, 0, n-1);
    //print data akhir (setelah sorting)
    print(data, n);

    return 0;
}
*/

//latihan
void bubble_sort(int no_duduk[], char nama[][50], char tipe[][50], int n){
    int i, tanda;
    int temp_duduk;
    char temp_nama[50], temp_tipe[50];

    do
    {
        tanda = 0;

        for (i = 0; i < n-1; i++)
        {
            if (no_duduk[i] > no_duduk[i+1])
            {
                //tukar no duduk
                temp_duduk = no_duduk[i];
                no_duduk[i] = no_duduk[i+1];
                no_duduk[i+1] = temp_duduk;

                //tukar nama
                strcpy(temp_nama, nama[i]);
                strcpy(nama[i], nama[i+1]);
                strcpy(nama[i+1], temp_nama);

                //tukar tipe
                strcpy(temp_tipe, tipe[i]);
                strcpy(tipe[i], tipe[i+1]);
                strcpy(tipe[i+1], temp_tipe);

                tanda = 1;
            }
            
        }
        
    } while (tanda == 1);
    
}

void quick_sort(int no_duduk[], char nama[][50], char tipe[][50], int kiri, int kanan){
    int i, j;
    int temp2_duduk;
    char temp2_nama[50], temp2_tipe[50];
    i = kiri, j = kanan;
    int pivot = no_duduk[(kanan+kiri)/2];

    do
    {
        while ((no_duduk[i] < pivot) && (i <= j))
        {
            i = i + 1;
        }
        while ((no_duduk[j] > pivot) && (i <= j))
        {
            j = j - 1;
        }
        
        if (i<j)
        {
            //tukar no duduk
            temp2_duduk = no_duduk[i];
            no_duduk[i] = no_duduk[j];
            no_duduk[j] = temp2_duduk;

            //tukar nama
            strcpy(temp2_nama, nama[i]);
            strcpy(nama[i], nama[j]);
            strcpy(nama[j], temp2_nama);

            //tukar tipe
            strcpy(temp2_tipe, tipe[i]);
            strcpy(tipe[i], tipe[j]);
            strcpy(tipe[j], temp2_tipe);

            i = i + 1;
            j = j - 1;
        }
        
    } while (i<j);

    if ((kiri < j) && (j < kanan))
    {
        quick_sort(no_duduk, nama, tipe, kiri, j);
    }
    if ((i < kanan) && (i > kiri))
    {
        quick_sort(no_duduk, nama, tipe, i, kanan);
    }
}

void print_akhir(int no_duduk[], char nama[][50], char tipe[][50], int n){
    int i;

    for (i = 0; i < n; i++)
    {
        printf("\n");
        printf("No Tempat Duduk : %d\n", no_duduk[i]);
        printf("Nama : %s\n", nama[i]);
        printf("Tipe : %s\n", tipe[i]);
    }
}

int main(){
    int i;

    char sorting;
    scanf(" %c", &sorting);
    int n;
    scanf("%d", &n);

    int no_duduk[n];
    char nama[n][50];
    char tipe[n][50];

    for (i = 0; i < n; i++)
    {
        scanf("%d", &no_duduk[i]);
        scanf("%s", nama[i]);
        scanf("%s", tipe[i]);
    }

    if (sorting == 'Q')
    {
        quick_sort(no_duduk, nama, tipe, 0, n-1);
    }
    if (sorting == 'B')
    {
        bubble_sort(no_duduk, nama, tipe, n);
    }

    print_akhir(no_duduk, nama, tipe, n);

    return 0;
}

/*

Q
6
15 Zulkifli Velvet
13 Mamang Reguler
17 Bambang Reguler
10 A VIP
11 B VIP
1 C Ekonomi

Q
6
2 iii lll
5 uuu zzz
8 ooo rrr
1 eee mmm
5 aaa ppp
4 xxx xxx

*/