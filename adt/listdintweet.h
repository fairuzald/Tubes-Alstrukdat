/* File : listlinier.h */
/* contoh ADT list berkait dengan representasi fisik pointer  */
/* Representasi address dengan pointer */
/* ElType adalah integer */

#ifndef LISTDINTWEET_H
#define LISTDINTWEET_H

#include "../function/friend/friend.h"
#include "../function/tweet/tweet.h"
#include "boolean.h"
#include "graph.h"
#include "liststatikuser.h"

/* Definisi Node : */
typedef int ElType;
typedef struct node *Address;
typedef struct node {
  ElType info;
  Address next;
} Node;

#define INFO(p) (p)->info
#define NEXT(p) (p)->next

/*  Kamus Umum */
#define IDX_MIN_LISTDINTWEET 0
/* Indeks minimum list */
#define IDX_UNDEF_LISTDINTWEET -1
/* Indeks tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef AddressTweet ElType; /* type elemen list */
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
#define ELMT_LISTDINTWEET(l, i) (l).buffer[(i)]
#define NEFF_LISTDINTWEET(l) (l).nEff
#define CAPACITY_LISTDINTWEET(l) (l).capacity

Address newNode(ElType val);

/* Definisi List : */
/* List kosong : FIRST(l) = NULL */
/* Setiap elemen dengan Address p dapat diacu INFO(p), NEXT(p) */
/* Elemen terakhir list: jika addressnya Last, maka NEXT(Last)=NULL */

typedef Address List;

#define IDX_UNDEF (-1)
#define FIRST(l) (l)

/* PROTOTYPE */
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *l);
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** TEST LIST KOSONG ******************/
boolean isEmpty(List l);
/* Mengirim true jika list kosong */

/****************** GETTER SETTER ******************/
ElType getElmt(List l, int idx);
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengembalikan nilai elemen l pada indeks idx */

void setElmt(List *l, int idx, ElType val);
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengubah elemen l pada indeks ke-idx menjadi val */

int indexOf(List l, ElType val);
/* I.S. l, val terdefinisi */
/* F.S. Mencari apakah ada elemen list l yang bernilai val */
/* Jika ada, mengembalikan indeks elemen pertama l yang bernilai val */
/* Mengembalikan IDX_UNDEF jika tidak ditemukan */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst(List *l, ElType val);
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. */

void insertLast(List *l, ElType val);
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

void insertAt(List *l, ElType val, int idx);
/* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu
 * 0..length(l) */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menyisipkan elemen dalam list pada indeks ke-idx (bukan menimpa elemen di i)
 */
/* yang bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(List *l, ElType *val);
/* I.S. List l tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen pertama di-dealokasi */
void deleteLast(List *l, ElType *val);
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen terakhir di-dealokasi */

void deleteAt(List *l, int idx, ElType *val);
/* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. val diset dengan elemen l pada indeks ke-idx. */
/*      Elemen l pada indeks ke-idx dihapus dari l */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayList(List l);
// void printInfo(List l);
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */

int length(List l);
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

/* MODUL TWEET DYNAMIC LIST */
/* Berisi definisi dan semua primitif pemrosesan list Tweet */
/* Penempatan elemen selalu rapat kiri */
/* Versi II : dengan banyaknya elemen didefinisikan secara eksplisit,
   memori list dinamik */

/* ********** KONSTRUKTOR ********** */

/* Konstruktor : create list kosong  */

void CreateListDinTweet(ListDinTweet *l, long capacity);
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */

void dealocateListDinTweet(ListDinTweet *l);
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY_LISTDINTWEET(l)=0;
 * NEFF_LISTDINTWEET(l)=0 */

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

/* Fitur-Fitur Utama */

void inputNewTweet(ListDinTweet *listTweet, User user);
/* Bagian dari fitur utama kicauan */
/* Membuat tweet baru berdasarkan masukan dari pengguna dan memasukannya ke
 * dalam list */

void displayListTweet(ListDinTweet listTweet, ListStatikUser listUser,
                      Graph grafPertemanan, User user);
/* Bagian dari fitur utama kicauan */
/* Menampilkan semua tweet milik pengguna dan teman-teman pengguna */

void like(ListDinTweet *listTweet, long id, ListStatikUser listUser,
          Graph grafPertemanan, User user);
/* Bagian dari fitur utama kicauan */
/* Mencari tweet dengan id "id" di dalam list, kemudian menambah jumlah like
 * pada tweet tersebut */

void editTweetInList(ListDinTweet *listTweet, long id, User user);
/* Bagian dari fitur utama kicauan */
/* Mencari tweet dengan id "id" di dalam list, kemudian mengganti text tweet
 * tersebut berdasarkan masukan dari pengguna */

/* Fungsi/prosedur tambahan */

boolean isOnlySpace(Word text);
/* Mengirimkan true jika text hanya berisi spasi */

boolean isIdExist(ListDinTweet listTweet, long id);
/* Mengirimkan true jika tweet dengan id tersebut berada di dalam list */
/* yaitu antara 1..NEFF_LISTDINTWEET(listTweet) */

boolean isTweetAuthor(AddressTweet ptweet, User user);
/* Mengirimkan true jika tweet tersebut dibuat oleh user tersebut */

boolean isTweetAuthorPrivateAccount(ListStatikUser listUser,
                                    AddressTweet pTweet);
/* Mengirimkan true jika tweet tersebut dibuat oleh user yang akunnya private */
/* listUser tidak kosong dan informasi author dari tweet pasti ada di dalam
 * listUser*/

boolean isFriend(ListStatikUser listUser, Graph grafPertemanan,
                 Word username1, Word username2);
/* Mengirimkan true jika akun username1 berteman dengan akun username2 */

#endif
