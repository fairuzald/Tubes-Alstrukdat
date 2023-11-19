#ifndef DRAFT_H
#define DRAFT_H

#include <time.h>

#include "../../adt/datetime.h"
#include "../../adt/input/wordmachine.h"

/* Definisi type Draft */
typedef struct {
  Word text;
  DATETIME timeCreated;
} Draft;

/* Selector Draft */
#define TextDraft(d) (d).text
#define TimeCreatedDraft(d) (d).timeCreated

/* Constructor Draft */
void CreateDraft(Draft *draft, Word text, DATETIME timeCreated);

/* Fungsi/prosedur Lain*/
void displayDraft(Draft draft);
void editDraft(Draft *draft, Word newText, DATETIME newTime);

#endif