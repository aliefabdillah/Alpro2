/*Saya Alief Muhammad Abdillah 2003623 mengerjakan TP4 dalam mata kuliah Algoritma dan Pemrograman 2
untuk keberkahan-Nya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/

//bagian mesin
#include "headtp4.h"

//===== Prosedur Input =====
void input(){
    scanf("%d", &n);            //perintah masukan n/jumlah array untuk masukan user

    //perulangan masukan nama, harga, dan nilai barang sebanyakan n
    for (i = 0; i < n; i++)
    {
        scanf("%s", barang[i]);
        scanf("%d", &harga[i]);
        scanf("%f", &nilai[i]);
    }

    //perintah masukan untuk metode sorting
    char metode[50];
    scanf("%s", metode);

    //perintah masukan untuk memilihi sorting naik/turun
    char naik_turun[50];
    scanf("%s", naik_turun);

    //perintah masukan untuk memilih patokan sorting berdasar nama/harga/nilai
    char patokan[50];
    scanf("%s", patokan);

    output(metode, naik_turun, patokan);    //pemanggilan prosedur output
    
}

//===== Prosedur Output =====
void output(char metode[], char naik_turun[], char patokan[]){
    if (strcmp(metode, "insertion") == 0)           //jika string metode berisikan kata insertion
    {
        insert(metode, naik_turun, patokan);        //jalankan prosedur insert
    }
    if (strcmp(metode, "selection") == 0)           //jika string metode berisikan kata selection
    {
        select(metode, naik_turun, patokan);        //jalankan prosedur select
    }
    
}

//===== Prosedur Insertion =====
void insert(char metode[], char naik_turun[], char patokan[]){
    for (i = 1; i < n; i++)                 //pengecekan setiap indeks array yang dimulai dari indeks ke 1
    {
        strcpy(sisip_barang, barang[i]);    //string barang[i] di copy ke dalam array sementara
        sisip_harga = harga[i];             //array harga[i] di pindahkan ke dalam array sementara
        sisip_nilai = nilai[i];             //arra nilai [i] di pindahlan ke dalam array sementara
        j = i - 1;                          //nilai awal j = nilai i saat ini dikurang 1 / mengecek ke indeks sebelumnya
        //jika masukan berupa asc/menaik
        if (strcmp(naik_turun, "asc") == 0)
        {   
            //jika patokan sorting berisi nama
            if (strcmp(patokan, "nama") == 0)
            {
                while ((j >= 0) && (strcmp(sisip_barang, barang[j]) < 0))   //pengecekan dengan syarat j >= 0 dan nama barang yang i < nama barang j
                {
                    strcpy(barang[j+1], barang[j]);       //nama barang pada indeks j dipindahkan ke nama barang indeks selanjutnya
                    harga[j+1] = harga[j];                //harga barang pada indeks j dipindahkan ke harga barang indeks selanjutnya
                    nilai[j+1] = nilai[j];                //nilai barang pada indeks j dipindahkan ke nilai barang indeks selanjutnya
                    j--;                            //nilai j berkurang
                }
                strcpy(barang[j+1], sisip_barang);        //nama yang berada pada sisip barang dipindahkan ke array barang yang kosong
                harga[j+1] = sisip_harga;                 //harga yang berada pada sisip harga dipindahkan ke array harga yang kosong
                nilai[j+1] = sisip_nilai;                 //nilai yang berada pada sisip nilai dipindahkan ke array nilai yang kosong
            }
            //jika patokan sorting berisi harga
            else if (strcmp(patokan, "harga") == 0)
            {
                while ((j >= 0) && (sisip_harga < harga[j]))   //pengecekan dengan syarat j >= 0 dan harga barang yang i < nama barang j
                {
                    strcpy(barang[j+1], barang[j]);       //nama barang pada indeks j dipindahkan ke nama barang indeks selanjutnya
                    harga[j+1] = harga[j];                //harga barang pada indeks j dipindahkan ke harga barang indeks selanjutnya
                    nilai[j+1] = nilai[j];                //nilai barang pada indeks j dipindahkan ke nilai barang indeks selanjutnya
                    j--;                            //nilai j berkurang
                }
                strcpy(barang[j+1], sisip_barang);        //nama yang berada pada sisip barang dipindahkan ke array barang yang kosong
                harga[j+1] = sisip_harga;                 //harga yang berada pada sisip harga dipindahkan ke array harga yang kosong
                nilai[j+1] = sisip_nilai;                 //nilai yang berada pada sisip nilai dipindahkan ke array nilai yang kosong
            }
            //jika patokan sorting berisi nilai
            else if (strcmp(patokan, "penilaian") == 0)
            {
                while ((j >= 0) && (sisip_nilai < nilai[j]))   //pengecekan dengan syarat j >= 0 dan nilai barang yang i < nama barang j
                {
                    strcpy(barang[j+1], barang[j]);       //nama barang pada indeks j dipindahkan ke nama barang indeks selanjutnya
                    harga[j+1] = harga[j];                //harga barang pada indeks j dipindahkan ke harga barang indeks selanjutnya
                    nilai[j+1] = nilai[j];                //nilai barang pada indeks j dipindahkan ke nilai barang indeks selanjutnya
                    j--;                            //nilai j berkurang
                }
                strcpy(barang[j+1], sisip_barang);        //nama yang berada pada sisip barang dipindahkan ke array barang yang kosong
                harga[j+1] = sisip_harga;                 //harga yang berada pada sisip harga dipindahkan ke array harga yang kosong
                nilai[j+1] = sisip_nilai;                 //nilai yang berada pada sisip nilai dipindahkan ke array nilai yang kosong
            }
        }
        else if (strcmp(naik_turun, "desc") == 0)
        {
            //jika patokan sorting berisi nama
            if (strcmp(patokan, "nama") == 0)
            {
                while ((j >= 0) && (strcmp(sisip_barang, barang[j]) > 0))   //pengecekan dengan syarat j >= 0 dan nama barang yang i > nama barang j
                {
                    strcpy(barang[j+1], barang[j]);       //nama barang pada indeks j dipindahkan ke nama barang indeks selanjutnya
                    harga[j+1] = harga[j];                //harga barang pada indeks j dipindahkan ke harga barang indeks selanjutnya
                    nilai[j+1] = nilai[j];                //nilai barang pada indeks j dipindahkan ke nilai barang indeks selanjutnya
                    j--;                            //nilai j berkurang
                }
                strcpy(barang[j+1], sisip_barang);        //nama yang berada pada sisip barang dipindahkan ke array barang yang kosong
                harga[j+1] = sisip_harga;                 //harga yang berada pada sisip harga dipindahkan ke array harga yang kosong
                nilai[j+1] = sisip_nilai;                 //nilai yang berada pada sisip nilai dipindahkan ke array nilai yang kosong
            }
            //jika patokan sorting berisi harga
            else if (strcmp(patokan, "harga") == 0)
            {
                while ((j >= 0) && (sisip_harga >= harga[j]))   //pengecekan dengan syarat j >= 0 dan harga barang yang i > nama barang j
                {
                    strcpy(barang[j+1], barang[j]);       //nama barang pada indeks j dipindahkan ke nama barang indeks selanjutnya
                    harga[j+1] = harga[j];                //harga barang pada indeks j dipindahkan ke harga barang indeks selanjutnya
                    nilai[j+1] = nilai[j];                //nilai barang pada indeks j dipindahkan ke nilai barang indeks selanjutnya
                    j--;                           //nilai j berkurang
                }
                strcpy(barang[j+1], sisip_barang);        //nama yang berada pada sisip barang dipindahkan ke array barang yang kosong
                harga[j+1] = sisip_harga;                 //harga yang berada pada sisip harga dipindahkan ke array harga yang kosong
                nilai[j+1] = sisip_nilai;                 //nilai yang berada pada sisip nilai dipindahkan ke array nilai yang kosong
            }
            //jika patokan sorting berisi nilai
            else if (strcmp(patokan, "penilaian") == 0)
            {
                while ((j >= 0) && (sisip_nilai >= nilai[j]))   //pengecekan dengan syarat j >= 0 dan nilai barang yang i > nama barang j
                {
                    strcpy(barang[j+1], barang[j]);       //nama barang pada indeks j dipindahkan ke nama barang indeks selanjutnya
                    harga[j+1] = harga[j];                //harga barang pada indeks j dipindahkan ke harga barang indeks selanjutnya
                    nilai[j+1] = nilai[j];                //nilai barang pada indeks j dipindahkan ke nilai barang indeks selanjutnya
                    j--;                            //nilai j berkurang
                }
                strcpy(barang[j+1], sisip_barang);        //nama yang berada pada sisip barang dipindahkan ke array barang yang kosong
                harga[j+1] = sisip_harga;                 //harga yang berada pada sisip harga dipindahkan ke array harga yang kosong
                nilai[j+1] = sisip_nilai;                 //nilai yang berada pada sisip nilai dipindahkan ke array nilai yang kosong
            }
        }
    }

    //proses print hasil sorting insertion
    for (i = 0; i < n; i++)
    {
        printf("%s %d %.1f\n", barang[i], harga[i], nilai[i]);
    }
    
}

//===== Prosedur Selection =====
void select(char metode[], char naik_turun[], char patokan[]){
    int min_indeks;     //variabel penampung indeks minimum

    //pengecekan dengan perulangan sebnayakn n-1
    for (i = 0; i < n-1; i++)
    {
        min_indeks = i;
        //jika masukan user berupa asc/naik
        if (strcmp(naik_turun, "asc") == 0)
        {
            //jika masukan user patokan sorting berupa nama
            if (strcmp(patokan, "nama") == 0)
            {   
                //pengecekan dimulai dari indeks i+1
                for ( j = i+1; j < n; j++)
                {
                    if (strcmp(barang[min_indeks], barang[j]) > 0)      //jika huruf nama barang pada min indeks lebih awal daripada nama barang setelahnya
                    {
                        min_indeks = j;         //nilai pada min indeks menjadi indeks j
                    }
                }
                //menukar nama barang
                strcpy(sisip_barang, barang[i]);
                strcpy(barang[i], barang[min_indeks]);
                strcpy(barang[min_indeks], sisip_barang);
                
                //menukar harga barang
                sisip_harga = harga[i];
                harga[i] = harga[min_indeks];
                harga[min_indeks] = sisip_harga;

                //menukar nilai barang
                sisip_nilai = nilai[i];
                nilai[i] = nilai[min_indeks];
                nilai[min_indeks] = sisip_nilai;
            }
            //jika masukan user patokan sorting berupa harga
            else if (strcmp(patokan, "harga") == 0)
            {
                //pengecekan dimulai dari indeks i+1
                for ( j = i+1; j < n; j++)
                {
                    if (harga[min_indeks] > harga[j])       //jika harga[j] nilainya lebih kecil dari harga di min indeks maka nilai minium ada di indek j
                    {
                        min_indeks = j;     //nilai pada min indeks menjadi indeks j
                    }
                }
                //menukar nama barang
                strcpy(sisip_barang, barang[i]);
                strcpy(barang[i], barang[min_indeks]);
                strcpy(barang[min_indeks], sisip_barang);
                
                //menukar harga barang
                sisip_harga = harga[i];
                harga[i] = harga[min_indeks];
                harga[min_indeks] = sisip_harga;

                //menukar nilai barang
                sisip_nilai = nilai[i];
                nilai[i] = nilai[min_indeks];
                nilai[min_indeks] = sisip_nilai;
            }
            //jika masukan user patokan sorting berupa nilai
            else if (strcmp(patokan, "penilaian") == 0)
            {
                for ( j = i+1; j < n; j++)
                {
                    if (nilai[min_indeks] > nilai[j])       //jika nilai[j] jumlahnya lebih kecil dari nilai di min indeks maka nilai minium ada di indek j
                    {
                        min_indeks = j;         //nilai pada min indeks menjadi indeks j
                    }
                }
                //menukar nama barang
                strcpy(sisip_barang, barang[i]);
                strcpy(barang[i], barang[min_indeks]);
                strcpy(barang[min_indeks], sisip_barang);
                
                //menukar harga barang
                sisip_harga = harga[i];
                harga[i] = harga[min_indeks];
                harga[min_indeks] = sisip_harga;

                //menukar nilai barang
                sisip_nilai = nilai[i];
                nilai[i] = nilai[min_indeks];
                nilai[min_indeks] = sisip_nilai;
            }
        }
        //jika perintah dari user adalah desc/menurun
        else if (strcmp(naik_turun, "desc") == 0)
        {
            //jika masukan user patokan sorting berupa nama
            if (strcmp(patokan, "nama") == 0)
            {   
                //pengecekan dimulai dari indeks i+1
                for ( j = i+1; j < n; j++)
                {
                    if (strcmp(barang[min_indeks], barang[j]) < 0)      //jika huruf nama barang pada min indeks lebih awal daripada nama barang setelahnya
                    {
                        min_indeks = j;         //nilai pada min indeks menjadi indeks j
                    }
                }
                //menukar nama barang
                strcpy(sisip_barang, barang[i]);
                strcpy(barang[i], barang[min_indeks]);
                strcpy(barang[min_indeks], sisip_barang);
                
                //menukar harga barang
                sisip_harga = harga[i];
                harga[i] = harga[min_indeks];
                harga[min_indeks] = sisip_harga;

                //menukar nilai barang
                sisip_nilai = nilai[i];
                nilai[i] = nilai[min_indeks];
                nilai[min_indeks] = sisip_nilai;
            }
            //jika masukan user patokan sorting berupa harga
            else if (strcmp(patokan, "harga") == 0)
            {
                //pengecekan dimulai dari indeks i+1
                for ( j = i+1; j < n; j++)
                {
                    if (harga[min_indeks] < harga[j])       //jika harga[j] nilainya lebih besar dari harga di min indeks maka nilai minium ada di indek min_indeks
                    {
                        min_indeks = j;     //nilai pada min indeks menjadi indeks j
                    }  
                }
                //menukar nama barang
                strcpy(sisip_barang, barang[i]);
                strcpy(barang[i], barang[min_indeks]);
                strcpy(barang[min_indeks], sisip_barang);
                
                //menukar harga barang
                sisip_harga = harga[i];
                harga[i] = harga[min_indeks];
                harga[min_indeks] = sisip_harga;

                //menukar nilai barang
                sisip_nilai = nilai[i];
                nilai[i] = nilai[min_indeks];
                nilai[min_indeks] = sisip_nilai;
            }
            //jika masukan user patokan sorting berupa nilai
            else if (strcmp(patokan, "penilaian") == 0)
            {
                for ( j = i+1; j < n; j++)
                {
                    if (nilai[min_indeks] <= nilai[j])       //jika nilai[j] jumlahnya lebih besar dari nilai di min indeks maka nilai minium ada di min_indeks
                    {
                        min_indeks = j;         //nilai pada min indeks menjadi indeks j
                    }
                }
                //menukar nama barang
                strcpy(sisip_barang, barang[i]);
                strcpy(barang[i], barang[min_indeks]);
                strcpy(barang[min_indeks], sisip_barang);
                
                //menukar harga barang
                sisip_harga = harga[i];
                harga[i] = harga[min_indeks];
                harga[min_indeks] = sisip_harga;

                //menukar nilai barang
                sisip_nilai = nilai[i];
                nilai[i] = nilai[min_indeks];
                nilai[min_indeks] = sisip_nilai;
            }
        }
    }

    //proses print setelah selection sorting
    for (i = 0; i < n; i++)
    {
        printf("%s %d %.1f\n", barang[i], harga[i], nilai[i]);
    }
    
}
/*
10
kalung 175000 4.2
frame 52000 4.5
jaket 175000 4.9
buku 65000 3.8
lampu 45000 5.0
ssd 1500000 4.9
sepatu 259000 4.4
rak 129500 5.0
atk 99700 4.0
hiasan 50400 4.7
selection
desc
harga
*/

/*
5
kemeja 150000 4.2
novel 79000 4.5
skincare 59500 4.0
cermin 29900 5.0
tirai 90000 4.8
insertion
asc
nama
*/