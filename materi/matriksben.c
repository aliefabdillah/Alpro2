//Matriks Bentukan

//TIPE BENTUKAN TITIK
	/*sebuah bungkusan berisi 2 titik x,y
	
	typedef struct{
		int x;
		int y;
	}titik;
	*/

//MATRIKS DARI TITIK
	/*terdiri dari beberapa cel yang berisi titik-titik bentukan
	*/

//contoh progam MATRIK TIPE BENTUKAN
#include <stdio.h>
/*

typedef struct{
	int x;
	int y;
}titik;
	
int main(){
	
	titik matriks[4][4];
	int i,j;
	for(i = 0; i < 4; i++){
		for(j = 0; j < 4; j++){
			printf("masukan koordinat x: ");
			scanf("%d", &matriks[i][j].x);
			printf("masukan koordinat y: ");
			scanf("%d", &matriks[i][j].y);
		}
	}
	
	for(i = 0; i < 4; i++){
		for(j = 0; j < 4; j++){
			printf("koordinat x : %d\n", matriks[i][j].x);
			printf("koordinat y : %d\n", matriks[i][j].y);
		}
	}
	
	return 0;
}
*/

//SIMULASI RGB PIXEL
/*
typedef struct{
	int red;
	int green;	
	int blue;	
}pixel;

int main(){
	int baris;
	int kolom;
	
	printf("masukan jumlah baris : ");
	scanf("%d", &baris);
	
	printf("masukan jumlah kolom : ");
	scanf("%d", &kolom);
	
	pixel arr[baris][kolom];
	
	int b,k;
	//inisialisasi warna pixel
	for(b=0;b<baris;b++){
		for(k=0;k<kolom;k++){
			//warna putih
			arr[b][k].red = 255;
			arr[b][k].green = 255;
			arr[b][k].blue = 255;
			
		}
	}
	
	//merubah dan Pengisian sebuah pixel 
	arr[1][1].red = 0;
	arr[1][1].green = 255;
	arr[1][1].blue = 0;
	
	for(b=0;b<baris;b++){
		for(k=0;k<kolom;k++){
			
			if((arr[b][k].red == 255) && (arr[b][k].green == 255) && 
			(arr[b][k].blue == 255)){
				
				printf("  Putih  ");
				
			}
			
			else if((arr[b][k].red == 0) && (arr[b][k].green == 255) && 
			(arr[b][k].blue == 0)){
				
				printf("  Hijau  ");
				
			}
		}
		printf("\n");
	}
	
	return 0;
}
*/	

//MATRIKS DIAGRAM CARTESIAN
	/*
	-indek baris merepresentasikan sumbu x (kanan ke kiri)
	-indek kolom merepresentasikan sumbu y (atas ke bawah)
	*/
	
//contoh progam MATRIKS CARTESIAN

/* 
	-berikan titik di sumbu x = 3 dan sumbu y = 2 atau koordinat (3,2)
*/

/*
int  main(){
	int matriks[5][5];
	int i,j;
	
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			matriks[i][j] = 0;
		}
	}
	
	matriks[3][2] = 1;
	
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			printf("%d ", matriks[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
*/

//MATRIKS GAME TIC TAC TOE
/*
int main(){
	
	//membersihkan layar
	system("cls");		
	int papan[3][3];
	
	//angka 1 untuk pemain pertama berupa huruf O
	//angka 2 untuk pemain pertama berupa huruf S
	
	int i,j,k;
	
	//inisialiasi papan di isi 0 semua
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			papan[i][j] = 0;
		}
	}
	
	//awal pemain diset -1 sebagai penanda game belum di mulai
	int pemain = -1;
	
	//x dan y  di set -1 sebagai penanda game belum di mulai
	//x dan y merupakan koordinat papan untuk mengisi jawaban
	int x = -1;
	int y = -1;
	
	for(i=0;i<9;i++){
		//mengisi papan jika ada masukan dari pemain
		if((x != -1) && (y != -1)){
			papan[x][y] = pemain;
		}
		
		//menggambar papan
		printf("Kondisi Papan:\n");
		printf("--------------\n");
		for(j=0;j<3;j++){
			printf("| ");
			
			for(k=0;k<3;k++){
				if(papan[k][j] == 0)
				{
					//jika papan kosong
					printf("  | ");
				}
				else if(papan[k][j] == 1)
				{
					//jika papan di isi pemain pertama
					printf("O | ");
				}
				else if(papan[k][j] == 2)
				{
					//jika papan di isi pemain kedua
					printf("S | ");
				}
			}
			printf("\n--------------\n");
		}
		printf("\n");
		
		//pergantian pemain yang akan mengisi papan
		if(pemain == 1)		//jika saat ini pemain 1 yang main 
		{
			pemain = 2;		//selanjutnya adalah pemain ke 2
		}
		else
		{
			pemain = 1;
		}
		
		//meminta masukan pemain
		printf("Masukan X, Y (Pemain %d) : ", pemain);
		scanf("%d %d", &x, &y);
		
		//membersihkan layar;
		system("cls");
	}
	
	return 0;
}
*/	

//ANIMASI SEDERHANA DENGAN MATRIKS
#include <time.h>	
/*
void wait(float x){
	//prosedur untuk membuat delay
	time_t start; //waktu mulai
	time_t current; //waktu saat ini
	time(&start); //memanggil waktu cpu
	
	do{
		time(&current); //mengambil waktu sistem sekarang
	
	}while (difftime(current,start) < x);	
	
}

int main(){
	//membuat matriks
	char arr[6][6];
	
	//x dan y adalah koordinat matriks dan inisialiasi x dan y  bernilai -1
	//variabel jalan untuk menandakan ke atas atau ke bawah
	int i,j;
	int x = -1, y = -1, jalan=1;
	
	//inisialiasi matriks
	//pada awal sebelum mulai semua matriks diisi tanda -
	for(i=0;i<6;i++){
		for(j=0;j<6;j++){
			arr[i][j] = '-';
		}
	}
	
	//proses animasi
	//animasi merupakan proses looping forever
	while(1){		//while akan looping forever yaitu cukup dengan hanya parameter di isi angka 1
		//membersihkan layar
		system("cls");
		
		//jika huruf b nilai x dan y nya sudah melebihi batas maka matriks di set tanda -
		if((x >= 0) && (x < 6)){
			arr[x][y] = '-';
		}
		
		//progam untuk pergerakan koordinat si BENTUKAN
		if((x == 6) && (y == 6)){			//jika x = 6 dan y = 6 atau sudah keluar dari matriks
			//maka animasi di set untuk berjalan ke atas
			jalan = -1;			//menandakan animasi naik ke atas
			x = x - 1;			//koordinat x akan naik atau berkurang 1 terus menerus
			y = y - 1;			//koordinat y akan naik atau berkurang 1 terus menerus
		}
		else if((x == -1) && (y == -1)){	//jika x = -1 dan y = -1 atau sudah keluar dari matriks
			//maka animasi akan berjalan ke bawah
			jalan = 1;			//animasi akan berjalan ke bawah
			x = x + 1;			//koordinat x akan turun atau bertambah 1 sampai batas bawah
			y = y + 1;			//koordinat y akan turun atau bertambah 1 sampai batas bawah
		}
		else if(jalan == 1){					
		//jika arah jalan nya ke bawah  maka koordinat akan bertambah 1 sampai batas bawah
			x = x + 1;
			y = y + 1;
		}
		else{
		//jika arah jalan nya ke atas maka koordinat akan berkurang 1 sampai batas atas
			x = x - 1;
			y = y - 1;
		}
		
		//jika B akan di gambar di matriks
		if((x >= 0) && (x < 6)){		//jika nilai x di antar range indeks matriks 0 sampai dengan 5
			arr[x][y] = 'B';
		}
		
		//penggambaran output matriks
		for(i=0;i<6;i++){
			for(j=0;j<6;j++){
				if(arr[i][j] == '-'){
					printf("    ");
				}
				else{
					printf(" %c ", arr[i][j]);
				}
			}
			printf("\n");
		}
		//prosedur delay selama 1 detik
		wait(1);
	}
	return 0;
}
*/

//MARI MENCOBA
/*
int main(){
	
	//membersihkan layar
	system("cls");		
	int papan[3][3];
	
	//angka 1 untuk pemain pertama berupa huruf 1B7 / 1A3
	//angka 2 untuk pemain pertama berupa huruf 2B7 / 2A3
	
	int i,j,k;
	
	//inisialiasi papan di isi 0 semua
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			papan[i][j] = 0;
		}
	}
	
	//awal pemain diset -1 sebagai penanda game belum di mulai
	int pemain = -1;
	
	//x dan y  di set -1 sebagai penanda game belum di mulai
	//x dan y merupakan koordinat papan untuk mengisi jawaban
	int x = -1;
	int y = -1;
	int skor1=0, skor2=0;
	
	for(i=0;i<9;i++){
		//mengisi papan jika ada masukan dari pemain
		if((x != -1) && (y != -1)){
			papan[x][y] = pemain;
		}
		
		//menggambar papan
		printf("Kondisi Papan:\n");
		printf("--------------\n");
		for(j=0;j<3;j++){
			printf("| ");
			
			for(k=0;k<3;k++){
				if(papan[k][j] == 0)
				{
					//jika papan kosong
					printf("  0 | ");
				}
				else if(papan[k][j] == 1)				
				{
					if(k+j==1 || k+j==4 || k+j==5 || k+j==8 || k+j==9){
					//jika papan di isi pemain pertama
						printf("%dA3 | ", papan[k][j]);
					}
					else{
						printf("%dB7 | ", papan[k][j]);
					}
				}
				else if(papan[k][j] == 2)
				{
					if(k+j==1 || k+j==4 || k+j==5 || k+j==8 || k+j==9){
					//jika papan di isi pemain pertama
						printf("%dA3 | ", papan[k][j]);
					}
					else{
						printf("%dB7 | ", papan[k][j]);
					}
				}
			}
			printf("\n--------------\n");
		}
		printf("\n");
		
		//pergantian pemain yang akan mengisi papan
		if(pemain == 1)		//jika saat ini pemain 1 yang main 
		{
			pemain = 2;		//selanjutnya adalah pemain ke 2
		}
		else
		{
			pemain = 1;
		}
		
		//meminta masukan pemain
		printf("Masukan X, Y (Pemain %d) : ", pemain);
		scanf("%d %d", &x, &y);
		
		//membersihkan layar;
		system("cls");
	}
	printf("Pemain : Skor\n");
	printf("  1    :  %d\n", skor1);
	printf("  2    :  %d\n", skor2);
	
	return 0;
}	
*/
	