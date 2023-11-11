#include <stdio.h>

#include "../../adt/input/wordmachine.h"

int main() {
  STARTWORD();  // Initialize the word processing

  while (!endWord) {
    // Process the current word
    printf("Current Word: %.*s\n", currentWord.Length, currentWord.TabWord);

    // Convert the word to lowercase
    LowerCase();
    printf("Lowercased Word: %.*s\n", currentWord.Length, currentWord.TabWord);

    // Advance to the next word
    ADVWORD();
  }

  return 0;
}
