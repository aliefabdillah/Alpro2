/*Saya Alief Muhammad Abdillah 2003623 mengerjakan Kuis 2 Kurmabs21 dalam mata kuliah Algoritma dan Pemrograman 2
untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/

//bagian mesin
#include "kurmahead.h"

//===== Prosedur Input =====
void input(){
    int n;              //variabel banyaknya array
    scanf("%d", &n);

    daftar_kurma list[n];       //deklarasi array

    //proses masukan array daftar data kurma
    for ( i = 0; i < n; i++)
    {
        scanf("%s", list[i].nama);
        scanf("%d", &list[i].gram);
        scanf("%d", &list[i].harga);
        scanf("%s", list[i].status);
        list[i].harga_per_gram = (int)list[i].harga/list[i].gram;
    }

    scanf("%d", &cari_harga);       //masukan nilai harga/berat yang ingin dicari

    sorting_harga_per_gram(n, list);        //pemanggilan prosedur sorting daftar kurma sesuai harga/gram
    cari_harga_per_gram(n, list);           //pemanggilan prosedur cari harga/berat
    output(n, list);                        //pemanggilan prosedur cetak akhir  
}

//==== Prosedur Sorting ======
void sorting_harga_per_gram(int n, daftar_kurma list[]){
    char temp_nama[20];
    int temp_gram;
    int temp_harga;
    char temp_status[20];
    int temp_harga_per_gram;

    //proses sorting menggunakan insertion sort
    for ( i = 1; i < n; i++)
    {
        strcpy(temp_nama, list[i].nama);
        temp_gram = list[i].gram;
        temp_harga = list[i].harga;
        strcpy(temp_status, list[i].status);
        temp_harga_per_gram = list[i].harga_per_gram;
        j = i - 1;
        while ((temp_harga_per_gram > list[j].harga_per_gram) && (j >= 0))
        {
            strcpy(list[j+1].nama, list[j].nama);
            list[j+1].gram = list[j].gram;
            list[j+1].harga = list[j].harga;
            strcpy(list[j+1].status, list[j].status);
            list[j+1].harga_per_gram = list[j].harga_per_gram;
            j--;
        }
        strcpy(list[j+1].nama, temp_nama);
        list[j+1].gram = temp_gram;
        list[j+1].harga = temp_harga;
        strcpy(list[j+1].status, temp_status);
        list[j+1].harga_per_gram = temp_harga_per_gram;
    }
}

//==== Prosedur cari harga/berat
void cari_harga_per_gram(int n, daftar_kurma list[]){
    i = 0;
    j = n - 1;
    k = 0;
    found = 0;

    //menggunakan binary search
    while ((found == 0) && (i <= j))
    {
        k = (int)(i+j)/2;       //k = index tengah
        if (list[k].harga_per_gram == cari_harga)        //jika harga/gram pada list == harga per gram yang dicari
        {
            found = 1;      // indikator berubah dan perulangan berhenti
        }
        else                //jika harga/gram pada list tidak sama dengan harga per gram yang dicari
        {
            if (list[k].harga_per_gram < cari_harga)     //jika harga/gram pada list lebih besar harga pergram yang dicari
            {
                j = k - 1;          //j nya mundur ke nilai index k - 1
            }
            else
            {
                i = k + 1;          //i nya maju ke nilai index k + 1
            }
        }
    }

}

//==== Prosedur Print akhir ==== 
void output(int n, daftar_kurma list[]){
    //jika found = 0 atau tidak ada data yang dicari
    if(found == 0){
        printf("tidak ditemukan\n");
    }
    //jika ada
    if(found == 1)
    {
        printf("nama kurma: %s\n", list[k].nama);
        printf("berat: %d gram\n", list[k].gram);
        printf("harga: %d\n", list[k].harga);
        printf("harga per berat: %d\n", list[k].harga_per_gram);
        if (strcmp(list[k].status, "premium") == 0)     //jika status == premium
        {
            printf("status premium: ya\n");
        }
        if (strcmp(list[k].status, "standar") == 0)     //jika status = standar
        {
            printf("status premium: tidak\n");
        }
    }
}

/* 
3
kurma_turki 500 20000 standar
sukari_turki 100 20000 premium
sukari_arab 250 30000 premium 
*/