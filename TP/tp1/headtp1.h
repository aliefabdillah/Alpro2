/*Saya Alief Muhammad Abdillah 2003623 mengerjakan TP1 dalam mata kuliah Algoritma dan Pemrograman 2
untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/

//bagian header
#include <stdio.h>

int awal[50][50];			//deklarasi variabel matriks awal/inputa
int transpose[50][50];		//deklarasi matriks simpanan hasil transpose
int refleksi[50][50];		//deklarasi matriks simpanan hasil refleksi
int akhir[50][50];			//deklarasi matriks hasil akhir

int jumlah;					//deklarasi variabel untuk menampung jumlah kolom terakhir
int i,j;					//iterator

/*
===============================
==   PROSEDUR INPUT OUTPUT   ==
===============================
*/
void input();									
void output(int baris, int kolom);				


void refleksi_transpose(int baris, int kolom);		//prosedur refleksi dan transpose pertama
void kanan(int sisa, int baris, int kolom);			//prosedur rotasi ke kanan
void kiri(int sisa, int baris, int kolom);			//prosedur rotasi ke kiri