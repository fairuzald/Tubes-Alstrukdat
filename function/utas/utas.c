#include "utas.h"

#include <stdio.h>
#include <stdlib.h>

void CreateUtas(ListDinTweet *listTweetMain, int idKicau, Word textTweet,
                Word authorTweet, DATETIME timeCreatedTweet) {
  AddressTweet temp = CreateTweet(textTweet, authorTweet, timeCreatedTweet, 0,
                                  0, 0, 0, 0, NULL, NULL, NULL, false);

  // memasukkan node ke utas
  insertUtas(&ELMT_LISTDINTWEET(*listTweetMain, idKicau - 1), temp,
             lengthUtas(ELMT_LISTDINTWEET(*listTweetMain, idKicau - 1)));
}

void initUtas(ListDinTweet *listTweetMain, int idKicau, User currentUser) {
  // cari apakah ada id di list tweet
  // tweet tersebut milik current user atau tidak
  // apakah sudah dijadikan utas atau belum
  if (idKicau > listTweetLength(*listTweetMain) || idKicau <= 0) {
    printf("\nKicauan tidak ditemukan\n");
  } else if (compareWordwWord(
                 AuthorTweet(ELMT_LISTDINTWEET(*listTweetMain, idKicau - 1)),
                 currentUser.nama)) {
    // id ada, tetapi utas bukan milik current user
    printf("\nUtas ini bukan milik anda!\n");
  } else if (KicauanUtama(ELMT_LISTDINTWEET(*listTweetMain, idKicau - 1))) {
    // sudah menjadi kicauan utama pada sebuah utas
    printf("\nKicauan ini sudah memiliki utas\n");
  } else {
    // syarat membuat utas terpenuhi
    boolean lanjutUtas = true;
    printf("\nUtas berhasil dibuat!\n");
    // ubah id utas
    IdUtas(ELMT_LISTDINTWEET(*listTweetMain, idKicau - 1)) =
        maxIDUtas(listTweetMain) + 1;
    do {
      // mengambil input kicauan
      printf("\nMasukkan kicauan:\n");
      STARTWORDnoIgnore(280);

      CreateUtas(listTweetMain, idKicau, currentWord, currentUser.nama,
                 getCurrentDateTime());
      // // membuat node tweet baru
      // AddressTweet temp = CreateTweet(currentWord, currentUser.nama,
      // getCurrentDateTime(), 0, 0, 0, 0, 0, NULL, NULL, NULL, false);

      // // memasukkan node ke utas
      // insertUtas(&ELMT_LISTDINTWEET(*listTweetMain, idKicau-1), temp,
      // lengthUtas(ELMT_LISTDINTWEET(*listTweetMain, idKicau - 1)));

      do {
        printf("\nApakah Anda ingin melanjutkan utas ini? (YA/TIDAK)  ");
        STARTWORD();
      } while (!(compareWordwString(currentWord, "TIDAK") ||
                 compareWordwString(currentWord, "YA")));  // handle input

      // lanjut atau tidak
      if (compareWordwString(currentWord, "TIDAK")) {
        // tidak lanjut
        lanjutUtas = false;
        printf("\nUtas selesai!\n");
      }
    } while (lanjutUtas);
  }
}

void connectUtas(ListDinTweet *listTweetMain, int idUtas, int index,
                 User currentUser) {
  if (idUtas > maxIDUtas(listTweetMain)) {
    // kasus idUtas tidak ada
    printf("\nUtas tidak ditemukan!\n");
  } else {
    // cari id utas
    int i = 0;
    while (idUtas != IdUtas(ELMT_LISTDINTWEET(*listTweetMain, i - 1)) &&
           i < listTweetLength(*listTweetMain)) {
      i++;
    }

    // tweet yang memiliki idUtas ketemu
    AddressTweet current = ELMT_LISTDINTWEET(*listTweetMain, i - 1);

    if (compareWordwWord(AuthorTweet(current), currentUser.nama)) {
      // utas bukan milik current user
      printf("\nAnda tidak bisa menyambung utas ini!\n");
    } else {
      // index terlalu tinggi
      if (index > lengthUtas(current)) {
        printf("\nIndex terlalu tinggi!\n");
      } else if (index = 0) {
        printf("\nAnda tidak bisa menyambung utas!\n");
      } else {
        // syarat terpenuhi
        // mengambil input kicauan
        printf("\nMasukkan kicauan:\n");
        STARTWORDnoIgnore(280);

        // membuat node tweet baru
        AddressTweet temp =
            CreateTweet(currentWord, currentUser.nama, getCurrentDateTime(), 0,
                        0, 0, 0, 0, NULL, NULL, NULL, false);

        // memasukkan node ke utas
        insertUtas(&current, temp, index);
      }
    }
  }
}

void deleteUtas(ListDinTweet *listTweetMain, int idUtas, int index,
                User currentUser) {
  if (idUtas > maxIDUtas(listTweetMain)) {
    // kasus idUtas tidak ada
    printf("\nUtas tidak ditemukan!\n");
  } else {
    // cari id utas
    int i = 0;
    while (idUtas != IdUtas(ELMT_LISTDINTWEET(*listTweetMain, i - 1)) &&
           i < listTweetLength(*listTweetMain)) {
      i++;
    }

    // tweet yang memiliki idUtas ketemu
    AddressTweet current = ELMT_LISTDINTWEET(*listTweetMain, i - 1);

    if (compareWordwWord(AuthorTweet(current), currentUser.nama)) {
      // utas bukan milik current user
      printf("\nAnda tidak bisa menghapus kicauan dalam utas ini!\n");
    } else {
      // index terlalu tinggi
      if (index > lengthUtas(current)) {
        printf(
            "\nKicauan sambungan dengan index %d tidak ditemukan pada utas!\n",
            index);
      } else if (index == 0) {
        printf("\nAnda tidak bisa menghapus kicauan utama!\n");
      } else {
        AddressTweet loc = Utas(current);
        if (index == 1) {
          Utas(current) = Utas(Utas(current));
          deallocateTweet(loc);
        } else {
          i = 1;

          AddressTweet loc = Utas(current);

          while (i < index - 1) {
            i++;
            loc = Utas(loc);
          }

          // ketemu sebelum index
          Utas(loc) = Utas(Utas(loc));
          AddressTweet p = Utas(loc);

          deallocateTweet(p);
        }
        printf("\nKicauan sambungan berhasil dihapus!\n");
      }
    }
  }
}

void displayUtas(ListDinTweet *listTweetMain, int idUtas, User currentUser,
                 Graph grafPertemanan) {
  if (idUtas > maxIDUtas(listTweetMain)) {
    // kasus idUtas tidak ada
    printf("\nUtas tidak ditemukan!\n");
  } else {
    // cari id utas
    int i = 0;
    while (idUtas != IdUtas(ELMT_LISTDINTWEET(*listTweetMain, i - 1)) &&
           i < listTweetLength(*listTweetMain)) {
      i++;
    }

    // tweet yang memiliki idUtas ketemu
    AddressTweet current = ELMT_LISTDINTWEET(*listTweetMain, i - 1);

    boolean priv = false;
    // penulisnya bukan dirinya sendiri
    if (compareWordwWord(AuthorTweet(current), currentUser.nama)) {
      // cari privat atau tidak
      int idAuthorTweet = userIndex(AuthorTweet(current));
      boolean priv =
          !PUBLIC(idAuthorTweet) &&
          !isTeman(grafPertemanan, AuthorTweet(current), currentUser.nama);
    }

    if (priv) {
      printf(
          "\nAkun yang membuat utas ini adalah akun privat! Ikuti dahulu akun "
          "ini untuk melihat utasnya!\n");
    } else {
      // display kicauan utama

      // display ID
      printf("| ID = %d\n", IdTweet(current));

      // display author
      printf("| ");
      int i;
      for (i = 0; i < AuthorTweet(current).Length; i++) {
        printf("%c", AuthorTweet(current).TabWord[i]);
      }
      printf("\n");

      // display timeCreated
      printf("| ");
      TulisDATETIME(TimeCreatedTweet(current));
      printf("\n");

      // display text
      printf("| ");
      for (i = 0; i < TextTweet(current).Length; i++) {
        printf("%c", TextTweet(current).TabWord[i]);
      }
      printf("\n");

      // display utas
      int indexUtas = 1;
      while (Utas(current) != NULL) {
        printf("\n");

        // display index
        printf("    | INDEX = %d\n", indexUtas);
        indexUtas++;

        // display author
        printf("    | ");
        int i;
        for (i = 0; i < AuthorTweet(current).Length; i++) {
          printf("%c", AuthorTweet(current).TabWord[i]);
        }
        printf("\n");

        // display timeCreated
        printf("    | ");
        TulisDATETIME(TimeCreatedTweet(current));
        printf("\n");

        // display text
        printf("    | ");
        for (i = 0; i < TextTweet(current).Length; i++) {
          printf("%c", TextTweet(current).TabWord[i]);
        }
        printf("\n");

        current = Utas(current);
      }
    }
  }
}
