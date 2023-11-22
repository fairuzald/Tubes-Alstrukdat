/* File: charmachine.c */
/* Implementasi Mesin Karakter */

#include "charmachinefile.h"

#include <stdio.h>

char currentCharFile;
boolean EOPFile;

static FILE *pita;
static int retval;

void STARTFILE(char path[]) {
  /* Algoritma */
  FILE *pita;
  if ((pita = fopen(path, "r")) != NULL) {
    // File ada dan dapat dibuka
    // Lanjutkan dengan operasi Anda di sini
    ADVFILE();
    fclose(pita);
  } else {
    // File tidak ada atau tidak dapat dibuka
    printf("File %s tidak ditemukan atau tidak dapat dibuka.\n", path);
  }
}

void ADVFILE() {
  /* Pita dimajukan satu karakter.
     I.S. : Karakter pada jendela =
            currentChar, currentChar != MARKFILE
     F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
            currentChar mungkin = MARKFILE.
                  Jika  currentChar = MARKFILE maka EOP akan menyala (true) */

  /* Algoritma */
  retval = fscanf(pita, "%c", &currentCharFile);
}
