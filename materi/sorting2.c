// Buble sort
/*
    sorting secara satu persatu angka
    sampai angka terurut
*/

//Contoh progam bubble sort
# include <stdio.h>
/*
int main(){
    int arrInt[5] = {34, 67, 23, 28, 98};
    int i; 
    int temp; 
    int tukar;

    do
    {
        tukar = 0;  //inisialiasi nilai tukar sebelum pertukaran
        //perulangan pertukaran
        for ( i = 0; i < 5-1; i++)
        {
            
            jika ascending
            if (arrInt[i] > arrInt[i+1])
            {
                temp = arrInt[i];
                arrInt[i] = arrInt[i+1];
                arrInt[i+1] = temp;
                tukar = 1;
            }

            //jika descending
            if (arrInt[i] < arrInt[i+1])
            {
                temp = arrInt[i];
                arrInt[i] = arrInt[i+1];
                arrInt[i+1] = temp;
                tukar = 1;
            }
            
        }
        
    } while (tukar == 1);
    
    for ( i = 0; i < 5; i++)
    {
        printf("%d ", arrInt[i]);
    }
    
    return 0;
}
*/

//Latihan mengurutkan pecahan dengan bubble sort
/*
typedef struct
{
    int pembilang;
    int penyebut;
}array;

array angka[4];

void bubble_lang(int i, int j, int temp_lang, int temp_but);
void bubble_but(int i, int j, int temp_lang, int temp_but);

int main(){
    int i,j,temp_lang,temp_but;
    char pengen;
    for ( i = 0; i < 4; i++)
    {
        scanf("%d", &angka[i].pembilang);
        scanf("%d", &angka[i].penyebut);
    }

    printf("apa yang ingi ditukar? (pembilang ketik A/a) (penyebut ketik B/b)\n");
    scanf(" %c", &pengen);

    if (pengen == 'A' || pengen == 'a')
    {
        bubble_lang(i, j, temp_lang, temp_but);
        for ( i = 0; i < 4; i++)
        {
            printf("|| %d %d ||\n", angka[i].pembilang, angka[i].penyebut);
        }
    }
    else if (pengen == 'B' || pengen == 'b')
    {
        bubble_but(i, j, temp_lang, temp_but);
        for ( i = 0; i < 4; i++)
        {
            printf("|| %d %d ||\n", angka[i].pembilang, angka[i].penyebut);
        }
    }
    else
    {
        printf("g ada bujang :v\n");
    }

    return 0;
}

void bubble_lang(int i, int j, int temp_lang, int temp_but){
    int swap;
    //secara descensding/ menurun (ascending tinggal ganti tanda)
    do
    {
        swap = 0;
        for (i = 0; i < 4-1; i++)
        {
            if (angka[i].pembilang < angka[i+1].pembilang)
            {
                //tukar pembilang
                temp_lang = angka[i].pembilang;
                angka[i].pembilang = angka[i+1].pembilang;
                angka[i+1].pembilang = temp_lang;

                //tukar penyebut
                temp_but = angka[i].penyebut;
                angka[i].penyebut = angka[i+1].penyebut;
                angka[i+1].penyebut = temp_but;

                swap = 1;
            }
        }   
    }while(swap == 1);
}

void bubble_but(int i, int j, int temp_lang, int temp_but){
    //secara descensding/ menurun (ascending tinggal ganti tanda)
    for(j = 0; j < 4 ; j++)
    {
        for (i = 0; i < 4-1; i++)
        {
            if (angka[i].penyebut < angka[i+1].penyebut)
            {
                //tukar pembilang
                temp_lang = angka[i].pembilang;
                angka[i].pembilang = angka[i+1].pembilang;
                angka[i+1].pembilang = temp_lang;

                //tukar penyebut
                temp_but = angka[i].penyebut;
                angka[i].penyebut = angka[i+1].penyebut;
                angka[i+1].penyebut = temp_but;
            }
        }   
    }
}
*/

//metode Quick sort
/*
    membagi menjadi partisi-partisi
*/

//contoh progam quick sort pivot pinggir
/*
void tulis(int tab[]);
void quickSortPinggir(int tab[], int l, int r);

int main(){
    int tab[5] = {34, 67, 23, 28, 98};
    tulis(tab);
    quickSortPinggir(tab, 0, 4);
    
    return 0;
}

void tulis(int tab[]){
    int i;
    for ( i = 0; i < 5; i++)
    {
        printf("%d ", tab[i]);
    }
    printf("\n");
}

void quickSortPinggir(int tab[], int l, int r){
    int i,j,temp;
    //int tab[5] = {34, 67, 23, 28, 98};
    i = l;
    j = r;

    do
    {
        //perulangan while secara ascending (jika ingin descending tinggal ganti tanda pada syarat while)
        while ((tab[i] < tab[r]) && (i<=j))
        {
            //mencegah i berjalan melewati batas j
            i = i + 1;
        }
        while ((tab[j] > tab[l]) && (i<=j))
        {
            //mencegah i berjalan meleawati batas i
            j = j - 1;
        }
        
        //proses menukar posisi jika ada yang tidak sesuai syarat while
        if (i < j)
        {
            temp = tab[i];
            tab[i] = tab[j];
            tab[j] = temp;

            i = i + 1;
            j = j - 1;
        }
    } while (i<j);

    tulis(tab);
    //bagian kiri ke tengah/pertemuan
    if (l < j)
    {
        quickSortPinggir(tab, l, j);
    }
    //bagian tengah/pertemuan ke kanan
    if (i < r)
    {
        quickSortPinggir(tab, i, r);
    }
}
*/

//contoh progam pivot tengah
void tulis(int tab[]);
void quickSortTengah(int tab[], int l, int r);

int main(){
    int tab[5] = {34, 67, 23, 28, 98};
    tulis(tab);
    quickSortTengah(tab, 0, 4);
    
    return 0;
}

void tulis(int tab[]){
    int i;
    for ( i = 0; i < 5; i++)
    {
        printf("%d ", tab[i]);
    }
    printf("\n");
}

void quickSortTengah(int tab[], int l, int r){
    int i,j,temp;
    //int tab[5] = {34, 67, 23, 28, 98};
    i = l;
    j = r;
    int pivot = tab[(l+r)/2];
    
    do
    {
        //perulangan while secara ascending (jika ingin descending tinggal ganti tanda pada syarat while)
        while ((tab[i] < pivot) && (i<=j))
        {
            //mencegah i berjalan melewati batas j
            i = i + 1;
        }
        while ((tab[j] > pivot) && (i<=j))
        {
            //mencegah i berjalan meleawati batas i
            j = j - 1;
        }
        
        //proses menukar posisi jika ada yang tidak sesuai syarat while
        if (i < j)
        {
            temp = tab[i];
            tab[i] = tab[j];
            tab[j] = temp;

            i = i + 1;
            j = j - 1;
        }
    } while (i<j);

    tulis(tab);
    //bagian kiri ke tengah/pertemuan
    if ((l < j) && (j < r) && (i != j))
    {
        /*
        syarat bertambah karena ada kemungkinan i = j berhentinya.
        yang artinya harusnya sudah tidak ada lagi proses pengurutan 2 kali
        karena sudah di jalankan di rekursif bagian bawah
        */

        quickSortTengah(tab, l, j);
    }
    //bagian tengah/pertemuan ke kanan
    if ((i < r) && (i > l))
    {
        /*
            syarat bertambah karena ada kemungkinan ternyata i sama dengan
            l yang artinya bahkan i tidak berjalan sama sekali ke depan.
        */

        quickSortTengah(tab, i, r);
    }
    
}