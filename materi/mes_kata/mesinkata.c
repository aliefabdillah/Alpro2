#include "headkata.h"

//aku suka kucing.
//memulai proses dengan mengambil satu kata
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

int cari_vokal(char kalimat[]){
    banyak_vokal = 0;
    panjang_kata = 0;
    while ((ckata[panjang_kata] != '\0'))
    {
        if ((ckata[panjang_kata] == 'a') || (ckata[panjang_kata] == 'i') || (ckata[panjang_kata] == 'u') ||
        (ckata[panjang_kata] == 'e') || (ckata[panjang_kata] == 'o'))
        {
            banyak_vokal++;
        }
        panjang_kata++;
    }

    return banyak_vokal;
}

int cek_palindrom(char kalimat[], int tanda){
    int i = 0;

    do
    {
        if (ckata[i] != ckata[panjang_kata - i - 1])
        {
            tanda = 1;
        }
        i++;
    } while (i < panjang_kata);
    
    return tanda;
}