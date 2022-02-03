#include "header.h"

//reset tampungan kata
void resetKata(){
	panjangkata = 0;
	currentKata[panjangkata] = '\0';
}


//pengecek apakah pita inputan sudah selesai
int eopKata(char pita[]){
  //bila bertemu titik, maka itu adalah akhir dari pita inputan
	if (pita[indeks] == '.'){ flag=0;return 1;}
	else return 0;
}


int isVocal(char a){
  if(a=='a' || a=='i' || a =='u' || a=='e' || a=='o'){
    return 1;
  }
  else{
    return 0;
  }
}

//mulai cek pita
void startKata(char pita[]){
	panjangkata = 0;
/*kondisi ini berlaku bila pada awal pita terdapat beberapa
	spasi sebelum kata pertama*/
	while(pita[indeks] == ' ') {
	    indeks++;
	}
	

	//proses menampung kata 
	while((pita[indeks] != ' ') && (eopKata(pita) == 0)) {
	    currentKata[panjangkata] = pita[indeks];
	    indeks++;
	    panjangkata++;
	}
  indeks++;
	//kosongkan karakter pada indeks panjang dari kata tampungan
	currentKata[panjangkata] = '\0';
}


char *getCurrentKata(){
	return currentKata;
}
//dapatkan panjang kata yang sedang ditampung
int getPanjangKata(){
	return panjangkata;
}

//Pencarian kata yang sesuai kirteria
void algoritma(int tmpPanjangKata){
  int flagg=1;
  int i=0;
  while(i<=tmpPanjangKata-5 && flagg){
    if(isVocal(currentKata[i])==1 && isVocal(currentKata[i+1])==0 && isVocal(currentKata[i+2])==0 && isVocal(currentKata[i+3])==0 && isVocal(currentKata[i+4])==1){
      printf("%s\n",currentKata);
      flagg=0;
      jumlah++;
    } 
    i++;
  }
}
