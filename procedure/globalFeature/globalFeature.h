#ifndef __GLOBALFEATURE_H__
#define __GLOBALFEATURE_H__

#include "../../adt/input/wordmachine.h"
#include "../../function/initialization/initialization.h"
#include "../../function/save/save.h"

void globalFeature(Word* command, boolean sudahMasuk);

void loadFromFolder(char* folderName);
void muat(boolean sudahMasuk);
#endif
