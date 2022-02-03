/*Saya Alief Muhammad Abdillah 2003623 mengerjakan TP1 dalam mata kuliah Algoritma dan Pemrograman 2
untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/

//bagian mesin
#include "headtp1.h"		//memanggil library header

//======= Prosedur Input ========
void input(){
	int baris, kolom;					//deklarasi inputan
	scanf("%d", &baris);				// masukan baris dan kolom
	scanf("%d", &kolom);
	
	//masukan matriks awal/inputan user
	for(i=0; i<baris; i++){					//perulangan iterator i sebanyak baris-1
		for(j=0; j<kolom; j++){				//perulangan iterator j sebanyak kolom-1
			scanf("%d", &awal[i][j]);		//masukan matriks awal oleh user
		}
	}
	
	output(baris, kolom);		//pemanggilan prosedur output dengan parameter baris dan kolom
}

//======= Prosedur Refleksi dan Transpose =======
void refleksi_transpose(int baris, int kolom){
	//refleksi matriks
	for(i=0;i<baris;i++){							//perulangan iterator i sebanyak baris-1
		for(j=0; j<kolom; j++){						//perulangan iterator j sebanyak kolom-1
			refleksi[i][j] = awal[baris-i-1][j];	//perefleksian matriks dengan memindahkan nilai di matriks awal ke matriks refleksi
		}											//jika diminta refleksi[0][0] = awal[2-0-1][0], dst
	}
	
	//transpose matriks
	for(i=0;i<baris;i++){							//perulangan iterator i sebanyak baris-1
		for(j=0; j<kolom; j++){						//perulangan iterator j sebanyak kolom-1
			transpose[j][i] = refleksi[i][j];		//transpose matriks dengan memindahkan nilai di matriks refleksi ke matriks transpose
		}											//jika diminta nilai transpose[1][0] = refleksi[0][1], dst
	}
	
	//jumlah kolom terakhir
	for(i=0;i<kolom;i++){							//perulangan i sebanyak kolom-1 karena matriks awal setelah di refleksi dan di transpose berbentuk [kolom][baris]
		jumlah = jumlah + transpose[i][baris-1];	//menjumlahkan nilai matriks yang ada di kolom terakhir, baris - 1 menanandakan kolom terakhir saja
	}
	
}

//======== Rotasi Ke Arah Kiri ============
void kiri(int sisa, int baris, int kolom){
	
	//jika hasil jumlah mod 4 = 0
	if(sisa == 0)
	{
		for(i=0;i<kolom;i++){									//perulangan i sebanyak kolom
			for(j=0;j<baris;j++){								//perulangan j sebanyak bari , hal ini terjadi karena ukuran matriks awal setelah di refleksi dan di transpose yaitu [kolom][baris]
				akhir[i][j] = transpose[i][j];					//matriks transpose di pindahkan ke matriks akhir
			}
		}
	}
	//jika jumlah mod 4 = 1
	else if(sisa == 1)
	{
		
		for(i=0;i<baris;i++){
			for(j=0;j<kolom;j++){
				//putaran 1 kali atau 90 derajat
				akhir[i][j] = awal[i][j];					//matriks inputan di pindahkan ke matriks akhir
			}												//karena rotasi ke 3 sama dengan matriks inputan
		}
	}
	//jika hasil jumlah mod 4 = 2
	else if(sisa == 2)
	{
		for(i=0;i<kolom;i++){
			for(j=0;j<baris;j++)
			{
				//putaran 180 derajat
				refleksi[i][j] = transpose[kolom-i-1][j];		//matriks transpose di refleksikan ke atas dan dipindahkan ke dalam matriks refleksi
			}
		}
		for(i=0;i<kolom;i++){
			for(j=0;j<baris;j++)
			{
				akhir[i][j] = refleksi[i][baris-j-1];			//matriks refleksi di refleksikan lagi ke samping dan di pindahkan ke matriks akhir
			}
		}
	}
	else if(sisa == 3)
	{
		for(i=0;i<baris;i++){									//perulangan i sebanyak baris dan j sebanyak kolom
			for(j=0;j<kolom;j++){								//hal ini terjadi karena matriks berbentuk [baris][kolom]
				//putaran 3 kali atau 270 derajat
				refleksi[i][j] = transpose[j][i];				//matriks transpose di transposekan dan masuk ke matriks refleksi
				akhir[i][j] = refleksi[i][kolom-j-1];			//matriks refleksi direfleksikan ke samping dan masuk ke matriks akhir
			}
		}
	}
	
}

//========== Rotasi Ke kanan ===============
void kanan(int sisa, int baris, int kolom){
	//jika hasil jumlah mod 4 = 0
	if(sisa == 0)
	{
		for(i=0;i<kolom;i++){									//perulangan i sebanyak kolom
			for(j=0;j<baris;j++){								//perulangan j sebanyak bari , hal ini terjadi karena ukuran matriks awal setelah di refleksi dan di transpose yaitu [kolom][baris]
				akhir[i][j] = transpose[i][j];					//matriks transpose di pindahkan ke matriks akhir
			}
		}
	}
	//jika jumlah mod 4 = 1
	else if(sisa == 1)
	{
		for(i=0;i<baris;i++){									//perulangan i sebanyak baris dan j sebanyak kolom
			for(j=0;j<kolom;j++){								//hal ini terjadi karena matriks berbentuk [baris][kolom]
				//putaran 1 kali atau 90 derajat
				refleksi[i][j] = transpose[j][i];				//matriks transpose di transposekan dan masuk ke matriks refleksi
				akhir[i][j] = refleksi[i][kolom-j-1];			//matriks refleksi direfleksikan ke samping dan masuk ke matriks akhir
			}
		}
	}
	//jika hasil jumlah mod 4 = 2
	else if(sisa == 2)
	{
		for(i=0;i<kolom;i++){
			for(j=0;j<baris;j++)
			{
				//putaran 180 derajat
				refleksi[i][j] = transpose[kolom-i-1][j];		//matriks transpose di refleksikan ke atas dan dipindahkan ke dalam matriks refleksi
			}
		}
		for(i=0;i<kolom;i++){
			for(j=0;j<baris;j++)
			{
				akhir[i][j] = refleksi[i][baris-j-1];			//matriks refleksi di refleksikan lagi ke samping dan di pindahkan ke matriks akhir
			}
		}
	}
	//jika jumlah mod 4 = 3
	else if(sisa == 3)
	{
		for(i=0;i<baris;i++){
			for(j=0;j<kolom;j++){
				//putaran 3 kali atau 270 derajat
				akhir[i][j] = awal[i][j];					//matriks inputan di pindahkan ke matriks akhir
			}												//karena rotasi ke 3 sama dengan matriks inputan
		}
	}
}

//======= Prosedur Output =========
void output(int baris, int kolom){
	
	refleksi_transpose(baris, kolom);				//Pemanggilan Prosedur Refleksi_transpose
	
	int sisa = 0;									//deklarasi variabel sisa untuk menampung nilai jumlag modulus 4
	sisa = jumlah % 4;
	
	//jika jumlah bernilai ganjil
	if(jumlah % 2 != 0){							
		kanan(sisa, baris, kolom);					// maka akan memanggil prosedur rotasi ke kanan
	}
	//jika tidak
	else{
		kiri(sisa, baris, kolom);					//akan memanggil prosedur rotasi ke kiri
	}
	
	//==== printf hasil akhir =====
		//jika sisa = 0 atau sisa = 2
	if((sisa == 0) || (sisa == 2))
	{
		for(i=0;i<kolom;i++){						//perulangan i sebanyak kolom dan j sebanyak baris
			for(j=0; j<baris; j++){					//karena output hasil sisa = 0 dan sisa = 2 memiliki bentuk matriks [kolom][baris]
				if(j != baris-1)					//jika indeks bukan indeks terakhir
				{
					printf("%d-", akhir[i][j]);
				}
				else								//jika indeks adalah indeks terakhir
				{	
					printf("%d-", akhir[i][j]);
				}
			}
			printf("\n");
		}	
	}
		//jika selain itu
	else
	{
		for(i=0;i<baris;i++){						//perulangan i sebanyak baris dan j sebanyak kolom	
			for(j=0; j<kolom; j++){					//karena output hasil sisa = 0 dan sisa = 2 memiliki bentuk matriks [baris][kolom]
				if(j != kolom-1)					//jika indeks bukan indeks terakhir
				{
					printf("%d-", akhir[i][j]);
				}
				else								//jika indek adalah indeks terakhir
				{
					printf("%d-", akhir[i][j]);
				}			
			}
			printf("\n");
		}
	}
	
	//menampilkan hasil perbandingan matriks hasil dengan matriks inputan
	int tanda = 0;								//deklarasi variabel penanda nilai
	
	for(i=0;i<baris;i++){						//perulangan i sebanyak baris dan j sebanyak kolom	
		for(j=0; j<kolom; j++){
			if(akhir[i][j] != awal[i][j]){		//
				tanda++;
			}
		}
	}
	
	//jika tanda > 1
	if(tanda > 0){
		printf("Wihh matrix yang seru!\n");
	}
	//jika selain 1
	else{
		printf("Coba lagi besok!\n");
	}
	
}
	