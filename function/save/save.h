#ifndef SAVE_USERH
#define SAVE_USERH

#include <stdio.h>
#include <stdlib.h>

#include "../../adt/boolean.h"
#include "../../adt/input/charmachinefile.h"
#include "../../adt/input/wordmachine.h"
#include "../../adt/input/wordmachinefile.h"
#include "../../adt/listdintweet.h"
#include "../../adt/liststackdraft.h"
#include "../../adt/liststatikuser.h"
#include "../friend/friend.h"
#include "../friend_request/friend_request.h"
#include "../input/input.h"
#include "../tweet/main_tweet.h"
#include "../tweet/tweet.h"
#include "../tweet_draft/main_draft.h"
#include "../tweet_draft/tweet_draft.h"
#include "../user/user.h"
// Function prototypes
#include <stdio.h>
#include <sys/stat.h>  // Untuk fungsi mkdir dan struct stat

#include "save.h"
void saveUser(ListStatikUser *l, char folderName[]);
void saveTweet(ListDinTweet *l, char folderName[]);
void saveUtas(ListDinTweet *l, char folderName[]);
void saveReply(ListDinTweet *l, char folderName[]);
void saveTweetReplyUtas(ListDinTweet *l, char folderName[]);
void saveDraft(ListStackDraft *l, char folderName[]);
void createFolder(char *folderName);
void saveToFolder(char *folderName);
void simpan(Word *command);

#endif
