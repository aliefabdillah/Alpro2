//Matriks

//Deklarasi Matriks
/*
- tipe_data
	nama_matriks[jumlah_baris][jum;ah_kolom]
	
- contoh
	int matriks[10][10] = artinya matriks dengan dimensi 10x10
*/

//Pengaksesan matriks
/*
- nama_matriks[baris_ke][kolom_ke]

- akan mengisi sel matriks baris ke 2 kolom 3
	matriks[2][3] = 9;

- akan menampilkan nilai matriks di sel baris ke 2 kolom ke 3
	printf("isi matriks baris ke 2 kolom ke 3 adalah : %d/n", matriks[2][3]);
*/

//contoh progam 1 (mengisi dan menampilkan matriks)
#include <stdio.h>
#include <string.h>
/*
int main(){
	int matriks[3][2];
	int baris;
	int kolom;
	
	for(baris = 0; baris < 3; baris++){
		for(kolom = 0; kolom < 2; kolom++){
			printf("masukan angka: ");
			scanf("%d", &matriks[baris][kolom]);
			printf("\n");
		}
	}
	
	for(baris = 0; baris < 3; baris++){
		for(kolom = 0; kolom < 2; kolom++){
			printf("isi baris %d kolom %d = %d\n", baris, kolom, matriks[baris][kolom]);
		}
	}
	return 0;
}
*/

//contoh progam menyalin matriks
/*
int main(){
	int matriks1[3][3];
	int matriks2[3][3];
	
	int i, j;
	
	for(i = 0; i<3 ;i++){
		for(j = 0; j < 3; j++){
			printf("masukan angka: ");
			scanf("%d", &matriks1[i][j]);
			printf("\n");
		}
	}
	
	for(i = 0; i < 3 ;i++){
		for(j = 0; j < 3; j++){
			matriks2[i][j] = matriks1[i][j];
		}
	}
	
	for(i = 0; i<3 ;i++){
		for(j = 0; j < 3; j++){
			printf("isi matriks2 baris %d kolom %d = %d\n", i, j, matriks2[i][j]);
		}
	}
	
	return 0;
}
*/

//penjumlahan matriks
/*
int main(){
	int matriks1[2][3];
	int matriks2[2][3];
	int hasil_tambah[2][3];
	int hasil_kurang[2][3];
	
	int i, j;
	
	printf("masukan nilai matrik 1 (2 x 3)\n");
	for(i = 0; i<2 ;i++){
		for(j = 0; j < 3; j++){
			scanf("%d", &matriks1[i][j]);
		}
	}
	
	printf("masukan nilai matrik 2 (2 x 3)\n");
	for(i = 0; i<2 ;i++){
		for(j = 0; j < 3; j++){
			scanf("%d", &matriks2[i][j]);
		}
	}
	
	//penjumlahan
	for(i = 0; i<2 ;i++){
		for(j = 0; j < 3; j++){
			hasil_tambah[i][j] = matriks1[i][j] + matriks2[i][j];
		}
	}
	
	//pengurangan
	for(i = 0; i<2 ;i++){
		for(j = 0; j < 3; j++){
			hasil_kurang[i][j] = matriks1[i][j] - matriks2[i][j];
		}
	}
	
	
	//menampilkan hasil
	printf("hasil jumlah matriks : \n");
	for(i = 0; i<2 ;i++){
		for(j = 0; j < 3; j++){
			printf("%d\n", hasil_tambah[i][j]);
		}
	}
	
	printf("hasil pengurangan matriks : \n");
	for(i = 0; i<2 ;i++){
		for(j = 0; j < 3; j++){
			printf("%d\n", hasil_kurang[i][j]);
		}
	}
	
	return 0;
}
*/

//perkalian matriks
/*
int main(){
	int matriks1[3][2];
	int matriks2[2][3];
	int matriks3[3][3];
	
	int i, j, jumlah_kali;
	
	//mengisi matriks1
	printf("masukan nilai matrik 1 (3 x 2)\n");
	for(i = 0; i<3 ;i++){
		for(j = 0; j < 2; j++){
			scanf("%d", &matriks1[i][j]);
		}
	}
	
	//mengisi matriks2
	printf("masukan nilai matrik 2 (2 x 3)\n");
	for(i = 0; i<2 ;i++){
		for(j = 0; j < 3; j++){
			scanf("%d", &matriks2[i][j]);
		}
	}
	
	//proses perkalian matriks
	for(i = 0; i<3 ;i++){
		for(j = 0; j < 3; j++){
			matriks3[i][j] = 0 ;
			for(jumlah_kali = 0 ; jumlah_kali < 2 ; jumlah_kali++){
				matriks3[i][j] = matriks3[i][j] + (matriks1[i][jumlah_kali] * matriks2[jumlah_kali][j]);
			}
		}
	}
	
	//menampilkan hasil
	printf("Hasil Kali Matriks: \n");
	for(i = 0; i<3 ;i++){
		for(j = 0; j < 3; j++){
			printf("%d ", matriks3[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
*/

//mari mencoba 2
/*
int main(){
	int baris, kolom;
	
	printf("masukan jumlah baris : ");
	scanf("%d", &baris);
	
	printf("masukan jumlah kolom : ");
	scanf("%d", &kolom);
	
	int matriks[baris][kolom];
	int i,j;
	
	printf("masukan angka pada matriks: \n");
	for(i = 0; i < baris; i++){
		for(j = 0; j < kolom; j++){
			scanf("%d", &matriks[i][j]);
		}
	}
	
	int angka;
	printf("masukan angka pengganti: ");
	scanf("%d", &angka);
	
	printf("\n-----------------------\n");
	
	for(i = 0; i < baris; i++){
		for(j = 0; j < kolom; j++){
			if(matriks[i][j] % 2 == 0){
				matriks[i][j] = angka;
			}
		}
	}
	
	printf("Hasil pergantian: \n");
	for(i = 0; i < baris; i++){
		for(j = 0; j < kolom; j++){
			printf("%d ", matriks[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
*/

//mari mencoba 3
int main(){
	int baris, kolom;
	
	printf("masukan jumlah baris : ");
	scanf("%d", &baris);
	
	printf("masukan jumlah kolom : ");
	scanf("%d", &kolom);
	
	int matriks[baris][kolom];
	int muter[baris][kolom];
	int i,j;
	
	printf("masukan angka pada matriks: \n");
	for(i = 0; i < baris; i++){
		for(j = 0; j < kolom; j++){
			scanf("%d", &matriks[i][j]);
		}
	}
	
	int pilih;
	printf("pilih rotasi ke kiri(ketik 1) atau kanan(ketik 2)?\n");
	scanf("%d", &pilih);
	
	if(pilih == 2){
		for(i = 0; i < baris; i++){
			for(j = 0; j < kolom; j++){
				muter[i][j] = matriks[baris-j-1][i];
			}
		}
	}
	else{
		for(i = 0; i < baris; i++){
			for(j = 0; j < kolom; j++){
				muter[baris-j-1][i] = matriks[i][j];
			}
		}
	}
	
	printf("\n");
	printf("Hasil rotasi: \n");
	for(i = 0; i < baris; i++){
		for(j = 0; j < kolom; j++){
			printf("%d ", muter[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
	