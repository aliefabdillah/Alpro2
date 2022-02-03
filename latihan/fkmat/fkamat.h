//bagian header

#include <stdio.h>

int i,j;
int hasil[50];
int kolom[10];
int baris[10];
int akhir[10];

void input();
void faktorial_kolom(int k, int kol, int temp);
int faktorial_baris(int b, int bar);
void output(int b, int k, int bar, int kol, int temp);
