/*Saya Alief Muhammad Abdillah 2003623 mengerjakan TP6 dalam mata kuliah Algoritma dan Pemrograman 2
untuk keberkahan-Nya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/

//bagian header
#include <stdio.h>
#include <string.h>

//tipe data bungkusan untuk penampung masukan durasi dan judul lagu
typedef struct 
{
    float durasi;
    char judul[50];
}arr1;


int i, j, k, l;     //variabel iterator
char metode;        //variabel metode
char urutan;        //variabel untuk menampung urutan (asencedin/descending)

//==== Prosedur =====
void input();                                                                      //prosedur inptu masukan
void insertion(int n, arr1 daftar1[]);                                             //prosedur insertion sorting array
void selection(int n, arr1 daftar1[]);                                             //prosedur selection sorting array
void bubble(int n, arr1 daftar1[]);                                                //prosedur bubble sorting array
void quick(int n, arr1 daftar1[], int kanan, int kiri);                             //prosedur quick sorting array
void merge(int n, int m, arr1 daftar1[], arr1 daftar2[], arr1 daftar_temp[]);       //prosedur merge array
void output(int n, int m, int o, arr1 daftar_hasil[], arr1 daftar1[]);              //prosedur menampilkan hasil gabun dar array

