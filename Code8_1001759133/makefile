SRC1 = Code8_1001759133.c
SRC2 = MovieTheaterLib.c
SRC3 = ListLib.c
SRC4 = StackLib.c
SRC5 = QueueLib.c
SRC6 = BSTLib.c

OBJ1 = $(SRC1:.c=.o)
OBJ2 = $(SRC2:.c=.o)
OBJ3 = $(SRC3:.c=.o)
OBJ4 = $(SRC4:.c=.o)
OBJ5 = $(SRC5:.c=.o)
OBJ6 = $(SRC6:.c=.o)

EXE = $(SRC1:.c=.e)
HFILE1 = MovieTheaterLib.h
HFILE2 = ListLib.h
HFILE3 = StackLib.h
HFILE4 = QueueLib.h
HFILE5 = BSTLib.h

CFLAGS = -g

all : $(EXE)

$(EXE): $(OBJ1) $(OBJ2) $(OBJ3) $(OBJ4) $(OBJ5) $(OBJ6)
	gcc $(CFLAGS) $(OBJ1) $(OBJ2) $(OBJ3) $(OBJ4) $(OBJ5) $(OBJ6) -o $(EXE)

$(OBJ1): $(SRC1) $(HFILE1) $(HFILE2) $(HFILE3) $(HFILE4) $(HFILE5)
	gcc -c $(CFLAGS) $(SRC1) -o $(OBJ1)

$(OBJ2): $(SRC2) $(HFILE1) $(HFILE2) $(HFILE3) $(HFILE4) $(HFILE5)
	gcc -c $(CFLAGS) $(SRC2) -o $(OBJ2)

$(OBJ3): $(SRC3) $(HFILE1) $(HFILE2) $(HFILE3) $(HFILE4) $(HFILE5)
	gcc -c $(CFLAGS) $(SRC3) -o $(OBJ3)

$(OBJ4): $(SRC4) $(HFILE1) $(HFILE2) $(HFILE3) $(HFILE4) $(HFILE5)
	gcc -c $(CFLAGS) $(SRC4) -o $(OBJ4)

$(OBJ5): $(SRC5) $(HFILE1) $(HFILE2) $(HFILE3) $(HFILE4) $(HFILE5)
	gcc -c $(CFLAGS) $(SRC5) -o $(OBJ5)

$(OBJ6): $(SRC6) $(HFILE1) $(HFILE2) $(HFILE3) $(HFILE4) $(HFILE5)
	gcc -c $(CFLAGS) $(SRC6) -o $(OBJ6)