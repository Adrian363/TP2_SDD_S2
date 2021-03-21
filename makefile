CC=gcc
OPT= -c -ansi -pedantic -Wall
tp2 : tp2.o cnp.o queue.o stack.o
	$(CC) -o TP2 TP2.o cnp.o queue.o stack.o
tp2.o : TP2.c
	$(CC) $(OPT) TP2.c
cnp.o : cnp.c cnp.h
	$(CC) $(OPT) cnp.c 
matrix.o : queue.c queue.h
	$(CC) $(OPT) queue.c
linked_list.o : stack.c stack.h
	$(CC) $(OPT) stack.c
clair :
	rm tp2.o basics.o matrix.o linked_list.o
propre : clair
	rm tp2
	
