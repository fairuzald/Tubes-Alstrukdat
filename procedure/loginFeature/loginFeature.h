#include "../../adt/boolean.h"
#include "../../adt/graph.h"
#include "../../adt/input/wordmachine.h"
#include "../../adt/listdintweet.h"
#include "../../adt/liststatikuser.h"
#include "../../function/friend/friend.h"
#include "../../function/friend_request/friend_request.h"
#include "../../function/profile/profile.h"
#include "../../function/save/save.h"
#include "../../function/tweet/main_tweet.h"
#include "../../function/user/user.h"
#ifndef LOGIN_FEATURE_H
#define LOGIN_FEATURE_H

// Function declarations for user-related features
void loginFeatureUser(Word *command);
void loginFeatureTeman(Word *command, boolean sudahMasuk);
void loginFeatureTemanReq(Word *command);
void loginFeatureTweet(Word *command);
void loginFeature(Word *command, boolean sudahMasuk);

#endif  // LOGIN_FEATURE_H
