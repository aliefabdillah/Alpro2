#include "headabs_prak.h"
//implementasi mesin karakter - Start
void start(char kata[]){
    indeks = 0;
    cc = kata[indeks];
}

//implementasi mesin karakter - Inc
void inc(char kata[]){
    indeks++;
    cc = kata[indeks];
}

//implementasi mesin karakter - EOP
/* int eop(){
    if (cc == '.')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
 */

int eop(){
    if (cc == ';')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//implementasi mesin karakter - adv
void adv(char kata[]){
    indeks++;
    cc = kata[indeks];
    while ((cc == ' ') && (eop() == 0))
    {
        indeks++;
        cc = kata[indeks];
    }
}

//implementasi mesin karakter - Get CC
char get_cc(){
    return cc;
}

int get_indeks(){
    return indeks+1;
}


