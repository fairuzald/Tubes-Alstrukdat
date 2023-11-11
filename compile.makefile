# Set the compiler executable
COMPILER = gcc


# Compile .c files
main.o: main.c
	$(COMPILER) -c main.c

# Add more rules for other .c files as needed

# List object files
OBJECT_FILES = main.o \
               function/friend/friend.o \
               function/initialization/initialization.o \
               function/user/user.o \
               function/input/input.o \
               function/save_load/save_load.o \
               function/utas/utas.o \
               function/tweet_draft/tweet_draft.o \
               function/reply/reply.o \
               function/tweet/tweet.o \
               function/friend_request/friend_request.o \
               function/profile/profile.o \
               function/pcolor/pcolor.o \
               function/error/error.o \
               adt/input/wordmachine.o \
               adt/input/charmachine.o \
               procedure/splashscreen.o

# Build main.exe from object files
main.exe: $(OBJECT_FILES)
	$(COMPILER) -o main.exe \
	  $(OBJECT_FILES) \
	  -Ifunction/friend \
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
	  -Ifunction/error \
	  -Iadt/input \
	  -Iadt/input/wordmachine \
	  -Iadt/input/charmachine \
	  -Iprocedure/splashscreen

# Clean up .o files
.PHONY: clean
clean:
	if exist *.o del /F /Q *.o
