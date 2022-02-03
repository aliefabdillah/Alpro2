//Materi Praktek Arsip Beruntun

//contoh progam READ arsip beruntun
#include <stdio.h>
#include <string.h>
/* 
typedef struct 
{
    char nim[20];
    char nama[50];
    char jurusan[20];
}data_mahasiswa;

int main(){
    int i, n=0;

    data_mahasiswa mhs[50];   //deklarasi rekaman

    FILE *fmahasiswa;     //deklarasi menghubungkan ke file yang akan di akses
    fmahasiswa = fopen("data_mahasiswa.dat", "r");
    fscanf(fmahasiswa, "%s %s %s",mhs[n].nim, mhs[n].nama, mhs[n].jurusan);    

    if (strcmp(mhs[n].nim, "####") == 0)
    {
        printf("File Kosong.\n");
    }
    else
    {
        while (strcmp(mhs[n].nim, "####")!=0)
        {
            n++;
            fscanf(fmahasiswa, "%s %s %s", mhs[n].nim, mhs[n].nama, mhs[n].jurusan);
        }

        printf("Data Mahasiswa:\n");
        for ( i = 0; i < n; i++)
        {
            printf("%s %s %s\n", mhs[i].nim, mhs[i].nama, mhs[i].jurusan);
        }
    }
    //menutup file 
    fclose(fmahasiswa);

    return 0;
}
 */

//contoh progam WRITE Sequential file
/* 
typedef struct 
{
    char nim[20];
    char nama[50];
    char jurusan[20];
}data_mahasiswa;

int main(){
    int i, n = 0;
    data_mahasiswa mhs[50];
    FILE *fmahasiswa;
    fmahasiswa = fopen("data_mahasiswa.dat", "w");

    scanf("%s %s %s", mhs[n].nim, mhs[n].nama, mhs[n].jurusan);

    while (strcmp(mhs[n].nim, "####") != 0)
    {
        fprintf(fmahasiswa, "%s %s %s\n", mhs[n].nim, mhs[n].nama, mhs[n].jurusan);
        n++;
        scanf("%s %s %s", mhs[n].nim, mhs[n].nama, mhs[n].jurusan);
    }

    fprintf(fmahasiswa, "#### #### ####\n");

    fclose(fmahasiswa);

    return 0;
}
 */

//contoh progam APPEND Arsip beruntun
/* 
typedef struct 
{
    char nim[20];
    char nama[50];
    char jurusan[20];
}data_mahasiswa;

int main(){
    int i, n=0;

    data_mahasiswa mhs[50];   //deklarasi rekaman

    FILE *fmahasiswa;     //deklarasi menghubungkan ke file yang akan di akses
    fmahasiswa = fopen("data_mahasiswa.dat", "r");
    fscanf(fmahasiswa, "%s %s %s",mhs[n].nim, mhs[n].nama, mhs[n].jurusan);

    if (strcmp(mhs[n].nim, "####") == 0)
    {
        printf("File Kosong.\n");
    }
    else
    {
        while (strcmp(mhs[n].nim, "####")!=0)
        {
            n++;
            fscanf(fmahasiswa, "%s %s %s", mhs[n].nim, mhs[n].nama, mhs[n].jurusan);
        }

        scanf("%s %s %s", mhs[n].nim, mhs[n].nama, mhs[n].jurusan);
        while (strcmp(mhs[n].nim, "####") != 0)
        {
            n++;
            scanf("%s %s %s", mhs[n].nim, mhs[n].nama, mhs[n].jurusan);
        }
    }

    fclose(fmahasiswa);

    fmahasiswa = fopen("data_mahasiswa.dat", "w");
    for ( i = 0; i < n; i++)
    {
        fprintf(fmahasiswa, "%s %s %s\n", mhs[i].nim, mhs[i].nama, mhs[i].jurusan);

    }
    fprintf(fmahasiswa, "#### #### ####\n");

    fclose(fmahasiswa);

    return 0;
}
 */

//latihan
typedef struct 
{
    char nama[20];
    char kode_jurusan[20];
    char kode_fakultas[20];
}data_mahasiswa;

typedef struct 
{
    char kd_jurusan[20];
    char nama_jurusan[20];
}data_jurusan;

typedef struct 
{
    char kd_fakultas[20];
    char nama_fakultas[20];
}data_fakultas;

int main(){
    int i, n=0, m=0, k=0;
    data_mahasiswa mhs[50];
    data_jurusan jrsn [50];
    data_fakultas fklts[50];

    FILE *fmahasiswa;
    FILE *fjurusan;
    FILE *ffakultas;

    fmahasiswa = fopen("mahasiswa.dat", "r");
    fjurusan = fopen("jurusan.dat", "r");
    ffakultas = fopen("fakultas.dat", "r");

    fscanf(fmahasiswa, "%s %s %s", mhs[n].nama, mhs[n].kode_jurusan, mhs[n].kode_fakultas);
    fscanf(fjurusan, "%s %s", jrsn[m].kd_jurusan, jrsn[m].nama_jurusan);
    fscanf(ffakultas, "%s %s", fklts[k].kd_fakultas, fklts[k].nama_fakultas);

    if (strcmp(mhs[n].nama, "####") == 0)
    {
        printf("File Kosong\n");
    }
    else
    {
        while(strcmp(mhs[n].nama, "####")!=0)
        {
            if ((strcmp(mhs[n].kode_jurusan, jrsn[m].kd_jurusan)!=0))
            {
                m++;
            }
            if(strcmp(mhs[n].kode_fakultas, fklts[k].kd_fakultas)!=0)
            {
                k++;
            }
            else
            {
                printf("%s ", mhs[n].nama);
                printf("%s ", jrsn[m].nama_jurusan);
                printf("%s\n", fklts[k].nama_fakultas);
                
                n++;
                fscanf(fmahasiswa, "%s %s %s", mhs[n].nama, mhs[n].kode_jurusan, mhs[n].kode_fakultas);
            }
        }
    }

    fclose(fmahasiswa);
    fclose(fjurusan);
    fclose(ffakultas);

    return 0;
}

        