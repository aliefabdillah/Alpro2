#include "headkata_prak.h"

void start_kata(char kalimat[]){
    indeks = 0;
    panjang_kata = 0;
    while (kalimat[indeks] == ' ')
    {
        indeks++;
    }

    while ((kalimat[indeks] != ' ') && (kalimat[indeks] != '.'))
    {
        current_kata[panjang_kata] = kalimat[indeks];
        indeks++;
        panjang_kata++;
    }
    
    current_kata[panjang_kata] = '\0';
}

void reset_kata(){
    panjang_kata = 0;
    current_kata[panjang_kata] = '\0';
}

void inc_kata(char kalimat[]){
    panjang_kata = 0;
    while (kalimat[indeks] == ' ')
    {
        indeks++;
    }

    while ((kalimat[indeks] != ' ') && (kalimat[indeks] != '.'))
    {
        current_kata[panjang_kata] = kalimat[indeks];
        indeks++;
        panjang_kata++;
    }
    
    current_kata[panjang_kata] = '\0';
}

char *get_kata(){
    return current_kata;
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

void insert_data(char kalimat[], mahasiswa *data){
    int coutlen = 0;
    start_kata(kalimat);

    while (eop_kata(kalimat) == 0)
    {
        if ((strcmp(get_kata(), "INSERT") != 0) && (strcmp(get_kata(), "mahasiswa") != 0))
        {
            if (coutlen == 0)
            {
                strcpy(data->nim, get_kata());
            }
            else if (coutlen == 1)
            {
                strcpy(data->nama, get_kata());
            }
            coutlen++;
        }
        inc_kata(kalimat);
    }
    
    strcpy(data->nilai, get_kata());
}