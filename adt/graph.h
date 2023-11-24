#ifndef GRAF_H
#define GRAF_H

#include <stdio.h>

/* Ukuran maksimum baris dan kolom (n x n) */
#define CAP 20

typedef int IdxType; /* Index baris, kolom */
typedef int El;

typedef struct {
  El mem[CAP][CAP];
  int n;  // Jumlah simpul dalam graf
} Graph;

/* Selektor */
#define ELMT(G, i, j) (G).mem[(i)][(j)]
#define JumlahSimpul(G) (G).n

void CreateGraph(Graph* G, int n);

void insertEdge(Graph* G, int prec, int succ);

void deleteEdge(Graph* G, int prec, int succ);

#endif