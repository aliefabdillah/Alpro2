//PRAKTIKUM MERGE TABEL
/*macam macam merger :
    1. Merge Tidak Urut
    2. Merge Urut
*/

#include <stdio.h>
#include <string.h>

//contoh progam merge tidak urut
/*
    alur merge tidak urut :
    1. diasumsikan ada 3 array
    2. mengisi array pertama
    3. mengisi array kedua
    4. masukkan semua isi array 1  ke array 3
    5. lanjutkan masukkan semua isi array 2 ke array 3
*/
/*
void tidak_urut(int n, int arr1[], int m, int arr2[], int arr3[]){
    int i;
    int count = 0;

    for ( i = 0; i < n; i++)
    {
        arr3[count] = arr1[i];
        count++;
    }
    
    for ( i = 0; i < m; i++)
    {
        arr3[count] = arr2[i];
        count++;
    }
    
}

int main(){
    int n,m;
    int i;
    scanf("%d", &n);
    scanf("%d", &m);

    int arr1[n];
    int arr2[m];
    int arr3[n+m];

    for ( i = 0; i < n; i++)
    {
        scanf("%d", &arr1[i]);
    }

    for ( i = 0; i < m; i++)
    {
        scanf("%d", &arr2[i]);
    }

    tidak_urut(n, arr1, m, arr2, arr3);

    for ( i = 0; i < n+m; i++)
    {
        printf("%d ", arr3[i]);
    }

    return 0;   
}
*/

//contoh progam merge urut
/*
    alur merge urut :
    1. diasumsikan ada 3 array
    2. mengisi array pertama
    3. mengisi array kedua
    4. sorting arrat pertama
    5. sorting array kedua
    6. looping membandingkan dan memasukan ke array 3
    7. jika array pertama masih sisa, masukan sisa array pertama pada array 3
    8. jika array kedua masih sisa, masukan sisa array kedua pada array 3
*/

/*
void urut_asc(int n, int arr1[], int m, int arr2[], int arr3[]){
    int i = 0,j = 0,k = 0,l = 0;

    while ((i < n) && (j < m))
    {
        if (arr1[i] < arr2[j])
        {
            arr3[k] = arr1[i];
            i++;
            k++;
        }
        else if (arr2[j] < arr1[i])
        {
            arr3[k] = arr2[j];
            j++;
            k++;
        }
        else
        {
            arr3[k] = arr1[i];
            i++;
            k++;

            arr3[k] = arr2[j];
            j++;
            k++;
        }
    }

    if (i < n)
    {
        for ( l = i; l < n; l++)
        {
            arr3[k] = arr1[l];
            k++;
        }
    }

    if (j < m)
    {
        for ( l = j; l < m; l++)
        {
            arr3[k] = arr2[l];
            k++;
        }
    }
}

void sorting(int n, int arr1[], int m, int arr2[], int arr3[]){
    int i,j; 
    int min, temp;

    
    //sorting array 1
    for ( i = 1; i < n; i++)
    {
        min = arr1[i];
        j = i - 1;
        while((arr1[j] > min) && (j >= 0))
        {
            arr1[j+1] = arr1[j];
            j--;
        }
        arr1[j+1] = min; 
    }
    
    
    //sorting array 2
    for ( i = 1; i < n; i++)
    {
        min = arr2[i];
        j = i - 1;
        while((arr2[j] > min) && (j >= 0))
        {
            arr2[j+1] = arr2[j];
            j--;
        }
        arr2[j+1] = min; 
    }
}

int main(){
    int n,m;
    int i;
    scanf("%d", &n);
    scanf("%d", &m);

    int arr1[n];
    int arr2[m];
    int arr3[n+m];

    for ( i = 0; i < n; i++)
    {
        scanf("%d", &arr1[i]);
    }

    for ( i = 0; i < m; i++)
    {
        scanf("%d", &arr2[i]);
    }

    sorting(n, arr1, m, arr2, arr3);
    urut_asc(n, arr1, m, arr2, arr3);

    for ( i = 0; i < n+m; i++)
    {
        printf("%d ", arr3[i]);
    }

   return 0;
}
*/

//latihan 1
/*
void sorting(int n, char arr1[][50], int m, char arr2[][50]){
    int i, j;
    char sisip[50];

    //sorting arr1
    for ( i = 0; i < n; i++)
    {
        strcpy(sisip, arr1[i]);
        j = i - 1;
        while ((j >= 0) && (strcmp(sisip, arr1[j]) < 0))
        {
            strcpy(arr1[j+1], arr1[j]);
            j--;
        }
        strcpy(arr1[j+1], sisip);
    }

    //sorting arr2
    for ( i = 0; i < m; i++)
    {
        strcpy(sisip, arr2[i]);
        j = i - 1;
        while ((j >= 0) && (strcmp(sisip, arr2[j]) < 0))
        {
            strcpy(arr2[j+1], arr2[j]);
            j--;
        }
        strcpy(arr2[j+1], sisip);
    }
    
}
void urut_asc(int n, char arr1[][50], int m, char arr2[][50], char arr3[][50]){
    int i = 0,j = 0,k = 0,l = 0;

     while ((i < n) && (j < m))
    {
        if (strcmp(arr1[i], arr2[j]) < 0)
        {
            strcpy(arr3[k], arr1[i]);
            i++;
            k++;
        }
        else if (strcmp(arr2[j], arr1[i]) < 0)
        {
            strcpy(arr3[k], arr2[j]);
            j++;
            k++;
        }
        else
        {
            strcpy(arr3[k], arr1[i]);
            i++;
            k++;

            strcpy(arr3[k], arr2[j]);
            j++;
            k++;
        }
    }

    if (i < n)
    {
        for ( l = i; l < n; l++)
        {
            strcpy(arr3[k], arr1[l]);
            k++;
        }
    }

    if (j < m)
    {
        for ( l = j; l < m; l++)
        {
            strcpy(arr3[k], arr2[l]);
            k++;
        }
    }
}

void cetak(int n, int m, char arr3[][50]){
    int i;

    printf("\n");
    for ( i = 0; i < n+m; i++)
    {
        printf("%s\n", arr3[i]);
    }
    
}

int main(){
    int i;

    int n;
    scanf("%d", &n);
    char arr1[n][50];
    for ( i = 0; i < n; i++)
    {
        scanf("%s", &arr1[i]);
    }

    int m;
    scanf("%d", &m);
    char arr2[m][50];
    for ( i = 0; i < m; i++)
    {
        scanf("%s", &arr2[i]);
    }
    
    char arr3[n+m][50];

    sorting(n, arr1, m, arr2);
    urut_asc(n, arr1, m, arr2, arr3);
    cetak(n, m, arr3);

    return 0;
}
*/

//latihan 2

void sorting(int n, char arr1[][50], int m, char arr2[][50], int o, char arr3[][50]){
    int i, j;
    char sisip[50];

    //sorting arr1
    for ( i = 0; i < n; i++)
    {
        strcpy(sisip, arr1[i]);
        j = i - 1;
        while ((j >= 0) && (strcmp(sisip, arr1[j]) > 0))
        {
            strcpy(arr1[j+1], arr1[j]);
            j--;
        }
        strcpy(arr1[j+1], sisip);
    }

    //sorting arr2
    for ( i = 0; i < m; i++)
    {
        strcpy(sisip, arr2[i]);
        j = i - 1;
        while ((j >= 0) && (strcmp(sisip, arr2[j]) > 0))
        {
            strcpy(arr2[j+1], arr2[j]);
            j--;
        }
        strcpy(arr2[j+1], sisip);
    }

    //sorting arr3
    for ( i = 0; i < o; i++)
    {
        strcpy(sisip, arr3[i]);
        j = i - 1;
        while ((j >= 0) && (strcmp(sisip, arr3[j]) > 0))
        {
            strcpy(arr3[j+1], arr3[j]);
            j--;
        }
        strcpy(arr3[j+1], sisip);
    }

    
}

void urut_desc(int n, char arr1[][50], int m, char arr2[][50], char temp[][50]){
    int i = 0,j = 0,k = 0,l = 0;

    while ((i < n) && (j < m))
    {
        if (strcmp(arr1[i], arr2[j]) > 0)       //descending jika arr1 abjadnya lebih tinggi dari arr2
        {
            strcpy(temp[k], arr1[i]);
            i++;
            k++;
        }
        else if (strcmp(arr2[j], arr1[i]) > 0)  //descending jika arr2 abjadnya lebih tinggi dari arr1
        {
            strcpy(temp[k], arr2[j]);
            j++;
            k++;
        }
        else                                   //jika sama
        {
            strcpy(temp[k], arr1[i]);
            i++;
            k++;

            strcpy(temp[k], arr2[j]);
            j++;
            k++;
        }
    }

    if (i < n)                              //jika masih ada sisa array 1
    {
        for ( l = i; l < n; l++)
        {
            strcpy(temp[k], arr1[l]);
            k++;
        }
    }

    if (j < m)                              //jika masih ada sisa di array 2
    {
        for ( l = j; l < m; l++)
        {
            strcpy(temp[k], arr2[l]);
            k++;
        }
    }
}

void urut_desc2(int n, int m, char temp[][50], int o, char arr3[][50], char hasil[][50]){
    int i = 0,j = 0,k = 0,l = 0;

    //perulangan sepanjang i < n+m dan j < o
    while ((i < n+m) && (j < o))
    {
        if (strcmp(temp[i], arr3[j]) > 0)           //descending jika temp abjadnya lebih tinggi dari arr3
        {
            strcpy(hasil[k], temp[i]);
            i++;
            k++;
        }
        else if (strcmp(arr3[j], temp[i]) > 0)      //descending jika arr3 abjadnya lebih tinggi dari temp
        {
            strcpy(hasil[k], arr3[j]);
            j++;
            k++;
        }
        else                                    //jika sama
        {
            strcpy(hasil[k], temp[i]);
            i++;
            k++;

            strcpy(hasil[k], arr3[j]);
            j++;
            k++;
        }
    }

    if (i < n+m)                            //jika masih ada sisa di temp dan i nyamasih < dari n+m/panjang temp
    {
        for ( l = i; l < n+m; l++)
        {
            strcpy(hasil[k], temp[l]);
            k++;
        }
    }

    if (j < o)                          //jika masih ada sisa di arr3 dan j nyamasih < dari o/panjang arr3
    {
        for ( l = j; l < o; l++)
        {
            strcpy(hasil[k], arr3[l]);
            k++;
        }
    }
}

void cetak(int n, int m, int o, char hasil[][50]){
    int i;

    printf("\n");
    for ( i = 0; i < n+m+o; i++)        //print dengan perulangan syarat i < panjang hasil/n+m+o
    {
        printf("%s\n", hasil[i]);
    }
}

int main(){
    int i;

    //masukan array1
    int n;
    scanf("%d", &n);
    char arr1[n][50];
    for ( i = 0; i < n; i++)
    {
        scanf("%s", &arr1[i]);
    }

    //masukan array2
    int m;
    scanf("%d", &m);
    char arr2[m][50];
    for ( i = 0; i < m; i++)
    {
        scanf("%s", &arr2[i]);
    }

    //masukan array3
    int o;
    scanf("%d", &o);
    char arr3[o][50];
    for ( i = 0; i < o; i++)
    {
        scanf("%s", &arr3[i]);
    }
    
    char temp[n+m][50];         //gabungan arra1 dan 2
    char hasil[n+m+o][50];      //gabungan temp dengan array 3

    sorting(n, arr1, m, arr2, o, arr3);    //panggil prosedur sorting
    urut_desc(n, arr1, m, arr2, temp);      //panggil prosedur gabung 1 dan 2
    urut_desc2(n, m, temp, o, arr3, hasil); //panggil prosedur gabung temp(1 dan 2) dan 3
    cetak(n, m, o, hasil);

    return 0;
}

/*
2
gehu
balabala
4
nasigoreng
kupattahu
mieayam
soto
3
esseruk
escampur
esjeruk
*/


/*
3
alpro1
statistika
logif
4
basisdata
mstr
etikaprofesi
alin
*/