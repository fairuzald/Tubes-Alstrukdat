# Compiler yang digunakan
CC=gcc

# Flags kompilasi
CFLAGS=-Ifunction/friend \
       -Ifunction/initialization \
       -Ifunction/user \
       -Ifunction/input \
       -Ifunction/save_load \
       -Ifunction/utas \
       -Ifunction/tweet_draft \
       -Ifunction/reply \
       -Ifunction/tweet \
       -Ifunction/friend_request \
       -Ifunction/profile \
       -Ifunction/pcolor \
       -Iadt/input/charmachine \
       -Iadt/input/wordmachine \
       -Iprocedure/splashscreen

# Objek yang dibuat saat kompilasi
OBJ_DIR=obj
SRC_DIR=.
SRC_SUBDIRS=$(shell find $(SRC_DIR) -type d)
SRC=$(wildcard $(addsuffix /*.c,$(SRC_SUBDIRS)))
OBJ=$(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))

# Target utama
all: main

# Aturan untuk membuat direktori obj jika belum ada
$(OBJ_DIR):
	mkdir -p $@

# Aturan untuk mengkompilasi main utama
main: $(OBJ_DIR) $(OBJ)
	$(CC) -o $@ $(OBJ) $(CFLAGS)

# Aturan untuk mengkompilasi file .o dari file .c
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c -o $@ $< $(CFLAGS)

# Bersihkan file yang dihasilkan oleh make
clean:
	rm -rf $(OBJ_DIR) main
