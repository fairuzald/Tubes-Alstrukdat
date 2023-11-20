/* MODUL TWEET DYNAMIC LIST */
/* Berisi definisi dan semua primitif pemrosesan list Tweet */
/* Penempatan elemen selalu rapat kiri */
/* Versi II : dengan banyaknya elemen didefinisikan secara eksplisit,
   memori list dinamik */

#ifndef LISTDINTWEET_H
#define LISTDINTWEET_H

#include "../function/friend/friend.h"
#include "../function/tweet/tweet.h"
#include "../function/user/user.h"
#include "boolean.h"
#include "graph.h"
#include "liststatikuser.h"

/*  Kamus Umum */
#define IDX_MIN 0
/* Indeks minimum list */
#define IDX_UNDEF -1
/* Indeks tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef Tweet ElType; /* type elemen list */
typedef long IdxType;
typedef struct {
  ElType *buffer; /* memori tempat penyimpan elemen (container) */
  long nEff;      /* >=0, banyaknya elemen efektif */
  long capacity;  /* ukuran elemen */
} ListDinTweet;
/* Indeks yang digunakan [0..capacity-1] */
/* Jika l adalah : ListDinTweet, cara deklarasi dan akses: */
/* Deklarasi : l : ListDinTweet */
/* Maka cara akses:
   l.nEff      untuk mengetahui banyaknya elemen
   l.buffer    untuk mengakses seluruh nilai elemen list
   l.buffer[i] untuk mengakses elemen ke-i */
/* Definisi :
  list kosong: l.nEff = 0
  Definisi elemen pertama : l.buffer[i] dengan i=0
  Definisi elemen terakhir yang terdefinisi: l.buffer[i] dengan i=l.capacity */

/* State Global ListDinTweet */
extern ListDinTweet listTweetMain;

/* ********** SELEKTOR ********** */

#define BUFFER(l) (l).buffer
#define ELMT(l, i) (l).buffer[i]
#define NEFF(l) (l).nEff
#define CAPACITY(l) (l).capacity

/* ********** KONSTRUKTOR ********** */

/* Konstruktor : create list kosong  */

void CreateListDinTweet(ListDinTweet *l, long capacity);
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */

void dealocateListDinTweet(ListDinTweet *l);
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */

/* ********** SELEKTOR (TAMBAHAN) ********** */

/* *** Banyaknya elemen *** */

int listTweetLength(ListDinTweet l);
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
/* *** Daya tampung container *** */

/* ********** TEST KOSONG/PENUH ********** */

/* *** Test list kosong *** */

boolean isEmptyListTweet(ListDinTweet l);
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */

/* *** Test list penuh *** */

boolean isFullListTweet(ListDinTweet l);
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */

/* ********** MENAMBAH DAN ELEMEN DI AKHIR ********** */

/* *** Menambahkan elemen terakhir *** */

void insertLastListTweet(ListDinTweet *l, ElType val);
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */

/* ********* MENGUBAH UKURAN ARRAY ********* */

void expandListTweet(ListDinTweet *l, int num);
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */

void shrinkListTweet(ListDinTweet *l, int num);
/* Proses : Mengurangi capacity sebanyak num */
/* I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity -
 * num. */
/* F.S. Ukuran list berkurang sebanyak num. */

/* Fitur-Fitur Utama */

void newTweet(ListDinTweet *listTweet, User currentUser);
/* Bagian dari fitur utama kicauan */
/* Membuat tweet baru berdasarkan masukan dari pengguna dan memasukannya ke
 * dalam list */

void displayListTweet(ListDinTweet listTweet, ListStatikUser listUser,
                      FriendshipMatrix friendshipMatrix, User currentUser);
/* Bagian dari fitur utama kicauan */
/* Menampilkan semua tweet milik pengguna dan teman-teman pengguna */

void like(ListDinTweet *listTweet, long id, ListStatikUser listUser,
          FriendshipMatrix friendshipMatrix, User currentUser);
/* Bagian dari fitur utama kicauan */
/* Mencari tweet dengan id "id" di dalam list, kemudian menambah jumlah like
 * pada tweet tersebut */

void editTweetInList(ListDinTweet *listTweet, long id, User currentUser);
/* Bagian dari fitur utama kicauan */
/* Mencari tweet dengan id "id" di dalam list, kemudian mengganti text tweet
 * tersebut berdasarkan masukan dari pengguna */

/* Fungsi/prosedur tambahan */

boolean isOnlySpace(Word text);
/* Mengirimkan true jika text hanya berisi spasi */

boolean isIdExist(ListDinTweet listTweet, long id);
/* Mengirimkan true jika tweet dengan id tersebut berada di dalam list */
/* yaitu antara 1..NEFF(listTweet) */

boolean isTweetAuthor(Tweet tweet, User user);
/* Mengirimkan true jika tweet tersebut dibuat oleh user tersebut */

boolean isTweetAuthorPrivateAccount(ListStatikUser listUser, Tweet tweet);
/* Mengirimkan true jika tweet tersebut dibuat oleh user yang akunnya private */
/* listUser tidak kosong dan informasi author dari tweet pasti ada di dalam
 * listUser*/

boolean isFriend(ListStatikUser listUser, FriendshipMatrix friendshipMatrix,
                 Word username1, Word username2);
/* Mengirimkan true jika akun username1 berteman dengan akun username2 */

#endif
