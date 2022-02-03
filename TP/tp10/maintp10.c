/*Saya Alief Muhammad Abdillah 2003623 mengerjakan TP10 dalam mata kuliah Algoritma dan Pemrograman 2
untuk keberkahan-Nya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/

//bagian main
#include "headtp10.h"

int main(){
    char kalimat[200];              //masukan kalimat
    scanf("%199[^\n]s", &kalimat);

    n = 0;
    start_kata(kalimat);                //proses mesin kata
    strcpy(arr_temp[n], get_kata());
    n++;
    while (eop_kata(kalimat) == 0)
    {
        inc_kata(kalimat);
        strcpy(arr_temp[n], get_kata());        //memindahkan kata pada kalimat menjadi array
        n++;
    }

    int len[n]; 
    hitung_ascii(len);              //proses menghitung ascii dari setiap kata

    char kata_baku[50][50];
    char kata_non_baku[50][50];
    //proses mengisi null pada array kata_baku dan non_baku
    for ( i = 0; i < 50; i++)
    {
        //prosedur memset untuk mengisi secara singkat array
        memset(kata_baku[i], '\0', 50);         
        memset(kata_non_baku[i], '\0', 50);
    }
     
    filter_kata(kata_baku, kata_non_baku);      //prosedur filter kata menjadi kata baku/tidak baku
    sorting(kata_baku, kata_non_baku);          //sorting array kata baku dan tidak baku 

    //print hasil akhir
    printf("KATA BAKU:\n");
    if (kata_baku[0][0] == '\0')            //jika array tidak memiliki isi/cuma berisi NULL
    {
        printf("TIDAK ADA.\n");
    }
    else                                    //jika tidak
    {
        for ( i = 0; i < bk; i++)
        {
            printf("%s\n", kata_baku[i]);
        }
    }
    
    printf("\nKATA NON BAKU:\n");
    if (kata_non_baku[0][0] == '\0')      //jika array tidak memiliki isi/cuma berisi NULL  
    {
        printf("TIDAK ADA.\n");         //jika tidak
    }
    else
    {
        for ( i = 0; i < tb; i++)
        {
            printf("%s\n", kata_non_baku[i]);
        }
    }

    return 0;
}
