#include "globalFeature.h"
void globalFeature(Word *command) {
  if (compareWordwString(*command, "SIMPAN")) {
    simpan(command);
  }
}