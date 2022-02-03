/*Saya Alief Muhammad Abdillah 2003623 mengerjakan TP6 dalam mata kuliah Algoritma dan Pemrograman 2
untuk keberkahan-Nya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/

//bagian mesin
#include "headtp6.h"

void input(){
    //masukan array1
    int n;                      //panjang array 1
    scanf("%d", &n);            //masukan panjang array 1
    arr1 daftar1[n];            //deklarasi bungkusan array 1
    for ( i = 0; i < n; i++)                //perulangan masukan dari array 1
    {
        scanf("%f", &daftar1[i].durasi);
        scanf("%s", daftar1[i].judul);
    }

    //masukan array2
    int m;                      //variabel panjang array 2
    scanf("%d", &m);            //masukan panjang array 2
    arr1 daftar2[m];            //deklarasi bungkusan array 2
    for ( i = 0; i < m; i++)                //perulangan masukan dari array 2
    {
        scanf("%f", &daftar2[i].durasi);
        scanf("%s", daftar2[i].judul);
    }

    //masukan array3
    int o;                      //variabel panjanhg array 3
    scanf("%d", &o);            //masukan panjang array 3
    arr1 daftar3[n];            //deklarasi bungkusan dari array 3
    for ( i = 0; i < o; i++)                //perulangan masukan dari array 3
    {
        scanf("%f", &daftar3[i].durasi);
        scanf("%s", daftar3[i].judul);
    }

    scanf(" %c", &metode);      //masukan metode (i, s, b, q)
    scanf(" %c", &urutan);      //masukan urutan (a, d)

    if (metode =='i')               //jika metode == i/insertion
    {
        insertion(n, daftar1);      //prosedur insertion array1
        insertion(m, daftar2);      //prosedur insertion array 2
        insertion(o, daftar3);      //prosedur insertion array 3
    }
    if (metode =='s')               //jika metode == s/selection
    {
        selection(n, daftar1);      //prosdur selection array  1
        selection(m, daftar2);      //prosdur selection array  2
        selection(o, daftar3);      //prosdur selection array  3
    }
    if (metode =='b')               //jika metode  == b/bubblesort
    {
        bubble(n, daftar1);         //prosdur bubblesort array  1
        bubble(m, daftar2);         //prosdur bubblesort array  2
        bubble(o, daftar3);         //prosdur bubblesort array  3
    }
    if (metode =='q')               //jika metode == q/quciksort
    {
        quick(n, daftar1, 0, n-1);  //prosdur quicksort array  1
        quick(m, daftar2, 0, m-1);  //prosdur quicksort array  2
        quick(o, daftar3, 0, o-1);  //prosdur quicksort array  3
    }

    arr1 daftar_temp[n+m];          //deklarasi bungkusan untuk menyimpan gabungan array 1 dan array 2
    arr1 daftar_hasil[n+m+o];       //deklarasi bungkusan untuk menyimpan gabungan dari daftar temp(gabunfan 1 & 2) dengan array 3

    merge(n, m, daftar1, daftar2, daftar_temp);         //pemanggilan prosedur penggabungan array  1 dan 2
    merge(n+m, o, daftar_temp, daftar3, daftar_hasil);  //pemanggilan prosedur penggabungan daftar temp(gabungan 1 & 2) dan array 3
    
    output(n, m, o, daftar_hasil, daftar1);             //pemanggilan prosedur output
}

//==== Prosedur Insertion =====
void insertion(int n, arr1 daftar1[]){
    char ins_judul[50];     //penampung sementara judul saat pertykaraan
    float ins_durasi;       //penampung sementara durasi saat pertukaran

    //jika urutan == a/ascending
    if (urutan == 'a')
    {
        //sorting array 1 dengan insertion
        for ( i = 1; i < n; i++)
        {
            strcpy(ins_judul, daftar1[i].judul);
            ins_durasi = daftar1[i].durasi;
            j = i-1;
            while ((j >= 0) && (ins_durasi < daftar1[j].durasi))
            {
                strcpy(daftar1[j+1].judul, daftar1[j].judul);
                daftar1[j+1].durasi = daftar1[j].durasi;
                j--;
            }
            strcpy(daftar1[j+1].judul, ins_judul);
            daftar1[j+1].durasi = ins_durasi;
        }
    }
    //jika urutan == d/descending 
    if (urutan =='d')
    {
        //sorting array dengan insertion
        for ( i = 1; i < n; i++)
        {
            strcpy(ins_judul, daftar1[i].judul);
            ins_durasi = daftar1[i].durasi;
            j = i-1;
            while ((j >= 0) && (ins_durasi > daftar1[j].durasi))
            {
                strcpy(daftar1[j+1].judul, daftar1[j].judul);
                daftar1[j+1].durasi = daftar1[j].durasi;
                j--;
            }
            strcpy(daftar1[j+1].judul, ins_judul);
            daftar1[j+1].durasi = ins_durasi;
        }
    }
}

//==== Prosedur Selection =====
void selection(int n, arr1 daftar1[]){
    char sel_judul[50];     //penampung sementara judul saat pertukraan
    float sel_durasi;       //penampung sementara durasi saat pertukaran
    int min;                //menampung indeks min/kecil

    //jika urutan = asencding
    if (urutan == 'a')
    {   
        //sorting array dengan metode selection
        for ( i = 0; i < n-1; i++)
        {
            min = i;
            for ( j = i+1; j < n; j++)
            {
                if (daftar1[min].durasi > daftar1[j].durasi)
                {
                    min = j;
                }
            }
            //pertukaran judul
            strcpy(sel_judul, daftar1[i].judul);
            strcpy(daftar1[i].judul, daftar1[min].judul);
            strcpy(daftar1[min].judul, sel_judul);

            //pertukaran durasi
            sel_durasi = daftar1[i].durasi;
            daftar1[i].durasi = daftar1[min].durasi;
            daftar1[min].durasi = sel_durasi;
        }
    }
    //jika urutan == deseding
    if (urutan == 'd')
    {
        //sorting dengan menggunakan selection sort
        for ( i = 0; i < n-1; i++)
        {
            min = i;
            for ( j = i+1; j < n; j++)
            {
                if (daftar1[min].durasi < daftar1[j].durasi)
                {
                    min = j;
                }
            }
            //pertukaran judul
            strcpy(sel_judul, daftar1[i].judul);
            strcpy(daftar1[i].judul, daftar1[min].judul);
            strcpy(daftar1[min].judul, sel_judul);

            //pertukaran durasi
            sel_durasi = daftar1[i].durasi;
            daftar1[i].durasi = daftar1[min].durasi;
            daftar1[min].durasi = sel_durasi;
        }
    } 
}

//==== Prosedur Bubble =====
void bubble(int n, arr1 daftar1[]){
    int tanda = 0;          //untuk penanda perulangan
    char bub_judul[50];     //penampung sementara saat pertukaraan
    float bub_durasi;       //penampung sementara durasi saat pertukaraan

    //jika ascnding
    if (urutan =='a')
    {
        do  //perulangan selana tanda = 1
        {
            tanda = 0;
            for ( i = 0; i < n-1; i++)
            {
                if (daftar1[i].durasi > daftar1[i+1].durasi)
                {
                    //tukar judu;
                    strcpy(bub_judul, daftar1[i].judul);
                    strcpy(daftar1[i].judul, daftar1[i+1].judul);
                    strcpy(daftar1[i+1].judul, bub_judul);
                    
                    //tukar durasi
                    bub_durasi = daftar1[i].durasi;
                    daftar1[i].durasi = daftar1[i+1].durasi;
                    daftar1[i+1].durasi = bub_durasi;
                    
                    tanda = 1;
                }
            }
        }while (tanda == 1);
    }
    //jika descending
    if (urutan =='d')
    {
        do      //perulangan selama tanda  = 1
        {
            tanda = 0;
            for ( i = 0; i < n-1; i++)
            {
                if (daftar1[i].durasi < daftar1[i+1].durasi)
                {
                    //tukar judul
                    strcpy(bub_judul, daftar1[i].judul);
                    strcpy(daftar1[i].judul, daftar1[i+1].judul);
                    strcpy(daftar1[i+1].judul, bub_judul);

                    //tukar durasi
                    bub_durasi = daftar1[i].durasi;
                    daftar1[i].durasi = daftar1[i+1].durasi;
                    daftar1[i+1].durasi = bub_durasi;

                    tanda = 1;
                }
            }
        }while (tanda == 1);
    }   
}

//==== Prosedur Quick =====
void quick(int n, arr1 daftar1[], int kiri, int kanan){
    i = kiri;           //untuk batas kiri
    j = kanan;          //batasa kanan
    char qui_judul[50];     //penampaung sementara saat pertukaraan judul
    float qui_durasi;       //penampung semenetara saat pertukaraan durasi

    //jika ascending
    if (urutan == 'a')
    {
        do
        {
            while ((daftar1[i].durasi < daftar1[kanan].durasi) && (i<=j))
            {
                i++;
            }
            while ((daftar1[j].durasi > daftar1[kiri].durasi) && (i<=j))
            {
                j--;
            }
            
            if (i < j)
            {
                //tukar judul
                strcpy(qui_judul, daftar1[i].judul);
                strcpy(daftar1[i].judul, daftar1[j].judul);
                strcpy(daftar1[j].judul, qui_judul);

                //tukar nama
                qui_durasi = daftar1[i].durasi;
                daftar1[i].durasi = daftar1[j].durasi;
                daftar1[j].durasi = qui_durasi;

                i++;
                j--;
            }
        } while (i<j);
        /*
            jika i sudah bertemu j atau dalam posisi yang sama/lebih
            melakukan proses rekursif yang membagi array menjadi beberapa bagian
        */
        if ((kiri < j) && (j < kanan))
        {
            quick(n, daftar1, kiri, j);           //pembagian dari indeks paling kiri sampai ke pertemuan i dan j
        }
        if ((i < kanan) && (i > kiri))
        {
            quick(n, daftar1, i, kanan);         //pembagian dari pertemuan i dan j sampai ke indek paling kanan
        }
    }

    //jika descending
    if (urutan == 'd')
    {
        do
        {
            while ((daftar1[i].durasi > daftar1[kanan].durasi) && (i<=j))
            {
                i++;
            }
            while ((daftar1[j].durasi < daftar1[kiri].durasi) && (i<=j))
            {
                j--;
            }
            
            if (i < j)
            {
                //tukar judul
                strcpy(qui_judul, daftar1[i].judul);
                strcpy(daftar1[i].judul, daftar1[j].judul);
                strcpy(daftar1[j].judul, qui_judul);

                //tukar nama
                qui_durasi = daftar1[i].durasi;
                daftar1[i].durasi = daftar1[j].durasi;
                daftar1[j].durasi = qui_durasi;

                i++;
                j--;
            }
        } while (i<j);
        /*
            jika i sudah bertemu j atau dalam posisi yang sama/lebih
            melakukan proses rekursif yang membagi array menjadi beberapa bagian
        */

        if ((kiri < j) && (j < kanan))
        {
            quick(n, daftar1, kiri, j);     //pembagian dari indeks paling kiri sampai ke pertemuan i dan j
        }
        if ((i < kanan) && (i > kiri))
        {
            quick(n, daftar1, i, kanan);    //pembagian dari pertemuan i dan j sampai ke indek paling kanan
        }
    }
}

//==== Prosedur Merge =====
void merge(int n, int m, arr1 daftar1[], arr1 daftar2[], arr1 daftar_temp[]){
    i = 0, j = 0, k = 0, l = 0;

    //jika urutan ascending
    if (urutan == 'a')
    {
        while ((i < n) && (j < m))
        {
            if (daftar1[i].durasi < daftar2[j].durasi)       //ascending jika durasi 1 < durasi 2
            {
                strcpy(daftar_temp[k].judul, daftar1[i].judul);     //judul di array 1 masuk ke daftar temp/hasil
                daftar_temp[k].durasi = daftar1[i].durasi;          //durasi di array 1 masuk ke daftar temp/hasil
                i++;    
                k++;
            }
            else if (daftar2[j].durasi < daftar1[i].durasi )  //ascending jika durasi 2 < durasi 1
            {
                strcpy(daftar_temp[k].judul, daftar2[j].judul);
                daftar_temp[k].durasi = daftar2[j].durasi;
                j++;
                k++;
            }
            else                                   //jika sama
            {
                strcpy(daftar_temp[k].judul, daftar1[i].judul);
                daftar_temp[k].durasi = daftar1[i].durasi;
                i++;
                k++;

                strcpy(daftar_temp[k].judul, daftar2[j].judul);
                daftar_temp[k].durasi = daftar2[j].durasi;
                j++;
                k++;
            }
        }

        if (i < n)                              //jika masih ada sisa array 1
        {
            for ( l = i; l < n; l++)
            {
                strcpy(daftar_temp[k].judul, daftar1[l].judul);
                daftar_temp[k].durasi = daftar1[l].durasi;
                k++;
            }
        }

        if (j < m)                              //jika masih ada sisa di array 2
        {
            for ( l = j; l < m; l++)
            {
                strcpy(daftar_temp[k].judul, daftar2[l].judul);
                daftar_temp[k].durasi = daftar2[l].durasi;
                k++;
            }
        }
    }
    //jika urutan ascending
    if (urutan == 'd')
    {
        while ((i < n) && (j < m))
        {
            if (daftar1[i].durasi > daftar2[j].durasi)       //descending jika arr1 > dari arr2
            {
                strcpy(daftar_temp[k].judul, daftar1[i].judul);
                daftar_temp[k].durasi = daftar1[i].durasi;
                i++;
                k++;
            }
            else if (daftar2[j].durasi > daftar1[i].durasi )  //descending jika arr2 > arr1
            {
                strcpy(daftar_temp[k].judul, daftar2[j].judul);
                daftar_temp[k].durasi = daftar2[j].durasi;
                j++;
                k++;
            }
            else                                   //jika sama
            {
                strcpy(daftar_temp[k].judul, daftar1[i].judul);
                daftar_temp[k].durasi = daftar1[i].durasi;
                i++;
                k++;

                strcpy(daftar_temp[k].judul, daftar2[j].judul);
                daftar_temp[k].durasi = daftar2[j].durasi;
                j++;
                k++;

            }
        }

        if (i < n)                              //jika masih ada sisa array 1
        {
            for ( l = i; l < n; l++)
            {
                strcpy(daftar_temp[k].judul, daftar1[l].judul);
                daftar_temp[k].durasi = daftar1[l].durasi;
                k++;
            }
        }

        if (j < m)                              //jika masih ada sisa di array 2
        {
            for ( l = j; l < m; l++)
            {
                strcpy(daftar_temp[k].judul, daftar2[l].judul);
                daftar_temp[k].durasi = daftar2[l].durasi;
                k++;
            }
        }
    }
}

//==== Prosedur Cetak Hasil Akhir ====
void output(int n, int m, int o, arr1 daftar_hasil[], arr1 daftar1[]){
    int sign = 0;           //variabel tanda 

    printf("Daftar Lagu Keluarga:\n");
    for ( i = 0; i < n+m+o; i++)                    //print outpur daftar hasil sepanjang n+m+o
    {
        printf("%.2f ", daftar_hasil[i].durasi);
        printf("%s\n", daftar_hasil[i].judul);
    }
    printf("\n");

    printf("Lagunya Ibnu:\n");
    for ( i = 0; i < n; i++)
    {
        if((n+m+o) % 2 != 0){
            for ( j = 0; j <= (n+m+o)/2; j++)
            {
                if (strcmp(daftar_hasil[j].judul, daftar1[i].judul) == 0)
                {
                    printf("%s\n", daftar_hasil[j].judul);
                    sign++;
                }
            }
        }
        else
        {
            for ( j = 0; j < (n+m+o)/2; j++)
            {
                if (strcmp(daftar_hasil[j].judul, daftar1[i].judul) == 0)
                {
                    printf("%s\n", daftar_hasil[j].judul);
                    sign++;
                }
            }
        }
    }
    if (sign == 0)
    {
        printf("Tidak memutar lagu Ibnu\n");
    }
}

/* 
3
3.30 terseyumlah
3.20 cinta
2.70 bertaut
2
4.10 pelangi
5.30 balonku
2
4.50 kenangan
7.60 mungkin
i d
*/

/* 
3
5.50 cuek
5.10 melukissenja
6.10 garisterdepan
3
6.20 kasihibu
4.10 pelangi
3.40 balonku
3
5.20 mungkin
4.10 bintangkehidupan
3.40 kemesraan
q a
 */

/* 
1
2.25 ddd
1
2.20 bbb
2
2.00 ccc
2.25 xxx
q a
 */
 