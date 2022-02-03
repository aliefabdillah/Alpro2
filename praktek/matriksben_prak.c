//matriks Bentukan praktek

//sebulum memakai bungkusan
/*
char nama[100][100][100];
char grade[100][100];
int nilai[100][100];


//setelah memakai bungkusan
/*
typedef struct{
	char nama[100];
	char grade;
	int nilai;
}siswa;

siswa matriks[2][2];
*/

//contoh progam

#include <stdio.h>
#include <string.h>

/*
typedef struct{
	char nama[100];
	char grade;
	int nilai;
}siswa;

int main(){
	int i,j,n,m;
	scanf("%d %d", &n, &m);
	
	siswa matriks[n][m];
	
	for(i=0;i<n;i++){
		for(j=0;j<m;j++)
		{
			scanf("%s", matriks[i][j].nama);
			scanf(" %c", &matriks[i][j].grade);
			scanf("%d", &matriks[i][j].nilai);
		}
	}
	
	printf("================\n");
	
	for(i=0;i<n;i++){
		printf("Baris %d :\n", i+1);
		for(j=0;j<m;j++){
			printf("Nama Siswa: %s\n", matriks[i][j].nama);
			printf("Grade Nilai: %c\n", matriks[i][j].grade);
			printf("Nilai: %d\n", matriks[i][j].nilai);
			printf("-----------------\n");
		}
		printf("===================\n");
	}
	
	return 0;
}
*/

//latihan soal 1
/*
typedef struct{
	char warna[100];
	int red;
	int green;
	int blue;
}matriks;

int main(){
	int i,j,n,m;
	scanf("%d %d", &n, &m);
	
	matriks color[n][m];
	for(i=0;i<n;i++){
		for(j=0;j<m;j++)
		{
			scanf("%s", color[i][j].warna);
			scanf("%d", &color[i][j].red);
			scanf("%d", &color[i][j].green);
			scanf("%d", &color[i][j].blue);
		}
	}
	
	char cari[10];
	int tanda = 0;
	scanf("%s", cari);
	
	printf("\n");
	printf("======================\n");
	for(i=0;i<n;i++){
		printf("Baris %d :\n", i+1);
		for(j=0;j<m;j++)
		{
			if(strcmp(cari, color[i][j].warna) == 0){
				tanda = 1;
				
				printf("Detail Warna Merah : %d\n", color[i][j].red);
				printf("Detail Warna Hijau : %d\n", color[i][j].green);
				printf("Detail Warna Biru : %d\n", color[i][j].blue);
				printf("-----------------------\n");
			}
		}
		if(tanda == 0){
			printf("Tidak ADA.\n");	
		}
		printf("======================\n");
		tanda = 0;
	}
	
	return 0;			
}
*/

//Latihan 2
typedef struct{
	char nama[100];
	int angka;
}matriks;

int main(){
	int i,j,n,m;
	scanf("%d %d", &n, &m);
	
	matriks siswa[n][m];
	for(i=0;i<n;i++){
		for(j=0;j<m;j++)
		{
			scanf("%s", siswa[i][j].nama);
			scanf("%d", &siswa[i][j].angka);
		}
	}
	
	matriks temp;
	char ganti1[10];
	char ganti2[10];
	int temp1 = -1, temp2 = -1;
	
	scanf("%s %s", &ganti1, &ganti2);
	for(i=0;i<n;i++){
		for(j=0;j<m;j++)
		{
			if(strcmp(ganti1, siswa[i][j].nama)==0 || strcmp(ganti2, siswa[i][j].nama)==0){
				if(temp1 != -1 && temp2 != -1){
					siswa[temp1][temp2] = siswa[i][j];
					siswa[i][j] = temp;
				}
				else{
					temp1 = i;
					temp2 = j;
					temp = siswa[i][j];
				}
			}
		}
	}
	
	printf("=============\n");
	for(i=0;i<n;i++){
		printf("Baris %d :\n", i+1);
		for(j=0;j<m;j++){
			printf("Nama Mahasiswa : %s\n", siswa[i][j].nama);
			printf("Nilai : %d\n", siswa[i][j].angka);
			printf("--------------------\n");
		}
		printf("=============\n");
	}
	
	return 0;
}
					