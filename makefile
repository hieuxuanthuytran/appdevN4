OBJ = screen.o testscreen.o comm.o
APPNAME = screentest

#linking rule
$(APPNAME) : $(OBJ)
	gcc -o $(APPNAME) $(OBJ) -lcurl
%.o : %.c
	gcc -c -o $@ $<

clean :
	rm $(APPNAME) $(OBJ)

#archiving rule
zip :
	tar cf appdev.tar *.c *.h makefile
