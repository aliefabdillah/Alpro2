/*Saya Alief Muhammad Abdillah 2003623 mengerjakan Eval UAS dalam mata kuliah Algoritma dan Pemrograman 2
untuk keberkahan-Nya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/

//bagian header
#include <stdio.h>
#include <string.h>

//array bungkusan
typedef struct 
{
    char id[50];
    char nama[50];
    char kelas[50];
}tabel_kereta;

//deklarasi bungkusan
tabel_kereta input[50];
tabel_kereta hasil[50];

//variabel global mesin kata
int indeks;
int panjang_kata;
char current_kata[50];

//variabel global lain
int i,j,n,m;
char temp_id[50];
char temp_nama[50];
char temp_kelas[50];

// Prosedur dan Fungsi
void start_kata(char query[]);      //mulai prosedur mesin kata
void inc_kata(char query[]);        //maju satu kata
char *get_kata();                   //mengambil kata saat ini
int get_panjang_kata();             //mengambil panjang kata saat ini
int eop_kata(char query[]);         //penanda ; untuk setiap query
int eop_query(char query[]);        //penanda ; pada query TAMPILKAN untuk menghentikan perulangan masukan
void CARI(char nama_kolom[50]);     //prosedur cari id/nama/kelas
void TAMPIL();                      //menampilkan hasil
void garis(int panjang_id);         //print garis