#ifndef __LOAD_H__
#define __LOAD_H__

#include <stdio.h>
#include <sys/stat.h>

#include "../../adt/input/wordmachine.h"
#include "../../function/initialization/initialization.h"
#include "../../function/input/input.h"

void loadFromFolder(char* folderName);
void muat(boolean sudahMasuk);
void logoutFeature(Word* command, boolean sudahMasuk);
#endif
