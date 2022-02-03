/*Saya Alief Muhammad Abdillah 2003623 mengerjakan TP7 dalam mata kuliah Algoritma dan Pemrograman 2
untuk keberkahan-Nya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/

//bagian header
#include <stdio.h>
#include <string.h>

//deklarasi tipe data struktur
typedef struct
{
    char nama[50];      //variabel nama
    int nilai;          //variabel nilai
    int m;              //variabel untuk menyimpan jumlah extra kulikuler
}data_siswa;

int total_nilai[50];    //variabel untuk menyimpan total nilai extrakulikuler
float rata_rata[50];    //variabel untuk menyimpan rata-rata nilai extrakulikuler
int found;              //variabel indikator saat proses pencarian
int index_cari;         //variabel untuk menampung masukan index yang ingin dicari namanya
int i,j,k,l;            //iterator untuk perulangan

//==== Prosedur dan Fungsi =====
void input();                                   //prosedur input
void rata_nilai(int n, data_siswa siswa[]);     //prosedru penghitungan nilai rata-rata
void search_bin(int n, data_siswa siswa[]);     //prosedur pencarian binary
void search_seq(int n, data_siswa siswa[]);     //prosedur pencarian sequential
void sorting(int n, data_siswa siswa[]);        //prosedur sorting
void output(int n, data_siswa siswa[]);         //prosedur menampilkan output
int cek_urut(int n);                            //fungsi mengecek apakah nilai sudah urut atau tidak
