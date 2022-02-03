/*Saya Alief Muhammad Abdillah 2003623 mengerjakan UTS dalam mata kuliah Algoritma dan Pemrograman 2
untuk keberkahan-Nya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/

//bagian header
#include <stdio.h>
#include <string.h>

//tipe data bungkusan untuk penampung masukan 
typedef struct 
{
    char nama[50];      //penampung nama
    int kalori;         //penampung masukan kalori
    int berat;          //penampung masukan berat makanan
    int harga;          //penampung masukan harga makanan
    float kal_per_gram; //penampung masukan kal/gram
}arr1;

int i, j, k, l;     //variabel iterator
char metode[2];        //variabel metode
char negara1[50], negara2[50], negara3[50];        //variabel negara

//==== Prosedur =====
void input();                                                                      //prosedur inptu masukan
void insertion(int n, arr1 daftar1[]);                                             //prosedur insertion sorting array
void selection(int n, arr1 daftar1[]);                                             //prosedur selection sorting array
void bubble(int n, arr1 daftar1[]);                                                //prosedur bubble sorting array
void quick(int n, arr1 daftar1[], int kiri, int kanan);                             //prosedur quick sorting array
void merge(int n, int m, arr1 daftar1[], arr1 daftar2[], arr1 daftar_temp[]);       //prosedur merge array
void output_per_negara(int n, int m, int o, arr1 daftar1[], arr1 daftar2[], arr1 daftar3[]);        //prosedur output per negara
void output_semua(int n, int m, int o, arr1 daftar_hasil[], arr1 daftar1[], arr1 daftar2[], arr1 daftar3[]);    //prosedur output semua