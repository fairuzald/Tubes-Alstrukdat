#include <stdio.h>
#include <stdlib.h>
#include "listdintweet.h"

void insertUtas(AddressTweet *kicauanUtama, AddressTweet sambungan, int index){
	if(index == 1){
		Utas(sambungan) = Utas(*kicauanUtama);
		Utas(*kicauanUtama) = sambungan;
	}else{
		int i = 0;
		AddressTweet loc = *kicauanUtama;
		while(i < index - 1){
			i++;
			loc = Utas(loc);
		}

		Utas(sambungan) = Utas(loc);
		Utas(loc) = Utas(sambungan);
	}
}

int lengthUtas(AddressTweet *kicauanUtama){
	int ans = 1;
	AddressTweet loc = Utas(*kicauanUtama);
	while(loc != NULL){
		ans++;
		loc = Utas(loc);
	}

	return ans;
}

int maxIDUtas(ListDinTweet *listTweetMain){
	int i = 0, ans = 0;
	for( ; i < listTweetLength(*listTweetMain); i++){
		if(IdUtas(ELMT_LISTDINTWEET(*listTweetMain, i)) > ans){
			ans = IdUtas(ELMT_LISTDINTWEET(*listTweetMain, i));
		}
	}

	return ans;
}