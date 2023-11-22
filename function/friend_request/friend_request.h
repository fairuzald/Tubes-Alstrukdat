#ifndef friend_request_H
#define friend_request_H

#include "./adt/queue.h"
#include "friend.h"

#define MAX_USERS 20

void addFriend(Queue *friendRequests, UserList * users, User currentUser);

void displayFriendRequests(Queue *friendRequests);

void approveFriendRequest(Queue *friendRequests);

#endif