/* 
    Saya Alief Muhammad Abdillah mengerjakan evaluasi Tugas Masa Depan dalam mata kuliah Algoritma dan 
    Pemrograman II untuk keberkahanNya maka saya tidak melakukan kecurangan seperti 
    yang telah dispesifikasikan. Aamiin.
 */

//bagian mesin
#include "headtmd.h"
/* Proseudur Menjalankan Progam Mesin kata */
void start_kata(char query[]){
    indeks = 0;
    panjang_kata = 0;
    while (query[indeks] == ' ')
    {
        indeks++;
    }

    while ((query[indeks] != ' ') && (query[indeks] != ';'))
    {
        current_kata[panjang_kata] = query[indeks];
        indeks++;
        panjang_kata++;
    }
    
    current_kata[panjang_kata] = '\0';
}

/* Prosedur maju satu kata */
void inc_kata(char query[]){
    panjang_kata = 0;
    while (query[indeks] == ' ')
    {
        indeks++;
    }

    while ((query[indeks] != ' ') && (query[indeks] != ';'))
    {
        current_kata[panjang_kata] = query[indeks];
        indeks++;
        panjang_kata++;
    }
    
    current_kata[panjang_kata] = '\0';
}

/* untuk mengambil kata */
char *get_kata(){
    return current_kata;
}

/* mengambil panjang kata */
int get_panjang_kata(){
    return panjang_kata;
}

/* mengecek eop kata */
int eop_kata(char query[]){
    if (query[indeks] == ';')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/* Prosedur query GANTI(update data pada tabel) */
void GANTI(char nama_tabel[50]){
    if(strcmp(nama_tabel, "tabel_beli") == 0)
    {
        inc_kata(query);
        strcpy(input_tbeli->kode_barang, get_kata());
        if (eop_kata(query) == 1)
        {
            printf("\nQuery salah, Cek kembali Query -_-\n");
        }
        else
        {
            read("tabel_beli");
            i = 0;
            int cari_prim = 0;
            while ((cari_prim == 0) && (i < hr))
            {
                if (strcmp(arr_tbeli[i].kode_barang, input_tbeli->kode_barang) == 0)
                {
                    cari_prim = 1;
                    if (eop_kata(query) == 0)
                    {
                        inc_kata(query);
                        strcpy(arr_tbeli[i].harga, get_kata());
                        if (eop_kata(query) == 0)
                        {
                            inc_kata(query);
                            strcpy(arr_tbeli[i].jmlh_beli, get_kata());
                            if (eop_kata(query) == 1)
                            {
                                write("tabel_beli");
                                printf("\nHoree Proses Berhasil :)\n");
                            }
                            else
                            {
                                printf("\nQuery salah, Cek kembali Query -_-\n"); 
                            }
                        }
                        else
                        {
                            printf("\nQuery salah, Cek kembali Query -_-\n"); 
                        }
                    }
                    else
                    {
                        printf("\nQuery salah, Cek kembali Query -_-\n");
                    }
                }
                else
                {
                    i++;
                }
            }
            if (cari_prim == 0)
            {
                printf("\nPrimary key tidak ditemukan, silahkan gunakan Query TAMBAH, untuk menambah Primary Key :o\n");
            }
        }
    }
    else
    {
        inc_kata(query);
        strcpy(input_tnama->kode_barang, get_kata());
        if (eop_kata(query) == 1)
        {
            printf("\nQuery Salah, cek kembali query -_-\n");
        }
        else
        {
            read("tabel_nama");
            i = 0;
            int cari_prim = 0;
            while ((cari_prim == 0) && (i < nm))
            {
                if (strcmp(arr_tnama[i].kode_barang, input_tnama->kode_barang) == 0)
                {   
                    cari_prim = 1;
                    if (eop_kata(query) == 0)
                    {
                        inc_kata(query);
                        strcpy(arr_tnama[i].nama, get_kata());
                        if (eop_kata(query) == 0)
                        {
                            inc_kata(query);
                            strcpy(arr_tnama[i].stok, get_kata());
                            if (eop_kata(query) == 1)
                            {
                                write("tabel_nama");
                                printf("\nHoree Proses Berhasil :)\n");
                            }
                            else
                            {
                                printf("\nQuery Salah, cek kembali query -_-\n");
                            }   
                        }
                        else
                        {
                            printf("\nQuery Salah, cek kembali query -_-\n");
                        }
                    }
                    else
                    {
                        printf("\nQuery Salah, cek kembali query -_-\n");
                    }
                }
                else
                {
                    i++;
                }
            }
            if (cari_prim == 0)
            {
                printf("\nPrimary key tidak ditemukan, silahkan gunakan Query TAMBAH, untuk menambah Primary Key :o\n");
            }   
        }   
    }
}

/* Prosedur query TAMBAH(insert data pada tabel) */
void TAMBAH(char nama_tabel[50]){
    if (strcmp(nama_tabel, "tabel_nama") == 0)
    {
        inc_kata(query);
        strcpy(input_tnama->kode_barang, get_kata());
        if (eop_kata(query) == 0)
        {
            inc_kata(query);
            strcpy(input_tnama->nama, get_kata());
            if (eop_kata(query) == 0)
            {
                inc_kata(query);
                strcpy(input_tnama->stok, get_kata());
                if (eop_kata(query) == 1)
                {
                    read("tabel_nama");
                    i=0;
                    int cek = 0;
                    //cek apakah primary key sudah ada atau tidak
                    while ((cek == 0) && (i < nm))
                    {
                        if (strcmp(arr_tnama[i].kode_barang, input_tnama->kode_barang) == 0)
                        {
                            cek = 1;
                        }
                        else
                        {
                            i++;
                        }
            
                    }

                    if (cek == 0)
                    {
                        strcpy(arr_tnama[nm].kode_barang, input_tnama->kode_barang);
                        strcpy(arr_tnama[nm].nama, input_tnama->nama);
                        strcpy(arr_tnama[nm].stok, input_tnama->stok);
                        nm++;
                        sort("tabel_nama");
                        write("tabel_nama");
                        printf("\nHoree data berhasil ditambahkan :)\n");
                    }
                    else
                    {
                        printf("\nPrimary key sudah ada silahkan ganti primary key yang lain :o\n");
                    }
                }
                else
                {
                    printf("\nCuma dapat tambah 3 kolom data ya...\n");
                }
            }
            else
            {
                printf("\nQuery salah, Cek kembali Query -_-\n");
            }
        }
        else
        {
            printf("\nQuery salah, Cek kembali Query -_-\n");
        }
    }
    else
    {
        inc_kata(query);
        strcpy(input_tbeli->kode_barang, get_kata());
        if (eop_kata(query) == 0)
        {
            inc_kata(query);
            strcpy(input_tbeli->harga, get_kata());
            if (eop_kata(query) == 0)
            {
                inc_kata(query);
                strcpy(input_tbeli->jmlh_beli, get_kata());
                if (eop_kata(query) == 1)
                {
                    read("tabel_beli");
                    i=0;
                    int cek = 0;
                    //cek apakah primary key sudah ada atau tidak
                    while ((cek == 0) && (i < hr))
                    {
                        if (strcmp(arr_tbeli[i].kode_barang, input_tbeli->kode_barang) == 0)
                        {
                            cek = 1;
                        }
                        else
                        {
                            i++;
                        }
            
                    }

                    if (cek == 0)
                    {
                        strcpy(arr_tbeli[hr].kode_barang, input_tbeli->kode_barang);
                        strcpy(arr_tbeli[hr].harga, input_tbeli->harga);
                        strcpy(arr_tbeli[hr].jmlh_beli, input_tbeli->jmlh_beli);
                        hr++;
                        sort("tabel_beli");
                        write("tabel_beli");
                        printf("\nHoree data berhasil ditambahkan :)\n");
                    }
                    else
                    {
                        printf("\nPrimary key sudah ada silahkan ganti primary key yang lain :o\n");
                    }
                }
                else
                {
                    printf("\nCuma dapat tambah 3 kolom data ya...\n");
                }
            }
            else
            {
                printf("\nQuery salah, Cek kembali Query -_-\n");
            }
        }
        else
        {
            printf("\nQuery salah, Cek kembali Query -_-\n");
        }
    }   
}

/* Prosedur query HAPUS(delete data pada tabel) */
void HAPUS(char nama_tabel[50]){
    if (strcmp(nama_tabel, "tabel_nama") == 0)
    {
        inc_kata(query);
        strcpy(input_tnama->kode_barang, get_kata());
        if (eop_kata(query) == 1)
        {
            read("tabel_nama");
            i = 0;
            int cek = 0;
            int curr_indeks;
            while ((cek == 0) && (i < nm))
            {
                if (strcmp(arr_tnama[i].kode_barang, input_tnama->kode_barang) == 0)
                {
                    cek = 1;
                    curr_indeks = i;
                }
                else
                {
                    i++;
                }
            }
        
            if (cek == 1)
            {
                for ( i = curr_indeks; i < nm; i++)
                {
                    arr_tnama[i] = arr_tnama[i+1];
                }
                nm--;
                write("tabel_nama");
                printf("\nHoree data berhasil dihapus :)\n");
            }
            else
            {
                printf("\nPrimary key tidak ditemukan, silahkan gunakan Query TAMBAH, untuk menambah Primary Key :o\n");
            }
        }
        else
        {
            printf("\nCuma dapat hapus 1 data ya...\n");
        }
    }
    else
    {
        inc_kata(query);
        strcpy(input_tbeli->kode_barang, get_kata());
        if(eop_kata(query) == 1)
        {
            read("tabel_beli");
            i = 0;
            int cek = 0;
            int curr_indeks;
            while ((cek == 0) && (i < hr))
            {
                if (strcmp(arr_tbeli[i].kode_barang, input_tbeli->kode_barang) == 0)
                {
                    cek = 1;
                    curr_indeks = i;
                }
                else
                {
                    i++;
                }
            }

            if (cek == 1)
            {
                for ( i = curr_indeks; i < hr; i++)
                {
                    arr_tbeli[i] = arr_tbeli[i+1];
                }
                hr--;
                write("tabel_beli");
                printf("\nHoree data berhasil dihapus :)\n");
            }
            else
            {
                printf("\nPrimary key tidak ditemukan, silahkan gunakan Query TAMBAH, untuk menambah Primary Key :o\n");
            }
        }
        else
        {
            printf("\nCuma dapat tambah 1 data ya...\n");
        }
    }
}

/* Prosedur query HAPUS_ALL(truncate tabel) */
void HAPUS_ALL(char nama_tabel[50]){
    if (strcmp(nama_tabel, "tabel_nama") == 0)
    {
        if (eop_kata(query) == 0)
        {
            printf("\nQuery salah, Cek kembali Query -_-\n");
        }
        else
        {
            file_nama = fopen("tabel_nama.dat", "w+");
            fprintf(file_nama, "%s %s %s\n", "####", "####", "####");
            fclose(file_nama);
            printf("\nHoree semua data pada tabel telah dihapus :)\n");
        }
    }
    else
    {
        if (eop_kata(query) == 0)
        {
            printf("\nQuery salah, Cek kembali Query -_-\n");
        }
        else
        {
            file_beli = fopen("tabel_beli.dat", "w+");
            fprintf(file_beli, "%s %s %s\n", "####", "####", "####");
            fclose(file_beli);
            printf("\nHoree semua data pada tabel telah dihapus :)\n");
        }
    }
}

/* Prosedur query TAMPIL(menampilkan tabel) */
void TAMPIL(char nama_tabel[50]){
    int spasi_kode_barang, spasi_nama, spasi_stok, spasi_harga, spasi_jmlh_beli;
    int spasi_minus_kd, spasi_minus_nm, spasi_minus_st, spasi_minus_hr, spasi_minus_bl;
    
    if ((strcmp(nama_tabel, "tabel_nama") == 0) && eop_kata(query) == 1)
    {
        int panjang_kode, panjang_nama, panjang_stok;

        read("tabel_nama");
        panjang_kode = strlen(arr_tnama[0].kode_barang);
        panjang_nama = strlen(arr_tnama[0].nama);
        panjang_stok = strlen(arr_tnama[0].stok);
        for ( i = 0; i < nm; i++)
        {
            if (panjang_kode < strlen(arr_tnama[i].kode_barang))
            {
                panjang_kode = strlen(arr_tnama[i].kode_barang);
            }
            if (panjang_nama < strlen(arr_tnama[i].nama))
            {
                panjang_nama = strlen(arr_tnama[i].nama);
            }
            if (panjang_stok < strlen(arr_tnama[i].stok))
            {
                panjang_stok = strlen(arr_tnama[i].stok);
            }
        }

        /*jika nama kolom lebih panjang dari panjang data terpanjang maka membuat varibel selisih antara 
        nama kolom dengan panjang data terpanjang*/
        if (strlen("Kode_Barang") >= panjang_kode)
        {
            spasi_minus_kd = strlen("Kode_Barang") - panjang_kode;
        }
        
        if (strlen("Nama") >= panjang_nama)
        {
            spasi_minus_nm = strlen("Nama") - panjang_nama;
        }
        
        if (strlen("Stok") >= panjang_stok)
        {
            spasi_minus_st = strlen("Stok") - panjang_stok;
        }
        
        //membuat garis tabel
        if (strlen("Kode_Barang") >= panjang_kode)
        {
            garis(panjang_kode+4+spasi_minus_kd);
        }
        else
        {
            garis(panjang_kode+4);
        }
        
        if (strlen("Nama") >= panjang_nama)
        {
            garis(panjang_nama+3+spasi_minus_nm);
        }
        else
        {
            garis(panjang_nama+3);
        }
        
        if (strlen("Stok") >= panjang_stok)
        {
            garis(panjang_stok+3+spasi_minus_st);
        }
        else
        {
            garis(panjang_stok+3);
        }
        
        //Menampilkan judul kolom pada tabel
        printf("\n| Kode_Barang"); 
        if (strlen("Kode_Barang") > panjang_kode)
        {
            printf(" |");
        }
        else
        {
            for ( i = 0; i < panjang_kode - strlen("Kode_Barang"); i++)
            {
                printf(" ");
            }
            printf(" |");
        }
    
        printf(" Nama");
        if (strlen("Nama") > panjang_nama)
        {
            printf(" |");
        }
        else
        {
            for ( i = 0; i < panjang_nama - strlen("Nama"); i++)
            {
                printf(" ");
            }
            printf(" |");
        }
        
        printf(" Stok");
        if (strlen("Stok") > panjang_stok)
        {
            printf(" |\n");
        }
        else
        {
            for ( i = 0; i < panjang_stok - strlen("Stok"); i++)
            {
                printf(" ");
            }
            printf(" |\n");
        }
        
        //membuat garis tabel 
        if (strlen("Kode_Barang") >= panjang_kode)
        {
            garis(panjang_kode+4+spasi_minus_kd);
        }
        else
        {
            garis(panjang_kode+4);
        }
        
        if (strlen("Nama") >= panjang_nama)
        {
            garis(panjang_nama+3+spasi_minus_nm);
        }
        else
        {
            garis(panjang_nama+3);
        }
        
        if (strlen("Stok") >= panjang_stok)
        {
            garis(panjang_stok+3+spasi_minus_st);
        }
        else
        {
            garis(panjang_stok+3);
        }
        printf("\n");
        

        //---menampilkan isi data pada tabel----
        for ( i = 0; i < nm; i++)
        {
            //-------- Tampil data Kode Barang --------------
            if (strlen("Kode_Barang") >= panjang_kode)
            {
                spasi_kode_barang = panjang_kode - strlen(arr_tnama[i].kode_barang);
                printf("| %s", arr_tnama[i].kode_barang);
                for ( j = 0; j < spasi_kode_barang + spasi_minus_kd; j++)
                {
                    printf(" ");
                }
                printf(" |");
            }
            else
            {
                spasi_kode_barang = panjang_kode - strlen(arr_tnama[i].kode_barang);
                printf("| %s", arr_tnama[i].kode_barang);
                for ( j = 0; j < spasi_kode_barang; j++)
                {
                    printf(" ");
                }
                printf(" |");
            }
            
            
            //-------- Tampil data Nama --------------
            if (strlen("Nama") >= panjang_nama)
            { 
                spasi_nama = panjang_nama - strlen(arr_tnama[i].nama);
                printf(" %s", arr_tnama[i].nama);
                for (j = 0; j < spasi_nama+spasi_minus_nm; j++)
                {
                    printf(" ");
                }
                printf(" |");
            }
            else
            {
                spasi_nama = panjang_nama - strlen(arr_tnama[i].nama);
                printf(" %s", arr_tnama[i].nama);
                for (j = 0; j < spasi_nama; j++)
                {
                    printf(" ");
                }
                printf(" |");
            }
            

            //--------- Tampil data Stok ---------------
            if (strlen("Stok") >= panjang_stok)
            {
                spasi_stok = panjang_stok - strlen(arr_tnama[i].stok);
                printf(" %s", arr_tnama[i].stok);
                for ( j = 0; j < spasi_stok + spasi_minus_st; j++)
                {
                    printf(" ");
                }
                printf(" |\n");
            }
            else
            {
                spasi_stok = panjang_stok - strlen(arr_tnama[i].stok);
                printf(" %s", arr_tnama[i].stok);
                for ( j = 0; j < spasi_stok; j++)
                {
                    printf(" ");
                }
                printf(" |\n");
            }
            
        }

        //membuat garis tabel 
        if (strlen("Kode_Barang") >= panjang_kode)
        {
            garis(panjang_kode+4+spasi_minus_kd);
        }
        else
        {
            garis(panjang_kode+4);
        }
        
        if (strlen("Nama") >= panjang_nama)
        {
            garis(panjang_nama+3+spasi_minus_nm);
        }
        else
        {
            garis(panjang_nama+3);
        }
        
        if (strlen("Stok") >= panjang_stok)
        {
            garis(panjang_stok+3+spasi_minus_st);
        }
        else
        {
            garis(panjang_stok+3);
        }
        printf("\n");

    }
    else if ((strcmp(nama_tabel, "tabel_beli") == 0) && eop_kata(query) == 1)
    {
        int panjang_kode_barang, panjang_harga, panjang_jmlh_beli;

        read("tabel_beli");
        panjang_kode_barang = strlen(arr_tbeli[0].kode_barang);
        panjang_harga = strlen(arr_tbeli[0].harga);
        panjang_jmlh_beli = strlen(arr_tbeli[0].jmlh_beli);
        for ( i = 0; i < hr; i++)
        {
            if (panjang_kode_barang < strlen(arr_tbeli[i].kode_barang))
            {
                panjang_kode_barang = strlen(arr_tbeli[i].kode_barang);
            }
            if (panjang_harga < strlen(arr_tbeli[i].harga))
            {
                panjang_harga = strlen(arr_tbeli[i].harga);
            }
            if (panjang_jmlh_beli < strlen(arr_tbeli[i].jmlh_beli))
            {
                panjang_jmlh_beli = strlen(arr_tbeli[i].jmlh_beli);
            }
        }

        /*jika nama kolom lebih panjang dari panjang data terpanjang maka membuat varibel selisih antara 
        nama kolom dengan panjang data terpanjang*/
        if (strlen("Kode_Barang") >= panjang_kode_barang)
        {
            spasi_minus_kd = strlen("Kode_barang") - panjang_kode_barang;
        }

        if (strlen("Harga") >= panjang_harga)
        {
            spasi_minus_hr = strlen("Harga") - panjang_harga;
        }

        if (strlen("Jmlh_Beli") >= panjang_jmlh_beli)
        {
            spasi_minus_bl = strlen("Jmlh_Beli") - panjang_jmlh_beli;
        }
        
        //membuat garis tabel
        if (strlen("Kode_Barang") >= panjang_kode_barang)
        {
            garis(panjang_kode_barang+4+spasi_minus_kd);
        }
        else
        {
            garis(panjang_kode_barang+4);
        }
        
        if (strlen("Harga") >= panjang_harga)
        {
            garis(panjang_harga+3+spasi_minus_hr);
        }
        else
        {
            garis(panjang_harga+3);
        }
        
        if (strlen("Jmlh_Beli") >= panjang_jmlh_beli)
        {
            garis(panjang_jmlh_beli+3+spasi_minus_bl);
        }
        else
        {
            garis(panjang_jmlh_beli+3);
        }
        
        //menampilkan nama kolom pada tabel
        printf("\n| Kode_barang"); 
        if (strlen("Kode_barang") >= panjang_kode_barang)
        {
            printf(" |");
        }
        if (strlen("Kode_barang") < panjang_kode_barang)
        {
            for ( i = 0; i < panjang_kode_barang - strlen("Kode_barang"); i++)
            {
                printf(" ");
            }
            printf(" |");
        }

        printf(" Harga");
        if (strlen("Harga") >= panjang_harga)
        {
            printf(" |");
        }
        if (strlen("Harga") < panjang_harga)
        {
            for ( i = 0; i < panjang_harga - strlen("Harga"); i++)
            {
                printf(" ");
            }
            printf(" |");
        }

        printf(" Jmlh_Beli");
        if (strlen("Jmlh_Beli") >= panjang_jmlh_beli)
        {
            printf(" |\n");
        }
        if (strlen("Jmlh_Beli") < panjang_jmlh_beli)
        {
            for ( i = 0; i < panjang_jmlh_beli - strlen("Jmlh_Beli"); i++)
            {
                printf(" ");
            }
            printf(" |\n");
        }

        //membuat garis tabel
        if (strlen("Kode_Barang") >= panjang_kode_barang)
        {
            garis(panjang_kode_barang+4+spasi_minus_kd);
        }
        else
        {
            garis(panjang_kode_barang+4);
        }
        
        if (strlen("Harga") >= panjang_harga)
        {
            garis(panjang_harga+3+spasi_minus_hr);
        }
        else
        {
            garis(panjang_harga+3);
        }
        
        if (strlen("Jmlh_Beli") >= panjang_jmlh_beli)
        {
            garis(panjang_jmlh_beli+3+spasi_minus_bl);
        }
        else
        {
            garis(panjang_jmlh_beli+3);
        }
        printf("\n");

        /*-- Menampilkan isi data pada Tabel --*/
        for ( i = 0; i < hr; i++)
        {
            //-------- Tampil data kode Barang --------------
            if (strlen("Kode_Barang") >= panjang_kode_barang)
            {
                spasi_kode_barang = panjang_kode_barang - strlen(arr_tbeli[i].kode_barang);
                printf("| %s", arr_tbeli[i].kode_barang);
                for ( j = 0; j < spasi_kode_barang + spasi_minus_kd; j++)
                {
                    printf(" ");
                }
                printf(" |");
            }
            else
            {
                spasi_kode_barang = panjang_kode_barang - strlen(arr_tbeli[i].kode_barang);
                printf("| %s", arr_tbeli[i].kode_barang);
                for ( j = 0; j < spasi_kode_barang; j++)
                {
                    printf(" ");
                }
                printf(" |");
            }
            
             
            //-------- Tampil data Harga --------------
            if (strlen("Harga") >= panjang_harga)
            {
                spasi_harga = panjang_harga - strlen(arr_tbeli[i].harga);
                printf(" %s", arr_tbeli[i].harga);
                for ( j = 0; j < spasi_harga + spasi_minus_hr; j++)
                {
                    printf(" ");
                }
                printf(" |");
            }
            else
            {
                spasi_harga = panjang_harga - strlen(arr_tbeli[i].harga);
                printf(" %s", arr_tbeli[i].harga);
                for ( j = 0; j < spasi_harga; j++)
                {
                    printf(" ");
                }
                printf(" |");
            }
            

            //--------- Tampil data jmlh_beli ---------------
            if (strlen("Jmlh_Beli") >= panjang_jmlh_beli)
            {
                spasi_jmlh_beli = panjang_jmlh_beli - strlen(arr_tbeli[i].jmlh_beli);
                printf(" %s", arr_tbeli[i].jmlh_beli);
                for ( j = 0; j < spasi_jmlh_beli + spasi_minus_bl; j++)
                {
                    printf(" ");
                }
                printf(" |\n");
            }
            else
            {
                spasi_jmlh_beli = panjang_jmlh_beli - strlen(arr_tbeli[i].jmlh_beli);
                printf(" %s", arr_tbeli[i].jmlh_beli);
                for ( j = 0; j < spasi_jmlh_beli; j++)
                {
                    printf(" ");
                }
                printf(" |\n");
            }
        }

        //membuat garis tabel
        if (strlen("Kode_Barang") >= panjang_kode_barang)
        {
            garis(panjang_kode_barang+4+spasi_minus_kd);
        }
        else
        {
            garis(panjang_kode_barang+4);
        }
        
        if (strlen("Harga") >= panjang_harga)
        {
            garis(panjang_harga+3+spasi_minus_hr);
        }
        else
        {
            garis(panjang_harga+3);
        }
        
        if (strlen("Jmlh_Beli") >= panjang_jmlh_beli)
        {
            garis(panjang_jmlh_beli+3+spasi_minus_bl);
        }
        else
        {
            garis(panjang_jmlh_beli+3);
        }
        printf("\n");

    }
    else
    {
        printf("\nQuery salah, Cek kembali Query -_-\n");
    }
}

/* Prosedur untuk membuat garis tabel */
void garis(int panjang_kode){
    for ( i = 0; i < panjang_kode ; i++)
    {
        printf("-");
    }
}

/* Prosedur Membca file */
void read(char nama_tabel[50]){
    if (strcmp(nama_tabel, "tabel_beli") == 0)
    {
        tabel_barang temp_tharga;
        hr = 0;
        file_beli = fopen("tabel_beli.dat", "r");

        fscanf(file_beli, "%s %s %s", &temp_tharga.kode_barang, &temp_tharga.harga, &temp_tharga.jmlh_beli);
        if (strcmp(temp_tharga.kode_barang, "####") == 0)
        {
            printf("\nFILE KOSONG\n");
        }
        else
        {
            while (strcmp(temp_tharga.kode_barang, "####") != 0)
            {
                arr_tbeli[hr] = temp_tharga;
                hr++;
                fscanf(file_beli, "%s %s %s", &temp_tharga.kode_barang, &temp_tharga.harga, &temp_tharga.jmlh_beli);
            }
            fclose(file_beli);
        }
    }  
    else
    {
        tabel_barang temp_tnama;
        nm = 0;
        file_nama = fopen("tabel_nama.dat", "r");

        fscanf(file_nama, "%s %s %s", &temp_tnama.kode_barang, &temp_tnama.nama, &temp_tnama.stok);
        if (strcmp(temp_tnama.kode_barang, "####") == 0)
        {
            printf("\nFILE KOSONG\n");
        }
        else
        {
            while (strcmp(temp_tnama.kode_barang, "####") != 0)
            {
                arr_tnama[nm] = temp_tnama;
                nm++;
                fscanf(file_nama, "%s %s %s", &temp_tnama.kode_barang, &temp_tnama.nama, &temp_tnama.stok);
            }
            fclose(file_nama);
        }   
    }
}

/* prosedur mewrite file */    
void write(char nama_tabel[50]){
    if (strcmp(nama_tabel, "tabel_beli") == 0)
    {
        file_beli = fopen("tabel_beli.dat", "w");
        for ( i = 0; i < hr; i++)
        {
            fprintf(file_beli, "%s %s %s\n", arr_tbeli[i].kode_barang, arr_tbeli[i].harga, arr_tbeli[i].jmlh_beli);
        }
        fprintf(file_beli, "%s %s %s\n", "####", "####", "####");
        fclose(file_beli);
    }
    else
    {
        file_nama = fopen("tabel_nama.dat", "w");
        for ( i = 0; i < nm; i++)
        {
            fprintf(file_nama, "%s %s %s\n", arr_tnama[i].kode_barang, arr_tnama[i].nama, arr_tnama[i].stok);
        }
        fprintf(file_nama, "%s %s %s\n", "####", "####", "####");
        fclose(file_nama);
    }
}

/* Prosedur sorting isi tabel */
void sort(char nama_tabel[50]){
    int cek = 0;
    /* Sorting tabel_nama */
    if (strcmp(nama_tabel, "tabel_nama") == 0)
    {
        char sisip_kode[10], sisip_nama[20], sisip_stok[10];

        //Proses cek apakah data sudah urut atau belum
        i = 0;
        while ((cek == 0) && (i < nm))
        {
            if (strcmp(arr_tnama[i].kode_barang, arr_tnama[i+1].kode_barang) > 0)       //jika data belum urut atau belum ascending
            {
                cek = 1;
            }
            else
            {
                i++;
            }
        }
        
        //jika belum ascending
        if (cek == 1)
        {
            //proses sorting secara insertion sort
            for ( i = 1; i < nm; i++)
            {
                strcpy(sisip_kode, arr_tnama[i].kode_barang);
                strcpy(sisip_nama, arr_tnama[i].nama);
                strcpy(sisip_stok, arr_tnama[i].stok);
                j = i - 1;
                while ((j >= 0) && strcmp(sisip_kode, arr_tnama[j].kode_barang) < 0)
                {
                    strcpy(arr_tnama[j+1].kode_barang, arr_tnama[j].kode_barang);
                    strcpy(arr_tnama[j+1].nama, arr_tnama[j].nama);
                    strcpy(arr_tnama[j+1].stok, arr_tnama[j].stok);
                    j--;
                }
                strcpy(arr_tnama[j+1].kode_barang, sisip_kode);
                strcpy(arr_tnama[j+1].nama, sisip_nama);
                strcpy(arr_tnama[j+1].stok, sisip_stok);
            }
        }
    }
    /* Sorting tabel_nama */
    else
    {
        char sisip_kode[10], sisip_harga[10], sisip_jmlh_beli[10];

        //Proses cek apakah data sudah urut atau belum
        i = 0;
        while ((cek == 0) && (i < hr))
        {
            if (strcmp(arr_tbeli[i].kode_barang, arr_tbeli[i+1].kode_barang) > 0)        //jika data belum urut atau belum ascending
            {
                cek = 1;
            }
            else
            {
                i++;
            }
        }
        
        //jika belum ascending
        if (cek == 1)
        {
            //proses sorting secara insertion sort
            for ( i = 1; i < hr; i++)
            {
                strcpy(sisip_kode, arr_tbeli[i].kode_barang);
                strcpy(sisip_harga, arr_tbeli[i].harga);
                strcpy(sisip_jmlh_beli, arr_tbeli[i].jmlh_beli);
                j = i - 1;
                while ((j >= 0) && strcmp(sisip_kode, arr_tbeli[j].kode_barang) < 0)
                {
                    strcpy(arr_tbeli[j+1].kode_barang, arr_tbeli[j].kode_barang);
                    strcpy(arr_tbeli[j+1].harga, arr_tbeli[j].harga);
                    strcpy(arr_tbeli[j+1].jmlh_beli, arr_tbeli[j].jmlh_beli);
                    j--;
                }
                strcpy(arr_tbeli[j+1].kode_barang, sisip_kode);
                strcpy(arr_tbeli[j+1].harga, sisip_harga);
                strcpy(arr_tbeli[j+1].jmlh_beli, sisip_jmlh_beli);
            }
        }
    }
}