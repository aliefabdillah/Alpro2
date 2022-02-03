//Materi Arsip Lanjutan
/* 
    penggabungan arsip beruntun :
    1. Tidak urut
    2. Urut
 */

//pengabbungan tidak urut
/* 
    data-data:
    -ArsipMatkul1:
    13501085 Nana A
    13501096 Titin A
    13501098 Cosmo A
    XXXXXXXX XXXX X

    -ArsipMatkul2:
    13501086 Dera B
    13501091 Jupiter A
    13501097 Mars A
    13501099 Nebula B
    XXXXXXXX XXXX X

    -ArsipMatKul3:
    13501085 Nana A
    13501096 Titin A
    13501098 Cosmo A
    13501086 Dera B
    13501091 Jupiter A
    13501097 Mars A
    13501099 Nebula B
    XXXXXXXX XXXX X
 */

#include <stdio.h>
#include <string.h>

//kode progam penggabunagn arsip tidak urut
/*
typedef struct{
    char nim[10];
    char nama[100];
    char nilai[2];
}nilai_matkul;

int main(){
    nilai_matkul rekaman;
    FILE *arsipMatkul1;
    FILE *arsipMatkul2;
    FILE *arsipMatkul3;
    arsipMatkul1 = fopen("ArsipMatKul1.dat", "r");
    arsipMatkul2 = fopen("ArsipMatKul2.dat", "r");
    arsipMatkul3 = fopen("ArsipMatKul3.dat", "w");

    fscanf(arsipMatkul1, "%s %s %s\n", &rekaman.nim, &rekaman.nama, &rekaman.nilai);
    while (strcmp(rekaman.nim,"XXXXXXXX")!=0)
    {
        fprintf(arsipMatkul3, "%s %s %s\n", rekaman.nim, rekaman.nama, rekaman.nilai);
        fscanf(arsipMatkul1, "%s %s %s\n", &rekaman.nim, &rekaman.nama, &rekaman.nilai);
    }
    
    fscanf(arsipMatkul2, "%s %s %s\n", &rekaman.nim, &rekaman.nama, &rekaman.nilai);
    while (strcmp(rekaman.nim,"XXXXXXXX")!=0)
    {
        fprintf(arsipMatkul3, "%s %s %s\n", rekaman.nim, rekaman.nama, rekaman.nilai);
        fscanf(arsipMatkul2, "%s %s %s\n", &rekaman.nim, &rekaman.nama, &rekaman.nilai);
    }

    fprintf(arsipMatkul3, "%s %s %s\n", "XXXXXXXX", "XXXX", "X");
    printf("proses penggabungan selesai\n");

    fclose(arsipMatkul1);
    fclose(arsipMatkul2);
    fclose(arsipMatkul3);

    return 0;
}
*/

//pengabbungan urut (sesuai nim)
/* 
    data-data:
    -ArsipMatkul1:
    13501085 Nana A
    13501096 Titin A
    13501098 Cosmo A
    XXXXXXXX XXXX X

    -ArsipMatkul2:
    13501086 Dera B
    13501091 Jupiter A
    13501097 Mars A
    13501099 Nebula B
    XXXXXXXX XXXX X

    -ArsipMatKul4:
    13501085 Nana A
    13501086 Dera B
    13501091 Jupiter A
    13501096 Titin A
    13501097 Mars A
    13501098 Cosmo A
    13501099 Nebula B
    XXXXXXXX XXXX X
 */

//kode progam penggabungan file urut
/*
typedef struct{
    char nim[10];
    char nama[100];
    char nilai[2];
}nilai_matkul;

int main(){
    nilai_matkul rekaman1;
    nilai_matkul rekaman2;

    FILE *arsipMatkul1;
    FILE *arsipMatkul2;
    FILE *arsipMatkul4;
    arsipMatkul1 = fopen("ArsipMatKul1.dat", "r");
    arsipMatkul2 = fopen("ArsipMatKul2.dat", "r");
    arsipMatkul4 = fopen("ArsipMatKul4.dat", "w");

    printf("Mulai Proses Penggabungan\n");

    fscanf(arsipMatkul1, "%s %s %s\n", &rekaman1.nim, &rekaman1.nama, &rekaman1.nilai);
    fscanf(arsipMatkul2, "%s %s %s\n", &rekaman2.nim, &rekaman2.nama, &rekaman2.nilai);
    
    while ((strcmp(rekaman1.nim, "XXXXXXXX") != 0) && 
    (strcmp(rekaman2.nim, "XXXXXXXX")!=0));
    {
        if (strcmp(rekaman1.nim, rekaman2.nim)<1)
        {
            fprintf(arsipMatkul4, "%s %s %s\n", rekaman1.nim, rekaman1.nama, rekaman1.nilai);
            fscanf(arsipMatkul1, "%s %s %s\n", &rekaman1.nim, &rekaman1.nama, &rekaman1.nilai);
        }
        else
        {
            fprintf(arsipMatkul4, "%s %s %s\n", rekaman2.nim, rekaman2.nama, rekaman2.nilai);
            fscanf(arsipMatkul2, "%s %s %s\n", &rekaman2.nim, &rekaman2.nama, &rekaman2.nilai);
        }
    }
    
    while (strcmp(rekaman1.nim, "XXXXXXXX") != 0)
    {
        fprintf(arsipMatkul4, "%s %s %s\n", rekaman1.nim, rekaman1.nama, rekaman1.nilai);
        fscanf(arsipMatkul1, "%s %s %s\n", &rekaman1.nim, &rekaman1.nama, &rekaman1.nilai);
    }
     while (strcmp(rekaman2.nim, "XXXXXXXX") != 0)
    {
        fprintf(arsipMatkul4, "%s %s %s\n", rekaman2.nim, rekaman2.nama, rekaman2.nilai);
        fscanf(arsipMatkul2, "%s %s %s\n", &rekaman2.nim, &rekaman2.nama, &rekaman2.nilai);
    }
    
    fprintf(arsipMatkul4, "%s %s %s\n", "XXXXXXXX", "XXXX","X");
    printf("Proses Penggabungan selesai\n");

    fclose(arsipMatkul1);
    fclose(arsipMatkul2);
    fclose(arsipMatkul4);

    return 0;
}
*/

//operasi data pada arsip beruntun
/* 
    1. memasukkan data/insert dapat dalam posisi berikut:
    -Memasukan data di awal arsip beruntun
        -jika ada data yang akan dimasukan lebih kecil dari data paling
        awal yang ada pada arsip beruntun
    
    -Memasukan data di tengah arsip beruntun
        -jika data yang akan dimasukan berada di tengah arsip beruntun, artinya
        ada nilai yang lebih kecil dan lebih besar dari data baru
    
    -Memasukan data dibelakang arsip beruntun
        -jika data yang akan dimasukan berada di paling belakang karena nilainya
        lebih besar dari nilai paling belakang dari arsip beruntun
    
    2. Terutama untuk arsip beruntun yang terurut agar operasi lainnya lebih efektif
 */

//kode progam insert data dari arsip beruntun ke dalam array
typedef struct{
    char nim[10];
    char nama[100];
    char nilai[2];
}nilai_matkul;

int main(){
    int jumlahrek = 0;
    nilai_matkul temp[100];
    nilai_matkul rekaman, baru;

    FILE *arsipMatkul;
    arsipMatkul = fopen("ArsipMatKul.dat", "r");
    printf("Mulai proses insert isi file ke array");

    fscanf(arsipMatkul, "%s %s %s\n", &rekaman.nim, &rekaman.nama, &rekaman.nilai);

    if (strcmp(rekaman.nim, "XXXXXXXX") == 0)
    {
        printf("Arsip Kosong\n");
    }
    else
    {
        do
        {
            strcpy(temp[jumlahrek].nim, rekaman.nim);
            strcpy(temp[jumlahrek].nama, rekaman.nama);
            strcpy(temp[jumlahrek].nilai, rekaman.nilai);
            jumlahrek++;
            
            fscanf(arsipMatkul, "%s %s %s", &rekaman.nim, &rekaman.nama, &rekaman.nilai);

        } while (strcmp(rekaman.nim, "XXXXXXXX") != 0);
        
    }
    fclose(arsipMatkul);

    //proses memasukan data baru
    printf("proses masukan data baru\n");
    printf("masukan nim: ");
    scanf("%s", &baru.nim);
    printf("masukan nama: ");
    scanf("%s", &baru.nama);
    printf("masukan nilai: ");
    scanf("%s", &baru.nilai);

    //memasukan data ke dalam array temp
    if (strcmp(baru.nim, temp[0].nim)<0)
    {
        //rekaman baru nilainya lebih kecil dari data array awal
        //posisi ada paling atas dan geser semua array kebelakang
        int i;
        for ( i = jumlahrek-1; i >= 0; i--)
        {
            strcpy(temp[i+1].nim, temp[i].nim);
            strcpy(temp[i+1].nama, temp[i].nama);
            strcpy(temp[i+1].nilai, temp[i].nilai);
        }
        jumlahrek++;
        strcpy(temp[0].nim, baru.nim);
        strcpy(temp[0].nama, baru.nama);
        strcpy(temp[0].nilai, baru.nilai);       
    }
    else if(strcmp(baru.nim, temp[jumlahrek-1].nim) > 0)
    {
        //jika data baru nilainya lebih besar dari nim akhir
        //posisi data ada akhir
        strcpy(temp[jumlahrek].nim, baru.nim);
        strcpy(temp[jumlahrek].nama, baru.nama);
        strcpy(temp[jumlahrek].nilai, baru.nilai); 
        jumlahrek++;
    }
    else
    {
        //data baru posisinya ada di tengah
        int i = 0;
        int stop = 0;
        //cari posisi data baru
        while ((i<jumlahrek) && (stop==0))
        {
            if (strmcp(temp[i].nim, baru.nim)>0)
            {
                stop=1;
            }
            else
            {
                i++;
            }
        }

        int j;
        for ( j = jumlahrek-1; j >= i; j--)
        {
            strcpy(temp[j+1].nim, temp[j].nim);
            strcpy(temp[j+1].nilai, temp[j].nama);
            strcpy(temp[j+1].nama, temp[j].nilai);
        }
        strcpy(temp[i].nim, baru.nim);
        strcpy(temp[i].nama, baru.nama);
        strcpy(temp[i].nilai, baru.nilai);
        jumlahrek++;
    }

    //flush ke file / pindahkan ke file
    arsipMatkul = fopen("ArsipMatKul.dat", "w");
    int i;
    for ( i = 0; i < jumlahrek; i++)
    {
        fprintf(arsipMatkul, "%s %s %s", temp[i].nim, temp[i].nama, temp[i].nilai);
    }

    fprintf(arsipMatkul, "XXXXXXXX", "XXXX", "X");
    fclose(arsipMatkul);

    return 0;
}