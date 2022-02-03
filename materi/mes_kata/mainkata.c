#include <stdio.h>
#include "headkata.h"

//menampilkan isi pita per kata
/* 
int main(){
    char kalimat[300];
    printf("masukan kalimat: \n");
    scanf("%299[^\n]s", &kalimat);

    start_kata(kalimat);
    printf("%s\n", get_kata());

    while (eop_kata(kalimat) == 0)
    {
        inc_kata(kalimat);
        printf("%s\n", get_kata());
    }
    
    return 0;
} */

//menghitung banyak kata dalam kalimat/pita
/* int main(){
    char kalimat[300];
    int jumlah_kata = 0;
    printf("masukan kalimat: \n");
    scanf("%299[^\n]s", &kalimat);

    start_kata(kalimat);
    while (eop_kata(kalimat) == 0)
    {
        jumlah_kata++;
        inc_kata(kalimat);
    }

    if (get_panjang_kata() > 0)
    {
        jumlah_kata++;
    }
    
    printf("%d\n", jumlah_kata);
    return 0;
    
} */

//menghitung banyak kata yang minimal mengandung 3 huruf vokal
 /* int main(){
    char kalimat[300];
    int jumlah_vokal = 0;
    int jumlah_kata = 0;
    printf("masukan kalimat: \n");
    scanf("%299[^\n]s", &kalimat);

    start_kata(kalimat);
    while (eop_kata(kalimat) == 0)
    {
        jumlah_vokal = cari_vokal(kalimat);
        if (jumlah_vokal >= 3)
        {
            jumlah_kata++;
        }
        inc_kata(kalimat);
    }
    
    if (get_panjang_kata() > 0)
    {
        jumlah_vokal = cari_vokal(kalimat);
        if (jumlah_vokal >= 3)
        {
            jumlah_kata++;
        }
    }

    printf("%d\n", jumlah_kata);
    return 0;
 } */

 //menghitung kata yang memiliki panjang kata ganjil
/*  int main(){
    char kalimat[300];
    int jumlah_kata = 0;
    printf("masukan kalimat: \n");
    scanf("%299[^\n]s", &kalimat);

    start_kata(kalimat);
    if (get_panjang_kata() % 2 != 0)
    {
        jumlah_kata++;
    }
    while (eop_kata(kalimat) == 0)
    {
        inc_kata(kalimat);
        if (get_panjang_kata() % 2 != 0)
        {
            jumlah_kata++;
        }
    }

    printf("banyak kata yang panjangnya ganjil : %d\n", jumlah_kata);

    return 0;
 } */

 //menampilkan kata yang palindrom
 int main(){
    char kalimat[300];
    int tanda = 0;
    int jumlah_kata = 0;
    printf("masukan kalimat: \n");
    scanf("%299[^\n]s", &kalimat);

    start_kata(kalimat);
    if (cek_palindrom(kalimat, tanda) == 0)
    {
        printf("%s\n", get_kata());
    }

    while (eop_kata(kalimat) == 0)
    {
        inc_kata(kalimat);
        if (cek_palindrom(kalimat, tanda) == 0)
        {
            printf("%s\n", get_kata());
        }
    }

    return 0;  
 }
    