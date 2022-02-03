/*Saya Alief Muhammad Abdillah 2003623 mengerjakan UAS meskat21 dalam mata kuliah Algoritma dan Pemrograman 2
untuk keberkahan-Nya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/

//bagian header
#include <stdio.h>
#include <string.h>

//variabel global
int indeks;
int i,j;
int panjang_kata;
char ckata[50];
int panjang;
char arr_akhir[50][50];

//prosedur & fungsi
void start_kata(char kalimat[]);
void reset_kata();
void inc_kata(char kalimat[]);
char* get_kata();
int get_panjang_kata();
int eop_kata(char kalimat[]);
int cek_vokal(char ckata);