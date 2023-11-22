#include "charmachine.h"

#include <stdio.h>

char currentChar;
boolean EOP;

static FILE *pita;
static int retval;

void START() {
  /* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
     Karakter pertama yang ada pada pita posisinya adalah pada jendela.
     I.S. : sembarang
     F.S. : currentChar adalah karakter pertama pada pita. Jika currentChar !=
     MARK maka EOP akan padam (false). Jika currentChar = MARK maka EOP akan
     menyala (true) */

  /* Algoritma */
  pita = stdin;
  if (currentChar == MARK)
    ADV(); /*untuk pemanggilan kedua dan selanjutnya, agar mark dari input
              sebelumnya terskip*/
  ADV(); /*untuk pemanggilan kedua, mengeskip '\n' dari input sebelumnya juga*/
}

void ADV() {
  /* Pita dimajukan satu karakter.
     I.S. : Karakter pada jendela =
            currentChar, currentChar != MARK
     F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
            currentChar mungkin = MARK.
                  Jika  currentChar = MARK maka EOP akan menyala (true) */

  /* Algoritma */
  retval = fscanf(pita, "%c", &currentChar);
  if (currentChar == MARK)
    EOP = true;
  else
    EOP = false;
}