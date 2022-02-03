/*Saya Alief Muhammad Abdillah 2003623 mengerjakan TP10 dalam mata kuliah Algoritma dan Pemrograman 2
untuk keberkahan-Nya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/

//bagian header
#include <stdio.h>
#include <string.h>

//variabel global
int indeks;     
int i, j, k, n;     //indeks untuk perulangan dan panjang dari array
int bk, tb;         //panjang dari array kata_baku dan kata_non_baku
int panjang_kata;   //panjang kata pada mesin kata
char current_kata[50];      //variabel untuk menampung kata di mesin kata
char arr_temp[50][50];      //array untuk menyimpan kalimat menjadi array
int arr_len[50];            //array panjang setiap kata pada kalimat

//Fungsi & Prosedur
void start_kata(char kalimat[]);        //proses memulai mesin kata
void inc_kata(char kalimat[]);          //prosedur maju satu kata pada kalimat
char *get_kata();                       //prosedur mengambil kata pada current kata
int eop_kata(char kalimat[]);           //fungsi penanda eop/end of procces
void filter_kata(char kata_baku[][50], char kata_non_baku[][50]);       //prosedur memfilter kata menjadi kata baku/non baku
void hitung_ascii(int len[]);                                           //prosedur menghitung ascii setiap kata
void sorting(char kata_baku[][50], char kata_non_baku[][50]);           //prosedur sorting array kata_baku dan kata_non_baku
