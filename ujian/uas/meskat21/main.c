#include "header.h"
int main(void) {
    flag=1;
    indeks=0;
    jumlah=0;
	char pita[300];
	scanf("%299[^\n]s", pita);
  
  while(!eopKata(pita) && flag){
   // printf("Nilai Indeks %d\n",indeks);
    startKata(pita);
    //char *tmpCurrentKata = getCurrentKata();
    int tmpPanjangKata = getPanjangKata();
    algoritma(tmpPanjangKata);
    resetKata();
  }

  printf("%d\n",jumlah);
	
  return 0;
}