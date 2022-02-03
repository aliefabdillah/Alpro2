#include "headkarakter.h"
//implementasi mesin karakter - Start
void start(char kata[]){
    indeks = 0;
    cc = kata[indeks];
}

//implementasi mesin karakter - Inc
void inc(char kata[]){
    indeks++;
    cc = kata[indeks];
}

//implementasi mesin karakter - EOP
int eop(){
    if (cc == '.')
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}

//implementasi mesin karakter - adv
void adv(char kata[]){
    indeks++;
    cc = kata[indeks];
    while ((cc == ' ') && (eop() == 0))
    {
        indeks++;
        cc = kata[indeks];
    }
}

//implementasi mesin karakter - Get CC
char get_cc(){
    return cc;
}

int get_indeks(){
    return indeks+1;
}

//menampilkan huruf a saja dan urutan huruf ke berapa
void cek_a(char kata[]){
    if (cc == 'a')
    {
        printf("%c urutan ke - %d\n", get_cc(), get_indeks());
        inc(kata);
    }
    else
    {
        inc(kata);
    }
} 

