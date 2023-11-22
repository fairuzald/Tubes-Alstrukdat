#ifndef LOADUTAS_H
#define LOADUTAS_H

#include <stdio.h>
#include <stdlib.h>

#include "../../adt/input/charmachinefile.h"
#include "../../adt/input/wordmachine.h"
#include "../../adt/input/wordmachinefile.h"
// Fungsi untuk membaca waktu dan tanggal
void readDateTime(Word time, Word date, DATETIME *output);
void ExtractWordAfterDash(const Word *inputWord, Word *outputWord);
// Fungsi untuk membaca konfigurasi draf
void readUtasConfig();

#endif /* LOA */
