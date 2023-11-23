# Set the compiler executable
COMPILER = gcc


# Compile .c files
main.o: main.c
	$(COMPILER) -c main.c

# Add more rules for other .c files as needed

# List object files
OBJECT_FILES = main.o \
               function/error/error.o \
               function/friend/friend.o \
               function/friend_request/friend_request.o \
               function/initialization/initialization.o \
               function/initialization/loadBalasan.o \
               function/initialization/loadDraf.o \
               function/initialization/loadKicauan.o \
               function/initialization/loadUser.o \
               function/initialization/loadUtas.o \
               function/input/input.o \
               function/pcolor/pcolor.o \
               function/profile/profile.o \
               function/reply/reply.o \
               function/save/save.o \
               function/tweet/tweet.o \
               function/tweet/main_tweet.o \
               function/tweet_draft/tweet_draft.o \
               function/tweet_draft/main_draft.o \
               function/user/user.o \
               function/utas/utas.o \
               adt/input/charmachine.o \
               adt/input/wordmachine.o \
               adt/input/charmachinefile.o \
               adt/input/wordmachinefile.o \
               adt/matrix/matrix.o \
							 adt/bintreetweet.o \
							 adt/datetime.o \
							 adt/graph.o \
							 adt/listdintweet.o \
							 adt/liststackdraft.o \
							 adt/liststatikuser.o \
							 adt/queue.o \
							 adt/stackdraft.o \
							 adt/time.o \
               procedure/splashscreen.o
							 procedure/globalFeature/globalFeature.o \
							 procedure/loginFeature/loginFeature.o \
							 procedure/logoutFeature/logoutFeature.o \

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
