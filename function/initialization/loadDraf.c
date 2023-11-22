#include "loadDraf.h"

// Fungsi untuk memisahkan waktu
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

void readDateTime(Word time, Word date, DATETIME *output) {
  int hh, mm, ss;
  splitTime(time, &hh, &mm, &ss);
  *output = splitDate(date, hh, mm, ss);
}

void readDrafConfig() {
  STARTWORDFILE("draf.config");
  CreateListStackDraft(&listStackDraftMain);

  int countUser;

  countUser = wordToInt(currentWordFile);
  ADVWORDFILE();
  Word nama, draf, date, time, clock;
  DATETIME dt;
  int countDraf;
  for (int i = 0; i < countUser; i++) {
    StackDraft stackDraft;
    countDraf = currentWordFile.TabWord[currentWordFile.Length - 1] - '0';
    CropWord(&currentWordFile, currentWordFile.Length - 2);
    CopyWordwWord(&nama, &currentWordFile);
    CropWord(&nama, 20);
    ADVWORDFILE();
    CreateEmptyStackDraft(&stackDraft, 20, nama);
    for (int j = 0; j < countDraf; j++) {
      Draft draft;
      CopyWordwWord(&draf, &currentWordFile);
      ADVWORDFILEnoBLANK();
      CopyWordwWord(&date, &currentWordFile);
      ADVWORDFILEnoBLANK();
      CopyWordwWord(&time, &currentWordFile);
      readDateTime(time, date, &dt);
      ADVWORDFILE();
      CreateDraft(&draft, draf, dt);
      Push(&stackDraft, draft);
    }
    insertLastListStackDraft(&listStackDraftMain, stackDraft);
  }
}