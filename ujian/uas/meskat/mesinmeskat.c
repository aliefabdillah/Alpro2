/*Saya Alief Muhammad Abdillah 2003623 mengerjakan UAS meskat21 dalam mata kuliah Algoritma dan Pemrograman 2
untuk keberkahan-Nya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/

//bagian mesin
#include "headmeskat.h"

//prosedur start mesin kata
void start_kata(char kalimat[]){
    indeks = 0;
    panjang_kata = 0;
    while (kalimat[indeks] == ' ')
    {
        indeks++;
    }

    while ((kalimat[indeks] != ' ') && (kalimat[indeks] != '.'))
    {
        ckata[panjang_kata] = kalimat[indeks];
        indeks++;
        panjang_kata++;
    }
    
    ckata[panjang_kata] = '\0';
}

//menghapus kata di current kata/ckata
void reset_kata(){
    panjang_kata = 0;
    ckata[panjang_kata] = '\0';
}

//maju satu kata selanjutnya
void inc_kata(char kalimat[]){
    panjang_kata = 0;
    while (kalimat[indeks] == ' ')
    {
        indeks++;
    }

    while ((kalimat[indeks] != ' ') && (kalimat[indeks] != '.'))
    {
        ckata[panjang_kata] = kalimat[indeks];
        indeks++;
        panjang_kata++;
    }
    
    ckata[panjang_kata] = '\0';
}

char* get_kata(){
    return ckata;
}

int get_panjang_kata(){
    return panjang_kata;
}

//fungsi eop
int eop_kata(char kalimat[]){
    if (kalimat[indeks] == '.')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//fungsi cek huruf vokal / konsonan
int cek_vokal(char ckata){
    if( ckata =='a' || ckata =='i' || ckata == 'u' || ckata == 'e' ||  ckata == 'o')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}