/*Saya Alief Muhammad Abdillah 2003623 mengerjakan TP8 dalam mata kuliah Algoritma dan Pemrograman 2
untuk keberkahan-Nya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/

//bagian header
#include <stdio.h>
#include <string.h>

//tipe data struktur penyimpan data
typedef struct
{
    char nama[50];      //variabel data nama film
    char strdr[50];     //vairaebl data nama dan kode sutradara di file Listfilm
    char bskp[20];      //vairaebl data nama dan kode bioskop di file Listfilm
    char gnr[20];       //vairaebl data nama dan kode genre di file Listfilm
    char kode[5];       //vairaebl data kode sutradara di array file sisanya 
}data_film;

//Connector Dengan File
FILE *file_film;       
FILE *ffilm;
FILE *file_sutradara;
FILE *file_genre;
FILE *file_bioskop;

//variabel global
int f, b, g, s, n;      //variabel indeks tiap file
int i,j, k,l;
int spasi_judul, spasi_sut,  spasi_gen, spasi_bio;

//Prosedur - Prosedur
void start();           //prosedur start
void read(data_film list[], data_film sutradara[], data_film genre[], data_film bioskop[]); //prosedur read file listFilm, sutrardara, genre, bioskop
void salin(data_film list[]);           //prosedur salin lisfFilm ke ListFilmFinal
void cetak_akhir(data_film list[]);     //prosdur cetak hasil akhir
void garis(int panjang_judul);          //prosedur cetak garis tabel
void tambah_list_film(data_film tmbh_film[]);       //prosedur menambah data pada file ListFilm
void tambah_sutradara(data_film tmbh_strdr[]);      //prosedur menambah data pada file Sutradara
void tambah_genre(data_film tmbh_gnr[]);            //prosedur menambah data pada file Genre
void tambah_bioskop(data_film tmbh_bskp[]);         //prosedur menambah data pada file Bioskop
