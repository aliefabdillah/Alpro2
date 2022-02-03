/*Saya Alief Muhammad Abdillah 2003623 mengerjakan UTS dalam mata kuliah Algoritma dan Pemrograman 2
untuk keberkahan-Nya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/
#include "headuts.h"

//bagian mesin
void input(){
    //masukan metode
    scanf("%s", metode);

    //masukan array1
    scanf("%s", negara1);
    int n;                      //panjang array 1
    scanf("%d", &n);            //masukan panjang array 1
    arr1 daftar1[n];            //deklarasi bungkusan array 1
    for ( i = 0; i < n; i++)                //perulangan masukan dari array 1
    {   
        //masukna nama,kalori,berat, harga array 1
        scanf("%s", daftar1[i].nama);
        scanf("%d", &daftar1[i].kalori);
        scanf("%d", &daftar1[i].berat);
        scanf("%d", &daftar1[i].harga);
        daftar1[i].kal_per_gram = (float)daftar1[i].kalori/daftar1[i].berat;    //konversi kalori/gram dalam float
    }

    //masukan array2
    scanf("%s", negara2);
    int m;                      //variabel panjang array 2
    scanf("%d", &m);            //masukan panjang array 2
    arr1 daftar2[m];            //deklarasi bungkusan array 2
    for ( i = 0; i < m; i++)                //perulangan masukan dari array 2
    {
        //masukna nama,kalori,berat, harga array 2
        scanf("%s", daftar2[i].nama);
        scanf("%d", &daftar2[i].kalori);
        scanf("%d", &daftar2[i].berat);
        scanf("%d", &daftar2[i].harga);
        daftar2[i].kal_per_gram = (float)daftar2[i].kalori/daftar2[i].berat;    //konversi kalori/gram dalam float
    }

    //masukan array3
    scanf("%s", negara3);
    int o;                      //variabel panjanhg array 3
    scanf("%d", &o);            //masukan panjang array 3
    arr1 daftar3[n];            //deklarasi bungkusan dari array 3
    for ( i = 0; i < o; i++)                //perulangan masukan dari array 3
    {
        //masukna nama,kalori,berat, harga array 3
        scanf("%s", daftar3[i].nama);
        scanf("%d", &daftar3[i].kalori);
        scanf("%d", &daftar3[i].berat);
        scanf("%d", &daftar3[i].harga);
        daftar3[i].kal_per_gram = (float)daftar3[i].kalori/daftar3[i].berat;    //konversi kalori/gram dalam float
    }

    //jika masukan metode 'is'/insertion maka memakai metode insertion sort
    if (strcmp(metode, "is") == 0)
    {
        insertion(n, daftar1);
        insertion(m, daftar2);
        insertion(o, daftar3);
    }
    //jika masukan metode 'is'/selection maka memakai metode selection sort
    if (strcmp(metode, "ss") == 0)
    {
        selection(n, daftar1);
        selection(m, daftar2);
        selection(o, daftar3);
    }
    //jika masukan metode 'is'/bubble maka memakai metode bubble sort
    if (strcmp(metode, "bs") == 0)
    {
        bubble(n, daftar1);
        bubble(m, daftar2);
        bubble(o, daftar3);
    }
    //jika masukan metode 'is'/quick sort maka memakai metode quicksort
    if (strcmp(metode, "qs") == 0)
    {
        quick(n, daftar1, 0, n-1);
        quick(m, daftar2, 0, m-1);
        quick(o, daftar3, 0, o-1);
    }

    arr1 daftar_temp[n+m];      //variabel penampung sementara merge array 1 dan 2
    arr1 daftar_hasil[n+m+o];   //variabel penampung merge array 3 dan daftar temp(arr1 dan arr2)

    merge(n, m, daftar1, daftar2, daftar_temp);             //pemanggilan prosedur merge array 1 dan 2
    merge(n+m, o, daftar_temp, daftar3, daftar_hasil);      //pemanggilan prosdur merge array 3 dan daftar temp

    output_per_negara(n, m, o, daftar1, daftar2, daftar3);          //pemanggilan prosedur output pernegara
    output_semua(n, m, o, daftar_hasil, daftar1, daftar2, daftar3); //pemanggilan output semua

}

void insertion(int n, arr1 daftar1[]){
    char ins_nama[50];      //penampung sementara saat pertukaraan nama
    int ins_kalori;         //penampung sementara saat pertukaraan kalori
    int ins_berat;          //penampung sementara saat pertukaraan berat
    int ins_harga;          //harga
    float ins_kal_per_gram;     //penampung sementara saat pertukaraan kal/gram

    //sorting array dengan insertion
        for ( i = 1; i < n; i++)
        {
            //memasukan array ke [i] ke penampung sementara
            strcpy(ins_nama, daftar1[i].nama);
            ins_kalori = daftar1[i].kalori;
            ins_berat = daftar1[i].berat;
            ins_harga = daftar1[i].harga;
            ins_kal_per_gram = daftar1[i].kal_per_gram;
            j = i-1;
            while ((j >= 0) && (ins_kal_per_gram > daftar1[j].kal_per_gram))
            {
                //proses pertukaran dari array [j+1] dengan array [j]
                strcpy(daftar1[j+1].nama, daftar1[j].nama);
                daftar1[j+1].kalori = daftar1[j].kalori;
                daftar1[j+1].berat = daftar1[j].berat;
                daftar1[j+1].harga = daftar1[j].harga;
                daftar1[j+1].kal_per_gram = daftar1[j].kal_per_gram;
                j--;
            }
            //arrya pada penampung dimasukan ke array [j+1]
            strcpy(daftar1[j+1].nama, ins_nama);
            daftar1[j+1].kalori = ins_kalori;
            daftar1[j+1].berat = ins_berat;
            daftar1[j+1].harga = ins_harga;
            daftar1[j+1].kal_per_gram = ins_kal_per_gram;
        }
}

void selection(int n, arr1 daftar1[]){
    int min;            //variabel penanda indeks min
    char sel_nama[50];  //penampung sementara saat pertukaraan nama
    int sel_kalori;     //penampung sementara saat pertukaraan kalort
    int sel_berat;      //penampung sementara saat pertukaraan berat
    int sel_harga;      //penampung sementara saat pertukaraan harga
    float sel_kal_per_gram; //penampung sementara saat pertukaraan kal/gram

    //sorting dengan menggunakan selection sort
        for ( i = 0; i < n-1; i++)
        {
            min = i;
            for ( j = i+1; j < n; j++)
            {
                if (daftar1[min].kal_per_gram < daftar1[j].kal_per_gram)
                {
                    min = j;
                }
            }
            //pertukaran nama makanan
            strcpy(sel_nama, daftar1[i].nama);
            strcpy(daftar1[i].nama, daftar1[min].nama);
            strcpy(daftar1[min].nama, sel_nama);

            //pertukaran kalori
            sel_kalori = daftar1[i].kalori;
            daftar1[i].kalori = daftar1[min].kalori;
            daftar1[min].kalori = sel_kalori;

            //pertukaran berat
            sel_berat = daftar1[i].berat;
            daftar1[i].berat = daftar1[min].berat;
            daftar1[min].berat = sel_berat;

            //pertukaran harga
            sel_harga = daftar1[i].harga;
            daftar1[i].harga = daftar1[min].harga;
            daftar1[min].harga = sel_harga;

            //pertukaran kal/gram
            sel_kal_per_gram = daftar1[i].kal_per_gram;
            daftar1[i].kal_per_gram = daftar1[min].kal_per_gram;
            daftar1[min].kal_per_gram = sel_kal_per_gram;
        }
}

void bubble(int n, arr1 daftar1[]){
    int tanda = 0;
    char bub_nama[50];      //penampung sementara saat pertukaraan nama
    int bub_kalori;         //penampung sementara saat pertukaraan kalori
    int bub_berat;          //penampung sementara saat pertukaraan berat
    int bub_harga;          //penampung sementara saat pertukaraan harga
    float bub_kal_per_gram;     //penampung sementara saat pertukaraan kal/gram

    do      //perulangan selama tanda  = 1
        {
            tanda = 0;
            for ( i = 0; i < n-1; i++)
            {
                if (daftar1[i].kal_per_gram < daftar1[i+1].kal_per_gram)
                {
                    //tukar nama
                    strcpy(bub_nama, daftar1[i].nama);
                    strcpy(daftar1[i].nama, daftar1[i+1].nama);
                    strcpy(daftar1[i+1].nama, bub_nama);

                    //tukar kalori
                    bub_kalori = daftar1[i].kalori;
                    daftar1[i].kalori = daftar1[i+1].kalori;
                    daftar1[i+1].kalori = bub_kalori;

                    //tukar berat
                    bub_berat = daftar1[i].berat;
                    daftar1[i].berat = daftar1[i+1].berat;
                    daftar1[i+1].berat = bub_berat;

                    //tukar harga
                    bub_harga = daftar1[i].harga;
                    daftar1[i].harga = daftar1[i+1].harga;
                    daftar1[i+1].harga = bub_harga;

                    //tukar kalori/gram
                    bub_kal_per_gram = daftar1[i].kal_per_gram;
                    daftar1[i].kal_per_gram = daftar1[i+1].kal_per_gram;
                    daftar1[i+1].kal_per_gram = bub_kal_per_gram;

                    tanda = 1;
                }
            }
        }while (tanda == 1);
}

void quick(int n, arr1 daftar1[], int kiri, int kanan){
    i = kiri;       //indeks untuk pivot kiri
    j = kanan;      //indeks untuk pivot kanan
    char qui_nama[50];      //penampung sementara saat pertukaraan nama
    int qui_kalori;         //penampung sementara saat pertukaraan kalori
    int qui_berat;          //penampung sementara saat pertukaraan beart
    int qui_harga;          //penampung sementara saat pertukaraan harga
    float qui_kal_per_gram;     //penampung sementara saat pertukaraan kal/gram

    do
        {
            //cek secara descending
            while ((daftar1[i].kal_per_gram > daftar1[kanan].kal_per_gram) && (i<=j))
            {
                i++;
            }
            while ((daftar1[j].kal_per_gram < daftar1[kiri].kal_per_gram) && (i<=j))
            {
                j--;
            }
            
            if (i < j)
            {
                //tukar nama
                strcpy(qui_nama, daftar1[i].nama);
                strcpy(daftar1[i].nama, daftar1[j].nama);
                strcpy(daftar1[j].nama, qui_nama);

                //tukar kalori 
                qui_kalori = daftar1[i].kalori;
                daftar1[i].kalori = daftar1[j].kalori;
                daftar1[j].kalori = qui_kalori;
                
                //tukar berat
                qui_berat = daftar1[i].berat;
                daftar1[i].berat = daftar1[j].berat;
                daftar1[j].berat = qui_berat;
                
                //tukar kalori 
                qui_harga = daftar1[i].harga;
                daftar1[i].harga = daftar1[j].harga;
                daftar1[j].harga = qui_harga;
                
                //tukar kalori 
                qui_kal_per_gram = daftar1[i].kal_per_gram;
                daftar1[i].kal_per_gram = daftar1[j].kal_per_gram;
                daftar1[j].kal_per_gram = qui_kal_per_gram;

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

void merge(int n, int m, arr1 daftar1[], arr1 daftar2[], arr1 daftar_temp[]){
    i = 0, j = 0, k = 0, l = 0;

    while ((i < n) && (j < m))
    {
        if (daftar1[i].kal_per_gram > daftar2[j].kal_per_gram)       //descending jika arr1 > dari arr2
        {
            //array 1 di masukan ke array temp
            strcpy(daftar_temp[k].nama, daftar1[i].nama);
            daftar_temp[k].kalori = daftar1[i].kalori;
            daftar_temp[k].berat = daftar1[i].berat;
            daftar_temp[k].harga = daftar1[i].harga;
            daftar_temp[k].kal_per_gram = daftar1[i].kal_per_gram;
            i++;
            k++;
        }
        else if (daftar2[j].kal_per_gram > daftar1[i].kal_per_gram )  //descending jika arr2 > arr1
        {
            //array 2 dimasukan ke array temp
            strcpy(daftar_temp[k].nama, daftar2[j].nama);
            daftar_temp[k].kalori = daftar2[j].kalori;
            daftar_temp[k].berat = daftar2[j].berat;
            daftar_temp[k].harga = daftar2[j].harga;
            daftar_temp[k].kal_per_gram = daftar2[j].kal_per_gram;
            j++;
            k++;
        }
        else                                   //jika sama
        {
            //array 1 dimasukan ke array temp
            strcpy(daftar_temp[k].nama, daftar1[i].nama);
            daftar_temp[k].kalori = daftar1[i].kalori;
            daftar_temp[k].berat = daftar1[i].berat;
            daftar_temp[k].harga = daftar1[i].harga;
            daftar_temp[k].kal_per_gram = daftar1[i].kal_per_gram;
            i++;
            k++;

            //array 2 dimasukan ke array temp
            strcpy(daftar_temp[k].nama, daftar2[j].nama);
            daftar_temp[k].kalori = daftar2[j].kalori;
            daftar_temp[k].berat = daftar2[j].berat;
            daftar_temp[k].harga = daftar2[j].harga;
            daftar_temp[k].kal_per_gram = daftar2[j].kal_per_gram;
            j++;
            k++;

        }
    }

    if (i < n)                              //jika masih ada sisa array 1
    {
        for ( l = i; l < n; l++)
        {
            strcpy(daftar_temp[k].nama, daftar1[l].nama);
            daftar_temp[k].kalori = daftar1[l].kalori;
            daftar_temp[k].berat = daftar1[l].berat;
            daftar_temp[k].harga = daftar1[l].harga;
            daftar_temp[k].kal_per_gram = daftar1[l].kal_per_gram;
            k++;
        }
    }

    if (j < m)                              //jika masih ada sisa di array 2
    {
        for ( l = j; l < m; l++)
        {
            strcpy(daftar_temp[k].nama, daftar2[l].nama);
            daftar_temp[k].kalori = daftar2[l].kalori;
            daftar_temp[k].berat = daftar2[l].berat;
            daftar_temp[k].harga = daftar2[l].harga;
            daftar_temp[k].kal_per_gram = daftar2[l].kal_per_gram;
            k++;
        }
    }    
}

void output_per_negara(int n, int m, int o, arr1 daftar1[], arr1 daftar2[], arr1 daftar3[]){
    //proses mengubah kal/gram yang desimal ke bentuk bilanga  bulat pada array 1
    int bulat1[n];
    for (i = 0; i < n; i++)
    {
        bulat1[i] = daftar1[i].kalori/daftar1[i].berat;
    }

    //proses mengubah kal/gram yang desimal ke bentuk bilanga  bulat pada array 2
    int bulat2[m];
    for (i = 0; i < m; i++)
    {
        bulat2[i] = daftar2[i].kalori/daftar2[i].berat;
    }

    //proses mengubah kal/gram yang desimal ke bentuk bilanga  bulat pada array 3
    int bulat3[o];
    for (i = 0; i < o; i++)
    {
        bulat3[i] = daftar3[i].kalori/daftar3[i].berat;
    }
    
    printf("Per Negara:\n");
    printf("%s:\n", negara1);
    for ( i = 0; i < n; i++)
    {
        printf("- %s %d %d %d - ", daftar1[i].nama, daftar1[i].kalori, daftar1[i].berat, daftar1[i].harga);
        if (daftar1[i].kal_per_gram - bulat1[i] != 0)       //jika kal/gram desimal - kal/gram bil.bulat != 0 maka print 2 angka di belakang koma
        {
            printf("%.2f\n", daftar1[i].kal_per_gram);
        }
        else                            //jika tidak maka print bilangan bulatnya
        {   
            printf("%d\n", bulat1[i]);  
        }

    }
    printf("\n");

    printf("%s:\n", negara2);
    for ( i = 0; i < m; i++)
    {
        printf("- %s %d %d %d - ", daftar2[i].nama, daftar2[i].kalori, daftar2[i].berat, daftar2[i].harga);
        if (daftar2[i].kal_per_gram - bulat2[i] != 0)       //jika kal/gram desimal - kal/gram bil.bulat != 0 maka print 2 angka di belakang koma
        {
            printf("%.2f\n", daftar2[i].kal_per_gram);
        }
        else
        {
            printf("%d\n", bulat2[i]);      //jika tidak maka print bilangan bulatnya
        }
    }
    printf("\n");

    printf("%s:\n", negara3);
    for ( i = 0; i < o; i++)
    {
        printf("- %s %d %d %d - ", daftar3[i].nama, daftar3[i].kalori, daftar3[i].berat, daftar3[i].harga);
        if (daftar3[i].kal_per_gram - bulat3[i] != 0)       //jika kal/gram desimal - kal/gram bil.bulat != 0 maka print 2 angka di belakang koma
        {   
            printf("%.2f\n", daftar3[i].kal_per_gram);
        }
        else                                //jika tidak maka print bilangan bulatnya
        {
            printf("%d\n", bulat3[i]);
        }
    }
    printf("\n");
}

void output_semua(int n, int m, int o, arr1 daftar_hasil[], arr1 daftar1[], arr1 daftar2[], arr1 daftar3[]){
    printf("Semua:\n");
    i=0;
    j=0;
    k=0;

    //proses mengubah kal/gram di array hasil dari desimal ke bil bulat
    int bulat[n+m+o];
    for ( l = 0; l < n+m+o; l++)
    {
        bulat[l] = daftar_hasil[l].kalori/daftar_hasil[l].berat;
    }

    for ( l = 0; l < n+m+o; l++)
    {
            //jika nama pada array hasil sama dengan nama makanan pada array 1 maka di awal ditambah negara asal makanan array 1
                if (strcmp(daftar_hasil[l].nama, daftar1[i].nama) == 0)
                {
                    printf("- %s %s %d %d %d - ", negara1, daftar_hasil[l].nama, daftar_hasil[l].kalori, daftar_hasil[l].berat, daftar_hasil[l].harga);
                    i++;
                    if (daftar_hasil[l].kal_per_gram - bulat[l] != 0)       //jika kal/gram desimal-kal/gram bil.bulat != 0 print 2 angka dibelakamg koma
                    {
                        printf("%.2f\n", daftar_hasil[l].kal_per_gram);
                    }
                    else
                    {
                        printf("%d\n", bulat[l]);       //jika tidak maka print bilangan bulatnya
                    }
                }
            //jika nama pada array hasil sama dengan nama makanan pada array 2 maka di awal ditambah negara asal makanan array 2
                if (strcmp(daftar_hasil[l].nama, daftar2[j].nama) == 0)
                {
                    printf("- %s %s %d %d %d - ", negara2, daftar_hasil[l].nama, daftar_hasil[l].kalori, daftar_hasil[l].berat, daftar_hasil[l].harga);
                    j++;
                    if (daftar_hasil[l].kal_per_gram - bulat[l] != 0)       //jika kal/gram desimal-kal/gram bil.bulat != 0 print 2 angka dibelakamg koma
                    {
                        printf("%.2f\n", daftar_hasil[l].kal_per_gram);
                    }
                    else
                    {
                        printf("%d\n", bulat[l]);       //jika tidak maka print bilangan bulatnya
                    }
                }
            //jika nama pada array hasil sama dengan nama makanan pada array 3 maka di awal ditambah negara asal makanan array 3
                if (strcmp(daftar_hasil[l].nama, daftar3[k].nama) == 0)
                {
                    printf("- %s %s %d %d %d - ", negara3, daftar_hasil[l].nama, daftar_hasil[l].kalori, daftar_hasil[l].berat, daftar_hasil[l].harga);
                    k++;
                    if (daftar_hasil[l].kal_per_gram - bulat[l] != 0)       //jika kal/gram desimal-kal/gram bil.bulat != 0 print 2 angka dibelakamg koma
                    {
                        printf("%.2f\n", daftar_hasil[l].kal_per_gram);
                    }
                    else
                    {
                        printf("%d\n", bulat[l]);       //jika tidak maka print bilangan bulatnya
                    }
                }
    }
}
/* 
is
Jepang
3
moci 100 100 4000
dorayaki 85 100 5000
dango 200 100 6000
Italia
2
meringue 200 50 2000
mousse 300 100 6000
Perancis
1
macaroon 150 100 10000
 */