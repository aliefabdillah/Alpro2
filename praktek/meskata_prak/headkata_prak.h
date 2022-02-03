#include <stdio.h>
#include <string.h>

//typedef untuk progam insert data ke bungkusan
typedef struct 
{
    char nim[10];
    char nama[100];
    char nilai[10];
}mahasiswa;

//variabel global
int indeks;
int panjang_kata;
char current_kata[50];

void start_kata(char kalimat[]);
void reset_kata();
void inc_kata(char kalimat[]);
char *get_kata();
int get_panjang_kata();
int eop_kata(char kalimat[]);
void insert_data(char kalimat[], mahasiswa *data);