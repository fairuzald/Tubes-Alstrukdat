#include "globalFeature.h"
void loginFeatureSave(Word *command) {
  if (compareWordwString(*command, "SIMPAN")) {
    ADV();
    simpan();
  }
}