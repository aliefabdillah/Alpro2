/*Saya Alief Muhammad Abdillah 2003623 mengerjakan TP9 dalam mata kuliah Algoritma dan Pemrograman 2
untuk keberkahan-Nya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/

//bagian header
#include <stdio.h>
#include <string.h>

//Variabel global
int indeks;     //variabel untuk indeks pada karakter
int n;          //vairabel penanda
char cc;        //vairabel cc/current character

//### Prosedur dan Fungsi ###
void input();                   //prosedur input masukan user
void start(char kode[]);        //prosedur memulai scan kode
void inc(char kode[]);          //prosedur maju setiap huruf
void output(char nama[]);       //prosedur menampilkan hasil akhir/output
char get_cc();                  //fungsi menganmbil huruf   
int eop();                      //fungsi penanda sudah di akhir kalimat
