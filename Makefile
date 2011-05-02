CFLAGS = -W -Wall -g -O2
OBJ = main.o hashtab.o

hashtab : $(OBJ)
main.o : main.c hashtab.h
hashtab.o : hashtab.c hashtab.h

.PHONY : clean run

run : hashtab
	./$^

clean :
	$(RM) $(OBJ) hashtab
