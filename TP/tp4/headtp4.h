/*Saya Alief Muhammad Abdillah 2003623 mengerjakan TP4 dalam mata kuliah Algoritma dan Pemrograman 2
untuk keberkahan-Nya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/

//bagian header
#include <stdio.h>          //deklarasi library stdio.h dan string.h 
#include <string.h>

//===== Deklarasi Variabel =====
int i,j;                //deklarasi iterator
int n;                  //deklarasi variabel untuk jumlah masukan user
char sisip_barang[50];  //variabel character untuk tempat sisip nama barang saat proses perpindahan 
int sisip_harga;        //variabel integer untuk tempat sisip harga barang saat proses perpindahan
float sisip_nilai;      //variabel float untuk tempat sisip nilai barang saat proses perpindahan
char barang[50][50];    //variabel penampung masukan nama barang
int harga[50];          //variabel penampung masukan harga barang
float nilai[50];        //variabel penampung masukan nilai barang


//===== Deklarasi Prosedur =====
void input();       //prosedur input
void output(char metode[], char naik_turun[], char patokan[]);      //prosedur ouput
void insert(char metode[], char naik_turun[], char patokan[]);      //prosedur sorting secara insertion
void select(char metode[], char naik_turun[], char patokan[]);      //prosedur sorting secara selection


