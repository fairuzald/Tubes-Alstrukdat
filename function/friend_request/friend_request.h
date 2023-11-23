#ifndef friend_request_H
#define friend_request_H

#include "./../adt/graph.h"
#include "./../adt/liststatikuser.h"
#include "./adt/boolean.h"
#include "./adt/input/wordmachine.h"
#include "friend.h"

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
// Function declarations
void CreateQueue(FriendRequestQueue *friendRequestQueue);
boolean isEmpty(FriendRequestQueue friendRequestQueue);
boolean isFull(FriendRequestQueue friendRequestQueue);
int length(FriendRequestQueue friendRequestQueue);
void addFriend(FriendRequestQueue *friendRequestQueue, Word currentUser);
void displayFriendRequests(FriendRequestQueue friendRequestQueue,
                           Word currentUser);
void approveFriendRequest(Word currentUser);
int NRequest(FriendRequestQueue friendRequestQueue, Word currentUser);
boolean isRequestExist(Word username, Word currentUser);

#endif