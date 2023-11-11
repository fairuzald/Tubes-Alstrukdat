@echo off

@REM REM Set the compiler executable
SET COMPILER=gcc


@REM REM Hapus file .o dan main yang sudah ada
if exist *.o del /F /Q *.o
if exist main.exe del /F /Q main.exe

@REM REM Kompilasi file .c
%COMPILER% -c main.c
%COMPILER% -c function\friend\friend.c
%COMPILER% -c function\initialization\initialization.c
%COMPILER% -c function\user\user.c
%COMPILER% -c function\input\input.c
%COMPILER% -c function\save_load\save_load.c
%COMPILER% -c function\utas\utas.c
%COMPILER% -c function\tweet_draft\tweet_draft.c
%COMPILER% -c function\reply\reply.c
%COMPILER% -c function\tweet\tweet.c
%COMPILER% -c function\friend_request\friend_request.c
%COMPILER% -c function\profile\profile.c
%COMPILER% -c function\pcolor\pcolor.c
%COMPILER% -c function\error\error.c
%COMPILER% -c adt\input\wordmachine.c
%COMPILER% -c adt\input\charmachine.c
%COMPILER% -c procedure\splashscreen.c

@REM REM Daftar file objek
SET OBJECT_FILES=main.o ^
friend.o ^
initialization.o ^
user.o ^
input.o ^
save_load.o ^
utas.o ^
tweet_draft.o ^
reply.o ^
tweet.o ^
friend_request.o ^
profile.o ^
pcolor.o ^
error.o ^
wordmachine.o ^
charmachine.o ^
splashscreen.o

@REM REM Buat main dari file .o
%COMPILER% -o main.exe ^
  %OBJECT_FILES% ^
  -Ifunction\friend ^
  -Ifunction\initialization ^
  -Ifunction\user ^
  -Ifunction\input ^
  -Ifunction\save_load ^
  -Ifunction\utas ^
  -Ifunction\tweet_draft ^
  -Ifunction\reply ^
  -Ifunction\tweet ^
  -Ifunction\friend_request ^
  -Ifunction\profile ^
  -Ifunction\pcolor ^
  -Ifunction\error ^
  -Iadt\input ^
  -Iadt\input\wordmachine ^
  -Iadt\input\charmachine ^
  -Iprocedure\splashscreen

@REM REM Bersihkan file .o
if exist *.o del /F /Q *.o
