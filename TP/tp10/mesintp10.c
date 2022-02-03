/*Saya Alief Muhammad Abdillah 2003623 mengerjakan TP10 dalam mata kuliah Algoritma dan Pemrograman 2
untuk keberkahan-Nya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/

//bagian mesin
#include "headtp10.h"

//Prosedur Start_kata
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

//Prosedur inc_kata
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

//fungsi Start_kata
char *get_kata(){
    return current_kata;
}

//fungsi eop_kata
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

//prosedur hitung ascii
void hitung_ascii(int len[]){
    for ( i = 0; i < n; i++)
    {
        len[i] = strlen(arr_temp[i]);       //memasukan panjang setiap kata pada array temp ke array len
    }

    //proses menjumlahkan nilai ascii setiap kata
    for ( i = 0; i < n; i++)
    {
        for ( j = 0; j < len[i]; j++)
        {
            arr_len[i] = arr_len[i] + arr_temp[i][j];
        }
    }
    
    
}

//prosedur filter_kata
void filter_kata(char kata_baku[][50], char kata_non_baku[][50]){
    bk = 0;     //variabel panjang array kata_baku
    tb = 0;     //variabel panjang array kata_non_baku
    for ( i = 0; i < n; i++)
    {   
        //jika panjang kata pada array genap
        if (arr_len[i] % 2 == 0)
        {
            strcpy(kata_baku[bk], arr_temp[i]);     //kata pada array temp masuk ke array kata baku
            bk++;
        }
        //jika ganjil
        else
        {
            strcpy(kata_non_baku[tb], arr_temp[i]); //kata pada array temp masuk ke array kata non baku
            tb++;
        }
    }
}

//prosedur sorting
void sorting(char kata_baku[][50], char kata_non_baku[][50]){
    //menggunakan insertion sort
    //sorting array kata baku
    char temp_kata[50];
    for ( i = 1; i < bk; i++)
    {
        strcpy(temp_kata, kata_baku[i]);
        j = i - 1;
        while ((j >= 0) && (strcmp(temp_kata, kata_baku[j]) < 0))
        {
            strcpy(kata_baku[j+1], kata_baku[j]);
            j--;
        }
        strcpy(kata_baku[j+1], temp_kata);
    }

    //sorting array kata_non_baku
    for ( i = 1; i < tb; i++)
    {
        strcpy(temp_kata, kata_non_baku[i]);
        j = i - 1;
        while ((j >= 0) && (strcmp(temp_kata, kata_non_baku[j]) < 0))
        {
            strcpy(kata_non_baku[j+1], kata_non_baku[j]);
            j--;
        }
        strcpy(kata_non_baku[j+1], temp_kata);
    }
}