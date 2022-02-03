/*Saya Alief Muhammad Abdillah 2003623 mengerjakan Kuis 1 reklom21 dalam mata kuliah Algoritma dan Pemrograman 2
untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/

//bagian mesin
#include "lompathead.h"

//==== Prosedur Input =====
void input(){
    long angka1, angka2;        //deklarasi angka yang akan dibagi dan dikali
    int dua = 2;                //deklarasi pembagi

    scanf("%ld", &angka1);      //proses input angka yang akan dibagi dan dikali
    scanf("%ld", &angka2);

    //printf("(%ld|%ld)\n", angka1, angka2);

    cetak(angka1, angka2, dua); //pemanggilan fungsi cetak
}

void cetak(long angka1, long angka2, int dua){
    
    if(angka1 - dua == 0)                             //basis / syarat pembagian dimana jika angka dibagi - 2 == 0
    {
        printf("(%ld|%ld)\n", angka1, angka2);            //mencetak angka yang dibagi yang berposisi kedua terakhir dan pengali                          //jika angka yang dibagi sudah = 2 //mencetak angka 1 dan hasl angka yang dikali posisi terakhir
        if (angka1 == 2)
        {
            printf("(1|%d)\n", angka2*2);
        }
        
    }
    else                                            //jika syarat pembagian dimana jika angka dibagi - 2 != 0
    {   
        printf("(%ld|%ld)\n", angka1, angka2);      //mengeprint angka hasil bagi dan hasil kali
        cetak(angka1/dua, angka2*dua, dua);         //proses perulangan rekursif
    }
}
