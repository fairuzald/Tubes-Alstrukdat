#ifndef friend_request_H
#define friend_request_H

#include "../../adt/boolean.h"
#include "../../adt/graph.h"
#include "../../adt/input/wordmachine.h"
#include "../../adt/liststatikuser.h"
#include "../friend/friend.h"

#define MAX_CAP 20 * 19  // (?) bener ga sih?
#define IDX_UNDEF -1

typedef struct {
  int senderID;           // ID pengguna yang meminta pertemanan
  int receiverID;         // ID pengguna yang diminta pertemanan
  int senderFriendCount;  // Jumlah teman saat pengguna meminta pertemanan
} FriendRequest;

typedef FriendRequest ElType;

typedef struct {
  ElType buffer[MAX_CAP];
  int idxHead;
  int idxTail;
  int n;  // Semacam Length
} FriendRequestQueue;

#define SenderID(x) (x).senderID
#define ReceiverID(x) (x).receiverID
#define FriendCount(x) (x).senderFriendCount

extern FriendRequestQueue friendRequestQueue;

void CreateQueue(FriendRequestQueue* friendRequestQueue);

void AppendQueue(FriendRequestQueue* friendRequestQueue, int senderID,
                 int receiverID, int senderFriendCount);

boolean isEmptyQueue(FriendRequestQueue friendRequestQueue);

boolean isFullQueue(FriendRequestQueue friendRequestQueue);

int lengthQueue(FriendRequestQueue friendRequestQueue);

void addFriend(FriendRequestQueue* friendRequestQueue, ListStatikUser userList,
               Word currentUser);

void displayFriendRequests(FriendRequestQueue friendRequestQueue,
                           ListStatikUser userList, Word currentUser);

void approveFriendRequest(FriendRequestQueue* friendRequestQueue,
                          ListStatikUser userList, Word currentUser);

int NRequest(FriendRequestQueue friendRequestQueue, ListStatikUser userList,
             Word currentUser);

boolean isRequestExist(Word username, Word currentUser);

#endif