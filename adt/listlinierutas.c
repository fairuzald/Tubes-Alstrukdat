#include <stdio.h>
#include <stdlib.h>

#include "listdintweet.h"

int lengthUtas(AddressTweet *kicauanUtama) {
  int ans = 1;
  AddressTweet loc = Utas(*kicauanUtama);
  while (loc != NULL) {
    ans++;
    loc = Utas(loc);
  }

  return ans;
}

void insertUtas(AddressTweet *kicauanUtama, AddressTweet sambungan, int index) {
  if (index == 1) {
    Utas(*kicauanUtama) = sambungan;
  } else if (index == lengthUtas(kicauanUtama)) {
    AddressTweet loc = *kicauanUtama;
    while (Utas(loc) != NULL) {
      loc = Utas(loc);
    }
    Utas(loc) = sambungan;
  } else {
    // 0 1 2 3
    int i = 0;
    AddressTweet loc = *kicauanUtama;
    while (i < index - 1) {
      i++;
      loc = Utas(loc);
    }

    Utas(sambungan) = Utas(loc);
    Utas(loc) = Utas(sambungan);
  }
}
int maxIDUtas(ListDinTweet *listTweetMain) {
  int i = 0, ans = 0;
  for (; i < listTweetLength(*listTweetMain); i++) {
    if (IdUtas(ELMT_LISTDINTWEET(*listTweetMain, i)) > ans) {
      ans = IdUtas(ELMT_LISTDINTWEET(*listTweetMain, i));
    }
  }

  return ans;
}