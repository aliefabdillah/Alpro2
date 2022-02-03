#include <stdio.h>
#define max 10
#define nama "dewa"
#define pecahan 1.5
#define penjumlahan(a, b) a+b

int main(){
    int angka = max;
    printf("nilai maksimum : %d\n", angka);
    printf("hasil penjumlahan : %d\n", penjumlahan(angka, 5));
    printf("nama : %s\n", nama);
    printf("pecahan : %f\n", pecahan);

    return 0;
}