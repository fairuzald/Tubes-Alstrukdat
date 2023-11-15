#include <stdio.h>
#include "friend.h"
#include "./adt/graph.h"
#include "./adt/wordmachine.h"

int findIdx(UserList *users, Word username) {
    for (int i = 0; i < users->n; i++) {
        if (compareWordwWord(users->users[i].name, username)) {
            return i;
        }
    }
}

void DaftarTeman(FriendshipMatrix *friendshipMatrix, UserList *users, Word currentUser, FriendList *friendList) {
    int userID = findIdx(users, currentUser);
    int i;

    printf("%s memiliki %d teman\n", Name(users->users[userID]), users->users[userID].popularity);
    printf("Daftar teman %s\n", Name(users->users[userID]));

    for (i = 0; i < friendList->n; i++) {
        int friendID = findIdx(users, currentWord);
        if (friendshipMatrix->Friendship.adjMatrix.mem[userID][friendID] == 1) {
            printf("| %s\n", Name(users->users[friendID]));
        }
    }
}


void HapusTeman(Graph *G, UserList *users, Word username, Word currentUser) {
    STARTWORD();
    int user1 = findIdx(users, currentUser);
    int user2 = findIdx(users, username);
    if (ELMT(G, user1, user2) == 1) {
        printf("Apakah anda yakin ingin menghapus ");
        STARTWORDnoIgnore(50);
        printf("%s dari daftar teman anda?(YA/TIDAK) ", currentWord.TabWord);

        if (compareWordwString(currentWord, "YA")) {
            removeFriend(G, users, username, currentUser);
            removeFromFriendList(users, currentWord, currentUser);
        } else {
            printf("Penghapusan teman dibatalkan.\n");
        }
    } else {
        printf("%s bukan teman Anda.\n", currentWord.TabWord);
    }
}

void removeFriend(Graph *G, UserList *users, Word username, Word currentUser) {
    int User1ID = findIdx(users, username);
    int User2ID = findIdx(users, currentUser);
    
    deleteEdge(G, User1ID, User2ID);
    deleteEdge(G, User2ID, User1ID);
}
