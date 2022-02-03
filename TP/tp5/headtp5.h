/*Saya Alief Muhammad Abdillah 2003623 mengerjakan TP5 dalam mata kuliah Algoritma dan Pemrograman 2
untuk keberkahan-Nya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/

//bagian header
#include <stdio.h>          //deklarasi library stdio.h dan string.h 

//bungkusan untuk menampung nilai pembilang dan penyebut
typedef struct
{
    int pembilang;  //variabel pembilang
    int penyebut;   //variabel penyebut
}bungkus;


int i,j;        //variabel iterator
int temp_pembilang, temp_penyebut;  //variabel sementara saat pertukaran
int tanda;      //variabel tanda saat bubble sort

//===== Bagian Prosedur & Fungsi ======
void input();           //prosedur input
double desimal_pecahan(bungkus angka);       //fungsi membagi pembilang dan penyebut dalam bentuk desimal untuk di urutkan
void bubble(int n, char urutan, bungkus angka[n]);  //prosedur bubble sort
void quick(int n, char urutan, bungkus angka[n], int kiri, int kanan);  //prosedur quick sort
void cetak(int n, bungkus angka[n]);        //prosedur print hasil akhir