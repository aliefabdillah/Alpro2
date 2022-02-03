//matriks praktek

//contoh progam 1

#include <stdio.h>
/*
int main(){
	int matriks[4][5];
	int i, j;
	int bantu = 11;
	
	for(i = 0; i<4 ;i++){
		for(j = 0; j < 5; j++){
			matriks[i][j] = bantu++;
		}
	}
	
	for(i = 0; i<4 ;i++){
		for(j = 0; j < 5; j++){
			printf("%d ", matriks[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
*/

//contoh progam 2
/*
int main(){
	int matriks[4][5];
	int i, j;
	int bantu = 11;
	int baris, kolom;
	
	for(i = 0; i<4 ;i++){
		for(j = 0; j < 5; j++){
			matriks[i][j] = bantu++;
		}
	}
	
	for(i = 0; i<4 ;i++){
		for(j = 0; j < 5; j++){
			printf("%d ", matriks[i][j]);
		}
		printf("\n");
	}
	
	printf("\n");
	printf("masukan baris yang dicari: ");
	scanf("%d", &baris);
	
	printf("\n");
	printf("masukan kolom yang dicari: ");
	scanf("%d", &kolom);
	
	printf("isi dari baris %d dan kolom %d adalah %d\n", baris, kolom, matriks[baris-1][kolom-1]);
	
	return 0;
}
*/

//latihan 1 MENCARI INDEKS
/*
int main(){
	int baris, kolom;
	
	printf("banyaknya baris : ");
	scanf("%d", &baris);
	
	printf("banyaknya kolom : ");
	scanf("%d", &kolom);
	
	int matriks[baris][kolom];
	int i, j;
	int bantu = 11;
	int nilai;
	
	for(i = 0; i<baris ;i++){
		for(j = 0; j < kolom; j++){
			matriks[i][j] = bantu++;
		}
	}
	
	for(i = 0; i<baris ;i++){
		for(j = 0; j < kolom; j++){
			printf("%d ", matriks[i][j]);
		}
		printf("\n");
	}
	
	printf("\n");
	printf("masukan nilai yang dicari: ");
	scanf("%d", &nilai);
	
	for(i=0; i < baris ; i++){
		for(j=0; j<kolom ; j++){
			if(matriks[i][j] == nilai){
				printf("angka %d ada di baris %d kolom %d\n", nilai, i+1, j+1);
			}
		}
	}
	
	return 0;
}
*/

//latihan 2 PERKALIAN MATRIKS DENGAN KONSTANTA
/*
int main(){
	int baris, kolom;
	
	printf("banyaknya baris : ");
	scanf("%d", &baris);
	
	printf("banyaknya kolom : ");
	scanf("%d", &kolom);
	
	int matriks[baris][kolom];
	int i,j;
	
	printf("masukan matrix[%d][%d]\n", baris, kolom);
	for(i=0;i<baris;i++){
		for(j=0;j<kolom;j++){
			scanf("%d", &matriks[i][j]);
		}
	}
	printf("\n");
	
	int konstanta;
	int hasil[baris][kolom];
	
	printf("masukan konstanta: ");
	scanf("%d", &konstanta);
	
	for(i=0;i<baris;i++){
		for(j=0;j<kolom;j++){
			hasil[i][j] = matriks[i][j] * konstanta;
		}
	}
	
	printf("Hasil kali matriks dengan konstanta: \n");
	for(i = 0; i<baris; i++){
		for(j = 0; j<kolom; j++){
			printf("%d ", hasil[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
*/

//latihan 3 TRANSPOSE
/*
int main(){
	int baris, kolom;
	
	printf("banyaknya baris : ");
	scanf("%d", &baris);
	
	printf("banyaknya kolom : ");
	scanf("%d", &kolom);
	
	int matriks[baris][kolom];
	int i,j;
	
	printf("masukan matrix[%d][%d]\n", baris, kolom);
	for(i=0;i<baris;i++){
		for(j=0;j<kolom;j++){
			scanf("%d", &matriks[i][j]);
		}
	}
	printf("\n");
	
	printf("Hasil Transpose:\n");
	for(i = 0; i<kolom ;i++){
		for(j = 0; j < baris; j++){
			printf("%d ", matriks[j][i]);
		}
		printf("\n");
	}
	
	return 0;
}
*/

//latihan 4 REFLEKSI
/*
int main(){
	int baris, kolom;
	
	printf("banyaknya baris : ");
	scanf("%d", &baris);
	
	printf("banyaknya kolom : ");
	scanf("%d", &kolom);
	
	int matriks[baris][kolom];
	int transpose[baris][kolom];
	int i,j;
	
	printf("masukan matrix[%d][%d]\n", baris, kolom);
	for(i=0;i<baris;i++){
		for(j=0;j<kolom;j++){
			scanf("%d", &matriks[i][j]);
		}
	}
	printf("\n");
	
	printf("Hasil Refleksi:\n");
	for(i = 0; i<baris ;i++){
		for(j = kolom-1 ; j >= 0; j--){
			printf("%d ", matriks[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
*/

//latihan 6 MEMBANDINGKAN MATRIKS
/*
int main(){
	int baris, kolom;
	
	printf("banyaknya baris : ");
	scanf("%d", &baris);
	
	printf("banyaknya kolom : ");
	scanf("%d", &kolom);
	
	int matriks1[baris][kolom];
	int matriks2[baris][kolom];
	int i,j;
	
	printf("masukan matriks1[%d][%d]\n", baris, kolom);
	for(i=0;i<baris;i++){
		for(j=0;j<kolom;j++){
			scanf("%d", &matriks1[i][j]);
		}
	}
	printf("\n");
	
	printf("masukan matriks2[%d][%d]\n", baris, kolom);
	for(i=0;i<baris;i++){
		for(j=0;j<kolom;j++){
			scanf("%d", &matriks2[i][j]);
		}
	}
	printf("\n");
	
	printf("===================\n");
	
	int tanda = 0;
	for(i=0;i<baris;i++){
		for(j=0;j<kolom;j++){
			if(matriks1[i][j] == matriks2[i][j]){
				tanda = 1;
			}
			else{
				tanda = 0;
			}
		}
	}
	
	if(tanda == 1){
		printf("MATRIKS SAMA\n");
	}
	else{
		printf("matriks beda\n");
	}
	
	return 0;
}
*/