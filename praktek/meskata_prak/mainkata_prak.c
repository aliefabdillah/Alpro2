#include "headkata_prak.h"

//menampilkan kata pada kalimat
/* int main(){
    char kalimat[100];
    printf("masukan kalimat: \n");
    scanf("%99[^\n]s", &kalimat);

    start_kata(kalimat);
    printf("%s\n", get_kata());

    while (eop_kata(kalimat) == 0)
    {
        inc_kata(kalimat);
        printf("%s\n", get_kata());
    }
    
    return 0;
} 
 */

//menambahkan data pada bungkusan
/* int main(){
    int n, i;
    char kalimat[200];
    printf("masukan banyak data : \n");
    scanf("%d", &n);

    mahasiswa data[n];
    for ( i = 0; i < n; i++)
    {
        scanf(" %199[^n]s", kalimat);
        insert_data(kalimat, &data[i]);
    }
    
    printf("Data Mahasiswa : \n");
    for ( i = 0; i < n; i++)
    {
        printf("%d. %s %s %s\n", i+1, data[i].nim, data[i].nama, data[i].nilai);
    }

    return 0;
    
} */

//latihan membuat tangga kata
//kalimat ini sangat panjang jadi kalian cukup baca sampai sini saja.
/* int main(){
    char kalimat[100];
    int spasi = 0;
    int i;
    printf("masukan kalimat: \n");
    scanf("%99[^\n]s", &kalimat);

    start_kata(kalimat);
    printf("%s\n", get_kata());
    while (eop_kata(kalimat) == 0)
    {
        spasi = spasi + get_panjang_kata();
        inc_kata(kalimat);
        for ( i = 0; i < spasi; i++)
        {
            printf(" ");
        }
        printf("%s\n", get_kata());
    }
} */

//latihan sorting kata dalam pita sesuai panjang kata
//long ago young girl pick the father berries who was hard at work.
int main(){
    char kalimat[100];
    int i, j; 
    int n = 0;
    
    printf("masukan kalimat: \n");
    scanf("%99[^\n]s", &kalimat);

    char kata[50][50];
    int panjang_kata[50];

    start_kata(kalimat);
    strcpy(kata[n], get_kata());
    panjang_kata[n] = get_panjang_kata();
    n++;

    while (eop_kata(kalimat) == 0)
    {
        inc_kata(kalimat);
        strcpy(kata[n], get_kata());
        panjang_kata[n] = get_panjang_kata(); 
        n++;
    }

    int temp_panjang;
    char temp_kata[50];
    for ( i = 0; i < n ; i++)
    {
        temp_panjang = panjang_kata[i];
        strcpy(temp_kata, kata[i]);
        j = i - 1;
        while ((temp_panjang < panjang_kata[j]) && (j >= 0))
        {
            strcpy(kata[j+1], kata[j]);
            panjang_kata[j+1] = panjang_kata[j];
            j = j - 1;
        }

        strcpy(kata[j+1], temp_kata);
        panjang_kata[j+1] = temp_panjang;
    }

    for ( i = 0; i < n; i++)
    {
        printf("%s\n", kata[i]);
    }
    
    return 0;
}
