/*Saya Alief Muhammad Abdillah 2003623 mengerjakan Eval UTS dalam mata kuliah Algoritma dan Pemrograman 2
untuk keberkahan-Nya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/

//bagian mesin
#include "headeval1.h"

//===== Prosedur Input =====
void input(){
    int n;      //panjang array 1
    scanf("%d", &n);
    daftar mhswa1[n];       //deklarasi array 1
    //masukan array 1 (nama, nilai1, nilai2)
    for ( i = 0; i < n; i++)        
    {
        scanf("%s %d %d", mhswa1[i].nama, &mhswa1[i].nilai1, &mhswa1[i].nilai2);
    }
    
    int m;      //panjang array 2
    scanf("%d", &m);
    daftar mhswa2[m];       //deklarasi bungkusan arraya 2
    //proses masukan array 2 (nama nilai1, nilai2)
    for ( i = 0; i < m; i++)
    {
        scanf("%s %d %d", mhswa2[i].nama, &mhswa2[i].nilai1, &mhswa2[i].nilai2);
    }

    //pemanggilan prosedur sorting array 1 dan array 2
    sorting(n, mhswa1, 0, n-1);
    sorting(m, mhswa2, 0, m-1);

    //Proses Penggabungan array 1 dan 2
    daftar gabungan[n+m];       //deklarasi bungkusan untuk menampung gabungan array1 dan 2
    merge(n, m, mhswa1, mhswa2, gabungan);      //pemanggilan prosedur merge

    cetak_gabung(n, m, gabungan);               //pemanggilan prosedur cetak akhir
}

//==== Prosedur Sorting =====
void sorting(int n, daftar mhswa1[], int kiri, int kanan){
    /* //sorting menggunakan insertion sort
    char temp_nama[50];     //variabel sementara untuk array nama
    int temp_nilai1;        //variabel sementara untuk array nilai1
    int temp_nilai2;        //variabel sementara untuk array nilai2

    //sorting array 1 dan 2 dengan insertion
        for ( i = 1; i < n; i++)
        {
            //memasukan nama,nilai1, dan 2 ke temp
            strcpy(temp_nama, mhswa1[i].nama);
            temp_nilai1= mhswa1[i].nilai1;
            temp_nilai2= mhswa1[i].nilai2;
            j = i-1;
            while ((j >= 0) && (strcmp(temp_nama, mhswa1[j].nama) < 0))     //jika temp_nama abjadnya lebih rendah dari mhswa[j]
            {   
                //tukar posisi
                strcpy(mhswa1[j+1].nama, mhswa1[j].nama);
                mhswa1[j+1].nilai1 = mhswa1[j].nilai1;
                mhswa1[j+1].nilai2 = mhswa1[j].nilai2;
                j--;
            }
            //memasukan array 1 yang ada di temp ke mhswa[j+1]
            strcpy(mhswa1[j+1].nama, temp_nama);
            mhswa1[j+1].nilai1 = temp_nilai1;
            mhswa1[j+1].nilai2 = temp_nilai2;
        } */

    //quick
    i = kiri;
    j = kanan;
    char temp_nama[50];     //variabel sementara untuk array nama
    int temp_nilai1;        //variabel sementara untuk array nilai1
    int temp_nilai2;        //variabel sementara untuk array nilai2

    do
    {
        while ((strcmp(mhswa1[i].nama, mhswa1[kanan].nama)<0) && (i<=j))
        {
            i++;
        }
        while ((strcmp(mhswa1[j].nama, mhswa1[kiri].nama)>0) && (i<=j))
        {
            j--;
        }

        if (i<j)
        {
            strcpy(temp_nama, mhswa1[i].nama);
            strcpy(mhswa1[i].nama, mhswa1[j].nama);
            strcpy(mhswa1[j].nama, temp_nama);

            temp_nilai1 = mhswa1[i].nilai1;
            mhswa1[i].nilai1 = mhswa1[j].nilai1;
            mhswa1[j].nilai1 = temp_nilai1;

            temp_nilai2 = mhswa1[i].nilai2;
            mhswa1[i].nilai2 = mhswa1[j].nilai2;
            mhswa1[j].nilai2 = temp_nilai2;

            i++;
            j--;
        }
    } while (i < j);

    if ((kiri < j) && (j < kanan))
    {
        sorting(n, mhswa1, kiri, j);
    }
    if ((i < kanan) && (i > kiri))
    {
        sorting(n, mhswa1, i, kanan);
    }
    
}

//==== Prosedur Merge ====
void merge(int n, int m, daftar mhswa1[], daftar mhswa2[], daftar gabungan[]){
    i = 0, j = 0, k = 0, l = 0;

        while ((i < n) && (j < m))
        {
            if (strcmp(mhswa1[i].nama, mhswa2[j].nama) < 0)       //ascending jika nama mhswa1 abjadnya lebih renda dari abjda mhswa2
            {
                strcpy(gabungan[k].nama, mhswa1[i].nama);     //nama di array 1 masuk ke daftar gabungan
                gabungan[k].nilai1 = mhswa1[i].nilai1;          //nilai1 di array 1 masuk ke daftar gabungan
                gabungan[k].nilai2 = mhswa1[i].nilai2;          //nilai2 di array 1 masuk ke daftar gabungan
                i++;    
                k++;
            }
            else if (strcmp(mhswa2[j].nama, mhswa1[i].nama) < 0 )  //ascending jika nama mhswa2 abjadnya lebih renda dari abjda mhswa1
            {
                strcpy(gabungan[k].nama, mhswa2[j].nama);     //nama di array 2 masuk ke daftar gabungan
                gabungan[k].nilai1 = mhswa2[j].nilai1;          //nilai1 di array 2 masuk ke daftar gabungan
                gabungan[k].nilai2 = mhswa2[j].nilai2;          //nilai2 di array 2 masuk ke daftar gabungan
                j++;
                k++;
            }
            else                                   //jika sama
            {
                strcpy(gabungan[k].nama, mhswa1[i].nama);     //nama di array 1 masuk ke daftar gabungan
                gabungan[k].nilai1 = mhswa1[i].nilai1;          //nilai1 di array 1 masuk ke daftar gabungan
                gabungan[k].nilai2 = mhswa1[i].nilai2;          //nilai2 di array 1 masuk ke daftar gabungan
                i++;    
                k++;

                strcpy(gabungan[k].nama, mhswa2[j].nama);     //nama di array 2 masuk ke daftar gabungan
                gabungan[k].nilai1 = mhswa2[j].nilai1;          //nilai1 di array 2 masuk ke daftar gabungan
                gabungan[k].nilai2 = mhswa2[j].nilai2;          //nilai2 di array 2 masuk ke daftar gabungan
                j++;
                k++;
            }
        }

        if (i < n)                              //jika masih ada sisa array 1
        {
            for ( l = i; l < n; l++)
            {
                strcpy(gabungan[k].nama, mhswa1[l].nama);     //nama di array 1 masuk ke daftar gabungan
                gabungan[k].nilai1 = mhswa1[l].nilai1;          //nilai1 di array 1 masuk ke daftar gabungan
                gabungan[k].nilai2 = mhswa1[l].nilai2;          //nilai2 di array 1 masuk ke daftar gabungan
                k++;
            }
        }

        if (j < m)                              //jika masih ada sisa di array 2
        {
            for ( l = j; l < m; l++)
            {
                strcpy(gabungan[k].nama, mhswa2[l].nama);     //nama di array 1 masuk ke daftar gabungan
                gabungan[k].nilai1 = mhswa2[l].nilai1;          //nilai1 di array 1 masuk ke daftar gabungan
                gabungan[k].nilai2 = mhswa2[l].nilai2;          //nilai2 di array 1 masuk ke daftar gabungan
                k++;
            }
        }
}

//==== Prosedur Cetak Akhir ====
void cetak_gabung(int n, int m, daftar gabungan[]){
    //proses cetak semua array gabungan
    printf("================\n");
    for ( i = 0; i < n+m; i++)
    {
        printf("%s %d %d\n", gabungan[i].nama, gabungan[i].nilai1, gabungan[i].nilai2);
    }
    //proses cetak setengah array awal
    printf("================\n");
    for (i = 0; i < (n+m)/2; i++)
    {
        printf("%s %d %d\n", gabungan[i].nama, gabungan[i].nilai1, gabungan[i].nilai2);
    }
    //proses cetak setengah array akhir
    printf("================\n");
    for (i = (n+m)/2; i < n+m; i++)
    {
        printf("%s %d %d\n", gabungan[i].nama, gabungan[i].nilai1, gabungan[i].nilai2);
    }
}

/* 
2
bayu 90 91
arif 23 79
4
fauzan 80 88
gita 77 100
rusman 89 80
ali 69 79
 */
