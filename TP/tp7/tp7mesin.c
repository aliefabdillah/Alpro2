/*Saya Alief Muhammad Abdillah 2003623 mengerjakan TP7 dalam mata kuliah Algoritma dan Pemrograman 2
untuk keberkahan-Nya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/

//bagian mesin
#include "tp7head.h"

//==== Prosedur Input ====
void input(){
    int n;              //variabel untuk menampung banyaknya siswa /panjang array siswa
    scanf("%d", &n);        //masukan user
    data_siswa siswa[n];    //dekalrasi bungkusan data_siswa sebanyak n

    //proses masukan nama, jumlah extra dan nilai
    for ( i = 0; i < n; i++)
    {
        scanf("%s", siswa[i].nama);     //proses masukan nama siswa
        scanf("%d", &siswa[i].m);             //proses masukan jumlah extra setiap siswa
        for ( j = 0; j < siswa[i].m; j++)
        {
            scanf("%d", &siswa[j].nilai);       //proses masukan nilai extra setiap siswa
            total_nilai[i] = total_nilai[i] + siswa[j].nilai;       //penghitungan total nilai setiap siswa
        }
    }
    
    scanf("%d", &index_cari);       //masukan index yang ingin dicari namanya

    rata_nilai(n, siswa);       //pemanggilan prosedurmenghitung rata-rata

    int tanda;                  //variabel penampung nilai dari fungsi cek_urut
    tanda = cek_urut(n);        //pemanggilan fungsi cek_urut dan nilainya akan dimasukan ke variavel tanda

    //jika tanda = 1 atau tidak urut posisi nilainya
    if (tanda == 1)
    {
        sorting(n, siswa);      //maka lakukan sorting
        search_seq(n, siswa);   //lalu jalankan prosedur search seq
    }
    //jika posisi nilainya sudah urut
    else
    {
        //jalankan prosedur search binary
        search_bin(n, siswa);
    }    
}

//==== Prosedur Menghitung rata-rata ====
void rata_nilai(int n, data_siswa siswa[]){
    
    for ( i = 0; i < n; i++)
    {
        rata_rata[i] = (float)total_nilai[i] / siswa[i].m;        //total nilai dibagai jumlah extra masing-masing siswa
    } 
}

//==== Fungsi Cek_urutan ====
int cek_urut(int n){
    int i;
    int cek;        //indikator 

    i = 0;
    cek = 0;    //inisialisasi indikator
    while ((i<n) && (cek == 0))     //perulangan pengecekan selama i < n dan indikator bernilai 0
    {   
        //jika ada rata-rata yang lebih besar dari nilai rata-rata sesudahnya / tidak urut dari kecil kebesar
        if (rata_rata[i] > rata_rata[i+1])
        {
            cek = 1;    //nilai indikator berubah menjadi = 1
        }
        i++;    //jika tidak i++/lanjutkan pengecekan
    }

    return cek;     //pengembalian nilai cek
}

//==== Prosedur Sorting ====
void sorting(int n, data_siswa siswa[]){
    int i, j;
    int temp_nilai;     //variabel penampung sementara dari nilai
    char temp_nama[50]; //vairabel penampung sementara dari nama

    //sorting dengan insertion sort
    for (i = 1; i < n; i++)
    {
        temp_nilai = rata_rata[i];
        strcpy(temp_nama, siswa[i].nama);
        j = i - 1;
        while ((temp_nilai < rata_rata[j]) && (j >= 0))     //jika nilai pada temp lebih kecil daripada nilai rata-rata pada indeks sebelumnnya
        {
            rata_rata[j+1] = rata_rata[j];
            strcpy(siswa[j+1].nama, siswa[j].nama);
            j--;
        }
        rata_rata[j+1] = temp_nilai;
        strcpy(siswa[j+1].nama, temp_nama);
    }
}

//==== Prosedur Search Sequential
void search_seq(int n, data_siswa siswa[]){
    found = 0;  //indikator jika sudah menemukan index yang ingin dicari nilaint

    //perulangan pengecekan selama i < n
    for ( i = 0; i < n; i++)
    {
        if (i == index_cari)    //jika i = index yang ingin dicari
        {
            found = 1;      //indikator berubah
        }
        else
        {
            i++;        //jika tidak lanjut
        }
    }

    
    output(n, siswa);
    
}

//==== Prosedur Serch Binary
void search_bin(int n, data_siswa siswa[]){
    i=0;        //index pertama
    j=n-1;      //index terakhir
    k = 0;      //variabel untuk menampung index tengah
    found = 0;  //indikator

    //perulangan selama found == 0 dan i < j
    while ((found == 0) && (i<=j))
    {
        k = (int)(i+j)/2;       //k = index tengah
        if (k == index_cari)        //jika k == index cari
        {
            found = 1;      // indikator berubah dan perulangan berhenti
        }
        else                //jika k tidak sama dengan index cari
        {
            if (k > index_cari)     //jika k lebih besar dari index cari
            {
                j = k - 1;          //j nya mundur ke nilai index k - 1
            }
            else
            {
                i = k + 1;          //i nya maju ke nilai index k + 1
            }
        }
    }

    
    output(n, siswa);           // maka panggil prosedur output
    
    
}

//==== Prosedur Output ====
void output(int n, data_siswa siswa[]){
    for ( i = 0; i < n; i++)
    {
        printf("%s\n", siswa[i].nama);      //menampilkan nama yang sudah disorting
    }

    printf("\nYang Diminta : %s\n", siswa[index_cari].nama);        //menampilkan nama berdasarkan index yang dingingkan
    
}

/* 
3
dadan
1
90
irene
1
100
makan
1

1
 */