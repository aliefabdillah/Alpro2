//Materi Merger Array/Tabel
/*
    terdapat 2 cara merge :
    1. Merge tidak urut
    2. Merge urut
*/

#include <stdio.h>

//contoh progam merge tidak urut
/*
    tabel 1 = 5, 3, 7, 8 
    tabel 2 = 2, 9, 4, 1
    tabel akhir = 5, 3, 7, 8, 2, 9, 4, 1
*/
/*
int main(){
    int tabel1[4];
    int tabel2[4];

    int tabel_akhir[8];
    int i;

    //masukan tabel 1
    printf("masukan angka tabel1:\n");
    for (i = 0; i < 4; i++)
    {
        scanf("%d", &tabel1[i]);
    }
    printf("\n");

    //masukan tabel 2
    printf("masukan angka tabel2:\n");
    for (i = 0; i < 4; i++)
    {
        scanf("%d", &tabel2[i]);
    }
    printf("\n");

    //proses penggabungan
    for ( i = 0; i < 4; i++)
    {
        tabel_akhir[i] = tabel1[i]; 
    }
     
    for ( i = 4; i < 8; i++)
    {
        tabel_akhir[i] = tabel2[i-4];
    }
    
    for ( i = 0; i < 8; i++)
    {
        printf("%d ", tabel_akhir[i]);
    }
    
    return 0;
}
*/

//contoh progam merge urut
/*
    tabel 1 = 5, 3, 7, 8, 1
    tabel 2 = 2, 9, 4,
    tabel akhir = 1, 2, 3, 4, 5, 6, 7, 8, 9
*/

int main(){
    int tabel1[5];
    int tabel2[3];
    int tabel_akhir[8];

    //iterator
    int i,j;
    int penghitung1, penghitung2, penghitung3;

    //masukan tabel 1
    printf("masukan angka tabel1:\n");
    for (penghitung1 = 0; penghitung1 < 5; penghitung1++)
    {
        scanf("%d", &tabel1[penghitung1]);
    }
    printf("\n");

    //masukan tabel 2
    printf("masukan angka tabel2:\n");
    for (penghitung2 = 0; penghitung2 < 3; penghitung2++)
    {
        scanf("%d", &tabel2[penghitung2]);
    }
    printf("\n");
    
    //proses pengurutan array 1
    int temp;
    for ( i = 1; i < 5; i++)
    {
        temp = tabel1[i];
        j = i -1;
        while (j >= 0 && temp < tabel1[j])
        {
            tabel1[j+1] = tabel1[j];
            j--;
        }
        tabel1[j+1] = temp;
    }

    //proses pengurutuan array 2
    for ( i = 1; i < 3; i++)
    {
        temp = tabel2[i];
        j = i -1;
        while (j >= 0 && temp < tabel2[j])
        {
            tabel2[j+1] = tabel2[j];
            j--;
        }
        tabel2[j+1] = temp;
    }

    for ( i = 0; i < 5; i++)
    {
        printf("%d ", tabel1[i]);
    }
    printf("\n");
    for ( i = 0; i < 3; i++)
    {
        printf("%d ", tabel2[i]);
    }
    printf("\n");

    //proses penggabungan 2 array yang telah di urut
    //inisialisasi indeks awal tiap tabel
    penghitung1 = 0;
    penghitung2 = 0;
    penghitung3 = 0;
    while ((penghitung1 < 5) && (penghitung2 < 3))
    {
        if (tabel1[penghitung1] < tabel2[penghitung2])
        {
            tabel_akhir[penghitung3] = tabel1[penghitung1];
            penghitung1 = penghitung1 + 1;
            penghitung3 = penghitung3 + 1;
        }
        else if(tabel2[penghitung2] < tabel1[penghitung1])
        {
            tabel_akhir[penghitung3] = tabel2[penghitung2];
            penghitung2 = penghitung2 + 1;
            penghitung3 = penghitung3 + 1;
        }
        else
        {
            tabel_akhir[penghitung3] = tabel1[penghitung1];
            penghitung1 = penghitung1 + 1;
            penghitung3 = penghitung3 + 1;
            tabel_akhir[penghitung3] = tabel2[penghitung2];
            penghitung2 = penghitung2 + 1;
            penghitung3 = penghitung3 + 1;
        }
    }

    //jika setelah di bandingkan dan digabungkan masih ada sisa pada tabel1/tabel2
    if (penghitung1 < 5)
    {
        for ( i = penghitung1; i < 5; i++)
        {
            tabel_akhir[penghitung3] = tabel1[i];
            penghitung3 = penghitung3 + 1;
        }
    }
    
    if (penghitung2 < 3)
    {
        for ( i = penghitung2; i < 3; i++)
        {
            tabel_akhir[penghitung3] = tabel2[i];
            penghitung3 = penghitung3 + 1;
        }
    }
    
    //print akhir
    for ( i = 0; i < 8; i++)
    {
        printf("%d ", tabel_akhir[i]);
    }
    
    
    return 0;
}