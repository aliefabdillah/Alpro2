//bagian mesin

#include "fkamat.h"

void input(){
    printf("K\n");
    int k;
    scanf("%d", &k);

    for (i = 0; i < k; i++)
    {
        scanf("%d", &kolom[i]);
    }

    printf("B\n");
    int b;
    scanf("%d", &b);

    for (i = 0; i < b; i++)
    {
        scanf("%d", &baris[i]);
    }
    
    int kol = 0;
    int bar = 0;
    int temp = 0;
    //output(b, k, bar, kol, temp);
    faktorial_kolom(k, kol, temp);
}

void output(int b, int k, int bar, int kol, int temp){
    akhir[10] = faktorial_kolom(k, kol, temp);

    for (i = 0; i < k; i++)
    {
        
    }
    
}


void faktorial_kolom(int k, int kol, int temp){
    if(kol < k){
        if(kolom[kol] == 0 || kolom[kol] == 1){
            temp = 1;
        }
        else{
            temp = kolom[kol];
            temp = temp * faktorial_kolom(k, kol, temp-1);
            kolom[kol] = temp;
        }
    }
    else if(kol == k){
    for (i = 0; i < k; i++)
    {
        printf("%d ", kolom[i]);
    }
    }

}

int faktorial_baris(int b, int bar){
        if (baris[i] == 0 || baris[i] == 1)
        {
            return 1;
        }
        else
        {
            return(baris[i] * faktorial_baris(b, bar));
        }
}