PROGS=zad3

all: $(PROGS)

zad3: zad3.o
	gcc -o zad3 zad3.o zad3.c

zad3.o: zad3.s
	as -o zad3.o zad3.s

clean:
	rm -f $(PROGS) *.o