#ifndef FRIEND_H
#define FRIEND_H

#include <stdio.h>

#include "../../adt/graph.h"
#include "../../adt/input/wordmachine.h"
#include "../../adt/liststatikuser.h"

extern Graph grafPertemanan;

int findID(ListStatikUser users, Word username);

Word findUser(ListStatikUser users, int userID);

int countTeman(Graph grafPertemanan, ListStatikUser userList, Word username);

void DaftarTeman(Graph grafPertemanan, ListStatikUser userList, Word currentUser, boolean sudahMasuk);

boolean isTeman(Graph grafPertemanan, Word userFriend, Word currentUser);

void HapusTeman(Graph * grafPertemanan, ListStatikUser * userList, Word currentUser, boolean sudahMasuk);

void insertFriend(Graph * grafPertemanan, Word userFriend, Word currentUser);

#endif