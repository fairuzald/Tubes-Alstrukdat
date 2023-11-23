#ifndef GRAF_H
#define GRAF_H

#include <stdio.h>

/* Ukuran maksimum baris dan kolom (n x n) */
#define MAX_CAP 20

typedef int IdxType; /* Index baris, kolom */
typedef int ElType;

typedef struct {
  ElType mem[MAX_CAP][MAX_CAP];
  int n;  // Jumlah simpul dalam graf
} Graph;

/* Selektor */
#define ELMT(G, i, j) (G).mem[(i)][(j)]
#define JumlahSimpul(G) (G).n

void CreateGraph(Graph* G, int n);

void insertEdge(Graph* G, int prec, int succ);

void deleteEdge(Graph* G, int prec, int succ);

#endif