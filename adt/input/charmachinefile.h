/* File: charmachinefile.h */
/* Definisi Mesin Karakter */

#ifndef __MESIN_KARFILE_H_
#define __MESIN_KARFILE_H_

#include "..\boolean.h"

#define MARKFILE '\n'
/* State Mesin */
extern char currentCharFile;
extern boolean EOPFile;

void STARTFILE(char path[]);
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita
          Jika currentChar != MARKFILE maka EOP akan padam (false)
          Jika currentChar = MARKFILE maka EOP akan menyala (true) */

void ADVFILE();
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = currentChar, currentChar != MARKFILE
   F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
          currentChar mungkin = MARKFILE
          Jika  currentChar = MARKFILE maka EOP akan menyala (true) */

#endif