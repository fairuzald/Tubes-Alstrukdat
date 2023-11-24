#include "graph.h"

#include <stdio.h>

#include "boolean.h"

void CreateGraph(Graph* G, int n) {
  int i, j;

  JumlahSimpul(*G) = n;  // n : banyak pengguna (user)

  for (i = 0; i < JumlahSimpul(*G); i++) {
    for (j = 0; j < JumlahSimpul(*G); j++) {
      ELMT(*G, i, j) = 0;
    }
  }
}

void insertEdge(Graph* G, int prec, int succ) { ELMT(*G, prec, succ) = 1; }

void deleteEdge(Graph* G, int prec, int succ) { ELMT(*G, prec, succ) = 0; }
