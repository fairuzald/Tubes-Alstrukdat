#include "listdintweet.h"

#include <stdio.h>
#include <stdlib.h>

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListDinTweet(ListDinTweet *l, long capacity) {
  /* I.S. l sembarang, capacity > 0 */
  /* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */
  BUFFER(*l) = (ElType *)malloc(capacity * sizeof(ElType));
  NEFF(*l) = 0;
  CAPACITY(*l) = capacity;
}

void dealocateList(ListDinTweet *l) {
  /* I.S. l terdefinisi; */
  /* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */
  free(BUFFER(*l));
  NEFF(*l) = 0;
  CAPACITY(*l) = 0;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listLength(ListDinTweet l) {
  /* Mengirimkan banyaknya elemen efektif list */
  /* Mengirimkan nol jika list l kosong */
  return NEFF(l);
}
/* *** Daya tampung container *** */

/* *** Selektor INDEKS *** */
IdxType getFirstIdx(ListDinTweet l) {
  /* Prekondisi : List l tidak kosong */
  /* Mengirimkan indeks elemen l pertama */
  return IDX_MIN;
}
IdxType getLastIdx(ListDinTweet l) {
  /* Prekondisi : List l tidak kosong */
  /* Mengirimkan indeks elemen l terakhir */
  return listLength(l) - 1;
}

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListDinTweet l, IdxType i) {
  /* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
  /* yaitu antara indeks yang terdefinisi utk container*/
  return IDX_MIN <= i && i <= CAPACITY(l) - 1;
}
boolean isIdxEff(ListDinTweet l, IdxType i) {
  /* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
  /* yaitu antara 0..NEFF(l) */
  return IDX_MIN <= i && i <= NEFF(l) - 1;
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmpty(ListDinTweet l) {
  /* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
  return listLength(l) == 0;
}
/* *** Test list penuh *** */
boolean isFull(ListDinTweet l) {
  /* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */
  return listLength(l) == CAPACITY(l);
}

/* ********** OPERASI LAIN ********** */
void copyList(ListDinTweet lIn, ListDinTweet *lOut) {
  /* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
  /* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
  /* Proses : Menyalin isi lIn ke lOut */
  CreateListDinTweet(lOut, CAPACITY(lIn));
  NEFF(*lOut) = NEFF(lIn);

  IdxType i;
  for (i = IDX_MIN; i <= listLength(lIn) - 1; i++) {
    ELMT(*lOut, i) = ELMT(lIn, i);
  }
}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLast(ListDinTweet *l, ElType val) {
  /* Proses: Menambahkan val sebagai elemen terakhir list */
  /* I.S. List l boleh kosong, tetapi tidak penuh */
  /* F.S. val adalah elemen terakhir l yang baru */
  ELMT(*l, listLength(*l)) = val;
  NEFF(*l)++;
}
/* ********** MENGHAPUS ELEMEN ********** */
void deleteLast(ListDinTweet *l, ElType *val) {
  /* Proses : Menghapus elemen terakhir list */
  /* I.S. List tidak kosong */
  /* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
  /*      Banyaknya elemen list berkurang satu */
  /*      List l mungkin menjadi kosong */
  *val = ELMT(*l, listLength(*l) - 1);
  NEFF(*l)--;
}

/* ********* MENGUBAH UKURAN ARRAY ********* */
void expandList(ListDinTweet *l, int num) {
  /* Proses : Menambahkan capacity l sebanyak num */
  /* I.S. List sudah terdefinisi */
  /* F.S. Ukuran list bertambah sebanyak num */
  BUFFER(*l) =
      (ElType *)realloc(BUFFER(*l), (CAPACITY(*l) + num) * sizeof(ElType));
  CAPACITY(*l) += num;
}

void shrinkList(ListDinTweet *l, int num) {
  /* Proses : Mengurangi capacity sebanyak num */
  /* I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity -
   * num. */
  /* F.S. Ukuran list berkurang sebanyak num. */
  BUFFER(*l) =
      (ElType *)realloc(BUFFER(*l), (CAPACITY(*l) - num) * sizeof(ElType));
  CAPACITY(*l) -= num;
}

void compressList(ListDinTweet *l) {
  /* Proses : Mengubah capacity sehingga capacity = nEff */
  /* I.S. List tidak kosong */
  /* F.S. Ukuran capacity = nEff */
  BUFFER(*l) = (ElType *)realloc(BUFFER(*l), NEFF(*l) * sizeof(ElType));
  CAPACITY(*l) = NEFF(*l);
}

/* FITUR-FITUR UTAMA*/

void newTweet(ListDinTweet *listTweet) {
  // Memasukkan text kicauan
  printf("Masukkan kicauan:\n");
  Word text;
  int i = 0;
  START();
  while (!EOP && i < NMax) {
    text.TabWord[i] = currentChar;
    i++;
    ADV();
  }
  text.Length = i;

  // Validasi masukan text kicauan
  if (isOnlySpace(text)) {
    // Jika masukan tidak valid, menampilkan pesan bahwa tweet gagal dibuat
    printf("Kicauan tidak boleh hanya berisi spasi!\n");
  } else {
    // (WIP) Author, timeCreated sementara
    Word author;
    author.TabWord[0] = 'x';  // author = "x"
    author.Length = 1;
    DATETIME timeCreated;
    CreateDATETIME(&timeCreated, 1, 1, 2000, 0, 0,
                   0);  // timeCreated = 01/01/2000 00:00:00

    long idTweet = NEFF(*listTweet) + 1;
    long idReply = 0;
    long idUtas = 0;
    long like = 0;
    long depth = 0;
    Tweet *reply1 = NULL;
    Tweet *reply2 = NULL;
    Tweet *utas = NULL;

    // Memasukkan semua informasi ke dalam Tweet
    Tweet newTweet;
    CreateTweet(&newTweet, text, author, timeCreated, idTweet, idReply, idUtas,
                like, depth, reply1, reply2, utas);

    // Memasukkan tweet ke dalam list Tweet
    if (isFull(*listTweet)) {
      expandList(listTweet, CAPACITY(*listTweet));
    }

    insertLast(listTweet, newTweet);

    // Menampilkan pesan bahwa tweet berhasil dibuat
    printf("Selamat! kicauan telah diterbitkan!\n");
    printf("Detil kicauan:\n");
    displayTweet(newTweet);
  }
}

void displayListTweet(ListDinTweet listTweet) {
  if (isEmpty(listTweet)) {
    printf("Daftar kicauan kosong !\n");
  } else {
    int i;
    for (i = 0; i < listLength(listTweet); i++) {
      displayTweet(ELMT(listTweet, i));
    }
  }
}

void like(ListDinTweet *listTweet, long id) {
  if (!isIdExist(*listTweet, id)) {
    printf("Tidak ditemukan kicauan dengan ID = %ld!\n", id);
  } else {
    // (WIP) Validasi akun private dan pertemanan
    likeTweet(&ELMT(*listTweet, id - 1));
    printf("Selamat! kicauan telah disukai!\n");
    printf("Detil kicauan:\n");
    displayTweet(ELMT(*listTweet, id - 1));
  }
}

void editTweetInList(ListDinTweet *listTweet, long id) {
  if (!isIdExist(*listTweet, id)) {
    printf("Tidak ditemukan kicauan dengan ID = %ld!\n", id);
  } else {
    // (WIP) Validasi pemilik akun

    // Memasukkan text kicauan
    printf("Masukkan kicauan baru:\n");
    Word newText;
    int i = 0;
    START();
    while (!EOP && i < NMax) {
      newText.TabWord[i] = currentChar;
      i++;
      ADV();
    }
    newText.Length = i;

    // Validasi masukan text kicauan
    if (isOnlySpace(newText)) {
      // Jika masukan tidak valid, menampilkan pesan bahwa tweet gagal di-edit
      printf("Kicauan tidak boleh hanya berisi spasi!\n");
    } else {
      TextTweet(ELMT(*listTweet, id - 1)) = newText;

      // Menampilkan pesan bahwa tweet berhasil dibuat
      printf("Selamat! kicauan telah diterbitkan!\n");
      printf("Detil kicauan:\n");
      displayTweet(ELMT(*listTweet, id - 1));
    }
  }
}

/* Fungsi/prosedur tambahan */

boolean isOnlySpace(Word text) {
  if (0 == text.Length) {
    return false;
  } else {
    int i = 0;
    while (i < text.Length - 1 && ' ' == text.TabWord[i]) {
      i++;
    }

    return ' ' == text.TabWord[i];
  }
}

boolean isIdExist(ListDinTweet listTweet, long id) {
  /* Mengirimkan true jika tweet dengan id "id" sudah terbentuk di dalam list
   * tweet */
  /* yaitu antara 1..NEFF(listTweet) */
  return 1 <= id && id <= NEFF(listTweet);
}
