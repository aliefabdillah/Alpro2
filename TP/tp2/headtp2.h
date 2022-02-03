/*Saya Alief Muhammad Abdillah 2003623 mengerjakan TP2 dalam mata kuliah Algoritma dan Pemrograman 2
untuk keberkahan-Nya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/

//bagian header
#include <stdio.h>
#include <string.h>

//===== Deklarasi Bentukan ======
typedef struct{
	char nama[50];					//matriks string penampung inputan nama
	float nilai1, nilai2, nilai3;	//matriks array penampung inputan nilai 1, 2 , 3
	char hasil[50];					//matriks string penampung hasil nama yang sudah di tukar posisinya
}bungkus;

int i,j,k,l;						//iterator
float rata_rata[50][50];			//matriks array penampung rata-rata dari nilai 1, 2, 3 
char ganti[20][20];					//array untuk menampung nama-nama yang akan di ubah posisinya

void input();						//deklarasi prosedur input
void cek_nama(int baris, int kolom, bungkus nilai[baris][kolom]);				//deklarasi prosedur cek nama yang akan di ubah posisinya
void cek_rata(int baris, int kolom, int baris_first, int kolom_first, int baris_sec, int kolom_sec, bungkus matrix[baris][kolom]);	//prosedur mengecek rata-rata nama yang akan di ubah posisinya
void print_akhir_awal(int baris, int kolom, bungkus matrix[baris][kolom]);		//prosedur cetak nama yang belum di ubah posisinya
void print_akhir_hasil(int baris, int kolom, bungkus matrix[baris][kolom]);		//prosedur cetak nama yang sudah di ubag posisinya
void print_akhir(int baris, int kolom, bungkus matrix[baris][kolom]);			//prosedur print output
int tukar_rata(int baris, int kolom, int baris_first, int kolom_first, int baris_sec, int kolom_sec, bungkus matrix[baris][kolom]);	 //fungsi pertukaran nilai rata-rata
void tukar_nama(int baris, int kolom, int baris_first, int kolom_first, int baris_sec, int kolom_sec, bungkus matrix[baris][kolom]); //prosedur pertukaran nama
