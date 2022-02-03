//MACRO
/* 
    - macro adalah bagian kode progam yang diberi nama
    - dapat didefinisikan dalam bahasa pemrogaman C
    - tujuan awal adalah untuk menyingkat kode progam
 */
/* 
    DEFINE:
    - define berfungsi untuk mendefinisikan macro berupa konstanta, pustaka
    maupun blok progam
    - define ditulis dibagian atas kode progam satu blok dengan include
    - konstanta adalah sejenis variabel namun memiliki nilai tetap/tidak berubah.
    contohnya phi = 3,14
    - berguna untuk membuat deklarasi yang digunakan berkali-kali
    contoh : #define batas 20    //konstanta dengan nama batas bernilai 20
 */

#include <stdio.h>
#include <string.h>

/* //contoh kode progam define
#define batas 20
#define nama "lovely"
#define pecahan 0.5

int main(){
    printf("nilai dari batas adalah : %d\n", batas);
    printf("nilai dari nama adalah : %s\n", nama);
    printf("nilai dari pecahan adalah : %d\n", pecahan);

    return 0;
} */

/* 
    const:
    - konstanta juga dapat dideklarasikan dengan menggunakan
    keyword const
 */

//contoh progam const

/* int main(){
    const int batas = 20;
    const char nama[10] = "lovely";
    const float pecahan = 0.5;

    printf("nilai dari batas adalah : %d\n", batas);
    printf("nilai dari nama adalah : %s\n", nama);
    printf("nilai dari pecahan adalah : %d\n", pecahan);
} */

/* 
    beberapa penulisan macro:
    1.  
        #ifdef MACRO
            //conditonal code
        #endif

    2. 
        #if expression
            //condtional code
        #endif

    3. 

        #if expression
            //condtional code if expresion is non-zero
        #else
            //conditonal if expresion is 0
        #endif

    4. 
        #if expression
            //condtional code if expresion is non-zero
        #elif expression1
            //condtional code if expresion is non-zero
        #elif expression2
            //condtional code if expresion is non-zero
        #else
            //conditonal if expresion is 0
        #endif
 */

// contoh contoh macro
/* #define increment(x) ++x

int main(){
    char *ptr = "0stayhappy";
    int x = 10;
    printf("%s\n", increment(ptr));
    printf("%d\n", increment(x));

    return 0;
} */

/* #define kali(a,b) (a) * (b)

int main(){
    printf("%d\n", kali(2+3, 3+5));

    return 0;
} */

/* #ifndef usia //jika usia belum didefinisikan nilainya
#define usia 10
#endif

int main(){
    printf("usianya %d tahun.\n", usia);

    return 0;
} */


/* 
    Macro dari kompilator:
    1. __DATE__ : string berisi tanggal saat ini
    2. __FILE__ : string berisi nama file
    3. __LINE__ : integer yang merepresentasikan nomor baris saat ini
    4. __TIME__ : string berisi waktu saat ini
 */

// contoh kode progam
/* int main(){
    printf("Waktu saat ini : %s\n", __TIME__);
    printf("Tanggal saat ini : %s\n", __DATE__);

    return 0;
} */

//nyoba
#define kali(i, x) for (i = 0; i < x; i++){ printf("hai\n"); }

int main(){
    int i = 0;
    kali(i, 3);

    return 0;
} 