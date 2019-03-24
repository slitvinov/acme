M = Run ac p to
PREFIX = $(HOME)
B = $(PREFIX)/bin

all:
	mkdir -p $B && \
	for i in $M; \
	do \
		cp $$i $B; \
		chmod +x $B/$$i; \
	done