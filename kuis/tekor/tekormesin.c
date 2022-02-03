/*Saya Alief Muhammad Abdillah 2003623 mengerjakan Kuis 1 mattbk21 dalam mata kuliah Algoritma dan Pemrograman 2
untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/

//bagian mesin
#include "tekorhead.h"

//=== prosedur input ===
void input(){
    int baris, kolom;       //deklarsi variabel jumlah kolom dan baris dari matriks 
    scanf("%d", &baris);    //inputan baris dan kolom
    scanf("%d", &kolom);

    scanf("%d", &isi_bungkusan);    //inputan untuk jumlah isi bungkusan

    int bar[50];            //indeks sementara
    int kol[50];            //indeks sementara

    //perulangan mengisi cell matriks
    k = 0;
    while(k<isi_bungkusan){         //syarat jika perulangan kurang dari jumlah isi bungkusan
        scanf("%d", &bar[k]);       //inputan baris cell makanan dan harga
        scanf("%d", &kol[k]);       //inputan kolom cell makanan dan harga
        scanf("%s", matrix[bar[k]][kol[k]].makanan);    //inputan nama makanan
        scanf("%d", &matrix[bar[k]][kol[k]].harga);     //inputan harga makannan
        k++;    
    }

    scanf("%d", &banyak_pilihan);           //inputan banyak pilihan dari pemain
    for (i = 0; i < banyak_pilihan; i++)    //perulangan sebanyak banyak pilihan pemain
    {
        scanf("%d", &baris_pil1[i]);        //masukan pilihan baris dan kolom dari pemain 1
        scanf("%d", &kolom_pil1[i]);
    }
    
    for (i = 0; i < banyak_pilihan; i++)    //perulangan sebanyak banyak pilihan pemain
    {
        scanf("%d", &baris_pil2[i]);        //masukan pilihan baris dan kolom dari pemain 2
        scanf("%d", &kolom_pil2[i]);
    }

    cetak(baris, kolom, bar, kol);          //pemanggilan prosedur cetak
}

//==== Prosedur cetak ===== 
void cetak(int baris, int kolom, int bar[], int kol[]){
    int biaya1 = 0;    //variabel penampung biaya pemain 1 
    int biaya2 = 0;    //variabel penampung biaya pemain 2

    //pengecekan pilihan pemain dengan yang tersedia di matriks
    for (i = 0; i < isi_bungkusan; i++)         //perulangan sebanyak isi bungkusan
    {
        for (j = 0; j < banyak_pilihan; j++)    //perulangan sebanyak banyak pilihan
        {
            if((bar[i] == baris_pil1[j]) && (kol[i] == kolom_pil1[j]))      //jika dari pilihan baris dan kolom pemain satu ada yang sama dengan pada matriks
            {
                biaya1 = biaya1 + matrix[bar[i]][kol[i]].harga;         //harga dari makanan yang telah di pilih akan masuk ke biayaa pemain 1
            }
            else if((bar[i] == baris_pil2[j]) && (kol[i] == kolom_pil2[j])) //jika dari pilihan baris dan kolom pemain dua ada yang sama dengan pada matriks
            {
                biaya2 = biaya2 + matrix[bar[i]][kol[i]].harga;         //harga dari makanan yang telah di pilih akan masuk ke biayaa pemain 2
            }
        }
    }

    printf("pemain pertama %d\n", biaya1);          //print jumlah biaya pemain pertama
    printf("pemain kedua %d\n", biaya2);            //print jumlah biaya pemain kedua
    if (biaya1 < biaya2)                            //jika baiya pemain 1 lebih murah dar pemain 2 
    {
        printf("pemenangnya pemain pertama\n");     //print pemenangannya pemain pertama
    }
    else if (biaya2 < biaya1)                       //jika biaya pemain 2 lebih murah dari pemain 1
    {
        printf("pemenangnya pemain kedua\n");       //print pemenangannya pemain kedua
    }
    else                                            //jika biaya pemain 1 = pemain 2
    {
        printf("tidak ada pemenang\n");             //print tidak ada pemenang
    }
}