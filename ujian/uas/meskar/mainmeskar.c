/*Saya Alief Muhammad Abdillah 2003623 mengerjakan UAS meskar21 dalam mata kuliah Algoritma dan Pemrograman 2
untuk keberkahan-Nya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/

//bagian main
#include "headmeskar.h"

int main(){
    char kata[300];     //variabel kata masukan
    char temp1, temp2, temp3, temp4;  //penampung sementar huruf yang akan di cek
    scanf("%299[^\n]s", &kata);

    start(kata);    //memulai prosedur mesin kata
    int n = 0;
    int m = 0;
    int cek = 0;
    //perulangan sampai bertemu eop
    //the soul feels what the mind ignores.
    while (eop() == 0)
    {
        //jika huruf temp 1 vokal
        if ((get_cc() == 'a') || (get_cc() == 'i') || (get_cc() == 'u') || (get_cc() == 'e') || (get_cc() == 'o'))
        {
            temp1 = get_cc();
            inc(kata);
            //jika huruf temp 2 konsonan
            if (((get_cc() > 97) && (get_cc() < 101)) || ((get_cc() > 101) && (get_cc() < 105)) || ((get_cc() > 105) && (get_cc() < 111)) || 
                    ((get_cc() > 111) && (get_cc() < 117)) || ((get_cc() > 117) && (get_cc() < 123)))
            {
                temp2 = get_cc();
                inc(kata);
                //jika huruf temp 3 konsonan
                if (((get_cc() > 97) && (get_cc() < 101)) || ((get_cc() > 101) && (get_cc() < 105)) || ((get_cc() > 105) && (get_cc() < 111)) || 
                    ((get_cc() > 111) && (get_cc() < 117)) || ((get_cc() > 117) && (get_cc() < 123)))
                {
                    temp3 = get_cc();
                    inc(kata);
                    //jika huruf temp 4 vokal
                    if ((get_cc() == 'a') || (get_cc() == 'i') || (get_cc() == 'u') || (get_cc() == 'e') || (get_cc() == 'o'))
                    {   
                        temp4 = get_cc();
                        arr[n][m] = temp1;
                        m++;
                        arr[n][m] = temp2;
                        m++;
                        arr[n][m] = temp3;
                        m++;
                        arr[n][m] = temp4;
                        m++;
                        n++;
                        inc(kata);
                        m = 0;
                    }
                    else
                    {
                        inc(kata);
                    }
                }
                else
                {
                    inc(kata);
                }
            }
            else
            {
                inc(kata);
            }
        }
        else
        {
            inc(kata);
        }
    }
    
    //print hasil akhir
    for (i = 0; i < n; i++)
    {
        printf("%s\n", arr[i]);
    }
    printf("%d\n", n);
}

//jangan lupa bahagia hari ini.
//amma amma amma abba .
//the soul feels what the mind ignores.