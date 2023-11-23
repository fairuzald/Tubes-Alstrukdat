@echo off

REM Set the compiler executable
set COMPILER=gcc

REM Compile .c files
gcc -o tes main.c  function/error/error.c function/friend/friend.c function/friend_request/friend_request.c function/initialization/initialization.c function/initialization/loadBalasan.c function/initialization/loadDraf.c function/initialization/loadKicauan.c function/initialization/loadUser.c function/initialization/loadUtas.c function/input/input.c function/pcolor/pcolor.c function/profile/profile.c function/reply/reply.c function/save/save.c function/tweet/tweet.c function/tweet/main_tweet.c function/tweet_draft/tweet_draft.c function/tweet_draft/main_draft.c function/user/user.c function/utas/utas.c adt/input/charmachine.c adt/input/wordmachine.c adt/input/charmachinefile.c adt/input/wordmachinefile.c adt/matrix/matrix.c adt/bintreetweet.c adt/datetime.c adt/graph.c adt/listdintweet.c adt/liststackdraft.c adt/liststatikuser.c adt/queue.c adt/stackdraft.c adt/time.c procedure/splashscreen.c procedure/globalFeature/globalFeature.c procedure/loginFeature/loginFeature.c procedure/logoutFeature/logoutFeature.c

REM Build main.exe from object files

if exist *.o del /F /Q *.o