#include "../../adt/listdintweet.h"
#include "../../adt/liststackdraft.h"
#include "../../adt/liststatikuser.h"

/* State Global ListStackDraft */
extern ListStackDraft listStackDraftMain;

/* Fitur-Fitur Utama */

void inputNewDraft(ListStackDraft *listStackDraft, ListDinTweet *listTweet,
                   User user);
/* Menambahkan sebuah draft */
/* Kemudian, user dapat memilih untuk menghapus, menyimpan, atau menerbitkan
 * draft */

void deleteNewDraft();
/* Menghapus draft yang baru dibuat */

void saveNewDraft(ListStackDraft *listStackDraft, User user, Word newText);
/* Menyimpan draft yang baru dibuat */

void publishNewDraft(ListDinTweet *listTweet, User user, Word newText);
/* Menerbitkan draft yang baru dibuat */

void displayUserDraft(ListStackDraft *listStackDraft, ListDinTweet *listTweet,
                      User user);
/* Menampilkan draft terakhir */
/* Kemudian, user dapat memilih untuk menghapus, mengubah, atau menerbitkan
 * draft */

void deleteUserDraft(ListStackDraft *listStackDraft, User user);
/* Menghapus draft terakhir milik user */

void modifyUserDraft(ListStackDraft *listStackDraft, ListDinTweet *listTweet,
                     User user);
/* Mengubah draft terakhir milik user */

void publishUserDraft(ListStackDraft *listStackDraft, ListDinTweet *listTweet,
                      User user);
/* Menerbitkan draft terakhir milik user */