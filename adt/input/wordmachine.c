#include "wordmachine.h"

#include <stdio.h>

boolean endWord;
Word currentWord;

void IgnoreBlanks() {
  /* Mengabaikan satu atau beberapa BLANK
  I.S. : currentChar sembarang
  F.S. : currentChar ≠ BLANK atau currentChar = MARK */
  while (currentChar == BLANK) {
    ADV();
  }
}

void STARTWORD() {
  /* I.S. : currentChar sembarang
  F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */
  START();
  IgnoreBlanks();
  if (currentChar == MARK) {
    endWord = true;
  } else {
    endWord = false;
    CopyWord();
  }
}
void STARTWORDBLANK() {
  /* I.S. : currentChar sembarang
  F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */
  START();
  IgnoreBlanks();
  if (currentChar == MARK) {
    endWord = true;
  } else {
    endWord = false;
    CopyWordBlank();
  }
}

void STARTWORDnoIgnore(int maxChar) {
  /* I.S. : currentChar sembarang
     F.S. : EndWord = true, currentChar = MARK, dan currentWord adalah seluruh
     masukan;*/
  /*KAMUS LOKAL*/
  int ctr;

  /*ALGORITMA*/
  ctr = 0;
  START();
  if (currentChar == MARK) {
    endWord = true;
  } else {
    endWord = false;
    while (currentChar != MARK) {
      if (ctr < NMax) {
        currentWord.TabWord[ctr] = currentChar;
      }
      ADV();
      ctr++;
    }
    if (ctr < NMax)
      currentWord.Length = ctr;
    else
      currentWord.Length = maxChar;
  }
}

void ADVWORD() {
  /* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
  F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
  Proses : Akuisisi kata menggunakan procedure SalinWord */
  IgnoreBlanks();
  if (currentChar == MARK) {
    endWord = true;
  } else {
    endWord = false;
    CopyWord();
    IgnoreBlanks();
  }
}

void CopyWord() {
  /* Mengakuisisi kata, menyimpan dalam currentWord
     I.S. : currentChar adalah karakter pertama dari kata
     F.S. : currentWord berisi kata yang sudah diakuisisi;
            currentChar = BLANK atau currentChar = MARK;
            currentChar adalah karakter sesudah karakter terakhir yang
     diakuisisi. Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
  int i = 0;
  while (currentChar != MARK && currentChar != BLANK) {
    if (i < NMax) {
      currentWord.TabWord[i] = currentChar;
    }
    ADV();
    i++;
  }
  if (i < NMax) {
    currentWord.Length = i;
  } else {
    currentWord.Length = NMax;
  }
}

void CopyWordBlank() {
  /* Mengakuisisi kata, menyimpan dalam currentWord
     I.S. : currentChar adalah karakter pertama dari kata
     F.S. : currentWord berisi kata yang sudah diakuisisi;
            currentChar = BLANK atau currentChar = MARK;
            currentChar adalah karakter sesudah karakter terakhir yang
     diakuisisi. Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
  int i = 0;
  while (currentChar != MARK) {
    if (i < NMax) {
      currentWord.TabWord[i] = currentChar;
    }
    ADV();
    i++;
  }
  if (i < NMax) {
    currentWord.Length = i;
  } else {
    currentWord.Length = NMax;
  }
}

void LowerCase() {
  /* I.S. currentword terdefinisi sembarang tetapi tidak kosong */
  /* F.S. currentword menjadi lowercase di setiap karakternya */
  for (int i = 0; i < currentWord.Length; i++) {
    if (currentWord.TabWord[i] >= 65 && currentWord.TabWord[i] <= 90) {
      currentWord.TabWord[i] += 32;
    }
  }
}

boolean compareWordwString(Word w, char st[]) {
  /*membandingkan word dengan string, true jika sama dan false jika berbeda*/
  /*KAMUS LOKAL*/
  int i;
  /*ALGORITMA*/
  i = 0;
  while (w.TabWord[i] == st[i] && i < w.Length && st[i] != '\0') {
    i += 1;
  }
  return (i == w.Length && st[i] == '\0');
}

boolean compareWordwWord(Word w1, Word w2) {
  /*membandingkan word dengan string, true jika sama dan false jika berbeda*/
  /*KAMUS LOKAL*/
  int i;
  boolean sama;

  /*ALGORITMA*/
  if (w1.Length != w2.Length) {
    sama = false;
  } else {
    i = 0;
    sama = true;
    while (i < w1.Length && sama) {
      if (w1.TabWord[i] != w2.TabWord[i]) sama = false;
      i++;
    }
  }
  return (sama);
}

void printWord(Word w) {
  /*mencetak word ke layar tanpa karakter tambahan sebelum ataupun sesudah
   * word*/
  for (int i = 0; i < w.Length; i++) {
    printf("%c", w.TabWord[i]);
  }
}

int wordToInt(Word w) {
  /* mengubah word menjadi integer */
  /* KAMUS LOKAL */
  int i, hasil, sign;

  /* ALGORITMA */
  hasil = 0;
  sign = 1;  // Default sign is positive

  // Check if the first character is a minus sign
  if (w.Length > 0 && w.TabWord[0] == '-') {
    sign = -1;  // Set sign to negative
    i = 1;      // Start from the second character
  } else {
    i = 0;  // Start from the first character
  }

  for (; i < w.Length; i++) {
    hasil = hasil * 10 + (w.TabWord[i] - '0');
  }
  return sign * hasil;
}

Word stringToWord(char *st) {
  /*mengubah string menjadi word*/
  /*KAMUS LOKAL*/
  Word w;
  int i;

  /*ALGORITMA*/
  i = 0;
  w.Length = 0;
  while (st[i] != '\0') {
    w.TabWord[i] = st[i];
    w.Length += 1;
    i += 1;
  }
  return w;
}

void ConcatWords(Word *result, const Word *word1, const Word *word2) {
  int i, j;

  // Copy characters from word1 to result
  for (i = 0; i < word1->Length; i++) {
    result->TabWord[i] = word1->TabWord[i];
  }

  // Concatenate characters from word2 to result
  for (j = 0; j < word2->Length; j++) {
    if (i < NMax - 1) {
      result->TabWord[i] = word2->TabWord[j];
      i++;
    } else {
      break;
    }
  }

  result->TabWord[i] = '\0';
  result->Length = i;
}

void CopyWordwWord(Word *dest, Word *src) {
  int i;

  for (i = 0; i < src->Length; i++) {
    dest->TabWord[i] = src->TabWord[i];
  }

  dest->Length = src->Length;
}