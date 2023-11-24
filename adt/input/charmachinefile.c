/* File: charmachine.c */
/* Implementasi Mesin Karakter */

#include "charmachinefile.h"

#include <stdio.h>

char currentCharFile;
boolean EOPFile;

static FILE *pita;
static int retval;

void STARTFILE(char path[]) {
  /* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
     Karakter pertama yang ada pada pita posisinya adalah pada jendela.
     I.S. : sembarang
     F.S. : currentChar adalah karakter pertama pada pita. Jika currentChar !=
     MARKFILE maka EOP akan padam (false). Jika currentChar = MARKFILE maka EOP
     akan menyala (true) */

  /* Algoritma */
  pita = fopen(path, "r");
  ADVFILE();
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