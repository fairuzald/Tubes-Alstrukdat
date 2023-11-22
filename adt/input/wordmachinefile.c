#include "wordmachinefile.h"

#include <stdio.h>

boolean endWordFile;
Word currentWordFile;

void IgnoreBlanksFile() {
  /* Mengabaikan satu atau beberapa BLANK
  I.S. : currentChar sembarang
  F.S. : currentChar ≠ BLANK atau currentChar = MARKFILE */
  while (currentCharFile == BLANK) {
    ADVFILE();
  }
}

void STARTWORDFILE(char path[]) {
  /* I.S. : currentChar sembarang
  F.S. : EndWord = true, dan currentChar = MARKFILE;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */
  STARTFILE(path);
  IgnoreBlanksFile();
  if (currentCharFile == MARKFILE) {
    endWordFile = true;
  } else {
    endWordFile = false;
    CopyWordFile();
  }
}

void ADVWORDFILEnoBLANK() {
  IgnoreBlanksFile();
  if (currentCharFile == MARKFILE) {
    endWordFile = true;
    ADVFILE();
    CopyWordFileNoBlank();
  } else {
    endWordFile = false;
    CopyWordFileNoBlank();
    IgnoreBlanksFile();
  }
}

void ADVWORDFILE() {
  /* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
  F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin
  MARKFILE Jika currentChar = MARKFILE, EndWord = true. Proses : Akuisisi kata
  menggunakan procedure SalinWord */
  IgnoreBlanksFile();
  if (currentCharFile == MARKFILE) {
    endWordFile = true;
    ADVFILE();
    CopyWordFile();
  } else {
    endWordFile = false;
    CopyWordFile();
    IgnoreBlanksFile();
  }
}

void ADVTIME() {
  IgnoreBlanksFile();
  if (currentCharFile == '/') {
    endWordFile = true;
    ADVFILE();
    CopyWordFile();
  } else {
    endWordFile = false;
    CopyWordFile();
    IgnoreBlanksFile();
  }
}

void CopyWordFileNoBlank() {
  /* Mengakuisisi kata, menyimpan dalam currentWord
     I.S. : currentChar adalah karakter pertama dari kata
     F.S. : currentWord berisi kata yang sudah diakuisisi;
            currentChar = BLANK atau currentChar = MARKFILE;
            currentChar adalah karakter sesudah karakter terakhir yang
     diakuisisi. Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
  int i = 0;

  while (currentCharFile != MARKFILE && currentCharFile != BLANK) {
    if (i < NMax) {
      currentWordFile.TabWord[i] = currentCharFile;
    }
    ADVFILE();
    i++;
  }
  if (i < NMax) {
    currentWordFile.Length = i;
  } else {
    currentWordFile.Length = NMax;
  }
}
void CopyWordFile() {
  /* Mengakuisisi kata, menyimpan dalam currentWord
     I.S. : currentChar adalah karakter pertama dari kata
     F.S. : currentWord berisi kata yang sudah diakuisisi;
            currentChar = BLANK atau currentChar = MARKFILE;
            currentChar adalah karakter sesudah karakter terakhir yang
     diakuisisi. Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
  int i = 0;

  while (currentCharFile != MARKFILE) {
    if (i < NMax) {
      currentWordFile.TabWord[i] = currentCharFile;
    }
    ADVFILE();
    i++;
  }
  if (i < NMax) {
    currentWordFile.Length = i;
  } else {
    currentWordFile.Length = NMax;
  }
}

void STARTWORDFilenoIgnore(int maxChar) {
  /* I.S. : currentChar sembarang
     F.S. : EndWord = true, currentChar = MARK, dan currentWord adalah seluruh
     masukan;*/
  /*KAMUS LOKAL*/
  int ctr;

  /*ALGORITMA*/
  ctr = 0;
  START();
  while (currentCharFile != MARKFILE) {
    if (ctr < maxChar) {
      currentWordFile.TabWord[ctr] = currentCharFile;
      ctr += 1;
    }
    ADVFILE();
  }
  currentWordFile.Length = ctr;
  endWordFile = true;
}

void CropWord(Word *word, int maxLength) {
  /* Memotong panjang kata sesuai dengan maxLength
     I.S. : word terdefinisi, maxLength merupakan panjang maksimum yang
     diinginkan F.S. : Jika panjang kata lebih dari maxLength, maka kata
     dipotong menjadi maxLength; Jika panjang kata kurang dari atau sama dengan
     maxLength, tidak ada perubahan. */
  if (word->Length > maxLength) {
    word->Length = maxLength;
  }
}

void LowerCaseFile() {
  /* I.S. currentword terdefinisi sembarang tetapi tidak kosong */
  /* F.S. currentword menjadi lowercase di setiap karakternya */
  for (int i = 0; i < currentWordFile.Length; i++) {
    if (currentWordFile.TabWord[i] >= 65 && currentWordFile.TabWord[i] <= 90) {
      currentWordFile.TabWord[i] += 32;
    }
  }
}

void copyIntegerFromWordMachine(int *num, Word word) {
  *num = 0;
  for (int i = 0; i < word.Length; i++) {
    *num = (*num * 10) + (word.TabWord[i] - 48);
  }
}
