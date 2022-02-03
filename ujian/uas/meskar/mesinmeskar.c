/*Saya Alief Muhammad Abdillah 2003623 mengerjakan UAS meskar21 dalam mata kuliah Algoritma dan Pemrograman 2
untuk keberkahan-Nya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/

#include "headmeskar.h"

//Prosedur - Start
void start(char kata[]){
    indeks = 0;
    cc = kata[indeks];
}

//Prosedur - Inc
void inc(char kata[]){
    indeks++;
    cc = kata[indeks];
}

//iFungsi - EOP
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

//Prosedur - adv
void adv(char kata[]){
    indeks++;
    cc = kata[indeks];
    while ((cc == ' ') && (eop() == 0))
    {
        indeks++;
        cc = kata[indeks];
    }
}

//Prosedur - Get CC
char get_cc(){
    return cc;
}

int get_indeks(){
    return indeks+1;
}

//Prosedur - Salin ke array akhir
void salin(char temp[], int n, int m){
    for (i = 0; i < m; i++)
    {
        arr[n][i] = temp[i];
    }
}