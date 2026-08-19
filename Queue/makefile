cc= gcc
target= queue
$(target): queue.o main.o
	$(cc) queue.o main.o -o $(target)
queue.o: queue.c queue.h
	$(cc) -c queue.c
main.o: main.c queue.h
	$(cc) -c main.c
