/*Saya Alief Muhammad Abdillah 2003623 mengerjakan TP5 dalam mata kuliah Algoritma dan Pemrograman 2
untuk keberkahan-Nya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/

//bagian input
#include "headtp5.h"

//==== Prosedur Input =====
void input(){
    int n;              //variabel untuk panjang array masukan
    int kiri,kanan;     //variabel untuk pivot pada proses quicksort
    scanf("%d", &n);    //masukan nilai n

    bungkus angka[n];   //deklarasi bungkusan
    
    //masukan user nilai pecahan (pembilang &  penyebut)
    for ( i = 0; i < n; i++)
    {
        scanf("%d", &angka[i].pembilang);
        scanf("%d", &angka[i].penyebut);
    }

    //masukan metode sorting (bubble sort (b) atau quick sort (q))
    char metode;
    scanf(" %c", &metode);

    //masukan urutan sorting (ascending (a) / descending (d))
    char urutan;
    scanf(" %c", &urutan);

    //jika metode memiliki masukan 'b'
    if (metode == 'b')
    {
        bubble(n, urutan, angka);   //masuk prosedur bublle sort
    }
    //jika meotde memiliki masukan 'q'
    if (metode == 'q')
    {
        quick(n, urutan, angka, 0, n-1);    //masuk prosedur quick sort
    }

    cetak(n, angka);    //prosedur cetak hasil akhir
}

//==== Fungsi Pembuat pecahan menjadi desimal ======
double desimal_pecahan(bungkus angka){

    return((double)angka.pembilang/angka.penyebut); 
}

//==== Prosedur Bubble sort =====
void bubble(int n, char urutan, bungkus angka[n]){
    //jika masukan urutan berupa huruf 'a'
    if (urutan == 'a')
    {   
        //laukan perulangan selama tanda = 1
        do
        {
        tanda = 0;      //inisialiasi pertama 
        //perulangan pengecekan
            for (i = 0; i < n-1; i++)
            {
                //jika nilai desimal[i] > desimal[i+1]
                if (desimal_pecahan(angka[i]) > desimal_pecahan(angka[i+1]))
                {
                //tukar pembilang
                temp_pembilang = angka[i].pembilang;
                angka[i].pembilang = angka[i+1].pembilang;
                angka[i+1].pembilang = temp_pembilang;

                //tukar penyebut
                temp_penyebut = angka[i].penyebut;
                angka[i].penyebut = angka[i+1].penyebut;
                angka[i+1].penyebut = temp_penyebut;

                tanda = 1;      //tanda berubah = 1
                }
            }      
        }while(tanda == 1);
    }
    //jika masukan urutan berupa huruf 'd'
    if (urutan == 'd')
    {
        //laukan perulangan selama tanda = 1
        do
        {
        tanda = 0;      //inisialiasi pertama 
        //perulangan pengecekan
            for (i = 0; i < n-1; i++)
            {
                //jika nilai desimal[i] < desimal[i+1]
                if (desimal_pecahan(angka[i]) < desimal_pecahan(angka[i+1]))
                {
                //tukar pembilang
                temp_pembilang = angka[i].pembilang;
                angka[i].pembilang = angka[i+1].pembilang;
                angka[i+1].pembilang = temp_pembilang;

                //tukar penyebut
                temp_penyebut = angka[i].penyebut;
                angka[i].penyebut = angka[i+1].penyebut;
                angka[i+1].penyebut = temp_penyebut;

                tanda = 1;
                }
            }      
        }while(tanda == 1);
    }
}

//====== Prosedur Quick Sort =======
void quick(int n, char urutan, bungkus angka[n], int kiri, int kanan){
    i = kiri;   //i = kiri /indeks paling kiri
    j = kanan;  //j = kanan /indeks paling kanan

    //jika masukan urutan berupa huruf 'a'
    if (urutan == 'a')
    {
        //lakukan perulangan selama i < j
        do{
            //pengecekan angka secara ascending 
            while ((desimal_pecahan(angka[i]) < desimal_pecahan(angka[kanan])) && (i <= j))
            {
                //mencegah i melewati batas j
                i++;
            }
            while ((desimal_pecahan(angka[j]) > desimal_pecahan(angka[kiri])) && (i <= j))
            {   
                //mencegah j melewati batas i
                j--;
            }

            //proses pertukaran selama i < j
            if (i < j)
            {
                //tukar pembilang
                temp_pembilang = angka[i].pembilang;
                angka[i].pembilang = angka[j].pembilang;
                angka[j].pembilang = temp_pembilang;

                //tukar penyebut
                temp_penyebut = angka[i].penyebut;
                angka[i].penyebut = angka[j].penyebut;
                angka[j].penyebut = temp_penyebut;

                i++;
                j--;
            }
        }while (i < j);

        /*
            jika i sudah bertemu j atau dalam posisi yang sama/lebih
            melakukan proses rekursif yang membagi array menjadi beberapa bagian
        */
        if (kiri < j)   //pembagian dari indeks paling kiri sampai ke pertemuan i dan j
        {
            quick(n, urutan, angka, kiri, j);
        }
        if (i < kanan)  //pembagian dari pertemuan i dan j sampai ke indek paling kanan
        {
            quick(n, urutan, angka, i, kanan);
        }
    }
    //jika masukan urutan berupa huruf 'd'
    if (urutan == 'd')
    {
        //lakukan perulangan selama i < j
        do{
            //pengecekan angaka secara descending
            while ((desimal_pecahan(angka[i]) > desimal_pecahan(angka[kanan])) && (i <= j))
            {
                //mencegah i melewati batas j
                i++;
            }
            while ((desimal_pecahan(angka[j]) < desimal_pecahan(angka[kiri])) && (i <= j))
            {
                //mencegah j melewati batas i
                j--;
            }

            //proses pertukaran selama i < j
            if (i < j)
            {
                //tukar pembilang
                temp_pembilang = angka[i].pembilang;
                angka[i].pembilang = angka[j].pembilang;
                angka[j].pembilang = temp_pembilang;

                //tukar penyebut
                temp_penyebut = angka[i].penyebut;
                angka[i].penyebut = angka[j].penyebut;
                angka[j].penyebut = temp_penyebut;

                i++;
                j--;
            }
        }while (i < j);

        /*
            jika i sudah bertemu j atau dalam posisi yang sama/lebih
            melakukan proses rekursif yang membagi array menjadi beberapa bagian
        */
        if (kiri < j)
        {
            quick(n, urutan, angka, kiri, j);   //pembagian dari indeks paling kiri sampai ke pertemuan i dan j
        }
        if (i < kanan)
        {
            quick(n, urutan, angka, i, kanan);   //pembagian dari pertemuan i dan j sampai ke indek paling kanan
        }
    }  
}

//==== prosedur cetak hasil akhir ====
void cetak(int n, bungkus angka[n]){
    //proses cetak pembilang
    for (i = 0; i < n; i++)
    {   
        //jika bukan indeks terakhir
        if (i != n-1)
        {
            printf("%d   ", angka[i].pembilang);
        }
        //jika indeks terakhir
        else
        {
            printf("%d\n", angka[i].pembilang);
        }
    }

    //proses cetak - dan koma
    for (i = 0; i < n; i++)
    {   
        //jika bukan indeks terakhir
        if (i != n-1)
        {
            printf("- , ");
        }
        //jika indeks terakhir
        else
        {
            printf("-\n");
        }
    }
    
    //proses cetak penyebut
    for (size_t i = 0; i < n; i++)
    {   
        //jika bukan indeks terakhir
        if (i != n-1)
        {
            printf("%d   ", angka[i].penyebut);
        }
        //jika indeks terakhir
        else
        {
            printf("%d\n", angka[i].penyebut);
        }
    }
}