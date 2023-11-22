#ifndef FRIEND_H
#define FRIEND_H

#include <stdio.h>

#include "../../adt/graph.h"
#include "../../adt/input/wordmachine.h"

#define MAX 100

typedef struct {
  Graph Friendship;  // Matriks adjacency untuk merepresentasikan pertemanan
} FriendshipMatrix;

extern FriendshipMatrix mFriendship; /*men-global-kan userList*/

typedef struct {
  int senderID;           // ID pengguna yang meminta pertemanan
  int receiverID;         // ID pengguna yang diminta pertemanan
  int senderFriendCount;  // Jumlah teman saat pengguna meminta pertemanan
} FriendRequest;

typedef struct {
  User users[MAX];  // Array of users
  int n;            // Jumlah pengguna dalam daftar
} UserList;

typedef struct {
  User friends[MAX];  // Array of user IDs
  int n;              // Jumlah teman dalam daftar
} FriendList;

typedef struct {
  Word name;       // Nama Pengguna
  int popularity;  // Jumlah Popularitas
} User;

#define User(x) users->users[x].name
#define Name(x) x->name
#define UserPopularity(x) x->popularity

int findIdx(UserList *users, Word username);

void DaftarTeman(FriendshipMatrix *friendshipMatrix, UserList *users,
                 Word currentUser, FriendList *friendList);

void HapusTeman(Graph *G, UserList *users, Word username, Word CurrentUser);

#endif