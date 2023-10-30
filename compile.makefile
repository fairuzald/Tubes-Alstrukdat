# Compiler yang digunakan
CC=gcc

# Flags kompilasi
CFLAGS=-Ifunction/friend -Ifunction/initialization -Ifunction/user -Ifunction/input -Ifunction/save_load -Ifunction/utas -Ifunction/tweet_draft -Ifunction/reply -Ifunction/tweet -Ifunction/friend_request -Ifunction/profile

# Objek yang dibuat saat kompilasi
OBJ=main.o \
    function/friend/friend.o function/initialization/initialization.o \
    function/user/user.o function/input/input.o function/save_load/save_load.o \
    function/utas/utas.o function/tweet_draft/tweet_draft.o \
    function/reply/reply.o function/tweet/tweet.o \
    function/friend_request/friend_request.o function/profile/profile.o

# Target utama
all: program

# Aturan untuk mengkompilasi program utama
program: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

# Aturan untuk mengkompilasi file .o dari file .c
%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

# Bersihkan file yang dihasilkan oleh make
clean:
	rm -f $(OBJ) program
