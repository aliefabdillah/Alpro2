//Materi Mesin Kata
/* 
    Kata adalah sekumpulan huruf yang dibatasi oleh spasi atau
    titik sebagai eop
 */

//bagian mesin kata
/* 
    CKATA - Current kata
    STARTKata - Nyalakan mesin dan masuk saku kata
    RESETKATA - Membersihkan CKATA
    INCKATA - maju satu kata
    GETKATA - mengambil nilai kata
    GETPANJANGKATA - mengambil nilai panjang kata
    EOPKATA - Lampu menyala jika ketemu titik sebagai eop
 */

#include <stdio.h>
#include <string.h>

//variabel global
int indeks;
int panjang_kata;
char ckata[50];
int banyak_vokal;

void start_kata(char kalimat[]);
void reset_kata();
void inc_kata(char kalimat[]);
char* get_kata();
int get_panjang_kata();
int eop_kata(char kalimat[]);
int cari_vokal(char kalimat[]);
int cek_palindrom(char kalimat[], int tanda);