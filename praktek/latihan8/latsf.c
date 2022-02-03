#include <stdio.h>
#include <string.h>

typedef struct
{
    char id[10];
    char nama[50];
    char jurusan[20];
    char fakultas[20];
}dataMahasiswa;

int main()
{
    int i, n = 0;

    dataMahasiswa mhs[50];

    // Read Mahasiswa
    FILE *fmahasiswa;
    fmahasiswa = fopen("Mahasiswa.dat", "r");

    fscanf(fmahasiswa, "%s %s %s", mhs[n].nama, mhs[n].jurusan, mhs[n].fakultas);
    if(strcmp(mhs[n].nama, "####") == 0){
        printf("File Kosong!\n");
    }
    else{
        while(strcmp(mhs[n].nama, "####") != 0)
        {
            n++;
            fscanf(fmahasiswa, "%s %s %s", mhs[n].nama, mhs[n].jurusan, mhs[n].fakultas);
        }
    }
    fclose(fmahasiswa);
    
    // Read Jurusan
    int j = 0;
    fmahasiswa = fopen("Jurusan.dat", "r");
    dataMahasiswa jurusan[10];
    fscanf(fmahasiswa, "%s %s", jurusan[j].id, jurusan[j].jurusan);
    if(strcmp(jurusan[j].id, "####") == 0){
        printf("File Kosong!\n");
    }
    else{
        while(strcmp(jurusan[j].id, "####") != 0)
        {
            j++;
            fscanf(fmahasiswa, "%s %s", jurusan[j].id, jurusan[j].jurusan);
        }
    }
    fclose(fmahasiswa);

    // Cari dan ubah id untuk jurusan
    int z;
    for(i = 0; i < n; i++){
        for(z = 0; z < j; z++){
            if(strcmp(mhs[i].jurusan, jurusan[z].id) == 0){
                strcpy(mhs[i].jurusan, jurusan[z].jurusan);
            }
        }
    }

    // Read Fakultas
    int f = 0;
    fmahasiswa = fopen("Fakultas.dat", "r");
    dataMahasiswa fakultas[10];
    fscanf(fmahasiswa, "%s %s", fakultas[f].id, fakultas[f].fakultas);
    if(strcmp(fakultas[f].id, "####") == 0){
        printf("File Kosong!\n");
    }
    else{
        while(strcmp(fakultas[f].id, "####") != 0)
        {
            f++;
            fscanf(fmahasiswa, "%s %s", fakultas[f].id, fakultas[f].fakultas);
        }
    }
    fclose(fmahasiswa);
    
    // Cari dan ubah id untuk fakultas
    for(i = 0; i < n; i++){
        for(z = 0; z < f; z++){
            if(strcmp(mhs[i].fakultas, fakultas[z].id) == 0){
                strcpy(mhs[i].fakultas, fakultas[z].fakultas);
            }
        }
    }

    // Print hasilnya
    for(i = 0; i < n; i++){
        printf("%s %s %s\n", mhs[i].nama, mhs[i].jurusan, mhs[i].fakultas);
    }
    
    
    return 0;
}