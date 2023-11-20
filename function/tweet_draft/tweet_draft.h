#ifndef DRAFT_H
#define DRAFT_H

#include <time.h>

#include "../../adt/datetime.h"
#include "../../adt/input/wordmachine.h"

/* Definisi type Draft */

typedef struct {
  Word textDraft;
  DATETIME timeCreatedDraft;
} Draft;

/* Selector Draft */

#define TextDraft(d) (d).textDraft
#define TimeCreatedDraft(d) (d).timeCreatedDraft

/* Constructor Draft */

void CreateDraft(Draft *draft, Word textDraft, DATETIME timeCreatedDraft);
/* Membentuk draft baru dan memasukkan semua informasi ke dalam draft tersebut
 */

/* Fungsi/prosedur Lain*/

void displayDraft(Draft draft);
/* Menampilkan text dan timeCreated dari suatu draft */

void editDraft(Draft *draft, Word newTextDraft, DATETIME newTimeCreatedDraft);
/* Mengganti text dan timeCreated dari suatu draft */

#endif
