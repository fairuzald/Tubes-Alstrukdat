#include "input.h"

// kebanyakan fungsinya dimasukkin langsung ke wordmachine(adt) biar gampang
// dipake

void readInput(Word *command) {
  /*membaca kata pertama dari input dan mereturn nama command yang akan
   * dijalankan*/
  STARTWORD();
  *command = currentWord;
}

void readInputNoIgnore(Word *command) {
  /*membaca kata pertama dari input dan mereturn nama command yang akan
   * dijalankan*/
  STARTWORDBLANK();
  *command = currentWord;
}