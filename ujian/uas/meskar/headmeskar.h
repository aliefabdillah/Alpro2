/*Saya Alief Muhammad Abdillah 2003623 mengerjakan UAS meskar21 dalam mata kuliah Algoritma dan Pemrograman 2
untuk keberkahan-Nya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/

//bagian header
#include <stdio.h>

//variabel global
int indeks;
char cc;
int i, j;           //iterator perulangan
char arr[50][50];   //untuk menampung hasil akhir

//Prosedur & Fungsi mesin kata
void salin(char temp[], int n, int m);      //prosedur tambahan untuk menyalin kata ke array akhir
void start(char kata[]);
void inc(char kata[]);
void adv(char kata[]);
char get_cc();
int get_indeks();
int eop();

