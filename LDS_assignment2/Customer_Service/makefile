CC = gcc

all: main.o customer_service.o ../Stack_n_Queue/stack.o ../Stack_n_Queue/queue.o
	$(CC) main.o customer_service.o ../Stack_n_Queue/stack.o ../Stack_n_Queue/queue.o -o main

main.o: main.c customer_service.h
	$(CC) -c main.c -o main.o

customer_service.o: customer_service.c customer_service.h
	$(CC) -c customer_service.c -o customer_service.o

../Stack_n_Queue/stack.o: ../Stack_n_Queue/stack.c ../Stack_n_Queue/stack.h
	$(CC) -c ../Stack_n_Queue/stack.c -o ../Stack_n_Queue/stack.o

../Stack_n_Queue/queue.o: ../Stack_n_Queue/queue.c ../Stack_n_Queue/queue.h
	$(CC) -c ../Stack_n_Queue/queue.c -o ../Stack_n_Queue/queue.o