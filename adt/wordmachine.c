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
void STARTWORDnoIgnore(int maxChar){
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, currentChar = MARK, dan currentWord adalah seluruh masukan;*/
   /*KAMUS LOKAL*/
   int ctr;

   /*ALGORITMA*/
    ctr=0;
    START();
    while(currentChar!=MARK){
        if(ctr<maxChar){
            currentWord.TabWord[ctr]=currentChar;
            ctr+=1;
        }
        ADV();
    }
    currentWord.Length=ctr;
    EndWord=true;
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

boolean compareWordwString(Word w, char st[]){
/*membandingkan word dengan string, true jika sama dan false jika berbeda*/
    /*KAMUS LOKAL*/
    int i;
    /*ALGORITMA*/
    i=0;
    while (w.TabWord[i]==st[i] && i<w.Length && st[i]!='\0'){
    i+=1;
    }
    return (i==w.Length && st[i]=='\0');
}

boolean compareWordwWord(Word w1, Word w2){
  /*membandingkan word dengan string, true jika sama dan false jika berbeda*/
    /*KAMUS LOKAL*/
    int i;
    boolean sama;

    /*ALGORITMA*/
    if (w1.Length!=w2.Length) sama=false;
    else {
        i=0;
        sama=true;
        while (i<w1.Length && sama){
            if (w1.TabWord[i]!=w2.TabWord[i]) sama=false;
        }
    }
    return (sama);
}

void printWord(Word w){
 /*mencetak word ke layar tanpa karakter tambahan sebelum ataupun sesudah word*/
    for(int i=0;i<w.Length;i++){
        printf("%c",w.TabWord[i]);
    }
}

int wordToInt(Word w){
 /*mengubah word menjadi integer*/
    /*KAMUS LOKAL*/
    int i,hasil;

    /*ALGORITMA*/
    hasil=0;
    for(i=0;i<w.Length;i++){
        hasil=hasil*10+(w.TabWord[i]-'0');
    }
}

Word stringToWord(char* st){
/*mengubah string menjadi word*/
    /*KAMUS LOKAL*/
    Word w;
    int i;

    /*ALGORITMA*/
    i=0;
    w.Length=0;
    while (st[i]!='\0'){
        w.TabWord[i]=st[i];
        w.Length+=1;
        i+=1;
    }
    return w;
}