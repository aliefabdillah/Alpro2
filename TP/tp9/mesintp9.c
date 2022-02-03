/*Saya Alief Muhammad Abdillah 2003623 mengerjakan TP9 dalam mata kuliah Algoritma dan Pemrograman 2
untuk keberkahan-Nya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/

//bagian mesin
#include "headtp9.h"

//### Prosedur Input ###
void input(){
    char nama[50];          //varibel nama
    char kode[50];         //variabel kode 
    char temp1, temp2;      //variabel temporary saat proses pengecekan

    scanf("%s", nama);
    scanf("%s", kode);

    n = 0;
    start(kode);            //proses pengecekan dimulai
    //perulangan selama bukan eop
    while (eop() == 0)
    {
        temp1 = get_cc();       //mengambil karakter pertama dan memasukan ke temp1
        inc(kode);              //maju satu karakter selanjutnya
        if (eop() == 0)
        {
            temp2 = get_cc();   //mengambil karakter saat ini dan memasukan ke temp2
            inc(kode);          //maju satu karakter ke selanjutnya
            if(eop() == 0)
            {
                if ((temp1 == 'x') && (temp2 == 'c') && (get_cc() == 'v'))          //jika susunan karakter adalah "xcv"
                {
                    n = 1;      //n = 1
                }
                if ((temp1 == 'r') && (temp2 == 'a') && (get_cc() == 'r'))          //jika susunan karakter adalah "rar"
                {
                    n = 1;      //n = 1
                }
                if ((temp1 == 'x') && (temp2 == 'a') && (get_cc() == 'r'))          //jika susunan karakter adalah "xar"
                {
                    n = 1;      //n = 1
                }
            }
        }
    }

    output(nama);       //pemanggilan prosedur output
}

//### Prosedur Star/Mulai ###
void start(char kode[]){
    indeks = 0;
    cc = kode[indeks];
}

//### Prosedur Inc/Maju satu karakter ###
void inc(char kode[]){
    indeks++;
    cc = kode[indeks];
}

//### Fungsi get_cc/mengambil karakter saat ini ###
char get_cc(){
    return cc;
}

//### Fungsi eop/penanda akhir kalimat/kode ###
int eop(){
    if (cc == '.')
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}

//### Prosedur Output/Tampil hasil Akhir ###
void output(char nama[]){
    //jika  n = 1
    if (n == 1) 
    {
        printf("%s adalah Agen Rahasia.\n", nama);
    }
    //jika selain itu
    else
    {
        printf("%s adalah pegawai biasa.\n", nama);
    }
}