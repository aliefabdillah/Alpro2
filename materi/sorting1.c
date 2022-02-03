//MATERI SORTING
/*Jenis-jenis sorting
    - Penyisipan (insertion sort)
    -Seleksi (Selection sort)
    -Gelembung (Bubble sort)
    -urut cepat (quick sort)
*/

//Progam Penyisipan
#include <stdio.h>
#include <string.h>

/*
int main(){
    int tabInt[10] = {34, 67, 23, 28, 98, 15, 89, 67, 28, 18};
    int i;
    int data_sisip;
    int j;

    for (i = 1; i < 10; i++)
    {
        data_sisip = tabInt[i];
        j= i - 1;
        while((data_sisip < tabInt[j]) && (j >= 0)){
        //jika data array < dari data sisip maka data array di geser ke belakang
            tabInt[j+1] = tabInt[j];
            j = j - 1;
        }
        //menampatkan data sisip pada array
        tabInt[j+1] = data_sisip;
    }

    for ( i = 0; i < 10; i++)
    {
        printf("%d ", tabInt[i]);
    }
    return 0;
}
*/

//Latihan Penyisipan Dari besar ke kecil
/*
int main(){
    int tabInt[10] = {34, 67, 23, 28, 98, 15, 89, 67, 28, 18};
    int i;
    int data_sisip;
    int j;

    for ( i = 1; i < 10; i++)
    {
        data_sisip = tabInt[i];
        j = i - 1;
        while ((data_sisip > tabInt[j]) && (j >= 0))
        {
            tabInt[j+1] = tabInt[j];
            j = j - 1;
        }
        tabInt[j+1] = data_sisip;
    }

    for (i = 0; i < 10; i++)
    {
        printf("%d ", tabInt[i]);
    }
    
    return 0;        
}
*/

//latihan mengurutkan berdasar pembilang atau penyebut
/*
typedef struct 
{
    int pembilang;
    int penyebut;
}array;

array angka[4];

void sorting_lang(int i, int j, int sisip_lang, int sisip_but);
void sorting_but(int i, int j, int sisip_lang, int sisip_but);

int main(){
    int i, j, sisip_lang, sisip_but;
    printf("Masukan Pembilang dan Penyebut:\n");
    for (i = 0; i < 4; i++)
    {
        scanf("%d", &angka[i].pembilang);
        scanf("%d", &angka[i].penyebut);
    }
    
    sorting_lang(i, j, sisip_lang, sisip_but);
    sorting_but(i, j, sisip_lang, sisip_but);

    return 0;
}

void sorting_lang(int i, int j, int sisip_lang, int sisip_but){
    for (i = 1; i < 4; i++)
    {
        sisip_lang = angka[i].pembilang;
        sisip_but = angka[i].penyebut;
        j = i - 1;
        while ((sisip_lang < angka[j].pembilang) && (j >= 0))
        {
            angka[j+1].pembilang = angka[j].pembilang;
            angka[j+1].penyebut = angka[j].penyebut;
            j = j - 1;
        }
        angka[j+1].pembilang = sisip_lang;
        angka[j+1].penyebut = sisip_but;
    }
    
    printf("Hasil mengurutkan Pembilang:\n");
    for (i = 0; i < 4; i++)
    {
        printf(" %d %d ||", angka[i].pembilang, angka[i].penyebut);
    }
    printf("\n");
    
}

void sorting_but(int i, int j, int sisip_lang, int sisip_but){
    //int i, j, sisip_lang, sisip_but;
    for (i = 1; i < 4; i++)
    {
        sisip_lang = angka[i].pembilang;
        sisip_but = angka[i].penyebut;
        j = i - 1;
        while ((sisip_but < angka[j].penyebut) && (j >= 0))
        {
            angka[j+1].pembilang = angka[j].pembilang;
            angka[j+1].penyebut = angka[j].penyebut;
            j = j - 1;
        }
        angka[j+1].pembilang = sisip_lang;
        angka[j+1].penyebut = sisip_but;
    }
    
    printf("Hasil mengurutkan Penyebut:\n");
    for (i = 0; i < 4; i++)
    {
        printf(" %d %d ||", angka[i].pembilang, angka[i].penyebut);
    }
    printf("\n");
}
*/

//Contoh Progam SELECTION SORT
//mengurutkan angka dari kecil ke besar / besar ke ekcil
/*
int main(){
    int tab[10] = {34, 67, 23, 28, 98, 15, 89, 67, 28, 18};
    int i,j;
    int min;
    int temp;

    for (i = 0; i < 10; i++)
    {
        //inisialiasasi indeks elemen minimum
        min = i;
        
        //perulangan mencari nilai minimum sepanjang indek i+1 sampai jumlah elemen array
        for (j = (i+1); j < 10; j++)
        {   
            //dari besar ke kecil
            if (tab[min] < tab[j])
            {
                min = j;
            }
            //dari kecil ke besar
            if (tab[min] > tab[j])
            {
                min = j;
            }
        }
        //menukar posisi elemen
        temp = tab[i];
        tab[i] = tab[min];
        tab[min] = temp;
    }

    for (i = 0; i < 10; i++)
    {
        printf("%d ", tab[i]);
    }
    
    return 0;
}
*/

//mengurutkan pecahan atau pembilang
typedef struct 
{
    int pembilang;
    int penyebut;
}array;

array angka[4];

void sorting_lang(int i, int j, int sisip_lang, int sisip_but, int min);
//void sorting_but(int i, int j, int sisip_lang, int sisip_but, int min);

int main(){
    int i, j, sisip_lang, sisip_but, min;
    printf("Masukan Pembilang dan Penyebut:\n");
    for (i = 0; i < 4; i++)
    {
        scanf("%d", &angka[i].pembilang);
        scanf("%d", &angka[i].penyebut);
    }
    
    sorting_lang(i, j, sisip_lang, sisip_but, min);
    //sorting_but(i, j, sisip_lang, sisip_but, min);

    return 0;
}

void sorting_lang(int i, int j, int sisip_lang, int sisip_but, int min){
    for (i = 0; i < 4; i++)
    {
        min = i;
        for ( j = i+1; j < 4; j++)
        {
            if (angka[min].pembilang > angka[j].pembilang )
            {
                min = j;
            }
        }
        //menukar pembilang
            sisip_lang = angka[i].pembilang;
            angka[i].pembilang = angka[min].pembilang;
            angka[min].pembilang = sisip_lang; 
            
        //menukar penyebut
            sisip_but = angka[i].penyebut;
            angka[i].penyebut = angka[min].penyebut;
            angka[min].penyebut = sisip_but;
    }

    printf("\nHasil Penyusunan Pembilang:\n");
    for ( i = 0; i < 4 ; i++)
    {
        printf(" %d %d ||", angka[i].pembilang, angka[i].penyebut);
    }
    
    
}
