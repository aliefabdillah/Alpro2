#include <stdio.h>
//const bisa digunakan sebagai variabel global juga
/* 
const int max = 0;
const char nama[10] = "dewa";
const float pecahan = 1.5;
 */ 

int main(){
    const int max = 0;
    const char nama[10] = "dewa";
    const float pecahan = 1.5;

    int angka = max;
    printf("nilai maksimum : %d\n", angka);
    printf("nama : %s\n", nama);
    printf("pecahan : %f\n", pecahan);
    
    return 0;
}