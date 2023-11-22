#include "listdintweet.h"

#include <stdio.h>
#include <stdlib.h>

ListDinTweet listTweetMain;

/* ********** KONSTRUKTOR ********** */

/* Konstruktor : create list kosong  */

void CreateListDinTweet(ListDinTweet *l, long capacity) {
  /* I.S. l sembarang, capacity > 0 */
  /* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */
  BUFFER(*l) = (ElTypeListDin *)malloc(capacity * sizeof(ElTypeListDin));
  NEFF_LISTDINTWEET(*l) = 0;
  CAPACITY_LISTDINTWEET(*l) = capacity;
}

void dealocateListDinTweet(ListDinTweet *l) {
  /* I.S. l terdefinisi; */
  /* F.S. (l) dikembalikan ke system, CAPACITY_LISTDINTWEET(l)=0;
   * NEFF_LISTDINTWEET(l)=0 */
  free(BUFFER(*l));
  NEFF_LISTDINTWEET(*l) = 0;
  CAPACITY_LISTDINTWEET(*l) = 0;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */

/* *** Banyaknya elemen *** */

int listTweetLength(ListDinTweet l) {
  /* Mengirimkan banyaknya elemen efektif list */
  /* Mengirimkan nol jika list l kosong */
  return NEFF_LISTDINTWEET(l);
}

/* ********** TEST KOSONG/PENUH ********** */

/* *** Test list kosong *** */

boolean isEmptyListTweet(ListDinTweet l) {
  /* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
  return listTweetLength(l) == 0;
}

/* *** Test list penuh *** */

boolean isFullListTweet(ListDinTweet l) {
  /* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */
  return listTweetLength(l) == CAPACITY_LISTDINTWEET(l);
}

/* ********** MENAMBAH DAN ELEMEN DI AKHIR ********** */

/* *** Menambahkan elemen terakhir *** */

void insertLastListTweet(ListDinTweet *l, ElTypeListDin val) {
  /* Proses: Menambahkan val sebagai elemen terakhir list */
  /* I.S. List l boleh kosong, tetapi tidak penuh */
  /* F.S. val adalah elemen terakhir l yang baru */
  ELMT_LISTDINTWEET(*l, listTweetLength(*l)) = val;
  NEFF_LISTDINTWEET(*l)++;
}

/* ********* MENGUBAH UKURAN ARRAY ********* */

void expandListTweet(ListDinTweet *l, int num) {
  /* Proses : Menambahkan capacity l sebanyak num */
  /* I.S. List sudah terdefinisi */
  /* F.S. Ukuran list bertambah sebanyak num */
  BUFFER(*l) = (ElTypeListDin *)realloc(
      BUFFER(*l), (CAPACITY_LISTDINTWEET(*l) + num) * sizeof(ElTypeListDin));
  CAPACITY_LISTDINTWEET(*l) += num;
}

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

    // Memasukkan semua informasi ke dalam Tweet
    AddressTweet pNewTweet =
        CreateTweet(currentWord, author, timeCreated, idTweet, idReply, idUtas,
                    like, depth, reply1, reply2, utas);

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
                      FriendshipMatrix friendshipMatrix, User user) {
  /* Bagian dari fitur utama kicauan */
  /* Menampilkan semua tweet milik pengguna dan teman-teman pengguna */

  if (isEmptyListTweet(listTweet)) {
    printf("Daftar kicauan kosong !\n");
  } else {
    int i;
    for (i = 0; i < listTweetLength(listTweet); i++) {
      AddressTweet pTweet = ELMT_LISTDINTWEET(listTweet, i);
      if (isTweetAuthor(pTweet, user) ||
          isFriend(listUser, friendshipMatrix, user.nama,
                   AuthorTweet(pTweet))) {
        displayTweet(pTweet);
      }
    }
  }
}

void like(ListDinTweet *listTweet, long id, ListStatikUser listUser,
          FriendshipMatrix friendshipMatrix, User user) {
  /* Bagian dari fitur utama kicauan */
  /* Mencari tweet dengan id "id" di dalam list, kemudian menambah jumlah like
   * pada tweet tersebut */

  if (!isIdExist(*listTweet, id)) {
    printf("Tidak ditemukan kicauan dengan ID = %ld!\n", id);
  } else if (isTweetAuthorPrivateAccount(
                 listUser, ELMT_LISTDINTWEET(*listTweet, id - 1)) &&
             !isFriend(listUser, friendshipMatrix, user.nama,
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
    printf("Tidak ditemukan kicauan dengan ID = %ld!\n", id);
  } else if (!isTweetAuthor(ELMT_LISTDINTWEET(*listTweet, id - 1), user)) {
    printf("Kicauan dengan ID = %ld bukan milikmu!\n", id);
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

boolean isTweetAuthor(AddressTweet pTweet, User user) {
  /* Mengirimkan true jika tweet tersebut dibuat oleh user tersebut */

  return compareWordwWord(AuthorTweet(pTweet), user.nama);
}

boolean isTweetAuthorPrivateAccount(ListStatikUser listUser,
                                    AddressTweet pTweet) {
  /* Mengirimkan true jika tweet tersebut dibuat oleh user yang akunnya private
   */
  /* listUser tidak kosong dan informasi author dari tweet pasti ada di dalam
   * listUser*/

  int i = 0;
  while (!isTweetAuthor(pTweet, listUser.contents[i])) {
    i++;
  }

  return !listUser.contents[i].public;
}

boolean isFriend(ListStatikUser listUser, FriendshipMatrix friendshipMatrix,
                 Word username1, Word username2) {
  /* Mengirimkan true jika akun username1 berteman dengan akun username2 */

  int user1Index = findIdx(&listUser, username1);
  int user2Index = findIdx(&listUser, username2);
  return 1 == friendshipMatrix.Friendship.adjMatrix.mem[user1Index][user2Index];
}
