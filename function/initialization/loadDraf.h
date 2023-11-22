#ifndef LOADUSER_H
#define LOADUSER_H

#include <stdio.h>
#include <stdlib.h>

#include "../../adt/input/charmachinefile.h"
#include "../../adt/input/wordmachine.h"
#include "../../adt/input/wordmachinefile.h"
#include "../../adt/liststackdraft.h"
#include "../../adt/stackdraft.h"
#include "../../adt/time.h"
#include "../tweet_draft/tweet_draft.h"
// Function prototypes
// Fungsi untuk memisahkan waktu
void splitTime(Word time, int *inthh, int *intmm, int *intss);

// Fungsi untuk memisahkan tanggal
DATETIME splitDate(Word date, int hh, int mm, int ss);

// Fungsi untuk membaca waktu dan tanggal
void readDateTime(Word time, Word date, DATETIME *output);

// Fungsi untuk membaca konfigurasi draf
void readDrafConfig();

#endif /* LOA */
