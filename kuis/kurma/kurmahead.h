/*Saya Alief Muhammad Abdillah 2003623 mengerjakan Kuis 2 Kurmabs21 dalam mata kuliah Algoritma dan Pemrograman 2
untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/

//bagian header
#include <stdio.h>
#include <string.h>

//bungkusan list daftar kurma
typedef struct
{
    char nama[20];  //variabel nama kurma
    int gram;       //variabel berat kurma
    int harga;      //variabel harga kurma
    char status[20];    //variabel status kurma (premium/standar)
    int harga_per_gram;     //variabel penampung harga/berat
}daftar_kurma;

int i,j,k;          //variabel iterator untuk indeks
int cari_harga;     //variabel untuk mencari harga/berat yang dinginkan
int found;          //variabel penanda

//==== Prosedur =====
void input();           //prosedur input masukan user
void cari_harga_per_gram(int n, daftar_kurma list[]);       //prosedur cari harga/berat yang di inginkan
void sorting_harga_per_gram(int n, daftar_kurma list[]);    //prosedur sorting sesuai harga/berat
void output(int n, daftar_kurma list[]);                    //prosedur tampil akhir

