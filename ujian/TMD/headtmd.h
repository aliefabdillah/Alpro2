/* 
    Saya Alief Muhammad Abdillah mengerjakan evaluasi Tugas Masa Depan dalam mata kuliah Algoritma dan 
    Pemrograman II untuk keberkahanNya maka saya tidak melakukan kecurangan seperti 
    yang telah dispesifikasikan. Aamiin.
 */

//bagain header
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//file bungkusan
typedef struct 
{
    char kode_barang[10];
    char nama[50];
    char harga[50];
    char stok[50];
    char jmlh_beli[50];
}tabel_barang;

FILE *file_nama;
FILE *file_beli;

tabel_barang arr_tnama[50];             //array bungkusan untuk tabel nama
tabel_barang arr_tbeli[50];             //array bungkusan untuk tabel beli
tabel_barang input_tnama[10];           //array bungkusan untuk input pada tabel nama
tabel_barang input_tbeli[10];           //array bungkusan untuk input pada tabel beli

//vairabel global mesin kata
int indeks;
int panjang_kata;
char current_kata[50];

//variabel global prosedur dan fungsi
int i, j;                           //iterator
int nm, hr;                         //menampung banyak data pada tabel
int status;                         //var. untuk pengecekan
char query[200];                    //var. masukan query

//MESIN KATA
void start_kata(char query[]);
void inc_kata(char query[]);
char *get_kata();
int eop_kata(char query[]);

//Prosedur Query
void GANTI(char nama_tabel[50]);
void TAMBAH(char nama_tabel[50]);
void HAPUS(char nama_tabel[50]);
void HAPUS_ALL(char nama_tabel[50]);
void TAMPIL(char nama_tabel[50]);

//Prosedur lainnya
void read(char nama_tabel[50]);
void write(char nama_tabel[50]);
void garis(int panjang_kode);
void sort(char nama_tabel[50]);
