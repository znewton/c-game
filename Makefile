SRC=src
IDIR=include
ODIR=obj
LDIR=lib

CC=gcc
CFLAGS=-I$(IDIR) -Wall
LFLAGS=-L$(LDIR)

LIBS=-lncurses -lm

SRCS=$(wildcard $(SRC)/*.c)

_INCLUDES=$(SRCS:.c=.h)
INCLUDES=$(patsubst $(SRC)/%,$(IDIR)/%,$(_INCLUDES))

_OBJS=$(SRCS:.c=.o)
OBJS=$(patsubst $(SRC)/%,$(ODIR)/%,$(_OBJS))

MAIN=main

all: $(MAIN)
	@echo main has been compiled

.c.o: $(SRCS)
	$(CC) $(CFLAGS) -c $< -o $@

$(MAIN): $(_OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(_OBJS) $(LFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core main $(IDIR)/*~ $(SRC)/*.o
