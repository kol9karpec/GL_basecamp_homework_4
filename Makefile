CC = @gcc

OFILE ?= main.out

IFILES += main.c

CFLAGS = --std=c90 -Wall -Werror #-pedantic
CFLAGS += $(IFILES)
CFLAGS += -o $(OFILE)

all: main.c
	$(CC) $(CFLAGS)

clean: 
	@rm -f $(OFILE)
	
