#include <stdio.h>
//squential search(pencarian beruntun)
//angka terbesar kedua

void squenSearch(int arr[], int n){
    int max = 0;
    int i, found;
    found = 0;
    i=0;
    int max2 =0;

    while(i<n){
        if(arr[i] > max){
            max2 = max;
            max = arr[i];
        }
        i++;
    }
    
    

    printf("Angka terbesar kedua  yaitu %d.\n", max2);
}

int main(){

    int n, cari;
    printf("Masukkan jumlah data : ");
    scanf("%d", &n);

    int arr[n];

    int i;
    printf("Masukkan data : \n");
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    squenSearch(arr, n);

    return 0;
}