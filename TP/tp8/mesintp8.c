/*Saya Alief Muhammad Abdillah 2003623 mengerjakan TP8 dalam mata kuliah Algoritma dan Pemrograman 2
untuk keberkahan-Nya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/

//bagian mesin
#include "headtp8.h"

//Prosedur Start
void start(){

    //Deklarasi Bungkusan
    data_film list[50];
    data_film sutradara[50];
    data_film genre[50];
    data_film bioskop[50];


    char pilihan;           //variabel penampung pilihan user
    char pilihan_file[20];      //variabel penampung pilihan file
    printf("apakah ingin menambah data (y/t)?: ");
    scanf(" %c", &pilihan);

    //jika ingin menambah data
    if (pilihan == 'y')
    {
        printf("data di file mana yang ingin diubah: ");
        scanf("%s", pilihan_file);
        if (strcmp(pilihan_file, "ListFilm") == 0)      //jika user memasukan ListFilm
        {
            data_film tmbh_film[50];
            tambah_list_film(tmbh_film);        //panggil prosedur tambah listFilm
        }
        else if (strcmp(pilihan_file, "Sutradara") == 0)
        {   
            data_film tmbh_strdr[50];
            tambah_sutradara(tmbh_strdr);       //panggil prosedur tambah Sutradara
        }
        else if (strcmp(pilihan_file, "Genre") == 0)
        {
            data_film tmbh_gnr[50];
            tambah_genre(tmbh_gnr);             //panggil prosedur tambah Genre
        }
        else if (strcmp(pilihan_file, "Bioskop") == 0)
        {
            data_film tmbh_bskp[50];
            tambah_bioskop(tmbh_bskp);          //Panggil Prosedur tambah Bioskop
        }
        else                    // jika tidak lewati 
        {
            printf("nama file tidak valid. proses dimulai\n");
            printf("\n");
        }
    }
    else    //jika tidak ignin menambah data
    {
        printf("proses dimulai\n");
        printf("\n");
    }

    read(list, sutradara, genre, bioskop);      //panggil prosedur read masing-masing file dan ditukar didalamnya
    salin(list);                                //salin listFilm.dat ke ListFilmFinal
    cetak_akhir(list);                          //prosedur cetak hasil akhir
}

//Proseudr Read File
void read(data_film list[], data_film sutradara[], data_film genre[], data_film bioskop[]){
    f = 0;
    //proses membaca file listFilmFinal.dat
    file_film = fopen("ListFilm.dat", "r");     //buka file ListFilm.dat
    fscanf(file_film, "%s %s %s %s", &list[f].nama, &list[f].strdr, &list[f].gnr, &list[f].bskp);
    if (strcmp(list[f].nama, "####") == 0)
    {
        printf("File Kosong\n");
    }
    else
    {
        while (strcmp(list[f].nama, "####") != 0)
        {
            f++;
            fscanf(file_film, "%s %s %s %s", &list[f].nama, &list[f].strdr, &list[f].gnr, &list[f].bskp);
        }
    }
    fclose(file_film);      //tutup setelah selesai scan pada file

    //proses membaca file Sutradara
    s = 0;
    file_sutradara = fopen("Sutradara.dat", "r");       //buka file Sutradara.dat
    fscanf(file_sutradara, "%s %s", &sutradara[s].kode, &sutradara[s].strdr);
    if (strcmp(sutradara[s].kode, "####") == 0)
    {
        printf("File Kosong\n");
    }
    else
    {
        while (strcmp(sutradara[s].kode, "####") != 0)
        {
            s++;
            fscanf(file_sutradara, "%s %s", &sutradara[s].kode, &sutradara[s].strdr);
        }
    }
    fclose(file_sutradara);     //tutup setelah selesai scan pada file
    
    //proses membaca file genre
    g = 0;
    file_genre = fopen("Genre.dat", "r");       //buka file Genre.dat dengan mode read
    fscanf(file_genre, "%s %s", &genre[g].kode, &genre[g].gnr);
    if (strcmp(genre[g].kode, "####") == 0)
    {
        printf("File Kosong\n");
    }
    else
    {
        while (strcmp(genre[g].kode, "####") != 0)
        {
            g++;
            fscanf(file_genre, "%s %s", &genre[g].kode, &genre[g].gnr);
        }
    }
    fclose(file_genre);         //tutup setelah selesai scan pada file

    //proses baca file bioskop
    b = 0;
    file_bioskop = fopen("Bioskop.dat", "r");       //buka file Bioskop.dat dengan mode read
    fscanf(file_bioskop, "%s %s", &bioskop[b].kode, &bioskop[b].bskp);
    if (strcmp(bioskop[b].kode, "####") == 0)
    {
        printf("File Kosong\n");
    }
    else
    {
        while (strcmp(bioskop[b].kode, "####") != 0)
        {
            b++;
            fscanf(file_bioskop, "%s %s", &bioskop[b].kode, &bioskop[b].bskp);
        }
    }
    fclose(file_bioskop);   //tutup setelah selesai scan pada file
    
    // tukar kode sutradara di file ListFilm dengan nama sutradara di  File Sutradara
    for ( i = 0; i < f; i++)
    {
        for ( j = 0; j < s; j++)
        {
            if (strcmp(list[i].strdr, sutradara[j].kode) == 0)
            {
                strcpy(list[i].strdr, sutradara[j].strdr);
            }
        }
    }

   // tukar kode genre di file ListFilm dengan nama Genre di  File Genre
    for ( i = 0; i < f; i++)
    {
        for ( j = 0; j < g; j++)
        {
            if (strcmp(list[i].gnr, genre[j].kode) == 0)
            {
                strcpy(list[i].gnr, genre[j].gnr);
            }
        }
    }

    // tukar kode Bioskop di file ListFilm dengan nama Bioskop di File Bioskop 
    for ( i = 0; i < f; i++)
    {
        for ( j = 0; j < b; j++)
        {
            if (strcmp(list[i].bskp, bioskop[j].kode) == 0)
            {
                strcpy(list[i].bskp, bioskop[j].bskp);
            }
        }
    }
}

//Prosedur Salin data Pada File
void salin(data_film list[]){
    //proses salin dari ListFilm ke ListFilmFinal
    file_film = fopen("ListFilmFinal.dat", "w");    //buka file ListFilmFinal dengan mode w
    for ( i = 0; i < f; i++)
    {
        fprintf(file_film, "%s %s %s %s\n", list[i].nama, list[i].strdr, list[i].gnr, list[i].bskp);
    }
    fprintf(file_film, "%s %s %s %s\n", "####", "####", "####", "####");
}

void cetak_akhir(data_film list[]){
    //progam print akhir dalam bentuk tabel
    int panjang_judul, panjang_sut, panjang_gen, panjang_bio;       
    //variabel untuk menampung string terbajang dari masing-masing kolom

    //cek kata terpanjang
    panjang_judul = strlen(list[0].nama);
    panjang_sut = strlen(list[0].strdr);
    panjang_gen = strlen(list[0].gnr);
    panjang_bio = strlen(list[0].bskp);
    for ( i = 0; i < f; i++)
    {
        if (panjang_judul < strlen(list[i].nama))
        {
            panjang_judul = strlen(list[i].nama);
        }
        if (panjang_sut < strlen(list[i].strdr))
        {
            panjang_sut = strlen(list[i].strdr);
        }
        if (panjang_gen < strlen(list[i].gnr))
        {
            panjang_gen = strlen(list[i].gnr);
        }
        if (panjang_bio < strlen(list[i].bskp))
        {
            panjang_bio = strlen(list[i].bskp);
        }
    }

    //proses Print akhir dalam bentuk tabel
    for ( i = 0; i < f; i++)
    {
        garis(panjang_judul); garis(panjang_sut); garis(panjang_gen); garis(panjang_bio);   //cetak garis-garis tabel
        printf("\n");
        if (strlen(list[i].nama) < panjang_judul)
        {
            spasi_judul = panjang_judul - strlen(list[i].nama);
            printf("%s", list[i].nama);
            for (k = 0; k < spasi_judul; k++)
            {
                printf(" ");
            }
            printf(" |");
        }
        if(strlen(list[i].nama) == panjang_judul)
        {
            printf("%s |", list[i].nama);
        }
        if (strlen(list[i].strdr) < panjang_sut)
        {
            spasi_sut = panjang_sut - strlen(list[i].strdr);
            printf("%s", list[i].strdr);
            for (k = 0; k < spasi_sut; k++)
            {
                printf(" ");
            }
            printf(" |");
        }
        if(strlen(list[i].strdr)== panjang_sut)
        {
            printf("%s |", list[i].strdr);
        }
        if (strlen(list[i].gnr) < panjang_gen)
        {
            spasi_gen = panjang_gen - strlen(list[i].gnr);
            printf("%s", list[i].gnr);
            for (k = 0; k < spasi_gen; k++)
            {
                printf(" ");
            }
            printf(" |");
        }
        if(strlen(list[i].gnr)== panjang_gen)
        {
            printf("%s |", list[i].gnr);
        }
        if (strlen(list[i].bskp) < panjang_bio)
        {
            spasi_bio = panjang_bio - strlen(list[i].bskp);
            printf("%s", list[i].bskp);
            for (k = 0; k < spasi_bio; k++)
            {
                printf(" ");
            }
            printf(" |\n");
        }
        if(strlen(list[i].bskp)== panjang_bio)
        {
            printf("%s |\n", list[i].bskp);
        }
    }   
    garis(panjang_judul); garis(panjang_sut); garis(panjang_gen); garis(panjang_bio); //cetak garis-garis tabel
    printf("\n"); 

    printf("proses selesai\n");
}

//Prosedur Cetak Garis Tabel
void garis(int panjang_judul){
    for ( j = 0; j <= panjang_judul+1; j++)
    {
        printf("-");
    }
}

//Prosedur Tambah data file ListFilm
void tambah_list_film(data_film tmbh_film[]){
    int fl = 0;
    file_film = fopen("ListFilm.dat", "r");

    printf("masukan record data (Judul_film Kode_Sutradara Kode_Genre Kode_Bioskop):\n");
    printf("(untuk berhenti tuliskan #### #### #### ####)\n");

    fscanf(file_film, "%s %s %s %s", &tmbh_film[fl].nama, &tmbh_film[fl].strdr, &tmbh_film[fl].gnr, &tmbh_film[fl].bskp);
    if (strcmp(tmbh_film[fl].nama, "####") == 0)
    {
        printf("File Kosong\n");
    }
    else
    {
        while (strcmp(tmbh_film[fl].nama, "####")!= 0){
            fl++;
            fscanf(file_film, "%s %s %s %s", &tmbh_film[fl].nama, &tmbh_film[fl].strdr, &tmbh_film[fl].gnr, &tmbh_film[fl].bskp);
        }

        scanf("%s %s %s %s", &tmbh_film[fl].nama, &tmbh_film[fl].strdr, &tmbh_film[fl].gnr, &tmbh_film[fl].bskp);
        while (strcmp(tmbh_film[fl].nama, "####")!= 0)
        {
            fl++;
            scanf("%s %s %s %s", &tmbh_film[fl].nama, &tmbh_film[fl].strdr, &tmbh_film[fl].gnr, &tmbh_film[fl].bskp);
        }
        
    }
    fclose(file_film);
    
    file_film = fopen("ListFilm.dat", "w");
    for ( i = 0; i < fl; i++)
    {
        fprintf(file_film, "%s %s %s %s\n", tmbh_film[i].nama, tmbh_film[i].strdr, tmbh_film[i].gnr, tmbh_film[i].bskp);
    }
    fprintf(file_film, "%s %s %s %s\n", "####", "####", "####", "####");

    fclose(file_film);
}

//Prosedur Tambah data file Sutradara
void tambah_sutradara(data_film tmbh_strdr[]){
    int st = 0;
    file_sutradara = fopen("Sutradara.dat", "r");

    printf("masukan record data (Kode_Sutradara Nama_Sutradara):\n");
    printf("(untuk berhenti tuliskan #### ####)\n");

    fscanf(file_sutradara, "%s %s", &tmbh_strdr[st].kode, &tmbh_strdr[st].strdr);
    if (strcmp(tmbh_strdr[st].kode, "####") == 0)
    {
        printf("File Kosong\n");
    }
    else
    {
        while (strcmp(tmbh_strdr[st].kode, "####")!= 0){
            st++;
            fscanf(file_sutradara, "%s %s", &tmbh_strdr[st].kode, &tmbh_strdr[st].strdr);
        }

        scanf("%s %s", &tmbh_strdr[st].kode, &tmbh_strdr[st].strdr);
        while (strcmp(tmbh_strdr[st].kode, "####")!= 0)
        {
            st++;
            scanf("%s %s", &tmbh_strdr[st].kode, &tmbh_strdr[st].strdr);
        }
        
    }
    fclose(file_sutradara);
    
    file_sutradara = fopen("Sutradara.dat", "w");
    for ( i = 0; i < st; i++)
    {
        fprintf(file_sutradara, "%s %s\n", tmbh_strdr[i].kode, tmbh_strdr[i].strdr);
    }
    fprintf(file_sutradara, "%s %s\n", "####", "####");

    fclose(file_sutradara);
}

//Prosedur Tambah data file Genre
void tambah_genre(data_film tmbh_gnr[]){
    int gr = 0;
    file_genre = fopen("Genre.dat", "r");

    printf("masukan record data (Kode_Genre Nama_Genre):\n");
    printf("(untuk berhenti tuliskan #### ####)\n");

    fscanf(file_genre, "%s %s", &tmbh_gnr[gr].kode, &tmbh_gnr[gr].gnr);
    if (strcmp(tmbh_gnr[gr].kode, "####") == 0)
    {
        printf("File Kosong\n");
    }
    else
    {
        while (strcmp(tmbh_gnr[gr].kode, "####")!= 0){
            gr++;
            fscanf(file_genre, "%s %s", &tmbh_gnr[gr].kode, &tmbh_gnr[gr].gnr);
        }

        scanf("%s %s", &tmbh_gnr[gr].kode, &tmbh_gnr[gr].gnr);
        while (strcmp(tmbh_gnr[gr].kode, "####")!= 0)
        {
            gr++;
            scanf("%s %s", &tmbh_gnr[gr].kode, &tmbh_gnr[gr].gnr);
        }
        
    }
    fclose(file_genre);
    
    file_genre = fopen("Genre.dat", "w");
    for ( i = 0; i < gr; i++)
    {
        fprintf(file_genre, "%s %s\n", tmbh_gnr[i].kode, tmbh_gnr[i].gnr);
    }
    fprintf(file_genre, "%s %s\n", "####", "####");

    fclose(file_genre);
}

//Prosedur Tambah data file Bioskop
void tambah_bioskop(data_film tmbh_bskp[]){
    int bs = 0;
    file_bioskop = fopen("Bioskop.dat", "r");
    printf("masukan record data (Kode_Bioskop Nama_Bioskop):\n");
    printf("(untuk berhenti tuliskan #### ####)\n");
    
    fscanf(file_bioskop, "%s %s", &tmbh_bskp[bs].kode, &tmbh_bskp[bs].bskp);
    if (strcmp(tmbh_bskp[bs].kode, "####") == 0)
    {
        printf("File Kosong\n");
    }
    else
    {
        while (strcmp(tmbh_bskp[bs].kode, "####")!= 0){
            bs++;
            fscanf(file_bioskop, "%s %s", &tmbh_bskp[bs].kode, &tmbh_bskp[bs].bskp);
        }

        scanf("%s %s", &tmbh_bskp[bs].kode, &tmbh_bskp[bs].bskp);
        while (strcmp(tmbh_bskp[bs].kode, "####")!= 0)
        {
            bs++;
            scanf("%s %s", &tmbh_bskp[bs].kode, &tmbh_bskp[bs].bskp);
        }
        
    }
    fclose(file_bioskop);
    
    file_bioskop = fopen("Bioskop.dat", "w");
    for ( i = 0; i < bs; i++)
    {
        fprintf(file_bioskop, "%s %s\n", tmbh_bskp[i].kode, tmbh_bskp[i].bskp);
    }
    fprintf(file_bioskop, "%s %s\n", "####", "####");

    fclose(file_bioskop);
}