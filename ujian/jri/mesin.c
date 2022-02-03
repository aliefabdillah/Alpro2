#include"tmd.h"

//pengecek apakah pita perkata bertemu tanda ;
int EOP(char tape[]){
    if(tape[idx] == ';'){ //jika iya
        return 1;
    }else {               //jika tidak
        return 0;
    }
}

void START(char tape[]){
	idx = 0; //karena start ada diawal pita, maka nilai indeks adalah 0
	lenkata = 0;
	/*kondisi ini berlaku bila pada awal pita terdapat beberapa
	spasi sebelum kata pertama*/
	while(tape[idx] == ' ') {
	    idx++;
	}
	//proses menampung kata pertama
	while((tape[idx] != ' ') && (EOP(tape) == 0)) {
	    ckata[lenkata] = tape[idx];
	    idx++;
	    lenkata++;
	}
	//kosongkan karakter pada indeks panjang dari kata tampungan
	ckata[lenkata] = '\0';
}

//dapatkan kata yang sedang ditampung
char *GETCURRENTWORD(){
	return ckata;
}

//prosedur mereset kata
void RESET(){
	lenkata = 0;
	ckata[lenkata] = '\0';
}

//maju satu kata pada pita
void INC(char tape[]){
	lenkata = 0;
	/*kondisi ini berlaku bila pada pengecekan pita terdapat beberapa
	spasi sebelum kata berikutnya*/
	while(tape[idx] == ' ') {
	    idx++;
	}
	//proses menampung kata berikutnya
	while((tape[idx] != ' ') && (EOP(tape) == 0)) {
	    ckata[lenkata] = tape[idx];
	    idx++;
	    lenkata++;
	}

	ckata[lenkata] = '\0';
}

//dapatkan panjang kata yang sedang ditampung
int GETLENGTWORD(){
	return lenkata;
}

//fungsi mencari mengecek command query masukan
int cekQuery(char tape[]){
    int find = 0; //parameter masukan 
    START(tape);
    if(strcmp(GETCURRENTWORD(), "INSERT")==0){  //jika command query diterima insert
        find = 1;
        INC(tape);
        if(strcmp(GETCURRENTWORD(), "tTahsin")==0 || strcmp(GETCURRENTWORD(), "tTahfidz")==0){
            find = 1;
        }else if(strcmp(GETCURRENTWORD(), "UPDATE")==0 || strcmp(GETCURRENTWORD(), "UPDATE")==0){
            find = 2; //jika commadn query masukan di terima insert update
        }
    }else if(strcmp(GETCURRENTWORD(), "UPDATE")==0){ //jika query masukan diterima update
        find = 3;
    }else if(strcmp(GETCURRENTWORD(), "DELETE")==0){    //jika query masukan diterima delete
        find = 4;
    }else if(strcmp(GETCURRENTWORD(), "SELECT")==0){    //jika query masukan diterima select
        find = 5;
    }else if(strcmp(GETCURRENTWORD(), "EXIT")==0){
        find = 6;
    }
    return find;    //mereturn nilai find yang diterima setiap syarat diatas
}

//fungsi searching mencari index yang sama konsep sequential search
int findIdx(char tape[]){
    START(tape);
    if(cekQuery(tape) == 1){    //jika cekquery bernilai 1
        START(tape);    //increment kata dilakukan satu kali
        INC(tape);
    }else if((cekQuery(tape) == 3) || (cekQuery(tape) == 4) || (cekQuery(tape) == 5)){  //jika cekquery bernilai 3/4/5
        INC(tape); //incremet kata dilakukan satu kali tanpa memulai start kata
    }else if(cekQuery(tape) == 2){ //jika cekquery bernilai 2
        START(tape); //increment kata dilakukan dua kali dengan memulai start kata
        INC(tape);
        INC(tape);
    }
    int find = 0; //parameter ditemukannya index yang sama
    int i = 0; //iterator perulangan
    upIdx = 0; //penampung index yang diterima perulangan iterator
    if(strcmp(GETCURRENTWORD(), "tTahsin")==0){ //jika dimasukan user tabel tahsin
        INC(tape); //inc sekali
        while ((i < dIdx)&&(find==0)){  //jika batas dari read dan parameter bernilai false
            if(strcmp(data[i].id_ths, GETCURRENTWORD())==0){   //jika data indeks yang sama ditemukan
                find = 1;   //parameter bernilai true
                upIdx = i; //menampung indeks yang sudah ditemukan
            }else {
                i++; //jika belum ditemukan iterator mencari seterusnya
            }
        }
    }else if(strcmp(GETCURRENTWORD(), "tTahfidz")==0){  //jika dimasukan user tabel tahsin
        INC(tape);
        upIdx = 0;
        while ((i < dIdx)&&(find==0)){ //jika batas dari read dan parameter bernilai false
            if(strcmp(data[i].id_tdz, GETCURRENTWORD())==0){ //jika data indeks yang sama ditemukan
                find = 1;   //parameter bernilai true
                upIdx = i; //menampung indeks yang sudah ditemukan
            }else {
                i++; //jika belum ditemukan iterator mencari seterusnya
            }
        }
    }
    return find; //mengembalikan nilai find
}

//fungsi menghitung total masukan yang ada pada masukan user
int cekTotal(char tape[]){
    START(tape);
    if(cekQuery(tape) == 1){    //jika cekquery bernilai 1
        START(tape);    //increment kata dilakukan satu kali
        INC(tape);
    }else if((cekQuery(tape) == 3) || (cekQuery(tape) == 4) || (cekQuery(tape) == 5)){  //jika cekquery bernilai 3/4/5
        INC(tape); //incremet kata dilakukan satu kali tanpa memulai start kata
    }else if(cekQuery(tape) == 2){ //jika cekquery bernilai 2
        START(tape); //increment kata dilakukan dua kali dengan memulai start kata
        INC(tape);
        INC(tape);
    }
    int total = 0; //total data di set 0
    while(EOP(tape)==0){ //jika eop pita belum ditemukan
    INC(tape);
        if(GETLENGTWORD() > 0){ //jika terdapat kata di ukur dari jumlah kata dan lebih dari 0
            total++; //total bertambah
        }

    }
    return total; //fungsi mereturn total
}     

//prosedur membaca file pada record data dat.
void read(char tape[]){
    int i;
    dIdx = 0;
    START(tape);
    if(cekQuery(tape) == 1){    //jika cekquery bernilai 1
        START(tape);    //increment kata dilakukan satu kali
        INC(tape);
    }else if((cekQuery(tape) == 3) || (cekQuery(tape) == 4) || (cekQuery(tape) == 5)){  //jika cekquery bernilai 3/4/5
        INC(tape); //incremet kata dilakukan satu kali tanpa memulai start kata
    }else if(cekQuery(tape) == 2){ //jika cekquery bernilai 2
        START(tape); //increment kata dilakukan dua kali dengan memulai start kata
        INC(tape);
        INC(tape);
    }
        if(strcmp(GETCURRENTWORD(), "tTahsin")==0){
            santri[0] = fopen("tTahsin.dat", "r");
             fscanf(santri[0], "%s %s %s", &data[dIdx].id_ths, &data[dIdx].nama_ths, &data[dIdx].halaqoh_ths);
            while(strcmp(data[dIdx].id_ths, "####") != 0){ //jika data belum eop file
                     dIdx++; //index maju
                    fscanf(santri[0], "%s %s %s", &data[dIdx].id_ths, &data[dIdx].nama_ths, &data[dIdx].halaqoh_ths); //membaca data dalam file
                 }
                 fclose(santri[0]); //menutup file
        }else if(strcmp(GETCURRENTWORD(), "tTahfidz")==0){
            santri[1] = fopen("tTahfidz.dat", "r");
            fscanf(santri[1], "%s %s %s", &data[dIdx].id_tdz, &data[dIdx].nama_tdz, &data[dIdx].halaqoh_tdz);
            while(strcmp(data[dIdx].id_tdz, "####") != 0){ //jika data belum eop file
                     dIdx++; //index maju
                    fscanf(santri[1], "%s %s %s", &data[dIdx].id_tdz, &data[dIdx].nama_tdz, &data[dIdx].halaqoh_tdz); //membaca data dalam file
                 }
                 fclose(santri[1]); //menutup file
        }
}

//prosedur membaca file/menyalin file kedalam record data file dat.
void write(char tape[]){
    int i;
    START(tape);
    if(cekQuery(tape) == 1){    //jika cekquery bernilai 1
        START(tape);    //increment kata dilakukan satu kali
        INC(tape);
    }else if((cekQuery(tape) == 3) || (cekQuery(tape) == 4) || (cekQuery(tape) == 5)){  //jika cekquery bernilai 3/4/5
        INC(tape); //incremet kata dilakukan satu kali tanpa memulai start kata
    }else if(cekQuery(tape) == 2){ //jika cekquery bernilai 2
        START(tape); //increment kata dilakukan dua kali dengan memulai start kata
        INC(tape);
        INC(tape);
    }
        if(strcmp(GETCURRENTWORD(), "tTahsin")==0){ //jika masukan tabel tahsin
            santri[0] = fopen("tTahsin.dat", "w"); //membuka file
            for(i=0; i<dIdx; i++){ //menulis record data dalam file
                fprintf(santri[0], "%s %s %s\n", data[i].id_ths, data[i].nama_ths, data[i].halaqoh_ths);
            }
            fprintf(santri[0], "#### #### ####\n"); //menulis data dummy
            fclose(santri[0]);
    }else if(strcmp(GETCURRENTWORD(), "tTahfidz")==0){ //jika masukan tabel tahfidz
            santri[1] = fopen("tTahfidz.dat", "w"); //membuka file
            for(i=0; i<dIdx; i++){ //menulis record data dalam file
                fprintf(santri[1], "%s %s %s\n", data[i].id_tdz, data[i].nama_tdz, data[i].halaqoh_tdz);
            }
            fprintf(santri[1], "#### #### ####\n"); //menulis data dummy
            fclose(santri[1]); //menutup file
        }
}

//prosedur insert data record
void insert(char tape[]){
    START(tape);
    if(cekQuery(tape) == 1){    //jika cekquery bernilai 1
        START(tape);    //increment kata dilakukan satu kali
        INC(tape);
    }else if((cekQuery(tape) == 3) || (cekQuery(tape) == 4) || (cekQuery(tape) == 5)){  //jika cekquery bernilai 3/4/5
        INC(tape); //incremet kata dilakukan satu kali tanpa memulai start kata
    }else if(cekQuery(tape) == 2){ //jika cekquery bernilai 2
        START(tape); //increment kata dilakukan dua kali dengan memulai start kata
        INC(tape);
        INC(tape);
    }

    if(strcmp(GETCURRENTWORD(), "tTahsin")==0){ //jika diminta tabel tahsin
        if(cekTotal(tape) == 3){ //jika jumlah masukan ada 3
            START(tape); //memulai kata masukan ulang dan inc 2 kali
            INC(tape);
            INC(tape);
            if(strcmp(GETCURRENTWORD(), data[upIdx].id_ths)!=0){ //jika primary key tidak sama
                strcpy(data[dIdx].id_ths, GETCURRENTWORD()); //mengisi data update dari masukan user
                INC(tape);
                strcpy(data[dIdx].nama_ths, GETCURRENTWORD());
                INC(tape);
                strcpy(data[dIdx].halaqoh_ths, GETCURRENTWORD());
                dIdx++;
                printf("\nINSERT DATA HAS SUCCESFULLY..........\n"); //tanda masukan update telah sukses
                write(tape);
                printf("\n%d row in set TAHSIN.\n", dIdx); //jumlah data record yang ada
            }else {
                printf("\nERROR INSERT DATA HAS UNSUCCESFULLY..........\n"); //jika primary sama data telah ada
                printf("SYNTAX ERROR  [ DATA ALREADY EXISTS ]\n");
            }
        }else if (cekTotal(tape) < 3){
            printf("\nERROR INSERT DATA HAS UNSUCCESFULLY..........\n"); //jika masukan user kelebihan
            printf("SYNTAX ERROR  [ SYNTAX OUT of LOAD ]\n");
        }else if (cekTotal(tape) > 3){
            printf("\nERROR INSERT DATA HAS UNSUCCESFULLY..........\n"); //jika masukan user kekurangan
            printf("SYNTAX ERROR  [ SYNTAX OVER LOAD ]\n");
        }
    }else if(strcmp(GETCURRENTWORD(), "tTahfidz")==0){ //jika diminta tabel tahfidz
        INC(tape);
        if(cekTotal(tape) == 3){ //jika masukan user ada 3
            START(tape); //memulai kata dan inc 2 kali
            INC(tape);
            INC(tape);
            if(strcmp(GETCURRENTWORD(), data[upIdx].id_tdz)!=0){ //jika primary key tidak sama
                strcpy(data[dIdx].id_tdz, GETCURRENTWORD()); //menginsert data dari masukan user
                INC(tape);
                strcpy(data[dIdx].nama_tdz, GETCURRENTWORD());
                INC(tape);
                strcpy(data[dIdx].halaqoh_tdz, GETCURRENTWORD());
                dIdx++;
                printf("\nINSERT DATA HAS SUCCESFULLY..........\n"); //tabda data berhasil di insert
                write(tape);
                printf("\n%d row in set TAHFIDZ.\n", dIdx);
            }else {
                printf("\nERROR INSERT DATA HAS UNSUCCESFULLY..........\n"); //jika data record sudah ada
                printf("SYNTAX ERROR  [ DATA ALREADY EXISTS ]\n");
            }
        }else if (cekTotal(tape) < 3){
            printf("\nERROR INSERT DATA HAS UNSUCCESFULLY..........\n"); //jika data kelebihan
            printf("SYNTAX ERROR  [ SYNTAX OUT of LOAD ]\n");
        }else if (cekTotal(tape) > 3){
            printf("\nERROR INSERT DATA HAS UNSUCCESFULLY..........\n"); //jika data masukan kekurangan
            printf("SYNTAX ERROR  [ SYNTAX OVER LOAD ]\n");
        }
    }else {
        printf("\nERROR INSERT DATA HAS UNSUCCESFULLY..........\n"); //jika tabel di cari tidak ada
        printf("SYNTAX ERROR  [ TABLE NOT FOUND ]\n");
    }
}

//prosedur untuk mengupdate data record yang sudah ada
void update(char tape[]){
    START(tape);
    if(cekQuery(tape) == 1){    //jika cekquery bernilai 1
        START(tape);    //increment kata dilakukan satu kali
        INC(tape);
    }else if((cekQuery(tape) == 3) || (cekQuery(tape) == 4) || (cekQuery(tape) == 5)){  //jika cekquery bernilai 3/4/5
        INC(tape); //incremet kata dilakukan satu kali tanpa memulai start kata
    }else if(cekQuery(tape) == 2){ //jika cekquery bernilai 2
        START(tape); //increment kata dilakukan dua kali dengan memulai start kata
        INC(tape);
        INC(tape);
    }
         if(strcmp(GETCURRENTWORD(), "tTahsin")==0){ //jika diminta tabel tahsin
             INC(tape);
                 if(strcmp(GETCURRENTWORD(), data[upIdx].id_ths)==0){ //jika data record ditemukan
                 strcpy(data[upIdx].id_ths, GETCURRENTWORD()); //mengupdate data yang baru
                 INC(tape);
                 strcpy(data[upIdx].nama_ths, GETCURRENTWORD());
                 INC(tape);
                 strcpy(data[upIdx].halaqoh_ths, GETCURRENTWORD());
                
             }
             printf("\nUPDATE DATA HAS SUCCESFULLY..........\n"); //tanda data berhasil di update
             write(tape); 
             printf("\n%d row in set TAHSIN.\n", dIdx);
         }else if(strcmp(GETCURRENTWORD(), "tTahfidz")==0){ //jika diminta tabel tahfidz
             INC(tape);
                 if(strcmp(GETCURRENTWORD(), data[upIdx].id_tdz)==0){ //jika data record ditemukan
                 strcpy(data[upIdx].id_tdz, GETCURRENTWORD());// mengupdate data yang baru
                 INC(tape);
                 strcpy(data[upIdx].nama_tdz, GETCURRENTWORD());
                 INC(tape);
                 strcpy(data[upIdx].halaqoh_tdz, GETCURRENTWORD());
                
             }
             printf("\nUPDATE DATA HAS SUCCESFULLY..........\n"); //tanda data berhasil diuopdate
             write(tape);
             printf("\n%d row in set TAHFIDZ.\n", dIdx);
         }else {
             printf("\nERROR UPDATE DATA HAS UNSUCCESFULLY..........\n"); //jika data tidak ditemukan di tabel
             printf("SYNTAX ERROR [ TABLE HAS NOT FOUND ]\n");
         }
}

//prosedur menghapus data yang sudah ada
void deleteData(char tape[]){
    int i;
    START(tape);
    if(cekQuery(tape) == 1){    //jika cekquery bernilai 1
        START(tape);    //increment kata dilakukan satu kali
        INC(tape);
    }else if((cekQuery(tape) == 3) || (cekQuery(tape) == 4) || (cekQuery(tape) == 5)){  //jika cekquery bernilai 3/4/5
        INC(tape); //incremet kata dilakukan satu kali tanpa memulai start kata
    }else if(cekQuery(tape) == 2){ //jika cekquery bernilai 2
        START(tape); //increment kata dilakukan dua kali dengan memulai start kata
        INC(tape);
        INC(tape);
    }
    if(strcmp(GETCURRENTWORD(), "tTahsin")==0){ //jika diminta tabel tahsin
             INC(tape);
             if(strcmp(GETCURRENTWORD(), data[upIdx].id_ths)==0){ //jika data ditemukan
                 for(i=upIdx; i<dIdx; i++){ //menaikkan data yang lama kedalam indeks data yang sudah dihapus
                     strcpy(data[i].id_ths, data[i+1].id_ths);
                    strcpy(data[i].nama_ths, data[i+1].nama_ths);
                    strcpy(data[i].halaqoh_ths, data[i+1].halaqoh_ths);
                 }
                dIdx--;
                printf("\nDELETE DATA HAS SUCCESFULLY..........\n"); //tanda data berhasil di hapus
                write(tape);
                printf("\n%d row in set TAHSIN.\n", dIdx);
             }else {
             printf("\nERROR UPDATE DATA HAS UNSUCCESFULLY..........\n"); //jika data tidak ditemukan
             printf("SYNTAX ERROR [ DATA HAS NOT FOUND ]\n");
             }
         }else if(strcmp(GETCURRENTWORD(), "tTahfidz")==0){ //jika dimminta tabel tahfidz
             INC(tape);
             if(strcmp(GETCURRENTWORD(), data[upIdx].id_tdz)==0){ //jika data ditemukan
                for(i=upIdx; i<dIdx; i++){
                     strcpy(data[i].id_tdz, data[i+1].id_tdz); //menauikkan data yang lama kedalam indeks data yang sudah dihapus
                    strcpy(data[i].nama_tdz, data[i+1].nama_tdz); 
                    strcpy(data[i].halaqoh_tdz, data[i+1].halaqoh_tdz);
                 }
                dIdx--;
             printf("\nDELETE DATA HAS SUCCESFULLY..........\n"); //tanda data berhasil dihapus
             write(tape);
             printf("\n%d row in set TAHFIDZ.\n", dIdx);
            }else {
                printf("\nERROR UPDATE DATA HAS UNSUCCESFULLY..........\n"); //jika data tidak ditemukan
                printf("SYNTAX ERROR [ DATA HAS NOT FOUND ]\n");
            }
         }else {
        printf("\nERROR INSERT DATA HAS UNSUCCESFULLY..........\n"); //jika tabel di cari tidak ada
        printf("SYNTAX ERROR  [ TABLE NOT FOUND ]\n");
    }
}

//prosedur menampilkan header pada tabel
void header(char tape[]){
    int i,j;
	//deklarasi variabel spasi maksimal
	int lim1=0,lim2=0,lim3=0;
	int len1[dIdx];
	int len2[dIdx];
	int len3[dIdx];

    START(tape);
    INC(tape);
    if(strcmp(GETCURRENTWORD(), "tTahsin")==0){ //jika diminta tabel tahsin
        
        for (i = 0; i < dIdx; i++){
		    len1[i] = strlen(data[i].id_ths);
		    if(len1[i] > lim1){ // spasi kolom nama id tahsin
			    lim1 = len1[i];
		    }
		    len2[i] = strlen(data[i].nama_ths);
		    if(len2[i] > lim2){ //spasi kolom nama tabel tahsin
			    lim2 = len2[i];
		    }
		    len3[i] = strlen(data[i].halaqoh_ths);
		    if(len3[i] > lim3){ //spasi kolom halaqoh nama halaqoh
			    lim3 = len3[i];
		    }
        }
        for (i=0; i<(((lim1+lim2+lim3)*2)/2)-1; i++){
            printf(" ");
        }
        printf("TABEL TAHSIN");
        printf("\n\n");
         if((lim1+lim2+lim3) % 2 == 0){
            for(i=0; i<(((lim1+lim2+lim3)*2)+4); i++){
		        printf("=");
	        }
        }else if((lim1+lim2+lim3) % 2 != 0){
            for(i=0; i<(((lim1+lim2+lim3)*2)+6); i++){
		        printf("=");
	        }
        }
	    printf("\n");
        printf("||");
        for(i=0; i<(lim1+0)/2; i++){
		    printf(" ");
	    }
        printf("ID SANTRI");
        for(i=0; i<(lim1+0)/2; i++){
		    printf(" ");
	    }
        printf("||");
        if(lim2 % 2 == 0){
            for(i=0; i<(lim2+0)/2; i++){
		        printf(" ");
	         }
        }else if(lim2 % 2 !=0){
            for(i=0; i<(lim2+0)/2; i++){
		        printf(" ");
	         }
        }
        printf("NAMA SANTRI");
        if(lim2 % 2 == 0){
            for(i=0; i<(lim2+0)/2; i++){
		        printf(" ");
	         }
        }else if(lim2 % 2 !=0){
            for(i=0; i<(lim2+0)/2; i++){
		        printf(" ");
	         }
        }
        printf("||");
        if(lim3 % 2 == 0){
            for(i=0; i<((lim3-1)/2); i++){
		         printf(" ");
	        }
        }else if(lim3 % 2 != 0){
            for(i=0; i<((lim3-3)/2); i++){
		         printf(" ");
	     }
        }
        
        printf("HALAQOH");
        if(lim3 % 2 == 0){
            for(i=0; i<((lim3-3)/2); i++){
		        printf(" ");
	        }
        }else if(lim3 % 2 != 0){
            for(i=0; i<((lim3-4)/2); i++){
		        printf(" ");
	        }
        }
        
        printf("||");
        printf("\n");
         if((lim1+lim2+lim3) % 2 == 0){
            for(i=0; i<(((lim1+lim2+lim3)*2)+4); i++){
		        printf("=");
	        }
        }else if((lim1+lim2+lim3) % 2 != 0){
            for(i=0; i<(((lim1+lim2+lim3)*2)+6); i++){
		        printf("=");
	        }
        }
        printf("\n");
        
    }else if(strcmp(GETCURRENTWORD(), "tTahfidz")==0){ //jika diminta tabel tahfidz
        
        for (i = 0; i < dIdx; i++){
		    len1[i] = strlen(data[i].id_tdz);
		    if(len1[i] > lim1){ // spasi kolom nama id tahsin
			    lim1 = len1[i];
		    }
		    len2[i] = strlen(data[i].nama_tdz);
		    if(len2[i] > lim2){ //spasi kolom nama tabel tahsin
			    lim2 = len2[i];
		    }
		    len3[i] = strlen(data[i].halaqoh_tdz);
		    if(len3[i] > lim3){ //spasi kolom halaqoh nama halaqoh
			    lim3 = len3[i];
		    }
        }
        printf("\n");
        for (i=0; i<(((lim1+lim2+lim3)*2)/2)-6; i++){
            printf(" ");
        }
        printf("TABEL TAHFIDZ");
        printf("\n\n");
        if((lim1+lim2+lim3) % 2 == 0){
            for(i=0; i<(((lim1+lim2+lim3)*2)+1); i++){
		        printf("=");
	        }
        }else if((lim1+lim2+lim3) % 2 != 0){
            for(i=0; i<(((lim1+lim2+lim3)*2)+1); i++){
		        printf("=");
	        }
        }
	    printf("\n");
        printf("||");
        for(i=0; i<(lim1+0)/2; i++){
		    printf(" ");
	    }
        printf("ID SANTRI");
        for(i=0; i<(lim1+0)/2; i++){
		    printf(" ");
	    }
        printf("||");
        if(lim2 % 2 == 0){
            for(i=0; i<(lim2-1)/2; i++){
		         printf(" ");
	        }
        }else if(lim2 % 2 != 0){
            for(i=0; i<(lim2+0)/2; i++){
		         printf(" ");
	        }
        }
        printf("NAMA SANTRI");
        if(lim2 % 2 == 0){
            for(i=0; i<(lim2-1)/2; i++){
		         printf(" ");
	        }
        }else if(lim2 % 2 != 0){
            for(i=0; i<(lim2+0)/2; i++){
		         printf(" ");
	        }
        }
        
        printf("||");
        if(lim3 % 2 == 0){
            for(i=0; i<(lim3-1)/2; i++){
		        printf(" ");
            }
	    }else if(lim3 % 2 != 0){
            for(i=0; i<(lim3+0)/2; i++){
		        printf(" ");
	        }
        }
        printf("HALAQOH");
        if(lim3 % 2 == 0){
            for(i=0; i<(lim3-1)/2; i++){
		        printf(" ");
            }
	    }else if(lim3 % 2 != 0){
            for(i=0; i<(lim3+0)/2; i++){
		        printf(" ");
	        }
        }

        printf("||");
        printf("\n");
        if((lim1+lim2+lim3) % 2 == 0){
            for(i=0; i<(((lim1+lim2+lim3)*2)+1); i++){
		        printf("=");
	        }
        }else if((lim1+lim2+lim3) % 2 != 0){
            for(i=0; i<(((lim1+lim2+lim3)*2)+1); i++){
		        printf("=");
	        }
        }
        
        printf("\n");
        
    }
}

//prosedur menampilkan isi tabel
void body(char tape[]){
    int i,j;
	//deklarasi variabel spasi maksimal
	int lim1=0,lim2=0,lim3=0;
	int len1[dIdx];
	int len2[dIdx];
	int len3[dIdx];

    START(tape);
    INC(tape);
    if(strcmp(GETCURRENTWORD(), "tTahsin")==0){ //jika diminta tabel tahsin
        for (i = 0; i < dIdx; i++){
		    len1[i] = strlen(data[i].id_ths);
		    if(len1[i] > lim1){ // spasi kolom nama id tahsin
			    lim1 = len1[i];
		    }
		    len2[i] = strlen(data[i].nama_ths);
		    if(len2[i] > lim2){ //spasi kolom nama tabel tahsin
			    lim2 = len2[i];
		    }
		    len3[i] = strlen(data[i].halaqoh_ths);
		    if(len3[i] > lim3){ //spasi kolom halaqoh nama halaqoh
			    lim3 = len3[i];
		    }
        }
        for (i = 0; i < dIdx; i++){
             printf("|| %s", data[i].id_ths);
             for(j=0; j < (lim1-len1[i])+7; j++){
                 printf(" ");
             }
             printf("|| %s", data[i].nama_ths);
             if(lim2 % 2 == 0){
                 for(j=0; j < (lim2-len2[i])+10; j++){
                    printf(" ");
                }
             }else if(lim2 % 2 != 0){
                 for(j=0; j < (lim2-len2[i])+9; j++){
                    printf(" ");
                }
             }
             
             printf("|| %s", data[i].halaqoh_ths);
             if(lim3 % 2 ==0){
                for(j=0; j < (lim3-len3[i])+3; j++){
                    printf(" ");
                }
             }else if(lim3 % 2 != 0){
                 for(j=0; j < (lim3-len3[i])+2; j++){
                    printf(" ");
                }
             }
             
             printf("||\n");
        }

    }else if(strcmp(GETCURRENTWORD(), "tTahfidz")==0){ //jika diminta tabel tahfidz
        read(tape);
        for (i = 0; i < dIdx; i++){
		    len1[i] = strlen(data[i].id_tdz);
		    if(len1[i] > lim1){ // spasi kolom nama id tahsin
			    lim1 = len1[i];
		    }
		    len2[i] = strlen(data[i].nama_tdz);
		    if(len2[i] > lim2){ //spasi kolom nama tabel tahsin
			    lim2 = len2[i];
		    }
		    len3[i] = strlen(data[i].halaqoh_tdz);
		    if(len3[i] > lim3){ //spasi kolom halaqoh nama halaqoh
			    lim3 = len3[i];
		    }
        }
        for (i = 0; i < dIdx; i++){
             printf("|| %s", data[i].id_tdz);
             for(j=0; j < (lim1-len1[i])+7; j++){
                 printf(" ");
             }
             printf("|| %s", data[i].nama_tdz);
             if(lim2 % 2 == 0){
                 for(j=0; j < ((lim2-len2[i])+8); j++){
                    printf(" ");
                }
             }else if(lim2 % 2 != 0){
                 for(j=0; j < ((lim2-len2[i])+9); j++){
                    printf(" ");
                }
             }
             
             printf("|| %s", data[i].halaqoh_tdz);
             if(lim3 % 2 == 0){
                 for(j=0; j < ((lim3-len3[i])+4); j++){
                    printf(" ");
                }
             }else if(lim3 % 2 != 0){
                 for(j=0; j < ((lim3-len3[i])+5); j++){
                    printf(" ");
                }
             }
             printf("||\n");
        }

    }
}

//prosedur menampilkan penutup tabel
void close(char tape[]){
    int i,j;
	//deklarasi variabel spasi maksimal
	int lim1=0,lim2=0,lim3=0;
	int len1[dIdx];
	int len2[dIdx];
	int len3[dIdx];

    START(tape);
    INC(tape);
    if(strcmp(GETCURRENTWORD(), "tTahsin")==0){ //jika diminta tabel tahsin
        
        for (i = 0; i < dIdx; i++){
		    len1[i] = strlen(data[i].id_ths);
		    if(len1[i] > lim1){ // spasi kolom nama id tahsin
			    lim1 = len1[i];
		    }
		    len2[i] = strlen(data[i].nama_ths);
		    if(len2[i] > lim2){ //spasi kolom nama tabel tahsin
			    lim2 = len2[i];
		    }
		    len3[i] = strlen(data[i].halaqoh_ths);
		    if(len3[i] > lim3){ //spasi kolom halaqoh nama halaqoh
			    lim3 = len3[i];
		    }
        }
        if((lim1+lim2+lim3) % 2 == 0){
            for(i=0; i<(((lim1+lim2+lim3)*2)+4); i++){
		        printf("=");
	        }
        }else if((lim1+lim2+lim3) % 2 != 0){
            for(i=0; i<(((lim1+lim2+lim3)*2)+6); i++){
		        printf("=");
	        }
        }
        printf("\n");
        printf("\n %d row in set TAHSIN.\n", dIdx);
    }else if(strcmp(GETCURRENTWORD(), "tTahfidz")==0){ //jika diminta tabel tahfidz
        for (i = 0; i < dIdx; i++){
		    len1[i] = strlen(data[i].id_tdz);
		    if(len1[i] > lim1){ // spasi kolom nama id tahsin
			    lim1 = len1[i];
		    }
		    len2[i] = strlen(data[i].nama_tdz);
		    if(len2[i] > lim2){ //spasi kolom nama tabel tahsin
			    lim2 = len2[i];
		    }
		    len3[i] = strlen(data[i].halaqoh_tdz);
		    if(len3[i] > lim3){ //spasi kolom halaqoh nama halaqoh
			    lim3 = len3[i];
		    }
        }
        if((lim1+lim2+lim3) % 2 == 0){
            for(i=0; i<(((lim1+lim2+lim3)*2)+1); i++){
		        printf("=");
	        }
        }else if((lim1+lim2+lim3) % 2 != 0){
            for(i=0; i<(((lim1+lim2+lim3)*2)+1); i++){
		        printf("=");
	        }
        }
        printf("\n");
        printf("\n %d row in set TAHFIDZ.\n", dIdx);
    }

}

void select(char tape[]){

    START(tape);
    INC(tape);
    if(strcmp(GETCURRENTWORD(), "tTahsin")==0){
        header(tape);
        body(tape);
        close(tape);
    }else if(strcmp(GETCURRENTWORD(), "tTahfidz")==0){
        header(tape);
        body(tape);
        close(tape);
    }
}