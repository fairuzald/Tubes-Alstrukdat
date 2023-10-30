#include <stdio.h>
#include <stdlib.h>

#include "../pcolor/pcolor.h"

void throwError(char *message) {
  printf(RED);
  printf("Error: %s\n", message);
  printf(NORMAL);
  exit(1);
}