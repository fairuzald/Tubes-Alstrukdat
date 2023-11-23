#ifndef MAIN_TWEET_H
#define MAIN_TWEET_H

#include "../../adt/graph.h"
#include "../../adt/listdintweet.h"
#include "../../adt/liststatikuser.h"
#include "../friend/friend.h"

/* State Global ListDinTweet */
extern ListDinTweet listTweetMain;

/* Fitur-Fitur Utama */

void inputNewTweet(ListDinTweet *listTweet, User user);
/* Bagian dari fitur utama kicauan */
/* Membuat tweet baru berdasarkan masukan dari pengguna dan memasukannya ke
 * dalam list */

void displayListTweet(ListDinTweet listTweet, ListStatikUser listUser,
                      Graph friendship, User user);
/* Bagian dari fitur utama kicauan */
/* Menampilkan semua tweet milik pengguna dan teman-teman pengguna */

void like(ListDinTweet *listTweet, long id, ListStatikUser listUser,
          Graph friendship, User user);
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

boolean isTweetAuthor(AddressTweet *kicauanUtama, User user);
/* Mengirimkan true jika tweet tersebut dibuat oleh user tersebut */

boolean isTweetAuthorPrivateAccount(ListStatikUser listUser,
                                    AddressTweet *kicauanUtama);
/* Mengirimkan true jika tweet tersebut dibuat oleh user yang akunnya private */
/* listUser tidak kosong dan informasi author dari tweet pasti ada di dalam
 * listUser*/

#endif
