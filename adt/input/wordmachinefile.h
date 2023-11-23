/* File: wordmachine.h */
/* Definisi Word Machine: Model Akuisisi Versi I */

#ifndef __MESINKATAFILE_H__
#define __MESINKATAFILE_H__

#include "../boolean.h"
#include "../datetime.h"
#include "charmachinefile.h"
#include "wordmachine.h"

/* State Mesin Word */
extern boolean endWordFile;
extern Word currentWordFile;

void IgnoreBlanksFile();
/* Mengabaikan satu atau beberapa BLANK
I.S. : currentChar sembarang
F.S. : currentChar ≠ BLANK atau currentChar = MARK */

void STARTWORDFILE(char path[]);
/* I.S. : currentChar sembarang
F.S. : EndWord = true, dan currentChar = MARK;
        atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
        currentChar karakter pertama sesudah karakter terakhir kata */
void CopyWordFileNoBlank();
void ADVWORDFILEnoBLANK();

void ADVWORDFILE();
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
        currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
        Jika currentChar = MARK, EndWord = true.
Proses : Akuisisi kata menggunakan procedure SalinWord */
void CropWord(Word *word, int maxLength);
void CropWordFront(Word *word, int croppedLength);
void CopyWordFile();
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
void STARTWORDFilenoIgnore(int maxChar);
void copyIntegerFromWordMachine(int *num, Word word);

void splitTime(Word time, int *inthh, int *intmm, int *intss);
// Fungsi untuk memisahkan tanggal
DATETIME splitDate(Word date, int hh, int mm, int ss);

#endif