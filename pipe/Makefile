.POSIX:
CC=gcc
M = sys exe popen
PREC = d
LINK = $(CC)

all: $M
.o:
	$(LINK) $< $(LDFLAGS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -c -o $@

.c:
%: %.c

lint:; make CFLAGS='-Wall -Wextra -g -O2'


.PHONY: clean lint
clean:; rm -f $M $(M:=.o)
