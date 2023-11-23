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

void CropWordFront(Word *word, int croppedLength) {
  /* Memotong panjang kata sesuai dengan maxLength
     I.S. : word terdefinisi, maxLength merupakan panjang maksimum yang
     diinginkan F.S. : Jika panjang kata lebih dari maxLength, maka kata
     dipotong menjadi maxLength; Jika panjang kata kurang dari atau sama dengan
     maxLength, tidak ada perubahan. */

  if (word->Length > croppedLength) {
    int startIdx = word->Length - croppedLength;
    int i, j;

    // Geser karakter ke depan untuk memotong dari belakang
    for (i = 0, j = startIdx; j < word->Length; ++i, ++j) {
      word->TabWord[i] = word->TabWord[j];
    }

    word->Length -= croppedLength;
    word->TabWord[word->Length] =
        '\0';  // Pastikan string berakhir dengan null terminator
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

void splitTime(Word time, int *inthh, int *intmm, int *intss) {
  // Mencari posisi karakter ":" dalam string waktu
  int colonPosHour = 0;
  while (time.TabWord[colonPosHour] != ':' && colonPosHour < time.Length) {
    colonPosHour++;
  }

  int colonPosMinute = colonPosHour + 1;
  while (time.TabWord[colonPosMinute] != ':' && colonPosMinute < time.Length) {
    colonPosMinute++;
  }

  // Memisahkan string waktu menjadi jam, menit, dan detik
  Word hh, mm, ss;
  for (int i = 0; i < colonPosHour; i++) {
    hh.TabWord[i] = time.TabWord[i];
  }
  hh.Length = colonPosHour;
  hh.TabWord[colonPosHour] = '\0';  // Menambahkan null terminator

  int j = 0;
  for (int i = colonPosHour + 1; i < colonPosMinute; i++) {
    mm.TabWord[j++] = time.TabWord[i];
  }
  mm.Length = j;
  mm.TabWord[j] = '\0';  // Menambahkan null terminator

  j = 0;
  for (int i = colonPosMinute + 1; i < time.Length; i++) {
    ss.TabWord[j++] = time.TabWord[i];
  }
  ss.Length = j;
  ss.TabWord[j] = '\0';  // Menambahkan null terminator
  *inthh = wordToInt(hh);
  *intmm = wordToInt(mm);
  *intss = wordToInt(ss);
}

// Fungsi untuk memisahkan tanggal
DATETIME splitDate(Word date, int hh, int mm, int ss) {
  // Mencari posisi karakter "/" dalam string tanggal
  int slashPosDay = 0;
  while (date.TabWord[slashPosDay] != '/' && slashPosDay < date.Length) {
    slashPosDay++;
  }

  int slashPosMonth = slashPosDay + 1;
  while (date.TabWord[slashPosMonth] != '/' && slashPosMonth < date.Length) {
    slashPosMonth++;
  }

  // Memisahkan string tanggal menjadi hari, bulan, dan tahun
  Word dd, month, yyyy;
  for (int i = 0; i < slashPosDay; i++) {
    dd.TabWord[i] = date.TabWord[i];
  }
  dd.Length = slashPosDay;
  dd.TabWord[slashPosDay] = '\0';  // Menambahkan null terminator

  int j = 0;
  for (int i = slashPosDay + 1; i < slashPosMonth; i++) {
    month.TabWord[j++] = date.TabWord[i];
  }
  month.Length = j;
  month.TabWord[j] = '\0';  // Menambahkan null terminator

  j = 0;
  for (int i = slashPosMonth + 1; i < date.Length; i++) {
    yyyy.TabWord[j++] = date.TabWord[i];
  }
  yyyy.Length = j;
  yyyy.TabWord[j] = '\0';  // Menambahkan null terminator

  int intdd = wordToInt(dd);
  int intmonth = wordToInt(month);
  int intyyyy = wordToInt(yyyy);

  DATETIME dt;
  CreateDATETIME(&dt, intdd, intmonth, intyyyy, hh, mm, ss);
  return dt;
}
