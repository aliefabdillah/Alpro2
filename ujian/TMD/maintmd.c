/* 
    Saya Alief Muhammad Abdillah mengerjakan evaluasi Tugas Masa Depan dalam mata kuliah Algoritma dan 
    Pemrograman II untuk keberkahanNya maka saya tidak melakukan kecurangan seperti 
    yang telah dispesifikasikan. Aamiin.
 */

//bagian main
#include "headtmd.h"

int main(){

    system("cls");	
    printf("Selamat Datang di Database Management System (DBMS)\n");
    printf("Versi Saat ini : 4.0\n");
    printf("Tanggal: %s     Jam : %s\n", __DATE__, __TIME__);

    char aturan[10];
    printf("\nApakah ingin melihat aturan query? (ya/tidak) : ");
    scanf("%s", &aturan);

    if (strcmp(aturan, "ya") == 0)
    {
        printf("\n----- Aturan Query -----\n");
        printf("1. Mengupdate data pada tabel\n");
        printf(" ==> TAMBAH GANTI 'nama_tabel' 'id_barang' 'atribut1(Nama_barang Stok_barang) / atribut2'(Harga_barang jmlh_beli';\n");
        printf("\n2. Menambah data pada tabel\n");
        printf(" ==> TAMBAH 'nama_tabel' 'id_barang' 'atribut1(Nama_barang Stok_barang) / atribut2'(Harga_barang jmlh_beli';\n");
        printf("\n3. Menghapus data pada tabel\n");
        printf(" ==> HAPUS 'nama_tabel' 'id_barang';\n");
        printf("\n4. Menghapus seluruh data pada tabel\n");
        printf(" ==> HAPUS 'nama_tabel';\n");
        printf("\n5. Menampilkan data pada tabel\n");
        printf(" ==> TAMPIL 'nama tabel';\n");
    }
    
    int stop = 0;
    while (stop == 0)
    {
        printf("\nDBDMS > ");
        scanf(" %199[^\n]s", &query);
        int pjg_query = strlen(query);
        if (query[pjg_query-1] == ';')
        {
            start_kata(query);

        //---------------- Query STOP ----------------
        //untuk keluar dari aplikasi
            if (strcmp(get_kata(), "STOP") == 0)
            {
                if (eop_kata(query) == 1)
                {
                    stop = 1;
                }
                else
                {
                    printf("\nQuery salah, masukan dengan benar -_-\n");
                }
            }

        //---------------- Query TAMBAH ----------------
            else if (strcmp(get_kata(), "TAMBAH") == 0)
            {
                inc_kata(query);
            //---------------- Query TAMBAH GANTI ----------------
                if (strcmp(get_kata(), "GANTI") == 0)
                {
                    inc_kata(query);
                    if (strcmp(get_kata(), "tabel_beli") == 0)
                    {
                        GANTI("tabel_beli");
                    }
                    else if (strcmp(get_kata(), "tabel_nama") == 0)
                    {
                        GANTI("tabel_nama");
                    }
                    else
                    {
                        printf("\nNama tabel salah, masukan dengan benar -_-\n");
                    }
                }
            //--------------- Query TAMBAH -----------------------
                else if (strcmp(get_kata(), "tabel_beli") == 0)
                {
                    TAMBAH("tabel_beli");
                }
                else if (strcmp(get_kata(), "tabel_nama") == 0)
                {
                    TAMBAH("tabel_nama");
                }
                else
                {
                    printf("\nQuery salah, masukan dengan benar -_-\n");
                }
            }
        
        //--------------- Query GANTI ------------------------
            else if (strcmp(get_kata(), "GANTI") == 0)
            {
                inc_kata(query);
                if (strcmp(get_kata(), "tabel_beli") == 0)
                {
                    GANTI("tabel_beli");
                }
                else if (strcmp(get_kata(), "tabel_nama") == 0)
                {
                    GANTI("tabel_nama");
                }
                else
                {
                    printf("\nNama tabel salah, masukan dengan benar -_-\n");
                }
            }

        //------------- Query HAPUS -----------------------
            else if (strcmp(get_kata(), "HAPUS") == 0)
            {
                inc_kata(query);
                if (strcmp(get_kata(), "tabel_nama") == 0)
                {
                    if (eop_kata(query) == 0)
                    {
                        HAPUS("tabel_nama");            //Query Hapus satu data 
                    }
                    else
                    {
                        HAPUS_ALL("tabel_nama");        //Query Hapus seluruh data
                    }
                }
                else if (strcmp(get_kata(), "tabel_beli") == 0)
                {
                    if (eop_kata(query) == 0)
                    {
                        HAPUS("tabel_beli");           //Query Hapus Satu data
                    }
                    else
                    {
                        HAPUS_ALL("tabel_beli");       //Query Hapus seluruh data
                    }
                }
                else
                {
                    printf("\nNama tabel salah, masukan dengan benar -_-\n");
                }  
            }
        
        // ------------- Query TAMPIL -------------------------
            else if (strcmp(get_kata(), "TAMPIL") == 0)
            {
                inc_kata(query);
                if (strcmp(get_kata(), "tabel_nama") == 0)
                {
                    read("tabel_nama");
                    if (nm > 0)
                    {
                        TAMPIL("tabel_nama");
                    }  
                }
                else if (strcmp(get_kata(), "tabel_beli") == 0)
                {
                    read("tabel_beli");
                    if (hr > 0)
                    {
                        TAMPIL("tabel_beli");
                    }
                }
                else
                {
                    printf("\nNama tabel salah, masukan dengan benar -_-\n");
                }   
            }
            
        //------------ Jika Query Salah ----------------------
            else
            {
                printf("\nQuery salah, masukan dengan benar -_-\n");
            }
        }
        else
        {
            printf("\nPakai tanda ';' (titik koma) pada akhir Query\n");
        }
    }
    system("cls");
    printf("\nJumpa Lagi!, Semoga harimu Menyenangkan :)\n");
    system("exit");

    return 0;
}