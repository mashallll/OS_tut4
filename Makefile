/* Makefile */
all: jeopardy

jeopardy: jeopardy.o questions.o players.o
	gcc -o jeopardy jeopardy.o questions.o players.o

jeopardy.o: jeopardy.c questions.h players.h
	gcc -c jeopardy.c

questions.o: questions.c questions.h
	gcc -c questions.c

players.o: players.c players.h
	gcc -c players.c

clean:
	rm -f *.o jeopardy