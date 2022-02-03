#include"tmd.h"

int main(){
    char tape[200]; 
    int cek = 0;
    int cek_if = 0;
    system("cls");
    printf("WELCOME TO FAJRI MAULANA ISKANDAR DBMS HALAQOH SANTRI  version 1.0\n");
        	    							                                    //variabel pita kata										//masukan pita
        while (cek_if == 0)
        {
            scanf(" %199[^\n]s", tape);
            if(cekQuery(tape)==1){
            read(tape);
            findIdx(tape);
            insert(tape);
         }else if(cekQuery(tape)==2){
             read(tape);
             findIdx(tape);
            update(tape);
         }else if(cekQuery(tape)==3){
            read(tape);
            findIdx(tape);
            update(tape);
         }else if(cekQuery(tape)==4){
             read(tape);
            findIdx(tape);
             deleteData(tape);
         }else if(cekQuery(tape)==5){
            read(tape);
            select(tape);
         }else if(cekQuery(tape)==6){
            cek_if = 1;
        }else {
            printf("\nERROR..........................\n"); //jika tabel di cari tidak ada
            printf("SYNTAX ERROR  [ COMMANDS WRONG ]\n");
         }
     }

        printf("\nPROGRAM END\n");
        system("exit");
    
    return 0;
    
}