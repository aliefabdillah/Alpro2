//Materi Rekursi
/*
	-Mekanisme untuk memanggil diri sendiri
	-melibatkan prosedur atau fungsi untuk mengulang diri sendiri
	untuk menjanlankan sebuah proses
	-rekursif digunakan untuk kasus yang tidak bisa memakai perulangan
*/

//CONTOH KASUS REKURSIF
/*
	- Kasus Pohon
*/

// SYARAT REKURSIF
/*
	- Basis = kondisi berhenti dari rekursif
	- rekursif = kode progam yang menyatakan rekursif atau pemanggilan diri sendiri
*/

// CONTOH PROGAM
#include <stdio.h>
/*
void tulis(int n){
	int counter;
	counter = n;
	
	if(counter > 0){	//jika sudah tidak memenuhi syarat maka rekursif akan berhenti (Basis)
		printf("Proses rekursif dengan nilai counter : %d\n", counter);
		counter = counter - 1;
		tulis(counter); //Rekursif (pemanggilan diri sendiri)
	}
}

int main(){
	tulis(10);
	return 0;
}
*/

// CONTOH PROGAM FAKTORIAL LOOPING
/*
int faktorial(int n){
	int i, hasil = 1;
	for(i = 2; i<=n ; i++){
		hasil = hasil * i;
	}
	
	return hasil;
}

int main(){
	int hasil = faktorial(3);
	printf("Hasil faktorial: %d\n", hasil);
	return 0;
}
*/

//CONTOH PROGAM FAKTORIAL REKURSIF
/*
int faktorial(int n){
	printf("n = %d\n", n);
	
	if((n == 0) || (n == 1)){
		return 1;
	}
	else{
		return(n * faktorial(n - 1));
	}
}

int main(){
	int hasil = faktorial(3);
	printf("hasil faktorial ; %d\n", hasil);
	
	return 0;
}
*/

//CONTOH PROGAM SUM REKURSIF
/*
int sum(int n){
	printf("n = %d\n", n);
	
	//jika 0???
	if(n == 1){
		return 1;
	}
	else if(n == 0){
		return 0;
	}
	else{
		return(n + sum(n - 1));
	}
}

int main(){
	int hasil = sum(0);
	printf("hasil Penjumlahan : %d\n", hasil);
	
	return 0;
}
*/

// FPB REKURSIF
/*
int Carifpb(int a, int b){
	if(b == 0){
		return a;
	}
	else{
		int temp = a % b;
		return Carifbp(b, temp);
	}
}

int main(){
	int hasil = Carifpb(18, 12);
	printf("hasil FBP : %d\n", hasil);
	
	return 0;
}
*/

//PANGKAT REKURSIF
/*
int pangkat(int x, int y){
	int hasil;
	if(y == 0){
		return 1;
	}
	else{
		hasil = x * pangkat (x, y-1);
		return hasil;
	}
	
}

int main(){
	int hasil = pangkat(2, 3);
	printf("hasil pangkat : %d\n", hasil);
	return 0;
}
*/

// FIBONACI
/*
	-bilangan fibonaci
	0 1 1 2 3 5 8 13 21 34 55, .....
	 + = + = + = +  =  +  =
*/

//FIBONACI BOTTOM UP REKURSIF
/*
void fib(int* arr, int n, int i){ //bottom up
	if(i == 0){
		arr[i] = 0;
		fib(arr, n, i+1);
	}
	else if(i == 1){
		arr[i] = 1;
		fib(arr, n, i+1);
	}
	else{
		if(i <= n){
			arr[i] = arr[i-1] + arr[i-2];
			fib(arr, n, i+1);
		}
	}
}

int main(){
	int n;
	printf("\nMasukan bilangan fibonacci ");
	scanf("%d", &n);
	int arr[n];
	
	fib(arr, n, 0);
	int i = 0;
	for(i = 0;i<=n;i++){
		printf("%d ", arr[i]);
	}
	return 0;
}
*/

// FIBONACCI TOP DOWN REKURSIF
/*
int fib(int* arr, int n){ //top down
	if(n < 2){
		arr[n] = n;
		return n;
	}
	else{
		arr[n] = fib(arr, n-1) + fib(arr, n-2);
		return arr[n];
	}
}

int main(){
	int n;
	printf("\nMasukan bilangan fibonacci ");
	scanf("%d", &n);
	int arr[n];
	
	fib(arr, n);
	int i = 0;
	for(i=n;i>=0;i--){
		printf("%d ", arr[i]);
	}
	
	return 0;
}
*/

// MENARA HANOI
/*
void tower(int n, char awal, char akhir, char tengah){
	if(n == 1){
		printf("pindahkan piringan ke %d dari tonggak %c ke tonggak %c\n", n, awal, akhir);
	}
	else{
		tower((n - 1), awal, tengah, akhir);
		//memindahkan piringan berikutnya dari awal ke tengah
		
		printf("Pindahkan piringan ke %d dari tonggak %c ke tonggak %c\n", n, awal, akhir);
		tower((n - 1), tengah, akhir, awal);
		//memindahkan piringan berikutnya ke akhir
	}
}

int main(){
	tower(3, 'A', 'C', 'B');
	return 0;
}
*/

//TUKAR KOIN
/*
	-kasus coin - cari banyaknya koin penukar paling sedikit
	- diberikan masukan:
		1. uang yang mesti diberikan dengan koin paling sedikit
		2. banyaknya koin yang dapat dijadikan penukar uang
	
	- contoh masukan:
		6 3 	//nilai uang - banyaknya koin penukar
		4		//koin penukar
		3
		1
	-output yang benar
	 6 
	 |
	3 3 	//menghasilkan 2 koin penukar yaitu angka 3 dan 3
	
	-output yang salah
	 6
	 |
	4 2
	  |
	 1 1	//menghasilkan 3 koin penukar yaitu angka 4, 1, dan 1
	 
	 //maka yang paling sedikiit adalah 2 penukar
*/

//progam
int minimal(int a, int b){
	//fungsi mencari nilai minimal antara 2 angka
	if(a < b){
		return a;
	}
	else{
		return b;
	}
}

int coin(int tukar[], int n, int memo[], int nilai){	//mencari banyaknya koin pengganti nilai
	//jika isi memo masih kosong maka perlu di isi
	//jika sudah terisi maka tidak perlu di isi
	if(memo[nilai] == -1){
		if(nilai == 0){		//jika nilai koin yang ditukar adalah 0(basis)
			//maka jumlah koin penukar adalah 0
			memo[nilai] = 0;
		}
		else{
			int i;		//inisialisasi agar isi memo tidak random
			memo[nilai] = 10000; 	//diberi nilai besar sebagai pembanding karena proses berikutnya adalah mencari nilai minimal
			
			//memeriksa setiap coin
			for(i=0;i<n-1;i++){
				//jika nilai dikurangi nilai koin tukar masih lebih besar dari 0/belum habis
				if(nilai - tukar[i] >= 0){
					//nilai memo adalah nilai minimal dari nilai memo sekaranh dibandingkan dengan jumlah penukar sisa nilai yang belum habis + 1
					//i dianggap sebagai 1 koin yang telah mengurangi sebelumnya
					//rekursif
					memo[nilai] = minimal(memo[nilai], coin(tukar, n, memo, nilai-tukar[i]) + 1);
				}
			}
		}
	}
	return memo[nilai];
}

int main(){
	int nilai; 		//nilai uang yang ingin ditukar
	int n; 			//banyaknya jenis koin
	int i;
	
	scanf("%d", &nilai);
	scanf("%d", &n);
	
	int tukar[n]; 			//array penyimpan nilai tukar
	int memo[nilai+1];		//memo penyimpan banyaknya koin penukar
	
	//memasukan nilai koin penukar
	for(i=0;i<n;i++){
		scanf("%d", &tukar[i]);
	}
	
	//inisialisasi semua sel memo
	for(i=0;i<=nilai;i++){
		memo[i] = -1;
	}
	
	//tampilkan jumlah coin penukar
	printf("%d\n", coin(tukar, n, memo, nilai));
	
	return 0;
}
