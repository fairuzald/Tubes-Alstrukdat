#include "input.h"

void readInput(Word *command){
  /*membaca kata pertama dari input dan mereturn nama command yang akan dijalankan*/
  STARTWORD();
  *command=currentWord;
}

boolean compareWordwSt(Word w, char st[]){
  /*membandingkan word dengan string, true jika sama dan false jika berbeda*/
  /*KAMUS LOKAL*/
  int i;
  /*ALGORITMA*/
  i=0;
  while (w.TabWord[i]==st[i] && i<w.Length && st[i]!='\0'){
    i+=1;
  }
  return (i==w.Length && st[i]=='\0');
}
