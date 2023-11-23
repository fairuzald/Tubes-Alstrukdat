#ifndef friend_request_H
#define friend_request_H

#include "friend.h"
#include "./adt/input/wordmachine.h"
#include "./adt/boolean.h"
#include "./../adt/graph.h"
#include "./../adt/liststatikuser.h"

#define MAX_CAP 20 * 19 // (?) bener ga sih?
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
  int n; // Semacam Length
} FriendRequestQueue;

#define SenderID(x) (x).senderID
#define ReceiverID(x) (x).receiverID
#define FriendCount(x) (x).senderFriendCount

extern FriendRequestQueue friendRequestQueue;

void CreateQueue(FriendRequestQueue * friendRequestQueue);

boolean isEmpty();

boolean isFull();

int length();

void tambahTeman();

void addFriend();

void displayFriendRequests();

void approveFriendRequest();

#endif