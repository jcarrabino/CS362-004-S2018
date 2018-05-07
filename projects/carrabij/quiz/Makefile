testme: testme.c
	gcc -o testme testme.c -coverage -fpic -lm
	./testme
	gcov ./testme -b

all: testme

clean:
	rm -f testme *.gcda *.gcno