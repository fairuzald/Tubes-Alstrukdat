# Hapus file .o dan program yang sudah ada
if exist *.o del /F /Q *.o
if exist program.exe del /F /Q program.exe

# Kompilasi file .c
gcc -c main.c
gcc -c function/friend/friend.c
gcc -c function/initialization/initialization.c
gcc -c function/user/user.c
gcc -c function/input/input.c
gcc -c function/save_load/save_load.c
gcc -c function/utas/utas.c
gcc -c function/tweet_draft/tweet_draft.c
gcc -c function/reply/reply.c
gcc -c function/tweet/tweet.c
gcc -c function/friend_request/friend_request.c
gcc -c function/profile/profile.c

# Buat program dari file .o
gcc -o program main.o friend.o initialization.o user.o input.o save_load.o utas.o tweet_draft.o reply.o tweet.o friend_request.o profile.o -Ifunction/friend -Ifunction/initialization -Ifunction/user -Ifunction/input -Ifunction/save_load -Ifunction/utas -Ifunction/tweet_draft -Ifunction/reply -Ifunction/tweet -Ifunction/friend_request -Ifunction/profile

# Bersihkan file .o
if exist *.o del /F /Q *.o
