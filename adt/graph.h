#include <stdio.h>

/* Ukuran maksimum baris dan kolom */
#define ROW_CAP 100
#define COL_CAP 100

typedef int IdxType; /* Index baris, kolom */
typedef int ElType;

typedef struct {
  ElType mem[ROW_CAP][COL_CAP];
  int rowEff; /* banyaknya/ukuran baris yg terdefinisi */
  int colEff; /* banyaknya/ukuran kolom yg terdefinisi */
} Matrix;

typedef struct {
  Matrix adjMatrix;
  int n;  // Jumlah simpul dalam graf
} Graph;

/* Selektor */
#define ROW_EFF(G) (G->adjMatrix).rowEff
#define COL_EFF(G) (G->adjMatrix).colEff
#define ELMT(G, i, j) (G->adjMatrix).mem[(i)][(j)]
#define JumlahSimpul(G) (G->n)

void CreateGraph(Graph* G, int n);

void insertEdge(Graph* G, int prec, int succ);

void deleteEdge(Graph* G, int prec, int succ);
