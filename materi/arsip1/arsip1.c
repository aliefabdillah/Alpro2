//Materi Arsip beruntun / Sequential File
/* 
    1. Rekaman/Record
        - Data yang memiliki tipe yang sama
    2. Arsip Beruntun
        - Sebuah file yang berisi kumpulan rekaman kolom-kolom data
        tertentu sesuai dengan kebutuhan, tapi dalam sebuah arsip beruntun, nama-nama 
        kolom tidak ikut disimpan didalam file sehingga file hanya berisi recordnya saja
        - Diakhir dengan data dummy atau EOF (End of file)
 */

#include <stdio.h>
#include <string.h>
//Membuat Arsip Beruntun / Progam
/* 
typedef struct{
    char nim[10];
    char nama[100];
    char nilai[2];
}nilai_matkul;

int main(){
    nilai_matkul rekaman;   //deklarasi rekaman
    FILE *arsipMatKul;     //deklarasi menghubungkan ke file yang akan di akses
    arsipMatKul = fopen("ArsipMatKul.dat", "w");    
    //mengaakses file, fopen(perintah membukan), "w"/write 
    //write = jika file sudah ada maka isinya akan ditimpa, jika blum ada isinya akan di isi di tempat yang sejajar dengan progam yanv kita buat

    //memulai proses file
    printf("Tuliskan rekaman satu per satu: \n");
    printf("Masuka Nim : \n");
    scanf("%s", &rekaman.nim);

    while (strcmp(rekaman.nim, "XXXXXXXX") != 0)    //mengecek apakah masukan tidak sama dengan EOF
    {
        //proses
        printf("masukan nama : \n");
        scanf("%s", &rekaman.nama);
        printf("masukan nilai : \n");
        scanf("%s", &rekaman.nilai);

        //menuliskan data pada user ke dalam file
        fprintf(arsipMatKul, "%s %s %s\n", 
        rekaman.nim, rekaman.nama, rekaman.nilai);

        //iterasi untuk putaran berikutnya
        printf("masukan nim : \n");
        scanf("%s", rekaman.nim);
    }

    //jika looping sudah selesai maka masukan data dummy ke dalam sequential filenya
    fprintf(arsipMatKul, "%s, %s, %s\n", "XXXXXXXX", "XXX", "X");

    //menutup file 
    fclose(arsipMatKul);

    return 0;
    
}
 */

//Membaca arsip Beruntun
/* 
    1. Arsip Kosong :
        - arsip yang hanya berisi data dummy/EOF (XXXXX XXX X)
    2. Arsip Berisi rekaman:
        - arsip yang berisi data asli dan data dummy
 */

//Membaca arsip beruntun tanpa pencarian
/* 
typedef struct{
    char nim[10];
    char nama[100];
    char nilai[2];
}nilai_matkul;

int main(){
    nilai_matkul rekaman;   //deklarasi rekaman
    FILE *arsipMatKul;     //deklarasi menghubungkan ke file yang akan di akses
    arsipMatKul = fopen("ArsipMatKul.dat", "r");
    //file harus sudah berisi data asli dan data dummy/EOF
    //mode pengaksesan adalah r/read artinya membaca file yang sudah ada

    //proses pembacaan
    printf("isi arsip beruntun adalah : \n");
    fscanf(arsipMatKul, "%s %s %s\n", &rekaman.nim, &rekaman.nama, &rekaman.nilai);


    //jika pembacaan pertama adalah data dummy/EOF
    if (strcmp(rekaman.nim, "XXXXXXXX") == 0)
    {
        printf("Arsip Kosong\n");
    }
    else
    {
        do
        {
            printf("nim : %s\n", rekaman.nim);
            printf("nama : %s\n", rekaman.nama);
            printf("nilai : %s\n", rekaman.nilai);
            printf("----------------\n");

            //iterasi/perulangan untuk data berikutnya
            fscanf(arsipMatKul, "%s, %s,%s\n", &rekaman.nim, &rekaman.nama, &rekaman.nilai);

        } while (strcmp(rekaman.nim, "XXXXXXXX") != 0);
    }

    fclose(arsipMatKul);

    return 0;
}
 */

//membaca arsip beruntun dengan pencarian
/* 
typedef struct{
    char nim[10];
    char nama[100];
    char nilai[2];
}nilai_matkul;

int main(){
    nilai_matkul rekaman;   //deklarasi rekaman
    FILE *arsipMatKul;     //deklarasi menghubungkan ke file yang akan di akses
    arsipMatKul = fopen("ArsipMatKul.dat", "r");
    //file harus sudah berisi data asli dan data dummy/EOF
    //mode pengaksesan adalah r/read artinya membaca file yang sudah ada

    char data_cari[10];
    printf("Masukan Nim yang akan dicari : \n");
    scanf("%s", &data_cari);
    fscanf(arsipMatKul, "%s %s %s\n", &rekaman.nim, &rekaman.nama, &rekaman.nilai);

    //pengecekan data pertama EOF atau bukan
    if (strcmp(rekaman.nim, "XXXXXXXX") == 0)
    {
        printf("Arsip Kosong\n");
    }
    else
    {
        //jika data yang dicari merupakan eof
        if (strcmp(data_cari, "XXXXXXXX") == 0)
        {
            printf("tidak ditemukan\n");
        }
        //jika tidak
        else
        {
            //lakukan perulangan pencarian dengan sequential search
            while ((strcmp(rekaman.nim, "XXXXXXXX") != 0) && 
            (strcmp(rekaman.nim, data_cari) !=0 ))
            {
                //iterasi pencarian data berikutnya
                fscanf(arsipMatKul, "%s %s %s\n", &rekaman.nim, &rekaman.nama, &rekaman.nilai);

            }

            if (strcmp(rekaman.nim, data_cari) == 0)
            {
                printf("hasil pencarian : \n");
                printf("nim : %s\n", rekaman.nim);
                printf("nama : %s\n", rekaman.nama);
                printf("nilai : %s\n", rekaman.nilai);
                printf("----------------\n");
            }
            else
            {
                printf("tidak ditemukan\n");
            }
        }
    }

    fclose(arsipMatKul);
    return 0;
}
 */

//menyalin arsip beruntun
typedef struct{
    char nim[10];
    char nama[100];
    char nilai[2];
}nilai_matkul;

int main(){
    nilai_matkul rekaman;   //deklarasi rekaman
    FILE *arsipMatKul1;     //deklarasi menghubungkan ke file1
    FILE *arsipMatKul2;     //deklarasi menghubungkan ke file2
    arsipMatKul1 = fopen("ArsipMatKul.dat", "r");      //untuk file satu melakukan pembacaan/penyalinan    
    arsipMatKul2 = fopen("ArsipMatKul.dat", "w");      //untuk file dua melakukan mode penulisan dari file 1

    printf("mulai proses penyalinan file\n");
    //proses pembacaan dan penyalinan dari file 1
    fscanf(arsipMatKul1, "%s %s %s\n", &rekaman.nim, &rekaman.nama, &rekaman.nilai);

    //jika dalam file 1 adalah eof
    if (strcmp(rekaman.nim, "XXXXXXXX")== 0)
    {
        //langsung tulis eof di file 2
        fprintf(arsipMatKul2, "%s %s %s\n", "XXXXXXXX", "XXX", "X");

    }
    else
    {
        //melakukan pengulanagn pembacaan dan penulisan selama bukan EOF
        while (strcmp(rekaman.nim, "XXXXXXXX") != 0)
        {
            //menyimpan data dari file satu yang telah discan ke file 2
            fprintf(arsipMatKul2, "%s %s %s\n", rekaman.nim, rekaman.nama, rekaman.nilai);
            /*membaca file satu dan mengulangi perulangan selama bukan eof dan 
            data yang dibaca kembali disimpan ke file 2*/
            fscanf(arsipMatKul1, "%s %s %s\n", &rekaman.nim, &rekaman.nama, &rekaman.nilai);
        }
        
        //jika perulangan selesai maka masukan EOF ke file 2
        fprintf(arsipMatKul2, "%s %s %s\n", "XXXXXXXX", "XXX", "X");
    }

    printf("proses menyalin file selesai\n");

    fclose(arsipMatKul1);   //tutup file 1
    fclose(arsipMatKul2);   //tutup file 2

    return 0;
}
