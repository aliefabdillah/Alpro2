//Materi Praktek Rekursif
/*
    rekursif dipakai pada kasus perulangan yang tidak bisa dipakai
    basis adalah kondisi agar fungsi atau prosedur berhenti melakukan rekursif
*/

//contoh kode progam

#include <stdio.h>
/*
void alfabet(int i){
    printf("%c ", i);

    if(i < 'z'){
        alfabet(i + 1);
    }
}

int main(){
    alfabet('a');

    return 0;
}
*/

//contoh progam 2
/*
void binary_rec(int);
int binary(int);

int main(){
    int num;

    printf("Enter Decimal Number\n");
    //num = 25;
    scanf("%d", &num);

    printf("\nRecursive logic\n");
    printf("Binary Equivalent of %d is ", num);
    binary_rec(num);

    printf("\n");

    return 0; 
}

void binary_rec(int num){
    if(num == 1){
        printf("1");
    }
    else{
        binary_rec(num/2);
        printf("%d", num%2);
    }
}
*/

//Latihan 1
/*
void cetak(int nomor){
   printf("%d ", nomor);

   if(nomor > 0){
       cetak(nomor-1); 
   }
    
}

int main(){
    int angka = 20;
    cetak(angka);
}
*/

//latihan 2

int fib(int* arr, int n){ 
    int temp1 = -1;
    int temp2 = -1; 
    int akhir = 0;
    int i;
    
	if(n < 2){
		arr[n] = n;
	}
	else{
		arr[n] = fib(arr, n-1) + fib(arr, n-2);
        if(arr[n]%2 == 0)
        {
            temp1 = temp2;
            temp2 = arr[n];
            if (temp1%2 == 0 && temp2%2 == 0)
            {
                akhir = temp1 + temp2;
                return akhir;
            }
            
        }
        
    }
    
}

int main(){
	int n;
	printf("\nMasukan bilangan fibonacci : ");
	scanf("%d", &n);
	int arr[n];
	
	int hasil = fib(arr, n);
    printf("%d", hasil);
    
	return 0;
}

//0 1 1 2 3 5 8 10 18 28
