SRC=src
IDIR=include
LDIR=lib
ODIR=obj

CC=gcc
CFLAGS=-I$(IDIR) -Wall

LIBS=-lncurses -lm

_SRCFILES=$(wildcard $(SRC)/*.c)

_DEPS=$(_SRCFILES:.c=.h)
DEPS=$(patsubst $(SRC)/%,$(IDIR)/%,$(_DEPS))

_OBJ=$(_SRCFILES:.c=.o)
OBJ=$(patsubst $(SRC)/%,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: $(_SRCFILES) $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

hello: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core hello $(IDIR)/*~
