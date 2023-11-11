# Compiler yang digunakan
CC=gcc
path = function
path2 = adt
path3 = procedure

# Flags kompilasi
CFLAGS=-I$(path)/friend \
       -I$(path)/initialization \
       -I$(path)/user \
       -I$(path)/input \
       -I$(path)/save_load \
       -I$(path)/utas \
       -I$(path)/tweet_draft \
       -I$(path)/reply \
       -I$(path)/tweet \
       -I$(path)/friend_request \
       -I$(path)/profile \
       -I$(path)/pcolor \
       -I$(path2)/input/charmachine \
       -I$(path2)/input/wordmachine \
       -I$(path3)/splashscreen

# Objek yang dibuat saat kompilasi
OBJ_DIR=obj
SRC_DIR=$(path) $(path2) $(path3)
SRC_SUBDIRS=$(patsubst %,$(SRC_DIR)/%,$(shell find $(SRC_DIR) -maxdepth 1 -type d))
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
