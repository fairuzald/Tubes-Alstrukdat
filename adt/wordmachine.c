#include <stdio.h>
#include <stdlib.h>
#include "wordmachine.h"

/* State Mesin Word */
boolean EndWord;
Word currentWord;

void IgnoreBlanks(){
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */
    while (currentChar==BLANK){
        ADV();
    }
}

void IgnoreBlanksAndEnters(){
/* Mengabaikan satu atau beberapa NEWLINE
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ NEWLINE atau currentChar = MARK */
   while (currentChar==NEWLINE || currentChar==BLANK){
        ADV();
   }
}

void STARTWORD(){
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */
    START();
    IgnoreBlanksAndEnters();
    if (currentChar==MARK){
        EndWord=true;
    }
    else{
        EndWord=false;
        ADVWORD();
    }

}

void ADVWORD(){
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */
    IgnoreBlanksAndEnters();
    if (currentChar==MARK){
        EndWord=true;
    }
    else{
        CopyWord();
        IgnoreBlanksAndEnters();
    }
}

void CopyWord(){
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
    /*kamus lokal*/
    int ctr;
    /*algoritma*/
    ctr=0;
    while((currentChar!=MARK)&&(currentChar!=BLANK)&&(currentChar!=NEWLINE)){
        if(ctr<NMax){
            currentWord.TabWord[ctr]=currentChar;
            ctr+=1;
        }
        ADV();
    }
    currentWord.Length=ctr;
}
