CC = gcc

all: main.o web_req_n_history.o ../Stack_n_Queue/stack.o ../Stack_n_Queue/queue.o
	$(CC) main.o web_req_n_history.o ../Stack_n_Queue/stack.o ../Stack_n_Queue/queue.o -o main

main.o: main.c web_req_n_history.h
	$(CC) -c main.c -o main.o

web_req_n_history.o: web_req_n_history.c web_req_n_history.h
	$(CC) -c web_req_n_history.c -o web_req_n_history.o

../Stack_n_Queue/stack.o: ../Stack_n_Queue/stack.c ../Stack_n_Queue/stack.h
	$(CC) -c ../Stack_n_Queue/stack.c -o ../Stack_n_Queue/stack.o

../Stack_n_Queue/queue.o: ../Stack_n_Queue/queue.c ../Stack_n_Queue/queue.h
	$(CC) -c ../Stack_n_Queue/queue.c -o ../Stack_n_Queue/queue.o