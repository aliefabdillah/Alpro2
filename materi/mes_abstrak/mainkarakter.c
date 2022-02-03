#include <stdio.h>
#include "headkarakter.h"
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

/*//menampilkan huruf a saja dan urutan huruf ke berapa
int main(){
    char kata[50];
    printf("masukan kalimat\n");
    scanf("%49[^\n]s", &kata);

    start(kata);
    while ((eop() == 0))
    {
        cek_a(kata);
    }

    return 0;   
} */

/* //menampilkan banyaknya huruf a
int main(){
    char kata[50];
    int n = 0;
    printf("masukan kalimat\n");
    scanf("%49[^\n]s", &kata);

    start(kata);
    while (eop() == 0)
    {
        if (get_cc() == 'a')
        {
            n++;
        }
        inc(kata);
    }
    
    printf("banyaknya huruf a adalah : %d\n", n);
    return 0;
} */

/* //menghitung banyak karakter tanpa spasi
int main(){
    char kata[50];
    int n = 0;
    printf("masukan kalimat\n");
    scanf("%49[^\n]s", &kata);

    start(kata);
    while (eop() == 0)
    {
        if (get_cc() != ' ')
        {
            n++;
        }
        inc(kata);
    }
    
    printf("banyaknya karakter adalah : %d\n", n+1);
    return 0;
} */

/* //menghitung banyaknya huruf
int main(){
    char kata[50];
    int n = 0;
    printf("masukan kalimat\n");
    scanf("%49[^\n]s", &kata);

    start(kata);
    while (eop() == 0)
    {
        n++;
        adv(kata);
    }

    printf("banyaknya huruf adalah : %d\n", n);
    return 0;
} */

/* //menghitung banyaknya suku kata na
int main(){
    char kata[50];
    char temp;
    int n = 0;
    printf("masukan kalimat\n");
    scanf("%49[^\n]s", &kata);

    start(kata);
    while (eop() == 0)
    {
        temp = get_cc();
        inc(kata);
        if (eop()==0)
        {
            if ((temp == 'n') && (get_cc() == 'a'))
            {
                n++;
            }
        }
    }

    printf("banyaknya suku kata 'na' adalah : %d\n", n);
    return 0;
} */

//menghitung banyaknya suku kata kak
int main(){
    char kata[50];
    char temp1, temp2;
    int n = 0;
    printf("masukan kalimat\n");
    scanf("%49[^\n]s", &kata);      //untuk bisa menerima masukan spasi pada string
// %49(sebanyak 49 karakter/mengikuti ukuran string), ^(bisa diisi apa saja), \n(diakhiri dengan enter), s(format string)

    start(kata);
    //sukak
    while (eop() == 0)
    {
        temp1 = get_cc();
        inc(kata);
        if (eop()==0)
        {
            temp2 = get_cc();
            inc(kata);
            if(eop() == 0)
            {
                if ((temp1 == 'k') && (temp2 == 'a') && (get_cc() == 'k'))
                {
                    n++;
                }
            }
        }
    }

    printf("banyaknya suku kata 'kak' adalah : %d\n", n);
    return 0;
}


