/* File: wordmachine.h */
/* Definisi Word Machine: Model Akuisisi Versi I */

#ifndef __MESINKATA_H__
#define __MESINKATA_H__

#include "../boolean.h"
#include "charmachine.h"

#define NMax 280
#define BLANK ' '

typedef struct {
  char TabWord[NMax]; /* container penyimpan kata, indeks yang dipakai
                         [0..NMax-1] */
  int Length;
} Word;

/* State Mesin Word */
extern boolean endWord;
extern Word currentWord;

void IgnoreBlanks();
/* Mengabaikan satu atau beberapa BLANK
I.S. : currentChar sembarang
F.S. : currentChar ≠ BLANK atau currentChar = MARK */

void STARTWORD();
/* I.S. : currentChar sembarang
F.S. : EndWord = true, dan currentChar = MARK;
        atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
        currentChar karakter pertama sesudah karakter terakhir kata */

void STARTWORDnoIgnore(int maxChar);
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, currentChar = MARK, dan currentWord adalah seluruh
   masukan*/

void ADVWORD();
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
        currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
        Jika currentChar = MARK, EndWord = true.
Proses : Akuisisi kata menggunakan procedure SalinWord */

void CopyWord();
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
void LowerCase();

boolean compareWordwString(Word w, char w2[]);
/*membandingkan word dengan string, true jika sama dan false jika berbeda*/

boolean compareWordwWord(Word w1, Word w2);
/*membandingkan word dengan string, true jika sama dan false jika berbeda*/

void printWord(Word w);
/*mencetak word ke layar tanpa karakter tambahan sebelum ataupun sesudah word*/

int wordToInt(Word w);
/*mengubah word menjadi integer (untuk input integer)*/

Word stringToWord(char*);
/*mengubah string menjadi word*/

#endif