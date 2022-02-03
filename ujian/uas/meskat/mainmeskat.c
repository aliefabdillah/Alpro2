/*Saya Alief Muhammad Abdillah 2003623 mengerjakan UAS meskat21 dalam mata kuliah Algoritma dan Pemrograman 2
untuk keberkahan-Nya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/

//bgian main
#include "headmeskat.h"

int main(){
    char kalimat[300];
    scanf("%299[^\n]s", &kalimat);      //masukan kalimat

    int cek = 0;
    int flag = 1;
    int m = 0;
    i = 0;
    j = 0;
    
    while (eop_kata(kalimat) == 0 && flag)
    {  
        start_kata(kalimat);
        panjang = get_panjang_kata();
        while (i <= panjang-5 && cek == 0)
        {
            //jika ada 3 huruf konsonan yang di apit 2 huruf vokal
            if (cek_vokal(ckata[i]) == 1 && cek_vokal(ckata[i+1]) == 0 && cek_vokal(ckata[i+2]) == 0
            && cek_vokal(ckata[i+3]) == 0 && cek_vokal(ckata[i+4]) == 1)
            {
                printf("%s\n", ckata);   //pindahkan ckata ke arr akhir
                m++;
                cek = 1;
            }
            i++;
        }
        reset_kata();
    }

    //proses print akhir
    /* for ( i = 0; i < m; i++)
    {
        printf("%s\n", arr_akhir[i]);
    } */
    printf("%d\n", m);

    return 0;
}

/*
    ammma ammma amma abbba . 
          ukkka ikkku kakkkii kaki kaki kakakakakkka.
 */