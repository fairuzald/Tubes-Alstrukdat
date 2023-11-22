#ifndef LOADUSER_H
#define LOADUSER_H

#include <stdio.h>
#include <stdlib.h>

#include "../../adt/input/charmachinefile.h"
#include "../../adt/input/wordmachine.h"
#include "../../adt/input/wordmachinefile.h"
#include "../../adt/listdintweet.h"
#include "../../adt/time.h"
#include "../tweet/tweet.h"
// Function prototypes
// Fungsi untuk memisahkan waktu
void readDrafConfig();
void readDateTime(Word time, Word date, DATETIME *output);

#endif /* LOA */
