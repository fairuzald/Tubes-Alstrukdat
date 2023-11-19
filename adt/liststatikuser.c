#include "liststatikuser.h"
#include <stdio.h>

ListStatikUser userList;

/* ********** KONSTRUKTOR ********** */
void CreateuserList(){
/* I.S. userList sembarang */
/* F.S. Terbentuk userList kosong dengan kapasitas CAPACITY */
/* Proses: Inisialisasi semua elemen userList sesuai nilai bawaan */
    /*KAMUS LOKAL*/
    IdxType i,j,k;
    Word emptyWord;

    /*ALGORITMA*/
    /* Definisi Word kosong */
    emptyWord.TabWord[0]=BLANK;
    emptyWord.Length=0;

    for (i=IDX_MIN;i<CAPACITY;i++){
        NAMA(i)=emptyWord;
        PASS(i)=emptyWord;
        BIO(i)=emptyWord;
        HP(i)=0;
        WETON(i)=emptyWord;
        PUBLIC(i)=true;
        initPP(FOTO(i));
    }
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya user *** */
int userCount(){
/* Mengirimkan banyaknya user yang terdaftar */
/* Mengirimkan nol jika belum ada user */
    /*kamus*/
    IdxType i;
    int counter;

    /*algoritma*/
    i=IDX_MIN;
    counter=0;
    while (NAMA(i).Length!=0 && i<CAPACITY){
        printf("%d",NAMA(i).Length);
        counter+=1;
        i+=1;
    }
    return counter;
}

/* *** Selektor INDEKS *** */
IdxType getLastIdx(){
/* Prekondisi : userList tidak kosong */
/* Mengirimkan indeks elemen userList terakhir */
    return(userCount() - 1);
}

/* ********** Test Indeks yang valid ********** */
boolean isIdxEff(IdxType i){
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk userList */
    return(IDX_MIN<=i && i<userCount());
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean noUsers(){
/* Mengirimkan true jika userList kosong, mengirimkan false jika tidak */
    return(userCount()==0);
}
/* *** Test List penuh *** */
boolean userFull(){
/* Mengirimkan true jika userList l penuh, mengirimkan false jika tidak */
    return(userCount()==CAPACITY);
}

/* ********** SEARCHING ********** */
int userIndex(Word val){
/* Search apakah ada user bernama val */
/* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF */
    /*kamus*/
    int i;

    /*algoritma*/
    if (noUsers()){
        return IDX_UNDEF;
    }
    else {
        for (i=IDX_MIN;i<=getLastIdx();i++){
            if (compareWordwWord(NAMA(i),val)){
                return i;
            }
        }
        return IDX_UNDEF;
    }
}

/* ********** MENAMBAH ELEMEN ********** */
void addUser(Word N, Word P){
/* I.S. l terdefinisi dan tidak penuh, n dan p dipastikan valid*/
/* F.S. Ditambahkan 1 user dengan nama dan password terisi, sedangkan sisanya value bawaan*/
    /*KAMUS LOKAL*/
    int i;

    /*ALGORITMA*/
    i=userCount();
    NAMA(i)=N;
    PASS(i)=P;
}


