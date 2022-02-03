#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*Saya FAJRI MAULANA ISKANDAR 2009576 mengerjakan Tugas Masa Depan ALPRO 2 dalam mata kuliah Algoritma dan Pemrograman
      untuk keberkahanNya maka saya tidak melakukan kecurangan
      seperti yang telah dispesifikasikan. Aamiin*/

typedef struct{
    //variabel string halaqoh tahsin
    char id_ths[50];           //variabel string id halaoqh tahsin
    char nama_ths[50];         //variabel string nama halaoqh tahsin
    char halaqoh_ths[50];      //variabel string halaqoh halaoqh tahsin
    //variabel string halaoh tahfidz
    char id_tdz[50];            //variabel string id halaoqh tahfidz
    char nama_tdz[50];          //variabel string nama halaoqh tahfidz
    char halaqoh_tdz[50];       //variabel string halaqoh halaoqh tahfidz
}tahfizh;                       //struktur tahfizh

tahfizh data[50];               //array typedef struktur tahfizh

//variabel global mesin kata
int idx;                    //index mesin kata
int lenkata;                //variabel panjang kata
char ckata[50];             //variabel string isi kata

//variabel global file data santri
FILE *santri[2];                //variabel penampung file
int dIdx;                       //variabel index data
int upIdx;                      //variabel index fungsi find data record yang sama
char use[10];                   //variabel string penentuan tabel yang akan di olah

//mesin olah kata
int EOP(char tape[]); //fungsi eop mesin kata
void START(char tape[]); //prosedur memulai mesin kata
char *GETCURRENTWORD(); // fungsi menampung kata
void RESET(); //prosedur mereset kata
void INC(char tape[]);//prosedur increment kata
int GETLENGTWORD(); //fungsi menampung panjang kata

//mesin pengolahan data
int cekQuery(char tape[]); //fungsi mencari mengecek command query masukan
int findIdx(char tape[]);//fungsi searching mencari index yang sama konsep sequential search
int cekTotal(char tape[]);//fungsi menghitung total masukan yang ada pada masukan user
void read(char tape[]);//prosedur membaca file pada record data dat.
void write(char tape[]);//prosedur membaca file/menyalin file kedalam record data file dat.
void insert(char tape[]);//prosedur insert data record
void update(char tape[]);//prosedur untuk mengupdate data record yang sudah ada
void deleteData(char tape[]);//prosedur menghapus data yang sudah ada

//mesin select
void header(char tape[]); //prosedur menampilkan header pada tabel
void body(char tape[]); //prosedur menampilkan isi tabel
void close(char tape[]);//prosedur menampilkan penutup tabel
void select(char tape[]); //prosedur menampilkan header isi close dari tabel
