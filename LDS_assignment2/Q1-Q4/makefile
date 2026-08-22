# Compile main
cc=gcc

main.o: main.c assignment_snq.h
	$(CC) -c main.c -o main.o

# Compile assignment logic
assignment_snq.o: assignment.c assignment_snq.h
	$(CC) -c assignment.c -o assignment_snq.o

# Compile external Stack module
../Stack_n_Queue/stack.o: ../Stack_n_Queue/stack.c ../Stack_n_Queue/stack.h
	$(CC) -c ../Stack_n_Queue/stack.c -o ../Stack_n_Queue/stack.o

# Compile external Queue module
../Stack_n_Queue/queue.o: ../Stack_n_Queue/queue.c ../Stack_n_Queue/queue.h
	$(CC) -c ../Stack_n_Queue/queue.c -o ../Stack_n_Queue/queue.o