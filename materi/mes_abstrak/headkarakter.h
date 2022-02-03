/* 
    MESIN ABSTRAK:
    1. Bentuknya sebenernya adalah sebuah kode progam
    2. Bertujuan untuk belajar membuat pustaka seperti string.h, stdio.h, dan lain lain
    3. setiap tombol pada mesin abstrak adalah sebuah fungsi atau prosedur
    4. Membuat mesin abstrak adalah mekanisme merancang dan membuat pustaka agar pustaka tidak mudah diganti
    ganti dan mudah digunakan

    MESIN KARAKTER:
    CC : curent charachter
    START : nyalakan mesin dan masukan satu karakter
    INC : maju satu karakter
    ADV : maju sampai ditemukan karakter berikutnya (spasi dilewat)
    GET CC : mengambil nilai cc
    EOP : lampu menyala jika ketemu titik sebagai end of process
 */
#include <stdio.h>

//implementasi Mesin Karakter - Variabel Global
int indeks;
char cc;

void start(char kata[]);
void inc(char kata[]);
void adv(char kata[]);
void cek_a(char kata[]);
char get_cc();
int get_indeks();
int eop();