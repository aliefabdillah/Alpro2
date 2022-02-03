/*Saya Alief Muhammad Abdillah 2003623 mengerjakan Eval UAS dalam mata kuliah Algoritma dan Pemrograman 2
untuk keberkahan-Nya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/

//bagian mesin
#include "headeval2.h"

/* Prosedur Start_Kata */
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

/* Prosedur Inc_kata */
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

/* Prosedur Get_kata */
char *get_kata(){
    return current_kata;
}

/* Proseudr get_panjang_kata */
int get_panjang_kata(){
    return panjang_kata;
}

/* Proseudur eop masing-masing query */
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
/* Prosedur eop untuk berhenti */
int eop_query(char query[]){
    if (query[indeks] == ';')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/* Prosedur Cari Data */
void CARI(char nama_kolom[50]){
    //jika nama kolom nya "id"
    if (strcmp(nama_kolom, "id") == 0)
    {
        for ( i = 0; i < n; i++)
        {
            if (strcmp(input[i].id, temp_id) == 0)
            {
                //salin data ke array hasil akhir
                strcpy(hasil[m].id, input[i].id);
                strcpy(hasil[m].nama, input[i].nama);
                strcpy(hasil[m].kelas, input[i].kelas);
                m++;
            }
        }
    }
    //jika nama kolom nya "nama"
    else if (strcmp(nama_kolom, "nama") == 0)
    {
        for ( i = 0; i < n; i++)
        {
            //salin data ke array hasil akhir
            if (strcmp(input[i].nama, temp_nama) == 0)
            {
                strcpy(hasil[m].id, input[i].id);
                strcpy(hasil[m].nama, input[i].nama);
                strcpy(hasil[m].kelas, input[i].kelas);
                m++;
            }
        }
    }
    //jika nama kolom nya "kelas"
    else
    {
        for ( i = 0; i < n; i++)
        {
            if (strcmp(input[i].kelas, temp_kelas) == 0)
            {
                //salin data ke array hasil akhir
                strcpy(hasil[m].id, input[i].id);
                strcpy(hasil[m].nama, input[i].nama);
                strcpy(hasil[m].kelas, input[i].kelas);
                m++;
            }
        }
    }
}

/* Prosedur tampil hasil akhir */
void TAMPIL(){
    int panjang_id, panjang_nama, panjang_kelas;                //var. panjang data terpanjang
    int spasi_id, spasi_nama, spasi_kelas;                      //var. spasi untuk perulangan tampil data
    int spasi_minus_id, spasi_minus_nama, spasi_minus_kelas;    //var. spasi minus

    //mencari data dengan kata terpanjang
    panjang_id = strlen(hasil[0].id);
    panjang_nama = strlen(hasil[0].nama);
    panjang_kelas = strlen(hasil[0].kelas);
    for ( i = 0; i < m; i++)
    {
        if (panjang_id < strlen(hasil[i].id))
        {
            panjang_id = strlen(hasil[i].id);
        }
        if (panjang_nama < strlen(hasil[i].nama))
        {
            panjang_nama = strlen(hasil[i].nama);
        }
        if (panjang_kelas < strlen(hasil[i].kelas))
        {
            panjang_kelas = strlen(hasil[i].kelas);
        }   
    }

    //menampung spasi minus jika judul kolom lebih panjang dari kata terpanjang
    if (strlen("ID Kereta") >= panjang_id)
    {
        spasi_minus_id = strlen("ID Kereta") - panjang_id;
    }

    if (strlen("Nama Kereta") >= panjang_nama)
    {
        spasi_minus_nama = strlen("Nama Kereta") - panjang_nama;
    }

    if (strlen("Kelas") >= panjang_kelas)
    {
        spasi_minus_kelas = strlen("Kelas") - panjang_kelas;
    }
    
    printf("TABEL HASIL PENCARIAN\n");
    
    //menampilkan data dalam bentuk tabel
    //print garis tabel
    if (strlen("ID Kereta") >= panjang_id)
    {
        garis(panjang_id+4+spasi_minus_id);
    }
    else
    {
        garis(panjang_id+4);
    }
    
    if (strlen("Nama Kereta") >= panjang_nama)
    {
        garis(panjang_nama+3+spasi_minus_nama);
    }
    else
    {
        garis(panjang_nama+3);
    }
    
    if (strlen("Kelas") >= panjang_kelas)
    {
        garis(panjang_kelas+3+spasi_minus_kelas);
    }
    else
    {
        garis(panjang_kelas+3);
    }
    
    
    printf("\n| ID Kereta");
    if (strlen("ID Kereta") > panjang_id)                           //jika judul kolom lebih panjang dari kata terpanjang
    {
        printf(" |");
    }
    else
    {
        for ( i = 0; i < panjang_id - strlen("ID Kereta"); i++)
        {
            printf(" ");
        }
        printf(" |");
    }

    printf(" Nama Kereta");
    if (strlen("Nama Kereta") > panjang_nama)                       //jika judul kolom lebih panjang dari kata terpanjang
    {
        printf(" |");
    }
    else
    {
        for ( i = 0; i < panjang_nama - strlen("Nama Kereta"); i++)
        {
            printf(" ");
        }
        printf(" |");
    }
    
    printf(" Kelas");
    if (strlen("Kelas") >= panjang_kelas)                            //jika judul kolom lebih panjang dari kata terpanjang
    {
        printf(" |\n");
    }
    else
    {
        for ( i = 0; i < panjang_kelas - strlen("Kelas"); i++)
        {
            printf(" ");
        }
        printf(" |\n");
    }

    //print garis
    if (strlen("ID Kereta") >= panjang_id)
    {
        garis(panjang_id+4+spasi_minus_id);
    }
    else
    {
        garis(panjang_id+4);
    }
    
    if (strlen("Nama Kereta") >= panjang_nama)
    {
        garis(panjang_nama+3+spasi_minus_nama);
    }
    else
    {
        garis(panjang_nama+3);
    }
    
    if (strlen("Kelas") >= panjang_kelas)
    {
        garis(panjang_kelas+3+spasi_minus_kelas);
    }
    else
    {
        garis(panjang_kelas+3);
    }
    printf("\n");

    //menampilkan isi array hasil akhir setelah di cari datanya
    for ( i = 0; i < m; i++)
    {
        //--------------- Tampil ID ----------------------
        if (strlen("ID Kereta") < panjang_id)
        {
            spasi_id = panjang_id - strlen(hasil[i].id);
            printf("| %s", hasil[i].id);
            for ( j = 0; j < spasi_id; j++)
            {
                printf(" ");
            }
            printf(" |");
        }
        else
        {
            spasi_id = panjang_id - strlen(hasil[i].id);
            printf("| %s", hasil[i].id);
            for ( j = 0; j < spasi_id+spasi_minus_id; j++)
            {
                printf(" ");
            }
            printf(" |");
        }
              
        
        //-------------- Tampil Nama ---------------------
        if (strlen("Nama Kereta") < panjang_nama)
        {
            spasi_nama = panjang_nama - strlen(hasil[i].nama);
            printf(" %s", hasil[i].nama);
            for ( j = 0; j < spasi_nama; j++)
            {
                printf(" ");
            }
            printf(" |");
        }
        else
        {
            spasi_nama = panjang_nama - strlen(hasil[i].nama);
            printf(" %s", hasil[i].nama);
            for ( j = 0; j < spasi_nama + spasi_minus_nama; j++)
            {
                printf(" ");
            }
            printf(" |");
        }

        //------------- Tampil Kelas ---------------------
        if (strlen("Kelas") < panjang_kelas)
        {
            spasi_kelas = panjang_kelas - strlen(hasil[i].kelas);
            printf(" %s", hasil[i].kelas);
            for ( j = 0; j < spasi_kelas; j++)
            {
                printf(" ");
            }
            printf(" |\n");
        }
        else
        {
            spasi_kelas = panjang_kelas - strlen(hasil[i].kelas);
            printf(" %s", hasil[i].kelas);
            for ( j = 0; j < spasi_kelas+spasi_minus_kelas; j++)
            {
                printf(" ");
            }
            printf(" |\n");
        }   
    }

    //print garis
    if (strlen("ID Kereta") >= panjang_id)
    {
        garis(panjang_id+4+spasi_minus_id);
    }
    else
    {
        garis(panjang_id+4);
    }
    
    if (strlen("Nama Kereta") >= panjang_nama)
    {
        garis(panjang_nama+3+spasi_minus_nama);
    }
    else
    {
        garis(panjang_nama+3);
    }
    
    if (strlen("Kelas") >= panjang_kelas)
    {
        garis(panjang_kelas+3+spasi_minus_kelas);
    }
    else
    {
        garis(panjang_kelas+3);
    }    
    printf("\n");
    printf("%d data dalam tabel.\n", m);
}

/*  Prosedur Print garis tabel */
void garis(int panjang_id){
    for ( i = 0; i < panjang_id ; i++)
    {
        printf("=");
    }
}