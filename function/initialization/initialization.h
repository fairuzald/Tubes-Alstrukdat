#ifndef LOAD_USER_H
#define LOAD_USER_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

#include "../../adt/datetime.h"
#include "../../adt/input/charmachine.h"
#include "../../adt/input/charmachinefile.h"
#include "../../adt/input/wordmachine.h"
#include "../../adt/input/wordmachinefile.h"
#include "../../adt/listdintweet.h"
#include "../../adt/liststackdraft.h"
#include "../../adt/liststatikuser.h"
#include "../../adt/stackdraft.h"
#include "../input/input.h"
#include "../profile/profile.h"
#include "../user/user.h"

void concat(char *str1, char *str2, char *output);

// Folder config search
boolean searchConfigFolder(char path[1000]);

void initialization(Word *command);

void readDateTime(Word time, Word date, DATETIME *output);
void concat(char *str1, char *str2, char *output);
void ExtractWordAfterDash(const Word *inputWord, Word *outputWord);
void readUtasConfig(char filePath[]);
void readUserConfig(char filePath[]);
void readDrafConfig(char filePath[]);
void readKicauanConfig(char filePath[]);
void readBalasanConfig(char filePath[]);
void readMatrix(PhotoMat *m, int nRow, int nCol);
void readDateTime(Word time, Word date, DATETIME *output);
boolean searchConfigFolder(char path[1000]);
void loadSemuaConfig(Word *folderName);
void initialization(Word *command);

#endif  // LOAD_USER_H
