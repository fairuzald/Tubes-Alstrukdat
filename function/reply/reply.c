void CreateReply(Word textTweet, Word authorTweet,
                         DATETIME timeCreatedTweet,
                         long idUtas,
                         AddressTweet utas, Tweet *prev, Tweet root, AddressTweet *newReply){

    AddressTweet temp = CreateTweet(textTweet, authorTweet,timeCreatedTweet, 0, 0,0, 0, Depth(*prev) + 1, NULL, NULL, NULL);
    IdReply(temp) = IdReply(root) +1;
    IdReply(root)++;
    if(Reply2(*prev) != NULL){
        // sebelumnya sudah ada balasan pada tweet yang sama
        // ke sibling balasannya
        // traverse reply1
        AddressTweet loc = Reply1(Reply2(*prev));
        while(Reply1(loc) != NULL){
            loc = Reply1(loc);
        }
        Reply1(loc) = temp;
        Depth(temp) = Depth(loc);
    }else{
        // balasan pertama
        Reply2(*prev) = temp;
        Depth(temp) = Depth(*prev)++;
    }

    *newReply = temp;
}

void dfsDelete(AddressTweet * root){
    if(root != NULL){
        dfsDelete(Reply1(*root));
        dfsDelete(Reply2(*root));
        deallocateTweet(root);
    }
}

void deleteReply(long idKicau, long idBalasan,  AddressTweet * root, AddressTweet * prev){
    if(IdReply(root) == idBalasan){
        Reply2(*prev) = NULL;
        dfsDelete(root);
        return;
    }else{
        *prev = *root;
        *root = Reply2(*root)
        deleteReply(idKicau, idBalasan, Reply2(*root), Reply2(*prev));
    }
}

void displayReply(int idKicau, int space, AddressTweet pTweet){
    if(!IsEmpty(pTweet)){

        int i = 0;
        for( ; i < 4 * space; i++){
            printf(" ");
        }
        printf("| ID = %d\n", IdReply((pTweet)));

        for( ; i < 4 * space; i++){
            printf(" ");
        }

        if(priv){
            printf("| PRIVAT\n");
        }else{
            printf("| ");
            int j;
            for (j = 0; j < AuthorTweet(pTweet).Length; j++) {
                printf("%c", AuthorTweet(pTweet).TabWord[j]);
            }
        }
        printf("\n");

        for( ; i < 4 * space; i++){
            printf(" ");
        }

        if(priv){
            printf("| PRIVAT\n");
        }else{
            // display timeCreated
            printf("| ");
            TulisDATETIME(TimeCreatedTweet(pTweet));
            printf("\n");
        }

        for( ; i < 4 * space; i++){
            printf(" ");
        }

        if(priv){
            printf("| PRIVAT\n");
        }else{
            // display text
            printf("| ");

            for (i = 0; i < TextTweet(pTweet).Length; i++) {
                printf("%c", TextTweet(pTweet).TabWord[i]);
            }
        }

        displayReply(idKicau, space, Reply1(pTweet));
        displayReply(idKicau, space + 1, Reply2(pTweet));
    }
}