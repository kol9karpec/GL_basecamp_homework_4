CC = @gcc

OFILE ?= main.out

IFILES += main.c

CFLAGS = --std=c99 -Wall -Werror #-pedantic
CFLAGS += $(IFILES)
CFLAGS += -o $(OFILE)

all: main.c
	$(CC) $(CFLAGS)
	@echo Done!

clean: 
	@rm -f $(OFILE)
	
