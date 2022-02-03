/*Saya Alief Muhammad Abdillah 2003623 mengerjakan Eval UAS dalam mata kuliah Algoritma dan Pemrograman 2
untuk keberkahan-Nya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/

//bagian main
#include "headeval2.h"

int main(){
    char query[200];                //deklarasi query
    int cek = 0;                    //var. cek perulangan
    scanf(" %199[^\n]s", &query);   //masukan user

    start_kata(query);              //memulai mesin kata
    n = 0;
    //perulangan sampai bertemu kata TAMPILKAN dan eop = ;
    while ((strcmp(get_kata(), "TAMPILKAN") != 0) && cek == 0)
    {
        //---------------- Jika Query INSERT --------------
        if (strcmp(get_kata(), "INSERT") == 0)
        {
            inc_kata(query);
            strcpy(input[n].id, get_kata());        
            if (eop_kata(query) == 0)
            {
                inc_kata(query);
                strcpy(input[n].nama, get_kata());      //memasukan kata selanjutnya ke input nama
                if (eop_kata(query) == 0)
                {
                    inc_kata(query);
                    strcpy(input[n].kelas, get_kata());     //memasukan kata selanjutnya ke input kelas
                    n++;
                    //jika bertemu ;
                    if (eop_kata(query) == 1)           
                    {
                        scanf(" %199[^\n]s", &query);       //kembali meminta masukan 
                        start_kata(query);
                    }
                }
            }
        }
        //---------------- Jika Query CARI --------------
        if (strcmp(get_kata(), "CARI") == 0)
        {
            inc_kata(query);
            if (strcmp(get_kata(), "id") == 0)
            {
                if (eop_kata(query) == 0)
                {
                    inc_kata(query);
                    strcpy(temp_id, get_kata());        //data dimasukan ke temp_id untuk dicari
                    
                    //jika bertemu ;
                    if (eop_kata(query) == 1)
                    {
                        CARI("id");                         //memanggil prosedur cari
                        scanf(" %199[^\n]s", &query);   //kembali meminta masukan
                        start_kata(query);
                    }
                }
            }
            if (strcmp(get_kata(), "nama") == 0)
            {
                if (eop_kata(query) == 0)
                {
                    inc_kata(query);
                    strcpy(temp_nama, get_kata());      //data dimasukan ke temp_nama untuk dicari
                    //jika bertemu ;
                    if (eop_kata(query) == 1)
                    {
                        CARI("nama");                       //memanggil prosedur cari
                        scanf(" %199[^\n]s", &query);   //kembali meminta masukan
                        start_kata(query);
                    }
                }
            }
            if (strcmp(get_kata(), "kelas") == 0)
            {
                if (eop_kata(query) == 0)
                {
                    inc_kata(query);
                    strcpy(temp_kelas, get_kata());     //data dimasukan ke temp_kelas untuk dicari
                    //jika bertemu ;
                    if (eop_kata(query) == 1)
                    {
                        CARI("kelas");                      //memanggil prosedur cari
                        scanf(" %199[^\n]s", &query);   //kembali meminta masukan
                        start_kata(query);
                    }
                }
            }
            if (eop_query(query) == 1)
            {
                cek = 1;
            }
        }
    }

    TAMPIL();       //prosedur tampil
    return 0;
}

/* 
INSERT KA0012345 Sawunggalih Bisnis;
INSERT KA002 ArgoMuria Eksekutif;
INSERT KA003 Madiun Bisni;
CARI kelas Eksekutif;
TAMPILKAN;
 */