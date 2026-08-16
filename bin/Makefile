M = ac add Book com cx gp gn gd gui lsort m mac mg mkapp new p pull push py Run to ws
PREFIX = $(HOME)
B = $(PREFIX)/.local/bin

all:
	mkdir -p $B && \
	for i in $M; \
	do \
		cp $$i $B; \
		chmod +x $B/$$i; \
	done
	S=`python3 -c 'import site; print(site.getusersitepackages())'` && \
	mkdir -p $$S && \
	cp $(PREFIX)/acme/lib/usercustomize.py $$S/usercustomize.py
