#include "headabs_prak.h"

/*menampilkan isi pita
int main(){
    char kata[50];
    printf("masukan kalimat\n");
    scanf("%49[^\n]s", &kata);

    start(kata);
    printf("%c\n", get_cc());

    while (eop() == 0)
    {
        inc(kata);
        printf("%c\n", get_cc());
    }

    return 0;
}
*/

//latihan
//menghitung banyaknya suku kata ka dalam sebuah pita dan pita diakhiri dengan tanda ";"
int main(){
    char kata[50];
    char huruf_temp;
    int jumlah = 0;

    printf("masukan kalimat:\n");
    scanf("%49[^\n]s", &kata);

    start(kata);
    do
    {
        huruf_temp = get_cc();
        inc(kata);
        if (eop() == 0)
        {
            if ((huruf_temp == 'k') && (get_cc() == 'a'))
            {
                jumlah++;
            }
        }
    }while (eop() == 0);

    printf("Banyak suku 'ka' adalah : %d\n", jumlah);
    return 0;
}