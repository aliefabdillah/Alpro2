/*Saya Alief Muhammad Abdillah 2003623 mengerjakan TP2 dalam mata kuliah Algoritma dan Pemrograman 2
untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/

//bagian mesin
#include "headtp2.h"

//====== Prosedur Input ======
void input(){
	int baris, kolom;				//deklarasi variabel baris dan kolom matriks
	
	scanf("%d", &baris);			//meminta user untuk memasukan jumlah baris
	scanf("%d", &kolom);			//meminta user untuk memasukan jumlah kolom

	bungkus matrix[baris][kolom];	//deklarasi bungkusan matriks
	
	//proses input nama, nilai1, nilai 2, dan nilai 3
	for(i=0;i<baris;i++)
	{
		for(j=0;j<kolom;j++)
		{
			scanf("%s", matrix[i][j].nama);
			scanf("%f", &matrix[i][j].nilai1);
			scanf("%f", &matrix[i][j].nilai2);
			scanf("%f", &matrix[i][j].nilai3);
		}
	}
	
	//proses pemindahan dari matriks nama ke matriks hasil
	for (i = 0; i < baris; i++)
	{
		for (j = 0; j < kolom; j++)
		{
			strcpy(matrix[i][j].hasil, matrix[i][j].nama);	//matriks nama/matriks inputan dipindahkan ke matriks hasil yang nantinya akan di ubah posisinya
		}
		
	}

	//proses perhitungan rata-rata
	for(i=0;i<baris;i++)
	{
		for(j=0;j<kolom;j++)
		{
			rata_rata[i][j] = (matrix[i][j].nilai1 + matrix[i][j].nilai2 + matrix[i][j].nilai3) / 3;  //setiap nilai pada nama di hitung rata-ratanya dan dimasukan ke dalam matriks rata-rata
		}
	}

	//proses input nama mana saja yang akan di ganti
	k=0;
	scanf("%s", ganti[k]);					//inputan awal sekaligus pancingan perulangam while
	while(strcmp(ganti[k], "stop") != 0)	//selama inputan bukan kata "stop" maka perulangan akan terus berjalan
	{
		k++;
		scanf("%s", ganti[k]);				//meminta user memasukan nama yang akan di ganti posisinya
		
	}
	
	cek_nama(baris, kolom, matrix);			//pemanggilan prosedur cek_nama
	
}

//====== Prosedur Cek Nama ======
void cek_nama(int baris, int kolom, bungkus matrix[baris][kolom]){
	int find = 0;				//variabel find/penanda
	int baris_first = -1;		//variabel baris dari nama yang akann di ganti pertama
	int kolom_first = -1; 		//variabel kolom dari nama yang akann di ganti pertama
	int baris_sec = -1; 		//variabel baris dari nama yang akann di ganti kedua
	int kolom_sec = -1;			//variabel kolom dari nama yang akann di ganti kedua

	l=0;
	while (l<k)			//perulangan while sampai jumlah kata yang akan di ganti
	{
		for(i=0;i<baris;i++)		
		{
			for(j=0;j<kolom;j++)
			{
				if (strcmp(ganti[l], matrix[i][j].hasil) == 0)		//jika kata yang ingin di ganti ada pada matriks
				{
					find++;						//penanda bertambah 1 dan mengulang sampai penanda bernilai 2
					if (find == 1)				//jika penanda bernilai 1
					{
						baris_first = i;		//indeks baris dari nama pertama masuk ke variabel baris_first
						kolom_first = j;		//indeks kolom dari nama pertama masuk ke variabel kolom_first
						l++;					//indeks dari array gantinya bertambah
						i=0;					//indek i dan j menajdi 0 lagi dan memulali perulangan matriks dari awal
						j=0;
					}
					else if(find == 2)			//jika penanda bernilai 2 berarti nama yang akan di ganti sudah sepasang dan siap untuk di tukar
					{
						baris_sec = i;			//indeks baris dari nama kedua masuk ke variabel baris_sec
						kolom_sec = j;			//indeks kolom dari nama kedua masuk ke variabel kolom_sec
						find = 0;				//find berubah 0 karena sudah sepasang dan di set untuk mencari pasangan nama berikutnya
						l++;					//indeks array ganti melanjutkan perulangan
						i=0;
						j=0;
						cek_rata(baris, kolom, baris_first, kolom_first, baris_sec, kolom_sec, matrix);		//pemanggilan prosedur cek rata-rata
					}
				}
			}
		}
	}

	print_akhir(baris, kolom, matrix);		//pemanggilan prosedur print output akhir
	
}

//====== Prosedur Cek rata-rata
void cek_rata(int baris, int kolom, int baris_first, int kolom_first, int baris_sec, int kolom_sec, bungkus matrix[baris][kolom]){
	
	if(rata_rata[baris_first][kolom_first] > rata_rata[baris_sec][kolom_sec])				//jika rata-rata dari nama yang akan di ganti pertama lebih besar dari nama pengganti kedua
	{
		tukar_nama(baris, kolom, baris_first, kolom_first, baris_sec, kolom_sec, matrix);	//pemanggilan fungsi tukar nama
		tukar_rata(baris, kolom, baris_first, kolom_first, baris_sec, kolom_sec, matrix);	//pemanggilan fungsi tukar rata-rata
	}
	
}

//====== Prosedur Tukar nama ======
void tukar_nama(int baris, int kolom, int baris_first, int kolom_first, int baris_sec, int kolom_sec, bungkus matrix[baris][kolom]){
	bungkus temp;		//deklarasi bungkusan sementara

	//proses pertukaran nama pada matriks
	strcpy(temp.hasil, matrix[baris_first][kolom_first].hasil);								
	strcpy(matrix[baris_first][kolom_first].hasil, matrix[baris_sec][kolom_sec].hasil);
	strcpy(matrix[baris_sec][kolom_sec].hasil, temp.hasil);
}

//====== Fungsi Tukar Rata-Rata ======
int tukar_rata(int baris, int kolom, int baris_first, int kolom_first, int baris_sec, int kolom_sec, bungkus matrix[baris][kolom]){
	float simpanan[50][50];		//deklarasi variabel sementara

	//proses perutukaran rata-ratannya
	simpanan[baris_first][kolom_first] = rata_rata[baris_first][kolom_first];
	rata_rata[baris_first][kolom_first] = rata_rata[baris_sec][kolom_sec];
	rata_rata[baris_sec][kolom_sec] = simpanan[baris_first][kolom_first];

	return rata_rata[baris][kolom];		//mereturn matriks rata-rata yang telah di tukar posisi
}

//===== Prosedur Print Inputan Awal ======
void print_akhir_awal(int baris, int kolom, bungkus matrix[baris][kolom]){
	int spasi_awal = 0;		//variabel jumlah spasi
	int max_awal[10];		//variabel jumlah maximal panjang kata setiap kolom

	//agar bisa dicek kata terpanjangnya dari setiap kolom maka matriks di transpose dahulu
	for (i = 0; i < kolom; i++)
	{	
		max_awal[i] = strlen(matrix[0][0].nama);			//max awal di set di matriks baris 0 kolom 0 atau awal
		for (j = 0; j < baris; j++)
		{
			if (max_awal[i] < strlen(matrix[j][i].nama))	//jika nilai maximal yang sudah di set sebelumnya < panjang kata matriks selanjutnya
			{
				max_awal[i] = strlen(matrix[j][i].nama);	//max = panjang kata pada matriks indeks tersebut
			}
		}
	}
	
	//proses align setiap kolom pada matriks
	for (i = 0; i < baris; i++)
	{
		for (j = 0; j < kolom; j++)
		{
			if (j != kolom-1)		//jika kolom bukan kolom terakhir
			{
				if (strlen(matrix[i][j].nama) < max_awal[j])		//dan jika panjang kata pada indeks terkait < maximal panjang kata pada kolom tersebut
				{
					spasi_awal = max_awal[j] - strlen(matrix[i][j].nama);	//jumlah spasi = max panjang nama - panjang nama yang ada di indeks terkait
					printf("%s  ", matrix[i][j].nama);						//print nama dengan tambahan 2 spasi
					for (k = 0; k < spasi_awal; k++)						//print spasi setelahnya sebanyak jumlah spasi yang telah di hitung sebelumnya
					{
						printf(" ");
					}
				}
				else												//jika panjang kata pada indeks terkait tidak lebih kecil dari / sama dengan panjang maximal kata pada kolom 
				{
					printf("%s  ", matrix[i][j].nama);				//print kata dengan tambahan 2 spasi di belakang
				}
			}
			else				//jika kolom adalah kolom terakhir
			{
				printf("%s", matrix[i][j].nama);					//print kata dan tanpa tambahan spasi
			}
		}
		printf("\n");
	}
}

//===== Prosedur Print Hasil Matriks Yang Telah di Tukar Posisi =======
void print_akhir_hasil(int baris, int kolom, bungkus matrix[baris][kolom]){
	int spasi_hasil = 0;	//variabel jumlah spasi
	int max_hasil[10];		//variabel jumlah maximal panjang kata setiap kolom

	//agar bisa dicek kata terpanjangnya dari setiap kolom maka matriks di transpose dahulu
	for (i = 0; i < kolom; i++)
	{	
		max_hasil[i] = strlen(matrix[0][0].hasil);			//max awal di set di matriks baris 0 kolom 0 atau awal
		for (j = 0; j < baris; j++)
		{
			if (max_hasil[i] < strlen(matrix[j][i].hasil))	//jika nilai maximal yang sudah di set sebelumnya < panjang kata matriks selanjutnya
			{
				max_hasil[i] = strlen(matrix[j][i].hasil);	//max = panjang kata pada matriks indeks tersebut
			}
		}
	}

	//proses align setiap kolom pada matriks
	for (i = 0; i < baris; i++)
	{
		for (j = 0; j < kolom; j++)
		{
			if (j != kolom-1)		//jika kolom bukan kolom terakhir
			{
				if (strlen(matrix[i][j].hasil) < max_hasil[j])					//dan jika panjang kata pada indeks terkait < maximal panjang kata pada kolom tersebut
				{
					spasi_hasil = max_hasil[j] - strlen(matrix[i][j].hasil);	//jumlah spasi = max panjang nama - panjang nama yang ada di indeks terkait
					printf("%s  ", matrix[i][j].hasil);							//print nama dengan tambahan 2 spasi
					for (k = 0; k < spasi_hasil; k++)							//print spasi setelahnya sebanyak jumlah spasi yang telah di hitung sebelumnya
					{
						printf(" ");
					}
				}
				else													//jika panjang kata pada indeks terkait tidak lebih kecil dari / sama dengan panjang maximal kata pada kolom
				{
					printf("%s  ", matrix[i][j].hasil);					//print kata dengan tambahan 2 spasi di belakang
				}
			}
			else				//jika kolom adalah kolom terakhir
			{
				printf("%s", matrix[i][j].hasil);			//print kata dan tanpa tambahan spasi
			}
		}
		printf("\n");
	}
	
}

//===== Prosedur Print Output =====
void print_akhir(int baris, int kolom, bungkus matrix[baris][kolom]){

	printf("Posisi Bangku Awal:\n");
	print_akhir_awal(baris, kolom, matrix);				//pemanggilan prosedur print bagian inputan

	printf("\n");
	printf("Posisi Bangku Setelah Nilai Dicek:\n");
	print_akhir_hasil(baris, kolom, matrix);			//pemanggilan prosedur print bagian hasil
}
