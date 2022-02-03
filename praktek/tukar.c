#include <stdio.h>
#include <string.h>

typedef struct{
	char nama[100];
	int angka;
}nilai;

void cariData(int n, int m, nilai matriks[n][m], char prev[], char dest[]);
void printData(int m, nilai matriks[m]);
void printDataMatriks(int n, int m, nilai matriks[n][m]);

int main()
{
	int n, m, i, j;

	scanf("%d %d", &n, &m);

	nilai matriks[n][m];

	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < m; ++j)
		{
			scanf("%s %d", matriks[i][j].nama, &matriks[i][j].angka);
		}
	}

	char prev[100], dest[100];
	scanf("%s %s", prev, dest);

	printf("Sebelum Pertukaran\n");
	for (i = 0; i < n; ++i)
	{
		printf("Baris %d : \n", i+1);
		printData(m, matriks[i]);
		printf("=========================\n");
	}
	cariData(n, m, matriks, prev, dest);
	printf("Setelah Pertukaran\n");
	printDataMatriks(n, m, matriks);
	return 0;
}

void printData(int m, nilai matriks[m]){
	int i;

	for (i = 0; i < m; ++i)
	{
		printf("Nama : %s\n", matriks[i].nama);
		printf("Angka : %d\n", matriks[i].angka);
		printf("------------------------\n");
	}
}
//cari dan tukar data
void cariData(int n, int m, nilai matriks[n][m], char prev[], char dest[]){
	int i, j, barisPrev, kolomPrev, barisDest, kolomDest;
	barisPrev = barisDest = kolomPrev = kolomDest = -1;

	int found = 0;
	//pakai while karena menghemat waktu perulangan, jika nilai ditemukan, langsung stop perulangannya
	i = 0;
	while((i < n) && (found == 0)) {
		j = 0;
	    while((j < m) && (found == 0)) {
	    	if (strcmp(matriks[i][j].nama, prev) == 0)
	    	{
	    		barisPrev = i;
	    		kolomPrev = j;
	    		found = 1;
	    	}
	        j++;
	    }
	    i++;
	}

	found = 0;
	i = 0;
	while((i < n) && (found == 0)) {
		j = 0;
	    while((j < m) && (found == 0)) {
	    	if (strcmp(matriks[i][j].nama, dest) == 0)
	    	{
	    		barisDest = i;
	    		kolomDest = j;
	    		found = 1;
	    	}
	        j++;
	    }
	    i++;
	}

	//tukarkan isi matriks hasil pencarian
	nilai temp;
	//tukar nama
	strcpy(temp.nama, matriks[barisPrev][kolomPrev].nama);
	strcpy(matriks[barisPrev][kolomPrev].nama, matriks[barisDest][kolomDest].nama);
	strcpy(matriks[barisDest][kolomDest].nama, temp.nama);
	//tukar angka
	temp.angka = matriks[barisPrev][kolomPrev].angka;
	matriks[barisPrev][kolomPrev].angka = matriks[barisDest][kolomDest].angka;
	matriks[barisDest][kolomDest].angka = temp.angka;

}
//kalau print keseluruhan tanpa dipotong
void printDataMatriks(int n, int m, nilai matriks[n][m]){
	int i, j;

	for (i = 0; i < n; ++i)
	{
		printf("Baris %d : \n", i+1);
		for (j = 0; j < m; ++j)
		{
			printf("Nama : %s\n", matriks[i][j].nama);
			printf("Angka : %d\n", matriks[i][j].angka);
			printf("------------------------\n");
		}
		printf("=========================\n");
	}	
}