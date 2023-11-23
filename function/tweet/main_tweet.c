#include "main_tweet.h"

#include <stdio.h>

/* State Global ListDinTweet */
ListDinTweet listTweetMain;

/* Fitur-Fitur Utama */

void inputNewTweet(ListDinTweet *listTweet, User user) {
  /* Bagian dari fitur utama kicauan */
  /* Membuat tweet baru berdasarkan masukan dari pengguna dan memasukannya ke
   * dalam list */

  // Memasukkan text kicauan

  printf("Masukkan kicauan:\n");
  // Word text;
  // int i = 0;
  // START();
  // while (!EOP && i < NMax) {
  //   text.TabWord[i] = currentChar;
  //   i++;
  //   ADV();
  // }

  // text.Length = i;

  STARTWORDnoIgnore(MAX_TWEET_LENGTH);

  // Validasi masukan text kicauan
  if (isOnlySpace(currentWord)) {
    // Jika masukan tidak valid, menampilkan pesan bahwa tweet gagal dibuat
    printf("Kicauan tidak boleh hanya berisi spasi!\n");
  } else {
    Word author = user.nama;
    DATETIME timeCreated = getCurrentDateTime();
    long idTweet = NEFF_LISTDINTWEET(*listTweet) + 1;
    long idReply = 0;
    long idUtas = 0;
    long like = 0;
    long depth = 0;
    AddressTweet reply1 = NULL;
    AddressTweet reply2 = NULL;
    AddressTweet utas = NULL;
    boolean kicauanUtama = false;

    // Memasukkan semua informasi ke dalam Tweet
    AddressTweet pNewTweet =
        CreateTweet(currentWord, author, timeCreated, idTweet, idReply, idUtas,
                    like, depth, reply1, reply2, utas, kicauanUtama);

    // Memasukkan tweet ke dalam list Tweet
    if (isFullListTweet(*listTweet)) {
      expandListTweet(listTweet, CAPACITY_LISTDINTWEET(*listTweet));
    }

    insertLastListTweet(listTweet, pNewTweet);

    // Menampilkan pesan bahwa tweet berhasil dibuat
    printf("Selamat! kicauan telah diterbitkan!\n");
    printf("Detil kicauan:\n");
    displayTweet(pNewTweet);
  }
}

void displayListTweet(ListDinTweet listTweet, ListStatikUser listUser,
                      Graph friendship, User user) {
  /* Bagian dari fitur utama kicauan */
  /* Menampilkan semua tweet milik pengguna dan teman-teman pengguna */

  if (isEmptyListTweet(listTweet)) {
    printf("Daftar kicauan kosong !\n");
  } else {
    int i;
    for (i = 0; i < listTweetLength(listTweet); i++) {
      AddressTweet *kicauanUtama = ELMT_LISTDINTWEET(listTweet, i);
      if (isTweetAuthor(*kicauanUtama, user) ||
          isTeman(friendship, AuthorTweet(*kicauanUtama), user.nama)) {
        displayTweet(*kicauanUtama);
      }
    }
  }
}

void like(ListDinTweet *listTweet, long id, ListStatikUser listUser,
          Graph friendship, User user) {
  /* Bagian dari fitur utama kicauan */
  /* Mencari tweet dengan id "id" di dalam list, kemudian menambah jumlah like
   * pada tweet tersebut */

  if (!isIdExist(*listTweet, id)) {
    printf("Tidak ditemukan kicauan dengan ID = %d!\n", id);
  } else if (isTweetAuthorPrivateAccount(
                 listUser, ELMT_LISTDINTWEET(*listTweet, id - 1)) &&
             !isTeman(friendship, user.nama,
                      AuthorTweet(ELMT_LISTDINTWEET(*listTweet, id - 1)))) {
    printf(
        "Wah, kicauan tersebut dibuat oleh akun privat! Ikuti akun itu dulu "
        "ya.\n");
  } else {
    likeTweet(ELMT_LISTDINTWEET(*listTweet, id - 1));
    printf("Selamat! kicauan telah disukai!\n");
    printf("Detil kicauan:\n");
    displayTweet(ELMT_LISTDINTWEET(*listTweet, id - 1));
  }
}

void editTweetInList(ListDinTweet *listTweet, long id, User user) {
  /* Bagian dari fitur utama kicauan */
  /* Mencari tweet dengan id "id" di dalam list, kemudian mengganti text tweet
   * tersebut berdasarkan masukan dari pengguna */

  if (!isIdExist(*listTweet, id)) {
    printf("Tidak ditemukan kicauan dengan ID = %d!\n", id);
  } else if (!isTweetAuthor(ELMT_LISTDINTWEET(*listTweet, id - 1), user)) {
    printf("Kicauan dengan ID = %d bukan milikmu!\n", id);
  } else {
    // Memasukkan text kicauan

    printf("Masukkan kicauan baru:\n");
    // Word newText;
    // int i = 0;
    // START();
    // while (!EOP && i < NMax) {
    //   newText.TabWord[i] = currentChar;
    //   i++;
    //   ADV();
    // }
    // newText.Length = i;

    STARTWORDnoIgnore(MAX_TWEET_LENGTH);

    // Validasi masukan text kicauan
    if (isOnlySpace(currentWord)) {
      // Jika masukan tidak valid, menampilkan pesan bahwa tweet gagal di-edit
      printf("Kicauan tidak boleh hanya berisi spasi!\n");
    } else {
      editTweet(ELMT_LISTDINTWEET(*listTweet, id - 1), currentWord);

      // Menampilkan pesan bahwa tweet berhasil dibuat
      printf("Selamat! kicauan telah diterbitkan!\n");
      printf("Detil kicauan:\n");
      displayTweet(ELMT_LISTDINTWEET(*listTweet, id - 1));
    }
  }
}

/* Fungsi/prosedur tambahan */

boolean isOnlySpace(Word text) {
  /* Mengirimkan true jika text hanya berisi spasi */

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
  /* Mengirimkan true jika tweet dengan id tersebut berada di dalam list */
  /* yaitu antara 1..NEFF_LISTDINTWEET(listTweet) */

  return 1 <= id && id <= NEFF_LISTDINTWEET(listTweet);
}

boolean isTweetAuthor(AddressTweet *kicauanUtama, User user) {
  /* Mengirimkan true jika tweet tersebut dibuat oleh user tersebut */

  return compareWordwWord(AuthorTweet(*kicauanUtama), user.nama);
}

boolean isTweetAuthorPrivateAccount(ListStatikUser listUser,
                                    AddressTweet *kicauanUtama) {
  /* Mengirimkan true jika tweet tersebut dibuat oleh user yang akunnya private
   */
  /* listUser tidak kosong dan informasi author dari tweet pasti ada di dalam
   * listUser*/

  int i = 0;
  while (!isTweetAuthor(*kicauanUtama, listUser.contents[i])) {
    i++;
  }

  return !listUser.contents[i].public;
}
