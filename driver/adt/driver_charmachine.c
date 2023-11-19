#include <stdio.h>

#include "../../adt/input/charmachine.h"

int main() {
  // Example usage of the character machine
  START();

  while (!EOP) {
    // Process currentChar or perform other actions
    printf("Current character: %c\n", currentChar);

    // Move to the next character
    ADV();
  }

  return 0;
}