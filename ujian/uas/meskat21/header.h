/*saya Farhan Dwian Saputra 2002969 
		mengerjakan uas dalam mata kuliah Algoritma 
		dan Pemograman II untuk keberkahanNya maka saya 
		tidak melakukan kecurangan seperti yang telah 
		dispesifikasikan. Aamiin*/

#include <stdio.h>
#include <string.h>

int flag;
int indeks; //cek indeks dari pita inputan
int panjangkata; //tampungan panjang kata
char currentKata[50]; //tampungan kata yang sedang dicek pada pita
int jumlah;

void resetKata();
int eopKata(char pita[]);
int isVocal(char a);
void startKata(char pita[]);
char *getCurrentKata();
int getPanjangKata();
void algoritma(int tmpPanjangKata);