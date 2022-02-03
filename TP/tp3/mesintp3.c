/*Saya Alief Muhammad Abdillah 2003623 mengerjakan TP3 dalam mata kuliah Algoritma dan Pemrograman 2
untuk keberkahan-Nya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/

//bagian mesin
#include "headertp3.h"

//===== PROSEDUR INPUT =====
void input(){
    int a[10], b[10], n[10];         //variabel a untuk indeks 0, variabel b untuk indeks 1, variabel n untuk indeks yang dicari
    int bakteri;                    // variabel untuk jumlah bakteri
    
    scanf("%d", &bakteri);          //input untuk jumlah bakteri

    for (i = 0; i < bakteri; i++)   //masukan untuk indeks 0, indeks 1 dan indeks yang di cari jumlahnya
    {                               //perulangan sebanyak jumlah bakteri
        scanf("%d", &a[i]);
        scanf("%d", &b[i]);
        scanf("%d", &n[i]);
    }
    
    int x = 0;                      //variabel pengganti iterator
    int temp = 0;                   //variabel pengganti iterator
    hitung(a, b, 0, n, 0, bakteri); //pemanggilan prosedur hitung
    
}

//===== PROSEDUR HITUNG ======
void hitung(int a[], int b[], int x, int n[], int temp, int bakteri){
    if(temp < bakteri){                              // syarat rekursif jika temp masih kurang dari jumlah bakteri
        if (x == 0)                                  // syarat x == 0 
        {
            hasil[temp][x] = a[temp];                // maka hasil[0][0] = indeks 0/a[0].....
            hitung(a, b, x+1, n, temp, bakteri);     //prosedur rekursif x + 1
        }
        else if (x == 1)                             //jika x = 1
        {
            hasil[temp][x] = b[temp];                //hasil[temp][1] = b[0]/b[1] ....
            hitung(a, b, x+1, n, temp, bakteri);     //prosedur rekursif x + 1
        }
        else if ((x >= 2) && (x <= n[temp]))         //syarat jika x > 2 dan kurang dari n bakteri
        {
            hasil[temp][x] = (2 * hasil[temp][x-1]) + (hasil[temp][x-2] * hasil[temp][x-2]);    //maka hasil[temp][x] = 2 * x - 1 + x - 2 pangkat 2
            if (x == n[temp])                                
            {                                                   //jika nilai x sudah sama dengan temp
                hitung(a, b, x-n[temp], n, temp+1, bakteri);    //prosedur rekursif dengan nilai x yang di kurang nilai x saat ini dan temp nya di tambah 1
            }
            else                                                //jika nilai x belum sama dengan temp
            {
                hitung(a, b, x+1, n, temp, bakteri);            //prosedur rekursif dengan x + 1
            }
        }
    }
    else if (temp == bakteri)                   //jika nilai temp sudah = bakteri maka rekursif berhenti dan masuk proses print
    {
        for (i = 0; i < temp; i++)              //print sebanyak temp atau jumlah bakteri
        {
            printf("%d\n", hasil[i][n[i]]);     //print jumlah bakteri di indeks yang ingin di cari
        }
    }
    
}


    
    
    
    
    


    
   