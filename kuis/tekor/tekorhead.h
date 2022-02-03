/*Saya Alief Muhammad Abdillah 2003623 mengerjakan Kuis 1 mattbk21 dalam mata kuliah Algoritma dan Pemrograman 2
untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/

//bagian header
#include <stdio.h>
#include <string.h>

//==== Tipe Data Struktur
typedef struct
{
    int harga;          //deklarasi untuk cell harga
    char makanan[50];   //deklarasi untuk cell makanan
}bungkus;

bungkus matrix[50][50]; //deklarasi matriks bungkusan

//==== Variabel Global =====
int i,j,k,l;            //iterator
int banyak_pilihan;     //variabel penampung banyaknya pilihan dar pemain
int isi_bungkusan;      //varaibel penampung isi dari bungkusan
int baris_pil1[10];     //array penammpung baris pilihan dari pemain pertama
int kolom_pil1[10];     //array penammpung kolom pilihan dari pemain pertama
int baris_pil2[10];     //array penammpung baris pilihan dari pemain kedua
int kolom_pil2[10];     //array penammpung kolom pilihan dari pemain kedua

void input();           //prosedur input
void cetak(int baris, int kolom, int bar[], int kol[]);     //prosedur cetak