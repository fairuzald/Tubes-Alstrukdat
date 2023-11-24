#include <stdio.h>
#include <stdlib.h>
#include "reply.h"

void CreateReply(ListDinTweet *listTweetMain, AddressTweet *temp, Word textTweet, Word authorTweet, DATETIME timeCreatedTweet, int idKicau, int idBalasan){
	// tweet terpilih
	AddressTweet current = ELMT_LISTDINTWEET(*listTweetMain, idKicau-1);

	if(idBalasan == -1){
		// membuat node tweet baru
		*temp = CreateTweet(textTweet, authorTweet, DATETIME timeCreatedTweet, 0, IdReply(current)+1, 0, 0, 0, NULL, NULL, NULL, false);
		IdReply(current)++;
		if(Reply2(current) != NULL){
			// sudah ada balasan sebelumnya
			// tambahkan di reply2
			AddressTweet loc = Reply2(current);
			while(Reply1(loc) != NULL){
				loc = Reply1(loc);
			}
			Reply1(loc) = *temp;
		}else{
			// belum ada balasan apapun sebelumnya
			Reply2(current) = *temp;
		}
	}else{
		AddressTweet prevTweet = findPrevReply(current, idBalasan);

		// membuat node tweet baru
		*temp = CreateTweet(currentWord, currentUser.nama, getCurrentDateTime(), 0, IdReply(current)+1, 0, 0, 0, NULL, NULL, NULL, false);
		IdReply(current)++;

		// Kasus ada di bawah reply2
		if(IdReply(Reply2(prevTweet)) == idBalasan){
			// tambahkan pada reply 1
			Reply1(Reply2(prevTweet)) = *temp;
		}else{
			// tambahkan pada reply 2
			Reply2(Reply1(prevTweet)) = *temp;
		}
	}
}

void displayNewReply(AddressTweet temp){
	printf("\nSelamat! balasan telah diterbitkan!\nDetil balasan:\n");

	// display ID
	printf("| ID = %d\n", IdReply(temp));

		// display author
	printf("| ");
	int i;
	for (i = 0; i < AuthorTweet(temp).Length; i++) {
		printf("%c", AuthorTweet(temp).TabWord[i]);
	}
	printf("\n");

	// display timeCreated
	printf("| ");
	TulisDATETIME(TimeCreatedTweet(temp));
	printf("\n");

	// display text
	printf("| ");
	for (i = 0; i < TextTweet(temp).Length; i++) {
		printf("%c", TextTweet(temp).TabWord[i]);
	}
	printf("\n");
}

AddressTweet findPrevReply(AddressTweet root, int idBalasan){
	// mengembalikan address node sebelumnya yang memiliki id balasan = isBalasan
	if(root == NULL){
		return NULL;
	}

	if(IdReply(Reply1(root)) == idBalasan || IdReply(Reply2(root)) == idBalasan){
		return root;
	}

	// cari di kiri
	AddressTweet leftRes = findReply(Reply1(root), idBalasan)
	if(leftRes != NULL){
		return leftRes;
	}

	// cari di kanan
	AddressTweet rightRes = findReply(Reply2(root), idBalasan)
	return rightRes
}

void inputNewReply(ListDinTweet *listTweetMain, User user, int idKicau, int idBalasan){
	// kasus tidak ada kicauan yang bisa dibalas
	// kasus tidak ada balasan yang bisa dibalas
	// kasus balasannya privat
	if(idKicau > listTweetLength(*listTweetMain) && idKicau <= 0){
		// id tidak terdapat pada list tweet
		printf("\nWah, tidak terdapat kicauan yang ingin Anda balas!\n");
	}else{
		// // tweet terpilih
		// AddressTweet current = ELMT_LISTDINTWEET(*listTweetMain, idKicau-1);

		if(idBalasan == -1){
			// kasus membuat balasan baru pada kicauan utama
			// kasus penulis privat
			int idAuthorTweet = userIndex(AuthorTweet(ELMT_LISTDINTWEET(*listTweetMain, idKicau-1)));
			boolean priv = !PUBLIC(idAuthorTweet) && !isTeman(grafPertemanan, AuthorTweet(current), currentUser.nama);
			if(priv){
				printf("\nWah, akun tersebut merupakan akun privat dan anda belum berteman akun tersebut!\n");
			}else{
				// node untuk balasan yang baru
				AddressTweet temp;

				// mengambil input kicauan
				printf("\nMasukkan balasan:\n");
				STARTWORDNOIGNORE(280);
				
				CreateReply(listTweetMain, &temp, currentWord, currentUser.nama, getCurrentDateTime(), idKicau, idBalasan);

				// // membuat node tweet baru
				// AddressTweet temp = CreateTweet(currentWord, currentUser.nama, getCurrentDateTime(), 0, IdReply(current)++, 0, 0, 0, NULL, NULL, NULL, false);
				// IdReply(current)++;
				// if(Reply2(current) != NULL){
				// 	// sudah ada balasan sebelumnya
				// 	// tambahkan di reply2
				// 	AddressTweet loc = Reply2(current);
				// 	while(Reply1(loc) != NULL){
				// 		loc = Reply1(loc);
				// 	}
				// 	Reply1(loc) = temp;
				// }else{
				// 	// belum ada balasan apapun sebelumnya
				// 	Reply2(current) = temp;
				// }

				displayNewReply(temp);
			}
		}else{
			AddressTweet prevTweet = findPrevReply(current, idBalasan);

			// tidak ada idBalasannya
			if(prevTweet == NULL){
				printf("\nWah, tidak terdapat balasan yang ingin Anda balas!\n");
			}else{
				// ada idBalasan
				
				// node untuk balasan yang baru
				AddressTweet temp;

				// mengambil input kicauan
				printf("\nMasukkan balasan:\n");
				STARTWORDNOIGNORE(280);

				CreateReply(listTweetMain, &temp, currentWord, currentUser.nama, getCurrentDateTime(), idKicau, idBalasan);
				
				// // membuat node tweet baru
				// AddressTweet temp = CreateTweet(currentWord, currentUser.nama, getCurrentDateTime(), 0, IdReply(current)++, 0, 0, 0, NULL, NULL, NULL, false);
				// IdReply(current)++;

				// // Kasus ada di bawah reply2
				// if(IdReply(Reply2(prevTweet)) == idBalasan){
				// 	// tambahkan pada reply 1
				// 	Reply1(Reply2(prevTweet)) = temp;
				// }else{
				// 	// tambahkan pada reply 2
				// 	Reply2(Reply1(prevTweet)) = temp;
				// }

				displayNewReply(temp);
			}
		}
	}
}

void deleteReply(ListDinTweet *listTweetMain, int idKicau, int idBalasan){
	// cari id kicau
	if(idKicau > listTweetLength(*listTweetMain)){
		// id tidak terdapat pada list tweet
		printf("\nTidak terdapat kicauan dengan id tersebut!\n");
	}else{
		AddressTweet current = ELMT_LISTDINTWEET(*listTweetMain, idKicau-1);
		if(Reply2(current) == NULL){
			// belum ada balasan
			printf("\nBalasan tidak ditemukan\n");
		}else{
			// cari posisi balasan
			AddressTweet sebelumBalasan = findPrevReply(Reply2(current), idBalasan);

			// ada idBalasan
			if(balasan != NULL){
				// cari di reply 1 atau reply 2
				AddressTweet balasan;

				// Kasus ada di bawah reply2
				if(IdReply(Reply2(sebelumBalasan)) == idBalasan){
					// pindahkan posisi balasan ke reply 2
					balasan = Reply2(sebelumBalasan);
					Reply2(sebelumBalasan) = Reply1(balasan);
				}else{
					// pindahkan posisi balasan ke reply 1
					balasan = Reply1(sebelumBalasan);
					// sambungkan balasan 1 sisanya
					Reply1(sebelumBalasan) = Reply1(balasan);
				}

				// cek status balasan
				if(currentUser.nama != AuthorTweet(balasan)){
					// balasan milik orang lain
					printf("\nHei, ini balasan punya siapa? Jangan dihapus ya!\n");
				}else{
					deleteNode(&Reply2(balasan));
					deallocateTweet(balasan);
					printf("\nBalasan berhasil dihapus\n");
				}
			}else{
				// tidak ada idBalasan
				printf("\nBalasan tidak ditemukan\n");
			}
		}
	}
}

void displayReply(ListDinTweet *listTweetMain, int idKicau){
	if(idKicau > listTweetLength(*listTweetMain)){
		// id tidak terdapat pada list tweet
		printf("\nTidak terdapat kicauan dengan id tersebut!\n");
	}else{
		// ada id
		// kasus kicauan privat
		// cari privat atau tidak
		int idAuthorTweet = userIndex(AuthorTweet(ELMT_LISTDINTWEET(*listTweetMain, idKicau-1)));
		boolean priv = !PUBLIC(idAuthorTweet) && !isTeman(grafPertemanan, AuthorTweet(current), currentUser.nama);
		if(priv){
			// privat
			printf("\nWah, kicauan tersebut dibuat oleh pengguna dengan akun privat!\n");
		}else{
			if(Reply2(ELMT_LISTDINTWEET(*listTweetMain, idKicau-1)) == NULL){
				// belum ada balasan
				printf("\nBelum terdapat balasan apapun pada kicauan tersebut. Yuk balas kicauan tersebut!\n");
			}else{
				displayNode(ELMT_LISTDINTWEET(*listTweetMain, idKicau-1), 0);
			}
		}
	}
}
