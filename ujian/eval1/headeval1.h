/*Saya Alief Muhammad Abdillah 2003623 mengerjakan Eval UTS dalam mata kuliah Algoritma dan Pemrograman 2
untuk keberkahan-Nya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/

//bagian header
#include <stdio.h>
#include <string.h>

//deklarasi bungkusan daftar nama,nilai1,nilai2
typedef struct 
{
    char nama[50];  //variabel nama
    int nilai1;     //variabel nilai1
    int nilai2;     //variabel nilai2
}daftar;

int i,j,k,l;        //iterator

//===== Prosedur =======
void input();           //prosedur input
void sorting(int n, daftar mhswa1[], int kiri, int kanan);      //prosedur sorting
void merge(int n, int m, daftar mhswa1[], daftar mhswa2[], daftar gabungan[]);      //prosedur merge kedua array
void cetak_gabung(int n, int m, daftar gabungan[]);             //prosedur cetak akhir          
